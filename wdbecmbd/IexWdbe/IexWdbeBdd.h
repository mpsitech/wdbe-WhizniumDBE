/**
	* \file IexWdbeBdd.h
	* data blocks and readers/writers for import/export complex IexWdbeBdd (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef IEXWDBEBDD_H
#define IEXWDBEBDD_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWdbe.h"
#include "VecWdbeVIop.h"

#define VecVIexWdbeBddIme IexWdbeBdd::VecVIme

#define ImeitemIWdbeBddMTarget IexWdbeBdd::ImeitemIMTarget
#define ImeIWdbeBddMTarget IexWdbeBdd::ImeIMTarget
#define VecWImeIWdbeBddMTargetIel IexWdbeBdd::ImeIMTarget::VecWIel

#define ImeitemIWdbeBddMSystem IexWdbeBdd::ImeitemIMSystem
#define ImeIWdbeBddMSystem IexWdbeBdd::ImeIMSystem
#define VecWImeIWdbeBddMSystemIel IexWdbeBdd::ImeIMSystem::VecWIel

#define ImeitemIWdbeBddAMModulePar IexWdbeBdd::ImeitemIAMModulePar
#define ImeIWdbeBddAMModulePar IexWdbeBdd::ImeIAMModulePar
#define VecWImeIWdbeBddAMModuleParIel IexWdbeBdd::ImeIAMModulePar::VecWIel

#define ImeitemIWdbeBddMController IexWdbeBdd::ImeitemIMController
#define ImeIWdbeBddMController IexWdbeBdd::ImeIMController
#define VecWImeIWdbeBddMControllerIel IexWdbeBdd::ImeIMController::VecWIel

#define ImeitemIWdbeBddMImbuf IexWdbeBdd::ImeitemIMImbuf
#define ImeIWdbeBddMImbuf IexWdbeBdd::ImeIMImbuf
#define VecWImeIWdbeBddMImbufIel IexWdbeBdd::ImeIMImbuf::VecWIel

#define ImeitemIWdbeBddMModule IexWdbeBdd::ImeitemIMModule
#define ImeIWdbeBddMModule IexWdbeBdd::ImeIMModule
#define VecWImeIWdbeBddMModuleIel IexWdbeBdd::ImeIMModule::VecWIel

#define ImeitemIWdbeBddAMPeripheralPar IexWdbeBdd::ImeitemIAMPeripheralPar
#define ImeIWdbeBddAMPeripheralPar IexWdbeBdd::ImeIAMPeripheralPar
#define VecWImeIWdbeBddAMPeripheralParIel IexWdbeBdd::ImeIAMPeripheralPar::VecWIel

#define ImeitemIWdbeBddMPeripheral IexWdbeBdd::ImeitemIMPeripheral
#define ImeIWdbeBddMPeripheral IexWdbeBdd::ImeIMPeripheral
#define VecWImeIWdbeBddMPeripheralIel IexWdbeBdd::ImeIMPeripheral::VecWIel

#define ImeitemIWdbeBddMUnit IexWdbeBdd::ImeitemIMUnit
#define ImeIWdbeBddMUnit IexWdbeBdd::ImeIMUnit
#define VecWImeIWdbeBddMUnitIel IexWdbeBdd::ImeIMUnit::VecWIel

/**
	* IexWdbeBdd
	*/
namespace IexWdbeBdd {
	/**
		* VecVIme (full: VecVIexWdbeBddIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMMODULEPAR = 1;
		static const Sbecore::uint IMEIAMPERIPHERALPAR = 2;
		static const Sbecore::uint IMEIMCONTROLLER = 3;
		static const Sbecore::uint IMEIMIMBUF = 4;
		static const Sbecore::uint IMEIMMODULE = 5;
		static const Sbecore::uint IMEIMPERIPHERAL = 6;
		static const Sbecore::uint IMEIMSYSTEM = 7;
		static const Sbecore::uint IMEIMTARGET = 8;
		static const Sbecore::uint IMEIMUNIT = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIMTarget (full: ImeitemIWdbeBddMTarget)
		*/
	class ImeitemIMTarget : public WdbeMTarget {

