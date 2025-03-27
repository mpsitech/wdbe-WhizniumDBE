/**
	* \file WdbeRMCoreprojectMPerson.cpp
	* database access for table TblWdbeRMCoreprojectMPerson (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeRMCoreprojectMPerson.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeRMCoreprojectMPerson
 ******************************************************************************/

WdbeRMCoreprojectMPerson::WdbeRMCoreprojectMPerson(
			const ubigint ref
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refWdbeMCoreproject
			, const ubigint refWdbeMPerson
			, const string srefKFunction
		) :
			ref(ref)
			, x1Startd(x1Startd)
			, x1Stopd(x1Stopd)
			, refWdbeMCoreproject(refWdbeMCoreproject)
			, refWdbeMPerson(refWdbeMPerson)
			, srefKFunction(srefKFunction)
		{
};

bool WdbeRMCoreprojectMPerson::operator==(
			const WdbeRMCoreprojectMPerson& comp
		) {
	return false;
};

bool WdbeRMCoreprojectMPerson::operator!=(
			const WdbeRMCoreprojectMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeRMCoreprojectMPerson
 ******************************************************************************/

ListWdbeRMCoreprojectMPerson::ListWdbeRMCoreprojectMPerson() {
};

ListWdbeRMCoreprojectMPerson::ListWdbeRMCoreprojectMPerson(
			const ListWdbeRMCoreprojectMPerson& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeRMCoreprojectMPerson(*(src.nodes[i]));
};

ListWdbeRMCoreprojectMPerson::~ListWdbeRMCoreprojectMPerson() {
	clear();
};

void ListWdbeRMCoreprojectMPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeRMCoreprojectMPerson::size() const {
	return(nodes.size());
};

void ListWdbeRMCoreprojectMPerson::append(
			WdbeRMCoreprojectMPerson* rec
		) {
	nodes.push_back(rec);
};

WdbeRMCoreprojectMPerson* ListWdbeRMCoreprojectMPerson::operator[](
			const uint ix
		) {
	WdbeRMCoreprojectMPerson* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeRMCoreprojectMPerson& ListWdbeRMCoreprojectMPerson::operator=(
			const ListWdbeRMCoreprojectMPerson& src
		) {
	WdbeRMCoreprojectMPerson* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeRMCoreprojectMPerson(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeRMCoreprojectMPerson::operator==(
			const ListWdbeRMCoreprojectMPerson& comp
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

bool ListWdbeRMCoreprojectMPerson::operator!=(
			const ListWdbeRMCoreprojectMPerson& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeRMCoreprojectMPerson
 ******************************************************************************/

TblWdbeRMCoreprojectMPerson::TblWdbeRMCoreprojectMPerson() {
};

TblWdbeRMCoreprojectMPerson::~TblWdbeRMCoreprojectMPerson() {
};

bool TblWdbeRMCoreprojectMPerson::loadRecBySQL(
			const string& sqlstr
			, WdbeRMCoreprojectMPerson** rec
		) {
	return false;
};

ubigint TblWdbeRMCoreprojectMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	return 0;
};

ubigint TblWdbeRMCoreprojectMPerson::insertRec(
			WdbeRMCoreprojectMPerson* rec
		) {
	return 0;
};

ubigint TblWdbeRMCoreprojectMPerson::insertNewRec(
			WdbeRMCoreprojectMPerson** rec
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refWdbeMCoreproject
			, const ubigint refWdbeMPerson
			, const string srefKFunction
		) {
	ubigint retval = 0;
	WdbeRMCoreprojectMPerson* _rec = NULL;

	_rec = new WdbeRMCoreprojectMPerson(0, x1Startd, x1Stopd, refWdbeMCoreproject, refWdbeMPerson, srefKFunction);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeRMCoreprojectMPerson::appendNewRecToRst(
			ListWdbeRMCoreprojectMPerson& rst
			, WdbeRMCoreprojectMPerson** rec
			, const uint x1Startd
			, const uint x1Stopd
			, const ubigint refWdbeMCoreproject
			, const ubigint refWdbeMPerson
			, const string srefKFunction
		) {
	ubigint retval = 0;
	WdbeRMCoreprojectMPerson* _rec = NULL;

	retval = insertNewRec(&_rec, x1Startd, x1Stopd, refWdbeMCoreproject, refWdbeMPerson, srefKFunction);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeRMCoreprojectMPerson::insertRst(
			ListWdbeRMCoreprojectMPerson& rst
			, bool transact
		) {
};

void TblWdbeRMCoreprojectMPerson::updateRec(
			WdbeRMCoreprojectMPerson* rec
		) {
};

void TblWdbeRMCoreprojectMPerson::updateRst(
			ListWdbeRMCoreprojectMPerson& rst
			, bool transact
		) {
};

void TblWdbeRMCoreprojectMPerson::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeRMCoreprojectMPerson::loadRecByRef(
			ubigint ref
			, WdbeRMCoreprojectMPerson** rec
		) {
	return false;
};

ubigint TblWdbeRMCoreprojectMPerson::loadRefsByCpr(
			ubigint refWdbeMCoreproject
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeRMCoreprojectMPerson::loadRstByCpr(
			ubigint refWdbeMCoreproject
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	return 0;
};

ubigint TblWdbeRMCoreprojectMPerson::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	return 0;
};

ubigint TblWdbeRMCoreprojectMPerson::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	ubigint numload = 0;
	WdbeRMCoreprojectMPerson* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeRMCoreprojectMPerson
 ******************************************************************************/

MyTblWdbeRMCoreprojectMPerson::MyTblWdbeRMCoreprojectMPerson() :
			TblWdbeRMCoreprojectMPerson()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeRMCoreprojectMPerson::~MyTblWdbeRMCoreprojectMPerson() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeRMCoreprojectMPerson::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeRMCoreprojectMPerson (x1Startd, x1Stopd, refWdbeMCoreproject, refWdbeMPerson, srefKFunction) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeRMCoreprojectMPerson SET x1Startd = ?, x1Stopd = ?, refWdbeMCoreproject = ?, refWdbeMPerson = ?, srefKFunction = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeRMCoreprojectMPerson WHERE ref = ?", false);
};

bool MyTblWdbeRMCoreprojectMPerson::loadRecBySQL(
			const string& sqlstr
			, WdbeRMCoreprojectMPerson** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeRMCoreprojectMPerson* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMCoreprojectMPerson::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMCoreprojectMPerson::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeRMCoreprojectMPerson();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Startd = atol((char*) dbrow[1]); else _rec->x1Startd = 0;
		if (dbrow[2]) _rec->x1Stopd = atol((char*) dbrow[2]); else _rec->x1Stopd = 0;
		if (dbrow[3]) _rec->refWdbeMCoreproject = atoll((char*) dbrow[3]); else _rec->refWdbeMCoreproject = 0;
		if (dbrow[4]) _rec->refWdbeMPerson = atoll((char*) dbrow[4]); else _rec->refWdbeMPerson = 0;
		if (dbrow[5]) _rec->srefKFunction.assign(dbrow[5], dblengths[5]); else _rec->srefKFunction = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeRMCoreprojectMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeRMCoreprojectMPerson* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMCoreprojectMPerson::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMCoreprojectMPerson::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeRMCoreprojectMPerson();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Startd = atol((char*) dbrow[1]); else rec->x1Startd = 0;
			if (dbrow[2]) rec->x1Stopd = atol((char*) dbrow[2]); else rec->x1Stopd = 0;
			if (dbrow[3]) rec->refWdbeMCoreproject = atoll((char*) dbrow[3]); else rec->refWdbeMCoreproject = 0;
			if (dbrow[4]) rec->refWdbeMPerson = atoll((char*) dbrow[4]); else rec->refWdbeMPerson = 0;
			if (dbrow[5]) rec->srefKFunction.assign(dbrow[5], dblengths[5]); else rec->srefKFunction = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeRMCoreprojectMPerson::insertRec(
			WdbeRMCoreprojectMPerson* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[4] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Startd,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stopd,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeMCoreproject,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWdbeMPerson,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeRMCoreprojectMPerson::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeRMCoreprojectMPerson::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeRMCoreprojectMPerson::insertRst(
			ListWdbeRMCoreprojectMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeRMCoreprojectMPerson::updateRec(
			WdbeRMCoreprojectMPerson* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Startd,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stopd,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeMCoreproject,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWdbeMPerson,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeRMCoreprojectMPerson::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeRMCoreprojectMPerson::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeRMCoreprojectMPerson::updateRst(
			ListWdbeRMCoreprojectMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeRMCoreprojectMPerson::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeRMCoreprojectMPerson::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeRMCoreprojectMPerson::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeRMCoreprojectMPerson::loadRecByRef(
			ubigint ref
			, WdbeRMCoreprojectMPerson** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeRMCoreprojectMPerson WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeRMCoreprojectMPerson::loadRefsByCpr(
			ubigint refWdbeMCoreproject
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeRMCoreprojectMPerson WHERE refWdbeMCoreproject = " + to_string(refWdbeMCoreproject) + "", append, refs);
};

ubigint MyTblWdbeRMCoreprojectMPerson::loadRstByCpr(
			ubigint refWdbeMCoreproject
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startd, x1Stopd, refWdbeMCoreproject, refWdbeMPerson, srefKFunction FROM TblWdbeRMCoreprojectMPerson WHERE refWdbeMCoreproject = " + to_string(refWdbeMCoreproject) + "", append, rst);
};

ubigint MyTblWdbeRMCoreprojectMPerson::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	return loadRstBySQL("SELECT ref, x1Startd, x1Stopd, refWdbeMCoreproject, refWdbeMPerson, srefKFunction FROM TblWdbeRMCoreprojectMPerson WHERE refWdbeMPerson = " + to_string(refWdbeMPerson) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeRMCoreprojectMPerson
 ******************************************************************************/

PgTblWdbeRMCoreprojectMPerson::PgTblWdbeRMCoreprojectMPerson() :
			TblWdbeRMCoreprojectMPerson()
			, PgTable()
		{
};

PgTblWdbeRMCoreprojectMPerson::~PgTblWdbeRMCoreprojectMPerson() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeRMCoreprojectMPerson::initStatements() {
	createStatement("TblWdbeRMCoreprojectMPerson_insertRec", "INSERT INTO TblWdbeRMCoreprojectMPerson (x1Startd, x1Stopd, refWdbeMCoreproject, refWdbeMPerson, srefKFunction) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWdbeRMCoreprojectMPerson_updateRec", "UPDATE TblWdbeRMCoreprojectMPerson SET x1Startd = $1, x1Stopd = $2, refWdbeMCoreproject = $3, refWdbeMPerson = $4, srefKFunction = $5 WHERE ref = $6", 6);
	createStatement("TblWdbeRMCoreprojectMPerson_removeRecByRef", "DELETE FROM TblWdbeRMCoreprojectMPerson WHERE ref = $1", 1);

	createStatement("TblWdbeRMCoreprojectMPerson_loadRecByRef", "SELECT ref, x1Startd, x1Stopd, refWdbeMCoreproject, refWdbeMPerson, srefKFunction FROM TblWdbeRMCoreprojectMPerson WHERE ref = $1", 1);
	createStatement("TblWdbeRMCoreprojectMPerson_loadRefsByCpr", "SELECT ref FROM TblWdbeRMCoreprojectMPerson WHERE refWdbeMCoreproject = $1", 1);
	createStatement("TblWdbeRMCoreprojectMPerson_loadRstByCpr", "SELECT ref, x1Startd, x1Stopd, refWdbeMCoreproject, refWdbeMPerson, srefKFunction FROM TblWdbeRMCoreprojectMPerson WHERE refWdbeMCoreproject = $1", 1);
	createStatement("TblWdbeRMCoreprojectMPerson_loadRstByPrs", "SELECT ref, x1Startd, x1Stopd, refWdbeMCoreproject, refWdbeMPerson, srefKFunction FROM TblWdbeRMCoreprojectMPerson WHERE refWdbeMPerson = $1", 1);
};

bool PgTblWdbeRMCoreprojectMPerson::loadRec(
			PGresult* res
			, WdbeRMCoreprojectMPerson** rec
		) {
	char* ptr;

	WdbeRMCoreprojectMPerson* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeRMCoreprojectMPerson();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "refwdbemcoreproject"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "srefkfunction")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stopd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWdbeMCoreproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWdbeMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefKFunction.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeRMCoreprojectMPerson::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeRMCoreprojectMPerson* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "refwdbemcoreproject"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "srefkfunction")
		};

		while (numread < numrow) {
			rec = new WdbeRMCoreprojectMPerson();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stopd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWdbeMCoreproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWdbeMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefKFunction.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeRMCoreprojectMPerson::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeRMCoreprojectMPerson** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCoreprojectMPerson::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMCoreprojectMPerson::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCoreprojectMPerson::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeRMCoreprojectMPerson::loadRecBySQL(
			const string& sqlstr
			, WdbeRMCoreprojectMPerson** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCoreprojectMPerson::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMCoreprojectMPerson::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCoreprojectMPerson::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeRMCoreprojectMPerson::insertRec(
			WdbeRMCoreprojectMPerson* rec
		) {
	PGresult* res;
	char* ptr;

	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	ubigint _refWdbeMCoreproject = htonl64(rec->refWdbeMCoreproject);
	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);

	const char* vals[] = {
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		(char*) &_refWdbeMCoreproject,
		(char*) &_refWdbeMPerson,
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

	res = PQexecPrepared(dbs, "TblWdbeRMCoreprojectMPerson_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCoreprojectMPerson::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeRMCoreprojectMPerson::insertRst(
			ListWdbeRMCoreprojectMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeRMCoreprojectMPerson::updateRec(
			WdbeRMCoreprojectMPerson* rec
		) {
	PGresult* res;

	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	ubigint _refWdbeMCoreproject = htonl64(rec->refWdbeMCoreproject);
	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		(char*) &_refWdbeMCoreproject,
		(char*) &_refWdbeMPerson,
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

	res = PQexecPrepared(dbs, "TblWdbeRMCoreprojectMPerson_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMCoreprojectMPerson::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeRMCoreprojectMPerson::updateRst(
			ListWdbeRMCoreprojectMPerson& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeRMCoreprojectMPerson::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeRMCoreprojectMPerson_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMCoreprojectMPerson::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeRMCoreprojectMPerson::loadRecByRef(
			ubigint ref
			, WdbeRMCoreprojectMPerson** rec
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

	return loadRecByStmt("TblWdbeRMCoreprojectMPerson_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeRMCoreprojectMPerson::loadRefsByCpr(
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

	return loadRefsByStmt("TblWdbeRMCoreprojectMPerson_loadRefsByCpr", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeRMCoreprojectMPerson::loadRstByCpr(
			ubigint refWdbeMCoreproject
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	ubigint _refWdbeMCoreproject = htonl64(refWdbeMCoreproject);

	const char* vals[] = {
		(char*) &_refWdbeMCoreproject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMCoreprojectMPerson_loadRstByCpr", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeRMCoreprojectMPerson::loadRstByPrs(
			ubigint refWdbeMPerson
			, const bool append
			, ListWdbeRMCoreprojectMPerson& rst
		) {
	ubigint _refWdbeMPerson = htonl64(refWdbeMPerson);

	const char* vals[] = {
		(char*) &_refWdbeMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMCoreprojectMPerson_loadRstByPrs", 1, vals, l, f, append, rst);
};

#endif
