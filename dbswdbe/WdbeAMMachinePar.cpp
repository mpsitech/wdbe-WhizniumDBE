/**
	* \file WdbeAMMachinePar.cpp
	* database access for table TblWdbeAMMachinePar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeAMMachinePar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMMachinePar
 ******************************************************************************/

WdbeAMMachinePar::WdbeAMMachinePar(
			const ubigint ref
			, const ubigint refWdbeMMachine
			, const string x1SrefKKey
			, const string Val
		) {

	this->ref = ref;
	this->refWdbeMMachine = refWdbeMMachine;
	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

bool WdbeAMMachinePar::operator==(
			const WdbeAMMachinePar& comp
		) {
	return false;
};

bool WdbeAMMachinePar::operator!=(
			const WdbeAMMachinePar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMMachinePar
 ******************************************************************************/

ListWdbeAMMachinePar::ListWdbeAMMachinePar() {
};

ListWdbeAMMachinePar::ListWdbeAMMachinePar(
			const ListWdbeAMMachinePar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMMachinePar(*(src.nodes[i]));
};

ListWdbeAMMachinePar::~ListWdbeAMMachinePar() {
	clear();
};

void ListWdbeAMMachinePar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMMachinePar::size() const {
	return(nodes.size());
};

void ListWdbeAMMachinePar::append(
			WdbeAMMachinePar* rec
		) {
	nodes.push_back(rec);
};

WdbeAMMachinePar* ListWdbeAMMachinePar::operator[](
			const uint ix
		) {
	WdbeAMMachinePar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMMachinePar& ListWdbeAMMachinePar::operator=(
			const ListWdbeAMMachinePar& src
		) {
	WdbeAMMachinePar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMMachinePar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMMachinePar::operator==(
			const ListWdbeAMMachinePar& comp
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

bool ListWdbeAMMachinePar::operator!=(
			const ListWdbeAMMachinePar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMMachinePar
 ******************************************************************************/

TblWdbeAMMachinePar::TblWdbeAMMachinePar() {
};

TblWdbeAMMachinePar::~TblWdbeAMMachinePar() {
};

bool TblWdbeAMMachinePar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMMachinePar** rec
		) {
	return false;
};

ubigint TblWdbeAMMachinePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMMachinePar& rst
		) {
	return 0;
};

ubigint TblWdbeAMMachinePar::insertRec(
			WdbeAMMachinePar* rec
		) {
	return 0;
};

ubigint TblWdbeAMMachinePar::insertNewRec(
			WdbeAMMachinePar** rec
			, const ubigint refWdbeMMachine
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMMachinePar* _rec = NULL;

	_rec = new WdbeAMMachinePar(0, refWdbeMMachine, x1SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMMachinePar::appendNewRecToRst(
			ListWdbeAMMachinePar& rst
			, WdbeAMMachinePar** rec
			, const ubigint refWdbeMMachine
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMMachinePar* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMMachine, x1SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMMachinePar::insertRst(
			ListWdbeAMMachinePar& rst
			, bool transact
		) {
};

void TblWdbeAMMachinePar::updateRec(
			WdbeAMMachinePar* rec
		) {
};

void TblWdbeAMMachinePar::updateRst(
			ListWdbeAMMachinePar& rst
			, bool transact
		) {
};

void TblWdbeAMMachinePar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMMachinePar::loadRecByRef(
			ubigint ref
			, WdbeAMMachinePar** rec
		) {
	return false;
};

ubigint TblWdbeAMMachinePar::loadRefsByMch(
			ubigint refWdbeMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMMachinePar::loadRstByMch(
			ubigint refWdbeMMachine
			, const bool append
			, ListWdbeAMMachinePar& rst
		) {
	return 0;
};

ubigint TblWdbeAMMachinePar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMMachinePar& rst
		) {
	ubigint numload = 0;
	WdbeAMMachinePar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMMachinePar
 ******************************************************************************/

MyTblWdbeAMMachinePar::MyTblWdbeAMMachinePar() :
			TblWdbeAMMachinePar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMMachinePar::~MyTblWdbeAMMachinePar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMMachinePar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMMachinePar (refWdbeMMachine, x1SrefKKey, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMMachinePar SET refWdbeMMachine = ?, x1SrefKKey = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMMachinePar WHERE ref = ?", false);
};

bool MyTblWdbeAMMachinePar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMMachinePar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMMachinePar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMMachinePar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMMachinePar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMMachinePar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMMachine = atoll((char*) dbrow[1]); else _rec->refWdbeMMachine = 0;
		if (dbrow[2]) _rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKKey = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMMachinePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMMachinePar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMMachinePar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMMachinePar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMMachinePar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMMachinePar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMMachine = atoll((char*) dbrow[1]); else rec->refWdbeMMachine = 0;
			if (dbrow[2]) rec->x1SrefKKey.assign(dbrow[2], dblengths[2]); else rec->x1SrefKKey = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMMachinePar::insertRec(
			WdbeAMMachinePar* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMMachinePar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMMachinePar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMMachinePar::insertRst(
			ListWdbeAMMachinePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMMachinePar::updateRec(
			WdbeAMMachinePar* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKKey.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMMachinePar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMMachinePar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMMachinePar::updateRst(
			ListWdbeAMMachinePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMMachinePar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMMachinePar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMMachinePar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMMachinePar::loadRecByRef(
			ubigint ref
			, WdbeAMMachinePar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMMachinePar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMMachinePar::loadRefsByMch(
			ubigint refWdbeMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMMachinePar WHERE refWdbeMMachine = " + to_string(refWdbeMMachine) + "", append, refs);
};

ubigint MyTblWdbeAMMachinePar::loadRstByMch(
			ubigint refWdbeMMachine
			, const bool append
			, ListWdbeAMMachinePar& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMMachine, x1SrefKKey, Val FROM TblWdbeAMMachinePar WHERE refWdbeMMachine = " + to_string(refWdbeMMachine) + " ORDER BY x1SrefKKey ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMMachinePar
 ******************************************************************************/

PgTblWdbeAMMachinePar::PgTblWdbeAMMachinePar() :
			TblWdbeAMMachinePar()
			, PgTable()
		{
};

PgTblWdbeAMMachinePar::~PgTblWdbeAMMachinePar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMMachinePar::initStatements() {
	createStatement("TblWdbeAMMachinePar_insertRec", "INSERT INTO TblWdbeAMMachinePar (refWdbeMMachine, x1SrefKKey, Val) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeAMMachinePar_updateRec", "UPDATE TblWdbeAMMachinePar SET refWdbeMMachine = $1, x1SrefKKey = $2, Val = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeAMMachinePar_removeRecByRef", "DELETE FROM TblWdbeAMMachinePar WHERE ref = $1", 1);

	createStatement("TblWdbeAMMachinePar_loadRecByRef", "SELECT ref, refWdbeMMachine, x1SrefKKey, Val FROM TblWdbeAMMachinePar WHERE ref = $1", 1);
	createStatement("TblWdbeAMMachinePar_loadRefsByMch", "SELECT ref FROM TblWdbeAMMachinePar WHERE refWdbeMMachine = $1", 1);
	createStatement("TblWdbeAMMachinePar_loadRstByMch", "SELECT ref, refWdbeMMachine, x1SrefKKey, Val FROM TblWdbeAMMachinePar WHERE refWdbeMMachine = $1 ORDER BY x1SrefKKey ASC", 1);
};

bool PgTblWdbeAMMachinePar::loadRec(
			PGresult* res
			, WdbeAMMachinePar** rec
		) {
	char* ptr;

	WdbeAMMachinePar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMMachinePar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmachine"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMMachinePar::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMMachinePar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMMachinePar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmachine"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WdbeAMMachinePar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMMachinePar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMMachinePar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMMachinePar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMMachinePar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMMachinePar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMMachinePar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMMachinePar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMMachinePar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMMachinePar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMMachinePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMMachinePar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMMachinePar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMMachinePar::insertRec(
			WdbeAMMachinePar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMMachine = htonl64(rec->refWdbeMMachine);

	const char* vals[] = {
		(char*) &_refWdbeMMachine,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMMachinePar_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMMachinePar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMMachinePar::insertRst(
			ListWdbeAMMachinePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMMachinePar::updateRec(
			WdbeAMMachinePar* rec
		) {
	PGresult* res;

	ubigint _refWdbeMMachine = htonl64(rec->refWdbeMMachine);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMMachine,
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

	res = PQexecPrepared(dbs, "TblWdbeAMMachinePar_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMMachinePar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMMachinePar::updateRst(
			ListWdbeAMMachinePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMMachinePar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMMachinePar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMMachinePar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMMachinePar::loadRecByRef(
			ubigint ref
			, WdbeAMMachinePar** rec
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

	return loadRecByStmt("TblWdbeAMMachinePar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMMachinePar::loadRefsByMch(
			ubigint refWdbeMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMMachine = htonl64(refWdbeMMachine);

	const char* vals[] = {
		(char*) &_refWdbeMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMMachinePar_loadRefsByMch", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMMachinePar::loadRstByMch(
			ubigint refWdbeMMachine
			, const bool append
			, ListWdbeAMMachinePar& rst
		) {
	ubigint _refWdbeMMachine = htonl64(refWdbeMMachine);

	const char* vals[] = {
		(char*) &_refWdbeMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMMachinePar_loadRstByMch", 1, vals, l, f, append, rst);
};

#endif

