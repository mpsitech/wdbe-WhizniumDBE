/**
	* \file RootWdbe.cpp
	* job handler for job RootWdbe (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbed.h>
#endif

#include "RootWdbe.h"

#include "RootWdbe_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

/******************************************************************************
 class RootWdbe
 ******************************************************************************/

RootWdbe::RootWdbe(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, const ubigint jrefSup
			, const bool _clearAll
		) :
			JobWdbe(xchg, VecWdbeVJob::ROOTWDBE, jrefSup, VecWdbeVLocale::ENUS)
		{
	jref = xchg->addJob(dbswdbe, this, jrefSup);

	license = NULL;

	// IP constructor.cust1 --- INSERT

	// log
	xchg->appendToLogfile("root job created");

	if (_clearAll) clearAll(dbswdbe);
	else clearQtb(dbswdbe);

	license = new JobWdbeLicense(xchg, dbswdbe, jref, ixWdbeVLocale);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecWdbeVCall::CALLWDBELOGOUT, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBESUSPSESS, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWdbeVCall::CALLWDBEREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	if (xchg->stgwdbeappearance.roottterm != 0) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * xchg->stgwdbeappearance.roottterm);
};

RootWdbe::~RootWdbe() {
	// log
	xchg->appendToLogfile("root job deleted");

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void RootWdbe::clearAll(
			DbsWdbe* dbswdbe
		) {
	WdbeMUsergroup* usg = NULL;
	WdbeRMUserMUsergroup* uru = NULL;
	WdbeMUser* usr = NULL;
	WdbeMPerson* prs = NULL;

	time_t now;

	string s;

	// empty out tables
	dbswdbe->executeQuery("DELETE FROM TblWdbeAccRMUserUniversal");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMCommandInvpar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMCommandRetpar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMCoreversionIp");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMCoreversionPlh");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMErrorPar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMFsmstateStep");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMLibraryMakefile");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMMachineMakefile");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMMachinePar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMModulePar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMPeripheralPar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMPersonDetail");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMPinPar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMUserAccess");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAMUsergroupAccess");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAVControlPar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAVKeylistKey");
	dbswdbe->executeQuery("DELETE FROM TblWdbeAVValuelistVal");
	if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::MY) dbswdbe->executeQuery("DELETE FROM TblWdbeCFile");
	else if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::PG) dbswdbe->executeQuery("ALTER SEQUENCE TblWdbeCFile RESTART WITH 1");
	if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::MY) dbswdbe->executeQuery("DELETE FROM TblWdbeCFsmstate");
	else if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::PG) dbswdbe->executeQuery("ALTER SEQUENCE TblWdbeCFsmstate RESTART WITH 1");
	if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::MY) dbswdbe->executeQuery("DELETE FROM TblWdbeCGeneric");
	else if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::PG) dbswdbe->executeQuery("ALTER SEQUENCE TblWdbeCGeneric RESTART WITH 1");
	if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::MY) dbswdbe->executeQuery("DELETE FROM TblWdbeCPin");
	else if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::PG) dbswdbe->executeQuery("ALTER SEQUENCE TblWdbeCPin RESTART WITH 1");
	if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::MY) dbswdbe->executeQuery("DELETE FROM TblWdbeCPort");
	else if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::PG) dbswdbe->executeQuery("ALTER SEQUENCE TblWdbeCPort RESTART WITH 1");
	if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::MY) dbswdbe->executeQuery("DELETE FROM TblWdbeCSegment");
	else if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::PG) dbswdbe->executeQuery("ALTER SEQUENCE TblWdbeCSegment RESTART WITH 1");
	if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::MY) dbswdbe->executeQuery("DELETE FROM TblWdbeCSignal");
	else if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::PG) dbswdbe->executeQuery("ALTER SEQUENCE TblWdbeCSignal RESTART WITH 1");
	if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::MY) dbswdbe->executeQuery("DELETE FROM TblWdbeCVariable");
	else if (dbswdbe->ixDbsVDbstype == VecDbsVDbstype::PG) dbswdbe->executeQuery("ALTER SEQUENCE TblWdbeCVariable RESTART WITH 1");
	dbswdbe->executeQuery("DELETE FROM TblWdbeHistRMUserUniversal");
	dbswdbe->executeQuery("DELETE FROM TblWdbeJAVKeylistKey");
	dbswdbe->executeQuery("DELETE FROM TblWdbeJMCoreversionState");
	dbswdbe->executeQuery("DELETE FROM TblWdbeJMPersonLastname");
	dbswdbe->executeQuery("DELETE FROM TblWdbeJMPinSref");
	dbswdbe->executeQuery("DELETE FROM TblWdbeJMUserState");
	dbswdbe->executeQuery("DELETE FROM TblWdbeJMVersionState");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMBank");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMCommand");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMController");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMCoreproject");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMCoreversion");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMError");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMFamily");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMFile");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMFsm");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMFsmstate");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMGeneric");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMImbuf");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMInterrupt");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMLibrary");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMMachine");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMModule");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMPeripheral");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMPerson");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMPin");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMPipeline");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMPort");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMProcess");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMProject");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMRelease");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMSegment");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMSensitivity");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMSession");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMSignal");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMSystem");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMTarget");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMUnit");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMUser");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMUsergroup");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMVariable");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMVector");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMVectoritem");
	dbswdbe->executeQuery("DELETE FROM TblWdbeMVersion");
	dbswdbe->executeQuery("DELETE FROM TblWdbeRMCommandMController");
	dbswdbe->executeQuery("DELETE FROM TblWdbeRMCoreprojectMPerson");
	dbswdbe->executeQuery("DELETE FROM TblWdbeRMLibraryMVersion");
	dbswdbe->executeQuery("DELETE FROM TblWdbeRMModuleMModule");
	dbswdbe->executeQuery("DELETE FROM TblWdbeRMModuleMPeripheral");
	dbswdbe->executeQuery("DELETE FROM TblWdbeRMPersonMProject");
	dbswdbe->executeQuery("DELETE FROM TblWdbeRMUsergroupUniversal");
	dbswdbe->executeQuery("DELETE FROM TblWdbeRMUserMUsergroup");

	clearQtb(dbswdbe);

	// generate a temporary user such that a session can be generated
	time(&now);

	dbswdbe->tblwdbemusergroup->insertNewRec(&usg, 0, 0, "temp", "temporary user group for system initialization");
	dbswdbe->tblwdbeamusergroupaccess->insertNewRec(NULL, usg->ref, VecWdbeVFeatgroup::VECWDBEVCARD, "CrdWdbeNav", VecWdbeWAccess::EDIT + VecWdbeWAccess::EXEC + VecWdbeWAccess::VIEW);
	dbswdbe->tblwdbermusermusergroup->insertNewRec(&uru, 0, usg->ref, VecWdbeVUserlevel::GADM);
	dbswdbe->tblwdbemuser->insertNewRec(&usr, usg->ref, 0, uru->ref, usg->ref, 0, "temp", 0, VecWdbeVMUserState::DUE, VecWdbeVLocale::ENUS, VecWdbeVUserlevel::GADM, "asdf1234", "", "temporary user for system initialization");
	usr->refJState = dbswdbe->tblwdbejmuserstate->insertNewRec(NULL, usr->ref, 0, VecWdbeVMUserState::DUE);
	dbswdbe->tblwdbejmuserstate->insertNewRec(NULL, usr->ref, now + 24*3600, VecWdbeVMUserState::EXP);
	usr->refWdbeMPerson = dbswdbe->tblwdbemperson->insertNewRec(&prs, usg->ref, usr->ref, VecWdbeWMPersonDerivate::USR, VecWdbeVMPersonSex::M, "Mr.", "Jack", 0, "Smith", 0, "", 0, "", "Dear Jack");

	prs->refJLastname = dbswdbe->tblwdbejmpersonlastname->insertNewRec(NULL, prs->ref, 0, "Smith");

	usg->grp = usg->ref;
	usg->own = usr->ref;
	dbswdbe->tblwdbemusergroup->updateRec(usg);

	uru->refWdbeMUser = usr->ref;
	dbswdbe->tblwdbermusermusergroup->updateRec(uru);

	dbswdbe->tblwdbemuser->updateRec(usr);

	dbswdbe->tblwdbemperson->updateRec(prs);

	cout << "\ttemporary account created for user 'temp', expires " << Ftm::stamp(now + 24*3600) << "; use password 'asdf1234' to log in" << endl;

	xchg->appendToLogfile("database cleared");

	delete usg;
	delete uru;
	delete usr;
	delete prs;
};

