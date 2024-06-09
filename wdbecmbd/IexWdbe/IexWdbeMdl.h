/**
	* \file IexWdbeMdl.h
	* data blocks and readers/writers for import/export complex IexWdbeMdl (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef IEXWDBEMDL_H
#define IEXWDBEMDL_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWdbe.h"
#include "VecWdbeVIop.h"

#define VecVIexWdbeMdlIme IexWdbeMdl::VecVIme

#define ImeitemIWdbeMdlAMModulePar IexWdbeMdl::ImeitemIAMModulePar
#define ImeIWdbeMdlAMModulePar IexWdbeMdl::ImeIAMModulePar
#define VecWImeIWdbeMdlAMModuleParIel IexWdbeMdl::ImeIAMModulePar::VecWIel

#define ImeitemIWdbeMdlMController IexWdbeMdl::ImeitemIMController
#define ImeIWdbeMdlMController IexWdbeMdl::ImeIMController
#define VecWImeIWdbeMdlMControllerIel IexWdbeMdl::ImeIMController::VecWIel

#define ImeitemIWdbeMdlMGeneric IexWdbeMdl::ImeitemIMGeneric
#define ImeIWdbeMdlMGeneric IexWdbeMdl::ImeIMGeneric
#define VecWImeIWdbeMdlMGenericIel IexWdbeMdl::ImeIMGeneric::VecWIel

#define ImeitemIWdbeMdlMImbuf IexWdbeMdl::ImeitemIMImbuf
#define ImeIWdbeMdlMImbuf IexWdbeMdl::ImeIMImbuf
#define VecWImeIWdbeMdlMImbufIel IexWdbeMdl::ImeIMImbuf::VecWIel

#define ImeitemIWdbeMdlRMModuleMModule IexWdbeMdl::ImeitemIRMModuleMModule
#define ImeIWdbeMdlRMModuleMModule IexWdbeMdl::ImeIRMModuleMModule
#define VecWImeIWdbeMdlRMModuleMModuleIel IexWdbeMdl::ImeIRMModuleMModule::VecWIel

#define ImeitemIWdbeMdlRMModuleMPeripheral IexWdbeMdl::ImeitemIRMModuleMPeripheral
#define ImeIWdbeMdlRMModuleMPeripheral IexWdbeMdl::ImeIRMModuleMPeripheral
#define VecWImeIWdbeMdlRMModuleMPeripheralIel IexWdbeMdl::ImeIRMModuleMPeripheral::VecWIel

#define ImeitemIWdbeMdlMModule IexWdbeMdl::ImeitemIMModule
#define ImeIWdbeMdlMModule IexWdbeMdl::ImeIMModule
#define VecWImeIWdbeMdlMModuleIel IexWdbeMdl::ImeIMModule::VecWIel

#define ImeitemIWdbeMdlAMPeripheralPar IexWdbeMdl::ImeitemIAMPeripheralPar
#define ImeIWdbeMdlAMPeripheralPar IexWdbeMdl::ImeIAMPeripheralPar
#define VecWImeIWdbeMdlAMPeripheralParIel IexWdbeMdl::ImeIAMPeripheralPar::VecWIel

#define ImeitemIWdbeMdlMPeripheral IexWdbeMdl::ImeitemIMPeripheral
#define ImeIWdbeMdlMPeripheral IexWdbeMdl::ImeIMPeripheral
#define VecWImeIWdbeMdlMPeripheralIel IexWdbeMdl::ImeIMPeripheral::VecWIel

#define ImeitemIWdbeMdlMUnit IexWdbeMdl::ImeitemIMUnit
#define ImeIWdbeMdlMUnit IexWdbeMdl::ImeIMUnit
#define VecWImeIWdbeMdlMUnitIel IexWdbeMdl::ImeIMUnit::VecWIel

/**
	* IexWdbeMdl
	*/
