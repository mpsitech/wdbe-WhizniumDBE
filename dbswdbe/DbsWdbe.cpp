/**
	* \file DbsWdbe.cpp
	* C++ wrapper for database DbsWdbe (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "DbsWdbe.h"

#include "DbsWdbe_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class DbsWdbe
 ******************************************************************************/

DbsWdbe::DbsWdbe() {
	initdone = false;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	dbsMy = NULL;
#endif
#if defined(SBECORE_PG)
	dbsPg = NULL;
#endif
};

DbsWdbe::~DbsWdbe() {
	if (initdone) term();
};

void DbsWdbe::init(
			const uint _ixDbsVDbstype
			, const string& _dbspath
			, const string& _dbsname
			, const string& _ip
			, const uint _port
			, const string& _username
			, const string& _password
		) {
	ixDbsVDbstype = _ixDbsVDbstype;
	dbspath = _dbspath;
	dbsname = _dbsname;
	username = _username;
	password = _password;
	ip = _ip;
	port = _port;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) {
		initMy();
		initdone = true;
	};
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		initPg();
		initdone = true;
	};
#endif
};

void DbsWdbe::term() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) {
		termMy();
		initdone = false;
	};
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		termPg();
		initdone = false;
	};
#endif
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
void DbsWdbe::initMy() {
	// connect to MySQL database
	dbsMy = mysql_init(NULL);

	mysql_options(dbsMy, MYSQL_READ_DEFAULT_GROUP, "MyccDatabase");
	if (!mysql_real_connect(dbsMy, ip.c_str(), username.c_str(), password.c_str(), dbsname.c_str(), port, NULL, 0)) {
		string dbms = "DbsWdbe::initMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_CONN, {{"dbms",dbms}});
	};

	executeQuery("SET SESSION wait_timeout = 31536000");

	tblwdbeaccrmuseruniversal = new MyTblWdbeAccRMUserUniversal();
	((MyTblWdbeAccRMUserUniversal*) tblwdbeaccrmuseruniversal)->init(dbsMy);
	tblwdbeamcommandinvpar = new MyTblWdbeAMCommandInvpar();
	((MyTblWdbeAMCommandInvpar*) tblwdbeamcommandinvpar)->init(dbsMy);
	tblwdbeamcommandretpar = new MyTblWdbeAMCommandRetpar();
	((MyTblWdbeAMCommandRetpar*) tblwdbeamcommandretpar)->init(dbsMy);
	tblwdbeamcoreversionip = new MyTblWdbeAMCoreversionIp();
	((MyTblWdbeAMCoreversionIp*) tblwdbeamcoreversionip)->init(dbsMy);
	tblwdbeamcoreversionplh = new MyTblWdbeAMCoreversionPlh();
	((MyTblWdbeAMCoreversionPlh*) tblwdbeamcoreversionplh)->init(dbsMy);
	tblwdbeamerrorpar = new MyTblWdbeAMErrorPar();
	((MyTblWdbeAMErrorPar*) tblwdbeamerrorpar)->init(dbsMy);
	tblwdbeamfsmstatestep = new MyTblWdbeAMFsmstateStep();
	((MyTblWdbeAMFsmstateStep*) tblwdbeamfsmstatestep)->init(dbsMy);
	tblwdbeamlibrarymakefile = new MyTblWdbeAMLibraryMakefile();
	((MyTblWdbeAMLibraryMakefile*) tblwdbeamlibrarymakefile)->init(dbsMy);
	tblwdbeammachinemakefile = new MyTblWdbeAMMachineMakefile();
	((MyTblWdbeAMMachineMakefile*) tblwdbeammachinemakefile)->init(dbsMy);
	tblwdbeammachinepar = new MyTblWdbeAMMachinePar();
	((MyTblWdbeAMMachinePar*) tblwdbeammachinepar)->init(dbsMy);
	tblwdbeammodulepar = new MyTblWdbeAMModulePar();
	((MyTblWdbeAMModulePar*) tblwdbeammodulepar)->init(dbsMy);
	tblwdbeamperipheralpar = new MyTblWdbeAMPeripheralPar();
	((MyTblWdbeAMPeripheralPar*) tblwdbeamperipheralpar)->init(dbsMy);
	tblwdbeampersondetail = new MyTblWdbeAMPersonDetail();
	((MyTblWdbeAMPersonDetail*) tblwdbeampersondetail)->init(dbsMy);
	tblwdbeampinpar = new MyTblWdbeAMPinPar();
	((MyTblWdbeAMPinPar*) tblwdbeampinpar)->init(dbsMy);
	tblwdbeamuseraccess = new MyTblWdbeAMUserAccess();
	((MyTblWdbeAMUserAccess*) tblwdbeamuseraccess)->init(dbsMy);
	tblwdbeamusergroupaccess = new MyTblWdbeAMUsergroupAccess();
	((MyTblWdbeAMUsergroupAccess*) tblwdbeamusergroupaccess)->init(dbsMy);
	tblwdbeavcontrolpar = new MyTblWdbeAVControlPar();
	((MyTblWdbeAVControlPar*) tblwdbeavcontrolpar)->init(dbsMy);
	tblwdbeavkeylistkey = new MyTblWdbeAVKeylistKey();
	((MyTblWdbeAVKeylistKey*) tblwdbeavkeylistkey)->init(dbsMy);
	tblwdbeavvaluelistval = new MyTblWdbeAVValuelistVal();
	((MyTblWdbeAVValuelistVal*) tblwdbeavvaluelistval)->init(dbsMy);
	tblwdbecfile = new MyTblWdbeCFile();
	((MyTblWdbeCFile*) tblwdbecfile)->init(dbsMy);
	tblwdbecfsmstate = new MyTblWdbeCFsmstate();
	((MyTblWdbeCFsmstate*) tblwdbecfsmstate)->init(dbsMy);
	tblwdbecgeneric = new MyTblWdbeCGeneric();
	((MyTblWdbeCGeneric*) tblwdbecgeneric)->init(dbsMy);
	tblwdbecpin = new MyTblWdbeCPin();
	((MyTblWdbeCPin*) tblwdbecpin)->init(dbsMy);
	tblwdbecport = new MyTblWdbeCPort();
	((MyTblWdbeCPort*) tblwdbecport)->init(dbsMy);
	tblwdbecsegment = new MyTblWdbeCSegment();
	((MyTblWdbeCSegment*) tblwdbecsegment)->init(dbsMy);
	tblwdbecsignal = new MyTblWdbeCSignal();
	((MyTblWdbeCSignal*) tblwdbecsignal)->init(dbsMy);
	tblwdbecvariable = new MyTblWdbeCVariable();
	((MyTblWdbeCVariable*) tblwdbecvariable)->init(dbsMy);
	tblwdbehistrmuseruniversal = new MyTblWdbeHistRMUserUniversal();
	((MyTblWdbeHistRMUserUniversal*) tblwdbehistrmuseruniversal)->init(dbsMy);
	tblwdbejavkeylistkey = new MyTblWdbeJAVKeylistKey();
	((MyTblWdbeJAVKeylistKey*) tblwdbejavkeylistkey)->init(dbsMy);
	tblwdbejmcoreversionstate = new MyTblWdbeJMCoreversionState();
	((MyTblWdbeJMCoreversionState*) tblwdbejmcoreversionstate)->init(dbsMy);
	tblwdbejmpersonlastname = new MyTblWdbeJMPersonLastname();
	((MyTblWdbeJMPersonLastname*) tblwdbejmpersonlastname)->init(dbsMy);
	tblwdbejmpinsref = new MyTblWdbeJMPinSref();
	((MyTblWdbeJMPinSref*) tblwdbejmpinsref)->init(dbsMy);
	tblwdbejmuserstate = new MyTblWdbeJMUserState();
	((MyTblWdbeJMUserState*) tblwdbejmuserstate)->init(dbsMy);
	tblwdbejmversionstate = new MyTblWdbeJMVersionState();
	((MyTblWdbeJMVersionState*) tblwdbejmversionstate)->init(dbsMy);
	tblwdbembank = new MyTblWdbeMBank();
	((MyTblWdbeMBank*) tblwdbembank)->init(dbsMy);
	tblwdbemcommand = new MyTblWdbeMCommand();
	((MyTblWdbeMCommand*) tblwdbemcommand)->init(dbsMy);
	tblwdbemcontroller = new MyTblWdbeMController();
	((MyTblWdbeMController*) tblwdbemcontroller)->init(dbsMy);
	tblwdbemcoreproject = new MyTblWdbeMCoreproject();
	((MyTblWdbeMCoreproject*) tblwdbemcoreproject)->init(dbsMy);
	tblwdbemcoreversion = new MyTblWdbeMCoreversion();
	((MyTblWdbeMCoreversion*) tblwdbemcoreversion)->init(dbsMy);
	tblwdbemerror = new MyTblWdbeMError();
	((MyTblWdbeMError*) tblwdbemerror)->init(dbsMy);
	tblwdbemfamily = new MyTblWdbeMFamily();
	((MyTblWdbeMFamily*) tblwdbemfamily)->init(dbsMy);
	tblwdbemfile = new MyTblWdbeMFile();
	((MyTblWdbeMFile*) tblwdbemfile)->init(dbsMy);
	tblwdbemfsm = new MyTblWdbeMFsm();
	((MyTblWdbeMFsm*) tblwdbemfsm)->init(dbsMy);
	tblwdbemfsmstate = new MyTblWdbeMFsmstate();
	((MyTblWdbeMFsmstate*) tblwdbemfsmstate)->init(dbsMy);
	tblwdbemgeneric = new MyTblWdbeMGeneric();
	((MyTblWdbeMGeneric*) tblwdbemgeneric)->init(dbsMy);
	tblwdbemimbuf = new MyTblWdbeMImbuf();
	((MyTblWdbeMImbuf*) tblwdbemimbuf)->init(dbsMy);
	tblwdbeminterrupt = new MyTblWdbeMInterrupt();
	((MyTblWdbeMInterrupt*) tblwdbeminterrupt)->init(dbsMy);
	tblwdbemlibrary = new MyTblWdbeMLibrary();
	((MyTblWdbeMLibrary*) tblwdbemlibrary)->init(dbsMy);
	tblwdbemmachine = new MyTblWdbeMMachine();
	((MyTblWdbeMMachine*) tblwdbemmachine)->init(dbsMy);
	tblwdbemmodule = new MyTblWdbeMModule();
	((MyTblWdbeMModule*) tblwdbemmodule)->init(dbsMy);
	tblwdbemperipheral = new MyTblWdbeMPeripheral();
	((MyTblWdbeMPeripheral*) tblwdbemperipheral)->init(dbsMy);
	tblwdbemperson = new MyTblWdbeMPerson();
	((MyTblWdbeMPerson*) tblwdbemperson)->init(dbsMy);
	tblwdbempin = new MyTblWdbeMPin();
	((MyTblWdbeMPin*) tblwdbempin)->init(dbsMy);
	tblwdbempipeline = new MyTblWdbeMPipeline();
	((MyTblWdbeMPipeline*) tblwdbempipeline)->init(dbsMy);
	tblwdbemport = new MyTblWdbeMPort();
	((MyTblWdbeMPort*) tblwdbemport)->init(dbsMy);
	tblwdbemprocess = new MyTblWdbeMProcess();
	((MyTblWdbeMProcess*) tblwdbemprocess)->init(dbsMy);
	tblwdbemproject = new MyTblWdbeMProject();
	((MyTblWdbeMProject*) tblwdbemproject)->init(dbsMy);
	tblwdbemrelease = new MyTblWdbeMRelease();
	((MyTblWdbeMRelease*) tblwdbemrelease)->init(dbsMy);
	tblwdbemsegment = new MyTblWdbeMSegment();
	((MyTblWdbeMSegment*) tblwdbemsegment)->init(dbsMy);
	tblwdbemsensitivity = new MyTblWdbeMSensitivity();
	((MyTblWdbeMSensitivity*) tblwdbemsensitivity)->init(dbsMy);
	tblwdbemsession = new MyTblWdbeMSession();
	((MyTblWdbeMSession*) tblwdbemsession)->init(dbsMy);
	tblwdbemsignal = new MyTblWdbeMSignal();
	((MyTblWdbeMSignal*) tblwdbemsignal)->init(dbsMy);
	tblwdbemsystem = new MyTblWdbeMSystem();
	((MyTblWdbeMSystem*) tblwdbemsystem)->init(dbsMy);
	tblwdbemtarget = new MyTblWdbeMTarget();
	((MyTblWdbeMTarget*) tblwdbemtarget)->init(dbsMy);
	tblwdbemunit = new MyTblWdbeMUnit();
	((MyTblWdbeMUnit*) tblwdbemunit)->init(dbsMy);
	tblwdbemuser = new MyTblWdbeMUser();
	((MyTblWdbeMUser*) tblwdbemuser)->init(dbsMy);
	tblwdbemusergroup = new MyTblWdbeMUsergroup();
	((MyTblWdbeMUsergroup*) tblwdbemusergroup)->init(dbsMy);
	tblwdbemvariable = new MyTblWdbeMVariable();
	((MyTblWdbeMVariable*) tblwdbemvariable)->init(dbsMy);
	tblwdbemvector = new MyTblWdbeMVector();
	((MyTblWdbeMVector*) tblwdbemvector)->init(dbsMy);
	tblwdbemvectoritem = new MyTblWdbeMVectoritem();
	((MyTblWdbeMVectoritem*) tblwdbemvectoritem)->init(dbsMy);
	tblwdbemversion = new MyTblWdbeMVersion();
	((MyTblWdbeMVersion*) tblwdbemversion)->init(dbsMy);
	tblwdbermcommandmcontroller = new MyTblWdbeRMCommandMController();
	((MyTblWdbeRMCommandMController*) tblwdbermcommandmcontroller)->init(dbsMy);
	tblwdbermcoreprojectmperson = new MyTblWdbeRMCoreprojectMPerson();
	((MyTblWdbeRMCoreprojectMPerson*) tblwdbermcoreprojectmperson)->init(dbsMy);
	tblwdbermlibrarymversion = new MyTblWdbeRMLibraryMVersion();
	((MyTblWdbeRMLibraryMVersion*) tblwdbermlibrarymversion)->init(dbsMy);
	tblwdbermmodulemmodule = new MyTblWdbeRMModuleMModule();
	((MyTblWdbeRMModuleMModule*) tblwdbermmodulemmodule)->init(dbsMy);
	tblwdbermmodulemperipheral = new MyTblWdbeRMModuleMPeripheral();
	((MyTblWdbeRMModuleMPeripheral*) tblwdbermmodulemperipheral)->init(dbsMy);
	tblwdbermpersonmproject = new MyTblWdbeRMPersonMProject();
	((MyTblWdbeRMPersonMProject*) tblwdbermpersonmproject)->init(dbsMy);
	tblwdbermusergroupuniversal = new MyTblWdbeRMUsergroupUniversal();
	((MyTblWdbeRMUsergroupUniversal*) tblwdbermusergroupuniversal)->init(dbsMy);
	tblwdbermusermusergroup = new MyTblWdbeRMUserMUsergroup();
	((MyTblWdbeRMUserMUsergroup*) tblwdbermusermusergroup)->init(dbsMy);

	tblwdbeqbnk1npin = new MyTblWdbeQBnk1NPin();
	((MyTblWdbeQBnk1NPin*) tblwdbeqbnk1npin)->init(dbsMy);
	tblwdbeqbnklist = new MyTblWdbeQBnkList();
	((MyTblWdbeQBnkList*) tblwdbeqbnklist)->init(dbsMy);
	tblwdbeqcmdainvpar = new MyTblWdbeQCmdAInvpar();
	((MyTblWdbeQCmdAInvpar*) tblwdbeqcmdainvpar)->init(dbsMy);
	tblwdbeqcmdaretpar = new MyTblWdbeQCmdARetpar();
	((MyTblWdbeQCmdARetpar*) tblwdbeqcmdaretpar)->init(dbsMy);
	tblwdbeqcmdlist = new MyTblWdbeQCmdList();
	((MyTblWdbeQCmdList*) tblwdbeqcmdlist)->init(dbsMy);
	tblwdbeqcmdmncontroller = new MyTblWdbeQCmdMNController();
	((MyTblWdbeQCmdMNController*) tblwdbeqcmdmncontroller)->init(dbsMy);
	tblwdbeqcpr1ncoreversion = new MyTblWdbeQCpr1NCoreversion();
	((MyTblWdbeQCpr1NCoreversion*) tblwdbeqcpr1ncoreversion)->init(dbsMy);
	tblwdbeqcprlist = new MyTblWdbeQCprList();
	((MyTblWdbeQCprList*) tblwdbeqcprlist)->init(dbsMy);
	tblwdbeqcprmnperson = new MyTblWdbeQCprMNPerson();
	((MyTblWdbeQCprMNPerson*) tblwdbeqcprmnperson)->init(dbsMy);
	tblwdbeqcvraip = new MyTblWdbeQCvrAIp();
	((MyTblWdbeQCvrAIp*) tblwdbeqcvraip)->init(dbsMy);
	tblwdbeqcvraplh = new MyTblWdbeQCvrAPlh();
	((MyTblWdbeQCvrAPlh*) tblwdbeqcvraplh)->init(dbsMy);
	tblwdbeqcvrbcv1ncoreversion = new MyTblWdbeQCvrBcv1NCoreversion();
	((MyTblWdbeQCvrBcv1NCoreversion*) tblwdbeqcvrbcv1ncoreversion)->init(dbsMy);
	tblwdbeqcvrhk1nmodule = new MyTblWdbeQCvrHk1NModule();
	((MyTblWdbeQCvrHk1NModule*) tblwdbeqcvrhk1nmodule)->init(dbsMy);
	tblwdbeqcvrlist = new MyTblWdbeQCvrList();
	((MyTblWdbeQCvrList*) tblwdbeqcvrlist)->init(dbsMy);
	tblwdbeqerrapar = new MyTblWdbeQErrAPar();
	((MyTblWdbeQErrAPar*) tblwdbeqerrapar)->init(dbsMy);
	tblwdbeqerrlist = new MyTblWdbeQErrList();
	((MyTblWdbeQErrList*) tblwdbeqerrlist)->init(dbsMy);
	tblwdbeqfam1nunit = new MyTblWdbeQFam1NUnit();
	((MyTblWdbeQFam1NUnit*) tblwdbeqfam1nunit)->init(dbsMy);
	tblwdbeqfamlist = new MyTblWdbeQFamList();
	((MyTblWdbeQFamList*) tblwdbeqfamlist)->init(dbsMy);
	tblwdbeqfillist = new MyTblWdbeQFilList();
	((MyTblWdbeQFilList*) tblwdbeqfillist)->init(dbsMy);
	tblwdbeqfstastep = new MyTblWdbeQFstAStep();
	((MyTblWdbeQFstAStep*) tblwdbeqfstastep)->init(dbsMy);
	tblwdbeqfstlist = new MyTblWdbeQFstList();
	((MyTblWdbeQFstList*) tblwdbeqfstlist)->init(dbsMy);
	tblwdbeqgenlist = new MyTblWdbeQGenList();
	((MyTblWdbeQGenList*) tblwdbeqgenlist)->init(dbsMy);
	tblwdbeqintlist = new MyTblWdbeQIntList();
	((MyTblWdbeQIntList*) tblwdbeqintlist)->init(dbsMy);
	tblwdbeqintsrc1nsensitivity = new MyTblWdbeQIntSrc1NSensitivity();
	((MyTblWdbeQIntSrc1NSensitivity*) tblwdbeqintsrc1nsensitivity)->init(dbsMy);
	tblwdbeqlibamakefile = new MyTblWdbeQLibAMakefile();
	((MyTblWdbeQLibAMakefile*) tblwdbeqlibamakefile)->init(dbsMy);
	tblwdbeqliblist = new MyTblWdbeQLibList();
	((MyTblWdbeQLibList*) tblwdbeqliblist)->init(dbsMy);
	tblwdbeqlibmnversion = new MyTblWdbeQLibMNVersion();
	((MyTblWdbeQLibMNVersion*) tblwdbeqlibmnversion)->init(dbsMy);
	tblwdbeqmch1nrelease = new MyTblWdbeQMch1NRelease();
	((MyTblWdbeQMch1NRelease*) tblwdbeqmch1nrelease)->init(dbsMy);
	tblwdbeqmchamakefile = new MyTblWdbeQMchAMakefile();
	((MyTblWdbeQMchAMakefile*) tblwdbeqmchamakefile)->init(dbsMy);
	tblwdbeqmchapar = new MyTblWdbeQMchAPar();
	((MyTblWdbeQMchAPar*) tblwdbeqmchapar)->init(dbsMy);
	tblwdbeqmchlist = new MyTblWdbeQMchList();
	((MyTblWdbeQMchList*) tblwdbeqmchlist)->init(dbsMy);
	tblwdbeqmchsup1nmachine = new MyTblWdbeQMchSup1NMachine();
	((MyTblWdbeQMchSup1NMachine*) tblwdbeqmchsup1nmachine)->init(dbsMy);
	tblwdbeqmod1nprocess = new MyTblWdbeQMod1NProcess();
	((MyTblWdbeQMod1NProcess*) tblwdbeqmod1nprocess)->init(dbsMy);
	tblwdbeqmodapar = new MyTblWdbeQModAPar();
	((MyTblWdbeQModAPar*) tblwdbeqmodapar)->init(dbsMy);
	tblwdbeqmodcormnmodule = new MyTblWdbeQModCorMNModule();
	((MyTblWdbeQModCorMNModule*) tblwdbeqmodcormnmodule)->init(dbsMy);
	tblwdbeqmodctdmnmodule = new MyTblWdbeQModCtdMNModule();
	((MyTblWdbeQModCtdMNModule*) tblwdbeqmodctdmnmodule)->init(dbsMy);
	tblwdbeqmodctrhk1nvector = new MyTblWdbeQModCtrHk1NVector();
	((MyTblWdbeQModCtrHk1NVector*) tblwdbeqmodctrhk1nvector)->init(dbsMy);
	tblwdbeqmodctrmncommand = new MyTblWdbeQModCtrMNCommand();
	((MyTblWdbeQModCtrMNCommand*) tblwdbeqmodctrmncommand)->init(dbsMy);
	tblwdbeqmodctrref1ncommand = new MyTblWdbeQModCtrRef1NCommand();
	((MyTblWdbeQModCtrRef1NCommand*) tblwdbeqmodctrref1ncommand)->init(dbsMy);
	tblwdbeqmodctrref1nerror = new MyTblWdbeQModCtrRef1NError();
	((MyTblWdbeQModCtrRef1NError*) tblwdbeqmodctrref1nerror)->init(dbsMy);
	tblwdbeqmodhsm1npipeline = new MyTblWdbeQModHsm1NPipeline();
	((MyTblWdbeQModHsm1NPipeline*) tblwdbeqmodhsm1npipeline)->init(dbsMy);
	tblwdbeqmodkhdltype = new MyTblWdbeQModKHdltype();
	((MyTblWdbeQModKHdltype*) tblwdbeqmodkhdltype)->init(dbsMy);
	tblwdbeqmodlist = new MyTblWdbeQModList();
	((MyTblWdbeQModList*) tblwdbeqmodlist)->init(dbsMy);
	tblwdbeqmodmdl1ngeneric = new MyTblWdbeQModMdl1NGeneric();
	((MyTblWdbeQModMdl1NGeneric*) tblwdbeqmodmdl1ngeneric)->init(dbsMy);
	tblwdbeqmodmdl1nport = new MyTblWdbeQModMdl1NPort();
	((MyTblWdbeQModMdl1NPort*) tblwdbeqmodmdl1nport)->init(dbsMy);
	tblwdbeqmodmge1nsignal = new MyTblWdbeQModMge1NSignal();
	((MyTblWdbeQModMge1NSignal*) tblwdbeqmodmge1nsignal)->init(dbsMy);
	tblwdbeqmodmnperipheral = new MyTblWdbeQModMNPeripheral();
	((MyTblWdbeQModMNPeripheral*) tblwdbeqmodmnperipheral)->init(dbsMy);
	tblwdbeqmodref1nsensitivity = new MyTblWdbeQModRef1NSensitivity();
	((MyTblWdbeQModRef1NSensitivity*) tblwdbeqmodref1nsensitivity)->init(dbsMy);
	tblwdbeqmodref1nsignal = new MyTblWdbeQModRef1NSignal();
	((MyTblWdbeQModRef1NSignal*) tblwdbeqmodref1nsignal)->init(dbsMy);
	tblwdbeqmodref1nvariable = new MyTblWdbeQModRef1NVariable();
	((MyTblWdbeQModRef1NVariable*) tblwdbeqmodref1nvariable)->init(dbsMy);
	tblwdbeqmodsup1nmodule = new MyTblWdbeQModSup1NModule();
	((MyTblWdbeQModSup1NModule*) tblwdbeqmodsup1nmodule)->init(dbsMy);
	tblwdbeqmtpapar = new MyTblWdbeQMtpAPar();
	((MyTblWdbeQMtpAPar*) tblwdbeqmtpapar)->init(dbsMy);
	tblwdbeqmtphsm1npipeline = new MyTblWdbeQMtpHsm1NPipeline();
	((MyTblWdbeQMtpHsm1NPipeline*) tblwdbeqmtphsm1npipeline)->init(dbsMy);
	tblwdbeqmtpkhdltype = new MyTblWdbeQMtpKHdltype();
	((MyTblWdbeQMtpKHdltype*) tblwdbeqmtpkhdltype)->init(dbsMy);
	tblwdbeqmtpkparkey = new MyTblWdbeQMtpKParKey();
	((MyTblWdbeQMtpKParKey*) tblwdbeqmtpkparkey)->init(dbsMy);
	tblwdbeqmtplist = new MyTblWdbeQMtpList();
	((MyTblWdbeQMtpList*) tblwdbeqmtplist)->init(dbsMy);
	tblwdbeqmtpmdl1ngeneric = new MyTblWdbeQMtpMdl1NGeneric();
	((MyTblWdbeQMtpMdl1NGeneric*) tblwdbeqmtpmdl1ngeneric)->init(dbsMy);
	tblwdbeqmtpmdl1nport = new MyTblWdbeQMtpMdl1NPort();
	((MyTblWdbeQMtpMdl1NPort*) tblwdbeqmtpmdl1nport)->init(dbsMy);
	tblwdbeqmtpmge1nsignal = new MyTblWdbeQMtpMge1NSignal();
	((MyTblWdbeQMtpMge1NSignal*) tblwdbeqmtpmge1nsignal)->init(dbsMy);
	tblwdbeqmtpref1nfile = new MyTblWdbeQMtpRef1NFile();
	((MyTblWdbeQMtpRef1NFile*) tblwdbeqmtpref1nfile)->init(dbsMy);
	tblwdbeqmtpref1nsensitivity = new MyTblWdbeQMtpRef1NSensitivity();
	((MyTblWdbeQMtpRef1NSensitivity*) tblwdbeqmtpref1nsensitivity)->init(dbsMy);
	tblwdbeqmtpref1nvariable = new MyTblWdbeQMtpRef1NVariable();
	((MyTblWdbeQMtpRef1NVariable*) tblwdbeqmtpref1nvariable)->init(dbsMy);
	tblwdbeqmtpsup1nmodule = new MyTblWdbeQMtpSup1NModule();
	((MyTblWdbeQMtpSup1NModule*) tblwdbeqmtpsup1nmodule)->init(dbsMy);
	tblwdbeqmtptpl1nmodule = new MyTblWdbeQMtpTpl1NModule();
	((MyTblWdbeQMtpTpl1NModule*) tblwdbeqmtptpl1nmodule)->init(dbsMy);
	tblwdbeqpinapar = new MyTblWdbeQPinAPar();
	((MyTblWdbeQPinAPar*) tblwdbeqpinapar)->init(dbsMy);
	tblwdbeqpinlist = new MyTblWdbeQPinList();
	((MyTblWdbeQPinList*) tblwdbeqpinlist)->init(dbsMy);
	tblwdbeqpphapar = new MyTblWdbeQPphAPar();
	((MyTblWdbeQPphAPar*) tblwdbeqpphapar)->init(dbsMy);
	tblwdbeqpphlist = new MyTblWdbeQPphList();
	((MyTblWdbeQPphList*) tblwdbeqpphlist)->init(dbsMy);
	tblwdbeqpphmnmodule = new MyTblWdbeQPphMNModule();
	((MyTblWdbeQPphMNModule*) tblwdbeqpphmnmodule)->init(dbsMy);
	tblwdbeqppllist = new MyTblWdbeQPplList();
	((MyTblWdbeQPplList*) tblwdbeqppllist)->init(dbsMy);
	tblwdbeqpplppl1nsegment = new MyTblWdbeQPplPpl1NSegment();
	((MyTblWdbeQPplPpl1NSegment*) tblwdbeqpplppl1nsegment)->init(dbsMy);
	tblwdbeqprcfsmfsm1nfsmstate = new MyTblWdbeQPrcFsmFsm1NFsmstate();
	((MyTblWdbeQPrcFsmFsm1NFsmstate*) tblwdbeqprcfsmfsm1nfsmstate)->init(dbsMy);
	tblwdbeqprckhdltype = new MyTblWdbeQPrcKHdltype();
	((MyTblWdbeQPrcKHdltype*) tblwdbeqprckhdltype)->init(dbsMy);
	tblwdbeqprclist = new MyTblWdbeQPrcList();
	((MyTblWdbeQPrcList*) tblwdbeqprclist)->init(dbsMy);
	tblwdbeqprcmge1nsignal = new MyTblWdbeQPrcMge1NSignal();
	((MyTblWdbeQPrcMge1NSignal*) tblwdbeqprcmge1nsignal)->init(dbsMy);
	tblwdbeqprcref1nsensitivity = new MyTblWdbeQPrcRef1NSensitivity();
	((MyTblWdbeQPrcRef1NSensitivity*) tblwdbeqprcref1nsensitivity)->init(dbsMy);
	tblwdbeqprcref1nvariable = new MyTblWdbeQPrcRef1NVariable();
	((MyTblWdbeQPrcRef1NVariable*) tblwdbeqprcref1nvariable)->init(dbsMy);
	tblwdbeqpreselect = new MyTblWdbeQPreselect();
	((MyTblWdbeQPreselect*) tblwdbeqpreselect)->init(dbsMy);
	tblwdbeqprjlist = new MyTblWdbeQPrjList();
	((MyTblWdbeQPrjList*) tblwdbeqprjlist)->init(dbsMy);
	tblwdbeqprjmnperson = new MyTblWdbeQPrjMNPerson();
	((MyTblWdbeQPrjMNPerson*) tblwdbeqprjmnperson)->init(dbsMy);
	tblwdbeqprjprj1nversion = new MyTblWdbeQPrjPrj1NVersion();
	((MyTblWdbeQPrjPrj1NVersion*) tblwdbeqprjprj1nversion)->init(dbsMy);
	tblwdbeqprsadetail = new MyTblWdbeQPrsADetail();
	((MyTblWdbeQPrsADetail*) tblwdbeqprsadetail)->init(dbsMy);
	tblwdbeqprslist = new MyTblWdbeQPrsList();
	((MyTblWdbeQPrsList*) tblwdbeqprslist)->init(dbsMy);
	tblwdbeqprsmncoreproject = new MyTblWdbeQPrsMNCoreproject();
	((MyTblWdbeQPrsMNCoreproject*) tblwdbeqprsmncoreproject)->init(dbsMy);
	tblwdbeqprsmnproject = new MyTblWdbeQPrsMNProject();
	((MyTblWdbeQPrsMNProject*) tblwdbeqprsmnproject)->init(dbsMy);
	tblwdbeqprtlist = new MyTblWdbeQPrtList();
	((MyTblWdbeQPrtList*) tblwdbeqprtlist)->init(dbsMy);
	tblwdbeqprtsrc1nsensitivity = new MyTblWdbeQPrtSrc1NSensitivity();
	((MyTblWdbeQPrtSrc1NSensitivity*) tblwdbeqprtsrc1nsensitivity)->init(dbsMy);
	tblwdbeqrlslist = new MyTblWdbeQRlsList();
	((MyTblWdbeQRlsList*) tblwdbeqrlslist)->init(dbsMy);
	tblwdbeqseglist = new MyTblWdbeQSegList();
	((MyTblWdbeQSegList*) tblwdbeqseglist)->init(dbsMy);
	tblwdbeqsegsup1nsegment = new MyTblWdbeQSegSup1NSegment();
	((MyTblWdbeQSegSup1NSegment*) tblwdbeqsegsup1nsegment)->init(dbsMy);
	tblwdbeqselect = new MyTblWdbeQSelect();
	((MyTblWdbeQSelect*) tblwdbeqselect)->init(dbsMy);
	tblwdbeqsiglist = new MyTblWdbeQSigList();
	((MyTblWdbeQSigList*) tblwdbeqsiglist)->init(dbsMy);
	tblwdbeqsigsrc1nsensitivity = new MyTblWdbeQSigSrc1NSensitivity();
	((MyTblWdbeQSigSrc1NSensitivity*) tblwdbeqsigsrc1nsensitivity)->init(dbsMy);
	tblwdbeqsil1nbank = new MyTblWdbeQSil1NBank();
	((MyTblWdbeQSil1NBank*) tblwdbeqsil1nbank)->init(dbsMy);
	tblwdbeqsil1ninterrupt = new MyTblWdbeQSil1NInterrupt();
	((MyTblWdbeQSil1NInterrupt*) tblwdbeqsil1ninterrupt)->init(dbsMy);
	tblwdbeqsil1nperipheral = new MyTblWdbeQSil1NPeripheral();
	((MyTblWdbeQSil1NPeripheral*) tblwdbeqsil1nperipheral)->init(dbsMy);
	tblwdbeqsil1ntarget = new MyTblWdbeQSil1NTarget();
	((MyTblWdbeQSil1NTarget*) tblwdbeqsil1ntarget)->init(dbsMy);
	tblwdbeqsilfwd1ncontroller = new MyTblWdbeQSilFwd1NController();
	((MyTblWdbeQSilFwd1NController*) tblwdbeqsilfwd1ncontroller)->init(dbsMy);
	tblwdbeqsilhk1nmodule = new MyTblWdbeQSilHk1NModule();
	((MyTblWdbeQSilHk1NModule*) tblwdbeqsilhk1nmodule)->init(dbsMy);
	tblwdbeqsilhk1nvector = new MyTblWdbeQSilHk1NVector();
	((MyTblWdbeQSilHk1NVector*) tblwdbeqsilhk1nvector)->init(dbsMy);
	tblwdbeqsillist = new MyTblWdbeQSilList();
	((MyTblWdbeQSilList*) tblwdbeqsillist)->init(dbsMy);
	tblwdbeqsilref1ncommand = new MyTblWdbeQSilRef1NCommand();
	((MyTblWdbeQSilRef1NCommand*) tblwdbeqsilref1ncommand)->init(dbsMy);
	tblwdbeqsilref1nerror = new MyTblWdbeQSilRef1NError();
	((MyTblWdbeQSilRef1NError*) tblwdbeqsilref1nerror)->init(dbsMy);
	tblwdbeqsilref1nsignal = new MyTblWdbeQSilRef1NSignal();
	((MyTblWdbeQSilRef1NSignal*) tblwdbeqsilref1nsignal)->init(dbsMy);
	tblwdbeqsilsil1nunit = new MyTblWdbeQSilSil1NUnit();
	((MyTblWdbeQSilSil1NUnit*) tblwdbeqsilsil1nunit)->init(dbsMy);
	tblwdbeqsnslist = new MyTblWdbeQSnsList();
	((MyTblWdbeQSnsList*) tblwdbeqsnslist)->init(dbsMy);
	tblwdbeqsyshk1nvector = new MyTblWdbeQSysHk1NVector();
	((MyTblWdbeQSysHk1NVector*) tblwdbeqsyshk1nvector)->init(dbsMy);
	tblwdbeqsyslist = new MyTblWdbeQSysList();
	((MyTblWdbeQSysList*) tblwdbeqsyslist)->init(dbsMy);
	tblwdbeqsyssys1ntarget = new MyTblWdbeQSysSys1NTarget();
	((MyTblWdbeQSysSys1NTarget*) tblwdbeqsyssys1ntarget)->init(dbsMy);
	tblwdbeqtrglist = new MyTblWdbeQTrgList();
	((MyTblWdbeQTrgList*) tblwdbeqtrglist)->init(dbsMy);
	tblwdbequnt1nbank = new MyTblWdbeQUnt1NBank();
	((MyTblWdbeQUnt1NBank*) tblwdbequnt1nbank)->init(dbsMy);
	tblwdbequnt1ninterrupt = new MyTblWdbeQUnt1NInterrupt();
	((MyTblWdbeQUnt1NInterrupt*) tblwdbequnt1ninterrupt)->init(dbsMy);
	tblwdbequnt1nperipheral = new MyTblWdbeQUnt1NPeripheral();
	((MyTblWdbeQUnt1NPeripheral*) tblwdbequnt1nperipheral)->init(dbsMy);
	tblwdbequnt1ntarget = new MyTblWdbeQUnt1NTarget();
	((MyTblWdbeQUnt1NTarget*) tblwdbequnt1ntarget)->init(dbsMy);
	tblwdbequntfwd1ncontroller = new MyTblWdbeQUntFwd1NController();
	((MyTblWdbeQUntFwd1NController*) tblwdbequntfwd1ncontroller)->init(dbsMy);
	tblwdbequnthk1nmodule = new MyTblWdbeQUntHk1NModule();
	((MyTblWdbeQUntHk1NModule*) tblwdbequnthk1nmodule)->init(dbsMy);
	tblwdbequnthk1nvector = new MyTblWdbeQUntHk1NVector();
	((MyTblWdbeQUntHk1NVector*) tblwdbequnthk1nvector)->init(dbsMy);
	tblwdbequntlist = new MyTblWdbeQUntList();
	((MyTblWdbeQUntList*) tblwdbequntlist)->init(dbsMy);
	tblwdbequntref1ncommand = new MyTblWdbeQUntRef1NCommand();
	((MyTblWdbeQUntRef1NCommand*) tblwdbequntref1ncommand)->init(dbsMy);
	tblwdbequntref1nerror = new MyTblWdbeQUntRef1NError();
	((MyTblWdbeQUntRef1NError*) tblwdbequntref1nerror)->init(dbsMy);
	tblwdbequntref1nsignal = new MyTblWdbeQUntRef1NSignal();
	((MyTblWdbeQUntRef1NSignal*) tblwdbequntref1nsignal)->init(dbsMy);
	tblwdbequntsil1nunit = new MyTblWdbeQUntSil1NUnit();
	((MyTblWdbeQUntSil1NUnit*) tblwdbequntsil1nunit)->init(dbsMy);
	tblwdbequsgaaccess = new MyTblWdbeQUsgAAccess();
	((MyTblWdbeQUsgAAccess*) tblwdbequsgaaccess)->init(dbsMy);
	tblwdbequsglist = new MyTblWdbeQUsgList();
	((MyTblWdbeQUsgList*) tblwdbequsglist)->init(dbsMy);
	tblwdbequsgmnuser = new MyTblWdbeQUsgMNUser();
	((MyTblWdbeQUsgMNUser*) tblwdbequsgmnuser)->init(dbsMy);
	tblwdbequsr1nsession = new MyTblWdbeQUsr1NSession();
	((MyTblWdbeQUsr1NSession*) tblwdbequsr1nsession)->init(dbsMy);
	tblwdbequsraaccess = new MyTblWdbeQUsrAAccess();
	((MyTblWdbeQUsrAAccess*) tblwdbequsraaccess)->init(dbsMy);
	tblwdbequsrlist = new MyTblWdbeQUsrList();
	((MyTblWdbeQUsrList*) tblwdbequsrlist)->init(dbsMy);
	tblwdbequsrmnusergroup = new MyTblWdbeQUsrMNUsergroup();
	((MyTblWdbeQUsrMNUsergroup*) tblwdbequsrmnusergroup)->init(dbsMy);
	tblwdbeqvarlist = new MyTblWdbeQVarList();
	((MyTblWdbeQVarList*) tblwdbeqvarlist)->init(dbsMy);
	tblwdbeqveclist = new MyTblWdbeQVecList();
	((MyTblWdbeQVecList*) tblwdbeqveclist)->init(dbsMy);
	tblwdbeqvecvec1nvectoritem = new MyTblWdbeQVecVec1NVectoritem();
	((MyTblWdbeQVecVec1NVectoritem*) tblwdbeqvecvec1nvectoritem)->init(dbsMy);
	tblwdbeqver1nrelease = new MyTblWdbeQVer1NRelease();
	((MyTblWdbeQVer1NRelease*) tblwdbeqver1nrelease)->init(dbsMy);
	tblwdbeqver1nsystem = new MyTblWdbeQVer1NSystem();
	((MyTblWdbeQVer1NSystem*) tblwdbeqver1nsystem)->init(dbsMy);
	tblwdbeqver1nunit = new MyTblWdbeQVer1NUnit();
	((MyTblWdbeQVer1NUnit*) tblwdbeqver1nunit)->init(dbsMy);
	tblwdbeqverbvr1nversion = new MyTblWdbeQVerBvr1NVersion();
	((MyTblWdbeQVerBvr1NVersion*) tblwdbeqverbvr1nversion)->init(dbsMy);
	tblwdbeqverlist = new MyTblWdbeQVerList();
	((MyTblWdbeQVerList*) tblwdbeqverlist)->init(dbsMy);
	tblwdbeqvermnlibrary = new MyTblWdbeQVerMNLibrary();
	((MyTblWdbeQVerMNLibrary*) tblwdbeqvermnlibrary)->init(dbsMy);
	tblwdbeqverref1nfile = new MyTblWdbeQVerRef1NFile();
	((MyTblWdbeQVerRef1NFile*) tblwdbeqverref1nfile)->init(dbsMy);
	tblwdbeqvitlist = new MyTblWdbeQVitList();
	((MyTblWdbeQVitList*) tblwdbeqvitlist)->init(dbsMy);
};

