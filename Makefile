# Makefile for the ROOT test programs.
# This Makefile shows nicely how to compile and link applications
# using the ROOT libraries on all supported platforms.
#
# Copyright (c) 2000 Rene Brun and Fons Rademakers
#
# Author: Fons Rademakers, 29/2/2000

include $(ROOTSYS)/etc/Makefile.arch
#-include ../MyConfig.mk

#------------------------------------------------------------------------------
IR = $(ROOTSYS)/include
$(shell test -d lib || mkdir lib)
L = lib/
S = $(PWD)/src/
ROOTLIBS     := $(shell root-config --glibs)

#clear the dictionaries
#$(shell rm $(S)/*Dict*)
EGS1 = $(wildcard $(S)/TEG*.$(SrcSuf))
EGDICTS = $(S)/TEGGenDict.$(SrcSuf)
$(shell touch $(S)/TEGGenDict.$(IncSuf) )
EGHD = $(patsubst $(S)/%.cxx, $(S)/%.h, $(EGS))
EGH = $(notdir $(EGHD))
#Dict object file should be first
EGS =  $(EGS1)
EGO = $(patsubst $(S)/%.$(SrcSuf), $(S)/%.$(ObjSuf), $(EGS))
EGDICTO = $(patsubst $(S)/%.$(SrcSuf), $(S)/%.$(ObjSuf), $(EGDICTS))
EGObj = $(notdir $(EGO))
EGSO = libEGGen.$(DllSuf)
ifeq ($(PLATFORM),win32)
EGLIB      = libEvent.lib
else
EGLIB      = $(shell pwd)/lib/$(EVENTSO)
endif
INCFLAGS += -I$(S) -I$(ROOTSYS)/include
#LDFLAGS +=  -O2 -pthread -m32 -c
#MAINEVENTO    = MainEvent.$(ObjSuf)
#MAINEVENTS    = MainEvent.$(SrcSuf)

OBJS          = $(EGO)
#PROGRAMS      = $(EVENT)
#OBJS         += $(GUITESTO) $(GUIVIEWERO) $(TETRISO)
#PROGRAMS     += $(GUITEST) $(GUIVIEWER) $(TETRISSO)

#------------------------------------------------------------------------------

.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf)
#.PHONY:    Aclock Hello Tetris

all:         $(EGSO)

$(EGSO):  $(EGO)    $(EGDICTO) 
ifeq ($(ARCH),aix)
		/usr/ibmcxx/bin/makeC++SharedLib $(OutPutOpt) $@ $(LIBS) -p 0 $^
else
ifeq ($(ARCH),aix5)
		/usr/vacpp/bin/makeC++SharedLib $(OutPutOpt) $@ $(LIBS) -p 0 $^
else
ifeq ($(PLATFORM),macosx)
# We need to make both the .dylib and the .so
		$(LD) $(SOFLAGS)$@ $(LDFLAGS) $^ $(OutPutOpt) $@
ifneq ($(subst $(MACOSX_MINOR),,1234),1234)
ifeq ($(MACOSX_MINOR),4)
		ln -sf $@ $(subst .$(DllSuf),.so,$@)
else
		$(LD) -bundle -undefined $(UNDEFOPT) $(LDFLAGS) $^ \
		   $(OutPutOpt) $(subst .$(DllSuf),.so,$@)
endif
endif
else
ifeq ($(PLATFORM),win32)
		bindexplib $* $^ > $*.def
		lib -nologo -MACHINE:IX86 $^ -def:$*.def \
		   $(OutPutOpt)$(EGLIB)
		$(LD) $(SOFLAGS) $(LDFLAGS) $^ $*.exp $(LIBS) \
		   $(OutPutOpt)$@
		$(MT_DLL)
else
		$(LD) $(SOFLAGS) $(LDFLAGS) $^ $(OutPutOpt) $@ $(EXPLLINKLIBS)
endif
endif
endif
endif
		@echo "$@ done"

#$(EG):       $(EGSO)
#		$(LD) $(LDFLAGS) $(EGLIB) $(LIBS) $(OutPutOpt)$@
#		$(MT_EXE)
#		@echo "$@ done"



clean:
		@rm -f $(EGO) $(EGSO) core
		@rm $(S)/*Dict*


.SUFFIXES: .$(SrcSuf)

###

$(EGDICTS): $(EGHD) $(S)EGGenLinkDef.h
	@rm -f src/*Dict*
	@echo "Generating dictionary $@..."
	@rootcint  -f $@ -c $(INCFLAGS) $^
	@echo "##-----------------------------------------------------------"

#.$(SrcSuf).$(ObjSuf):
%.$(ObjSuf): %.$(SrcSuf)
	$(CXX)  $(CXXFLAGS) $(INCFLAGS)  -o $@ -c $<

ifeq ($(GCC_MAJOR),4)
ifeq ($(GCC_MINOR),1)
TBenchDict.o: CXXFLAGS += -Wno-strict-aliasing
endif
endif