	public:
		ImeitemIMTarget(const std::string& srefRefWdbeMUnit = "", const std::string& sref = "", const std::string& rteSrefsWdbeMModule = "", const std::string& Comment = "");
		ImeitemIMTarget(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWdbeMUnit;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMTarget (full: ImeIWdbeBddMTarget)
		*/
	class ImeIMTarget {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBddMTargetIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWDBEMUNIT = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint RTESREFSWDBEMMODULE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMTarget();
		~ImeIMTarget();

	public:
		std::vector<ImeitemIMTarget*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSystem (full: ImeitemIWdbeBddMSystem)
		*/
	class ImeitemIMSystem : public WdbeMSystem {

	public:
		ImeitemIMSystem(const std::string& srefRefWdbeMUnit = "", const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMSystem(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWdbeMUnit;

		ImeIMTarget imeimtarget;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSystem (full: ImeIWdbeBddMSystem)
		*/
	class ImeIMSystem {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBddMSystemIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWDBEMUNIT = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSystem();
		~ImeIMSystem();

	public:
		std::vector<ImeitemIMSystem*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMModulePar (full: ImeitemIWdbeBddAMModulePar)
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
		* ImeIAMModulePar (full: ImeIWdbeBddAMModulePar)
		*/
	class ImeIAMModulePar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBddAMModuleParIel)
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
		* ImeitemIMController (full: ImeitemIWdbeBddMController)
		*/
	class ImeitemIMController : public WdbeMController {

	public:
		ImeitemIMController(const std::string& srefFwdRefWdbeMUnit = "");
		ImeitemIMController(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefFwdRefWdbeMUnit;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMController (full: ImeIWdbeBddMController)
		*/
	class ImeIMController {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBddMControllerIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFFWDREFWDBEMUNIT = 1;

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
		* ImeitemIMImbuf (full: ImeitemIWdbeBddMImbuf)
		*/
	class ImeitemIMImbuf : public WdbeMImbuf {

	public:
		ImeitemIMImbuf(const std::string& hsrefCorRefWdbeMModule = "", const std::string& sref = "", const Sbecore::uint ixVDir = 0);
		ImeitemIMImbuf(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hsrefCorRefWdbeMModule;
		std::string srefIxVDir;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMImbuf (full: ImeIWdbeBddMImbuf)
		*/
	class ImeIMImbuf {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBddMImbufIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint HSREFCORREFWDBEMMODULE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFIXVDIR = 4;

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
		* ImeitemIMModule (full: ImeitemIWdbeBddMModule)
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
		ImeIMImbuf imeimimbuf;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMModule (full: ImeIWdbeBddMModule)
		*/
	class ImeIMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBddMModuleIel)
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
		* ImeitemIAMPeripheralPar (full: ImeitemIWdbeBddAMPeripheralPar)
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
		* ImeIAMPeripheralPar (full: ImeIWdbeBddAMPeripheralPar)
		*/
	class ImeIAMPeripheralPar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBddAMPeripheralParIel)
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
		* ImeitemIMPeripheral (full: ImeitemIWdbeBddMPeripheral)
		*/
	class ImeitemIMPeripheral : public WdbeMPeripheral {

	public:
		ImeitemIMPeripheral(const std::string& hsrefRefWdbeMModule = "", const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMPeripheral(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hsrefRefWdbeMModule;

		ImeIAMPeripheralPar imeiamperipheralpar;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPeripheral (full: ImeIWdbeBddMPeripheral)
		*/
	class ImeIMPeripheral {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBddMPeripheralIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint HSREFREFWDBEMMODULE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint COMMENT = 4;

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
		* ImeitemIMUnit (full: ImeitemIWdbeBddMUnit)
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
		* ImeIMUnit (full: ImeIWdbeBddMUnit)
		*/
	class ImeIMUnit {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBddMUnitIel)
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

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIMSystem& imeimsystem, ImeIMUnit& imeimunit);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMSystem& imeimsystem, ImeIMUnit& imeimunit);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMSystem& imeimsystem, ImeIMUnit& imeimunit);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMSystem& imeimsystem, ImeIMUnit& imeimunit);

	void writeTxt(std::fstream& outfile, ImeIMSystem& imeimsystem, ImeIMUnit& imeimunit);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMSystem& imeimsystem, ImeIMUnit& imeimunit);

	std::map<Sbecore::uint,Sbecore::uint> icsWdbeVIopInsAll();
	Sbecore::uint getIxWdbeVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWdbeVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWdbeVIop);
};

#endif

