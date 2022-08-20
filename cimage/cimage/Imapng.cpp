/*
 * File:	imapng.cc
 * Purpose:	Platform Independent JPEG Image Class
 * Author:	Alejandro Aguilar Sierra
 * Created:	1995
 * Copyright: (c) 1995, Alejandro Aguilar Sierra <asierra@servidor.unam.mx>
 *
 *      logjmp
 */

// #include "stdafx.h"

#include "imapng.h"
#if CIMAGE_SUPPORT_PNG

extern "C" {
#include "png.h"
}

#include "imaiter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void
ima_png_error(png_struct *png_ptr, char *message)
{
//        AfxMessageBox(message);

	longjmp(png_ptr->jmpbuf, 1);
}

BOOL
CImagePNG::ReadFile(const CString& imageFileName)
{
  int number_passes;

  if (imageFileName != "")
    filename = imageFileName;

	FILE *fp;
	png_struct *png_ptr;
   png_info *info_ptr;
	CImageIterator iter(this);

	/* open the file */
	fp = fopen((const char *)filename, "rb");
	if (!fp)
		return FALSE;




	/* Create and initialize the png_struct with the desired error handler
    * functions.  If you want to use the default stderr and longjump method,
    * you can supply NULL for the last three parameters.  We also supply the
    * the compiler header file version, so that we know if the application
    * was compiled with a compatible version of the library.  REQUIRED
    */
   png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,
      (void *)NULL, NULL, NULL);

   if (png_ptr == NULL)
   {
      fclose(fp);
		return FALSE ;
   }

   /* Allocate/initialize the memory for image information.  REQUIRED. */
   info_ptr = png_create_info_struct(png_ptr);
   if (info_ptr == NULL)
   {
      fclose(fp);
      png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
		return FALSE ;
   }

   /* Set error handling if you are using the setjmp/longjmp method (this is
    * the normal method of doing things with libpng).  REQUIRED unless you
    * set up your own error handlers in the png_create_read_struct() earlier.
    */
   if (setjmp(png_ptr->jmpbuf))
   {
      /* Free all of the memory associated with the png_ptr and info_ptr */
      png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
      fclose(fp);
	  return FALSE ;
   }
	/* set up the input control */
	png_init_io(png_ptr, fp);

	/* read the file information */
	png_read_info(png_ptr, info_ptr);

	/* allocate the memory to hold the image using the fields
		of png_info. */
	png_color_16 my_background={ 0, 31, 127, 255, 0 };

	png_set_background(png_ptr, &my_background,
			PNG_BACKGROUND_GAMMA_SCREEN, 0, 1.0);

	/* tell libpng to strip 16 bit depth files down to 8 bits */
	if (info_ptr->bit_depth == 16)
		png_set_strip_16(png_ptr);

	int pixel_depth=(info_ptr->pixel_depth<24) ? info_ptr->pixel_depth: 24;
	Create(info_ptr->width, info_ptr->height, pixel_depth,
		info_ptr->color_type);

	if (info_ptr->num_palette>0)
	  SetPalette((int)info_ptr->num_palette, (rgb_color_struct*)info_ptr->palette);

	int row_stride = info_ptr->width * ((pixel_depth+7)>>3);

	byte *row_pointers = new byte[row_stride];

	/* turn on interlace handling */
	if (info_ptr->interlace_type)
		number_passes = png_set_interlace_handling(png_ptr);
	else
		number_passes = 1;
//	printf("NP = %d ", number_passes);

	for (int pass=0; pass< number_passes; pass++) {
	iter.Upset();
	int y=0;
	do	{
	  if (info_ptr->interlace_type)  {
		 if (pass>0)
			iter.GetRow(row_pointers, row_stride);
		 png_read_row(png_ptr, row_pointers, NULL);
	  }
	  else
		 png_read_row(png_ptr, row_pointers, NULL);

	  iter.SetRow(row_pointers, row_stride);
	  y++;
	} while(iter.PrevRow());
	}
	delete[] row_pointers;

	/* read the rest of the file, getting any additional chunks
		in info_ptr */
	png_read_end(png_ptr, info_ptr);


   /* clean up after the read, and free any memory allocated - REQUIRED */
   png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);


	/* close the file */
	fclose(fp);

	/* that's it */
	return TRUE;
}


