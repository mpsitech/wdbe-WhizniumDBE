/**
	* \file WdbeMCoreversion.cpp
	* database access for table TblWdbeMCoreversion (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeMCoreversion.h"

#include "WdbeMCoreversion_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMCoreversion
 ******************************************************************************/

WdbeMCoreversion::WdbeMCoreversion(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refWdbeMCoreproject
			, const ubigint bcvRefWdbeMCoreversion
			, const ubigint refWdbeMModule
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWSpectype
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refWdbeMCoreproject = refWdbeMCoreproject;
	this->bcvRefWdbeMCoreversion = bcvRefWdbeMCoreversion;
	this->refWdbeMModule = refWdbeMModule;
	this->Major = Major;
	this->Minor = Minor;
	this->Sub = Sub;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->ixWSpectype = ixWSpectype;
};

bool WdbeMCoreversion::operator==(
			const WdbeMCoreversion& comp
		) {
	return false;
};

bool WdbeMCoreversion::operator!=(
			const WdbeMCoreversion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMCoreversion
 ******************************************************************************/

ListWdbeMCoreversion::ListWdbeMCoreversion() {
};

ListWdbeMCoreversion::ListWdbeMCoreversion(
			const ListWdbeMCoreversion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMCoreversion(*(src.nodes[i]));
};

ListWdbeMCoreversion::~ListWdbeMCoreversion() {
	clear();
};

void ListWdbeMCoreversion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMCoreversion::size() const {
	return(nodes.size());
};

void ListWdbeMCoreversion::append(
			WdbeMCoreversion* rec
		) {
	nodes.push_back(rec);
};

WdbeMCoreversion* ListWdbeMCoreversion::operator[](
			const uint ix
		) {
	WdbeMCoreversion* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMCoreversion& ListWdbeMCoreversion::operator=(
			const ListWdbeMCoreversion& src
		) {
	WdbeMCoreversion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMCoreversion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMCoreversion::operator==(
			const ListWdbeMCoreversion& comp
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

bool ListWdbeMCoreversion::operator!=(
			const ListWdbeMCoreversion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMCoreversion
 ******************************************************************************/

TblWdbeMCoreversion::TblWdbeMCoreversion() {
};

TblWdbeMCoreversion::~TblWdbeMCoreversion() {
};

bool TblWdbeMCoreversion::loadRecBySQL(
			const string& sqlstr
			, WdbeMCoreversion** rec
		) {
	return false;
};

ubigint TblWdbeMCoreversion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCoreversion& rst
		) {
	return 0;
};

ubigint TblWdbeMCoreversion::insertRec(
			WdbeMCoreversion* rec
		) {
	return 0;
};

ubigint TblWdbeMCoreversion::insertNewRec(
			WdbeMCoreversion** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refWdbeMCoreproject
			, const ubigint bcvRefWdbeMCoreversion
			, const ubigint refWdbeMModule
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWSpectype
		) {
	ubigint retval = 0;
	WdbeMCoreversion* _rec = NULL;

	_rec = new WdbeMCoreversion(0, grp, own, refWdbeMCoreproject, bcvRefWdbeMCoreversion, refWdbeMModule, Major, Minor, Sub, refJState, ixVState, ixWSpectype);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMCoreversion::appendNewRecToRst(
			ListWdbeMCoreversion& rst
			, WdbeMCoreversion** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refWdbeMCoreproject
			, const ubigint bcvRefWdbeMCoreversion
			, const ubigint refWdbeMModule
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWSpectype
		) {
	ubigint retval = 0;
	WdbeMCoreversion* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refWdbeMCoreproject, bcvRefWdbeMCoreversion, refWdbeMModule, Major, Minor, Sub, refJState, ixVState, ixWSpectype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMCoreversion::insertRst(
			ListWdbeMCoreversion& rst
			, bool transact
		) {
};

void TblWdbeMCoreversion::updateRec(
			WdbeMCoreversion* rec
		) {
};

void TblWdbeMCoreversion::updateRst(
			ListWdbeMCoreversion& rst
			, bool transact
		) {
};

void TblWdbeMCoreversion::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMCoreversion::loadRecByRef(
			ubigint ref
			, WdbeMCoreversion** rec
		) {
	return false;
};

ubigint TblWdbeMCoreversion::loadRefsByCpr(
			ubigint refWdbeMCoreproject
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMCoreversion::loadRstByCpr(
			ubigint refWdbeMCoreproject
			, const bool append
			, ListWdbeMCoreversion& rst
		) {
	return 0;
};

ubigint TblWdbeMCoreversion::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMCoreversion& rst
		) {
	ubigint numload = 0;
	WdbeMCoreversion* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMCoreversion
 ******************************************************************************/

MyTblWdbeMCoreversion::MyTblWdbeMCoreversion() :
			TblWdbeMCoreversion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMCoreversion::~MyTblWdbeMCoreversion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMCoreversion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMCoreversion (grp, own, refWdbeMCoreproject, bcvRefWdbeMCoreversion, refWdbeMModule, Major, Minor, Sub, refJState, ixVState, ixWSpectype) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMCoreversion SET grp = ?, own = ?, refWdbeMCoreproject = ?, bcvRefWdbeMCoreversion = ?, refWdbeMModule = ?, Major = ?, Minor = ?, Sub = ?, refJState = ?, ixVState = ?, ixWSpectype = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMCoreversion WHERE ref = ?", false);
};

bool MyTblWdbeMCoreversion::loadRecBySQL(
			const string& sqlstr
			, WdbeMCoreversion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMCoreversion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMCoreversion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMCoreversion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeMCoreversion();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refWdbeMCoreproject = atoll((char*) dbrow[3]); else _rec->refWdbeMCoreproject = 0;
		if (dbrow[4]) _rec->bcvRefWdbeMCoreversion = atoll((char*) dbrow[4]); else _rec->bcvRefWdbeMCoreversion = 0;
		if (dbrow[5]) _rec->refWdbeMModule = atoll((char*) dbrow[5]); else _rec->refWdbeMModule = 0;
		if (dbrow[6]) _rec->Major = atoi((char*) dbrow[6]); else _rec->Major = 0;
		if (dbrow[7]) _rec->Minor = atoi((char*) dbrow[7]); else _rec->Minor = 0;
		if (dbrow[8]) _rec->Sub = atoi((char*) dbrow[8]); else _rec->Sub = 0;
		if (dbrow[9]) _rec->refJState = atoll((char*) dbrow[9]); else _rec->refJState = 0;
		if (dbrow[10]) _rec->ixVState = atol((char*) dbrow[10]); else _rec->ixVState = 0;
		if (dbrow[11]) _rec->ixWSpectype = atol((char*) dbrow[11]); else _rec->ixWSpectype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMCoreversion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCoreversion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMCoreversion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMCoreversion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMCoreversion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeMCoreversion();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refWdbeMCoreproject = atoll((char*) dbrow[3]); else rec->refWdbeMCoreproject = 0;
			if (dbrow[4]) rec->bcvRefWdbeMCoreversion = atoll((char*) dbrow[4]); else rec->bcvRefWdbeMCoreversion = 0;
			if (dbrow[5]) rec->refWdbeMModule = atoll((char*) dbrow[5]); else rec->refWdbeMModule = 0;
			if (dbrow[6]) rec->Major = atoi((char*) dbrow[6]); else rec->Major = 0;
			if (dbrow[7]) rec->Minor = atoi((char*) dbrow[7]); else rec->Minor = 0;
			if (dbrow[8]) rec->Sub = atoi((char*) dbrow[8]); else rec->Sub = 0;
			if (dbrow[9]) rec->refJState = atoll((char*) dbrow[9]); else rec->refJState = 0;
			if (dbrow[10]) rec->ixVState = atol((char*) dbrow[10]); else rec->ixVState = 0;
			if (dbrow[11]) rec->ixWSpectype = atol((char*) dbrow[11]); else rec->ixWSpectype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMCoreversion::insertRec(
			WdbeMCoreversion* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeMCoreproject,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->bcvRefWdbeMCoreversion,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Major,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Minor,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Sub,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixVState,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixWSpectype,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMCoreversion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMCoreversion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMCoreversion::insertRst(
			ListWdbeMCoreversion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMCoreversion::updateRec(
			WdbeMCoreversion* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeMCoreproject,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->bcvRefWdbeMCoreversion,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Major,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Minor,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Sub,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixVState,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixWSpectype,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMCoreversion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMCoreversion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMCoreversion::updateRst(
			ListWdbeMCoreversion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMCoreversion::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMCoreversion::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMCoreversion::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMCoreversion::loadRecByRef(
			ubigint ref
			, WdbeMCoreversion** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMCoreversion WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMCoreversion::loadRefsByCpr(
			ubigint refWdbeMCoreproject
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMCoreversion WHERE refWdbeMCoreproject = " + to_string(refWdbeMCoreproject) + "", append, refs);
};

ubigint MyTblWdbeMCoreversion::loadRstByCpr(
			ubigint refWdbeMCoreproject
			, const bool append
			, ListWdbeMCoreversion& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, refWdbeMCoreproject, bcvRefWdbeMCoreversion, refWdbeMModule, Major, Minor, Sub, refJState, ixVState, ixWSpectype FROM TblWdbeMCoreversion WHERE refWdbeMCoreproject = " + to_string(refWdbeMCoreproject) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMCoreversion
 ******************************************************************************/

PgTblWdbeMCoreversion::PgTblWdbeMCoreversion() :
			TblWdbeMCoreversion()
			, PgTable()
		{
};

PgTblWdbeMCoreversion::~PgTblWdbeMCoreversion() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMCoreversion::initStatements() {
	createStatement("TblWdbeMCoreversion_insertRec", "INSERT INTO TblWdbeMCoreversion (grp, own, refWdbeMCoreproject, bcvRefWdbeMCoreversion, refWdbeMModule, Major, Minor, Sub, refJState, ixVState, ixWSpectype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11);
	createStatement("TblWdbeMCoreversion_updateRec", "UPDATE TblWdbeMCoreversion SET grp = $1, own = $2, refWdbeMCoreproject = $3, bcvRefWdbeMCoreversion = $4, refWdbeMModule = $5, Major = $6, Minor = $7, Sub = $8, refJState = $9, ixVState = $10, ixWSpectype = $11 WHERE ref = $12", 12);
	createStatement("TblWdbeMCoreversion_removeRecByRef", "DELETE FROM TblWdbeMCoreversion WHERE ref = $1", 1);

	createStatement("TblWdbeMCoreversion_loadRecByRef", "SELECT ref, grp, own, refWdbeMCoreproject, bcvRefWdbeMCoreversion, refWdbeMModule, Major, Minor, Sub, refJState, ixVState, ixWSpectype FROM TblWdbeMCoreversion WHERE ref = $1", 1);
	createStatement("TblWdbeMCoreversion_loadRefsByCpr", "SELECT ref FROM TblWdbeMCoreversion WHERE refWdbeMCoreproject = $1", 1);
	createStatement("TblWdbeMCoreversion_loadRstByCpr", "SELECT ref, grp, own, refWdbeMCoreproject, bcvRefWdbeMCoreversion, refWdbeMModule, Major, Minor, Sub, refJState, ixVState, ixWSpectype FROM TblWdbeMCoreversion WHERE refWdbeMCoreproject = $1", 1);
};

bool PgTblWdbeMCoreversion::loadRec(
			PGresult* res
			, WdbeMCoreversion** rec
		) {
	char* ptr;

	WdbeMCoreversion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMCoreversion();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwdbemcoreproject"),
			PQfnumber(res, "bcvrefwdbemcoreversion"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "major"),
			PQfnumber(res, "minor"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwspectype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWdbeMCoreproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->bcvRefWdbeMCoreversion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Major = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Minor = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Sub = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->ixWSpectype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMCoreversion::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMCoreversion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMCoreversion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwdbemcoreproject"),
			PQfnumber(res, "bcvrefwdbemcoreversion"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "major"),
			PQfnumber(res, "minor"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwspectype")
		};

		while (numread < numrow) {
			rec = new WdbeMCoreversion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWdbeMCoreproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->bcvRefWdbeMCoreversion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Major = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Minor = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Sub = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->ixWSpectype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMCoreversion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMCoreversion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCoreversion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMCoreversion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMCoreversion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCoreversion::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMCoreversion::loadRecBySQL(
			const string& sqlstr
			, WdbeMCoreversion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCoreversion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMCoreversion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCoreversion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCoreversion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMCoreversion::insertRec(
			WdbeMCoreversion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeMCoreproject = htonl64(rec->refWdbeMCoreproject);
	ubigint _bcvRefWdbeMCoreversion = htonl64(rec->bcvRefWdbeMCoreversion);
	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	usmallint _Major = htons(rec->Major);
	usmallint _Minor = htons(rec->Minor);
	usmallint _Sub = htons(rec->Sub);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWSpectype = htonl(rec->ixWSpectype);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWdbeMCoreproject,
		(char*) &_bcvRefWdbeMCoreversion,
		(char*) &_refWdbeMModule,
		(char*) &_Major,
		(char*) &_Minor,
		(char*) &_Sub,
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixWSpectype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeMCoreversion_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCoreversion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMCoreversion::insertRst(
			ListWdbeMCoreversion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMCoreversion::updateRec(
			WdbeMCoreversion* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeMCoreproject = htonl64(rec->refWdbeMCoreproject);
	ubigint _bcvRefWdbeMCoreversion = htonl64(rec->bcvRefWdbeMCoreversion);
	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	usmallint _Major = htons(rec->Major);
	usmallint _Minor = htons(rec->Minor);
	usmallint _Sub = htons(rec->Sub);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWSpectype = htonl(rec->ixWSpectype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWdbeMCoreproject,
		(char*) &_bcvRefWdbeMCoreversion,
		(char*) &_refWdbeMModule,
		(char*) &_Major,
		(char*) &_Minor,
		(char*) &_Sub,
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixWSpectype,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeMCoreversion_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMCoreversion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMCoreversion::updateRst(
			ListWdbeMCoreversion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMCoreversion::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMCoreversion_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMCoreversion::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMCoreversion::loadRecByRef(
			ubigint ref
			, WdbeMCoreversion** rec
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

	return loadRecByStmt("TblWdbeMCoreversion_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMCoreversion::loadRefsByCpr(
			ubigint refWdbeMCoreproject
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMCoreproject = htonl64(refWdbeMCoreproject);

	const char* vals[] = {
		(char*) &_refWdbeMCoreproject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMCoreversion_loadRefsByCpr", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMCoreversion::loadRstByCpr(
			ubigint refWdbeMCoreproject
			, const bool append
			, ListWdbeMCoreversion& rst
		) {
	ubigint _refWdbeMCoreproject = htonl64(refWdbeMCoreproject);

	const char* vals[] = {
		(char*) &_refWdbeMCoreproject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMCoreversion_loadRstByCpr", 1, vals, l, f, append, rst);
};

#endif