void DbsWdbe::termMy() {
	mysql_close(dbsMy);
	mysql_thread_end();
};
#endif

#if defined(SBECORE_PG)
void DbsWdbe::initPg() {
	// connect to PostgreSQL database
	dbsPg = PQsetdbLogin(ip.c_str(), to_string(port).c_str(), NULL, NULL, dbsname.c_str(), username.c_str(), password.c_str());

	if (PQstatus(dbsPg) == CONNECTION_BAD) {
		string dbms = "DbsWdbe::initPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_CONN, {{"dbms",dbms}});
	};

	tblwdbeaccrmuseruniversal = new PgTblWdbeAccRMUserUniversal();
	((PgTblWdbeAccRMUserUniversal*) tblwdbeaccrmuseruniversal)->init(dbsPg);
	tblwdbeamcommandinvpar = new PgTblWdbeAMCommandInvpar();
	((PgTblWdbeAMCommandInvpar*) tblwdbeamcommandinvpar)->init(dbsPg);
	tblwdbeamcommandretpar = new PgTblWdbeAMCommandRetpar();
	((PgTblWdbeAMCommandRetpar*) tblwdbeamcommandretpar)->init(dbsPg);
	tblwdbeamcoreversionip = new PgTblWdbeAMCoreversionIp();
	((PgTblWdbeAMCoreversionIp*) tblwdbeamcoreversionip)->init(dbsPg);
	tblwdbeamcoreversionplh = new PgTblWdbeAMCoreversionPlh();
	((PgTblWdbeAMCoreversionPlh*) tblwdbeamcoreversionplh)->init(dbsPg);
	tblwdbeamerrorpar = new PgTblWdbeAMErrorPar();
	((PgTblWdbeAMErrorPar*) tblwdbeamerrorpar)->init(dbsPg);
	tblwdbeamfsmstatestep = new PgTblWdbeAMFsmstateStep();
	((PgTblWdbeAMFsmstateStep*) tblwdbeamfsmstatestep)->init(dbsPg);
	tblwdbeamlibrarymakefile = new PgTblWdbeAMLibraryMakefile();
	((PgTblWdbeAMLibraryMakefile*) tblwdbeamlibrarymakefile)->init(dbsPg);
	tblwdbeammachinemakefile = new PgTblWdbeAMMachineMakefile();
	((PgTblWdbeAMMachineMakefile*) tblwdbeammachinemakefile)->init(dbsPg);
	tblwdbeammachinepar = new PgTblWdbeAMMachinePar();
	((PgTblWdbeAMMachinePar*) tblwdbeammachinepar)->init(dbsPg);
	tblwdbeammodulepar = new PgTblWdbeAMModulePar();
	((PgTblWdbeAMModulePar*) tblwdbeammodulepar)->init(dbsPg);
	tblwdbeamperipheralpar = new PgTblWdbeAMPeripheralPar();
	((PgTblWdbeAMPeripheralPar*) tblwdbeamperipheralpar)->init(dbsPg);
	tblwdbeampersondetail = new PgTblWdbeAMPersonDetail();
	((PgTblWdbeAMPersonDetail*) tblwdbeampersondetail)->init(dbsPg);
	tblwdbeampinpar = new PgTblWdbeAMPinPar();
	((PgTblWdbeAMPinPar*) tblwdbeampinpar)->init(dbsPg);
	tblwdbeamuseraccess = new PgTblWdbeAMUserAccess();
	((PgTblWdbeAMUserAccess*) tblwdbeamuseraccess)->init(dbsPg);
	tblwdbeamusergroupaccess = new PgTblWdbeAMUsergroupAccess();
	((PgTblWdbeAMUsergroupAccess*) tblwdbeamusergroupaccess)->init(dbsPg);
	tblwdbeavcontrolpar = new PgTblWdbeAVControlPar();
	((PgTblWdbeAVControlPar*) tblwdbeavcontrolpar)->init(dbsPg);
	tblwdbeavkeylistkey = new PgTblWdbeAVKeylistKey();
	((PgTblWdbeAVKeylistKey*) tblwdbeavkeylistkey)->init(dbsPg);
	tblwdbeavvaluelistval = new PgTblWdbeAVValuelistVal();
	((PgTblWdbeAVValuelistVal*) tblwdbeavvaluelistval)->init(dbsPg);
	tblwdbecfile = new PgTblWdbeCFile();
	((PgTblWdbeCFile*) tblwdbecfile)->init(dbsPg);
	tblwdbecfsmstate = new PgTblWdbeCFsmstate();
	((PgTblWdbeCFsmstate*) tblwdbecfsmstate)->init(dbsPg);
	tblwdbecgeneric = new PgTblWdbeCGeneric();
	((PgTblWdbeCGeneric*) tblwdbecgeneric)->init(dbsPg);
	tblwdbecpin = new PgTblWdbeCPin();
	((PgTblWdbeCPin*) tblwdbecpin)->init(dbsPg);
	tblwdbecport = new PgTblWdbeCPort();
	((PgTblWdbeCPort*) tblwdbecport)->init(dbsPg);
	tblwdbecsegment = new PgTblWdbeCSegment();
	((PgTblWdbeCSegment*) tblwdbecsegment)->init(dbsPg);
	tblwdbecsignal = new PgTblWdbeCSignal();
	((PgTblWdbeCSignal*) tblwdbecsignal)->init(dbsPg);
	tblwdbecvariable = new PgTblWdbeCVariable();
	((PgTblWdbeCVariable*) tblwdbecvariable)->init(dbsPg);
	tblwdbehistrmuseruniversal = new PgTblWdbeHistRMUserUniversal();
	((PgTblWdbeHistRMUserUniversal*) tblwdbehistrmuseruniversal)->init(dbsPg);
	tblwdbejavkeylistkey = new PgTblWdbeJAVKeylistKey();
	((PgTblWdbeJAVKeylistKey*) tblwdbejavkeylistkey)->init(dbsPg);
	tblwdbejmcoreversionstate = new PgTblWdbeJMCoreversionState();
	((PgTblWdbeJMCoreversionState*) tblwdbejmcoreversionstate)->init(dbsPg);
	tblwdbejmpersonlastname = new PgTblWdbeJMPersonLastname();
	((PgTblWdbeJMPersonLastname*) tblwdbejmpersonlastname)->init(dbsPg);
	tblwdbejmpinsref = new PgTblWdbeJMPinSref();
	((PgTblWdbeJMPinSref*) tblwdbejmpinsref)->init(dbsPg);
	tblwdbejmuserstate = new PgTblWdbeJMUserState();
	((PgTblWdbeJMUserState*) tblwdbejmuserstate)->init(dbsPg);
	tblwdbejmversionstate = new PgTblWdbeJMVersionState();
	((PgTblWdbeJMVersionState*) tblwdbejmversionstate)->init(dbsPg);
	tblwdbembank = new PgTblWdbeMBank();
	((PgTblWdbeMBank*) tblwdbembank)->init(dbsPg);
	tblwdbemcommand = new PgTblWdbeMCommand();
	((PgTblWdbeMCommand*) tblwdbemcommand)->init(dbsPg);
	tblwdbemcontroller = new PgTblWdbeMController();
	((PgTblWdbeMController*) tblwdbemcontroller)->init(dbsPg);
	tblwdbemcoreproject = new PgTblWdbeMCoreproject();
	((PgTblWdbeMCoreproject*) tblwdbemcoreproject)->init(dbsPg);
	tblwdbemcoreversion = new PgTblWdbeMCoreversion();
	((PgTblWdbeMCoreversion*) tblwdbemcoreversion)->init(dbsPg);
	tblwdbemerror = new PgTblWdbeMError();
	((PgTblWdbeMError*) tblwdbemerror)->init(dbsPg);
	tblwdbemfamily = new PgTblWdbeMFamily();
	((PgTblWdbeMFamily*) tblwdbemfamily)->init(dbsPg);
	tblwdbemfile = new PgTblWdbeMFile();
	((PgTblWdbeMFile*) tblwdbemfile)->init(dbsPg);
	tblwdbemfsm = new PgTblWdbeMFsm();
	((PgTblWdbeMFsm*) tblwdbemfsm)->init(dbsPg);
	tblwdbemfsmstate = new PgTblWdbeMFsmstate();
	((PgTblWdbeMFsmstate*) tblwdbemfsmstate)->init(dbsPg);
	tblwdbemgeneric = new PgTblWdbeMGeneric();
	((PgTblWdbeMGeneric*) tblwdbemgeneric)->init(dbsPg);
	tblwdbemimbuf = new PgTblWdbeMImbuf();
	((PgTblWdbeMImbuf*) tblwdbemimbuf)->init(dbsPg);
	tblwdbeminterrupt = new PgTblWdbeMInterrupt();
	((PgTblWdbeMInterrupt*) tblwdbeminterrupt)->init(dbsPg);
	tblwdbemlibrary = new PgTblWdbeMLibrary();
	((PgTblWdbeMLibrary*) tblwdbemlibrary)->init(dbsPg);
	tblwdbemmachine = new PgTblWdbeMMachine();
	((PgTblWdbeMMachine*) tblwdbemmachine)->init(dbsPg);
	tblwdbemmodule = new PgTblWdbeMModule();
	((PgTblWdbeMModule*) tblwdbemmodule)->init(dbsPg);
	tblwdbemperipheral = new PgTblWdbeMPeripheral();
	((PgTblWdbeMPeripheral*) tblwdbemperipheral)->init(dbsPg);
	tblwdbemperson = new PgTblWdbeMPerson();
	((PgTblWdbeMPerson*) tblwdbemperson)->init(dbsPg);
	tblwdbempin = new PgTblWdbeMPin();
	((PgTblWdbeMPin*) tblwdbempin)->init(dbsPg);
	tblwdbempipeline = new PgTblWdbeMPipeline();
	((PgTblWdbeMPipeline*) tblwdbempipeline)->init(dbsPg);
	tblwdbemport = new PgTblWdbeMPort();
	((PgTblWdbeMPort*) tblwdbemport)->init(dbsPg);
	tblwdbemprocess = new PgTblWdbeMProcess();
	((PgTblWdbeMProcess*) tblwdbemprocess)->init(dbsPg);
	tblwdbemproject = new PgTblWdbeMProject();
	((PgTblWdbeMProject*) tblwdbemproject)->init(dbsPg);
	tblwdbemrelease = new PgTblWdbeMRelease();
	((PgTblWdbeMRelease*) tblwdbemrelease)->init(dbsPg);
	tblwdbemsegment = new PgTblWdbeMSegment();
	((PgTblWdbeMSegment*) tblwdbemsegment)->init(dbsPg);
	tblwdbemsensitivity = new PgTblWdbeMSensitivity();
	((PgTblWdbeMSensitivity*) tblwdbemsensitivity)->init(dbsPg);
	tblwdbemsession = new PgTblWdbeMSession();
	((PgTblWdbeMSession*) tblwdbemsession)->init(dbsPg);
	tblwdbemsignal = new PgTblWdbeMSignal();
	((PgTblWdbeMSignal*) tblwdbemsignal)->init(dbsPg);
	tblwdbemsystem = new PgTblWdbeMSystem();
	((PgTblWdbeMSystem*) tblwdbemsystem)->init(dbsPg);
	tblwdbemtarget = new PgTblWdbeMTarget();
	((PgTblWdbeMTarget*) tblwdbemtarget)->init(dbsPg);
	tblwdbemunit = new PgTblWdbeMUnit();
	((PgTblWdbeMUnit*) tblwdbemunit)->init(dbsPg);
	tblwdbemuser = new PgTblWdbeMUser();
	((PgTblWdbeMUser*) tblwdbemuser)->init(dbsPg);
	tblwdbemusergroup = new PgTblWdbeMUsergroup();
	((PgTblWdbeMUsergroup*) tblwdbemusergroup)->init(dbsPg);
	tblwdbemvariable = new PgTblWdbeMVariable();
	((PgTblWdbeMVariable*) tblwdbemvariable)->init(dbsPg);
	tblwdbemvector = new PgTblWdbeMVector();
	((PgTblWdbeMVector*) tblwdbemvector)->init(dbsPg);
	tblwdbemvectoritem = new PgTblWdbeMVectoritem();
	((PgTblWdbeMVectoritem*) tblwdbemvectoritem)->init(dbsPg);
	tblwdbemversion = new PgTblWdbeMVersion();
	((PgTblWdbeMVersion*) tblwdbemversion)->init(dbsPg);
	tblwdbermcommandmcontroller = new PgTblWdbeRMCommandMController();
	((PgTblWdbeRMCommandMController*) tblwdbermcommandmcontroller)->init(dbsPg);
	tblwdbermcoreprojectmperson = new PgTblWdbeRMCoreprojectMPerson();
	((PgTblWdbeRMCoreprojectMPerson*) tblwdbermcoreprojectmperson)->init(dbsPg);
	tblwdbermlibrarymversion = new PgTblWdbeRMLibraryMVersion();
	((PgTblWdbeRMLibraryMVersion*) tblwdbermlibrarymversion)->init(dbsPg);
	tblwdbermmodulemmodule = new PgTblWdbeRMModuleMModule();
	((PgTblWdbeRMModuleMModule*) tblwdbermmodulemmodule)->init(dbsPg);
	tblwdbermmodulemperipheral = new PgTblWdbeRMModuleMPeripheral();
	((PgTblWdbeRMModuleMPeripheral*) tblwdbermmodulemperipheral)->init(dbsPg);
	tblwdbermpersonmproject = new PgTblWdbeRMPersonMProject();
	((PgTblWdbeRMPersonMProject*) tblwdbermpersonmproject)->init(dbsPg);
	tblwdbermusergroupuniversal = new PgTblWdbeRMUsergroupUniversal();
	((PgTblWdbeRMUsergroupUniversal*) tblwdbermusergroupuniversal)->init(dbsPg);
	tblwdbermusermusergroup = new PgTblWdbeRMUserMUsergroup();
	((PgTblWdbeRMUserMUsergroup*) tblwdbermusermusergroup)->init(dbsPg);

	tblwdbeqbnk1npin = new PgTblWdbeQBnk1NPin();
	((PgTblWdbeQBnk1NPin*) tblwdbeqbnk1npin)->init(dbsPg);
	tblwdbeqbnklist = new PgTblWdbeQBnkList();
	((PgTblWdbeQBnkList*) tblwdbeqbnklist)->init(dbsPg);
	tblwdbeqcmdainvpar = new PgTblWdbeQCmdAInvpar();
	((PgTblWdbeQCmdAInvpar*) tblwdbeqcmdainvpar)->init(dbsPg);
	tblwdbeqcmdaretpar = new PgTblWdbeQCmdARetpar();
	((PgTblWdbeQCmdARetpar*) tblwdbeqcmdaretpar)->init(dbsPg);
	tblwdbeqcmdlist = new PgTblWdbeQCmdList();
	((PgTblWdbeQCmdList*) tblwdbeqcmdlist)->init(dbsPg);
	tblwdbeqcmdmncontroller = new PgTblWdbeQCmdMNController();
	((PgTblWdbeQCmdMNController*) tblwdbeqcmdmncontroller)->init(dbsPg);
	tblwdbeqcpr1ncoreversion = new PgTblWdbeQCpr1NCoreversion();
	((PgTblWdbeQCpr1NCoreversion*) tblwdbeqcpr1ncoreversion)->init(dbsPg);
	tblwdbeqcprlist = new PgTblWdbeQCprList();
	((PgTblWdbeQCprList*) tblwdbeqcprlist)->init(dbsPg);
	tblwdbeqcprmnperson = new PgTblWdbeQCprMNPerson();
	((PgTblWdbeQCprMNPerson*) tblwdbeqcprmnperson)->init(dbsPg);
	tblwdbeqcvraip = new PgTblWdbeQCvrAIp();
	((PgTblWdbeQCvrAIp*) tblwdbeqcvraip)->init(dbsPg);
	tblwdbeqcvraplh = new PgTblWdbeQCvrAPlh();
	((PgTblWdbeQCvrAPlh*) tblwdbeqcvraplh)->init(dbsPg);
	tblwdbeqcvrbcv1ncoreversion = new PgTblWdbeQCvrBcv1NCoreversion();
	((PgTblWdbeQCvrBcv1NCoreversion*) tblwdbeqcvrbcv1ncoreversion)->init(dbsPg);
	tblwdbeqcvrhk1nmodule = new PgTblWdbeQCvrHk1NModule();
	((PgTblWdbeQCvrHk1NModule*) tblwdbeqcvrhk1nmodule)->init(dbsPg);
	tblwdbeqcvrlist = new PgTblWdbeQCvrList();
	((PgTblWdbeQCvrList*) tblwdbeqcvrlist)->init(dbsPg);
	tblwdbeqerrapar = new PgTblWdbeQErrAPar();
	((PgTblWdbeQErrAPar*) tblwdbeqerrapar)->init(dbsPg);
	tblwdbeqerrlist = new PgTblWdbeQErrList();
	((PgTblWdbeQErrList*) tblwdbeqerrlist)->init(dbsPg);
	tblwdbeqfam1nunit = new PgTblWdbeQFam1NUnit();
	((PgTblWdbeQFam1NUnit*) tblwdbeqfam1nunit)->init(dbsPg);
	tblwdbeqfamlist = new PgTblWdbeQFamList();
	((PgTblWdbeQFamList*) tblwdbeqfamlist)->init(dbsPg);
	tblwdbeqfillist = new PgTblWdbeQFilList();
	((PgTblWdbeQFilList*) tblwdbeqfillist)->init(dbsPg);
	tblwdbeqfstastep = new PgTblWdbeQFstAStep();
	((PgTblWdbeQFstAStep*) tblwdbeqfstastep)->init(dbsPg);
	tblwdbeqfstlist = new PgTblWdbeQFstList();
	((PgTblWdbeQFstList*) tblwdbeqfstlist)->init(dbsPg);
	tblwdbeqgenlist = new PgTblWdbeQGenList();
	((PgTblWdbeQGenList*) tblwdbeqgenlist)->init(dbsPg);
	tblwdbeqintlist = new PgTblWdbeQIntList();
	((PgTblWdbeQIntList*) tblwdbeqintlist)->init(dbsPg);
	tblwdbeqintsrc1nsensitivity = new PgTblWdbeQIntSrc1NSensitivity();
	((PgTblWdbeQIntSrc1NSensitivity*) tblwdbeqintsrc1nsensitivity)->init(dbsPg);
	tblwdbeqlibamakefile = new PgTblWdbeQLibAMakefile();
	((PgTblWdbeQLibAMakefile*) tblwdbeqlibamakefile)->init(dbsPg);
	tblwdbeqliblist = new PgTblWdbeQLibList();
	((PgTblWdbeQLibList*) tblwdbeqliblist)->init(dbsPg);
	tblwdbeqlibmnversion = new PgTblWdbeQLibMNVersion();
	((PgTblWdbeQLibMNVersion*) tblwdbeqlibmnversion)->init(dbsPg);
	tblwdbeqmch1nrelease = new PgTblWdbeQMch1NRelease();
	((PgTblWdbeQMch1NRelease*) tblwdbeqmch1nrelease)->init(dbsPg);
	tblwdbeqmchamakefile = new PgTblWdbeQMchAMakefile();
	((PgTblWdbeQMchAMakefile*) tblwdbeqmchamakefile)->init(dbsPg);
	tblwdbeqmchapar = new PgTblWdbeQMchAPar();
	((PgTblWdbeQMchAPar*) tblwdbeqmchapar)->init(dbsPg);
	tblwdbeqmchlist = new PgTblWdbeQMchList();
	((PgTblWdbeQMchList*) tblwdbeqmchlist)->init(dbsPg);
	tblwdbeqmchsup1nmachine = new PgTblWdbeQMchSup1NMachine();
	((PgTblWdbeQMchSup1NMachine*) tblwdbeqmchsup1nmachine)->init(dbsPg);
	tblwdbeqmod1nprocess = new PgTblWdbeQMod1NProcess();
	((PgTblWdbeQMod1NProcess*) tblwdbeqmod1nprocess)->init(dbsPg);
	tblwdbeqmodapar = new PgTblWdbeQModAPar();
	((PgTblWdbeQModAPar*) tblwdbeqmodapar)->init(dbsPg);
	tblwdbeqmodcormnmodule = new PgTblWdbeQModCorMNModule();
	((PgTblWdbeQModCorMNModule*) tblwdbeqmodcormnmodule)->init(dbsPg);
	tblwdbeqmodctdmnmodule = new PgTblWdbeQModCtdMNModule();
	((PgTblWdbeQModCtdMNModule*) tblwdbeqmodctdmnmodule)->init(dbsPg);
	tblwdbeqmodctrhk1nvector = new PgTblWdbeQModCtrHk1NVector();
	((PgTblWdbeQModCtrHk1NVector*) tblwdbeqmodctrhk1nvector)->init(dbsPg);
	tblwdbeqmodctrmncommand = new PgTblWdbeQModCtrMNCommand();
	((PgTblWdbeQModCtrMNCommand*) tblwdbeqmodctrmncommand)->init(dbsPg);
	tblwdbeqmodctrref1ncommand = new PgTblWdbeQModCtrRef1NCommand();
	((PgTblWdbeQModCtrRef1NCommand*) tblwdbeqmodctrref1ncommand)->init(dbsPg);
	tblwdbeqmodctrref1nerror = new PgTblWdbeQModCtrRef1NError();
	((PgTblWdbeQModCtrRef1NError*) tblwdbeqmodctrref1nerror)->init(dbsPg);
	tblwdbeqmodhsm1npipeline = new PgTblWdbeQModHsm1NPipeline();
	((PgTblWdbeQModHsm1NPipeline*) tblwdbeqmodhsm1npipeline)->init(dbsPg);
	tblwdbeqmodkhdltype = new PgTblWdbeQModKHdltype();
	((PgTblWdbeQModKHdltype*) tblwdbeqmodkhdltype)->init(dbsPg);
	tblwdbeqmodlist = new PgTblWdbeQModList();
	((PgTblWdbeQModList*) tblwdbeqmodlist)->init(dbsPg);
	tblwdbeqmodmdl1ngeneric = new PgTblWdbeQModMdl1NGeneric();
	((PgTblWdbeQModMdl1NGeneric*) tblwdbeqmodmdl1ngeneric)->init(dbsPg);
	tblwdbeqmodmdl1nport = new PgTblWdbeQModMdl1NPort();
	((PgTblWdbeQModMdl1NPort*) tblwdbeqmodmdl1nport)->init(dbsPg);
	tblwdbeqmodmge1nsignal = new PgTblWdbeQModMge1NSignal();
	((PgTblWdbeQModMge1NSignal*) tblwdbeqmodmge1nsignal)->init(dbsPg);
	tblwdbeqmodmnperipheral = new PgTblWdbeQModMNPeripheral();
	((PgTblWdbeQModMNPeripheral*) tblwdbeqmodmnperipheral)->init(dbsPg);
	tblwdbeqmodref1nsensitivity = new PgTblWdbeQModRef1NSensitivity();
	((PgTblWdbeQModRef1NSensitivity*) tblwdbeqmodref1nsensitivity)->init(dbsPg);
	tblwdbeqmodref1nsignal = new PgTblWdbeQModRef1NSignal();
	((PgTblWdbeQModRef1NSignal*) tblwdbeqmodref1nsignal)->init(dbsPg);
	tblwdbeqmodref1nvariable = new PgTblWdbeQModRef1NVariable();
	((PgTblWdbeQModRef1NVariable*) tblwdbeqmodref1nvariable)->init(dbsPg);
	tblwdbeqmodsup1nmodule = new PgTblWdbeQModSup1NModule();
	((PgTblWdbeQModSup1NModule*) tblwdbeqmodsup1nmodule)->init(dbsPg);
	tblwdbeqmtpapar = new PgTblWdbeQMtpAPar();
	((PgTblWdbeQMtpAPar*) tblwdbeqmtpapar)->init(dbsPg);
	tblwdbeqmtphsm1npipeline = new PgTblWdbeQMtpHsm1NPipeline();
	((PgTblWdbeQMtpHsm1NPipeline*) tblwdbeqmtphsm1npipeline)->init(dbsPg);
	tblwdbeqmtpkhdltype = new PgTblWdbeQMtpKHdltype();
	((PgTblWdbeQMtpKHdltype*) tblwdbeqmtpkhdltype)->init(dbsPg);
	tblwdbeqmtpkparkey = new PgTblWdbeQMtpKParKey();
	((PgTblWdbeQMtpKParKey*) tblwdbeqmtpkparkey)->init(dbsPg);
	tblwdbeqmtplist = new PgTblWdbeQMtpList();
	((PgTblWdbeQMtpList*) tblwdbeqmtplist)->init(dbsPg);
	tblwdbeqmtpmdl1ngeneric = new PgTblWdbeQMtpMdl1NGeneric();
	((PgTblWdbeQMtpMdl1NGeneric*) tblwdbeqmtpmdl1ngeneric)->init(dbsPg);
	tblwdbeqmtpmdl1nport = new PgTblWdbeQMtpMdl1NPort();
	((PgTblWdbeQMtpMdl1NPort*) tblwdbeqmtpmdl1nport)->init(dbsPg);
	tblwdbeqmtpmge1nsignal = new PgTblWdbeQMtpMge1NSignal();
	((PgTblWdbeQMtpMge1NSignal*) tblwdbeqmtpmge1nsignal)->init(dbsPg);
	tblwdbeqmtpref1nfile = new PgTblWdbeQMtpRef1NFile();
	((PgTblWdbeQMtpRef1NFile*) tblwdbeqmtpref1nfile)->init(dbsPg);
	tblwdbeqmtpref1nsensitivity = new PgTblWdbeQMtpRef1NSensitivity();
	((PgTblWdbeQMtpRef1NSensitivity*) tblwdbeqmtpref1nsensitivity)->init(dbsPg);
	tblwdbeqmtpref1nvariable = new PgTblWdbeQMtpRef1NVariable();
	((PgTblWdbeQMtpRef1NVariable*) tblwdbeqmtpref1nvariable)->init(dbsPg);
	tblwdbeqmtpsup1nmodule = new PgTblWdbeQMtpSup1NModule();
	((PgTblWdbeQMtpSup1NModule*) tblwdbeqmtpsup1nmodule)->init(dbsPg);
	tblwdbeqmtptpl1nmodule = new PgTblWdbeQMtpTpl1NModule();
	((PgTblWdbeQMtpTpl1NModule*) tblwdbeqmtptpl1nmodule)->init(dbsPg);
	tblwdbeqpinapar = new PgTblWdbeQPinAPar();
	((PgTblWdbeQPinAPar*) tblwdbeqpinapar)->init(dbsPg);
	tblwdbeqpinlist = new PgTblWdbeQPinList();
	((PgTblWdbeQPinList*) tblwdbeqpinlist)->init(dbsPg);
	tblwdbeqpphapar = new PgTblWdbeQPphAPar();
	((PgTblWdbeQPphAPar*) tblwdbeqpphapar)->init(dbsPg);
	tblwdbeqpphlist = new PgTblWdbeQPphList();
	((PgTblWdbeQPphList*) tblwdbeqpphlist)->init(dbsPg);
	tblwdbeqpphmnmodule = new PgTblWdbeQPphMNModule();
	((PgTblWdbeQPphMNModule*) tblwdbeqpphmnmodule)->init(dbsPg);
	tblwdbeqppllist = new PgTblWdbeQPplList();
	((PgTblWdbeQPplList*) tblwdbeqppllist)->init(dbsPg);
	tblwdbeqpplppl1nsegment = new PgTblWdbeQPplPpl1NSegment();
	((PgTblWdbeQPplPpl1NSegment*) tblwdbeqpplppl1nsegment)->init(dbsPg);
	tblwdbeqprcfsmfsm1nfsmstate = new PgTblWdbeQPrcFsmFsm1NFsmstate();
	((PgTblWdbeQPrcFsmFsm1NFsmstate*) tblwdbeqprcfsmfsm1nfsmstate)->init(dbsPg);
	tblwdbeqprckhdltype = new PgTblWdbeQPrcKHdltype();
	((PgTblWdbeQPrcKHdltype*) tblwdbeqprckhdltype)->init(dbsPg);
	tblwdbeqprclist = new PgTblWdbeQPrcList();
	((PgTblWdbeQPrcList*) tblwdbeqprclist)->init(dbsPg);
	tblwdbeqprcmge1nsignal = new PgTblWdbeQPrcMge1NSignal();
	((PgTblWdbeQPrcMge1NSignal*) tblwdbeqprcmge1nsignal)->init(dbsPg);
	tblwdbeqprcref1nsensitivity = new PgTblWdbeQPrcRef1NSensitivity();
	((PgTblWdbeQPrcRef1NSensitivity*) tblwdbeqprcref1nsensitivity)->init(dbsPg);
	tblwdbeqprcref1nvariable = new PgTblWdbeQPrcRef1NVariable();
	((PgTblWdbeQPrcRef1NVariable*) tblwdbeqprcref1nvariable)->init(dbsPg);
	tblwdbeqpreselect = new PgTblWdbeQPreselect();
	((PgTblWdbeQPreselect*) tblwdbeqpreselect)->init(dbsPg);
	tblwdbeqprjlist = new PgTblWdbeQPrjList();
	((PgTblWdbeQPrjList*) tblwdbeqprjlist)->init(dbsPg);
	tblwdbeqprjmnperson = new PgTblWdbeQPrjMNPerson();
	((PgTblWdbeQPrjMNPerson*) tblwdbeqprjmnperson)->init(dbsPg);
	tblwdbeqprjprj1nversion = new PgTblWdbeQPrjPrj1NVersion();
	((PgTblWdbeQPrjPrj1NVersion*) tblwdbeqprjprj1nversion)->init(dbsPg);
	tblwdbeqprsadetail = new PgTblWdbeQPrsADetail();
	((PgTblWdbeQPrsADetail*) tblwdbeqprsadetail)->init(dbsPg);
	tblwdbeqprslist = new PgTblWdbeQPrsList();
	((PgTblWdbeQPrsList*) tblwdbeqprslist)->init(dbsPg);
	tblwdbeqprsmncoreproject = new PgTblWdbeQPrsMNCoreproject();
	((PgTblWdbeQPrsMNCoreproject*) tblwdbeqprsmncoreproject)->init(dbsPg);
	tblwdbeqprsmnproject = new PgTblWdbeQPrsMNProject();
	((PgTblWdbeQPrsMNProject*) tblwdbeqprsmnproject)->init(dbsPg);
	tblwdbeqprtlist = new PgTblWdbeQPrtList();
	((PgTblWdbeQPrtList*) tblwdbeqprtlist)->init(dbsPg);
	tblwdbeqprtsrc1nsensitivity = new PgTblWdbeQPrtSrc1NSensitivity();
	((PgTblWdbeQPrtSrc1NSensitivity*) tblwdbeqprtsrc1nsensitivity)->init(dbsPg);
	tblwdbeqrlslist = new PgTblWdbeQRlsList();
	((PgTblWdbeQRlsList*) tblwdbeqrlslist)->init(dbsPg);
	tblwdbeqseglist = new PgTblWdbeQSegList();
	((PgTblWdbeQSegList*) tblwdbeqseglist)->init(dbsPg);
	tblwdbeqsegsup1nsegment = new PgTblWdbeQSegSup1NSegment();
	((PgTblWdbeQSegSup1NSegment*) tblwdbeqsegsup1nsegment)->init(dbsPg);
	tblwdbeqselect = new PgTblWdbeQSelect();
	((PgTblWdbeQSelect*) tblwdbeqselect)->init(dbsPg);
	tblwdbeqsiglist = new PgTblWdbeQSigList();
	((PgTblWdbeQSigList*) tblwdbeqsiglist)->init(dbsPg);
	tblwdbeqsigsrc1nsensitivity = new PgTblWdbeQSigSrc1NSensitivity();
	((PgTblWdbeQSigSrc1NSensitivity*) tblwdbeqsigsrc1nsensitivity)->init(dbsPg);
	tblwdbeqsil1nbank = new PgTblWdbeQSil1NBank();
	((PgTblWdbeQSil1NBank*) tblwdbeqsil1nbank)->init(dbsPg);
	tblwdbeqsil1ninterrupt = new PgTblWdbeQSil1NInterrupt();
	((PgTblWdbeQSil1NInterrupt*) tblwdbeqsil1ninterrupt)->init(dbsPg);
	tblwdbeqsil1nperipheral = new PgTblWdbeQSil1NPeripheral();
	((PgTblWdbeQSil1NPeripheral*) tblwdbeqsil1nperipheral)->init(dbsPg);
	tblwdbeqsil1ntarget = new PgTblWdbeQSil1NTarget();
	((PgTblWdbeQSil1NTarget*) tblwdbeqsil1ntarget)->init(dbsPg);
	tblwdbeqsilfwd1ncontroller = new PgTblWdbeQSilFwd1NController();
	((PgTblWdbeQSilFwd1NController*) tblwdbeqsilfwd1ncontroller)->init(dbsPg);
	tblwdbeqsilhk1nmodule = new PgTblWdbeQSilHk1NModule();
	((PgTblWdbeQSilHk1NModule*) tblwdbeqsilhk1nmodule)->init(dbsPg);
	tblwdbeqsilhk1nvector = new PgTblWdbeQSilHk1NVector();
	((PgTblWdbeQSilHk1NVector*) tblwdbeqsilhk1nvector)->init(dbsPg);
	tblwdbeqsillist = new PgTblWdbeQSilList();
	((PgTblWdbeQSilList*) tblwdbeqsillist)->init(dbsPg);
	tblwdbeqsilref1ncommand = new PgTblWdbeQSilRef1NCommand();
	((PgTblWdbeQSilRef1NCommand*) tblwdbeqsilref1ncommand)->init(dbsPg);
	tblwdbeqsilref1nerror = new PgTblWdbeQSilRef1NError();
	((PgTblWdbeQSilRef1NError*) tblwdbeqsilref1nerror)->init(dbsPg);
	tblwdbeqsilref1nsignal = new PgTblWdbeQSilRef1NSignal();
	((PgTblWdbeQSilRef1NSignal*) tblwdbeqsilref1nsignal)->init(dbsPg);
	tblwdbeqsilsil1nunit = new PgTblWdbeQSilSil1NUnit();
	((PgTblWdbeQSilSil1NUnit*) tblwdbeqsilsil1nunit)->init(dbsPg);
	tblwdbeqsnslist = new PgTblWdbeQSnsList();
	((PgTblWdbeQSnsList*) tblwdbeqsnslist)->init(dbsPg);
	tblwdbeqsyshk1nvector = new PgTblWdbeQSysHk1NVector();
	((PgTblWdbeQSysHk1NVector*) tblwdbeqsyshk1nvector)->init(dbsPg);
	tblwdbeqsyslist = new PgTblWdbeQSysList();
	((PgTblWdbeQSysList*) tblwdbeqsyslist)->init(dbsPg);
	tblwdbeqsyssys1ntarget = new PgTblWdbeQSysSys1NTarget();
	((PgTblWdbeQSysSys1NTarget*) tblwdbeqsyssys1ntarget)->init(dbsPg);
	tblwdbeqtrglist = new PgTblWdbeQTrgList();
	((PgTblWdbeQTrgList*) tblwdbeqtrglist)->init(dbsPg);
	tblwdbequnt1nbank = new PgTblWdbeQUnt1NBank();
	((PgTblWdbeQUnt1NBank*) tblwdbequnt1nbank)->init(dbsPg);
	tblwdbequnt1ninterrupt = new PgTblWdbeQUnt1NInterrupt();
	((PgTblWdbeQUnt1NInterrupt*) tblwdbequnt1ninterrupt)->init(dbsPg);
	tblwdbequnt1nperipheral = new PgTblWdbeQUnt1NPeripheral();
	((PgTblWdbeQUnt1NPeripheral*) tblwdbequnt1nperipheral)->init(dbsPg);
	tblwdbequnt1ntarget = new PgTblWdbeQUnt1NTarget();
	((PgTblWdbeQUnt1NTarget*) tblwdbequnt1ntarget)->init(dbsPg);
	tblwdbequntfwd1ncontroller = new PgTblWdbeQUntFwd1NController();
	((PgTblWdbeQUntFwd1NController*) tblwdbequntfwd1ncontroller)->init(dbsPg);
	tblwdbequnthk1nmodule = new PgTblWdbeQUntHk1NModule();
	((PgTblWdbeQUntHk1NModule*) tblwdbequnthk1nmodule)->init(dbsPg);
	tblwdbequnthk1nvector = new PgTblWdbeQUntHk1NVector();
	((PgTblWdbeQUntHk1NVector*) tblwdbequnthk1nvector)->init(dbsPg);
	tblwdbequntlist = new PgTblWdbeQUntList();
	((PgTblWdbeQUntList*) tblwdbequntlist)->init(dbsPg);
	tblwdbequntref1ncommand = new PgTblWdbeQUntRef1NCommand();
	((PgTblWdbeQUntRef1NCommand*) tblwdbequntref1ncommand)->init(dbsPg);
	tblwdbequntref1nerror = new PgTblWdbeQUntRef1NError();
	((PgTblWdbeQUntRef1NError*) tblwdbequntref1nerror)->init(dbsPg);
	tblwdbequntref1nsignal = new PgTblWdbeQUntRef1NSignal();
	((PgTblWdbeQUntRef1NSignal*) tblwdbequntref1nsignal)->init(dbsPg);
	tblwdbequntsil1nunit = new PgTblWdbeQUntSil1NUnit();
	((PgTblWdbeQUntSil1NUnit*) tblwdbequntsil1nunit)->init(dbsPg);
	tblwdbequsgaaccess = new PgTblWdbeQUsgAAccess();
	((PgTblWdbeQUsgAAccess*) tblwdbequsgaaccess)->init(dbsPg);
	tblwdbequsglist = new PgTblWdbeQUsgList();
	((PgTblWdbeQUsgList*) tblwdbequsglist)->init(dbsPg);
	tblwdbequsgmnuser = new PgTblWdbeQUsgMNUser();
	((PgTblWdbeQUsgMNUser*) tblwdbequsgmnuser)->init(dbsPg);
	tblwdbequsr1nsession = new PgTblWdbeQUsr1NSession();
	((PgTblWdbeQUsr1NSession*) tblwdbequsr1nsession)->init(dbsPg);
	tblwdbequsraaccess = new PgTblWdbeQUsrAAccess();
	((PgTblWdbeQUsrAAccess*) tblwdbequsraaccess)->init(dbsPg);
	tblwdbequsrlist = new PgTblWdbeQUsrList();
	((PgTblWdbeQUsrList*) tblwdbequsrlist)->init(dbsPg);
	tblwdbequsrmnusergroup = new PgTblWdbeQUsrMNUsergroup();
	((PgTblWdbeQUsrMNUsergroup*) tblwdbequsrmnusergroup)->init(dbsPg);
	tblwdbeqvarlist = new PgTblWdbeQVarList();
	((PgTblWdbeQVarList*) tblwdbeqvarlist)->init(dbsPg);
	tblwdbeqveclist = new PgTblWdbeQVecList();
	((PgTblWdbeQVecList*) tblwdbeqveclist)->init(dbsPg);
	tblwdbeqvecvec1nvectoritem = new PgTblWdbeQVecVec1NVectoritem();
	((PgTblWdbeQVecVec1NVectoritem*) tblwdbeqvecvec1nvectoritem)->init(dbsPg);
	tblwdbeqver1nrelease = new PgTblWdbeQVer1NRelease();
	((PgTblWdbeQVer1NRelease*) tblwdbeqver1nrelease)->init(dbsPg);
	tblwdbeqver1nsystem = new PgTblWdbeQVer1NSystem();
	((PgTblWdbeQVer1NSystem*) tblwdbeqver1nsystem)->init(dbsPg);
	tblwdbeqver1nunit = new PgTblWdbeQVer1NUnit();
	((PgTblWdbeQVer1NUnit*) tblwdbeqver1nunit)->init(dbsPg);
	tblwdbeqverbvr1nversion = new PgTblWdbeQVerBvr1NVersion();
	((PgTblWdbeQVerBvr1NVersion*) tblwdbeqverbvr1nversion)->init(dbsPg);
	tblwdbeqverlist = new PgTblWdbeQVerList();
	((PgTblWdbeQVerList*) tblwdbeqverlist)->init(dbsPg);
	tblwdbeqvermnlibrary = new PgTblWdbeQVerMNLibrary();
	((PgTblWdbeQVerMNLibrary*) tblwdbeqvermnlibrary)->init(dbsPg);
	tblwdbeqverref1nfile = new PgTblWdbeQVerRef1NFile();
	((PgTblWdbeQVerRef1NFile*) tblwdbeqverref1nfile)->init(dbsPg);
	tblwdbeqvitlist = new PgTblWdbeQVitList();
	((PgTblWdbeQVitList*) tblwdbeqvitlist)->init(dbsPg);
};

