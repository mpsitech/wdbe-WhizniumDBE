/**
	* \file IexWdbeDcd.h
	* data blocks and readers/writers for import/export complex IexWdbeDcd (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef IEXWDBEDCD_H
#define IEXWDBEDCD_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWdbe.h"
#include "VecWdbeVIop.h"

#define VecVIexWdbeDcdIme IexWdbeDcd::VecVIme

#define ImeitemIWdbeDcdAMCoreversionIp IexWdbeDcd::ImeitemIAMCoreversionIp
#define ImeIWdbeDcdAMCoreversionIp IexWdbeDcd::ImeIAMCoreversionIp
#define VecWImeIWdbeDcdAMCoreversionIpIel IexWdbeDcd::ImeIAMCoreversionIp::VecWIel

#define ImeitemIWdbeDcdAMCoreversionPlh IexWdbeDcd::ImeitemIAMCoreversionPlh
#define ImeIWdbeDcdAMCoreversionPlh IexWdbeDcd::ImeIAMCoreversionPlh
#define VecWImeIWdbeDcdAMCoreversionPlhIel IexWdbeDcd::ImeIAMCoreversionPlh::VecWIel

#define ImeitemIWdbeDcdCGeneric IexWdbeDcd::ImeitemICGeneric
#define ImeIWdbeDcdCGeneric IexWdbeDcd::ImeICGeneric
#define VecWImeIWdbeDcdCGenericIel IexWdbeDcd::ImeICGeneric::VecWIel

#define ImeitemIWdbeDcdCPort IexWdbeDcd::ImeitemICPort
#define ImeIWdbeDcdCPort IexWdbeDcd::ImeICPort
#define VecWImeIWdbeDcdCPortIel IexWdbeDcd::ImeICPort::VecWIel

#define ImeitemIWdbeDcdCSignal IexWdbeDcd::ImeitemICSignal
#define ImeIWdbeDcdCSignal IexWdbeDcd::ImeICSignal
#define VecWImeIWdbeDcdCSignalIel IexWdbeDcd::ImeICSignal::VecWIel

#define ImeitemIWdbeDcdAMCommandInvpar IexWdbeDcd::ImeitemIAMCommandInvpar
#define ImeIWdbeDcdAMCommandInvpar IexWdbeDcd::ImeIAMCommandInvpar
#define VecWImeIWdbeDcdAMCommandInvparIel IexWdbeDcd::ImeIAMCommandInvpar::VecWIel

#define ImeitemIWdbeDcdAMCommandRetpar IexWdbeDcd::ImeitemIAMCommandRetpar
#define ImeIWdbeDcdAMCommandRetpar IexWdbeDcd::ImeIAMCommandRetpar
#define VecWImeIWdbeDcdAMCommandRetparIel IexWdbeDcd::ImeIAMCommandRetpar::VecWIel

#define ImeitemIWdbeDcdMCommand IexWdbeDcd::ImeitemIMCommand
#define ImeIWdbeDcdMCommand IexWdbeDcd::ImeIMCommand
#define VecWImeIWdbeDcdMCommandIel IexWdbeDcd::ImeIMCommand::VecWIel

#define ImeitemIWdbeDcdAMErrorPar IexWdbeDcd::ImeitemIAMErrorPar
#define ImeIWdbeDcdAMErrorPar IexWdbeDcd::ImeIAMErrorPar
#define VecWImeIWdbeDcdAMErrorParIel IexWdbeDcd::ImeIAMErrorPar::VecWIel

#define ImeitemIWdbeDcdMError IexWdbeDcd::ImeitemIMError
#define ImeIWdbeDcdMError IexWdbeDcd::ImeIMError
#define VecWImeIWdbeDcdMErrorIel IexWdbeDcd::ImeIMError::VecWIel

#define ImeitemIWdbeDcdMVector IexWdbeDcd::ImeitemIMVector
#define ImeIWdbeDcdMVector IexWdbeDcd::ImeIMVector
#define VecWImeIWdbeDcdMVectorIel IexWdbeDcd::ImeIMVector::VecWIel

#define ImeitemIWdbeDcdMController IexWdbeDcd::ImeitemIMController
#define ImeIWdbeDcdMController IexWdbeDcd::ImeIMController
#define VecWImeIWdbeDcdMControllerIel IexWdbeDcd::ImeIMController::VecWIel

#define ImeitemIWdbeDcdMGeneric IexWdbeDcd::ImeitemIMGeneric
#define ImeIWdbeDcdMGeneric IexWdbeDcd::ImeIMGeneric
#define VecWImeIWdbeDcdMGenericIel IexWdbeDcd::ImeIMGeneric::VecWIel

#define ImeitemIWdbeDcdMPort IexWdbeDcd::ImeitemIMPort
#define ImeIWdbeDcdMPort IexWdbeDcd::ImeIMPort
#define VecWImeIWdbeDcdMPortIel IexWdbeDcd::ImeIMPort::VecWIel

#define ImeitemIWdbeDcdJAVKeylistKey IexWdbeDcd::ImeitemIJAVKeylistKey
#define ImeIWdbeDcdJAVKeylistKey IexWdbeDcd::ImeIJAVKeylistKey
#define VecWImeIWdbeDcdJAVKeylistKeyIel IexWdbeDcd::ImeIJAVKeylistKey::VecWIel

#define ImeitemIWdbeDcdAVKeylistKey IexWdbeDcd::ImeitemIAVKeylistKey
#define ImeIWdbeDcdAVKeylistKey IexWdbeDcd::ImeIAVKeylistKey
#define VecWImeIWdbeDcdAVKeylistKeyIel IexWdbeDcd::ImeIAVKeylistKey::VecWIel

#define ImeitemIWdbeDcdCVariable IexWdbeDcd::ImeitemICVariable
#define ImeIWdbeDcdCVariable IexWdbeDcd::ImeICVariable
#define VecWImeIWdbeDcdCVariableIel IexWdbeDcd::ImeICVariable::VecWIel

#define ImeitemIWdbeDcdCFsmstate IexWdbeDcd::ImeitemICFsmstate
#define ImeIWdbeDcdCFsmstate IexWdbeDcd::ImeICFsmstate
#define VecWImeIWdbeDcdCFsmstateIel IexWdbeDcd::ImeICFsmstate::VecWIel

#define ImeitemIWdbeDcdAMFsmstateStep IexWdbeDcd::ImeitemIAMFsmstateStep
#define ImeIWdbeDcdAMFsmstateStep IexWdbeDcd::ImeIAMFsmstateStep
#define VecWImeIWdbeDcdAMFsmstateStepIel IexWdbeDcd::ImeIAMFsmstateStep::VecWIel

#define ImeitemIWdbeDcdMFsmstate IexWdbeDcd::ImeitemIMFsmstate
#define ImeIWdbeDcdMFsmstate IexWdbeDcd::ImeIMFsmstate
#define VecWImeIWdbeDcdMFsmstateIel IexWdbeDcd::ImeIMFsmstate::VecWIel

#define ImeitemIWdbeDcdMFsm IexWdbeDcd::ImeitemIMFsm
#define ImeIWdbeDcdMFsm IexWdbeDcd::ImeIMFsm
#define VecWImeIWdbeDcdMFsmIel IexWdbeDcd::ImeIMFsm::VecWIel

#define ImeitemIWdbeDcdMVariable IexWdbeDcd::ImeitemIMVariable
#define ImeIWdbeDcdMVariable IexWdbeDcd::ImeIMVariable
#define VecWImeIWdbeDcdMVariableIel IexWdbeDcd::ImeIMVariable::VecWIel

#define ImeitemIWdbeDcdMProcess IexWdbeDcd::ImeitemIMProcess
#define ImeIWdbeDcdMProcess IexWdbeDcd::ImeIMProcess
#define VecWImeIWdbeDcdMProcessIel IexWdbeDcd::ImeIMProcess::VecWIel

#define ImeitemIWdbeDcdMSignal IexWdbeDcd::ImeitemIMSignal
#define ImeIWdbeDcdMSignal IexWdbeDcd::ImeIMSignal
#define VecWImeIWdbeDcdMSignalIel IexWdbeDcd::ImeIMSignal::VecWIel

#define ImeitemIWdbeDcdMModule IexWdbeDcd::ImeitemIMModule
#define ImeIWdbeDcdMModule IexWdbeDcd::ImeIMModule
#define VecWImeIWdbeDcdMModuleIel IexWdbeDcd::ImeIMModule::VecWIel

/**
	* IexWdbeDcd
	*/
