/**
	* \file IexWdbeDal.h
	* data blocks and readers/writers for import/export complex IexWdbeDal (declarations)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#ifndef IEXWDBEDAL_H
#define IEXWDBEDAL_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWdbe.h"
#include "VecWdbeVIop.h"

#define VecVIexWdbeDalIme IexWdbeDal::VecVIme

#define ImeitemIWdbeDalCSegment IexWdbeDal::ImeitemICSegment
#define ImeIWdbeDalCSegment IexWdbeDal::ImeICSegment
#define VecWImeIWdbeDalCSegmentIel IexWdbeDal::ImeICSegment::VecWIel

#define ImeitemIWdbeDalMSegment IexWdbeDal::ImeitemIMSegment
#define ImeIWdbeDalMSegment IexWdbeDal::ImeIMSegment
#define VecWImeIWdbeDalMSegmentIel IexWdbeDal::ImeIMSegment::VecWIel

#define ImeitemIWdbeDalMPipeline IexWdbeDal::ImeitemIMPipeline
#define ImeIWdbeDalMPipeline IexWdbeDal::ImeIMPipeline
#define VecWImeIWdbeDalMPipelineIel IexWdbeDal::ImeIMPipeline::VecWIel

#define ImeitemIWdbeDalMModule IexWdbeDal::ImeitemIMModule
#define ImeIWdbeDalMModule IexWdbeDal::ImeIMModule
#define VecWImeIWdbeDalMModuleIel IexWdbeDal::ImeIMModule::VecWIel

#define ImeitemIWdbeDalMUnit IexWdbeDal::ImeitemIMUnit
#define ImeIWdbeDalMUnit IexWdbeDal::ImeIMUnit
#define VecWImeIWdbeDalMUnitIel IexWdbeDal::ImeIMUnit::VecWIel

/**
	* IexWdbeDal
	*/
namespace IexWdbeDal {
	/**
		* VecVIme (full: VecVIexWdbeDalIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEICSEGMENT = 1;
		static const Sbecore::uint IMEIMMODULE = 2;
		static const Sbecore::uint IMEIMPIPELINE = 3;
		static const Sbecore::uint IMEIMSEGMENT = 4;
		static const Sbecore::uint IMEIMUNIT = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemICSegment (full: ImeitemIWdbeDalCSegment)
		*/
	class ImeitemICSegment {

	public:
		ImeitemICSegment(const Sbecore::ubigint iref = 0);
		ImeitemICSegment(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

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
		* ImeICSegment (full: ImeIWdbeDalCSegment)
		*/
	class ImeICSegment {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDalCSegmentIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREF = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeICSegment();
		~ImeICSegment();

	public:
		std::vector<ImeitemICSegment*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMSegment (full: ImeitemIWdbeDalMSegment)
		*/
	class ImeitemIMSegment : public WdbeMSegment {

	public:
		ImeitemIMSegment(const Sbecore::ubigint irefRefWdbeCSegment = 0, const std::string& hsrefSupRefWdbeMSegment = "", const std::string& sref = "", const std::string& Infmt = "", const std::string& Outfmt = "", const Sbecore::usmallint Latency = 0, const std::string& Comment = "");
		ImeitemIMSegment(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		Sbecore::ubigint irefRefWdbeCSegment;
		std::string hsrefSupRefWdbeMSegment;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMSegment (full: ImeIWdbeDalMSegment)
		*/
	class ImeIMSegment {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDalMSegmentIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint IREFREFWDBECSEGMENT = 1;
			static const Sbecore::uint HSREFSUPREFWDBEMSEGMENT = 2;
			static const Sbecore::uint SREF = 4;
			static const Sbecore::uint INFMT = 8;
			static const Sbecore::uint OUTFMT = 16;
			static const Sbecore::uint LATENCY = 32;
			static const Sbecore::uint COMMENT = 64;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMSegment();
		~ImeIMSegment();

	public:
		std::vector<ImeitemIMSegment*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPipeline (full: ImeitemIWdbeDalMPipeline)
		*/
	class ImeitemIMPipeline : public WdbeMPipeline {

	public:
		ImeitemIMPipeline(const std::string& sref = "", const std::string& clkSrefWdbeMSignal = "", const std::string& clgSrefWdbeMSignal = "", const std::string& asrSrefWdbeMSignal = "", const Sbecore::usmallint Depth = 0, const std::string& Comment = "");
		ImeitemIMPipeline(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeICSegment imeicsegment;
		ImeIMSegment imeimsegment;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPipeline (full: ImeIWdbeDalMPipeline)
		*/
	class ImeIMPipeline {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDalMPipelineIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint CLKSREFWDBEMSIGNAL = 2;
			static const Sbecore::uint CLGSREFWDBEMSIGNAL = 4;
			static const Sbecore::uint ASRSREFWDBEMSIGNAL = 8;
			static const Sbecore::uint DEPTH = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPipeline();
		~ImeIMPipeline();

	public:
		std::vector<ImeitemIMPipeline*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMModule (full: ImeitemIWdbeDalMModule)
		*/
	class ImeitemIMModule : public WdbeMModule {

	public:
		ImeitemIMModule(const std::string& hsrefSupRefWdbeMModule = "", const std::string& sref = "");
		ImeitemIMModule(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string hsrefSupRefWdbeMModule;

		ImeIMPipeline imeimpipeline;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMModule (full: ImeIWdbeDalMModule)
		*/
	class ImeIMModule {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDalMModuleIel)
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
		* ImeitemIMUnit (full: ImeitemIWdbeDalMUnit)
		*/
	class ImeitemIMUnit : public WdbeMUnit {

	public:
		ImeitemIMUnit(const std::string& sref = "");
		ImeitemIMUnit(DbsWdbe* dbswdbe, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIMModule imeimmodule;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUnit (full: ImeIWdbeDalMUnit)
		*/
	class ImeIMUnit {

	public:
		/**
			* VecWIel (full: VecWImeIWdbeDalMUnitIel)
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
