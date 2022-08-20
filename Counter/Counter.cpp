// COUNTER.CPP - Implementation file for your Internet Server
//    Counter Extension

#include "stdafx.h"
#include "Counter.h"
#include "mydatabase.h"
#include "\wxz\cimage\cimage\cimage.h"
#include <afxtempl.h>

///////////////////////////////////////////////////////////////////////
// The one and only CWinApp object
// NOTE: You may remove this object if you alter your project to no
// longer use MFC in a DLL.

CWinApp theApp;

///////////////////////////////////////////////////////////////////////
// command-parsing map

BEGIN_PARSE_MAP(CCounterExtension, CHttpServer)
	DEFAULT_PARSE_COMMAND(Default, CCounterExtension)
	ON_PARSE_COMMAND(Default, CCounterExtension, ITS_PSTR ITS_PSTR ITS_I2 ITS_PSTR ITS_PSTR ITS_PSTR)
	ON_PARSE_COMMAND_PARAMS("link style width=4 ord='no' bgcolor='000000' fgcolor='ffffff'")
END_PARSE_MAP(CCounterExtension)


///////////////////////////////////////////////////////////////////////
// The one and only CCounterExtension object

CCounterExtension theExtension;


///////////////////////////////////////////////////////////////////////
// CCounterExtension implementation

CCounterExtension::CCounterExtension()
{
	m_pdb = new CMyDatabase;
	m_querySet.m_pDatabase = m_pdb;
}

CCounterExtension::~CCounterExtension()
{
	delete m_pdb;
}

BOOL CCounterExtension::GetExtensionVersion(HSE_VERSION_INFO* pVer)
{
	// Call default implementation for initialization
	CHttpServer::GetExtensionVersion(pVer);

	GetModuleFileName(AfxGetInstanceHandle(), m_strPath, 256);

	// Load description string
	TCHAR sz[HSE_MAX_EXT_DLL_NAME_LEN+1];
	ISAPIVERIFY(::LoadString(AfxGetResourceHandle(),
			IDS_SERVER, sz, HSE_MAX_EXT_DLL_NAME_LEN));
	_tcscpy(pVer->lpszExtensionDesc, sz);
	return TRUE;
}

BOOL CCounterExtension::TerminateExtension(DWORD dwFlags)
{
	// extension is being terminated
	//TODO: Clean up any per-instance resources
	return TRUE;
}

///////////////////////////////////////////////////////////////////////
// CCounterExtension command handlers

