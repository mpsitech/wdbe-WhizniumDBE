# file Makefile
# make file for Wdbe database access library, release dbswdbe_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 5 Nov 2025
# IP header --- ABOVE

LIBROOT = ${WHIZSDKROOT}/lib

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

STATLIB = ar
STATLIBFLAGS = rcs

INCPATH = -I${WHIZSDKROOT}/build -I/usr/include/jsoncpp -I/usr/include/libxml2 -I/usr/include/mariadb

PCHS = DbsWdbe.h.gch

OBJS = DbsWdbe.o
OBJS += WdbeAccRMUserUniversal.o WdbeAMCommandInvpar.o WdbeAMCommandRetpar.o WdbeAMCoreversionIp.o WdbeAMCoreversionPlh.o WdbeAMErrorPar.o WdbeAMFsmstateStep.o WdbeAMLibraryMakefile.o WdbeAMMachineMakefile.o WdbeAMMachinePar.o WdbeAMModulePar.o WdbeAMPeripheralPar.o WdbeAMPersonDetail.o WdbeAMPinPar.o WdbeAMUserAccess.o WdbeAMUsergroupAccess.o WdbeAVControlPar.o WdbeAVKeylistKey.o WdbeAVValuelistVal.o WdbeCFile.o WdbeCFsmstate.o WdbeCGeneric.o WdbeCPin.o WdbeCPort.o WdbeCSegment.o WdbeCSignal.o WdbeCVariable.o WdbeHistRMUserUniversal.o WdbeJAVKeylistKey.o WdbeJMCoreversionState.o WdbeJMPersonLastname.o WdbeJMPinSref.o WdbeJMUserState.o WdbeJMVersionState.o WdbeMBank.o WdbeMCdc.o WdbeMCommand.o WdbeMComponent.o WdbeMController.o WdbeMCoreproject.o WdbeMCoreversion.o WdbeMError.o WdbeMFamily.o WdbeMFile.o WdbeMFsm.o WdbeMFsmstate.o WdbeMGeneric.o WdbeMImbuf.o WdbeMInterrupt.o WdbeMLibrary.o WdbeMMachine.o WdbeMModule.o WdbeMPeripheral.o WdbeMPerson.o WdbeMPin.o WdbeMPipeline.o WdbeMPort.o WdbeMProcess.o WdbeMProject.o WdbeMRelease.o WdbeMSegment.o WdbeMSensitivity.o WdbeMSession.o WdbeMSignal.o WdbeMUnit.o WdbeMUser.o WdbeMUsergroup.o WdbeMVariable.o WdbeMVector.o WdbeMVectoritem.o WdbeMVersion.o WdbeRMCdcMSignal.o WdbeRMCommandMController.o WdbeRMComponentMLibrary.o WdbeRMCoreprojectMPerson.o WdbeRMModuleMModule.o WdbeRMModuleMPeripheral.o WdbeRMPersonMProject.o WdbeRMUsergroupUniversal.o WdbeRMUserMUsergroup.o
OBJS += WdbeQBnk1NPin.o WdbeQBnkList.o WdbeQCdcList.o WdbeQCdcMNSignal.o WdbeQCmdAInvpar.o WdbeQCmdARetpar.o WdbeQCmdHk1NVector.o WdbeQCmdList.o WdbeQCmdMNController.o WdbeQCmp1NRelease.o WdbeQCmpList.o WdbeQCmpMNLibrary.o WdbeQCpr1NCoreversion.o WdbeQCprList.o WdbeQCprMNPerson.o WdbeQCvrAIp.o WdbeQCvrAPlh.o WdbeQCvrBcv1NCoreversion.o WdbeQCvrHk1NModule.o WdbeQCvrList.o WdbeQErrAPar.o WdbeQErrList.o WdbeQFam1NUnit.o WdbeQFamList.o WdbeQFilList.o WdbeQFstAStep.o WdbeQFstList.o WdbeQGenList.o WdbeQIntList.o WdbeQIntSrc1NSensitivity.o WdbeQLibAMakefile.o WdbeQLibList.o WdbeQLibMNComponent.o WdbeQMch1NRelease.o WdbeQMchAMakefile.o WdbeQMchAPar.o WdbeQMchList.o WdbeQMchSup1NMachine.o WdbeQMod1NCdc.o WdbeQMod1NProcess.o WdbeQModAPar.o WdbeQModCorMNModule.o WdbeQModCtdMNModule.o WdbeQModCtrHk1NVector.o WdbeQModCtrMNCommand.o WdbeQModCtrRef1NCommand.o WdbeQModCtrRef1NError.o WdbeQModHsm1NPipeline.o WdbeQModKHdltype.o WdbeQModList.o WdbeQModMdl1NGeneric.o WdbeQModMdl1NPort.o WdbeQModMge1NSignal.o WdbeQModMNPeripheral.o WdbeQModRef1NSensitivity.o WdbeQModRef1NSignal.o WdbeQModRef1NVariable.o WdbeQModSup1NModule.o WdbeQMtpAPar.o WdbeQMtpHsm1NPipeline.o WdbeQMtpKHdltype.o WdbeQMtpKParKey.o WdbeQMtpList.o WdbeQMtpMdl1NGeneric.o WdbeQMtpMdl1NPort.o WdbeQMtpMge1NSignal.o WdbeQMtpRef1NFile.o WdbeQMtpRef1NSensitivity.o WdbeQMtpRef1NVariable.o WdbeQMtpSup1NModule.o WdbeQMtpTpl1NModule.o WdbeQPinAPar.o WdbeQPinList.o WdbeQPphAPar.o WdbeQPphList.o WdbeQPphMNModule.o WdbeQPplList.o WdbeQPplPpl1NSegment.o WdbeQPrcFsmFsm1NFsmstate.o WdbeQPrcFsmHk1NVector.o WdbeQPrcKHdltype.o WdbeQPrcList.o WdbeQPrcMge1NSignal.o WdbeQPrcRef1NSensitivity.o WdbeQPrcRef1NVariable.o WdbeQPreselect.o WdbeQPrjList.o WdbeQPrjMNPerson.o WdbeQPrjPrj1NVersion.o WdbeQPrsADetail.o WdbeQPrsList.o WdbeQPrsMNCoreproject.o WdbeQPrsMNProject.o WdbeQPrtList.o WdbeQPrtSrc1NSensitivity.o WdbeQRlsList.o WdbeQSegList.o WdbeQSegSup1NSegment.o WdbeQSelect.o WdbeQSigList.o WdbeQSigMNCdc.o WdbeQSigSrc1NSensitivity.o WdbeQSil1NBank.o WdbeQSil1NInterrupt.o WdbeQSil1NPeripheral.o WdbeQSilHk1NModule.o WdbeQSilHk1NVector.o WdbeQSilList.o WdbeQSilRef1NCommand.o WdbeQSilRef1NError.o WdbeQSilRef1NSignal.o WdbeQSilSil1NUnit.o WdbeQSnsList.o WdbeQUnt1NBank.o WdbeQUnt1NInterrupt.o WdbeQUnt1NPeripheral.o WdbeQUntHk1NModule.o WdbeQUntHk1NVector.o WdbeQUntList.o WdbeQUntRef1NCommand.o WdbeQUntRef1NError.o WdbeQUntRef1NSignal.o WdbeQUntSil1NUnit.o WdbeQUsgAAccess.o WdbeQUsgList.o WdbeQUsgMNUser.o WdbeQUsr1NSession.o WdbeQUsrAAccess.o WdbeQUsrList.o WdbeQUsrMNUsergroup.o WdbeQVarList.o WdbeQVecList.o WdbeQVecVec1NVectoritem.o WdbeQVer1NComponent.o WdbeQVer1NUnit.o WdbeQVerBvr1NVersion.o WdbeQVerList.o WdbeQVerRef1NFile.o WdbeQVitList.o

LIB = libdbswdbe

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(LIB)

$(LIB):	$(PCHS) $(OBJS)
	$(STATLIB) $(STATLIBFLAGS) $(LIB).a $(OBJS)

install:
	mv $(LIB).a $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o
