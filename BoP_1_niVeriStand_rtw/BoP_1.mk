# File    : BoP_1.mk (for Release 2010b and later)
#
# Abstract:
#       Real-Time Workshop template makefile for building a real-time
#       version of a Simulink model to run on National Instruments
#       RT Series hardware. This template makefile uses generated C code
#       and supports the Microsoft Visual C/C++ compiler.
#
#       Note that this template is automatically customized by the Real-Time
#       Workshop build procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#
#         OPT_OPTS       - Optimization option. See DEFAULT_OPT_OPTS in
#                          vctools.mak for default.
#         OPTS           - User specific options.
#         CPP_OPTS       - C++ compiler options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set NIDEBUG = 1, which will trigger OPTS=-Zi (may vary with
#                               compiler version, see compiler doc) 
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see grt.tlc

#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the Real-Time Workshop build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         		= nmake
HOST            		= PC
BUILD           		= yes
SYS_TARGET_FILE 		= NIVeriStand.tlc
BUILD_SUCCESS			= ^#^#^# Created

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  SOLVER              - Solver source file name
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  MEX_OPT_FILE        - mex option file name
#  VISUAL_VER          - Visual C++ version information

MODEL           		= BoP_1
MODULES         		= BoP_1_data.c ni_modelframework.c rtGetInf.c rtGetNaN.c rt_nonfinite.c rt_logging.c
MAKEFILE        		= BoP_1.mk
MATLAB_ROOT     		= C:\Program Files\MATLAB\R2017a
ALT_MATLAB_ROOT 		= C:\PROGRA~1\MATLAB\R2017a
MATLAB_BIN      		= C:\Program Files\MATLAB\R2017a\bin
ALT_MATLAB_BIN  		= C:\PROGRA~1\MATLAB\R2017a\bin
MASTER_ANCHOR_DIR    	= 
START_DIR          		= C:\Users\Darcy\Desktop\BOPDRA~1
S_FUNCTIONS     		= 
S_FUNCTIONS_LIB 		= 
SOLVER          		= 
NUMST           		= 1
TID01EQ         		= 0
NCSTATES        		= 0
BUILDARGS       		=  ISPROTECTINGMODEL=NOTPROTECTING NIDEBUG=0 NIOPT="Default" OPTS=""
MULTITASKING    		= 0
EXT_MODE        		= 0
MATLAB_VERSION			= R2017a
STR_MATLAB_VERSION 		= "$(MATLAB_VERSION)"

MODELREFS            	= 
SHARED_SRC          	= 
SHARED_SRC_DIR       	= 
SHARED_BIN_DIR       	= 
SHARED_LIB           	= 
TARGET_LANG_EXT			= c
VISUAL_VER				= 10.0
OPTIMIZATION_FLAGS   	= 
ADDITIONAL_LDFLAGS   	= 

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD          	= $(NIDEBUG)

NIVERISTAND_ROOT		= C:\VeriStand\2017
NIVERISTAND_LIB_DIR     = $(NIVERISTAND_ROOT)\ModelInterface\tmw\lib\x86\vc\$(VISUAL_VER)\$(MATLAB_VERSION)
!if "$(DEBUG_BUILD)" == "1"
NIVERISTAND_LIB_DIR 	= $(NIVERISTAND_LIB_DIR)\DEBUG
!else
NIVERISTAND_LIB_DIR 	= $(NIVERISTAND_LIB_DIR)\RELEASE
!endif

#--------------------------- Model and reference models -----------------------
MODELLIB                  				= BoP_1lib.lib
MODELREF_LINK_LIBS        		= 
MODELREF_LINK_RSPFILE			= BoP_1_ref.rsp
MODELREF_INC_PATH				= 
RELATIVE_PATH_TO_ANCHOR		= ..
# NONE: standalone, SIM: modelref sim, RTW: modelref rtw
MODELREF_TARGET_TYPE			= NONE

!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif

#--------------------------- Tool Specifications ------------------------------

# Optimize for 32-bit, used implictly by Win32.mk
CPU = i386
!include $(MATLAB_ROOT)\rtw\c\tools\vctools.mak
PERL = $(MATLAB_ROOT)\sys\perl\win32\bin\perl

