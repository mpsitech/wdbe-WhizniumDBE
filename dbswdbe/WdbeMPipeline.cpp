/**
	* \file WdbeMPipeline.cpp
	* database access for table TblWdbeMPipeline (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeMPipeline.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMPipeline
 ******************************************************************************/

WdbeMPipeline::WdbeMPipeline(
			const ubigint ref
			, const ubigint hsmRefWdbeMModule
			, const string sref
			, const string clkSrefWdbeMSignal
			, const string clgSrefWdbeMSignal
			, const string asrSrefWdbeMSignal
			, const usmallint Depth
			, const string Comment
		) :
			ref(ref)
			, hsmRefWdbeMModule(hsmRefWdbeMModule)
			, sref(sref)
			, clkSrefWdbeMSignal(clkSrefWdbeMSignal)
			, clgSrefWdbeMSignal(clgSrefWdbeMSignal)
			, asrSrefWdbeMSignal(asrSrefWdbeMSignal)
			, Depth(Depth)
			, Comment(Comment)
		{
};

bool WdbeMPipeline::operator==(
			const WdbeMPipeline& comp
		) {
	return false;
};

bool WdbeMPipeline::operator!=(
			const WdbeMPipeline& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMPipeline
 ******************************************************************************/

ListWdbeMPipeline::ListWdbeMPipeline() {
};

ListWdbeMPipeline::ListWdbeMPipeline(
			const ListWdbeMPipeline& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMPipeline(*(src.nodes[i]));
};

ListWdbeMPipeline::~ListWdbeMPipeline() {
	clear();
};

void ListWdbeMPipeline::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMPipeline::size() const {
	return(nodes.size());
};

void ListWdbeMPipeline::append(
			WdbeMPipeline* rec
		) {
	nodes.push_back(rec);
};

WdbeMPipeline* ListWdbeMPipeline::operator[](
			const uint ix
		) {
	WdbeMPipeline* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMPipeline& ListWdbeMPipeline::operator=(
			const ListWdbeMPipeline& src
		) {
	WdbeMPipeline* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMPipeline(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMPipeline::operator==(
			const ListWdbeMPipeline& comp
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

bool ListWdbeMPipeline::operator!=(
			const ListWdbeMPipeline& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMPipeline
 ******************************************************************************/

TblWdbeMPipeline::TblWdbeMPipeline() {
};

TblWdbeMPipeline::~TblWdbeMPipeline() {
};

bool TblWdbeMPipeline::loadRecBySQL(
			const string& sqlstr
			, WdbeMPipeline** rec
		) {
	return false;
};

ubigint TblWdbeMPipeline::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPipeline& rst
		) {
	return 0;
};

ubigint TblWdbeMPipeline::insertRec(
			WdbeMPipeline* rec
		) {
	return 0;
};

ubigint TblWdbeMPipeline::insertNewRec(
			WdbeMPipeline** rec
			, const ubigint hsmRefWdbeMModule
			, const string sref
			, const string clkSrefWdbeMSignal
			, const string clgSrefWdbeMSignal
			, const string asrSrefWdbeMSignal
			, const usmallint Depth
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMPipeline* _rec = NULL;

	_rec = new WdbeMPipeline(0, hsmRefWdbeMModule, sref, clkSrefWdbeMSignal, clgSrefWdbeMSignal, asrSrefWdbeMSignal, Depth, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMPipeline::appendNewRecToRst(
			ListWdbeMPipeline& rst
			, WdbeMPipeline** rec
			, const ubigint hsmRefWdbeMModule
			, const string sref
			, const string clkSrefWdbeMSignal
			, const string clgSrefWdbeMSignal
			, const string asrSrefWdbeMSignal
			, const usmallint Depth
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMPipeline* _rec = NULL;

	retval = insertNewRec(&_rec, hsmRefWdbeMModule, sref, clkSrefWdbeMSignal, clgSrefWdbeMSignal, asrSrefWdbeMSignal, Depth, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMPipeline::insertRst(
			ListWdbeMPipeline& rst
			, bool transact
		) {
};

void TblWdbeMPipeline::updateRec(
			WdbeMPipeline* rec
		) {
};

void TblWdbeMPipeline::updateRst(
			ListWdbeMPipeline& rst
			, bool transact
		) {
};

void TblWdbeMPipeline::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMPipeline::loadRecByRef(
			ubigint ref
			, WdbeMPipeline** rec
		) {
	return false;
};

ubigint TblWdbeMPipeline::loadRefsByHsm(
			ubigint hsmRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMPipeline::loadRstByHsm(
			ubigint hsmRefWdbeMModule
			, const bool append
			, ListWdbeMPipeline& rst
		) {
	return 0;
};

bool TblWdbeMPipeline::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMPipeline::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMPipeline& rst
		) {
	ubigint numload = 0;
	WdbeMPipeline* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMPipeline
 ******************************************************************************/

MyTblWdbeMPipeline::MyTblWdbeMPipeline() :
			TblWdbeMPipeline()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMPipeline::~MyTblWdbeMPipeline() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMPipeline::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMPipeline (hsmRefWdbeMModule, sref, clkSrefWdbeMSignal, clgSrefWdbeMSignal, asrSrefWdbeMSignal, Depth, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMPipeline SET hsmRefWdbeMModule = ?, sref = ?, clkSrefWdbeMSignal = ?, clgSrefWdbeMSignal = ?, asrSrefWdbeMSignal = ?, Depth = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMPipeline WHERE ref = ?", false);
};

bool MyTblWdbeMPipeline::loadRecBySQL(
			const string& sqlstr
			, WdbeMPipeline** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMPipeline* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMPipeline::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMPipeline::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMPipeline();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->hsmRefWdbeMModule = atoll((char*) dbrow[1]); else _rec->hsmRefWdbeMModule = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->clkSrefWdbeMSignal.assign(dbrow[3], dblengths[3]); else _rec->clkSrefWdbeMSignal = "";
		if (dbrow[4]) _rec->clgSrefWdbeMSignal.assign(dbrow[4], dblengths[4]); else _rec->clgSrefWdbeMSignal = "";
		if (dbrow[5]) _rec->asrSrefWdbeMSignal.assign(dbrow[5], dblengths[5]); else _rec->asrSrefWdbeMSignal = "";
		if (dbrow[6]) _rec->Depth = atoi((char*) dbrow[6]); else _rec->Depth = 0;
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMPipeline::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPipeline& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMPipeline* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMPipeline::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMPipeline::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMPipeline();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->hsmRefWdbeMModule = atoll((char*) dbrow[1]); else rec->hsmRefWdbeMModule = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->clkSrefWdbeMSignal.assign(dbrow[3], dblengths[3]); else rec->clkSrefWdbeMSignal = "";
			if (dbrow[4]) rec->clgSrefWdbeMSignal.assign(dbrow[4], dblengths[4]); else rec->clgSrefWdbeMSignal = "";
			if (dbrow[5]) rec->asrSrefWdbeMSignal.assign(dbrow[5], dblengths[5]); else rec->asrSrefWdbeMSignal = "";
			if (dbrow[6]) rec->Depth = atoi((char*) dbrow[6]); else rec->Depth = 0;
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMPipeline::insertRec(
			WdbeMPipeline* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[1] = rec->sref.length();
	l[2] = rec->clkSrefWdbeMSignal.length();
	l[3] = rec->clgSrefWdbeMSignal.length();
	l[4] = rec->asrSrefWdbeMSignal.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->hsmRefWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->clkSrefWdbeMSignal.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->clgSrefWdbeMSignal.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->asrSrefWdbeMSignal.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Depth,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMPipeline::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMPipeline::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMPipeline::insertRst(
			ListWdbeMPipeline& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMPipeline::updateRec(
			WdbeMPipeline* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[1] = rec->sref.length();
	l[2] = rec->clkSrefWdbeMSignal.length();
	l[3] = rec->clgSrefWdbeMSignal.length();
	l[4] = rec->asrSrefWdbeMSignal.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->hsmRefWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->clkSrefWdbeMSignal.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->clgSrefWdbeMSignal.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->asrSrefWdbeMSignal.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Depth,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMPipeline::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMPipeline::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMPipeline::updateRst(
			ListWdbeMPipeline& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMPipeline::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMPipeline::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMPipeline::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMPipeline::loadRecByRef(
			ubigint ref
			, WdbeMPipeline** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMPipeline WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMPipeline::loadRefsByHsm(
			ubigint hsmRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMPipeline WHERE hsmRefWdbeMModule = " + to_string(hsmRefWdbeMModule) + "", append, refs);
};

ubigint MyTblWdbeMPipeline::loadRstByHsm(
			ubigint hsmRefWdbeMModule
			, const bool append
			, ListWdbeMPipeline& rst
		) {
	return loadRstBySQL("SELECT ref, hsmRefWdbeMModule, sref, clkSrefWdbeMSignal, clgSrefWdbeMSignal, asrSrefWdbeMSignal, Depth, Comment FROM TblWdbeMPipeline WHERE hsmRefWdbeMModule = " + to_string(hsmRefWdbeMModule) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMPipeline::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMPipeline WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMPipeline
 ******************************************************************************/

PgTblWdbeMPipeline::PgTblWdbeMPipeline() :
			TblWdbeMPipeline()
			, PgTable()
		{
};

PgTblWdbeMPipeline::~PgTblWdbeMPipeline() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMPipeline::initStatements() {
	createStatement("TblWdbeMPipeline_insertRec", "INSERT INTO TblWdbeMPipeline (hsmRefWdbeMModule, sref, clkSrefWdbeMSignal, clgSrefWdbeMSignal, asrSrefWdbeMSignal, Depth, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWdbeMPipeline_updateRec", "UPDATE TblWdbeMPipeline SET hsmRefWdbeMModule = $1, sref = $2, clkSrefWdbeMSignal = $3, clgSrefWdbeMSignal = $4, asrSrefWdbeMSignal = $5, Depth = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWdbeMPipeline_removeRecByRef", "DELETE FROM TblWdbeMPipeline WHERE ref = $1", 1);

	createStatement("TblWdbeMPipeline_loadRecByRef", "SELECT ref, hsmRefWdbeMModule, sref, clkSrefWdbeMSignal, clgSrefWdbeMSignal, asrSrefWdbeMSignal, Depth, Comment FROM TblWdbeMPipeline WHERE ref = $1", 1);
	createStatement("TblWdbeMPipeline_loadRefsByHsm", "SELECT ref FROM TblWdbeMPipeline WHERE hsmRefWdbeMModule = $1", 1);
	createStatement("TblWdbeMPipeline_loadRstByHsm", "SELECT ref, hsmRefWdbeMModule, sref, clkSrefWdbeMSignal, clgSrefWdbeMSignal, asrSrefWdbeMSignal, Depth, Comment FROM TblWdbeMPipeline WHERE hsmRefWdbeMModule = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMPipeline_loadSrfByRef", "SELECT sref FROM TblWdbeMPipeline WHERE ref = $1", 1);
};

bool PgTblWdbeMPipeline::loadRec(
			PGresult* res
			, WdbeMPipeline** rec
		) {
	char* ptr;

	WdbeMPipeline* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMPipeline();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "hsmrefwdbemmodule"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "clksrefwdbemsignal"),
			PQfnumber(res, "clgsrefwdbemsignal"),
			PQfnumber(res, "asrsrefwdbemsignal"),
			PQfnumber(res, "depth"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->hsmRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->clkSrefWdbeMSignal.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->clgSrefWdbeMSignal.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->asrSrefWdbeMSignal.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Depth = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMPipeline::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMPipeline& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMPipeline* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "hsmrefwdbemmodule"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "clksrefwdbemsignal"),
			PQfnumber(res, "clgsrefwdbemsignal"),
			PQfnumber(res, "asrsrefwdbemsignal"),
			PQfnumber(res, "depth"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMPipeline();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->hsmRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->clkSrefWdbeMSignal.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->clgSrefWdbeMSignal.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->asrSrefWdbeMSignal.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Depth = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMPipeline::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMPipeline** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPipeline::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMPipeline::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMPipeline& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPipeline::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMPipeline::loadRecBySQL(
			const string& sqlstr
			, WdbeMPipeline** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPipeline::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMPipeline::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPipeline& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPipeline::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMPipeline::insertRec(
			WdbeMPipeline* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _hsmRefWdbeMModule = htonl64(rec->hsmRefWdbeMModule);
	usmallint _Depth = htons(rec->Depth);

	const char* vals[] = {
		(char*) &_hsmRefWdbeMModule,
		rec->sref.c_str(),
		rec->clkSrefWdbeMSignal.c_str(),
		rec->clgSrefWdbeMSignal.c_str(),
		rec->asrSrefWdbeMSignal.c_str(),
		(char*) &_Depth,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 0, 0, 0, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeMPipeline_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPipeline::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMPipeline::insertRst(
			ListWdbeMPipeline& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMPipeline::updateRec(
			WdbeMPipeline* rec
		) {
	PGresult* res;

	ubigint _hsmRefWdbeMModule = htonl64(rec->hsmRefWdbeMModule);
	usmallint _Depth = htons(rec->Depth);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_hsmRefWdbeMModule,
		rec->sref.c_str(),
		rec->clkSrefWdbeMSignal.c_str(),
		rec->clgSrefWdbeMSignal.c_str(),
		rec->asrSrefWdbeMSignal.c_str(),
		(char*) &_Depth,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 0, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMPipeline_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMPipeline::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMPipeline::updateRst(
			ListWdbeMPipeline& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMPipeline::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMPipeline_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMPipeline::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMPipeline::loadRecByRef(
			ubigint ref
			, WdbeMPipeline** rec
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

	return loadRecByStmt("TblWdbeMPipeline_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMPipeline::loadRefsByHsm(
			ubigint hsmRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _hsmRefWdbeMModule = htonl64(hsmRefWdbeMModule);

	const char* vals[] = {
		(char*) &_hsmRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMPipeline_loadRefsByHsm", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMPipeline::loadRstByHsm(
			ubigint hsmRefWdbeMModule
			, const bool append
			, ListWdbeMPipeline& rst
		) {
	ubigint _hsmRefWdbeMModule = htonl64(hsmRefWdbeMModule);

	const char* vals[] = {
		(char*) &_hsmRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMPipeline_loadRstByHsm", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMPipeline::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMPipeline_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
