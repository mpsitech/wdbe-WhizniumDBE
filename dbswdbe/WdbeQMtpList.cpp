/**
	* \file WdbeQMtpList.cpp
	* Dbs and XML wrapper for table TblWdbeQMtpList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQMtpList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMtpList
 ******************************************************************************/

WdbeQMtpList::WdbeQMtpList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string srefWdbeKVendor
			, const string titSrefWdbeKVendor
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const string Srefrule
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, sref(sref)
			, srefWdbeKVendor(srefWdbeKVendor)
			, titSrefWdbeKVendor(titSrefWdbeKVendor)
			, ixVBasetype(ixVBasetype)
			, srefIxVBasetype(srefIxVBasetype)
			, titIxVBasetype(titIxVBasetype)
			, hkIxVTbl(hkIxVTbl)
			, srefHkIxVTbl(srefHkIxVTbl)
			, titHkIxVTbl(titHkIxVTbl)
			, hkUref(hkUref)
			, stubHkUref(stubHkUref)
			, Srefrule(Srefrule)
		{
};

void WdbeQMtpList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["vnd"] = srefWdbeKVendor;
		me["vnd2"] = titSrefWdbeKVendor;
		me["typ"] = srefIxVBasetype;
		me["typ2"] = titIxVBasetype;
		me["hkt"] = srefHkIxVTbl;
		me["hkt2"] = titHkIxVTbl;
		me["hku"] = stubHkUref;
		me["srr"] = Srefrule;
	} else {
		me["sref"] = sref;
		me["srefWdbeKVendor"] = srefWdbeKVendor;
		me["titSrefWdbeKVendor"] = titSrefWdbeKVendor;
		me["srefIxVBasetype"] = srefIxVBasetype;
		me["titIxVBasetype"] = titIxVBasetype;
		me["srefHkIxVTbl"] = srefHkIxVTbl;
		me["titHkIxVTbl"] = titHkIxVTbl;
		me["stubHkUref"] = stubHkUref;
		me["Srefrule"] = Srefrule;
	};
};

void WdbeQMtpList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQMtpList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "vnd", srefWdbeKVendor);
		writeString(wr, "vnd2", titSrefWdbeKVendor);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "hkt", srefHkIxVTbl);
		writeString(wr, "hkt2", titHkIxVTbl);
		writeString(wr, "hku", stubHkUref);
		writeString(wr, "srr", Srefrule);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefWdbeKVendor", srefWdbeKVendor);
		writeString(wr, "titSrefWdbeKVendor", titSrefWdbeKVendor);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "srefHkIxVTbl", srefHkIxVTbl);
		writeString(wr, "titHkIxVTbl", titHkIxVTbl);
		writeString(wr, "stubHkUref", stubHkUref);
		writeString(wr, "Srefrule", Srefrule);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQMtpList
 ******************************************************************************/

ListWdbeQMtpList::ListWdbeQMtpList() {
};

ListWdbeQMtpList::ListWdbeQMtpList(
			const ListWdbeQMtpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpList(*(src.nodes[i]));
};

ListWdbeQMtpList::~ListWdbeQMtpList() {
	clear();
};

void ListWdbeQMtpList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQMtpList::size() const {
	return(nodes.size());
};