void DbsWdbe::termPg() {
	PQfinish(dbsPg);
};
#endif

void DbsWdbe::begin() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) beginMy();
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) beginPg();
#endif
};

bool DbsWdbe::commit() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return commitMy();
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return commitPg();
#endif

	return false;
};

void DbsWdbe::rollback() {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) rollbackMy();
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) rollbackPg();
#endif
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
void DbsWdbe::beginMy() {
	if (mysql_query(dbsMy, "BEGIN")) {
		string dbms = "DbsWdbe::beginMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","BEGIN"}});
	};
};

bool DbsWdbe::commitMy() {
	if (mysql_query(dbsMy, "COMMIT")) {
		rollbackMy();
		return false;
	};

	return true;
};

void DbsWdbe::rollbackMy() {
	if (mysql_query(dbsMy, "ROLLBACK")) {
		string dbms = "DbsWdbe::rollbackMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","ROLLBACK"}});
	};
};
#endif

#if defined(SBECORE_PG)
void DbsWdbe::beginPg() {
	PGresult* res;

	res = PQexec(dbsPg, "BEGIN");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "DbsWdbe::beginPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","BEGIN"}});
	};

	PQclear(res);
};

bool DbsWdbe::commitPg() {
	PGresult* res;

	res = PQexec(dbsPg, "COMMIT");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		rollbackPg();

		PQclear(res);
		return false;
	};

	PQclear(res);
	return true;
};