void RootWdbe::clearQtb(
			DbsWdbe* dbswdbe
		) {
	dbswdbe->executeQuery("DELETE FROM TblWdbeQBnk1NPin");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQBnkList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCmdAInvpar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCmdARetpar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCmdList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCmdMNController");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCpr1NCoreversion");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCprList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCprMNPerson");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCvrAIp");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCvrAPlh");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCvrBcv1NCoreversion");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCvrHk1NModule");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQCvrList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQErrAPar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQErrList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQFam1NUnit");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQFamList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQFilList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQFstAStep");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQFstList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQGenList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQIntList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQIntSrc1NSensitivity");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQLibAMakefile");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQLibList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQLibMNVersion");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMch1NRelease");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMchAMakefile");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMchAPar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMchList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMchSup1NMachine");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMod1NProcess");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModAPar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModCorMNModule");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModCtdMNModule");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModCtrHk1NVector");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModCtrMNCommand");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModCtrRef1NCommand");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModCtrRef1NError");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModHsm1NPipeline");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModKHdltype");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModMdl1NGeneric");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModMdl1NPort");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModMge1NSignal");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModMNPeripheral");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModRef1NSensitivity");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModRef1NSignal");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModRef1NVariable");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQModSup1NModule");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpAPar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpHsm1NPipeline");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpKHdltype");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpKParKey");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpMdl1NGeneric");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpMdl1NPort");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpMge1NSignal");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpRef1NFile");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpRef1NSensitivity");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpRef1NVariable");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpSup1NModule");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQMtpTpl1NModule");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPinAPar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPinList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPphAPar");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPphList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPphMNModule");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPplList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPplPpl1NSegment");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrcFsmFsm1NFsmstate");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrcKHdltype");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrcList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrcMge1NSignal");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrcRef1NSensitivity");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrcRef1NVariable");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPreselect");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrjList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrjMNPerson");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrjPrj1NVersion");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrsADetail");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrsList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrsMNCoreproject");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrsMNProject");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrtList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQPrtSrc1NSensitivity");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQRlsList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSegList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSegSup1NSegment");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSelect");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSigList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSigSrc1NSensitivity");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSil1NBank");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSil1NInterrupt");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSil1NPeripheral");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSil1NTarget");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSilFwd1NController");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSilHk1NModule");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSilHk1NVector");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSilList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSilRef1NCommand");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSilRef1NError");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSilRef1NSignal");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSilSil1NUnit");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSnsList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSysHk1NVector");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSysList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQSysSys1NTarget");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQTrgList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUnt1NBank");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUnt1NInterrupt");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUnt1NPeripheral");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUnt1NTarget");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUntFwd1NController");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUntHk1NModule");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUntHk1NVector");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUntList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUntRef1NCommand");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUntRef1NError");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUntRef1NSignal");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUntSil1NUnit");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUsgAAccess");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUsgList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUsgMNUser");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUsr1NSession");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUsrAAccess");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUsrList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQUsrMNUsergroup");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQVarList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQVecList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQVecVec1NVectoritem");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQVer1NRelease");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQVer1NSystem");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQVer1NUnit");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQVerBvr1NVersion");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQVerList");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQVerMNLibrary");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQVerRef1NFile");
	dbswdbe->executeQuery("DELETE FROM TblWdbeQVitList");
};

