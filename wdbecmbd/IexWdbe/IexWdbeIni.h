/**
	* \file IexWdbeIni.h
	* data blocks and readers/writers for import/export complex IexWdbeIni (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef IEXWDBEINI_H
#define IEXWDBEINI_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWdbe.h"
#include "VecWdbeVIop.h"

#define VecVIexWdbeIniIme IexWdbeIni::VecVIme

#define ImeitemIWdbeIniAVControlPar IexWdbeIni::ImeitemIAVControlPar
#define ImeIWdbeIniAVControlPar IexWdbeIni::ImeIAVControlPar
#define VecWImeIWdbeIniAVControlParIel IexWdbeIni::ImeIAVControlPar::VecWIel

#define ImeitemIWdbeIniJAVKeylistKey1 IexWdbeIni::ImeitemIJAVKeylistKey1
#define ImeIWdbeIniJAVKeylistKey1 IexWdbeIni::ImeIJAVKeylistKey1
#define VecWImeIWdbeIniJAVKeylistKey1Iel IexWdbeIni::ImeIJAVKeylistKey1::VecWIel

#define ImeitemIWdbeIniAVKeylistKey1 IexWdbeIni::ImeitemIAVKeylistKey1
#define ImeIWdbeIniAVKeylistKey1 IexWdbeIni::ImeIAVKeylistKey1
#define VecWImeIWdbeIniAVKeylistKey1Iel IexWdbeIni::ImeIAVKeylistKey1::VecWIel

#define ImeitemIWdbeIniAVValuelistVal IexWdbeIni::ImeitemIAVValuelistVal
#define ImeIWdbeIniAVValuelistVal IexWdbeIni::ImeIAVValuelistVal
#define VecWImeIWdbeIniAVValuelistValIel IexWdbeIni::ImeIAVValuelistVal::VecWIel

#define ImeitemIWdbeIniJMCoreversionState IexWdbeIni::ImeitemIJMCoreversionState
#define ImeIWdbeIniJMCoreversionState IexWdbeIni::ImeIJMCoreversionState
#define VecWImeIWdbeIniJMCoreversionStateIel IexWdbeIni::ImeIJMCoreversionState::VecWIel

#define ImeitemIWdbeIniMCoreversion IexWdbeIni::ImeitemIMCoreversion
#define ImeIWdbeIniMCoreversion IexWdbeIni::ImeIMCoreversion
#define VecWImeIWdbeIniMCoreversionIel IexWdbeIni::ImeIMCoreversion::VecWIel

#define ImeitemIWdbeIniRMCoreprojectMPerson IexWdbeIni::ImeitemIRMCoreprojectMPerson
#define ImeIWdbeIniRMCoreprojectMPerson IexWdbeIni::ImeIRMCoreprojectMPerson
#define VecWImeIWdbeIniRMCoreprojectMPersonIel IexWdbeIni::ImeIRMCoreprojectMPerson::VecWIel

#define ImeitemIWdbeIniMCoreproject IexWdbeIni::ImeitemIMCoreproject
#define ImeIWdbeIniMCoreproject IexWdbeIni::ImeIMCoreproject
#define VecWImeIWdbeIniMCoreprojectIel IexWdbeIni::ImeIMCoreproject::VecWIel

#define ImeitemIWdbeIniMFamily IexWdbeIni::ImeitemIMFamily
#define ImeIWdbeIniMFamily IexWdbeIni::ImeIMFamily
#define VecWImeIWdbeIniMFamilyIel IexWdbeIni::ImeIMFamily::VecWIel

#define ImeitemIWdbeIniMFile1 IexWdbeIni::ImeitemIMFile1
#define ImeIWdbeIniMFile1 IexWdbeIni::ImeIMFile1
#define VecWImeIWdbeIniMFile1Iel IexWdbeIni::ImeIMFile1::VecWIel

#define ImeitemIWdbeIniAMLibraryMakefile IexWdbeIni::ImeitemIAMLibraryMakefile
#define ImeIWdbeIniAMLibraryMakefile IexWdbeIni::ImeIAMLibraryMakefile
#define VecWImeIWdbeIniAMLibraryMakefileIel IexWdbeIni::ImeIAMLibraryMakefile::VecWIel

#define ImeitemIWdbeIniMLibrary IexWdbeIni::ImeitemIMLibrary
#define ImeIWdbeIniMLibrary IexWdbeIni::ImeIMLibrary
#define VecWImeIWdbeIniMLibraryIel IexWdbeIni::ImeIMLibrary::VecWIel

#define ImeitemIWdbeIniAMMachineMakefile IexWdbeIni::ImeitemIAMMachineMakefile
#define ImeIWdbeIniAMMachineMakefile IexWdbeIni::ImeIAMMachineMakefile
#define VecWImeIWdbeIniAMMachineMakefileIel IexWdbeIni::ImeIAMMachineMakefile::VecWIel

#define ImeitemIWdbeIniAMMachinePar IexWdbeIni::ImeitemIAMMachinePar
#define ImeIWdbeIniAMMachinePar IexWdbeIni::ImeIAMMachinePar
#define VecWImeIWdbeIniAMMachineParIel IexWdbeIni::ImeIAMMachinePar::VecWIel

#define ImeitemIWdbeIniMMachine IexWdbeIni::ImeitemIMMachine
#define ImeIWdbeIniMMachine IexWdbeIni::ImeIMMachine
#define VecWImeIWdbeIniMMachineIel IexWdbeIni::ImeIMMachine::VecWIel

#define ImeitemIWdbeIniAMModulePar IexWdbeIni::ImeitemIAMModulePar
#define ImeIWdbeIniAMModulePar IexWdbeIni::ImeIAMModulePar
#define VecWImeIWdbeIniAMModuleParIel IexWdbeIni::ImeIAMModulePar::VecWIel

#define ImeitemIWdbeIniJAVKeylistKey3 IexWdbeIni::ImeitemIJAVKeylistKey3
#define ImeIWdbeIniJAVKeylistKey3 IexWdbeIni::ImeIJAVKeylistKey3
#define VecWImeIWdbeIniJAVKeylistKey3Iel IexWdbeIni::ImeIJAVKeylistKey3::VecWIel

#define ImeitemIWdbeIniAVKeylistKey3 IexWdbeIni::ImeitemIAVKeylistKey3
#define ImeIWdbeIniAVKeylistKey3 IexWdbeIni::ImeIAVKeylistKey3
#define VecWImeIWdbeIniAVKeylistKey3Iel IexWdbeIni::ImeIAVKeylistKey3::VecWIel

#define ImeitemIWdbeIniCGeneric IexWdbeIni::ImeitemICGeneric
#define ImeIWdbeIniCGeneric IexWdbeIni::ImeICGeneric
#define VecWImeIWdbeIniCGenericIel IexWdbeIni::ImeICGeneric::VecWIel

#define ImeitemIWdbeIniCPort IexWdbeIni::ImeitemICPort
#define ImeIWdbeIniCPort IexWdbeIni::ImeICPort
#define VecWImeIWdbeIniCPortIel IexWdbeIni::ImeICPort::VecWIel

#define ImeitemIWdbeIniCVariable IexWdbeIni::ImeitemICVariable
#define ImeIWdbeIniCVariable IexWdbeIni::ImeICVariable
#define VecWImeIWdbeIniCVariableIel IexWdbeIni::ImeICVariable::VecWIel

#define ImeitemIWdbeIniAMCommandInvpar IexWdbeIni::ImeitemIAMCommandInvpar
#define ImeIWdbeIniAMCommandInvpar IexWdbeIni::ImeIAMCommandInvpar
#define VecWImeIWdbeIniAMCommandInvparIel IexWdbeIni::ImeIAMCommandInvpar::VecWIel

#define ImeitemIWdbeIniAMCommandRetpar IexWdbeIni::ImeitemIAMCommandRetpar
#define ImeIWdbeIniAMCommandRetpar IexWdbeIni::ImeIAMCommandRetpar
#define VecWImeIWdbeIniAMCommandRetparIel IexWdbeIni::ImeIAMCommandRetpar::VecWIel

#define ImeitemIWdbeIniMCommand IexWdbeIni::ImeitemIMCommand
#define ImeIWdbeIniMCommand IexWdbeIni::ImeIMCommand
#define VecWImeIWdbeIniMCommandIel IexWdbeIni::ImeIMCommand::VecWIel

#define ImeitemIWdbeIniAMErrorPar IexWdbeIni::ImeitemIAMErrorPar
#define ImeIWdbeIniAMErrorPar IexWdbeIni::ImeIAMErrorPar
#define VecWImeIWdbeIniAMErrorParIel IexWdbeIni::ImeIAMErrorPar::VecWIel

#define ImeitemIWdbeIniMError IexWdbeIni::ImeitemIMError
#define ImeIWdbeIniMError IexWdbeIni::ImeIMError
#define VecWImeIWdbeIniMErrorIel IexWdbeIni::ImeIMError::VecWIel

#define ImeitemIWdbeIniMVectoritem IexWdbeIni::ImeitemIMVectoritem
#define ImeIWdbeIniMVectoritem IexWdbeIni::ImeIMVectoritem
#define VecWImeIWdbeIniMVectoritemIel IexWdbeIni::ImeIMVectoritem::VecWIel

#define ImeitemIWdbeIniMVector IexWdbeIni::ImeitemIMVector
#define ImeIWdbeIniMVector IexWdbeIni::ImeIMVector
#define VecWImeIWdbeIniMVectorIel IexWdbeIni::ImeIMVector::VecWIel

#define ImeitemIWdbeIniMController IexWdbeIni::ImeitemIMController
#define ImeIWdbeIniMController IexWdbeIni::ImeIMController
#define VecWImeIWdbeIniMControllerIel IexWdbeIni::ImeIMController::VecWIel

#define ImeitemIWdbeIniMFile2 IexWdbeIni::ImeitemIMFile2
#define ImeIWdbeIniMFile2 IexWdbeIni::ImeIMFile2
#define VecWImeIWdbeIniMFile2Iel IexWdbeIni::ImeIMFile2::VecWIel

#define ImeitemIWdbeIniMGeneric IexWdbeIni::ImeitemIMGeneric
#define ImeIWdbeIniMGeneric IexWdbeIni::ImeIMGeneric
#define VecWImeIWdbeIniMGenericIel IexWdbeIni::ImeIMGeneric::VecWIel

#define ImeitemIWdbeIniMPort IexWdbeIni::ImeitemIMPort
#define ImeIWdbeIniMPort IexWdbeIni::ImeIMPort
#define VecWImeIWdbeIniMPortIel IexWdbeIni::ImeIMPort::VecWIel

#define ImeitemIWdbeIniMVariable IexWdbeIni::ImeitemIMVariable
#define ImeIWdbeIniMVariable IexWdbeIni::ImeIMVariable
#define VecWImeIWdbeIniMVariableIel IexWdbeIni::ImeIMVariable::VecWIel

#define ImeitemIWdbeIniRMModuleMModule IexWdbeIni::ImeitemIRMModuleMModule
#define ImeIWdbeIniRMModuleMModule IexWdbeIni::ImeIRMModuleMModule
#define VecWImeIWdbeIniRMModuleMModuleIel IexWdbeIni::ImeIRMModuleMModule::VecWIel

#define ImeitemIWdbeIniMModule IexWdbeIni::ImeitemIMModule
#define ImeIWdbeIniMModule IexWdbeIni::ImeIMModule
#define VecWImeIWdbeIniMModuleIel IexWdbeIni::ImeIMModule::VecWIel

#define ImeitemIWdbeIniJMPinSref IexWdbeIni::ImeitemIJMPinSref
#define ImeIWdbeIniJMPinSref IexWdbeIni::ImeIJMPinSref
#define VecWImeIWdbeIniJMPinSrefIel IexWdbeIni::ImeIJMPinSref::VecWIel

#define ImeitemIWdbeIniMPin IexWdbeIni::ImeitemIMPin
#define ImeIWdbeIniMPin IexWdbeIni::ImeIMPin
#define VecWImeIWdbeIniMPinIel IexWdbeIni::ImeIMPin::VecWIel

#define ImeitemIWdbeIniMBank IexWdbeIni::ImeitemIMBank
#define ImeIWdbeIniMBank IexWdbeIni::ImeIMBank
#define VecWImeIWdbeIniMBankIel IexWdbeIni::ImeIMBank::VecWIel

#define ImeitemIWdbeIniJAVKeylistKey2 IexWdbeIni::ImeitemIJAVKeylistKey2
#define ImeIWdbeIniJAVKeylistKey2 IexWdbeIni::ImeIJAVKeylistKey2
#define VecWImeIWdbeIniJAVKeylistKey2Iel IexWdbeIni::ImeIJAVKeylistKey2::VecWIel

#define ImeitemIWdbeIniAVKeylistKey2 IexWdbeIni::ImeitemIAVKeylistKey2
#define ImeIWdbeIniAVKeylistKey2 IexWdbeIni::ImeIAVKeylistKey2
#define VecWImeIWdbeIniAVKeylistKey2Iel IexWdbeIni::ImeIAVKeylistKey2::VecWIel

#define ImeitemIWdbeIniMPeripheral IexWdbeIni::ImeitemIMPeripheral
#define ImeIWdbeIniMPeripheral IexWdbeIni::ImeIMPeripheral
#define VecWImeIWdbeIniMPeripheralIel IexWdbeIni::ImeIMPeripheral::VecWIel

#define ImeitemIWdbeIniMUnit IexWdbeIni::ImeitemIMUnit
#define ImeIWdbeIniMUnit IexWdbeIni::ImeIMUnit
#define VecWImeIWdbeIniMUnitIel IexWdbeIni::ImeIMUnit::VecWIel

#define ImeitemIWdbeIniAMUsergroupAccess IexWdbeIni::ImeitemIAMUsergroupAccess
#define ImeIWdbeIniAMUsergroupAccess IexWdbeIni::ImeIAMUsergroupAccess
#define VecWImeIWdbeIniAMUsergroupAccessIel IexWdbeIni::ImeIAMUsergroupAccess::VecWIel

#define ImeitemIWdbeIniAMUserAccess IexWdbeIni::ImeitemIAMUserAccess
#define ImeIWdbeIniAMUserAccess IexWdbeIni::ImeIAMUserAccess
#define VecWImeIWdbeIniAMUserAccessIel IexWdbeIni::ImeIAMUserAccess::VecWIel

#define ImeitemIWdbeIniJMUserState IexWdbeIni::ImeitemIJMUserState
#define ImeIWdbeIniJMUserState IexWdbeIni::ImeIJMUserState
#define VecWImeIWdbeIniJMUserStateIel IexWdbeIni::ImeIJMUserState::VecWIel

#define ImeitemIWdbeIniJMPersonLastname IexWdbeIni::ImeitemIJMPersonLastname
#define ImeIWdbeIniJMPersonLastname IexWdbeIni::ImeIJMPersonLastname
#define VecWImeIWdbeIniJMPersonLastnameIel IexWdbeIni::ImeIJMPersonLastname::VecWIel

#define ImeitemIWdbeIniMPerson IexWdbeIni::ImeitemIMPerson
#define ImeIWdbeIniMPerson IexWdbeIni::ImeIMPerson
#define VecWImeIWdbeIniMPersonIel IexWdbeIni::ImeIMPerson::VecWIel

#define ImeitemIWdbeIniMUser IexWdbeIni::ImeitemIMUser
#define ImeIWdbeIniMUser IexWdbeIni::ImeIMUser
#define VecWImeIWdbeIniMUserIel IexWdbeIni::ImeIMUser::VecWIel

#define ImeitemIWdbeIniMUsergroup IexWdbeIni::ImeitemIMUsergroup
#define ImeIWdbeIniMUsergroup IexWdbeIni::ImeIMUsergroup
#define VecWImeIWdbeIniMUsergroupIel IexWdbeIni::ImeIMUsergroup::VecWIel

/**
	* IexWdbeIni
	*/
