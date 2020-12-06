/**
	* \file WdbeMSystem.cpp
	* database access for table TblWdbeMSystem (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMSystem.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMSystem
 ******************************************************************************/

WdbeMSystem::WdbeMSystem(
			const ubigint ref
			, const ubigint refWdbeMVersion
			, const ubigint refWdbeMUnit
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->refWdbeMVersion = refWdbeMVersion;
	this->refWdbeMUnit = refWdbeMUnit;
	this->sref = sref;
	this->Comment = Comment;
};

bool WdbeMSystem::operator==(
			const WdbeMSystem& comp
		) {
	return false;
};

bool WdbeMSystem::operator!=(
			const WdbeMSystem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMSystem
 ******************************************************************************/

ListWdbeMSystem::ListWdbeMSystem() {
};

ListWdbeMSystem::ListWdbeMSystem(
			const ListWdbeMSystem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMSystem(*(src.nodes[i]));
};

ListWdbeMSystem::~ListWdbeMSystem() {
	clear();
};

void ListWdbeMSystem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMSystem::size() const {
	return(nodes.size());
};

void ListWdbeMSystem::append(
			WdbeMSystem* rec
		) {
	nodes.push_back(rec);
};

WdbeMSystem* ListWdbeMSystem::operator[](
			const uint ix
		) {
	WdbeMSystem* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMSystem& ListWdbeMSystem::operator=(
			const ListWdbeMSystem& src
		) {
	WdbeMSystem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMSystem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMSystem::operator==(
			const ListWdbeMSystem& comp
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

bool ListWdbeMSystem::operator!=(
			const ListWdbeMSystem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMSystem
 ******************************************************************************/

TblWdbeMSystem::TblWdbeMSystem() {
};

TblWdbeMSystem::~TblWdbeMSystem() {
};

bool TblWdbeMSystem::loadRecBySQL(
			const string& sqlstr
			, WdbeMSystem** rec
		) {
	return false;
};

ubigint TblWdbeMSystem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSystem& rst
		) {
	return 0;
};

ubigint TblWdbeMSystem::insertRec(
			WdbeMSystem* rec
		) {
	return 0;
};

ubigint TblWdbeMSystem::insertNewRec(
			WdbeMSystem** rec
			, const ubigint refWdbeMVersion
			, const ubigint refWdbeMUnit
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMSystem* _rec = NULL;

	_rec = new WdbeMSystem(0, refWdbeMVersion, refWdbeMUnit, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMSystem::appendNewRecToRst(
			ListWdbeMSystem& rst
			, WdbeMSystem** rec
			, const ubigint refWdbeMVersion
			, const ubigint refWdbeMUnit
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMSystem* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMVersion, refWdbeMUnit, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMSystem::insertRst(
			ListWdbeMSystem& rst
			, bool transact
		) {
};

void TblWdbeMSystem::updateRec(
			WdbeMSystem* rec
		) {
};

void TblWdbeMSystem::updateRst(
			ListWdbeMSystem& rst
			, bool transact
		) {
};

void TblWdbeMSystem::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMSystem::loadRecByRef(
			ubigint ref
			, WdbeMSystem** rec
		) {
	return false;
};

bool TblWdbeMSystem::loadRecByUnt(
			ubigint refWdbeMUnit
			, WdbeMSystem** rec
		) {
	return false;
};

ubigint TblWdbeMSystem::loadRstByVer(
			ubigint refWdbeMVersion
			, const bool append
			, ListWdbeMSystem& rst
		) {
	return 0;
};

bool TblWdbeMSystem::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMSystem::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMSystem& rst
		) {
	ubigint numload = 0;
	WdbeMSystem* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMSystem
 ******************************************************************************/

MyTblWdbeMSystem::MyTblWdbeMSystem() :
			TblWdbeMSystem()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMSystem::~MyTblWdbeMSystem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMSystem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMSystem (refWdbeMVersion, refWdbeMUnit, sref, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMSystem SET refWdbeMVersion = ?, refWdbeMUnit = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMSystem WHERE ref = ?", false);
};

bool MyTblWdbeMSystem::loadRecBySQL(
			const string& sqlstr
			, WdbeMSystem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMSystem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMSystem::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMSystem::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMSystem();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMVersion = atoll((char*) dbrow[1]); else _rec->refWdbeMVersion = 0;
		if (dbrow[2]) _rec->refWdbeMUnit = atoll((char*) dbrow[2]); else _rec->refWdbeMUnit = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMSystem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSystem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMSystem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMSystem::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMSystem::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMSystem();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMVersion = atoll((char*) dbrow[1]); else rec->refWdbeMVersion = 0;
			if (dbrow[2]) rec->refWdbeMUnit = atoll((char*) dbrow[2]); else rec->refWdbeMUnit = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMSystem::insertRec(
			WdbeMSystem* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMUnit,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMSystem::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMSystem::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMSystem::insertRst(
			ListWdbeMSystem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMSystem::updateRec(
			WdbeMSystem* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMVersion,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMUnit,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMSystem::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMSystem::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMSystem::updateRst(
			ListWdbeMSystem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMSystem::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMSystem::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMSystem::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMSystem::loadRecByRef(
			ubigint ref
			, WdbeMSystem** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMSystem WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMSystem::loadRecByUnt(
			ubigint refWdbeMUnit
			, WdbeMSystem** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMVersion, refWdbeMUnit, sref, Comment FROM TblWdbeMSystem WHERE refWdbeMUnit = " + to_string(refWdbeMUnit) + "", rec);
};

ubigint MyTblWdbeMSystem::loadRstByVer(
			ubigint refWdbeMVersion
			, const bool append
			, ListWdbeMSystem& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMVersion, refWdbeMUnit, sref, Comment FROM TblWdbeMSystem WHERE refWdbeMVersion = " + to_string(refWdbeMVersion) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMSystem::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMSystem WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMSystem
 ******************************************************************************/

PgTblWdbeMSystem::PgTblWdbeMSystem() :
			TblWdbeMSystem()
			, PgTable()
		{
};

PgTblWdbeMSystem::~PgTblWdbeMSystem() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMSystem::initStatements() {
	createStatement("TblWdbeMSystem_insertRec", "INSERT INTO TblWdbeMSystem (refWdbeMVersion, refWdbeMUnit, sref, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeMSystem_updateRec", "UPDATE TblWdbeMSystem SET refWdbeMVersion = $1, refWdbeMUnit = $2, sref = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeMSystem_removeRecByRef", "DELETE FROM TblWdbeMSystem WHERE ref = $1", 1);

	createStatement("TblWdbeMSystem_loadRecByRef", "SELECT ref, refWdbeMVersion, refWdbeMUnit, sref, Comment FROM TblWdbeMSystem WHERE ref = $1", 1);
	createStatement("TblWdbeMSystem_loadRecByUnt", "SELECT ref, refWdbeMVersion, refWdbeMUnit, sref, Comment FROM TblWdbeMSystem WHERE refWdbeMUnit = $1", 1);
	createStatement("TblWdbeMSystem_loadRstByVer", "SELECT ref, refWdbeMVersion, refWdbeMUnit, sref, Comment FROM TblWdbeMSystem WHERE refWdbeMVersion = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMSystem_loadSrfByRef", "SELECT sref FROM TblWdbeMSystem WHERE ref = $1", 1);
};

bool PgTblWdbeMSystem::loadRec(
			PGresult* res
			, WdbeMSystem** rec
		) {
	char* ptr;

	WdbeMSystem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMSystem();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemversion"),
			PQfnumber(res, "refwdbemunit"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMUnit = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMSystem::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMSystem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMSystem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemversion"),
			PQfnumber(res, "refwdbemunit"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMSystem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMUnit = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMSystem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMSystem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSystem::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMSystem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMSystem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSystem::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMSystem::loadRecBySQL(
			const string& sqlstr
			, WdbeMSystem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSystem::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMSystem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSystem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSystem::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMSystem::insertRec(
			WdbeMSystem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);
	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);

	const char* vals[] = {
		(char*) &_refWdbeMVersion,
		(char*) &_refWdbeMUnit,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMSystem_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSystem::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMSystem::insertRst(
			ListWdbeMSystem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMSystem::updateRec(
			WdbeMSystem* rec
		) {
	PGresult* res;

	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);
	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMVersion,
		(char*) &_refWdbeMUnit,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMSystem_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMSystem::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMSystem::updateRst(
			ListWdbeMSystem& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMSystem::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMSystem_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMSystem::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMSystem::loadRecByRef(
			ubigint ref
			, WdbeMSystem** rec
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

	return loadRecByStmt("TblWdbeMSystem_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMSystem::loadRecByUnt(
			ubigint refWdbeMUnit
			, WdbeMSystem** rec
		) {
	ubigint _refWdbeMUnit = htonl64(refWdbeMUnit);

	const char* vals[] = {
		(char*) &_refWdbeMUnit
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMSystem_loadRecByUnt", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMSystem::loadRstByVer(
			ubigint refWdbeMVersion
			, const bool append
			, ListWdbeMSystem& rst
		) {
	ubigint _refWdbeMVersion = htonl64(refWdbeMVersion);

	const char* vals[] = {
		(char*) &_refWdbeMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMSystem_loadRstByVer", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMSystem::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMSystem_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
