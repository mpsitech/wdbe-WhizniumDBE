/**
	* \file WdbeQSnsList.cpp
	* Dbs and XML wrapper for table TblWdbeQSnsList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQSnsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSnsList
 ******************************************************************************/

WdbeQSnsList::WdbeQSnsList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint srcIxVTbl
			, const string srefSrcIxVTbl
			, const string titSrcIxVTbl
			, const ubigint srcUref
			, const string stubSrcUref
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, refIxVTbl(refIxVTbl)
			, srefRefIxVTbl(srefRefIxVTbl)
			, titRefIxVTbl(titRefIxVTbl)
			, refUref(refUref)
			, stubRefUref(stubRefUref)
			, srcIxVTbl(srcIxVTbl)
			, srefSrcIxVTbl(srefSrcIxVTbl)
			, titSrcIxVTbl(titSrcIxVTbl)
			, srcUref(srcUref)
			, stubSrcUref(stubSrcUref)
		{
};

void WdbeQSnsList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["ret"] = srefRefIxVTbl;
		me["ret2"] = titRefIxVTbl;
		me["reu"] = stubRefUref;
		me["srt"] = srefSrcIxVTbl;
		me["srt2"] = titSrcIxVTbl;
		me["sru"] = stubSrcUref;
	} else {
		me["srefRefIxVTbl"] = srefRefIxVTbl;
		me["titRefIxVTbl"] = titRefIxVTbl;
		me["stubRefUref"] = stubRefUref;
		me["srefSrcIxVTbl"] = srefSrcIxVTbl;
		me["titSrcIxVTbl"] = titSrcIxVTbl;
		me["stubSrcUref"] = stubSrcUref;
	};
};

