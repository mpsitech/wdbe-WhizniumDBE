/**
	* \file JobWdbeLicense_blks.cpp
	* job handler for job JobWdbeLicense (implementation of blocks)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWdbeLicense::VecVSge
 ******************************************************************************/

uint JobWdbeLicense::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "conn") return CONN;
	if (s == "conerr") return CONERR;
	if (s == "auth") return AUTH;
	if (s == "auterr") return AUTERR;
	if (s == "sync") return SYNC;
	if (s == "sncerr") return SNCERR;

	return(0);
};

string JobWdbeLicense::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == CONN) return("conn");
	if (ix == CONERR) return("conerr");
	if (ix == AUTH) return("auth");
	if (ix == AUTERR) return("auterr");
	if (ix == SYNC) return("sync");
	if (ix == SNCERR) return("sncerr");

	return("");
};

void JobWdbeLicense::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 7; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWdbeLicense::Stg
 ******************************************************************************/

JobWdbeLicense::Stg::Stg(
			const string& engip
			, const uint engport
			, const string& username
			, const string& password
			, const string& licenseBase
			, const string& licenseFull
			, const string& licenseTpl
			, const string& lastAttempt
			, const string& lastSuccess
			, const string& lastSync
		) :
			Block()
		{
	this->engip = engip;
	this->engport = engport;
	this->username = username;
	this->password = password;
	this->licenseBase = licenseBase;
	this->licenseFull = licenseFull;
	this->licenseTpl = licenseTpl;
	this->lastAttempt = lastAttempt;
	this->lastSuccess = lastSuccess;
	this->lastSync = lastSync;
	mask = {ENGIP, ENGPORT, USERNAME, PASSWORD, LICENSEBASE, LICENSEFULL, LICENSETPL, LASTATTEMPT, LASTSUCCESS, LASTSYNC};
};

bool JobWdbeLicense::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWdbeLicense");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWdbeLicense";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engip", engip)) add(ENGIP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engport", engport)) add(ENGPORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "licenseBase", licenseBase)) add(LICENSEBASE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "licenseFull", licenseFull)) add(LICENSEFULL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "licenseTpl", licenseTpl)) add(LICENSETPL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "lastAttempt", lastAttempt)) add(LASTATTEMPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "lastSuccess", lastSuccess)) add(LASTSUCCESS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "lastSync", lastSync)) add(LASTSYNC);
	};

	return basefound;
};

void JobWdbeLicense::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWdbeLicense";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWdbeLicense";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "engip", engip);
		writeUintAttr(wr, itemtag, "sref", "engport", engport);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "licenseBase", licenseBase);
		writeStringAttr(wr, itemtag, "sref", "licenseFull", licenseFull);
		writeStringAttr(wr, itemtag, "sref", "licenseTpl", licenseTpl);
		writeStringAttr(wr, itemtag, "sref", "lastAttempt", lastAttempt);
		writeStringAttr(wr, itemtag, "sref", "lastSuccess", lastSuccess);
		writeStringAttr(wr, itemtag, "sref", "lastSync", lastSync);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWdbeLicense::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (engip == comp->engip) insert(items, ENGIP);
	if (engport == comp->engport) insert(items, ENGPORT);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (licenseBase == comp->licenseBase) insert(items, LICENSEBASE);
	if (licenseFull == comp->licenseFull) insert(items, LICENSEFULL);
	if (licenseTpl == comp->licenseTpl) insert(items, LICENSETPL);
	if (lastAttempt == comp->lastAttempt) insert(items, LASTATTEMPT);
	if (lastSuccess == comp->lastSuccess) insert(items, LASTSUCCESS);
	if (lastSync == comp->lastSync) insert(items, LASTSYNC);

	return(items);
};

set<uint> JobWdbeLicense::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ENGIP, ENGPORT, USERNAME, PASSWORD, LICENSEBASE, LICENSEFULL, LICENSETPL, LASTATTEMPT, LASTSUCCESS, LASTSYNC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

