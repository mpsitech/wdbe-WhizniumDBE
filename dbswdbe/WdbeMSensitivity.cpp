/**
	* \file WdbeMSensitivity.cpp
	* database access for table TblWdbeMSensitivity (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeMSensitivity.h"

#include "WdbeMSensitivity_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMSensitivity
 ******************************************************************************/

WdbeMSensitivity::WdbeMSensitivity(
			const ubigint ref
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint srcIxVTbl
			, const ubigint srcUref
		) :
			ref(ref)
			, refIxVTbl(refIxVTbl)
			, refUref(refUref)
			, srcIxVTbl(srcIxVTbl)
			, srcUref(srcUref)
		{
};

bool WdbeMSensitivity::operator==(
			const WdbeMSensitivity& comp
		) {
	return false;
};

bool WdbeMSensitivity::operator!=(
			const WdbeMSensitivity& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMSensitivity
 ******************************************************************************/

ListWdbeMSensitivity::ListWdbeMSensitivity() {
};

ListWdbeMSensitivity::ListWdbeMSensitivity(
			const ListWdbeMSensitivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMSensitivity(*(src.nodes[i]));
};

ListWdbeMSensitivity::~ListWdbeMSensitivity() {
	clear();
};

void ListWdbeMSensitivity::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMSensitivity::size() const {
	return(nodes.size());
};

void ListWdbeMSensitivity::append(
			WdbeMSensitivity* rec
		) {
	nodes.push_back(rec);
};

WdbeMSensitivity* ListWdbeMSensitivity::operator[](
			const uint ix
		) {
	WdbeMSensitivity* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMSensitivity& ListWdbeMSensitivity::operator=(
			const ListWdbeMSensitivity& src
		) {
	WdbeMSensitivity* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMSensitivity(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMSensitivity::operator==(
			const ListWdbeMSensitivity& comp
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

bool ListWdbeMSensitivity::operator!=(
			const ListWdbeMSensitivity& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMSensitivity
 ******************************************************************************/

TblWdbeMSensitivity::TblWdbeMSensitivity() {
};

TblWdbeMSensitivity::~TblWdbeMSensitivity() {
};

bool TblWdbeMSensitivity::loadRecBySQL(
			const string& sqlstr
			, WdbeMSensitivity** rec
		) {
	return false;
};

ubigint TblWdbeMSensitivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSensitivity& rst
		) {
	return 0;
};

ubigint TblWdbeMSensitivity::insertRec(
			WdbeMSensitivity* rec
		) {
	return 0;
};

ubigint TblWdbeMSensitivity::insertNewRec(
			WdbeMSensitivity** rec
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint srcIxVTbl
			, const ubigint srcUref
		) {
	ubigint retval = 0;
	WdbeMSensitivity* _rec = NULL;

	_rec = new WdbeMSensitivity(0, refIxVTbl, refUref, srcIxVTbl, srcUref);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMSensitivity::appendNewRecToRst(
			ListWdbeMSensitivity& rst
			, WdbeMSensitivity** rec
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint srcIxVTbl
			, const ubigint srcUref
		) {
	ubigint retval = 0;
	WdbeMSensitivity* _rec = NULL;

	retval = insertNewRec(&_rec, refIxVTbl, refUref, srcIxVTbl, srcUref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMSensitivity::insertRst(
			ListWdbeMSensitivity& rst
			, bool transact
		) {
};

void TblWdbeMSensitivity::updateRec(
			WdbeMSensitivity* rec
		) {
};

void TblWdbeMSensitivity::updateRst(
			ListWdbeMSensitivity& rst
			, bool transact
		) {
};

void TblWdbeMSensitivity::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMSensitivity::loadRecByRef(
			ubigint ref
			, WdbeMSensitivity** rec
		) {
	return false;
};

ubigint TblWdbeMSensitivity::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMSensitivity::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMSensitivity& rst
		) {
	return 0;
};

ubigint TblWdbeMSensitivity::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMSensitivity& rst
		) {
	ubigint numload = 0;
	WdbeMSensitivity* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMSensitivity
 ******************************************************************************/

MyTblWdbeMSensitivity::MyTblWdbeMSensitivity() :
			TblWdbeMSensitivity()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMSensitivity::~MyTblWdbeMSensitivity() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMSensitivity::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMSensitivity (refIxVTbl, refUref, srcIxVTbl, srcUref) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMSensitivity SET refIxVTbl = ?, refUref = ?, srcIxVTbl = ?, srcUref = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMSensitivity WHERE ref = ?", false);
};

bool MyTblWdbeMSensitivity::loadRecBySQL(
			const string& sqlstr
			, WdbeMSensitivity** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMSensitivity* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMSensitivity::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMSensitivity::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeMSensitivity();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refIxVTbl = atol((char*) dbrow[1]); else _rec->refIxVTbl = 0;
		if (dbrow[2]) _rec->refUref = atoll((char*) dbrow[2]); else _rec->refUref = 0;
		if (dbrow[3]) _rec->srcIxVTbl = atol((char*) dbrow[3]); else _rec->srcIxVTbl = 0;
		if (dbrow[4]) _rec->srcUref = atoll((char*) dbrow[4]); else _rec->srcUref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMSensitivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSensitivity& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMSensitivity* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMSensitivity::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMSensitivity::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeMSensitivity();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refIxVTbl = atol((char*) dbrow[1]); else rec->refIxVTbl = 0;
			if (dbrow[2]) rec->refUref = atoll((char*) dbrow[2]); else rec->refUref = 0;
			if (dbrow[3]) rec->srcIxVTbl = atol((char*) dbrow[3]); else rec->srcIxVTbl = 0;
			if (dbrow[4]) rec->srcUref = atoll((char*) dbrow[4]); else rec->srcUref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMSensitivity::insertRec(
			WdbeMSensitivity* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUint(&rec->refIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refUref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->srcIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->srcUref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMSensitivity::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMSensitivity::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMSensitivity::insertRst(
			ListWdbeMSensitivity& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMSensitivity::updateRec(
			WdbeMSensitivity* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUint(&rec->refIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refUref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->srcIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->srcUref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMSensitivity::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMSensitivity::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMSensitivity::updateRst(
			ListWdbeMSensitivity& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMSensitivity::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMSensitivity::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMSensitivity::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMSensitivity::loadRecByRef(
			ubigint ref
			, WdbeMSensitivity** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMSensitivity WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMSensitivity::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMSensitivity WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", append, refs);
};

ubigint MyTblWdbeMSensitivity::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMSensitivity& rst
		) {
	return loadRstBySQL("SELECT ref, refIxVTbl, refUref, srcIxVTbl, srcUref FROM TblWdbeMSensitivity WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMSensitivity
 ******************************************************************************/

PgTblWdbeMSensitivity::PgTblWdbeMSensitivity() :
			TblWdbeMSensitivity()
			, PgTable()
		{
};

PgTblWdbeMSensitivity::~PgTblWdbeMSensitivity() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMSensitivity::initStatements() {
	createStatement("TblWdbeMSensitivity_insertRec", "INSERT INTO TblWdbeMSensitivity (refIxVTbl, refUref, srcIxVTbl, srcUref) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeMSensitivity_updateRec", "UPDATE TblWdbeMSensitivity SET refIxVTbl = $1, refUref = $2, srcIxVTbl = $3, srcUref = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeMSensitivity_removeRecByRef", "DELETE FROM TblWdbeMSensitivity WHERE ref = $1", 1);

	createStatement("TblWdbeMSensitivity_loadRecByRef", "SELECT ref, refIxVTbl, refUref, srcIxVTbl, srcUref FROM TblWdbeMSensitivity WHERE ref = $1", 1);
	createStatement("TblWdbeMSensitivity_loadRefsByRetReu", "SELECT ref FROM TblWdbeMSensitivity WHERE refIxVTbl = $1 AND refUref = $2", 2);
	createStatement("TblWdbeMSensitivity_loadRstByRetReu", "SELECT ref, refIxVTbl, refUref, srcIxVTbl, srcUref FROM TblWdbeMSensitivity WHERE refIxVTbl = $1 AND refUref = $2", 2);
};

bool PgTblWdbeMSensitivity::loadRec(
			PGresult* res
			, WdbeMSensitivity** rec
		) {
	char* ptr;

	WdbeMSensitivity* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMSensitivity();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "srcixvtbl"),
			PQfnumber(res, "srcuref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->srcIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->srcUref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMSensitivity::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMSensitivity& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMSensitivity* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "srcixvtbl"),
			PQfnumber(res, "srcuref")
		};

		while (numread < numrow) {
			rec = new WdbeMSensitivity();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->srcIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->srcUref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMSensitivity::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMSensitivity** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSensitivity::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMSensitivity::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMSensitivity& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSensitivity::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMSensitivity::loadRecBySQL(
			const string& sqlstr
			, WdbeMSensitivity** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSensitivity::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMSensitivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSensitivity& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSensitivity::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMSensitivity::insertRec(
			WdbeMSensitivity* rec
		) {
	PGresult* res;
	char* ptr;

	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _srcIxVTbl = htonl(rec->srcIxVTbl);
	ubigint _srcUref = htonl64(rec->srcUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_srcIxVTbl,
		(char*) &_srcUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeMSensitivity_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSensitivity::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMSensitivity::insertRst(
			ListWdbeMSensitivity& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMSensitivity::updateRec(
			WdbeMSensitivity* rec
		) {
	PGresult* res;

	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _srcIxVTbl = htonl(rec->srcIxVTbl);
	ubigint _srcUref = htonl64(rec->srcUref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_srcIxVTbl,
		(char*) &_srcUref,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeMSensitivity_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMSensitivity::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMSensitivity::updateRst(
			ListWdbeMSensitivity& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMSensitivity::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMSensitivity_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMSensitivity::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMSensitivity::loadRecByRef(
			ubigint ref
			, WdbeMSensitivity** rec
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

	return loadRecByStmt("TblWdbeMSensitivity_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMSensitivity::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblWdbeMSensitivity_loadRefsByRetReu", 2, vals, l, f, append, refs);
};

ubigint PgTblWdbeMSensitivity::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMSensitivity& rst
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWdbeMSensitivity_loadRstByRetReu", 2, vals, l, f, append, rst);
};

#endif
