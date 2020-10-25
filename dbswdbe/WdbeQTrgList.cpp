/**
	* \file WdbeQTrgList.cpp
	* Dbs and XML wrapper for table TblWdbeQTrgList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQTrgList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQTrgList
 ******************************************************************************/

WdbeQTrgList::WdbeQTrgList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint sysRefWdbeMSystem
			, const string stubSysRefWdbeMSystem
			, const ubigint refWdbeMUnit
			, const string stubRefWdbeMUnit
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->sysRefWdbeMSystem = sysRefWdbeMSystem;
	this->stubSysRefWdbeMSystem = stubSysRefWdbeMSystem;
	this->refWdbeMUnit = refWdbeMUnit;
	this->stubRefWdbeMUnit = stubRefWdbeMUnit;
};

void WdbeQTrgList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQTrgList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "sys", stubSysRefWdbeMSystem);
		writeString(wr, "unt", stubRefWdbeMUnit);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubSysRefWdbeMSystem", stubSysRefWdbeMSystem);
		writeString(wr, "stubRefWdbeMUnit", stubRefWdbeMUnit);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQTrgList
 ******************************************************************************/

ListWdbeQTrgList::ListWdbeQTrgList() {
};

ListWdbeQTrgList::ListWdbeQTrgList(
			const ListWdbeQTrgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQTrgList(*(src.nodes[i]));
};

ListWdbeQTrgList::~ListWdbeQTrgList() {
	clear();
};

void ListWdbeQTrgList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQTrgList::size() const {
	return(nodes.size());
};

