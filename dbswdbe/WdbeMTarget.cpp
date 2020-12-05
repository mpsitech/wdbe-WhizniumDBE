/**
	* \file WdbeMTarget.cpp
	* database access for table TblWdbeMTarget (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMTarget.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMTarget
 ******************************************************************************/

WdbeMTarget::WdbeMTarget(
			const ubigint ref
			, const ubigint sysRefWdbeMSystem
			, const uint sysNum
			, const ubigint refWdbeMUnit
			, const string sref
			, const string rteSrefsWdbeMModule
			, const string Comment
		) {

	this->ref = ref;
	this->sysRefWdbeMSystem = sysRefWdbeMSystem;
	this->sysNum = sysNum;
	this->refWdbeMUnit = refWdbeMUnit;
	this->sref = sref;
	this->rteSrefsWdbeMModule = rteSrefsWdbeMModule;
	this->Comment = Comment;
};

bool WdbeMTarget::operator==(
			const WdbeMTarget& comp
		) {
	return false;
};

bool WdbeMTarget::operator!=(
			const WdbeMTarget& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMTarget
 ******************************************************************************/

ListWdbeMTarget::ListWdbeMTarget() {
};

ListWdbeMTarget::ListWdbeMTarget(
			const ListWdbeMTarget& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMTarget(*(src.nodes[i]));
};

ListWdbeMTarget::~ListWdbeMTarget() {
	clear();
};

void ListWdbeMTarget::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMTarget::size() const {
	return(nodes.size());
};

void ListWdbeMTarget::append(
			WdbeMTarget* rec
		) {
	nodes.push_back(rec);
};

WdbeMTarget* ListWdbeMTarget::operator[](
			const uint ix
		) {
	WdbeMTarget* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMTarget& ListWdbeMTarget::operator=(
			const ListWdbeMTarget& src
		) {
	WdbeMTarget* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMTarget(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMTarget::operator==(
			const ListWdbeMTarget& comp
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

bool ListWdbeMTarget::operator!=(
			const ListWdbeMTarget& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMTarget
 ******************************************************************************/

TblWdbeMTarget::TblWdbeMTarget() {
};

TblWdbeMTarget::~TblWdbeMTarget() {
};

bool TblWdbeMTarget::loadRecBySQL(
			const string& sqlstr
			, WdbeMTarget** rec
		) {
	return false;
};

ubigint TblWdbeMTarget::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMTarget& rst
		) {
	return 0;
};

ubigint TblWdbeMTarget::insertRec(
			WdbeMTarget* rec
		) {
	return 0;
};

ubigint TblWdbeMTarget::insertNewRec(
			WdbeMTarget** rec
			, const ubigint sysRefWdbeMSystem
			, const uint sysNum
			, const ubigint refWdbeMUnit
			, const string sref
			, const string rteSrefsWdbeMModule
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMTarget* _rec = NULL;

	_rec = new WdbeMTarget(0, sysRefWdbeMSystem, sysNum, refWdbeMUnit, sref, rteSrefsWdbeMModule, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMTarget::appendNewRecToRst(
			ListWdbeMTarget& rst
			, WdbeMTarget** rec
			, const ubigint sysRefWdbeMSystem
			, const uint sysNum
			, const ubigint refWdbeMUnit
			, const string sref
			, const string rteSrefsWdbeMModule
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMTarget* _rec = NULL;

	retval = insertNewRec(&_rec, sysRefWdbeMSystem, sysNum, refWdbeMUnit, sref, rteSrefsWdbeMModule, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMTarget::insertRst(
			ListWdbeMTarget& rst
			, bool transact
		) {
};

void TblWdbeMTarget::updateRec(
			WdbeMTarget* rec
		) {
};

void TblWdbeMTarget::updateRst(
			ListWdbeMTarget& rst
			, bool transact
		) {
};

void TblWdbeMTarget::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMTarget::loadRecByRef(
			ubigint ref
			, WdbeMTarget** rec
		) {
	return false;
};

ubigint TblWdbeMTarget::loadRefsBySys(
			ubigint sysRefWdbeMSystem
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMTarget::loadRstBySys(
			ubigint sysRefWdbeMSystem
			, const bool append
			, ListWdbeMTarget& rst
		) {
	return 0;
};

bool TblWdbeMTarget::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMTarget::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMTarget& rst
		) {
	ubigint numload = 0;
	WdbeMTarget* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMTarget
 ******************************************************************************/

MyTblWdbeMTarget::MyTblWdbeMTarget() :
			TblWdbeMTarget()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMTarget::~MyTblWdbeMTarget() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMTarget::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMTarget (sysRefWdbeMSystem, sysNum, refWdbeMUnit, sref, rteSrefsWdbeMModule, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMTarget SET sysRefWdbeMSystem = ?, sysNum = ?, refWdbeMUnit = ?, sref = ?, rteSrefsWdbeMModule = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMTarget WHERE ref = ?", false);
};

bool MyTblWdbeMTarget::loadRecBySQL(
			const string& sqlstr
			, WdbeMTarget** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMTarget* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMTarget::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMTarget::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMTarget();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->sysRefWdbeMSystem = atoll((char*) dbrow[1]); else _rec->sysRefWdbeMSystem = 0;
		if (dbrow[2]) _rec->sysNum = atol((char*) dbrow[2]); else _rec->sysNum = 0;
		if (dbrow[3]) _rec->refWdbeMUnit = atoll((char*) dbrow[3]); else _rec->refWdbeMUnit = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->rteSrefsWdbeMModule.assign(dbrow[5], dblengths[5]); else _rec->rteSrefsWdbeMModule = "";
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMTarget::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMTarget& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMTarget* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMTarget::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMTarget::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMTarget();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->sysRefWdbeMSystem = atoll((char*) dbrow[1]); else rec->sysRefWdbeMSystem = 0;
			if (dbrow[2]) rec->sysNum = atol((char*) dbrow[2]); else rec->sysNum = 0;
			if (dbrow[3]) rec->refWdbeMUnit = atoll((char*) dbrow[3]); else rec->refWdbeMUnit = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->rteSrefsWdbeMModule.assign(dbrow[5], dblengths[5]); else rec->rteSrefsWdbeMModule = "";
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMTarget::insertRec(
			WdbeMTarget* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();
	l[4] = rec->rteSrefsWdbeMModule.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->sysRefWdbeMSystem,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->sysNum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeMUnit,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->rteSrefsWdbeMModule.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMTarget::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMTarget::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMTarget::insertRst(
			ListWdbeMTarget& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMTarget::updateRec(
			WdbeMTarget* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	l[4] = rec->rteSrefsWdbeMModule.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->sysRefWdbeMSystem,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->sysNum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeMUnit,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->rteSrefsWdbeMModule.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMTarget::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMTarget::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMTarget::updateRst(
			ListWdbeMTarget& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMTarget::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMTarget::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMTarget::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMTarget::loadRecByRef(
			ubigint ref
			, WdbeMTarget** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMTarget WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMTarget::loadRefsBySys(
			ubigint sysRefWdbeMSystem
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMTarget WHERE sysRefWdbeMSystem = " + to_string(sysRefWdbeMSystem) + "", append, refs);
};

ubigint MyTblWdbeMTarget::loadRstBySys(
			ubigint sysRefWdbeMSystem
			, const bool append
			, ListWdbeMTarget& rst
		) {
	return loadRstBySQL("SELECT ref, sysRefWdbeMSystem, sysNum, refWdbeMUnit, sref, rteSrefsWdbeMModule, Comment FROM TblWdbeMTarget WHERE sysRefWdbeMSystem = " + to_string(sysRefWdbeMSystem) + " ORDER BY sysNum ASC", append, rst);
};

bool MyTblWdbeMTarget::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMTarget WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMTarget
 ******************************************************************************/

PgTblWdbeMTarget::PgTblWdbeMTarget() :
			TblWdbeMTarget()
			, PgTable()
		{
};

PgTblWdbeMTarget::~PgTblWdbeMTarget() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMTarget::initStatements() {
	createStatement("TblWdbeMTarget_insertRec", "INSERT INTO TblWdbeMTarget (sysRefWdbeMSystem, sysNum, refWdbeMUnit, sref, rteSrefsWdbeMModule, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6);
	createStatement("TblWdbeMTarget_updateRec", "UPDATE TblWdbeMTarget SET sysRefWdbeMSystem = $1, sysNum = $2, refWdbeMUnit = $3, sref = $4, rteSrefsWdbeMModule = $5, Comment = $6 WHERE ref = $7", 7);
	createStatement("TblWdbeMTarget_removeRecByRef", "DELETE FROM TblWdbeMTarget WHERE ref = $1", 1);

	createStatement("TblWdbeMTarget_loadRecByRef", "SELECT ref, sysRefWdbeMSystem, sysNum, refWdbeMUnit, sref, rteSrefsWdbeMModule, Comment FROM TblWdbeMTarget WHERE ref = $1", 1);
	createStatement("TblWdbeMTarget_loadRefsBySys", "SELECT ref FROM TblWdbeMTarget WHERE sysRefWdbeMSystem = $1", 1);
	createStatement("TblWdbeMTarget_loadRstBySys", "SELECT ref, sysRefWdbeMSystem, sysNum, refWdbeMUnit, sref, rteSrefsWdbeMModule, Comment FROM TblWdbeMTarget WHERE sysRefWdbeMSystem = $1 ORDER BY sysNum ASC", 1);
	createStatement("TblWdbeMTarget_loadSrfByRef", "SELECT sref FROM TblWdbeMTarget WHERE ref = $1", 1);
};

bool PgTblWdbeMTarget::loadRec(
			PGresult* res
			, WdbeMTarget** rec
		) {
	char* ptr;

	WdbeMTarget* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMTarget();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sysrefwdbemsystem"),
			PQfnumber(res, "sysnum"),
			PQfnumber(res, "refwdbemunit"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "rtesrefswdbemmodule"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->sysRefWdbeMSystem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sysNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWdbeMUnit = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->rteSrefsWdbeMModule.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMTarget::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMTarget& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMTarget* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sysrefwdbemsystem"),
			PQfnumber(res, "sysnum"),
			PQfnumber(res, "refwdbemunit"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "rtesrefswdbemmodule"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMTarget();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->sysRefWdbeMSystem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sysNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWdbeMUnit = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->rteSrefsWdbeMModule.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMTarget::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMTarget** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMTarget::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMTarget::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMTarget& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMTarget::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMTarget::loadRecBySQL(
			const string& sqlstr
			, WdbeMTarget** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMTarget::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMTarget::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMTarget& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMTarget::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMTarget::insertRec(
			WdbeMTarget* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _sysRefWdbeMSystem = htonl64(rec->sysRefWdbeMSystem);
	uint _sysNum = htonl(rec->sysNum);
	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);

	const char* vals[] = {
		(char*) &_sysRefWdbeMSystem,
		(char*) &_sysNum,
		(char*) &_refWdbeMUnit,
		rec->sref.c_str(),
		rec->rteSrefsWdbeMModule.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMTarget_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMTarget::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMTarget::insertRst(
			ListWdbeMTarget& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMTarget::updateRec(
			WdbeMTarget* rec
		) {
	PGresult* res;

	ubigint _sysRefWdbeMSystem = htonl64(rec->sysRefWdbeMSystem);
	uint _sysNum = htonl(rec->sysNum);
	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_sysRefWdbeMSystem,
		(char*) &_sysNum,
		(char*) &_refWdbeMUnit,
		rec->sref.c_str(),
		rec->rteSrefsWdbeMModule.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMTarget_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMTarget::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMTarget::updateRst(
			ListWdbeMTarget& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMTarget::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMTarget_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMTarget::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMTarget::loadRecByRef(
			ubigint ref
			, WdbeMTarget** rec
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

	return loadRecByStmt("TblWdbeMTarget_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMTarget::loadRefsBySys(
			ubigint sysRefWdbeMSystem
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _sysRefWdbeMSystem = htonl64(sysRefWdbeMSystem);

	const char* vals[] = {
		(char*) &_sysRefWdbeMSystem
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMTarget_loadRefsBySys", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMTarget::loadRstBySys(
			ubigint sysRefWdbeMSystem
			, const bool append
			, ListWdbeMTarget& rst
		) {
	ubigint _sysRefWdbeMSystem = htonl64(sysRefWdbeMSystem);

	const char* vals[] = {
		(char*) &_sysRefWdbeMSystem
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMTarget_loadRstBySys", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMTarget::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMTarget_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