namespace IexWdbeIni {
	/**
		* VecVIme (full: VecVIexWdbeIniIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMCOMMANDINVPAR = 1;
		static const Sbecore::uint IMEIAMCOMMANDRETPAR = 2;
		static const Sbecore::uint IMEIAMERRORPAR = 3;
		static const Sbecore::uint IMEIAMLIBRARYMAKEFILE = 4;
		static const Sbecore::uint IMEIAMMACHINEMAKEFILE = 5;
		static const Sbecore::uint IMEIAMMACHINEPAR = 6;
		static const Sbecore::uint IMEIAMMODULEPAR = 7;
		static const Sbecore::uint IMEIAMUSERACCESS = 8;
		static const Sbecore::uint IMEIAMUSERGROUPACCESS = 9;
		static const Sbecore::uint IMEIAVCONTROLPAR = 10;
		static const Sbecore::uint IMEIAVKEYLISTKEY1 = 11;
		static const Sbecore::uint IMEIAVKEYLISTKEY2 = 12;
		static const Sbecore::uint IMEIAVKEYLISTKEY3 = 13;
		static const Sbecore::uint IMEIAVVALUELISTVAL = 14;
		static const Sbecore::uint IMEICGENERIC = 15;
		static const Sbecore::uint IMEICPORT = 16;
		static const Sbecore::uint IMEICVARIABLE = 17;
		static const Sbecore::uint IMEIJAVKEYLISTKEY1 = 18;
		static const Sbecore::uint IMEIJAVKEYLISTKEY2 = 19;
		static const Sbecore::uint IMEIJAVKEYLISTKEY3 = 20;
		static const Sbecore::uint IMEIJMCOREVERSIONSTATE = 21;
		static const Sbecore::uint IMEIJMPERSONLASTNAME = 22;
		static const Sbecore::uint IMEIJMPINSREF = 23;
		static const Sbecore::uint IMEIJMUSERSTATE = 24;
		static const Sbecore::uint IMEIMBANK = 25;
		static const Sbecore::uint IMEIMCOMMAND = 26;
		static const Sbecore::uint IMEIMCONTROLLER = 27;
		static const Sbecore::uint IMEIMCOREPROJECT = 28;
		static const Sbecore::uint IMEIMCOREVERSION = 29;
		static const Sbecore::uint IMEIMERROR = 30;
		static const Sbecore::uint IMEIMFAMILY = 31;
		static const Sbecore::uint IMEIMFILE1 = 32;
		static const Sbecore::uint IMEIMFILE2 = 33;
		static const Sbecore::uint IMEIMGENERIC = 34;
		static const Sbecore::uint IMEIMLIBRARY = 35;
		static const Sbecore::uint IMEIMMACHINE = 36;
		static const Sbecore::uint IMEIMMODULE = 37;
		static const Sbecore::uint IMEIMPERIPHERAL = 38;
		static const Sbecore::uint IMEIMPERSON = 39;
		static const Sbecore::uint IMEIMPIN = 40;
		static const Sbecore::uint IMEIMPORT = 41;
		static const Sbecore::uint IMEIMUNIT = 42;
		static const Sbecore::uint IMEIMUSER = 43;
		static const Sbecore::uint IMEIMUSERGROUP = 44;
		static const Sbecore::uint IMEIMVARIABLE = 45;
		static const Sbecore::uint IMEIMVECTOR = 46;
		static const Sbecore::uint IMEIMVECTORITEM = 47;
		static const Sbecore::uint IMEIRMCOREPROJECTMPERSON = 48;
		static const Sbecore::uint IMEIRMMODULEMMODULE = 49;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAVControlPar (full: ImeitemIWdbeIniAVControlPar)
		*/
	class ImeitemIAVControlPar : public WdbeAVControlPar {

