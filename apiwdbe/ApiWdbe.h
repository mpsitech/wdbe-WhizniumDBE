/**
	* \file ApiWdbe.h
	* Wdbe API library global functionality (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef APIWDBE_H
#define APIWDBE_H

#define WDBE_VERSION "1.1.44"
#define WDBE_VERSION_MAJOR 1
#define WDBE_VERSION_MINOR 1
#define WDBE_VERSION_SUB 44

#include "ApiWdbe_blks.h"

#include "WdbeQBnk1NPin.h"
#include "WdbeQBnkList.h"
#include "WdbeQCdcList.h"
#include "WdbeQCdcMNSignal.h"
#include "WdbeQCmdAInvpar.h"
#include "WdbeQCmdARetpar.h"
#include "WdbeQCmdHk1NVector.h"
#include "WdbeQCmdList.h"
#include "WdbeQCmdMNController.h"
#include "WdbeQCmp1NRelease.h"
#include "WdbeQCmpList.h"
#include "WdbeQCmpMNLibrary.h"
#include "WdbeQCpr1NCoreversion.h"
#include "WdbeQCprList.h"
#include "WdbeQCprMNPerson.h"
#include "WdbeQCvrAIp.h"
#include "WdbeQCvrAPlh.h"
#include "WdbeQCvrBcv1NCoreversion.h"
#include "WdbeQCvrHk1NModule.h"
#include "WdbeQCvrList.h"
#include "WdbeQErrAPar.h"
#include "WdbeQErrList.h"
#include "WdbeQFam1NUnit.h"
#include "WdbeQFamList.h"
#include "WdbeQFilList.h"
#include "WdbeQFstAStep.h"
#include "WdbeQFstList.h"
#include "WdbeQGenList.h"
#include "WdbeQIntList.h"
#include "WdbeQIntSrc1NSensitivity.h"
#include "WdbeQLibAMakefile.h"
#include "WdbeQLibList.h"
#include "WdbeQLibMNComponent.h"
#include "WdbeQMch1NRelease.h"
#include "WdbeQMchAMakefile.h"
#include "WdbeQMchAPar.h"
#include "WdbeQMchList.h"
#include "WdbeQMchSup1NMachine.h"
#include "WdbeQMod1NCdc.h"
#include "WdbeQMod1NProcess.h"
#include "WdbeQModAPar.h"
#include "WdbeQModCorMNModule.h"
#include "WdbeQModCtdMNModule.h"
#include "WdbeQModCtrHk1NVector.h"
#include "WdbeQModCtrMNCommand.h"
#include "WdbeQModCtrRef1NCommand.h"
#include "WdbeQModCtrRef1NError.h"
#include "WdbeQModHsm1NPipeline.h"
#include "WdbeQModKHdltype.h"
#include "WdbeQModList.h"
#include "WdbeQModMdl1NGeneric.h"
#include "WdbeQModMdl1NPort.h"
#include "WdbeQModMge1NSignal.h"
#include "WdbeQModMNPeripheral.h"
#include "WdbeQModRef1NSensitivity.h"
#include "WdbeQModRef1NSignal.h"
#include "WdbeQModRef1NVariable.h"
#include "WdbeQModSup1NModule.h"
#include "WdbeQMtpAPar.h"
#include "WdbeQMtpHsm1NPipeline.h"
#include "WdbeQMtpKHdltype.h"
#include "WdbeQMtpKParKey.h"
#include "WdbeQMtpList.h"
#include "WdbeQMtpMdl1NGeneric.h"
#include "WdbeQMtpMdl1NPort.h"
#include "WdbeQMtpMge1NSignal.h"
#include "WdbeQMtpRef1NFile.h"
#include "WdbeQMtpRef1NSensitivity.h"
#include "WdbeQMtpRef1NVariable.h"
#include "WdbeQMtpSup1NModule.h"
#include "WdbeQMtpTpl1NModule.h"
#include "WdbeQPinAPar.h"
#include "WdbeQPinList.h"
#include "WdbeQPphAPar.h"
#include "WdbeQPphList.h"
#include "WdbeQPphMNModule.h"
#include "WdbeQPplList.h"
#include "WdbeQPplPpl1NSegment.h"
#include "WdbeQPrcFsmFsm1NFsmstate.h"
#include "WdbeQPrcFsmHk1NVector.h"
#include "WdbeQPrcKHdltype.h"
#include "WdbeQPrcList.h"
#include "WdbeQPrcMge1NSignal.h"
#include "WdbeQPrcRef1NSensitivity.h"
#include "WdbeQPrcRef1NVariable.h"
#include "WdbeQPrjList.h"
#include "WdbeQPrjMNPerson.h"
#include "WdbeQPrjPrj1NVersion.h"
#include "WdbeQPrsADetail.h"
#include "WdbeQPrsList.h"
#include "WdbeQPrsMNCoreproject.h"
#include "WdbeQPrsMNProject.h"
#include "WdbeQPrtList.h"
#include "WdbeQPrtSrc1NSensitivity.h"
#include "WdbeQRlsList.h"
#include "WdbeQSegList.h"
#include "WdbeQSegSup1NSegment.h"
#include "WdbeQSigList.h"
#include "WdbeQSigMNCdc.h"
#include "WdbeQSigSrc1NSensitivity.h"
#include "WdbeQSil1NBank.h"
#include "WdbeQSil1NInterrupt.h"
#include "WdbeQSil1NPeripheral.h"
#include "WdbeQSilHk1NModule.h"
#include "WdbeQSilHk1NVector.h"
#include "WdbeQSilList.h"
#include "WdbeQSilRef1NCommand.h"
#include "WdbeQSilRef1NError.h"
#include "WdbeQSilRef1NSignal.h"
#include "WdbeQSilSil1NUnit.h"
#include "WdbeQSnsList.h"
#include "WdbeQUnt1NBank.h"
#include "WdbeQUnt1NInterrupt.h"
#include "WdbeQUnt1NPeripheral.h"
#include "WdbeQUntHk1NModule.h"
#include "WdbeQUntHk1NVector.h"
#include "WdbeQUntList.h"
#include "WdbeQUntRef1NCommand.h"
#include "WdbeQUntRef1NError.h"
#include "WdbeQUntRef1NSignal.h"
#include "WdbeQUntSil1NUnit.h"
#include "WdbeQUsgAAccess.h"
#include "WdbeQUsgList.h"
#include "WdbeQUsgMNUser.h"
#include "WdbeQUsr1NSession.h"
#include "WdbeQUsrAAccess.h"
#include "WdbeQUsrList.h"
#include "WdbeQUsrMNUsergroup.h"
#include "WdbeQVarList.h"
#include "WdbeQVecList.h"
#include "WdbeQVecVec1NVectoritem.h"
#include "WdbeQVer1NComponent.h"
#include "WdbeQVer1NUnit.h"
#include "WdbeQVerBvr1NVersion.h"
#include "WdbeQVerList.h"
#include "WdbeQVerRef1NFile.h"
#include "WdbeQVitList.h"

#include "CrdWdbeBnk.h"
#include "CrdWdbeCdc.h"
#include "CrdWdbeCmd.h"
#include "CrdWdbeCmp.h"
#include "CrdWdbeCpr.h"
#include "CrdWdbeCvr.h"
#include "CrdWdbeErr.h"
#include "CrdWdbeFam.h"
#include "CrdWdbeFil.h"
#include "CrdWdbeFst.h"
#include "CrdWdbeGen.h"
#include "CrdWdbeInt.h"
#include "CrdWdbeLib.h"
#include "CrdWdbeMch.h"
#include "CrdWdbeMod.h"
#include "CrdWdbeMtp.h"
#include "CrdWdbeNav.h"
#include "CrdWdbePin.h"
#include "CrdWdbePph.h"
#include "CrdWdbePpl.h"
#include "CrdWdbePrc.h"
#include "CrdWdbePrf.h"
#include "CrdWdbePrj.h"
#include "CrdWdbePrs.h"
#include "CrdWdbePrt.h"
#include "CrdWdbeRls.h"
#include "CrdWdbeSeg.h"
#include "CrdWdbeSig.h"
#include "CrdWdbeSil.h"
#include "CrdWdbeSns.h"
#include "CrdWdbeUnt.h"
#include "CrdWdbeUsg.h"
#include "CrdWdbeUsr.h"
#include "CrdWdbeUtl.h"
#include "CrdWdbeVar.h"
#include "CrdWdbeVec.h"
#include "CrdWdbeVer.h"
#include "CrdWdbeVit.h"
#include "DlgWdbeCprNew.h"
#include "DlgWdbeCvrBsccd.h"
#include "DlgWdbeCvrDetcd.h"
#include "DlgWdbeCvrNew.h"
#include "DlgWdbeCvrWrite.h"
#include "DlgWdbeFilDownload.h"
#include "DlgWdbeFilNew.h"
#include "DlgWdbeNavLoaini.h"
#include "DlgWdbeNavMnglic.h"
#include "DlgWdbePrjImpex.h"
#include "DlgWdbePrjNew.h"
#include "DlgWdbeRlsFinreptr.h"
#include "DlgWdbeRlsStareptr.h"
#include "DlgWdbeRlsWrite.h"
#include "DlgWdbeUsrMngkeypair.h"
#include "DlgWdbeUtlExtrip.h"
#include "DlgWdbeUtlMrgip.h"
#include "DlgWdbeVerCmdset.h"
#include "DlgWdbeVerCustfst.h"
#include "DlgWdbeVerDeploy.h"
#include "DlgWdbeVerDflalg.h"
#include "DlgWdbeVerFinmod.h"
#include "DlgWdbeVerGenfst.h"
#include "DlgWdbeVerMdlstr.h"
#include "DlgWdbeVerNew.h"
#include "PnlWdbeBnk1NPin.h"
#include "PnlWdbeBnkDetail.h"
#include "PnlWdbeBnkHeadbar.h"
#include "PnlWdbeBnkList.h"
#include "PnlWdbeBnkRec.h"
#include "PnlWdbeCdcDetail.h"
#include "PnlWdbeCdcHeadbar.h"
#include "PnlWdbeCdcList.h"
#include "PnlWdbeCdcMNSignal.h"
#include "PnlWdbeCdcRec.h"
#include "PnlWdbeCmdAInvpar.h"
#include "PnlWdbeCmdARetpar.h"
#include "PnlWdbeCmdDetail.h"
#include "PnlWdbeCmdHeadbar.h"
#include "PnlWdbeCmdHk1NVector.h"
#include "PnlWdbeCmdList.h"
#include "PnlWdbeCmdMNController.h"
#include "PnlWdbeCmdRec.h"
#include "PnlWdbeCmp1NRelease.h"
#include "PnlWdbeCmpDetail.h"
#include "PnlWdbeCmpHeadbar.h"
#include "PnlWdbeCmpList.h"
#include "PnlWdbeCmpMNLibrary.h"
#include "PnlWdbeCmpRec.h"
#include "PnlWdbeCpr1NCoreversion.h"
#include "PnlWdbeCprDetail.h"
#include "PnlWdbeCprHeadbar.h"
#include "PnlWdbeCprList.h"
#include "PnlWdbeCprMNPerson.h"
#include "PnlWdbeCprRec.h"
#include "PnlWdbeCvrAIp.h"
#include "PnlWdbeCvrAPlh.h"
#include "PnlWdbeCvrBcv1NCoreversion.h"
#include "PnlWdbeCvrDetail.h"
#include "PnlWdbeCvrHeadbar.h"
#include "PnlWdbeCvrHk1NModule.h"
#include "PnlWdbeCvrList.h"
#include "PnlWdbeCvrRec.h"
#include "PnlWdbeErrAPar.h"
#include "PnlWdbeErrDetail.h"
#include "PnlWdbeErrHeadbar.h"
#include "PnlWdbeErrList.h"
#include "PnlWdbeErrRec.h"
#include "PnlWdbeFam1NUnit.h"
#include "PnlWdbeFamDetail.h"
#include "PnlWdbeFamHeadbar.h"
#include "PnlWdbeFamList.h"
#include "PnlWdbeFamRec.h"
#include "PnlWdbeFilDetail.h"
#include "PnlWdbeFilHeadbar.h"
#include "PnlWdbeFilList.h"
#include "PnlWdbeFilRec.h"
#include "PnlWdbeFstAStep.h"
#include "PnlWdbeFstDetail.h"
#include "PnlWdbeFstHeadbar.h"
#include "PnlWdbeFstList.h"
#include "PnlWdbeFstRec.h"
#include "PnlWdbeGenDetail.h"
#include "PnlWdbeGenHeadbar.h"
#include "PnlWdbeGenList.h"
#include "PnlWdbeGenRec.h"
#include "PnlWdbeIntDetail.h"
#include "PnlWdbeIntHeadbar.h"
#include "PnlWdbeIntList.h"
#include "PnlWdbeIntRec.h"
#include "PnlWdbeIntSrc1NSensitivity.h"
#include "PnlWdbeLibAMakefile.h"
#include "PnlWdbeLibDetail.h"
#include "PnlWdbeLibHeadbar.h"
#include "PnlWdbeLibList.h"
#include "PnlWdbeLibMNComponent.h"
#include "PnlWdbeLibRec.h"
#include "PnlWdbeMch1NRelease.h"
#include "PnlWdbeMchAMakefile.h"
#include "PnlWdbeMchAPar.h"
#include "PnlWdbeMchDetail.h"
#include "PnlWdbeMchHeadbar.h"
#include "PnlWdbeMchList.h"
#include "PnlWdbeMchRec.h"
#include "PnlWdbeMchSup1NMachine.h"
#include "PnlWdbeMod1NCdc.h"
#include "PnlWdbeMod1NProcess.h"
#include "PnlWdbeModAPar.h"
#include "PnlWdbeModCorMNModule.h"
#include "PnlWdbeModCtdMNModule.h"
#include "PnlWdbeModCtrHk1NVector.h"
#include "PnlWdbeModCtrMNCommand.h"
#include "PnlWdbeModCtrRef1NCommand.h"
#include "PnlWdbeModCtrRef1NError.h"
#include "PnlWdbeModDetail.h"
#include "PnlWdbeModHeadbar.h"
#include "PnlWdbeModHsm1NPipeline.h"
#include "PnlWdbeModKHdltype.h"
#include "PnlWdbeModList.h"
#include "PnlWdbeModMdl1NGeneric.h"
#include "PnlWdbeModMdl1NPort.h"
#include "PnlWdbeModMge1NSignal.h"
#include "PnlWdbeModMNPeripheral.h"
#include "PnlWdbeModRec.h"
#include "PnlWdbeModRef1NSensitivity.h"
#include "PnlWdbeModRef1NSignal.h"
#include "PnlWdbeModRef1NVariable.h"
#include "PnlWdbeModSup1NModule.h"
#include "PnlWdbeMtpAPar.h"
#include "PnlWdbeMtpDetail.h"
#include "PnlWdbeMtpHeadbar.h"
#include "PnlWdbeMtpHsm1NPipeline.h"
#include "PnlWdbeMtpKHdltype.h"
#include "PnlWdbeMtpKParKey.h"
#include "PnlWdbeMtpList.h"
#include "PnlWdbeMtpMdl1NGeneric.h"
#include "PnlWdbeMtpMdl1NPort.h"
#include "PnlWdbeMtpMge1NSignal.h"
#include "PnlWdbeMtpRec.h"
#include "PnlWdbeMtpRef1NFile.h"
#include "PnlWdbeMtpRef1NSensitivity.h"
#include "PnlWdbeMtpRef1NVariable.h"
#include "PnlWdbeMtpSup1NModule.h"
#include "PnlWdbeMtpTpl1NModule.h"
#include "PnlWdbeNavAdmin.h"
#include "PnlWdbeNavAuxfct.h"
#include "PnlWdbeNavCoredev.h"
#include "PnlWdbeNavDeploy.h"
#include "PnlWdbeNavDevdev.h"
#include "PnlWdbeNavGlobal.h"
#include "PnlWdbeNavHeadbar.h"
#include "PnlWdbeNavHigh.h"
#include "PnlWdbeNavLow.h"
#include "PnlWdbeNavPre.h"
#include "PnlWdbePinAPar.h"
#include "PnlWdbePinDetail.h"
#include "PnlWdbePinHeadbar.h"
#include "PnlWdbePinList.h"
#include "PnlWdbePinRec.h"
#include "PnlWdbePphAPar.h"
#include "PnlWdbePphDetail.h"
#include "PnlWdbePphHeadbar.h"
#include "PnlWdbePphList.h"
#include "PnlWdbePphMNModule.h"
#include "PnlWdbePphRec.h"
#include "PnlWdbePplDetail.h"
#include "PnlWdbePplHeadbar.h"
#include "PnlWdbePplList.h"
#include "PnlWdbePplPpl1NSegment.h"
#include "PnlWdbePplRec.h"
#include "PnlWdbePrcDetail.h"
#include "PnlWdbePrcFsmFsm1NFsmstate.h"
#include "PnlWdbePrcFsmHk1NVector.h"
#include "PnlWdbePrcHeadbar.h"
#include "PnlWdbePrcKHdltype.h"
#include "PnlWdbePrcList.h"
#include "PnlWdbePrcMge1NSignal.h"
#include "PnlWdbePrcRec.h"
#include "PnlWdbePrcRef1NSensitivity.h"
#include "PnlWdbePrcRef1NVariable.h"
#include "PnlWdbePrfDaemon.h"
#include "PnlWdbePrfHeadbar.h"
#include "PnlWdbePrfLicense.h"
#include "PnlWdbePrjDetail.h"
#include "PnlWdbePrjHeadbar.h"
#include "PnlWdbePrjList.h"
#include "PnlWdbePrjMNPerson.h"
#include "PnlWdbePrjPrj1NVersion.h"
#include "PnlWdbePrjRec.h"
#include "PnlWdbePrsADetail.h"
#include "PnlWdbePrsDetail.h"
#include "PnlWdbePrsHeadbar.h"
#include "PnlWdbePrsList.h"
#include "PnlWdbePrsMNCoreproject.h"
#include "PnlWdbePrsMNProject.h"
#include "PnlWdbePrsRec.h"
#include "PnlWdbePrtDetail.h"
#include "PnlWdbePrtHeadbar.h"
#include "PnlWdbePrtList.h"
#include "PnlWdbePrtRec.h"
#include "PnlWdbePrtSrc1NSensitivity.h"
#include "PnlWdbeRlsDetail.h"
#include "PnlWdbeRlsHeadbar.h"
#include "PnlWdbeRlsList.h"
#include "PnlWdbeRlsRec.h"
#include "PnlWdbeSegDetail.h"
#include "PnlWdbeSegHeadbar.h"
#include "PnlWdbeSegList.h"
#include "PnlWdbeSegRec.h"
#include "PnlWdbeSegSup1NSegment.h"
#include "PnlWdbeSigDetail.h"
#include "PnlWdbeSigHeadbar.h"
#include "PnlWdbeSigList.h"
#include "PnlWdbeSigMNCdc.h"
#include "PnlWdbeSigRec.h"
#include "PnlWdbeSigSrc1NSensitivity.h"
#include "PnlWdbeSil1NBank.h"
#include "PnlWdbeSil1NInterrupt.h"
#include "PnlWdbeSil1NPeripheral.h"
#include "PnlWdbeSilDetail.h"
#include "PnlWdbeSilHeadbar.h"
#include "PnlWdbeSilHk1NModule.h"
#include "PnlWdbeSilHk1NVector.h"
#include "PnlWdbeSilList.h"
#include "PnlWdbeSilRec.h"
#include "PnlWdbeSilRef1NCommand.h"
#include "PnlWdbeSilRef1NError.h"
#include "PnlWdbeSilRef1NSignal.h"
#include "PnlWdbeSilSil1NUnit.h"
#include "PnlWdbeSnsDetail.h"
#include "PnlWdbeSnsHeadbar.h"
#include "PnlWdbeSnsList.h"
#include "PnlWdbeSnsRec.h"
#include "PnlWdbeUnt1NBank.h"
#include "PnlWdbeUnt1NInterrupt.h"
#include "PnlWdbeUnt1NPeripheral.h"
#include "PnlWdbeUntDetail.h"
#include "PnlWdbeUntHeadbar.h"
#include "PnlWdbeUntHk1NModule.h"
#include "PnlWdbeUntHk1NVector.h"
#include "PnlWdbeUntList.h"
#include "PnlWdbeUntRec.h"
#include "PnlWdbeUntRef1NCommand.h"
#include "PnlWdbeUntRef1NError.h"
#include "PnlWdbeUntRef1NSignal.h"
#include "PnlWdbeUntSil1NUnit.h"
#include "PnlWdbeUsgAAccess.h"
#include "PnlWdbeUsgDetail.h"
#include "PnlWdbeUsgHeadbar.h"
#include "PnlWdbeUsgList.h"
#include "PnlWdbeUsgMNUser.h"
#include "PnlWdbeUsgRec.h"
#include "PnlWdbeUsr1NSession.h"
#include "PnlWdbeUsrAAccess.h"
#include "PnlWdbeUsrDetail.h"
#include "PnlWdbeUsrHeadbar.h"
#include "PnlWdbeUsrList.h"
#include "PnlWdbeUsrMNUsergroup.h"
#include "PnlWdbeUsrRec.h"
#include "PnlWdbeUtlHeadbar.h"
#include "PnlWdbeVarDetail.h"
#include "PnlWdbeVarHeadbar.h"
#include "PnlWdbeVarList.h"
#include "PnlWdbeVarRec.h"
#include "PnlWdbeVecDetail.h"
#include "PnlWdbeVecHeadbar.h"
#include "PnlWdbeVecList.h"
#include "PnlWdbeVecRec.h"
#include "PnlWdbeVecVec1NVectoritem.h"
#include "PnlWdbeVer1NComponent.h"
#include "PnlWdbeVer1NUnit.h"
#include "PnlWdbeVerBvr1NVersion.h"
#include "PnlWdbeVerDetail.h"
#include "PnlWdbeVerHeadbar.h"
#include "PnlWdbeVerList.h"
#include "PnlWdbeVerRec.h"
#include "PnlWdbeVerRef1NFile.h"
#include "PnlWdbeVitDetail.h"
#include "PnlWdbeVitHeadbar.h"
#include "PnlWdbeVitList.h"
#include "PnlWdbeVitRec.h"
#include "QryWdbeBnk1NPin.h"
#include "QryWdbeBnkList.h"
#include "QryWdbeCdcList.h"
#include "QryWdbeCdcMNSignal.h"
#include "QryWdbeCmdAInvpar.h"
#include "QryWdbeCmdARetpar.h"
#include "QryWdbeCmdHk1NVector.h"
#include "QryWdbeCmdList.h"
#include "QryWdbeCmdMNController.h"
#include "QryWdbeCmp1NRelease.h"
#include "QryWdbeCmpList.h"
#include "QryWdbeCmpMNLibrary.h"
#include "QryWdbeCpr1NCoreversion.h"
#include "QryWdbeCprList.h"
#include "QryWdbeCprMNPerson.h"
#include "QryWdbeCvrAIp.h"
#include "QryWdbeCvrAPlh.h"
#include "QryWdbeCvrBcv1NCoreversion.h"
#include "QryWdbeCvrHk1NModule.h"
#include "QryWdbeCvrList.h"
#include "QryWdbeErrAPar.h"
#include "QryWdbeErrList.h"
#include "QryWdbeFam1NUnit.h"
#include "QryWdbeFamList.h"
#include "QryWdbeFilList.h"
#include "QryWdbeFstAStep.h"
#include "QryWdbeFstList.h"
#include "QryWdbeGenList.h"
#include "QryWdbeIntList.h"
#include "QryWdbeIntSrc1NSensitivity.h"
#include "QryWdbeLibAMakefile.h"
#include "QryWdbeLibList.h"
#include "QryWdbeLibMNComponent.h"
#include "QryWdbeMch1NRelease.h"
#include "QryWdbeMchAMakefile.h"
#include "QryWdbeMchAPar.h"
#include "QryWdbeMchList.h"
#include "QryWdbeMchSup1NMachine.h"
#include "QryWdbeMod1NCdc.h"
#include "QryWdbeMod1NProcess.h"
#include "QryWdbeModAPar.h"
#include "QryWdbeModCorMNModule.h"
#include "QryWdbeModCtdMNModule.h"
#include "QryWdbeModCtrHk1NVector.h"
#include "QryWdbeModCtrMNCommand.h"
#include "QryWdbeModCtrRef1NCommand.h"
#include "QryWdbeModCtrRef1NError.h"
#include "QryWdbeModHsm1NPipeline.h"
#include "QryWdbeModKHdltype.h"
#include "QryWdbeModList.h"
#include "QryWdbeModMdl1NGeneric.h"
#include "QryWdbeModMdl1NPort.h"
#include "QryWdbeModMge1NSignal.h"
#include "QryWdbeModMNPeripheral.h"
#include "QryWdbeModRef1NSensitivity.h"
#include "QryWdbeModRef1NSignal.h"
#include "QryWdbeModRef1NVariable.h"
#include "QryWdbeModSup1NModule.h"
#include "QryWdbeMtpAPar.h"
#include "QryWdbeMtpHsm1NPipeline.h"
#include "QryWdbeMtpKHdltype.h"
#include "QryWdbeMtpKParKey.h"
#include "QryWdbeMtpList.h"
#include "QryWdbeMtpMdl1NGeneric.h"
#include "QryWdbeMtpMdl1NPort.h"
#include "QryWdbeMtpMge1NSignal.h"
#include "QryWdbeMtpRef1NFile.h"
#include "QryWdbeMtpRef1NSensitivity.h"
#include "QryWdbeMtpRef1NVariable.h"
#include "QryWdbeMtpSup1NModule.h"
#include "QryWdbeMtpTpl1NModule.h"
#include "QryWdbePinAPar.h"
#include "QryWdbePinList.h"
#include "QryWdbePphAPar.h"
#include "QryWdbePphList.h"
#include "QryWdbePphMNModule.h"
#include "QryWdbePplList.h"
#include "QryWdbePplPpl1NSegment.h"
#include "QryWdbePrcFsmFsm1NFsmstate.h"
#include "QryWdbePrcFsmHk1NVector.h"
#include "QryWdbePrcKHdltype.h"
#include "QryWdbePrcList.h"
#include "QryWdbePrcMge1NSignal.h"
#include "QryWdbePrcRef1NSensitivity.h"
#include "QryWdbePrcRef1NVariable.h"
#include "QryWdbePrjList.h"
#include "QryWdbePrjMNPerson.h"
#include "QryWdbePrjPrj1NVersion.h"
#include "QryWdbePrsADetail.h"
#include "QryWdbePrsList.h"
#include "QryWdbePrsMNCoreproject.h"
#include "QryWdbePrsMNProject.h"
#include "QryWdbePrtList.h"
#include "QryWdbePrtSrc1NSensitivity.h"
#include "QryWdbeRlsList.h"
#include "QryWdbeSegList.h"
#include "QryWdbeSegSup1NSegment.h"
#include "QryWdbeSigList.h"
#include "QryWdbeSigMNCdc.h"
#include "QryWdbeSigSrc1NSensitivity.h"
#include "QryWdbeSil1NBank.h"
#include "QryWdbeSil1NInterrupt.h"
#include "QryWdbeSil1NPeripheral.h"
#include "QryWdbeSilHk1NModule.h"
#include "QryWdbeSilHk1NVector.h"
#include "QryWdbeSilList.h"
#include "QryWdbeSilRef1NCommand.h"
#include "QryWdbeSilRef1NError.h"
#include "QryWdbeSilRef1NSignal.h"
#include "QryWdbeSilSil1NUnit.h"
#include "QryWdbeSnsList.h"
#include "QryWdbeUnt1NBank.h"
#include "QryWdbeUnt1NInterrupt.h"
#include "QryWdbeUnt1NPeripheral.h"
#include "QryWdbeUntHk1NModule.h"
#include "QryWdbeUntHk1NVector.h"
#include "QryWdbeUntList.h"
#include "QryWdbeUntRef1NCommand.h"
#include "QryWdbeUntRef1NError.h"
#include "QryWdbeUntRef1NSignal.h"
#include "QryWdbeUntSil1NUnit.h"
#include "QryWdbeUsgAAccess.h"
#include "QryWdbeUsgList.h"
#include "QryWdbeUsgMNUser.h"
#include "QryWdbeUsr1NSession.h"
#include "QryWdbeUsrAAccess.h"
#include "QryWdbeUsrList.h"
#include "QryWdbeUsrMNUsergroup.h"
#include "QryWdbeVarList.h"
#include "QryWdbeVecList.h"
#include "QryWdbeVecVec1NVectoritem.h"
#include "QryWdbeVer1NComponent.h"
#include "QryWdbeVer1NUnit.h"
#include "QryWdbeVerBvr1NVersion.h"
#include "QryWdbeVerList.h"
#include "QryWdbeVerRef1NFile.h"
#include "QryWdbeVitList.h"
#include "RootWdbe.h"
#include "SessWdbe.h"

/**
	* StgWdbeapi
	*/
class StgWdbeapi : public Sbecore::Block {

public:
	static const Sbecore::uint ENGIP = 1;
	static const Sbecore::uint ENGPORT = 2;
	static const Sbecore::uint USERNAME = 3;
	static const Sbecore::uint PASSWORD = 4;

public:
	StgWdbeapi(const std::string engip = "", const Sbecore::uint engport = 0, const std::string username = "", const std::string password = "");

public:
	std::string engip;
	Sbecore::uint engport;
	std::string username;
	std::string password;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> compare(const StgWdbeapi* comp);
};

/**
	* ApiWdbe
	*/
namespace ApiWdbe {
	Sbecore::uint readDpchEng(char* buf, unsigned long buflen, DpchEngWdbe** dpcheng);
	void writeDpchApp(DpchAppWdbe* dpchapp, char** buf, unsigned long& buflen, unsigned long ofs = 0);
};

#endif