void CCounterExtension::Default(CHttpServerContext* pCtxt, LPTSTR strLink, LPTSTR strStyle,
		short nWidth, LPTSTR strOrd, LPTSTR clrBack, LPTSTR clrFore)
{
	if (nWidth < 0)
		nWidth = 4;
	else if (nWidth > 9)
		nWidth = 9;

	if (!m_querySet.IsOpen())
	{
		CWaitCursor wait;
		m_querySet.Open();
	}
	if (!m_querySet.IsOpen())
	{
		return;
	}

	m_querySet.m_strFilter = _T("link = '");
	m_querySet.m_strFilter += strLink;
	m_querySet.m_strFilter += _T("'");
	m_querySet.Requery();

	CString strCount;

	if (m_querySet.IsEOF())
	{
		m_querySet.AddNew();
		m_querySet.m_link = strLink;
		m_querySet.m_count = 1;
	}
	else
	{
		m_querySet.MoveFirst();
		m_querySet.Edit();
		m_querySet.m_count ++;
	}

	try
	{
		m_querySet.Update();
	}
	catch (CDBException * e)
	{
		e->Delete();
	}

	if (nWidth == 0)
	{
		strCount.Format(_T("%d"), m_querySet.m_count);
		nWidth = strCount.GetLength();
	}
	else
	{
		strCount.Format(_T("%010d"), m_querySet.m_count);
		strCount = strCount.Right(nWidth);
	}

	CArray<CImage *, CImage*> imgSrc;
	BYTE * pData = NULL;
	CImage * image = NULL;
	TCHAR strPath[MAX_PATH] = _T("");
	TCHAR strName[MAX_PATH] = _T("");
	int i, x, y;
	byte r, g, b;
	CStdioFile fl;
	DWORD nLen;
	CString imgFile;
	CImage * img, * imgOrd;
	int nPerImageWidth, nImageHeight;

//	COLORREF clrFr, clrBk;

//	if (!ConvertStrToRGB(clrFore, clrFr))
//		clrFr = RGB(255, 255, 255);
//	if (!ConvertStrToRGB(clrBack, clrBk))
//		clrBk = RGB(0, 0, 0);

	if (!GetTempPath(MAX_PATH, strPath))
		goto error;

	if (!GetTempFileName(strPath, _T("cun"), 0, strName))
		goto error;

	image = new CImage(strName, CIMAGE_FORMAT_GIF);

	for (i = 0; i < nWidth; i ++)
	{
		imgFile = m_strPath;
		imgFile = imgFile.Left(imgFile.ReverseFind(_T('\\')) + 1);
		imgFile += strStyle;
		imgFile += _T("\\");
		imgFile+= strCount[i];
		imgFile += _T(".gif");

		img = new CImage(imgFile, CIMAGE_FORMAT_GIF);
		imgSrc.Add(img);
		
		if (img->GetWidth() <= 0)
			goto error;
	}

	if (lstrcmpi(strOrd, _T("yes")) == 0)
	{
		imgFile = _T("d:\\counter\\digits\\");
		imgFile += strStyle;
		imgFile += _T("\\");

		switch (strCount[nWidth - 1] - _T('0'))
		{
		case 1:
			imgFile += _T("st.gif");
			break;

		case 2:
			imgFile += _T("nd.gif");
			break;

		case 3:
			imgFile += _T("rd.gif");
			break;

		default:
			imgFile += _T("th.gif");
			break;
		}

		imgOrd = new CImage(imgFile, CIMAGE_FORMAT_GIF);
		if (imgOrd->GetWidth() <= 0)
			delete imgOrd;
		else
			imgSrc.Add(imgOrd);
	}

	nWidth = imgSrc.GetSize();
	nPerImageWidth = imgSrc[0]->GetWidth();
	nImageHeight = imgSrc[0]->GetHeight();
	image->Create(nPerImageWidth * nWidth, nImageHeight, 8);
	image->SetPalette(new CImagePalette(imgSrc[0]->GetPalette()));

	for (i = 0; i < nWidth; i ++)
	{
		for (y = 0; y < nImageHeight; y ++)
		{
			for (x = 0; x < nPerImageWidth; x ++)
			{
				imgSrc[i]->GetRGB(x, y, &r, &g, &b);
				
/*				if (r == 255 || g == 255 || b == 255)
				{
					r = (byte)(clrFr & 0x000000ff);
					g = (byte)((clrFr & 0x0000ff00) >> 8);
					b = (byte)((clrFr & 0x00ff0000) >> 16);
				}
				else
				{
					r = (byte)(clrBk & 0x000000ff);
					g = (byte)((clrBk & 0x0000ff00) >> 8);
					b = (byte)((clrBk & 0x00ff0000) >> 16);
				}
*/
				image->SetRGB(x + i * nPerImageWidth, y, r, g, b);
			}
		}
	}

	if (!image->SaveFile(strName, CIMAGE_FORMAT_GIF))
		goto error;

	if (!fl.Open(strName, CFile::modeRead | CFile::typeBinary))
		goto error;

	nLen = fl.GetLength();
	if (nLen == 0)
		goto error;

	pData = new BYTE[nLen];
	fl.Read(pData, nLen);
	fl.Close();

	pCtxt->m_pStream->Write(pData, nLen);

error:
	if (pData)
		delete [] pData;
	
	if (imgSrc.GetSize())
	{
		for (i = 0; i < imgSrc.GetSize(); i ++)
			delete imgSrc[i];
	}

	if (image)
		delete image;

	if (lstrlen(strName))
		DeleteFile(strName);
}

// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CCounterExtension, CHttpServer)
	//{{AFX_MSG_MAP(CCounterExtension)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0



///////////////////////////////////////////////////////////////////////
// If your extension will not use MFC, you'll need this code to make
// sure the extension objects can find the resource handle for the
// module.  If you convert your extension to not be dependent on MFC,
// remove the comments arounn the following AfxGetResourceHandle()
// and DllMain() functions, as well as the g_hInstance global.

/****

static HINSTANCE g_hInstance;

HINSTANCE AFXISAPI AfxGetResourceHandle()
{
	return g_hInstance;
}

BOOL WINAPI DllMain(HINSTANCE hInst, ULONG ulReason,
					LPVOID lpReserved)
{
	if (ulReason == DLL_PROCESS_ATTACH)
	{
		g_hInstance = hInst;
	}

	return TRUE;
}

****/

BOOL CCounterExtension::ConvertStrToRGB(CString strClr, COLORREF& clrRet)
{
	strClr.MakeLower();
	if (strClr.GetLength() != 6)
		return FALSE;

	BYTE r = 0, g = 0, b = 0;
	TCHAR ch;
	
	BYTE bt;

	for (int i = 0; i < 6; i ++)
	{
		ch = strClr[i];
		if (!ConvertCharToByte(ch, bt))
			return FALSE;

		switch (i)
		{
		case 0:
			r = bt;
			break;

		case 1:
			r = r * 16 + bt;
			break;

		case 2:
			g = bt;
			break;

		case 3:
			g = g * 16 + bt;
			break;

		case 4:
			b = bt;
			break;

		case 5:
			b = b * 16 + bt;
			break;
		}
	}

	clrRet = RGB(r, g, b);

	return TRUE;
}

BOOL CCounterExtension::ConvertCharToByte(TCHAR ch, BYTE &btRet)
{
	if (ch >= '0' && ch <= '9')
	{
		btRet = ch - '0';
		return TRUE;
	}
	else if (ch >= 'a' && ch <= 'f')
	{
		btRet = ch - 'a' + 10;
		return TRUE;
	}

	return FALSE;
}
