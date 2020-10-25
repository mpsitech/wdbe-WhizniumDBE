/**
	* \file Wdbeopd.cpp
	* inter-thread exchange object for Wdbe operation daemon wdbeopd1 (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "Wdbeopd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DpchWdbedReg
 ******************************************************************************/

DpchWdbedReg::DpchWdbedReg() :
			DpchWdbe(VecWdbeVDpch::DPCHWDBEDREG)
		{
};

bool DpchWdbedReg::all(
			const set<uint>& items
		) {
	if (!find(items, SCRNREF)) return false;

	return true;
};

void DpchWdbedReg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchWdbedReg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrNref", "", scrNref)) add(SCRNREF);
	};
};

/******************************************************************************
 namespace DpchWdbeopdAck
 ******************************************************************************/

void DpchWdbeopdAck::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchWdbeopdAck");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchWdbeopdReg
 ******************************************************************************/

void DpchWdbeopdReg::writeXML(
			xmlTextWriter* wr
			, const usmallint port
			, const uint ixWdbeVOpengtype
			, const usmallint opprcn
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchWdbeopdReg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeUsmallint(wr, "port", port);
		writeString(wr, "srefIxWdbeVOpengtype", VecWdbeVOpengtype::getSref(ixWdbeVOpengtype));
		writeUsmallint(wr, "opprcn", opprcn);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchWdbeopdUnreg
 ******************************************************************************/

void DpchWdbeopdUnreg::writeXML(
			xmlTextWriter* wr
			, const string& scrNref
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchWdbeopdUnreg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrNref", scrNref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class StgWdbeDatabase
 ******************************************************************************/

StgWdbeDatabase::StgWdbeDatabase(
			const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& username
			, const string& password
			, const string& ip
			, const usmallint port
		) :
			Block()
		{
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	mask = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
};

bool StgWdbeDatabase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbeDatabase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbeDatabase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
	};

	return basefound;
};

void StgWdbeDatabase::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbeDatabase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWdbeDatabase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbeDatabase::comm(
			const StgWdbeDatabase* comp
		) {
	set<uint> items;

	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);

	return(items);
};

set<uint> StgWdbeDatabase::diff(
			const StgWdbeDatabase* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWdbeMonitor
 ******************************************************************************/

StgWdbeMonitor::StgWdbeMonitor(
			const string& username
			, const string& password
			, const string& ip
			, const usmallint port
			, const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& dbsusername
			, const string& dbspassword
		) :
			Block()
		{
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->dbsusername = dbsusername;
	this->dbspassword = dbspassword;
	mask = {USERNAME, PASSWORD, IP, PORT, IXDBSVDBSTYPE, DBSPATH, DBSNAME, DBSUSERNAME, DBSPASSWORD};
};

bool StgWdbeMonitor::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbeMonitor");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbeMonitor";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsusername", dbsusername)) add(DBSUSERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspassword", dbspassword)) add(DBSPASSWORD);
	};

	return basefound;
};

void StgWdbeMonitor::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbeMonitor";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWdbeMonitor";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "dbsusername", dbsusername);
		writeStringAttr(wr, itemtag, "sref", "dbspassword", dbspassword);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbeMonitor::comm(
			const StgWdbeMonitor* comp
		) {
	set<uint> items;

	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);
	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (dbsusername == comp->dbsusername) insert(items, DBSUSERNAME);
	if (dbspassword == comp->dbspassword) insert(items, DBSPASSWORD);

	return(items);
};

set<uint> StgWdbeMonitor::diff(
			const StgWdbeMonitor* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {USERNAME, PASSWORD, IP, PORT, IXDBSVDBSTYPE, DBSPATH, DBSNAME, DBSUSERNAME, DBSPASSWORD};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWdbeopd
 ******************************************************************************/

StgWdbeopd::StgWdbeopd(
			const string& engip
			, const usmallint engport
			, const usmallint engsrvportbase
			, const usmallint engsrvportofs
			, const usmallint opprcn
		) :
			Block()
		{
	this->engip = engip;
	this->engport = engport;
	this->engsrvportbase = engsrvportbase;
	this->engsrvportofs = engsrvportofs;
	this->opprcn = opprcn;
	mask = {ENGIP, ENGPORT, ENGSRVPORTBASE, ENGSRVPORTOFS, OPPRCN};
};

bool StgWdbeopd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbeopd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbeopd";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engip", engip)) add(ENGIP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engport", engport)) add(ENGPORT);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engsrvportbase", engsrvportbase)) add(ENGSRVPORTBASE);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engsrvportofs", engsrvportofs)) add(ENGSRVPORTOFS);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opprcn", opprcn)) add(OPPRCN);
	};

	return basefound;
};