void DbsWdbe::rollbackPg() {
	PGresult* res;

	res = PQexec(dbsPg, "ROLLBACK");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "DbsWdbe::rollbackPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql","ROLLBACK"}});
	};

	PQclear(res);
};
#endif

bool DbsWdbe::loadUintBySQL(
			const string& sqlstr
			, uint& val
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadUintBySQLMy(sqlstr, val);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadUintBySQLPg(sqlstr, val);
#endif

	return false;
};

bool DbsWdbe::loadStringBySQL(
			const string& sqlstr
			, string& val
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadStringBySQLMy(sqlstr, val);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadStringBySQLPg(sqlstr, val);
#endif

	return false;
};

bool DbsWdbe::loadRefBySQL(
			const string& sqlstr
			, ubigint& ref
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefBySQLMy(sqlstr, ref);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadRefBySQLPg(sqlstr, ref);
#endif

	return false;
};

ubigint DbsWdbe::loadRefsBySQL(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefsBySQLMy(sqlstr, append, refs);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadRefsBySQLPg(sqlstr, append, refs);
#endif

	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
bool DbsWdbe::loadUintBySQLMy(
			const string& sqlstr
			, uint& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWdbe::loadUintBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWdbe::loadUintBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		val = atol((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsWdbe::loadStringBySQLMy(
			const string& sqlstr
			, string& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWdbe::loadStringBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWdbe::loadStringBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);
		val.assign(dbrow[0], dblengths[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsWdbe::loadRefBySQLMy(
			const string& sqlstr
			, ubigint& ref
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWdbe::loadRefBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWdbe::loadRefBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		ref = atoll((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

ubigint DbsWdbe::loadRefsBySQLMy(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "DbsWdbe::loadRefsBySQLMy() / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) {
		string dbms = "DbsWdbe::loadRefsBySQLMy() / store result / " + string(mysql_error(dbsMy));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		dbrow = mysql_fetch_row(dbresult);
		refs.push_back(atoll((char*) dbrow[0]));
		numread++;
	};

	mysql_free_result(dbresult);
	
	return(numread);
};
#endif

#if defined(SBECORE_PG)
bool DbsWdbe::loadUintBySQLPg(
			const string& sqlstr
			, uint& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWdbe::loadUintBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val = atol(ptr);

		retval = true;
	};

	PQclear(res);

	return retval;
};

bool DbsWdbe::loadStringBySQLPg(
			const string& sqlstr
			, string& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;

	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWdbe::loadStringBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val.assign(ptr, PQgetlength(res, 0, 0));

		retval = true;
	};

	PQclear(res);

	return retval;
};

bool DbsWdbe::loadRefBySQLPg(
			const string& sqlstr
			, ubigint& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWdbe::loadRefBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	return retval;
};

ubigint DbsWdbe::loadRefsBySQLPg(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	PGresult* res; ubigint numrow; ubigint numread = 0; char* ptr;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "DbsWdbe::loadRefsBySQLPg() / " + string(PQerrorMessage(dbsPg));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = PQntuples(res);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		ptr = PQgetvalue(res, numread, 0); refs.push_back(atoll(ptr));
		numread++;
	};

	PQclear(res);

	return(numread);
};
#endif

void DbsWdbe::executeQuery(
			const string& sqlstr
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY)
		if (mysql_real_query(dbsMy, sqlstr.c_str(), strlen(sqlstr.c_str()))) {
			string dbms = "DbsWdbe::executeQuery() / MySQL / " + string(mysql_error(dbsMy));
			throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
		};
#endif

#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		PGresult* res;

		res = PQexec(dbsPg, sqlstr.c_str());
		if (PQresultStatus(res) != PGRES_COMMAND_OK) {
			string dbms = "DbsWdbe::executeQuery() / PgSQL / " + string(PQerrorMessage(dbsPg));
			throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
		};
	};
#endif

};

void DbsWdbe::executeQueryDiv(
			const string& sqlstrmy
			, const string& sqlstrpg
		) {
#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	if (ixDbsVDbstype == VecDbsVDbstype::MY) executeQuery(sqlstrmy);
#endif
#if defined(SBECORE_PG)
	if (ixDbsVDbstype == VecDbsVDbstype::PG) executeQuery(sqlstrpg);
#endif
};

void DbsWdbe::executeFile(
			const string& fullpath
		) {
	string sqlstr = "";
	char c;
	
	ifstream sqlfile(fullpath.c_str());

	while (sqlfile.get(c)) {
		switch (c) {
			case '\n':
				break;
			case '\t':
				break;
			case ';':
				executeQuery(sqlstr);
				sqlstr = "";
				break;
			default:
				sqlstr = sqlstr + c;
				break;
		};
	};
	sqlfile.close();
};

uint DbsWdbe::getIxWSubsetByRefWdbeMModule(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	WdbeMModule* rec = NULL;

	if (tblwdbemmodule->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByWdbeMModule(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsWdbe::getIxWSubsetByWdbeMModule(
			WdbeMModule* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMCT) == 0) {
		a = false; a = (rec->hkIxVTbl == VecWdbeVMModuleHkTbl::VOID);
		args.push_back(a);
		a = false; a = (rec->supRefWdbeMModule == 0);
		args.push_back(a);
		a = false; a = (rec->tplRefWdbeMModule == 0);
		args.push_back(a);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a && b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a && b);
		a = args.back(); args.pop_back();
		args.push_back(!a);
		a = false; a = (rec->ixVBasetype == VecWdbeVMModuleBasetype::CTR);
		args.push_back(a);
		a = false; a = (rec->ixVBasetype == VecWdbeVMModuleBasetype::FWDCTR);
		args.push_back(a);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a || b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a && b);
		if (args.back()) {
			ixWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMCT;
			dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMIB;
			ixWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMOD;
			dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMOD;
			dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMTP;
		} else {
		};

		dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMCT;
		args.clear();
	};

	if ((dneIxWSubset & TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMIB) == 0) {
		a = false; a = (rec->hkIxVTbl == VecWdbeVMModuleHkTbl::VOID);
		args.push_back(a);
		a = false; a = (rec->supRefWdbeMModule == 0);
		args.push_back(a);
		a = false; a = (rec->tplRefWdbeMModule == 0);
		args.push_back(a);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a && b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a && b);
		a = args.back(); args.pop_back();
		args.push_back(!a);
		a = false; a = (rec->ixVBasetype == VecWdbeVMModuleBasetype::IMBUF);
		args.push_back(a);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a && b);
		if (args.back()) {
			ixWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMIB;
			dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMCT;
			ixWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMOD;
			dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMOD;
			dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMTP;
		} else {
		};

		dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMIB;
		args.clear();
	};

	if ((dneIxWSubset & TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMOD) == 0) {
		a = false; a = (rec->hkIxVTbl == VecWdbeVMModuleHkTbl::VOID);
		args.push_back(a);
		a = false; a = (rec->supRefWdbeMModule == 0);
		args.push_back(a);
		a = false; a = (rec->tplRefWdbeMModule == 0);
		args.push_back(a);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a && b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a && b);
		a = args.back(); args.pop_back();
		args.push_back(!a);
		if (args.back()) {
			ixWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMOD;
		} else {
			dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMCT;
			dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMIB;
			ixWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMTP;
		};

		dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMOD;
		dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMTP;
		args.clear();
	};

	if ((dneIxWSubset & TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMTP) == 0) {
		a = false; a = (rec->hkIxVTbl == VecWdbeVMModuleHkTbl::VOID);
		args.push_back(a);
		a = false; a = (rec->supRefWdbeMModule == 0);
		args.push_back(a);
		a = false; a = (rec->tplRefWdbeMModule == 0);
		args.push_back(a);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a && b);
		b = args.back(); args.pop_back();
		a = args.back(); args.pop_back();
		args.push_back(a && b);
		if (args.back()) {
			ixWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMTP;
			dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMCT;
			dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMIB;
		} else {
			ixWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMOD;
		};

		dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMTP;
		dneIxWSubset |= TblWdbeMModule::VecWSubset::SBSWDBEBMMODULEMOD;
		args.clear();
	};

	return ixWSubset;
};