#------------------------------ Include/Lib Path ------------------------------

MATLAB_INCLUDES = $(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common

# Additional file include paths

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)\BoP_1_niVeriStand_rtw

INCLUDE = $(INCLUDE);.;$(RELATIVE_PATH_TO_ANCHOR);$(MATLAB_INCLUDES);$(USER_INCLUDES)
INCLUDE = $(INCLUDE);$(MODELREF_INC_PATH)

!if "$(SHARED_SRC_DIR)" != ""
INCLUDE = $(INCLUDE);$(SHARED_SRC_DIR)		
!endif

#------------------------ rtModel ----------------------------------------------

RTM_CC_OPTS = -DUSE_RTMODEL

#----------------- Compiler and Linker Options --------------------------------

# Optimization Options
!if "$(NIOPT)" == "Default"
CC_OPTS = $(DEFAULT_OPT_OPTS)
!elseif "$(NIOPT)" == "Favor fast code"
# We see a performance hit with /Oi, so we don't use /O2 which uses it
CC_OPTS = /Og /Oy /Ob1 /Gs /GF /Gy /Ot
!elseif "$(NIOPT)" == "Favor small code"
CC_OPTS = /O1
!endif

# General User Options
!if "$(DEBUG_BUILD)" == "1"
CC_OPTS = $(CC_OPTS) /Zi /MDd
LDFLAGS = $(LDFLAGS) /DEBUG /PDB:$(MODEL).pdb
!else
CC_OPTS = $(CC_OPTS) /MD
!endif

USE_REBUILT_RTW_LIB_FILES = 1

!if "$(OPTIMIZATION_FLAGS)" != ""
CC_OPTS = $(CC_OPTS) $(OPTS) $(RTM_CC_OPTS) $(OPTIMIZATION_FLAGS)
!else
CC_OPTS = $(CC_OPTS) $(OPTS) $(RTM_CC_OPTS)
!endif

!if "$(MODELREF_TARGET_TYPE)" == "NONE"
CC_OPTS = $(CC_OPTS) -DNI_ROOTMODEL_$(MODEL)
!else
CC_OPTS = $(CC_OPTS) -DNI_REFMODEL_$(MODEL)
!endif

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
		  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
		  -DMT=$(MULTITASKING) -DHAVESTDIO -DNATIONAL_INSTRUMENTS_SIT \
		  -D_CRT_SECURE_NO_DEPRECATE

# Uncomment this line to move warning level to W4
# cflags = $(cflags:W3=W4)
CFLAGS   = $(cflags) $(cvarsdll) $(CFLAGS_VERSPECIFIC) \
           $(CC_OPTS) $(CPP_REQ_DEFINES)
CPPFLAGS = $(cflags) $(cvarsdll) $(CPPFLAGS_VERSPECIFIC) \
		   $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES)
LDFLAGS  = $(ldebug) $(dlllflags) $(conlibsdll) $(LDFLAGS) $(ADDITIONAL_LDFLAGS)

#----------------------------- Source Files -----------------------------------

MODEL_FILE		= $(MODEL).$(TARGET_LANG_EXT)
MODEL_DATA_FILE	= $(MODEL)_data.$(TARGET_LANG_EXT)

#Shared library
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
PRODUCT   = $(MODEL).dll
REQ_SRCS  = $(MODEL_FILE) $(MODULES) rt_sim.c $(SOLVER) $(MODEL).rc
!else
#Model Reference Target
PRODUCT   = $(MODELLIB)
REQ_SRCS  = $(MODULES)
!endif

USER_SRCS =

SRCS = $(REQ_SRCS) $(USER_SRCS) $(S_FUNCTIONS)
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS_C_LOWER = $(OBJS_C_UPPER:.c=.obj)
OBJS = $(OBJS_C_LOWER:.rc=.res)

SHARED_OBJS_CPP_UPPER = $(SHARED_SRC:.CPP=.obj)
SHARED_OBJS_CPP_LOWER = $(SHARED_OBJS_CPP_UPPER:.cpp=.obj)
SHARED_OBJS_C_UPPER = $(SHARED_OBJS_CPP_LOWER:.C=.obj)
SHARED_OBJS = $(SHARED_OBJS_C_UPPER:.c=.obj)

