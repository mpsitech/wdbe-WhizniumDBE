/**
	* \file DbsWdbe.h
	* C++ wrapper for database DbsWdbe (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef DBSWDBE_H
#define DBSWDBE_H

#define WDBE_VERSION "1.1.20"
#define WDBE_VERSION_MAJOR 1
#define WDBE_VERSION_MINOR 1
#define WDBE_VERSION_SUB 20

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include "WdbeAccRMUserUniversal.h"
#include "WdbeAMCommandInvpar.h"
#include "WdbeAMCommandRetpar.h"
#include "WdbeAMCoreversionIp.h"
#include "WdbeAMCoreversionPlh.h"
#include "WdbeAMErrorPar.h"
#include "WdbeAMFsmstateStep.h"
#include "WdbeAMLibraryMakefile.h"
#include "WdbeAMMachineMakefile.h"
#include "WdbeAMMachinePar.h"
#include "WdbeAMModulePar.h"
#include "WdbeAMPeripheralPar.h"
#include "WdbeAMPersonDetail.h"
#include "WdbeAMPinPar.h"
#include "WdbeAMUserAccess.h"
#include "WdbeAMUsergroupAccess.h"
#include "WdbeAVControlPar.h"
#include "WdbeAVKeylistKey.h"
#include "WdbeAVValuelistVal.h"
#include "WdbeCFile.h"
#include "WdbeCFsmstate.h"
#include "WdbeCGeneric.h"
#include "WdbeCPin.h"
#include "WdbeCPort.h"
#include "WdbeCSegment.h"
#include "WdbeCSignal.h"
#include "WdbeCVariable.h"
#include "WdbeHistRMUserUniversal.h"
#include "WdbeJAVKeylistKey.h"
#include "WdbeJMCoreversionState.h"
#include "WdbeJMPersonLastname.h"
#include "WdbeJMPinSref.h"
#include "WdbeJMUserState.h"
#include "WdbeJMVersionState.h"
#include "WdbeMBank.h"
#include "WdbeMCommand.h"
#include "WdbeMController.h"
#include "WdbeMCoreproject.h"
#include "WdbeMCoreversion.h"
#include "WdbeMError.h"
#include "WdbeMFamily.h"
#include "WdbeMFile.h"
#include "WdbeMFsm.h"
#include "WdbeMFsmstate.h"
#include "WdbeMGeneric.h"
#include "WdbeMImbuf.h"
#include "WdbeMInterrupt.h"
#include "WdbeMLibrary.h"
#include "WdbeMMachine.h"
#include "WdbeMModule.h"
#include "WdbeMPeripheral.h"
#include "WdbeMPerson.h"
#include "WdbeMPin.h"
#include "WdbeMPipeline.h"
#include "WdbeMPort.h"
#include "WdbeMProcess.h"
#include "WdbeMProject.h"
#include "WdbeMRelease.h"
#include "WdbeMSegment.h"
#include "WdbeMSensitivity.h"
#include "WdbeMSession.h"
#include "WdbeMSignal.h"
#include "WdbeMSystem.h"
#include "WdbeMTarget.h"
#include "WdbeMUnit.h"
#include "WdbeMUser.h"
#include "WdbeMUsergroup.h"
#include "WdbeMVariable.h"
#include "WdbeMVector.h"
#include "WdbeMVectoritem.h"
#include "WdbeMVersion.h"
#include "WdbeRMCommandMController.h"
#include "WdbeRMCoreprojectMPerson.h"
#include "WdbeRMLibraryMVersion.h"
#include "WdbeRMModuleMModule.h"
#include "WdbeRMModuleMPeripheral.h"
#include "WdbeRMPersonMProject.h"
#include "WdbeRMUsergroupUniversal.h"
#include "WdbeRMUserMUsergroup.h"

#include "WdbeQBnk1NPin.h"
#include "WdbeQBnkList.h"
#include "WdbeQCmdAInvpar.h"
#include "WdbeQCmdARetpar.h"
#include "WdbeQCmdList.h"
#include "WdbeQCmdMNController.h"
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
#include "WdbeQLibMNVersion.h"
#include "WdbeQMch1NRelease.h"
#include "WdbeQMchAMakefile.h"
#include "WdbeQMchAPar.h"
#include "WdbeQMchList.h"
#include "WdbeQMchSup1NMachine.h"
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
#include "WdbeQPrcKHdltype.h"
#include "WdbeQPrcList.h"
#include "WdbeQPrcMge1NSignal.h"
#include "WdbeQPrcRef1NSensitivity.h"
#include "WdbeQPrcRef1NVariable.h"
#include "WdbeQPreselect.h"
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
#include "WdbeQSelect.h"
#include "WdbeQSigList.h"
#include "WdbeQSigSrc1NSensitivity.h"
#include "WdbeQSil1NBank.h"
#include "WdbeQSil1NInterrupt.h"
#include "WdbeQSil1NPeripheral.h"
#include "WdbeQSil1NTarget.h"
#include "WdbeQSilFwd1NController.h"
#include "WdbeQSilHk1NModule.h"
#include "WdbeQSilHk1NVector.h"
#include "WdbeQSilList.h"
#include "WdbeQSilRef1NCommand.h"
#include "WdbeQSilRef1NError.h"
#include "WdbeQSilRef1NSignal.h"
#include "WdbeQSilSil1NUnit.h"
#include "WdbeQSnsList.h"
#include "WdbeQSysHk1NVector.h"
#include "WdbeQSysList.h"
#include "WdbeQSysSys1NTarget.h"
#include "WdbeQTrgList.h"
#include "WdbeQUnt1NBank.h"
#include "WdbeQUnt1NInterrupt.h"
#include "WdbeQUnt1NPeripheral.h"
#include "WdbeQUnt1NTarget.h"
#include "WdbeQUntFwd1NController.h"
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
#include "WdbeQVer1NRelease.h"
#include "WdbeQVer1NSystem.h"
#include "WdbeQVer1NUnit.h"
#include "WdbeQVerBvr1NVersion.h"
#include "WdbeQVerList.h"
#include "WdbeQVerMNLibrary.h"
#include "WdbeQVerRef1NFile.h"
#include "WdbeQVitList.h"

#define VecWdbeVCard DbsWdbe::VecVCard
#define VecWdbeVControl DbsWdbe::VecVControl
#define VecWdbeVFeatgroup DbsWdbe::VecVFeatgroup
#define VecWdbeVKeylist DbsWdbe::VecVKeylist
#define VecWdbeVLat DbsWdbe::VecVLat
#define VecWdbeVLocale DbsWdbe::VecVLocale
#define VecWdbeVLop DbsWdbe::VecVLop
#define VecWdbeVMaintable DbsWdbe::VecVMaintable
#define VecWdbeVOolop DbsWdbe::VecVOolop
#define VecWdbeVPartype DbsWdbe::VecVPartype
#define VecWdbeVPreset DbsWdbe::VecVPreset
#define VecWdbeVRecaccess DbsWdbe::VecVRecaccess
#define VecWdbeVUserlevel DbsWdbe::VecVUserlevel
#define VecWdbeVValuelist DbsWdbe::VecVValuelist
#define VecWdbeWAccess DbsWdbe::VecWAccess

/**
	* DbsWdbe
	*/
class DbsWdbe {

public:
	/**
		* VecVCard (full: VecWdbeVCard)
		*/
	class VecVCard {

	public:
		static const Sbecore::uint CRDWDBEUSG = 1;
		static const Sbecore::uint CRDWDBEUSR = 2;
		static const Sbecore::uint CRDWDBEPRS = 3;
		static const Sbecore::uint CRDWDBEFIL = 4;
		static const Sbecore::uint CRDWDBENAV = 5;
		static const Sbecore::uint CRDWDBEMCH = 6;
		static const Sbecore::uint CRDWDBELIB = 7;
		static const Sbecore::uint CRDWDBEFAM = 8;
		static const Sbecore::uint CRDWDBESIL = 9;
		static const Sbecore::uint CRDWDBEMTP = 10;
		static const Sbecore::uint CRDWDBEPRJ = 11;
		static const Sbecore::uint CRDWDBEVER = 12;
		static const Sbecore::uint CRDWDBESYS = 13;
		static const Sbecore::uint CRDWDBETRG = 14;
		static const Sbecore::uint CRDWDBEUNT = 15;
		static const Sbecore::uint CRDWDBERLS = 16;
		static const Sbecore::uint CRDWDBECPR = 17;
		static const Sbecore::uint CRDWDBECVR = 18;
		static const Sbecore::uint CRDWDBEPPH = 19;
		static const Sbecore::uint CRDWDBEMOD = 20;
		static const Sbecore::uint CRDWDBEVEC = 21;
		static const Sbecore::uint CRDWDBEVIT = 22;
		static const Sbecore::uint CRDWDBECMD = 23;
		static const Sbecore::uint CRDWDBEERR = 24;
		static const Sbecore::uint CRDWDBEPPL = 25;
		static const Sbecore::uint CRDWDBESEG = 26;
		static const Sbecore::uint CRDWDBEBNK = 27;
		static const Sbecore::uint CRDWDBEPIN = 28;
		static const Sbecore::uint CRDWDBEINT = 29;
		static const Sbecore::uint CRDWDBESNS = 30;
		static const Sbecore::uint CRDWDBEVAR = 31;
		static const Sbecore::uint CRDWDBEGEN = 32;
		static const Sbecore::uint CRDWDBEPRT = 33;
		static const Sbecore::uint CRDWDBESIG = 34;
		static const Sbecore::uint CRDWDBEPRC = 35;
		static const Sbecore::uint CRDWDBEFST = 36;
		static const Sbecore::uint CRDWDBEUTL = 37;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVControl (full: VecWdbeVControl)
		*/
	class VecVControl {

