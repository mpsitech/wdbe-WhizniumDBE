/**
	* \file WdbeAMUsergroupAccess.cpp
	* database access for table TblWdbeAMUsergroupAccess (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeAMUsergroupAccess.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMUsergroupAccess
 ******************************************************************************/

WdbeAMUsergroupAccess::WdbeAMUsergroupAccess(
			const ubigint ref
			, const ubigint refWdbeMUsergroup
			, const uint x1IxWdbeVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWdbeWAccess
		) {

	this->ref = ref;
	this->refWdbeMUsergroup = refWdbeMUsergroup;
	this->x1IxWdbeVFeatgroup = x1IxWdbeVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWdbeWAccess = ixWdbeWAccess;
};

bool WdbeAMUsergroupAccess::operator==(
			const WdbeAMUsergroupAccess& comp
		) {
	return false;
};

bool WdbeAMUsergroupAccess::operator!=(
			const WdbeAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMUsergroupAccess
 ******************************************************************************/

ListWdbeAMUsergroupAccess::ListWdbeAMUsergroupAccess() {
};

ListWdbeAMUsergroupAccess::ListWdbeAMUsergroupAccess(
			const ListWdbeAMUsergroupAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMUsergroupAccess(*(src.nodes[i]));
};

ListWdbeAMUsergroupAccess::~ListWdbeAMUsergroupAccess() {
	clear();
};

void ListWdbeAMUsergroupAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMUsergroupAccess::size() const {
	return(nodes.size());
};

void ListWdbeAMUsergroupAccess::append(
			WdbeAMUsergroupAccess* rec
		) {
	nodes.push_back(rec);
};

WdbeAMUsergroupAccess* ListWdbeAMUsergroupAccess::operator[](
			const uint ix
		) {
	WdbeAMUsergroupAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMUsergroupAccess& ListWdbeAMUsergroupAccess::operator=(
			const ListWdbeAMUsergroupAccess& src
		) {
	WdbeAMUsergroupAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMUsergroupAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMUsergroupAccess::operator==(
			const ListWdbeAMUsergroupAccess& comp
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

bool ListWdbeAMUsergroupAccess::operator!=(
			const ListWdbeAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMUsergroupAccess
 ******************************************************************************/

TblWdbeAMUsergroupAccess::TblWdbeAMUsergroupAccess() {
};

TblWdbeAMUsergroupAccess::~TblWdbeAMUsergroupAccess() {
};

bool TblWdbeAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WdbeAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblWdbeAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblWdbeAMUsergroupAccess::insertRec(
			WdbeAMUsergroupAccess* rec
		) {
	return 0;
};

ubigint TblWdbeAMUsergroupAccess::insertNewRec(
			WdbeAMUsergroupAccess** rec
			, const ubigint refWdbeMUsergroup
			, const uint x1IxWdbeVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWdbeWAccess
		) {
	ubigint retval = 0;
	WdbeAMUsergroupAccess* _rec = NULL;

	_rec = new WdbeAMUsergroupAccess(0, refWdbeMUsergroup, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMUsergroupAccess::appendNewRecToRst(
			ListWdbeAMUsergroupAccess& rst
			, WdbeAMUsergroupAccess** rec
			, const ubigint refWdbeMUsergroup
			, const uint x1IxWdbeVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWdbeWAccess
		) {
	ubigint retval = 0;
	WdbeAMUsergroupAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMUsergroup, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMUsergroupAccess::insertRst(
			ListWdbeAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblWdbeAMUsergroupAccess::updateRec(
			WdbeAMUsergroupAccess* rec
		) {
};

void TblWdbeAMUsergroupAccess::updateRst(
			ListWdbeAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblWdbeAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WdbeAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblWdbeAMUsergroupAccess::loadRefsByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMUsergroupAccess::loadRstByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, ListWdbeAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblWdbeAMUsergroupAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMUsergroupAccess& rst
		) {
	ubigint numload = 0;
	WdbeAMUsergroupAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMUsergroupAccess
 ******************************************************************************/

MyTblWdbeAMUsergroupAccess::MyTblWdbeAMUsergroupAccess() :
			TblWdbeAMUsergroupAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMUsergroupAccess::~MyTblWdbeAMUsergroupAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMUsergroupAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMUsergroupAccess (refWdbeMUsergroup, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMUsergroupAccess SET refWdbeMUsergroup = ?, x1IxWdbeVFeatgroup = ?, x2FeaSrefUix = ?, ixWdbeWAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMUsergroupAccess WHERE ref = ?", false);
};

bool MyTblWdbeAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WdbeAMUsergroupAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMUsergroupAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMUsergroupAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMUsergroupAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMUsergroupAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMUsergroup = atoll((char*) dbrow[1]); else _rec->refWdbeMUsergroup = 0;
		if (dbrow[2]) _rec->x1IxWdbeVFeatgroup = atol((char*) dbrow[2]); else _rec->x1IxWdbeVFeatgroup = 0;
		if (dbrow[3]) _rec->x2FeaSrefUix.assign(dbrow[3], dblengths[3]); else _rec->x2FeaSrefUix = "";
		if (dbrow[4]) _rec->ixWdbeWAccess = atol((char*) dbrow[4]); else _rec->ixWdbeWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMUsergroupAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMUsergroupAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMUsergroupAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMUsergroupAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMUsergroupAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMUsergroup = atoll((char*) dbrow[1]); else rec->refWdbeMUsergroup = 0;
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

ubigint MyTblWdbeAMUsergroupAccess::insertRec(
			WdbeAMUsergroupAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWdbeVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeWAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMUsergroupAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMUsergroupAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMUsergroupAccess::insertRst(
			ListWdbeAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMUsergroupAccess::updateRec(
			WdbeAMUsergroupAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWdbeVFeatgroup,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeWAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMUsergroupAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMUsergroupAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMUsergroupAccess::updateRst(
			ListWdbeAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMUsergroupAccess::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMUsergroupAccess::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WdbeAMUsergroupAccess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMUsergroupAccess WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMUsergroupAccess::loadRefsByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMUsergroupAccess WHERE refWdbeMUsergroup = " + to_string(refWdbeMUsergroup) + "", append, refs);
};

ubigint MyTblWdbeAMUsergroupAccess::loadRstByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, ListWdbeAMUsergroupAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMUsergroup, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess FROM TblWdbeAMUsergroupAccess WHERE refWdbeMUsergroup = " + to_string(refWdbeMUsergroup) + " ORDER BY x1IxWdbeVFeatgroup ASC, x2FeaSrefUix ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMUsergroupAccess
 ******************************************************************************/

PgTblWdbeAMUsergroupAccess::PgTblWdbeAMUsergroupAccess() :
			TblWdbeAMUsergroupAccess()
			, PgTable()
		{
};

PgTblWdbeAMUsergroupAccess::~PgTblWdbeAMUsergroupAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMUsergroupAccess::initStatements() {
	createStatement("TblWdbeAMUsergroupAccess_insertRec", "INSERT INTO TblWdbeAMUsergroupAccess (refWdbeMUsergroup, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeAMUsergroupAccess_updateRec", "UPDATE TblWdbeAMUsergroupAccess SET refWdbeMUsergroup = $1, x1IxWdbeVFeatgroup = $2, x2FeaSrefUix = $3, ixWdbeWAccess = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeAMUsergroupAccess_removeRecByRef", "DELETE FROM TblWdbeAMUsergroupAccess WHERE ref = $1", 1);

	createStatement("TblWdbeAMUsergroupAccess_loadRecByRef", "SELECT ref, refWdbeMUsergroup, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess FROM TblWdbeAMUsergroupAccess WHERE ref = $1", 1);
	createStatement("TblWdbeAMUsergroupAccess_loadRefsByUsg", "SELECT ref FROM TblWdbeAMUsergroupAccess WHERE refWdbeMUsergroup = $1", 1);
	createStatement("TblWdbeAMUsergroupAccess_loadRstByUsg", "SELECT ref, refWdbeMUsergroup, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess FROM TblWdbeAMUsergroupAccess WHERE refWdbeMUsergroup = $1 ORDER BY x1IxWdbeVFeatgroup ASC, x2FeaSrefUix ASC", 1);
};

bool PgTblWdbeAMUsergroupAccess::loadRec(
			PGresult* res
			, WdbeAMUsergroupAccess** rec
		) {
	char* ptr;

	WdbeAMUsergroupAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMUsergroupAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemusergroup"),
			PQfnumber(res, "x1ixwdbevfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwdbewaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxWdbeVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWdbeWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMUsergroupAccess::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMUsergroupAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMUsergroupAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemusergroup"),
			PQfnumber(res, "x1ixwdbevfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwdbewaccess")
		};

		while (numread < numrow) {
			rec = new WdbeAMUsergroupAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMUsergroup = atoll(ptr);
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

bool PgTblWdbeAMUsergroupAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMUsergroupAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMUsergroupAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMUsergroupAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, WdbeAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMUsergroupAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMUsergroupAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMUsergroupAccess::insertRec(
			WdbeAMUsergroupAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMUsergroup = htonl64(rec->refWdbeMUsergroup);
	uint _x1IxWdbeVFeatgroup = htonl(rec->x1IxWdbeVFeatgroup);
	uint _ixWdbeWAccess = htonl(rec->ixWdbeWAccess);

	const char* vals[] = {
		(char*) &_refWdbeMUsergroup,
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

	res = PQexecPrepared(dbs, "TblWdbeAMUsergroupAccess_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMUsergroupAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMUsergroupAccess::insertRst(
			ListWdbeAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMUsergroupAccess::updateRec(
			WdbeAMUsergroupAccess* rec
		) {
	PGresult* res;

	ubigint _refWdbeMUsergroup = htonl64(rec->refWdbeMUsergroup);
	uint _x1IxWdbeVFeatgroup = htonl(rec->x1IxWdbeVFeatgroup);
	uint _ixWdbeWAccess = htonl(rec->ixWdbeWAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMUsergroup,
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

	res = PQexecPrepared(dbs, "TblWdbeAMUsergroupAccess_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMUsergroupAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMUsergroupAccess::updateRst(
			ListWdbeAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMUsergroupAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMUsergroupAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMUsergroupAccess::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, WdbeAMUsergroupAccess** rec
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

	return loadRecByStmt("TblWdbeAMUsergroupAccess_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMUsergroupAccess::loadRefsByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMUsergroup = htonl64(refWdbeMUsergroup);

	const char* vals[] = {
		(char*) &_refWdbeMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMUsergroupAccess_loadRefsByUsg", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMUsergroupAccess::loadRstByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, ListWdbeAMUsergroupAccess& rst
		) {
	ubigint _refWdbeMUsergroup = htonl64(refWdbeMUsergroup);

	const char* vals[] = {
		(char*) &_refWdbeMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMUsergroupAccess_loadRstByUsg", 1, vals, l, f, append, rst);
};

#endif

