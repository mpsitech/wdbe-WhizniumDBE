/**
	* \file WdbeMProcess.cpp
	* database access for table TblWdbeMProcess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMProcess.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMProcess
 ******************************************************************************/

WdbeMProcess::WdbeMProcess(
			const ubigint ref
			, const ubigint refWdbeMModule
			, const ubigint refWdbeMFsm
			, const string sref
			, const string clkSrefWdbeMSignal
			, const string asrSrefWdbeMSignal
			, const bool Falling
			, const string Syncrst
			, const bool Extip
			, const string Comment
		) {

	this->ref = ref;
	this->refWdbeMModule = refWdbeMModule;
	this->refWdbeMFsm = refWdbeMFsm;
	this->sref = sref;
	this->clkSrefWdbeMSignal = clkSrefWdbeMSignal;
	this->asrSrefWdbeMSignal = asrSrefWdbeMSignal;
	this->Falling = Falling;
	this->Syncrst = Syncrst;
	this->Extip = Extip;
	this->Comment = Comment;
};

bool WdbeMProcess::operator==(
			const WdbeMProcess& comp
		) {
	return false;
};

bool WdbeMProcess::operator!=(
			const WdbeMProcess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMProcess
 ******************************************************************************/

ListWdbeMProcess::ListWdbeMProcess() {
};

ListWdbeMProcess::ListWdbeMProcess(
			const ListWdbeMProcess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMProcess(*(src.nodes[i]));
};

ListWdbeMProcess::~ListWdbeMProcess() {
	clear();
};

void ListWdbeMProcess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMProcess::size() const {
	return(nodes.size());
};

void ListWdbeMProcess::append(
			WdbeMProcess* rec
		) {
	nodes.push_back(rec);
};

WdbeMProcess* ListWdbeMProcess::operator[](
			const uint ix
		) {
	WdbeMProcess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMProcess& ListWdbeMProcess::operator=(
			const ListWdbeMProcess& src
		) {
	WdbeMProcess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMProcess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMProcess::operator==(
			const ListWdbeMProcess& comp
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

bool ListWdbeMProcess::operator!=(
			const ListWdbeMProcess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMProcess
 ******************************************************************************/

TblWdbeMProcess::TblWdbeMProcess() {
};

TblWdbeMProcess::~TblWdbeMProcess() {
};

bool TblWdbeMProcess::loadRecBySQL(
			const string& sqlstr
			, WdbeMProcess** rec
		) {
	return false;
};

ubigint TblWdbeMProcess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMProcess& rst
		) {
	return 0;
};

ubigint TblWdbeMProcess::insertRec(
			WdbeMProcess* rec
		) {
	return 0;
};

ubigint TblWdbeMProcess::insertNewRec(
			WdbeMProcess** rec
			, const ubigint refWdbeMModule
			, const ubigint refWdbeMFsm
			, const string sref
			, const string clkSrefWdbeMSignal
			, const string asrSrefWdbeMSignal
			, const bool Falling
			, const string Syncrst
			, const bool Extip
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMProcess* _rec = NULL;

	_rec = new WdbeMProcess(0, refWdbeMModule, refWdbeMFsm, sref, clkSrefWdbeMSignal, asrSrefWdbeMSignal, Falling, Syncrst, Extip, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMProcess::appendNewRecToRst(
			ListWdbeMProcess& rst
			, WdbeMProcess** rec
			, const ubigint refWdbeMModule
			, const ubigint refWdbeMFsm
			, const string sref
			, const string clkSrefWdbeMSignal
			, const string asrSrefWdbeMSignal
			, const bool Falling
			, const string Syncrst
			, const bool Extip
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMProcess* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMModule, refWdbeMFsm, sref, clkSrefWdbeMSignal, asrSrefWdbeMSignal, Falling, Syncrst, Extip, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMProcess::insertRst(
			ListWdbeMProcess& rst
			, bool transact
		) {
};

void TblWdbeMProcess::updateRec(
			WdbeMProcess* rec
		) {
};

void TblWdbeMProcess::updateRst(
			ListWdbeMProcess& rst
			, bool transact
		) {
};

void TblWdbeMProcess::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMProcess::loadRecByRef(
			ubigint ref
			, WdbeMProcess** rec
		) {
	return false;
};

bool TblWdbeMProcess::loadRecByFsm(
			ubigint refWdbeMFsm
			, WdbeMProcess** rec
		) {
	return false;
};

ubigint TblWdbeMProcess::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMProcess::loadRstByMdl(
			ubigint refWdbeMModule
			, const bool append
			, ListWdbeMProcess& rst
		) {
	return 0;
};

bool TblWdbeMProcess::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMProcess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMProcess& rst
		) {
	ubigint numload = 0;
	WdbeMProcess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMProcess
 ******************************************************************************/

MyTblWdbeMProcess::MyTblWdbeMProcess() :
			TblWdbeMProcess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMProcess::~MyTblWdbeMProcess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMProcess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMProcess (refWdbeMModule, refWdbeMFsm, sref, clkSrefWdbeMSignal, asrSrefWdbeMSignal, Falling, Syncrst, Extip, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMProcess SET refWdbeMModule = ?, refWdbeMFsm = ?, sref = ?, clkSrefWdbeMSignal = ?, asrSrefWdbeMSignal = ?, Falling = ?, Syncrst = ?, Extip = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMProcess WHERE ref = ?", false);
};

bool MyTblWdbeMProcess::loadRecBySQL(
			const string& sqlstr
			, WdbeMProcess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMProcess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMProcess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMProcess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMProcess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMModule = atoll((char*) dbrow[1]); else _rec->refWdbeMModule = 0;
		if (dbrow[2]) _rec->refWdbeMFsm = atoll((char*) dbrow[2]); else _rec->refWdbeMFsm = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->clkSrefWdbeMSignal.assign(dbrow[4], dblengths[4]); else _rec->clkSrefWdbeMSignal = "";
		if (dbrow[5]) _rec->asrSrefWdbeMSignal.assign(dbrow[5], dblengths[5]); else _rec->asrSrefWdbeMSignal = "";
		if (dbrow[6]) _rec->Falling = (atoi((char*) dbrow[6]) != 0); else _rec->Falling = false;
		if (dbrow[7]) _rec->Syncrst.assign(dbrow[7], dblengths[7]); else _rec->Syncrst = "";
		if (dbrow[8]) _rec->Extip = (atoi((char*) dbrow[8]) != 0); else _rec->Extip = false;
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMProcess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMProcess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMProcess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMProcess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMProcess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMProcess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMModule = atoll((char*) dbrow[1]); else rec->refWdbeMModule = 0;
			if (dbrow[2]) rec->refWdbeMFsm = atoll((char*) dbrow[2]); else rec->refWdbeMFsm = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->clkSrefWdbeMSignal.assign(dbrow[4], dblengths[4]); else rec->clkSrefWdbeMSignal = "";
			if (dbrow[5]) rec->asrSrefWdbeMSignal.assign(dbrow[5], dblengths[5]); else rec->asrSrefWdbeMSignal = "";
			if (dbrow[6]) rec->Falling = (atoi((char*) dbrow[6]) != 0); else rec->Falling = false;
			if (dbrow[7]) rec->Syncrst.assign(dbrow[7], dblengths[7]); else rec->Syncrst = "";
			if (dbrow[8]) rec->Extip = (atoi((char*) dbrow[8]) != 0); else rec->Extip = false;
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMProcess::insertRec(
			WdbeMProcess* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[2] = rec->sref.length();
	l[3] = rec->clkSrefWdbeMSignal.length();
	l[4] = rec->asrSrefWdbeMSignal.length();
	tinyint Falling = rec->Falling;
	l[6] = rec->Syncrst.length();
	tinyint Extip = rec->Extip;
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMFsm,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->clkSrefWdbeMSignal.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->asrSrefWdbeMSignal.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Falling,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Syncrst.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Extip,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMProcess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMProcess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMProcess::insertRst(
			ListWdbeMProcess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMProcess::updateRec(
			WdbeMProcess* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[2] = rec->sref.length();
	l[3] = rec->clkSrefWdbeMSignal.length();
	l[4] = rec->asrSrefWdbeMSignal.length();
	tinyint Falling = rec->Falling;
	l[6] = rec->Syncrst.length();
	tinyint Extip = rec->Extip;
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMFsm,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->clkSrefWdbeMSignal.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->asrSrefWdbeMSignal.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Falling,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Syncrst.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Extip,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->ref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMProcess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMProcess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMProcess::updateRst(
			ListWdbeMProcess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMProcess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMProcess::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMProcess::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMProcess::loadRecByRef(
			ubigint ref
			, WdbeMProcess** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMProcess WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMProcess::loadRecByFsm(
			ubigint refWdbeMFsm
			, WdbeMProcess** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMModule, refWdbeMFsm, sref, clkSrefWdbeMSignal, asrSrefWdbeMSignal, Falling, Syncrst, Extip, Comment FROM TblWdbeMProcess WHERE refWdbeMFsm = " + to_string(refWdbeMFsm) + "", rec);
};

ubigint MyTblWdbeMProcess::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(refWdbeMModule) + "", append, refs);
};

ubigint MyTblWdbeMProcess::loadRstByMdl(
			ubigint refWdbeMModule
			, const bool append
			, ListWdbeMProcess& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMModule, refWdbeMFsm, sref, clkSrefWdbeMSignal, asrSrefWdbeMSignal, Falling, Syncrst, Extip, Comment FROM TblWdbeMProcess WHERE refWdbeMModule = " + to_string(refWdbeMModule) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMProcess::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMProcess WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMProcess
 ******************************************************************************/

PgTblWdbeMProcess::PgTblWdbeMProcess() :
			TblWdbeMProcess()
			, PgTable()
		{
};

PgTblWdbeMProcess::~PgTblWdbeMProcess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMProcess::initStatements() {
	createStatement("TblWdbeMProcess_insertRec", "INSERT INTO TblWdbeMProcess (refWdbeMModule, refWdbeMFsm, sref, clkSrefWdbeMSignal, asrSrefWdbeMSignal, Falling, Syncrst, Extip, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING ref", 9);
	createStatement("TblWdbeMProcess_updateRec", "UPDATE TblWdbeMProcess SET refWdbeMModule = $1, refWdbeMFsm = $2, sref = $3, clkSrefWdbeMSignal = $4, asrSrefWdbeMSignal = $5, Falling = $6, Syncrst = $7, Extip = $8, Comment = $9 WHERE ref = $10", 10);
	createStatement("TblWdbeMProcess_removeRecByRef", "DELETE FROM TblWdbeMProcess WHERE ref = $1", 1);

	createStatement("TblWdbeMProcess_loadRecByRef", "SELECT ref, refWdbeMModule, refWdbeMFsm, sref, clkSrefWdbeMSignal, asrSrefWdbeMSignal, Falling, Syncrst, Extip, Comment FROM TblWdbeMProcess WHERE ref = $1", 1);
	createStatement("TblWdbeMProcess_loadRecByFsm", "SELECT ref, refWdbeMModule, refWdbeMFsm, sref, clkSrefWdbeMSignal, asrSrefWdbeMSignal, Falling, Syncrst, Extip, Comment FROM TblWdbeMProcess WHERE refWdbeMFsm = $1", 1);
	createStatement("TblWdbeMProcess_loadRefsByMdl", "SELECT ref FROM TblWdbeMProcess WHERE refWdbeMModule = $1", 1);
	createStatement("TblWdbeMProcess_loadRstByMdl", "SELECT ref, refWdbeMModule, refWdbeMFsm, sref, clkSrefWdbeMSignal, asrSrefWdbeMSignal, Falling, Syncrst, Extip, Comment FROM TblWdbeMProcess WHERE refWdbeMModule = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMProcess_loadSrfByRef", "SELECT sref FROM TblWdbeMProcess WHERE ref = $1", 1);
};

bool PgTblWdbeMProcess::loadRec(
			PGresult* res
			, WdbeMProcess** rec
		) {
	char* ptr;

	WdbeMProcess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMProcess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "refwdbemfsm"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "clksrefwdbemsignal"),
			PQfnumber(res, "asrsrefwdbemsignal"),
			PQfnumber(res, "falling"),
			PQfnumber(res, "syncrst"),
			PQfnumber(res, "extip"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMFsm = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->clkSrefWdbeMSignal.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->asrSrefWdbeMSignal.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Falling = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Syncrst.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Extip = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMProcess::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMProcess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMProcess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "refwdbemfsm"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "clksrefwdbemsignal"),
			PQfnumber(res, "asrsrefwdbemsignal"),
			PQfnumber(res, "falling"),
			PQfnumber(res, "syncrst"),
			PQfnumber(res, "extip"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMProcess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMFsm = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->clkSrefWdbeMSignal.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->asrSrefWdbeMSignal.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Falling = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Syncrst.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Extip = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMProcess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMProcess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMProcess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMProcess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMProcess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMProcess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMProcess::loadRecBySQL(
			const string& sqlstr
			, WdbeMProcess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMProcess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMProcess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMProcess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMProcess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMProcess::insertRec(
			WdbeMProcess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	ubigint _refWdbeMFsm = htonl64(rec->refWdbeMFsm);
	smallint _Falling = htons((smallint) rec->Falling);
	smallint _Extip = htons((smallint) rec->Extip);

	const char* vals[] = {
		(char*) &_refWdbeMModule,
		(char*) &_refWdbeMFsm,
		rec->sref.c_str(),
		rec->clkSrefWdbeMSignal.c_str(),
		rec->asrSrefWdbeMSignal.c_str(),
		(char*) &_Falling,
		rec->Syncrst.c_str(),
		(char*) &_Extip,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(smallint),
		0,
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 0, 0, 0, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeMProcess_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMProcess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMProcess::insertRst(
			ListWdbeMProcess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMProcess::updateRec(
			WdbeMProcess* rec
		) {
	PGresult* res;

	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	ubigint _refWdbeMFsm = htonl64(rec->refWdbeMFsm);
	smallint _Falling = htons((smallint) rec->Falling);
	smallint _Extip = htons((smallint) rec->Extip);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMModule,
		(char*) &_refWdbeMFsm,
		rec->sref.c_str(),
		rec->clkSrefWdbeMSignal.c_str(),
		rec->asrSrefWdbeMSignal.c_str(),
		(char*) &_Falling,
		rec->Syncrst.c_str(),
		(char*) &_Extip,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(smallint),
		0,
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 0, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMProcess_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMProcess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMProcess::updateRst(
			ListWdbeMProcess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMProcess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMProcess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMProcess::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMProcess::loadRecByRef(
			ubigint ref
			, WdbeMProcess** rec
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

	return loadRecByStmt("TblWdbeMProcess_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMProcess::loadRecByFsm(
			ubigint refWdbeMFsm
			, WdbeMProcess** rec
		) {
	ubigint _refWdbeMFsm = htonl64(refWdbeMFsm);

	const char* vals[] = {
		(char*) &_refWdbeMFsm
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMProcess_loadRecByFsm", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMProcess::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMModule = htonl64(refWdbeMModule);

	const char* vals[] = {
		(char*) &_refWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMProcess_loadRefsByMdl", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMProcess::loadRstByMdl(
			ubigint refWdbeMModule
			, const bool append
			, ListWdbeMProcess& rst
		) {
	ubigint _refWdbeMModule = htonl64(refWdbeMModule);

	const char* vals[] = {
		(char*) &_refWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMProcess_loadRstByMdl", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMProcess::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMProcess_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
