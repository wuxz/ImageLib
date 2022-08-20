# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!IF "$(CFG)" == ""
CFG=jpeg - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to jpeg - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "jpeg - Win32 Release" && "$(CFG)" != "jpeg - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "jpeg.mak" CFG="jpeg - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "jpeg - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Debug" (based on "Win32 (x86) Static Library")
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
# PROP Target_Last_Scanned "jpeg - Win32 Debug"
CPP=cl.exe

!IF  "$(CFG)" == "jpeg - Win32 Release"

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

ALL : "$(OUTDIR)\jpeg.lib"

CLEAN : 
	-@erase ".\Release\jpeg.lib"
	-@erase ".\Release\Jdcolor.obj"
	-@erase ".\Release\Jcsample.obj"
	-@erase ".\Release\Jcmaster.obj"
	-@erase ".\Release\Jddctmgr.obj"
	-@erase ".\Release\Jdmarker.obj"
	-@erase ".\Release\Jdatadst.obj"
	-@erase ".\Release\Jdcoefct.obj"
	-@erase ".\Release\Jfdctflt.obj"
	-@erase ".\Release\Jquant2.obj"
	-@erase ".\Release\Jutils.obj"
	-@erase ".\Release\Jdapi.obj"
	-@erase ".\Release\Jidctflt.obj"
	-@erase ".\Release\Jidctfst.obj"
	-@erase ".\Release\Jdsample.obj"
	-@erase ".\Release\Jccoefct.obj"
	-@erase ".\Release\Jcprepct.obj"
	-@erase ".\Release\Jfdctint.obj"
	-@erase ".\Release\Jdhuff.obj"
	-@erase ".\Release\Jquant1.obj"
	-@erase ".\Release\Jidctint.obj"
	-@erase ".\Release\Jmemnobs.obj"
	-@erase ".\Release\Jdmainct.obj"
	-@erase ".\Release\Jcmainct.obj"
	-@erase ".\Release\Jdpostct.obj"
	-@erase ".\Release\Jcapi.obj"
	-@erase ".\Release\Jchuff.obj"
	-@erase ".\Release\Jdmerge.obj"
	-@erase ".\Release\Jidctred.obj"
	-@erase ".\Release\Jcdctmgr.obj"
	-@erase ".\Release\Jerror.obj"
	-@erase ".\Release\Jccolor.obj"
	-@erase ".\Release\Jmemmgr.obj"
	-@erase ".\Release\Jcomapi.obj"
	-@erase ".\Release\Jcmarker.obj"
	-@erase ".\Release\Jfdctfst.obj"
	-@erase ".\Release\Jcparam.obj"
	-@erase ".\Release\Jdatasrc.obj"
	-@erase ".\Release\Jdmaster.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /YX
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/jpeg.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/jpeg.lib" 
LIB32_OBJS= \
	".\Release\Jdcolor.obj" \
	".\Release\Jcsample.obj" \
	".\Release\Jcmaster.obj" \
	".\Release\Jddctmgr.obj" \
	".\Release\Jdmarker.obj" \
	".\Release\Jdatadst.obj" \
	".\Release\Jdcoefct.obj" \
	".\Release\Jfdctflt.obj" \
	".\Release\Jquant2.obj" \
	".\Release\Jutils.obj" \
	".\Release\Jdapi.obj" \
	".\Release\Jidctflt.obj" \
	".\Release\Jidctfst.obj" \
	".\Release\Jdsample.obj" \
	".\Release\Jccoefct.obj" \
	".\Release\Jcprepct.obj" \
	".\Release\Jfdctint.obj" \
	".\Release\Jdhuff.obj" \
	".\Release\Jquant1.obj" \
	".\Release\Jidctint.obj" \
	".\Release\Jmemnobs.obj" \
	".\Release\Jdmainct.obj" \
	".\Release\Jcmainct.obj" \
	".\Release\Jdpostct.obj" \
	".\Release\Jcapi.obj" \
	".\Release\Jchuff.obj" \
	".\Release\Jdmerge.obj" \
	".\Release\Jidctred.obj" \
	".\Release\Jcdctmgr.obj" \
	".\Release\Jerror.obj" \
	".\Release\Jccolor.obj" \
	".\Release\Jmemmgr.obj" \
	".\Release\Jcomapi.obj" \
	".\Release\Jcmarker.obj" \
	".\Release\Jfdctfst.obj" \
	".\Release\Jcparam.obj" \
	".\Release\Jdatasrc.obj" \
	".\Release\Jdmaster.obj"

"$(OUTDIR)\jpeg.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "jpeg - Win32 Debug"

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

ALL : "$(OUTDIR)\jpeg.lib"

