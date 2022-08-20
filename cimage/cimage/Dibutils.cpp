/**************************************************************************

	 UTILS.C - useful functions for WinG Sample Apps

 **************************************************************************/
/**************************************************************************

	 (C) Copyright 1994 Microsoft Corp.  All rights reserved.

    You have a royalty-free right to use, modify, reproduce and 
    distribute the Sample Files (and/or any modified version) in 
    any way you find useful, provided that you agree that 
	 Microsoft has no warranty obligations or liability for any
    Sample Application Files which are modified. 

 **************************************************************************/

/*----------------------------------------------------------------------------*\
|   Functions for handling Device Independent Bitmaps and clearing the         |
|   System Palette.                                                            |
\*----------------------------------------------------------------------------*/

#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include "dibutils.h"

#if defined(WIN32) || defined(_WIN32)
    #include <memory.h>             // for _fmemcpy()
	 #define _huge
#ifndef hmemcpy
    #define hmemcpy memcpy
#endif
#endif

#define BFT_ICON   0x4349   /* 'IC' */
#define BFT_BITMAP 0x4d42   /* 'BM' */
#define BFT_CURSOR 0x5450   /* 'PT' */

/* flags for _lseek */
#define  SEEK_CUR 1
#define  SEEK_END 2
#define  SEEK_SET 0


/*
 *  Clear the System Palette so that we can ensure an identity palette 
 *  mapping for fast performance.
 */

void ClearSystemPalette(void)
{
  //*** A dummy palette setup
  struct
  {
    WORD Version;
    WORD NumberOfEntries;
    PALETTEENTRY aEntries[256];
  } Palette =
  {
    0x300,
    256
  };

  HPALETTE ScreenPalette = 0;
  HDC ScreenDC;
  int Counter;
  UINT nMapped = 0;
  BOOL bOK = FALSE;
  int  nOK = 0;
  
  //*** Reset everything in the system palette to black
  for(Counter = 0; Counter < 256; Counter++)
  {
    Palette.aEntries[Counter].peRed = 0;
	 Palette.aEntries[Counter].peGreen = 0;
    Palette.aEntries[Counter].peBlue = 0;
    Palette.aEntries[Counter].peFlags = PC_NOCOLLAPSE;
  }

  //*** Create, select, realize, deselect, and delete the palette
  ScreenDC = GetDC(NULL);
  ScreenPalette = CreatePalette((LOGPALETTE *)&Palette);

  if (ScreenPalette)
  {
	 ScreenPalette = SelectPalette(ScreenDC,ScreenPalette,FALSE);
	 nMapped = RealizePalette(ScreenDC);
    ScreenPalette = SelectPalette(ScreenDC,ScreenPalette,FALSE);
    bOK = DeleteObject(ScreenPalette);
  }

  nOK = ReleaseDC(NULL, ScreenDC);

  return;
}


/*
 *   Open a DIB file and return a MEMORY DIB, a memory handle containing..
 *
 *   BITMAP INFO    bi
 *   palette data
 *   bits....
 */

int DibWriteFile(LPSTR szFile, LPBITMAPINFOHEADER lpbi)
{
	 HFILE               fh;
	 OFSTRUCT            of;

	 fh = OpenFile(szFile, &of, OF_WRITE | OF_CREATE);

  if (!fh) {
//	 printf("la regamos0");
	 return 0;
  }

  long size = DibSize(lpbi);

  // write file header
  BITMAPFILEHEADER bmf;
  bmf.bfType = 'BM';
  bmf.bfSize = sizeof(bmf) + size;
  bmf.bfReserved1 = 0;
  bmf.bfReserved2 = 0;
  bmf.bfOffBits = sizeof(bmf) + (char far*)(DibPtr(lpbi)) - (char far*)lpbi;
#if defined( __WATCOMC__) || defined(_MSC_VER)
  if (_hwrite(fh, (LPCSTR)(&bmf), sizeof(bmf))<0 ||
	_hwrite(fh, (LPCSTR)lpbi, size)<0) {
	  _lclose(fh);
//	 printf("la regamos1");
	  return 0;
  }
#else
  if (_hwrite(fh, (LPBYTE)(&bmf), sizeof(bmf))<0 ||
	_hwrite(fh, (LPBYTE)lpbi, size)<0) {
	  _lclose(fh);
//	 printf("la regamos1");
	  return 0;
  }
#endif

  _lclose(fh);
  return 1;
}

