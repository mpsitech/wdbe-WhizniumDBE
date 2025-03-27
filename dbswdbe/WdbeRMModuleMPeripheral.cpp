/**
	* \file WdbeRMModuleMPeripheral.cpp
	* database access for table TblWdbeRMModuleMPeripheral (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 13 Oct 2021
  */
// IP header --- ABOVE

#include "WdbeRMModuleMPeripheral.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeRMModuleMPeripheral
 ******************************************************************************/

WdbeRMModuleMPeripheral::WdbeRMModuleMPeripheral(
			const ubigint ref
			, const ubigint refWdbeMModule
			, const ubigint refWdbeMPeripheral
		) :
			ref(ref)
			, refWdbeMModule(refWdbeMModule)
			, refWdbeMPeripheral(refWdbeMPeripheral)
		{
};

bool WdbeRMModuleMPeripheral::operator==(
			const WdbeRMModuleMPeripheral& comp
		) {
	return false;
};

bool WdbeRMModuleMPeripheral::operator!=(
			const WdbeRMModuleMPeripheral& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeRMModuleMPeripheral
 ******************************************************************************/

ListWdbeRMModuleMPeripheral::ListWdbeRMModuleMPeripheral() {
};

ListWdbeRMModuleMPeripheral::ListWdbeRMModuleMPeripheral(
			const ListWdbeRMModuleMPeripheral& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeRMModuleMPeripheral(*(src.nodes[i]));
};

ListWdbeRMModuleMPeripheral::~ListWdbeRMModuleMPeripheral() {
	clear();
};

void ListWdbeRMModuleMPeripheral::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeRMModuleMPeripheral::size() const {
	return(nodes.size());
};

void ListWdbeRMModuleMPeripheral::append(
			WdbeRMModuleMPeripheral* rec
		) {
	nodes.push_back(rec);
};

WdbeRMModuleMPeripheral* ListWdbeRMModuleMPeripheral::operator[](
			const uint ix
		) {
	WdbeRMModuleMPeripheral* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeRMModuleMPeripheral& ListWdbeRMModuleMPeripheral::operator=(
			const ListWdbeRMModuleMPeripheral& src
		) {
	WdbeRMModuleMPeripheral* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeRMModuleMPeripheral(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeRMModuleMPeripheral::operator==(
			const ListWdbeRMModuleMPeripheral& comp
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

bool ListWdbeRMModuleMPeripheral::operator!=(
			const ListWdbeRMModuleMPeripheral& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeRMModuleMPeripheral
 ******************************************************************************/

TblWdbeRMModuleMPeripheral::TblWdbeRMModuleMPeripheral() {
};

TblWdbeRMModuleMPeripheral::~TblWdbeRMModuleMPeripheral() {
};

bool TblWdbeRMModuleMPeripheral::loadRecBySQL(
			const string& sqlstr
			, WdbeRMModuleMPeripheral** rec
		) {
	return false;
};

ubigint TblWdbeRMModuleMPeripheral::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMModuleMPeripheral& rst
		) {
	return 0;
};

ubigint TblWdbeRMModuleMPeripheral::insertRec(
			WdbeRMModuleMPeripheral* rec
		) {
	return 0;
};

ubigint TblWdbeRMModuleMPeripheral::insertNewRec(
			WdbeRMModuleMPeripheral** rec
			, const ubigint refWdbeMModule
			, const ubigint refWdbeMPeripheral
		) {
	ubigint retval = 0;
	WdbeRMModuleMPeripheral* _rec = NULL;

	_rec = new WdbeRMModuleMPeripheral(0, refWdbeMModule, refWdbeMPeripheral);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeRMModuleMPeripheral::appendNewRecToRst(
			ListWdbeRMModuleMPeripheral& rst
			, WdbeRMModuleMPeripheral** rec
			, const ubigint refWdbeMModule
			, const ubigint refWdbeMPeripheral
		) {
	ubigint retval = 0;
	WdbeRMModuleMPeripheral* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMModule, refWdbeMPeripheral);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeRMModuleMPeripheral::insertRst(
			ListWdbeRMModuleMPeripheral& rst
			, bool transact
		) {
};

void TblWdbeRMModuleMPeripheral::updateRec(
			WdbeRMModuleMPeripheral* rec
		) {
};

void TblWdbeRMModuleMPeripheral::updateRst(
			ListWdbeRMModuleMPeripheral& rst
			, bool transact
		) {
};

void TblWdbeRMModuleMPeripheral::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeRMModuleMPeripheral::loadRecByRef(
			ubigint ref
			, WdbeRMModuleMPeripheral** rec
		) {
	return false;
};

ubigint TblWdbeRMModuleMPeripheral::loadMdlsByPph(
			ubigint refWdbeMPeripheral
			, const bool append
			, vector<ubigint>& refWdbeMModules
		) {
	return 0;
};

ubigint TblWdbeRMModuleMPeripheral::loadPphsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refWdbeMPeripherals
		) {
	return 0;
};

ubigint TblWdbeRMModuleMPeripheral::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeRMModuleMPeripheral::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeRMModuleMPeripheral& rst
		) {
	ubigint numload = 0;
	WdbeRMModuleMPeripheral* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeRMModuleMPeripheral
 ******************************************************************************/

MyTblWdbeRMModuleMPeripheral::MyTblWdbeRMModuleMPeripheral() :
			TblWdbeRMModuleMPeripheral()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeRMModuleMPeripheral::~MyTblWdbeRMModuleMPeripheral() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeRMModuleMPeripheral::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeRMModuleMPeripheral (refWdbeMModule, refWdbeMPeripheral) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeRMModuleMPeripheral SET refWdbeMModule = ?, refWdbeMPeripheral = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeRMModuleMPeripheral WHERE ref = ?", false);
};

bool MyTblWdbeRMModuleMPeripheral::loadRecBySQL(
			const string& sqlstr
			, WdbeRMModuleMPeripheral** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeRMModuleMPeripheral* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMModuleMPeripheral::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMModuleMPeripheral::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeRMModuleMPeripheral();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMModule = atoll((char*) dbrow[1]); else _rec->refWdbeMModule = 0;
		if (dbrow[2]) _rec->refWdbeMPeripheral = atoll((char*) dbrow[2]); else _rec->refWdbeMPeripheral = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeRMModuleMPeripheral::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMModuleMPeripheral& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeRMModuleMPeripheral* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMModuleMPeripheral::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMModuleMPeripheral::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeRMModuleMPeripheral();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMModule = atoll((char*) dbrow[1]); else rec->refWdbeMModule = 0;
			if (dbrow[2]) rec->refWdbeMPeripheral = atoll((char*) dbrow[2]); else rec->refWdbeMPeripheral = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeRMModuleMPeripheral::insertRec(
			WdbeRMModuleMPeripheral* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMPeripheral,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeRMModuleMPeripheral::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeRMModuleMPeripheral::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeRMModuleMPeripheral::insertRst(
			ListWdbeRMModuleMPeripheral& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeRMModuleMPeripheral::updateRec(
			WdbeRMModuleMPeripheral* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMPeripheral,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeRMModuleMPeripheral::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeRMModuleMPeripheral::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeRMModuleMPeripheral::updateRst(
			ListWdbeRMModuleMPeripheral& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeRMModuleMPeripheral::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeRMModuleMPeripheral::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeRMModuleMPeripheral::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeRMModuleMPeripheral::loadRecByRef(
			ubigint ref
			, WdbeRMModuleMPeripheral** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeRMModuleMPeripheral WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeRMModuleMPeripheral::loadMdlsByPph(
			ubigint refWdbeMPeripheral
			, const bool append
			, vector<ubigint>& refWdbeMModules
		) {
	return loadRefsBySQL("SELECT refWdbeMModule FROM TblWdbeRMModuleMPeripheral WHERE refWdbeMPeripheral = " + to_string(refWdbeMPeripheral) + "", append, refWdbeMModules);
};

ubigint MyTblWdbeRMModuleMPeripheral::loadPphsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refWdbeMPeripherals
		) {
	return loadRefsBySQL("SELECT refWdbeMPeripheral FROM TblWdbeRMModuleMPeripheral WHERE refWdbeMModule = " + to_string(refWdbeMModule) + "", append, refWdbeMPeripherals);
};

ubigint MyTblWdbeRMModuleMPeripheral::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeRMModuleMPeripheral WHERE refWdbeMModule = " + to_string(refWdbeMModule) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeRMModuleMPeripheral
 ******************************************************************************/

PgTblWdbeRMModuleMPeripheral::PgTblWdbeRMModuleMPeripheral() :
			TblWdbeRMModuleMPeripheral()
			, PgTable()
		{
};

PgTblWdbeRMModuleMPeripheral::~PgTblWdbeRMModuleMPeripheral() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeRMModuleMPeripheral::initStatements() {
	createStatement("TblWdbeRMModuleMPeripheral_insertRec", "INSERT INTO TblWdbeRMModuleMPeripheral (refWdbeMModule, refWdbeMPeripheral) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWdbeRMModuleMPeripheral_updateRec", "UPDATE TblWdbeRMModuleMPeripheral SET refWdbeMModule = $1, refWdbeMPeripheral = $2 WHERE ref = $3", 3);
	createStatement("TblWdbeRMModuleMPeripheral_removeRecByRef", "DELETE FROM TblWdbeRMModuleMPeripheral WHERE ref = $1", 1);

	createStatement("TblWdbeRMModuleMPeripheral_loadRecByRef", "SELECT ref, refWdbeMModule, refWdbeMPeripheral FROM TblWdbeRMModuleMPeripheral WHERE ref = $1", 1);
	createStatement("TblWdbeRMModuleMPeripheral_loadMdlsByPph", "SELECT refWdbeMModule FROM TblWdbeRMModuleMPeripheral WHERE refWdbeMPeripheral = $1", 1);
	createStatement("TblWdbeRMModuleMPeripheral_loadPphsByMdl", "SELECT refWdbeMPeripheral FROM TblWdbeRMModuleMPeripheral WHERE refWdbeMModule = $1", 1);
	createStatement("TblWdbeRMModuleMPeripheral_loadRefsByMdl", "SELECT ref FROM TblWdbeRMModuleMPeripheral WHERE refWdbeMModule = $1", 1);
};

bool PgTblWdbeRMModuleMPeripheral::loadRec(
			PGresult* res
			, WdbeRMModuleMPeripheral** rec
		) {
	char* ptr;

	WdbeRMModuleMPeripheral* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeRMModuleMPeripheral();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "refwdbemperipheral")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMPeripheral = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeRMModuleMPeripheral::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeRMModuleMPeripheral& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeRMModuleMPeripheral* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "refwdbemperipheral")
		};

		while (numread < numrow) {
			rec = new WdbeRMModuleMPeripheral();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMPeripheral = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeRMModuleMPeripheral::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeRMModuleMPeripheral** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMModuleMPeripheral::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeRMModuleMPeripheral::loadRecBySQL(
			const string& sqlstr
			, WdbeRMModuleMPeripheral** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMModuleMPeripheral::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMModuleMPeripheral::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMModuleMPeripheral& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMModuleMPeripheral::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeRMModuleMPeripheral::insertRec(
			WdbeRMModuleMPeripheral* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	ubigint _refWdbeMPeripheral = htonl64(rec->refWdbeMPeripheral);

	const char* vals[] = {
		(char*) &_refWdbeMModule,
		(char*) &_refWdbeMPeripheral
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMModuleMPeripheral_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMModuleMPeripheral::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeRMModuleMPeripheral::insertRst(
			ListWdbeRMModuleMPeripheral& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeRMModuleMPeripheral::updateRec(
			WdbeRMModuleMPeripheral* rec
		) {
	PGresult* res;

	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	ubigint _refWdbeMPeripheral = htonl64(rec->refWdbeMPeripheral);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMModule,
		(char*) &_refWdbeMPeripheral,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMModuleMPeripheral_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMModuleMPeripheral::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeRMModuleMPeripheral::updateRst(
			ListWdbeRMModuleMPeripheral& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeRMModuleMPeripheral::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeRMModuleMPeripheral_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMModuleMPeripheral::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeRMModuleMPeripheral::loadRecByRef(
			ubigint ref
			, WdbeRMModuleMPeripheral** rec
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

	return loadRecByStmt("TblWdbeRMModuleMPeripheral_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeRMModuleMPeripheral::loadMdlsByPph(
			ubigint refWdbeMPeripheral
			, const bool append
			, vector<ubigint>& refWdbeMModules
		) {
	ubigint _refWdbeMPeripheral = htonl64(refWdbeMPeripheral);

	const char* vals[] = {
		(char*) &_refWdbeMPeripheral
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMModuleMPeripheral_loadMdlsByPph", 1, vals, l, f, append, refWdbeMModules);
};

ubigint PgTblWdbeRMModuleMPeripheral::loadPphsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refWdbeMPeripherals
		) {
	ubigint _refWdbeMModule = htonl64(refWdbeMModule);

	const char* vals[] = {
		(char*) &_refWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMModuleMPeripheral_loadPphsByMdl", 1, vals, l, f, append, refWdbeMPeripherals);
};

ubigint PgTblWdbeRMModuleMPeripheral::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMModule = htonl64(refWdbeMModule);

	const char* vals[] = {
		(char*) &_refWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMModuleMPeripheral_loadRefsByMdl", 1, vals, l, f, append, refs);
};

#endif
