/**
	* \file WdbeRMCdcMSignal.cpp
	* database access for table TblWdbeRMCdcMSignal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#include "WdbeRMCdcMSignal.h"

#include "WdbeRMCdcMSignal_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeRMCdcMSignal
 ******************************************************************************/

WdbeRMCdcMSignal::WdbeRMCdcMSignal(
			const ubigint ref
			, const ubigint refWdbeMCdc
			, const ubigint refWdbeMSignal
			, const uint ixVDir
		) {

	this->ref = ref;
	this->refWdbeMCdc = refWdbeMCdc;
	this->refWdbeMSignal = refWdbeMSignal;
	this->ixVDir = ixVDir;
};

bool WdbeRMCdcMSignal::operator==(
			const WdbeRMCdcMSignal& comp
		) {
	return false;
};

bool WdbeRMCdcMSignal::operator!=(
			const WdbeRMCdcMSignal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeRMCdcMSignal
 ******************************************************************************/

ListWdbeRMCdcMSignal::ListWdbeRMCdcMSignal() {
};

ListWdbeRMCdcMSignal::ListWdbeRMCdcMSignal(
			const ListWdbeRMCdcMSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeRMCdcMSignal(*(src.nodes[i]));
};

ListWdbeRMCdcMSignal::~ListWdbeRMCdcMSignal() {
	clear();
};

void ListWdbeRMCdcMSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeRMCdcMSignal::size() const {
	return(nodes.size());
};

void ListWdbeRMCdcMSignal::append(
			WdbeRMCdcMSignal* rec
		) {
	nodes.push_back(rec);
};

WdbeRMCdcMSignal* ListWdbeRMCdcMSignal::operator[](
			const uint ix
		) {
	WdbeRMCdcMSignal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeRMCdcMSignal& ListWdbeRMCdcMSignal::operator=(
			const ListWdbeRMCdcMSignal& src
		) {
	WdbeRMCdcMSignal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeRMCdcMSignal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeRMCdcMSignal::operator==(
			const ListWdbeRMCdcMSignal& comp
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

bool ListWdbeRMCdcMSignal::operator!=(
			const ListWdbeRMCdcMSignal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeRMCdcMSignal
 ******************************************************************************/

TblWdbeRMCdcMSignal::TblWdbeRMCdcMSignal() {
};

TblWdbeRMCdcMSignal::~TblWdbeRMCdcMSignal() {
};

bool TblWdbeRMCdcMSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeRMCdcMSignal** rec
		) {
	return false;
};

ubigint TblWdbeRMCdcMSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	return 0;
};

ubigint TblWdbeRMCdcMSignal::insertRec(
			WdbeRMCdcMSignal* rec
		) {
	return 0;
};

ubigint TblWdbeRMCdcMSignal::insertNewRec(
			WdbeRMCdcMSignal** rec
			, const ubigint refWdbeMCdc
			, const ubigint refWdbeMSignal
			, const uint ixVDir
		) {
	ubigint retval = 0;
	WdbeRMCdcMSignal* _rec = NULL;

	_rec = new WdbeRMCdcMSignal(0, refWdbeMCdc, refWdbeMSignal, ixVDir);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeRMCdcMSignal::appendNewRecToRst(
			ListWdbeRMCdcMSignal& rst
			, WdbeRMCdcMSignal** rec
			, const ubigint refWdbeMCdc
			, const ubigint refWdbeMSignal
			, const uint ixVDir
		) {
	ubigint retval = 0;
	WdbeRMCdcMSignal* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMCdc, refWdbeMSignal, ixVDir);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeRMCdcMSignal::insertRst(
			ListWdbeRMCdcMSignal& rst
			, bool transact
		) {
};

void TblWdbeRMCdcMSignal::updateRec(
			WdbeRMCdcMSignal* rec
		) {
};

void TblWdbeRMCdcMSignal::updateRst(
			ListWdbeRMCdcMSignal& rst
			, bool transact
		) {
};

void TblWdbeRMCdcMSignal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeRMCdcMSignal::loadRecByRef(
			ubigint ref
			, WdbeRMCdcMSignal** rec
		) {
	return false;
};

ubigint TblWdbeRMCdcMSignal::loadRefsByCdc(
			ubigint refWdbeMCdc
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeRMCdcMSignal::loadRstByCdc(
			ubigint refWdbeMCdc
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	return 0;
};

ubigint TblWdbeRMCdcMSignal::loadRstBySig(
			ubigint refWdbeMSignal
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	return 0;
};

ubigint TblWdbeRMCdcMSignal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	ubigint numload = 0;
	WdbeRMCdcMSignal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeRMCdcMSignal
 ******************************************************************************/

MyTblWdbeRMCdcMSignal::MyTblWdbeRMCdcMSignal() :
			TblWdbeRMCdcMSignal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeRMCdcMSignal::~MyTblWdbeRMCdcMSignal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeRMCdcMSignal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeRMCdcMSignal (refWdbeMCdc, refWdbeMSignal, ixVDir) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeRMCdcMSignal SET refWdbeMCdc = ?, refWdbeMSignal = ?, ixVDir = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeRMCdcMSignal WHERE ref = ?", false);
};

bool MyTblWdbeRMCdcMSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeRMCdcMSignal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeRMCdcMSignal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMCdcMSignal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMCdcMSignal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeRMCdcMSignal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMCdc = atoll((char*) dbrow[1]); else _rec->refWdbeMCdc = 0;
		if (dbrow[2]) _rec->refWdbeMSignal = atoll((char*) dbrow[2]); else _rec->refWdbeMSignal = 0;
		if (dbrow[3]) _rec->ixVDir = atol((char*) dbrow[3]); else _rec->ixVDir = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeRMCdcMSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeRMCdcMSignal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMCdcMSignal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMCdcMSignal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeRMCdcMSignal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMCdc = atoll((char*) dbrow[1]); else rec->refWdbeMCdc = 0;
			if (dbrow[2]) rec->refWdbeMSignal = atoll((char*) dbrow[2]); else rec->refWdbeMSignal = 0;
			if (dbrow[3]) rec->ixVDir = atol((char*) dbrow[3]); else rec->ixVDir = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeRMCdcMSignal::insertRec(
			WdbeRMCdcMSignal* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMCdc,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMSignal,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVDir,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeRMCdcMSignal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeRMCdcMSignal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeRMCdcMSignal::insertRst(
			ListWdbeRMCdcMSignal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeRMCdcMSignal::updateRec(
			WdbeRMCdcMSignal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMCdc,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMSignal,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVDir,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeRMCdcMSignal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeRMCdcMSignal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeRMCdcMSignal::updateRst(
			ListWdbeRMCdcMSignal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeRMCdcMSignal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeRMCdcMSignal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeRMCdcMSignal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeRMCdcMSignal::loadRecByRef(
			ubigint ref
			, WdbeRMCdcMSignal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeRMCdcMSignal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeRMCdcMSignal::loadRefsByCdc(
			ubigint refWdbeMCdc
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeRMCdcMSignal WHERE refWdbeMCdc = " + to_string(refWdbeMCdc) + "", append, refs);
};

ubigint MyTblWdbeRMCdcMSignal::loadRstByCdc(
			ubigint refWdbeMCdc
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMCdc, refWdbeMSignal, ixVDir FROM TblWdbeRMCdcMSignal WHERE refWdbeMCdc = " + to_string(refWdbeMCdc) + "", append, rst);
};

ubigint MyTblWdbeRMCdcMSignal::loadRstBySig(
			ubigint refWdbeMSignal
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMCdc, refWdbeMSignal, ixVDir FROM TblWdbeRMCdcMSignal WHERE refWdbeMSignal = " + to_string(refWdbeMSignal) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeRMCdcMSignal
 ******************************************************************************/

PgTblWdbeRMCdcMSignal::PgTblWdbeRMCdcMSignal() :
			TblWdbeRMCdcMSignal()
			, PgTable()
		{
};

PgTblWdbeRMCdcMSignal::~PgTblWdbeRMCdcMSignal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeRMCdcMSignal::initStatements() {
	createStatement("TblWdbeRMCdcMSignal_insertRec", "INSERT INTO TblWdbeRMCdcMSignal (refWdbeMCdc, refWdbeMSignal, ixVDir) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeRMCdcMSignal_updateRec", "UPDATE TblWdbeRMCdcMSignal SET refWdbeMCdc = $1, refWdbeMSignal = $2, ixVDir = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeRMCdcMSignal_removeRecByRef", "DELETE FROM TblWdbeRMCdcMSignal WHERE ref = $1", 1);

	createStatement("TblWdbeRMCdcMSignal_loadRecByRef", "SELECT ref, refWdbeMCdc, refWdbeMSignal, ixVDir FROM TblWdbeRMCdcMSignal WHERE ref = $1", 1);
	createStatement("TblWdbeRMCdcMSignal_loadRefsByCdc", "SELECT ref FROM TblWdbeRMCdcMSignal WHERE refWdbeMCdc = $1", 1);
	createStatement("TblWdbeRMCdcMSignal_loadRstByCdc", "SELECT ref, refWdbeMCdc, refWdbeMSignal, ixVDir FROM TblWdbeRMCdcMSignal WHERE refWdbeMCdc = $1", 1);
	createStatement("TblWdbeRMCdcMSignal_loadRstBySig", "SELECT ref, refWdbeMCdc, refWdbeMSignal, ixVDir FROM TblWdbeRMCdcMSignal WHERE refWdbeMSignal = $1", 1);
};

bool PgTblWdbeRMCdcMSignal::loadRec(
			PGresult* res
			, WdbeRMCdcMSignal** rec
		) {
	char* ptr;

	WdbeRMCdcMSignal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeRMCdcMSignal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemcdc"),
			PQfnumber(res, "refwdbemsignal"),
			PQfnumber(res, "ixvdir")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMCdc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMSignal = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVDir = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeRMCdcMSignal::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeRMCdcMSignal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemcdc"),
			PQfnumber(res, "refwdbemsignal"),
			PQfnumber(res, "ixvdir")
		};

		while (numread < numrow) {
			rec = new WdbeRMCdcMSignal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMCdc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMSignal = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVDir = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeRMCdcMSignal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeRMCdcMSignal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCdcMSignal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMCdcMSignal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCdcMSignal::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeRMCdcMSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeRMCdcMSignal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCdcMSignal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMCdcMSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCdcMSignal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeRMCdcMSignal::insertRec(
			WdbeRMCdcMSignal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMCdc = htonl64(rec->refWdbeMCdc);
	ubigint _refWdbeMSignal = htonl64(rec->refWdbeMSignal);
	uint _ixVDir = htonl(rec->ixVDir);

	const char* vals[] = {
		(char*) &_refWdbeMCdc,
		(char*) &_refWdbeMSignal,
		(char*) &_ixVDir
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMCdcMSignal_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCdcMSignal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeRMCdcMSignal::insertRst(
			ListWdbeRMCdcMSignal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeRMCdcMSignal::updateRec(
			WdbeRMCdcMSignal* rec
		) {
	PGresult* res;

	ubigint _refWdbeMCdc = htonl64(rec->refWdbeMCdc);
	ubigint _refWdbeMSignal = htonl64(rec->refWdbeMSignal);
	uint _ixVDir = htonl(rec->ixVDir);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMCdc,
		(char*) &_refWdbeMSignal,
		(char*) &_ixVDir,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMCdcMSignal_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMCdcMSignal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeRMCdcMSignal::updateRst(
			ListWdbeRMCdcMSignal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeRMCdcMSignal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeRMCdcMSignal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMCdcMSignal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeRMCdcMSignal::loadRecByRef(
			ubigint ref
			, WdbeRMCdcMSignal** rec
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

	return loadRecByStmt("TblWdbeRMCdcMSignal_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeRMCdcMSignal::loadRefsByCdc(
			ubigint refWdbeMCdc
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMCdc = htonl64(refWdbeMCdc);

	const char* vals[] = {
		(char*) &_refWdbeMCdc
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMCdcMSignal_loadRefsByCdc", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeRMCdcMSignal::loadRstByCdc(
			ubigint refWdbeMCdc
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	ubigint _refWdbeMCdc = htonl64(refWdbeMCdc);

	const char* vals[] = {
		(char*) &_refWdbeMCdc
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMCdcMSignal_loadRstByCdc", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeRMCdcMSignal::loadRstBySig(
			ubigint refWdbeMSignal
			, const bool append
			, ListWdbeRMCdcMSignal& rst
		) {
	ubigint _refWdbeMSignal = htonl64(refWdbeMSignal);

	const char* vals[] = {
		(char*) &_refWdbeMSignal
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMCdcMSignal_loadRstBySig", 1, vals, l, f, append, rst);
};

#endif
