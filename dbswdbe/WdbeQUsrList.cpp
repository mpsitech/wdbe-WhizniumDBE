/**
	* \file WdbeQUsrList.cpp
	* Dbs and XML wrapper for table TblWdbeQUsrList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQUsrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUsrList
 ******************************************************************************/

WdbeQUsrList::WdbeQUsrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWdbeMPerson
			, const string stubRefWdbeMPerson
			, const string sref
			, const ubigint refWdbeMUsergroup
			, const string stubRefWdbeMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWdbeVLocale
			, const string srefIxWdbeVLocale
			, const string titIxWdbeVLocale
			, const uint ixWdbeVUserlevel
			, const string srefIxWdbeVUserlevel
			, const string titIxWdbeVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->refWdbeMPerson = refWdbeMPerson;
	this->stubRefWdbeMPerson = stubRefWdbeMPerson;
	this->sref = sref;
	this->refWdbeMUsergroup = refWdbeMUsergroup;
	this->stubRefWdbeMUsergroup = stubRefWdbeMUsergroup;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->ixWdbeVLocale = ixWdbeVLocale;
	this->srefIxWdbeVLocale = srefIxWdbeVLocale;
	this->titIxWdbeVLocale = titIxWdbeVLocale;
	this->ixWdbeVUserlevel = ixWdbeVUserlevel;
	this->srefIxWdbeVUserlevel = srefIxWdbeVUserlevel;
	this->titIxWdbeVUserlevel = titIxWdbeVUserlevel;
};

void WdbeQUsrList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["grp"] = stubGrp;
		me["own"] = stubOwn;
		me["prs"] = stubRefWdbeMPerson;
		me["srf"] = sref;
		me["usg"] = stubRefWdbeMUsergroup;
		me["ste"] = srefIxVState;
		me["ste2"] = titIxVState;
		me["lcl"] = srefIxWdbeVLocale;
		me["lcl2"] = titIxWdbeVLocale;
		me["ulv"] = srefIxWdbeVUserlevel;
		me["ulv2"] = titIxWdbeVUserlevel;
	} else {
		me["stubGrp"] = stubGrp;
		me["stubOwn"] = stubOwn;
		me["stubRefWdbeMPerson"] = stubRefWdbeMPerson;
		me["sref"] = sref;
		me["stubRefWdbeMUsergroup"] = stubRefWdbeMUsergroup;
		me["srefIxVState"] = srefIxVState;
		me["titIxVState"] = titIxVState;
		me["srefIxWdbeVLocale"] = srefIxWdbeVLocale;
		me["titIxWdbeVLocale"] = titIxWdbeVLocale;
		me["srefIxWdbeVUserlevel"] = srefIxWdbeVUserlevel;
		me["titIxWdbeVUserlevel"] = titIxWdbeVUserlevel;
	};
};

void WdbeQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "prs", stubRefWdbeMPerson);
		writeString(wr, "srf", sref);
		writeString(wr, "usg", stubRefWdbeMUsergroup);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "lcl", srefIxWdbeVLocale);
		writeString(wr, "lcl2", titIxWdbeVLocale);
		writeString(wr, "ulv", srefIxWdbeVUserlevel);
		writeString(wr, "ulv2", titIxWdbeVUserlevel);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "stubRefWdbeMPerson", stubRefWdbeMPerson);
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefWdbeMUsergroup", stubRefWdbeMUsergroup);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "srefIxWdbeVLocale", srefIxWdbeVLocale);
		writeString(wr, "titIxWdbeVLocale", titIxWdbeVLocale);
		writeString(wr, "srefIxWdbeVUserlevel", srefIxWdbeVUserlevel);
		writeString(wr, "titIxWdbeVUserlevel", titIxWdbeVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQUsrList
 ******************************************************************************/

ListWdbeQUsrList::ListWdbeQUsrList() {
};

ListWdbeQUsrList::ListWdbeQUsrList(
			const ListWdbeQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsrList(*(src.nodes[i]));
};

ListWdbeQUsrList::~ListWdbeQUsrList() {
	clear();
};

void ListWdbeQUsrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQUsrList::size() const {
	return(nodes.size());
};

void ListWdbeQUsrList::append(
			WdbeQUsrList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQUsrList& ListWdbeQUsrList::operator=(
			const ListWdbeQUsrList& src
		) {
	WdbeQUsrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQUsrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQUsrList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQUsrList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQUsrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQUsrList
 ******************************************************************************/

TblWdbeQUsrList::TblWdbeQUsrList() {
};

TblWdbeQUsrList::~TblWdbeQUsrList() {
};

bool TblWdbeQUsrList::loadRecBySQL(
			const string& sqlstr
			, WdbeQUsrList** rec
		) {
	return false;
};

ubigint TblWdbeQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUsrList& rst
		) {
	return 0;
};

ubigint TblWdbeQUsrList::insertRec(
			WdbeQUsrList* rec
		) {
	return 0;
};

ubigint TblWdbeQUsrList::insertNewRec(
			WdbeQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWdbeMPerson
			, const string stubRefWdbeMPerson
			, const string sref
			, const ubigint refWdbeMUsergroup
			, const string stubRefWdbeMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWdbeVLocale
			, const string srefIxWdbeVLocale
			, const string titIxWdbeVLocale
			, const uint ixWdbeVUserlevel
			, const string srefIxWdbeVUserlevel
			, const string titIxWdbeVUserlevel
		) {
	ubigint retval = 0;
	WdbeQUsrList* _rec = NULL;

	_rec = new WdbeQUsrList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, refWdbeMPerson, stubRefWdbeMPerson, sref, refWdbeMUsergroup, stubRefWdbeMUsergroup, ixVState, srefIxVState, titIxVState, ixWdbeVLocale, srefIxWdbeVLocale, titIxWdbeVLocale, ixWdbeVUserlevel, srefIxWdbeVUserlevel, titIxWdbeVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQUsrList::appendNewRecToRst(
			ListWdbeQUsrList& rst
			, WdbeQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWdbeMPerson
			, const string stubRefWdbeMPerson
			, const string sref
			, const ubigint refWdbeMUsergroup
			, const string stubRefWdbeMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixWdbeVLocale
			, const string srefIxWdbeVLocale
			, const string titIxWdbeVLocale
			, const uint ixWdbeVUserlevel
			, const string srefIxWdbeVUserlevel
			, const string titIxWdbeVUserlevel
		) {
	ubigint retval = 0;
	WdbeQUsrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, refWdbeMPerson, stubRefWdbeMPerson, sref, refWdbeMUsergroup, stubRefWdbeMUsergroup, ixVState, srefIxVState, titIxVState, ixWdbeVLocale, srefIxWdbeVLocale, titIxWdbeVLocale, ixWdbeVUserlevel, srefIxWdbeVUserlevel, titIxWdbeVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQUsrList::insertRst(
			ListWdbeQUsrList& rst
		) {
};

void TblWdbeQUsrList::updateRec(
			WdbeQUsrList* rec
		) {
};

void TblWdbeQUsrList::updateRst(
			ListWdbeQUsrList& rst
		) {
};

void TblWdbeQUsrList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQUsrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQUsrList::loadRecByQref(
			ubigint qref
			, WdbeQUsrList** rec
		) {
	return false;
};

ubigint TblWdbeQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUsrList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQUsrList
 ******************************************************************************/

MyTblWdbeQUsrList::MyTblWdbeQUsrList() :
			TblWdbeQUsrList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQUsrList::~MyTblWdbeQUsrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQUsrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQUsrList (jref, jnum, ref, grp, own, refWdbeMPerson, sref, refWdbeMUsergroup, ixVState, ixWdbeVLocale, ixWdbeVUserlevel) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQUsrList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, refWdbeMPerson = ?, sref = ?, refWdbeMUsergroup = ?, ixVState = ?, ixWdbeVLocale = ?, ixWdbeVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQUsrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQUsrList WHERE jref = ?", false);
};

bool MyTblWdbeQUsrList::loadRecBySQL(
			const string& sqlstr
			, WdbeQUsrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQUsrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQUsrList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQUsrList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQUsrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->refWdbeMPerson = atoll((char*) dbrow[6]); else _rec->refWdbeMPerson = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->refWdbeMUsergroup = atoll((char*) dbrow[8]); else _rec->refWdbeMUsergroup = 0;
		if (dbrow[9]) _rec->ixVState = atol((char*) dbrow[9]); else _rec->ixVState = 0;
		if (dbrow[10]) _rec->ixWdbeVLocale = atol((char*) dbrow[10]); else _rec->ixWdbeVLocale = 0;
		if (dbrow[11]) _rec->ixWdbeVUserlevel = atol((char*) dbrow[11]); else _rec->ixWdbeVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUsrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQUsrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQUsrList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQUsrList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQUsrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->refWdbeMPerson = atoll((char*) dbrow[6]); else rec->refWdbeMPerson = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->refWdbeMUsergroup = atoll((char*) dbrow[8]); else rec->refWdbeMUsergroup = 0;
			if (dbrow[9]) rec->ixVState = atol((char*) dbrow[9]); else rec->ixVState = 0;
			if (dbrow[10]) rec->ixWdbeVLocale = atol((char*) dbrow[10]); else rec->ixWdbeVLocale = 0;
			if (dbrow[11]) rec->ixWdbeVUserlevel = atol((char*) dbrow[11]); else rec->ixWdbeVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQUsrList::insertRec(
			WdbeQUsrList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWdbeMPerson,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWdbeMUsergroup,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWdbeVLocale,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixWdbeVUserlevel,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQUsrList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQUsrList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQUsrList::insertRst(
			ListWdbeQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQUsrList::updateRec(
			WdbeQUsrList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[6] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWdbeMPerson,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWdbeMUsergroup,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixVState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWdbeVLocale,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixWdbeVUserlevel,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQUsrList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQUsrList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQUsrList::updateRst(
			ListWdbeQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQUsrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQUsrList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQUsrList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQUsrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQUsrList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQUsrList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQUsrList::loadRecByQref(
			ubigint qref
			, WdbeQUsrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQUsrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUsrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQUsrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQUsrList
 ******************************************************************************/

PgTblWdbeQUsrList::PgTblWdbeQUsrList() :
			TblWdbeQUsrList()
			, PgTable()
		{
};

PgTblWdbeQUsrList::~PgTblWdbeQUsrList() {
};

void PgTblWdbeQUsrList::initStatements() {
	createStatement("TblWdbeQUsrList_insertRec", "INSERT INTO TblWdbeQUsrList (jref, jnum, ref, grp, own, refWdbeMPerson, sref, refWdbeMUsergroup, ixVState, ixWdbeVLocale, ixWdbeVUserlevel) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblWdbeQUsrList_updateRec", "UPDATE TblWdbeQUsrList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, refWdbeMPerson = $6, sref = $7, refWdbeMUsergroup = $8, ixVState = $9, ixWdbeVLocale = $10, ixWdbeVUserlevel = $11 WHERE qref = $12", 12);
	createStatement("TblWdbeQUsrList_removeRecByQref", "DELETE FROM TblWdbeQUsrList WHERE qref = $1", 1);
	createStatement("TblWdbeQUsrList_removeRstByJref", "DELETE FROM TblWdbeQUsrList WHERE jref = $1", 1);

	createStatement("TblWdbeQUsrList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, refWdbeMPerson, sref, refWdbeMUsergroup, ixVState, ixWdbeVLocale, ixWdbeVUserlevel FROM TblWdbeQUsrList WHERE qref = $1", 1);
	createStatement("TblWdbeQUsrList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, refWdbeMPerson, sref, refWdbeMUsergroup, ixVState, ixWdbeVLocale, ixWdbeVUserlevel FROM TblWdbeQUsrList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQUsrList::loadRec(
			PGresult* res
			, WdbeQUsrList** rec
		) {
	char* ptr;

	WdbeQUsrList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQUsrList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwdbemusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwdbevlocale"),
			PQfnumber(res, "ixwdbevuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWdbeMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWdbeMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixWdbeVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->ixWdbeVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQUsrList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQUsrList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQUsrList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwdbemusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwdbevlocale"),
			PQfnumber(res, "ixwdbevuserlevel")
		};

		while (numread < numrow) {
			rec = new WdbeQUsrList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWdbeMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWdbeMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixWdbeVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->ixWdbeVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQUsrList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQUsrList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUsrList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQUsrList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQUsrList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUsrList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQUsrList::loadRecBySQL(
			const string& sqlstr
			, WdbeQUsrList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQUsrList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUsrList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQUsrList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQUsrList::insertRec(
			WdbeQUsrList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);
	ubigint _refWdbeMUsergroup = htonl64(rec->refWdbeMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWdbeVLocale = htonl(rec->ixWdbeVLocale);
	uint _ixWdbeVUserlevel = htonl(rec->ixWdbeVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWdbeMPerson,
		rec->sref.c_str(),
		(char*) &_refWdbeMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixWdbeVLocale,
		(char*) &_ixWdbeVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQUsrList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUsrList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQUsrList::insertRst(
			ListWdbeQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQUsrList::updateRec(
			WdbeQUsrList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);
	ubigint _refWdbeMUsergroup = htonl64(rec->refWdbeMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWdbeVLocale = htonl(rec->ixWdbeVLocale);
	uint _ixWdbeVUserlevel = htonl(rec->ixWdbeVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWdbeMPerson,
		rec->sref.c_str(),
		(char*) &_refWdbeMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixWdbeVLocale,
		(char*) &_ixWdbeVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQUsrList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUsrList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQUsrList::updateRst(
			ListWdbeQUsrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQUsrList::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWdbeQUsrList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUsrList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQUsrList::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWdbeQUsrList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUsrList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQUsrList::loadRecByQref(
			ubigint qref
			, WdbeQUsrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeQUsrList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUsrList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQUsrList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
