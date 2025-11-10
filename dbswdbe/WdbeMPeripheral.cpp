/**
	* \file WdbeMPeripheral.cpp
	* database access for table TblWdbeMPeripheral (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMPeripheral.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMPeripheral
 ******************************************************************************/

WdbeMPeripheral::WdbeMPeripheral(
			const ubigint ref
			, const ubigint refWdbeMUnit
			, const string sref
			, const string Comment
		) :
			ref(ref)
			, refWdbeMUnit(refWdbeMUnit)
			, sref(sref)
			, Comment(Comment)
		{
};

bool WdbeMPeripheral::operator==(
			const WdbeMPeripheral& comp
		) {
	return false;
};

bool WdbeMPeripheral::operator!=(
			const WdbeMPeripheral& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMPeripheral
 ******************************************************************************/

ListWdbeMPeripheral::ListWdbeMPeripheral() {
};

ListWdbeMPeripheral::ListWdbeMPeripheral(
			const ListWdbeMPeripheral& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMPeripheral(*(src.nodes[i]));
};

ListWdbeMPeripheral::~ListWdbeMPeripheral() {
	clear();
};

void ListWdbeMPeripheral::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMPeripheral::size() const {
	return(nodes.size());
};

void ListWdbeMPeripheral::append(
			WdbeMPeripheral* rec
		) {
	nodes.push_back(rec);
};

WdbeMPeripheral* ListWdbeMPeripheral::operator[](
			const uint ix
		) {
	WdbeMPeripheral* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMPeripheral& ListWdbeMPeripheral::operator=(
			const ListWdbeMPeripheral& src
		) {
	WdbeMPeripheral* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMPeripheral(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMPeripheral::operator==(
			const ListWdbeMPeripheral& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListWdbeMPeripheral::operator!=(
			const ListWdbeMPeripheral& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMPeripheral
 ******************************************************************************/

TblWdbeMPeripheral::TblWdbeMPeripheral() {
};

TblWdbeMPeripheral::~TblWdbeMPeripheral() {
};

bool TblWdbeMPeripheral::loadRecBySQL(
			const string& sqlstr
			, WdbeMPeripheral** rec
		) {
	return false;
};

ubigint TblWdbeMPeripheral::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPeripheral& rst
		) {
	return 0;
};

ubigint TblWdbeMPeripheral::insertRec(
			WdbeMPeripheral* rec
		) {
	return 0;
};

ubigint TblWdbeMPeripheral::insertNewRec(
			WdbeMPeripheral** rec
			, const ubigint refWdbeMUnit
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMPeripheral* _rec = NULL;

	_rec = new WdbeMPeripheral(0, refWdbeMUnit, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMPeripheral::appendNewRecToRst(
			ListWdbeMPeripheral& rst
			, WdbeMPeripheral** rec
			, const ubigint refWdbeMUnit
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMPeripheral* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMUnit, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMPeripheral::insertRst(
			ListWdbeMPeripheral& rst
			, bool transact
		) {
};

void TblWdbeMPeripheral::updateRec(
			WdbeMPeripheral* rec
		) {
};

void TblWdbeMPeripheral::updateRst(
			ListWdbeMPeripheral& rst
			, bool transact
		) {
};

void TblWdbeMPeripheral::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMPeripheral::loadRecByRef(
			ubigint ref
			, WdbeMPeripheral** rec
		) {
	return false;
};

ubigint TblWdbeMPeripheral::loadRefsByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMPeripheral::loadRstByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, ListWdbeMPeripheral& rst
		) {
	return 0;
};

bool TblWdbeMPeripheral::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMPeripheral::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMPeripheral& rst
		) {
	ubigint numload = 0;
	WdbeMPeripheral* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMPeripheral
 ******************************************************************************/

MyTblWdbeMPeripheral::MyTblWdbeMPeripheral() :
			TblWdbeMPeripheral()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMPeripheral::~MyTblWdbeMPeripheral() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMPeripheral::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMPeripheral (refWdbeMUnit, sref, Comment) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMPeripheral SET refWdbeMUnit = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMPeripheral WHERE ref = ?", false);
};

bool MyTblWdbeMPeripheral::loadRecBySQL(
			const string& sqlstr
			, WdbeMPeripheral** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMPeripheral* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMPeripheral::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMPeripheral::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMPeripheral();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMUnit = atoll((char*) dbrow[1]); else _rec->refWdbeMUnit = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->Comment.assign(dbrow[3], dblengths[3]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMPeripheral::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPeripheral& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMPeripheral* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMPeripheral::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMPeripheral::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMPeripheral();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMUnit = atoll((char*) dbrow[1]); else rec->refWdbeMUnit = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->Comment.assign(dbrow[3], dblengths[3]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMPeripheral::insertRec(
			WdbeMPeripheral* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->sref.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUnit,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMPeripheral::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMPeripheral::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMPeripheral::insertRst(
			ListWdbeMPeripheral& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMPeripheral::updateRec(
			WdbeMPeripheral* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->sref.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUnit,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMPeripheral::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMPeripheral::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMPeripheral::updateRst(
			ListWdbeMPeripheral& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMPeripheral::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMPeripheral::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMPeripheral::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMPeripheral::loadRecByRef(
			ubigint ref
			, WdbeMPeripheral** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMPeripheral WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMPeripheral::loadRefsByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMPeripheral WHERE refWdbeMUnit = " + to_string(refWdbeMUnit) + "", append, refs);
};

ubigint MyTblWdbeMPeripheral::loadRstByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, ListWdbeMPeripheral& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMUnit, sref, Comment FROM TblWdbeMPeripheral WHERE refWdbeMUnit = " + to_string(refWdbeMUnit) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMPeripheral::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMPeripheral WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMPeripheral
 ******************************************************************************/

PgTblWdbeMPeripheral::PgTblWdbeMPeripheral() :
			TblWdbeMPeripheral()
			, PgTable()
		{
};

PgTblWdbeMPeripheral::~PgTblWdbeMPeripheral() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMPeripheral::initStatements() {
	createStatement("TblWdbeMPeripheral_insertRec", "INSERT INTO TblWdbeMPeripheral (refWdbeMUnit, sref, Comment) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeMPeripheral_updateRec", "UPDATE TblWdbeMPeripheral SET refWdbeMUnit = $1, sref = $2, Comment = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeMPeripheral_removeRecByRef", "DELETE FROM TblWdbeMPeripheral WHERE ref = $1", 1);

	createStatement("TblWdbeMPeripheral_loadRecByRef", "SELECT ref, refWdbeMUnit, sref, Comment FROM TblWdbeMPeripheral WHERE ref = $1", 1);
	createStatement("TblWdbeMPeripheral_loadRefsByUnt", "SELECT ref FROM TblWdbeMPeripheral WHERE refWdbeMUnit = $1", 1);
	createStatement("TblWdbeMPeripheral_loadRstByUnt", "SELECT ref, refWdbeMUnit, sref, Comment FROM TblWdbeMPeripheral WHERE refWdbeMUnit = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMPeripheral_loadSrfByRef", "SELECT sref FROM TblWdbeMPeripheral WHERE ref = $1", 1);
};

bool PgTblWdbeMPeripheral::loadRec(
			PGresult* res
			, WdbeMPeripheral** rec
		) {
	char* ptr;

	WdbeMPeripheral* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMPeripheral();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemunit"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMUnit = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMPeripheral::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMPeripheral& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMPeripheral* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemunit"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMPeripheral();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMUnit = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMPeripheral::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMPeripheral** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPeripheral::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMPeripheral::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMPeripheral& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPeripheral::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMPeripheral::loadRecBySQL(
			const string& sqlstr
			, WdbeMPeripheral** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPeripheral::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMPeripheral::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPeripheral& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPeripheral::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMPeripheral::insertRec(
			WdbeMPeripheral* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);

	const char* vals[] = {
		(char*) &_refWdbeMUnit,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMPeripheral_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPeripheral::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMPeripheral::insertRst(
			ListWdbeMPeripheral& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMPeripheral::updateRec(
			WdbeMPeripheral* rec
		) {
	PGresult* res;

	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMUnit,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMPeripheral_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMPeripheral::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMPeripheral::updateRst(
			ListWdbeMPeripheral& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMPeripheral::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWdbeMPeripheral_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMPeripheral::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMPeripheral::loadRecByRef(
			ubigint ref
			, WdbeMPeripheral** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMPeripheral_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMPeripheral::loadRefsByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMUnit = htonl64(refWdbeMUnit);

	const char* vals[] = {
		(char*) &_refWdbeMUnit
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMPeripheral_loadRefsByUnt", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMPeripheral::loadRstByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, ListWdbeMPeripheral& rst
		) {
	ubigint _refWdbeMUnit = htonl64(refWdbeMUnit);

	const char* vals[] = {
		(char*) &_refWdbeMUnit
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMPeripheral_loadRstByUnt", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMPeripheral::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMPeripheral_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