/* write a png file */

BOOL CImagePNG::SaveFile(const CString& imageFileName)
{
	if (imageFileName != "")
		filename = imageFileName;

	CImageIterator iter(this);
	FILE *fp;
	png_struct *png_ptr;
	png_info *info_ptr;

   /* open the file */
	fp = fopen((const char *)filename, "wb");
	if (!fp)
		return FALSE;


   /* Create and initialize the png_struct with the desired error handler
    * functions.  If you want to use the default stderr and longjump method,
    * you can supply NULL for the last three parameters.  We also check that
    * the library version is compatible with the one used at compile time,
    * in case we are using dynamically linked libraries.  REQUIRED.
    */
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,
      (void *)NULL, NULL, NULL);

	if (png_ptr == NULL)
	{
		fclose(fp);
		/* If we get here, we had a problem reading the file */
		return FALSE;
	}

	   /* Allocate/initialize the image information data.  REQUIRED */
   info_ptr = png_create_info_struct(png_ptr);
   if (info_ptr == NULL)
   {
      fclose(fp);
      png_destroy_write_struct(&png_ptr,  (png_infopp)NULL);
      return FALSE;
   }

   /* Set error handling.  REQUIRED if you aren't supplying your own
    * error hadnling functions in the png_create_write_struct() call.
    */
   if (setjmp(png_ptr->jmpbuf))
   {
      /* If we get here, we had a problem reading the file */
      fclose(fp);
      png_destroy_write_struct(&png_ptr,  (png_infopp)&info_ptr);
      return FALSE;
   }

            
	int row_stride = GetWidth() * ((GetDepth()+7)>>3);
	/* set up the output control */
	 png_init_io(png_ptr, fp);

	/* set the file information here */
	info_ptr->width = GetWidth();
	info_ptr->height = GetHeight();
	info_ptr->pixel_depth = GetDepth();
	info_ptr->channels = (GetDepth()>8) ? 3: 1;
	info_ptr->bit_depth = GetDepth()/info_ptr->channels;
	info_ptr->color_type = GetColorType();
	info_ptr->compression_type = info_ptr->filter_type = info_ptr->interlace_type=0;
	info_ptr->valid = 0;
	info_ptr->rowbytes = row_stride;


// printf("P = %d D = %d RS= %d GD= %d CH= %d ", info_ptr->pixel_depth, info_ptr->bit_depth, row_stride, GetDepth(), info_ptr->channels);
	/* set the palette if there is one */
	if ((GetColorType() & COLORTYPE_PALETTE) && GetPalette())
	{
	 // printf("writig paleta[%d %d %x]",GetColorType() ,COLORTYPE_PALETTE, GetPalette());
	  info_ptr->valid |= PNG_INFO_PLTE;
	  info_ptr->palette = new png_color[256];
	  info_ptr->num_palette = 256;
	  for (int i=0; i<256; i++)
		 GetPalette()->GetRGB(i, &info_ptr->palette[i].red, &info_ptr->palette[i].green, &info_ptr->palette[i].blue);
	}  

	/* write the file information */
	png_write_info(png_ptr, info_ptr);
	/* If you are only writing one row at a time, this works */

	byte *row_pointers = new byte[row_stride];
  	iter.Upset();
	do	{
//	  (unsigned char *)iter.GetRow();
	  iter.GetRow(row_pointers, row_stride);
	  png_write_row(png_ptr, row_pointers);
	} while(iter.PrevRow());
        
        delete [] row_pointers;

   /* It is REQUIRED to call this to finish writing the rest of the file */
   png_write_end(png_ptr, info_ptr);

   /* if you malloced the palette, free it here */
   if (info_ptr->palette)
		delete[] (info_ptr->palette);

   /* clean up after the write, and free any memory allocated */
   png_destroy_write_struct(&png_ptr, (png_infopp)&info_ptr);

	/* close the file */
	fclose(fp);

	/* that's it */
	return TRUE;
}


#endif // CIMAGE_SUPPORT_PNG

