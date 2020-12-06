/**
	* \file WdbeAMPinPar.cpp
	* database access for table TblWdbeAMPinPar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAMPinPar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMPinPar
 ******************************************************************************/

WdbeAMPinPar::WdbeAMPinPar(
			const ubigint ref
			, const ubigint refWdbeMPin
			, const string x1SrefKKey
			, const string Val
		) {

	this->ref = ref;
	this->refWdbeMPin = refWdbeMPin;
	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

bool WdbeAMPinPar::operator==(
			const WdbeAMPinPar& comp
		) {
	return false;
};

bool WdbeAMPinPar::operator!=(
			const WdbeAMPinPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMPinPar
 ******************************************************************************/

ListWdbeAMPinPar::ListWdbeAMPinPar() {
};

ListWdbeAMPinPar::ListWdbeAMPinPar(
			const ListWdbeAMPinPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMPinPar(*(src.nodes[i]));
};

ListWdbeAMPinPar::~ListWdbeAMPinPar() {
	clear();
};

void ListWdbeAMPinPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMPinPar::size() const {
	return(nodes.size());
};

void ListWdbeAMPinPar::append(
			WdbeAMPinPar* rec
		) {
	nodes.push_back(rec);
};

WdbeAMPinPar* ListWdbeAMPinPar::operator[](
			const uint ix
		) {
	WdbeAMPinPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMPinPar& ListWdbeAMPinPar::operator=(
			const ListWdbeAMPinPar& src
		) {
	WdbeAMPinPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMPinPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMPinPar::operator==(
			const ListWdbeAMPinPar& comp
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

bool ListWdbeAMPinPar::operator!=(
			const ListWdbeAMPinPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMPinPar
 ******************************************************************************/

TblWdbeAMPinPar::TblWdbeAMPinPar() {
};

TblWdbeAMPinPar::~TblWdbeAMPinPar() {
};

bool TblWdbeAMPinPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMPinPar** rec
		) {
	return false;
};

ubigint TblWdbeAMPinPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMPinPar& rst
		) {
	return 0;
};

ubigint TblWdbeAMPinPar::insertRec(
			WdbeAMPinPar* rec
		) {
	return 0;
};

ubigint TblWdbeAMPinPar::insertNewRec(
			WdbeAMPinPar** rec
			, const ubigint refWdbeMPin
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMPinPar* _rec = NULL;

	_rec = new WdbeAMPinPar(0, refWdbeMPin, x1SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMPinPar::appendNewRecToRst(
			ListWdbeAMPinPar& rst
			, WdbeAMPinPar** rec
			, const ubigint refWdbeMPin
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMPinPar* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMPin, x1SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMPinPar::insertRst(
			ListWdbeAMPinPar& rst
			, bool transact
		) {
};

void TblWdbeAMPinPar::updateRec(
			WdbeAMPinPar* rec
		) {
};

void TblWdbeAMPinPar::updateRst(
			ListWdbeAMPinPar& rst
			, bool transact
		) {
};

void TblWdbeAMPinPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMPinPar::loadRecByRef(
			ubigint ref
			, WdbeAMPinPar** rec
		) {
	return false;
};

ubigint TblWdbeAMPinPar::loadRefsByPin(
			ubigint refWdbeMPin
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMPinPar::loadRstByPin(
			ubigint refWdbeMPin
			, const bool append
			, ListWdbeAMPinPar& rst
		) {
	return 0;
};

ubigint TblWdbeAMPinPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMPinPar& rst
		) {
	ubigint numload = 0;
	WdbeAMPinPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMPinPar
 ******************************************************************************/

MyTblWdbeAMPinPar::MyTblWdbeAMPinPar() :
			TblWdbeAMPinPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMPinPar::~MyTblWdbeAMPinPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMPinPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMPinPar (refWdbeMPin, x1SrefKKey, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMPinPar SET refWdbeMPin = ?, x1SrefKKey = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMPinPar WHERE ref = ?", false);
};

bool MyTblWdbeAMPinPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMPinPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMPinPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMPinPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMPinPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMPinPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMPin = atoll((char*) dbrow[1]); else _rec->refWdbeMPin = 0;
		if (dbrow[2]) _rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKKey = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMPinPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMPinPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMPinPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMPinPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMPinPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMPinPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMPin = atoll((char*) dbrow[1]); else rec->refWdbeMPin = 0;
			if (dbrow[2]) rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else rec->x1SrefKKey = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMPinPar::insertRec(
			WdbeAMPinPar* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMPin,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMPinPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMPinPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMPinPar::insertRst(
			ListWdbeAMPinPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMPinPar::updateRec(
			WdbeAMPinPar* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMPin,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMPinPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMPinPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMPinPar::updateRst(
			ListWdbeAMPinPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMPinPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMPinPar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMPinPar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMPinPar::loadRecByRef(
			ubigint ref
			, WdbeAMPinPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMPinPar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMPinPar::loadRefsByPin(
			ubigint refWdbeMPin
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMPinPar WHERE refWdbeMPin = " + to_string(refWdbeMPin) + "", append, refs);
};

ubigint MyTblWdbeAMPinPar::loadRstByPin(
			ubigint refWdbeMPin
			, const bool append
			, ListWdbeAMPinPar& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMPin, x1SrefKKey, Val FROM TblWdbeAMPinPar WHERE refWdbeMPin = " + to_string(refWdbeMPin) + " ORDER BY x1SrefKKey ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMPinPar
 ******************************************************************************/

PgTblWdbeAMPinPar::PgTblWdbeAMPinPar() :
			TblWdbeAMPinPar()
			, PgTable()
		{
};

PgTblWdbeAMPinPar::~PgTblWdbeAMPinPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMPinPar::initStatements() {
	createStatement("TblWdbeAMPinPar_insertRec", "INSERT INTO TblWdbeAMPinPar (refWdbeMPin, x1SrefKKey, Val) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeAMPinPar_updateRec", "UPDATE TblWdbeAMPinPar SET refWdbeMPin = $1, x1SrefKKey = $2, Val = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeAMPinPar_removeRecByRef", "DELETE FROM TblWdbeAMPinPar WHERE ref = $1", 1);

	createStatement("TblWdbeAMPinPar_loadRecByRef", "SELECT ref, refWdbeMPin, x1SrefKKey, Val FROM TblWdbeAMPinPar WHERE ref = $1", 1);
	createStatement("TblWdbeAMPinPar_loadRefsByPin", "SELECT ref FROM TblWdbeAMPinPar WHERE refWdbeMPin = $1", 1);
	createStatement("TblWdbeAMPinPar_loadRstByPin", "SELECT ref, refWdbeMPin, x1SrefKKey, Val FROM TblWdbeAMPinPar WHERE refWdbeMPin = $1 ORDER BY x1SrefKKey ASC", 1);
};

bool PgTblWdbeAMPinPar::loadRec(
			PGresult* res
			, WdbeAMPinPar** rec
		) {
	char* ptr;

	WdbeAMPinPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMPinPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbempin"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMPin = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMPinPar::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMPinPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMPinPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbempin"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WdbeAMPinPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMPin = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMPinPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMPinPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPinPar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMPinPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMPinPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPinPar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMPinPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMPinPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPinPar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMPinPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMPinPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPinPar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMPinPar::insertRec(
			WdbeAMPinPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMPin = htonl64(rec->refWdbeMPin);

	const char* vals[] = {
		(char*) &_refWdbeMPin,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMPinPar_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPinPar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMPinPar::insertRst(
			ListWdbeAMPinPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMPinPar::updateRec(
			WdbeAMPinPar* rec
		) {
	PGresult* res;

	ubigint _refWdbeMPin = htonl64(rec->refWdbeMPin);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMPin,
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

	res = PQexecPrepared(dbs, "TblWdbeAMPinPar_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMPinPar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMPinPar::updateRst(
			ListWdbeAMPinPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMPinPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMPinPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMPinPar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMPinPar::loadRecByRef(
			ubigint ref
			, WdbeAMPinPar** rec
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

	return loadRecByStmt("TblWdbeAMPinPar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMPinPar::loadRefsByPin(
			ubigint refWdbeMPin
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMPin = htonl64(refWdbeMPin);

	const char* vals[] = {
		(char*) &_refWdbeMPin
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMPinPar_loadRefsByPin", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMPinPar::loadRstByPin(
			ubigint refWdbeMPin
			, const bool append
			, ListWdbeAMPinPar& rst
		) {
	ubigint _refWdbeMPin = htonl64(refWdbeMPin);

	const char* vals[] = {
		(char*) &_refWdbeMPin
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMPinPar_loadRstByPin", 1, vals, l, f, append, rst);
};

#endif
