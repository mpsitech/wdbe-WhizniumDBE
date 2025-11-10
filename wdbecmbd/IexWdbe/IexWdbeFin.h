/**
	* \file IexWdbeFin.h
	* data blocks and readers/writers for import/export complex IexWdbeFin (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef IEXWDBEFIN_H
#define IEXWDBEFIN_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWdbe.h"
#include "VecWdbeVIop.h"

#define VecVIexWdbeFinIme IexWdbeFin::VecVIme

#define ImeitemIWdbeFinCSignal1 IexWdbeFin::ImeitemICSignal1
#define ImeIWdbeFinCSignal1 IexWdbeFin::ImeICSignal1
#define VecWImeIWdbeFinCSignal1Iel IexWdbeFin::ImeICSignal1::VecWIel

#define ImeitemIWdbeFinCPin IexWdbeFin::ImeitemICPin
#define ImeIWdbeFinCPin IexWdbeFin::ImeICPin
#define VecWImeIWdbeFinCPinIel IexWdbeFin::ImeICPin::VecWIel

#define ImeitemIWdbeFinAMPinPar IexWdbeFin::ImeitemIAMPinPar
#define ImeIWdbeFinAMPinPar IexWdbeFin::ImeIAMPinPar
#define VecWImeIWdbeFinAMPinParIel IexWdbeFin::ImeIAMPinPar::VecWIel

#define ImeitemIWdbeFinJMPinSref IexWdbeFin::ImeitemIJMPinSref
#define ImeIWdbeFinJMPinSref IexWdbeFin::ImeIJMPinSref
#define VecWImeIWdbeFinJMPinSrefIel IexWdbeFin::ImeIJMPinSref::VecWIel

#define ImeitemIWdbeFinMPin IexWdbeFin::ImeitemIMPin
#define ImeIWdbeFinMPin IexWdbeFin::ImeIMPin
#define VecWImeIWdbeFinMPinIel IexWdbeFin::ImeIMPin::VecWIel

#define ImeitemIWdbeFinMBank IexWdbeFin::ImeitemIMBank
#define ImeIWdbeFinMBank IexWdbeFin::ImeIMBank
#define VecWImeIWdbeFinMBankIel IexWdbeFin::ImeIMBank::VecWIel

#define ImeitemIWdbeFinMInterrupt1 IexWdbeFin::ImeitemIMInterrupt1
#define ImeIWdbeFinMInterrupt1 IexWdbeFin::ImeIMInterrupt1
#define VecWImeIWdbeFinMInterrupt1Iel IexWdbeFin::ImeIMInterrupt1::VecWIel

#define ImeitemIWdbeFinCGeneric IexWdbeFin::ImeitemICGeneric
#define ImeIWdbeFinCGeneric IexWdbeFin::ImeICGeneric
#define VecWImeIWdbeFinCGenericIel IexWdbeFin::ImeICGeneric::VecWIel

#define ImeitemIWdbeFinCPort IexWdbeFin::ImeitemICPort
#define ImeIWdbeFinCPort IexWdbeFin::ImeICPort
#define VecWImeIWdbeFinCPortIel IexWdbeFin::ImeICPort::VecWIel

#define ImeitemIWdbeFinCSignal2 IexWdbeFin::ImeitemICSignal2
#define ImeIWdbeFinCSignal2 IexWdbeFin::ImeICSignal2
#define VecWImeIWdbeFinCSignal2Iel IexWdbeFin::ImeICSignal2::VecWIel

#define ImeitemIWdbeFinCVariable1 IexWdbeFin::ImeitemICVariable1
#define ImeIWdbeFinCVariable1 IexWdbeFin::ImeICVariable1
#define VecWImeIWdbeFinCVariable1Iel IexWdbeFin::ImeICVariable1::VecWIel

#define ImeitemIWdbeFinRMCdcMSignal IexWdbeFin::ImeitemIRMCdcMSignal
#define ImeIWdbeFinRMCdcMSignal IexWdbeFin::ImeIRMCdcMSignal
#define VecWImeIWdbeFinRMCdcMSignalIel IexWdbeFin::ImeIRMCdcMSignal::VecWIel

#define ImeitemIWdbeFinMCdc IexWdbeFin::ImeitemIMCdc
#define ImeIWdbeFinMCdc IexWdbeFin::ImeIMCdc
#define VecWImeIWdbeFinMCdcIel IexWdbeFin::ImeIMCdc::VecWIel

#define ImeitemIWdbeFinMCommand IexWdbeFin::ImeitemIMCommand
#define ImeIWdbeFinMCommand IexWdbeFin::ImeIMCommand
#define VecWImeIWdbeFinMCommandIel IexWdbeFin::ImeIMCommand::VecWIel

#define ImeitemIWdbeFinMError IexWdbeFin::ImeitemIMError
#define ImeIWdbeFinMError IexWdbeFin::ImeIMError
#define VecWImeIWdbeFinMErrorIel IexWdbeFin::ImeIMError::VecWIel

#define ImeitemIWdbeFinRMCommandMController IexWdbeFin::ImeitemIRMCommandMController
#define ImeIWdbeFinRMCommandMController IexWdbeFin::ImeIRMCommandMController
#define VecWImeIWdbeFinRMCommandMControllerIel IexWdbeFin::ImeIRMCommandMController::VecWIel

#define ImeitemIWdbeFinMController IexWdbeFin::ImeitemIMController
#define ImeIWdbeFinMController IexWdbeFin::ImeIMController
#define VecWImeIWdbeFinMControllerIel IexWdbeFin::ImeIMController::VecWIel

#define ImeitemIWdbeFinMGeneric IexWdbeFin::ImeitemIMGeneric
#define ImeIWdbeFinMGeneric IexWdbeFin::ImeIMGeneric
#define VecWImeIWdbeFinMGenericIel IexWdbeFin::ImeIMGeneric::VecWIel

#define ImeitemIWdbeFinMPort IexWdbeFin::ImeitemIMPort
#define ImeIWdbeFinMPort IexWdbeFin::ImeIMPort
#define VecWImeIWdbeFinMPortIel IexWdbeFin::ImeIMPort::VecWIel

#define ImeitemIWdbeFinJAVKeylistKey IexWdbeFin::ImeitemIJAVKeylistKey
#define ImeIWdbeFinJAVKeylistKey IexWdbeFin::ImeIJAVKeylistKey
#define VecWImeIWdbeFinJAVKeylistKeyIel IexWdbeFin::ImeIJAVKeylistKey::VecWIel

#define ImeitemIWdbeFinAVKeylistKey IexWdbeFin::ImeitemIAVKeylistKey
#define ImeIWdbeFinAVKeylistKey IexWdbeFin::ImeIAVKeylistKey
#define VecWImeIWdbeFinAVKeylistKeyIel IexWdbeFin::ImeIAVKeylistKey::VecWIel

#define ImeitemIWdbeFinCVariable2 IexWdbeFin::ImeitemICVariable2
#define ImeIWdbeFinCVariable2 IexWdbeFin::ImeICVariable2
#define VecWImeIWdbeFinCVariable2Iel IexWdbeFin::ImeICVariable2::VecWIel

#define ImeitemIWdbeFinCFsmstate IexWdbeFin::ImeitemICFsmstate
#define ImeIWdbeFinCFsmstate IexWdbeFin::ImeICFsmstate
#define VecWImeIWdbeFinCFsmstateIel IexWdbeFin::ImeICFsmstate::VecWIel

#define ImeitemIWdbeFinAMFsmstateStep IexWdbeFin::ImeitemIAMFsmstateStep
#define ImeIWdbeFinAMFsmstateStep IexWdbeFin::ImeIAMFsmstateStep
#define VecWImeIWdbeFinAMFsmstateStepIel IexWdbeFin::ImeIAMFsmstateStep::VecWIel

#define ImeitemIWdbeFinMFsmstate IexWdbeFin::ImeitemIMFsmstate
#define ImeIWdbeFinMFsmstate IexWdbeFin::ImeIMFsmstate
#define VecWImeIWdbeFinMFsmstateIel IexWdbeFin::ImeIMFsmstate::VecWIel

#define ImeitemIWdbeFinMFsm IexWdbeFin::ImeitemIMFsm
#define ImeIWdbeFinMFsm IexWdbeFin::ImeIMFsm
#define VecWImeIWdbeFinMFsmIel IexWdbeFin::ImeIMFsm::VecWIel

#define ImeitemIWdbeFinMSensitivity2 IexWdbeFin::ImeitemIMSensitivity2
#define ImeIWdbeFinMSensitivity2 IexWdbeFin::ImeIMSensitivity2
#define VecWImeIWdbeFinMSensitivity2Iel IexWdbeFin::ImeIMSensitivity2::VecWIel

#define ImeitemIWdbeFinMVariable2 IexWdbeFin::ImeitemIMVariable2
#define ImeIWdbeFinMVariable2 IexWdbeFin::ImeIMVariable2
#define VecWImeIWdbeFinMVariable2Iel IexWdbeFin::ImeIMVariable2::VecWIel

#define ImeitemIWdbeFinMProcess IexWdbeFin::ImeitemIMProcess
#define ImeIWdbeFinMProcess IexWdbeFin::ImeIMProcess
#define VecWImeIWdbeFinMProcessIel IexWdbeFin::ImeIMProcess::VecWIel

#define ImeitemIWdbeFinMSensitivity1 IexWdbeFin::ImeitemIMSensitivity1
#define ImeIWdbeFinMSensitivity1 IexWdbeFin::ImeIMSensitivity1
#define VecWImeIWdbeFinMSensitivity1Iel IexWdbeFin::ImeIMSensitivity1::VecWIel

#define ImeitemIWdbeFinMSignal2 IexWdbeFin::ImeitemIMSignal2
#define ImeIWdbeFinMSignal2 IexWdbeFin::ImeIMSignal2
#define VecWImeIWdbeFinMSignal2Iel IexWdbeFin::ImeIMSignal2::VecWIel

#define ImeitemIWdbeFinMVariable1 IexWdbeFin::ImeitemIMVariable1
#define ImeIWdbeFinMVariable1 IexWdbeFin::ImeIMVariable1
#define VecWImeIWdbeFinMVariable1Iel IexWdbeFin::ImeIMVariable1::VecWIel

#define ImeitemIWdbeFinMModule IexWdbeFin::ImeitemIMModule
#define ImeIWdbeFinMModule IexWdbeFin::ImeIMModule
#define VecWImeIWdbeFinMModuleIel IexWdbeFin::ImeIMModule::VecWIel

#define ImeitemIWdbeFinMSignal1 IexWdbeFin::ImeitemIMSignal1
#define ImeIWdbeFinMSignal1 IexWdbeFin::ImeIMSignal1
#define VecWImeIWdbeFinMSignal1Iel IexWdbeFin::ImeIMSignal1::VecWIel

#define ImeitemIWdbeFinMUnit IexWdbeFin::ImeitemIMUnit
#define ImeIWdbeFinMUnit IexWdbeFin::ImeIMUnit
#define VecWImeIWdbeFinMUnitIel IexWdbeFin::ImeIMUnit::VecWIel

/**
	* IexWdbeFin
	*/