// The following is an alternative implementation of DIB writing, since
// the above doesn't appear to work.

/****************************************************************************
 *									    *
 *  FUNCTION   :  PaletteSize(VOID FAR * pv)				    *
 *									    *
 *  PURPOSE    :  Calculates the palette size in bytes. If the info. block  *
 *		  is of the BITMAPCOREHEADER type, the number of colors is  *
 *		  multiplied by 3 to give the palette size, otherwise the   *
 *		  number of colors is multiplied by 4.								*
 *									    *
 *  RETURNS    :  Palette size in number of bytes.			    *
 *									    *
 ****************************************************************************/

WORD PaletteSize(VOID FAR * pv)
{
	LPBITMAPINFOHEADER lpbi;
	WORD	       NumColors;

	lpbi = (LPBITMAPINFOHEADER) pv;
	NumColors = DibNumColors(lpbi);

	if (lpbi->biSize == sizeof(BITMAPCOREHEADER))
		return NumColors * sizeof(RGBTRIPLE);
	else 
		return NumColors * sizeof(RGBQUAD);
}

/****************************************************************************
 *									    *
 *  FUNCTION   : lwrite(int fh, VOID FAR *pv, DWORD ul) 		    *
 *									    *
 *  PURPOSE    : Writes data in steps of 32k till all the data is written.  *
 *									    *
 *  RETURNS    : 0 - If write did not proceed correctly.		    *
 *		 number of bytes written otherwise.			    *
 *									    *
 ****************************************************************************/

#define MAXREAD  32768				 /* Number of bytes to be read during */
						 /* each read operation.			 */

DWORD PASCAL lwrite(int fh, VOID FAR *pv, DWORD ul)
{
	DWORD     ulT = ul;
#if defined(WINNT) || defined(WIN32) || defined(__WIN32__)
	BYTE *hp = (BYTE *) pv;
#else
	BYTE huge *hp = (BYTE huge *) pv;
#endif
	while (ul > MAXREAD) {
		if (_lwrite(fh, (LPSTR) hp, (WORD) MAXREAD) != MAXREAD)
			return 0;
		ul -= MAXREAD;
		hp += MAXREAD;
		}
	if (_lwrite(fh, (LPSTR) hp, (WORD) ul) != (WORD) ul)
		return 0;
	return ulT;
}

/****************************************************************************
 *									    *
 *  FUNCTION   : WriteDIB(LPSTR szFile,HANDLE hdib)			    *
 *									    *
 *  PURPOSE    : Write a global handle in CF_DIB format to a file.	    *
 *									    *
 *  RETURNS    : TRUE  - if successful. 				    *
 *		 FALSE - otherwise					    *
 *									    *
 ****************************************************************************/

BOOL WriteDIB(const char *szFile, LPBITMAPINFOHEADER  lpbi)
{
	BITMAPFILEHEADER	hdr;
	int                 fh;
	OFSTRUCT            of;

	if (!lpbi)
		return FALSE;

	fh = OpenFile(szFile, &of, OF_CREATE | OF_READWRITE);
	if (fh == -1)
		return FALSE;

    /* Fill in the fields of the file header */
	hdr.bfType = BFT_BITMAP;
	hdr.bfSize = DibSize(lpbi) + sizeof(BITMAPFILEHEADER);
	hdr.bfReserved1 = 0;
	hdr.bfReserved2 = 0;
	hdr.bfOffBits = (DWORD) sizeof(BITMAPFILEHEADER) + lpbi->biSize + 
		 PaletteSize(lpbi);

    /* Write the file header */
	_lwrite(fh, (LPSTR) &hdr, sizeof(BITMAPFILEHEADER));

    /* Write the DIB header and the bits */
	lwrite(fh, (LPSTR) lpbi, DibSize(lpbi));

	_lclose(fh);
	return TRUE;
}

