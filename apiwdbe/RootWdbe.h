/**
	* \file RootWdbe.h
	* API code for job RootWdbe (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef ROOTWDBE_H
#define ROOTWDBE_H

#include "ApiWdbe_blks.h"

#define VecVRootWdbeSge RootWdbe::VecVSge

#define DpchAppRootWdbeLogin RootWdbe::DpchAppLogin
#define DpchEngRootWdbeData RootWdbe::DpchEngData

/**
	* RootWdbe
	*/
namespace RootWdbe {
	/**
		* VecVSge (full: VecVRootWdbeSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint SYNC = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* DpchAppLogin (full: DpchAppRootWdbeLogin)
		*/
	class DpchAppLogin : public DpchAppWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint USERNAME = 2;
		static const Sbecore::uint PASSWORD = 3;
		static const Sbecore::uint M2MNOTREG = 4;
		static const Sbecore::uint CHKSUSPSESS = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchAppLogin(const std::string& scrJref = "", const std::string& username = "", const std::string& password = "", const bool m2mNotReg = false, const bool chksuspsess = false, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		std::string username;
		std::string password;
		bool m2mNotReg;
		bool chksuspsess;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngRootWdbeData)
		*/
	class DpchEngData : public DpchEngWdbe {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint FEEDFENSSPS = 2;

	public:
		DpchEngData();

	public:
		Sbecore::Xmlio::Feed feedFEnsSps;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