	public:
		static const Sbecore::uint PNLWDBEUSGLIST_TCOGRP = 1;
		static const Sbecore::uint PNLWDBEUSGLIST_TCOOWN = 2;
		static const Sbecore::uint PNLWDBEUSGLIST_TCOSRF = 3;
		static const Sbecore::uint PNLWDBEUSGAACCESS_TCOFEG = 4;
		static const Sbecore::uint PNLWDBEUSGAACCESS_TCOFEA = 5;
		static const Sbecore::uint PNLWDBEUSGAACCESS_TCOACC = 6;
		static const Sbecore::uint PNLWDBEUSGMNUSER_TCOMREF = 7;
		static const Sbecore::uint PNLWDBEUSGMNUSER_TCOULV = 8;
		static const Sbecore::uint PNLWDBEUSRLIST_TCOGRP = 9;
		static const Sbecore::uint PNLWDBEUSRLIST_TCOOWN = 10;
		static const Sbecore::uint PNLWDBEUSRLIST_TCOPRS = 11;
		static const Sbecore::uint PNLWDBEUSRLIST_TCOSRF = 12;
		static const Sbecore::uint PNLWDBEUSRLIST_TCOUSG = 13;
		static const Sbecore::uint PNLWDBEUSRLIST_TCOSTE = 14;
		static const Sbecore::uint PNLWDBEUSRLIST_TCOLCL = 15;
		static const Sbecore::uint PNLWDBEUSRLIST_TCOULV = 16;
		static const Sbecore::uint PNLWDBEUSRAACCESS_TCOFEG = 17;
		static const Sbecore::uint PNLWDBEUSRAACCESS_TCOFEA = 18;
		static const Sbecore::uint PNLWDBEUSRAACCESS_TCOACC = 19;
		static const Sbecore::uint PNLWDBEUSR1NSESSION_TCOREF = 20;
		static const Sbecore::uint PNLWDBEUSRMNUSERGROUP_TCOMREF = 21;
		static const Sbecore::uint PNLWDBEUSRMNUSERGROUP_TCOULV = 22;
		static const Sbecore::uint PNLWDBEPRSLIST_TCOGRP = 23;
		static const Sbecore::uint PNLWDBEPRSLIST_TCOOWN = 24;
		static const Sbecore::uint PNLWDBEPRSLIST_TCOTIT = 25;
		static const Sbecore::uint PNLWDBEPRSLIST_TCOFNM = 26;
		static const Sbecore::uint PNLWDBEPRSLIST_TCOLNM = 27;
		static const Sbecore::uint PNLWDBEPRSLIST_TCOSEX = 28;
		static const Sbecore::uint PNLWDBEPRSLIST_TCOTEL = 29;
		static const Sbecore::uint PNLWDBEPRSLIST_TCOEML = 30;
		static const Sbecore::uint PNLWDBEPRSADETAIL_TCOTYP = 31;
		static const Sbecore::uint PNLWDBEPRSADETAIL_TCOVAL = 32;
		static const Sbecore::uint PNLWDBEPRSMNPROJECT_TCOMREF = 33;
		static const Sbecore::uint PNLWDBEPRSMNPROJECT_TCOSTA = 34;
		static const Sbecore::uint PNLWDBEPRSMNPROJECT_TCOSTO = 35;
		static const Sbecore::uint PNLWDBEPRSMNPROJECT_TCOFCT = 36;
		static const Sbecore::uint PNLWDBEPRSMNCOREPROJECT_TCOMREF = 37;
		static const Sbecore::uint PNLWDBEPRSMNCOREPROJECT_TCOSTA = 38;
		static const Sbecore::uint PNLWDBEPRSMNCOREPROJECT_TCOSTO = 39;
		static const Sbecore::uint PNLWDBEPRSMNCOREPROJECT_TCOFCT = 40;
		static const Sbecore::uint PNLWDBEFILLIST_TCOGRP = 41;
		static const Sbecore::uint PNLWDBEFILLIST_TCOOWN = 42;
		static const Sbecore::uint PNLWDBEFILLIST_TCOFNM = 43;
		static const Sbecore::uint PNLWDBEFILLIST_TCORET = 44;
		static const Sbecore::uint PNLWDBEFILLIST_TCOREU = 45;
		static const Sbecore::uint PNLWDBEFILLIST_TCOCNT = 46;
		static const Sbecore::uint PNLWDBEFILLIST_TCOMIM = 47;
		static const Sbecore::uint PNLWDBEFILLIST_TCOSIZ = 48;
		static const Sbecore::uint PNLWDBEMCHLIST_TCOSRF = 49;
		static const Sbecore::uint PNLWDBEMCHLIST_TCOSUP = 50;
		static const Sbecore::uint PNLWDBEMCHAPAR_TCOKEY = 51;
		static const Sbecore::uint PNLWDBEMCHAPAR_TCOVAL = 52;
		static const Sbecore::uint PNLWDBEMCHAMAKEFILE_TCOTAG = 53;
		static const Sbecore::uint PNLWDBEMCHAMAKEFILE_TCOVAL = 54;
		static const Sbecore::uint PNLWDBEMCH1NRELEASE_TCOREF = 55;
		static const Sbecore::uint PNLWDBEMCHSUP1NMACHINE_TCOREF = 56;
		static const Sbecore::uint PNLWDBELIBLIST_TCOSRF = 57;
		static const Sbecore::uint PNLWDBELIBLIST_TCOTIT = 58;
		static const Sbecore::uint PNLWDBELIBLIST_TCOVER = 59;
		static const Sbecore::uint PNLWDBELIBAMAKEFILE_TCOMCH = 60;
		static const Sbecore::uint PNLWDBELIBAMAKEFILE_TCOTAG = 61;
		static const Sbecore::uint PNLWDBELIBAMAKEFILE_TCOVAL = 62;
		static const Sbecore::uint PNLWDBELIBMNVERSION_TCOMREF = 63;
		static const Sbecore::uint PNLWDBEFAMLIST_TCOVND = 64;
		static const Sbecore::uint PNLWDBEFAMLIST_TCOTIT = 65;
		static const Sbecore::uint PNLWDBEFAM1NUNIT_TCOREF = 66;
		static const Sbecore::uint PNLWDBESILLIST_TCOSRF = 67;
		static const Sbecore::uint PNLWDBESILLIST_TCOTIT = 68;
		static const Sbecore::uint PNLWDBESILLIST_TCOFSR = 69;
		static const Sbecore::uint PNLWDBESILLIST_TCOTYP = 70;
		static const Sbecore::uint PNLWDBESILLIST_TCORET = 71;
		static const Sbecore::uint PNLWDBESILLIST_TCOREU = 72;
		static const Sbecore::uint PNLWDBESILLIST_TCOSYS = 73;
		static const Sbecore::uint PNLWDBESILLIST_TCOMDL = 74;
		static const Sbecore::uint PNLWDBESILLIST_TCOPKG = 75;
		static const Sbecore::uint PNLWDBESILLIST_TCOESY = 76;
		static const Sbecore::uint PNLWDBESILLIST_TCOTCH = 77;
		static const Sbecore::uint PNLWDBESIL1NTARGET_TCOREF = 78;
		static const Sbecore::uint PNLWDBESIL1NINTERRUPT_TCOREF = 79;
		static const Sbecore::uint PNLWDBESIL1NPERIPHERAL_TCOREF = 80;
		static const Sbecore::uint PNLWDBESILSIL1NUNIT_TCOREF = 81;
		static const Sbecore::uint PNLWDBESILFWD1NCONTROLLER_TCOREF = 82;
		static const Sbecore::uint PNLWDBESIL1NBANK_TCOREF = 83;
		static const Sbecore::uint PNLWDBESILHK1NMODULE_TCOREF = 84;
		static const Sbecore::uint PNLWDBESILHK1NVECTOR_TCOREF = 85;
		static const Sbecore::uint PNLWDBESILREF1NSIGNAL_TCOREF = 86;
		static const Sbecore::uint PNLWDBESILREF1NERROR_TCOREF = 87;
		static const Sbecore::uint PNLWDBESILREF1NCOMMAND_TCOREF = 88;
		static const Sbecore::uint PNLWDBEMTPLIST_TCOSRF = 89;
		static const Sbecore::uint PNLWDBEMTPLIST_TCOVND = 90;
		static const Sbecore::uint PNLWDBEMTPLIST_TCOTYP = 91;
		static const Sbecore::uint PNLWDBEMTPLIST_TCOSRR = 92;
		static const Sbecore::uint PNLWDBEMTPKPARKEY_TCOFIX = 93;
		static const Sbecore::uint PNLWDBEMTPKPARKEY_TCOSRF = 94;
		static const Sbecore::uint PNLWDBEMTPKPARKEY_TCOAVL = 95;
		static const Sbecore::uint PNLWDBEMTPKPARKEY_TCOIMP = 96;
		static const Sbecore::uint PNLWDBEMTPKPARKEY_TCOTIT = 97;
		static const Sbecore::uint PNLWDBEMTPKPARKEY_TCOCMT = 98;
		static const Sbecore::uint PNLWDBEMTPKHDLTYPE_TCOFIX = 99;
		static const Sbecore::uint PNLWDBEMTPKHDLTYPE_TCOSRF = 100;
		static const Sbecore::uint PNLWDBEMTPKHDLTYPE_TCOAVL = 101;
		static const Sbecore::uint PNLWDBEMTPKHDLTYPE_TCOIMP = 102;
		static const Sbecore::uint PNLWDBEMTPKHDLTYPE_TCOTIT = 103;
		static const Sbecore::uint PNLWDBEMTPKHDLTYPE_TCOCMT = 104;
		static const Sbecore::uint PNLWDBEMTPAPAR_TCOKEY = 105;
		static const Sbecore::uint PNLWDBEMTPAPAR_TCOVAL = 106;
		static const Sbecore::uint PNLWDBEMTPMDL1NGENERIC_TCOREF = 107;
		static const Sbecore::uint PNLWDBEMTPTPL1NMODULE_TCOREF = 108;
		static const Sbecore::uint PNLWDBEMTPHSM1NPIPELINE_TCOREF = 109;
		static const Sbecore::uint PNLWDBEMTPMDL1NPORT_TCOREF = 110;
		static const Sbecore::uint PNLWDBEMTPSUP1NMODULE_TCOREF = 111;
		static const Sbecore::uint PNLWDBEMTPREF1NSENSITIVITY_TCOREF = 112;
		static const Sbecore::uint PNLWDBEMTPREF1NVARIABLE_TCOREF = 113;
		static const Sbecore::uint PNLWDBEMTPMGE1NSIGNAL_TCOREF = 114;
		static const Sbecore::uint PNLWDBEMTPREF1NFILE_TCOREF = 115;
		static const Sbecore::uint PNLWDBEPRJLIST_TCOGRP = 116;
		static const Sbecore::uint PNLWDBEPRJLIST_TCOOWN = 117;
		static const Sbecore::uint PNLWDBEPRJLIST_TCOSHO = 118;
		static const Sbecore::uint PNLWDBEPRJLIST_TCOTIT = 119;
		static const Sbecore::uint PNLWDBEPRJLIST_TCOVER = 120;
		static const Sbecore::uint PNLWDBEPRJLIST_TCOESY = 121;
		static const Sbecore::uint PNLWDBEPRJLIST_TCOGRL = 122;
		static const Sbecore::uint PNLWDBEPRJPRJ1NVERSION_TCOREF = 123;
		static const Sbecore::uint PNLWDBEPRJMNPERSON_TCOMREF = 124;
		static const Sbecore::uint PNLWDBEPRJMNPERSON_TCOSTA = 125;
		static const Sbecore::uint PNLWDBEPRJMNPERSON_TCOSTO = 126;
		static const Sbecore::uint PNLWDBEPRJMNPERSON_TCOFCT = 127;
		static const Sbecore::uint PNLWDBEVERLIST_TCOGRP = 128;
		static const Sbecore::uint PNLWDBEVERLIST_TCOOWN = 129;
		static const Sbecore::uint PNLWDBEVERLIST_TCOPRJ = 130;
		static const Sbecore::uint PNLWDBEVERLIST_TCOMAJ = 131;
		static const Sbecore::uint PNLWDBEVERLIST_TCOMIN = 132;
		static const Sbecore::uint PNLWDBEVERLIST_TCOSUB = 133;
		static const Sbecore::uint PNLWDBEVERLIST_TCOBVR = 134;
		static const Sbecore::uint PNLWDBEVERLIST_TCOSTE = 135;
		static const Sbecore::uint PNLWDBEVER1NRELEASE_TCOREF = 136;
		static const Sbecore::uint PNLWDBEVER1NSYSTEM_TCOREF = 137;
		static const Sbecore::uint PNLWDBEVERBVR1NVERSION_TCOREF = 138;
		static const Sbecore::uint PNLWDBEVER1NUNIT_TCOREF = 139;
		static const Sbecore::uint PNLWDBEVERREF1NFILE_TCOREF = 140;
		static const Sbecore::uint PNLWDBEVERMNLIBRARY_TCOMREF = 141;
		static const Sbecore::uint PNLWDBESYSLIST_TCOSRF = 142;
		static const Sbecore::uint PNLWDBESYSLIST_TCOVER = 143;
		static const Sbecore::uint PNLWDBESYSLIST_TCOUNT = 144;
		static const Sbecore::uint PNLWDBESYSSYS1NTARGET_TCOREF = 145;
		static const Sbecore::uint PNLWDBESYSHK1NVECTOR_TCOREF = 146;
		static const Sbecore::uint PNLWDBETRGLIST_TCOSRF = 147;
		static const Sbecore::uint PNLWDBETRGLIST_TCOSYS = 148;
		static const Sbecore::uint PNLWDBETRGLIST_TCOUNT = 149;
		static const Sbecore::uint PNLWDBEUNTLIST_TCOSRF = 150;
		static const Sbecore::uint PNLWDBEUNTLIST_TCOTIT = 151;
		static const Sbecore::uint PNLWDBEUNTLIST_TCOFSR = 152;
		static const Sbecore::uint PNLWDBEUNTLIST_TCOTYP = 153;
		static const Sbecore::uint PNLWDBEUNTLIST_TCORET = 154;
		static const Sbecore::uint PNLWDBEUNTLIST_TCOREU = 155;
		static const Sbecore::uint PNLWDBEUNTLIST_TCOSYS = 156;
		static const Sbecore::uint PNLWDBEUNTLIST_TCOMDL = 157;
		static const Sbecore::uint PNLWDBEUNTLIST_TCOPKG = 158;
		static const Sbecore::uint PNLWDBEUNTLIST_TCOESY = 159;
		static const Sbecore::uint PNLWDBEUNTLIST_TCOTCH = 160;
		static const Sbecore::uint PNLWDBEUNT1NTARGET_TCOREF = 161;
		static const Sbecore::uint PNLWDBEUNT1NINTERRUPT_TCOREF = 162;
		static const Sbecore::uint PNLWDBEUNT1NPERIPHERAL_TCOREF = 163;
		static const Sbecore::uint PNLWDBEUNTSIL1NUNIT_TCOREF = 164;
		static const Sbecore::uint PNLWDBEUNTFWD1NCONTROLLER_TCOREF = 165;
		static const Sbecore::uint PNLWDBEUNT1NBANK_TCOREF = 166;
		static const Sbecore::uint PNLWDBEUNTHK1NMODULE_TCOREF = 167;
		static const Sbecore::uint PNLWDBEUNTHK1NVECTOR_TCOREF = 168;
		static const Sbecore::uint PNLWDBEUNTREF1NSIGNAL_TCOREF = 169;
		static const Sbecore::uint PNLWDBEUNTREF1NERROR_TCOREF = 170;
		static const Sbecore::uint PNLWDBEUNTREF1NCOMMAND_TCOREF = 171;
		static const Sbecore::uint PNLWDBERLSLIST_TCOSRF = 172;
		static const Sbecore::uint PNLWDBERLSLIST_TCOTYP = 173;
		static const Sbecore::uint PNLWDBERLSLIST_TCOVER = 174;
		static const Sbecore::uint PNLWDBERLSLIST_TCOMCH = 175;
		static const Sbecore::uint PNLWDBECPRLIST_TCOGRP = 176;
		static const Sbecore::uint PNLWDBECPRLIST_TCOOWN = 177;
		static const Sbecore::uint PNLWDBECPRLIST_TCOSRF = 178;
		static const Sbecore::uint PNLWDBECPRLIST_TCOTIT = 179;
		static const Sbecore::uint PNLWDBECPRLIST_TCOTYP = 180;
		static const Sbecore::uint PNLWDBECPRLIST_TCOCVR = 181;
		static const Sbecore::uint PNLWDBECPRLIST_TCOGRL = 182;
		static const Sbecore::uint PNLWDBECPR1NCOREVERSION_TCOREF = 183;
		static const Sbecore::uint PNLWDBECPRMNPERSON_TCOMREF = 184;
		static const Sbecore::uint PNLWDBECPRMNPERSON_TCOSTA = 185;
		static const Sbecore::uint PNLWDBECPRMNPERSON_TCOSTO = 186;
		static const Sbecore::uint PNLWDBECPRMNPERSON_TCOFCT = 187;
		static const Sbecore::uint PNLWDBECVRLIST_TCOGRP = 188;
		static const Sbecore::uint PNLWDBECVRLIST_TCOOWN = 189;
		static const Sbecore::uint PNLWDBECVRLIST_TCOCPR = 190;
		static const Sbecore::uint PNLWDBECVRLIST_TCOMAJ = 191;
		static const Sbecore::uint PNLWDBECVRLIST_TCOMIN = 192;
		static const Sbecore::uint PNLWDBECVRLIST_TCOSUB = 193;
		static const Sbecore::uint PNLWDBECVRLIST_TCOBCV = 194;
		static const Sbecore::uint PNLWDBECVRLIST_TCOSTE = 195;
		static const Sbecore::uint PNLWDBECVRAPLH_TCOSRF = 196;
		static const Sbecore::uint PNLWDBECVRAPLH_TCOCMT = 197;
		static const Sbecore::uint PNLWDBECVRAIP_TCOSRF = 198;
		static const Sbecore::uint PNLWDBECVRAIP_TCOTTY = 199;
		static const Sbecore::uint PNLWDBECVRAIP_TCOCMT = 200;
		static const Sbecore::uint PNLWDBECVRBCV1NCOREVERSION_TCOREF = 201;
		static const Sbecore::uint PNLWDBECVRHK1NMODULE_TCOREF = 202;
		static const Sbecore::uint PNLWDBEPPHLIST_TCOSRF = 203;
		static const Sbecore::uint PNLWDBEPPHLIST_TCOUNT = 204;
		static const Sbecore::uint PNLWDBEPPHAPAR_TCOKEY = 205;
		static const Sbecore::uint PNLWDBEPPHAPAR_TCOVAL = 206;
		static const Sbecore::uint PNLWDBEPPHMNMODULE_TCOMREF = 207;
		static const Sbecore::uint PNLWDBEMODLIST_TCOSRF = 208;
		static const Sbecore::uint PNLWDBEMODLIST_TCOVND = 209;
		static const Sbecore::uint PNLWDBEMODLIST_TCOTYP = 210;
		static const Sbecore::uint PNLWDBEMODLIST_TCOHKT = 211;
		static const Sbecore::uint PNLWDBEMODLIST_TCOHKU = 212;
		static const Sbecore::uint PNLWDBEMODLIST_TCOSUP = 213;
		static const Sbecore::uint PNLWDBEMODLIST_TCOTPL = 214;
		static const Sbecore::uint PNLWDBEMODKHDLTYPE_TCOFIX = 215;
		static const Sbecore::uint PNLWDBEMODKHDLTYPE_TCOSRF = 216;
		static const Sbecore::uint PNLWDBEMODKHDLTYPE_TCOAVL = 217;
		static const Sbecore::uint PNLWDBEMODKHDLTYPE_TCOIMP = 218;
		static const Sbecore::uint PNLWDBEMODKHDLTYPE_TCOTIT = 219;
		static const Sbecore::uint PNLWDBEMODKHDLTYPE_TCOCMT = 220;
		static const Sbecore::uint PNLWDBEMODAPAR_TCOKEY = 221;
		static const Sbecore::uint PNLWDBEMODAPAR_TCOVAL = 222;
		static const Sbecore::uint PNLWDBEMODMDL1NGENERIC_TCOREF = 223;
		static const Sbecore::uint PNLWDBEMODHSM1NPIPELINE_TCOREF = 224;
		static const Sbecore::uint PNLWDBEMOD1NPROCESS_TCOREF = 225;
		static const Sbecore::uint PNLWDBEMODMDL1NPORT_TCOREF = 226;
		static const Sbecore::uint PNLWDBEMODSUP1NMODULE_TCOREF = 227;
		static const Sbecore::uint PNLWDBEMODREF1NSIGNAL_TCOREF = 228;
		static const Sbecore::uint PNLWDBEMODREF1NSENSITIVITY_TCOREF = 229;
		static const Sbecore::uint PNLWDBEMODREF1NVARIABLE_TCOREF = 230;
		static const Sbecore::uint PNLWDBEMODMGE1NSIGNAL_TCOREF = 231;
		static const Sbecore::uint PNLWDBEMODCTRHK1NVECTOR_TCOREF = 232;
		static const Sbecore::uint PNLWDBEMODCTRREF1NERROR_TCOREF = 233;
		static const Sbecore::uint PNLWDBEMODCTRREF1NCOMMAND_TCOREF = 234;
		static const Sbecore::uint PNLWDBEMODMNPERIPHERAL_TCOMREF = 235;
		static const Sbecore::uint PNLWDBEMODCTDMNMODULE_TCOMREF = 236;
		static const Sbecore::uint PNLWDBEMODCTDMNMODULE_TCOFCT = 237;
		static const Sbecore::uint PNLWDBEMODCORMNMODULE_TCOMREF = 238;
		static const Sbecore::uint PNLWDBEMODCORMNMODULE_TCOFCT = 239;
		static const Sbecore::uint PNLWDBEMODCTRMNCOMMAND_TCOMREF = 240;
		static const Sbecore::uint PNLWDBEMODCTRMNCOMMAND_TCOIVR = 241;
		static const Sbecore::uint PNLWDBEMODCTRMNCOMMAND_TCORVR = 242;
		static const Sbecore::uint PNLWDBEVECLIST_TCOSRF = 243;
		static const Sbecore::uint PNLWDBEVECLIST_TCOTYP = 244;
		static const Sbecore::uint PNLWDBEVECLIST_TCOHKT = 245;
		static const Sbecore::uint PNLWDBEVECLIST_TCOHKU = 246;
		static const Sbecore::uint PNLWDBEVECVEC1NVECTORITEM_TCOREF = 247;
		static const Sbecore::uint PNLWDBEVITLIST_TCOSRF = 248;
		static const Sbecore::uint PNLWDBEVITLIST_TCOTIT = 249;
		static const Sbecore::uint PNLWDBEVITLIST_TCOVEC = 250;
		static const Sbecore::uint PNLWDBECMDLIST_TCOSRF = 251;
		static const Sbecore::uint PNLWDBECMDLIST_TCOFSR = 252;
		static const Sbecore::uint PNLWDBECMDLIST_TCORET = 253;
		static const Sbecore::uint PNLWDBECMDLIST_TCOREU = 254;
		static const Sbecore::uint PNLWDBECMDLIST_TCORTY = 255;
		static const Sbecore::uint PNLWDBECMDAINVPAR_TCOSRF = 256;
		static const Sbecore::uint PNLWDBECMDAINVPAR_TCOPTY = 257;
		static const Sbecore::uint PNLWDBECMDAINVPAR_TCOVEC = 258;
		static const Sbecore::uint PNLWDBECMDAINVPAR_TCOLEN = 259;
		static const Sbecore::uint PNLWDBECMDAINVPAR_TCODFV = 260;
		static const Sbecore::uint PNLWDBECMDAINVPAR_TCOVIT = 261;
		static const Sbecore::uint PNLWDBECMDAINVPAR_TCOCMT = 262;
		static const Sbecore::uint PNLWDBECMDARETPAR_TCOSRF = 263;
		static const Sbecore::uint PNLWDBECMDARETPAR_TCOPTY = 264;
		static const Sbecore::uint PNLWDBECMDARETPAR_TCOVEC = 265;
		static const Sbecore::uint PNLWDBECMDARETPAR_TCOLEN = 266;
		static const Sbecore::uint PNLWDBECMDARETPAR_TCOCMT = 267;
		static const Sbecore::uint PNLWDBECMDMNCONTROLLER_TCOMREF = 268;
		static const Sbecore::uint PNLWDBECMDMNCONTROLLER_TCOIVR = 269;
		static const Sbecore::uint PNLWDBECMDMNCONTROLLER_TCORVR = 270;
		static const Sbecore::uint PNLWDBEERRLIST_TCOSRF = 271;
		static const Sbecore::uint PNLWDBEERRLIST_TCOFSR = 272;
		static const Sbecore::uint PNLWDBEERRLIST_TCORET = 273;
		static const Sbecore::uint PNLWDBEERRLIST_TCOREU = 274;
		static const Sbecore::uint PNLWDBEERRAPAR_TCOSRF = 275;
		static const Sbecore::uint PNLWDBEERRAPAR_TCOPTY = 276;
		static const Sbecore::uint PNLWDBEERRAPAR_TCOVEC = 277;
		static const Sbecore::uint PNLWDBEERRAPAR_TCOLEN = 278;
		static const Sbecore::uint PNLWDBEERRAPAR_TCOCMT = 279;
		static const Sbecore::uint PNLWDBEPPLLIST_TCOSRF = 280;
		static const Sbecore::uint PNLWDBEPPLLIST_TCOHSM = 281;
		static const Sbecore::uint PNLWDBEPPLLIST_TCODPT = 282;
		static const Sbecore::uint PNLWDBEPPLPPL1NSEGMENT_TCOREF = 283;
		static const Sbecore::uint PNLWDBESEGLIST_TCOSRF = 284;
		static const Sbecore::uint PNLWDBESEGLIST_TCOPPL = 285;
		static const Sbecore::uint PNLWDBESEGLIST_TCOSUP = 286;
		static const Sbecore::uint PNLWDBESEGLIST_TCOIFM = 287;
		static const Sbecore::uint PNLWDBESEGLIST_TCOOFM = 288;
		static const Sbecore::uint PNLWDBESEGLIST_TCOLCY = 289;
		static const Sbecore::uint PNLWDBESEGSUP1NSEGMENT_TCOREF = 290;
		static const Sbecore::uint PNLWDBEBNKLIST_TCOSRF = 291;
		static const Sbecore::uint PNLWDBEBNKLIST_TCOUNT = 292;
		static const Sbecore::uint PNLWDBEBNKLIST_TCOVST = 293;
		static const Sbecore::uint PNLWDBEBNK1NPIN_TCOREF = 294;
		static const Sbecore::uint PNLWDBEPINLIST_TCOSRF = 295;
		static const Sbecore::uint PNLWDBEPINLIST_TCOBNK = 296;
		static const Sbecore::uint PNLWDBEPINLIST_TCOLOC = 297;
		static const Sbecore::uint PNLWDBEPINAPAR_TCOKEY = 298;
		static const Sbecore::uint PNLWDBEPINAPAR_TCOVAL = 299;
		static const Sbecore::uint PNLWDBEINTLIST_TCOSRF = 300;
		static const Sbecore::uint PNLWDBEINTLIST_TCOUNT = 301;
		static const Sbecore::uint PNLWDBEINTSRC1NSENSITIVITY_TCOREF = 302;
		static const Sbecore::uint PNLWDBESNSLIST_TCORET = 303;
		static const Sbecore::uint PNLWDBESNSLIST_TCOREU = 304;
		static const Sbecore::uint PNLWDBESNSLIST_TCOSRT = 305;
		static const Sbecore::uint PNLWDBESNSLIST_TCOSRU = 306;
		static const Sbecore::uint PNLWDBEVARLIST_TCOSRF = 307;
		static const Sbecore::uint PNLWDBEVARLIST_TCORET = 308;
		static const Sbecore::uint PNLWDBEVARLIST_TCOREU = 309;
		static const Sbecore::uint PNLWDBEVARLIST_TCOCON = 310;
		static const Sbecore::uint PNLWDBEVARLIST_TCOFAL = 311;
		static const Sbecore::uint PNLWDBEVARLIST_TCOHTY = 312;
		static const Sbecore::uint PNLWDBEVARLIST_TCOWID = 313;
		static const Sbecore::uint PNLWDBEVARLIST_TCOMMX = 314;
		static const Sbecore::uint PNLWDBEGENLIST_TCOSRF = 315;
		static const Sbecore::uint PNLWDBEGENLIST_TCOMDL = 316;
		static const Sbecore::uint PNLWDBEGENLIST_TCOHTY = 317;
		static const Sbecore::uint PNLWDBEGENLIST_TCOWID = 318;
		static const Sbecore::uint PNLWDBEGENLIST_TCOMMX = 319;
		static const Sbecore::uint PNLWDBEPRTLIST_TCOSRF = 320;
		static const Sbecore::uint PNLWDBEPRTLIST_TCOMDL = 321;
		static const Sbecore::uint PNLWDBEPRTLIST_TCOMDC = 322;
		static const Sbecore::uint PNLWDBEPRTLIST_TCODIR = 323;
		static const Sbecore::uint PNLWDBEPRTLIST_TCOHTY = 324;
		static const Sbecore::uint PNLWDBEPRTLIST_TCOWID = 325;
		static const Sbecore::uint PNLWDBEPRTLIST_TCOMMX = 326;
		static const Sbecore::uint PNLWDBEPRTSRC1NSENSITIVITY_TCOREF = 327;
		static const Sbecore::uint PNLWDBESIGLIST_TCOSRF = 328;
		static const Sbecore::uint PNLWDBESIGLIST_TCOTYP = 329;
		static const Sbecore::uint PNLWDBESIGLIST_TCORET = 330;
		static const Sbecore::uint PNLWDBESIGLIST_TCOREU = 331;
		static const Sbecore::uint PNLWDBESIGLIST_TCOMGT = 332;
		static const Sbecore::uint PNLWDBESIGLIST_TCOMGU = 333;
		static const Sbecore::uint PNLWDBESIGLIST_TCOVEC = 334;
		static const Sbecore::uint PNLWDBESIGLIST_TCOCON = 335;
		static const Sbecore::uint PNLWDBESIGLIST_TCOHTY = 336;
		static const Sbecore::uint PNLWDBESIGLIST_TCOWID = 337;
		static const Sbecore::uint PNLWDBESIGLIST_TCOMMX = 338;
		static const Sbecore::uint PNLWDBESIGSRC1NSENSITIVITY_TCOREF = 339;
		static const Sbecore::uint PNLWDBEPRCLIST_TCOSRF = 340;
		static const Sbecore::uint PNLWDBEPRCLIST_TCOMDL = 341;
		static const Sbecore::uint PNLWDBEPRCLIST_TCOFAL = 342;
		static const Sbecore::uint PNLWDBEPRCKHDLTYPE_TCOFIX = 343;
		static const Sbecore::uint PNLWDBEPRCKHDLTYPE_TCOSRF = 344;
		static const Sbecore::uint PNLWDBEPRCKHDLTYPE_TCOAVL = 345;
		static const Sbecore::uint PNLWDBEPRCKHDLTYPE_TCOIMP = 346;
		static const Sbecore::uint PNLWDBEPRCKHDLTYPE_TCOTIT = 347;
		static const Sbecore::uint PNLWDBEPRCKHDLTYPE_TCOCMT = 348;
		static const Sbecore::uint PNLWDBEPRCREF1NSENSITIVITY_TCOREF = 349;
		static const Sbecore::uint PNLWDBEPRCREF1NVARIABLE_TCOREF = 350;
		static const Sbecore::uint PNLWDBEPRCMGE1NSIGNAL_TCOREF = 351;
		static const Sbecore::uint PNLWDBEPRCFSMFSM1NFSMSTATE_TCOREF = 352;
		static const Sbecore::uint PNLWDBEFSTLIST_TCOSRF = 353;
		static const Sbecore::uint PNLWDBEFSTLIST_TCOFSM = 354;
		static const Sbecore::uint PNLWDBEFSTASTEP_TCOFNX = 355;
		static const Sbecore::uint PNLWDBEFSTASTEP_TCOCN1 = 356;
		static const Sbecore::uint PNLWDBEFSTASTEP_TCOIP1 = 357;
		static const Sbecore::uint PNLWDBEFSTASTEP_TCOCN2 = 358;
		static const Sbecore::uint PNLWDBEFSTASTEP_TCOIP2 = 359;
		static const Sbecore::uint PNLWDBEFSTASTEP_TCOCN3 = 360;
		static const Sbecore::uint PNLWDBEFSTASTEP_TCOIP3 = 361;
		static const Sbecore::uint PNLWDBEFSTASTEP_TCOCN4 = 362;
		static const Sbecore::uint PNLWDBEFSTASTEP_TCOIP4 = 363;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVFeatgroup (full: VecWdbeVFeatgroup)
		*/
	class VecVFeatgroup {

