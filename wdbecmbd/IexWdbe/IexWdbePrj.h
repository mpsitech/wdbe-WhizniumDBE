/**
	* \file IexWdbePrj.h
	* data blocks and readers/writers for import/export complex IexWdbePrj (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifndef IEXWDBEPRJ_H
#define IEXWDBEPRJ_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWdbe.h"
#include "VecWdbeVIop.h"

#define VecVIexWdbePrjIme IexWdbePrj::VecVIme

#define ImeitemIWdbePrjJMVersionState IexWdbePrj::ImeitemIJMVersionState
#define ImeIWdbePrjJMVersionState IexWdbePrj::ImeIJMVersionState
#define VecWImeIWdbePrjJMVersionStateIel IexWdbePrj::ImeIJMVersionState::VecWIel

#define ImeitemIWdbePrjMRelease IexWdbePrj::ImeitemIMRelease
#define ImeIWdbePrjMRelease IexWdbePrj::ImeIMRelease
#define VecWImeIWdbePrjMReleaseIel IexWdbePrj::ImeIMRelease::VecWIel

#define ImeitemIWdbePrjRMLibraryMVersion IexWdbePrj::ImeitemIRMLibraryMVersion
#define ImeIWdbePrjRMLibraryMVersion IexWdbePrj::ImeIRMLibraryMVersion
#define VecWImeIWdbePrjRMLibraryMVersionIel IexWdbePrj::ImeIRMLibraryMVersion::VecWIel

#define ImeitemIWdbePrjMVersion IexWdbePrj::ImeitemIMVersion
#define ImeIWdbePrjMVersion IexWdbePrj::ImeIMVersion
#define VecWImeIWdbePrjMVersionIel IexWdbePrj::ImeIMVersion::VecWIel

#define ImeitemIWdbePrjRMPersonMProject IexWdbePrj::ImeitemIRMPersonMProject
#define ImeIWdbePrjRMPersonMProject IexWdbePrj::ImeIRMPersonMProject
#define VecWImeIWdbePrjRMPersonMProjectIel IexWdbePrj::ImeIRMPersonMProject::VecWIel

#define ImeitemIWdbePrjMProject IexWdbePrj::ImeitemIMProject
#define ImeIWdbePrjMProject IexWdbePrj::ImeIMProject
#define VecWImeIWdbePrjMProjectIel IexWdbePrj::ImeIMProject::VecWIel

/**
	* IexWdbePrj
	*/
namespace IexWdbePrj {
	/**
		* VecVIme (full: VecVIexWdbePrjIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIJMVERSIONSTATE = 1;
		static const Sbecore::uint IMEIMPROJECT = 2;
		static const Sbecore::uint IMEIMRELEASE = 3;
		static const Sbecore::uint IMEIMVERSION = 4;
		static const Sbecore::uint IMEIRMLIBRARYMVERSION = 5;
		static const Sbecore::uint IMEIRMPERSONMPROJECT = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIJMVersionState (full: ImeitemIWdbePrjJMVersionState)
		*/
	class ImeitemIJMVersionState : public WdbeJMVersionState {