bool RootWdbe::authenticate(
			DbsWdbe* dbswdbe
			, const string& username
			, const string& password
			, ubigint& refWdbeMUser
		) {
	bool valid = false;

	ubigint ref;

	WdbeMUser* usr = NULL;

	time_t now;

	refWdbeMUser = 0;

	if (dbswdbe->tblwdbemuser->loadRecBySrfPwd(username, password, &usr)) {
		if ((usr->ixVState == VecWdbeVMUserState::DSG) || (usr->ixVState == VecWdbeVMUserState::DUE)) {
			// check if expired
			time(&now);

			if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeJMUserState WHERE refWdbeMUser = " + to_string(usr->ref) + " AND x1Start < " + to_string(now) + " AND ixVState = " + to_string(VecWdbeVMUserState::EXP) + " ORDER BY x1Start DESC LIMIT 1", ref)) {
				usr->refJState = ref;
				usr->ixVState = VecWdbeVMUserState::EXP;
				dbswdbe->tblwdbemuser->updateRec(usr);
			};
		};

		valid = ((usr->ixVState == VecWdbeVMUserState::ACT) || (usr->ixVState == VecWdbeVMUserState::DUE));

		if (valid) refWdbeMUser = usr->ref;

		delete usr;
	};

	return valid;
};

