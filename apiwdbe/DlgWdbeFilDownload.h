/**
	* \file DlgWdbeFilDownload.h
	* API code for job DlgWdbeFilDownload (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef DLGWDBEFILDOWNLOAD_H
#define DLGWDBEFILDOWNLOAD_H

#include "ApiWdbe_blks.h"

#define VecVDlgWdbeFilDownloadDo DlgWdbeFilDownload::VecVDo

#define ContInfDlgWdbeFilDownload DlgWdbeFilDownload::ContInf
#define StatAppDlgWdbeFilDownload DlgWdbeFilDownload::StatApp
#define TagDlgWdbeFilDownload DlgWdbeFilDownload::Tag

#define DpchAppDlgWdbeFilDownloadDo DlgWdbeFilDownload::DpchAppDo
#define DpchEngDlgWdbeFilDownloadData DlgWdbeFilDownload::DpchEngData

/**
	* DlgWdbeFilDownload
	*/
namespace DlgWdbeFilDownload {
	/**
		* VecVDo (full: VecVDlgWdbeFilDownloadDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfDlgWdbeFilDownload)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInf(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWdbeFilDownload)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SHORTMENU = 1;

	public:
		StatApp(const std::string& shortMenu = "");

	public:
		std::string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * Tag (full: TagDlgWdbeFilDownload)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint DLD = 2;
		static const Sbecore::uint BUTDNE = 3;

	public:
		Tag(const std::string& Cpt = "", const std::string& Dld = "", const std::string& ButDne = "");

	public:
		std::string Cpt;
		std::string Dld;
		std::string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeFilDownloadDo)
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
		* DpchEngData (full: DpchEngDlgWdbeFilDownloadData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatApp statapp;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

