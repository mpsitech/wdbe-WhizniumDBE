/**
	* \file WdbeQPrcPrc1NVariable.cpp
	* Dbs and XML wrapper for table TblWdbeQPrcPrc1NVariable (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQPrcPrc1NVariable.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrcPrc1NVariable
 ******************************************************************************/

WdbeQPrcPrc1NVariable::WdbeQPrcPrc1NVariable(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint prcNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->prcNum = prcNum;
};

void WdbeQPrcPrc1NVariable::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQPrcPrc1NVariable";

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
 class ListWdbeQPrcPrc1NVariable
 ******************************************************************************/

ListWdbeQPrcPrc1NVariable::ListWdbeQPrcPrc1NVariable() {
};

ListWdbeQPrcPrc1NVariable::ListWdbeQPrcPrc1NVariable(
			const ListWdbeQPrcPrc1NVariable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcPrc1NVariable(*(src.nodes[i]));
};

ListWdbeQPrcPrc1NVariable::~ListWdbeQPrcPrc1NVariable() {
	clear();
};

void ListWdbeQPrcPrc1NVariable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQPrcPrc1NVariable::size() const {
	return(nodes.size());
};

void ListWdbeQPrcPrc1NVariable::append(
			WdbeQPrcPrc1NVariable* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQPrcPrc1NVariable& ListWdbeQPrcPrc1NVariable::operator=(
			const ListWdbeQPrcPrc1NVariable& src
		) {
	WdbeQPrcPrc1NVariable* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQPrcPrc1NVariable(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQPrcPrc1NVariable::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQPrcPrc1NVariable";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQPrcPrc1NVariable
 ******************************************************************************/

TblWdbeQPrcPrc1NVariable::TblWdbeQPrcPrc1NVariable() {
};

TblWdbeQPrcPrc1NVariable::~TblWdbeQPrcPrc1NVariable() {
};

bool TblWdbeQPrcPrc1NVariable::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrcPrc1NVariable** rec
		) {
	return false;
};

ubigint TblWdbeQPrcPrc1NVariable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrcPrc1NVariable& rst
		) {
	return 0;
};

ubigint TblWdbeQPrcPrc1NVariable::insertRec(
			WdbeQPrcPrc1NVariable* rec
		) {
	return 0;
};

ubigint TblWdbeQPrcPrc1NVariable::insertNewRec(
			WdbeQPrcPrc1NVariable** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint prcNum
		) {
	ubigint retval = 0;
	WdbeQPrcPrc1NVariable* _rec = NULL;

	_rec = new WdbeQPrcPrc1NVariable(0, jref, jnum, ref, stubRef, prcNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQPrcPrc1NVariable::appendNewRecToRst(
			ListWdbeQPrcPrc1NVariable& rst
			, WdbeQPrcPrc1NVariable** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint prcNum
		) {
	ubigint retval = 0;
	WdbeQPrcPrc1NVariable* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, prcNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQPrcPrc1NVariable::insertRst(
			ListWdbeQPrcPrc1NVariable& rst
		) {
};

void TblWdbeQPrcPrc1NVariable::updateRec(
			WdbeQPrcPrc1NVariable* rec
		) {
};

void TblWdbeQPrcPrc1NVariable::updateRst(
			ListWdbeQPrcPrc1NVariable& rst
		) {
};

void TblWdbeQPrcPrc1NVariable::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQPrcPrc1NVariable::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQPrcPrc1NVariable::loadRecByQref(
			ubigint qref
			, WdbeQPrcPrc1NVariable** rec
		) {
	return false;
};

ubigint TblWdbeQPrcPrc1NVariable::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrcPrc1NVariable& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQPrcPrc1NVariable
 ******************************************************************************/

MyTblWdbeQPrcPrc1NVariable::MyTblWdbeQPrcPrc1NVariable() :
			TblWdbeQPrcPrc1NVariable()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQPrcPrc1NVariable::~MyTblWdbeQPrcPrc1NVariable() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQPrcPrc1NVariable::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQPrcPrc1NVariable (jref, jnum, ref, prcNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQPrcPrc1NVariable SET jref = ?, jnum = ?, ref = ?, prcNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQPrcPrc1NVariable WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQPrcPrc1NVariable WHERE jref = ?", false);
};

bool MyTblWdbeQPrcPrc1NVariable::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrcPrc1NVariable** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQPrcPrc1NVariable* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQPrcPrc1NVariable();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->prcNum = atol((char*) dbrow[4]); else _rec->prcNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQPrcPrc1NVariable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrcPrc1NVariable& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQPrcPrc1NVariable* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQPrcPrc1NVariable();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->prcNum = atol((char*) dbrow[4]); else rec->prcNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQPrcPrc1NVariable::insertRec(
			WdbeQPrcPrc1NVariable* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->prcNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQPrcPrc1NVariable::insertRst(
			ListWdbeQPrcPrc1NVariable& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQPrcPrc1NVariable::updateRec(
			WdbeQPrcPrc1NVariable* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->prcNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrcPrc1NVariable::updateRst(
			ListWdbeQPrcPrc1NVariable& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQPrcPrc1NVariable::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrcPrc1NVariable::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQPrcPrc1NVariable::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQPrcPrc1NVariable::loadRecByQref(
			ubigint qref
			, WdbeQPrcPrc1NVariable** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQPrcPrc1NVariable WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQPrcPrc1NVariable::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrcPrc1NVariable& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQPrcPrc1NVariable WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQPrcPrc1NVariable
 ******************************************************************************/

PgTblWdbeQPrcPrc1NVariable::PgTblWdbeQPrcPrc1NVariable() :
			TblWdbeQPrcPrc1NVariable()
			, PgTable()
		{
};

PgTblWdbeQPrcPrc1NVariable::~PgTblWdbeQPrcPrc1NVariable() {
};

void PgTblWdbeQPrcPrc1NVariable::initStatements() {
	createStatement("TblWdbeQPrcPrc1NVariable_insertRec", "INSERT INTO TblWdbeQPrcPrc1NVariable (jref, jnum, ref, prcNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWdbeQPrcPrc1NVariable_updateRec", "UPDATE TblWdbeQPrcPrc1NVariable SET jref = $1, jnum = $2, ref = $3, prcNum = $4 WHERE qref = $5", 5);
	createStatement("TblWdbeQPrcPrc1NVariable_removeRecByQref", "DELETE FROM TblWdbeQPrcPrc1NVariable WHERE qref = $1", 1);
	createStatement("TblWdbeQPrcPrc1NVariable_removeRstByJref", "DELETE FROM TblWdbeQPrcPrc1NVariable WHERE jref = $1", 1);

	createStatement("TblWdbeQPrcPrc1NVariable_loadRecByQref", "SELECT qref, jref, jnum, ref, prcNum FROM TblWdbeQPrcPrc1NVariable WHERE qref = $1", 1);
	createStatement("TblWdbeQPrcPrc1NVariable_loadRstByJref", "SELECT qref, jref, jnum, ref, prcNum FROM TblWdbeQPrcPrc1NVariable WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQPrcPrc1NVariable::loadRec(
			PGresult* res
			, WdbeQPrcPrc1NVariable** rec
		) {
	char* ptr;

	WdbeQPrcPrc1NVariable* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQPrcPrc1NVariable();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "prcnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->prcNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQPrcPrc1NVariable::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQPrcPrc1NVariable& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQPrcPrc1NVariable* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "prcnum")
		};

		while (numread < numrow) {
			rec = new WdbeQPrcPrc1NVariable();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->prcNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQPrcPrc1NVariable::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQPrcPrc1NVariable** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrcPrc1NVariable::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrcPrc1NVariable::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQPrcPrc1NVariable& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrcPrc1NVariable::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQPrcPrc1NVariable::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrcPrc1NVariable** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrcPrc1NVariable::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrcPrc1NVariable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrcPrc1NVariable& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrcPrc1NVariable::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQPrcPrc1NVariable::insertRec(
			WdbeQPrcPrc1NVariable* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _prcNum = htonl(rec->prcNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_prcNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQPrcPrc1NVariable_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrcPrc1NVariable::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQPrcPrc1NVariable::insertRst(
			ListWdbeQPrcPrc1NVariable& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQPrcPrc1NVariable::updateRec(
			WdbeQPrcPrc1NVariable* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _prcNum = htonl(rec->prcNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_prcNum,
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

	res = PQexecPrepared(dbs, "TblWdbeQPrcPrc1NVariable_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrcPrc1NVariable::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrcPrc1NVariable::updateRst(
			ListWdbeQPrcPrc1NVariable& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQPrcPrc1NVariable::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrcPrc1NVariable_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrcPrc1NVariable::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrcPrc1NVariable::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrcPrc1NVariable_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrcPrc1NVariable::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQPrcPrc1NVariable::loadRecByQref(
			ubigint qref
			, WdbeQPrcPrc1NVariable** rec
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

	return loadRecByStmt("TblWdbeQPrcPrc1NVariable_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQPrcPrc1NVariable::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrcPrc1NVariable& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQPrcPrc1NVariable_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

