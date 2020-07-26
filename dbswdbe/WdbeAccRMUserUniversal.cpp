/**
	* \file WdbeAccRMUserUniversal.cpp
	* database access for table TblWdbeAccRMUserUniversal (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeAccRMUserUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAccRMUserUniversal
 ******************************************************************************/

WdbeAccRMUserUniversal::WdbeAccRMUserUniversal(
			const ubigint ref
			, const ubigint refWdbeMUser
			, const uint unvIxWdbeVMaintable
			, const ubigint unvUref
			, const uint ixWdbeVRecaccess
		) {

	this->ref = ref;
	this->refWdbeMUser = refWdbeMUser;
	this->unvIxWdbeVMaintable = unvIxWdbeVMaintable;
	this->unvUref = unvUref;
	this->ixWdbeVRecaccess = ixWdbeVRecaccess;
};

bool WdbeAccRMUserUniversal::operator==(
			const WdbeAccRMUserUniversal& comp
		) {
	return false;
};

bool WdbeAccRMUserUniversal::operator!=(
			const WdbeAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAccRMUserUniversal
 ******************************************************************************/

ListWdbeAccRMUserUniversal::ListWdbeAccRMUserUniversal() {
};

ListWdbeAccRMUserUniversal::ListWdbeAccRMUserUniversal(
			const ListWdbeAccRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAccRMUserUniversal(*(src.nodes[i]));
};

ListWdbeAccRMUserUniversal::~ListWdbeAccRMUserUniversal() {
	clear();
};

void ListWdbeAccRMUserUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAccRMUserUniversal::size() const {
	return(nodes.size());
};

void ListWdbeAccRMUserUniversal::append(
			WdbeAccRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

WdbeAccRMUserUniversal* ListWdbeAccRMUserUniversal::operator[](
			const uint ix
		) {
	WdbeAccRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAccRMUserUniversal& ListWdbeAccRMUserUniversal::operator=(
			const ListWdbeAccRMUserUniversal& src
		) {
	WdbeAccRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAccRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAccRMUserUniversal::operator==(
			const ListWdbeAccRMUserUniversal& comp
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

bool ListWdbeAccRMUserUniversal::operator!=(
			const ListWdbeAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAccRMUserUniversal
 ******************************************************************************/

TblWdbeAccRMUserUniversal::TblWdbeAccRMUserUniversal() {
};

TblWdbeAccRMUserUniversal::~TblWdbeAccRMUserUniversal() {
};

bool TblWdbeAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WdbeAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWdbeAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAccRMUserUniversal& rst
		) {
	return 0;
};

ubigint TblWdbeAccRMUserUniversal::insertRec(
			WdbeAccRMUserUniversal* rec
		) {
	return 0;
};

ubigint TblWdbeAccRMUserUniversal::insertNewRec(
			WdbeAccRMUserUniversal** rec
			, const ubigint refWdbeMUser
			, const uint unvIxWdbeVMaintable
			, const ubigint unvUref
			, const uint ixWdbeVRecaccess
		) {
	ubigint retval = 0;
	WdbeAccRMUserUniversal* _rec = NULL;

	_rec = new WdbeAccRMUserUniversal(0, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAccRMUserUniversal::appendNewRecToRst(
			ListWdbeAccRMUserUniversal& rst
			, WdbeAccRMUserUniversal** rec
			, const ubigint refWdbeMUser
			, const uint unvIxWdbeVMaintable
			, const ubigint unvUref
			, const uint ixWdbeVRecaccess
		) {
	ubigint retval = 0;
	WdbeAccRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAccRMUserUniversal::insertRst(
			ListWdbeAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblWdbeAccRMUserUniversal::updateRec(
			WdbeAccRMUserUniversal* rec
		) {
};

void TblWdbeAccRMUserUniversal::updateRst(
			ListWdbeAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblWdbeAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WdbeAccRMUserUniversal** rec
		) {
	return false;
};

bool TblWdbeAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWdbeMUser
			, uint unvIxWdbeVMaintable
			, ubigint unvUref
			, WdbeAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWdbeAccRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAccRMUserUniversal& rst
		) {
	ubigint numload = 0;
	WdbeAccRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAccRMUserUniversal
 ******************************************************************************/

MyTblWdbeAccRMUserUniversal::MyTblWdbeAccRMUserUniversal() :
			TblWdbeAccRMUserUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAccRMUserUniversal::~MyTblWdbeAccRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAccRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAccRMUserUniversal (refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAccRMUserUniversal SET refWdbeMUser = ?, unvIxWdbeVMaintable = ?, unvUref = ?, ixWdbeVRecaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAccRMUserUniversal WHERE ref = ?", false);
};

bool MyTblWdbeAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WdbeAccRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAccRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAccRMUserUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAccRMUserUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeAccRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMUser = atoll((char*) dbrow[1]); else _rec->refWdbeMUser = 0;
		if (dbrow[2]) _rec->unvIxWdbeVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWdbeVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWdbeVRecaccess = atol((char*) dbrow[4]); else _rec->ixWdbeVRecaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAccRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAccRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAccRMUserUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAccRMUserUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeAccRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMUser = atoll((char*) dbrow[1]); else rec->refWdbeMUser = 0;
			if (dbrow[2]) rec->unvIxWdbeVMaintable = atol((char*) dbrow[2]); else rec->unvIxWdbeVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixWdbeVRecaccess = atol((char*) dbrow[4]); else rec->ixWdbeVRecaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAccRMUserUniversal::insertRec(
			WdbeAccRMUserUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWdbeVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVRecaccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAccRMUserUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAccRMUserUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAccRMUserUniversal::insertRst(
			ListWdbeAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAccRMUserUniversal::updateRec(
			WdbeAccRMUserUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWdbeVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVRecaccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAccRMUserUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAccRMUserUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAccRMUserUniversal::updateRst(
			ListWdbeAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAccRMUserUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAccRMUserUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WdbeAccRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAccRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWdbeMUser
			, uint unvIxWdbeVMaintable
			, ubigint unvUref
			, WdbeAccRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess FROM TblWdbeAccRMUserUniversal WHERE refWdbeMUser = " + to_string(refWdbeMUser) + " AND unvIxWdbeVMaintable = " + to_string(unvIxWdbeVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAccRMUserUniversal
 ******************************************************************************/

PgTblWdbeAccRMUserUniversal::PgTblWdbeAccRMUserUniversal() :
			TblWdbeAccRMUserUniversal()
			, PgTable()
		{
};

PgTblWdbeAccRMUserUniversal::~PgTblWdbeAccRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAccRMUserUniversal::initStatements() {
	createStatement("TblWdbeAccRMUserUniversal_insertRec", "INSERT INTO TblWdbeAccRMUserUniversal (refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeAccRMUserUniversal_updateRec", "UPDATE TblWdbeAccRMUserUniversal SET refWdbeMUser = $1, unvIxWdbeVMaintable = $2, unvUref = $3, ixWdbeVRecaccess = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeAccRMUserUniversal_removeRecByRef", "DELETE FROM TblWdbeAccRMUserUniversal WHERE ref = $1", 1);

	createStatement("TblWdbeAccRMUserUniversal_loadRecByRef", "SELECT ref, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess FROM TblWdbeAccRMUserUniversal WHERE ref = $1", 1);
	createStatement("TblWdbeAccRMUserUniversal_loadRecByUsrMtbUnv", "SELECT ref, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess FROM TblWdbeAccRMUserUniversal WHERE refWdbeMUser = $1 AND unvIxWdbeVMaintable = $2 AND unvUref = $3", 3);
};

bool PgTblWdbeAccRMUserUniversal::loadRec(
			PGresult* res
			, WdbeAccRMUserUniversal** rec
		) {
	char* ptr;

	WdbeAccRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAccRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "unvixwdbevmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwdbevrecaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxWdbeVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWdbeVRecaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAccRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAccRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAccRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "unvixwdbevmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwdbevrecaccess")
		};

		while (numread < numrow) {
			rec = new WdbeAccRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxWdbeVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWdbeVRecaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAccRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAccRMUserUniversal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WdbeAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAccRMUserUniversal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAccRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAccRMUserUniversal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAccRMUserUniversal::insertRec(
			WdbeAccRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	uint _unvIxWdbeVMaintable = htonl(rec->unvIxWdbeVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWdbeVRecaccess = htonl(rec->ixWdbeVRecaccess);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_unvIxWdbeVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWdbeVRecaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeAccRMUserUniversal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAccRMUserUniversal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAccRMUserUniversal::insertRst(
			ListWdbeAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAccRMUserUniversal::updateRec(
			WdbeAccRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	uint _unvIxWdbeVMaintable = htonl(rec->unvIxWdbeVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWdbeVRecaccess = htonl(rec->ixWdbeVRecaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_unvIxWdbeVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWdbeVRecaccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeAccRMUserUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAccRMUserUniversal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAccRMUserUniversal::updateRst(
			ListWdbeAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAccRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAccRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAccRMUserUniversal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, WdbeAccRMUserUniversal** rec
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

	return loadRecByStmt("TblWdbeAccRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refWdbeMUser
			, uint unvIxWdbeVMaintable
			, ubigint unvUref
			, WdbeAccRMUserUniversal** rec
		) {
	ubigint _refWdbeMUser = htonl64(refWdbeMUser);
	uint _unvIxWdbeVMaintable = htonl(unvIxWdbeVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_unvIxWdbeVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblWdbeAccRMUserUniversal_loadRecByUsrMtbUnv", 3, vals, l, f, rec);
};

#endif