# ------------------------- Additional Libraries ------------------------------

LIBS =


LIBS = $(LIBS)

# ---------------------------- Linker Script ----------------------------------

CMD_FILE = $(MODEL).lnk
GEN_LNK_SCRIPT = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl
MANIFEST_FILE = $(PRODUCT).manifest

#--------------------------------- Rules --------------------------------------
all: set_environment_variables $(PRODUCT)

# Recompilation will occur if a change is detected in the source, but not necessarily if only type definitions have changed. 
# To guarantee all model references are using the parameter type definition, we must call clean before each build.

!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Stand-alone model ---
$(PRODUCT) : create_lib_dir clean $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS)
	@echo ### Linking ...
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) $(LDFLAGS) $(S_FUNCTIONS_LIB) $(SHARED_LIB) $(LIBS) $(MAT_LIBS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) /dll -out:$@
	@if exist $(MANIFEST_FILE) mt.exe -manifest $(MANIFEST_FILE) -outputresource:$@;2
	@echo $(BUILD_SUCCESS) library : %cd%\$(PRODUCT)
!else
#--- Model reference RTW Target ---
$(PRODUCT) : create_lib_dir clean $(OBJS) $(SHARED_LIB)
	@echo ### Linking ...
	$(PERL) $(GEN_LNK_SCRIPT) $(CMD_FILE) $(OBJS)
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE) $(S_FUNCTIONS_LIB)
	@echo $(BUILD_SUCCESS) static library : %cd%\$(PRODUCT)
!endif

# Create the lib folder if it does not exist.
create_lib_dir :
	@IF NOT EXIST "$(NIVERISTAND_LIB_DIR)" (mkdir "$(NIVERISTAND_LIB_DIR)" )

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

# Additional sources
	
{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<


{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<
{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<


{$(MATLAB_ROOT)\rtw\c\src}.c{$(NIVERISTAND_LIB_DIR)}.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $< /Fo$@
{$(MATLAB_ROOT)\simulink\src}.c{$(NIVERISTAND_LIB_DIR)}.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $< /Fo$@


{$(MATLAB_ROOT)\rtw\c\src}.cpp{$(NIVERISTAND_LIB_DIR)}.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $< /Fo$@
{$(MATLAB_ROOT)\simulink\src}.cpp{$(NIVERISTAND_LIB_DIR)}.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $< /Fo$@


# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

# Put these rule last, otherwise nmake will check toolboxes first

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<
	
.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

.rc.res : 
	@echo ### Compiling $<
	$(RC) $<
	
!if "$(TARGET_LANG_EXT)" ==  "cpp"
$(MODEL).obj :
	@echo ### Compiling model source: $(MODEL_FILE)
	$(CC) $(CPPFLAGS) -DNI_VERISTAND_MAINMODELFILE $(MODEL_FILE)

$(MODEL)_data.obj :
	@echo ### Compiling model data file: $(MODEL_DATA_FILE)
	$(CC) $(CPPFLAGS) -DNI_VERISTAND_MODELDATAFILE $(MODEL_DATA_FILE)
!else
$(MODEL).obj :
	@echo ### Compiling model source: $(MODEL_FILE)
	$(CC) $(CFLAGS) -DNI_VERISTAND_MAINMODELFILE $(MODEL_FILE)

$(MODEL)_data.obj :
	@echo ### Compiling model data file: $(MODEL_DATA_FILE)
	$(CC) $(CFLAGS) -DNI_VERISTAND_MODELDATAFILE $(MODEL_DATA_FILE)
!endif

!if "$(SHARED_LIB)" != ""
$(SHARED_LIB) : $(SHARED_SRC)
	@echo ### Creating $@
	@$(CC) $(CFLAGS) -Fo$(SHARED_BIN_DIR)\ $?
	@$(LIBCMD) /nologo /out:$@ $(SHARED_OBJS)
	@echo $(BUILD_SUCCESS) static library : $@ 
!endif

set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

# Libraries:







#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

#----------------------------- Utilities -----------------------------------

clean:
	@echo ### Deleting the objects and $(PRODUCT)
	-del /F /Q $(OBJS) $(CMD_FILE) $(MANIFEST_FILE) $(PRODUCT)