PDIB DibOpenFile(LPSTR szFile)
{
	 HFILE               fh;
	 DWORD               dwLen;
	 DWORD               dwBits;
	 PDIB                pdib;
	 LPVOID              p;
	 OFSTRUCT            of;

#if defined(WIN32) || defined(_WIN32)
	 #define GetCurrentInstance()    GetModuleHandle(NULL)
#else
	 #define GetCurrentInstance()    (HINSTANCE)SELECTOROF((LPVOID)&of)
#endif

	 fh = OpenFile(szFile, &of, OF_READ);

#if 0
	 if (fh == -1)
	 {
		  HRSRC h;

		  h = FindResource(GetCurrentInstance(), szFile, RT_BITMAP);

#if defined(WIN32) || defined(_WIN32)
		  //!!! can we call GlobalFree() on this? is it the right format.
		  //!!! can we write to this resource?
		  if (h)
				return (PDIB)LockResource(LoadResource(GetCurrentInstance(), h));
#else
		  if (h)
				fh = AccessResource(GetCurrentInstance(), h);
#endif
	 }
#endif

	 if (fh == -1)
		  return NULL;

	 pdib = DibReadBitmapInfo(fh);

	 if (!pdib)
		  return NULL;

    /* How much memory do we need to hold the DIB */

    dwBits = pdib->biSizeImage;
    dwLen  = pdib->biSize + DibPaletteSize(pdib) + dwBits;

    /* Can we get more memory? */

	 p = GlobalReAllocPtr(pdib,dwLen,0);

    if (!p)
    {
		  GlobalFreePtr(pdib);
        pdib = NULL;
    }
    else
    {
        pdib = (PDIB)p;
    }

    if (pdib)
    {
		  /* read in the bits */
		  _hread(fh, (LPBYTE)pdib + (UINT)pdib->biSize + DibPaletteSize(pdib), dwBits);
    }

    _lclose(fh);

    return pdib;
}


/*
 *  ReadDibBitmapInfo()
 *
 *  Will read a file in DIB format and return a global HANDLE to its
 *  BITMAPINFO.  This function will work with both "old" and "new"
 *  bitmap formats, but will always return a "new" BITMAPINFO.
 */

PDIB DibReadBitmapInfo(HFILE fh)
{
    DWORD     off;
    HANDLE    hbi = NULL;
    int       size;
    int       i;
    int       nNumColors;

    RGBQUAD FAR       *pRgb;
    BITMAPINFOHEADER   bi;
    BITMAPCOREHEADER   bc;
    BITMAPFILEHEADER   bf;
    PDIB               pdib;

    if (fh == -1)
        return NULL;

    off = _llseek(fh,0L,SEEK_CUR);

    if (sizeof(bf) != _lread(fh,(LPSTR)&bf,sizeof(bf)))
        return FALSE;

    /*
     *  do we have a RC HEADER?
     */
    if (bf.bfType != BFT_BITMAP)
    {
        bf.bfOffBits = 0L;
        _llseek(fh,off,SEEK_SET);
    }

    if (sizeof(bi) != _lread(fh,(LPSTR)&bi,sizeof(bi)))
        return FALSE;

    /*
     *  what type of bitmap info is this?
     */
    switch (size = (int)bi.biSize)
    {
        default:
        case sizeof(BITMAPINFOHEADER):
            break;

        case sizeof(BITMAPCOREHEADER):
            bc = *(BITMAPCOREHEADER*)&bi;
            bi.biSize               = sizeof(BITMAPINFOHEADER);
            bi.biWidth              = (DWORD)bc.bcWidth;
            bi.biHeight             = (DWORD)bc.bcHeight;
            bi.biPlanes             =  (UINT)bc.bcPlanes;
            bi.biBitCount           =  (UINT)bc.bcBitCount;
            bi.biCompression        = BI_RGB;
            bi.biSizeImage          = 0;
            bi.biXPelsPerMeter      = 0;
            bi.biYPelsPerMeter      = 0;
            bi.biClrUsed            = 0;
            bi.biClrImportant       = 0;

            _llseek(fh,(LONG)sizeof(BITMAPCOREHEADER)-sizeof(BITMAPINFOHEADER),SEEK_CUR);

            break;
    }

    nNumColors = DibNumColors(&bi);

#if 0
    if (bi.biSizeImage == 0)
        bi.biSizeImage = DibSizeImage(&bi);

    if (bi.biClrUsed == 0)
        bi.biClrUsed = DibNumColors(&bi);
#else
    FixBitmapInfo(&bi);
#endif

    pdib = (PDIB)GlobalAllocPtr(GMEM_MOVEABLE,(LONG)bi.biSize + nNumColors * sizeof(RGBQUAD));

    if (!pdib)
        return NULL;

    *pdib = bi;

    pRgb = DibColors(pdib);

    if (nNumColors)
    {
        if (size == sizeof(BITMAPCOREHEADER))
        {
            /*
             * convert a old color table (3 byte entries) to a new
             * color table (4 byte entries)
             */
            _lread(fh,(LPVOID)pRgb,nNumColors * sizeof(RGBTRIPLE));

            for (i=nNumColors-1; i>=0; i--)
            {
                RGBQUAD rgb;

                rgb.rgbRed      = ((RGBTRIPLE FAR *)pRgb)[i].rgbtRed;
                rgb.rgbBlue     = ((RGBTRIPLE FAR *)pRgb)[i].rgbtBlue;
                rgb.rgbGreen    = ((RGBTRIPLE FAR *)pRgb)[i].rgbtGreen;
                rgb.rgbReserved = (BYTE)0;

                pRgb[i] = rgb;
            }
        }
        else
        {
            _lread(fh,(LPVOID)pRgb,nNumColors * sizeof(RGBQUAD));
        }
    }

    if (bf.bfOffBits != 0L)
        _llseek(fh,off + bf.bfOffBits,SEEK_SET);

    return pdib;
}

