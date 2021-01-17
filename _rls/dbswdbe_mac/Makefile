# file Makefile
# make file for Wdbe database access library, release dbswdbe_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 13 Jan 2021
# IP header --- ABOVE

LIBROOT = ${WHIZSDKROOT}/lib

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

STATLIB = ar
STATLIBFLAGS = rcs

INCPATH = -I${WHIZSDKROOT}/build -I/usr/local/include/libxml2 -I/usr/local/mysql/include

PCHS = DbsWdbe.h.gch

OBJS = DbsWdbe.o
OBJS += WdbeAccRMUserUniversal.o WdbeAMCommandInvpar.o WdbeAMCommandRetpar.o WdbeAMCoreversionIp.o WdbeAMCoreversionPlh.o WdbeAMErrorPar.o WdbeAMFsmstateStep.o WdbeAMLibraryMakefile.o WdbeAMMachineMakefile.o WdbeAMMachinePar.o WdbeAMModulePar.o WdbeAMPeripheralPar.o WdbeAMPersonDetail.o WdbeAMPinPar.o WdbeAMUserAccess.o WdbeAMUsergroupAccess.o WdbeAVControlPar.o WdbeAVKeylistKey.o WdbeAVValuelistVal.o WdbeCFile.o WdbeCFsmstate.o WdbeCGeneric.o WdbeCPin.o WdbeCPort.o WdbeCSignal.o WdbeCVariable.o WdbeHistRMUserUniversal.o WdbeJAVKeylistKey.o WdbeJMCoreversionState.o WdbeJMPersonLastname.o WdbeJMPinSref.o WdbeJMUserState.o WdbeJMVersionState.o WdbeMBank.o WdbeMCommand.o WdbeMController.o WdbeMCoreproject.o WdbeMCoreversion.o WdbeMError.o WdbeMFamily.o WdbeMFile.o WdbeMFsm.o WdbeMFsmstate.o WdbeMGeneric.o WdbeMImbuf.o WdbeMLibrary.o WdbeMMachine.o WdbeMModule.o WdbeMPeripheral.o WdbeMPerson.o WdbeMPin.o WdbeMPort.o WdbeMProcess.o WdbeMProject.o WdbeMRelease.o WdbeMSession.o WdbeMSignal.o WdbeMSystem.o WdbeMTarget.o WdbeMUnit.o WdbeMUser.o WdbeMUsergroup.o WdbeMVariable.o WdbeMVector.o WdbeMVectoritem.o WdbeMVersion.o WdbeRMCommandMController.o WdbeRMCoreprojectMPerson.o WdbeRMLibraryMVersion.o WdbeRMPersonMProject.o WdbeRMUsergroupUniversal.o WdbeRMUserMUsergroup.o
OBJS += WdbeQBnk1NPin.o WdbeQBnkList.o WdbeQCmdAInvpar.o WdbeQCmdARetpar.o WdbeQCmdList.o WdbeQCmdMNController.o WdbeQCpr1NCoreversion.o WdbeQCprList.o WdbeQCprMNPerson.o WdbeQCvrAIp.o WdbeQCvrAPlh.o WdbeQCvrBcv1NCoreversion.o WdbeQCvrHk1NModule.o WdbeQCvrList.o WdbeQErrAPar.o WdbeQErrList.o WdbeQFam1NUnit.o WdbeQFamList.o WdbeQFilList.o WdbeQFstAStep.o WdbeQFstList.o WdbeQGenList.o WdbeQLibAMakefile.o WdbeQLibList.o WdbeQLibMNVersion.o WdbeQMch1NRelease.o WdbeQMchAMakefile.o WdbeQMchAPar.o WdbeQMchList.o WdbeQMchSup1NMachine.o WdbeQMod1NPeripheral.o WdbeQMod1NProcess.o WdbeQModAPar.o WdbeQModCor1NImbuf.o WdbeQModCtrHk1NVector.o WdbeQModCtrMNCommand.o WdbeQModCtrRef1NCommand.o WdbeQModCtrRef1NError.o WdbeQModKHdltype.o WdbeQModList.o WdbeQModMdl1NGeneric.o WdbeQModMdl1NPort.o WdbeQModMdl1NSignal.o WdbeQModMge1NSignal.o WdbeQModSup1NModule.o WdbeQMtpAPar.o WdbeQMtpKHdltype.o WdbeQMtpKParKey.o WdbeQMtpList.o WdbeQMtpMdl1NGeneric.o WdbeQMtpMdl1NPort.o WdbeQMtpMge1NSignal.o WdbeQMtpRef1NFile.o WdbeQMtpSup1NModule.o WdbeQMtpTpl1NModule.o WdbeQPinAPar.o WdbeQPinList.o WdbeQPphAPar.o WdbeQPphList.o WdbeQPrcFsmFsm1NFsmstate.o WdbeQPrcKHdltype.o WdbeQPrcList.o WdbeQPrcMge1NSignal.o WdbeQPrcPrc1NVariable.o WdbeQPreselect.o WdbeQPrjList.o WdbeQPrjMNPerson.o WdbeQPrjPrj1NVersion.o WdbeQPrsADetail.o WdbeQPrsList.o WdbeQPrsMNCoreproject.o WdbeQPrsMNProject.o WdbeQPrtList.o WdbeQRlsList.o WdbeQSelect.o WdbeQSigList.o WdbeQSil1NBank.o WdbeQSil1NPeripheral.o WdbeQSil1NTarget.o WdbeQSilFwd1NController.o WdbeQSilHk1NModule.o WdbeQSilHk1NVector.o WdbeQSilList.o WdbeQSilRef1NCommand.o WdbeQSilRef1NError.o WdbeQSilSil1NUnit.o WdbeQSysHk1NVector.o WdbeQSysList.o WdbeQSysSys1NTarget.o WdbeQTrgList.o WdbeQUnt1NBank.o WdbeQUnt1NPeripheral.o WdbeQUnt1NTarget.o WdbeQUntFwd1NController.o WdbeQUntHk1NModule.o WdbeQUntHk1NVector.o WdbeQUntList.o WdbeQUntRef1NCommand.o WdbeQUntRef1NError.o WdbeQUntSil1NUnit.o WdbeQUsgAAccess.o WdbeQUsgList.o WdbeQUsgMNUser.o WdbeQUsr1NSession.o WdbeQUsrAAccess.o WdbeQUsrList.o WdbeQUsrMNUsergroup.o WdbeQVarList.o WdbeQVecList.o WdbeQVecVec1NVectoritem.o WdbeQVer1NRelease.o WdbeQVer1NSystem.o WdbeQVer1NUnit.o WdbeQVerBvr1NVersion.o WdbeQVerList.o WdbeQVerMNLibrary.o WdbeQVerRef1NFile.o WdbeQVitList.o

LIB = libdbswdbe

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(LIB)

$(LIB):	$(PCHS) $(OBJS)
	$(STATLIB) $(STATLIBFLAGS) $(LIB).a $(OBJS)
	rm -f *.o

install:
	mv $(LIB).a $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o
