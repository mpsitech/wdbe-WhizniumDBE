/**
	* \file IexWdbeCsx.h
	* data blocks and readers/writers for import/export complex IexWdbeCsx (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef IEXWDBECSX_H
#define IEXWDBECSX_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWdbe.h"
#include "VecWdbeVIop.h"

#define VecVIexWdbeCsxIme IexWdbeCsx::VecVIme

#define ImeitemIWdbeCsxAMCommandInvpar1 IexWdbeCsx::ImeitemIAMCommandInvpar1
#define ImeIWdbeCsxAMCommandInvpar1 IexWdbeCsx::ImeIAMCommandInvpar1
#define VecWImeIWdbeCsxAMCommandInvpar1Iel IexWdbeCsx::ImeIAMCommandInvpar1::VecWIel

#define ImeitemIWdbeCsxAMCommandRetpar1 IexWdbeCsx::ImeitemIAMCommandRetpar1
#define ImeIWdbeCsxAMCommandRetpar1 IexWdbeCsx::ImeIAMCommandRetpar1
#define VecWImeIWdbeCsxAMCommandRetpar1Iel IexWdbeCsx::ImeIAMCommandRetpar1::VecWIel

#define ImeitemIWdbeCsxMCommand1 IexWdbeCsx::ImeitemIMCommand1
#define ImeIWdbeCsxMCommand1 IexWdbeCsx::ImeIMCommand1
#define VecWImeIWdbeCsxMCommand1Iel IexWdbeCsx::ImeIMCommand1::VecWIel

#define ImeitemIWdbeCsxAMErrorPar1 IexWdbeCsx::ImeitemIAMErrorPar1
#define ImeIWdbeCsxAMErrorPar1 IexWdbeCsx::ImeIAMErrorPar1
#define VecWImeIWdbeCsxAMErrorPar1Iel IexWdbeCsx::ImeIAMErrorPar1::VecWIel

#define ImeitemIWdbeCsxMError1 IexWdbeCsx::ImeitemIMError1
#define ImeIWdbeCsxMError1 IexWdbeCsx::ImeIMError1
#define VecWImeIWdbeCsxMError1Iel IexWdbeCsx::ImeIMError1::VecWIel

#define ImeitemIWdbeCsxAMCommandInvpar2 IexWdbeCsx::ImeitemIAMCommandInvpar2
#define ImeIWdbeCsxAMCommandInvpar2 IexWdbeCsx::ImeIAMCommandInvpar2
#define VecWImeIWdbeCsxAMCommandInvpar2Iel IexWdbeCsx::ImeIAMCommandInvpar2::VecWIel

#define ImeitemIWdbeCsxAMCommandRetpar2 IexWdbeCsx::ImeitemIAMCommandRetpar2
#define ImeIWdbeCsxAMCommandRetpar2 IexWdbeCsx::ImeIAMCommandRetpar2
#define VecWImeIWdbeCsxAMCommandRetpar2Iel IexWdbeCsx::ImeIAMCommandRetpar2::VecWIel

#define ImeitemIWdbeCsxMCommand2 IexWdbeCsx::ImeitemIMCommand2
#define ImeIWdbeCsxMCommand2 IexWdbeCsx::ImeIMCommand2
#define VecWImeIWdbeCsxMCommand2Iel IexWdbeCsx::ImeIMCommand2::VecWIel

#define ImeitemIWdbeCsxAMErrorPar2 IexWdbeCsx::ImeitemIAMErrorPar2
#define ImeIWdbeCsxAMErrorPar2 IexWdbeCsx::ImeIAMErrorPar2
#define VecWImeIWdbeCsxAMErrorPar2Iel IexWdbeCsx::ImeIAMErrorPar2::VecWIel

#define ImeitemIWdbeCsxMError2 IexWdbeCsx::ImeitemIMError2
#define ImeIWdbeCsxMError2 IexWdbeCsx::ImeIMError2
#define VecWImeIWdbeCsxMError2Iel IexWdbeCsx::ImeIMError2::VecWIel

#define ImeitemIWdbeCsxMVectoritem2 IexWdbeCsx::ImeitemIMVectoritem2
#define ImeIWdbeCsxMVectoritem2 IexWdbeCsx::ImeIMVectoritem2
#define VecWImeIWdbeCsxMVectoritem2Iel IexWdbeCsx::ImeIMVectoritem2::VecWIel

#define ImeitemIWdbeCsxMVector2 IexWdbeCsx::ImeitemIMVector2
#define ImeIWdbeCsxMVector2 IexWdbeCsx::ImeIMVector2
#define VecWImeIWdbeCsxMVector2Iel IexWdbeCsx::ImeIMVector2::VecWIel

#define ImeitemIWdbeCsxRMCommandMController IexWdbeCsx::ImeitemIRMCommandMController
#define ImeIWdbeCsxRMCommandMController IexWdbeCsx::ImeIRMCommandMController
#define VecWImeIWdbeCsxRMCommandMControllerIel IexWdbeCsx::ImeIRMCommandMController::VecWIel

#define ImeitemIWdbeCsxMController IexWdbeCsx::ImeitemIMController
#define ImeIWdbeCsxMController IexWdbeCsx::ImeIMController
#define VecWImeIWdbeCsxMControllerIel IexWdbeCsx::ImeIMController::VecWIel

#define ImeitemIWdbeCsxMModule IexWdbeCsx::ImeitemIMModule
#define ImeIWdbeCsxMModule IexWdbeCsx::ImeIMModule
#define VecWImeIWdbeCsxMModuleIel IexWdbeCsx::ImeIMModule::VecWIel

#define ImeitemIWdbeCsxMVectoritem1 IexWdbeCsx::ImeitemIMVectoritem1
#define ImeIWdbeCsxMVectoritem1 IexWdbeCsx::ImeIMVectoritem1
#define VecWImeIWdbeCsxMVectoritem1Iel IexWdbeCsx::ImeIMVectoritem1::VecWIel

#define ImeitemIWdbeCsxMVector1 IexWdbeCsx::ImeitemIMVector1
#define ImeIWdbeCsxMVector1 IexWdbeCsx::ImeIMVector1
#define VecWImeIWdbeCsxMVector1Iel IexWdbeCsx::ImeIMVector1::VecWIel

#define ImeitemIWdbeCsxMUnit IexWdbeCsx::ImeitemIMUnit
#define ImeIWdbeCsxMUnit IexWdbeCsx::ImeIMUnit
#define VecWImeIWdbeCsxMUnitIel IexWdbeCsx::ImeIMUnit::VecWIel

/**
	* IexWdbeCsx
	*/