void WdbeQSnsList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQSnsList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeString(wr, "srt", srefSrcIxVTbl);
		writeString(wr, "srt2", titSrcIxVTbl);
		writeString(wr, "sru", stubSrcUref);
	} else {
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeString(wr, "srefSrcIxVTbl", srefSrcIxVTbl);
		writeString(wr, "titSrcIxVTbl", titSrcIxVTbl);
		writeString(wr, "stubSrcUref", stubSrcUref);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQSnsList
 ******************************************************************************/

ListWdbeQSnsList::ListWdbeQSnsList() {
};

ListWdbeQSnsList::ListWdbeQSnsList(
			const ListWdbeQSnsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSnsList(*(src.nodes[i]));
};

ListWdbeQSnsList::~ListWdbeQSnsList() {
	clear();
};

void ListWdbeQSnsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQSnsList::size() const {
	return(nodes.size());
};

void ListWdbeQSnsList::append(
			WdbeQSnsList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQSnsList& ListWdbeQSnsList::operator=(
			const ListWdbeQSnsList& src
		) {
	WdbeQSnsList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQSnsList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQSnsList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQSnsList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQSnsList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQSnsList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQSnsList
 ******************************************************************************/

TblWdbeQSnsList::TblWdbeQSnsList() {
};

TblWdbeQSnsList::~TblWdbeQSnsList() {
};

bool TblWdbeQSnsList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSnsList** rec
		) {
	return false;
};

ubigint TblWdbeQSnsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSnsList& rst
		) {
	return 0;
};

ubigint TblWdbeQSnsList::insertRec(
			WdbeQSnsList* rec
		) {
	return 0;
};

ubigint TblWdbeQSnsList::insertNewRec(
			WdbeQSnsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint srcIxVTbl
			, const string srefSrcIxVTbl
			, const string titSrcIxVTbl
			, const ubigint srcUref
			, const string stubSrcUref
		) {
	ubigint retval = 0;
	WdbeQSnsList* _rec = NULL;

	_rec = new WdbeQSnsList(0, jref, jnum, ref, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, srcIxVTbl, srefSrcIxVTbl, titSrcIxVTbl, srcUref, stubSrcUref);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQSnsList::appendNewRecToRst(
			ListWdbeQSnsList& rst
			, WdbeQSnsList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint srcIxVTbl
			, const string srefSrcIxVTbl
			, const string titSrcIxVTbl
			, const ubigint srcUref
			, const string stubSrcUref
		) {
	ubigint retval = 0;
	WdbeQSnsList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, srcIxVTbl, srefSrcIxVTbl, titSrcIxVTbl, srcUref, stubSrcUref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQSnsList::insertRst(
			ListWdbeQSnsList& rst
		) {
};

void TblWdbeQSnsList::updateRec(
			WdbeQSnsList* rec
		) {
};

void TblWdbeQSnsList::updateRst(
			ListWdbeQSnsList& rst
		) {
};

void TblWdbeQSnsList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQSnsList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQSnsList::loadRecByQref(
			ubigint qref
			, WdbeQSnsList** rec
		) {
	return false;
};

ubigint TblWdbeQSnsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSnsList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQSnsList
 ******************************************************************************/

MyTblWdbeQSnsList::MyTblWdbeQSnsList() :
			TblWdbeQSnsList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQSnsList::~MyTblWdbeQSnsList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQSnsList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQSnsList (jref, jnum, ref, refIxVTbl, refUref, srcIxVTbl, srcUref) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQSnsList SET jref = ?, jnum = ?, ref = ?, refIxVTbl = ?, refUref = ?, srcIxVTbl = ?, srcUref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQSnsList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQSnsList WHERE jref = ?", false);
};

bool MyTblWdbeQSnsList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSnsList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQSnsList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSnsList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSnsList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQSnsList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refIxVTbl = atol((char*) dbrow[4]); else _rec->refIxVTbl = 0;
		if (dbrow[5]) _rec->refUref = atoll((char*) dbrow[5]); else _rec->refUref = 0;
		if (dbrow[6]) _rec->srcIxVTbl = atol((char*) dbrow[6]); else _rec->srcIxVTbl = 0;
		if (dbrow[7]) _rec->srcUref = atoll((char*) dbrow[7]); else _rec->srcUref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQSnsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSnsList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQSnsList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSnsList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSnsList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQSnsList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refIxVTbl = atol((char*) dbrow[4]); else rec->refIxVTbl = 0;
			if (dbrow[5]) rec->refUref = atoll((char*) dbrow[5]); else rec->refUref = 0;
			if (dbrow[6]) rec->srcIxVTbl = atol((char*) dbrow[6]); else rec->srcIxVTbl = 0;
			if (dbrow[7]) rec->srcUref = atoll((char*) dbrow[7]); else rec->srcUref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQSnsList::insertRec(
			WdbeQSnsList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->srcIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->srcUref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQSnsList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQSnsList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQSnsList::insertRst(
			ListWdbeQSnsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQSnsList::updateRec(
			WdbeQSnsList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->srcIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->srcUref,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQSnsList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQSnsList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSnsList::updateRst(
			ListWdbeQSnsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQSnsList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQSnsList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQSnsList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSnsList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQSnsList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQSnsList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQSnsList::loadRecByQref(
			ubigint qref
			, WdbeQSnsList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQSnsList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQSnsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSnsList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQSnsList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQSnsList
 ******************************************************************************/

PgTblWdbeQSnsList::PgTblWdbeQSnsList() :
			TblWdbeQSnsList()
			, PgTable()
		{
};

PgTblWdbeQSnsList::~PgTblWdbeQSnsList() {
};

void PgTblWdbeQSnsList::initStatements() {
	createStatement("TblWdbeQSnsList_insertRec", "INSERT INTO TblWdbeQSnsList (jref, jnum, ref, refIxVTbl, refUref, srcIxVTbl, srcUref) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWdbeQSnsList_updateRec", "UPDATE TblWdbeQSnsList SET jref = $1, jnum = $2, ref = $3, refIxVTbl = $4, refUref = $5, srcIxVTbl = $6, srcUref = $7 WHERE qref = $8", 8);
	createStatement("TblWdbeQSnsList_removeRecByQref", "DELETE FROM TblWdbeQSnsList WHERE qref = $1", 1);
	createStatement("TblWdbeQSnsList_removeRstByJref", "DELETE FROM TblWdbeQSnsList WHERE jref = $1", 1);

	createStatement("TblWdbeQSnsList_loadRecByQref", "SELECT qref, jref, jnum, ref, refIxVTbl, refUref, srcIxVTbl, srcUref FROM TblWdbeQSnsList WHERE qref = $1", 1);
	createStatement("TblWdbeQSnsList_loadRstByJref", "SELECT qref, jref, jnum, ref, refIxVTbl, refUref, srcIxVTbl, srcUref FROM TblWdbeQSnsList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQSnsList::loadRec(
			PGresult* res
			, WdbeQSnsList** rec
		) {
	char* ptr;

	WdbeQSnsList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQSnsList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "srcixvtbl"),
			PQfnumber(res, "srcuref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->srcIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->srcUref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQSnsList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQSnsList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQSnsList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "srcixvtbl"),
			PQfnumber(res, "srcuref")
		};

		while (numread < numrow) {
			rec = new WdbeQSnsList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->srcIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->srcUref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQSnsList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQSnsList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSnsList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSnsList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQSnsList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSnsList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQSnsList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSnsList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSnsList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSnsList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSnsList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSnsList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQSnsList::insertRec(
			WdbeQSnsList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _srcIxVTbl = htonl(rec->srcIxVTbl);
	ubigint _srcUref = htonl64(rec->srcUref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_srcIxVTbl,
		(char*) &_srcUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQSnsList_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSnsList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQSnsList::insertRst(
			ListWdbeQSnsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQSnsList::updateRec(
			WdbeQSnsList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _srcIxVTbl = htonl(rec->srcIxVTbl);
	ubigint _srcUref = htonl64(rec->srcUref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_srcIxVTbl,
		(char*) &_srcUref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQSnsList_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSnsList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSnsList::updateRst(
			ListWdbeQSnsList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQSnsList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSnsList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSnsList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSnsList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSnsList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSnsList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQSnsList::loadRecByQref(
			ubigint qref
			, WdbeQSnsList** rec
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

	return loadRecByStmt("TblWdbeQSnsList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQSnsList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSnsList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQSnsList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