void RootWdbe::handleRequest(
			DbsWdbe* dbswdbe
			, ReqWdbe* req
		) {
	if (req->ixVBasetype == ReqWdbe::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tclearAll" << endl;
			cout << "\tcreateSess" << endl;
			cout << "\teraseSess" << endl;
			cout << "\texportIni" << endl;
			cout << "\ttest" << endl;
		} else if (req->cmd == "clearAll") {
			req->retain = handleClearAll(dbswdbe);

		} else if (req->cmd == "createSess") {
			req->retain = handleCreateSess(dbswdbe);

		} else if (req->cmd == "eraseSess") {
			req->retain = handleEraseSess(dbswdbe);

		} else if (req->cmd == "exportIni") {
			req->retain = handleExportIni(dbswdbe);

		} else if (req->cmd == "test") {
			req->retain = handleTest(dbswdbe);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWdbeVDpch == VecWdbeVDpch::DPCHAPPROOTWDBELOGIN) {
			handleDpchAppLogin(dbswdbe, (DpchAppLogin*) (req->dpchapp), req->ip, &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWdbe::VecVBasetype::TIMER) {
		if (req->sref == "warnterm") handleTimerWithSrefWarnterm(dbswdbe);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::IDLE)) handleTimerWithSrefMonInSgeIdle(dbswdbe);
	};
};

bool RootWdbe::handleClearAll(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	clearAll(dbswdbe);
	return retval;
};

bool RootWdbe::handleCreateSess(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	string input;
	string input2;

	ubigint refUsr;

	cout << "\tuser name: ";
	cin >> input;
	cout << "\tpassword: ";
	cin >> input2;

	// verify password and create a session
	if (authenticate(dbswdbe, input, input2, refUsr)) {
		xchg->jrefCmd = insertSubjob(sesss, new SessWdbe(xchg, dbswdbe, jref, refUsr, "127.0.0.1"));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;

		if ((xchg->stgwdbeappearance.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (xchg->stgwdbeappearance.sesstterm - xchg->stgwdbeappearance.sesstwarn));

		xchg->appendToLogfile("command line session created for user '" + input + "'");

	} else {
		cout << "\tlogin failed." << endl;

		xchg->appendToLogfile("command line login refused for user '" + input + "'");
	};

	return retval;
};

bool RootWdbe::handleEraseSess(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;

	string input;
	ubigint iinput;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	if (!eraseSubjobByJref(sesss, iinput)) cout << "\tjob reference doesn't exist!" << endl;
	else cout << "\tsession erased." << endl;

	return retval;
};

bool RootWdbe::handleExportIni(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleExportIni --- IBEGIN

	// (re-)export initialization data
	vector<ubigint> refs;

	map<uint,uint> icsWdbeVIop;

	JobWdbeIexIni* iexini = NULL;
	iexini = new JobWdbeIexIni(xchg, dbswdbe, jref, ixWdbeVLocale);

	iexini->reset(dbswdbe);

	// ImeIMCoreproject
	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMCoreproject ORDER BY sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimcoreproject.nodes.push_back(new ImeitemIWdbeIniMCoreproject(dbswdbe, refs[i]));

	// ImeIMFamily
	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMFamily ORDER BY Title ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimfamily.nodes.push_back(new ImeitemIWdbeIniMFamily(dbswdbe, refs[i]));

	// ImeIMFile1
	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMFile WHERE refIxVTbl = " + to_string(VecWdbeVMFileRefTbl::VOID) + " ORDER BY Filename ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimfile1.nodes.push_back(new ImeitemIWdbeIniMFile1(dbswdbe, refs[i]));

	// ImeIMLibrary
	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMLibrary ORDER BY sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimlibrary.nodes.push_back(new ImeitemIWdbeIniMLibrary(dbswdbe, refs[i]));

	// ImeIMMachine
	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMMachine ORDER BY supRefWdbeMMachine ASC, sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimmachine.nodes.push_back(new ImeitemIWdbeIniMMachine(dbswdbe, refs[i]));

	// ImeIMModule
	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::VOID) +  " ORDER BY sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimmodule.nodes.push_back(new ImeitemIWdbeIniMModule(dbswdbe, refs[i]));

	// ImeIMUnit
	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMUnit WHERE refIxVTbl <> " + to_string(VecWdbeVMUnitRefTbl::VER) +  " ORDER BY sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimunit.nodes.push_back(new ImeitemIWdbeIniMUnit(dbswdbe, refs[i]));

	// ImeIMUsergroup
	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMUsergroup ORDER BY sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimusergroup.nodes.push_back(new ImeitemIWdbeIniMUsergroup(dbswdbe, refs[i]));

	icsWdbeVIop = IexWdbeIni::icsWdbeVIopInsAll();

	iexini->collect(dbswdbe, icsWdbeVIop);

	iexini->exportToFile(dbswdbe, "./IexWdbeIni_exported.txt", false);

	delete iexini;

	// IP handleExportIni --- IEND
	return retval;
};