uint DbsWdbe::getIxWSubsetByRefWdbeMUnit(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	WdbeMUnit* rec = NULL;

	if (tblwdbemunit->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByWdbeMUnit(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsWdbe::getIxWSubsetByWdbeMUnit(
			WdbeMUnit* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblWdbeMUnit::VecWSubset::SBSWDBEBMUNITSIL) == 0) {
		a = false; a = (rec->silRefWdbeMUnit == 0);
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblWdbeMUnit::VecWSubset::SBSWDBEBMUNITSIL;
		} else {
			ixWSubset |= TblWdbeMUnit::VecWSubset::SBSWDBEBMUNITUNI;
		};

		dneIxWSubset |= TblWdbeMUnit::VecWSubset::SBSWDBEBMUNITSIL;
		dneIxWSubset |= TblWdbeMUnit::VecWSubset::SBSWDBEBMUNITUNI;
		args.clear();
	};

	if ((dneIxWSubset & TblWdbeMUnit::VecWSubset::SBSWDBEBMUNITUNI) == 0) {
		a = false; a = (rec->silRefWdbeMUnit == 0);
		args.push_back(a);
		a = args.back(); args.pop_back();
		args.push_back(!a);
		if (args.back()) {
			ixWSubset |= TblWdbeMUnit::VecWSubset::SBSWDBEBMUNITUNI;
		} else {
			ixWSubset |= TblWdbeMUnit::VecWSubset::SBSWDBEBMUNITSIL;
		};

		dneIxWSubset |= TblWdbeMUnit::VecWSubset::SBSWDBEBMUNITUNI;
		dneIxWSubset |= TblWdbeMUnit::VecWSubset::SBSWDBEBMUNITSIL;
		args.clear();
	};

	return ixWSubset;
};