namespace IexWdbeFin {
	/**
		* VecVIme (full: VecVIexWdbeFinIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMFSMSTATESTEP = 1;
		static const Sbecore::uint IMEIAMPINPAR = 2;
		static const Sbecore::uint IMEIAVKEYLISTKEY = 3;
		static const Sbecore::uint IMEICFSMSTATE = 4;
		static const Sbecore::uint IMEICGENERIC = 5;
		static const Sbecore::uint IMEICPIN = 6;
		static const Sbecore::uint IMEICPORT = 7;
		static const Sbecore::uint IMEICSIGNAL1 = 8;
		static const Sbecore::uint IMEICSIGNAL2 = 9;
		static const Sbecore::uint IMEICVARIABLE1 = 10;
		static const Sbecore::uint IMEICVARIABLE2 = 11;
		static const Sbecore::uint IMEIJAVKEYLISTKEY = 12;
		static const Sbecore::uint IMEIJMPINSREF = 13;
		static const Sbecore::uint IMEIMBANK = 14;
		static const Sbecore::uint IMEIMCDC = 15;
		static const Sbecore::uint IMEIMCOMMAND = 16;
		static const Sbecore::uint IMEIMCONTROLLER = 17;
		static const Sbecore::uint IMEIMERROR = 18;
		static const Sbecore::uint IMEIMFSM = 19;
		static const Sbecore::uint IMEIMFSMSTATE = 20;
		static const Sbecore::uint IMEIMGENERIC = 21;
		static const Sbecore::uint IMEIMINTERRUPT1 = 22;
		static const Sbecore::uint IMEIMMODULE = 23;
		static const Sbecore::uint IMEIMPIN = 24;
		static const Sbecore::uint IMEIMPORT = 25;
		static const Sbecore::uint IMEIMPROCESS = 26;
		static const Sbecore::uint IMEIMSENSITIVITY1 = 27;
		static const Sbecore::uint IMEIMSENSITIVITY2 = 28;
		static const Sbecore::uint IMEIMSIGNAL1 = 29;
		static const Sbecore::uint IMEIMSIGNAL2 = 30;
		static const Sbecore::uint IMEIMUNIT = 31;
		static const Sbecore::uint IMEIMVARIABLE1 = 32;
		static const Sbecore::uint IMEIMVARIABLE2 = 33;
		static const Sbecore::uint IMEIRMCDCMSIGNAL = 34;
		static const Sbecore::uint IMEIRMCOMMANDMCONTROLLER = 35;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemICSignal1 (full: ImeitemIWdbeFinCSignal1)
		*/
	class ImeitemICSignal1 {