	public:
		static const Sbecore::uint VECWDBEVCARD = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVKeylist (full: VecWdbeVKeylist)
		*/
	class VecVKeylist {

	public:
		static const Sbecore::uint KLSTWDBEKAMLIBRARYMAKEFILETAG = 1;
		static const Sbecore::uint KLSTWDBEKAMMACHINEMAKEFILETAG = 2;
		static const Sbecore::uint KLSTWDBEKAMMACHINEPARKEY = 3;
		static const Sbecore::uint KLSTWDBEKAMMODULEPARKEY = 4;
		static const Sbecore::uint KLSTWDBEKAMPERIPHERALPARKEY = 5;
		static const Sbecore::uint KLSTWDBEKAMPERSONDETAILTYPE = 6;
		static const Sbecore::uint KLSTWDBEKAMPINPARKEY = 7;
		static const Sbecore::uint KLSTWDBEKHDLTYPE = 8;
		static const Sbecore::uint KLSTWDBEKMBANKVOLTSTD = 9;
		static const Sbecore::uint KLSTWDBEKMFILECONTENT = 10;
		static const Sbecore::uint KLSTWDBEKMFILEMIMETYPE = 11;
		static const Sbecore::uint KLSTWDBEKMRELEASEOPTION = 12;
		static const Sbecore::uint KLSTWDBEKMUNITPACKAGE = 13;
		static const Sbecore::uint KLSTWDBEKMUNITTOOLCH = 14;
		static const Sbecore::uint KLSTWDBEKMVECTOROPTION = 15;
		static const Sbecore::uint KLSTWDBEKRMCOREPROJECTMPERSONFUNCTION = 16;
		static const Sbecore::uint KLSTWDBEKRMMODULEMMODULEFUNCTION = 17;
		static const Sbecore::uint KLSTWDBEKRMPERSONMPROJECTFUNCTION = 18;
		static const Sbecore::uint KLSTWDBEKVENDOR = 19;
		static const Sbecore::uint KLSTKWDBEMTPCPLMSTBUCUSTOP = 20;
		static const Sbecore::uint KLSTKWDBEMTPCPLMSTTDCUSTOP = 21;
		static const Sbecore::uint KLSTKWDBEMTPGENFSTCUSTOP = 22;
		static const Sbecore::uint KLSTKWDBEMTPPLHFPGACUSTOP = 23;
		static const Sbecore::uint KLSTKWDBEMTPPLHMCUCUSTOP = 24;
		static const Sbecore::uint KLSTKWDBEMTPWRFPGACUSTOP = 25;
		static const Sbecore::uint KLSTKWDBEMTPWRMCUCUSTOP = 26;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);
	};

