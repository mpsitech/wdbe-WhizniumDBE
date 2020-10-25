/**
	* \file IexWdbeDdd.h
	* data blocks and readers/writers for import/export complex IexWdbeDdd (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef IEXWDBEDDD_H
#define IEXWDBEDDD_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWdbe.h"
#include "VecWdbeVIop.h"

#define VecVIexWdbeDddIme IexWdbeDdd::VecVIme

#define ImeitemIWdbeDddCPin IexWdbeDdd::ImeitemICPin
#define ImeIWdbeDddCPin IexWdbeDdd::ImeICPin
#define VecWImeIWdbeDddCPinIel IexWdbeDdd::ImeICPin::VecWIel

#define ImeitemIWdbeDddAMPinPar IexWdbeDdd::ImeitemIAMPinPar
#define ImeIWdbeDddAMPinPar IexWdbeDdd::ImeIAMPinPar
#define VecWImeIWdbeDddAMPinParIel IexWdbeDdd::ImeIAMPinPar::VecWIel

#define ImeitemIWdbeDddJMPinSref IexWdbeDdd::ImeitemIJMPinSref
#define ImeIWdbeDddJMPinSref IexWdbeDdd::ImeIJMPinSref
#define VecWImeIWdbeDddJMPinSrefIel IexWdbeDdd::ImeIJMPinSref::VecWIel

#define ImeitemIWdbeDddMPin IexWdbeDdd::ImeitemIMPin
#define ImeIWdbeDddMPin IexWdbeDdd::ImeIMPin
#define VecWImeIWdbeDddMPinIel IexWdbeDdd::ImeIMPin::VecWIel

#define ImeitemIWdbeDddMBank IexWdbeDdd::ImeitemIMBank
#define ImeIWdbeDddMBank IexWdbeDdd::ImeIMBank
#define VecWImeIWdbeDddMBankIel IexWdbeDdd::ImeIMBank::VecWIel

#define ImeitemIWdbeDddAMCommandInvpar1 IexWdbeDdd::ImeitemIAMCommandInvpar1
#define ImeIWdbeDddAMCommandInvpar1 IexWdbeDdd::ImeIAMCommandInvpar1
#define VecWImeIWdbeDddAMCommandInvpar1Iel IexWdbeDdd::ImeIAMCommandInvpar1::VecWIel

#define ImeitemIWdbeDddAMCommandRetpar1 IexWdbeDdd::ImeitemIAMCommandRetpar1
#define ImeIWdbeDddAMCommandRetpar1 IexWdbeDdd::ImeIAMCommandRetpar1
#define VecWImeIWdbeDddAMCommandRetpar1Iel IexWdbeDdd::ImeIAMCommandRetpar1::VecWIel

#define ImeitemIWdbeDddMCommand1 IexWdbeDdd::ImeitemIMCommand1
#define ImeIWdbeDddMCommand1 IexWdbeDdd::ImeIMCommand1
#define VecWImeIWdbeDddMCommand1Iel IexWdbeDdd::ImeIMCommand1::VecWIel

#define ImeitemIWdbeDddAMErrorPar1 IexWdbeDdd::ImeitemIAMErrorPar1
#define ImeIWdbeDddAMErrorPar1 IexWdbeDdd::ImeIAMErrorPar1
#define VecWImeIWdbeDddAMErrorPar1Iel IexWdbeDdd::ImeIAMErrorPar1::VecWIel

#define ImeitemIWdbeDddMError1 IexWdbeDdd::ImeitemIMError1
#define ImeIWdbeDddMError1 IexWdbeDdd::ImeIMError1
#define VecWImeIWdbeDddMError1Iel IexWdbeDdd::ImeIMError1::VecWIel

#define ImeitemIWdbeDddCGeneric IexWdbeDdd::ImeitemICGeneric
#define ImeIWdbeDddCGeneric IexWdbeDdd::ImeICGeneric
#define VecWImeIWdbeDddCGenericIel IexWdbeDdd::ImeICGeneric::VecWIel

#define ImeitemIWdbeDddCPort IexWdbeDdd::ImeitemICPort
#define ImeIWdbeDddCPort IexWdbeDdd::ImeICPort
#define VecWImeIWdbeDddCPortIel IexWdbeDdd::ImeICPort::VecWIel

#define ImeitemIWdbeDddCSignal IexWdbeDdd::ImeitemICSignal
#define ImeIWdbeDddCSignal IexWdbeDdd::ImeICSignal
#define VecWImeIWdbeDddCSignalIel IexWdbeDdd::ImeICSignal::VecWIel

#define ImeitemIWdbeDddAMCommandInvpar2 IexWdbeDdd::ImeitemIAMCommandInvpar2
#define ImeIWdbeDddAMCommandInvpar2 IexWdbeDdd::ImeIAMCommandInvpar2
#define VecWImeIWdbeDddAMCommandInvpar2Iel IexWdbeDdd::ImeIAMCommandInvpar2::VecWIel

#define ImeitemIWdbeDddAMCommandRetpar2 IexWdbeDdd::ImeitemIAMCommandRetpar2
#define ImeIWdbeDddAMCommandRetpar2 IexWdbeDdd::ImeIAMCommandRetpar2
#define VecWImeIWdbeDddAMCommandRetpar2Iel IexWdbeDdd::ImeIAMCommandRetpar2::VecWIel

#define ImeitemIWdbeDddMCommand2 IexWdbeDdd::ImeitemIMCommand2
#define ImeIWdbeDddMCommand2 IexWdbeDdd::ImeIMCommand2
#define VecWImeIWdbeDddMCommand2Iel IexWdbeDdd::ImeIMCommand2::VecWIel

#define ImeitemIWdbeDddAMErrorPar2 IexWdbeDdd::ImeitemIAMErrorPar2
#define ImeIWdbeDddAMErrorPar2 IexWdbeDdd::ImeIAMErrorPar2
#define VecWImeIWdbeDddAMErrorPar2Iel IexWdbeDdd::ImeIAMErrorPar2::VecWIel

#define ImeitemIWdbeDddMError2 IexWdbeDdd::ImeitemIMError2
#define ImeIWdbeDddMError2 IexWdbeDdd::ImeIMError2
#define VecWImeIWdbeDddMError2Iel IexWdbeDdd::ImeIMError2::VecWIel

#define ImeitemIWdbeDddMVectoritem2 IexWdbeDdd::ImeitemIMVectoritem2
#define ImeIWdbeDddMVectoritem2 IexWdbeDdd::ImeIMVectoritem2
#define VecWImeIWdbeDddMVectoritem2Iel IexWdbeDdd::ImeIMVectoritem2::VecWIel

#define ImeitemIWdbeDddMVector2 IexWdbeDdd::ImeitemIMVector2
#define ImeIWdbeDddMVector2 IexWdbeDdd::ImeIMVector2
#define VecWImeIWdbeDddMVector2Iel IexWdbeDdd::ImeIMVector2::VecWIel

#define ImeitemIWdbeDddRMCommandMController IexWdbeDdd::ImeitemIRMCommandMController
#define ImeIWdbeDddRMCommandMController IexWdbeDdd::ImeIRMCommandMController
#define VecWImeIWdbeDddRMCommandMControllerIel IexWdbeDdd::ImeIRMCommandMController::VecWIel

#define ImeitemIWdbeDddMController IexWdbeDdd::ImeitemIMController
#define ImeIWdbeDddMController IexWdbeDdd::ImeIMController
#define VecWImeIWdbeDddMControllerIel IexWdbeDdd::ImeIMController::VecWIel

#define ImeitemIWdbeDddMGeneric IexWdbeDdd::ImeitemIMGeneric
#define ImeIWdbeDddMGeneric IexWdbeDdd::ImeIMGeneric
#define VecWImeIWdbeDddMGenericIel IexWdbeDdd::ImeIMGeneric::VecWIel

#define ImeitemIWdbeDddMImbuf IexWdbeDdd::ImeitemIMImbuf
#define ImeIWdbeDddMImbuf IexWdbeDdd::ImeIMImbuf
#define VecWImeIWdbeDddMImbufIel IexWdbeDdd::ImeIMImbuf::VecWIel

#define ImeitemIWdbeDddMPort IexWdbeDdd::ImeitemIMPort
#define ImeIWdbeDddMPort IexWdbeDdd::ImeIMPort
#define VecWImeIWdbeDddMPortIel IexWdbeDdd::ImeIMPort::VecWIel

#define ImeitemIWdbeDddJAVKeylistKey IexWdbeDdd::ImeitemIJAVKeylistKey
#define ImeIWdbeDddJAVKeylistKey IexWdbeDdd::ImeIJAVKeylistKey
#define VecWImeIWdbeDddJAVKeylistKeyIel IexWdbeDdd::ImeIJAVKeylistKey::VecWIel

#define ImeitemIWdbeDddAVKeylistKey IexWdbeDdd::ImeitemIAVKeylistKey
#define ImeIWdbeDddAVKeylistKey IexWdbeDdd::ImeIAVKeylistKey
#define VecWImeIWdbeDddAVKeylistKeyIel IexWdbeDdd::ImeIAVKeylistKey::VecWIel

#define ImeitemIWdbeDddCVariable IexWdbeDdd::ImeitemICVariable
#define ImeIWdbeDddCVariable IexWdbeDdd::ImeICVariable
#define VecWImeIWdbeDddCVariableIel IexWdbeDdd::ImeICVariable::VecWIel

#define ImeitemIWdbeDddCFsmstate IexWdbeDdd::ImeitemICFsmstate
#define ImeIWdbeDddCFsmstate IexWdbeDdd::ImeICFsmstate
#define VecWImeIWdbeDddCFsmstateIel IexWdbeDdd::ImeICFsmstate::VecWIel

#define ImeitemIWdbeDddAMFsmstateStep IexWdbeDdd::ImeitemIAMFsmstateStep
#define ImeIWdbeDddAMFsmstateStep IexWdbeDdd::ImeIAMFsmstateStep
#define VecWImeIWdbeDddAMFsmstateStepIel IexWdbeDdd::ImeIAMFsmstateStep::VecWIel

#define ImeitemIWdbeDddMFsmstate IexWdbeDdd::ImeitemIMFsmstate
#define ImeIWdbeDddMFsmstate IexWdbeDdd::ImeIMFsmstate
#define VecWImeIWdbeDddMFsmstateIel IexWdbeDdd::ImeIMFsmstate::VecWIel

#define ImeitemIWdbeDddMFsm IexWdbeDdd::ImeitemIMFsm
#define ImeIWdbeDddMFsm IexWdbeDdd::ImeIMFsm
#define VecWImeIWdbeDddMFsmIel IexWdbeDdd::ImeIMFsm::VecWIel

#define ImeitemIWdbeDddMVariable IexWdbeDdd::ImeitemIMVariable
#define ImeIWdbeDddMVariable IexWdbeDdd::ImeIMVariable
#define VecWImeIWdbeDddMVariableIel IexWdbeDdd::ImeIMVariable::VecWIel

#define ImeitemIWdbeDddMProcess IexWdbeDdd::ImeitemIMProcess
#define ImeIWdbeDddMProcess IexWdbeDdd::ImeIMProcess
#define VecWImeIWdbeDddMProcessIel IexWdbeDdd::ImeIMProcess::VecWIel

#define ImeitemIWdbeDddMSignal IexWdbeDdd::ImeitemIMSignal
#define ImeIWdbeDddMSignal IexWdbeDdd::ImeIMSignal
#define VecWImeIWdbeDddMSignalIel IexWdbeDdd::ImeIMSignal::VecWIel

#define ImeitemIWdbeDddMModule IexWdbeDdd::ImeitemIMModule
#define ImeIWdbeDddMModule IexWdbeDdd::ImeIMModule
#define VecWImeIWdbeDddMModuleIel IexWdbeDdd::ImeIMModule::VecWIel

#define ImeitemIWdbeDddMVectoritem1 IexWdbeDdd::ImeitemIMVectoritem1
#define ImeIWdbeDddMVectoritem1 IexWdbeDdd::ImeIMVectoritem1
#define VecWImeIWdbeDddMVectoritem1Iel IexWdbeDdd::ImeIMVectoritem1::VecWIel

#define ImeitemIWdbeDddMVector1 IexWdbeDdd::ImeitemIMVector1
#define ImeIWdbeDddMVector1 IexWdbeDdd::ImeIMVector1
#define VecWImeIWdbeDddMVector1Iel IexWdbeDdd::ImeIMVector1::VecWIel

#define ImeitemIWdbeDddMUnit IexWdbeDdd::ImeitemIMUnit
#define ImeIWdbeDddMUnit IexWdbeDdd::ImeIMUnit
#define VecWImeIWdbeDddMUnitIel IexWdbeDdd::ImeIMUnit::VecWIel

/**
	* IexWdbeDdd
	*/
