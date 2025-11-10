/**
	* \file PnlWdbePrfDaemon.h
	* API code for job PnlWdbePrfDaemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

#ifndef PNLWDBEPRFDAEMON_H
#define PNLWDBEPRFDAEMON_H

#include "ApiWdbe_blks.h"

#define VecVWdbePrfDaemonDo PnlWdbePrfDaemon::VecVDo

#define ContIacWdbePrfDaemon PnlWdbePrfDaemon::ContIac
#define StatShrWdbePrfDaemon PnlWdbePrfDaemon::StatShr
#define TagWdbePrfDaemon PnlWdbePrfDaemon::Tag

#define DpchAppWdbePrfDaemonData PnlWdbePrfDaemon::DpchAppData
#define DpchAppWdbePrfDaemonDo PnlWdbePrfDaemon::DpchAppDo
#define DpchEngWdbePrfDaemonData PnlWdbePrfDaemon::DpchEngData

/**
	* PnlWdbePrfDaemon
	*/
namespace PnlWdbePrfDaemon {
	/**
		* VecVDo (full: VecVWdbePrfDaemonDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWdbePrfDaemon)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXF2 = 1;
		static const Sbecore::uint CHK3 = 2;
		static const Sbecore::uint TXF4 = 3;
		static const Sbecore::uint TXF5 = 4;
		static const Sbecore::uint TXF6 = 5;
		static const Sbecore::uint TXF102 = 6;
		static const Sbecore::uint CHK103 = 7;
		static const Sbecore::uint TXF104 = 8;
		static const Sbecore::uint TXF202 = 9;
		static const Sbecore::uint TXF203 = 10;
		static const Sbecore::uint CHK204 = 11;
		static const Sbecore::uint TXF302 = 12;
		static const Sbecore::uint TXF303 = 13;
		static const Sbecore::uint CHK304 = 14;
		static const Sbecore::uint NUMFPUP402 = 15;
		static const Sbecore::uint TXF403 = 16;
		static const Sbecore::uint TXF404 = 17;
		static const Sbecore::uint TXF405 = 18;
		static const Sbecore::uint TXF406 = 19;
		static const Sbecore::uint TXF407 = 20;
		static const Sbecore::uint TXF408 = 21;
		static const Sbecore::uint TXF502 = 22;
		static const Sbecore::uint TXF503 = 23;
		static const Sbecore::uint TXF504 = 24;
		static const Sbecore::uint TXF505 = 25;
		static const Sbecore::uint TXF506 = 26;
		static const Sbecore::uint TXF507 = 27;
		static const Sbecore::uint TXF602 = 28;
		static const Sbecore::uint TXF603 = 29;
		static const Sbecore::uint TXF702 = 30;
		static const Sbecore::uint TXF703 = 31;
		static const Sbecore::uint TXF704 = 32;
		static const Sbecore::uint TXF705 = 33;
		static const Sbecore::uint NUMFPUP706 = 34;
		static const Sbecore::uint TXF707 = 35;
		static const Sbecore::uint TXF708 = 36;
		static const Sbecore::uint TXF709 = 37;
		static const Sbecore::uint TXF710 = 38;

	public:
		ContIac(const std::string& Txf2 = "", const bool Chk3 = false, const std::string& Txf4 = "", const std::string& Txf5 = "", const std::string& Txf6 = "", const std::string& Txf102 = "", const bool Chk103 = false, const std::string& Txf104 = "", const std::string& Txf202 = "", const std::string& Txf203 = "", const bool Chk204 = false, const std::string& Txf302 = "", const std::string& Txf303 = "", const bool Chk304 = false, const Sbecore::uint numFPup402 = 1, const std::string& Txf403 = "", const std::string& Txf404 = "", const std::string& Txf405 = "", const std::string& Txf406 = "", const std::string& Txf407 = "", const std::string& Txf408 = "", const std::string& Txf502 = "", const std::string& Txf503 = "", const std::string& Txf504 = "", const std::string& Txf505 = "", const std::string& Txf506 = "", const std::string& Txf507 = "", const std::string& Txf602 = "", const std::string& Txf603 = "", const std::string& Txf702 = "", const std::string& Txf703 = "", const std::string& Txf704 = "", const std::string& Txf705 = "", const Sbecore::uint numFPup706 = 1, const std::string& Txf707 = "", const std::string& Txf708 = "", const std::string& Txf709 = "", const std::string& Txf710 = "");

	public:
		std::string Txf2;
		bool Chk3;
		std::string Txf4;
		std::string Txf5;
		std::string Txf6;
		std::string Txf102;
		bool Chk103;
		std::string Txf104;
		std::string Txf202;
		std::string Txf203;
		bool Chk204;
		std::string Txf302;
		std::string Txf303;
		bool Chk304;
		Sbecore::uint numFPup402;
		std::string Txf403;
		std::string Txf404;
		std::string Txf405;
		std::string Txf406;
		std::string Txf407;
		std::string Txf408;
		std::string Txf502;
		std::string Txf503;
		std::string Txf504;
		std::string Txf505;
		std::string Txf506;
		std::string Txf507;
		std::string Txf602;
		std::string Txf603;
		std::string Txf702;
		std::string Txf703;
		std::string Txf704;
		std::string Txf705;
		Sbecore::uint numFPup706;
		std::string Txf707;
		std::string Txf708;
		std::string Txf709;
		std::string Txf710;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatShr (full: StatShrWdbePrfDaemon)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWDBEVEXPSTATE = 1;
		static const Sbecore::uint TXF2CLEAN = 2;
		static const Sbecore::uint CHK3CLEAN = 3;
		static const Sbecore::uint TXF4CLEAN = 4;
		static const Sbecore::uint TXF5CLEAN = 5;
		static const Sbecore::uint TXF6CLEAN = 6;
		static const Sbecore::uint TXF102CLEAN = 7;
		static const Sbecore::uint CHK103CLEAN = 8;
		static const Sbecore::uint TXF104CLEAN = 9;
		static const Sbecore::uint SEP2AVAIL = 10;
		static const Sbecore::uint HDG201AVAIL = 11;
		static const Sbecore::uint TXF202AVAIL = 12;
		static const Sbecore::uint TXF202CLEAN = 13;
		static const Sbecore::uint TXF203AVAIL = 14;
		static const Sbecore::uint TXF203CLEAN = 15;
		static const Sbecore::uint CHK204AVAIL = 16;
		static const Sbecore::uint CHK204CLEAN = 17;
		static const Sbecore::uint SEP3AVAIL = 18;
		static const Sbecore::uint HDG301AVAIL = 19;
		static const Sbecore::uint TXF302AVAIL = 20;
		static const Sbecore::uint TXF302CLEAN = 21;
		static const Sbecore::uint TXF303AVAIL = 22;
		static const Sbecore::uint TXF303CLEAN = 23;
		static const Sbecore::uint CHK304AVAIL = 24;
		static const Sbecore::uint CHK304CLEAN = 25;
		static const Sbecore::uint PUP402CLEAN = 26;
		static const Sbecore::uint TXF403CLEAN = 27;
		static const Sbecore::uint TXF404CLEAN = 28;
		static const Sbecore::uint TXF405CLEAN = 29;
		static const Sbecore::uint TXF406CLEAN = 30;
		static const Sbecore::uint TXF407CLEAN = 31;
		static const Sbecore::uint TXF408CLEAN = 32;
		static const Sbecore::uint TXF502CLEAN = 33;
		static const Sbecore::uint TXF503CLEAN = 34;
		static const Sbecore::uint TXF504CLEAN = 35;
		static const Sbecore::uint TXF505CLEAN = 36;
		static const Sbecore::uint TXF506CLEAN = 37;
		static const Sbecore::uint TXF507CLEAN = 38;
		static const Sbecore::uint TXF602CLEAN = 39;
		static const Sbecore::uint TXF603CLEAN = 40;
		static const Sbecore::uint TXF702CLEAN = 41;
		static const Sbecore::uint TXF703CLEAN = 42;
		static const Sbecore::uint TXF704CLEAN = 43;
		static const Sbecore::uint TXF705CLEAN = 44;
		static const Sbecore::uint PUP706CLEAN = 45;
		static const Sbecore::uint TXF707CLEAN = 46;
		static const Sbecore::uint TXF708CLEAN = 47;
		static const Sbecore::uint TXF709CLEAN = 48;
		static const Sbecore::uint TXF710CLEAN = 49;

	public:
		StatShr(const Sbecore::uint ixWdbeVExpstate = VecWdbeVExpstate::MIND, const bool Txf2Clean = false, const bool Chk3Clean = false, const bool Txf4Clean = false, const bool Txf5Clean = false, const bool Txf6Clean = false, const bool Txf102Clean = false, const bool Chk103Clean = false, const bool Txf104Clean = false, const bool Sep2Avail = true, const bool Hdg201Avail = true, const bool Txf202Avail = true, const bool Txf202Clean = false, const bool Txf203Avail = true, const bool Txf203Clean = false, const bool Chk204Avail = true, const bool Chk204Clean = false, const bool Sep3Avail = true, const bool Hdg301Avail = true, const bool Txf302Avail = true, const bool Txf302Clean = false, const bool Txf303Avail = true, const bool Txf303Clean = false, const bool Chk304Avail = true, const bool Chk304Clean = false, const bool Pup402Clean = false, const bool Txf403Clean = false, const bool Txf404Clean = false, const bool Txf405Clean = false, const bool Txf406Clean = false, const bool Txf407Clean = false, const bool Txf408Clean = false, const bool Txf502Clean = false, const bool Txf503Clean = false, const bool Txf504Clean = false, const bool Txf505Clean = false, const bool Txf506Clean = false, const bool Txf507Clean = false, const bool Txf602Clean = false, const bool Txf603Clean = false, const bool Txf702Clean = false, const bool Txf703Clean = false, const bool Txf704Clean = false, const bool Txf705Clean = false, const bool Pup706Clean = false, const bool Txf707Clean = false, const bool Txf708Clean = false, const bool Txf709Clean = false, const bool Txf710Clean = false);

	public:
		Sbecore::uint ixWdbeVExpstate;
		bool Txf2Clean;
		bool Chk3Clean;
		bool Txf4Clean;
		bool Txf5Clean;
		bool Txf6Clean;
		bool Txf102Clean;
		bool Chk103Clean;
		bool Txf104Clean;
		bool Sep2Avail;
		bool Hdg201Avail;
		bool Txf202Avail;
		bool Txf202Clean;
		bool Txf203Avail;
		bool Txf203Clean;
		bool Chk204Avail;
		bool Chk204Clean;
		bool Sep3Avail;
		bool Hdg301Avail;
		bool Txf302Avail;
		bool Txf302Clean;
		bool Txf303Avail;
		bool Txf303Clean;
		bool Chk304Avail;
		bool Chk304Clean;
		bool Pup402Clean;
		bool Txf403Clean;
		bool Txf404Clean;
		bool Txf405Clean;
		bool Txf406Clean;
		bool Txf407Clean;
		bool Txf408Clean;
		bool Txf502Clean;
		bool Txf503Clean;
		bool Txf504Clean;
		bool Txf505Clean;
		bool Txf506Clean;
		bool Txf507Clean;
		bool Txf602Clean;
		bool Txf603Clean;
		bool Txf702Clean;
		bool Txf703Clean;
		bool Txf704Clean;
		bool Txf705Clean;
		bool Pup706Clean;
		bool Txf707Clean;
		bool Txf708Clean;
		bool Txf709Clean;
		bool Txf710Clean;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWdbePrfDaemon)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint HDG1 = 2;
		static const Sbecore::uint CPT2 = 3;
		static const Sbecore::uint CPT3 = 4;
		static const Sbecore::uint CPT4 = 5;
		static const Sbecore::uint CPT5 = 6;
		static const Sbecore::uint CPT6 = 7;
		static const Sbecore::uint HDG101 = 8;
		static const Sbecore::uint CPT102 = 9;
		static const Sbecore::uint CPT103 = 10;
		static const Sbecore::uint CPT104 = 11;
		static const Sbecore::uint HDG201 = 12;
		static const Sbecore::uint CPT202 = 13;
		static const Sbecore::uint CPT203 = 14;
		static const Sbecore::uint CPT204 = 15;
		static const Sbecore::uint HDG301 = 16;
		static const Sbecore::uint CPT302 = 17;
		static const Sbecore::uint CPT303 = 18;
		static const Sbecore::uint CPT304 = 19;
		static const Sbecore::uint HDG401 = 20;
		static const Sbecore::uint CPT402 = 21;
		static const Sbecore::uint CPT403 = 22;
		static const Sbecore::uint CPT404 = 23;
		static const Sbecore::uint CPT405 = 24;
		static const Sbecore::uint CPT406 = 25;
		static const Sbecore::uint CPT407 = 26;
		static const Sbecore::uint CPT408 = 27;
		static const Sbecore::uint HDG501 = 28;
		static const Sbecore::uint CPT502 = 29;
		static const Sbecore::uint CPT503 = 30;
		static const Sbecore::uint CPT504 = 31;
		static const Sbecore::uint CPT505 = 32;
		static const Sbecore::uint CPT506 = 33;
		static const Sbecore::uint CPT507 = 34;
		static const Sbecore::uint HDG601 = 35;
		static const Sbecore::uint CPT602 = 36;
		static const Sbecore::uint CPT603 = 37;
		static const Sbecore::uint HDG701 = 38;
		static const Sbecore::uint CPT702 = 39;
		static const Sbecore::uint CPT703 = 40;
		static const Sbecore::uint CPT704 = 41;
		static const Sbecore::uint CPT705 = 42;
		static const Sbecore::uint CPT706 = 43;
		static const Sbecore::uint CPT707 = 44;
		static const Sbecore::uint CPT708 = 45;
		static const Sbecore::uint CPT709 = 46;
		static const Sbecore::uint CPT710 = 47;

	public:
		Tag(const std::string& Cpt = "", const std::string& Hdg1 = "", const std::string& Cpt2 = "", const std::string& Cpt3 = "", const std::string& Cpt4 = "", const std::string& Cpt5 = "", const std::string& Cpt6 = "", const std::string& Hdg101 = "", const std::string& Cpt102 = "", const std::string& Cpt103 = "", const std::string& Cpt104 = "", const std::string& Hdg201 = "", const std::string& Cpt202 = "", const std::string& Cpt203 = "", const std::string& Cpt204 = "", const std::string& Hdg301 = "", const std::string& Cpt302 = "", const std::string& Cpt303 = "", const std::string& Cpt304 = "", const std::string& Hdg401 = "", const std::string& Cpt402 = "", const std::string& Cpt403 = "", const std::string& Cpt404 = "", const std::string& Cpt405 = "", const std::string& Cpt406 = "", const std::string& Cpt407 = "", const std::string& Cpt408 = "", const std::string& Hdg501 = "", const std::string& Cpt502 = "", const std::string& Cpt503 = "", const std::string& Cpt504 = "", const std::string& Cpt505 = "", const std::string& Cpt506 = "", const std::string& Cpt507 = "", const std::string& Hdg601 = "", const std::string& Cpt602 = "", const std::string& Cpt603 = "", const std::string& Hdg701 = "", const std::string& Cpt702 = "", const std::string& Cpt703 = "", const std::string& Cpt704 = "", const std::string& Cpt705 = "", const std::string& Cpt706 = "", const std::string& Cpt707 = "", const std::string& Cpt708 = "", const std::string& Cpt709 = "", const std::string& Cpt710 = "");

	public:
		std::string Cpt;
		std::string Hdg1;
		std::string Cpt2;
		std::string Cpt3;
		std::string Cpt4;
		std::string Cpt5;
		std::string Cpt6;
		std::string Hdg101;
		std::string Cpt102;
		std::string Cpt103;
		std::string Cpt104;
		std::string Hdg201;
		std::string Cpt202;
		std::string Cpt203;
		std::string Cpt204;
		std::string Hdg301;
		std::string Cpt302;
		std::string Cpt303;
		std::string Cpt304;
		std::string Hdg401;
		std::string Cpt402;
		std::string Cpt403;
		std::string Cpt404;
		std::string Cpt405;
		std::string Cpt406;
		std::string Cpt407;
		std::string Cpt408;
		std::string Hdg501;
		std::string Cpt502;
		std::string Cpt503;
		std::string Cpt504;
		std::string Cpt505;
		std::string Cpt506;
		std::string Cpt507;
		std::string Hdg601;
		std::string Cpt602;
		std::string Cpt603;
		std::string Hdg701;
		std::string Cpt702;
		std::string Cpt703;
		std::string Cpt704;
		std::string Cpt705;
		std::string Cpt706;
		std::string Cpt707;
		std::string Cpt708;
		std::string Cpt709;
		std::string Cpt710;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWdbePrfDaemonData)
		*/
	class DpchAppData : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppWdbePrfDaemonDo)
		*/
	class DpchAppDo : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngWdbePrfDaemonData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFPUP402 = 3;
		static const Sbecore::uint FEEDFPUP706 = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFPup402;
		Sbecore::Feed feedFPup706;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