CLEAN : 
	-@erase ".\Debug\jpeg.lib"
	-@erase ".\Debug\Jdcolor.obj"
	-@erase ".\Debug\Jidctflt.obj"
	-@erase ".\Debug\Jidctfst.obj"
	-@erase ".\Debug\Jdsample.obj"
	-@erase ".\Debug\Jcprepct.obj"
	-@erase ".\Debug\Jchuff.obj"
	-@erase ".\Debug\Jdapi.obj"
	-@erase ".\Debug\Jerror.obj"
	-@erase ".\Debug\Jidctint.obj"
	-@erase ".\Debug\Jquant2.obj"
	-@erase ".\Debug\Jutils.obj"
	-@erase ".\Debug\Jmemnobs.obj"
	-@erase ".\Debug\Jdmainct.obj"
	-@erase ".\Debug\Jcmaster.obj"
	-@erase ".\Debug\Jmemmgr.obj"
	-@erase ".\Debug\Jddctmgr.obj"
	-@erase ".\Debug\Jcparam.obj"
	-@erase ".\Debug\Jdhuff.obj"
	-@erase ".\Debug\Jcmainct.obj"
	-@erase ".\Debug\Jquant1.obj"
	-@erase ".\Debug\Jdpostct.obj"
	-@erase ".\Debug\Jidctred.obj"
	-@erase ".\Debug\Jcdctmgr.obj"
	-@erase ".\Debug\Jfdctflt.obj"
	-@erase ".\Debug\Jcmarker.obj"
	-@erase ".\Debug\Jfdctfst.obj"
	-@erase ".\Debug\Jcapi.obj"
	-@erase ".\Debug\Jdatasrc.obj"
	-@erase ".\Debug\Jccoefct.obj"
	-@erase ".\Debug\Jdmaster.obj"
	-@erase ".\Debug\Jfdctint.obj"
	-@erase ".\Debug\Jdmerge.obj"
	-@erase ".\Debug\Jcsample.obj"
	-@erase ".\Debug\Jccolor.obj"
	-@erase ".\Debug\Jcomapi.obj"
	-@erase ".\Debug\Jdmarker.obj"
	-@erase ".\Debug\Jdatadst.obj"
	-@erase ".\Debug\Jdcoefct.obj"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MDd /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /YX
CPP_PROJ=/nologo /MDd /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D\
 "_AFXDLL" /D "_MBCS" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/jpeg.bsc" 
BSC32_SBRS=
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
LIB32_FLAGS=/nologo /out:"$(OUTDIR)/jpeg.lib" 
LIB32_OBJS= \
	".\Debug\Jdcolor.obj" \
	".\Debug\Jidctflt.obj" \
	".\Debug\Jidctfst.obj" \
	".\Debug\Jdsample.obj" \
	".\Debug\Jcprepct.obj" \
	".\Debug\Jchuff.obj" \
	".\Debug\Jdapi.obj" \
	".\Debug\Jerror.obj" \
	".\Debug\Jidctint.obj" \
	".\Debug\Jquant2.obj" \
	".\Debug\Jutils.obj" \
	".\Debug\Jmemnobs.obj" \
	".\Debug\Jdmainct.obj" \
	".\Debug\Jcmaster.obj" \
	".\Debug\Jmemmgr.obj" \
	".\Debug\Jddctmgr.obj" \
	".\Debug\Jcparam.obj" \
	".\Debug\Jdhuff.obj" \
	".\Debug\Jcmainct.obj" \
	".\Debug\Jquant1.obj" \
	".\Debug\Jdpostct.obj" \
	".\Debug\Jidctred.obj" \
	".\Debug\Jcdctmgr.obj" \
	".\Debug\Jfdctflt.obj" \
	".\Debug\Jcmarker.obj" \
	".\Debug\Jfdctfst.obj" \
	".\Debug\Jcapi.obj" \
	".\Debug\Jdatasrc.obj" \
	".\Debug\Jccoefct.obj" \
	".\Debug\Jdmaster.obj" \
	".\Debug\Jfdctint.obj" \
	".\Debug\Jdmerge.obj" \
	".\Debug\Jcsample.obj" \
	".\Debug\Jccolor.obj" \
	".\Debug\Jcomapi.obj" \
	".\Debug\Jdmarker.obj" \
	".\Debug\Jdatadst.obj" \
	".\Debug\Jdcoefct.obj"

"$(OUTDIR)\jpeg.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
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

# Name "jpeg - Win32 Release"
# Name "jpeg - Win32 Debug"

!IF  "$(CFG)" == "jpeg - Win32 Release"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Jfdctint.c
DEP_CPP_JFDCT=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jdct.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jfdctint.obj" : $(SOURCE) $(DEP_CPP_JFDCT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jccoefct.c
DEP_CPP_JCCOE=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jccoefct.obj" : $(SOURCE) $(DEP_CPP_JCCOE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jccolor.c
DEP_CPP_JCCOL=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jccolor.obj" : $(SOURCE) $(DEP_CPP_JCCOL) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jcdctmgr.c
DEP_CPP_JCDCT=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jdct.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jcdctmgr.obj" : $(SOURCE) $(DEP_CPP_JCDCT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jchuff.c
DEP_CPP_JCHUF=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jchuff.obj" : $(SOURCE) $(DEP_CPP_JCHUF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jcmarker.c
DEP_CPP_JCMAR=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jcmarker.obj" : $(SOURCE) $(DEP_CPP_JCMAR) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jcmaster.c
DEP_CPP_JCMAS=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jcmaster.obj" : $(SOURCE) $(DEP_CPP_JCMAS) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jcomapi.c
DEP_CPP_JCOMA=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jcomapi.obj" : $(SOURCE) $(DEP_CPP_JCOMA) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jcparam.c
DEP_CPP_JCPAR=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jcparam.obj" : $(SOURCE) $(DEP_CPP_JCPAR) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jcprepct.c
DEP_CPP_JCPRE=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jcprepct.obj" : $(SOURCE) $(DEP_CPP_JCPRE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jcsample.c
DEP_CPP_JCSAM=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jcsample.obj" : $(SOURCE) $(DEP_CPP_JCSAM) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdatadst.c
DEP_CPP_JDATA=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jerror.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	