	/**
		* VecVLat (full: VecWdbeVLat)
		*/
	class VecVLat {

	public:
		static const Sbecore::uint DLO = 1;
		static const Sbecore::uint INI = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVLocale (full: VecWdbeVLocale)
		*/
	class VecVLocale {

	public:
		static const Sbecore::uint ENUS = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVLop (full: VecWdbeVLop)
		*/
	class VecVLop {

	public:
		static const Sbecore::uint INS = 1;
		static const Sbecore::uint RMV = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVMaintable (full: VecWdbeVMaintable)
		*/
	class VecVMaintable {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint TBLWDBEMBANK = 2;
		static const Sbecore::uint TBLWDBEMCOMMAND = 3;
		static const Sbecore::uint TBLWDBEMCONTROLLER = 4;
		static const Sbecore::uint TBLWDBEMCOREPROJECT = 5;
		static const Sbecore::uint TBLWDBEMCOREVERSION = 6;
		static const Sbecore::uint TBLWDBEMERROR = 7;
		static const Sbecore::uint TBLWDBEMFAMILY = 8;
		static const Sbecore::uint TBLWDBEMFILE = 9;
		static const Sbecore::uint TBLWDBEMFSM = 10;
		static const Sbecore::uint TBLWDBEMFSMSTATE = 11;
		static const Sbecore::uint TBLWDBEMGENERIC = 12;
		static const Sbecore::uint TBLWDBEMIMBUF = 13;
		static const Sbecore::uint TBLWDBEMINTERRUPT = 14;
		static const Sbecore::uint TBLWDBEMLIBRARY = 15;
		static const Sbecore::uint TBLWDBEMMACHINE = 16;
		static const Sbecore::uint TBLWDBEMMODULE = 17;
		static const Sbecore::uint TBLWDBEMPERIPHERAL = 18;
		static const Sbecore::uint TBLWDBEMPERSON = 19;
		static const Sbecore::uint TBLWDBEMPIN = 20;
		static const Sbecore::uint TBLWDBEMPIPELINE = 21;
		static const Sbecore::uint TBLWDBEMPORT = 22;
		static const Sbecore::uint TBLWDBEMPROCESS = 23;
		static const Sbecore::uint TBLWDBEMPROJECT = 24;
		static const Sbecore::uint TBLWDBEMRELEASE = 25;
		static const Sbecore::uint TBLWDBEMSEGMENT = 26;
		static const Sbecore::uint TBLWDBEMSENSITIVITY = 27;
		static const Sbecore::uint TBLWDBEMSESSION = 28;
		static const Sbecore::uint TBLWDBEMSIGNAL = 29;
		static const Sbecore::uint TBLWDBEMSYSTEM = 30;
		static const Sbecore::uint TBLWDBEMTARGET = 31;
		static const Sbecore::uint TBLWDBEMUNIT = 32;
		static const Sbecore::uint TBLWDBEMUSER = 33;
		static const Sbecore::uint TBLWDBEMUSERGROUP = 34;
		static const Sbecore::uint TBLWDBEMVARIABLE = 35;
		static const Sbecore::uint TBLWDBEMVECTOR = 36;
		static const Sbecore::uint TBLWDBEMVECTORITEM = 37;
		static const Sbecore::uint TBLWDBEMVERSION = 38;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVOolop (full: VecWdbeVOolop)
		*/
	class VecVOolop {

