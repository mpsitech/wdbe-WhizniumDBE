/**
	* \file QryWdbePrjPrj1NVersion.h
	* API code for job QryWdbePrjPrj1NVersion (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 16 Dec 2020
	*/
// IP header --- ABOVE

#ifndef QRYWDBEPRJPRJ1NVERSION_H
#define QRYWDBEPRJPRJ1NVERSION_H

#include "ApiWdbe_blks.h"

#define StatAppQryWdbePrjPrj1NVersion QryWdbePrjPrj1NVersion::StatApp
#define StatShrQryWdbePrjPrj1NVersion QryWdbePrjPrj1NVersion::StatShr
#define StgIacQryWdbePrjPrj1NVersion QryWdbePrjPrj1NVersion::StgIac

/**
	* QryWdbePrjPrj1NVersion
	*/
namespace QryWdbePrjPrj1NVersion {
	/**
	  * StatApp (full: StatAppQryWdbePrjPrj1NVersion)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint FIRSTCOL = 1;
		static const Sbecore::uint JNUMFIRSTDISP = 2;
		static const Sbecore::uint NCOL = 3;
		static const Sbecore::uint NDISP = 4;

	public:
		StatApp(const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 1, const Sbecore::uint ndisp = 10);

	public:
		Sbecore::uint firstcol;
		Sbecore::uint jnumFirstdisp;
		Sbecore::uint ncol;
		Sbecore::uint ndisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrQryWdbePrjPrj1NVersion)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint NTOT = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StatShr(const Sbecore::uint ntot = 0, const Sbecore::uint jnumFirstload = 0, const Sbecore::uint nload = 0);

	public:
		Sbecore::uint ntot;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacQryWdbePrjPrj1NVersion)
	  */
	class StgIac : public Sbecore::Block {

	public:
		static const Sbecore::uint JNUM = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StgIac(const Sbecore::uint jnum = 0, const Sbecore::uint jnumFirstload = 1, const Sbecore::uint nload = 100);

	public:
		Sbecore::uint jnum;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

};

#endif