/*
 *  DibSetUsage(hdib,hpal,wUsage)
 *
 *  Modifies the color table of the passed DIB for use with the wUsage
 *  parameter specifed.
 *
 *  if wUsage is DIB_PAL_COLORS the DIB color table is set to 0-256
 *  if wUsage is DIB_RGB_COLORS the DIB color table is set to the RGB values
 *      in the passed palette
 */

BOOL DibSetUsage(PDIB pdib, HPALETTE hpal,UINT wUsage)
{
    PALETTEENTRY       ape[256];
    RGBQUAD FAR *      pRgb;
    WORD FAR *         pw;
    int                nColors;
    int                n;

    if (hpal == NULL)
        hpal = (HPALETTE)GetStockObject(DEFAULT_PALETTE);

    if (!pdib)
        return FALSE;

    nColors = DibNumColors(pdib);
    
    if (nColors == 3 && DibCompression(pdib) == BI_BITFIELDS)
        nColors = 0;

    if (nColors > 0)
    {
        pRgb = DibColors(pdib);

        switch (wUsage)
        {
            //
            // Set the DIB color table to palette indexes
            //
            case DIB_PAL_COLORS:
            {
                // According to Oliver Schreck <schreck@iis.fhg.de>,
                // this produces a wrong palette.
                for (pw = (WORD FAR*)pRgb,n=0; n<nColors; n++,pw++)
                    *pw = n;

                // Notes by JACS: This is the corrected code.
				// Actually this doens't work, it gives a corrupt
				// palette when reading in a JPEG.
/*
				for (n=0; n<nColors; n++)
				{
					pRgb[n].rgbRed      = n;
					pRgb[n].rgbGreen    = n;
					pRgb[n].rgbBlue     = n;
				}
*/
                break;
            }

            //
            // Set the DIB color table to RGBQUADS
            //
            default:
            case DIB_RGB_COLORS:
                nColors =  (nColors < 256) ? nColors: 256;

                GetPaletteEntries(hpal,0,nColors,ape);

                for (n=0; n<nColors; n++)
                {
                    pRgb[n].rgbRed      = ape[n].peRed;
                    pRgb[n].rgbGreen    = ape[n].peGreen;
                    pRgb[n].rgbBlue     = ape[n].peBlue;
                    pRgb[n].rgbReserved = 0;
                }
                break;
        }
    }
    return TRUE;
}

/*
 *  DibCreate(bits, dx, dy)
 *
 *  Creates a new packed DIB with the given dimensions and the
 *  given number of bits per pixel
 */

