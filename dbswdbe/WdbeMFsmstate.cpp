/**
	* \file WdbeMFsmstate.cpp
	* database access for table TblWdbeMFsmstate (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMFsmstate.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMFsmstate
 ******************************************************************************/

WdbeMFsmstate::WdbeMFsmstate(
			const ubigint ref
			, const ubigint refWdbeCFsmstate
			, const ubigint fsmRefWdbeMFsm
			, const uint fsmNum
			, const string sref
			, const bool Extip
			, const string Comment
		) :
			ref(ref)
			, refWdbeCFsmstate(refWdbeCFsmstate)
			, fsmRefWdbeMFsm(fsmRefWdbeMFsm)
			, fsmNum(fsmNum)
			, sref(sref)
			, Extip(Extip)
			, Comment(Comment)
		{
};

bool WdbeMFsmstate::operator==(
			const WdbeMFsmstate& comp
		) {
	return false;
};

bool WdbeMFsmstate::operator!=(
			const WdbeMFsmstate& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMFsmstate
 ******************************************************************************/

ListWdbeMFsmstate::ListWdbeMFsmstate() {
};

ListWdbeMFsmstate::ListWdbeMFsmstate(
			const ListWdbeMFsmstate& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMFsmstate(*(src.nodes[i]));
};

ListWdbeMFsmstate::~ListWdbeMFsmstate() {
	clear();
};

void ListWdbeMFsmstate::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMFsmstate::size() const {
	return(nodes.size());
};

void ListWdbeMFsmstate::append(
			WdbeMFsmstate* rec
		) {
	nodes.push_back(rec);
};

WdbeMFsmstate* ListWdbeMFsmstate::operator[](
			const uint ix
		) {
	WdbeMFsmstate* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMFsmstate& ListWdbeMFsmstate::operator=(
			const ListWdbeMFsmstate& src
		) {
	WdbeMFsmstate* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMFsmstate(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMFsmstate::operator==(
			const ListWdbeMFsmstate& comp
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

bool ListWdbeMFsmstate::operator!=(
			const ListWdbeMFsmstate& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMFsmstate
 ******************************************************************************/

TblWdbeMFsmstate::TblWdbeMFsmstate() {
};

TblWdbeMFsmstate::~TblWdbeMFsmstate() {
};

bool TblWdbeMFsmstate::loadRecBySQL(
			const string& sqlstr
			, WdbeMFsmstate** rec
		) {
	return false;
};

ubigint TblWdbeMFsmstate::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	return 0;
};

ubigint TblWdbeMFsmstate::insertRec(
			WdbeMFsmstate* rec
		) {
	return 0;
};

ubigint TblWdbeMFsmstate::insertNewRec(
			WdbeMFsmstate** rec
			, const ubigint refWdbeCFsmstate
			, const ubigint fsmRefWdbeMFsm
			, const uint fsmNum
			, const string sref
			, const bool Extip
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMFsmstate* _rec = NULL;

	_rec = new WdbeMFsmstate(0, refWdbeCFsmstate, fsmRefWdbeMFsm, fsmNum, sref, Extip, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMFsmstate::appendNewRecToRst(
			ListWdbeMFsmstate& rst
			, WdbeMFsmstate** rec
			, const ubigint refWdbeCFsmstate
			, const ubigint fsmRefWdbeMFsm
			, const uint fsmNum
			, const string sref
			, const bool Extip
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMFsmstate* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeCFsmstate, fsmRefWdbeMFsm, fsmNum, sref, Extip, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMFsmstate::insertRst(
			ListWdbeMFsmstate& rst
			, bool transact
		) {
};

void TblWdbeMFsmstate::updateRec(
			WdbeMFsmstate* rec
		) {
};

void TblWdbeMFsmstate::updateRst(
			ListWdbeMFsmstate& rst
			, bool transact
		) {
};

void TblWdbeMFsmstate::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMFsmstate::loadRecByRef(
			ubigint ref
			, WdbeMFsmstate** rec
		) {
	return false;
};

ubigint TblWdbeMFsmstate::loadRefsByClu(
			ubigint refWdbeCFsmstate
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMFsmstate::loadRefsByFsm(
			ubigint fsmRefWdbeMFsm
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMFsmstate::loadRstByClu(
			ubigint refWdbeCFsmstate
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	return 0;
};

ubigint TblWdbeMFsmstate::loadRstByFsm(
			ubigint fsmRefWdbeMFsm
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	return 0;
};

bool TblWdbeMFsmstate::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMFsmstate::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	ubigint numload = 0;
	WdbeMFsmstate* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMFsmstate
 ******************************************************************************/

MyTblWdbeMFsmstate::MyTblWdbeMFsmstate() :
			TblWdbeMFsmstate()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMFsmstate::~MyTblWdbeMFsmstate() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMFsmstate::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMFsmstate (refWdbeCFsmstate, fsmRefWdbeMFsm, fsmNum, sref, Extip, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMFsmstate SET refWdbeCFsmstate = ?, fsmRefWdbeMFsm = ?, fsmNum = ?, sref = ?, Extip = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMFsmstate WHERE ref = ?", false);
};

bool MyTblWdbeMFsmstate::loadRecBySQL(
			const string& sqlstr
			, WdbeMFsmstate** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMFsmstate* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMFsmstate::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMFsmstate::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMFsmstate();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeCFsmstate = atoll((char*) dbrow[1]); else _rec->refWdbeCFsmstate = 0;
		if (dbrow[2]) _rec->fsmRefWdbeMFsm = atoll((char*) dbrow[2]); else _rec->fsmRefWdbeMFsm = 0;
		if (dbrow[3]) _rec->fsmNum = atol((char*) dbrow[3]); else _rec->fsmNum = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Extip = (atoi((char*) dbrow[5]) != 0); else _rec->Extip = false;
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMFsmstate::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMFsmstate* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMFsmstate::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMFsmstate::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMFsmstate();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeCFsmstate = atoll((char*) dbrow[1]); else rec->refWdbeCFsmstate = 0;
			if (dbrow[2]) rec->fsmRefWdbeMFsm = atoll((char*) dbrow[2]); else rec->fsmRefWdbeMFsm = 0;
			if (dbrow[3]) rec->fsmNum = atol((char*) dbrow[3]); else rec->fsmNum = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Extip = (atoi((char*) dbrow[5]) != 0); else rec->Extip = false;
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMFsmstate::insertRec(
			WdbeMFsmstate* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();
	tinyint Extip = rec->Extip;
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCFsmstate,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->fsmRefWdbeMFsm,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->fsmNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Extip,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMFsmstate::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMFsmstate::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMFsmstate::insertRst(
			ListWdbeMFsmstate& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMFsmstate::updateRec(
			WdbeMFsmstate* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	tinyint Extip = rec->Extip;
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCFsmstate,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->fsmRefWdbeMFsm,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->fsmNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Extip,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMFsmstate::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMFsmstate::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMFsmstate::updateRst(
			ListWdbeMFsmstate& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMFsmstate::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMFsmstate::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMFsmstate::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMFsmstate::loadRecByRef(
			ubigint ref
			, WdbeMFsmstate** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMFsmstate WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMFsmstate::loadRefsByClu(
			ubigint refWdbeCFsmstate
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMFsmstate WHERE refWdbeCFsmstate = " + to_string(refWdbeCFsmstate) + "", append, refs);
};

ubigint MyTblWdbeMFsmstate::loadRefsByFsm(
			ubigint fsmRefWdbeMFsm
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMFsmstate WHERE fsmRefWdbeMFsm = " + to_string(fsmRefWdbeMFsm) + "", append, refs);
};

ubigint MyTblWdbeMFsmstate::loadRstByClu(
			ubigint refWdbeCFsmstate
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCFsmstate, fsmRefWdbeMFsm, fsmNum, sref, Extip, Comment FROM TblWdbeMFsmstate WHERE refWdbeCFsmstate = " + to_string(refWdbeCFsmstate) + "", append, rst);
};

ubigint MyTblWdbeMFsmstate::loadRstByFsm(
			ubigint fsmRefWdbeMFsm
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCFsmstate, fsmRefWdbeMFsm, fsmNum, sref, Extip, Comment FROM TblWdbeMFsmstate WHERE fsmRefWdbeMFsm = " + to_string(fsmRefWdbeMFsm) + " ORDER BY fsmNum ASC", append, rst);
};

bool MyTblWdbeMFsmstate::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMFsmstate WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMFsmstate
 ******************************************************************************/

PgTblWdbeMFsmstate::PgTblWdbeMFsmstate() :
			TblWdbeMFsmstate()
			, PgTable()
		{
};

PgTblWdbeMFsmstate::~PgTblWdbeMFsmstate() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMFsmstate::initStatements() {
	createStatement("TblWdbeMFsmstate_insertRec", "INSERT INTO TblWdbeMFsmstate (refWdbeCFsmstate, fsmRefWdbeMFsm, fsmNum, sref, Extip, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6);
	createStatement("TblWdbeMFsmstate_updateRec", "UPDATE TblWdbeMFsmstate SET refWdbeCFsmstate = $1, fsmRefWdbeMFsm = $2, fsmNum = $3, sref = $4, Extip = $5, Comment = $6 WHERE ref = $7", 7);
	createStatement("TblWdbeMFsmstate_removeRecByRef", "DELETE FROM TblWdbeMFsmstate WHERE ref = $1", 1);

	createStatement("TblWdbeMFsmstate_loadRecByRef", "SELECT ref, refWdbeCFsmstate, fsmRefWdbeMFsm, fsmNum, sref, Extip, Comment FROM TblWdbeMFsmstate WHERE ref = $1", 1);
	createStatement("TblWdbeMFsmstate_loadRefsByClu", "SELECT ref FROM TblWdbeMFsmstate WHERE refWdbeCFsmstate = $1", 1);
	createStatement("TblWdbeMFsmstate_loadRefsByFsm", "SELECT ref FROM TblWdbeMFsmstate WHERE fsmRefWdbeMFsm = $1", 1);
	createStatement("TblWdbeMFsmstate_loadRstByClu", "SELECT ref, refWdbeCFsmstate, fsmRefWdbeMFsm, fsmNum, sref, Extip, Comment FROM TblWdbeMFsmstate WHERE refWdbeCFsmstate = $1", 1);
	createStatement("TblWdbeMFsmstate_loadRstByFsm", "SELECT ref, refWdbeCFsmstate, fsmRefWdbeMFsm, fsmNum, sref, Extip, Comment FROM TblWdbeMFsmstate WHERE fsmRefWdbeMFsm = $1 ORDER BY fsmNum ASC", 1);
	createStatement("TblWdbeMFsmstate_loadSrfByRef", "SELECT sref FROM TblWdbeMFsmstate WHERE ref = $1", 1);
};

bool PgTblWdbeMFsmstate::loadRec(
			PGresult* res
			, WdbeMFsmstate** rec
		) {
	char* ptr;

	WdbeMFsmstate* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMFsmstate();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecfsmstate"),
			PQfnumber(res, "fsmrefwdbemfsm"),
			PQfnumber(res, "fsmnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "extip"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeCFsmstate = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->fsmRefWdbeMFsm = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->fsmNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Extip = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMFsmstate::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMFsmstate* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecfsmstate"),
			PQfnumber(res, "fsmrefwdbemfsm"),
			PQfnumber(res, "fsmnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "extip"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMFsmstate();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeCFsmstate = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->fsmRefWdbeMFsm = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->fsmNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Extip = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMFsmstate::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMFsmstate** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFsmstate::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMFsmstate::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFsmstate::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMFsmstate::loadRecBySQL(
			const string& sqlstr
			, WdbeMFsmstate** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFsmstate::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMFsmstate::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFsmstate::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMFsmstate::insertRec(
			WdbeMFsmstate* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeCFsmstate = htonl64(rec->refWdbeCFsmstate);
	ubigint _fsmRefWdbeMFsm = htonl64(rec->fsmRefWdbeMFsm);
	uint _fsmNum = htonl(rec->fsmNum);
	smallint _Extip = htons((smallint) rec->Extip);

	const char* vals[] = {
		(char*) &_refWdbeCFsmstate,
		(char*) &_fsmRefWdbeMFsm,
		(char*) &_fsmNum,
		rec->sref.c_str(),
		(char*) &_Extip,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeMFsmstate_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFsmstate::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMFsmstate::insertRst(
			ListWdbeMFsmstate& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMFsmstate::updateRec(
			WdbeMFsmstate* rec
		) {
	PGresult* res;

	ubigint _refWdbeCFsmstate = htonl64(rec->refWdbeCFsmstate);
	ubigint _fsmRefWdbeMFsm = htonl64(rec->fsmRefWdbeMFsm);
	uint _fsmNum = htonl(rec->fsmNum);
	smallint _Extip = htons((smallint) rec->Extip);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeCFsmstate,
		(char*) &_fsmRefWdbeMFsm,
		(char*) &_fsmNum,
		rec->sref.c_str(),
		(char*) &_Extip,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMFsmstate_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMFsmstate::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMFsmstate::updateRst(
			ListWdbeMFsmstate& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMFsmstate::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMFsmstate_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMFsmstate::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMFsmstate::loadRecByRef(
			ubigint ref
			, WdbeMFsmstate** rec
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

	return loadRecByStmt("TblWdbeMFsmstate_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMFsmstate::loadRefsByClu(
			ubigint refWdbeCFsmstate
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeCFsmstate = htonl64(refWdbeCFsmstate);

	const char* vals[] = {
		(char*) &_refWdbeCFsmstate
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMFsmstate_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMFsmstate::loadRefsByFsm(
			ubigint fsmRefWdbeMFsm
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _fsmRefWdbeMFsm = htonl64(fsmRefWdbeMFsm);

	const char* vals[] = {
		(char*) &_fsmRefWdbeMFsm
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMFsmstate_loadRefsByFsm", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMFsmstate::loadRstByClu(
			ubigint refWdbeCFsmstate
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	ubigint _refWdbeCFsmstate = htonl64(refWdbeCFsmstate);

	const char* vals[] = {
		(char*) &_refWdbeCFsmstate
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMFsmstate_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeMFsmstate::loadRstByFsm(
			ubigint fsmRefWdbeMFsm
			, const bool append
			, ListWdbeMFsmstate& rst
		) {
	ubigint _fsmRefWdbeMFsm = htonl64(fsmRefWdbeMFsm);

	const char* vals[] = {
		(char*) &_fsmRefWdbeMFsm
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMFsmstate_loadRstByFsm", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMFsmstate::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMFsmstate_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