void ListWdbeQMtpList::append(
			WdbeQMtpList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQMtpList& ListWdbeQMtpList::operator=(
			const ListWdbeQMtpList& src
		) {
	WdbeQMtpList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQMtpList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQMtpList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQMtpList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQMtpList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQMtpList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQMtpList
 ******************************************************************************/

TblWdbeQMtpList::TblWdbeQMtpList() {
};

TblWdbeQMtpList::~TblWdbeQMtpList() {
};

bool TblWdbeQMtpList::loadRecBySQL(
			const string& sqlstr
			, WdbeQMtpList** rec
		) {
	return false;
};

ubigint TblWdbeQMtpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMtpList& rst
		) {
	return 0;
};

ubigint TblWdbeQMtpList::insertRec(
			WdbeQMtpList* rec
		) {
	return 0;
};

ubigint TblWdbeQMtpList::insertNewRec(
			WdbeQMtpList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string srefWdbeKVendor
			, const string titSrefWdbeKVendor
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const string Srefrule
		) {
	ubigint retval = 0;
	WdbeQMtpList* _rec = NULL;

	_rec = new WdbeQMtpList(0, jref, jnum, ref, sref, srefWdbeKVendor, titSrefWdbeKVendor, ixVBasetype, srefIxVBasetype, titIxVBasetype, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, Srefrule);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQMtpList::appendNewRecToRst(
			ListWdbeQMtpList& rst
			, WdbeQMtpList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string srefWdbeKVendor
			, const string titSrefWdbeKVendor
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const string Srefrule
		) {
	ubigint retval = 0;
	WdbeQMtpList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, srefWdbeKVendor, titSrefWdbeKVendor, ixVBasetype, srefIxVBasetype, titIxVBasetype, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, Srefrule);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQMtpList::insertRst(
			ListWdbeQMtpList& rst
		) {
};

void TblWdbeQMtpList::updateRec(
			WdbeQMtpList* rec
		) {
};

void TblWdbeQMtpList::updateRst(
			ListWdbeQMtpList& rst
		) {
};

void TblWdbeQMtpList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQMtpList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQMtpList::loadRecByQref(
			ubigint qref
			, WdbeQMtpList** rec
		) {
	return false;
};

ubigint TblWdbeQMtpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMtpList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQMtpList
 ******************************************************************************/

MyTblWdbeQMtpList::MyTblWdbeQMtpList() :
			TblWdbeQMtpList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQMtpList::~MyTblWdbeQMtpList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQMtpList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQMtpList (jref, jnum, ref, sref, srefWdbeKVendor, ixVBasetype, hkIxVTbl, hkUref, Srefrule) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQMtpList SET jref = ?, jnum = ?, ref = ?, sref = ?, srefWdbeKVendor = ?, ixVBasetype = ?, hkIxVTbl = ?, hkUref = ?, Srefrule = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQMtpList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQMtpList WHERE jref = ?", false);
};

bool MyTblWdbeQMtpList::loadRecBySQL(
			const string& sqlstr
			, WdbeQMtpList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQMtpList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQMtpList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQMtpList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQMtpList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->srefWdbeKVendor.assign(dbrow[5], dblengths[5]); else _rec->srefWdbeKVendor = "";
		if (dbrow[6]) _rec->ixVBasetype = atol((char*) dbrow[6]); else _rec->ixVBasetype = 0;
		if (dbrow[7]) _rec->hkIxVTbl = atol((char*) dbrow[7]); else _rec->hkIxVTbl = 0;
		if (dbrow[8]) _rec->hkUref = atoll((char*) dbrow[8]); else _rec->hkUref = 0;
		if (dbrow[9]) _rec->Srefrule.assign(dbrow[9], dblengths[9]); else _rec->Srefrule = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQMtpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMtpList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQMtpList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQMtpList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQMtpList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQMtpList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->srefWdbeKVendor.assign(dbrow[5], dblengths[5]); else rec->srefWdbeKVendor = "";
			if (dbrow[6]) rec->ixVBasetype = atol((char*) dbrow[6]); else rec->ixVBasetype = 0;
			if (dbrow[7]) rec->hkIxVTbl = atol((char*) dbrow[7]); else rec->hkIxVTbl = 0;
			if (dbrow[8]) rec->hkUref = atoll((char*) dbrow[8]); else rec->hkUref = 0;
			if (dbrow[9]) rec->Srefrule.assign(dbrow[9], dblengths[9]); else rec->Srefrule = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQMtpList::insertRec(
			WdbeQMtpList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[4] = rec->srefWdbeKVendor.length();
	l[8] = rec->Srefrule.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefWdbeKVendor.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->hkIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->hkUref,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Srefrule.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQMtpList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQMtpList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQMtpList::insertRst(
			ListWdbeQMtpList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQMtpList::updateRec(
			WdbeQMtpList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	l[4] = rec->srefWdbeKVendor.length();
	l[8] = rec->Srefrule.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefWdbeKVendor.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->hkIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->hkUref,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Srefrule.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQMtpList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQMtpList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQMtpList::updateRst(
			ListWdbeQMtpList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQMtpList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQMtpList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQMtpList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQMtpList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQMtpList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQMtpList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQMtpList::loadRecByQref(
			ubigint qref
			, WdbeQMtpList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQMtpList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQMtpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMtpList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQMtpList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQMtpList
 ******************************************************************************/

PgTblWdbeQMtpList::PgTblWdbeQMtpList() :
			TblWdbeQMtpList()
			, PgTable()
		{
};

PgTblWdbeQMtpList::~PgTblWdbeQMtpList() {
};

void PgTblWdbeQMtpList::initStatements() {
	createStatement("TblWdbeQMtpList_insertRec", "INSERT INTO TblWdbeQMtpList (jref, jnum, ref, sref, srefWdbeKVendor, ixVBasetype, hkIxVTbl, hkUref, Srefrule) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblWdbeQMtpList_updateRec", "UPDATE TblWdbeQMtpList SET jref = $1, jnum = $2, ref = $3, sref = $4, srefWdbeKVendor = $5, ixVBasetype = $6, hkIxVTbl = $7, hkUref = $8, Srefrule = $9 WHERE qref = $10", 10);
	createStatement("TblWdbeQMtpList_removeRecByQref", "DELETE FROM TblWdbeQMtpList WHERE qref = $1", 1);
	createStatement("TblWdbeQMtpList_removeRstByJref", "DELETE FROM TblWdbeQMtpList WHERE jref = $1", 1);

	createStatement("TblWdbeQMtpList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, srefWdbeKVendor, ixVBasetype, hkIxVTbl, hkUref, Srefrule FROM TblWdbeQMtpList WHERE qref = $1", 1);
	createStatement("TblWdbeQMtpList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, srefWdbeKVendor, ixVBasetype, hkIxVTbl, hkUref, Srefrule FROM TblWdbeQMtpList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQMtpList::loadRec(
			PGresult* res
			, WdbeQMtpList** rec
		) {
	char* ptr;

	WdbeQMtpList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQMtpList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefwdbekvendor"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "srefrule")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefWdbeKVendor.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Srefrule.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQMtpList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQMtpList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQMtpList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefwdbekvendor"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "srefrule")
		};

		while (numread < numrow) {
			rec = new WdbeQMtpList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefWdbeKVendor.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Srefrule.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQMtpList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQMtpList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMtpList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQMtpList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQMtpList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMtpList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQMtpList::loadRecBySQL(
			const string& sqlstr
			, WdbeQMtpList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQMtpList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQMtpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMtpList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQMtpList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQMtpList::insertRec(
			WdbeQMtpList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->srefWdbeKVendor.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->Srefrule.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQMtpList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMtpList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQMtpList::insertRst(
			ListWdbeQMtpList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQMtpList::updateRec(
			WdbeQMtpList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->srefWdbeKVendor.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->Srefrule.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQMtpList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMtpList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQMtpList::updateRst(
			ListWdbeQMtpList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQMtpList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQMtpList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMtpList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQMtpList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQMtpList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMtpList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQMtpList::loadRecByQref(
			ubigint qref
			, WdbeQMtpList** rec
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

	return loadRecByStmt("TblWdbeQMtpList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQMtpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMtpList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQMtpList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