void StgWdbeopd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbeopd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWdbeopd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "engip", engip);
		writeUsmallintAttr(wr, itemtag, "sref", "engport", engport);
		writeUsmallintAttr(wr, itemtag, "sref", "engsrvportbase", engsrvportbase);
		writeUsmallintAttr(wr, itemtag, "sref", "engsrvportofs", engsrvportofs);
		writeUsmallintAttr(wr, itemtag, "sref", "opprcn", opprcn);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbeopd::comm(
			const StgWdbeopd* comp
		) {
	set<uint> items;

	if (engip == comp->engip) insert(items, ENGIP);
	if (engport == comp->engport) insert(items, ENGPORT);
	if (engsrvportbase == comp->engsrvportbase) insert(items, ENGSRVPORTBASE);
	if (engsrvportofs == comp->engsrvportofs) insert(items, ENGSRVPORTOFS);
	if (opprcn == comp->opprcn) insert(items, OPPRCN);

	return(items);
};

set<uint> StgWdbeopd::diff(
			const StgWdbeopd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ENGIP, ENGPORT, ENGSRVPORTBASE, ENGSRVPORTOFS, OPPRCN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgWdbePath
 ******************************************************************************/

StgWdbePath::StgWdbePath(
			const string& acvpath
			, const string& keypath
			, const string& monpath
			, const string& tmppath
			, const string& webpath
			, const string& helpurl
		) :
			Block()
		{
	this->acvpath = acvpath;
	this->keypath = keypath;
	this->monpath = monpath;
	this->tmppath = tmppath;
	this->webpath = webpath;
	this->helpurl = helpurl;
	mask = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
};

bool StgWdbePath::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbePath");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbePath";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acvpath", acvpath)) add(ACVPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "keypath", keypath)) add(KEYPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "monpath", monpath)) add(MONPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "tmppath", tmppath)) add(TMPPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "webpath", webpath)) add(WEBPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "helpurl", helpurl)) add(HELPURL);
	};

	return basefound;
};

void StgWdbePath::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbePath";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemWdbePath";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "acvpath", acvpath);
		writeStringAttr(wr, itemtag, "sref", "keypath", keypath);
		writeStringAttr(wr, itemtag, "sref", "monpath", monpath);
		writeStringAttr(wr, itemtag, "sref", "tmppath", tmppath);
		writeStringAttr(wr, itemtag, "sref", "webpath", webpath);
		writeStringAttr(wr, itemtag, "sref", "helpurl", helpurl);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbePath::comm(
			const StgWdbePath* comp
		) {
	set<uint> items;

	if (acvpath == comp->acvpath) insert(items, ACVPATH);
	if (keypath == comp->keypath) insert(items, KEYPATH);
	if (monpath == comp->monpath) insert(items, MONPATH);
	if (tmppath == comp->tmppath) insert(items, TMPPATH);
	if (webpath == comp->webpath) insert(items, WEBPATH);
	if (helpurl == comp->helpurl) insert(items, HELPURL);

	return(items);
};

set<uint> StgWdbePath::diff(
			const StgWdbePath* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACVPATH, KEYPATH, MONPATH, TMPPATH, WEBPATH, HELPURL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class ReqopWdbe
 ******************************************************************************/

ReqopWdbe::ReqopWdbe(
			const uint ixVBasetype
			, const uint ixVState
		) :
			cReady("cReady", "ReqopWdbe", "ReqopWdbe")
		{
	this->ixVBasetype = ixVBasetype;
	this->ixVState = ixVState;

	pdone = 0;

	pp = NULL;

	request = NULL;
	requestlen = 0;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;
};

ReqopWdbe::~ReqopWdbe() {
	if (pp) MHD_destroy_post_processor(pp);

	if (request) delete[] request;

	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	if (reply) delete[] reply;

	cReady.lockMutex("ReqopWdbe", "~ReqopWdbe");
	cReady.unlockMutex("ReqopWdbe", "~ReqopWdbe");
};

void ReqopWdbe::setStateReply() {
	cReady.lockMutex("ReqopWdbe", "setStateReply", "scrOref=" + dpchinv->scrOref);

	ixVState = VecVState::REPLY;

	pdone = 100;

	if (dpchret) {
		dpchret->scrOref = dpchinv->scrOref;
		dpchret->scrJref = dpchinv->scrJref;
		dpchret->pdone = pdone;
	};

	cReady.unlockMutex("ReqopWdbe", "setStateReply", "scrOref=" + dpchinv->scrOref);

	cReady.signal("ReqopWdbe", "setStateReply", "scrOref=" + dpchinv->scrOref);
};

/******************************************************************************
 class ShrdatWdbe
 ******************************************************************************/

ShrdatWdbe::ShrdatWdbe(
			const string& srefSupclass
			, const string& srefObject
		) :
			rwmAccess("shrdat.mAccess", srefSupclass + "::" + srefObject, srefObject)
		{
	this->srefSupclass = srefSupclass;
	this->srefObject = srefObject;
};

ShrdatWdbe::~ShrdatWdbe() {
};

void ShrdatWdbe::init(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
		) {
};

void ShrdatWdbe::term(
			XchgWdbe* xchg
		) {
};

void ShrdatWdbe::rlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	rwmAccess.rlock(srefObject, srefMember);
};

