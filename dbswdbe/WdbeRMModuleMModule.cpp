/**
	* \file WdbeRMModuleMModule.cpp
	* database access for table TblWdbeRMModuleMModule (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Oct 2021
  */
// IP header --- ABOVE

#include "WdbeRMModuleMModule.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeRMModuleMModule
 ******************************************************************************/

WdbeRMModuleMModule::WdbeRMModuleMModule(
			const ubigint ref
			, const ubigint ctdRefWdbeMModule
			, const ubigint corRefWdbeMModule
			, const string srefKFunction
		) :
			ref(ref)
			, ctdRefWdbeMModule(ctdRefWdbeMModule)
			, corRefWdbeMModule(corRefWdbeMModule)
			, srefKFunction(srefKFunction)
		{
};

bool WdbeRMModuleMModule::operator==(
			const WdbeRMModuleMModule& comp
		) {
	return false;
};

bool WdbeRMModuleMModule::operator!=(
			const WdbeRMModuleMModule& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeRMModuleMModule
 ******************************************************************************/

ListWdbeRMModuleMModule::ListWdbeRMModuleMModule() {
};

ListWdbeRMModuleMModule::ListWdbeRMModuleMModule(
			const ListWdbeRMModuleMModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeRMModuleMModule(*(src.nodes[i]));
};

ListWdbeRMModuleMModule::~ListWdbeRMModuleMModule() {
	clear();
};

void ListWdbeRMModuleMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeRMModuleMModule::size() const {
	return(nodes.size());
};

void ListWdbeRMModuleMModule::append(
			WdbeRMModuleMModule* rec
		) {
	nodes.push_back(rec);
};

WdbeRMModuleMModule* ListWdbeRMModuleMModule::operator[](
			const uint ix
		) {
	WdbeRMModuleMModule* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeRMModuleMModule& ListWdbeRMModuleMModule::operator=(
			const ListWdbeRMModuleMModule& src
		) {
	WdbeRMModuleMModule* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeRMModuleMModule(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeRMModuleMModule::operator==(
			const ListWdbeRMModuleMModule& comp
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

bool ListWdbeRMModuleMModule::operator!=(
			const ListWdbeRMModuleMModule& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeRMModuleMModule
 ******************************************************************************/

TblWdbeRMModuleMModule::TblWdbeRMModuleMModule() {
};

TblWdbeRMModuleMModule::~TblWdbeRMModuleMModule() {
};

bool TblWdbeRMModuleMModule::loadRecBySQL(
			const string& sqlstr
			, WdbeRMModuleMModule** rec
		) {
	return false;
};

ubigint TblWdbeRMModuleMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	return 0;
};

ubigint TblWdbeRMModuleMModule::insertRec(
			WdbeRMModuleMModule* rec
		) {
	return 0;
};

ubigint TblWdbeRMModuleMModule::insertNewRec(
			WdbeRMModuleMModule** rec
			, const ubigint ctdRefWdbeMModule
			, const ubigint corRefWdbeMModule
			, const string srefKFunction
		) {
	ubigint retval = 0;
	WdbeRMModuleMModule* _rec = NULL;

	_rec = new WdbeRMModuleMModule(0, ctdRefWdbeMModule, corRefWdbeMModule, srefKFunction);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeRMModuleMModule::appendNewRecToRst(
			ListWdbeRMModuleMModule& rst
			, WdbeRMModuleMModule** rec
			, const ubigint ctdRefWdbeMModule
			, const ubigint corRefWdbeMModule
			, const string srefKFunction
		) {
	ubigint retval = 0;
	WdbeRMModuleMModule* _rec = NULL;

	retval = insertNewRec(&_rec, ctdRefWdbeMModule, corRefWdbeMModule, srefKFunction);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeRMModuleMModule::insertRst(
			ListWdbeRMModuleMModule& rst
			, bool transact
		) {
};

void TblWdbeRMModuleMModule::updateRec(
			WdbeRMModuleMModule* rec
		) {
};

void TblWdbeRMModuleMModule::updateRst(
			ListWdbeRMModuleMModule& rst
			, bool transact
		) {
};

void TblWdbeRMModuleMModule::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeRMModuleMModule::loadRecByRef(
			ubigint ref
			, WdbeRMModuleMModule** rec
		) {
	return false;
};

ubigint TblWdbeRMModuleMModule::loadRefsByCtd(
			ubigint ctdRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeRMModuleMModule::loadRstByCor(
			ubigint corRefWdbeMModule
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	return 0;
};

ubigint TblWdbeRMModuleMModule::loadRstByCtd(
			ubigint ctdRefWdbeMModule
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	return 0;
};

ubigint TblWdbeRMModuleMModule::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	ubigint numload = 0;
	WdbeRMModuleMModule* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeRMModuleMModule
 ******************************************************************************/

MyTblWdbeRMModuleMModule::MyTblWdbeRMModuleMModule() :
			TblWdbeRMModuleMModule()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeRMModuleMModule::~MyTblWdbeRMModuleMModule() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeRMModuleMModule::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeRMModuleMModule (ctdRefWdbeMModule, corRefWdbeMModule, srefKFunction) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeRMModuleMModule SET ctdRefWdbeMModule = ?, corRefWdbeMModule = ?, srefKFunction = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeRMModuleMModule WHERE ref = ?", false);
};

bool MyTblWdbeRMModuleMModule::loadRecBySQL(
			const string& sqlstr
			, WdbeRMModuleMModule** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeRMModuleMModule* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMModuleMModule::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMModuleMModule::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeRMModuleMModule();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ctdRefWdbeMModule = atoll((char*) dbrow[1]); else _rec->ctdRefWdbeMModule = 0;
		if (dbrow[2]) _rec->corRefWdbeMModule = atoll((char*) dbrow[2]); else _rec->corRefWdbeMModule = 0;
		if (dbrow[3]) _rec->srefKFunction.assign(dbrow[3], dblengths[3]); else _rec->srefKFunction = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeRMModuleMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeRMModuleMModule* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMModuleMModule::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMModuleMModule::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeRMModuleMModule();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ctdRefWdbeMModule = atoll((char*) dbrow[1]); else rec->ctdRefWdbeMModule = 0;
			if (dbrow[2]) rec->corRefWdbeMModule = atoll((char*) dbrow[2]); else rec->corRefWdbeMModule = 0;
			if (dbrow[3]) rec->srefKFunction.assign(dbrow[3], dblengths[3]); else rec->srefKFunction = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeRMModuleMModule::insertRec(
			WdbeRMModuleMModule* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->ctdRefWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->corRefWdbeMModule,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeRMModuleMModule::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeRMModuleMModule::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeRMModuleMModule::insertRst(
			ListWdbeRMModuleMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeRMModuleMModule::updateRec(
			WdbeRMModuleMModule* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->ctdRefWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->corRefWdbeMModule,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeRMModuleMModule::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeRMModuleMModule::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeRMModuleMModule::updateRst(
			ListWdbeRMModuleMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeRMModuleMModule::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeRMModuleMModule::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeRMModuleMModule::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeRMModuleMModule::loadRecByRef(
			ubigint ref
			, WdbeRMModuleMModule** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeRMModuleMModule WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeRMModuleMModule::loadRefsByCtd(
			ubigint ctdRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeRMModuleMModule WHERE ctdRefWdbeMModule = " + to_string(ctdRefWdbeMModule) + "", append, refs);
};

ubigint MyTblWdbeRMModuleMModule::loadRstByCor(
			ubigint corRefWdbeMModule
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	return loadRstBySQL("SELECT ref, ctdRefWdbeMModule, corRefWdbeMModule, srefKFunction FROM TblWdbeRMModuleMModule WHERE corRefWdbeMModule = " + to_string(corRefWdbeMModule) + "", append, rst);
};

ubigint MyTblWdbeRMModuleMModule::loadRstByCtd(
			ubigint ctdRefWdbeMModule
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	return loadRstBySQL("SELECT ref, ctdRefWdbeMModule, corRefWdbeMModule, srefKFunction FROM TblWdbeRMModuleMModule WHERE ctdRefWdbeMModule = " + to_string(ctdRefWdbeMModule) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeRMModuleMModule
 ******************************************************************************/

PgTblWdbeRMModuleMModule::PgTblWdbeRMModuleMModule() :
			TblWdbeRMModuleMModule()
			, PgTable()
		{
};

PgTblWdbeRMModuleMModule::~PgTblWdbeRMModuleMModule() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeRMModuleMModule::initStatements() {
	createStatement("TblWdbeRMModuleMModule_insertRec", "INSERT INTO TblWdbeRMModuleMModule (ctdRefWdbeMModule, corRefWdbeMModule, srefKFunction) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeRMModuleMModule_updateRec", "UPDATE TblWdbeRMModuleMModule SET ctdRefWdbeMModule = $1, corRefWdbeMModule = $2, srefKFunction = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeRMModuleMModule_removeRecByRef", "DELETE FROM TblWdbeRMModuleMModule WHERE ref = $1", 1);

	createStatement("TblWdbeRMModuleMModule_loadRecByRef", "SELECT ref, ctdRefWdbeMModule, corRefWdbeMModule, srefKFunction FROM TblWdbeRMModuleMModule WHERE ref = $1", 1);
	createStatement("TblWdbeRMModuleMModule_loadRefsByCtd", "SELECT ref FROM TblWdbeRMModuleMModule WHERE ctdRefWdbeMModule = $1", 1);
	createStatement("TblWdbeRMModuleMModule_loadRstByCor", "SELECT ref, ctdRefWdbeMModule, corRefWdbeMModule, srefKFunction FROM TblWdbeRMModuleMModule WHERE corRefWdbeMModule = $1", 1);
	createStatement("TblWdbeRMModuleMModule_loadRstByCtd", "SELECT ref, ctdRefWdbeMModule, corRefWdbeMModule, srefKFunction FROM TblWdbeRMModuleMModule WHERE ctdRefWdbeMModule = $1", 1);
};

bool PgTblWdbeRMModuleMModule::loadRec(
			PGresult* res
			, WdbeRMModuleMModule** rec
		) {
	char* ptr;

	WdbeRMModuleMModule* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeRMModuleMModule();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ctdrefwdbemmodule"),
			PQfnumber(res, "correfwdbemmodule"),
			PQfnumber(res, "srefkfunction")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ctdRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->corRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->srefKFunction.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeRMModuleMModule::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeRMModuleMModule* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ctdrefwdbemmodule"),
			PQfnumber(res, "correfwdbemmodule"),
			PQfnumber(res, "srefkfunction")
		};

		while (numread < numrow) {
			rec = new WdbeRMModuleMModule();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ctdRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->corRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->srefKFunction.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeRMModuleMModule::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeRMModuleMModule** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMModuleMModule::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMModuleMModule::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMModuleMModule::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeRMModuleMModule::loadRecBySQL(
			const string& sqlstr
			, WdbeRMModuleMModule** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMModuleMModule::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMModuleMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMModuleMModule::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeRMModuleMModule::insertRec(
			WdbeRMModuleMModule* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _ctdRefWdbeMModule = htonl64(rec->ctdRefWdbeMModule);
	ubigint _corRefWdbeMModule = htonl64(rec->corRefWdbeMModule);

	const char* vals[] = {
		(char*) &_ctdRefWdbeMModule,
		(char*) &_corRefWdbeMModule,
		rec->srefKFunction.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeRMModuleMModule_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMModuleMModule::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeRMModuleMModule::insertRst(
			ListWdbeRMModuleMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeRMModuleMModule::updateRec(
			WdbeRMModuleMModule* rec
		) {
	PGresult* res;

	ubigint _ctdRefWdbeMModule = htonl64(rec->ctdRefWdbeMModule);
	ubigint _corRefWdbeMModule = htonl64(rec->corRefWdbeMModule);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ctdRefWdbeMModule,
		(char*) &_corRefWdbeMModule,
		rec->srefKFunction.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMModuleMModule_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMModuleMModule::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeRMModuleMModule::updateRst(
			ListWdbeRMModuleMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeRMModuleMModule::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeRMModuleMModule_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMModuleMModule::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeRMModuleMModule::loadRecByRef(
			ubigint ref
			, WdbeRMModuleMModule** rec
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

	return loadRecByStmt("TblWdbeRMModuleMModule_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeRMModuleMModule::loadRefsByCtd(
			ubigint ctdRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _ctdRefWdbeMModule = htonl64(ctdRefWdbeMModule);

	const char* vals[] = {
		(char*) &_ctdRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMModuleMModule_loadRefsByCtd", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeRMModuleMModule::loadRstByCor(
			ubigint corRefWdbeMModule
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	ubigint _corRefWdbeMModule = htonl64(corRefWdbeMModule);

	const char* vals[] = {
		(char*) &_corRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMModuleMModule_loadRstByCor", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeRMModuleMModule::loadRstByCtd(
			ubigint ctdRefWdbeMModule
			, const bool append
			, ListWdbeRMModuleMModule& rst
		) {
	ubigint _ctdRefWdbeMModule = htonl64(ctdRefWdbeMModule);

	const char* vals[] = {
		(char*) &_ctdRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMModuleMModule_loadRstByCtd", 1, vals, l, f, append, rst);
};

#endif
