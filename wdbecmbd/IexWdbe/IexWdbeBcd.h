/**
	* \file IexWdbeBcd.h
	* data blocks and readers/writers for import/export complex IexWdbeBcd (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef IEXWDBEBCD_H
#define IEXWDBEBCD_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWdbe.h"
#include "VecWdbeVIop.h"

#define VecVIexWdbeBcdIme IexWdbeBcd::VecVIme

#define ImeitemIWdbeBcdAMModulePar IexWdbeBcd::ImeitemIAMModulePar
#define ImeIWdbeBcdAMModulePar IexWdbeBcd::ImeIAMModulePar
#define VecWImeIWdbeBcdAMModuleParIel IexWdbeBcd::ImeIAMModulePar::VecWIel

#define ImeitemIWdbeBcdJAVKeylistKey IexWdbeBcd::ImeitemIJAVKeylistKey
#define ImeIWdbeBcdJAVKeylistKey IexWdbeBcd::ImeIJAVKeylistKey
#define VecWImeIWdbeBcdJAVKeylistKeyIel IexWdbeBcd::ImeIJAVKeylistKey::VecWIel

#define ImeitemIWdbeBcdAVKeylistKey IexWdbeBcd::ImeitemIAVKeylistKey
#define ImeIWdbeBcdAVKeylistKey IexWdbeBcd::ImeIAVKeylistKey
#define VecWImeIWdbeBcdAVKeylistKeyIel IexWdbeBcd::ImeIAVKeylistKey::VecWIel

#define ImeitemIWdbeBcdMModule IexWdbeBcd::ImeitemIMModule
#define ImeIWdbeBcdMModule IexWdbeBcd::ImeIMModule
#define VecWImeIWdbeBcdMModuleIel IexWdbeBcd::ImeIMModule::VecWIel

/**
	* IexWdbeBcd
	*/
namespace IexWdbeBcd {
	/**
		* VecVIme (full: VecVIexWdbeBcdIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMMODULEPAR = 1;
		static const Sbecore::uint IMEIAVKEYLISTKEY = 2;
		static const Sbecore::uint IMEIJAVKEYLISTKEY = 3;
		static const Sbecore::uint IMEIMMODULE = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAMModulePar (full: ImeitemIWdbeBcdAMModulePar)
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
		* ImeIAMModulePar (full: ImeIWdbeBcdAMModulePar)
		*/
	class ImeIAMModulePar {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBcdAMModuleParIel)
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
		* ImeitemIJAVKeylistKey (full: ImeitemIWdbeBcdJAVKeylistKey)
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
		* ImeIJAVKeylistKey (full: ImeIWdbeBcdJAVKeylistKey)
		*/
	class ImeIJAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBcdJAVKeylistKeyIel)
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
		* ImeitemIAVKeylistKey (full: ImeitemIWdbeBcdAVKeylistKey)
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
		* ImeIAVKeylistKey (full: ImeIWdbeBcdAVKeylistKey)
		*/
	class ImeIAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBcdAVKeylistKeyIel)
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
		* ImeitemIMModule (full: ImeitemIWdbeBcdMModule)
		*/
	class ImeitemIMModule : public WdbeMModule {

	public:
		ImeitemIMModule(const Sbecore::uint ixVBasetype = 0, const std::string& hsrefSupRefWdbeMModule = "", const std::string& srefTplRefWdbeMModule = "", const std::string& sref = "", const std::string& Srefrule = "", const std::string& Comment = "");
		ImeitemIMModule(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string hsrefSupRefWdbeMModule;
		std::string srefTplRefWdbeMModule;

		ImeIAMModulePar imeiammodulepar;
		ImeIAVKeylistKey imeiavkeylistkey;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMModule (full: ImeIWdbeBcdMModule)
		*/
	class ImeIMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeBcdMModuleIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint HSREFSUPREFWDBEMMODULE = 2;
			static const Sbecore::uint SREFTPLREFWDBEMMODULE = 4;
			static const Sbecore::uint SREF = 8;
			static const Sbecore::uint SREFRULE = 16;
			static const Sbecore::uint COMMENT = 32;

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

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIMModule& imeimmodule);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMModule& imeimmodule);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMModule& imeimmodule);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMModule& imeimmodule);

	void writeTxt(std::fstream& outfile, ImeIMModule& imeimmodule);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMModule& imeimmodule);

	std::map<Sbecore::uint,Sbecore::uint> icsWdbeVIopInsAll();
	Sbecore::uint getIxWdbeVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWdbeVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWdbeVIop);
};

#endif