	public:
		ImeitemIAVControlPar(const Sbecore::uint ixWdbeVControl = 0, const std::string& Par = "", const std::string& Val = "");
		ImeitemIAVControlPar(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxWdbeVControl;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVControlPar (full: ImeIWdbeIniAVControlPar)
		*/
	class ImeIAVControlPar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAVControlParIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWDBEVCONTROL = 1;
			static const Sbecore::uint PAR = 2;
			static const Sbecore::uint VAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVControlPar();
		~ImeIAVControlPar();

	public:
		std::vector<ImeitemIAVControlPar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey1 (full: ImeitemIWdbeIniJAVKeylistKey1)
		*/
	class ImeitemIJAVKeylistKey1 : public WdbeJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey1(const Sbecore::uint x1IxWdbeVLocale = 0, const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJAVKeylistKey1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWdbeVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey1 (full: ImeIWdbeIniJAVKeylistKey1)
		*/
	class ImeIJAVKeylistKey1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniJAVKeylistKey1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWDBEVLOCALE = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAVKeylistKey1();
		~ImeIJAVKeylistKey1();

	public:
		std::vector<ImeitemIJAVKeylistKey1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey1 (full: ImeitemIWdbeIniAVKeylistKey1)
		*/
	class ImeitemIAVKeylistKey1 : public WdbeAVKeylistKey {

	public:
		ImeitemIAVKeylistKey1(const Sbecore::uint klsIxWdbeVKeylist = 0, const std::string& sref = "", const std::string& Avail = "", const std::string& Implied = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIAVKeylistKey1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefKlsIxWdbeVKeylist;

		ImeIJAVKeylistKey1 imeijavkeylistkey1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey1 (full: ImeIWdbeIniAVKeylistKey1)
		*/
	class ImeIAVKeylistKey1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAVKeylistKey1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFKLSIXWDBEVKEYLIST = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint AVAIL = 4;
			static const Sbecore::uint IMPLIED = 8;
			static const Sbecore::uint TITLE = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVKeylistKey1();
		~ImeIAVKeylistKey1();

	public:
		std::vector<ImeitemIAVKeylistKey1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVValuelistVal (full: ImeitemIWdbeIniAVValuelistVal)
		*/
	class ImeitemIAVValuelistVal : public WdbeAVValuelistVal {

	public:
		ImeitemIAVValuelistVal(const Sbecore::uint vlsIxWdbeVValuelist = 0, const Sbecore::uint x1IxWdbeVLocale = 0, const std::string& Val = "");
		ImeitemIAVValuelistVal(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefVlsIxWdbeVValuelist;
		std::string srefX1IxWdbeVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVValuelistVal (full: ImeIWdbeIniAVValuelistVal)
		*/
	class ImeIAVValuelistVal {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAVValuelistValIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFVLSIXWDBEVVALUELIST = 1;
			static const Sbecore::uint SREFX1IXWDBEVLOCALE = 2;
			static const Sbecore::uint VAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVValuelistVal();
		~ImeIAVValuelistVal();

	public:
		std::vector<ImeitemIAVValuelistVal*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMCoreversionState (full: ImeitemIWdbeIniJMCoreversionState)
		*/
	class ImeitemIJMCoreversionState : public WdbeJMCoreversionState {

	public:
		ImeitemIJMCoreversionState(const Sbecore::uint ixVState = 0);
		ImeitemIJMCoreversionState(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMCoreversionState (full: ImeIWdbeIniJMCoreversionState)
		*/
	class ImeIJMCoreversionState {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniJMCoreversionStateIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSTATE = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMCoreversionState();
		~ImeIJMCoreversionState();

	public:
		std::vector<ImeitemIJMCoreversionState*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCoreversion (full: ImeitemIWdbeIniMCoreversion)
		*/
	class ImeitemIMCoreversion : public WdbeMCoreversion {

	public:
		ImeitemIMCoreversion(const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::uint ixVState = 0, const Sbecore::uint ixWSpectype = 0);
		ImeitemIMCoreversion(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;
		std::string srefsIxWSpectype;

		ImeIJMCoreversionState imeijmcoreversionstate;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCoreversion (full: ImeIWdbeIniMCoreversion)
		*/
	class ImeIMCoreversion {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMCoreversionIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint MAJOR = 1;
			static const Sbecore::uint MINOR = 2;
			static const Sbecore::uint SUB = 4;
			static const Sbecore::uint SREFIXVSTATE = 8;
			static const Sbecore::uint SREFSIXWSPECTYPE = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMCoreversion();
		~ImeIMCoreversion();

	public:
		std::vector<ImeitemIMCoreversion*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMCoreprojectMPerson (full: ImeitemIWdbeIniRMCoreprojectMPerson)
		*/
	class ImeitemIRMCoreprojectMPerson : public WdbeRMCoreprojectMPerson {

	public:
		ImeitemIRMCoreprojectMPerson(const std::string& hintRefWdbeMPerson = "", const std::string& srefKFunction = "");
		ImeitemIRMCoreprojectMPerson(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hintRefWdbeMPerson;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMCoreprojectMPerson (full: ImeIWdbeIniRMCoreprojectMPerson)
		*/
	class ImeIRMCoreprojectMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniRMCoreprojectMPersonIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint HINTREFWDBEMPERSON = 1;
			static const Sbecore::uint SREFKFUNCTION = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMCoreprojectMPerson();
		~ImeIRMCoreprojectMPerson();

	public:
		std::vector<ImeitemIRMCoreprojectMPerson*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCoreproject (full: ImeitemIWdbeIniMCoreproject)
		*/
	class ImeitemIMCoreproject : public WdbeMCoreproject {

	public:
		ImeitemIMCoreproject(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& Title = "", const std::string& Giturl = "", const std::string& Comment = "");
		ImeitemIMCoreproject(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

		ImeIMCoreversion imeimcoreversion;
		ImeIRMCoreprojectMPerson imeirmcoreprojectmperson;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCoreproject (full: ImeIWdbeIniMCoreproject)
		*/
	class ImeIMCoreproject {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMCoreprojectIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint TITLE = 4;
			static const Sbecore::uint GITURL = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMCoreproject();
		~ImeIMCoreproject();

	public:
		std::vector<ImeitemIMCoreproject*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFamily (full: ImeitemIWdbeIniMFamily)
		*/
	class ImeitemIMFamily : public WdbeMFamily {

	public:
		ImeitemIMFamily(const Sbecore::ubigint iref = 0, const std::string& srefWdbeKVendor = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIMFamily(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint iref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFamily (full: ImeIWdbeIniMFamily)
		*/
	class ImeIMFamily {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMFamilyIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;
			static const Sbecore::uint SREFWDBEKVENDOR = 2;
			static const Sbecore::uint TITLE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFamily();
		~ImeIMFamily();

	public:
		std::vector<ImeitemIMFamily*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile1 (full: ImeitemIWdbeIniMFile1)
		*/
	class ImeitemIMFile1 : public WdbeMFile {

	public:
		ImeitemIMFile1(const std::string& osrefKContent = "", const std::string& Filename = "", const std::string& srefKMimetype = "", const std::string& Comment = "");
		ImeitemIMFile1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFile1 (full: ImeIWdbeIniMFile1)
		*/
	class ImeIMFile1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMFile1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint OSREFKCONTENT = 1;
			static const Sbecore::uint FILENAME = 2;
			static const Sbecore::uint SREFKMIMETYPE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFile1();
		~ImeIMFile1();

	public:
		std::vector<ImeitemIMFile1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMLibraryMakefile (full: ImeitemIWdbeIniAMLibraryMakefile)
		*/
	class ImeitemIAMLibraryMakefile : public WdbeAMLibraryMakefile {

	public:
		ImeitemIAMLibraryMakefile(const std::string& hsrefX1RefWdbeMMachine = "", const std::string& x2SrefKTag = "", const std::string& Val = "");
		ImeitemIAMLibraryMakefile(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hsrefX1RefWdbeMMachine;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMLibraryMakefile (full: ImeIWdbeIniAMLibraryMakefile)
		*/
	class ImeIAMLibraryMakefile {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAMLibraryMakefileIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint HSREFX1REFWDBEMMACHINE = 1;
			static const Sbecore::uint X2SREFKTAG = 2;
			static const Sbecore::uint VAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMLibraryMakefile();
		~ImeIAMLibraryMakefile();

	public:
		std::vector<ImeitemIAMLibraryMakefile*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMLibrary (full: ImeitemIWdbeIniMLibrary)
		*/
	class ImeitemIMLibrary : public WdbeMLibrary {

	public:
		ImeitemIMLibrary(const std::string& sref = "", const std::string& Title = "", const std::string& Version = "", const std::string& depSrefsWdbeMLibrary = "", const std::string& Comment = "");
		ImeitemIMLibrary(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMLibraryMakefile imeiamlibrarymakefile;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMLibrary (full: ImeIWdbeIniMLibrary)
		*/
	class ImeIMLibrary {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMLibraryIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint VERSION = 4;
			static const Sbecore::uint DEPSREFSWDBEMLIBRARY = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMLibrary();
		~ImeIMLibrary();

	public:
		std::vector<ImeitemIMLibrary*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMMachineMakefile (full: ImeitemIWdbeIniAMMachineMakefile)
		*/
	class ImeitemIAMMachineMakefile : public WdbeAMMachineMakefile {

	public:
		ImeitemIAMMachineMakefile(const std::string& x1SrefKTag = "", const std::string& Val = "");
		ImeitemIAMMachineMakefile(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMMachineMakefile (full: ImeIWdbeIniAMMachineMakefile)
		*/
	class ImeIAMMachineMakefile {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAMMachineMakefileIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint X1SREFKTAG = 1;
			static const Sbecore::uint VAL = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMMachineMakefile();
		~ImeIAMMachineMakefile();

	public:
		std::vector<ImeitemIAMMachineMakefile*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMMachinePar (full: ImeitemIWdbeIniAMMachinePar)
		*/
	class ImeitemIAMMachinePar : public WdbeAMMachinePar {

	public:
		ImeitemIAMMachinePar(const std::string& x1SrefKKey = "", const std::string& Val = "");
		ImeitemIAMMachinePar(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMMachinePar (full: ImeIWdbeIniAMMachinePar)
		*/
	class ImeIAMMachinePar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAMMachineParIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint X1SREFKKEY = 1;
			static const Sbecore::uint VAL = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMMachinePar();
		~ImeIAMMachinePar();

	public:
		std::vector<ImeitemIAMMachinePar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMMachine (full: ImeitemIWdbeIniMMachine)
		*/
	class ImeitemIMMachine : public WdbeMMachine {

	public:
		ImeitemIMMachine(const std::string& hsrefSupRefWdbeMMachine = "", const std::string& sref = "", const std::string& hsrefCchRefWdbeMMachine = "", const std::string& Comment = "");
		ImeitemIMMachine(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hsrefSupRefWdbeMMachine;
		std::string hsrefCchRefWdbeMMachine;

		ImeIAMMachineMakefile imeiammachinemakefile;
		ImeIAMMachinePar imeiammachinepar;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMMachine (full: ImeIWdbeIniMMachine)
		*/
	class ImeIMMachine {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMMachineIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint HSREFSUPREFWDBEMMACHINE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint HSREFCCHREFWDBEMMACHINE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMMachine();
		~ImeIMMachine();

	public:
		std::vector<ImeitemIMMachine*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMModulePar (full: ImeitemIWdbeIniAMModulePar)
		*/
	class ImeitemIAMModulePar : public WdbeAMModulePar {

	public:
		ImeitemIAMModulePar(const std::string& x1SrefKKey = "", const std::string& Val = "");
		ImeitemIAMModulePar(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMModulePar (full: ImeIWdbeIniAMModulePar)
		*/
	class ImeIAMModulePar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAMModuleParIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint X1SREFKKEY = 1;
			static const Sbecore::uint VAL = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMModulePar();
		~ImeIAMModulePar();

	public:
		std::vector<ImeitemIAMModulePar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey3 (full: ImeitemIWdbeIniJAVKeylistKey3)
		*/
	class ImeitemIJAVKeylistKey3 : public WdbeJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey3(const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJAVKeylistKey3(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey3 (full: ImeIWdbeIniJAVKeylistKey3)
		*/
	class ImeIJAVKeylistKey3 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniJAVKeylistKey3Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint TITLE = 1;
			static const Sbecore::uint COMMENT = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAVKeylistKey3();
		~ImeIJAVKeylistKey3();

	public:
		std::vector<ImeitemIJAVKeylistKey3*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey3 (full: ImeitemIWdbeIniAVKeylistKey3)
		*/
	class ImeitemIAVKeylistKey3 : public WdbeAVKeylistKey {

	public:
		ImeitemIAVKeylistKey3(const Sbecore::uint klsIxWdbeVKeylist = 0, const std::string& sref = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIAVKeylistKey3(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefKlsIxWdbeVKeylist;

		ImeIJAVKeylistKey3 imeijavkeylistkey3;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey3 (full: ImeIWdbeIniAVKeylistKey3)
		*/
	class ImeIAVKeylistKey3 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAVKeylistKey3Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFKLSIXWDBEVKEYLIST = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint TITLE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVKeylistKey3();
		~ImeIAVKeylistKey3();

	public:
		std::vector<ImeitemIAVKeylistKey3*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICGeneric (full: ImeitemIWdbeIniCGeneric)
		*/
	class ImeitemICGeneric {

	public:
		ImeitemICGeneric(const Sbecore::ubigint iref = 0);
		ImeitemICGeneric(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint iref;
		Sbecore::ubigint ref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeICGeneric (full: ImeIWdbeIniCGeneric)
		*/
	class ImeICGeneric {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniCGenericIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICGeneric();
		~ImeICGeneric();

	public:
		std::vector<ImeitemICGeneric*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICPort (full: ImeitemIWdbeIniCPort)
		*/
	class ImeitemICPort {

	public:
		ImeitemICPort(const Sbecore::ubigint iref = 0);
		ImeitemICPort(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint iref;
		Sbecore::ubigint ref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeICPort (full: ImeIWdbeIniCPort)
		*/
	class ImeICPort {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniCPortIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICPort();
		~ImeICPort();

	public:
		std::vector<ImeitemICPort*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICVariable (full: ImeitemIWdbeIniCVariable)
		*/
	class ImeitemICVariable {

	public:
		ImeitemICVariable(const Sbecore::ubigint iref = 0);
		ImeitemICVariable(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint iref;
		Sbecore::ubigint ref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeICVariable (full: ImeIWdbeIniCVariable)
		*/
	class ImeICVariable {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniCVariableIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICVariable();
		~ImeICVariable();

	public:
		std::vector<ImeitemICVariable*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMCommandInvpar (full: ImeitemIWdbeIniAMCommandInvpar)
		*/
	class ImeitemIAMCommandInvpar : public WdbeAMCommandInvpar {

	public:
		ImeitemIAMCommandInvpar(const std::string& sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string& srefRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string& Defval = "", const std::string& srefRefWdbeMVectoritem = "", const std::string& Comment = "");
		ImeitemIAMCommandInvpar(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxWdbeVPartype;
		std::string srefRefWdbeMVector;
		std::string srefRefWdbeMVectoritem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMCommandInvpar (full: ImeIWdbeIniAMCommandInvpar)
		*/
	class ImeIAMCommandInvpar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAMCommandInvparIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXWDBEVPARTYPE = 2;
			static const Sbecore::uint SREFREFWDBEMVECTOR = 4;
			static const Sbecore::uint LENGTH = 8;
			static const Sbecore::uint DEFVAL = 16;
			static const Sbecore::uint SREFREFWDBEMVECTORITEM = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMCommandInvpar();
		~ImeIAMCommandInvpar();

	public:
		std::vector<ImeitemIAMCommandInvpar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMCommandRetpar (full: ImeitemIWdbeIniAMCommandRetpar)
		*/
	class ImeitemIAMCommandRetpar : public WdbeAMCommandRetpar {

	public:
		ImeitemIAMCommandRetpar(const std::string& sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string& srefRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string& Comment = "");
		ImeitemIAMCommandRetpar(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxWdbeVPartype;
		std::string srefRefWdbeMVector;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMCommandRetpar (full: ImeIWdbeIniAMCommandRetpar)
		*/
	class ImeIAMCommandRetpar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAMCommandRetparIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXWDBEVPARTYPE = 2;
			static const Sbecore::uint SREFREFWDBEMVECTOR = 4;
			static const Sbecore::uint LENGTH = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMCommandRetpar();
		~ImeIAMCommandRetpar();

	public:
		std::vector<ImeitemIAMCommandRetpar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCommand (full: ImeitemIWdbeIniMCommand)
		*/
	class ImeitemIMCommand : public WdbeMCommand {

	public:
		ImeitemIMCommand(const Sbecore::uint refNum = 0, const std::string& sref = "", const Sbecore::uint ixVRettype = 0, const std::string& Comment = "");
		ImeitemIMCommand(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVRettype;

		ImeIAMCommandInvpar imeiamcommandinvpar;
		ImeIAMCommandRetpar imeiamcommandretpar;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCommand (full: ImeIWdbeIniMCommand)
		*/
	class ImeIMCommand {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMCommandIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint REFNUM = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFIXVRETTYPE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMCommand();
		~ImeIMCommand();

	public:
		std::vector<ImeitemIMCommand*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMErrorPar (full: ImeitemIWdbeIniAMErrorPar)
		*/
	class ImeitemIAMErrorPar : public WdbeAMErrorPar {

	public:
		ImeitemIAMErrorPar(const std::string& sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string& srefRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string& Comment = "");
		ImeitemIAMErrorPar(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxWdbeVPartype;
		std::string srefRefWdbeMVector;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMErrorPar (full: ImeIWdbeIniAMErrorPar)
		*/
	class ImeIAMErrorPar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAMErrorParIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXWDBEVPARTYPE = 2;
			static const Sbecore::uint SREFREFWDBEMVECTOR = 4;
			static const Sbecore::uint LENGTH = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMErrorPar();
		~ImeIAMErrorPar();

	public:
		std::vector<ImeitemIAMErrorPar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMError (full: ImeitemIWdbeIniMError)
		*/
	class ImeitemIMError : public WdbeMError {

	public:
		ImeitemIMError(const Sbecore::uint refNum = 0, const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMError(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMErrorPar imeiamerrorpar;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMError (full: ImeIWdbeIniMError)
		*/
	class ImeIMError {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMErrorIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint REFNUM = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMError();
		~ImeIMError();

	public:
		std::vector<ImeitemIMError*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVectoritem (full: ImeitemIWdbeIniMVectoritem)
		*/
	class ImeitemIMVectoritem : public WdbeMVectoritem {

	public:
		ImeitemIMVectoritem(const std::string& sref = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIMVectoritem(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVectoritem (full: ImeIWdbeIniMVectoritem)
		*/
	class ImeIMVectoritem {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMVectoritemIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMVectoritem();
		~ImeIMVectoritem();

	public:
		std::vector<ImeitemIMVectoritem*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVector (full: ImeitemIWdbeIniMVector)
		*/
	class ImeitemIMVector : public WdbeMVector {

	public:
		ImeitemIMVector(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& srefsKOption = "");
		ImeitemIMVector(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

		ImeIMVectoritem imeimvectoritem;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVector (full: ImeIWdbeIniMVector)
		*/
	class ImeIMVector {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMVectorIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFSKOPTION = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMVector();
		~ImeIMVector();

	public:
		std::vector<ImeitemIMVector*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMController (full: ImeitemIWdbeIniMController)
		*/
	class ImeitemIMController : public WdbeMController {

	public:
		ImeitemIMController();
		ImeitemIMController(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIMCommand imeimcommand;
		ImeIMError imeimerror;
		ImeIMVector imeimvector;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMController (full: ImeIWdbeIniMController)
		*/
	class ImeIMController {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMControllerIel)
			*/
		class VecWIel {

		public:

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMController();
		~ImeIMController();

	public:
		std::vector<ImeitemIMController*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile2 (full: ImeitemIWdbeIniMFile2)
		*/
	class ImeitemIMFile2 : public WdbeMFile {

	public:
		ImeitemIMFile2(const std::string& osrefKContent = "", const std::string& Filename = "", const std::string& srefKMimetype = "", const std::string& Comment = "");
		ImeitemIMFile2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFile2 (full: ImeIWdbeIniMFile2)
		*/
	class ImeIMFile2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMFile2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint OSREFKCONTENT = 1;
			static const Sbecore::uint FILENAME = 2;
			static const Sbecore::uint SREFKMIMETYPE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFile2();
		~ImeIMFile2();

	public:
		std::vector<ImeitemIMFile2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMGeneric (full: ImeitemIWdbeIniMGeneric)
		*/
	class ImeitemIMGeneric : public WdbeMGeneric {

	public:
		ImeitemIMGeneric(const Sbecore::ubigint irefRefWdbeCGeneric = 0, const std::string& sref = "", const std::string& srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const std::string& Defval = "", const std::string& Comment = "");
		ImeitemIMGeneric(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWdbeCGeneric;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMGeneric (full: ImeIWdbeIniMGeneric)
		*/
	class ImeIMGeneric {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMGenericIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWDBECGENERIC = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFWDBEKHDLTYPE = 4;
			static const Sbecore::uint WIDTH = 8;
			static const Sbecore::uint MINMAX = 16;
			static const Sbecore::uint DEFVAL = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMGeneric();
		~ImeIMGeneric();

	public:
		std::vector<ImeitemIMGeneric*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPort (full: ImeitemIWdbeIniMPort)
		*/
	class ImeitemIMPort : public WdbeMPort {

	public:
		ImeitemIMPort(const Sbecore::ubigint irefRefWdbeCPort = 0, const Sbecore::uint mdlIxVCat = 0, const std::string& sref = "", const Sbecore::uint ixVDir = 0, const std::string& srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const std::string& Defval = "", const std::string& Comment = "");
		ImeitemIMPort(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWdbeCPort;
		std::string srefMdlIxVCat;
		std::string srefIxVDir;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPort (full: ImeIWdbeIniMPort)
		*/
	class ImeIMPort {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMPortIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWDBECPORT = 1;
			static const Sbecore::uint SREFMDLIXVCAT = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint SREFIXVDIR = 8;
			static const Sbecore::uint SREFWDBEKHDLTYPE = 16;
			static const Sbecore::uint WIDTH = 32;
			static const Sbecore::uint MINMAX = 64;
			static const Sbecore::uint DEFVAL = 128;
			static const Sbecore::uint COMMENT = 256;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPort();
		~ImeIMPort();

	public:
		std::vector<ImeitemIMPort*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVariable (full: ImeitemIWdbeIniMVariable)
		*/
	class ImeitemIMVariable : public WdbeMVariable {

	public:
		ImeitemIMVariable(const Sbecore::ubigint irefRefWdbeCVariable = 0, const std::string& sref = "", const std::string& srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const std::string& Comment = "");
		ImeitemIMVariable(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWdbeCVariable;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVariable (full: ImeIWdbeIniMVariable)
		*/
	class ImeIMVariable {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMVariableIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWDBECVARIABLE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFWDBEKHDLTYPE = 4;
			static const Sbecore::uint WIDTH = 8;
			static const Sbecore::uint MINMAX = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMVariable();
		~ImeIMVariable();

	public:
		std::vector<ImeitemIMVariable*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMModuleMModule (full: ImeitemIWdbeIniRMModuleMModule)
		*/
	class ImeitemIRMModuleMModule : public WdbeRMModuleMModule {

	public:
		ImeitemIRMModuleMModule(const std::string& srefKFunction = "");
		ImeitemIRMModuleMModule(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMModuleMModule (full: ImeIWdbeIniRMModuleMModule)
		*/
	class ImeIRMModuleMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniRMModuleMModuleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFKFUNCTION = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMModuleMModule();
		~ImeIRMModuleMModule();

	public:
		std::vector<ImeitemIRMModuleMModule*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMModule (full: ImeitemIWdbeIniMModule)
		*/
	class ImeitemIMModule : public WdbeMModule {

	public:
		ImeitemIMModule(const Sbecore::uint ixVBasetype = 0, const std::string& hsrefSupRefWdbeMModule = "", const std::string& srefTplRefWdbeMModule = "", const std::string& sref = "", const std::string& srefWdbeKVendor = "", const std::string& Srefrule = "", const std::string& Comment = "");
		ImeitemIMModule(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string hsrefSupRefWdbeMModule;
		std::string srefTplRefWdbeMModule;

		ImeIAMModulePar imeiammodulepar;
		ImeIAVKeylistKey3 imeiavkeylistkey3;
		ImeICGeneric imeicgeneric;
		ImeICPort imeicport;
		ImeICVariable imeicvariable;
		ImeIMController imeimcontroller;
		ImeIMFile2 imeimfile2;
		ImeIMGeneric imeimgeneric;
		ImeIMPort imeimport;
		ImeIMVariable imeimvariable;
		ImeIRMModuleMModule imeirmmodulemmodule;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMModule (full: ImeIWdbeIniMModule)
		*/
	class ImeIMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMModuleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint HSREFSUPREFWDBEMMODULE = 2;
			static const Sbecore::uint SREFTPLREFWDBEMMODULE = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint SREFWDBEKVENDOR = 16;
			static const Sbecore::uint SREFRULE = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMModule();
		~ImeIMModule();

	public:
		std::vector<ImeitemIMModule*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMPinSref (full: ImeitemIWdbeIniJMPinSref)
		*/
	class ImeitemIJMPinSref : public WdbeJMPinSref {

	public:
		ImeitemIJMPinSref(const std::string& srefX1RefWdbeMPeripheral = "", const std::string& sref = "");
		ImeitemIJMPinSref(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1RefWdbeMPeripheral;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMPinSref (full: ImeIWdbeIniJMPinSref)
		*/
	class ImeIJMPinSref {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniJMPinSrefIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1REFWDBEMPERIPHERAL = 1;
			static const Sbecore::uint SREF = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMPinSref();
		~ImeIJMPinSref();

	public:
		std::vector<ImeitemIJMPinSref*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPin (full: ImeitemIWdbeIniMPin)
		*/
	class ImeitemIMPin : public WdbeMPin {

	public:
		ImeitemIMPin(const std::string& sref = "", const std::string& Location = "");
		ImeitemIMPin(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJMPinSref imeijmpinsref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPin (full: ImeIWdbeIniMPin)
		*/
	class ImeIMPin {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMPinIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint LOCATION = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPin();
		~ImeIMPin();

	public:
		std::vector<ImeitemIMPin*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMBank (full: ImeitemIWdbeIniMBank)
		*/
	class ImeitemIMBank : public WdbeMBank {

	public:
		ImeitemIMBank(const std::string& sref = "");
		ImeitemIMBank(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIMPin imeimpin;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMBank (full: ImeIWdbeIniMBank)
		*/
	class ImeIMBank {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMBankIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMBank();
		~ImeIMBank();

	public:
		std::vector<ImeitemIMBank*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey2 (full: ImeitemIWdbeIniJAVKeylistKey2)
		*/
	class ImeitemIJAVKeylistKey2 : public WdbeJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey2(const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJAVKeylistKey2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey2 (full: ImeIWdbeIniJAVKeylistKey2)
		*/
	class ImeIJAVKeylistKey2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniJAVKeylistKey2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint TITLE = 1;
			static const Sbecore::uint COMMENT = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAVKeylistKey2();
		~ImeIJAVKeylistKey2();

	public:
		std::vector<ImeitemIJAVKeylistKey2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey2 (full: ImeitemIWdbeIniAVKeylistKey2)
		*/
	class ImeitemIAVKeylistKey2 : public WdbeAVKeylistKey {

	public:
		ImeitemIAVKeylistKey2(const std::string& sref = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIAVKeylistKey2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJAVKeylistKey2 imeijavkeylistkey2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey2 (full: ImeIWdbeIniAVKeylistKey2)
		*/
	class ImeIAVKeylistKey2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAVKeylistKey2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVKeylistKey2();
		~ImeIAVKeylistKey2();

	public:
		std::vector<ImeitemIAVKeylistKey2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPeripheral (full: ImeitemIWdbeIniMPeripheral)
		*/
	class ImeitemIMPeripheral : public WdbeMPeripheral {

	public:
		ImeitemIMPeripheral(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMPeripheral(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAVKeylistKey2 imeiavkeylistkey2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPeripheral (full: ImeIWdbeIniMPeripheral)
		*/
	class ImeIMPeripheral {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMPeripheralIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint COMMENT = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPeripheral();
		~ImeIMPeripheral();

	public:
		std::vector<ImeitemIMPeripheral*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUnit (full: ImeitemIWdbeIniMUnit)
		*/
	class ImeitemIMUnit : public WdbeMUnit {

	public:
		ImeitemIMUnit(const Sbecore::uint ixVBasetype = 0, const Sbecore::uint refIxVTbl = 0, const Sbecore::ubigint irefRefUref = 0, const std::string& sref = "", const std::string& Title = "", const std::string& srefKPackage = "", const std::string& Comment = "");
		ImeitemIMUnit(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefRefIxVTbl;
		Sbecore::ubigint irefRefUref;

		ImeIMBank imeimbank;
		ImeIMPeripheral imeimperipheral;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUnit (full: ImeIWdbeIniMUnit)
		*/
	class ImeIMUnit {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMUnitIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFREFIXVTBL = 2;
			static const Sbecore::uint IREFREFUREF = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint TITLE = 16;
			static const Sbecore::uint SREFKPACKAGE = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMUnit();
		~ImeIMUnit();

	public:
		std::vector<ImeitemIMUnit*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUsergroupAccess (full: ImeitemIWdbeIniAMUsergroupAccess)
		*/
	class ImeitemIAMUsergroupAccess : public WdbeAMUsergroupAccess {

	public:
		ImeitemIAMUsergroupAccess(const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string& x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0);
		ImeitemIAMUsergroupAccess(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWdbeVFeatgroup;
		std::string srefsIxWdbeWAccess;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUsergroupAccess (full: ImeIWdbeIniAMUsergroupAccess)
		*/
	class ImeIAMUsergroupAccess {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAMUsergroupAccessIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWDBEVFEATGROUP = 1;
			static const Sbecore::uint X2FEASREFUIX = 2;
			static const Sbecore::uint SREFSIXWDBEWACCESS = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMUsergroupAccess();
		~ImeIAMUsergroupAccess();

	public:
		std::vector<ImeitemIAMUsergroupAccess*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUserAccess (full: ImeitemIWdbeIniAMUserAccess)
		*/
	class ImeitemIAMUserAccess : public WdbeAMUserAccess {

	public:
		ImeitemIAMUserAccess(const Sbecore::uint x1IxWdbeVFeatgroup = 0, const std::string& x2FeaSrefUix = "", const Sbecore::uint ixWdbeWAccess = 0);
		ImeitemIAMUserAccess(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWdbeVFeatgroup;
		std::string srefsIxWdbeWAccess;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUserAccess (full: ImeIWdbeIniAMUserAccess)
		*/
	class ImeIAMUserAccess {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniAMUserAccessIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWDBEVFEATGROUP = 1;
			static const Sbecore::uint X2FEASREFUIX = 2;
			static const Sbecore::uint SREFSIXWDBEWACCESS = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMUserAccess();
		~ImeIAMUserAccess();

	public:
		std::vector<ImeitemIAMUserAccess*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMUserState (full: ImeitemIWdbeIniJMUserState)
		*/
	class ImeitemIJMUserState : public WdbeJMUserState {

	public:
		ImeitemIJMUserState(const Sbecore::uint ixVState = 0);
		ImeitemIJMUserState(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMUserState (full: ImeIWdbeIniJMUserState)
		*/
	class ImeIJMUserState {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniJMUserStateIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSTATE = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMUserState();
		~ImeIJMUserState();

	public:
		std::vector<ImeitemIJMUserState*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMPersonLastname (full: ImeitemIWdbeIniJMPersonLastname)
		*/
	class ImeitemIJMPersonLastname : public WdbeJMPersonLastname {

	public:
		ImeitemIJMPersonLastname(const std::string& Lastname = "");
		ImeitemIJMPersonLastname(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMPersonLastname (full: ImeIWdbeIniJMPersonLastname)
		*/
	class ImeIJMPersonLastname {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniJMPersonLastnameIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint LASTNAME = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMPersonLastname();
		~ImeIJMPersonLastname();

	public:
		std::vector<ImeitemIJMPersonLastname*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPerson (full: ImeitemIWdbeIniMPerson)
		*/
	class ImeitemIMPerson : public WdbeMPerson {

	public:
		ImeitemIMPerson(const Sbecore::uint ixVSex = 0, const std::string& Title = "", const std::string& Firstname = "", const std::string& Lastname = "");
		ImeitemIMPerson(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVSex;

		ImeIJMPersonLastname imeijmpersonlastname;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPerson (full: ImeIWdbeIniMPerson)
		*/
	class ImeIMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMPersonIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSEX = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint FIRSTNAME = 4;
			static const Sbecore::uint LASTNAME = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPerson();
		~ImeIMPerson();

	public:
		std::vector<ImeitemIMPerson*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUser (full: ImeitemIWdbeIniMUser)
		*/
	class ImeitemIMUser : public WdbeMUser {

	public:
		ImeitemIMUser(const std::string& sref = "", const Sbecore::uint ixVState = 0, const Sbecore::uint ixWdbeVLocale = 0, const Sbecore::uint ixWdbeVUserlevel = 0, const std::string& Password = "", const std::string& Fullkey = "", const std::string& Comment = "");
		ImeitemIMUser(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;
		std::string srefIxWdbeVLocale;
		std::string srefIxWdbeVUserlevel;

		ImeIAMUserAccess imeiamuseraccess;
		ImeIJMUserState imeijmuserstate;
		ImeIMPerson imeimperson;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUser (full: ImeIWdbeIniMUser)
		*/
	class ImeIMUser {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMUserIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXVSTATE = 2;
			static const Sbecore::uint SREFIXWDBEVLOCALE = 4;
			static const Sbecore::uint SREFIXWDBEVUSERLEVEL = 8;
			static const Sbecore::uint PASSWORD = 16;
			static const Sbecore::uint FULLKEY = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMUser();
		~ImeIMUser();

	public:
		std::vector<ImeitemIMUser*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUsergroup (full: ImeitemIWdbeIniMUsergroup)
		*/
	class ImeitemIMUsergroup : public WdbeMUsergroup {

	public:
		ImeitemIMUsergroup(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMUsergroup(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMUsergroupAccess imeiamusergroupaccess;
		ImeIMUser imeimuser;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUsergroup (full: ImeIWdbeIniMUsergroup)
		*/
	class ImeIMUsergroup {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeIniMUsergroupIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint COMMENT = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMUsergroup();
		~ImeIMUsergroup();

	public:
		std::vector<ImeitemIMUsergroup*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCoreproject& imeimcoreproject, ImeIMFamily& imeimfamily, ImeIMFile1& imeimfile1, ImeIMLibrary& imeimlibrary, ImeIMMachine& imeimmachine, ImeIMModule& imeimmodule, ImeIMUnit& imeimunit, ImeIMUsergroup& imeimusergroup);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCoreproject& imeimcoreproject, ImeIMFamily& imeimfamily, ImeIMFile1& imeimfile1, ImeIMLibrary& imeimlibrary, ImeIMMachine& imeimmachine, ImeIMModule& imeimmodule, ImeIMUnit& imeimunit, ImeIMUsergroup& imeimusergroup);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCoreproject& imeimcoreproject, ImeIMFamily& imeimfamily, ImeIMFile1& imeimfile1, ImeIMLibrary& imeimlibrary, ImeIMMachine& imeimmachine, ImeIMModule& imeimmodule, ImeIMUnit& imeimunit, ImeIMUsergroup& imeimusergroup);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCoreproject& imeimcoreproject, ImeIMFamily& imeimfamily, ImeIMFile1& imeimfile1, ImeIMLibrary& imeimlibrary, ImeIMMachine& imeimmachine, ImeIMModule& imeimmodule, ImeIMUnit& imeimunit, ImeIMUsergroup& imeimusergroup);

	void writeTxt(std::fstream& outfile, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCoreproject& imeimcoreproject, ImeIMFamily& imeimfamily, ImeIMFile1& imeimfile1, ImeIMLibrary& imeimlibrary, ImeIMMachine& imeimmachine, ImeIMModule& imeimmodule, ImeIMUnit& imeimunit, ImeIMUsergroup& imeimusergroup);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey1& imeiavkeylistkey1, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMCoreproject& imeimcoreproject, ImeIMFamily& imeimfamily, ImeIMFile1& imeimfile1, ImeIMLibrary& imeimlibrary, ImeIMMachine& imeimmachine, ImeIMModule& imeimmodule, ImeIMUnit& imeimunit, ImeIMUsergroup& imeimusergroup);

	std::map<Sbecore::uint,Sbecore::uint> icsWdbeVIopInsAll();
	Sbecore::uint getIxWdbeVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWdbeVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWdbeVIop);
};

#endif