	public:
		static const Sbecore::uint INA = 1;
		static const Sbecore::uint INB = 2;
		static const Sbecore::uint RMV = 3;
		static const Sbecore::uint SWP = 4;
		static const Sbecore::uint TOA = 5;
		static const Sbecore::uint TOB = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVPartype (full: VecWdbeVPartype)
		*/
	class VecVPartype {

	public:
		static const Sbecore::uint TIX = 1;
		static const Sbecore::uint _BOOL = 2;
		static const Sbecore::uint INT8 = 3;
		static const Sbecore::uint UINT8 = 4;
		static const Sbecore::uint INT16 = 5;
		static const Sbecore::uint UINT16 = 6;
		static const Sbecore::uint INT32 = 7;
		static const Sbecore::uint UINT32 = 8;
		static const Sbecore::uint BLOB = 9;
		static const Sbecore::uint VBLOB = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVPreset (full: VecWdbeVPreset)
		*/
	class VecVPreset {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint PREWDBEADMIN = 2;
		static const Sbecore::uint PREWDBEBNKLIST_SRF = 3;
		static const Sbecore::uint PREWDBEBNKLIST_UNT = 4;
		static const Sbecore::uint PREWDBECMDLIST_RET = 5;
		static const Sbecore::uint PREWDBECMDLIST_REU = 6;
		static const Sbecore::uint PREWDBECMDLIST_SRF = 7;
		static const Sbecore::uint PREWDBECPRLIST_CVR = 8;
		static const Sbecore::uint PREWDBECPRLIST_GRP = 9;
		static const Sbecore::uint PREWDBECPRLIST_OWN = 10;
		static const Sbecore::uint PREWDBECPRLIST_SRF = 11;
		static const Sbecore::uint PREWDBECPRLIST_TIT = 12;
		static const Sbecore::uint PREWDBECPRLIST_TYP = 13;
		static const Sbecore::uint PREWDBECPRMNPERSON_X1 = 14;
		static const Sbecore::uint PREWDBECVRLIST_BCV = 15;
		static const Sbecore::uint PREWDBECVRLIST_CPR = 16;
		static const Sbecore::uint PREWDBECVRLIST_GRP = 17;
		static const Sbecore::uint PREWDBECVRLIST_OWN = 18;
		static const Sbecore::uint PREWDBECVRLIST_STE = 19;
		static const Sbecore::uint PREWDBEERRLIST_RET = 20;
		static const Sbecore::uint PREWDBEERRLIST_REU = 21;
		static const Sbecore::uint PREWDBEERRLIST_SRF = 22;
		static const Sbecore::uint PREWDBEEXTFOLDER = 23;
		static const Sbecore::uint PREWDBEFAMLIST_TIT = 24;
		static const Sbecore::uint PREWDBEFAMLIST_VND = 25;
		static const Sbecore::uint PREWDBEFILLIST_FNM = 26;
		static const Sbecore::uint PREWDBEFILLIST_GRP = 27;
		static const Sbecore::uint PREWDBEFILLIST_OWN = 28;
		static const Sbecore::uint PREWDBEFILLIST_RET = 29;
		static const Sbecore::uint PREWDBEFILLIST_REU = 30;
		static const Sbecore::uint PREWDBEFSTLIST_FSM = 31;
		static const Sbecore::uint PREWDBEFSTLIST_SRF = 32;
		static const Sbecore::uint PREWDBEGENLIST_MDL = 33;
		static const Sbecore::uint PREWDBEGENLIST_SRF = 34;
		static const Sbecore::uint PREWDBEGITURL = 35;
		static const Sbecore::uint PREWDBEGROUP = 36;
		static const Sbecore::uint PREWDBEINTLIST_SRF = 37;
		static const Sbecore::uint PREWDBEINTLIST_UNT = 38;
		static const Sbecore::uint PREWDBEIP = 39;
		static const Sbecore::uint PREWDBEIXBASEREPTYPE = 40;
		static const Sbecore::uint PREWDBEIXCRDACCBNK = 41;
		static const Sbecore::uint PREWDBEIXCRDACCCMD = 42;
		static const Sbecore::uint PREWDBEIXCRDACCCPR = 43;
		static const Sbecore::uint PREWDBEIXCRDACCCVR = 44;
		static const Sbecore::uint PREWDBEIXCRDACCERR = 45;
		static const Sbecore::uint PREWDBEIXCRDACCFAM = 46;
		static const Sbecore::uint PREWDBEIXCRDACCFIL = 47;
		static const Sbecore::uint PREWDBEIXCRDACCFST = 48;
		static const Sbecore::uint PREWDBEIXCRDACCGEN = 49;
		static const Sbecore::uint PREWDBEIXCRDACCINT = 50;
		static const Sbecore::uint PREWDBEIXCRDACCLIB = 51;
		static const Sbecore::uint PREWDBEIXCRDACCMCH = 52;
		static const Sbecore::uint PREWDBEIXCRDACCMOD = 53;
		static const Sbecore::uint PREWDBEIXCRDACCMTP = 54;
		static const Sbecore::uint PREWDBEIXCRDACCPIN = 55;
		static const Sbecore::uint PREWDBEIXCRDACCPPH = 56;
		static const Sbecore::uint PREWDBEIXCRDACCPPL = 57;
		static const Sbecore::uint PREWDBEIXCRDACCPRC = 58;
		static const Sbecore::uint PREWDBEIXCRDACCPRJ = 59;
		static const Sbecore::uint PREWDBEIXCRDACCPRS = 60;
		static const Sbecore::uint PREWDBEIXCRDACCPRT = 61;
		static const Sbecore::uint PREWDBEIXCRDACCRLS = 62;
		static const Sbecore::uint PREWDBEIXCRDACCSEG = 63;
		static const Sbecore::uint PREWDBEIXCRDACCSIG = 64;
		static const Sbecore::uint PREWDBEIXCRDACCSIL = 65;
		static const Sbecore::uint PREWDBEIXCRDACCSNS = 66;
		static const Sbecore::uint PREWDBEIXCRDACCSYS = 67;
		static const Sbecore::uint PREWDBEIXCRDACCTRG = 68;
		static const Sbecore::uint PREWDBEIXCRDACCUNT = 69;
		static const Sbecore::uint PREWDBEIXCRDACCUSG = 70;
		static const Sbecore::uint PREWDBEIXCRDACCUSR = 71;
		static const Sbecore::uint PREWDBEIXCRDACCUTL = 72;
		static const Sbecore::uint PREWDBEIXCRDACCVAR = 73;
		static const Sbecore::uint PREWDBEIXCRDACCVEC = 74;
		static const Sbecore::uint PREWDBEIXCRDACCVER = 75;
		static const Sbecore::uint PREWDBEIXCRDACCVIT = 76;
		static const Sbecore::uint PREWDBEIXLCL = 77;
		static const Sbecore::uint PREWDBEIXORD = 78;
		static const Sbecore::uint PREWDBEIXPRE = 79;
		static const Sbecore::uint PREWDBEIXRECACC = 80;
		static const Sbecore::uint PREWDBEJREFNOTIFY = 81;
		static const Sbecore::uint PREWDBEJREFSESS = 82;
		static const Sbecore::uint PREWDBELIBAMAKEFILE_X1 = 83;
		static const Sbecore::uint PREWDBELIBAMAKEFILE_X2 = 84;
		static const Sbecore::uint PREWDBELIBLIST_SRF = 85;
		static const Sbecore::uint PREWDBEMCHAMAKEFILE_X1 = 86;
		static const Sbecore::uint PREWDBEMCHAPAR_X1 = 87;
		static const Sbecore::uint PREWDBEMCHLIST_SRF = 88;
		static const Sbecore::uint PREWDBEMCHLIST_SUP = 89;
		static const Sbecore::uint PREWDBEMODAPAR_X1 = 90;
		static const Sbecore::uint PREWDBEMODLIST_HKT = 91;
		static const Sbecore::uint PREWDBEMODLIST_HKU = 92;
		static const Sbecore::uint PREWDBEMODLIST_SRF = 93;
		static const Sbecore::uint PREWDBEMODLIST_SUP = 94;
		static const Sbecore::uint PREWDBEMODLIST_TPL = 95;
		static const Sbecore::uint PREWDBEMODLIST_TYP = 96;
		static const Sbecore::uint PREWDBEMTPAPAR_X1 = 97;
		static const Sbecore::uint PREWDBEMTPLIST_HKT = 98;
		static const Sbecore::uint PREWDBEMTPLIST_HKU = 99;
		static const Sbecore::uint PREWDBEMTPLIST_SRF = 100;
		static const Sbecore::uint PREWDBEMTPLIST_TYP = 101;
		static const Sbecore::uint PREWDBENOADM = 102;
		static const Sbecore::uint PREWDBEOWNER = 103;
		static const Sbecore::uint PREWDBEPINAPAR_X1 = 104;
		static const Sbecore::uint PREWDBEPINLIST_BNK = 105;
		static const Sbecore::uint PREWDBEPINLIST_SRF = 106;
		static const Sbecore::uint PREWDBEPPHAPAR_X1 = 107;
		static const Sbecore::uint PREWDBEPPHLIST_SRF = 108;
		static const Sbecore::uint PREWDBEPPHLIST_UNT = 109;
		static const Sbecore::uint PREWDBEPPLLIST_HSM = 110;
		static const Sbecore::uint PREWDBEPPLLIST_SRF = 111;
		static const Sbecore::uint PREWDBEPRCLIST_MDL = 112;
		static const Sbecore::uint PREWDBEPRCLIST_SRF = 113;
		static const Sbecore::uint PREWDBEPRJLIST_GRP = 114;
		static const Sbecore::uint PREWDBEPRJLIST_OWN = 115;
		static const Sbecore::uint PREWDBEPRJLIST_SHO = 116;
		static const Sbecore::uint PREWDBEPRJLIST_TIT = 117;
		static const Sbecore::uint PREWDBEPRJLIST_VER = 118;
		static const Sbecore::uint PREWDBEPRJMNPERSON_X1 = 119;
		static const Sbecore::uint PREWDBEPRSADETAIL_X1 = 120;
		static const Sbecore::uint PREWDBEPRSLIST_GRP = 121;
		static const Sbecore::uint PREWDBEPRSLIST_LNM = 122;
		static const Sbecore::uint PREWDBEPRSLIST_OWN = 123;
		static const Sbecore::uint PREWDBEPRSMNCOREPROJECT_X1 = 124;
		static const Sbecore::uint PREWDBEPRSMNPROJECT_X1 = 125;
		static const Sbecore::uint PREWDBEPRTLIST_MDL = 126;
		static const Sbecore::uint PREWDBEPRTLIST_SRF = 127;
		static const Sbecore::uint PREWDBEREFBNK = 128;
		static const Sbecore::uint PREWDBEREFCMD = 129;
		static const Sbecore::uint PREWDBEREFCPR = 130;
		static const Sbecore::uint PREWDBEREFCTR = 131;
		static const Sbecore::uint PREWDBEREFCVR = 132;
		static const Sbecore::uint PREWDBEREFERR = 133;
		static const Sbecore::uint PREWDBEREFFAM = 134;
		static const Sbecore::uint PREWDBEREFFIL = 135;
		static const Sbecore::uint PREWDBEREFFSM = 136;
		static const Sbecore::uint PREWDBEREFFST = 137;
		static const Sbecore::uint PREWDBEREFGEN = 138;
		static const Sbecore::uint PREWDBEREFIMB = 139;
		static const Sbecore::uint PREWDBEREFINT = 140;
		static const Sbecore::uint PREWDBEREFLIB = 141;
		static const Sbecore::uint PREWDBEREFMCH = 142;
		static const Sbecore::uint PREWDBEREFMCT = 143;
		static const Sbecore::uint PREWDBEREFMDL = 144;
		static const Sbecore::uint PREWDBEREFMIB = 145;
		static const Sbecore::uint PREWDBEREFMOD = 146;
		static const Sbecore::uint PREWDBEREFMTP = 147;
		static const Sbecore::uint PREWDBEREFPIN = 148;
		static const Sbecore::uint PREWDBEREFPPH = 149;
		static const Sbecore::uint PREWDBEREFPPL = 150;
		static const Sbecore::uint PREWDBEREFPRC = 151;
		static const Sbecore::uint PREWDBEREFPRJ = 152;
		static const Sbecore::uint PREWDBEREFPRS = 153;
		static const Sbecore::uint PREWDBEREFPRT = 154;
		static const Sbecore::uint PREWDBEREFRLS = 155;
		static const Sbecore::uint PREWDBEREFSEG = 156;
		static const Sbecore::uint PREWDBEREFSEL = 157;
		static const Sbecore::uint PREWDBEREFSES = 158;
		static const Sbecore::uint PREWDBEREFSIG = 159;
		static const Sbecore::uint PREWDBEREFSIL = 160;
		static const Sbecore::uint PREWDBEREFSNS = 161;
		static const Sbecore::uint PREWDBEREFSYS = 162;
		static const Sbecore::uint PREWDBEREFTRG = 163;
		static const Sbecore::uint PREWDBEREFUNI = 164;
		static const Sbecore::uint PREWDBEREFUNT = 165;
		static const Sbecore::uint PREWDBEREFUSG = 166;
		static const Sbecore::uint PREWDBEREFUSR = 167;
		static const Sbecore::uint PREWDBEREFVAR = 168;
		static const Sbecore::uint PREWDBEREFVEC = 169;
		static const Sbecore::uint PREWDBEREFVER = 170;
		static const Sbecore::uint PREWDBEREFVIT = 171;
		static const Sbecore::uint PREWDBEREPFOLDER = 172;
		static const Sbecore::uint PREWDBERLSLIST_MCH = 173;
		static const Sbecore::uint PREWDBERLSLIST_SRF = 174;
		static const Sbecore::uint PREWDBERLSLIST_TYP = 175;
		static const Sbecore::uint PREWDBERLSLIST_VER = 176;
		static const Sbecore::uint PREWDBESEGLIST_PPL = 177;
		static const Sbecore::uint PREWDBESEGLIST_SRF = 178;
		static const Sbecore::uint PREWDBESEGLIST_SUP = 179;
		static const Sbecore::uint PREWDBESESS = 180;
		static const Sbecore::uint PREWDBESIGLIST_CON = 181;
		static const Sbecore::uint PREWDBESIGLIST_MGT = 182;
		static const Sbecore::uint PREWDBESIGLIST_MGU = 183;
		static const Sbecore::uint PREWDBESIGLIST_RET = 184;
		static const Sbecore::uint PREWDBESIGLIST_REU = 185;
		static const Sbecore::uint PREWDBESIGLIST_SRF = 186;
		static const Sbecore::uint PREWDBESIGLIST_TYP = 187;
		static const Sbecore::uint PREWDBESIGLIST_VEC = 188;
		static const Sbecore::uint PREWDBESILLIST_MDL = 189;
		static const Sbecore::uint PREWDBESILLIST_RET = 190;
		static const Sbecore::uint PREWDBESILLIST_REU = 191;
		static const Sbecore::uint PREWDBESILLIST_SRF = 192;
		static const Sbecore::uint PREWDBESILLIST_SYS = 193;
		static const Sbecore::uint PREWDBESILLIST_TIT = 194;
		static const Sbecore::uint PREWDBESILLIST_TYP = 195;
		static const Sbecore::uint PREWDBESNSLIST_RET = 196;
		static const Sbecore::uint PREWDBESNSLIST_REU = 197;
		static const Sbecore::uint PREWDBESNSLIST_SRT = 198;
		static const Sbecore::uint PREWDBESNSLIST_SRU = 199;
		static const Sbecore::uint PREWDBESUSPSESS = 200;
		static const Sbecore::uint PREWDBESYSDATE = 201;
		static const Sbecore::uint PREWDBESYSLIST_SRF = 202;
		static const Sbecore::uint PREWDBESYSLIST_UNT = 203;
		static const Sbecore::uint PREWDBESYSLIST_VER = 204;
		static const Sbecore::uint PREWDBESYSSTAMP = 205;
		static const Sbecore::uint PREWDBESYSTIME = 206;
		static const Sbecore::uint PREWDBETLAST = 207;
		static const Sbecore::uint PREWDBETRGLIST_SRF = 208;
		static const Sbecore::uint PREWDBETRGLIST_SYS = 209;
		static const Sbecore::uint PREWDBETRGLIST_UNT = 210;
		static const Sbecore::uint PREWDBEUNTLIST_MDL = 211;
		static const Sbecore::uint PREWDBEUNTLIST_RET = 212;
		static const Sbecore::uint PREWDBEUNTLIST_REU = 213;
		static const Sbecore::uint PREWDBEUNTLIST_SRF = 214;
		static const Sbecore::uint PREWDBEUNTLIST_SYS = 215;
		static const Sbecore::uint PREWDBEUNTLIST_TIT = 216;
		static const Sbecore::uint PREWDBEUNTLIST_TYP = 217;
		static const Sbecore::uint PREWDBEUSGAACCESS_X1 = 218;
		static const Sbecore::uint PREWDBEUSGAACCESS_X2 = 219;
		static const Sbecore::uint PREWDBEUSGLIST_GRP = 220;
		static const Sbecore::uint PREWDBEUSGLIST_OWN = 221;
		static const Sbecore::uint PREWDBEUSGLIST_SRF = 222;
		static const Sbecore::uint PREWDBEUSRAACCESS_X1 = 223;
		static const Sbecore::uint PREWDBEUSRAACCESS_X2 = 224;
		static const Sbecore::uint PREWDBEUSRLIST_GRP = 225;
		static const Sbecore::uint PREWDBEUSRLIST_OWN = 226;
		static const Sbecore::uint PREWDBEUSRLIST_PRS = 227;
		static const Sbecore::uint PREWDBEUSRLIST_SRF = 228;
		static const Sbecore::uint PREWDBEUSRLIST_STE = 229;
		static const Sbecore::uint PREWDBEUSRLIST_USG = 230;
		static const Sbecore::uint PREWDBEVARLIST_RET = 231;
		static const Sbecore::uint PREWDBEVARLIST_REU = 232;
		static const Sbecore::uint PREWDBEVARLIST_SRF = 233;
		static const Sbecore::uint PREWDBEVECLIST_HKT = 234;
		static const Sbecore::uint PREWDBEVECLIST_HKU = 235;
		static const Sbecore::uint PREWDBEVECLIST_SRF = 236;
		static const Sbecore::uint PREWDBEVECLIST_TYP = 237;
		static const Sbecore::uint PREWDBEVERLIST_BVR = 238;
		static const Sbecore::uint PREWDBEVERLIST_GRP = 239;
		static const Sbecore::uint PREWDBEVERLIST_OWN = 240;
		static const Sbecore::uint PREWDBEVERLIST_PRJ = 241;
		static const Sbecore::uint PREWDBEVERLIST_STE = 242;
		static const Sbecore::uint PREWDBEVITLIST_SRF = 243;
		static const Sbecore::uint PREWDBEVITLIST_VEC = 244;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);
	};

