/**
	* \file WdbeAMPersonDetail.cpp
	* database access for table TblWdbeAMPersonDetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAMPersonDetail.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMPersonDetail
 ******************************************************************************/

WdbeAMPersonDetail::WdbeAMPersonDetail(
			const ubigint ref
			, const ubigint refWdbeMPerson
			, const string x1SrefKType
			, const string Val
		) {

	this->ref = ref;
	this->refWdbeMPerson = refWdbeMPerson;
	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

bool WdbeAMPersonDetail::operator==(
			const WdbeAMPersonDetail& comp
		) {
	return false;
};

bool WdbeAMPersonDetail::operator!=(
			const WdbeAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMPersonDetail
 ******************************************************************************/

ListWdbeAMPersonDetail::ListWdbeAMPersonDetail() {
};

ListWdbeAMPersonDetail::ListWdbeAMPersonDetail(
			const ListWdbeAMPersonDetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMPersonDetail(*(src.nodes[i]));
};

ListWdbeAMPersonDetail::~ListWdbeAMPersonDetail() {
	clear();
};

void ListWdbeAMPersonDetail::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMPersonDetail::size() const {
	return(nodes.size());
};

void ListWdbeAMPersonDetail::append(
			WdbeAMPersonDetail* rec
		) {
	nodes.push_back(rec);
};

WdbeAMPersonDetail* ListWdbeAMPersonDetail::operator[](
			const uint ix
		) {
	WdbeAMPersonDetail* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMPersonDetail& ListWdbeAMPersonDetail::operator=(
			const ListWdbeAMPersonDetail& src
		) {
	WdbeAMPersonDetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMPersonDetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMPersonDetail::operator==(
			const ListWdbeAMPersonDetail& comp
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

bool ListWdbeAMPersonDetail::operator!=(
			const ListWdbeAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMPersonDetail
 ******************************************************************************/

TblWdbeAMPersonDetail::TblWdbeAMPersonDetail() {
};

TblWdbeAMPersonDetail::~TblWdbeAMPersonDetail() {
};

bool TblWdbeAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WdbeAMPersonDetail** rec
		) {
	return false;
};

ubigint TblWdbeAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMPersonDetail& rst
		) {
	return 0;
};

ubigint TblWdbeAMPersonDetail::insertRec(
			WdbeAMPersonDetail* rec
		) {
	return 0;
};

ubigint TblWdbeAMPersonDetail::insertNewRec(
			WdbeAMPersonDetail** rec
			, const ubigint refWdbeMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMPersonDetail* _rec = NULL;

	_rec = new WdbeAMPersonDetail(0, refWdbeMPerson, x1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMPersonDetail::appendNewRecToRst(
			ListWdbeAMPersonDetail& rst
			, WdbeAMPersonDetail** rec
			, const ubigint refWdbeMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMPersonDetail* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMPerson, x1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMPersonDetail::insertRst(
			ListWdbeAMPersonDetail& rst
			, bool transact
		) {
};

void TblWdbeAMPersonDetail::updateRec(
			WdbeAMPersonDetail* rec
		) {
};

void TblWdbeAMPersonDetail::updateRst(
			ListWdbeAMPersonDetail& rst
			, bool transact
		) {
};

void TblWdbeAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMPersonDetail::loadRecByRef(
			ubigint ref
			, WdbeAMPersonDetail** rec
		) {
	return false;
};

bool TblWdbeAMPersonDetail::loadRecByPrsTyp(
			ubigint refWdbeMPerson
			, string x1SrefKType
			, WdbeAMPersonDetail** rec
		) {
	return false;
};

ubigint TblWdbeAMPersonDetail::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeAMPersonDetail& rst
		) {
	return 0;
};

ubigint TblWdbeAMPersonDetail::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMPersonDetail& rst
		) {
	ubigint numload = 0;
	WdbeAMPersonDetail* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMPersonDetail
 ******************************************************************************/

MyTblWdbeAMPersonDetail::MyTblWdbeAMPersonDetail() :
			TblWdbeAMPersonDetail()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMPersonDetail::~MyTblWdbeAMPersonDetail() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMPersonDetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMPersonDetail (refWdbeMPerson, x1SrefKType, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMPersonDetail SET refWdbeMPerson = ?, x1SrefKType = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMPersonDetail WHERE ref = ?", false);
};

bool MyTblWdbeAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WdbeAMPersonDetail** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMPersonDetail* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMPersonDetail::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMPersonDetail::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMPersonDetail();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMPerson = atoll((char*) dbrow[1]); else _rec->refWdbeMPerson = 0;
		if (dbrow[2]) _rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKType = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMPersonDetail& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMPersonDetail* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMPersonDetail::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMPersonDetail::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMPersonDetail();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMPerson = atoll((char*) dbrow[1]); else rec->refWdbeMPerson = 0;
			if (dbrow[2]) rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else rec->x1SrefKType = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMPersonDetail::insertRec(
			WdbeAMPersonDetail* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMPersonDetail::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMPersonDetail::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMPersonDetail::insertRst(
			ListWdbeAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMPersonDetail::updateRec(
			WdbeAMPersonDetail* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMPersonDetail::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMPersonDetail::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMPersonDetail::updateRst(
			ListWdbeAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMPersonDetail::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMPersonDetail::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMPersonDetail::loadRecByRef(
			ubigint ref
			, WdbeAMPersonDetail** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMPersonDetail WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeAMPersonDetail::loadRecByPrsTyp(
			ubigint refWdbeMPerson
			, string x1SrefKType
			, WdbeAMPersonDetail** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMPerson, x1SrefKType, Val FROM TblWdbeAMPersonDetail WHERE refWdbeMPerson = " + to_string(refWdbeMPerson) + " AND x1SrefKType = '" + x1SrefKType + "'", rec);
};

ubigint MyTblWdbeAMPersonDetail::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeAMPersonDetail& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMPerson, x1SrefKType, Val FROM TblWdbeAMPersonDetail WHERE refWdbeMPerson = " + to_string(refWdbeMPerson) + " ORDER BY x1SrefKType ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMPersonDetail
 ******************************************************************************/

PgTblWdbeAMPersonDetail::PgTblWdbeAMPersonDetail() :
			TblWdbeAMPersonDetail()
			, PgTable()
		{
};

PgTblWdbeAMPersonDetail::~PgTblWdbeAMPersonDetail() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMPersonDetail::initStatements() {
	createStatement("TblWdbeAMPersonDetail_insertRec", "INSERT INTO TblWdbeAMPersonDetail (refWdbeMPerson, x1SrefKType, Val) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeAMPersonDetail_updateRec", "UPDATE TblWdbeAMPersonDetail SET refWdbeMPerson = $1, x1SrefKType = $2, Val = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeAMPersonDetail_removeRecByRef", "DELETE FROM TblWdbeAMPersonDetail WHERE ref = $1", 1);

	createStatement("TblWdbeAMPersonDetail_loadRecByRef", "SELECT ref, refWdbeMPerson, x1SrefKType, Val FROM TblWdbeAMPersonDetail WHERE ref = $1", 1);
	createStatement("TblWdbeAMPersonDetail_loadRecByPrsTyp", "SELECT ref, refWdbeMPerson, x1SrefKType, Val FROM TblWdbeAMPersonDetail WHERE refWdbeMPerson = $1 AND x1SrefKType = $2", 2);
	createStatement("TblWdbeAMPersonDetail_loadRstByPrs", "SELECT ref, refWdbeMPerson, x1SrefKType, Val FROM TblWdbeAMPersonDetail WHERE refWdbeMPerson = $1 ORDER BY x1SrefKType ASC", 1);
};

bool PgTblWdbeAMPersonDetail::loadRec(
			PGresult* res
			, WdbeAMPersonDetail** rec
		) {
	char* ptr;

	WdbeAMPersonDetail* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMPersonDetail();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKType.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMPersonDetail::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMPersonDetail& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMPersonDetail* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WdbeAMPersonDetail();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKType.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMPersonDetail::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPersonDetail::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMPersonDetail::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMPersonDetail& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPersonDetail::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, WdbeAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPersonDetail::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMPersonDetail& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPersonDetail::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMPersonDetail::insertRec(
			WdbeAMPersonDetail* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);

	const char* vals[] = {
		(char*) &_refWdbeMPerson,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMPersonDetail_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMPersonDetail::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMPersonDetail::insertRst(
			ListWdbeAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMPersonDetail::updateRec(
			WdbeAMPersonDetail* rec
		) {
	PGresult* res;

	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMPerson,
		rec->x1SrefKType.c_str(),
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

	res = PQexecPrepared(dbs, "TblWdbeAMPersonDetail_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMPersonDetail::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMPersonDetail::updateRst(
			ListWdbeAMPersonDetail& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMPersonDetail::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMPersonDetail_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMPersonDetail::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMPersonDetail::loadRecByRef(
			ubigint ref
			, WdbeAMPersonDetail** rec
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

	return loadRecByStmt("TblWdbeAMPersonDetail_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeAMPersonDetail::loadRecByPrsTyp(
			ubigint refWdbeMPerson
			, string x1SrefKType
			, WdbeAMPersonDetail** rec
		) {
	ubigint _refWdbeMPerson = htonl64(refWdbeMPerson);

	const char* vals[] = {
		(char*) &_refWdbeMPerson,
		x1SrefKType.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRecByStmt("TblWdbeAMPersonDetail_loadRecByPrsTyp", 2, vals, l, f, rec);
};

ubigint PgTblWdbeAMPersonDetail::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeAMPersonDetail& rst
		) {
	ubigint _refWdbeMPerson = htonl64(refWdbeMPerson);

	const char* vals[] = {
		(char*) &_refWdbeMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMPersonDetail_loadRstByPrs", 1, vals, l, f, append, rst);
};

#endif

