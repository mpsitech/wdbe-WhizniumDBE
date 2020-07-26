-- CREATE ROLE mpsitech LOGIN
-- 	UNENCRYPTED PASSWORD 'asdf1234'
-- 	NOSUPERUSER INHERIT NOCREATEDB NOCREATEROLE;
-- COMMENT ON ROLE mpsitech IS 'MPSI Technologies GmbH';

CREATE DATABASE "DbsWdbe"
	WITH ENCODING='UTF8'
	OWNER = mpsitech
	CONNECTION LIMIT = -1;

DROP TABLE IF EXISTS TblWdbeAccRMUserUniversal;
DROP TABLE IF EXISTS TblWdbeAMCommandInvpar;
DROP TABLE IF EXISTS TblWdbeAMCommandRetpar;
DROP TABLE IF EXISTS TblWdbeAMCoreversionIp;
DROP TABLE IF EXISTS TblWdbeAMCoreversionPlh;
DROP TABLE IF EXISTS TblWdbeAMErrorPar;
DROP TABLE IF EXISTS TblWdbeAMFsmstateStep;
DROP TABLE IF EXISTS TblWdbeAMLibraryMakefile;
DROP TABLE IF EXISTS TblWdbeAMMachineMakefile;
DROP TABLE IF EXISTS TblWdbeAMMachinePar;
DROP TABLE IF EXISTS TblWdbeAMModulePar;
DROP TABLE IF EXISTS TblWdbeAMPeripheralPar;
DROP TABLE IF EXISTS TblWdbeAMPersonDetail;
DROP TABLE IF EXISTS TblWdbeAMPinPar;
DROP TABLE IF EXISTS TblWdbeAMUserAccess;
DROP TABLE IF EXISTS TblWdbeAMUsergroupAccess;
DROP TABLE IF EXISTS TblWdbeAVControlPar;
DROP TABLE IF EXISTS TblWdbeAVKeylistKey;
DROP TABLE IF EXISTS TblWdbeAVValuelistVal;
DROP SEQUENCE IF EXISTS TblWdbeCFile;
DROP SEQUENCE IF EXISTS TblWdbeCFsmstate;
DROP SEQUENCE IF EXISTS TblWdbeCGeneric;
DROP SEQUENCE IF EXISTS TblWdbeCPin;
DROP SEQUENCE IF EXISTS TblWdbeCPort;
DROP SEQUENCE IF EXISTS TblWdbeCSignal;
DROP SEQUENCE IF EXISTS TblWdbeCVariable;
DROP TABLE IF EXISTS TblWdbeHistRMUserUniversal;
DROP TABLE IF EXISTS TblWdbeJAVKeylistKey;
DROP TABLE IF EXISTS TblWdbeJMCoreversionState;
DROP TABLE IF EXISTS TblWdbeJMPersonLastname;
DROP TABLE IF EXISTS TblWdbeJMPinSref;
DROP TABLE IF EXISTS TblWdbeJMUserState;
DROP TABLE IF EXISTS TblWdbeJMVersionState;
DROP TABLE IF EXISTS TblWdbeMBank;
DROP TABLE IF EXISTS TblWdbeMCommand;
DROP TABLE IF EXISTS TblWdbeMController;
DROP TABLE IF EXISTS TblWdbeMCoreproject;
DROP TABLE IF EXISTS TblWdbeMCoreversion;
DROP TABLE IF EXISTS TblWdbeMError;
DROP TABLE IF EXISTS TblWdbeMFamily;
DROP TABLE IF EXISTS TblWdbeMFile;
DROP TABLE IF EXISTS TblWdbeMFsm;
DROP TABLE IF EXISTS TblWdbeMFsmstate;
DROP TABLE IF EXISTS TblWdbeMGeneric;
DROP TABLE IF EXISTS TblWdbeMImbuf;
DROP TABLE IF EXISTS TblWdbeMLibrary;
DROP TABLE IF EXISTS TblWdbeMMachine;
DROP TABLE IF EXISTS TblWdbeMModule;
DROP TABLE IF EXISTS TblWdbeMPeripheral;
DROP TABLE IF EXISTS TblWdbeMPerson;
DROP TABLE IF EXISTS TblWdbeMPin;
DROP TABLE IF EXISTS TblWdbeMPort;
DROP TABLE IF EXISTS TblWdbeMProcess;
DROP TABLE IF EXISTS TblWdbeMProject;
DROP TABLE IF EXISTS TblWdbeMRelease;
DROP TABLE IF EXISTS TblWdbeMSession;
DROP TABLE IF EXISTS TblWdbeMSignal;
DROP TABLE IF EXISTS TblWdbeMSystem;
DROP TABLE IF EXISTS TblWdbeMTarget;
DROP TABLE IF EXISTS TblWdbeMUnit;
DROP TABLE IF EXISTS TblWdbeMUser;
DROP TABLE IF EXISTS TblWdbeMUsergroup;
DROP TABLE IF EXISTS TblWdbeMVariable;
DROP TABLE IF EXISTS TblWdbeMVector;
DROP TABLE IF EXISTS TblWdbeMVectoritem;
DROP TABLE IF EXISTS TblWdbeMVersion;
DROP TABLE IF EXISTS TblWdbeRMCommandMController;
DROP TABLE IF EXISTS TblWdbeRMCoreprojectMPerson;
DROP TABLE IF EXISTS TblWdbeRMLibraryMVersion;
DROP TABLE IF EXISTS TblWdbeRMPersonMProject;
DROP TABLE IF EXISTS TblWdbeRMUsergroupUniversal;
DROP TABLE IF EXISTS TblWdbeRMUserMUsergroup;

DROP TABLE IF EXISTS TblWdbeQBnk1NPin;
DROP TABLE IF EXISTS TblWdbeQBnkList;
DROP TABLE IF EXISTS TblWdbeQCmdAInvpar;
DROP TABLE IF EXISTS TblWdbeQCmdARetpar;
DROP TABLE IF EXISTS TblWdbeQCmdList;
DROP TABLE IF EXISTS TblWdbeQCmdMNController;
DROP TABLE IF EXISTS TblWdbeQCpr1NCoreversion;
DROP TABLE IF EXISTS TblWdbeQCprList;
DROP TABLE IF EXISTS TblWdbeQCprMNPerson;
DROP TABLE IF EXISTS TblWdbeQCvrAIp;
DROP TABLE IF EXISTS TblWdbeQCvrAPlh;
DROP TABLE IF EXISTS TblWdbeQCvrBcv1NCoreversion;
DROP TABLE IF EXISTS TblWdbeQCvrHk1NModule;
DROP TABLE IF EXISTS TblWdbeQCvrList;
DROP TABLE IF EXISTS TblWdbeQErrAPar;
DROP TABLE IF EXISTS TblWdbeQErrList;
DROP TABLE IF EXISTS TblWdbeQFam1NUnit;
DROP TABLE IF EXISTS TblWdbeQFamList;
DROP TABLE IF EXISTS TblWdbeQFilList;
DROP TABLE IF EXISTS TblWdbeQFstAStep;
DROP TABLE IF EXISTS TblWdbeQFstList;
DROP TABLE IF EXISTS TblWdbeQGenList;
DROP TABLE IF EXISTS TblWdbeQLibAMakefile;
DROP TABLE IF EXISTS TblWdbeQLibList;
DROP TABLE IF EXISTS TblWdbeQLibMNVersion;
DROP TABLE IF EXISTS TblWdbeQMch1NRelease;
DROP TABLE IF EXISTS TblWdbeQMchAMakefile;
DROP TABLE IF EXISTS TblWdbeQMchAPar;
DROP TABLE IF EXISTS TblWdbeQMchList;
DROP TABLE IF EXISTS TblWdbeQMod1NPeripheral;
DROP TABLE IF EXISTS TblWdbeQMod1NProcess;
DROP TABLE IF EXISTS TblWdbeQModAPar;
DROP TABLE IF EXISTS TblWdbeQModCor1NImbuf;
DROP TABLE IF EXISTS TblWdbeQModCtrHk1NVector;
DROP TABLE IF EXISTS TblWdbeQModCtrMNCommand;
DROP TABLE IF EXISTS TblWdbeQModCtrRef1NCommand;
DROP TABLE IF EXISTS TblWdbeQModCtrRef1NError;
DROP TABLE IF EXISTS TblWdbeQModKHdltype;
DROP TABLE IF EXISTS TblWdbeQModList;
DROP TABLE IF EXISTS TblWdbeQModMdl1NGeneric;
DROP TABLE IF EXISTS TblWdbeQModMdl1NPort;
DROP TABLE IF EXISTS TblWdbeQModMdl1NSignal;
DROP TABLE IF EXISTS TblWdbeQModMge1NSignal;
DROP TABLE IF EXISTS TblWdbeQModSup1NModule;
DROP TABLE IF EXISTS TblWdbeQMtpAPar;
DROP TABLE IF EXISTS TblWdbeQMtpKHdltype;
DROP TABLE IF EXISTS TblWdbeQMtpKParKey;
DROP TABLE IF EXISTS TblWdbeQMtpList;
DROP TABLE IF EXISTS TblWdbeQMtpMdl1NGeneric;
DROP TABLE IF EXISTS TblWdbeQMtpMdl1NPort;
DROP TABLE IF EXISTS TblWdbeQMtpMge1NSignal;
DROP TABLE IF EXISTS TblWdbeQMtpRef1NFile;
DROP TABLE IF EXISTS TblWdbeQMtpSup1NModule;
DROP TABLE IF EXISTS TblWdbeQMtpTpl1NModule;
DROP TABLE IF EXISTS TblWdbeQPinAPar;
DROP TABLE IF EXISTS TblWdbeQPinList;
DROP TABLE IF EXISTS TblWdbeQPphAPar;
DROP TABLE IF EXISTS TblWdbeQPphList;
DROP TABLE IF EXISTS TblWdbeQPrcFsmFsm1NFsmstate;
DROP TABLE IF EXISTS TblWdbeQPrcKHdltype;
DROP TABLE IF EXISTS TblWdbeQPrcList;
DROP TABLE IF EXISTS TblWdbeQPrcMge1NSignal;
DROP TABLE IF EXISTS TblWdbeQPrcPrc1NVariable;
DROP TABLE IF EXISTS TblWdbeQPreselect;
DROP TABLE IF EXISTS TblWdbeQPrj1NVersion;
DROP TABLE IF EXISTS TblWdbeQPrjList;
DROP TABLE IF EXISTS TblWdbeQPrjMNPerson;
DROP TABLE IF EXISTS TblWdbeQPrsADetail;
DROP TABLE IF EXISTS TblWdbeQPrsList;
DROP TABLE IF EXISTS TblWdbeQPrsMNCoreproject;
DROP TABLE IF EXISTS TblWdbeQPrsMNProject;
DROP TABLE IF EXISTS TblWdbeQPrtList;
DROP TABLE IF EXISTS TblWdbeQRlsList;
DROP TABLE IF EXISTS TblWdbeQSelect;
DROP TABLE IF EXISTS TblWdbeQSigList;
DROP TABLE IF EXISTS TblWdbeQSil1NBank;
DROP TABLE IF EXISTS TblWdbeQSil1NPeripheral;
DROP TABLE IF EXISTS TblWdbeQSil1NTarget;
DROP TABLE IF EXISTS TblWdbeQSilFwd1NController;
DROP TABLE IF EXISTS TblWdbeQSilHk1NModule;
DROP TABLE IF EXISTS TblWdbeQSilHk1NVector;
DROP TABLE IF EXISTS TblWdbeQSilList;
DROP TABLE IF EXISTS TblWdbeQSilRef1NCommand;
DROP TABLE IF EXISTS TblWdbeQSilRef1NError;
DROP TABLE IF EXISTS TblWdbeQSilSil1NUnit;
DROP TABLE IF EXISTS TblWdbeQSysHk1NVector;
DROP TABLE IF EXISTS TblWdbeQSysList;
DROP TABLE IF EXISTS TblWdbeQSysSys1NTarget;
DROP TABLE IF EXISTS TblWdbeQTrgList;
DROP TABLE IF EXISTS TblWdbeQUnt1NBank;
DROP TABLE IF EXISTS TblWdbeQUnt1NPeripheral;
DROP TABLE IF EXISTS TblWdbeQUnt1NTarget;
DROP TABLE IF EXISTS TblWdbeQUntFwd1NController;
DROP TABLE IF EXISTS TblWdbeQUntHk1NModule;
DROP TABLE IF EXISTS TblWdbeQUntHk1NVector;
DROP TABLE IF EXISTS TblWdbeQUntList;
DROP TABLE IF EXISTS TblWdbeQUntRef1NCommand;
DROP TABLE IF EXISTS TblWdbeQUntRef1NError;
DROP TABLE IF EXISTS TblWdbeQUntSil1NUnit;
DROP TABLE IF EXISTS TblWdbeQUsgAAccess;
DROP TABLE IF EXISTS TblWdbeQUsgList;
DROP TABLE IF EXISTS TblWdbeQUsgMNUser;
DROP TABLE IF EXISTS TblWdbeQUsr1NSession;
DROP TABLE IF EXISTS TblWdbeQUsrAAccess;
DROP TABLE IF EXISTS TblWdbeQUsrList;
DROP TABLE IF EXISTS TblWdbeQUsrMNUsergroup;
DROP TABLE IF EXISTS TblWdbeQVarList;
DROP TABLE IF EXISTS TblWdbeQVecList;
DROP TABLE IF EXISTS TblWdbeQVecVec1NVectoritem;
DROP TABLE IF EXISTS TblWdbeQVer1NRelease;
DROP TABLE IF EXISTS TblWdbeQVer1NSystem;
DROP TABLE IF EXISTS TblWdbeQVer1NUnit;
DROP TABLE IF EXISTS TblWdbeQVerBvr1NVersion;
DROP TABLE IF EXISTS TblWdbeQVerList;
DROP TABLE IF EXISTS TblWdbeQVerMNLibrary;
DROP TABLE IF EXISTS TblWdbeQVerRef1NFile;
DROP TABLE IF EXISTS TblWdbeQVitList;

CREATE TABLE TblWdbeAccRMUserUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMUser BIGINT,
	unvIxWdbeVMaintable INT,
	unvUref BIGINT,
	ixWdbeVRecaccess INT
);
ALTER TABLE TblWdbeAccRMUserUniversal OWNER TO epsi;
CREATE INDEX TblWdbeAccRMUserUniversal_refWdbeMUser ON TblWdbeAccRMUserUniversal (refWdbeMUser);
CREATE INDEX TblWdbeAccRMUserUniversal_unvIxWdbeVMaintable ON TblWdbeAccRMUserUniversal (unvIxWdbeVMaintable);
CREATE INDEX TblWdbeAccRMUserUniversal_unvUref ON TblWdbeAccRMUserUniversal (unvUref);

CREATE TABLE TblWdbeAMCommandInvpar(
	ref BIGSERIAL PRIMARY KEY,
	cmdRefWdbeMCommand BIGINT,
	cmdNum INT,
	sref VARCHAR(50),
	ixWdbeVPartype INT,
	refWdbeMVector BIGINT,
	Length SMALLINT,
	Defval TEXT,
	refWdbeMVectoritem BIGINT,
	Comment TEXT
);
ALTER TABLE TblWdbeAMCommandInvpar OWNER TO epsi;
CREATE INDEX TblWdbeAMCommandInvpar_cmdRefWdbeMCommand ON TblWdbeAMCommandInvpar (cmdRefWdbeMCommand);
CREATE INDEX TblWdbeAMCommandInvpar_cmdNum ON TblWdbeAMCommandInvpar (cmdNum);
CREATE INDEX TblWdbeAMCommandInvpar_sref ON TblWdbeAMCommandInvpar (sref);

