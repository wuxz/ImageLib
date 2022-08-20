# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!IF "$(CFG)" == ""
CFG=cimage - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to cimage - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "cimage - Win32 Release" && "$(CFG)" != "cimage - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "cimage.mak" CFG="cimage - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cimage - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "cimage - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "cimage - Win32 Debug"
CPP=cl.exe

!IF  "$(CFG)" == "cimage - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\cimage.lib"

CLEAN : 
	-@erase ".\Release\cimage.lib"
	-@erase ".\Release\Imajpg.obj"
	-@erase ".\Release\Imapng.obj"
	-@erase ".\Release\Gifdecod.obj"
	-@erase ".\Release\Imabmp.obj"
	-@erase ".\Release\Imagif.obj"
	-@erase ".\Release\cimage.obj"
	-@erase ".\Release\cmap.obj"
	-@erase ".\Release\cimageb.obj"
	-@erase ".\Release\Dibutils.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../jpeg" /I "../png" /I "../zlib" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /YX
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "../jpeg" /I "../png" /I "../zlib" /D\
 "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/cimage.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/cimage.lib" 
LIB32_OBJS= \
	"$(INTDIR)/Imajpg.obj" \
	"$(INTDIR)/Imapng.obj" \
	"$(INTDIR)/Gifdecod.obj" \
	"$(INTDIR)/Imabmp.obj" \
	"$(INTDIR)/Imagif.obj" \
	"$(INTDIR)/cimage.obj" \
	"$(INTDIR)/cmap.obj" \
	"$(INTDIR)/cimageb.obj" \
	"$(INTDIR)/Dibutils.obj"

"$(OUTDIR)\cimage.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "cimage - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\cimage.lib"

CLEAN : 
	-@erase ".\Debug\cimage.lib"
	-@erase ".\Debug\cimage.obj"
	-@erase ".\Debug\cmap.obj"
	-@erase ".\Debug\Imagif.obj"
	-@erase ".\Debug\Gifdecod.obj"
	-@erase ".\Debug\Dibutils.obj"
	-@erase ".\Debug\cimageb.obj"
	-@erase ".\Debug\Imabmp.obj"
	-@erase ".\Debug\Imajpg.obj"
	-@erase ".\Debug\Imapng.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MDd /W3 /GX /Z7 /Od /I "../jpeg" /I "../png" /I "../zlib" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /MDd /W3 /GX /Z7 /Od /I "../jpeg" /I "../png" /I "../zlib" /D\
 "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/cimage.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/cimage.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/cimage.lib" 
LIB32_OBJS= \
	"$(INTDIR)/cimage.obj" \
	"$(INTDIR)/cmap.obj" \
	"$(INTDIR)/Imagif.obj" \
	"$(INTDIR)/Gifdecod.obj" \
	"$(INTDIR)/Dibutils.obj" \
	"$(INTDIR)/cimageb.obj" \
	"$(INTDIR)/Imabmp.obj" \
	"$(INTDIR)/Imajpg.obj" \
	"$(INTDIR)/Imapng.obj"

"$(OUTDIR)\cimage.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "cimage - Win32 Release"
# Name "cimage - Win32 Debug"

!IF  "$(CFG)" == "cimage - Win32 Release"

!ELSEIF  "$(CFG)" == "cimage - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Imapng.cpp
DEP_CPP_IMAPN=\
	".\Imapng.h"\
	".\../png\png.h"\
	".\Imaiter.h"\
	".\Imafile.h"\
	".\cimageb.h"\
	".\StdAfx.h"\
	".\cmap.h"\
	".\../zlib\zlib.h"\
	".\..\png\pngconf.h"\
	".\..\zlib\zconf.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\cimage.h"\
	
NODEP_CPP_IMAPN=\
	".\..\png\alloc.h"\
	

"$(INTDIR)\Imapng.obj" : $(SOURCE) $(DEP_CPP_IMAPN) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\cimageb.cpp
DEP_CPP_CIMAG=\
	".\StdAfx.h"\
	".\cmap.h"\
	".\cimageb.h"\
	".\dibutils.h"\
	

"$(INTDIR)\cimageb.obj" : $(SOURCE) $(DEP_CPP_CIMAG) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\cmap.cpp
DEP_CPP_CMAP_=\
	".\StdAfx.h"\
	".\cmap.h"\
	

"$(INTDIR)\cmap.obj" : $(SOURCE) $(DEP_CPP_CMAP_) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dibutils.cpp
DEP_CPP_DIBUT=\
	".\StdAfx.h"\
	".\dibutils.h"\
	

"$(INTDIR)\Dibutils.obj" : $(SOURCE) $(DEP_CPP_DIBUT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Gifdecod.cpp
DEP_CPP_GIFDE=\
	".\StdAfx.h"\
	".\gifdecod.h"\
	

"$(INTDIR)\Gifdecod.obj" : $(SOURCE) $(DEP_CPP_GIFDE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Imabmp.cpp
DEP_CPP_IMABM=\
	".\Imabmp.h"\
	".\dibutils.h"\
	".\Imafile.h"\
	".\cimageb.h"\
	".\StdAfx.h"\
	".\cmap.h"\
	

"$(INTDIR)\Imabmp.obj" : $(SOURCE) $(DEP_CPP_IMABM) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Imagif.cpp
DEP_CPP_IMAGI=\
	".\Imagif.h"\
	".\Imaiter.h"\
	".\gifdecod.h"\
	".\Imafile.h"\
	".\cimageb.h"\
	".\StdAfx.h"\
	".\cmap.h"\
	".\cimage.h"\
	

"$(INTDIR)\Imagif.obj" : $(SOURCE) $(DEP_CPP_IMAGI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Imajpg.cpp
DEP_CPP_IMAJP=\
	".\Imajpg.h"\
	".\../jpeg\jpeglib.h"\
	".\Imaiter.h"\
	".\Imafile.h"\
	".\cimageb.h"\
	".\StdAfx.h"\
	".\cmap.h"\
	".\..\jpeg\jconfig.h"\
	".\..\jpeg\jmorecfg.h"\
	".\..\jpeg\jpegint.h"\
	".\..\jpeg\jerror.h"\
	".\cimage.h"\
	

"$(INTDIR)\Imajpg.obj" : $(SOURCE) $(DEP_CPP_IMAJP) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\cimage.cpp
DEP_CPP_CIMAGE=\
	".\StdAfx.h"\
	".\cimage.h"\
	".\Imajpg.h"\
	".\Imagif.h"\
	".\Imapng.h"\
	".\Imabmp.h"\
	".\cimageb.h"\
	".\cmap.h"\
	".\Imafile.h"\
	

"$(INTDIR)\cimage.obj" : $(SOURCE) $(DEP_CPP_CIMAGE) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