	/**
		* VecVRecaccess (full: VecWdbeVRecaccess)
		*/
	class VecVRecaccess {

	public:
		static const Sbecore::uint FULL = 1;
		static const Sbecore::uint NONE = 2;
		static const Sbecore::uint VIEW = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVUserlevel (full: VecWdbeVUserlevel)
		*/
	class VecVUserlevel {

	public:
		static const Sbecore::uint ADM = 1;
		static const Sbecore::uint GADM = 2;
		static const Sbecore::uint REG = 3;
		static const Sbecore::uint VTOR = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVValuelist (full: VecWdbeVValuelist)
		*/
	class VecVValuelist {

	public:
		static const Sbecore::uint VLSTWDBEUMPERSONTITLE = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);
	};

	/**
		* VecWAccess (full: VecWdbeWAccess)
		*/
	class VecWAccess {

	public:
		static const Sbecore::uint EDIT = 1;
		static const Sbecore::uint EXEC = 2;
		static const Sbecore::uint VIEW = 4;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

		static void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	};

public:
	DbsWdbe();
	~DbsWdbe();

	void init(const Sbecore::uint _ixDbsVDbstype, const std::string& _dbspath, const std::string& _dbsname, const std::string& _ip, const Sbecore::uint _port, const std::string& _username, const std::string& _password);
	void term();

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	void initMy();
	void termMy();
#endif
#if defined(SBECORE_PG)
	void initPg();
	void termPg();
#endif

public:
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string username;
	std::string password;
	std::string ip;
	int port;

