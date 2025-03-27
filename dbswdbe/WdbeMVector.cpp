/**
	* \file WdbeMVector.cpp
	* database access for table TblWdbeMVector (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMVector.h"

#include "WdbeMVector_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMVector
 ******************************************************************************/

WdbeMVector::WdbeMVector(
			const ubigint ref
			, const uint ixVBasetype
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const string srefsKOption
		) :
			ref(ref)
			, ixVBasetype(ixVBasetype)
			, hkIxVTbl(hkIxVTbl)
			, hkUref(hkUref)
			, sref(sref)
			, srefsKOption(srefsKOption)
		{
};

bool WdbeMVector::operator==(
			const WdbeMVector& comp
		) {
	return false;
};

bool WdbeMVector::operator!=(
			const WdbeMVector& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMVector
 ******************************************************************************/

ListWdbeMVector::ListWdbeMVector() {
};

ListWdbeMVector::ListWdbeMVector(
			const ListWdbeMVector& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMVector(*(src.nodes[i]));
};

ListWdbeMVector::~ListWdbeMVector() {
	clear();
};

void ListWdbeMVector::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMVector::size() const {
	return(nodes.size());
};

void ListWdbeMVector::append(
			WdbeMVector* rec
		) {
	nodes.push_back(rec);
};

WdbeMVector* ListWdbeMVector::operator[](
			const uint ix
		) {
	WdbeMVector* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMVector& ListWdbeMVector::operator=(
			const ListWdbeMVector& src
		) {
	WdbeMVector* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMVector(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMVector::operator==(
			const ListWdbeMVector& comp
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

bool ListWdbeMVector::operator!=(
			const ListWdbeMVector& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMVector
 ******************************************************************************/

TblWdbeMVector::TblWdbeMVector() {
};

TblWdbeMVector::~TblWdbeMVector() {
};

bool TblWdbeMVector::loadRecBySQL(
			const string& sqlstr
			, WdbeMVector** rec
		) {
	return false;
};

ubigint TblWdbeMVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMVector& rst
		) {
	return 0;
};

ubigint TblWdbeMVector::insertRec(
			WdbeMVector* rec
		) {
	return 0;
};

ubigint TblWdbeMVector::insertNewRec(
			WdbeMVector** rec
			, const uint ixVBasetype
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const string srefsKOption
		) {
	ubigint retval = 0;
	WdbeMVector* _rec = NULL;

	_rec = new WdbeMVector(0, ixVBasetype, hkIxVTbl, hkUref, sref, srefsKOption);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMVector::appendNewRecToRst(
			ListWdbeMVector& rst
			, WdbeMVector** rec
			, const uint ixVBasetype
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const string sref
			, const string srefsKOption
		) {
	ubigint retval = 0;
	WdbeMVector* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, hkIxVTbl, hkUref, sref, srefsKOption);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMVector::insertRst(
			ListWdbeMVector& rst
			, bool transact
		) {
};

void TblWdbeMVector::updateRec(
			WdbeMVector* rec
		) {
};

void TblWdbeMVector::updateRst(
			ListWdbeMVector& rst
			, bool transact
		) {
};

void TblWdbeMVector::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMVector::loadRecByRef(
			ubigint ref
			, WdbeMVector** rec
		) {
	return false;
};

bool TblWdbeMVector::loadRecByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, WdbeMVector** rec
		) {
	return false;
};

ubigint TblWdbeMVector::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMVector::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListWdbeMVector& rst
		) {
	return 0;
};

bool TblWdbeMVector::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMVector::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMVector& rst
		) {
	ubigint numload = 0;
	WdbeMVector* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMVector
 ******************************************************************************/

MyTblWdbeMVector::MyTblWdbeMVector() :
			TblWdbeMVector()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMVector::~MyTblWdbeMVector() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMVector::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMVector (ixVBasetype, hkIxVTbl, hkUref, sref, srefsKOption) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMVector SET ixVBasetype = ?, hkIxVTbl = ?, hkUref = ?, sref = ?, srefsKOption = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMVector WHERE ref = ?", false);
};

bool MyTblWdbeMVector::loadRecBySQL(
			const string& sqlstr
			, WdbeMVector** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMVector* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMVector::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMVector::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMVector();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->hkIxVTbl = atol((char*) dbrow[2]); else _rec->hkIxVTbl = 0;
		if (dbrow[3]) _rec->hkUref = atoll((char*) dbrow[3]); else _rec->hkUref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->srefsKOption.assign(dbrow[5], dblengths[5]); else _rec->srefsKOption = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMVector& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMVector* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMVector::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMVector::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMVector();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->hkIxVTbl = atol((char*) dbrow[2]); else rec->hkIxVTbl = 0;
			if (dbrow[3]) rec->hkUref = atoll((char*) dbrow[3]); else rec->hkUref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->srefsKOption.assign(dbrow[5], dblengths[5]); else rec->srefsKOption = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMVector::insertRec(
			WdbeMVector* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->sref.length();
	l[4] = rec->srefsKOption.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->hkIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->hkUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMVector::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMVector::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMVector::insertRst(
			ListWdbeMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMVector::updateRec(
			WdbeMVector* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();
	l[4] = rec->srefsKOption.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->hkIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->hkUref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMVector::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMVector::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMVector::updateRst(
			ListWdbeMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMVector::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMVector::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMVector::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMVector::loadRecByRef(
			ubigint ref
			, WdbeMVector** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMVector WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMVector::loadRecByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, WdbeMVector** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, hkIxVTbl, hkUref, sref, srefsKOption FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", rec);
};

ubigint MyTblWdbeMVector::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", append, refs);
};

ubigint MyTblWdbeMVector::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListWdbeMVector& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, hkIxVTbl, hkUref, sref, srefsKOption FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMVector::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMVector WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMVector
 ******************************************************************************/

PgTblWdbeMVector::PgTblWdbeMVector() :
			TblWdbeMVector()
			, PgTable()
		{
};

PgTblWdbeMVector::~PgTblWdbeMVector() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMVector::initStatements() {
	createStatement("TblWdbeMVector_insertRec", "INSERT INTO TblWdbeMVector (ixVBasetype, hkIxVTbl, hkUref, sref, srefsKOption) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWdbeMVector_updateRec", "UPDATE TblWdbeMVector SET ixVBasetype = $1, hkIxVTbl = $2, hkUref = $3, sref = $4, srefsKOption = $5 WHERE ref = $6", 6);
	createStatement("TblWdbeMVector_removeRecByRef", "DELETE FROM TblWdbeMVector WHERE ref = $1", 1);

	createStatement("TblWdbeMVector_loadRecByRef", "SELECT ref, ixVBasetype, hkIxVTbl, hkUref, sref, srefsKOption FROM TblWdbeMVector WHERE ref = $1", 1);
	createStatement("TblWdbeMVector_loadRecByHktHku", "SELECT ref, ixVBasetype, hkIxVTbl, hkUref, sref, srefsKOption FROM TblWdbeMVector WHERE hkIxVTbl = $1 AND hkUref = $2", 2);
	createStatement("TblWdbeMVector_loadRefsByHktHku", "SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = $1 AND hkUref = $2", 2);
	createStatement("TblWdbeMVector_loadRstByHktHku", "SELECT ref, ixVBasetype, hkIxVTbl, hkUref, sref, srefsKOption FROM TblWdbeMVector WHERE hkIxVTbl = $1 AND hkUref = $2 ORDER BY sref ASC", 2);
	createStatement("TblWdbeMVector_loadSrfByRef", "SELECT sref FROM TblWdbeMVector WHERE ref = $1", 1);
};

bool PgTblWdbeMVector::loadRec(
			PGresult* res
			, WdbeMVector** rec
		) {
	char* ptr;

	WdbeMVector* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMVector();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefskoption")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefsKOption.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMVector::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMVector& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMVector* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefskoption")
		};

		while (numread < numrow) {
			rec = new WdbeMVector();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefsKOption.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMVector::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMVector** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVector::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMVector::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMVector& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVector::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMVector::loadRecBySQL(
			const string& sqlstr
			, WdbeMVector** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVector::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMVector::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMVector& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVector::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMVector::insertRec(
			WdbeMVector* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str(),
		rec->srefsKOption.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMVector_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVector::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMVector::insertRst(
			ListWdbeMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMVector::updateRec(
			WdbeMVector* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		rec->sref.c_str(),
		rec->srefsKOption.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMVector_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMVector::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMVector::updateRst(
			ListWdbeMVector& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMVector::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMVector_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMVector::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMVector::loadRecByRef(
			ubigint ref
			, WdbeMVector** rec
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

	return loadRecByStmt("TblWdbeMVector_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMVector::loadRecByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, WdbeMVector** rec
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWdbeMVector_loadRecByHktHku", 2, vals, l, f, rec);
};

ubigint PgTblWdbeMVector::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblWdbeMVector_loadRefsByHktHku", 2, vals, l, f, append, refs);
};

ubigint PgTblWdbeMVector::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListWdbeMVector& rst
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWdbeMVector_loadRstByHktHku", 2, vals, l, f, append, rst);
};

bool PgTblWdbeMVector::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMVector_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