namespace IexWdbeDdd {
	/**
		* VecVIme (full: VecVIexWdbeDddIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMCOMMANDINVPAR1 = 1;
		static const Sbecore::uint IMEIAMCOMMANDINVPAR2 = 2;
		static const Sbecore::uint IMEIAMCOMMANDRETPAR1 = 3;
		static const Sbecore::uint IMEIAMCOMMANDRETPAR2 = 4;
		static const Sbecore::uint IMEIAMERRORPAR1 = 5;
		static const Sbecore::uint IMEIAMERRORPAR2 = 6;
		static const Sbecore::uint IMEIAMFSMSTATESTEP = 7;
		static const Sbecore::uint IMEIAMPINPAR = 8;
		static const Sbecore::uint IMEIAVKEYLISTKEY = 9;
		static const Sbecore::uint IMEICFSMSTATE = 10;
		static const Sbecore::uint IMEICGENERIC = 11;
		static const Sbecore::uint IMEICPIN = 12;
		static const Sbecore::uint IMEICPORT = 13;
		static const Sbecore::uint IMEICSIGNAL = 14;
		static const Sbecore::uint IMEICVARIABLE = 15;
		static const Sbecore::uint IMEIJAVKEYLISTKEY = 16;
		static const Sbecore::uint IMEIJMPINSREF = 17;
		static const Sbecore::uint IMEIMBANK = 18;
		static const Sbecore::uint IMEIMCOMMAND1 = 19;
		static const Sbecore::uint IMEIMCOMMAND2 = 20;
		static const Sbecore::uint IMEIMCONTROLLER = 21;
		static const Sbecore::uint IMEIMERROR1 = 22;
		static const Sbecore::uint IMEIMERROR2 = 23;
		static const Sbecore::uint IMEIMFSM = 24;
		static const Sbecore::uint IMEIMFSMSTATE = 25;
		static const Sbecore::uint IMEIMGENERIC = 26;
		static const Sbecore::uint IMEIMIMBUF = 27;
		static const Sbecore::uint IMEIMMODULE = 28;
		static const Sbecore::uint IMEIMPIN = 29;
		static const Sbecore::uint IMEIMPORT = 30;
		static const Sbecore::uint IMEIMPROCESS = 31;
		static const Sbecore::uint IMEIMSIGNAL = 32;
		static const Sbecore::uint IMEIMUNIT = 33;
		static const Sbecore::uint IMEIMVARIABLE = 34;
		static const Sbecore::uint IMEIMVECTOR1 = 35;
		static const Sbecore::uint IMEIMVECTOR2 = 36;
		static const Sbecore::uint IMEIMVECTORITEM1 = 37;
		static const Sbecore::uint IMEIMVECTORITEM2 = 38;
		static const Sbecore::uint IMEIRMCOMMANDMCONTROLLER = 39;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemICPin (full: ImeitemIWdbeDddCPin)
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
		* ImeICPin (full: ImeIWdbeDddCPin)
		*/
	class ImeICPin {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddCPinIel)
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
		* ImeitemIAMPinPar (full: ImeitemIWdbeDddAMPinPar)
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
		* ImeIAMPinPar (full: ImeIWdbeDddAMPinPar)
		*/
	class ImeIAMPinPar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddAMPinParIel)
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
		* ImeitemIJMPinSref (full: ImeitemIWdbeDddJMPinSref)
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
		* ImeIJMPinSref (full: ImeIWdbeDddJMPinSref)
		*/
	class ImeIJMPinSref {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddJMPinSrefIel)
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
		* ImeitemIMPin (full: ImeitemIWdbeDddMPin)
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
		* ImeIMPin (full: ImeIWdbeDddMPin)
		*/
	class ImeIMPin {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMPinIel)
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
		* ImeitemIMBank (full: ImeitemIWdbeDddMBank)
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
		* ImeIMBank (full: ImeIWdbeDddMBank)
		*/
	class ImeIMBank {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMBankIel)
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
		* ImeitemIAMCommandInvpar1 (full: ImeitemIWdbeDddAMCommandInvpar1)
		*/
	class ImeitemIAMCommandInvpar1 : public WdbeAMCommandInvpar {

	public:
		ImeitemIAMCommandInvpar1(const std::string& sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string& srefRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string& Defval = "", const std::string& srefRefWdbeMVectoritem = "", const std::string& Comment = "");
		ImeitemIAMCommandInvpar1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIAMCommandInvpar1 (full: ImeIWdbeDddAMCommandInvpar1)
		*/
	class ImeIAMCommandInvpar1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddAMCommandInvpar1Iel)
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
		ImeIAMCommandInvpar1();
		~ImeIAMCommandInvpar1();

	public:
		std::vector<ImeitemIAMCommandInvpar1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMCommandRetpar1 (full: ImeitemIWdbeDddAMCommandRetpar1)
		*/
	class ImeitemIAMCommandRetpar1 : public WdbeAMCommandRetpar {

	public:
		ImeitemIAMCommandRetpar1(const std::string& sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string& srefRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string& Comment = "");
		ImeitemIAMCommandRetpar1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIAMCommandRetpar1 (full: ImeIWdbeDddAMCommandRetpar1)
		*/
	class ImeIAMCommandRetpar1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddAMCommandRetpar1Iel)
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
		ImeIAMCommandRetpar1();
		~ImeIAMCommandRetpar1();

	public:
		std::vector<ImeitemIAMCommandRetpar1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCommand1 (full: ImeitemIWdbeDddMCommand1)
		*/
	class ImeitemIMCommand1 : public WdbeMCommand {

	public:
		ImeitemIMCommand1(const Sbecore::uint refNum = 0, const std::string& sref = "", const Sbecore::uint ixVRettype = 0, const std::string& Comment = "");
		ImeitemIMCommand1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVRettype;

		ImeIAMCommandInvpar1 imeiamcommandinvpar1;
		ImeIAMCommandRetpar1 imeiamcommandretpar1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCommand1 (full: ImeIWdbeDddMCommand1)
		*/
	class ImeIMCommand1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMCommand1Iel)
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
		ImeIMCommand1();
		~ImeIMCommand1();

	public:
		std::vector<ImeitemIMCommand1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMErrorPar1 (full: ImeitemIWdbeDddAMErrorPar1)
		*/
	class ImeitemIAMErrorPar1 : public WdbeAMErrorPar {

	public:
		ImeitemIAMErrorPar1(const std::string& sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string& srefRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string& Comment = "");
		ImeitemIAMErrorPar1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIAMErrorPar1 (full: ImeIWdbeDddAMErrorPar1)
		*/
	class ImeIAMErrorPar1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddAMErrorPar1Iel)
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
		ImeIAMErrorPar1();
		~ImeIAMErrorPar1();

	public:
		std::vector<ImeitemIAMErrorPar1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMError1 (full: ImeitemIWdbeDddMError1)
		*/
	class ImeitemIMError1 : public WdbeMError {

	public:
		ImeitemIMError1(const Sbecore::uint refNum = 0, const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMError1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMErrorPar1 imeiamerrorpar1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMError1 (full: ImeIWdbeDddMError1)
		*/
	class ImeIMError1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMError1Iel)
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
		ImeIMError1();
		~ImeIMError1();

	public:
		std::vector<ImeitemIMError1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICGeneric (full: ImeitemIWdbeDddCGeneric)
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
		* ImeICGeneric (full: ImeIWdbeDddCGeneric)
		*/
	class ImeICGeneric {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddCGenericIel)
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
		* ImeitemICPort (full: ImeitemIWdbeDddCPort)
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
		* ImeICPort (full: ImeIWdbeDddCPort)
		*/
	class ImeICPort {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddCPortIel)
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
		* ImeitemICSignal (full: ImeitemIWdbeDddCSignal)
		*/
	class ImeitemICSignal {

	public:
		ImeitemICSignal(const Sbecore::ubigint iref = 0);
		ImeitemICSignal(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeICSignal (full: ImeIWdbeDddCSignal)
		*/
	class ImeICSignal {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddCSignalIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICSignal();
		~ImeICSignal();

	public:
		std::vector<ImeitemICSignal*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMCommandInvpar2 (full: ImeitemIWdbeDddAMCommandInvpar2)
		*/
	class ImeitemIAMCommandInvpar2 : public WdbeAMCommandInvpar {

	public:
		ImeitemIAMCommandInvpar2(const std::string& sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string& srefRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string& Defval = "", const std::string& srefRefWdbeMVectoritem = "", const std::string& Comment = "");
		ImeitemIAMCommandInvpar2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIAMCommandInvpar2 (full: ImeIWdbeDddAMCommandInvpar2)
		*/
	class ImeIAMCommandInvpar2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddAMCommandInvpar2Iel)
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
		ImeIAMCommandInvpar2();
		~ImeIAMCommandInvpar2();

	public:
		std::vector<ImeitemIAMCommandInvpar2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMCommandRetpar2 (full: ImeitemIWdbeDddAMCommandRetpar2)
		*/
	class ImeitemIAMCommandRetpar2 : public WdbeAMCommandRetpar {

	public:
		ImeitemIAMCommandRetpar2(const std::string& sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string& srefRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string& Comment = "");
		ImeitemIAMCommandRetpar2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIAMCommandRetpar2 (full: ImeIWdbeDddAMCommandRetpar2)
		*/
	class ImeIAMCommandRetpar2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddAMCommandRetpar2Iel)
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
		ImeIAMCommandRetpar2();
		~ImeIAMCommandRetpar2();

	public:
		std::vector<ImeitemIAMCommandRetpar2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCommand2 (full: ImeitemIWdbeDddMCommand2)
		*/
	class ImeitemIMCommand2 : public WdbeMCommand {

	public:
		ImeitemIMCommand2(const Sbecore::uint refNum = 0, const std::string& sref = "", const Sbecore::uint ixVRettype = 0, const std::string& srefIvrRefWdbeMSignal = "", const std::string& srefRvrRefWdbeMSignal = "", const std::string& srefRerRefWdbeMSignal = "", const std::string& Comment = "");
		ImeitemIMCommand2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVRettype;
		std::string srefIvrRefWdbeMSignal;
		std::string srefRvrRefWdbeMSignal;
		std::string srefRerRefWdbeMSignal;

		ImeIAMCommandInvpar2 imeiamcommandinvpar2;
		ImeIAMCommandRetpar2 imeiamcommandretpar2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCommand2 (full: ImeIWdbeDddMCommand2)
		*/
	class ImeIMCommand2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMCommand2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint REFNUM = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFIXVRETTYPE = 4;
			static const Sbecore::uint SREFIVRREFWDBEMSIGNAL = 8;
			static const Sbecore::uint SREFRVRREFWDBEMSIGNAL = 16;
			static const Sbecore::uint SREFRERREFWDBEMSIGNAL = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMCommand2();
		~ImeIMCommand2();

	public:
		std::vector<ImeitemIMCommand2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMErrorPar2 (full: ImeitemIWdbeDddAMErrorPar2)
		*/
	class ImeitemIAMErrorPar2 : public WdbeAMErrorPar {

	public:
		ImeitemIAMErrorPar2(const std::string& sref = "", const Sbecore::uint ixWdbeVPartype = 0, const std::string& srefRefWdbeMVector = "", const Sbecore::utinyint Length = 0, const std::string& Comment = "");
		ImeitemIAMErrorPar2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIAMErrorPar2 (full: ImeIWdbeDddAMErrorPar2)
		*/
	class ImeIAMErrorPar2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddAMErrorPar2Iel)
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
		ImeIAMErrorPar2();
		~ImeIAMErrorPar2();

	public:
		std::vector<ImeitemIAMErrorPar2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMError2 (full: ImeitemIWdbeDddMError2)
		*/
	class ImeitemIMError2 : public WdbeMError {

	public:
		ImeitemIMError2(const Sbecore::uint refNum = 0, const std::string& sref = "", const std::string& srefTraRefWdbeMSignal = "", const std::string& Comment = "");
		ImeitemIMError2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefTraRefWdbeMSignal;

		ImeIAMErrorPar2 imeiamerrorpar2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMError2 (full: ImeIWdbeDddMError2)
		*/
	class ImeIMError2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMError2Iel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint REFNUM = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFTRAREFWDBEMSIGNAL = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMError2();
		~ImeIMError2();

	public:
		std::vector<ImeitemIMError2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVectoritem2 (full: ImeitemIWdbeDddMVectoritem2)
		*/
	class ImeitemIMVectoritem2 : public WdbeMVectoritem {

	public:
		ImeitemIMVectoritem2(const std::string& sref = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIMVectoritem2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIMVectoritem2 (full: ImeIWdbeDddMVectoritem2)
		*/
	class ImeIMVectoritem2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMVectoritem2Iel)
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
		ImeIMVectoritem2();
		~ImeIMVectoritem2();

	public:
		std::vector<ImeitemIMVectoritem2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVector2 (full: ImeitemIWdbeDddMVector2)
		*/
	class ImeitemIMVector2 : public WdbeMVector {

	public:
		ImeitemIMVector2(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& srefsKOption = "");
		ImeitemIMVector2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

		ImeIMVectoritem2 imeimvectoritem2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVector2 (full: ImeIWdbeDddMVector2)
		*/
	class ImeIMVector2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMVector2Iel)
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
		ImeIMVector2();
		~ImeIMVector2();

	public:
		std::vector<ImeitemIMVector2*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMCommandMController (full: ImeitemIWdbeDddRMCommandMController)
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
		* ImeIRMCommandMController (full: ImeIWdbeDddRMCommandMController)
		*/
	class ImeIRMCommandMController {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddRMCommandMControllerIel)
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
		* ImeitemIMController (full: ImeitemIWdbeDddMController)
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

		ImeIMCommand2 imeimcommand2;
		ImeIMError2 imeimerror2;
		ImeIMVector2 imeimvector2;
		ImeIRMCommandMController imeirmcommandmcontroller;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMController (full: ImeIWdbeDddMController)
		*/
	class ImeIMController {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMControllerIel)
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
		* ImeitemIMGeneric (full: ImeitemIWdbeDddMGeneric)
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
		* ImeIMGeneric (full: ImeIWdbeDddMGeneric)
		*/
	class ImeIMGeneric {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMGenericIel)
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
		* ImeitemIMImbuf (full: ImeitemIWdbeDddMImbuf)
		*/
	class ImeitemIMImbuf : public WdbeMImbuf {

	public:
		ImeitemIMImbuf(const Sbecore::utinyint Prio = 0);
		ImeitemIMImbuf(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIMImbuf (full: ImeIWdbeDddMImbuf)
		*/
	class ImeIMImbuf {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMImbufIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint PRIO = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMImbuf();
		~ImeIMImbuf();

	public:
		std::vector<ImeitemIMImbuf*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPort (full: ImeitemIWdbeDddMPort)
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
		* ImeIMPort (full: ImeIWdbeDddMPort)
		*/
	class ImeIMPort {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMPortIel)
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
		* ImeitemIJAVKeylistKey (full: ImeitemIWdbeDddJAVKeylistKey)
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
		* ImeIJAVKeylistKey (full: ImeIWdbeDddJAVKeylistKey)
		*/
	class ImeIJAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddJAVKeylistKeyIel)
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
		* ImeitemIAVKeylistKey (full: ImeitemIWdbeDddAVKeylistKey)
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
		* ImeIAVKeylistKey (full: ImeIWdbeDddAVKeylistKey)
		*/
	class ImeIAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddAVKeylistKeyIel)
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
		* ImeitemICVariable (full: ImeitemIWdbeDddCVariable)
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
		* ImeICVariable (full: ImeIWdbeDddCVariable)
		*/
	class ImeICVariable {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddCVariableIel)
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
		* ImeitemICFsmstate (full: ImeitemIWdbeDddCFsmstate)
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
		* ImeICFsmstate (full: ImeIWdbeDddCFsmstate)
		*/
	class ImeICFsmstate {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddCFsmstateIel)
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
		* ImeitemIAMFsmstateStep (full: ImeitemIWdbeDddAMFsmstateStep)
		*/
	class ImeitemIAMFsmstateStep : public WdbeAMFsmstateStep {

	public:
		ImeitemIAMFsmstateStep(const std::string& srefFnxRefWdbeMFsmstate = "", const std::string& Cond1 = "", const std::string& Ip1 = "", const std::string& Cond2 = "", const std::string& Ip2 = "", const std::string& Cond3 = "", const std::string& Ip3 = "", const std::string& Cond4 = "", const std::string& Ip4 = "");
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
		* ImeIAMFsmstateStep (full: ImeIWdbeDddAMFsmstateStep)
		*/
	class ImeIAMFsmstateStep {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddAMFsmstateStepIel)
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
		* ImeitemIMFsmstate (full: ImeitemIWdbeDddMFsmstate)
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
		* ImeIMFsmstate (full: ImeIWdbeDddMFsmstate)
		*/
	class ImeIMFsmstate {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMFsmstateIel)
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
		* ImeitemIMFsm (full: ImeitemIWdbeDddMFsm)
		*/
	class ImeitemIMFsm : public WdbeMFsm {

	public:
		ImeitemIMFsm();
		ImeitemIMFsm(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeICFsmstate imeicfsmstate;
		ImeIMFsmstate imeimfsmstate;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFsm (full: ImeIWdbeDddMFsm)
		*/
	class ImeIMFsm {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMFsmIel)
			*/
		class VecWIel {

		public:

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
		* ImeitemIMVariable (full: ImeitemIWdbeDddMVariable)
		*/
	class ImeitemIMVariable : public WdbeMVariable {

	public:
		ImeitemIMVariable(const Sbecore::ubigint irefRefWdbeCVariable = 0, const std::string& sref = "", const bool Const = false, const bool Falling = false, const std::string& srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const std::string& Onval = "", const std::string& Offval = "", const bool Defon = false, const std::string& Comment = "");
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
		* ImeIMVariable (full: ImeIWdbeDddMVariable)
		*/
	class ImeIMVariable {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMVariableIel)
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
			static const Sbecore::uint DEFON = 512;
			static const Sbecore::uint COMMENT = 1024;

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
		* ImeitemIMProcess (full: ImeitemIWdbeDddMProcess)
		*/
	class ImeitemIMProcess : public WdbeMProcess {

	public:
		ImeitemIMProcess(const std::string& sref = "", const std::string& clkSrefWdbeMSignal = "", const std::string& asrSrefWdbeMSignal = "", const bool Falling = false, const std::string& Syncrst = "", const bool Extip = false, const std::string& Comment = "");
		ImeitemIMProcess(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAVKeylistKey imeiavkeylistkey;
		ImeICVariable imeicvariable;
		ImeIMFsm imeimfsm;
		ImeIMVariable imeimvariable;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMProcess (full: ImeIWdbeDddMProcess)
		*/
	class ImeIMProcess {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMProcessIel)
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
		* ImeitemIMSignal (full: ImeitemIWdbeDddMSignal)
		*/
	class ImeitemIMSignal : public WdbeMSignal {

	public:
		ImeitemIMSignal(const Sbecore::uint ixVBasetype = 0, const Sbecore::ubigint irefRefWdbeCSignal = 0, const Sbecore::uint mgeIxVTbl = 0, const std::string& srefMgeUref = "", const std::string& sref = "", const bool Const = false, const std::string& srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const std::string& Comb = "", const std::string& Onval = "", const std::string& Offval = "", const bool Defon = false, const std::string& srefDrvRefWdbeMPort = "", const std::string& Comment = "");
		ImeitemIMSignal(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIMSignal (full: ImeIWdbeDddMSignal)
		*/
	class ImeIMSignal {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMSignalIel)
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
			static const Sbecore::uint DEFON = 4096;
			static const Sbecore::uint SREFDRVREFWDBEMPORT = 8192;
			static const Sbecore::uint COMMENT = 16384;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSignal();
		~ImeIMSignal();

	public:
		std::vector<ImeitemIMSignal*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMModule (full: ImeitemIWdbeDddMModule)
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
		ImeICSignal imeicsignal;
		ImeIMController imeimcontroller;
		ImeIMGeneric imeimgeneric;
		ImeIMImbuf imeimimbuf;
		ImeIMPort imeimport;
		ImeIMProcess imeimprocess;
		ImeIMSignal imeimsignal;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMModule (full: ImeIWdbeDddMModule)
		*/
	class ImeIMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMModuleIel)
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
		* ImeitemIMVectoritem1 (full: ImeitemIWdbeDddMVectoritem1)
		*/
	class ImeitemIMVectoritem1 : public WdbeMVectoritem {

	public:
		ImeitemIMVectoritem1(const std::string& sref = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIMVectoritem1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIMVectoritem1 (full: ImeIWdbeDddMVectoritem1)
		*/
	class ImeIMVectoritem1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMVectoritem1Iel)
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
		ImeIMVectoritem1();
		~ImeIMVectoritem1();

	public:
		std::vector<ImeitemIMVectoritem1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVector1 (full: ImeitemIWdbeDddMVector1)
		*/
	class ImeitemIMVector1 : public WdbeMVector {

	public:
		ImeitemIMVector1(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& srefsKOption = "");
		ImeitemIMVector1(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

		ImeIMVectoritem1 imeimvectoritem1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVector1 (full: ImeIWdbeDddMVector1)
		*/
	class ImeIMVector1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMVector1Iel)
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
		ImeIMVector1();
		~ImeIMVector1();

	public:
		std::vector<ImeitemIMVector1*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUnit (full: ImeitemIWdbeDddMUnit)
		*/
	class ImeitemIMUnit : public WdbeMUnit {

	public:
		ImeitemIMUnit(const std::string& sref = "");
		ImeitemIMUnit(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIMBank imeimbank;
		ImeIMCommand1 imeimcommand1;
		ImeIMError1 imeimerror1;
		ImeIMModule imeimmodule;
		ImeIMVector1 imeimvector1;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUnit (full: ImeIWdbeDddMUnit)
		*/
	class ImeIMUnit {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDddMUnitIel)
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

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIMUnit& imeimunit);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMUnit& imeimunit);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMUnit& imeimunit);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMUnit& imeimunit);

	void writeTxt(std::fstream& outfile, ImeIMUnit& imeimunit);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMUnit& imeimunit);

	std::map<Sbecore::uint,Sbecore::uint> icsWdbeVIopInsAll();
	Sbecore::uint getIxWdbeVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWdbeVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWdbeVIop);
};

#endif

