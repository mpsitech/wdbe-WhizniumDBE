/**
	* \file WdbeRMUsergroupUniversal.cpp
	* database access for table TblWdbeRMUsergroupUniversal (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeRMUsergroupUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeRMUsergroupUniversal
 ******************************************************************************/

WdbeRMUsergroupUniversal::WdbeRMUsergroupUniversal(
			const ubigint ref
			, const ubigint refWdbeMUsergroup
			, const uint unvIxWdbeVMaintable
			, const ubigint unvUref
			, const uint ixWdbeVRecaccess
		) {

	this->ref = ref;
	this->refWdbeMUsergroup = refWdbeMUsergroup;
	this->unvIxWdbeVMaintable = unvIxWdbeVMaintable;
	this->unvUref = unvUref;
	this->ixWdbeVRecaccess = ixWdbeVRecaccess;
};

bool WdbeRMUsergroupUniversal::operator==(
			const WdbeRMUsergroupUniversal& comp
		) {
	return false;
};

bool WdbeRMUsergroupUniversal::operator!=(
			const WdbeRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeRMUsergroupUniversal
 ******************************************************************************/

ListWdbeRMUsergroupUniversal::ListWdbeRMUsergroupUniversal() {
};

ListWdbeRMUsergroupUniversal::ListWdbeRMUsergroupUniversal(
			const ListWdbeRMUsergroupUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeRMUsergroupUniversal(*(src.nodes[i]));
};

ListWdbeRMUsergroupUniversal::~ListWdbeRMUsergroupUniversal() {
	clear();
};

void ListWdbeRMUsergroupUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeRMUsergroupUniversal::size() const {
	return(nodes.size());
};

void ListWdbeRMUsergroupUniversal::append(
			WdbeRMUsergroupUniversal* rec
		) {
	nodes.push_back(rec);
};

WdbeRMUsergroupUniversal* ListWdbeRMUsergroupUniversal::operator[](
			const uint ix
		) {
	WdbeRMUsergroupUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeRMUsergroupUniversal& ListWdbeRMUsergroupUniversal::operator=(
			const ListWdbeRMUsergroupUniversal& src
		) {
	WdbeRMUsergroupUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeRMUsergroupUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeRMUsergroupUniversal::operator==(
			const ListWdbeRMUsergroupUniversal& comp
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

bool ListWdbeRMUsergroupUniversal::operator!=(
			const ListWdbeRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeRMUsergroupUniversal
 ******************************************************************************/

TblWdbeRMUsergroupUniversal::TblWdbeRMUsergroupUniversal() {
};

TblWdbeRMUsergroupUniversal::~TblWdbeRMUsergroupUniversal() {
};

bool TblWdbeRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WdbeRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblWdbeRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMUsergroupUniversal& rst
		) {
	return 0;
};

ubigint TblWdbeRMUsergroupUniversal::insertRec(
			WdbeRMUsergroupUniversal* rec
		) {
	return 0;
};

ubigint TblWdbeRMUsergroupUniversal::insertNewRec(
			WdbeRMUsergroupUniversal** rec
			, const ubigint refWdbeMUsergroup
			, const uint unvIxWdbeVMaintable
			, const ubigint unvUref
			, const uint ixWdbeVRecaccess
		) {
	ubigint retval = 0;
	WdbeRMUsergroupUniversal* _rec = NULL;

	_rec = new WdbeRMUsergroupUniversal(0, refWdbeMUsergroup, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeRMUsergroupUniversal::appendNewRecToRst(
			ListWdbeRMUsergroupUniversal& rst
			, WdbeRMUsergroupUniversal** rec
			, const ubigint refWdbeMUsergroup
			, const uint unvIxWdbeVMaintable
			, const ubigint unvUref
			, const uint ixWdbeVRecaccess
		) {
	ubigint retval = 0;
	WdbeRMUsergroupUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMUsergroup, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeRMUsergroupUniversal::insertRst(
			ListWdbeRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblWdbeRMUsergroupUniversal::updateRec(
			WdbeRMUsergroupUniversal* rec
		) {
};

void TblWdbeRMUsergroupUniversal::updateRst(
			ListWdbeRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblWdbeRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WdbeRMUsergroupUniversal** rec
		) {
	return false;
};

bool TblWdbeRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWdbeMUsergroup
			, uint unvIxWdbeVMaintable
			, ubigint unvUref
			, WdbeRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblWdbeRMUsergroupUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeRMUsergroupUniversal& rst
		) {
	ubigint numload = 0;
	WdbeRMUsergroupUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeRMUsergroupUniversal
 ******************************************************************************/

MyTblWdbeRMUsergroupUniversal::MyTblWdbeRMUsergroupUniversal() :
			TblWdbeRMUsergroupUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeRMUsergroupUniversal::~MyTblWdbeRMUsergroupUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeRMUsergroupUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeRMUsergroupUniversal (refWdbeMUsergroup, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeRMUsergroupUniversal SET refWdbeMUsergroup = ?, unvIxWdbeVMaintable = ?, unvUref = ?, ixWdbeVRecaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeRMUsergroupUniversal WHERE ref = ?", false);
};

bool MyTblWdbeRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WdbeRMUsergroupUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeRMUsergroupUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMUsergroupUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMUsergroupUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeRMUsergroupUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMUsergroup = atoll((char*) dbrow[1]); else _rec->refWdbeMUsergroup = 0;
		if (dbrow[2]) _rec->unvIxWdbeVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWdbeVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWdbeVRecaccess = atol((char*) dbrow[4]); else _rec->ixWdbeVRecaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMUsergroupUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMUsergroupUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMUsergroupUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeRMUsergroupUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMUsergroup = atoll((char*) dbrow[1]); else rec->refWdbeMUsergroup = 0;
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

ubigint MyTblWdbeRMUsergroupUniversal::insertRec(
			WdbeRMUsergroupUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWdbeVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVRecaccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeRMUsergroupUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeRMUsergroupUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeRMUsergroupUniversal::insertRst(
			ListWdbeRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeRMUsergroupUniversal::updateRec(
			WdbeRMUsergroupUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWdbeVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVRecaccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeRMUsergroupUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeRMUsergroupUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeRMUsergroupUniversal::updateRst(
			ListWdbeRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeRMUsergroupUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeRMUsergroupUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WdbeRMUsergroupUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeRMUsergroupUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWdbeMUsergroup
			, uint unvIxWdbeVMaintable
			, ubigint unvUref
			, WdbeRMUsergroupUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMUsergroup, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess FROM TblWdbeRMUsergroupUniversal WHERE refWdbeMUsergroup = " + to_string(refWdbeMUsergroup) + " AND unvIxWdbeVMaintable = " + to_string(unvIxWdbeVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeRMUsergroupUniversal
 ******************************************************************************/

PgTblWdbeRMUsergroupUniversal::PgTblWdbeRMUsergroupUniversal() :
			TblWdbeRMUsergroupUniversal()
			, PgTable()
		{
};

PgTblWdbeRMUsergroupUniversal::~PgTblWdbeRMUsergroupUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeRMUsergroupUniversal::initStatements() {
	createStatement("TblWdbeRMUsergroupUniversal_insertRec", "INSERT INTO TblWdbeRMUsergroupUniversal (refWdbeMUsergroup, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeRMUsergroupUniversal_updateRec", "UPDATE TblWdbeRMUsergroupUniversal SET refWdbeMUsergroup = $1, unvIxWdbeVMaintable = $2, unvUref = $3, ixWdbeVRecaccess = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeRMUsergroupUniversal_removeRecByRef", "DELETE FROM TblWdbeRMUsergroupUniversal WHERE ref = $1", 1);

	createStatement("TblWdbeRMUsergroupUniversal_loadRecByRef", "SELECT ref, refWdbeMUsergroup, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess FROM TblWdbeRMUsergroupUniversal WHERE ref = $1", 1);
	createStatement("TblWdbeRMUsergroupUniversal_loadRecByUsgMtbUnv", "SELECT ref, refWdbeMUsergroup, unvIxWdbeVMaintable, unvUref, ixWdbeVRecaccess FROM TblWdbeRMUsergroupUniversal WHERE refWdbeMUsergroup = $1 AND unvIxWdbeVMaintable = $2 AND unvUref = $3", 3);
};

bool PgTblWdbeRMUsergroupUniversal::loadRec(
			PGresult* res
			, WdbeRMUsergroupUniversal** rec
		) {
	char* ptr;

	WdbeRMUsergroupUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeRMUsergroupUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemusergroup"),
			PQfnumber(res, "unvixwdbevmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwdbevrecaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxWdbeVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWdbeVRecaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeRMUsergroupUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeRMUsergroupUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemusergroup"),
			PQfnumber(res, "unvixwdbevmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwdbevrecaccess")
		};

		while (numread < numrow) {
			rec = new WdbeRMUsergroupUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMUsergroup = atoll(ptr);
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

bool PgTblWdbeRMUsergroupUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMUsergroupUniversal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, WdbeRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMUsergroupUniversal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMUsergroupUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMUsergroupUniversal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeRMUsergroupUniversal::insertRec(
			WdbeRMUsergroupUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMUsergroup = htonl64(rec->refWdbeMUsergroup);
	uint _unvIxWdbeVMaintable = htonl(rec->unvIxWdbeVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWdbeVRecaccess = htonl(rec->ixWdbeVRecaccess);

	const char* vals[] = {
		(char*) &_refWdbeMUsergroup,
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

	res = PQexecPrepared(dbs, "TblWdbeRMUsergroupUniversal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMUsergroupUniversal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeRMUsergroupUniversal::insertRst(
			ListWdbeRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeRMUsergroupUniversal::updateRec(
			WdbeRMUsergroupUniversal* rec
		) {
	PGresult* res;

	ubigint _refWdbeMUsergroup = htonl64(rec->refWdbeMUsergroup);
	uint _unvIxWdbeVMaintable = htonl(rec->unvIxWdbeVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWdbeVRecaccess = htonl(rec->ixWdbeVRecaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMUsergroup,
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

	res = PQexecPrepared(dbs, "TblWdbeRMUsergroupUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMUsergroupUniversal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeRMUsergroupUniversal::updateRst(
			ListWdbeRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeRMUsergroupUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeRMUsergroupUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMUsergroupUniversal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, WdbeRMUsergroupUniversal** rec
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

	return loadRecByStmt("TblWdbeRMUsergroupUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refWdbeMUsergroup
			, uint unvIxWdbeVMaintable
			, ubigint unvUref
			, WdbeRMUsergroupUniversal** rec
		) {
	ubigint _refWdbeMUsergroup = htonl64(refWdbeMUsergroup);
	uint _unvIxWdbeVMaintable = htonl(unvIxWdbeVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refWdbeMUsergroup,
		(char*) &_unvIxWdbeVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblWdbeRMUsergroupUniversal_loadRecByUsgMtbUnv", 3, vals, l, f, rec);
};

#endif