"$(INTDIR)\Jdatadst.obj" : $(SOURCE) $(DEP_CPP_JDATA) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdmainct.c
DEP_CPP_JDMAI=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jdmainct.obj" : $(SOURCE) $(DEP_CPP_JDMAI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jerror.c
DEP_CPP_JERRO=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jversion.h"\
	".\jerror.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	

"$(INTDIR)\Jerror.obj" : $(SOURCE) $(DEP_CPP_JERRO) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jfdctfst.c
DEP_CPP_JFDCTF=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jdct.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jfdctfst.obj" : $(SOURCE) $(DEP_CPP_JFDCTF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jcapi.c
DEP_CPP_JCAPI=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jcapi.obj" : $(SOURCE) $(DEP_CPP_JCAPI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jidctflt.c
DEP_CPP_JIDCT=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jdct.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jidctflt.obj" : $(SOURCE) $(DEP_CPP_JIDCT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jmemmgr.c
DEP_CPP_JMEMM=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jmemsys.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jmemmgr.obj" : $(SOURCE) $(DEP_CPP_JMEMM) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jmemnobs.c
DEP_CPP_JMEMN=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jmemsys.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jmemnobs.obj" : $(SOURCE) $(DEP_CPP_JMEMN) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jutils.c
DEP_CPP_JUTIL=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jutils.obj" : $(SOURCE) $(DEP_CPP_JUTIL) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdmerge.c
DEP_CPP_JDMER=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jdmerge.obj" : $(SOURCE) $(DEP_CPP_JDMER) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdatasrc.c
DEP_CPP_JDATAS=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jerror.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	

"$(INTDIR)\Jdatasrc.obj" : $(SOURCE) $(DEP_CPP_JDATAS) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdcoefct.c
DEP_CPP_JDCOE=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jdcoefct.obj" : $(SOURCE) $(DEP_CPP_JDCOE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdcolor.c
DEP_CPP_JDCOL=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jdcolor.obj" : $(SOURCE) $(DEP_CPP_JDCOL) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jddctmgr.c
DEP_CPP_JDDCT=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jdct.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jddctmgr.obj" : $(SOURCE) $(DEP_CPP_JDDCT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdhuff.c
DEP_CPP_JDHUF=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jdhuff.obj" : $(SOURCE) $(DEP_CPP_JDHUF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdmarker.c
DEP_CPP_JDMAR=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jdmarker.obj" : $(SOURCE) $(DEP_CPP_JDMAR) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdmaster.c
DEP_CPP_JDMAS=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jdmaster.obj" : $(SOURCE) $(DEP_CPP_JDMAS) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdapi.c
DEP_CPP_JDAPI=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jdapi.obj" : $(SOURCE) $(DEP_CPP_JDAPI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdpostct.c
DEP_CPP_JDPOS=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jdpostct.obj" : $(SOURCE) $(DEP_CPP_JDPOS) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jdsample.c
DEP_CPP_JDSAM=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jdsample.obj" : $(SOURCE) $(DEP_CPP_JDSAM) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jidctfst.c
DEP_CPP_JIDCTF=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jdct.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jidctfst.obj" : $(SOURCE) $(DEP_CPP_JIDCTF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jidctint.c
DEP_CPP_JIDCTI=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jdct.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jidctint.obj" : $(SOURCE) $(DEP_CPP_JIDCTI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jidctred.c
DEP_CPP_JIDCTR=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jdct.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jidctred.obj" : $(SOURCE) $(DEP_CPP_JIDCTR) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jquant1.c
DEP_CPP_JQUAN=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jquant1.obj" : $(SOURCE) $(DEP_CPP_JQUAN) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jquant2.c
DEP_CPP_JQUANT=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jquant2.obj" : $(SOURCE) $(DEP_CPP_JQUANT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jcmainct.c
DEP_CPP_JCMAI=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jcmainct.obj" : $(SOURCE) $(DEP_CPP_JCMAI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Jfdctflt.c
DEP_CPP_JFDCTFL=\
	".\jinclude.h"\
	".\jpeglib.h"\
	".\jdct.h"\
	".\jconfig.h"\
	{$(INCLUDE)}"\sys\Types.h"\
	".\jmorecfg.h"\
	".\jpegint.h"\
	".\jerror.h"\
	

"$(INTDIR)\Jfdctflt.obj" : $(SOURCE) $(DEP_CPP_JFDCTFL) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