bool RootWdbe::handleTest(
			DbsWdbe* dbswdbe
		) {
	bool retval = false;
	// IP handleTest --- IBEGIN

	// derive hash from list of projects
	string hash;

	ListWdbeMProject prjs;
	WdbeMProject* prj = NULL;

	dbswdbe->tblwdbemproject->loadRstBySQL("SELECT * FROM TblWdbeMProject ORDER BY Short ASC", false, prjs);

	for (unsigned int i = 0; i < prjs.nodes.size(); i++) {
		prj = prjs.nodes[i];
		hash += prj->Short + prj->Title;
	};

	cout << "project list hash: '" << hash << "'" << endl;

	// derive hash for (build-ready) versions
	//string hash;
	ubigint refWdbeMProject;

	ListWdbeMVersion vers;
	WdbeMVersion* ver = NULL;

//	ListWdbeJMVersionState verJstes;
//	WdbeJMVersionState* verJste = NULL;

	ListWdbeMRelease rlss;
	WdbeMRelease* rls = NULL;

	ListWdbeMUnit unts;
	WdbeMUnit* unt = NULL;

	ListWdbeMPeripheral pphs;
	WdbeMPeripheral* pph = NULL;

	ListWdbeMModule mdls;
	WdbeMModule* mdl = NULL;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeMVector vecs;
	WdbeMVector* vec = NULL;

	ListWdbeMProcess prcs;
	WdbeMProcess* prc = NULL;

	for (unsigned int k = 0; k < prjs.nodes.size(); k++) {
		prj = prjs.nodes[k];

		refWdbeMProject = prj->ref;

		dbswdbe->tblwdbemversion->loadRstBySQL("SELECT * FROM TblWdbeMVersion WHERE prjRefWdbeMProject = " + to_string(refWdbeMProject) + " AND ixVState = " + to_string(VecWdbeVMVersionState::READY)
					+ " ORDER BY prjNum ASC, Major ASC, Minor ASC, Sub ASC", false, vers);
		for (unsigned int i = 0; i < vers.nodes.size(); i++) {
			ver = vers.nodes[i];

			hash = to_string(ver->Major) + to_string(ver->Minor) + to_string(ver->Sub);

/*
			dbswdbe->tblwdbejmversionstate->loadRstByVer(ver->ref, false, verJstes);
			for (unsigned int j = 0; j < verJstes.nodes.size(); j++) {
				verJste = verJstes.nodes[j];
				hash += to_string(verJste->x1Start) + VecWdbeVMVersionState::getSref(verJste->ixVState);
			};
*/
			dbswdbe->tblwdbemrelease->loadRstByVer(ver->ref, false, rlss);
			for (unsigned int j = 0; j < rlss.nodes.size(); j++) {
				rls = rlss.nodes[j];
				hash += rls->sref;
			};

			dbswdbe->tblwdbemunit->loadRstByRetReu(VecWdbeVMUnitRefTbl::VER, ver->ref, false, unts);
			for (unsigned int j = 0; j < unts.nodes.size(); j++) {
				unt = unts.nodes[j];
				hash += unt->sref;
			};

			dbswdbe->tblwdbemperipheral->loadRstBySQL("SELECT TblWdbeMPeripheral.* FROM TblWdbeMUnit, TblWdbeMPeripheral WHERE TblWdbeMPeripheral.refWdbeMUnit = TblWdbeMUnit.ref AND TblWdbeMUnit.refIxVTbl = "
						+ to_string(VecWdbeVMUnitRefTbl::VER) + " AND TblWdbeMUnit.refUref = " + to_string(ver->ref) + " ORDER BY TblWdbeMPeripheral.sref ASC", false, pphs);
			for (unsigned int j = 0; j < pphs.nodes.size(); j++) {
				pph = pphs.nodes[j];
				hash += pph->sref;
			};

			dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT TblWdbeMModule.* FROM TblWdbeMUnit, TblWdbeMModule WHERE TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT)
						+ " AND TblWdbeMModule.hkUref = TblWdbeMUnit.ref AND TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND TblWdbeMUnit.refUref = " + to_string(ver->ref)
						+ " ORDER BY TblWdbeMModule.sref ASC", false, mdls);
			for (unsigned int j = 0; j < mdls.nodes.size(); j++) {
				mdl = mdls.nodes[j];
				hash += mdl->sref;
			};

			dbswdbe->tblwdbemcommand->loadRstBySQL("SELECT TblWdbeMCommand.* FROM TblWdbeMUnit, TblWdbeMCommand WHERE TblWdbeMCommand.refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::UNT)
						+ " AND TblWdbeMCommand.refUref = TblWdbeMUnit.ref AND TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND TblWdbeMUnit.refUref = " + to_string(ver->ref)
						+ " ORDER BY TblWdbeMCommand.sref ASC", false, cmds);
			dbswdbe->tblwdbemcommand->loadRstBySQL("SELECT TblWdbeMCommand.* FROM TblWdbeMUnit, TblWdbeMModule, TblWdbeMCommand WHERE TblWdbeMCommand.refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR)
						+ " AND TblWdbeMCommand.refUref = TblWdbeMModule.refWdbeMController AND TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT)
						+ " AND TblWdbeMModule.hkUref = TblWdbeMUnit.ref AND TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND TblWdbeMUnit.refUref = " + to_string(ver->ref)
						+ " ORDER BY TblWdbeMCommand.sref ASC", true, cmds);
			for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
				cmd = cmds.nodes[j];
				hash += cmd->sref;
			};

			dbswdbe->tblwdbemvector->loadRstBySQL("SELECT TblWdbeMVector.* FROM TblWdbeMUnit, TblWdbeMVector WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::UNT)
						+ " AND TblWdbeMVector.hkUref = TblWdbeMUnit.ref AND TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND TblWdbeMUnit.refUref = " + to_string(ver->ref)
						+ " ORDER BY TblWdbeMVector.sref ASC", false, vecs);
			dbswdbe->tblwdbemvector->loadRstBySQL("SELECT TblWdbeMVector.* FROM TblWdbeMUnit, TblWdbeMModule, TblWdbeMVector WHERE TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CTR)
						+ " AND TblWdbeMVector.hkUref = TblWdbeMModule.refWdbeMController AND TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT)
						+ " AND TblWdbeMModule.hkUref = TblWdbeMUnit.ref AND TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND TblWdbeMUnit.refUref = " + to_string(ver->ref)
						+ " ORDER BY TblWdbeMVector.sref ASC", true, vecs);
			for (unsigned int j = 0; j < vecs.nodes.size(); j++) {
				vec = vecs.nodes[j];
				hash += vec->sref;
			};

			dbswdbe->tblwdbemprocess->loadRstBySQL("SELECT TblWdbeMProcess.* FROM TblWdbeMUnit, TblWdbeMModule, TblWdbeMProcess WHERE TblWdbeMProcess.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMModule.hkIxVTbl = "
						+ to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = TblWdbeMUnit.ref AND TblWdbeMUnit.refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND TblWdbeMUnit.refUref = "
						+ to_string(ver->ref) + " ORDER BY TblWdbeMProcess.sref ASC", false, prcs);
			for (unsigned int j = 0; j < prcs.nodes.size(); j++) {
				prc = prcs.nodes[j];
				hash += prc->sref;
			};

			cout << "hash for build-ready version " << prj->Short << " " << to_string(ver->Major) << "." << to_string(ver->Minor) << "." << to_string(ver->Sub) << " is '" << hash << "'" << endl;
		};
	};

	unsigned char md[SHA256_DIGEST_LENGTH];
	SHA256_CTX context;

	char* base64 = NULL;
	unsigned int base64len;

	bool success;

	success = SHA256_Init(&context);

	if (success) success = SHA256_Update(&context, (const unsigned char*) hash.c_str(), hash.length());

	if (success) success = SHA256_Final(md, &context);

	if (success) {
		toBase64(md, SHA256_DIGEST_LENGTH, &base64, base64len);

		if (base64) {
			cout << "Base64-encoded SHA256 hash: " << string(base64, base64len) << endl;
			delete[] base64;
		};
	};

	// IP handleTest --- IEND
	return retval;
};

