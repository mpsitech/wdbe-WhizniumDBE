/**
	* \file WdbeAMUserAccess.cpp
	* database access for table TblWdbeAMUserAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAMUserAccess.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMUserAccess
 ******************************************************************************/

WdbeAMUserAccess::WdbeAMUserAccess(
			const ubigint ref
			, const ubigint refWdbeMUser
			, const uint x1IxWdbeVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWdbeWAccess
		) {

	this->ref = ref;
	this->refWdbeMUser = refWdbeMUser;
	this->x1IxWdbeVFeatgroup = x1IxWdbeVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWdbeWAccess = ixWdbeWAccess;
};

bool WdbeAMUserAccess::operator==(
			const WdbeAMUserAccess& comp
		) {
	return false;
};

bool WdbeAMUserAccess::operator!=(
			const WdbeAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMUserAccess
 ******************************************************************************/

ListWdbeAMUserAccess::ListWdbeAMUserAccess() {
};

ListWdbeAMUserAccess::ListWdbeAMUserAccess(
			const ListWdbeAMUserAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMUserAccess(*(src.nodes[i]));
};

ListWdbeAMUserAccess::~ListWdbeAMUserAccess() {
	clear();
};

void ListWdbeAMUserAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMUserAccess::size() const {
	return(nodes.size());
};

void ListWdbeAMUserAccess::append(
			WdbeAMUserAccess* rec
		) {
	nodes.push_back(rec);
};

WdbeAMUserAccess* ListWdbeAMUserAccess::operator[](
			const uint ix
		) {
	WdbeAMUserAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMUserAccess& ListWdbeAMUserAccess::operator=(
			const ListWdbeAMUserAccess& src
		) {
	WdbeAMUserAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMUserAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMUserAccess::operator==(
			const ListWdbeAMUserAccess& comp
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

bool ListWdbeAMUserAccess::operator!=(
			const ListWdbeAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMUserAccess
 ******************************************************************************/

TblWdbeAMUserAccess::TblWdbeAMUserAccess() {
};

TblWdbeAMUserAccess::~TblWdbeAMUserAccess() {
};

bool TblWdbeAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WdbeAMUserAccess** rec
		) {
	return false;
};

ubigint TblWdbeAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMUserAccess& rst
		) {
	return 0;
};

ubigint TblWdbeAMUserAccess::insertRec(
			WdbeAMUserAccess* rec
		) {
	return 0;
};

ubigint TblWdbeAMUserAccess::insertNewRec(
			WdbeAMUserAccess** rec
			, const ubigint refWdbeMUser
			, const uint x1IxWdbeVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWdbeWAccess
		) {
	ubigint retval = 0;
	WdbeAMUserAccess* _rec = NULL;

	_rec = new WdbeAMUserAccess(0, refWdbeMUser, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMUserAccess::appendNewRecToRst(
			ListWdbeAMUserAccess& rst
			, WdbeAMUserAccess** rec
			, const ubigint refWdbeMUser
			, const uint x1IxWdbeVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWdbeWAccess
		) {
	ubigint retval = 0;
	WdbeAMUserAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMUser, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMUserAccess::insertRst(
			ListWdbeAMUserAccess& rst
			, bool transact
		) {
};

void TblWdbeAMUserAccess::updateRec(
			WdbeAMUserAccess* rec
		) {
};

void TblWdbeAMUserAccess::updateRst(
			ListWdbeAMUserAccess& rst
			, bool transact
		) {
};

void TblWdbeAMUserAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMUserAccess::loadRecByRef(
			ubigint ref
			, WdbeAMUserAccess** rec
		) {
	return false;
};

ubigint TblWdbeAMUserAccess::loadRefsByUsr(
			ubigint refWdbeMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMUserAccess::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeAMUserAccess& rst
		) {
	return 0;
};

ubigint TblWdbeAMUserAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMUserAccess& rst
		) {
	ubigint numload = 0;
	WdbeAMUserAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMUserAccess
 ******************************************************************************/

MyTblWdbeAMUserAccess::MyTblWdbeAMUserAccess() :
			TblWdbeAMUserAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMUserAccess::~MyTblWdbeAMUserAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMUserAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMUserAccess (refWdbeMUser, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMUserAccess SET refWdbeMUser = ?, x1IxWdbeVFeatgroup = ?, x2FeaSrefUix = ?, ixWdbeWAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMUserAccess WHERE ref = ?", false);
};

bool MyTblWdbeAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WdbeAMUserAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMUserAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMUserAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMUserAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMUserAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMUser = atoll((char*) dbrow[1]); else _rec->refWdbeMUser = 0;
		if (dbrow[2]) _rec->x1IxWdbeVFeatgroup = atol((char*) dbrow[2]); else _rec->x1IxWdbeVFeatgroup = 0;
		if (dbrow[3]) _rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else _rec->x2FeaSrefUix = "";
		if (dbrow[4]) _rec->ixWdbeWAccess = atol((char*) dbrow[4]); else _rec->ixWdbeWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMUserAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMUserAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMUserAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMUserAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMUserAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMUser = atoll((char*) dbrow[1]); else rec->refWdbeMUser = 0;
			if (dbrow[2]) rec->x1IxWdbeVFeatgroup = atol((char*) dbrow[2]); else rec->x1IxWdbeVFeatgroup = 0;
			if (dbrow[3]) rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else rec->x2FeaSrefUix = "";
			if (dbrow[4]) rec->ixWdbeWAccess = atol((char*) dbrow[4]); else rec->ixWdbeWAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMUserAccess::insertRec(
			WdbeAMUserAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWdbeVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeWAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMUserAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMUserAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMUserAccess::insertRst(
			ListWdbeAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMUserAccess::updateRec(
			WdbeAMUserAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWdbeVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeWAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMUserAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMUserAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMUserAccess::updateRst(
			ListWdbeAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMUserAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMUserAccess::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMUserAccess::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMUserAccess::loadRecByRef(
			ubigint ref
			, WdbeAMUserAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMUserAccess WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMUserAccess::loadRefsByUsr(
			ubigint refWdbeMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMUserAccess WHERE refWdbeMUser = " + to_string(refWdbeMUser) + "", append, refs);
};

ubigint MyTblWdbeAMUserAccess::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeAMUserAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMUser, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess FROM TblWdbeAMUserAccess WHERE refWdbeMUser = " + to_string(refWdbeMUser) + " ORDER BY x1IxWdbeVFeatgroup ASC, x2FeaSrefUix ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMUserAccess
 ******************************************************************************/

PgTblWdbeAMUserAccess::PgTblWdbeAMUserAccess() :
			TblWdbeAMUserAccess()
			, PgTable()
		{
};

PgTblWdbeAMUserAccess::~PgTblWdbeAMUserAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMUserAccess::initStatements() {
	createStatement("TblWdbeAMUserAccess_insertRec", "INSERT INTO TblWdbeAMUserAccess (refWdbeMUser, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeAMUserAccess_updateRec", "UPDATE TblWdbeAMUserAccess SET refWdbeMUser = $1, x1IxWdbeVFeatgroup = $2, x2FeaSrefUix = $3, ixWdbeWAccess = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeAMUserAccess_removeRecByRef", "DELETE FROM TblWdbeAMUserAccess WHERE ref = $1", 1);

	createStatement("TblWdbeAMUserAccess_loadRecByRef", "SELECT ref, refWdbeMUser, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess FROM TblWdbeAMUserAccess WHERE ref = $1", 1);
	createStatement("TblWdbeAMUserAccess_loadRefsByUsr", "SELECT ref FROM TblWdbeAMUserAccess WHERE refWdbeMUser = $1", 1);
	createStatement("TblWdbeAMUserAccess_loadRstByUsr", "SELECT ref, refWdbeMUser, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess FROM TblWdbeAMUserAccess WHERE refWdbeMUser = $1 ORDER BY x1IxWdbeVFeatgroup ASC, x2FeaSrefUix ASC", 1);
};

bool PgTblWdbeAMUserAccess::loadRec(
			PGresult* res
			, WdbeAMUserAccess** rec
		) {
	char* ptr;

	WdbeAMUserAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMUserAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "x1ixwdbevfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwdbewaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxWdbeVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWdbeWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMUserAccess::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMUserAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMUserAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "x1ixwdbevfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwdbewaccess")
		};

		while (numread < numrow) {
			rec = new WdbeAMUserAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxWdbeVFeatgroup = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWdbeWAccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMUserAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMUserAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMUserAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMUserAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, WdbeAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMUserAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMUserAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMUserAccess::insertRec(
			WdbeAMUserAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	uint _x1IxWdbeVFeatgroup = htonl(rec->x1IxWdbeVFeatgroup);
	uint _ixWdbeWAccess = htonl(rec->ixWdbeWAccess);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_x1IxWdbeVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWdbeWAccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMUserAccess_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMUserAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMUserAccess::insertRst(
			ListWdbeAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMUserAccess::updateRec(
			WdbeAMUserAccess* rec
		) {
	PGresult* res;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	uint _x1IxWdbeVFeatgroup = htonl(rec->x1IxWdbeVFeatgroup);
	uint _ixWdbeWAccess = htonl(rec->ixWdbeWAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_x1IxWdbeVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWdbeWAccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMUserAccess_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMUserAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMUserAccess::updateRst(
			ListWdbeAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMUserAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMUserAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMUserAccess::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMUserAccess::loadRecByRef(
			ubigint ref
			, WdbeAMUserAccess** rec
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

	return loadRecByStmt("TblWdbeAMUserAccess_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMUserAccess::loadRefsByUsr(
			ubigint refWdbeMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMUser = htonl64(refWdbeMUser);

	const char* vals[] = {
		(char*) &_refWdbeMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMUserAccess_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMUserAccess::loadRstByUsr(
			ubigint refWdbeMUser
			, const bool append
			, ListWdbeAMUserAccess& rst
		) {
	ubigint _refWdbeMUser = htonl64(refWdbeMUser);

	const char* vals[] = {
		(char*) &_refWdbeMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMUserAccess_loadRstByUsr", 1, vals, l, f, append, rst);
};

#endif