PDIB DibCreate(int bits, int dx, int dy)
{
    LPBITMAPINFOHEADER lpbi ;
    DWORD       dwSizeImage;
    int         i;
    DWORD FAR  *pdw;

    dwSizeImage = dy*(DWORD)((dx*bits/8+3)&~3);

    lpbi = (PDIB)GlobalAllocPtr(GHND,sizeof(BITMAPINFOHEADER)+dwSizeImage + 1024);

    if (lpbi == NULL)
        return NULL;

    lpbi->biSize            = sizeof(BITMAPINFOHEADER) ;
    lpbi->biWidth           = dx;
    lpbi->biHeight          = dy;
    lpbi->biPlanes          = 1;
    lpbi->biBitCount        = bits ;
    lpbi->biCompression     = BI_RGB ;
    lpbi->biSizeImage       = dwSizeImage;
    lpbi->biXPelsPerMeter   = 0 ;
    lpbi->biYPelsPerMeter   = 0 ;
    lpbi->biClrUsed         = 0 ;
    lpbi->biClrImportant    = 0 ;

    if (bits == 4)
        lpbi->biClrUsed = 16;

    else if (bits == 8)
        lpbi->biClrUsed = 256;

    pdw = (DWORD FAR *)((LPBYTE)lpbi+(int)lpbi->biSize);

    for (i=0; i<(int)lpbi->biClrUsed/16; i++)
    {
        *pdw++ = 0x00000000;    // 0000  black
        *pdw++ = 0x00800000;    // 0001  dark red
        *pdw++ = 0x00008000;    // 0010  dark green
		  *pdw++ = 0x00808000;    // 0011  mustard
        *pdw++ = 0x00000080;    // 0100  dark blue
        *pdw++ = 0x00800080;    // 0101  purple
        *pdw++ = 0x00008080;    // 0110  dark turquoise
        *pdw++ = 0x00C0C0C0;    // 1000  gray
        *pdw++ = 0x00808080;    // 0111  dark gray
        *pdw++ = 0x00FF0000;    // 1001  red
        *pdw++ = 0x0000FF00;    // 1010  green
		  *pdw++ = 0x00FFFF00;    // 1011  yellow
        *pdw++ = 0x000000FF;    // 1100  blue
        *pdw++ = 0x00FF00FF;    // 1101  pink (magenta)
        *pdw++ = 0x0000FFFF;    // 1110  cyan
        *pdw++ = 0x00FFFFFF;    // 1111  white
    }

    return (PDIB)lpbi;
}

static void xlatClut8(BYTE FAR *pb, DWORD dwSize, BYTE FAR *xlat)
{
    DWORD dw;

#ifdef __cplusplus
    for (dw = 0; dw < dwSize; dw++, ((BYTE _huge *&)pb)++)
#else
    for (dw = 0; dw < dwSize; dw++, ((BYTE _huge *)pb)++)
#endif
        *pb = xlat[*pb];
}

static void xlatClut4(BYTE FAR *pb, DWORD dwSize, BYTE FAR *xlat)
{
    DWORD dw;

#ifdef __cplusplus
    for (dw = 0; dw < dwSize; dw++, ((BYTE _huge *&)pb)++)
#else
    for (dw = 0; dw < dwSize; dw++, ((BYTE _huge *)pb)++)
#endif
        *pb = (BYTE)(xlat[*pb & 0x0F] | (xlat[(*pb >> 4) & 0x0F] << 4));
}

#define RLE_ESCAPE  0
#define RLE_EOL     0
#define RLE_EOF     1
#define RLE_JMP     2

static void xlatRle8(BYTE FAR *pb, DWORD dwSize, BYTE FAR *xlat)
{
    BYTE    cnt;
    BYTE    b;
    BYTE _huge *prle = pb;

    for(;;)
    {
        cnt = *prle++;
        b   = *prle;

        if (cnt == RLE_ESCAPE)
        {
            prle++;

            switch (b)
            {
                case RLE_EOF:
                    return;

                case RLE_EOL:
                    break;

                case RLE_JMP:
                    prle++;     // skip dX
                    prle++;     // skip dY
                    break;

                default:
                    cnt = b;
                    for (b=0; b<cnt; b++,prle++)
                        *prle = xlat[*prle];

                    if (cnt & 1)
                        prle++;

                    break;
            }
        }
        else
        {
            *prle++ = xlat[b];
        }
    }
}

static void xlatRle4(BYTE FAR *pb, DWORD dwSize, BYTE FAR *xlat)
{
}

static void hmemmove(BYTE _huge *d, BYTE _huge *s, LONG len)
{
    d += len-1;
    s += len-1;

    while (len--)
        *d-- = *s--;
}

/*
 *  DibMapToPalette(pdib, hpal)
 *
 *  Map the colors of the DIB, using GetNearestPaletteIndex, to
 *  the colors of the given palette.
 */

