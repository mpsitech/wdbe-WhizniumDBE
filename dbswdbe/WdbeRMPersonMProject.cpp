/**
	* \file WdbeRMPersonMProject.cpp
	* database access for table TblWdbeRMPersonMProject (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeRMPersonMProject.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeRMPersonMProject
 ******************************************************************************/

WdbeRMPersonMProject::WdbeRMPersonMProject(
			const ubigint ref
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refWdbeMPerson
			, const ubigint refWdbeMProject
			, const string srefKFunction
		) {

	this->ref = ref;
	this->x1Startd = x1Startd;
	this->x1Stopd = x1Stopd;
	this->refWdbeMPerson = refWdbeMPerson;
	this->refWdbeMProject = refWdbeMProject;
	this->srefKFunction = srefKFunction;
};

bool WdbeRMPersonMProject::operator==(
			const WdbeRMPersonMProject& comp
		) {
	return false;
};

bool WdbeRMPersonMProject::operator!=(
			const WdbeRMPersonMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeRMPersonMProject
 ******************************************************************************/

ListWdbeRMPersonMProject::ListWdbeRMPersonMProject() {
};

ListWdbeRMPersonMProject::ListWdbeRMPersonMProject(
			const ListWdbeRMPersonMProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeRMPersonMProject(*(src.nodes[i]));
};

ListWdbeRMPersonMProject::~ListWdbeRMPersonMProject() {
	clear();
};

void ListWdbeRMPersonMProject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeRMPersonMProject::size() const {
	return(nodes.size());
};

void ListWdbeRMPersonMProject::append(
			WdbeRMPersonMProject* rec
		) {
	nodes.push_back(rec);
};

WdbeRMPersonMProject* ListWdbeRMPersonMProject::operator[](
			const uint ix
		) {
	WdbeRMPersonMProject* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeRMPersonMProject& ListWdbeRMPersonMProject::operator=(
			const ListWdbeRMPersonMProject& src
		) {
	WdbeRMPersonMProject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeRMPersonMProject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeRMPersonMProject::operator==(
			const ListWdbeRMPersonMProject& comp
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

bool ListWdbeRMPersonMProject::operator!=(
			const ListWdbeRMPersonMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeRMPersonMProject
 ******************************************************************************/

TblWdbeRMPersonMProject::TblWdbeRMPersonMProject() {
};

TblWdbeRMPersonMProject::~TblWdbeRMPersonMProject() {
};

bool TblWdbeRMPersonMProject::loadRecBySQL(
			const string& sqlstr
			, WdbeRMPersonMProject** rec
		) {
	return false;
};

ubigint TblWdbeRMPersonMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	return 0;
};

ubigint TblWdbeRMPersonMProject::insertRec(
			WdbeRMPersonMProject* rec
		) {
	return 0;
};

ubigint TblWdbeRMPersonMProject::insertNewRec(
			WdbeRMPersonMProject** rec
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refWdbeMPerson
			, const ubigint refWdbeMProject
			, const string srefKFunction
		) {
	ubigint retval = 0;
	WdbeRMPersonMProject* _rec = NULL;

	_rec = new WdbeRMPersonMProject(0, x1Startd, x1Stopd, refWdbeMPerson, refWdbeMProject, srefKFunction);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeRMPersonMProject::appendNewRecToRst(
			ListWdbeRMPersonMProject& rst
			, WdbeRMPersonMProject** rec
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refWdbeMPerson
			, const ubigint refWdbeMProject
			, const string srefKFunction
		) {
	ubigint retval = 0;
	WdbeRMPersonMProject* _rec = NULL;

	retval = insertNewRec(&_rec, x1Startd, x1Stopd, refWdbeMPerson, refWdbeMProject, srefKFunction);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeRMPersonMProject::insertRst(
			ListWdbeRMPersonMProject& rst
			, bool transact
		) {
};

void TblWdbeRMPersonMProject::updateRec(
			WdbeRMPersonMProject* rec
		) {
};

void TblWdbeRMPersonMProject::updateRst(
			ListWdbeRMPersonMProject& rst
			, bool transact
		) {
};

void TblWdbeRMPersonMProject::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeRMPersonMProject::loadRecByRef(
			ubigint ref
			, WdbeRMPersonMProject** rec
		) {
	return false;
};

ubigint TblWdbeRMPersonMProject::loadRefsByPrj(
			ubigint refWdbeMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeRMPersonMProject::loadRstByPrj(
			ubigint refWdbeMProject
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	return 0;
};

ubigint TblWdbeRMPersonMProject::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	return 0;
};

ubigint TblWdbeRMPersonMProject::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	ubigint numload = 0;
	WdbeRMPersonMProject* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeRMPersonMProject
 ******************************************************************************/

MyTblWdbeRMPersonMProject::MyTblWdbeRMPersonMProject() :
			TblWdbeRMPersonMProject()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeRMPersonMProject::~MyTblWdbeRMPersonMProject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeRMPersonMProject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeRMPersonMProject (x1Startd, x1Stopd, refWdbeMPerson, refWdbeMProject, srefKFunction) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeRMPersonMProject SET x1Startd = ?, x1Stopd = ?, refWdbeMPerson = ?, refWdbeMProject = ?, srefKFunction = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeRMPersonMProject WHERE ref = ?", false);
};

bool MyTblWdbeRMPersonMProject::loadRecBySQL(
			const string& sqlstr
			, WdbeRMPersonMProject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeRMPersonMProject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMPersonMProject::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMPersonMProject::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeRMPersonMProject();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Startd = atol((char*) dbrow[1]); else _rec->x1Startd = 0;
		if (dbrow[2]) _rec->x1Stopd = atol((char*) dbrow[2]); else _rec->x1Stopd = 0;
		if (dbrow[3]) _rec->refWdbeMPerson = atoll((char*) dbrow[3]); else _rec->refWdbeMPerson = 0;
		if (dbrow[4]) _rec->refWdbeMProject = atoll((char*) dbrow[4]); else _rec->refWdbeMProject = 0;
		if (dbrow[5]) _rec->srefKFunction.assign(dbrow[5], dblengths[5]); else _rec->srefKFunction = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeRMPersonMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeRMPersonMProject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMPersonMProject::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMPersonMProject::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeRMPersonMProject();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Startd = atol((char*) dbrow[1]); else rec->x1Startd = 0;
			if (dbrow[2]) rec->x1Stopd = atol((char*) dbrow[2]); else rec->x1Stopd = 0;
			if (dbrow[3]) rec->refWdbeMPerson = atoll((char*) dbrow[3]); else rec->refWdbeMPerson = 0;
			if (dbrow[4]) rec->refWdbeMProject = atoll((char*) dbrow[4]); else rec->refWdbeMProject = 0;
			if (dbrow[5]) rec->srefKFunction.assign(dbrow[5], dblengths[5]); else rec->srefKFunction = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeRMPersonMProject::insertRec(
			WdbeRMPersonMProject* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[4] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Startd,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stopd,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeMPerson,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWdbeMProject,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeRMPersonMProject::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeRMPersonMProject::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeRMPersonMProject::insertRst(
			ListWdbeRMPersonMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeRMPersonMProject::updateRec(
			WdbeRMPersonMProject* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Startd,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stopd,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeMPerson,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWdbeMProject,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeRMPersonMProject::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeRMPersonMProject::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeRMPersonMProject::updateRst(
			ListWdbeRMPersonMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeRMPersonMProject::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeRMPersonMProject::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeRMPersonMProject::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeRMPersonMProject::loadRecByRef(
			ubigint ref
			, WdbeRMPersonMProject** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeRMPersonMProject WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeRMPersonMProject::loadRefsByPrj(
			ubigint refWdbeMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeRMPersonMProject WHERE refWdbeMProject = " + to_string(refWdbeMProject) + "", append, refs);
};

ubigint MyTblWdbeRMPersonMProject::loadRstByPrj(
			ubigint refWdbeMProject
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startd, x1Stopd, refWdbeMPerson, refWdbeMProject, srefKFunction FROM TblWdbeRMPersonMProject WHERE refWdbeMProject = " + to_string(refWdbeMProject) + "", append, rst);
};

ubigint MyTblWdbeRMPersonMProject::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startd, x1Stopd, refWdbeMPerson, refWdbeMProject, srefKFunction FROM TblWdbeRMPersonMProject WHERE refWdbeMPerson = " + to_string(refWdbeMPerson) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeRMPersonMProject
 ******************************************************************************/

PgTblWdbeRMPersonMProject::PgTblWdbeRMPersonMProject() :
			TblWdbeRMPersonMProject()
			, PgTable()
		{
};

PgTblWdbeRMPersonMProject::~PgTblWdbeRMPersonMProject() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeRMPersonMProject::initStatements() {
	createStatement("TblWdbeRMPersonMProject_insertRec", "INSERT INTO TblWdbeRMPersonMProject (x1Startd, x1Stopd, refWdbeMPerson, refWdbeMProject, srefKFunction) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWdbeRMPersonMProject_updateRec", "UPDATE TblWdbeRMPersonMProject SET x1Startd = $1, x1Stopd = $2, refWdbeMPerson = $3, refWdbeMProject = $4, srefKFunction = $5 WHERE ref = $6", 6);
	createStatement("TblWdbeRMPersonMProject_removeRecByRef", "DELETE FROM TblWdbeRMPersonMProject WHERE ref = $1", 1);

	createStatement("TblWdbeRMPersonMProject_loadRecByRef", "SELECT ref, x1Startd, x1Stopd, refWdbeMPerson, refWdbeMProject, srefKFunction FROM TblWdbeRMPersonMProject WHERE ref = $1", 1);
	createStatement("TblWdbeRMPersonMProject_loadRefsByPrj", "SELECT ref FROM TblWdbeRMPersonMProject WHERE refWdbeMProject = $1", 1);
	createStatement("TblWdbeRMPersonMProject_loadRstByPrj", "SELECT ref, x1Startd, x1Stopd, refWdbeMPerson, refWdbeMProject, srefKFunction FROM TblWdbeRMPersonMProject WHERE refWdbeMProject = $1", 1);
	createStatement("TblWdbeRMPersonMProject_loadRstByPrs", "SELECT ref, x1Startd, x1Stopd, refWdbeMPerson, refWdbeMProject, srefKFunction FROM TblWdbeRMPersonMProject WHERE refWdbeMPerson = $1", 1);
};

bool PgTblWdbeRMPersonMProject::loadRec(
			PGresult* res
			, WdbeRMPersonMProject** rec
		) {
	char* ptr;

	WdbeRMPersonMProject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeRMPersonMProject();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "refwdbemproject"),
			PQfnumber(res, "srefkfunction")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stopd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWdbeMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWdbeMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefKFunction.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeRMPersonMProject::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeRMPersonMProject* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "refwdbemproject"),
			PQfnumber(res, "srefkfunction")
		};

		while (numread < numrow) {
			rec = new WdbeRMPersonMProject();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stopd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWdbeMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWdbeMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefKFunction.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeRMPersonMProject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeRMPersonMProject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMPersonMProject::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMPersonMProject::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMPersonMProject::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeRMPersonMProject::loadRecBySQL(
			const string& sqlstr
			, WdbeRMPersonMProject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMPersonMProject::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMPersonMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMPersonMProject::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeRMPersonMProject::insertRec(
			WdbeRMPersonMProject* rec
		) {
	PGresult* res;
	char* ptr;

	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);
	ubigint _refWdbeMProject = htonl64(rec->refWdbeMProject);

	const char* vals[] = {
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		(char*) &_refWdbeMPerson,
		(char*) &_refWdbeMProject,
		rec->srefKFunction.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeRMPersonMProject_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMPersonMProject::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeRMPersonMProject::insertRst(
			ListWdbeRMPersonMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeRMPersonMProject::updateRec(
			WdbeRMPersonMProject* rec
		) {
	PGresult* res;

	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);
	ubigint _refWdbeMProject = htonl64(rec->refWdbeMProject);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		(char*) &_refWdbeMPerson,
		(char*) &_refWdbeMProject,
		rec->srefKFunction.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMPersonMProject_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMPersonMProject::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeRMPersonMProject::updateRst(
			ListWdbeRMPersonMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeRMPersonMProject::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeRMPersonMProject_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMPersonMProject::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeRMPersonMProject::loadRecByRef(
			ubigint ref
			, WdbeRMPersonMProject** rec
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

	return loadRecByStmt("TblWdbeRMPersonMProject_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeRMPersonMProject::loadRefsByPrj(
			ubigint refWdbeMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMProject = htonl64(refWdbeMProject);

	const char* vals[] = {
		(char*) &_refWdbeMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMPersonMProject_loadRefsByPrj", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeRMPersonMProject::loadRstByPrj(
			ubigint refWdbeMProject
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	ubigint _refWdbeMProject = htonl64(refWdbeMProject);

	const char* vals[] = {
		(char*) &_refWdbeMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMPersonMProject_loadRstByPrj", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeRMPersonMProject::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeRMPersonMProject& rst
		) {
	ubigint _refWdbeMPerson = htonl64(refWdbeMPerson);

	const char* vals[] = {
		(char*) &_refWdbeMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMPersonMProject_loadRstByPrs", 1, vals, l, f, append, rst);
};

#endif
