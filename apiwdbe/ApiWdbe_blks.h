/**
	* \file ApiWdbe_blks.h
	* Wdbe API library global data blocks (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef APIWDBE_BLKS_H
#define APIWDBE_BLKS_H

#include "VecWdbeVBasereptype.h"
#include "VecWdbeVExpstate.h"
#include "VecWdbeVReqitmode.h"

#include "VecWdbeVDpch.h"

/**
	* ContInfWdbeAlert
	*/
class ContInfWdbeAlert : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint TXTCPT = 1;
	static const Sbecore::uint TXTMSG1 = 2;
	static const Sbecore::uint TXTMSG2 = 3;
	static const Sbecore::uint TXTMSG3 = 4;
	static const Sbecore::uint TXTMSG4 = 5;
	static const Sbecore::uint TXTMSG5 = 6;
	static const Sbecore::uint TXTMSG6 = 7;
	static const Sbecore::uint TXTMSG7 = 8;
	static const Sbecore::uint TXTMSG8 = 9;
	static const Sbecore::uint TXTMSG9 = 10;
	static const Sbecore::uint TXTMSG10 = 11;
	static const Sbecore::uint TXTMSG11 = 12;
	static const Sbecore::uint TXTMSG12 = 13;

public:
	ContInfWdbeAlert(const std::string& TxtCpt = "", const std::string& TxtMsg1 = "", const std::string& TxtMsg2 = "", const std::string& TxtMsg3 = "", const std::string& TxtMsg4 = "", const std::string& TxtMsg5 = "", const std::string& TxtMsg6 = "", const std::string& TxtMsg7 = "", const std::string& TxtMsg8 = "", const std::string& TxtMsg9 = "", const std::string& TxtMsg10 = "", const std::string& TxtMsg11 = "", const std::string& TxtMsg12 = "");

public:
	std::string TxtCpt;
	std::string TxtMsg1;
	std::string TxtMsg2;
	std::string TxtMsg3;
	std::string TxtMsg4;
	std::string TxtMsg5;
	std::string TxtMsg6;
	std::string TxtMsg7;
	std::string TxtMsg8;
	std::string TxtMsg9;
	std::string TxtMsg10;
	std::string TxtMsg11;
	std::string TxtMsg12;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	std::set<Sbecore::uint> compare(const ContInfWdbeAlert* comp);
};

/**
	* DpchWdbe
	*/
class DpchWdbe : public Sbecore::Xmlio::Block {

public:
	DpchWdbe(const Sbecore::uint ixWdbeVDpch = 0);
	virtual ~DpchWdbe();

public:
	Sbecore::uint ixWdbeVDpch;
};

/**
	* DpchAppWdbe
	*/
class DpchAppWdbe : public DpchWdbe {

public:
	static const Sbecore::uint SCRJREF = 1;

public:
	DpchAppWdbe(const Sbecore::uint ixWdbeVDpch = 0, const std::string& scrJref = "");
	virtual ~DpchAppWdbe();

public:
	std::string scrJref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();

	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppWdbeAlert
	*/
class DpchAppWdbeAlert : public DpchAppWdbe {

public:
	static const Sbecore::uint SCRJREF = 1;
	static const Sbecore::uint NUMFMCB = 2;
	static const Sbecore::uint ALL = 3;

public:
	DpchAppWdbeAlert(const std::string& scrJref = "", const Sbecore::uint numFMcb = 0, const std::set<Sbecore::uint>& mask = {NONE});

public:
	Sbecore::uint numFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppWdbeInit
	*/
class DpchAppWdbeInit : public DpchAppWdbe {

public:
	DpchAppWdbeInit(const std::string& scrJref = "");
};

/**
	* DpchAppWdbeResume
	*/
class DpchAppWdbeResume : public DpchAppWdbe {

public:
	DpchAppWdbeResume(const std::string& scrJref = "");
};

/**
	* DpchEngWdbe
	*/
class DpchEngWdbe : public DpchWdbe {

public:
	static const Sbecore::uint SCRJREF = 1;

public:
	DpchEngWdbe(const Sbecore::uint ixWdbeVDpch = 0);
	virtual ~DpchEngWdbe();

public:
	std::string scrJref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();

	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngWdbeAck
	*/
class DpchEngWdbeAck : public DpchEngWdbe {

public:
	DpchEngWdbeAck();
};

/**
	* DpchEngWdbeAlert
	*/
class DpchEngWdbeAlert : public DpchEngWdbe {

public:
	static const Sbecore::uint SCRJREF = 1;
	static const Sbecore::uint CONTINF = 2;
	static const Sbecore::uint FEEDFMCB = 3;

public:
	DpchEngWdbeAlert();

public:
	ContInfWdbeAlert continf;
	Sbecore::Xmlio::Feed feedFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngWdbeConfirm
	*/
class DpchEngWdbeConfirm : public DpchEngWdbe {

public:
	static const Sbecore::uint ACCEPTED = 1;
	static const Sbecore::uint SCRJREF = 2;
	static const Sbecore::uint SREF = 3;

public:
	DpchEngWdbeConfirm();

public:
	bool accepted;
	std::string sref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngWdbeSuspend
	*/
class DpchEngWdbeSuspend : public DpchEngWdbe {

public:
	DpchEngWdbeSuspend();
};

#endif