void RootWdbe::handleDpchAppLogin(
			DbsWdbe* dbswdbe
			, DpchAppLogin* dpchapplogin
			, const string ip
			, DpchEngWdbe** dpcheng
		) {
	ubigint refUsr;

	ubigint jrefSess;

	Feed feedFEnsSps("FeedFEnsSps");

	// verify password
	if (authenticate(dbswdbe, StrMod::lc(dpchapplogin->username), dpchapplogin->password, refUsr)) {
		if (!(dpchapplogin->m2mNotReg)) {
			if (xchg->stgwdbeappearance.suspsess && dpchapplogin->chksuspsess) {
				// look for suspended sessions
				for (auto it = sesss.begin(); it != sesss.end(); it++) {
					jrefSess = it->second->jref;

					if (xchg->getRefPreset(VecWdbeVPreset::PREWDBEOWNER, jrefSess) == refUsr) {
						if (xchg->getBoolvalPreset(VecWdbeVPreset::PREWDBESUSPSESS, jrefSess)) {
							xchg->addTxtvalPreset(VecWdbeVPreset::PREWDBEIP, jrefSess, ip);
							feedFEnsSps.appendIxSrefTitles(0, Scr::scramble(jrefSess), StubWdbe::getStubSesStd(dbswdbe, xchg->getRefPreset(VecWdbeVPreset::PREWDBESESS, jrefSess)));
						};
					};
				};
			};

			if (feedFEnsSps.size() == 0) {
				// start new session
				jrefSess = insertSubjob(sesss, new SessWdbe(xchg, dbswdbe, jref, refUsr, ip));

				if ((xchg->stgwdbeappearance.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (xchg->stgwdbeappearance.sesstterm - xchg->stgwdbeappearance.sesstwarn));

				xchg->appendToLogfile("session created for user '" + dpchapplogin->username + "' from IP " + ip);

				*dpcheng = new DpchEngWdbeConfirm(true, jrefSess, "");

			} else {
				// return suspended sessions
				*dpcheng = new DpchEngData(0, &feedFEnsSps, {DpchEngData::ALL});
			};

		};

	} else {
		xchg->appendToLogfile("login refused for user '" + dpchapplogin->username + "' from IP " + ip);

		*dpcheng = new DpchEngWdbeConfirm(false, 0, "");
	};
};

void RootWdbe::handleTimerWithSrefWarnterm(
			DbsWdbe* dbswdbe
		) {
	SessWdbe* sess = NULL;

	time_t tlast;
	time_t tnext = 0;

	time_t rawtime;
	time(&rawtime);

	bool term;

	if (xchg->stgwdbeappearance.sesstterm != 0) {
		for (auto it = sesss.begin(); it != sesss.end();) {
			sess = (SessWdbe*) it->second;

			term = false;

			tlast = xchg->getRefPreset(VecWdbeVPreset::PREWDBETLAST, sess->jref);

			if ((tlast + ((int) xchg->stgwdbeappearance.sesstterm)) <= rawtime) term = true;
			else if ((tlast + ((int) xchg->stgwdbeappearance.sesstterm) - ((int) xchg->stgwdbeappearance.sesstwarn)) <= rawtime) {
				sess->warnTerm(dbswdbe);
				if ((tnext == 0) || ((tlast + ((int) xchg->stgwdbeappearance.sesstterm)) < tnext)) tnext = tlast + ((int) xchg->stgwdbeappearance.sesstterm);
			} else if ((tnext == 0) || ((tlast + ((int) xchg->stgwdbeappearance.sesstterm) - ((int) xchg->stgwdbeappearance.sesstwarn)) < tnext)) tnext = tlast + xchg->stgwdbeappearance.sesstterm - xchg->stgwdbeappearance.sesstwarn;

			if (term) {
				sess->term(dbswdbe);
				it = sesss.erase(it);

				delete sess;

			} else it++;
		};
	};

	term = false;

	if (xchg->stgwdbeappearance.roottterm != 0) {
		tlast = xchg->getRefPreset(VecWdbeVPreset::PREWDBETLAST, jref);

		if ((tlast + ((int) xchg->stgwdbeappearance.roottterm)) <= rawtime) term = true;
		else if ((tnext == 0) || ((tlast + ((int) xchg->stgwdbeappearance.roottterm)) < tnext)) tnext = tlast + xchg->stgwdbeappearance.roottterm;
	};

	if (term) {
		cout << endl << "\tterminating due to inactivity" << endl;
		kill(getpid(), SIGTERM);
	} else if (tnext != 0) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (tnext - rawtime));
};

