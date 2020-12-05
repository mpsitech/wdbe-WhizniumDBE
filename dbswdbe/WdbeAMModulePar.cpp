/**
	* \file WdbeAMModulePar.cpp
	* database access for table TblWdbeAMModulePar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAMModulePar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMModulePar
 ******************************************************************************/

WdbeAMModulePar::WdbeAMModulePar(
			const ubigint ref
			, const ubigint mdlRefWdbeMModule
			, const uint mdlNum
			, const string x1SrefKKey
			, const string Val
		) {

	this->ref = ref;
	this->mdlRefWdbeMModule = mdlRefWdbeMModule;
	this->mdlNum = mdlNum;
	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

bool WdbeAMModulePar::operator==(
			const WdbeAMModulePar& comp
		) {
	return false;
};

bool WdbeAMModulePar::operator!=(
			const WdbeAMModulePar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMModulePar
 ******************************************************************************/

ListWdbeAMModulePar::ListWdbeAMModulePar() {
};

ListWdbeAMModulePar::ListWdbeAMModulePar(
			const ListWdbeAMModulePar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMModulePar(*(src.nodes[i]));
};

ListWdbeAMModulePar::~ListWdbeAMModulePar() {
	clear();
};

void ListWdbeAMModulePar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMModulePar::size() const {
	return(nodes.size());
};

void ListWdbeAMModulePar::append(
			WdbeAMModulePar* rec
		) {
	nodes.push_back(rec);
};

WdbeAMModulePar* ListWdbeAMModulePar::operator[](
			const uint ix
		) {
	WdbeAMModulePar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMModulePar& ListWdbeAMModulePar::operator=(
			const ListWdbeAMModulePar& src
		) {
	WdbeAMModulePar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMModulePar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMModulePar::operator==(
			const ListWdbeAMModulePar& comp
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

bool ListWdbeAMModulePar::operator!=(
			const ListWdbeAMModulePar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMModulePar
 ******************************************************************************/

TblWdbeAMModulePar::TblWdbeAMModulePar() {
};

TblWdbeAMModulePar::~TblWdbeAMModulePar() {
};

bool TblWdbeAMModulePar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMModulePar** rec
		) {
	return false;
};

ubigint TblWdbeAMModulePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMModulePar& rst
		) {
	return 0;
};

ubigint TblWdbeAMModulePar::insertRec(
			WdbeAMModulePar* rec
		) {
	return 0;
};

ubigint TblWdbeAMModulePar::insertNewRec(
			WdbeAMModulePar** rec
			, const ubigint mdlRefWdbeMModule
			, const uint mdlNum
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMModulePar* _rec = NULL;

	_rec = new WdbeAMModulePar(0, mdlRefWdbeMModule, mdlNum, x1SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMModulePar::appendNewRecToRst(
			ListWdbeAMModulePar& rst
			, WdbeAMModulePar** rec
			, const ubigint mdlRefWdbeMModule
			, const uint mdlNum
			, const string x1SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMModulePar* _rec = NULL;

	retval = insertNewRec(&_rec, mdlRefWdbeMModule, mdlNum, x1SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMModulePar::insertRst(
			ListWdbeAMModulePar& rst
			, bool transact
		) {
};

void TblWdbeAMModulePar::updateRec(
			WdbeAMModulePar* rec
		) {
};

void TblWdbeAMModulePar::updateRst(
			ListWdbeAMModulePar& rst
			, bool transact
		) {
};

void TblWdbeAMModulePar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMModulePar::loadRecByRef(
			ubigint ref
			, WdbeAMModulePar** rec
		) {
	return false;
};

ubigint TblWdbeAMModulePar::loadRefsByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMModulePar::loadRstByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, ListWdbeAMModulePar& rst
		) {
	return 0;
};

ubigint TblWdbeAMModulePar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMModulePar& rst
		) {
	ubigint numload = 0;
	WdbeAMModulePar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMModulePar
 ******************************************************************************/

MyTblWdbeAMModulePar::MyTblWdbeAMModulePar() :
			TblWdbeAMModulePar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMModulePar::~MyTblWdbeAMModulePar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMModulePar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMModulePar (mdlRefWdbeMModule, mdlNum, x1SrefKKey, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMModulePar SET mdlRefWdbeMModule = ?, mdlNum = ?, x1SrefKKey = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMModulePar WHERE ref = ?", false);
};

bool MyTblWdbeAMModulePar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMModulePar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMModulePar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMModulePar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMModulePar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMModulePar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->mdlRefWdbeMModule = atoll((char*) dbrow[1]); else _rec->mdlRefWdbeMModule = 0;
		if (dbrow[2]) _rec->mdlNum = atol((char*) dbrow[2]); else _rec->mdlNum = 0;
		if (dbrow[3]) _rec->x1SrefKKey.assign(dbrow[3], dblengths[3]); else _rec->x1SrefKKey = "";
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMModulePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMModulePar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMModulePar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMModulePar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMModulePar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMModulePar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->mdlRefWdbeMModule = atoll((char*) dbrow[1]); else rec->mdlRefWdbeMModule = 0;
			if (dbrow[2]) rec->mdlNum = atol((char*) dbrow[2]); else rec->mdlNum = 0;
			if (dbrow[3]) rec->x1SrefKKey.assign(dbrow[3], dblengths[3]); else rec->x1SrefKKey = "";
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMModulePar::insertRec(
			WdbeAMModulePar* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x1SrefKKey.length();
	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->mdlNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMModulePar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMModulePar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMModulePar::insertRst(
			ListWdbeAMModulePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMModulePar::updateRec(
			WdbeAMModulePar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x1SrefKKey.length();
	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->mdlNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x1SrefKKey.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMModulePar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMModulePar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMModulePar::updateRst(
			ListWdbeAMModulePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMModulePar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMModulePar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMModulePar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMModulePar::loadRecByRef(
			ubigint ref
			, WdbeAMModulePar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMModulePar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMModulePar::loadRefsByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMModulePar WHERE mdlRefWdbeMModule = " + to_string(mdlRefWdbeMModule) + "", append, refs);
};

ubigint MyTblWdbeAMModulePar::loadRstByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, ListWdbeAMModulePar& rst
		) {
	return loadRstBySQL("SELECT ref, mdlRefWdbeMModule, mdlNum, x1SrefKKey, Val FROM TblWdbeAMModulePar WHERE mdlRefWdbeMModule = " + to_string(mdlRefWdbeMModule) + " ORDER BY mdlNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMModulePar
 ******************************************************************************/

PgTblWdbeAMModulePar::PgTblWdbeAMModulePar() :
			TblWdbeAMModulePar()
			, PgTable()
		{
};

PgTblWdbeAMModulePar::~PgTblWdbeAMModulePar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMModulePar::initStatements() {
	createStatement("TblWdbeAMModulePar_insertRec", "INSERT INTO TblWdbeAMModulePar (mdlRefWdbeMModule, mdlNum, x1SrefKKey, Val) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeAMModulePar_updateRec", "UPDATE TblWdbeAMModulePar SET mdlRefWdbeMModule = $1, mdlNum = $2, x1SrefKKey = $3, Val = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeAMModulePar_removeRecByRef", "DELETE FROM TblWdbeAMModulePar WHERE ref = $1", 1);

	createStatement("TblWdbeAMModulePar_loadRecByRef", "SELECT ref, mdlRefWdbeMModule, mdlNum, x1SrefKKey, Val FROM TblWdbeAMModulePar WHERE ref = $1", 1);
	createStatement("TblWdbeAMModulePar_loadRefsByMdl", "SELECT ref FROM TblWdbeAMModulePar WHERE mdlRefWdbeMModule = $1", 1);
	createStatement("TblWdbeAMModulePar_loadRstByMdl", "SELECT ref, mdlRefWdbeMModule, mdlNum, x1SrefKKey, Val FROM TblWdbeAMModulePar WHERE mdlRefWdbeMModule = $1 ORDER BY mdlNum ASC", 1);
};

bool PgTblWdbeAMModulePar::loadRec(
			PGresult* res
			, WdbeAMModulePar** rec
		) {
	char* ptr;

	WdbeAMModulePar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMModulePar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "mdlrefwdbemmodule"),
			PQfnumber(res, "mdlnum"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->mdlRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->mdlNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMModulePar::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMModulePar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMModulePar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "mdlrefwdbemmodule"),
			PQfnumber(res, "mdlnum"),
			PQfnumber(res, "x1srefkkey"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WdbeAMModulePar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->mdlRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->mdlNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMModulePar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMModulePar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMModulePar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMModulePar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMModulePar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMModulePar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMModulePar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMModulePar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMModulePar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMModulePar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMModulePar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMModulePar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMModulePar::insertRec(
			WdbeAMModulePar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	uint _mdlNum = htonl(rec->mdlNum);

	const char* vals[] = {
		(char*) &_mdlRefWdbeMModule,
		(char*) &_mdlNum,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMModulePar_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMModulePar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMModulePar::insertRst(
			ListWdbeAMModulePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMModulePar::updateRec(
			WdbeAMModulePar* rec
		) {
	PGresult* res;

	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	uint _mdlNum = htonl(rec->mdlNum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_mdlRefWdbeMModule,
		(char*) &_mdlNum,
		rec->x1SrefKKey.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMModulePar_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMModulePar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMModulePar::updateRst(
			ListWdbeAMModulePar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMModulePar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMModulePar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMModulePar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMModulePar::loadRecByRef(
			ubigint ref
			, WdbeAMModulePar** rec
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

	return loadRecByStmt("TblWdbeAMModulePar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMModulePar::loadRefsByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _mdlRefWdbeMModule = htonl64(mdlRefWdbeMModule);

	const char* vals[] = {
		(char*) &_mdlRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMModulePar_loadRefsByMdl", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMModulePar::loadRstByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, ListWdbeAMModulePar& rst
		) {
	ubigint _mdlRefWdbeMModule = htonl64(mdlRefWdbeMModule);

	const char* vals[] = {
		(char*) &_mdlRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMModulePar_loadRstByMdl", 1, vals, l, f, append, rst);
};

#endif