namespace IexWdbeDcd {
	/**
		* VecVIme (full: VecVIexWdbeDcdIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMCOMMANDINVPAR = 1;
		static const Sbecore::uint IMEIAMCOMMANDRETPAR = 2;
		static const Sbecore::uint IMEIAMCOREVERSIONIP = 3;
		static const Sbecore::uint IMEIAMCOREVERSIONPLH = 4;
		static const Sbecore::uint IMEIAMERRORPAR = 5;
		static const Sbecore::uint IMEIAMFSMSTATESTEP = 6;
		static const Sbecore::uint IMEIAVKEYLISTKEY = 7;
		static const Sbecore::uint IMEICFSMSTATE = 8;
		static const Sbecore::uint IMEICGENERIC = 9;
		static const Sbecore::uint IMEICPORT = 10;
		static const Sbecore::uint IMEICSIGNAL = 11;
		static const Sbecore::uint IMEICVARIABLE = 12;
		static const Sbecore::uint IMEIJAVKEYLISTKEY = 13;
		static const Sbecore::uint IMEIMCOMMAND = 14;
		static const Sbecore::uint IMEIMCONTROLLER = 15;
		static const Sbecore::uint IMEIMERROR = 16;
		static const Sbecore::uint IMEIMFSM = 17;
		static const Sbecore::uint IMEIMFSMSTATE = 18;
		static const Sbecore::uint IMEIMGENERIC = 19;
		static const Sbecore::uint IMEIMMODULE = 20;
		static const Sbecore::uint IMEIMPORT = 21;
		static const Sbecore::uint IMEIMPROCESS = 22;
		static const Sbecore::uint IMEIMSIGNAL = 23;
		static const Sbecore::uint IMEIMVARIABLE = 24;
		static const Sbecore::uint IMEIMVECTOR = 25;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAMCoreversionIp (full: ImeitemIWdbeDcdAMCoreversionIp)
		*/
	class ImeitemIAMCoreversionIp : public WdbeAMCoreversionIp {