void RootWdbe::handleTimerWithSrefMonInSgeIdle(
			DbsWdbe* dbswdbe
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 240000000, true);
	changeStage(dbswdbe, VecVSge::IDLE); // IP handleTimerWithSrefMonInSgeIdle --- ILINE
};

void RootWdbe::handleCall(
			DbsWdbe* dbswdbe
			, Call* call
		) {
	if (call->ixVCall == VecWdbeVCall::CALLWDBELOGOUT) {
		call->abort = handleCallWdbeLogout(dbswdbe, call->jref, call->argInv.boolval);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBESUSPSESS) {
		call->abort = handleCallWdbeSuspsess(dbswdbe, call->jref);
	} else if (call->ixVCall == VecWdbeVCall::CALLWDBEREFPRESET) {
		call->abort = handleCallWdbeRefPreSet(dbswdbe, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool RootWdbe::handleCallWdbeLogout(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const bool boolvalInv
		) {
	bool retval = false;

	time_t rawtime;

	if (!boolvalInv) {
		eraseSubjobByJref(sesss, jrefTrig);

		if (xchg->stgwdbeappearance.roottterm) {
			time(&rawtime);
			xchg->addRefPreset(VecWdbeVPreset::PREWDBETLAST, jref, rawtime);
		};
	};

	return retval;
};

bool RootWdbe::handleCallWdbeSuspsess(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
		) {
	bool retval = false;

	xchg->addBoolvalPreset(VecWdbeVPreset::PREWDBESUSPSESS, jrefTrig, true);
	xchg->removeDcolsByJref(jrefTrig);

	return retval;
};

bool RootWdbe::handleCallWdbeRefPreSet(
			DbsWdbe* dbswdbe
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWdbeVPreset::PREWDBETLAST) {
		xchg->addRefPreset(ixInv, jref, refInv);
	};

	return retval;
};

void RootWdbe::changeStage(
			DbsWdbe* dbswdbe
			, uint _ixVSge
			, DpchEngWdbe** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswdbe); break;
				case VecVSge::SYNC: leaveSgeSync(dbswdbe); break;
			};

			setStage(dbswdbe, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswdbe, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswdbe, reenter); break;
			case VecVSge::SYNC: _ixVSge = enterSgeSync(dbswdbe, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string RootWdbe::getSquawk(
			DbsWdbe* dbswdbe
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::SYNC) ) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::SYNC) retval = "synchronizing projects and versions with licensing server";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint RootWdbe::enterSgeIdle(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 240000000, true);

	// IP enterSgeIdle --- IBEGIN

	// notify license server of whether there are active sessions (4 min interval)
	license->heartbeat(!sesss.empty());

	// IP enterSgeIdle --- IEND

	return retval;
};

void RootWdbe::leaveSgeIdle(
			DbsWdbe* dbswdbe
		) {
	invalidateWakeups();
	// IP leaveSgeIdle --- INSERT
};

uint RootWdbe::enterSgeSync(
			DbsWdbe* dbswdbe
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSync --- INSERT

	return retval;
};

void RootWdbe::leaveSgeSync(
			DbsWdbe* dbswdbe
		) {
	// IP leaveSgeSync --- INSERT
};