void DbsWdbe::fillFeedFromKlst(
			const uint klsIxWdbeVKeylist
			, const uint ixWdbeVLocale
			, Feed& feed
		) {
	ListWdbeAVKeylistKey klsAkeys;
	WdbeAVKeylistKey* klsAkey = NULL;

	tblwdbeavkeylistkey->loadRstByKls(klsIxWdbeVKeylist, false, klsAkeys);

	feed.clear();
	for (unsigned int i = 0; i < klsAkeys.nodes.size(); i++) {
		klsAkey = klsAkeys.nodes[i];

		tblwdbejavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixWdbeVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

void DbsWdbe::fillFeedFromKlstByMtbUref(
			const uint klsIxWdbeVKeylist
			, const uint x1IxWdbeVMaintable
			, const ubigint x1Uref
			, const uint ixWdbeVLocale
			, Feed& feed
		) {
	ListWdbeAVKeylistKey klsAkeys;
	WdbeAVKeylistKey* klsAkey = NULL;

	tblwdbeavkeylistkey->loadRstByKlsMtbUrf(klsIxWdbeVKeylist, x1IxWdbeVMaintable, x1Uref, false, klsAkeys);

	feed.clear();
	for (unsigned int i = 0; i < klsAkeys.nodes.size(); i++) {
		klsAkey = klsAkeys.nodes[i];

		tblwdbejavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixWdbeVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

string DbsWdbe::getKlstTitleBySref(
			const uint klsIxWdbeVKeylist
			, const string& sref
			, const uint ixWdbeVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblwdbeavkeylistkey->loadRefByKlsSrf(klsIxWdbeVKeylist, sref, refKlk))
		if (!tblwdbejavkeylistkey->loadTitByKlkLcl(refKlk, ixWdbeVLocale, retval))
			tblwdbeavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

string DbsWdbe::getKlstTitleByMtbUrefSref(
			const uint klsIxWdbeVKeylist
			, const uint x1IxWdbeVMaintable
			, const ubigint x1Uref
			, const string& sref
			, const uint ixWdbeVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblwdbeavkeylistkey->loadRefByKlsMtbUrfSrf(klsIxWdbeVKeylist, x1IxWdbeVMaintable, x1Uref, sref, refKlk))
		if (!tblwdbejavkeylistkey->loadTitByKlkLcl(refKlk, ixWdbeVLocale, retval))
			tblwdbeavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

void DbsWdbe::fillFeedFromVlst(
			const uint vlsIxWdbeVValuelist
			, const uint x1IxWdbeVLocale
			, Feed& feed
		) {
	ListWdbeAVValuelistVal vlsAvals;
	WdbeAVValuelistVal* vlsAval = NULL;

	tblwdbeavvaluelistval->loadRstByVlsLcl(vlsIxWdbeVValuelist, x1IxWdbeVLocale, false, vlsAvals);

	feed.clear();
	for (unsigned int i = 0; i < vlsAvals.nodes.size(); i++) {
		vlsAval = vlsAvals.nodes[i];

		feed.appendTitles(vlsAval->Val);
	};
};
