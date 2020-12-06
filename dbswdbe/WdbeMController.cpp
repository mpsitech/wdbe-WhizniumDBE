/**
	* \file WdbeMController.cpp
	* database access for table TblWdbeMController (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMController.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMController
 ******************************************************************************/

WdbeMController::WdbeMController(
			const ubigint ref
			, const ubigint refWdbeMModule
			, const ubigint fwdRefWdbeMUnit
			, const string Fullsref
			, const ubigint clrRefWdbeMSignal
		) {

	this->ref = ref;
	this->refWdbeMModule = refWdbeMModule;
	this->fwdRefWdbeMUnit = fwdRefWdbeMUnit;
	this->Fullsref = Fullsref;
	this->clrRefWdbeMSignal = clrRefWdbeMSignal;
};

bool WdbeMController::operator==(
			const WdbeMController& comp
		) {
	return false;
};

bool WdbeMController::operator!=(
			const WdbeMController& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMController
 ******************************************************************************/

ListWdbeMController::ListWdbeMController() {
};

ListWdbeMController::ListWdbeMController(
			const ListWdbeMController& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMController(*(src.nodes[i]));
};

ListWdbeMController::~ListWdbeMController() {
	clear();
};

void ListWdbeMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMController::size() const {
	return(nodes.size());
};

void ListWdbeMController::append(
			WdbeMController* rec
		) {
	nodes.push_back(rec);
};

WdbeMController* ListWdbeMController::operator[](
			const uint ix
		) {
	WdbeMController* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMController& ListWdbeMController::operator=(
			const ListWdbeMController& src
		) {
	WdbeMController* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMController(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMController::operator==(
			const ListWdbeMController& comp
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

bool ListWdbeMController::operator!=(
			const ListWdbeMController& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMController
 ******************************************************************************/

TblWdbeMController::TblWdbeMController() {
};

TblWdbeMController::~TblWdbeMController() {
};

bool TblWdbeMController::loadRecBySQL(
			const string& sqlstr
			, WdbeMController** rec
		) {
	return false;
};

ubigint TblWdbeMController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMController& rst
		) {
	return 0;
};

ubigint TblWdbeMController::insertRec(
			WdbeMController* rec
		) {
	return 0;
};

ubigint TblWdbeMController::insertNewRec(
			WdbeMController** rec
			, const ubigint refWdbeMModule
			, const ubigint fwdRefWdbeMUnit
			, const string Fullsref
			, const ubigint clrRefWdbeMSignal
		) {
	ubigint retval = 0;
	WdbeMController* _rec = NULL;

	_rec = new WdbeMController(0, refWdbeMModule, fwdRefWdbeMUnit, Fullsref, clrRefWdbeMSignal);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMController::appendNewRecToRst(
			ListWdbeMController& rst
			, WdbeMController** rec
			, const ubigint refWdbeMModule
			, const ubigint fwdRefWdbeMUnit
			, const string Fullsref
			, const ubigint clrRefWdbeMSignal
		) {
	ubigint retval = 0;
	WdbeMController* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMModule, fwdRefWdbeMUnit, Fullsref, clrRefWdbeMSignal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMController::insertRst(
			ListWdbeMController& rst
			, bool transact
		) {
};

void TblWdbeMController::updateRec(
			WdbeMController* rec
		) {
};

void TblWdbeMController::updateRst(
			ListWdbeMController& rst
			, bool transact
		) {
};

void TblWdbeMController::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMController::loadRecByRef(
			ubigint ref
			, WdbeMController** rec
		) {
	return false;
};

bool TblWdbeMController::loadFsrByRef(
			ubigint ref
			, string& Fullsref
		) {
	return false;
};

bool TblWdbeMController::loadRecByMdl(
			ubigint refWdbeMModule
			, WdbeMController** rec
		) {
	return false;
};

ubigint TblWdbeMController::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMController::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMController& rst
		) {
	ubigint numload = 0;
	WdbeMController* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMController
 ******************************************************************************/

MyTblWdbeMController::MyTblWdbeMController() :
			TblWdbeMController()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMController::~MyTblWdbeMController() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMController::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMController (refWdbeMModule, fwdRefWdbeMUnit, Fullsref, clrRefWdbeMSignal) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMController SET refWdbeMModule = ?, fwdRefWdbeMUnit = ?, Fullsref = ?, clrRefWdbeMSignal = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMController WHERE ref = ?", false);
};

bool MyTblWdbeMController::loadRecBySQL(
			const string& sqlstr
			, WdbeMController** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMController* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMController::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMController::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMController();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMModule = atoll((char*) dbrow[1]); else _rec->refWdbeMModule = 0;
		if (dbrow[2]) _rec->fwdRefWdbeMUnit = atoll((char*) dbrow[2]); else _rec->fwdRefWdbeMUnit = 0;
		if (dbrow[3]) _rec->Fullsref.assign(dbrow[3], dblengths[3]); else _rec->Fullsref = "";
		if (dbrow[4]) _rec->clrRefWdbeMSignal = atoll((char*) dbrow[4]); else _rec->clrRefWdbeMSignal = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMController& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMController* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMController::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMController::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMController();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMModule = atoll((char*) dbrow[1]); else rec->refWdbeMModule = 0;
			if (dbrow[2]) rec->fwdRefWdbeMUnit = atoll((char*) dbrow[2]); else rec->fwdRefWdbeMUnit = 0;
			if (dbrow[3]) rec->Fullsref.assign(dbrow[3], dblengths[3]); else rec->Fullsref = "";
			if (dbrow[4]) rec->clrRefWdbeMSignal = atoll((char*) dbrow[4]); else rec->clrRefWdbeMSignal = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMController::insertRec(
			WdbeMController* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Fullsref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->fwdRefWdbeMUnit,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->clrRefWdbeMSignal,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMController::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMController::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMController::insertRst(
			ListWdbeMController& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMController::updateRec(
			WdbeMController* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Fullsref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->fwdRefWdbeMUnit,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->clrRefWdbeMSignal,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMController::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMController::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMController::updateRst(
			ListWdbeMController& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMController::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMController::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMController::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMController::loadRecByRef(
			ubigint ref
			, WdbeMController** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMController WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMController::loadFsrByRef(
			ubigint ref
			, string& Fullsref
		) {
	return loadStringBySQL("SELECT Fullsref FROM TblWdbeMController WHERE ref = " + to_string(ref) + "", Fullsref);
};

bool MyTblWdbeMController::loadRecByMdl(
			ubigint refWdbeMModule
			, WdbeMController** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMModule, fwdRefWdbeMUnit, Fullsref, clrRefWdbeMSignal FROM TblWdbeMController WHERE refWdbeMModule = " + to_string(refWdbeMModule) + "", rec);
};

ubigint MyTblWdbeMController::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMController WHERE refWdbeMModule = " + to_string(refWdbeMModule) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMController
 ******************************************************************************/

PgTblWdbeMController::PgTblWdbeMController() :
			TblWdbeMController()
			, PgTable()
		{
};

PgTblWdbeMController::~PgTblWdbeMController() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMController::initStatements() {
	createStatement("TblWdbeMController_insertRec", "INSERT INTO TblWdbeMController (refWdbeMModule, fwdRefWdbeMUnit, Fullsref, clrRefWdbeMSignal) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeMController_updateRec", "UPDATE TblWdbeMController SET refWdbeMModule = $1, fwdRefWdbeMUnit = $2, Fullsref = $3, clrRefWdbeMSignal = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeMController_removeRecByRef", "DELETE FROM TblWdbeMController WHERE ref = $1", 1);

	createStatement("TblWdbeMController_loadRecByRef", "SELECT ref, refWdbeMModule, fwdRefWdbeMUnit, Fullsref, clrRefWdbeMSignal FROM TblWdbeMController WHERE ref = $1", 1);
	createStatement("TblWdbeMController_loadFsrByRef", "SELECT Fullsref FROM TblWdbeMController WHERE ref = $1", 1);
	createStatement("TblWdbeMController_loadRecByMdl", "SELECT ref, refWdbeMModule, fwdRefWdbeMUnit, Fullsref, clrRefWdbeMSignal FROM TblWdbeMController WHERE refWdbeMModule = $1", 1);
	createStatement("TblWdbeMController_loadRefsByMdl", "SELECT ref FROM TblWdbeMController WHERE refWdbeMModule = $1", 1);
};

bool PgTblWdbeMController::loadRec(
			PGresult* res
			, WdbeMController** rec
		) {
	char* ptr;

	WdbeMController* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMController();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "fwdrefwdbemunit"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "clrrefwdbemsignal")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->fwdRefWdbeMUnit = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Fullsref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->clrRefWdbeMSignal = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMController::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMController& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMController* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "fwdrefwdbemunit"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "clrrefwdbemsignal")
		};

		while (numread < numrow) {
			rec = new WdbeMController();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->fwdRefWdbeMUnit = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Fullsref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->clrRefWdbeMSignal = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMController::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMController** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMController::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeMController::loadRecBySQL(
			const string& sqlstr
			, WdbeMController** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMController::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMController& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMController::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMController::insertRec(
			WdbeMController* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	ubigint _fwdRefWdbeMUnit = htonl64(rec->fwdRefWdbeMUnit);
	ubigint _clrRefWdbeMSignal = htonl64(rec->clrRefWdbeMSignal);

	const char* vals[] = {
		(char*) &_refWdbeMModule,
		(char*) &_fwdRefWdbeMUnit,
		rec->Fullsref.c_str(),
		(char*) &_clrRefWdbeMSignal
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMController_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMController::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMController::insertRst(
			ListWdbeMController& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMController::updateRec(
			WdbeMController* rec
		) {
	PGresult* res;

	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	ubigint _fwdRefWdbeMUnit = htonl64(rec->fwdRefWdbeMUnit);
	ubigint _clrRefWdbeMSignal = htonl64(rec->clrRefWdbeMSignal);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMModule,
		(char*) &_fwdRefWdbeMUnit,
		rec->Fullsref.c_str(),
		(char*) &_clrRefWdbeMSignal,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeMController_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMController::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMController::updateRst(
			ListWdbeMController& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMController::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMController_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMController::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMController::loadRecByRef(
			ubigint ref
			, WdbeMController** rec
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

	return loadRecByStmt("TblWdbeMController_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMController::loadFsrByRef(
			ubigint ref
			, string& Fullsref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMController_loadFsrByRef", 1, vals, l, f, Fullsref);
};

bool PgTblWdbeMController::loadRecByMdl(
			ubigint refWdbeMModule
			, WdbeMController** rec
		) {
	ubigint _refWdbeMModule = htonl64(refWdbeMModule);

	const char* vals[] = {
		(char*) &_refWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMController_loadRecByMdl", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMController::loadRefsByMdl(
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

	return loadRefsByStmt("TblWdbeMController_loadRefsByMdl", 1, vals, l, f, append, refs);
};

#endif
