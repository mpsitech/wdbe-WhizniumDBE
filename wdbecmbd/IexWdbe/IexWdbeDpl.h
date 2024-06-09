/**
	* \file IexWdbeDpl.h
	* data blocks and readers/writers for import/export complex IexWdbeDpl (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
	*/
// IP header --- ABOVE

#ifndef IEXWDBEDPL_H
#define IEXWDBEDPL_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWdbe.h"
#include "VecWdbeVIop.h"

#define VecVIexWdbeDplIme IexWdbeDpl::VecVIme

#define ImeitemIWdbeDplMRelease IexWdbeDpl::ImeitemIMRelease
#define ImeIWdbeDplMRelease IexWdbeDpl::ImeIMRelease
#define VecWImeIWdbeDplMReleaseIel IexWdbeDpl::ImeIMRelease::VecWIel

#define ImeitemIWdbeDplRMComponentMLibrary IexWdbeDpl::ImeitemIRMComponentMLibrary
#define ImeIWdbeDplRMComponentMLibrary IexWdbeDpl::ImeIRMComponentMLibrary
#define VecWImeIWdbeDplRMComponentMLibraryIel IexWdbeDpl::ImeIRMComponentMLibrary::VecWIel

#define ImeitemIWdbeDplMComponent IexWdbeDpl::ImeitemIMComponent
#define ImeIWdbeDplMComponent IexWdbeDpl::ImeIMComponent
#define VecWImeIWdbeDplMComponentIel IexWdbeDpl::ImeIMComponent::VecWIel

/**
	* IexWdbeDpl
	*/
namespace IexWdbeDpl {
	/**
		* VecVIme (full: VecVIexWdbeDplIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIMCOMPONENT = 1;
		static const Sbecore::uint IMEIMRELEASE = 2;
		static const Sbecore::uint IMEIRMCOMPONENTMLIBRARY = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIMRelease (full: ImeitemIWdbeDplMRelease)
		*/
	class ImeitemIMRelease : public WdbeMRelease {

	public:
		ImeitemIMRelease(const std::string& hsrefRefWdbeMMachine = "", const std::string& sref = "", const std::string& srefsKOption = "", const std::string& Comment = "");
		ImeitemIMRelease(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hsrefRefWdbeMMachine;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMRelease (full: ImeIWdbeDplMRelease)
		*/
	class ImeIMRelease {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDplMReleaseIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint HSREFREFWDBEMMACHINE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint SREFSKOPTION = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMRelease();
		~ImeIMRelease();

	public:
		std::vector<ImeitemIMRelease*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMComponentMLibrary (full: ImeitemIWdbeDplRMComponentMLibrary)
		*/
	class ImeitemIRMComponentMLibrary : public WdbeRMComponentMLibrary {

	public:
		ImeitemIRMComponentMLibrary(const std::string& srefRefWdbeMLibrary = "");
		ImeitemIRMComponentMLibrary(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefRefWdbeMLibrary;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIRMComponentMLibrary (full: ImeIWdbeDplRMComponentMLibrary)
		*/
	class ImeIRMComponentMLibrary {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDplRMComponentMLibraryIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWDBEMLIBRARY = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMComponentMLibrary();
		~ImeIRMComponentMLibrary();

	public:
		std::vector<ImeitemIRMComponentMLibrary*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMComponent (full: ImeitemIWdbeDplMComponent)
		*/
	class ImeitemIMComponent : public WdbeMComponent {

	public:
		ImeitemIMComponent(const Sbecore::uint ixVBasetype = 0, const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMComponent(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;

		ImeIMRelease imeimrelease;
		ImeIRMComponentMLibrary imeirmcomponentmlibrary;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMComponent (full: ImeIWdbeDplMComponent)
		*/
	class ImeIMComponent {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDplMComponentIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMComponent();
		~ImeIMComponent();

	public:
		std::vector<ImeitemIMComponent*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIMComponent& imeimcomponent);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMComponent& imeimcomponent);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMComponent& imeimcomponent);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMComponent& imeimcomponent);

	void writeTxt(std::fstream& outfile, ImeIMComponent& imeimcomponent);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMComponent& imeimcomponent);

	std::map<Sbecore::uint,Sbecore::uint> icsWdbeVIopInsAll();
	Sbecore::uint getIxWdbeVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWdbeVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWdbeVIop);
};

#endif