void ListWdbeQTrgList::append(
			WdbeQTrgList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQTrgList& ListWdbeQTrgList::operator=(
			const ListWdbeQTrgList& src
		) {
	WdbeQTrgList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQTrgList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQTrgList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQTrgList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQTrgList
 ******************************************************************************/

TblWdbeQTrgList::TblWdbeQTrgList() {
};

TblWdbeQTrgList::~TblWdbeQTrgList() {
};

bool TblWdbeQTrgList::loadRecBySQL(
			const string& sqlstr
			, WdbeQTrgList** rec
		) {
	return false;
};

ubigint TblWdbeQTrgList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQTrgList& rst
		) {
	return 0;
};

ubigint TblWdbeQTrgList::insertRec(
			WdbeQTrgList* rec
		) {
	return 0;
};

ubigint TblWdbeQTrgList::insertNewRec(
			WdbeQTrgList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint sysRefWdbeMSystem
			, const string stubSysRefWdbeMSystem
			, const ubigint refWdbeMUnit
			, const string stubRefWdbeMUnit
		) {
	ubigint retval = 0;
	WdbeQTrgList* _rec = NULL;

	_rec = new WdbeQTrgList(0, jref, jnum, ref, sref, sysRefWdbeMSystem, stubSysRefWdbeMSystem, refWdbeMUnit, stubRefWdbeMUnit);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQTrgList::appendNewRecToRst(
			ListWdbeQTrgList& rst
			, WdbeQTrgList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint sysRefWdbeMSystem
			, const string stubSysRefWdbeMSystem
			, const ubigint refWdbeMUnit
			, const string stubRefWdbeMUnit
		) {
	ubigint retval = 0;
	WdbeQTrgList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, sysRefWdbeMSystem, stubSysRefWdbeMSystem, refWdbeMUnit, stubRefWdbeMUnit);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQTrgList::insertRst(
			ListWdbeQTrgList& rst
		) {
};

void TblWdbeQTrgList::updateRec(
			WdbeQTrgList* rec
		) {
};

void TblWdbeQTrgList::updateRst(
			ListWdbeQTrgList& rst
		) {
};

void TblWdbeQTrgList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQTrgList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQTrgList::loadRecByQref(
			ubigint qref
			, WdbeQTrgList** rec
		) {
	return false;
};

ubigint TblWdbeQTrgList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQTrgList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQTrgList
 ******************************************************************************/

MyTblWdbeQTrgList::MyTblWdbeQTrgList() :
			TblWdbeQTrgList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQTrgList::~MyTblWdbeQTrgList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQTrgList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQTrgList (jref, jnum, ref, sref, sysRefWdbeMSystem, refWdbeMUnit) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQTrgList SET jref = ?, jnum = ?, ref = ?, sref = ?, sysRefWdbeMSystem = ?, refWdbeMUnit = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQTrgList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQTrgList WHERE jref = ?", false);
};

bool MyTblWdbeQTrgList::loadRecBySQL(
			const string& sqlstr
			, WdbeQTrgList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQTrgList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQTrgList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQTrgList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQTrgList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->sysRefWdbeMSystem = atoll((char*) dbrow[5]); else _rec->sysRefWdbeMSystem = 0;
		if (dbrow[6]) _rec->refWdbeMUnit = atoll((char*) dbrow[6]); else _rec->refWdbeMUnit = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQTrgList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQTrgList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQTrgList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQTrgList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQTrgList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQTrgList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->sysRefWdbeMSystem = atoll((char*) dbrow[5]); else rec->sysRefWdbeMSystem = 0;
			if (dbrow[6]) rec->refWdbeMUnit = atoll((char*) dbrow[6]); else rec->refWdbeMUnit = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQTrgList::insertRec(
			WdbeQTrgList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->sysRefWdbeMSystem,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWdbeMUnit,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQTrgList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQTrgList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQTrgList::insertRst(
			ListWdbeQTrgList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQTrgList::updateRec(
			WdbeQTrgList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->sysRefWdbeMSystem,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWdbeMUnit,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQTrgList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQTrgList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQTrgList::updateRst(
			ListWdbeQTrgList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQTrgList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQTrgList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQTrgList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQTrgList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQTrgList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQTrgList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQTrgList::loadRecByQref(
			ubigint qref
			, WdbeQTrgList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQTrgList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQTrgList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQTrgList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQTrgList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQTrgList
 ******************************************************************************/

PgTblWdbeQTrgList::PgTblWdbeQTrgList() :
			TblWdbeQTrgList()
			, PgTable()
		{
};

PgTblWdbeQTrgList::~PgTblWdbeQTrgList() {
};

void PgTblWdbeQTrgList::initStatements() {
	createStatement("TblWdbeQTrgList_insertRec", "INSERT INTO TblWdbeQTrgList (jref, jnum, ref, sref, sysRefWdbeMSystem, refWdbeMUnit) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWdbeQTrgList_updateRec", "UPDATE TblWdbeQTrgList SET jref = $1, jnum = $2, ref = $3, sref = $4, sysRefWdbeMSystem = $5, refWdbeMUnit = $6 WHERE qref = $7", 7);
	createStatement("TblWdbeQTrgList_removeRecByQref", "DELETE FROM TblWdbeQTrgList WHERE qref = $1", 1);
	createStatement("TblWdbeQTrgList_removeRstByJref", "DELETE FROM TblWdbeQTrgList WHERE jref = $1", 1);

	createStatement("TblWdbeQTrgList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, sysRefWdbeMSystem, refWdbeMUnit FROM TblWdbeQTrgList WHERE qref = $1", 1);
	createStatement("TblWdbeQTrgList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, sysRefWdbeMSystem, refWdbeMUnit FROM TblWdbeQTrgList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQTrgList::loadRec(
			PGresult* res
			, WdbeQTrgList** rec
		) {
	char* ptr;

	WdbeQTrgList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQTrgList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "sysrefwdbemsystem"),
			PQfnumber(res, "refwdbemunit")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sysRefWdbeMSystem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWdbeMUnit = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQTrgList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQTrgList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQTrgList* rec;

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
			PQfnumber(res, "sysrefwdbemsystem"),
			PQfnumber(res, "refwdbemunit")
		};

		while (numread < numrow) {
			rec = new WdbeQTrgList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sysRefWdbeMSystem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWdbeMUnit = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQTrgList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQTrgList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQTrgList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQTrgList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQTrgList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQTrgList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQTrgList::loadRecBySQL(
			const string& sqlstr
			, WdbeQTrgList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQTrgList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQTrgList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQTrgList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQTrgList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQTrgList::insertRec(
			WdbeQTrgList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _sysRefWdbeMSystem = htonl64(rec->sysRefWdbeMSystem);
	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_sysRefWdbeMSystem,
		(char*) &_refWdbeMUnit
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQTrgList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQTrgList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQTrgList::insertRst(
			ListWdbeQTrgList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQTrgList::updateRec(
			WdbeQTrgList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _sysRefWdbeMSystem = htonl64(rec->sysRefWdbeMSystem);
	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_sysRefWdbeMSystem,
		(char*) &_refWdbeMUnit,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQTrgList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQTrgList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQTrgList::updateRst(
			ListWdbeQTrgList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQTrgList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQTrgList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQTrgList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQTrgList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQTrgList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQTrgList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQTrgList::loadRecByQref(
			ubigint qref
			, WdbeQTrgList** rec
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

	return loadRecByStmt("TblWdbeQTrgList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQTrgList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQTrgList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQTrgList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

