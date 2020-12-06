/**
	* \file WdbeQVecVec1NVectoritem.cpp
	* Dbs and XML wrapper for table TblWdbeQVecVec1NVectoritem (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQVecVec1NVectoritem.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQVecVec1NVectoritem
 ******************************************************************************/

WdbeQVecVec1NVectoritem::WdbeQVecVec1NVectoritem(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint vecNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->vecNum = vecNum;
};

void WdbeQVecVec1NVectoritem::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQVecVec1NVectoritem";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQVecVec1NVectoritem
 ******************************************************************************/

ListWdbeQVecVec1NVectoritem::ListWdbeQVecVec1NVectoritem() {
};

ListWdbeQVecVec1NVectoritem::ListWdbeQVecVec1NVectoritem(
			const ListWdbeQVecVec1NVectoritem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQVecVec1NVectoritem(*(src.nodes[i]));
};

ListWdbeQVecVec1NVectoritem::~ListWdbeQVecVec1NVectoritem() {
	clear();
};

void ListWdbeQVecVec1NVectoritem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQVecVec1NVectoritem::size() const {
	return(nodes.size());
};

void ListWdbeQVecVec1NVectoritem::append(
			WdbeQVecVec1NVectoritem* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQVecVec1NVectoritem& ListWdbeQVecVec1NVectoritem::operator=(
			const ListWdbeQVecVec1NVectoritem& src
		) {
	WdbeQVecVec1NVectoritem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQVecVec1NVectoritem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQVecVec1NVectoritem::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQVecVec1NVectoritem";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQVecVec1NVectoritem
 ******************************************************************************/

TblWdbeQVecVec1NVectoritem::TblWdbeQVecVec1NVectoritem() {
};

TblWdbeQVecVec1NVectoritem::~TblWdbeQVecVec1NVectoritem() {
};

bool TblWdbeQVecVec1NVectoritem::loadRecBySQL(
			const string& sqlstr
			, WdbeQVecVec1NVectoritem** rec
		) {
	return false;
};

ubigint TblWdbeQVecVec1NVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQVecVec1NVectoritem& rst
		) {
	return 0;
};

ubigint TblWdbeQVecVec1NVectoritem::insertRec(
			WdbeQVecVec1NVectoritem* rec
		) {
	return 0;
};

ubigint TblWdbeQVecVec1NVectoritem::insertNewRec(
			WdbeQVecVec1NVectoritem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint vecNum
		) {
	ubigint retval = 0;
	WdbeQVecVec1NVectoritem* _rec = NULL;

	_rec = new WdbeQVecVec1NVectoritem(0, jref, jnum, ref, stubRef, vecNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQVecVec1NVectoritem::appendNewRecToRst(
			ListWdbeQVecVec1NVectoritem& rst
			, WdbeQVecVec1NVectoritem** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint vecNum
		) {
	ubigint retval = 0;
	WdbeQVecVec1NVectoritem* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, vecNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQVecVec1NVectoritem::insertRst(
			ListWdbeQVecVec1NVectoritem& rst
		) {
};

void TblWdbeQVecVec1NVectoritem::updateRec(
			WdbeQVecVec1NVectoritem* rec
		) {
};

void TblWdbeQVecVec1NVectoritem::updateRst(
			ListWdbeQVecVec1NVectoritem& rst
		) {
};

void TblWdbeQVecVec1NVectoritem::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQVecVec1NVectoritem::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQVecVec1NVectoritem::loadRecByQref(
			ubigint qref
			, WdbeQVecVec1NVectoritem** rec
		) {
	return false;
};

ubigint TblWdbeQVecVec1NVectoritem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQVecVec1NVectoritem& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQVecVec1NVectoritem
 ******************************************************************************/

MyTblWdbeQVecVec1NVectoritem::MyTblWdbeQVecVec1NVectoritem() :
			TblWdbeQVecVec1NVectoritem()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQVecVec1NVectoritem::~MyTblWdbeQVecVec1NVectoritem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQVecVec1NVectoritem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQVecVec1NVectoritem (jref, jnum, ref, vecNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQVecVec1NVectoritem SET jref = ?, jnum = ?, ref = ?, vecNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQVecVec1NVectoritem WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQVecVec1NVectoritem WHERE jref = ?", false);
};

bool MyTblWdbeQVecVec1NVectoritem::loadRecBySQL(
			const string& sqlstr
			, WdbeQVecVec1NVectoritem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQVecVec1NVectoritem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQVecVec1NVectoritem();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->vecNum = atol((char*) dbrow[4]); else _rec->vecNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQVecVec1NVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQVecVec1NVectoritem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQVecVec1NVectoritem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQVecVec1NVectoritem();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->vecNum = atol((char*) dbrow[4]); else rec->vecNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQVecVec1NVectoritem::insertRec(
			WdbeQVecVec1NVectoritem* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->vecNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQVecVec1NVectoritem::insertRst(
			ListWdbeQVecVec1NVectoritem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQVecVec1NVectoritem::updateRec(
			WdbeQVecVec1NVectoritem* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->vecNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQVecVec1NVectoritem::updateRst(
			ListWdbeQVecVec1NVectoritem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQVecVec1NVectoritem::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQVecVec1NVectoritem::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQVecVec1NVectoritem::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQVecVec1NVectoritem::loadRecByQref(
			ubigint qref
			, WdbeQVecVec1NVectoritem** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQVecVec1NVectoritem WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQVecVec1NVectoritem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQVecVec1NVectoritem& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQVecVec1NVectoritem WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQVecVec1NVectoritem
 ******************************************************************************/

PgTblWdbeQVecVec1NVectoritem::PgTblWdbeQVecVec1NVectoritem() :
			TblWdbeQVecVec1NVectoritem()
			, PgTable()
		{
};

PgTblWdbeQVecVec1NVectoritem::~PgTblWdbeQVecVec1NVectoritem() {
};

void PgTblWdbeQVecVec1NVectoritem::initStatements() {
	createStatement("TblWdbeQVecVec1NVectoritem_insertRec", "INSERT INTO TblWdbeQVecVec1NVectoritem (jref, jnum, ref, vecNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWdbeQVecVec1NVectoritem_updateRec", "UPDATE TblWdbeQVecVec1NVectoritem SET jref = $1, jnum = $2, ref = $3, vecNum = $4 WHERE qref = $5", 5);
	createStatement("TblWdbeQVecVec1NVectoritem_removeRecByQref", "DELETE FROM TblWdbeQVecVec1NVectoritem WHERE qref = $1", 1);
	createStatement("TblWdbeQVecVec1NVectoritem_removeRstByJref", "DELETE FROM TblWdbeQVecVec1NVectoritem WHERE jref = $1", 1);

	createStatement("TblWdbeQVecVec1NVectoritem_loadRecByQref", "SELECT qref, jref, jnum, ref, vecNum FROM TblWdbeQVecVec1NVectoritem WHERE qref = $1", 1);
	createStatement("TblWdbeQVecVec1NVectoritem_loadRstByJref", "SELECT qref, jref, jnum, ref, vecNum FROM TblWdbeQVecVec1NVectoritem WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQVecVec1NVectoritem::loadRec(
			PGresult* res
			, WdbeQVecVec1NVectoritem** rec
		) {
	char* ptr;

	WdbeQVecVec1NVectoritem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQVecVec1NVectoritem();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "vecnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->vecNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQVecVec1NVectoritem::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQVecVec1NVectoritem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQVecVec1NVectoritem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "vecnum")
		};

		while (numread < numrow) {
			rec = new WdbeQVecVec1NVectoritem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->vecNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQVecVec1NVectoritem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQVecVec1NVectoritem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQVecVec1NVectoritem::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQVecVec1NVectoritem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQVecVec1NVectoritem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQVecVec1NVectoritem::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQVecVec1NVectoritem::loadRecBySQL(
			const string& sqlstr
			, WdbeQVecVec1NVectoritem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQVecVec1NVectoritem::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQVecVec1NVectoritem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQVecVec1NVectoritem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQVecVec1NVectoritem::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQVecVec1NVectoritem::insertRec(
			WdbeQVecVec1NVectoritem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _vecNum = htonl(rec->vecNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_vecNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQVecVec1NVectoritem_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQVecVec1NVectoritem::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQVecVec1NVectoritem::insertRst(
			ListWdbeQVecVec1NVectoritem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQVecVec1NVectoritem::updateRec(
			WdbeQVecVec1NVectoritem* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _vecNum = htonl(rec->vecNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_vecNum,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQVecVec1NVectoritem_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQVecVec1NVectoritem::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQVecVec1NVectoritem::updateRst(
			ListWdbeQVecVec1NVectoritem& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQVecVec1NVectoritem::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQVecVec1NVectoritem_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQVecVec1NVectoritem::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQVecVec1NVectoritem::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQVecVec1NVectoritem_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQVecVec1NVectoritem::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQVecVec1NVectoritem::loadRecByQref(
			ubigint qref
			, WdbeQVecVec1NVectoritem** rec
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

	return loadRecByStmt("TblWdbeQVecVec1NVectoritem_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQVecVec1NVectoritem::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQVecVec1NVectoritem& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQVecVec1NVectoritem_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