CREATE TABLE TblWdbeAMCommandRetpar(
	ref BIGSERIAL PRIMARY KEY,
	cmdRefWdbeMCommand BIGINT,
	cmdNum INT,
	sref VARCHAR(50),
	ixWdbeVPartype INT,
	refWdbeMVector BIGINT,
	Length SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWdbeAMCommandRetpar OWNER TO epsi;
CREATE INDEX TblWdbeAMCommandRetpar_cmdRefWdbeMCommand ON TblWdbeAMCommandRetpar (cmdRefWdbeMCommand);
CREATE INDEX TblWdbeAMCommandRetpar_cmdNum ON TblWdbeAMCommandRetpar (cmdNum);
CREATE INDEX TblWdbeAMCommandRetpar_sref ON TblWdbeAMCommandRetpar (sref);

CREATE TABLE TblWdbeAMCoreversionIp(
	ref BIGSERIAL PRIMARY KEY,
	cvrRefWdbeMCoreversion BIGINT,
	cvrNum INT,
	sref VARCHAR(50),
	ixVTagtype INT,
	Comment TEXT
);
ALTER TABLE TblWdbeAMCoreversionIp OWNER TO epsi;
CREATE INDEX TblWdbeAMCoreversionIp_cvrRefWdbeMCoreversion ON TblWdbeAMCoreversionIp (cvrRefWdbeMCoreversion);
CREATE INDEX TblWdbeAMCoreversionIp_cvrNum ON TblWdbeAMCoreversionIp (cvrNum);
CREATE INDEX TblWdbeAMCoreversionIp_sref ON TblWdbeAMCoreversionIp (sref);

CREATE TABLE TblWdbeAMCoreversionPlh(
	ref BIGSERIAL PRIMARY KEY,
	cvrRefWdbeMCoreversion BIGINT,
	cvrNum INT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWdbeAMCoreversionPlh OWNER TO epsi;
CREATE INDEX TblWdbeAMCoreversionPlh_cvrRefWdbeMCoreversion ON TblWdbeAMCoreversionPlh (cvrRefWdbeMCoreversion);
CREATE INDEX TblWdbeAMCoreversionPlh_cvrNum ON TblWdbeAMCoreversionPlh (cvrNum);
CREATE INDEX TblWdbeAMCoreversionPlh_sref ON TblWdbeAMCoreversionPlh (sref);

CREATE TABLE TblWdbeAMErrorPar(
	ref BIGSERIAL PRIMARY KEY,
	errRefWdbeMError BIGINT,
	errNum INT,
	sref VARCHAR(50),
	ixWdbeVPartype INT,
	refWdbeMVector BIGINT,
	Length SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWdbeAMErrorPar OWNER TO epsi;
CREATE INDEX TblWdbeAMErrorPar_errRefWdbeMError ON TblWdbeAMErrorPar (errRefWdbeMError);
CREATE INDEX TblWdbeAMErrorPar_errNum ON TblWdbeAMErrorPar (errNum);
CREATE INDEX TblWdbeAMErrorPar_sref ON TblWdbeAMErrorPar (sref);

CREATE TABLE TblWdbeAMFsmstateStep(
	ref BIGSERIAL PRIMARY KEY,
	fstRefWdbeMFsmstate BIGINT,
	fstNum INT,
	fnxRefWdbeMFsmstate BIGINT,
	Cond1 TEXT,
	Ip1 VARCHAR(50),
	Cond2 TEXT,
	Ip2 VARCHAR(50),
	Cond3 TEXT,
	Ip3 VARCHAR(50),
	Cond4 TEXT,
	Ip4 VARCHAR(50)
);
ALTER TABLE TblWdbeAMFsmstateStep OWNER TO epsi;
CREATE INDEX TblWdbeAMFsmstateStep_fstRefWdbeMFsmstate ON TblWdbeAMFsmstateStep (fstRefWdbeMFsmstate);
CREATE INDEX TblWdbeAMFsmstateStep_fstNum ON TblWdbeAMFsmstateStep (fstNum);

CREATE TABLE TblWdbeAMLibraryMakefile(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMLibrary BIGINT,
	x1RefWdbeMMachine BIGINT,
	x2SrefKTag VARCHAR(50),
	Val TEXT
);
ALTER TABLE TblWdbeAMLibraryMakefile OWNER TO epsi;
CREATE INDEX TblWdbeAMLibraryMakefile_refWdbeMLibrary ON TblWdbeAMLibraryMakefile (refWdbeMLibrary);
CREATE INDEX TblWdbeAMLibraryMakefile_x1RefWdbeMMachine ON TblWdbeAMLibraryMakefile (x1RefWdbeMMachine);
CREATE INDEX TblWdbeAMLibraryMakefile_x2SrefKTag ON TblWdbeAMLibraryMakefile (x2SrefKTag);

CREATE TABLE TblWdbeAMMachineMakefile(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMMachine BIGINT,
	x1SrefKTag VARCHAR(50),
	Val TEXT
);
ALTER TABLE TblWdbeAMMachineMakefile OWNER TO epsi;
CREATE INDEX TblWdbeAMMachineMakefile_refWdbeMMachine ON TblWdbeAMMachineMakefile (refWdbeMMachine);
CREATE INDEX TblWdbeAMMachineMakefile_x1SrefKTag ON TblWdbeAMMachineMakefile (x1SrefKTag);

CREATE TABLE TblWdbeAMMachinePar(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMMachine BIGINT,
	x1SrefKKey VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeAMMachinePar OWNER TO epsi;
CREATE INDEX TblWdbeAMMachinePar_refWdbeMMachine ON TblWdbeAMMachinePar (refWdbeMMachine);
CREATE INDEX TblWdbeAMMachinePar_x1SrefKKey ON TblWdbeAMMachinePar (x1SrefKKey);

CREATE TABLE TblWdbeAMModulePar(
	ref BIGSERIAL PRIMARY KEY,
	mdlRefWdbeMModule BIGINT,
	mdlNum INT,
	x1SrefKKey VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeAMModulePar OWNER TO epsi;
CREATE INDEX TblWdbeAMModulePar_mdlRefWdbeMModule ON TblWdbeAMModulePar (mdlRefWdbeMModule);
CREATE INDEX TblWdbeAMModulePar_mdlNum ON TblWdbeAMModulePar (mdlNum);
CREATE INDEX TblWdbeAMModulePar_x1SrefKKey ON TblWdbeAMModulePar (x1SrefKKey);

CREATE TABLE TblWdbeAMPeripheralPar(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMPeripheral BIGINT,
	x1SrefKKey VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeAMPeripheralPar OWNER TO epsi;
CREATE INDEX TblWdbeAMPeripheralPar_refWdbeMPeripheral ON TblWdbeAMPeripheralPar (refWdbeMPeripheral);
CREATE INDEX TblWdbeAMPeripheralPar_x1SrefKKey ON TblWdbeAMPeripheralPar (x1SrefKKey);

CREATE TABLE TblWdbeAMPersonDetail(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMPerson BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeAMPersonDetail OWNER TO epsi;
CREATE INDEX TblWdbeAMPersonDetail_refWdbeMPerson ON TblWdbeAMPersonDetail (refWdbeMPerson);

CREATE TABLE TblWdbeAMPinPar(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMPin BIGINT,
	x1SrefKKey VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeAMPinPar OWNER TO epsi;
CREATE INDEX TblWdbeAMPinPar_refWdbeMPin ON TblWdbeAMPinPar (refWdbeMPin);
CREATE INDEX TblWdbeAMPinPar_x1SrefKKey ON TblWdbeAMPinPar (x1SrefKKey);

CREATE TABLE TblWdbeAMUserAccess(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMUser BIGINT,
	x1IxWdbeVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWdbeWAccess INT
);
ALTER TABLE TblWdbeAMUserAccess OWNER TO epsi;
CREATE INDEX TblWdbeAMUserAccess_refWdbeMUser ON TblWdbeAMUserAccess (refWdbeMUser);
CREATE INDEX TblWdbeAMUserAccess_x1IxWdbeVFeatgroup ON TblWdbeAMUserAccess (x1IxWdbeVFeatgroup);
CREATE INDEX TblWdbeAMUserAccess_x2FeaSrefUix ON TblWdbeAMUserAccess (x2FeaSrefUix);

CREATE TABLE TblWdbeAMUsergroupAccess(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMUsergroup BIGINT,
	x1IxWdbeVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWdbeWAccess INT
);
ALTER TABLE TblWdbeAMUsergroupAccess OWNER TO epsi;
CREATE INDEX TblWdbeAMUsergroupAccess_refWdbeMUsergroup ON TblWdbeAMUsergroupAccess (refWdbeMUsergroup);
CREATE INDEX TblWdbeAMUsergroupAccess_x1IxWdbeVFeatgroup ON TblWdbeAMUsergroupAccess (x1IxWdbeVFeatgroup);
CREATE INDEX TblWdbeAMUsergroupAccess_x2FeaSrefUix ON TblWdbeAMUsergroupAccess (x2FeaSrefUix);

CREATE TABLE TblWdbeAVControlPar(
	ref BIGSERIAL PRIMARY KEY,
	ixWdbeVControl INT,
	x1RefWdbeMUser BIGINT,
	x2IxWdbeVLocale INT,
	Par VARCHAR(192),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeAVControlPar OWNER TO epsi;
CREATE INDEX TblWdbeAVControlPar_ixWdbeVControl ON TblWdbeAVControlPar (ixWdbeVControl);
CREATE INDEX TblWdbeAVControlPar_x1RefWdbeMUser ON TblWdbeAVControlPar (x1RefWdbeMUser);
CREATE INDEX TblWdbeAVControlPar_x2IxWdbeVLocale ON TblWdbeAVControlPar (x2IxWdbeVLocale);
CREATE INDEX TblWdbeAVControlPar_Par ON TblWdbeAVControlPar (Par);

CREATE TABLE TblWdbeAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
	klsIxWdbeVKeylist INT,
	klsNum INT,
	x1IxWdbeVMaintable INT,
	x1Uref BIGINT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeAVKeylistKey OWNER TO epsi;
CREATE INDEX TblWdbeAVKeylistKey_klsIxWdbeVKeylist ON TblWdbeAVKeylistKey (klsIxWdbeVKeylist);
CREATE INDEX TblWdbeAVKeylistKey_klsNum ON TblWdbeAVKeylistKey (klsNum);
CREATE INDEX TblWdbeAVKeylistKey_x1IxWdbeVMaintable ON TblWdbeAVKeylistKey (x1IxWdbeVMaintable);
CREATE INDEX TblWdbeAVKeylistKey_x1Uref ON TblWdbeAVKeylistKey (x1Uref);
CREATE INDEX TblWdbeAVKeylistKey_sref ON TblWdbeAVKeylistKey (sref);

CREATE TABLE TblWdbeAVValuelistVal(
	ref BIGSERIAL PRIMARY KEY,
	vlsIxWdbeVValuelist INT,
	vlsNum INT,
	x1IxWdbeVLocale INT,
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeAVValuelistVal OWNER TO epsi;
CREATE INDEX TblWdbeAVValuelistVal_vlsIxWdbeVValuelist ON TblWdbeAVValuelistVal (vlsIxWdbeVValuelist);
CREATE INDEX TblWdbeAVValuelistVal_vlsNum ON TblWdbeAVValuelistVal (vlsNum);
CREATE INDEX TblWdbeAVValuelistVal_x1IxWdbeVLocale ON TblWdbeAVValuelistVal (x1IxWdbeVLocale);

CREATE SEQUENCE TblWdbeCFile INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWdbeCFile OWNER TO epsi;

CREATE SEQUENCE TblWdbeCFsmstate INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWdbeCFsmstate OWNER TO epsi;

CREATE SEQUENCE TblWdbeCGeneric INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWdbeCGeneric OWNER TO epsi;

CREATE SEQUENCE TblWdbeCPin INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWdbeCPin OWNER TO epsi;

CREATE SEQUENCE TblWdbeCPort INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWdbeCPort OWNER TO epsi;

CREATE SEQUENCE TblWdbeCSignal INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWdbeCSignal OWNER TO epsi;

CREATE SEQUENCE TblWdbeCVariable INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblWdbeCVariable OWNER TO epsi;

CREATE TABLE TblWdbeHistRMUserUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMUser BIGINT,
	unvIxWdbeVMaintable INT,
	unvUref BIGINT,
	ixWdbeVCard INT,
	ixWdbeVPreset INT,
	preIxWdbeVMaintable INT,
	preUref BIGINT,
	start INT
);
ALTER TABLE TblWdbeHistRMUserUniversal OWNER TO epsi;
CREATE INDEX TblWdbeHistRMUserUniversal_refWdbeMUser ON TblWdbeHistRMUserUniversal (refWdbeMUser);
CREATE INDEX TblWdbeHistRMUserUniversal_unvIxWdbeVMaintable ON TblWdbeHistRMUserUniversal (unvIxWdbeVMaintable);
CREATE INDEX TblWdbeHistRMUserUniversal_unvUref ON TblWdbeHistRMUserUniversal (unvUref);
CREATE INDEX TblWdbeHistRMUserUniversal_ixWdbeVCard ON TblWdbeHistRMUserUniversal (ixWdbeVCard);
CREATE INDEX TblWdbeHistRMUserUniversal_ixWdbeVPreset ON TblWdbeHistRMUserUniversal (ixWdbeVPreset);
CREATE INDEX TblWdbeHistRMUserUniversal_preIxWdbeVMaintable ON TblWdbeHistRMUserUniversal (preIxWdbeVMaintable);
CREATE INDEX TblWdbeHistRMUserUniversal_preUref ON TblWdbeHistRMUserUniversal (preUref);

CREATE TABLE TblWdbeJAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeAVKeylistKey BIGINT,
	x1IxWdbeVLocale INT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeJAVKeylistKey OWNER TO epsi;
CREATE INDEX TblWdbeJAVKeylistKey_refWdbeAVKeylistKey ON TblWdbeJAVKeylistKey (refWdbeAVKeylistKey);
CREATE INDEX TblWdbeJAVKeylistKey_x1IxWdbeVLocale ON TblWdbeJAVKeylistKey (x1IxWdbeVLocale);

CREATE TABLE TblWdbeJMCoreversionState(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMCoreversion BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblWdbeJMCoreversionState OWNER TO epsi;
CREATE INDEX TblWdbeJMCoreversionState_refWdbeMCoreversion ON TblWdbeJMCoreversionState (refWdbeMCoreversion);
CREATE INDEX TblWdbeJMCoreversionState_x1Start ON TblWdbeJMCoreversionState (x1Start);

CREATE TABLE TblWdbeJMPersonLastname(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMPerson BIGINT,
	x1Startd INT,
	Lastname VARCHAR(50)
);
ALTER TABLE TblWdbeJMPersonLastname OWNER TO epsi;
CREATE INDEX TblWdbeJMPersonLastname_refWdbeMPerson ON TblWdbeJMPersonLastname (refWdbeMPerson);
CREATE INDEX TblWdbeJMPersonLastname_x1Startd ON TblWdbeJMPersonLastname (x1Startd);
CREATE INDEX TblWdbeJMPersonLastname_Lastname ON TblWdbeJMPersonLastname (Lastname);

CREATE TABLE TblWdbeJMPinSref(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMPin BIGINT,
	x1RefWdbeMPeripheral BIGINT,
	sref VARCHAR(50)
);
ALTER TABLE TblWdbeJMPinSref OWNER TO epsi;
CREATE INDEX TblWdbeJMPinSref_refWdbeMPin ON TblWdbeJMPinSref (refWdbeMPin);
CREATE INDEX TblWdbeJMPinSref_x1RefWdbeMPeripheral ON TblWdbeJMPinSref (x1RefWdbeMPeripheral);
CREATE INDEX TblWdbeJMPinSref_sref ON TblWdbeJMPinSref (sref);

CREATE TABLE TblWdbeJMUserState(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMUser BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblWdbeJMUserState OWNER TO epsi;
CREATE INDEX TblWdbeJMUserState_refWdbeMUser ON TblWdbeJMUserState (refWdbeMUser);
CREATE INDEX TblWdbeJMUserState_x1Start ON TblWdbeJMUserState (x1Start);

CREATE TABLE TblWdbeJMVersionState(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMVersion BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblWdbeJMVersionState OWNER TO epsi;
CREATE INDEX TblWdbeJMVersionState_refWdbeMVersion ON TblWdbeJMVersionState (refWdbeMVersion);
CREATE INDEX TblWdbeJMVersionState_x1Start ON TblWdbeJMVersionState (x1Start);

CREATE TABLE TblWdbeMBank(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMUnit BIGINT,
	sref VARCHAR(50),
	srefKVoltstd VARCHAR(50)
);
ALTER TABLE TblWdbeMBank OWNER TO epsi;
CREATE INDEX TblWdbeMBank_refWdbeMUnit ON TblWdbeMBank (refWdbeMUnit);
CREATE INDEX TblWdbeMBank_sref ON TblWdbeMBank (sref);

CREATE TABLE TblWdbeMCommand(
	ref BIGSERIAL PRIMARY KEY,
	refIxVTbl INT,
	refUref BIGINT,
	refNum INT,
	sref VARCHAR(50),
	Fullsref VARCHAR(50),
	ixVRettype INT,
	ivrRefWdbeMSignal BIGINT,
	rvrRefWdbeMSignal BIGINT,
	rerRefWdbeMSignal BIGINT,
	Comment TEXT
);
ALTER TABLE TblWdbeMCommand OWNER TO epsi;
CREATE INDEX TblWdbeMCommand_refIxVTbl ON TblWdbeMCommand (refIxVTbl);
CREATE INDEX TblWdbeMCommand_refUref ON TblWdbeMCommand (refUref);
CREATE INDEX TblWdbeMCommand_refNum ON TblWdbeMCommand (refNum);
CREATE INDEX TblWdbeMCommand_sref ON TblWdbeMCommand (sref);

CREATE TABLE TblWdbeMController(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMModule BIGINT,
	fwdRefWdbeMUnit BIGINT,
	Fullsref VARCHAR(50),
	clrRefWdbeMSignal BIGINT
);
ALTER TABLE TblWdbeMController OWNER TO epsi;
CREATE INDEX TblWdbeMController_refWdbeMModule ON TblWdbeMController (refWdbeMModule);
CREATE INDEX TblWdbeMController_fwdRefWdbeMUnit ON TblWdbeMController (fwdRefWdbeMUnit);

CREATE TABLE TblWdbeMCoreproject(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	ixVBasetype INT,
	refWdbeMCoreversion BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	Giturl VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeMCoreproject OWNER TO epsi;
CREATE INDEX TblWdbeMCoreproject_grp ON TblWdbeMCoreproject (grp);
CREATE INDEX TblWdbeMCoreproject_own ON TblWdbeMCoreproject (own);
CREATE INDEX TblWdbeMCoreproject_ixVBasetype ON TblWdbeMCoreproject (ixVBasetype);
CREATE INDEX TblWdbeMCoreproject_refWdbeMCoreversion ON TblWdbeMCoreproject (refWdbeMCoreversion);
CREATE INDEX TblWdbeMCoreproject_sref ON TblWdbeMCoreproject (sref);
CREATE INDEX TblWdbeMCoreproject_Title ON TblWdbeMCoreproject (Title);

CREATE TABLE TblWdbeMCoreversion(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refWdbeMCoreproject BIGINT,
	bcvRefWdbeMCoreversion BIGINT,
	refWdbeMModule BIGINT,
	Major SMALLINT,
	Minor SMALLINT,
	Sub SMALLINT,
	refJState BIGINT,
	ixVState INT,
	ixWSpectype INT
);
ALTER TABLE TblWdbeMCoreversion OWNER TO epsi;
CREATE INDEX TblWdbeMCoreversion_grp ON TblWdbeMCoreversion (grp);
CREATE INDEX TblWdbeMCoreversion_own ON TblWdbeMCoreversion (own);
CREATE INDEX TblWdbeMCoreversion_refWdbeMCoreproject ON TblWdbeMCoreversion (refWdbeMCoreproject);
CREATE INDEX TblWdbeMCoreversion_bcvRefWdbeMCoreversion ON TblWdbeMCoreversion (bcvRefWdbeMCoreversion);
CREATE INDEX TblWdbeMCoreversion_refWdbeMModule ON TblWdbeMCoreversion (refWdbeMModule);
CREATE INDEX TblWdbeMCoreversion_ixVState ON TblWdbeMCoreversion (ixVState);

CREATE TABLE TblWdbeMError(
	ref BIGSERIAL PRIMARY KEY,
	refIxVTbl INT,
	refUref BIGINT,
	refNum INT,
	sref VARCHAR(50),
	Fullsref VARCHAR(50),
	traRefWdbeMSignal BIGINT,
	Comment TEXT
);
ALTER TABLE TblWdbeMError OWNER TO epsi;
CREATE INDEX TblWdbeMError_refIxVTbl ON TblWdbeMError (refIxVTbl);
CREATE INDEX TblWdbeMError_refUref ON TblWdbeMError (refUref);
CREATE INDEX TblWdbeMError_refNum ON TblWdbeMError (refNum);
CREATE INDEX TblWdbeMError_sref ON TblWdbeMError (sref);

CREATE TABLE TblWdbeMFamily(
	ref BIGSERIAL PRIMARY KEY,
	srefKVendor VARCHAR(50),
	Title VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWdbeMFamily OWNER TO epsi;
CREATE INDEX TblWdbeMFamily_srefKVendor ON TblWdbeMFamily (srefKVendor);
CREATE INDEX TblWdbeMFamily_Title ON TblWdbeMFamily (Title);

CREATE TABLE TblWdbeMFile(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refWdbeCFile BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	Archived INT,
	Filename VARCHAR(50),
	Archivename VARCHAR(30),
	srefKMimetype VARCHAR(50),
	Size SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWdbeMFile OWNER TO epsi;
CREATE INDEX TblWdbeMFile_grp ON TblWdbeMFile (grp);
CREATE INDEX TblWdbeMFile_own ON TblWdbeMFile (own);
CREATE INDEX TblWdbeMFile_refWdbeCFile ON TblWdbeMFile (refWdbeCFile);
CREATE INDEX TblWdbeMFile_refIxVTbl ON TblWdbeMFile (refIxVTbl);
CREATE INDEX TblWdbeMFile_refUref ON TblWdbeMFile (refUref);
CREATE INDEX TblWdbeMFile_Filename ON TblWdbeMFile (Filename);

CREATE TABLE TblWdbeMFsm(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMProcess BIGINT
);
ALTER TABLE TblWdbeMFsm OWNER TO epsi;
CREATE INDEX TblWdbeMFsm_refWdbeMProcess ON TblWdbeMFsm (refWdbeMProcess);

CREATE TABLE TblWdbeMFsmstate(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeCFsmstate BIGINT,
	fsmRefWdbeMFsm BIGINT,
	fsmNum INT,
	sref VARCHAR(50),
	Extip SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWdbeMFsmstate OWNER TO epsi;
CREATE INDEX TblWdbeMFsmstate_refWdbeCFsmstate ON TblWdbeMFsmstate (refWdbeCFsmstate);
CREATE INDEX TblWdbeMFsmstate_fsmRefWdbeMFsm ON TblWdbeMFsmstate (fsmRefWdbeMFsm);
CREATE INDEX TblWdbeMFsmstate_fsmNum ON TblWdbeMFsmstate (fsmNum);
CREATE INDEX TblWdbeMFsmstate_sref ON TblWdbeMFsmstate (sref);

CREATE TABLE TblWdbeMGeneric(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeCGeneric BIGINT,
	mdlRefWdbeMModule BIGINT,
	mdlNum INT,
	sref VARCHAR(50),
	srefWdbeKHdltype VARCHAR(50),
	Width SMALLINT,
	Minmax VARCHAR(30),
	Defval TEXT,
	srcSrefWdbeMGeneric VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWdbeMGeneric OWNER TO epsi;
CREATE INDEX TblWdbeMGeneric_refWdbeCGeneric ON TblWdbeMGeneric (refWdbeCGeneric);
CREATE INDEX TblWdbeMGeneric_mdlRefWdbeMModule ON TblWdbeMGeneric (mdlRefWdbeMModule);
CREATE INDEX TblWdbeMGeneric_mdlNum ON TblWdbeMGeneric (mdlNum);
CREATE INDEX TblWdbeMGeneric_sref ON TblWdbeMGeneric (sref);

CREATE TABLE TblWdbeMImbuf(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMModule BIGINT,
	corRefWdbeMModule BIGINT,
	sref VARCHAR(50),
	ixVDir INT,
	Prio SMALLINT
);
ALTER TABLE TblWdbeMImbuf OWNER TO epsi;
CREATE INDEX TblWdbeMImbuf_refWdbeMModule ON TblWdbeMImbuf (refWdbeMModule);
CREATE INDEX TblWdbeMImbuf_corRefWdbeMModule ON TblWdbeMImbuf (corRefWdbeMModule);
CREATE INDEX TblWdbeMImbuf_sref ON TblWdbeMImbuf (sref);
CREATE INDEX TblWdbeMImbuf_Prio ON TblWdbeMImbuf (Prio);

CREATE TABLE TblWdbeMLibrary(
	ref BIGSERIAL PRIMARY KEY,
	sref VARCHAR(50),
	Title VARCHAR(50),
	Version VARCHAR(30),
	depSrefsWdbeMLibrary VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeMLibrary OWNER TO epsi;
CREATE INDEX TblWdbeMLibrary_sref ON TblWdbeMLibrary (sref);

CREATE TABLE TblWdbeMMachine(
	ref BIGSERIAL PRIMARY KEY,
	srefKPlatform VARCHAR(50),
	sref VARCHAR(50),
	cchRefWdbeMMachine BIGINT,
	Comment TEXT
);
ALTER TABLE TblWdbeMMachine OWNER TO epsi;
CREATE INDEX TblWdbeMMachine_srefKPlatform ON TblWdbeMMachine (srefKPlatform);
CREATE INDEX TblWdbeMMachine_sref ON TblWdbeMMachine (sref);

CREATE TABLE TblWdbeMModule(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	hkIxVTbl INT,
	hkUref BIGINT,
	hkNum INT,
	supRefWdbeMModule BIGINT,
	tplRefWdbeMModule BIGINT,
	refWdbeMController BIGINT,
	refWdbeMImbuf BIGINT,
	sref VARCHAR(50),
	Srefrule VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeMModule OWNER TO epsi;
CREATE INDEX TblWdbeMModule_ixVBasetype ON TblWdbeMModule (ixVBasetype);
CREATE INDEX TblWdbeMModule_hkIxVTbl ON TblWdbeMModule (hkIxVTbl);
CREATE INDEX TblWdbeMModule_hkUref ON TblWdbeMModule (hkUref);
CREATE INDEX TblWdbeMModule_hkNum ON TblWdbeMModule (hkNum);
CREATE INDEX TblWdbeMModule_supRefWdbeMModule ON TblWdbeMModule (supRefWdbeMModule);
CREATE INDEX TblWdbeMModule_tplRefWdbeMModule ON TblWdbeMModule (tplRefWdbeMModule);
CREATE INDEX TblWdbeMModule_refWdbeMController ON TblWdbeMModule (refWdbeMController);
CREATE INDEX TblWdbeMModule_refWdbeMImbuf ON TblWdbeMModule (refWdbeMImbuf);
CREATE INDEX TblWdbeMModule_sref ON TblWdbeMModule (sref);

CREATE TABLE TblWdbeMPeripheral(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMUnit BIGINT,
	refWdbeMModule BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWdbeMPeripheral OWNER TO epsi;
CREATE INDEX TblWdbeMPeripheral_refWdbeMUnit ON TblWdbeMPeripheral (refWdbeMUnit);
CREATE INDEX TblWdbeMPeripheral_refWdbeMModule ON TblWdbeMPeripheral (refWdbeMModule);
CREATE INDEX TblWdbeMPeripheral_sref ON TblWdbeMPeripheral (sref);

CREATE TABLE TblWdbeMPerson(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	ixWDerivate INT,
	ixVSex INT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	refJLastname BIGINT,
	Lastname VARCHAR(50),
	telRefADetail BIGINT,
	telVal VARCHAR(192),
	emlRefADetail BIGINT,
	emlVal VARCHAR(192),
	Salutation VARCHAR(100)
);
ALTER TABLE TblWdbeMPerson OWNER TO epsi;
CREATE INDEX TblWdbeMPerson_grp ON TblWdbeMPerson (grp);
CREATE INDEX TblWdbeMPerson_own ON TblWdbeMPerson (own);
CREATE INDEX TblWdbeMPerson_ixWDerivate ON TblWdbeMPerson (ixWDerivate);
CREATE INDEX TblWdbeMPerson_Lastname ON TblWdbeMPerson (Lastname);

CREATE TABLE TblWdbeMPin(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeCPin BIGINT,
	refWdbeMBank BIGINT,
	refJSref BIGINT,
	sref VARCHAR(50),
	Location VARCHAR(5)
);
ALTER TABLE TblWdbeMPin OWNER TO epsi;
CREATE INDEX TblWdbeMPin_refWdbeCPin ON TblWdbeMPin (refWdbeCPin);
CREATE INDEX TblWdbeMPin_refWdbeMBank ON TblWdbeMPin (refWdbeMBank);
CREATE INDEX TblWdbeMPin_sref ON TblWdbeMPin (sref);

CREATE TABLE TblWdbeMPort(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeCPort BIGINT,
	mdlRefWdbeMModule BIGINT,
	mdlNum INT,
	mdlIxVCat INT,
	sref VARCHAR(50),
	ixVDir INT,
	srefWdbeKHdltype VARCHAR(50),
	Width SMALLINT,
	Minmax VARCHAR(30),
	Defval TEXT,
	cpiSrefWdbeMPin VARCHAR(50),
	cprSrefWdbeMPort VARCHAR(50),
	csiSrefWdbeMSignal VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWdbeMPort OWNER TO epsi;
CREATE INDEX TblWdbeMPort_refWdbeCPort ON TblWdbeMPort (refWdbeCPort);
CREATE INDEX TblWdbeMPort_mdlRefWdbeMModule ON TblWdbeMPort (mdlRefWdbeMModule);
CREATE INDEX TblWdbeMPort_mdlNum ON TblWdbeMPort (mdlNum);
CREATE INDEX TblWdbeMPort_sref ON TblWdbeMPort (sref);

CREATE TABLE TblWdbeMProcess(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMModule BIGINT,
	refWdbeMFsm BIGINT,
	sref VARCHAR(50),
	clkSrefWdbeMSignal VARCHAR(50),
	asrSrefWdbeMSignal VARCHAR(50),
	Falling SMALLINT,
	Syncrst VARCHAR(192),
	Extip SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWdbeMProcess OWNER TO epsi;
CREATE INDEX TblWdbeMProcess_refWdbeMModule ON TblWdbeMProcess (refWdbeMModule);
CREATE INDEX TblWdbeMProcess_refWdbeMFsm ON TblWdbeMProcess (refWdbeMFsm);
CREATE INDEX TblWdbeMProcess_sref ON TblWdbeMProcess (sref);

CREATE TABLE TblWdbeMProject(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refWdbeMVersion BIGINT,
	Short VARCHAR(5),
	Title VARCHAR(50),
	Easy SMALLINT,
	Giturl VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeMProject OWNER TO epsi;
CREATE INDEX TblWdbeMProject_grp ON TblWdbeMProject (grp);
CREATE INDEX TblWdbeMProject_own ON TblWdbeMProject (own);
CREATE INDEX TblWdbeMProject_refWdbeMVersion ON TblWdbeMProject (refWdbeMVersion);
CREATE INDEX TblWdbeMProject_Short ON TblWdbeMProject (Short);
CREATE INDEX TblWdbeMProject_Title ON TblWdbeMProject (Title);

CREATE TABLE TblWdbeMRelease(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWdbeMVersion BIGINT,
	refWdbeMMachine BIGINT,
	sref VARCHAR(50),
	srefsKOption VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeMRelease OWNER TO epsi;
CREATE INDEX TblWdbeMRelease_ixVBasetype ON TblWdbeMRelease (ixVBasetype);
CREATE INDEX TblWdbeMRelease_refWdbeMVersion ON TblWdbeMRelease (refWdbeMVersion);
CREATE INDEX TblWdbeMRelease_refWdbeMMachine ON TblWdbeMRelease (refWdbeMMachine);
CREATE INDEX TblWdbeMRelease_sref ON TblWdbeMRelease (sref);

CREATE TABLE TblWdbeMSession(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMUser BIGINT,
	start INT,
	stop INT,
	Ip VARCHAR(30)
);
ALTER TABLE TblWdbeMSession OWNER TO epsi;
CREATE INDEX TblWdbeMSession_refWdbeMUser ON TblWdbeMSession (refWdbeMUser);
CREATE INDEX TblWdbeMSession_start ON TblWdbeMSession (start);

CREATE TABLE TblWdbeMSignal(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refWdbeCSignal BIGINT,
	mdlRefWdbeMModule BIGINT,
	mdlNum INT,
	mgeIxVTbl INT,
	mgeUref BIGINT,
	refWdbeMVector BIGINT,
	sref VARCHAR(50),
	Const SMALLINT,
	srefWdbeKHdltype VARCHAR(50),
	Width SMALLINT,
	Minmax VARCHAR(30),
	Comb VARCHAR(192),
	Onval TEXT,
	Offval TEXT,
	Defon SMALLINT,
	drvRefWdbeMPort BIGINT,
	Comment TEXT
);
ALTER TABLE TblWdbeMSignal OWNER TO epsi;
CREATE INDEX TblWdbeMSignal_ixVBasetype ON TblWdbeMSignal (ixVBasetype);
CREATE INDEX TblWdbeMSignal_refWdbeCSignal ON TblWdbeMSignal (refWdbeCSignal);
CREATE INDEX TblWdbeMSignal_mdlRefWdbeMModule ON TblWdbeMSignal (mdlRefWdbeMModule);
CREATE INDEX TblWdbeMSignal_mdlNum ON TblWdbeMSignal (mdlNum);
CREATE INDEX TblWdbeMSignal_mgeIxVTbl ON TblWdbeMSignal (mgeIxVTbl);
CREATE INDEX TblWdbeMSignal_mgeUref ON TblWdbeMSignal (mgeUref);
CREATE INDEX TblWdbeMSignal_refWdbeMVector ON TblWdbeMSignal (refWdbeMVector);
CREATE INDEX TblWdbeMSignal_sref ON TblWdbeMSignal (sref);
CREATE INDEX TblWdbeMSignal_Const ON TblWdbeMSignal (Const);

CREATE TABLE TblWdbeMSystem(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMVersion BIGINT,
	refWdbeMUnit BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWdbeMSystem OWNER TO epsi;
CREATE INDEX TblWdbeMSystem_refWdbeMVersion ON TblWdbeMSystem (refWdbeMVersion);
CREATE INDEX TblWdbeMSystem_refWdbeMUnit ON TblWdbeMSystem (refWdbeMUnit);
CREATE INDEX TblWdbeMSystem_sref ON TblWdbeMSystem (sref);

CREATE TABLE TblWdbeMTarget(
	ref BIGSERIAL PRIMARY KEY,
	sysRefWdbeMSystem BIGINT,
	sysNum INT,
	refWdbeMUnit BIGINT,
	sref VARCHAR(50),
	rteSrefsWdbeMModule VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeMTarget OWNER TO epsi;
CREATE INDEX TblWdbeMTarget_sysRefWdbeMSystem ON TblWdbeMTarget (sysRefWdbeMSystem);
CREATE INDEX TblWdbeMTarget_sysNum ON TblWdbeMTarget (sysNum);
CREATE INDEX TblWdbeMTarget_refWdbeMUnit ON TblWdbeMTarget (refWdbeMUnit);
CREATE INDEX TblWdbeMTarget_sref ON TblWdbeMTarget (sref);

CREATE TABLE TblWdbeMUnit(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refIxVTbl INT,
	refUref BIGINT,
	silRefWdbeMUnit BIGINT,
	refWdbeMSystem BIGINT,
	refWdbeMModule BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(192),
	Fullsref VARCHAR(50),
	srefKPackage VARCHAR(50),
	Easy SMALLINT,
	srefKToolch VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWdbeMUnit OWNER TO epsi;
CREATE INDEX TblWdbeMUnit_ixVBasetype ON TblWdbeMUnit (ixVBasetype);
CREATE INDEX TblWdbeMUnit_refIxVTbl ON TblWdbeMUnit (refIxVTbl);
CREATE INDEX TblWdbeMUnit_refUref ON TblWdbeMUnit (refUref);
CREATE INDEX TblWdbeMUnit_silRefWdbeMUnit ON TblWdbeMUnit (silRefWdbeMUnit);
CREATE INDEX TblWdbeMUnit_refWdbeMSystem ON TblWdbeMUnit (refWdbeMSystem);
CREATE INDEX TblWdbeMUnit_refWdbeMModule ON TblWdbeMUnit (refWdbeMModule);
CREATE INDEX TblWdbeMUnit_sref ON TblWdbeMUnit (sref);
CREATE INDEX TblWdbeMUnit_Title ON TblWdbeMUnit (Title);

CREATE TABLE TblWdbeMUser(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refRUsergroup BIGINT,
	refWdbeMUsergroup BIGINT,
	refWdbeMPerson BIGINT,
	sref VARCHAR(50),
	refJState BIGINT,
	ixVState INT,
	ixWdbeVLocale INT,
	ixWdbeVUserlevel INT,
	Password VARCHAR(30),
	Fullkey TEXT,
	Comment TEXT
);
ALTER TABLE TblWdbeMUser OWNER TO epsi;
CREATE INDEX TblWdbeMUser_grp ON TblWdbeMUser (grp);
CREATE INDEX TblWdbeMUser_own ON TblWdbeMUser (own);
CREATE INDEX TblWdbeMUser_refWdbeMUsergroup ON TblWdbeMUser (refWdbeMUsergroup);
CREATE INDEX TblWdbeMUser_refWdbeMPerson ON TblWdbeMUser (refWdbeMPerson);
CREATE INDEX TblWdbeMUser_sref ON TblWdbeMUser (sref);
CREATE INDEX TblWdbeMUser_refJState ON TblWdbeMUser (refJState);
CREATE INDEX TblWdbeMUser_ixVState ON TblWdbeMUser (ixVState);

CREATE TABLE TblWdbeMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWdbeMUsergroup OWNER TO epsi;
CREATE INDEX TblWdbeMUsergroup_grp ON TblWdbeMUsergroup (grp);
CREATE INDEX TblWdbeMUsergroup_own ON TblWdbeMUsergroup (own);
CREATE INDEX TblWdbeMUsergroup_sref ON TblWdbeMUsergroup (sref);

CREATE TABLE TblWdbeMVariable(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeCVariable BIGINT,
	prcRefWdbeMProcess BIGINT,
	prcNum INT,
	sref VARCHAR(50),
	Const SMALLINT,
	Falling SMALLINT,
	srefWdbeKHdltype VARCHAR(50),
	Width SMALLINT,
	Minmax VARCHAR(30),
	Onval TEXT,
	Offval TEXT,
	Defon SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWdbeMVariable OWNER TO epsi;
CREATE INDEX TblWdbeMVariable_refWdbeCVariable ON TblWdbeMVariable (refWdbeCVariable);
CREATE INDEX TblWdbeMVariable_prcRefWdbeMProcess ON TblWdbeMVariable (prcRefWdbeMProcess);
CREATE INDEX TblWdbeMVariable_prcNum ON TblWdbeMVariable (prcNum);
CREATE INDEX TblWdbeMVariable_sref ON TblWdbeMVariable (sref);

CREATE TABLE TblWdbeMVector(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	hkIxVTbl INT,
	hkUref BIGINT,
	sref VARCHAR(50),
	srefsKOption VARCHAR(192)
);
ALTER TABLE TblWdbeMVector OWNER TO epsi;
CREATE INDEX TblWdbeMVector_ixVBasetype ON TblWdbeMVector (ixVBasetype);
CREATE INDEX TblWdbeMVector_hkIxVTbl ON TblWdbeMVector (hkIxVTbl);
CREATE INDEX TblWdbeMVector_hkUref ON TblWdbeMVector (hkUref);
CREATE INDEX TblWdbeMVector_sref ON TblWdbeMVector (sref);

CREATE TABLE TblWdbeMVectoritem(
	ref BIGSERIAL PRIMARY KEY,
	vecRefWdbeMVector BIGINT,
	vecNum INT,
	sref VARCHAR(50),
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeMVectoritem OWNER TO epsi;
CREATE INDEX TblWdbeMVectoritem_vecRefWdbeMVector ON TblWdbeMVectoritem (vecRefWdbeMVector);
CREATE INDEX TblWdbeMVectoritem_vecNum ON TblWdbeMVectoritem (vecNum);
CREATE INDEX TblWdbeMVectoritem_sref ON TblWdbeMVectoritem (sref);

CREATE TABLE TblWdbeMVersion(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refWdbeMProject BIGINT,
	bvrRefWdbeMVersion BIGINT,
	Major SMALLINT,
	Minor SMALLINT,
	Sub SMALLINT,
	refJState BIGINT,
	ixVState INT,
	About TEXT,
	Comment TEXT
);
ALTER TABLE TblWdbeMVersion OWNER TO epsi;
CREATE INDEX TblWdbeMVersion_grp ON TblWdbeMVersion (grp);
CREATE INDEX TblWdbeMVersion_own ON TblWdbeMVersion (own);
CREATE INDEX TblWdbeMVersion_refWdbeMProject ON TblWdbeMVersion (refWdbeMProject);
CREATE INDEX TblWdbeMVersion_bvrRefWdbeMVersion ON TblWdbeMVersion (bvrRefWdbeMVersion);
CREATE INDEX TblWdbeMVersion_ixVState ON TblWdbeMVersion (ixVState);

CREATE TABLE TblWdbeRMCommandMController(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMCommand BIGINT,
	refWdbeMController BIGINT,
	ivrRefWdbeMSignal BIGINT,
	rvrRefWdbeMSignal BIGINT
);
ALTER TABLE TblWdbeRMCommandMController OWNER TO epsi;
CREATE INDEX TblWdbeRMCommandMController_refWdbeMCommand ON TblWdbeRMCommandMController (refWdbeMCommand);
CREATE INDEX TblWdbeRMCommandMController_refWdbeMController ON TblWdbeRMCommandMController (refWdbeMController);

CREATE TABLE TblWdbeRMCoreprojectMPerson(
	ref BIGSERIAL PRIMARY KEY,
	x1Startd INT,
	x1Stopd INT,
	refWdbeMCoreproject BIGINT,
	refWdbeMPerson BIGINT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblWdbeRMCoreprojectMPerson OWNER TO epsi;
CREATE INDEX TblWdbeRMCoreprojectMPerson_x1Startd ON TblWdbeRMCoreprojectMPerson (x1Startd);
CREATE INDEX TblWdbeRMCoreprojectMPerson_x1Stopd ON TblWdbeRMCoreprojectMPerson (x1Stopd);
CREATE INDEX TblWdbeRMCoreprojectMPerson_refWdbeMCoreproject ON TblWdbeRMCoreprojectMPerson (refWdbeMCoreproject);
CREATE INDEX TblWdbeRMCoreprojectMPerson_refWdbeMPerson ON TblWdbeRMCoreprojectMPerson (refWdbeMPerson);

CREATE TABLE TblWdbeRMLibraryMVersion(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMLibrary BIGINT,
	refWdbeMVersion BIGINT
);
ALTER TABLE TblWdbeRMLibraryMVersion OWNER TO epsi;
CREATE INDEX TblWdbeRMLibraryMVersion_refWdbeMLibrary ON TblWdbeRMLibraryMVersion (refWdbeMLibrary);
CREATE INDEX TblWdbeRMLibraryMVersion_refWdbeMVersion ON TblWdbeRMLibraryMVersion (refWdbeMVersion);

CREATE TABLE TblWdbeRMPersonMProject(
	ref BIGSERIAL PRIMARY KEY,
	x1Startd INT,
	x1Stopd INT,
	refWdbeMPerson BIGINT,
	refWdbeMProject BIGINT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblWdbeRMPersonMProject OWNER TO epsi;
CREATE INDEX TblWdbeRMPersonMProject_x1Startd ON TblWdbeRMPersonMProject (x1Startd);
CREATE INDEX TblWdbeRMPersonMProject_x1Stopd ON TblWdbeRMPersonMProject (x1Stopd);
CREATE INDEX TblWdbeRMPersonMProject_refWdbeMPerson ON TblWdbeRMPersonMProject (refWdbeMPerson);
CREATE INDEX TblWdbeRMPersonMProject_refWdbeMProject ON TblWdbeRMPersonMProject (refWdbeMProject);

CREATE TABLE TblWdbeRMUsergroupUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMUsergroup BIGINT,
	unvIxWdbeVMaintable INT,
	unvUref BIGINT,
	ixWdbeVRecaccess INT
);
ALTER TABLE TblWdbeRMUsergroupUniversal OWNER TO epsi;
CREATE INDEX TblWdbeRMUsergroupUniversal_refWdbeMUsergroup ON TblWdbeRMUsergroupUniversal (refWdbeMUsergroup);
CREATE INDEX TblWdbeRMUsergroupUniversal_unvIxWdbeVMaintable ON TblWdbeRMUsergroupUniversal (unvIxWdbeVMaintable);
CREATE INDEX TblWdbeRMUsergroupUniversal_unvUref ON TblWdbeRMUsergroupUniversal (unvUref);

CREATE TABLE TblWdbeRMUserMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	refWdbeMUser BIGINT,
	refWdbeMUsergroup BIGINT,
	ixWdbeVUserlevel INT
);
ALTER TABLE TblWdbeRMUserMUsergroup OWNER TO epsi;
CREATE INDEX TblWdbeRMUserMUsergroup_refWdbeMUser ON TblWdbeRMUserMUsergroup (refWdbeMUser);
CREATE INDEX TblWdbeRMUserMUsergroup_refWdbeMUsergroup ON TblWdbeRMUserMUsergroup (refWdbeMUsergroup);

CREATE TABLE TblWdbeQBnk1NPin(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQBnk1NPin OWNER TO epsi;
CREATE INDEX TblWdbeQBnk1NPin_jref ON TblWdbeQBnk1NPin (jref);
CREATE INDEX TblWdbeQBnk1NPin_jnum ON TblWdbeQBnk1NPin (jnum);

CREATE TABLE TblWdbeQBnkList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refWdbeMUnit BIGINT,
	srefKVoltstd VARCHAR(50)
);
ALTER TABLE TblWdbeQBnkList OWNER TO epsi;
CREATE INDEX TblWdbeQBnkList_jref ON TblWdbeQBnkList (jref);
CREATE INDEX TblWdbeQBnkList_jnum ON TblWdbeQBnkList (jnum);

CREATE TABLE TblWdbeQCmdAInvpar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	cmdNum INT,
	sref VARCHAR(50),
	ixWdbeVPartype INT,
	refWdbeMVector BIGINT,
	Length SMALLINT,
	Defval TEXT,
	refWdbeMVectoritem BIGINT,
	Comment TEXT
);
ALTER TABLE TblWdbeQCmdAInvpar OWNER TO epsi;
CREATE INDEX TblWdbeQCmdAInvpar_jref ON TblWdbeQCmdAInvpar (jref);
CREATE INDEX TblWdbeQCmdAInvpar_jnum ON TblWdbeQCmdAInvpar (jnum);

CREATE TABLE TblWdbeQCmdARetpar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	cmdNum INT,
	sref VARCHAR(50),
	ixWdbeVPartype INT,
	refWdbeMVector BIGINT,
	Length SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWdbeQCmdARetpar OWNER TO epsi;
CREATE INDEX TblWdbeQCmdARetpar_jref ON TblWdbeQCmdARetpar (jref);
CREATE INDEX TblWdbeQCmdARetpar_jnum ON TblWdbeQCmdARetpar (jnum);

CREATE TABLE TblWdbeQCmdList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Fullsref VARCHAR(50),
	refIxVTbl INT,
	refUref BIGINT,
	ixVRettype INT
);
ALTER TABLE TblWdbeQCmdList OWNER TO epsi;
CREATE INDEX TblWdbeQCmdList_jref ON TblWdbeQCmdList (jref);
CREATE INDEX TblWdbeQCmdList_jnum ON TblWdbeQCmdList (jnum);

CREATE TABLE TblWdbeQCmdMNController(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ivrRefWdbeMSignal BIGINT,
	rvrRefWdbeMSignal BIGINT
);
ALTER TABLE TblWdbeQCmdMNController OWNER TO epsi;
CREATE INDEX TblWdbeQCmdMNController_jref ON TblWdbeQCmdMNController (jref);
CREATE INDEX TblWdbeQCmdMNController_jnum ON TblWdbeQCmdMNController (jnum);

CREATE TABLE TblWdbeQCpr1NCoreversion(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQCpr1NCoreversion OWNER TO epsi;
CREATE INDEX TblWdbeQCpr1NCoreversion_jref ON TblWdbeQCpr1NCoreversion (jref);
CREATE INDEX TblWdbeQCpr1NCoreversion_jnum ON TblWdbeQCpr1NCoreversion (jnum);

CREATE TABLE TblWdbeQCprList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	ixVBasetype INT,
	refWdbeMCoreversion BIGINT,
	Giturl VARCHAR(192)
);
ALTER TABLE TblWdbeQCprList OWNER TO epsi;
CREATE INDEX TblWdbeQCprList_jref ON TblWdbeQCprList (jref);
CREATE INDEX TblWdbeQCprList_jnum ON TblWdbeQCprList (jnum);

CREATE TABLE TblWdbeQCprMNPerson(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Startd INT,
	x1Stopd INT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblWdbeQCprMNPerson OWNER TO epsi;
CREATE INDEX TblWdbeQCprMNPerson_jref ON TblWdbeQCprMNPerson (jref);
CREATE INDEX TblWdbeQCprMNPerson_jnum ON TblWdbeQCprMNPerson (jnum);

CREATE TABLE TblWdbeQCvrAIp(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	cvrNum INT,
	sref VARCHAR(50),
	ixVTagtype INT,
	Comment TEXT
);
ALTER TABLE TblWdbeQCvrAIp OWNER TO epsi;
CREATE INDEX TblWdbeQCvrAIp_jref ON TblWdbeQCvrAIp (jref);
CREATE INDEX TblWdbeQCvrAIp_jnum ON TblWdbeQCvrAIp (jnum);

CREATE TABLE TblWdbeQCvrAPlh(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	cvrNum INT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblWdbeQCvrAPlh OWNER TO epsi;
CREATE INDEX TblWdbeQCvrAPlh_jref ON TblWdbeQCvrAPlh (jref);
CREATE INDEX TblWdbeQCvrAPlh_jnum ON TblWdbeQCvrAPlh (jnum);

CREATE TABLE TblWdbeQCvrBcv1NCoreversion(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQCvrBcv1NCoreversion OWNER TO epsi;
CREATE INDEX TblWdbeQCvrBcv1NCoreversion_jref ON TblWdbeQCvrBcv1NCoreversion (jref);
CREATE INDEX TblWdbeQCvrBcv1NCoreversion_jnum ON TblWdbeQCvrBcv1NCoreversion (jnum);

CREATE TABLE TblWdbeQCvrHk1NModule(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	hkNum INT
);
ALTER TABLE TblWdbeQCvrHk1NModule OWNER TO epsi;
CREATE INDEX TblWdbeQCvrHk1NModule_jref ON TblWdbeQCvrHk1NModule (jref);
CREATE INDEX TblWdbeQCvrHk1NModule_jnum ON TblWdbeQCvrHk1NModule (jnum);

CREATE TABLE TblWdbeQCvrList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	refWdbeMCoreproject BIGINT,
	Major SMALLINT,
	Minor SMALLINT,
	Sub SMALLINT,
	bcvRefWdbeMCoreversion BIGINT,
	ixVState INT
);
ALTER TABLE TblWdbeQCvrList OWNER TO epsi;
CREATE INDEX TblWdbeQCvrList_jref ON TblWdbeQCvrList (jref);
CREATE INDEX TblWdbeQCvrList_jnum ON TblWdbeQCvrList (jnum);

CREATE TABLE TblWdbeQErrAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	errNum INT,
	sref VARCHAR(50),
	ixWdbeVPartype INT,
	refWdbeMVector BIGINT,
	Length SMALLINT,
	Comment TEXT
);
ALTER TABLE TblWdbeQErrAPar OWNER TO epsi;
CREATE INDEX TblWdbeQErrAPar_jref ON TblWdbeQErrAPar (jref);
CREATE INDEX TblWdbeQErrAPar_jnum ON TblWdbeQErrAPar (jnum);

CREATE TABLE TblWdbeQErrList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Fullsref VARCHAR(50),
	refIxVTbl INT,
	refUref BIGINT
);
ALTER TABLE TblWdbeQErrList OWNER TO epsi;
CREATE INDEX TblWdbeQErrList_jref ON TblWdbeQErrList (jref);
CREATE INDEX TblWdbeQErrList_jnum ON TblWdbeQErrList (jnum);

CREATE TABLE TblWdbeQFam1NUnit(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQFam1NUnit OWNER TO epsi;
CREATE INDEX TblWdbeQFam1NUnit_jref ON TblWdbeQFam1NUnit (jref);
CREATE INDEX TblWdbeQFam1NUnit_jnum ON TblWdbeQFam1NUnit (jnum);

CREATE TABLE TblWdbeQFamList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	srefKVendor VARCHAR(50),
	Title VARCHAR(50)
);
ALTER TABLE TblWdbeQFamList OWNER TO epsi;
CREATE INDEX TblWdbeQFamList_jref ON TblWdbeQFamList (jref);
CREATE INDEX TblWdbeQFamList_jnum ON TblWdbeQFamList (jnum);

CREATE TABLE TblWdbeQFilList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Filename VARCHAR(50),
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	srefKMimetype VARCHAR(50),
	Size SMALLINT
);
ALTER TABLE TblWdbeQFilList OWNER TO epsi;
CREATE INDEX TblWdbeQFilList_jref ON TblWdbeQFilList (jref);
CREATE INDEX TblWdbeQFilList_jnum ON TblWdbeQFilList (jnum);

CREATE TABLE TblWdbeQFstAStep(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	fstNum INT,
	fnxRefWdbeMFsmstate BIGINT,
	Cond1 TEXT,
	Ip1 VARCHAR(50),
	Cond2 TEXT,
	Ip2 VARCHAR(50),
	Cond3 TEXT,
	Ip3 VARCHAR(50),
	Cond4 TEXT,
	Ip4 VARCHAR(50)
);
ALTER TABLE TblWdbeQFstAStep OWNER TO epsi;
CREATE INDEX TblWdbeQFstAStep_jref ON TblWdbeQFstAStep (jref);
CREATE INDEX TblWdbeQFstAStep_jnum ON TblWdbeQFstAStep (jnum);

CREATE TABLE TblWdbeQFstList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	fsmRefWdbeMFsm BIGINT
);
ALTER TABLE TblWdbeQFstList OWNER TO epsi;
CREATE INDEX TblWdbeQFstList_jref ON TblWdbeQFstList (jref);
CREATE INDEX TblWdbeQFstList_jnum ON TblWdbeQFstList (jnum);

CREATE TABLE TblWdbeQGenList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	mdlRefWdbeMModule BIGINT,
	srefWdbeKHdltype VARCHAR(50),
	Width SMALLINT,
	Minmax VARCHAR(30)
);
ALTER TABLE TblWdbeQGenList OWNER TO epsi;
CREATE INDEX TblWdbeQGenList_jref ON TblWdbeQGenList (jref);
CREATE INDEX TblWdbeQGenList_jnum ON TblWdbeQGenList (jnum);

CREATE TABLE TblWdbeQLibAMakefile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefWdbeMMachine BIGINT,
	x2SrefKTag VARCHAR(50),
	Val TEXT
);
ALTER TABLE TblWdbeQLibAMakefile OWNER TO epsi;
CREATE INDEX TblWdbeQLibAMakefile_jref ON TblWdbeQLibAMakefile (jref);
CREATE INDEX TblWdbeQLibAMakefile_jnum ON TblWdbeQLibAMakefile (jnum);

CREATE TABLE TblWdbeQLibList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	Version VARCHAR(30)
);
ALTER TABLE TblWdbeQLibList OWNER TO epsi;
CREATE INDEX TblWdbeQLibList_jref ON TblWdbeQLibList (jref);
CREATE INDEX TblWdbeQLibList_jnum ON TblWdbeQLibList (jnum);

CREATE TABLE TblWdbeQLibMNVersion(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWdbeQLibMNVersion OWNER TO epsi;
CREATE INDEX TblWdbeQLibMNVersion_jref ON TblWdbeQLibMNVersion (jref);
CREATE INDEX TblWdbeQLibMNVersion_jnum ON TblWdbeQLibMNVersion (jnum);

CREATE TABLE TblWdbeQMch1NRelease(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQMch1NRelease OWNER TO epsi;
CREATE INDEX TblWdbeQMch1NRelease_jref ON TblWdbeQMch1NRelease (jref);
CREATE INDEX TblWdbeQMch1NRelease_jnum ON TblWdbeQMch1NRelease (jnum);

CREATE TABLE TblWdbeQMchAMakefile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKTag VARCHAR(50),
	Val TEXT
);
ALTER TABLE TblWdbeQMchAMakefile OWNER TO epsi;
CREATE INDEX TblWdbeQMchAMakefile_jref ON TblWdbeQMchAMakefile (jref);
CREATE INDEX TblWdbeQMchAMakefile_jnum ON TblWdbeQMchAMakefile (jnum);

CREATE TABLE TblWdbeQMchAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKKey VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeQMchAPar OWNER TO epsi;
CREATE INDEX TblWdbeQMchAPar_jref ON TblWdbeQMchAPar (jref);
CREATE INDEX TblWdbeQMchAPar_jnum ON TblWdbeQMchAPar (jnum);

CREATE TABLE TblWdbeQMchList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	srefKPlatform VARCHAR(50)
);
ALTER TABLE TblWdbeQMchList OWNER TO epsi;
CREATE INDEX TblWdbeQMchList_jref ON TblWdbeQMchList (jref);
CREATE INDEX TblWdbeQMchList_jnum ON TblWdbeQMchList (jnum);

CREATE TABLE TblWdbeQMod1NPeripheral(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQMod1NPeripheral OWNER TO epsi;
CREATE INDEX TblWdbeQMod1NPeripheral_jref ON TblWdbeQMod1NPeripheral (jref);
CREATE INDEX TblWdbeQMod1NPeripheral_jnum ON TblWdbeQMod1NPeripheral (jnum);

CREATE TABLE TblWdbeQMod1NProcess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQMod1NProcess OWNER TO epsi;
CREATE INDEX TblWdbeQMod1NProcess_jref ON TblWdbeQMod1NProcess (jref);
CREATE INDEX TblWdbeQMod1NProcess_jnum ON TblWdbeQMod1NProcess (jnum);

CREATE TABLE TblWdbeQModAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mdlNum INT,
	x1SrefKKey VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeQModAPar OWNER TO epsi;
CREATE INDEX TblWdbeQModAPar_jref ON TblWdbeQModAPar (jref);
CREATE INDEX TblWdbeQModAPar_jnum ON TblWdbeQModAPar (jnum);

CREATE TABLE TblWdbeQModCor1NImbuf(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQModCor1NImbuf OWNER TO epsi;
CREATE INDEX TblWdbeQModCor1NImbuf_jref ON TblWdbeQModCor1NImbuf (jref);
CREATE INDEX TblWdbeQModCor1NImbuf_jnum ON TblWdbeQModCor1NImbuf (jnum);

CREATE TABLE TblWdbeQModCtrHk1NVector(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQModCtrHk1NVector OWNER TO epsi;
CREATE INDEX TblWdbeQModCtrHk1NVector_jref ON TblWdbeQModCtrHk1NVector (jref);
CREATE INDEX TblWdbeQModCtrHk1NVector_jnum ON TblWdbeQModCtrHk1NVector (jnum);

CREATE TABLE TblWdbeQModCtrMNCommand(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ivrRefWdbeMSignal BIGINT,
	rvrRefWdbeMSignal BIGINT
);
ALTER TABLE TblWdbeQModCtrMNCommand OWNER TO epsi;
CREATE INDEX TblWdbeQModCtrMNCommand_jref ON TblWdbeQModCtrMNCommand (jref);
CREATE INDEX TblWdbeQModCtrMNCommand_jnum ON TblWdbeQModCtrMNCommand (jnum);

CREATE TABLE TblWdbeQModCtrRef1NCommand(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refNum INT
);
ALTER TABLE TblWdbeQModCtrRef1NCommand OWNER TO epsi;
CREATE INDEX TblWdbeQModCtrRef1NCommand_jref ON TblWdbeQModCtrRef1NCommand (jref);
CREATE INDEX TblWdbeQModCtrRef1NCommand_jnum ON TblWdbeQModCtrRef1NCommand (jnum);

CREATE TABLE TblWdbeQModCtrRef1NError(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refNum INT
);
ALTER TABLE TblWdbeQModCtrRef1NError OWNER TO epsi;
CREATE INDEX TblWdbeQModCtrRef1NError_jref ON TblWdbeQModCtrRef1NError (jref);
CREATE INDEX TblWdbeQModCtrRef1NError_jnum ON TblWdbeQModCtrRef1NError (jnum);

CREATE TABLE TblWdbeQModKHdltype(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeQModKHdltype OWNER TO epsi;
CREATE INDEX TblWdbeQModKHdltype_jref ON TblWdbeQModKHdltype (jref);
CREATE INDEX TblWdbeQModKHdltype_jnum ON TblWdbeQModKHdltype (jnum);

CREATE TABLE TblWdbeQModList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	hkIxVTbl INT,
	hkUref BIGINT,
	supRefWdbeMModule BIGINT,
	tplRefWdbeMModule BIGINT,
	Srefrule VARCHAR(192)
);
ALTER TABLE TblWdbeQModList OWNER TO epsi;
CREATE INDEX TblWdbeQModList_jref ON TblWdbeQModList (jref);
CREATE INDEX TblWdbeQModList_jnum ON TblWdbeQModList (jnum);

CREATE TABLE TblWdbeQModMdl1NGeneric(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mdlNum INT
);
ALTER TABLE TblWdbeQModMdl1NGeneric OWNER TO epsi;
CREATE INDEX TblWdbeQModMdl1NGeneric_jref ON TblWdbeQModMdl1NGeneric (jref);
CREATE INDEX TblWdbeQModMdl1NGeneric_jnum ON TblWdbeQModMdl1NGeneric (jnum);

CREATE TABLE TblWdbeQModMdl1NPort(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mdlNum INT
);
ALTER TABLE TblWdbeQModMdl1NPort OWNER TO epsi;
CREATE INDEX TblWdbeQModMdl1NPort_jref ON TblWdbeQModMdl1NPort (jref);
CREATE INDEX TblWdbeQModMdl1NPort_jnum ON TblWdbeQModMdl1NPort (jnum);

CREATE TABLE TblWdbeQModMdl1NSignal(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mdlNum INT
);
ALTER TABLE TblWdbeQModMdl1NSignal OWNER TO epsi;
CREATE INDEX TblWdbeQModMdl1NSignal_jref ON TblWdbeQModMdl1NSignal (jref);
CREATE INDEX TblWdbeQModMdl1NSignal_jnum ON TblWdbeQModMdl1NSignal (jnum);

CREATE TABLE TblWdbeQModMge1NSignal(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQModMge1NSignal OWNER TO epsi;
CREATE INDEX TblWdbeQModMge1NSignal_jref ON TblWdbeQModMge1NSignal (jref);
CREATE INDEX TblWdbeQModMge1NSignal_jnum ON TblWdbeQModMge1NSignal (jnum);

CREATE TABLE TblWdbeQModSup1NModule(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQModSup1NModule OWNER TO epsi;
CREATE INDEX TblWdbeQModSup1NModule_jref ON TblWdbeQModSup1NModule (jref);
CREATE INDEX TblWdbeQModSup1NModule_jnum ON TblWdbeQModSup1NModule (jnum);

CREATE TABLE TblWdbeQMtpAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mdlNum INT,
	x1SrefKKey VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeQMtpAPar OWNER TO epsi;
CREATE INDEX TblWdbeQMtpAPar_jref ON TblWdbeQMtpAPar (jref);
CREATE INDEX TblWdbeQMtpAPar_jnum ON TblWdbeQMtpAPar (jnum);

CREATE TABLE TblWdbeQMtpKHdltype(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeQMtpKHdltype OWNER TO epsi;
CREATE INDEX TblWdbeQMtpKHdltype_jref ON TblWdbeQMtpKHdltype (jref);
CREATE INDEX TblWdbeQMtpKHdltype_jnum ON TblWdbeQMtpKHdltype (jnum);

CREATE TABLE TblWdbeQMtpKParKey(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeQMtpKParKey OWNER TO epsi;
CREATE INDEX TblWdbeQMtpKParKey_jref ON TblWdbeQMtpKParKey (jref);
CREATE INDEX TblWdbeQMtpKParKey_jnum ON TblWdbeQMtpKParKey (jnum);

CREATE TABLE TblWdbeQMtpList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	hkIxVTbl INT,
	hkUref BIGINT,
	Srefrule VARCHAR(192)
);
ALTER TABLE TblWdbeQMtpList OWNER TO epsi;
CREATE INDEX TblWdbeQMtpList_jref ON TblWdbeQMtpList (jref);
CREATE INDEX TblWdbeQMtpList_jnum ON TblWdbeQMtpList (jnum);

CREATE TABLE TblWdbeQMtpMdl1NGeneric(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mdlNum INT
);
ALTER TABLE TblWdbeQMtpMdl1NGeneric OWNER TO epsi;
CREATE INDEX TblWdbeQMtpMdl1NGeneric_jref ON TblWdbeQMtpMdl1NGeneric (jref);
CREATE INDEX TblWdbeQMtpMdl1NGeneric_jnum ON TblWdbeQMtpMdl1NGeneric (jnum);

CREATE TABLE TblWdbeQMtpMdl1NPort(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mdlNum INT
);
ALTER TABLE TblWdbeQMtpMdl1NPort OWNER TO epsi;
CREATE INDEX TblWdbeQMtpMdl1NPort_jref ON TblWdbeQMtpMdl1NPort (jref);
CREATE INDEX TblWdbeQMtpMdl1NPort_jnum ON TblWdbeQMtpMdl1NPort (jnum);

CREATE TABLE TblWdbeQMtpMge1NSignal(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQMtpMge1NSignal OWNER TO epsi;
CREATE INDEX TblWdbeQMtpMge1NSignal_jref ON TblWdbeQMtpMge1NSignal (jref);
CREATE INDEX TblWdbeQMtpMge1NSignal_jnum ON TblWdbeQMtpMge1NSignal (jnum);

CREATE TABLE TblWdbeQMtpRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQMtpRef1NFile OWNER TO epsi;
CREATE INDEX TblWdbeQMtpRef1NFile_jref ON TblWdbeQMtpRef1NFile (jref);
CREATE INDEX TblWdbeQMtpRef1NFile_jnum ON TblWdbeQMtpRef1NFile (jnum);

CREATE TABLE TblWdbeQMtpSup1NModule(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQMtpSup1NModule OWNER TO epsi;
CREATE INDEX TblWdbeQMtpSup1NModule_jref ON TblWdbeQMtpSup1NModule (jref);
CREATE INDEX TblWdbeQMtpSup1NModule_jnum ON TblWdbeQMtpSup1NModule (jnum);

CREATE TABLE TblWdbeQMtpTpl1NModule(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQMtpTpl1NModule OWNER TO epsi;
CREATE INDEX TblWdbeQMtpTpl1NModule_jref ON TblWdbeQMtpTpl1NModule (jref);
CREATE INDEX TblWdbeQMtpTpl1NModule_jnum ON TblWdbeQMtpTpl1NModule (jnum);

CREATE TABLE TblWdbeQPinAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKKey VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeQPinAPar OWNER TO epsi;
CREATE INDEX TblWdbeQPinAPar_jref ON TblWdbeQPinAPar (jref);
CREATE INDEX TblWdbeQPinAPar_jnum ON TblWdbeQPinAPar (jnum);

CREATE TABLE TblWdbeQPinList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refWdbeMBank BIGINT,
	Location VARCHAR(5)
);
ALTER TABLE TblWdbeQPinList OWNER TO epsi;
CREATE INDEX TblWdbeQPinList_jref ON TblWdbeQPinList (jref);
CREATE INDEX TblWdbeQPinList_jnum ON TblWdbeQPinList (jnum);

CREATE TABLE TblWdbeQPphAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKKey VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeQPphAPar OWNER TO epsi;
CREATE INDEX TblWdbeQPphAPar_jref ON TblWdbeQPphAPar (jref);
CREATE INDEX TblWdbeQPphAPar_jnum ON TblWdbeQPphAPar (jnum);

CREATE TABLE TblWdbeQPphList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refWdbeMUnit BIGINT,
	refWdbeMModule BIGINT
);
ALTER TABLE TblWdbeQPphList OWNER TO epsi;
CREATE INDEX TblWdbeQPphList_jref ON TblWdbeQPphList (jref);
CREATE INDEX TblWdbeQPphList_jnum ON TblWdbeQPphList (jnum);

CREATE TABLE TblWdbeQPrcFsmFsm1NFsmstate(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	fsmNum INT
);
ALTER TABLE TblWdbeQPrcFsmFsm1NFsmstate OWNER TO epsi;
CREATE INDEX TblWdbeQPrcFsmFsm1NFsmstate_jref ON TblWdbeQPrcFsmFsm1NFsmstate (jref);
CREATE INDEX TblWdbeQPrcFsmFsm1NFsmstate_jnum ON TblWdbeQPrcFsmFsm1NFsmstate (jnum);

CREATE TABLE TblWdbeQPrcKHdltype(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(192),
	Comment TEXT
);
ALTER TABLE TblWdbeQPrcKHdltype OWNER TO epsi;
CREATE INDEX TblWdbeQPrcKHdltype_jref ON TblWdbeQPrcKHdltype (jref);
CREATE INDEX TblWdbeQPrcKHdltype_jnum ON TblWdbeQPrcKHdltype (jnum);

CREATE TABLE TblWdbeQPrcList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refWdbeMModule BIGINT,
	Falling SMALLINT
);
ALTER TABLE TblWdbeQPrcList OWNER TO epsi;
CREATE INDEX TblWdbeQPrcList_jref ON TblWdbeQPrcList (jref);
CREATE INDEX TblWdbeQPrcList_jnum ON TblWdbeQPrcList (jnum);

CREATE TABLE TblWdbeQPrcMge1NSignal(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQPrcMge1NSignal OWNER TO epsi;
CREATE INDEX TblWdbeQPrcMge1NSignal_jref ON TblWdbeQPrcMge1NSignal (jref);
CREATE INDEX TblWdbeQPrcMge1NSignal_jnum ON TblWdbeQPrcMge1NSignal (jnum);

CREATE TABLE TblWdbeQPrcPrc1NVariable(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	prcNum INT
);
ALTER TABLE TblWdbeQPrcPrc1NVariable OWNER TO epsi;
CREATE INDEX TblWdbeQPrcPrc1NVariable_jref ON TblWdbeQPrcPrc1NVariable (jref);
CREATE INDEX TblWdbeQPrcPrc1NVariable_jnum ON TblWdbeQPrcPrc1NVariable (jnum);

CREATE TABLE TblWdbeQPreselect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQPreselect OWNER TO epsi;
CREATE INDEX TblWdbeQPreselect_jref ON TblWdbeQPreselect (jref);

CREATE TABLE TblWdbeQPrj1NVersion(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQPrj1NVersion OWNER TO epsi;
CREATE INDEX TblWdbeQPrj1NVersion_jref ON TblWdbeQPrj1NVersion (jref);
CREATE INDEX TblWdbeQPrj1NVersion_jnum ON TblWdbeQPrj1NVersion (jnum);

CREATE TABLE TblWdbeQPrjList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Short VARCHAR(5),
	Title VARCHAR(50),
	refWdbeMVersion BIGINT,
	Easy SMALLINT,
	Giturl VARCHAR(192)
);
ALTER TABLE TblWdbeQPrjList OWNER TO epsi;
CREATE INDEX TblWdbeQPrjList_jref ON TblWdbeQPrjList (jref);
CREATE INDEX TblWdbeQPrjList_jnum ON TblWdbeQPrjList (jnum);

CREATE TABLE TblWdbeQPrjMNPerson(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Startd INT,
	x1Stopd INT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblWdbeQPrjMNPerson OWNER TO epsi;
CREATE INDEX TblWdbeQPrjMNPerson_jref ON TblWdbeQPrjMNPerson (jref);
CREATE INDEX TblWdbeQPrjMNPerson_jnum ON TblWdbeQPrjMNPerson (jnum);

CREATE TABLE TblWdbeQPrsADetail(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(192)
);
ALTER TABLE TblWdbeQPrsADetail OWNER TO epsi;
CREATE INDEX TblWdbeQPrsADetail_jref ON TblWdbeQPrsADetail (jref);
CREATE INDEX TblWdbeQPrsADetail_jnum ON TblWdbeQPrsADetail (jnum);

CREATE TABLE TblWdbeQPrsList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	Lastname VARCHAR(50),
	ixVSex INT,
	telVal VARCHAR(192),
	emlVal VARCHAR(192)
);
ALTER TABLE TblWdbeQPrsList OWNER TO epsi;
CREATE INDEX TblWdbeQPrsList_jref ON TblWdbeQPrsList (jref);
CREATE INDEX TblWdbeQPrsList_jnum ON TblWdbeQPrsList (jnum);

CREATE TABLE TblWdbeQPrsMNCoreproject(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Startd INT,
	x1Stopd INT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblWdbeQPrsMNCoreproject OWNER TO epsi;
CREATE INDEX TblWdbeQPrsMNCoreproject_jref ON TblWdbeQPrsMNCoreproject (jref);
CREATE INDEX TblWdbeQPrsMNCoreproject_jnum ON TblWdbeQPrsMNCoreproject (jnum);

CREATE TABLE TblWdbeQPrsMNProject(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Startd INT,
	x1Stopd INT,
	srefKFunction VARCHAR(50)
);
ALTER TABLE TblWdbeQPrsMNProject OWNER TO epsi;
CREATE INDEX TblWdbeQPrsMNProject_jref ON TblWdbeQPrsMNProject (jref);
CREATE INDEX TblWdbeQPrsMNProject_jnum ON TblWdbeQPrsMNProject (jnum);

CREATE TABLE TblWdbeQPrtList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	mdlRefWdbeMModule BIGINT,
	mdlIxVCat INT,
	ixVDir INT,
	srefWdbeKHdltype VARCHAR(50),
	Width SMALLINT,
	Minmax VARCHAR(30)
);
ALTER TABLE TblWdbeQPrtList OWNER TO epsi;
CREATE INDEX TblWdbeQPrtList_jref ON TblWdbeQPrtList (jref);
CREATE INDEX TblWdbeQPrtList_jnum ON TblWdbeQPrtList (jnum);

CREATE TABLE TblWdbeQRlsList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	refWdbeMVersion BIGINT,
	refWdbeMMachine BIGINT
);
ALTER TABLE TblWdbeQRlsList OWNER TO epsi;
CREATE INDEX TblWdbeQRlsList_jref ON TblWdbeQRlsList (jref);
CREATE INDEX TblWdbeQRlsList_jnum ON TblWdbeQRlsList (jnum);

CREATE TABLE TblWdbeQSelect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ix INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQSelect OWNER TO epsi;
CREATE INDEX TblWdbeQSelect_jref ON TblWdbeQSelect (jref);
CREATE INDEX TblWdbeQSelect_ix ON TblWdbeQSelect (ix);

CREATE TABLE TblWdbeQSigList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	mdlRefWdbeMModule BIGINT,
	mgeIxVTbl INT,
	mgeUref BIGINT,
	refWdbeMVector BIGINT,
	Const SMALLINT,
	srefWdbeKHdltype VARCHAR(50),
	Width SMALLINT,
	Minmax VARCHAR(30)
);
ALTER TABLE TblWdbeQSigList OWNER TO epsi;
CREATE INDEX TblWdbeQSigList_jref ON TblWdbeQSigList (jref);
CREATE INDEX TblWdbeQSigList_jnum ON TblWdbeQSigList (jnum);

CREATE TABLE TblWdbeQSil1NBank(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQSil1NBank OWNER TO epsi;
CREATE INDEX TblWdbeQSil1NBank_jref ON TblWdbeQSil1NBank (jref);
CREATE INDEX TblWdbeQSil1NBank_jnum ON TblWdbeQSil1NBank (jnum);

CREATE TABLE TblWdbeQSil1NPeripheral(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQSil1NPeripheral OWNER TO epsi;
CREATE INDEX TblWdbeQSil1NPeripheral_jref ON TblWdbeQSil1NPeripheral (jref);
CREATE INDEX TblWdbeQSil1NPeripheral_jnum ON TblWdbeQSil1NPeripheral (jnum);

CREATE TABLE TblWdbeQSil1NTarget(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQSil1NTarget OWNER TO epsi;
CREATE INDEX TblWdbeQSil1NTarget_jref ON TblWdbeQSil1NTarget (jref);
CREATE INDEX TblWdbeQSil1NTarget_jnum ON TblWdbeQSil1NTarget (jnum);

CREATE TABLE TblWdbeQSilFwd1NController(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQSilFwd1NController OWNER TO epsi;
CREATE INDEX TblWdbeQSilFwd1NController_jref ON TblWdbeQSilFwd1NController (jref);
CREATE INDEX TblWdbeQSilFwd1NController_jnum ON TblWdbeQSilFwd1NController (jnum);

CREATE TABLE TblWdbeQSilHk1NModule(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	hkNum INT
);
ALTER TABLE TblWdbeQSilHk1NModule OWNER TO epsi;
CREATE INDEX TblWdbeQSilHk1NModule_jref ON TblWdbeQSilHk1NModule (jref);
CREATE INDEX TblWdbeQSilHk1NModule_jnum ON TblWdbeQSilHk1NModule (jnum);

CREATE TABLE TblWdbeQSilHk1NVector(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQSilHk1NVector OWNER TO epsi;
CREATE INDEX TblWdbeQSilHk1NVector_jref ON TblWdbeQSilHk1NVector (jref);
CREATE INDEX TblWdbeQSilHk1NVector_jnum ON TblWdbeQSilHk1NVector (jnum);

CREATE TABLE TblWdbeQSilList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(192),
	Fullsref VARCHAR(50),
	ixVBasetype INT,
	refIxVTbl INT,
	refUref BIGINT,
	refWdbeMSystem BIGINT,
	refWdbeMModule BIGINT,
	srefKPackage VARCHAR(50),
	Easy SMALLINT,
	srefKToolch VARCHAR(50)
);
ALTER TABLE TblWdbeQSilList OWNER TO epsi;
CREATE INDEX TblWdbeQSilList_jref ON TblWdbeQSilList (jref);
CREATE INDEX TblWdbeQSilList_jnum ON TblWdbeQSilList (jnum);

CREATE TABLE TblWdbeQSilRef1NCommand(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refNum INT
);
ALTER TABLE TblWdbeQSilRef1NCommand OWNER TO epsi;
CREATE INDEX TblWdbeQSilRef1NCommand_jref ON TblWdbeQSilRef1NCommand (jref);
CREATE INDEX TblWdbeQSilRef1NCommand_jnum ON TblWdbeQSilRef1NCommand (jnum);

CREATE TABLE TblWdbeQSilRef1NError(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refNum INT
);
ALTER TABLE TblWdbeQSilRef1NError OWNER TO epsi;
CREATE INDEX TblWdbeQSilRef1NError_jref ON TblWdbeQSilRef1NError (jref);
CREATE INDEX TblWdbeQSilRef1NError_jnum ON TblWdbeQSilRef1NError (jnum);

CREATE TABLE TblWdbeQSilSil1NUnit(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQSilSil1NUnit OWNER TO epsi;
CREATE INDEX TblWdbeQSilSil1NUnit_jref ON TblWdbeQSilSil1NUnit (jref);
CREATE INDEX TblWdbeQSilSil1NUnit_jnum ON TblWdbeQSilSil1NUnit (jnum);

CREATE TABLE TblWdbeQSysHk1NVector(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQSysHk1NVector OWNER TO epsi;
CREATE INDEX TblWdbeQSysHk1NVector_jref ON TblWdbeQSysHk1NVector (jref);
CREATE INDEX TblWdbeQSysHk1NVector_jnum ON TblWdbeQSysHk1NVector (jnum);

CREATE TABLE TblWdbeQSysList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refWdbeMVersion BIGINT,
	refWdbeMUnit BIGINT
);
ALTER TABLE TblWdbeQSysList OWNER TO epsi;
CREATE INDEX TblWdbeQSysList_jref ON TblWdbeQSysList (jref);
CREATE INDEX TblWdbeQSysList_jnum ON TblWdbeQSysList (jnum);

CREATE TABLE TblWdbeQSysSys1NTarget(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sysNum INT
);
ALTER TABLE TblWdbeQSysSys1NTarget OWNER TO epsi;
CREATE INDEX TblWdbeQSysSys1NTarget_jref ON TblWdbeQSysSys1NTarget (jref);
CREATE INDEX TblWdbeQSysSys1NTarget_jnum ON TblWdbeQSysSys1NTarget (jnum);

CREATE TABLE TblWdbeQTrgList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	sysRefWdbeMSystem BIGINT,
	refWdbeMUnit BIGINT
);
ALTER TABLE TblWdbeQTrgList OWNER TO epsi;
CREATE INDEX TblWdbeQTrgList_jref ON TblWdbeQTrgList (jref);
CREATE INDEX TblWdbeQTrgList_jnum ON TblWdbeQTrgList (jnum);

CREATE TABLE TblWdbeQUnt1NBank(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQUnt1NBank OWNER TO epsi;
CREATE INDEX TblWdbeQUnt1NBank_jref ON TblWdbeQUnt1NBank (jref);
CREATE INDEX TblWdbeQUnt1NBank_jnum ON TblWdbeQUnt1NBank (jnum);

CREATE TABLE TblWdbeQUnt1NPeripheral(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQUnt1NPeripheral OWNER TO epsi;
CREATE INDEX TblWdbeQUnt1NPeripheral_jref ON TblWdbeQUnt1NPeripheral (jref);
CREATE INDEX TblWdbeQUnt1NPeripheral_jnum ON TblWdbeQUnt1NPeripheral (jnum);

CREATE TABLE TblWdbeQUnt1NTarget(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQUnt1NTarget OWNER TO epsi;
CREATE INDEX TblWdbeQUnt1NTarget_jref ON TblWdbeQUnt1NTarget (jref);
CREATE INDEX TblWdbeQUnt1NTarget_jnum ON TblWdbeQUnt1NTarget (jnum);

CREATE TABLE TblWdbeQUntFwd1NController(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQUntFwd1NController OWNER TO epsi;
CREATE INDEX TblWdbeQUntFwd1NController_jref ON TblWdbeQUntFwd1NController (jref);
CREATE INDEX TblWdbeQUntFwd1NController_jnum ON TblWdbeQUntFwd1NController (jnum);

CREATE TABLE TblWdbeQUntHk1NModule(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	hkNum INT
);
ALTER TABLE TblWdbeQUntHk1NModule OWNER TO epsi;
CREATE INDEX TblWdbeQUntHk1NModule_jref ON TblWdbeQUntHk1NModule (jref);
CREATE INDEX TblWdbeQUntHk1NModule_jnum ON TblWdbeQUntHk1NModule (jnum);

CREATE TABLE TblWdbeQUntHk1NVector(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQUntHk1NVector OWNER TO epsi;
CREATE INDEX TblWdbeQUntHk1NVector_jref ON TblWdbeQUntHk1NVector (jref);
CREATE INDEX TblWdbeQUntHk1NVector_jnum ON TblWdbeQUntHk1NVector (jnum);

CREATE TABLE TblWdbeQUntList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(192),
	Fullsref VARCHAR(50),
	ixVBasetype INT,
	refIxVTbl INT,
	refUref BIGINT,
	refWdbeMSystem BIGINT,
	refWdbeMModule BIGINT,
	srefKPackage VARCHAR(50),
	Easy SMALLINT,
	srefKToolch VARCHAR(50)
);
ALTER TABLE TblWdbeQUntList OWNER TO epsi;
CREATE INDEX TblWdbeQUntList_jref ON TblWdbeQUntList (jref);
CREATE INDEX TblWdbeQUntList_jnum ON TblWdbeQUntList (jnum);

CREATE TABLE TblWdbeQUntRef1NCommand(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refNum INT
);
ALTER TABLE TblWdbeQUntRef1NCommand OWNER TO epsi;
CREATE INDEX TblWdbeQUntRef1NCommand_jref ON TblWdbeQUntRef1NCommand (jref);
CREATE INDEX TblWdbeQUntRef1NCommand_jnum ON TblWdbeQUntRef1NCommand (jnum);

CREATE TABLE TblWdbeQUntRef1NError(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refNum INT
);
ALTER TABLE TblWdbeQUntRef1NError OWNER TO epsi;
CREATE INDEX TblWdbeQUntRef1NError_jref ON TblWdbeQUntRef1NError (jref);
CREATE INDEX TblWdbeQUntRef1NError_jnum ON TblWdbeQUntRef1NError (jnum);

CREATE TABLE TblWdbeQUntSil1NUnit(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQUntSil1NUnit OWNER TO epsi;
CREATE INDEX TblWdbeQUntSil1NUnit_jref ON TblWdbeQUntSil1NUnit (jref);
CREATE INDEX TblWdbeQUntSil1NUnit_jnum ON TblWdbeQUntSil1NUnit (jnum);

CREATE TABLE TblWdbeQUsgAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxWdbeVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWdbeWAccess INT
);
ALTER TABLE TblWdbeQUsgAAccess OWNER TO epsi;
CREATE INDEX TblWdbeQUsgAAccess_jref ON TblWdbeQUsgAAccess (jref);
CREATE INDEX TblWdbeQUsgAAccess_jnum ON TblWdbeQUsgAAccess (jnum);

CREATE TABLE TblWdbeQUsgList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50)
);
ALTER TABLE TblWdbeQUsgList OWNER TO epsi;
CREATE INDEX TblWdbeQUsgList_jref ON TblWdbeQUsgList (jref);
CREATE INDEX TblWdbeQUsgList_jnum ON TblWdbeQUsgList (jnum);

CREATE TABLE TblWdbeQUsgMNUser(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixWdbeVUserlevel INT
);
ALTER TABLE TblWdbeQUsgMNUser OWNER TO epsi;
CREATE INDEX TblWdbeQUsgMNUser_jref ON TblWdbeQUsgMNUser (jref);
CREATE INDEX TblWdbeQUsgMNUser_jnum ON TblWdbeQUsgMNUser (jnum);

CREATE TABLE TblWdbeQUsr1NSession(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQUsr1NSession OWNER TO epsi;
CREATE INDEX TblWdbeQUsr1NSession_jref ON TblWdbeQUsr1NSession (jref);
CREATE INDEX TblWdbeQUsr1NSession_jnum ON TblWdbeQUsr1NSession (jnum);

CREATE TABLE TblWdbeQUsrAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxWdbeVFeatgroup INT,
	x2FeaSrefUix VARCHAR(50),
	ixWdbeWAccess INT
);
ALTER TABLE TblWdbeQUsrAAccess OWNER TO epsi;
CREATE INDEX TblWdbeQUsrAAccess_jref ON TblWdbeQUsrAAccess (jref);
CREATE INDEX TblWdbeQUsrAAccess_jnum ON TblWdbeQUsrAAccess (jnum);

CREATE TABLE TblWdbeQUsrList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	refWdbeMPerson BIGINT,
	sref VARCHAR(50),
	refWdbeMUsergroup BIGINT,
	ixVState INT,
	ixWdbeVLocale INT,
	ixWdbeVUserlevel INT
);
ALTER TABLE TblWdbeQUsrList OWNER TO epsi;
CREATE INDEX TblWdbeQUsrList_jref ON TblWdbeQUsrList (jref);
CREATE INDEX TblWdbeQUsrList_jnum ON TblWdbeQUsrList (jnum);

CREATE TABLE TblWdbeQUsrMNUsergroup(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixWdbeVUserlevel INT
);
ALTER TABLE TblWdbeQUsrMNUsergroup OWNER TO epsi;
CREATE INDEX TblWdbeQUsrMNUsergroup_jref ON TblWdbeQUsrMNUsergroup (jref);
CREATE INDEX TblWdbeQUsrMNUsergroup_jnum ON TblWdbeQUsrMNUsergroup (jnum);

CREATE TABLE TblWdbeQVarList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	prcRefWdbeMProcess BIGINT,
	Const SMALLINT,
	Falling SMALLINT,
	srefWdbeKHdltype VARCHAR(50),
	Width SMALLINT,
	Minmax VARCHAR(30)
);
ALTER TABLE TblWdbeQVarList OWNER TO epsi;
CREATE INDEX TblWdbeQVarList_jref ON TblWdbeQVarList (jref);
CREATE INDEX TblWdbeQVarList_jnum ON TblWdbeQVarList (jnum);

CREATE TABLE TblWdbeQVecList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	hkIxVTbl INT,
	hkUref BIGINT
);
ALTER TABLE TblWdbeQVecList OWNER TO epsi;
CREATE INDEX TblWdbeQVecList_jref ON TblWdbeQVecList (jref);
CREATE INDEX TblWdbeQVecList_jnum ON TblWdbeQVecList (jnum);

CREATE TABLE TblWdbeQVecVec1NVectoritem(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	vecNum INT
);
ALTER TABLE TblWdbeQVecVec1NVectoritem OWNER TO epsi;
CREATE INDEX TblWdbeQVecVec1NVectoritem_jref ON TblWdbeQVecVec1NVectoritem (jref);
CREATE INDEX TblWdbeQVecVec1NVectoritem_jnum ON TblWdbeQVecVec1NVectoritem (jnum);

CREATE TABLE TblWdbeQVer1NRelease(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQVer1NRelease OWNER TO epsi;
CREATE INDEX TblWdbeQVer1NRelease_jref ON TblWdbeQVer1NRelease (jref);
CREATE INDEX TblWdbeQVer1NRelease_jnum ON TblWdbeQVer1NRelease (jnum);

CREATE TABLE TblWdbeQVer1NSystem(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQVer1NSystem OWNER TO epsi;
CREATE INDEX TblWdbeQVer1NSystem_jref ON TblWdbeQVer1NSystem (jref);
CREATE INDEX TblWdbeQVer1NSystem_jnum ON TblWdbeQVer1NSystem (jnum);

CREATE TABLE TblWdbeQVer1NUnit(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQVer1NUnit OWNER TO epsi;
CREATE INDEX TblWdbeQVer1NUnit_jref ON TblWdbeQVer1NUnit (jref);
CREATE INDEX TblWdbeQVer1NUnit_jnum ON TblWdbeQVer1NUnit (jnum);

CREATE TABLE TblWdbeQVerBvr1NVersion(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQVerBvr1NVersion OWNER TO epsi;
CREATE INDEX TblWdbeQVerBvr1NVersion_jref ON TblWdbeQVerBvr1NVersion (jref);
CREATE INDEX TblWdbeQVerBvr1NVersion_jnum ON TblWdbeQVerBvr1NVersion (jnum);

CREATE TABLE TblWdbeQVerList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	grp BIGINT,
	own BIGINT,
	refWdbeMProject BIGINT,
	Major SMALLINT,
	Minor SMALLINT,
	Sub SMALLINT,
	bvrRefWdbeMVersion BIGINT,
	ixVState INT
);
ALTER TABLE TblWdbeQVerList OWNER TO epsi;
CREATE INDEX TblWdbeQVerList_jref ON TblWdbeQVerList (jref);
CREATE INDEX TblWdbeQVerList_jnum ON TblWdbeQVerList (jnum);

CREATE TABLE TblWdbeQVerMNLibrary(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblWdbeQVerMNLibrary OWNER TO epsi;
CREATE INDEX TblWdbeQVerMNLibrary_jref ON TblWdbeQVerMNLibrary (jref);
CREATE INDEX TblWdbeQVerMNLibrary_jnum ON TblWdbeQVerMNLibrary (jnum);

CREATE TABLE TblWdbeQVerRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblWdbeQVerRef1NFile OWNER TO epsi;
CREATE INDEX TblWdbeQVerRef1NFile_jref ON TblWdbeQVerRef1NFile (jref);
CREATE INDEX TblWdbeQVerRef1NFile_jnum ON TblWdbeQVerRef1NFile (jnum);

CREATE TABLE TblWdbeQVitList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(192),
	vecRefWdbeMVector BIGINT
);
ALTER TABLE TblWdbeQVitList OWNER TO epsi;
CREATE INDEX TblWdbeQVitList_jref ON TblWdbeQVitList (jref);
CREATE INDEX TblWdbeQVitList_jnum ON TblWdbeQVitList (jnum);

