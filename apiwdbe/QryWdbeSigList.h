/**
	* \file QryWdbeSigList.h
	* API code for job QryWdbeSigList (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef QRYWDBESIGLIST_H
#define QRYWDBESIGLIST_H

#include "ApiWdbe_blks.h"

#define VecVQryWdbeSigListOrd QryWdbeSigList::VecVOrd

#define StatAppQryWdbeSigList QryWdbeSigList::StatApp
#define StatShrQryWdbeSigList QryWdbeSigList::StatShr
#define StgIacQryWdbeSigList QryWdbeSigList::StgIac

/**
	* QryWdbeSigList
	*/
namespace QryWdbeSigList {
	/**
		* VecVOrd (full: VecVQryWdbeSigListOrd)
		*/
	class VecVOrd {

	public:
		static const Sbecore::uint SRF = 1;
		static const Sbecore::uint TYP = 2;
		static const Sbecore::uint MDL = 3;
		static const Sbecore::uint MGT = 4;
		static const Sbecore::uint MGU = 5;
		static const Sbecore::uint VEC = 6;
		static const Sbecore::uint CON = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * StatApp (full: StatAppQryWdbeSigList)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint FIRSTCOL = 1;
		static const Sbecore::uint JNUMFIRSTDISP = 2;
		static const Sbecore::uint NCOL = 3;
		static const Sbecore::uint NDISP = 4;

	public:
		StatApp(const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 13, const Sbecore::uint ndisp = 25);

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
	  * StatShr (full: StatShrQryWdbeSigList)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

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
	  * StgIac (full: StgIacQryWdbeSigList)
	  */
	class StgIac : public Sbecore::Xmlio::Block {

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