void ShrdatWdbe::runlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	rwmAccess.runlock(srefObject, srefMember);
};

void ShrdatWdbe::wlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	rwmAccess.wlock(srefObject, srefMember);
};

void ShrdatWdbe::wunlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	rwmAccess.wunlock(srefObject, srefMember);
};

// IP ShrdatOpprc.subs --- INSERT

/******************************************************************************
 class XchgWdbeopd::ShrdatOpprc
 ******************************************************************************/

XchgWdbeopd::ShrdatOpprc::ShrdatOpprc() :
			ShrdatWdbe("XchgWdbe", "ShrdatOpprc")
		{
};

void XchgWdbeopd::ShrdatOpprc::init(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
		) {
	// IP ShrdatOpprc.init --- INSERT
};

void XchgWdbeopd::ShrdatOpprc::term(
			XchgWdbe* xchg
		) {
	// IP ShrdatOpprc.term --- INSERT
};

/******************************************************************************
 class XchgWdbeopd
 ******************************************************************************/

XchgWdbeopd::XchgWdbeopd() :
			cStable("cStable", "XchgWdbeopd", "XchgWdbeopd")
			, mLogfile("mLogfile", "XchgWdbeopd", "XchgWdbeopd")
			, cTerm("cTerm", "XchgWdbeopd", "XchgWdbeopd")
			, cOpprcs("cOpprcs", "XchgWdbeopd", "XchgWdbeopd")
			, mReqs("mReqs", "XchgWdbeopd", "XchgWdbeopd")
		{
	// IP constructor.data --- INSERT
};

XchgWdbeopd::~XchgWdbeopd() {
	// empty out lists
	for (auto it = reqs.begin(); it != reqs.end(); it++) delete(*it);
	for (auto it = prcreqs.begin(); it != prcreqs.end(); it++) delete(it->second);
};

// IP cust --- INSERT

void XchgWdbeopd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	mLogfile.lock("XchgWdbeopd", "appendToLogfile");

	time(&rawtime);

	logfile.open(exedir + "/log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	mLogfile.unlock("XchgWdbeopd", "appendToLogfile");
};

void XchgWdbeopd::addReq(
			ReqopWdbe* req
		) {
	mReqs.lock("XchgWdbeopd", "addReq");

	req->ixVState = ReqopWdbe::VecVState::WAITPRC;
	reqs.push_back(req);

	mReqs.unlock("XchgWdbeopd", "addReq");

	cOpprcs.signal("XchgWdbeopd", "addReq");
};

ReqopWdbe* XchgWdbeopd::pullFirstReq() {
	ReqopWdbe* req;

	// get first element from list
	mReqs.lock("XchgWdbeopd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqopWdbe::VecVState::PRC;
		reqs.pop_front();

		prcreqs[req->dpchinv->scrOref] = req;
	};

	mReqs.unlock("XchgWdbeopd", "pullFirstReq");

	return req;
};

ReqopWdbe* XchgWdbeopd::getPrcreqByScrOref(
			const string& scrOref
		) {
	ReqopWdbe* req = NULL;

	mReqs.lock("XchgWdbeopd", "getPrcreqByScrOref", "scrOref=" + scrOref);

	auto it = prcreqs.find(scrOref);

	if (it != prcreqs.end()) {
		req = it->second;
		req->cReady.lockMutex("XchgWdbeopd", "getPrcreqByScrOref", "scrOref=" + scrOref);
	};

	mReqs.unlock("XchgWdbeopd", "getPrcreqByScrOref", "scrOref=" + scrOref);

	return req;
};

void XchgWdbeopd::pullPrcreq(
			const string& scrOref
		) {
	mReqs.lock("XchgWdbeopd", "pullPrcreq", "scrOref=" + scrOref);

	auto it = prcreqs.find(scrOref);
	if (it != prcreqs.end()) prcreqs.erase(it);

	mReqs.unlock("XchgWdbeopd", "pullPrcreq", "scrOref=" + scrOref);
};

void XchgWdbeopd::setPdone(
			const string& scrOref
			, const utinyint pdone
		) {
	ReqopWdbe* req = NULL;

	req = getPrcreqByScrOref(scrOref);

	if (req) {
		req->pdone = pdone;
		req->cReady.unlockMutex("XchgWdbeopd", "setPdone", "scrOref=" + scrOref);
	};
};