	bool initdone;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	MYSQL* dbsMy;
#endif
#if defined(SBECORE_PG)
	PGconn* dbsPg;
#endif

public:
	void begin();																						//!< transaction functionality
	bool commit();
	void rollback();

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	void beginMy();
	bool commitMy();
	void rollbackMy();
#endif
#if defined(SBECORE_PG)
	void beginPg();
	bool commitPg();
	void rollbackPg();
#endif

	bool loadUintBySQL(const std::string& sqlstr, Sbecore::uint& val);		//!< execute a SQL query returning a single uint (arbitrary tables)
	bool loadStringBySQL(const std::string& sqlstr, std::string& val);//!< execute a SQL query returning a single string (arbitrary tables)

	bool loadRefBySQL(const std::string& sqlstr, Sbecore::ubigint& ref);	//!< execute a SQL query returning a single reference (arbitrary tables)
																													//! load a list of references by a SQL query (arbitrary tables)
	Sbecore::ubigint loadRefsBySQL(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	bool loadUintBySQLMy(const std::string& sqlstr, Sbecore::uint& val);
	bool loadStringBySQLMy(const std::string& sqlstr, std::string& val);

	bool loadRefBySQLMy(const std::string& sqlstr, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySQLMy(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);
#endif

#if defined(SBECORE_PG)
	bool loadUintBySQLPg(const std::string& sqlstr, Sbecore::uint& val);
	bool loadStringBySQLPg(const std::string& sqlstr, std::string& val);

	bool loadRefBySQLPg(const std::string& sqlstr, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySQLPg(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);
#endif

	void executeQuery(const std::string& sqlstr);								//!< run single SQL command
	void executeQueryDiv(const std::string& sqlstrmy, const std::string& sqlstrpg);
	void executeFile(const std::string& fullpath);								//!< SQL file batch execution

public:
	Sbecore::uint getIxWSubsetByRefWdbeMModule(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByWdbeMModule(WdbeMModule* rec);

	Sbecore::uint getIxWSubsetByRefWdbeMUnit(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByWdbeMUnit(WdbeMUnit* rec);

	void fillFeedFromKlst(const Sbecore::uint klsIxWdbeVKeylist, const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);
	void fillFeedFromKlstByMtbUref(const Sbecore::uint klsIxWdbeVKeylist, const Sbecore::uint x1IxWdbeVMaintable, const Sbecore::ubigint x1Uref, const Sbecore::uint ixWdbeVLocale, Sbecore::Feed& feed);

	std::string getKlstTitleBySref(const Sbecore::uint klsIxWdbeVKeylist, const std::string& sref, const Sbecore::uint ixWdbeVLocale = 0);
	std::string getKlstTitleByMtbUrefSref(const Sbecore::uint klsIxWdbeVKeylist, const Sbecore::uint x1IxWdbeVMaintable, const Sbecore::ubigint x1Uref, const std::string& sref, const Sbecore::uint ixWdbeVLocale = 0);

	void fillFeedFromVlst(const Sbecore::uint vlsIxWdbeVValuelist, const Sbecore::uint x1IxWdbeVLocale, Sbecore::Feed& feed);

public:
	TblWdbeAccRMUserUniversal* tblwdbeaccrmuseruniversal;
	TblWdbeAMCommandInvpar* tblwdbeamcommandinvpar;
	TblWdbeAMCommandRetpar* tblwdbeamcommandretpar;
	TblWdbeAMCoreversionIp* tblwdbeamcoreversionip;
	TblWdbeAMCoreversionPlh* tblwdbeamcoreversionplh;
	TblWdbeAMErrorPar* tblwdbeamerrorpar;
	TblWdbeAMFsmstateStep* tblwdbeamfsmstatestep;
	TblWdbeAMLibraryMakefile* tblwdbeamlibrarymakefile;
	TblWdbeAMMachineMakefile* tblwdbeammachinemakefile;
	TblWdbeAMMachinePar* tblwdbeammachinepar;
	TblWdbeAMModulePar* tblwdbeammodulepar;
	TblWdbeAMPeripheralPar* tblwdbeamperipheralpar;
	TblWdbeAMPersonDetail* tblwdbeampersondetail;
	TblWdbeAMPinPar* tblwdbeampinpar;
	TblWdbeAMUserAccess* tblwdbeamuseraccess;
	TblWdbeAMUsergroupAccess* tblwdbeamusergroupaccess;
	TblWdbeAVControlPar* tblwdbeavcontrolpar;
	TblWdbeAVKeylistKey* tblwdbeavkeylistkey;
	TblWdbeAVValuelistVal* tblwdbeavvaluelistval;
	TblWdbeCFile* tblwdbecfile;
	TblWdbeCFsmstate* tblwdbecfsmstate;
	TblWdbeCGeneric* tblwdbecgeneric;
	TblWdbeCPin* tblwdbecpin;
	TblWdbeCPort* tblwdbecport;
	TblWdbeCSegment* tblwdbecsegment;
	TblWdbeCSignal* tblwdbecsignal;
	TblWdbeCVariable* tblwdbecvariable;
	TblWdbeHistRMUserUniversal* tblwdbehistrmuseruniversal;
	TblWdbeJAVKeylistKey* tblwdbejavkeylistkey;
	TblWdbeJMCoreversionState* tblwdbejmcoreversionstate;
	TblWdbeJMPersonLastname* tblwdbejmpersonlastname;
	TblWdbeJMPinSref* tblwdbejmpinsref;
	TblWdbeJMUserState* tblwdbejmuserstate;
	TblWdbeJMVersionState* tblwdbejmversionstate;
	TblWdbeMBank* tblwdbembank;
	TblWdbeMCommand* tblwdbemcommand;
	TblWdbeMController* tblwdbemcontroller;
	TblWdbeMCoreproject* tblwdbemcoreproject;
	TblWdbeMCoreversion* tblwdbemcoreversion;
	TblWdbeMError* tblwdbemerror;
	TblWdbeMFamily* tblwdbemfamily;
	TblWdbeMFile* tblwdbemfile;
	TblWdbeMFsm* tblwdbemfsm;
	TblWdbeMFsmstate* tblwdbemfsmstate;
	TblWdbeMGeneric* tblwdbemgeneric;
	TblWdbeMImbuf* tblwdbemimbuf;
	TblWdbeMInterrupt* tblwdbeminterrupt;
	TblWdbeMLibrary* tblwdbemlibrary;
	TblWdbeMMachine* tblwdbemmachine;
	TblWdbeMModule* tblwdbemmodule;
	TblWdbeMPeripheral* tblwdbemperipheral;
	TblWdbeMPerson* tblwdbemperson;
	TblWdbeMPin* tblwdbempin;
	TblWdbeMPipeline* tblwdbempipeline;
	TblWdbeMPort* tblwdbemport;
	TblWdbeMProcess* tblwdbemprocess;
	TblWdbeMProject* tblwdbemproject;
	TblWdbeMRelease* tblwdbemrelease;
	TblWdbeMSegment* tblwdbemsegment;
	TblWdbeMSensitivity* tblwdbemsensitivity;
	TblWdbeMSession* tblwdbemsession;
	TblWdbeMSignal* tblwdbemsignal;
	TblWdbeMSystem* tblwdbemsystem;
	TblWdbeMTarget* tblwdbemtarget;
	TblWdbeMUnit* tblwdbemunit;
	TblWdbeMUser* tblwdbemuser;
	TblWdbeMUsergroup* tblwdbemusergroup;
	TblWdbeMVariable* tblwdbemvariable;
	TblWdbeMVector* tblwdbemvector;
	TblWdbeMVectoritem* tblwdbemvectoritem;
	TblWdbeMVersion* tblwdbemversion;
	TblWdbeRMCommandMController* tblwdbermcommandmcontroller;
	TblWdbeRMCoreprojectMPerson* tblwdbermcoreprojectmperson;
	TblWdbeRMLibraryMVersion* tblwdbermlibrarymversion;
	TblWdbeRMModuleMModule* tblwdbermmodulemmodule;
	TblWdbeRMModuleMPeripheral* tblwdbermmodulemperipheral;
	TblWdbeRMPersonMProject* tblwdbermpersonmproject;
	TblWdbeRMUsergroupUniversal* tblwdbermusergroupuniversal;
	TblWdbeRMUserMUsergroup* tblwdbermusermusergroup;

	TblWdbeQBnk1NPin* tblwdbeqbnk1npin;
	TblWdbeQBnkList* tblwdbeqbnklist;
	TblWdbeQCmdAInvpar* tblwdbeqcmdainvpar;
	TblWdbeQCmdARetpar* tblwdbeqcmdaretpar;
	TblWdbeQCmdList* tblwdbeqcmdlist;
	TblWdbeQCmdMNController* tblwdbeqcmdmncontroller;
	TblWdbeQCpr1NCoreversion* tblwdbeqcpr1ncoreversion;
	TblWdbeQCprList* tblwdbeqcprlist;
	TblWdbeQCprMNPerson* tblwdbeqcprmnperson;
	TblWdbeQCvrAIp* tblwdbeqcvraip;
	TblWdbeQCvrAPlh* tblwdbeqcvraplh;
	TblWdbeQCvrBcv1NCoreversion* tblwdbeqcvrbcv1ncoreversion;
	TblWdbeQCvrHk1NModule* tblwdbeqcvrhk1nmodule;
	TblWdbeQCvrList* tblwdbeqcvrlist;
	TblWdbeQErrAPar* tblwdbeqerrapar;
	TblWdbeQErrList* tblwdbeqerrlist;
	TblWdbeQFam1NUnit* tblwdbeqfam1nunit;
	TblWdbeQFamList* tblwdbeqfamlist;
	TblWdbeQFilList* tblwdbeqfillist;
	TblWdbeQFstAStep* tblwdbeqfstastep;
	TblWdbeQFstList* tblwdbeqfstlist;
	TblWdbeQGenList* tblwdbeqgenlist;
	TblWdbeQIntList* tblwdbeqintlist;
	TblWdbeQIntSrc1NSensitivity* tblwdbeqintsrc1nsensitivity;
	TblWdbeQLibAMakefile* tblwdbeqlibamakefile;
	TblWdbeQLibList* tblwdbeqliblist;
	TblWdbeQLibMNVersion* tblwdbeqlibmnversion;
	TblWdbeQMch1NRelease* tblwdbeqmch1nrelease;
	TblWdbeQMchAMakefile* tblwdbeqmchamakefile;
	TblWdbeQMchAPar* tblwdbeqmchapar;
	TblWdbeQMchList* tblwdbeqmchlist;
	TblWdbeQMchSup1NMachine* tblwdbeqmchsup1nmachine;
	TblWdbeQMod1NProcess* tblwdbeqmod1nprocess;
	TblWdbeQModAPar* tblwdbeqmodapar;
	TblWdbeQModCorMNModule* tblwdbeqmodcormnmodule;
	TblWdbeQModCtdMNModule* tblwdbeqmodctdmnmodule;
	TblWdbeQModCtrHk1NVector* tblwdbeqmodctrhk1nvector;
	TblWdbeQModCtrMNCommand* tblwdbeqmodctrmncommand;
	TblWdbeQModCtrRef1NCommand* tblwdbeqmodctrref1ncommand;
	TblWdbeQModCtrRef1NError* tblwdbeqmodctrref1nerror;
	TblWdbeQModHsm1NPipeline* tblwdbeqmodhsm1npipeline;
	TblWdbeQModKHdltype* tblwdbeqmodkhdltype;
	TblWdbeQModList* tblwdbeqmodlist;
	TblWdbeQModMdl1NGeneric* tblwdbeqmodmdl1ngeneric;
	TblWdbeQModMdl1NPort* tblwdbeqmodmdl1nport;
	TblWdbeQModMge1NSignal* tblwdbeqmodmge1nsignal;
	TblWdbeQModMNPeripheral* tblwdbeqmodmnperipheral;
	TblWdbeQModRef1NSensitivity* tblwdbeqmodref1nsensitivity;
	TblWdbeQModRef1NSignal* tblwdbeqmodref1nsignal;
	TblWdbeQModRef1NVariable* tblwdbeqmodref1nvariable;
	TblWdbeQModSup1NModule* tblwdbeqmodsup1nmodule;
	TblWdbeQMtpAPar* tblwdbeqmtpapar;
	TblWdbeQMtpHsm1NPipeline* tblwdbeqmtphsm1npipeline;
	TblWdbeQMtpKHdltype* tblwdbeqmtpkhdltype;
	TblWdbeQMtpKParKey* tblwdbeqmtpkparkey;
	TblWdbeQMtpList* tblwdbeqmtplist;
	TblWdbeQMtpMdl1NGeneric* tblwdbeqmtpmdl1ngeneric;
	TblWdbeQMtpMdl1NPort* tblwdbeqmtpmdl1nport;
	TblWdbeQMtpMge1NSignal* tblwdbeqmtpmge1nsignal;
	TblWdbeQMtpRef1NFile* tblwdbeqmtpref1nfile;
	TblWdbeQMtpRef1NSensitivity* tblwdbeqmtpref1nsensitivity;
	TblWdbeQMtpRef1NVariable* tblwdbeqmtpref1nvariable;
	TblWdbeQMtpSup1NModule* tblwdbeqmtpsup1nmodule;
	TblWdbeQMtpTpl1NModule* tblwdbeqmtptpl1nmodule;
	TblWdbeQPinAPar* tblwdbeqpinapar;
	TblWdbeQPinList* tblwdbeqpinlist;
	TblWdbeQPphAPar* tblwdbeqpphapar;
	TblWdbeQPphList* tblwdbeqpphlist;
	TblWdbeQPphMNModule* tblwdbeqpphmnmodule;
	TblWdbeQPplList* tblwdbeqppllist;
	TblWdbeQPplPpl1NSegment* tblwdbeqpplppl1nsegment;
	TblWdbeQPrcFsmFsm1NFsmstate* tblwdbeqprcfsmfsm1nfsmstate;
	TblWdbeQPrcKHdltype* tblwdbeqprckhdltype;
	TblWdbeQPrcList* tblwdbeqprclist;
	TblWdbeQPrcMge1NSignal* tblwdbeqprcmge1nsignal;
	TblWdbeQPrcRef1NSensitivity* tblwdbeqprcref1nsensitivity;
	TblWdbeQPrcRef1NVariable* tblwdbeqprcref1nvariable;
	TblWdbeQPreselect* tblwdbeqpreselect;
	TblWdbeQPrjList* tblwdbeqprjlist;
	TblWdbeQPrjMNPerson* tblwdbeqprjmnperson;
	TblWdbeQPrjPrj1NVersion* tblwdbeqprjprj1nversion;
	TblWdbeQPrsADetail* tblwdbeqprsadetail;
	TblWdbeQPrsList* tblwdbeqprslist;
	TblWdbeQPrsMNCoreproject* tblwdbeqprsmncoreproject;
	TblWdbeQPrsMNProject* tblwdbeqprsmnproject;
	TblWdbeQPrtList* tblwdbeqprtlist;
	TblWdbeQPrtSrc1NSensitivity* tblwdbeqprtsrc1nsensitivity;
	TblWdbeQRlsList* tblwdbeqrlslist;
	TblWdbeQSegList* tblwdbeqseglist;
	TblWdbeQSegSup1NSegment* tblwdbeqsegsup1nsegment;
	TblWdbeQSelect* tblwdbeqselect;
	TblWdbeQSigList* tblwdbeqsiglist;
	TblWdbeQSigSrc1NSensitivity* tblwdbeqsigsrc1nsensitivity;
	TblWdbeQSil1NBank* tblwdbeqsil1nbank;
	TblWdbeQSil1NInterrupt* tblwdbeqsil1ninterrupt;
	TblWdbeQSil1NPeripheral* tblwdbeqsil1nperipheral;
	TblWdbeQSil1NTarget* tblwdbeqsil1ntarget;
	TblWdbeQSilFwd1NController* tblwdbeqsilfwd1ncontroller;
	TblWdbeQSilHk1NModule* tblwdbeqsilhk1nmodule;
	TblWdbeQSilHk1NVector* tblwdbeqsilhk1nvector;
	TblWdbeQSilList* tblwdbeqsillist;
	TblWdbeQSilRef1NCommand* tblwdbeqsilref1ncommand;
	TblWdbeQSilRef1NError* tblwdbeqsilref1nerror;
	TblWdbeQSilRef1NSignal* tblwdbeqsilref1nsignal;
	TblWdbeQSilSil1NUnit* tblwdbeqsilsil1nunit;
	TblWdbeQSnsList* tblwdbeqsnslist;
	TblWdbeQSysHk1NVector* tblwdbeqsyshk1nvector;
	TblWdbeQSysList* tblwdbeqsyslist;
	TblWdbeQSysSys1NTarget* tblwdbeqsyssys1ntarget;
	TblWdbeQTrgList* tblwdbeqtrglist;
	TblWdbeQUnt1NBank* tblwdbequnt1nbank;
	TblWdbeQUnt1NInterrupt* tblwdbequnt1ninterrupt;
	TblWdbeQUnt1NPeripheral* tblwdbequnt1nperipheral;
	TblWdbeQUnt1NTarget* tblwdbequnt1ntarget;
	TblWdbeQUntFwd1NController* tblwdbequntfwd1ncontroller;
	TblWdbeQUntHk1NModule* tblwdbequnthk1nmodule;
	TblWdbeQUntHk1NVector* tblwdbequnthk1nvector;
	TblWdbeQUntList* tblwdbequntlist;
	TblWdbeQUntRef1NCommand* tblwdbequntref1ncommand;
	TblWdbeQUntRef1NError* tblwdbequntref1nerror;
	TblWdbeQUntRef1NSignal* tblwdbequntref1nsignal;
	TblWdbeQUntSil1NUnit* tblwdbequntsil1nunit;
	TblWdbeQUsgAAccess* tblwdbequsgaaccess;
	TblWdbeQUsgList* tblwdbequsglist;
	TblWdbeQUsgMNUser* tblwdbequsgmnuser;
	TblWdbeQUsr1NSession* tblwdbequsr1nsession;
	TblWdbeQUsrAAccess* tblwdbequsraaccess;
	TblWdbeQUsrList* tblwdbequsrlist;
	TblWdbeQUsrMNUsergroup* tblwdbequsrmnusergroup;
	TblWdbeQVarList* tblwdbeqvarlist;
	TblWdbeQVecList* tblwdbeqveclist;
	TblWdbeQVecVec1NVectoritem* tblwdbeqvecvec1nvectoritem;
	TblWdbeQVer1NRelease* tblwdbeqver1nrelease;
	TblWdbeQVer1NSystem* tblwdbeqver1nsystem;
	TblWdbeQVer1NUnit* tblwdbeqver1nunit;
	TblWdbeQVerBvr1NVersion* tblwdbeqverbvr1nversion;
	TblWdbeQVerList* tblwdbeqverlist;
	TblWdbeQVerMNLibrary* tblwdbeqvermnlibrary;
	TblWdbeQVerRef1NFile* tblwdbeqverref1nfile;
	TblWdbeQVitList* tblwdbeqvitlist;
};
#endif