	public:
		ImeitemIAMCoreversionIp(const std::string& sref = "", const Sbecore::uint ixVTagtype = 0, const std::string& Comment = "");
		ImeitemIAMCoreversionIp(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVTagtype;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMCoreversionIp (full: ImeIWdbeDcdAMCoreversionIp)
		*/
	class ImeIAMCoreversionIp {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdAMCoreversionIpIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXVTAGTYPE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMCoreversionIp();
		~ImeIAMCoreversionIp();

	public:
		std::vector<ImeitemIAMCoreversionIp*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMCoreversionPlh (full: ImeitemIWdbeDcdAMCoreversionPlh)
		*/
	class ImeitemIAMCoreversionPlh : public WdbeAMCoreversionPlh {

	public:
		ImeitemIAMCoreversionPlh(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIAMCoreversionPlh(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIAMCoreversionPlh (full: ImeIWdbeDcdAMCoreversionPlh)
		*/
	class ImeIAMCoreversionPlh {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdAMCoreversionPlhIel)
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
		ImeIAMCoreversionPlh();
		~ImeIAMCoreversionPlh();

	public:
		std::vector<ImeitemIAMCoreversionPlh*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemICGeneric (full: ImeitemIWdbeDcdCGeneric)
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
		* ImeICGeneric (full: ImeIWdbeDcdCGeneric)
		*/
	class ImeICGeneric {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdCGenericIel)
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
		* ImeitemICPort (full: ImeitemIWdbeDcdCPort)
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
		* ImeICPort (full: ImeIWdbeDcdCPort)
		*/
	class ImeICPort {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdCPortIel)
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
		* ImeitemICSignal (full: ImeitemIWdbeDcdCSignal)
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
		* ImeICSignal (full: ImeIWdbeDcdCSignal)
		*/
	class ImeICSignal {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdCSignalIel)
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
		* ImeitemIAMCommandInvpar (full: ImeitemIWdbeDcdAMCommandInvpar)
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
		* ImeIAMCommandInvpar (full: ImeIWdbeDcdAMCommandInvpar)
		*/
	class ImeIAMCommandInvpar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdAMCommandInvparIel)
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
		* ImeitemIAMCommandRetpar (full: ImeitemIWdbeDcdAMCommandRetpar)
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
		* ImeIAMCommandRetpar (full: ImeIWdbeDcdAMCommandRetpar)
		*/
	class ImeIAMCommandRetpar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdAMCommandRetparIel)
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
		* ImeitemIMCommand (full: ImeitemIWdbeDcdMCommand)
		*/
	class ImeitemIMCommand : public WdbeMCommand {

	public:
		ImeitemIMCommand(const Sbecore::uint refNum = 0, const std::string& sref = "", const Sbecore::uint ixVRettype = 0, const std::string& srefIvrRefWdbeMSignal = "", const std::string& srefRvrRefWdbeMSignal = "", const std::string& srefRerRefWdbeMSignal = "", const std::string& Comment = "");
		ImeitemIMCommand(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVRettype;
		std::string srefIvrRefWdbeMSignal;
		std::string srefRvrRefWdbeMSignal;
		std::string srefRerRefWdbeMSignal;

		ImeIAMCommandInvpar imeiamcommandinvpar;
		ImeIAMCommandRetpar imeiamcommandretpar;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCommand (full: ImeIWdbeDcdMCommand)
		*/
	class ImeIMCommand {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMCommandIel)
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
		* ImeitemIAMErrorPar (full: ImeitemIWdbeDcdAMErrorPar)
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
		* ImeIAMErrorPar (full: ImeIWdbeDcdAMErrorPar)
		*/
	class ImeIAMErrorPar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdAMErrorParIel)
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
		* ImeitemIMError (full: ImeitemIWdbeDcdMError)
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
		* ImeIMError (full: ImeIWdbeDcdMError)
		*/
	class ImeIMError {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMErrorIel)
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
		* ImeitemIMVector (full: ImeitemIWdbeDcdMVector)
		*/
	class ImeitemIMVector : public WdbeMVector {

	public:
		ImeitemIMVector(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& srefsKOption = "");
		ImeitemIMVector(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVector (full: ImeIWdbeDcdMVector)
		*/
	class ImeIMVector {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMVectorIel)
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
		* ImeitemIMController (full: ImeitemIWdbeDcdMController)
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
		ImeIMVector imeimvector;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMController (full: ImeIWdbeDcdMController)
		*/
	class ImeIMController {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMControllerIel)
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
		* ImeitemIMGeneric (full: ImeitemIWdbeDcdMGeneric)
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
		* ImeIMGeneric (full: ImeIWdbeDcdMGeneric)
		*/
	class ImeIMGeneric {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMGenericIel)
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
		* ImeitemIMPort (full: ImeitemIWdbeDcdMPort)
		*/
	class ImeitemIMPort : public WdbeMPort {

	public:
		ImeitemIMPort(const Sbecore::uint ixWdbeVIop = 0, const Sbecore::ubigint irefRefWdbeCPort = 0, const Sbecore::uint mdlIxVCat = 0, const std::string& sref = "", const Sbecore::uint ixVDir = 0, const std::string& srefWdbeKHdltype = "", const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const std::string& Defval = "", const std::string& cprSrefWdbeMPort = "", const std::string& csiSrefWdbeMSignal = "", const std::string& Comment = "");
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
		* ImeIMPort (full: ImeIWdbeDcdMPort)
		*/
	class ImeIMPort {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMPortIel)
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
			static const Sbecore::uint CPRSREFWDBEMPORT = 512;
			static const Sbecore::uint CSISREFWDBEMSIGNAL = 1024;
			static const Sbecore::uint COMMENT = 2048;

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
		* ImeitemIJAVKeylistKey (full: ImeitemIWdbeDcdJAVKeylistKey)
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
		* ImeIJAVKeylistKey (full: ImeIWdbeDcdJAVKeylistKey)
		*/
	class ImeIJAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdJAVKeylistKeyIel)
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
		* ImeitemIAVKeylistKey (full: ImeitemIWdbeDcdAVKeylistKey)
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
		* ImeIAVKeylistKey (full: ImeIWdbeDcdAVKeylistKey)
		*/
	class ImeIAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdAVKeylistKeyIel)
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
		* ImeitemICVariable (full: ImeitemIWdbeDcdCVariable)
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
		* ImeICVariable (full: ImeIWdbeDcdCVariable)
		*/
	class ImeICVariable {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdCVariableIel)
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
		* ImeitemICFsmstate (full: ImeitemIWdbeDcdCFsmstate)
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
		* ImeICFsmstate (full: ImeIWdbeDcdCFsmstate)
		*/
	class ImeICFsmstate {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdCFsmstateIel)
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
		* ImeitemIAMFsmstateStep (full: ImeitemIWdbeDcdAMFsmstateStep)
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
		* ImeIAMFsmstateStep (full: ImeIWdbeDcdAMFsmstateStep)
		*/
	class ImeIAMFsmstateStep {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdAMFsmstateStepIel)
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
		* ImeitemIMFsmstate (full: ImeitemIWdbeDcdMFsmstate)
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
		* ImeIMFsmstate (full: ImeIWdbeDcdMFsmstate)
		*/
	class ImeIMFsmstate {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMFsmstateIel)
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
		* ImeitemIMFsm (full: ImeitemIWdbeDcdMFsm)
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
		* ImeIMFsm (full: ImeIWdbeDcdMFsm)
		*/
	class ImeIMFsm {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMFsmIel)
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
		* ImeitemIMVariable (full: ImeitemIWdbeDcdMVariable)
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
		* ImeIMVariable (full: ImeIWdbeDcdMVariable)
		*/
	class ImeIMVariable {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMVariableIel)
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
		* ImeitemIMProcess (full: ImeitemIWdbeDcdMProcess)
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
		* ImeIMProcess (full: ImeIWdbeDcdMProcess)
		*/
	class ImeIMProcess {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMProcessIel)
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
		* ImeitemIMSignal (full: ImeitemIWdbeDcdMSignal)
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
		* ImeIMSignal (full: ImeIWdbeDcdMSignal)
		*/
	class ImeIMSignal {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMSignalIel)
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
		* ImeitemIMModule (full: ImeitemIWdbeDcdMModule)
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
		* ImeIMModule (full: ImeIWdbeDcdMModule)
		*/
	class ImeIMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDcdMModuleIel)
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

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIAMCoreversionIp& imeiamcoreversionip, ImeIAMCoreversionPlh& imeiamcoreversionplh, ImeIMModule& imeimmodule);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIAMCoreversionIp& imeiamcoreversionip, ImeIAMCoreversionPlh& imeiamcoreversionplh, ImeIMModule& imeimmodule);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIAMCoreversionIp& imeiamcoreversionip, ImeIAMCoreversionPlh& imeiamcoreversionplh, ImeIMModule& imeimmodule);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIAMCoreversionIp& imeiamcoreversionip, ImeIAMCoreversionPlh& imeiamcoreversionplh, ImeIMModule& imeimmodule);

	void writeTxt(std::fstream& outfile, ImeIAMCoreversionIp& imeiamcoreversionip, ImeIAMCoreversionPlh& imeiamcoreversionplh, ImeIMModule& imeimmodule);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIAMCoreversionIp& imeiamcoreversionip, ImeIAMCoreversionPlh& imeiamcoreversionplh, ImeIMModule& imeimmodule);

	std::map<Sbecore::uint,Sbecore::uint> icsWdbeVIopInsAll();
	Sbecore::uint getIxWdbeVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWdbeVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWdbeVIop);
};

#endif

