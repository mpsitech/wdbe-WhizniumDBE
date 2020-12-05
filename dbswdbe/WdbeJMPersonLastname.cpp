/**
	* \file WdbeJMPersonLastname.cpp
	* database access for table TblWdbeJMPersonLastname (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeJMPersonLastname.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeJMPersonLastname
 ******************************************************************************/

WdbeJMPersonLastname::WdbeJMPersonLastname(
			const ubigint ref
			, const ubigint refWdbeMPerson
			, const uint x1Startd
			, const string Lastname
		) {

	this->ref = ref;
	this->refWdbeMPerson = refWdbeMPerson;
	this->x1Startd = x1Startd;
	this->Lastname = Lastname;
};

bool WdbeJMPersonLastname::operator==(
			const WdbeJMPersonLastname& comp
		) {
	return false;
};

bool WdbeJMPersonLastname::operator!=(
			const WdbeJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeJMPersonLastname
 ******************************************************************************/

ListWdbeJMPersonLastname::ListWdbeJMPersonLastname() {
};

ListWdbeJMPersonLastname::ListWdbeJMPersonLastname(
			const ListWdbeJMPersonLastname& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeJMPersonLastname(*(src.nodes[i]));
};

ListWdbeJMPersonLastname::~ListWdbeJMPersonLastname() {
	clear();
};

void ListWdbeJMPersonLastname::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeJMPersonLastname::size() const {
	return(nodes.size());
};

void ListWdbeJMPersonLastname::append(
			WdbeJMPersonLastname* rec
		) {
	nodes.push_back(rec);
};

WdbeJMPersonLastname* ListWdbeJMPersonLastname::operator[](
			const uint ix
		) {
	WdbeJMPersonLastname* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeJMPersonLastname& ListWdbeJMPersonLastname::operator=(
			const ListWdbeJMPersonLastname& src
		) {
	WdbeJMPersonLastname* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeJMPersonLastname(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeJMPersonLastname::operator==(
			const ListWdbeJMPersonLastname& comp
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

bool ListWdbeJMPersonLastname::operator!=(
			const ListWdbeJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeJMPersonLastname
 ******************************************************************************/

TblWdbeJMPersonLastname::TblWdbeJMPersonLastname() {
};

TblWdbeJMPersonLastname::~TblWdbeJMPersonLastname() {
};

bool TblWdbeJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WdbeJMPersonLastname** rec
		) {
	return false;
};

ubigint TblWdbeJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblWdbeJMPersonLastname::insertRec(
			WdbeJMPersonLastname* rec
		) {
	return 0;
};

ubigint TblWdbeJMPersonLastname::insertNewRec(
			WdbeJMPersonLastname** rec
			, const ubigint refWdbeMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	WdbeJMPersonLastname* _rec = NULL;

	_rec = new WdbeJMPersonLastname(0, refWdbeMPerson, x1Startd, Lastname);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeJMPersonLastname::appendNewRecToRst(
			ListWdbeJMPersonLastname& rst
			, WdbeJMPersonLastname** rec
			, const ubigint refWdbeMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	WdbeJMPersonLastname* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMPerson, x1Startd, Lastname);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeJMPersonLastname::insertRst(
			ListWdbeJMPersonLastname& rst
			, bool transact
		) {
};

void TblWdbeJMPersonLastname::updateRec(
			WdbeJMPersonLastname* rec
		) {
};

void TblWdbeJMPersonLastname::updateRst(
			ListWdbeJMPersonLastname& rst
			, bool transact
		) {
};

void TblWdbeJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeJMPersonLastname::loadRecByRef(
			ubigint ref
			, WdbeJMPersonLastname** rec
		) {
	return false;
};

bool TblWdbeJMPersonLastname::loadRecByPrsSta(
			ubigint refWdbeMPerson
			, uint x1Startd
			, WdbeJMPersonLastname** rec
		) {
	return false;
};

ubigint TblWdbeJMPersonLastname::loadRefsByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeJMPersonLastname::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblWdbeJMPersonLastname::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeJMPersonLastname& rst
		) {
	ubigint numload = 0;
	WdbeJMPersonLastname* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeJMPersonLastname
 ******************************************************************************/

MyTblWdbeJMPersonLastname::MyTblWdbeJMPersonLastname() :
			TblWdbeJMPersonLastname()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeJMPersonLastname::~MyTblWdbeJMPersonLastname() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeJMPersonLastname::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeJMPersonLastname (refWdbeMPerson, x1Startd, Lastname) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeJMPersonLastname SET refWdbeMPerson = ?, x1Startd = ?, Lastname = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeJMPersonLastname WHERE ref = ?", false);
};

bool MyTblWdbeJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WdbeJMPersonLastname** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeJMPersonLastname* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJMPersonLastname::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJMPersonLastname::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeJMPersonLastname();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMPerson = atoll((char*) dbrow[1]); else _rec->refWdbeMPerson = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->Lastname.assign(dbrow[3], dblengths[3]); else _rec->Lastname = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMPersonLastname& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeJMPersonLastname* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJMPersonLastname::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJMPersonLastname::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeJMPersonLastname();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMPerson = atoll((char*) dbrow[1]); else rec->refWdbeMPerson = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->Lastname.assign(dbrow[3], dblengths[3]); else rec->Lastname = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeJMPersonLastname::insertRec(
			WdbeJMPersonLastname* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeJMPersonLastname::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeJMPersonLastname::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeJMPersonLastname::insertRst(
			ListWdbeJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeJMPersonLastname::updateRec(
			WdbeJMPersonLastname* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeJMPersonLastname::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeJMPersonLastname::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeJMPersonLastname::updateRst(
			ListWdbeJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeJMPersonLastname::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeJMPersonLastname::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeJMPersonLastname::loadRecByRef(
			ubigint ref
			, WdbeJMPersonLastname** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeJMPersonLastname WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeJMPersonLastname::loadRecByPrsSta(
			ubigint refWdbeMPerson
			, uint x1Startd
			, WdbeJMPersonLastname** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMPerson, x1Startd, Lastname FROM TblWdbeJMPersonLastname WHERE refWdbeMPerson = " + to_string(refWdbeMPerson) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblWdbeJMPersonLastname::loadRefsByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeJMPersonLastname WHERE refWdbeMPerson = " + to_string(refWdbeMPerson) + "", append, refs);
};

ubigint MyTblWdbeJMPersonLastname::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeJMPersonLastname& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMPerson, x1Startd, Lastname FROM TblWdbeJMPersonLastname WHERE refWdbeMPerson = " + to_string(refWdbeMPerson) + " ORDER BY x1Startd ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeJMPersonLastname
 ******************************************************************************/

PgTblWdbeJMPersonLastname::PgTblWdbeJMPersonLastname() :
			TblWdbeJMPersonLastname()
			, PgTable()
		{
};

PgTblWdbeJMPersonLastname::~PgTblWdbeJMPersonLastname() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeJMPersonLastname::initStatements() {
	createStatement("TblWdbeJMPersonLastname_insertRec", "INSERT INTO TblWdbeJMPersonLastname (refWdbeMPerson, x1Startd, Lastname) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeJMPersonLastname_updateRec", "UPDATE TblWdbeJMPersonLastname SET refWdbeMPerson = $1, x1Startd = $2, Lastname = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeJMPersonLastname_removeRecByRef", "DELETE FROM TblWdbeJMPersonLastname WHERE ref = $1", 1);

	createStatement("TblWdbeJMPersonLastname_loadRecByRef", "SELECT ref, refWdbeMPerson, x1Startd, Lastname FROM TblWdbeJMPersonLastname WHERE ref = $1", 1);
	createStatement("TblWdbeJMPersonLastname_loadRecByPrsSta", "SELECT ref, refWdbeMPerson, x1Startd, Lastname FROM TblWdbeJMPersonLastname WHERE refWdbeMPerson = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2);
	createStatement("TblWdbeJMPersonLastname_loadRefsByPrs", "SELECT ref FROM TblWdbeJMPersonLastname WHERE refWdbeMPerson = $1", 1);
	createStatement("TblWdbeJMPersonLastname_loadRstByPrs", "SELECT ref, refWdbeMPerson, x1Startd, Lastname FROM TblWdbeJMPersonLastname WHERE refWdbeMPerson = $1 ORDER BY x1Startd ASC", 1);
};

bool PgTblWdbeJMPersonLastname::loadRec(
			PGresult* res
			, WdbeJMPersonLastname** rec
		) {
	char* ptr;

	WdbeJMPersonLastname* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeJMPersonLastname();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeJMPersonLastname::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeJMPersonLastname& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeJMPersonLastname* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		while (numread < numrow) {
			rec = new WdbeJMPersonLastname();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeJMPersonLastname::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMPersonLastname::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJMPersonLastname::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMPersonLastname::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, WdbeJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMPersonLastname::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMPersonLastname::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeJMPersonLastname::insertRec(
			WdbeJMPersonLastname* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);
	uint _x1Startd = htonl(rec->x1Startd);

	const char* vals[] = {
		(char*) &_refWdbeMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeJMPersonLastname_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMPersonLastname::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeJMPersonLastname::insertRst(
			ListWdbeJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeJMPersonLastname::updateRec(
			WdbeJMPersonLastname* rec
		) {
	PGresult* res;

	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);
	uint _x1Startd = htonl(rec->x1Startd);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeJMPersonLastname_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJMPersonLastname::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeJMPersonLastname::updateRst(
			ListWdbeJMPersonLastname& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeJMPersonLastname::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeJMPersonLastname_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJMPersonLastname::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeJMPersonLastname::loadRecByRef(
			ubigint ref
			, WdbeJMPersonLastname** rec
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

	return loadRecByStmt("TblWdbeJMPersonLastname_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeJMPersonLastname::loadRecByPrsSta(
			ubigint refWdbeMPerson
			, uint x1Startd
			, WdbeJMPersonLastname** rec
		) {
	ubigint _refWdbeMPerson = htonl64(refWdbeMPerson);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refWdbeMPerson,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWdbeJMPersonLastname_loadRecByPrsSta", 2, vals, l, f, rec);
};

ubigint PgTblWdbeJMPersonLastname::loadRefsByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMPerson = htonl64(refWdbeMPerson);

	const char* vals[] = {
		(char*) &_refWdbeMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeJMPersonLastname_loadRefsByPrs", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeJMPersonLastname::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeJMPersonLastname& rst
		) {
	ubigint _refWdbeMPerson = htonl64(refWdbeMPerson);

	const char* vals[] = {
		(char*) &_refWdbeMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeJMPersonLastname_loadRstByPrs", 1, vals, l, f, append, rst);
};

#endif

