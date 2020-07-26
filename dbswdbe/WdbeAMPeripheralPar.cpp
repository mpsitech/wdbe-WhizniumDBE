/**
	* \file WdbeAMPeripheralPar.cpp
	* database access for table TblWdbeAMPeripheralPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeAMPeripheralPar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMPeripheralPar
 ******************************************************************************/

WdbeAMPeripheralPar::WdbeAMPeripheralPar(
			const ubigint ref
			, const ubigint refWdbeMPeripheral
			, const string x1SrefKKey
			, const string Val
		) {

	this->ref = ref;
	this->refWdbeMPeripheral = refWdbeMPeripheral;
	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

bool WdbeAMPeripheralPar::operator==(
			const WdbeAMPeripheralPar& comp
		) {
	return false;
};

bool WdbeAMPeripheralPar::operator!=(
			const WdbeAMPeripheralPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMPeripheralPar
 ******************************************************************************/

ListWdbeAMPeripheralPar::ListWdbeAMPeripheralPar() {
};

ListWdbeAMPeripheralPar::ListWdbeAMPeripheralPar(
			const ListWdbeAMPeripheralPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMPeripheralPar(*(src.nodes[i]));
};

ListWdbeAMPeripheralPar::~ListWdbeAMPeripheralPar() {
	clear();
};

void ListWdbeAMPeripheralPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMPeripheralPar::size() const {
	return(nodes.size());
};

void ListWdbeAMPeripheralPar::append(
			WdbeAMPeripheralPar* rec
		) {
	nodes.push_back(rec);
};

WdbeAMPeripheralPar* ListWdbeAMPeripheralPar::operator[](
			const uint ix
		) {
	WdbeAMPeripheralPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMPeripheralPar& ListWdbeAMPeripheralPar::operator=(
			const ListWdbeAMPeripheralPar& src
		) {
	WdbeAMPeripheralPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMPeripheralPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMPeripheralPar::operator==(
			const ListWdbeAMPeripheralPar& comp
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

bool ListWdbeAMPeripheralPar::operator!=(
			const ListWdbeAMPeripheralPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMPeripheralPar
 ******************************************************************************/

TblWdbeAMPeripheralPar::TblWdbeAMPeripheralPar() {
};

TblWdbeAMPeripheralPar::~TblWdbeAMPeripheralPar() {
};

bool TblWdbeAMPeripheralPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMPeripheralPar** rec
		) {
	return false;
};

ubigint TblWdbeAMPeripheralPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMPeripheralPar& rst
		) {
	return 0;
};

ubigint TblWdbeAMPeripheralPar::insertRec(
			WdbeAMPeripheralPar* rec
		) {
	return 0;
};

ubigint TblWdbeAMPeripheralPar::insertNewRec(
			WdbeAMPeripheralPar** rec
			, const ubigint refWdbeMPeripheral
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMPeripheralPar* _rec = NULL;

	_rec = new WdbeAMPeripheralPar(0, refWdbeMPeripheral, x1SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMPeripheralPar::appendNewRecToRst(
			ListWdbeAMPeripheralPar& rst
			, WdbeAMPeripheralPar** rec
			, const ubigint refWdbeMPeripheral
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMPeripheralPar* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMPeripheral, x1SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMPeripheralPar::insertRst(
			ListWdbeAMPeripheralPar& rst
			, bool transact
		) {
};

void TblWdbeAMPeripheralPar::updateRec(
			WdbeAMPeripheralPar* rec
		) {
};

void TblWdbeAMPeripheralPar::updateRst(
			ListWdbeAMPeripheralPar& rst
			, bool transact
		) {
};

void TblWdbeAMPeripheralPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMPeripheralPar::loadRecByRef(
			ubigint ref
			, WdbeAMPeripheralPar** rec
		) {
	return false;
};

ubigint TblWdbeAMPeripheralPar::loadRefsByPph(
			ubigint refWdbeMPeripheral
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMPeripheralPar::loadRstByPph(
			ubigint refWdbeMPeripheral
			, const bool append
			, ListWdbeAMPeripheralPar& rst
		) {
	return 0;
};

ubigint TblWdbeAMPeripheralPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMPeripheralPar& rst
		) {
	ubigint numload = 0;
	WdbeAMPeripheralPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMPeripheralPar
 ******************************************************************************/

MyTblWdbeAMPeripheralPar::MyTblWdbeAMPeripheralPar() :
			TblWdbeAMPeripheralPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMPeripheralPar::~MyTblWdbeAMPeripheralPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMPeripheralPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMPeripheralPar (refWdbeMPeripheral, x1SrefKKey, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMPeripheralPar SET refWdbeMPeripheral = ?, x1SrefKKey = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMPeripheralPar WHERE ref = ?", false);
};

bool MyTblWdbeAMPeripheralPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMPeripheralPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMPeripheralPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMPeripheralPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMPeripheralPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMPeripheralPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMPeripheral = atoll((char*) dbrow[1]); else _rec->refWdbeMPeripheral = 0;
		if (dbrow[2]) _rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKKey = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMPeripheralPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMPeripheralPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMPeripheralPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMPeripheralPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMPeripheralPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMPeripheralPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMPeripheral = atoll((char*) dbrow[1]); else rec->refWdbeMPeripheral = 0;
			if (dbrow[2]) rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else rec->x1SrefKKey = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMPeripheralPar::insertRec(
			WdbeAMPeripheralPar* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMPeripheral,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMPeripheralPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMPeripheralPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMPeripheralPar::insertRst(
			ListWdbeAMPeripheralPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMPeripheralPar::updateRec(
			WdbeAMPeripheralPar* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMPeripheral,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMPeripheralPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMPeripheralPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMPeripheralPar::updateRst(
			ListWdbeAMPeripheralPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMPeripheralPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMPeripheralPar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMPeripheralPar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMPeripheralPar::loadRecByRef(
			ubigint ref
			, WdbeAMPeripheralPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMPeripheralPar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMPeripheralPar::loadRefsByPph(
			ubigint refWdbeMPeripheral
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMPeripheralPar WHERE refWdbeMPeripheral = " + to_string(refWdbeMPeripheral) + "", append, refs);
};

ubigint MyTblWdbeAMPeripheralPar::loadRstByPph(
			ubigint refWdbeMPeripheral
			, const bool append
			, ListWdbeAMPeripheralPar& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMPeripheral, x1SrefKKey, Val FROM TblWdbeAMPeripheralPar WHERE refWdbeMPeripheral = " + to_string(refWdbeMPeripheral) + " ORDER BY x1SrefKKey ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMPeripheralPar
 ******************************************************************************/

PgTblWdbeAMPeripheralPar::PgTblWdbeAMPeripheralPar() :
			TblWdbeAMPeripheralPar()
			, PgTable()
		{
};

PgTblWdbeAMPeripheralPar::~PgTblWdbeAMPeripheralPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMPeripheralPar::initStatements() {
	createStatement("TblWdbeAMPeripheralPar_insertRec", "INSERT INTO TblWdbeAMPeripheralPar (refWdbeMPeripheral, x1SrefKKey, Val) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeAMPeripheralPar_updateRec", "UPDATE TblWdbeAMPeripheralPar SET refWdbeMPeripheral = $1, x1SrefKKey = $2, Val = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeAMPeripheralPar_removeRecByRef", "DELETE FROM TblWdbeAMPeripheralPar WHERE ref = $1", 1);

	createStatement("TblWdbeAMPeripheralPar_loadRecByRef", "SELECT ref, refWdbeMPeripheral, x1SrefKKey, Val FROM TblWdbeAMPeripheralPar WHERE ref = $1", 1);
	createStatement("TblWdbeAMPeripheralPar_loadRefsByPph", "SELECT ref FROM TblWdbeAMPeripheralPar WHERE refWdbeMPeripheral = $1", 1);
	createStatement("TblWdbeAMPeripheralPar_loadRstByPph", "SELECT ref, refWdbeMPeripheral, x1SrefKKey, Val FROM TblWdbeAMPeripheralPar WHERE refWdbeMPeripheral = $1 ORDER BY x1SrefKKey ASC", 1);
};

bool PgTblWdbeAMPeripheralPar::loadRec(
			PGresult* res
			, WdbeAMPeripheralPar** rec
		) {
	char* ptr;

	WdbeAMPeripheralPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMPeripheralPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemperipheral"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMPeripheral = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMPeripheralPar::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMPeripheralPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMPeripheralPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemperipheral"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WdbeAMPeripheralPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMPeripheral = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMPeripheralPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMPeripheralPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPeripheralPar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMPeripheralPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMPeripheralPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPeripheralPar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMPeripheralPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMPeripheralPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPeripheralPar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMPeripheralPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMPeripheralPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPeripheralPar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMPeripheralPar::insertRec(
			WdbeAMPeripheralPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMPeripheral = htonl64(rec->refWdbeMPeripheral);

	const char* vals[] = {
		(char*) &_refWdbeMPeripheral,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMPeripheralPar_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPeripheralPar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMPeripheralPar::insertRst(
			ListWdbeAMPeripheralPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMPeripheralPar::updateRec(
			WdbeAMPeripheralPar* rec
		) {
	PGresult* res;

	ubigint _refWdbeMPeripheral = htonl64(rec->refWdbeMPeripheral);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMPeripheral,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMPeripheralPar_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMPeripheralPar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMPeripheralPar::updateRst(
			ListWdbeAMPeripheralPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMPeripheralPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMPeripheralPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMPeripheralPar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMPeripheralPar::loadRecByRef(
			ubigint ref
			, WdbeAMPeripheralPar** rec
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

	return loadRecByStmt("TblWdbeAMPeripheralPar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMPeripheralPar::loadRefsByPph(
			ubigint refWdbeMPeripheral
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMPeripheral = htonl64(refWdbeMPeripheral);

	const char* vals[] = {
		(char*) &_refWdbeMPeripheral
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMPeripheralPar_loadRefsByPph", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMPeripheralPar::loadRstByPph(
			ubigint refWdbeMPeripheral
			, const bool append
			, ListWdbeAMPeripheralPar& rst
		) {
	ubigint _refWdbeMPeripheral = htonl64(refWdbeMPeripheral);

	const char* vals[] = {
		(char*) &_refWdbeMPeripheral
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMPeripheralPar_loadRstByPph", 1, vals, l, f, append, rst);
};

#endif

