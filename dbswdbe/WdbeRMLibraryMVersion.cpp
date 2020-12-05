/**
	* \file WdbeRMLibraryMVersion.cpp
	* database access for table TblWdbeRMLibraryMVersion (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeRMLibraryMVersion.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeRMLibraryMVersion
 ******************************************************************************/

WdbeRMLibraryMVersion::WdbeRMLibraryMVersion(
			const ubigint ref
			, const ubigint refWdbeMLibrary
			, const ubigint refWdbeMVersion
		) {

	this->ref = ref;
	this->refWdbeMLibrary = refWdbeMLibrary;
	this->refWdbeMVersion = refWdbeMVersion;
};

bool WdbeRMLibraryMVersion::operator==(
			const WdbeRMLibraryMVersion& comp
		) {
	return false;
};

bool WdbeRMLibraryMVersion::operator!=(
			const WdbeRMLibraryMVersion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeRMLibraryMVersion
 ******************************************************************************/

ListWdbeRMLibraryMVersion::ListWdbeRMLibraryMVersion() {
};

ListWdbeRMLibraryMVersion::ListWdbeRMLibraryMVersion(
			const ListWdbeRMLibraryMVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeRMLibraryMVersion(*(src.nodes[i]));
};

ListWdbeRMLibraryMVersion::~ListWdbeRMLibraryMVersion() {
	clear();
};

void ListWdbeRMLibraryMVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeRMLibraryMVersion::size() const {
	return(nodes.size());
};

void ListWdbeRMLibraryMVersion::append(
			WdbeRMLibraryMVersion* rec
		) {
	nodes.push_back(rec);
};

WdbeRMLibraryMVersion* ListWdbeRMLibraryMVersion::operator[](
			const uint ix
		) {
	WdbeRMLibraryMVersion* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeRMLibraryMVersion& ListWdbeRMLibraryMVersion::operator=(
			const ListWdbeRMLibraryMVersion& src
		) {
	WdbeRMLibraryMVersion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeRMLibraryMVersion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeRMLibraryMVersion::operator==(
			const ListWdbeRMLibraryMVersion& comp
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

bool ListWdbeRMLibraryMVersion::operator!=(
			const ListWdbeRMLibraryMVersion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeRMLibraryMVersion
 ******************************************************************************/

TblWdbeRMLibraryMVersion::TblWdbeRMLibraryMVersion() {
};

TblWdbeRMLibraryMVersion::~TblWdbeRMLibraryMVersion() {
};

bool TblWdbeRMLibraryMVersion::loadRecBySQL(
			const string& sqlstr
			, WdbeRMLibraryMVersion** rec
		) {
	return false;
};

ubigint TblWdbeRMLibraryMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMLibraryMVersion& rst
		) {
	return 0;
};

ubigint TblWdbeRMLibraryMVersion::insertRec(
			WdbeRMLibraryMVersion* rec
		) {
	return 0;
};

ubigint TblWdbeRMLibraryMVersion::insertNewRec(
			WdbeRMLibraryMVersion** rec
			, const ubigint refWdbeMLibrary
			, const ubigint refWdbeMVersion
		) {
	ubigint retval = 0;
	WdbeRMLibraryMVersion* _rec = NULL;

	_rec = new WdbeRMLibraryMVersion(0, refWdbeMLibrary, refWdbeMVersion);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeRMLibraryMVersion::appendNewRecToRst(
			ListWdbeRMLibraryMVersion& rst
			, WdbeRMLibraryMVersion** rec
			, const ubigint refWdbeMLibrary
			, const ubigint refWdbeMVersion
		) {
	ubigint retval = 0;
	WdbeRMLibraryMVersion* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMLibrary, refWdbeMVersion);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeRMLibraryMVersion::insertRst(
			ListWdbeRMLibraryMVersion& rst
			, bool transact
		) {
};

void TblWdbeRMLibraryMVersion::updateRec(
			WdbeRMLibraryMVersion* rec
		) {
};

void TblWdbeRMLibraryMVersion::updateRst(
			ListWdbeRMLibraryMVersion& rst
			, bool transact
		) {
};

void TblWdbeRMLibraryMVersion::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeRMLibraryMVersion::loadRecByRef(
			ubigint ref
			, WdbeRMLibraryMVersion** rec
		) {
	return false;
};

ubigint TblWdbeRMLibraryMVersion::loadLibsByVer(
			ubigint refWdbeMVersion
			, const bool append
			, vector<ubigint>& refWdbeMLibrarys
		) {
	return 0;
};

ubigint TblWdbeRMLibraryMVersion::loadRefsByVer(
			ubigint refWdbeMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeRMLibraryMVersion::loadVersByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, vector<ubigint>& refWdbeMVersions
		) {
	return 0;
};

ubigint TblWdbeRMLibraryMVersion::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeRMLibraryMVersion& rst
		) {
	ubigint numload = 0;
	WdbeRMLibraryMVersion* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeRMLibraryMVersion
 ******************************************************************************/

MyTblWdbeRMLibraryMVersion::MyTblWdbeRMLibraryMVersion() :
			TblWdbeRMLibraryMVersion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeRMLibraryMVersion::~MyTblWdbeRMLibraryMVersion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeRMLibraryMVersion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeRMLibraryMVersion (refWdbeMLibrary, refWdbeMVersion) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeRMLibraryMVersion SET refWdbeMLibrary = ?, refWdbeMVersion = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeRMLibraryMVersion WHERE ref = ?", false);
};

bool MyTblWdbeRMLibraryMVersion::loadRecBySQL(
			const string& sqlstr
			, WdbeRMLibraryMVersion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeRMLibraryMVersion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMLibraryMVersion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMLibraryMVersion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeRMLibraryMVersion();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMLibrary = atoll((char*) dbrow[1]); else _rec->refWdbeMLibrary = 0;
		if (dbrow[2]) _rec->refWdbeMVersion = atoll((char*) dbrow[2]); else _rec->refWdbeMVersion = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeRMLibraryMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMLibraryMVersion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeRMLibraryMVersion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMLibraryMVersion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMLibraryMVersion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeRMLibraryMVersion();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMLibrary = atoll((char*) dbrow[1]); else rec->refWdbeMLibrary = 0;
			if (dbrow[2]) rec->refWdbeMVersion = atoll((char*) dbrow[2]); else rec->refWdbeMVersion = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeRMLibraryMVersion::insertRec(
			WdbeRMLibraryMVersion* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMLibrary,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMVersion,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeRMLibraryMVersion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeRMLibraryMVersion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeRMLibraryMVersion::insertRst(
			ListWdbeRMLibraryMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeRMLibraryMVersion::updateRec(
			WdbeRMLibraryMVersion* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMLibrary,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeRMLibraryMVersion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeRMLibraryMVersion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeRMLibraryMVersion::updateRst(
			ListWdbeRMLibraryMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeRMLibraryMVersion::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeRMLibraryMVersion::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeRMLibraryMVersion::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeRMLibraryMVersion::loadRecByRef(
			ubigint ref
			, WdbeRMLibraryMVersion** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeRMLibraryMVersion WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeRMLibraryMVersion::loadLibsByVer(
			ubigint refWdbeMVersion
			, const bool append
			, vector<ubigint>& refWdbeMLibrarys
		) {
	return loadRefsBySQL("SELECT refWdbeMLibrary FROM TblWdbeRMLibraryMVersion WHERE refWdbeMVersion = " + to_string(refWdbeMVersion) + "", append, refWdbeMLibrarys);
};

ubigint MyTblWdbeRMLibraryMVersion::loadRefsByVer(
			ubigint refWdbeMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeRMLibraryMVersion WHERE refWdbeMVersion = " + to_string(refWdbeMVersion) + "", append, refs);
};

ubigint MyTblWdbeRMLibraryMVersion::loadVersByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, vector<ubigint>& refWdbeMVersions
		) {
	return loadRefsBySQL("SELECT refWdbeMVersion FROM TblWdbeRMLibraryMVersion WHERE refWdbeMLibrary = " + to_string(refWdbeMLibrary) + "", append, refWdbeMVersions);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeRMLibraryMVersion
 ******************************************************************************/

PgTblWdbeRMLibraryMVersion::PgTblWdbeRMLibraryMVersion() :
			TblWdbeRMLibraryMVersion()
			, PgTable()
		{
};

PgTblWdbeRMLibraryMVersion::~PgTblWdbeRMLibraryMVersion() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeRMLibraryMVersion::initStatements() {
	createStatement("TblWdbeRMLibraryMVersion_insertRec", "INSERT INTO TblWdbeRMLibraryMVersion (refWdbeMLibrary, refWdbeMVersion) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWdbeRMLibraryMVersion_updateRec", "UPDATE TblWdbeRMLibraryMVersion SET refWdbeMLibrary = $1, refWdbeMVersion = $2 WHERE ref = $3", 3);
	createStatement("TblWdbeRMLibraryMVersion_removeRecByRef", "DELETE FROM TblWdbeRMLibraryMVersion WHERE ref = $1", 1);

	createStatement("TblWdbeRMLibraryMVersion_loadRecByRef", "SELECT ref, refWdbeMLibrary, refWdbeMVersion FROM TblWdbeRMLibraryMVersion WHERE ref = $1", 1);
	createStatement("TblWdbeRMLibraryMVersion_loadLibsByVer", "SELECT refWdbeMLibrary FROM TblWdbeRMLibraryMVersion WHERE refWdbeMVersion = $1", 1);
	createStatement("TblWdbeRMLibraryMVersion_loadRefsByVer", "SELECT ref FROM TblWdbeRMLibraryMVersion WHERE refWdbeMVersion = $1", 1);
	createStatement("TblWdbeRMLibraryMVersion_loadVersByLib", "SELECT refWdbeMVersion FROM TblWdbeRMLibraryMVersion WHERE refWdbeMLibrary = $1", 1);
};

bool PgTblWdbeRMLibraryMVersion::loadRec(
			PGresult* res
			, WdbeRMLibraryMVersion** rec
		) {
	char* ptr;

	WdbeRMLibraryMVersion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeRMLibraryMVersion();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemlibrary"),
			PQfnumber(res, "refwdbemversion")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMLibrary = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMVersion = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeRMLibraryMVersion::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeRMLibraryMVersion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeRMLibraryMVersion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemlibrary"),
			PQfnumber(res, "refwdbemversion")
		};

		while (numread < numrow) {
			rec = new WdbeRMLibraryMVersion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMLibrary = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMVersion = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeRMLibraryMVersion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeRMLibraryMVersion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMLibraryMVersion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeRMLibraryMVersion::loadRecBySQL(
			const string& sqlstr
			, WdbeRMLibraryMVersion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMLibraryMVersion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMLibraryMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMLibraryMVersion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMLibraryMVersion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeRMLibraryMVersion::insertRec(
			WdbeRMLibraryMVersion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMLibrary = htonl64(rec->refWdbeMLibrary);
	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);

	const char* vals[] = {
		(char*) &_refWdbeMLibrary,
		(char*) &_refWdbeMVersion
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMLibraryMVersion_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMLibraryMVersion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeRMLibraryMVersion::insertRst(
			ListWdbeRMLibraryMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeRMLibraryMVersion::updateRec(
			WdbeRMLibraryMVersion* rec
		) {
	PGresult* res;

	ubigint _refWdbeMLibrary = htonl64(rec->refWdbeMLibrary);
	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMLibrary,
		(char*) &_refWdbeMVersion,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMLibraryMVersion_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMLibraryMVersion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeRMLibraryMVersion::updateRst(
			ListWdbeRMLibraryMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeRMLibraryMVersion::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeRMLibraryMVersion_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMLibraryMVersion::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeRMLibraryMVersion::loadRecByRef(
			ubigint ref
			, WdbeRMLibraryMVersion** rec
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

	return loadRecByStmt("TblWdbeRMLibraryMVersion_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeRMLibraryMVersion::loadLibsByVer(
			ubigint refWdbeMVersion
			, const bool append
			, vector<ubigint>& refWdbeMLibrarys
		) {
	ubigint _refWdbeMVersion = htonl64(refWdbeMVersion);

	const char* vals[] = {
		(char*) &_refWdbeMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMLibraryMVersion_loadLibsByVer", 1, vals, l, f, append, refWdbeMLibrarys);
};

ubigint PgTblWdbeRMLibraryMVersion::loadRefsByVer(
			ubigint refWdbeMVersion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMVersion = htonl64(refWdbeMVersion);

	const char* vals[] = {
		(char*) &_refWdbeMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMLibraryMVersion_loadRefsByVer", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeRMLibraryMVersion::loadVersByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, vector<ubigint>& refWdbeMVersions
		) {
	ubigint _refWdbeMLibrary = htonl64(refWdbeMLibrary);

	const char* vals[] = {
		(char*) &_refWdbeMLibrary
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMLibraryMVersion_loadVersByLib", 1, vals, l, f, append, refWdbeMVersions);
};

#endif