namespace IexWdbeCsx {
	/**
		* VecVIme (full: VecVIexWdbeCsxIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMCOMMANDINVPAR1 = 1;
		static const Sbecore::uint IMEIAMCOMMANDINVPAR2 = 2;
		static const Sbecore::uint IMEIAMCOMMANDRETPAR1 = 3;
		static const Sbecore::uint IMEIAMCOMMANDRETPAR2 = 4;
		static const Sbecore::uint IMEIAMERRORPAR1 = 5;
		static const Sbecore::uint IMEIAMERRORPAR2 = 6;
		static const Sbecore::uint IMEIMCOMMAND1 = 7;
		static const Sbecore::uint IMEIMCOMMAND2 = 8;
		static const Sbecore::uint IMEIMCONTROLLER = 9;
		static const Sbecore::uint IMEIMERROR1 = 10;
		static const Sbecore::uint IMEIMERROR2 = 11;
		static const Sbecore::uint IMEIMMODULE = 12;
		static const Sbecore::uint IMEIMUNIT = 13;
		static const Sbecore::uint IMEIMVECTOR1 = 14;
		static const Sbecore::uint IMEIMVECTOR2 = 15;
		static const Sbecore::uint IMEIMVECTORITEM1 = 16;
		static const Sbecore::uint IMEIMVECTORITEM2 = 17;
		static const Sbecore::uint IMEIRMCOMMANDMCONTROLLER = 18;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAMCommandInvpar1 (full: ImeitemIWdbeCsxAMCommandInvpar1)
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
		* ImeIAMCommandInvpar1 (full: ImeIWdbeCsxAMCommandInvpar1)
		*/
	class ImeIAMCommandInvpar1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxAMCommandInvpar1Iel)
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
		* ImeitemIAMCommandRetpar1 (full: ImeitemIWdbeCsxAMCommandRetpar1)
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
		* ImeIAMCommandRetpar1 (full: ImeIWdbeCsxAMCommandRetpar1)
		*/
	class ImeIAMCommandRetpar1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxAMCommandRetpar1Iel)
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
		* ImeitemIMCommand1 (full: ImeitemIWdbeCsxMCommand1)
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
		* ImeIMCommand1 (full: ImeIWdbeCsxMCommand1)
		*/
	class ImeIMCommand1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxMCommand1Iel)
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
		* ImeitemIAMErrorPar1 (full: ImeitemIWdbeCsxAMErrorPar1)
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
		* ImeIAMErrorPar1 (full: ImeIWdbeCsxAMErrorPar1)
		*/
	class ImeIAMErrorPar1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxAMErrorPar1Iel)
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
		* ImeitemIMError1 (full: ImeitemIWdbeCsxMError1)
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
		* ImeIMError1 (full: ImeIWdbeCsxMError1)
		*/
	class ImeIMError1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxMError1Iel)
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
		* ImeitemIAMCommandInvpar2 (full: ImeitemIWdbeCsxAMCommandInvpar2)
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
		* ImeIAMCommandInvpar2 (full: ImeIWdbeCsxAMCommandInvpar2)
		*/
	class ImeIAMCommandInvpar2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxAMCommandInvpar2Iel)
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
		* ImeitemIAMCommandRetpar2 (full: ImeitemIWdbeCsxAMCommandRetpar2)
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
		* ImeIAMCommandRetpar2 (full: ImeIWdbeCsxAMCommandRetpar2)
		*/
	class ImeIAMCommandRetpar2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxAMCommandRetpar2Iel)
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
		* ImeitemIMCommand2 (full: ImeitemIWdbeCsxMCommand2)
		*/
	class ImeitemIMCommand2 : public WdbeMCommand {

	public:
		ImeitemIMCommand2(const Sbecore::uint refNum = 0, const std::string& sref = "", const Sbecore::uint ixVRettype = 0, const std::string& Comment = "");
		ImeitemIMCommand2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVRettype;

		ImeIAMCommandInvpar2 imeiamcommandinvpar2;
		ImeIAMCommandRetpar2 imeiamcommandretpar2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCommand2 (full: ImeIWdbeCsxMCommand2)
		*/
	class ImeIMCommand2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxMCommand2Iel)
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
		* ImeitemIAMErrorPar2 (full: ImeitemIWdbeCsxAMErrorPar2)
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
		* ImeIAMErrorPar2 (full: ImeIWdbeCsxAMErrorPar2)
		*/
	class ImeIAMErrorPar2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxAMErrorPar2Iel)
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
		* ImeitemIMError2 (full: ImeitemIWdbeCsxMError2)
		*/
	class ImeitemIMError2 : public WdbeMError {

	public:
		ImeitemIMError2(const Sbecore::uint refNum = 0, const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMError2(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMErrorPar2 imeiamerrorpar2;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMError2 (full: ImeIWdbeCsxMError2)
		*/
	class ImeIMError2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxMError2Iel)
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
		* ImeitemIMVectoritem2 (full: ImeitemIWdbeCsxMVectoritem2)
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
		* ImeIMVectoritem2 (full: ImeIWdbeCsxMVectoritem2)
		*/
	class ImeIMVectoritem2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxMVectoritem2Iel)
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
		* ImeitemIMVector2 (full: ImeitemIWdbeCsxMVector2)
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
		* ImeIMVector2 (full: ImeIWdbeCsxMVector2)
		*/
	class ImeIMVector2 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxMVector2Iel)
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
		* ImeitemIRMCommandMController (full: ImeitemIWdbeCsxRMCommandMController)
		*/
	class ImeitemIRMCommandMController : public WdbeRMCommandMController {

	public:
		ImeitemIRMCommandMController(const std::string& srefRefWdbeMCommand = "");
		ImeitemIRMCommandMController(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWdbeMCommand;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMCommandMController (full: ImeIWdbeCsxRMCommandMController)
		*/
	class ImeIRMCommandMController {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxRMCommandMControllerIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWDBEMCOMMAND = 1;

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
		* ImeitemIMController (full: ImeitemIWdbeCsxMController)
		*/
	class ImeitemIMController : public WdbeMController {

	public:
		ImeitemIMController();
		ImeitemIMController(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

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
		* ImeIMController (full: ImeIWdbeCsxMController)
		*/
	class ImeIMController {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxMControllerIel)
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
		* ImeitemIMModule (full: ImeitemIWdbeCsxMModule)
		*/
	class ImeitemIMModule : public WdbeMModule {

	public:
		ImeitemIMModule(const std::string& hsrefSupRefWdbeMModule = "", const std::string& sref = "");
		ImeitemIMModule(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hsrefSupRefWdbeMModule;

		ImeIMController imeimcontroller;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMModule (full: ImeIWdbeCsxMModule)
		*/
	class ImeIMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxMModuleIel)
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
		* ImeitemIMVectoritem1 (full: ImeitemIWdbeCsxMVectoritem1)
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
		* ImeIMVectoritem1 (full: ImeIWdbeCsxMVectoritem1)
		*/
	class ImeIMVectoritem1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxMVectoritem1Iel)
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
		* ImeitemIMVector1 (full: ImeitemIWdbeCsxMVector1)
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
		* ImeIMVector1 (full: ImeIWdbeCsxMVector1)
		*/
	class ImeIMVector1 {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxMVector1Iel)
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
		* ImeitemIMUnit (full: ImeitemIWdbeCsxMUnit)
		*/
	class ImeitemIMUnit : public WdbeMUnit {

	public:
		ImeitemIMUnit(const std::string& sref = "");
		ImeitemIMUnit(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

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
		* ImeIMUnit (full: ImeIWdbeCsxMUnit)
		*/
	class ImeIMUnit {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeCsxMUnitIel)
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