	public:
		ImeitemICSignal1(const Sbecore::ubigint iref = 0);
		ImeitemICSignal1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeICSignal1 (full: ImeIWdbeFinCSignal1)
		*/
	class ImeICSignal1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinCSignal1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICSignal1();
		~ImeICSignal1();

	public:
		std::vector<ImeitemICSignal1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICPin (full: ImeitemIWdbeFinCPin)
		*/
	class ImeitemICPin {

	public:
		ImeitemICPin(const Sbecore::ubigint iref = 0);
		ImeitemICPin(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeICPin (full: ImeIWdbeFinCPin)
		*/
	class ImeICPin {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinCPinIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICPin();
		~ImeICPin();

	public:
		std::vector<ImeitemICPin*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMPinPar (full: ImeitemIWdbeFinAMPinPar)
		*/
	class ImeitemIAMPinPar : public WdbeAMPinPar {

	public:
		ImeitemIAMPinPar(const std::string& x1SrefKKey = "", const std::string& Val = "");
		ImeitemIAMPinPar(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIAMPinPar (full: ImeIWdbeFinAMPinPar)
		*/
	class ImeIAMPinPar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinAMPinParIel)
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
		ImeIAMPinPar();
		~ImeIAMPinPar();

	public:
		std::vector<ImeitemIAMPinPar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMPinSref (full: ImeitemIWdbeFinJMPinSref)
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
		* ImeIJMPinSref (full: ImeIWdbeFinJMPinSref)
		*/
	class ImeIJMPinSref {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinJMPinSrefIel)
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
		* ImeitemIMPin (full: ImeitemIWdbeFinMPin)
		*/
	class ImeitemIMPin : public WdbeMPin {

	public:
		ImeitemIMPin(const Sbecore::uint ixWdbeVIop = 0, const Sbecore::ubigint irefRefWdbeCPin = 0, const std::string& sref = "", const std::string& Location = "");
		ImeitemIMPin(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWdbeVIop;
		std::string srefIxWdbeVIop;
		Sbecore::ubigint irefRefWdbeCPin;

		ImeIAMPinPar imeiampinpar;
		ImeIJMPinSref imeijmpinsref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPin (full: ImeIWdbeFinMPin)
		*/
	class ImeIMPin {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMPinIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWDBEVIOP = 1;
			static const Sbecore::uint IREFREFWDBECPIN = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint LOCATION = 8;

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
		* ImeitemIMBank (full: ImeitemIWdbeFinMBank)
		*/
	class ImeitemIMBank : public WdbeMBank {

	public:
		ImeitemIMBank(const Sbecore::uint ixWdbeVIop = 0, const std::string& sref = "", const std::string& srefKVoltstd = "");
		ImeitemIMBank(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWdbeVIop;
		std::string srefIxWdbeVIop;

		ImeICPin imeicpin;
		ImeIMPin imeimpin;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMBank (full: ImeIWdbeFinMBank)
		*/
	class ImeIMBank {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMBankIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWDBEVIOP = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFKVOLTSTD = 4;

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
		* ImeitemIMInterrupt1 (full: ImeitemIWdbeFinMInterrupt1)
		*/
	class ImeitemIMInterrupt1 : public WdbeMInterrupt {

	public:
		ImeitemIMInterrupt1(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMInterrupt1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIMInterrupt1 (full: ImeIWdbeFinMInterrupt1)
		*/
	class ImeIMInterrupt1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMInterrupt1Iel)
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
		ImeIMInterrupt1();
		~ImeIMInterrupt1();

	public:
		std::vector<ImeitemIMInterrupt1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICGeneric (full: ImeitemIWdbeFinCGeneric)
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
		* ImeICGeneric (full: ImeIWdbeFinCGeneric)
		*/
	class ImeICGeneric {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinCGenericIel)
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
		* ImeitemICPort (full: ImeitemIWdbeFinCPort)
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
		* ImeICPort (full: ImeIWdbeFinCPort)
		*/
	class ImeICPort {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinCPortIel)
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
		* ImeitemICSignal2 (full: ImeitemIWdbeFinCSignal2)
		*/
	class ImeitemICSignal2 {

	public:
		ImeitemICSignal2(const Sbecore::ubigint iref = 0);
		ImeitemICSignal2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeICSignal2 (full: ImeIWdbeFinCSignal2)
		*/
	class ImeICSignal2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinCSignal2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICSignal2();
		~ImeICSignal2();

	public:
		std::vector<ImeitemICSignal2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICVariable1 (full: ImeitemIWdbeFinCVariable1)
		*/
	class ImeitemICVariable1 {

	public:
		ImeitemICVariable1(const Sbecore::ubigint iref = 0);
		ImeitemICVariable1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeICVariable1 (full: ImeIWdbeFinCVariable1)
		*/
	class ImeICVariable1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinCVariable1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICVariable1();
		~ImeICVariable1();

	public:
		std::vector<ImeitemICVariable1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMCdcMSignal (full: ImeitemIWdbeFinRMCdcMSignal)
		*/
	class ImeitemIRMCdcMSignal : public WdbeRMCdcMSignal {

	public:
		ImeitemIRMCdcMSignal(const std::string& srefRefWdbeMSignal = "", const Sbecore::uint ixVDir = 0);
		ImeitemIRMCdcMSignal(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWdbeMSignal;
		std::string srefIxVDir;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMCdcMSignal (full: ImeIWdbeFinRMCdcMSignal)
		*/
	class ImeIRMCdcMSignal {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinRMCdcMSignalIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWDBEMSIGNAL = 1;
			static const Sbecore::uint SREFIXVDIR = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMCdcMSignal();
		~ImeIRMCdcMSignal();

	public:
		std::vector<ImeitemIRMCdcMSignal*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCdc (full: ImeitemIWdbeFinMCdc)
		*/
	class ImeitemIMCdc : public WdbeMCdc {

	public:
		ImeitemIMCdc(const std::string& fckSrefWdbeMSignal = "", const std::string& farSrefWdbeMSignal = "", const std::string& sckSrefWdbeMSignal = "", const std::string& sarSrefWdbeMSignal = "", const double Ratio = 0.0);
		ImeitemIMCdc(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIRMCdcMSignal imeirmcdcmsignal;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCdc (full: ImeIWdbeFinMCdc)
		*/
	class ImeIMCdc {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMCdcIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint FCKSREFWDBEMSIGNAL = 1;
			static const Sbecore::uint FARSREFWDBEMSIGNAL = 2;
			static const Sbecore::uint SCKSREFWDBEMSIGNAL = 4;
			static const Sbecore::uint SARSREFWDBEMSIGNAL = 8;
			static const Sbecore::uint RATIO = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMCdc();
		~ImeIMCdc();

	public:
		std::vector<ImeitemIMCdc*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCommand (full: ImeitemIWdbeFinMCommand)
		*/
	class ImeitemIMCommand : public WdbeMCommand {

	public:
		ImeitemIMCommand(const std::string& sref = "", const std::string& srefIvrRefWdbeMSignal = "", const std::string& srefRvrRefWdbeMSignal = "", const std::string& srefRerRefWdbeMSignal = "");
		ImeitemIMCommand(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIvrRefWdbeMSignal;
		std::string srefRvrRefWdbeMSignal;
		std::string srefRerRefWdbeMSignal;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCommand (full: ImeIWdbeFinMCommand)
		*/
	class ImeIMCommand {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMCommandIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIVRREFWDBEMSIGNAL = 2;
			static const Sbecore::uint SREFRVRREFWDBEMSIGNAL = 4;
			static const Sbecore::uint SREFRERREFWDBEMSIGNAL = 8;

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
		* ImeitemIMError (full: ImeitemIWdbeFinMError)
		*/
	class ImeitemIMError : public WdbeMError {

	public:
		ImeitemIMError(const std::string& sref = "", const std::string& srefTraRefWdbeMSignal = "");
		ImeitemIMError(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefTraRefWdbeMSignal;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMError (full: ImeIWdbeFinMError)
		*/
	class ImeIMError {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMErrorIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFTRAREFWDBEMSIGNAL = 2;

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
		* ImeitemIRMCommandMController (full: ImeitemIWdbeFinRMCommandMController)
		*/
	class ImeitemIRMCommandMController : public WdbeRMCommandMController {

	public:
		ImeitemIRMCommandMController(const std::string& srefRefWdbeMCommand = "", const std::string& srefIvrRefWdbeMSignal = "", const std::string& srefRvrRefWdbeMSignal = "");
		ImeitemIRMCommandMController(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWdbeMCommand;
		std::string srefIvrRefWdbeMSignal;
		std::string srefRvrRefWdbeMSignal;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMCommandMController (full: ImeIWdbeFinRMCommandMController)
		*/
	class ImeIRMCommandMController {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinRMCommandMControllerIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWDBEMCOMMAND = 1;
			static const Sbecore::uint SREFIVRREFWDBEMSIGNAL = 2;
			static const Sbecore::uint SREFRVRREFWDBEMSIGNAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMCommandMController();
		~ImeIRMCommandMController();

	public:
		std::vector<ImeitemIRMCommandMController*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMController (full: ImeitemIWdbeFinMController)
		*/
	class ImeitemIMController : public WdbeMController {

	public:
		ImeitemIMController(const Sbecore::uint ixWdbeVIop = 0, const std::string& srefClrRefWdbeMSignal = "");
		ImeitemIMController(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWdbeVIop;
		std::string srefIxWdbeVIop;
		std::string srefClrRefWdbeMSignal;

		ImeIMCommand imeimcommand;
		ImeIMError imeimerror;
		ImeIRMCommandMController imeirmcommandmcontroller;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMController (full: ImeIWdbeFinMController)
		*/
	class ImeIMController {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMControllerIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWDBEVIOP = 1;
			static const Sbecore::uint SREFCLRREFWDBEMSIGNAL = 2;

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
		* ImeitemIMGeneric (full: ImeitemIWdbeFinMGeneric)
		*/
	class ImeitemIMGeneric : public WdbeMGeneric {

	public:
		ImeitemIMGeneric(const Sbecore::uint ixWdbeVIop = 0, const Sbecore::ubigint irefRefWdbeCGeneric = 0, const std::string& sref = "", const std::string& srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const std::string& Defval = "", const std::string& srcSrefWdbeMGeneric = "", const std::string& Comment = "");
		ImeitemIMGeneric(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWdbeVIop;
		std::string srefIxWdbeVIop;
		Sbecore::ubigint irefRefWdbeCGeneric;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMGeneric (full: ImeIWdbeFinMGeneric)
		*/
	class ImeIMGeneric {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMGenericIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWDBEVIOP = 1;
			static const Sbecore::uint IREFREFWDBECGENERIC = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint SREFWDBEKHDLTYPE = 8;
			static const Sbecore::uint WIDTH = 16;
			static const Sbecore::uint MINMAX = 32;
			static const Sbecore::uint DEFVAL = 64;
			static const Sbecore::uint SRCSREFWDBEMGENERIC = 128;
			static const Sbecore::uint COMMENT = 256;

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
		* ImeitemIMPort (full: ImeitemIWdbeFinMPort)
		*/
	class ImeitemIMPort : public WdbeMPort {

	public:
		ImeitemIMPort(const Sbecore::uint ixWdbeVIop = 0, const Sbecore::ubigint irefRefWdbeCPort = 0, const Sbecore::uint mdlIxVCat = 0, const std::string& sref = "", const Sbecore::uint ixVDir = 0, const std::string& srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const std::string& Defval = "", const std::string& cpiSrefWdbeMPin = "", const std::string& cprSrefWdbeMPort = "", const std::string& csiSrefWdbeMSignal = "", const std::string& Comment = "");
		ImeitemIMPort(DbsWdbe* dbswdbe, const Sbecore::uint ixWdbeVIop, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::uint ixWdbeVIop;
		std::string srefIxWdbeVIop;
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
		* ImeIMPort (full: ImeIWdbeFinMPort)
		*/
	class ImeIMPort {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMPortIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWDBEVIOP = 1;
			static const Sbecore::uint IREFREFWDBECPORT = 2;
			static const Sbecore::uint SREFMDLIXVCAT = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint SREFIXVDIR = 16;
			static const Sbecore::uint SREFWDBEKHDLTYPE = 32;
			static const Sbecore::uint WIDTH = 64;
			static const Sbecore::uint MINMAX = 128;
			static const Sbecore::uint DEFVAL = 256;
			static const Sbecore::uint CPISREFWDBEMPIN = 512;
			static const Sbecore::uint CPRSREFWDBEMPORT = 1024;
			static const Sbecore::uint CSISREFWDBEMSIGNAL = 2048;
			static const Sbecore::uint COMMENT = 4096;

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
		* ImeitemIJAVKeylistKey (full: ImeitemIWdbeFinJAVKeylistKey)
		*/
	class ImeitemIJAVKeylistKey : public WdbeJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey(const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJAVKeylistKey(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIJAVKeylistKey (full: ImeIWdbeFinJAVKeylistKey)
		*/
	class ImeIJAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinJAVKeylistKeyIel)
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
		ImeIJAVKeylistKey();
		~ImeIJAVKeylistKey();

	public:
		std::vector<ImeitemIJAVKeylistKey*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey (full: ImeitemIWdbeFinAVKeylistKey)
		*/
	class ImeitemIAVKeylistKey : public WdbeAVKeylistKey {

	public:
		ImeitemIAVKeylistKey(const std::string& sref = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIAVKeylistKey(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIJAVKeylistKey imeijavkeylistkey;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey (full: ImeIWdbeFinAVKeylistKey)
		*/
	class ImeIAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinAVKeylistKeyIel)
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
		ImeIAVKeylistKey();
		~ImeIAVKeylistKey();

	public:
		std::vector<ImeitemIAVKeylistKey*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICVariable2 (full: ImeitemIWdbeFinCVariable2)
		*/
	class ImeitemICVariable2 {

	public:
		ImeitemICVariable2(const Sbecore::ubigint iref = 0);
		ImeitemICVariable2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeICVariable2 (full: ImeIWdbeFinCVariable2)
		*/
	class ImeICVariable2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinCVariable2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICVariable2();
		~ImeICVariable2();

	public:
		std::vector<ImeitemICVariable2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICFsmstate (full: ImeitemIWdbeFinCFsmstate)
		*/
	class ImeitemICFsmstate {

	public:
		ImeitemICFsmstate(const Sbecore::ubigint iref = 0);
		ImeitemICFsmstate(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeICFsmstate (full: ImeIWdbeFinCFsmstate)
		*/
	class ImeICFsmstate {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinCFsmstateIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICFsmstate();
		~ImeICFsmstate();

	public:
		std::vector<ImeitemICFsmstate*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMFsmstateStep (full: ImeitemIWdbeFinAMFsmstateStep)
		*/
	class ImeitemIAMFsmstateStep : public WdbeAMFsmstateStep {

	public:
		ImeitemIAMFsmstateStep(const std::string& srefFnxRefWdbeMFsmstate = "", const std::string& Cond1 = "", const std::string& Ip1 = "", const std::string& Cond2 = "", const std::string& Ip2 = "", const std::string& Cond3 = "", const std::string& Ip3 = "", const std::string& Cond4 = "", const std::string& Ip4 = "", const std::string& Cond5 = "", const std::string& Ip5 = "", const std::string& Cond6 = "", const std::string& Ip6 = "");
		ImeitemIAMFsmstateStep(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefFnxRefWdbeMFsmstate;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMFsmstateStep (full: ImeIWdbeFinAMFsmstateStep)
		*/
	class ImeIAMFsmstateStep {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinAMFsmstateStepIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFFNXREFWDBEMFSMSTATE = 1;
			static const Sbecore::uint COND1 = 2;
			static const Sbecore::uint IP1 = 4;
			static const Sbecore::uint COND2 = 8;
			static const Sbecore::uint IP2 = 16;
			static const Sbecore::uint COND3 = 32;
			static const Sbecore::uint IP3 = 64;
			static const Sbecore::uint COND4 = 128;
			static const Sbecore::uint IP4 = 256;
			static const Sbecore::uint COND5 = 512;
			static const Sbecore::uint IP5 = 1024;
			static const Sbecore::uint COND6 = 2048;
			static const Sbecore::uint IP6 = 4096;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMFsmstateStep();
		~ImeIAMFsmstateStep();

	public:
		std::vector<ImeitemIAMFsmstateStep*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFsmstate (full: ImeitemIWdbeFinMFsmstate)
		*/
	class ImeitemIMFsmstate : public WdbeMFsmstate {

	public:
		ImeitemIMFsmstate(const Sbecore::ubigint irefRefWdbeCFsmstate = 0, const std::string& sref = "", const bool Extip = false, const std::string& Comment = "");
		ImeitemIMFsmstate(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWdbeCFsmstate;

		ImeIAMFsmstateStep imeiamfsmstatestep;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFsmstate (full: ImeIWdbeFinMFsmstate)
		*/
	class ImeIMFsmstate {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMFsmstateIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWDBECFSMSTATE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint EXTIP = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFsmstate();
		~ImeIMFsmstate();

	public:
		std::vector<ImeitemIMFsmstate*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFsm (full: ImeitemIWdbeFinMFsm)
		*/
	class ImeitemIMFsm : public WdbeMFsm {

	public:
		ImeitemIMFsm(const Sbecore::uint ixVDbgtaptype = 0);
		ImeitemIMFsm(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVDbgtaptype;

		ImeICFsmstate imeicfsmstate;
		ImeIMFsmstate imeimfsmstate;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFsm (full: ImeIWdbeFinMFsm)
		*/
	class ImeIMFsm {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMFsmIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVDBGTAPTYPE = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFsm();
		~ImeIMFsm();

	public:
		std::vector<ImeitemIMFsm*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSensitivity2 (full: ImeitemIWdbeFinMSensitivity2)
		*/
	class ImeitemIMSensitivity2 : public WdbeMSensitivity {

	public:
		ImeitemIMSensitivity2(const Sbecore::uint srcIxVTbl = 0, const std::string& srefSrcUref = "");
		ImeitemIMSensitivity2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefSrcIxVTbl;
		std::string srefSrcUref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSensitivity2 (full: ImeIWdbeFinMSensitivity2)
		*/
	class ImeIMSensitivity2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMSensitivity2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFSRCIXVTBL = 1;
			static const Sbecore::uint SREFSRCUREF = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSensitivity2();
		~ImeIMSensitivity2();

	public:
		std::vector<ImeitemIMSensitivity2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVariable2 (full: ImeitemIWdbeFinMVariable2)
		*/
	class ImeitemIMVariable2 : public WdbeMVariable {

	public:
		ImeitemIMVariable2(const Sbecore::ubigint irefRefWdbeCVariable = 0, const std::string& sref = "", const bool Const = false, const bool Falling = false, const std::string& srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const std::string& Onval = "", const std::string& Offval = "", const std::string& Comment = "");
		ImeitemIMVariable2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIMVariable2 (full: ImeIWdbeFinMVariable2)
		*/
	class ImeIMVariable2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMVariable2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWDBECVARIABLE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint CONST = 4;
			static const Sbecore::uint FALLING = 8;
			static const Sbecore::uint SREFWDBEKHDLTYPE = 16;
			static const Sbecore::uint WIDTH = 32;
			static const Sbecore::uint MINMAX = 64;
			static const Sbecore::uint ONVAL = 128;
			static const Sbecore::uint OFFVAL = 256;
			static const Sbecore::uint COMMENT = 512;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMVariable2();
		~ImeIMVariable2();

	public:
		std::vector<ImeitemIMVariable2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMProcess (full: ImeitemIWdbeFinMProcess)
		*/
	class ImeitemIMProcess : public WdbeMProcess {

	public:
		ImeitemIMProcess(const std::string& sref = "", const std::string& clkSrefWdbeMSignal = "", const std::string& asrSrefWdbeMSignal = "", const bool Falling = false, const std::string& Syncrst = "", const bool Extip = false, const std::string& Comment = "");
		ImeitemIMProcess(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAVKeylistKey imeiavkeylistkey;
		ImeICVariable2 imeicvariable2;
		ImeIMFsm imeimfsm;
		ImeIMSensitivity2 imeimsensitivity2;
		ImeIMVariable2 imeimvariable2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMProcess (full: ImeIWdbeFinMProcess)
		*/
	class ImeIMProcess {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMProcessIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint CLKSREFWDBEMSIGNAL = 2;
			static const Sbecore::uint ASRSREFWDBEMSIGNAL = 4;
			static const Sbecore::uint FALLING = 8;
			static const Sbecore::uint SYNCRST = 16;
			static const Sbecore::uint EXTIP = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMProcess();
		~ImeIMProcess();

	public:
		std::vector<ImeitemIMProcess*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSensitivity1 (full: ImeitemIWdbeFinMSensitivity1)
		*/
	class ImeitemIMSensitivity1 : public WdbeMSensitivity {

	public:
		ImeitemIMSensitivity1(const Sbecore::uint srcIxVTbl = 0, const std::string& srefSrcUref = "");
		ImeitemIMSensitivity1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefSrcIxVTbl;
		std::string srefSrcUref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSensitivity1 (full: ImeIWdbeFinMSensitivity1)
		*/
	class ImeIMSensitivity1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMSensitivity1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFSRCIXVTBL = 1;
			static const Sbecore::uint SREFSRCUREF = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSensitivity1();
		~ImeIMSensitivity1();

	public:
		std::vector<ImeitemIMSensitivity1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSignal2 (full: ImeitemIWdbeFinMSignal2)
		*/
	class ImeitemIMSignal2 : public WdbeMSignal {

	public:
		ImeitemIMSignal2(const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint irefRefWdbeCSignal = 0, const Sbecore::uint mgeIxVTbl = 0, const std::string& srefMgeUref = "", const std::string& sref = "", const bool Const = false, const std::string& srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const std::string& Comb = "", const std::string& Onval = "", const std::string& Offval = "", const std::string& srefDrvRefWdbeMPort = "", const std::string& Comment = "");
		ImeitemIMSignal2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		Sbecore::ubigint irefRefWdbeCSignal;
		std::string srefMgeIxVTbl;
		std::string srefMgeUref;
		std::string srefDrvRefWdbeMPort;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSignal2 (full: ImeIWdbeFinMSignal2)
		*/
	class ImeIMSignal2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMSignal2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint IREFREFWDBECSIGNAL = 2;
			static const Sbecore::uint SREFMGEIXVTBL = 4;
			static const Sbecore::uint SREFMGEUREF = 8;
			static const Sbecore::uint SREF = 16;
			static const Sbecore::uint CONST = 32;
			static const Sbecore::uint SREFWDBEKHDLTYPE = 64;
			static const Sbecore::uint WIDTH = 128;
			static const Sbecore::uint MINMAX = 256;
			static const Sbecore::uint COMB = 512;
			static const Sbecore::uint ONVAL = 1024;
			static const Sbecore::uint OFFVAL = 2048;
			static const Sbecore::uint SREFDRVREFWDBEMPORT = 4096;
			static const Sbecore::uint COMMENT = 8192;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSignal2();
		~ImeIMSignal2();

	public:
		std::vector<ImeitemIMSignal2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVariable1 (full: ImeitemIWdbeFinMVariable1)
		*/
	class ImeitemIMVariable1 : public WdbeMVariable {

	public:
		ImeitemIMVariable1(const Sbecore::ubigint irefRefWdbeCVariable = 0, const std::string& sref = "", const std::string& srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const std::string& Comment = "");
		ImeitemIMVariable1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIMVariable1 (full: ImeIWdbeFinMVariable1)
		*/
	class ImeIMVariable1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMVariable1Iel)
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
		ImeIMVariable1();
		~ImeIMVariable1();

	public:
		std::vector<ImeitemIMVariable1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMModule (full: ImeitemIWdbeFinMModule)
		*/
	class ImeitemIMModule : public WdbeMModule {

	public:
		ImeitemIMModule(const std::string& hsrefSupRefWdbeMModule = "", const std::string& sref = "");
		ImeitemIMModule(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hsrefSupRefWdbeMModule;

		ImeICGeneric imeicgeneric;
		ImeICPort imeicport;
		ImeICSignal2 imeicsignal2;
		ImeICVariable1 imeicvariable1;
		ImeIMCdc imeimcdc;
		ImeIMController imeimcontroller;
		ImeIMGeneric imeimgeneric;
		ImeIMPort imeimport;
		ImeIMProcess imeimprocess;
		ImeIMSensitivity1 imeimsensitivity1;
		ImeIMSignal2 imeimsignal2;
		ImeIMVariable1 imeimvariable1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMModule (full: ImeIWdbeFinMModule)
		*/
	class ImeIMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMModuleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint HSREFSUPREFWDBEMMODULE = 1;
			static const Sbecore::uint SREF = 2;

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
		* ImeitemIMSignal1 (full: ImeitemIWdbeFinMSignal1)
		*/
	class ImeitemIMSignal1 : public WdbeMSignal {

	public:
		ImeitemIMSignal1(const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint irefRefWdbeCSignal = 0, const std::string& srefMgeUref = "", const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMSignal1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		Sbecore::ubigint irefRefWdbeCSignal;
		std::string srefMgeUref;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSignal1 (full: ImeIWdbeFinMSignal1)
		*/
	class ImeIMSignal1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMSignal1Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint IREFREFWDBECSIGNAL = 2;
			static const Sbecore::uint SREFMGEUREF = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSignal1();
		~ImeIMSignal1();

	public:
		std::vector<ImeitemIMSignal1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUnit (full: ImeitemIWdbeFinMUnit)
		*/
	class ImeitemIMUnit : public WdbeMUnit {

	public:
		ImeitemIMUnit(const std::string& sref = "");
		ImeitemIMUnit(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeICSignal1 imeicsignal1;
		ImeIMBank imeimbank;
		ImeIMInterrupt1 imeiminterrupt1;
		ImeIMModule imeimmodule;
		ImeIMSignal1 imeimsignal1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUnit (full: ImeIWdbeFinMUnit)
		*/
	class ImeIMUnit {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeFinMUnitIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;

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

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIMUnit& imeimunit);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMUnit& imeimunit);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMUnit& imeimunit);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMUnit& imeimunit);

	void writeTxt(std::fstream& outfile, ImeIMUnit& imeimunit);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMUnit& imeimunit);

	std::map<Sbecore::uint,Sbecore::uint> icsWdbeVIopInsAll();
	Sbecore::uint getIxWdbeVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWdbeVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWdbeVIop);
};

#endif