	public:
		ImeitemIJMVersionState(const Sbecore::uint ixVState = 0);
		ImeitemIJMVersionState(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIJMVersionState (full: ImeIWdbePrjJMVersionState)
		*/
	class ImeIJMVersionState {

	public:
		/**
			* VecWIel (full: VecWImeIWdbePrjJMVersionStateIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSTATE = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMVersionState();
		~ImeIJMVersionState();

	public:
		std::vector<ImeitemIJMVersionState*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMRelease (full: ImeitemIWdbePrjMRelease)
		*/
	class ImeitemIMRelease : public WdbeMRelease {

	public:
		ImeitemIMRelease(const Sbecore::uint ixVBasetype = 0, const std::string& hsrefRefWdbeMMachine = "", const std::string& sref = "", const std::string& srefsKOption = "", const std::string& Comment = "");
		ImeitemIMRelease(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVBasetype;
		std::string hsrefRefWdbeMMachine;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMRelease (full: ImeIWdbePrjMRelease)
		*/
	class ImeIMRelease {

	public:
		/**
			* VecWIel (full: VecWImeIWdbePrjMReleaseIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVBASETYPE = 1;
			static const Sbecore::uint HSREFREFWDBEMMACHINE = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint SREFSKOPTION = 8;
			static const Sbecore::uint COMMENT = 16;

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
		* ImeitemIRMLibraryMVersion (full: ImeitemIWdbePrjRMLibraryMVersion)
		*/
	class ImeitemIRMLibraryMVersion : public WdbeRMLibraryMVersion {

	public:
		ImeitemIRMLibraryMVersion(const std::string& srefRefWdbeMLibrary = "");
		ImeitemIRMLibraryMVersion(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIRMLibraryMVersion (full: ImeIWdbePrjRMLibraryMVersion)
		*/
	class ImeIRMLibraryMVersion {

	public:
		/**
			* VecWIel (full: VecWImeIWdbePrjRMLibraryMVersionIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFREFWDBEMLIBRARY = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIRMLibraryMVersion();
		~ImeIRMLibraryMVersion();

	public:
		std::vector<ImeitemIRMLibraryMVersion*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMVersion (full: ImeitemIWdbePrjMVersion)
		*/
	class ImeitemIMVersion : public WdbeMVersion {

	public:
		ImeitemIMVersion(const Sbecore::usmallint Major = 0, const Sbecore::usmallint Minor = 0, const Sbecore::usmallint Sub = 0, const Sbecore::uint ixVState = 0, const std::string& About = "", const std::string& Comment = "");
		ImeitemIMVersion(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;

		ImeIJMVersionState imeijmversionstate;
		ImeIMRelease imeimrelease;
		ImeIRMLibraryMVersion imeirmlibrarymversion;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMVersion (full: ImeIWdbePrjMVersion)
		*/
	class ImeIMVersion {

	public:
		/**
			* VecWIel (full: VecWImeIWdbePrjMVersionIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint MAJOR = 1;
			static const Sbecore::uint MINOR = 2;
			static const Sbecore::uint SUB = 4;
			static const Sbecore::uint SREFIXVSTATE = 8;
			static const Sbecore::uint ABOUT = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMVersion();
		~ImeIMVersion();

	public:
		std::vector<ImeitemIMVersion*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIRMPersonMProject (full: ImeitemIWdbePrjRMPersonMProject)
		*/
	class ImeitemIRMPersonMProject : public WdbeRMPersonMProject {

	public:
		ImeitemIRMPersonMProject(const std::string& hintRefWdbeMPerson = "", const std::string& srefKFunction = "");
		ImeitemIRMPersonMProject(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeIRMPersonMProject (full: ImeIWdbePrjRMPersonMProject)
		*/
	class ImeIRMPersonMProject {

	public:
		/**
			* VecWIel (full: VecWImeIWdbePrjRMPersonMProjectIel)
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
		ImeIRMPersonMProject();
		~ImeIRMPersonMProject();

	public:
		std::vector<ImeitemIRMPersonMProject*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMProject (full: ImeitemIWdbePrjMProject)
		*/
	class ImeitemIMProject : public WdbeMProject {

	public:
		ImeitemIMProject(const std::string& Short = "", const std::string& Title = "", const bool Easy = false, const std::string& Giturl = "", const std::string& Comment = "");
		ImeitemIMProject(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIMVersion imeimversion;
		ImeIRMPersonMProject imeirmpersonmproject;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMProject (full: ImeIWdbePrjMProject)
		*/
	class ImeIMProject {

	public:
		/**
			* VecWIel (full: VecWImeIWdbePrjMProjectIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SHORT = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint EASY = 4;
			static const Sbecore::uint GITURL = 8;
			static const Sbecore::uint COMMENT = 16;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMProject();
		~ImeIMProject();

	public:
		std::vector<ImeitemIMProject*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, const std::string& rectpath, ImeIMProject& imeimproject);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIMProject& imeimproject);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIMProject& imeimproject);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIMProject& imeimproject);

	void writeTxt(std::fstream& outfile, ImeIMProject& imeimproject);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIMProject& imeimproject);

	std::map<Sbecore::uint,Sbecore::uint> icsWdbeVIopInsAll();
	Sbecore::uint getIxWdbeVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWdbeVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWdbeVIop);
};

#endif