namespace IexWdbeMdl {
	/**
		* VecVIme (full: VecVIexWdbeMdlIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMMODULEPAR = 1;
		static const Sbecore::uint IMEIAMPERIPHERALPAR = 2;
		static const Sbecore::uint IMEIMCONTROLLER = 3;
		static const Sbecore::uint IMEIMGENERIC = 4;
		static const Sbecore::uint IMEIMIMBUF = 5;
		static const Sbecore::uint IMEIMMODULE = 6;
		static const Sbecore::uint IMEIMPERIPHERAL = 7;
		static const Sbecore::uint IMEIMUNIT = 8;
		static const Sbecore::uint IMEIRMMODULEMMODULE = 9;
		static const Sbecore::uint IMEIRMMODULEMPERIPHERAL = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAMModulePar (full: ImeitemIWdbeMdlAMModulePar)
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
		* ImeIAMModulePar (full: ImeIWdbeMdlAMModulePar)
		*/
	class ImeIAMModulePar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeMdlAMModuleParIel)
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
		* ImeitemIMController (full: ImeitemIWdbeMdlMController)
		*/
	class ImeitemIMController : public WdbeMController {

	public:
		ImeitemIMController();
		ImeitemIMController(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIMController (full: ImeIWdbeMdlMController)
		*/
	class ImeIMController {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeMdlMControllerIel)
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
		* ImeitemIMGeneric (full: ImeitemIWdbeMdlMGeneric)
		*/
	class ImeitemIMGeneric : public WdbeMGeneric {

	public:
		ImeitemIMGeneric(const std::string& sref = "", const std::string& Defval = "");
		ImeitemIMGeneric(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIMGeneric (full: ImeIWdbeMdlMGeneric)
		*/
	class ImeIMGeneric {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeMdlMGenericIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint DEFVAL = 2;

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
		* ImeitemIMImbuf (full: ImeitemIWdbeMdlMImbuf)
		*/
	class ImeitemIMImbuf : public WdbeMImbuf {

	public:
		ImeitemIMImbuf(const Sbecore::uint ixVRotype = 0, const Sbecore::usmallint Width = 0, const std::string& Minmax = "", const Sbecore::utinyint Prio = 0);
		ImeitemIMImbuf(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVRotype;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMImbuf (full: ImeIWdbeMdlMImbuf)
		*/
	class ImeIMImbuf {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeMdlMImbufIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVROTYPE = 1;
			static const Sbecore::uint WIDTH = 2;
			static const Sbecore::uint MINMAX = 4;
			static const Sbecore::uint PRIO = 8;

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
		* ImeitemIRMModuleMModule (full: ImeitemIWdbeMdlRMModuleMModule)
		*/
	class ImeitemIRMModuleMModule : public WdbeRMModuleMModule {

	public:
		ImeitemIRMModuleMModule(const std::string& hsrefCorRefWdbeMModule = "", const std::string& srefKFunction = "");
		ImeitemIRMModuleMModule(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hsrefCorRefWdbeMModule;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMModuleMModule (full: ImeIWdbeMdlRMModuleMModule)
		*/
	class ImeIRMModuleMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeMdlRMModuleMModuleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint HSREFCORREFWDBEMMODULE = 1;
			static const Sbecore::uint SREFKFUNCTION = 2;

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
		* ImeitemIRMModuleMPeripheral (full: ImeitemIWdbeMdlRMModuleMPeripheral)
		*/
	class ImeitemIRMModuleMPeripheral : public WdbeRMModuleMPeripheral {

	public:
		ImeitemIRMModuleMPeripheral(const std::string& srefRefWdbeMPeripheral = "");
		ImeitemIRMModuleMPeripheral(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWdbeMPeripheral;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMModuleMPeripheral (full: ImeIWdbeMdlRMModuleMPeripheral)
		*/
	class ImeIRMModuleMPeripheral {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeMdlRMModuleMPeripheralIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWDBEMPERIPHERAL = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMModuleMPeripheral();
		~ImeIRMModuleMPeripheral();

	public:
		std::vector<ImeitemIRMModuleMPeripheral*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMModule (full: ImeitemIWdbeMdlMModule)
		*/
	class ImeitemIMModule : public WdbeMModule {

	public:
		ImeitemIMModule(const Sbecore::uint ixVBasetype = 0, const std::string& hsrefSupRefWdbeMModule = "", const std::string& srefTplRefWdbeMModule = "", const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMModule(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string hsrefSupRefWdbeMModule;
		std::string srefTplRefWdbeMModule;

		ImeIAMModulePar imeiammodulepar;
		ImeIMController imeimcontroller;
		ImeIMGeneric imeimgeneric;
		ImeIMImbuf imeimimbuf;
		ImeIRMModuleMModule imeirmmodulemmodule;
		ImeIRMModuleMPeripheral imeirmmodulemperipheral;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMModule (full: ImeIWdbeMdlMModule)
		*/
	class ImeIMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeMdlMModuleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint HSREFSUPREFWDBEMMODULE = 2;
			static const Sbecore::uint SREFTPLREFWDBEMMODULE = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint COMMENT = 16;

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
		* ImeitemIAMPeripheralPar (full: ImeitemIWdbeMdlAMPeripheralPar)
		*/
	class ImeitemIAMPeripheralPar : public WdbeAMPeripheralPar {

	public:
		ImeitemIAMPeripheralPar(const std::string& x1SrefKKey = "", const std::string& Val = "");
		ImeitemIAMPeripheralPar(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIAMPeripheralPar (full: ImeIWdbeMdlAMPeripheralPar)
		*/
	class ImeIAMPeripheralPar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeMdlAMPeripheralParIel)
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
		ImeIAMPeripheralPar();
		~ImeIAMPeripheralPar();

	public:
		std::vector<ImeitemIAMPeripheralPar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPeripheral (full: ImeitemIWdbeMdlMPeripheral)
		*/
	class ImeitemIMPeripheral : public WdbeMPeripheral {

	public:
		ImeitemIMPeripheral(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMPeripheral(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMPeripheralPar imeiamperipheralpar;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPeripheral (full: ImeIWdbeMdlMPeripheral)
		*/
	class ImeIMPeripheral {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeMdlMPeripheralIel)
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
		* ImeitemIMUnit (full: ImeitemIWdbeMdlMUnit)
		*/
	class ImeitemIMUnit : public WdbeMUnit {

	public:
		ImeitemIMUnit(const Sbecore::uint ixVBasetype = 0, const std::string& srefSilRefWdbeMUnit = "", const std::string& sref = "", const std::string& Title = "", const bool Easy = false, const std::string& srefKToolch = "", const std::string& Comment = "");
		ImeitemIMUnit(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string srefSilRefWdbeMUnit;

		ImeIMModule imeimmodule;
		ImeIMPeripheral imeimperipheral;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUnit (full: ImeIWdbeMdlMUnit)
		*/
	class ImeIMUnit {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeMdlMUnitIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREFSILREFWDBEMUNIT = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint TITLE = 8;
			static const Sbecore::uint EASY = 16;
			static const Sbecore::uint SREFKTOOLCH = 32;
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