BOOL DibMapToPalette(PDIB pdib, HPALETTE hpal)
{
	 LPBITMAPINFOHEADER  lpbi;
	 PALETTEENTRY        pe;
	 int                 n;
	 int                 nDibColors;
	 int                 nPalColors=0;
	 BYTE FAR *          lpBits;
	 RGBQUAD FAR *       lpRgb;
	 BYTE                xlat[256];
	 DWORD               SizeImage;

	 if (!hpal || !pdib)
		  return FALSE;

	 lpbi   = (LPBITMAPINFOHEADER)pdib;
	 lpRgb  = DibColors(pdib);

	 GetObject(hpal,sizeof(int),(LPSTR)&nPalColors);
	 nDibColors = DibNumColors(pdib);

	 if ((SizeImage = lpbi->biSizeImage) == 0)
		  SizeImage = DibSizeImage(lpbi);

	 //
	 //  build a xlat table. from the current DIB colors to the given
	 //  palette.
	 //
	 for (n=0; n<nDibColors; n++)
		  xlat[n] = (BYTE)GetNearestPaletteIndex(hpal,RGB(lpRgb[n].rgbRed,lpRgb[n].rgbGreen,lpRgb[n].rgbBlue));

	 lpBits = (LPBYTE)DibPtr(lpbi);
	 lpbi->biClrUsed = nPalColors;

	 //
	 // re-size the DIB
	 //
	 if (nPalColors > nDibColors)
	 {
		  GlobalReAllocPtr(lpbi, lpbi->biSize + nPalColors*sizeof(RGBQUAD) + SizeImage, 0);
		  hmemmove((BYTE _huge *)DibPtr(lpbi), (BYTE _huge *)lpBits, SizeImage);
		  lpBits = (LPBYTE)DibPtr(lpbi);
	 }
	 else if (nPalColors < nDibColors)
	 {
		  hmemcpy(DibPtr(lpbi), lpBits, SizeImage);
		  GlobalReAllocPtr(lpbi, lpbi->biSize + nPalColors*sizeof(RGBQUAD) + SizeImage, 0);
		  lpBits = (LPBYTE)DibPtr(lpbi);
	 }

	 //
	 // translate the DIB bits
	 //
	 switch (lpbi->biCompression)
	 {
		  case BI_RLE8:
				xlatRle8(lpBits, SizeImage, xlat);
				break;

		  case BI_RLE4:
				xlatRle4(lpBits, SizeImage, xlat);
				break;

        case BI_RGB:
				if (lpbi->biBitCount == 8)
                xlatClut8(lpBits, SizeImage, xlat);
            else
                xlatClut4(lpBits, SizeImage, xlat);
            break;
    }

    //
    //  Now copy the RGBs in the logical palette to the dib color table
    //
    for (n=0; n<nPalColors; n++)
    {
        GetPaletteEntries(hpal,n,1,&pe);

        lpRgb[n].rgbRed      = pe.peRed;
		  lpRgb[n].rgbGreen    = pe.peGreen;
		  lpRgb[n].rgbBlue     = pe.peBlue;
		  lpRgb[n].rgbReserved = (BYTE)0;
	 }

	 return TRUE;
}

HPALETTE MakePalette(const BITMAPINFO FAR* Info, UINT flags)
{
    HPALETTE hPalette;
    const RGBQUAD far* rgb = Info->bmiColors;
    
    // PJO - Calculate colours correctly
    WORD nColors = WORD( Info->bmiHeader.biClrUsed ? Info->bmiHeader.biClrUsed : 
                                               1 << Info->bmiHeader.biBitCount );
    if ( nColors ) {
        LOGPALETTE* logPal = (LOGPALETTE*)
            new BYTE[sizeof(LOGPALETTE) + (nColors-1)*sizeof(PALETTEENTRY)];
        
        logPal->palVersion  = 0x300; // Windows 3.0 version
        logPal->palNumEntries = nColors;
        for (short n = 0; n < nColors; n++) {
            logPal->palPalEntry[n].peRed   = rgb[n].rgbRed;
            logPal->palPalEntry[n].peGreen = rgb[n].rgbGreen;
            logPal->palPalEntry[n].peBlue  = rgb[n].rgbBlue;
            logPal->palPalEntry[n].peFlags = (BYTE)flags;
        }
        hPalette = ::CreatePalette(logPal);
        delete logPal;
    } else
        hPalette = 0;
    
    return hPalette;
}

