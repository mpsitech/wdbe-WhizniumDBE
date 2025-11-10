/**
	* \file WdbeAMCoreversionIp.cpp
	* database access for table TblWdbeAMCoreversionIp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAMCoreversionIp.h"

#include "WdbeAMCoreversionIp_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMCoreversionIp
 ******************************************************************************/

WdbeAMCoreversionIp::WdbeAMCoreversionIp(
			const ubigint ref
			, const ubigint cvrRefWdbeMCoreversion
			, const uint cvrNum
			, const string sref
			, const uint ixVTagtype
			, const string Comment
		) :
			ref(ref)
			, cvrRefWdbeMCoreversion(cvrRefWdbeMCoreversion)
			, cvrNum(cvrNum)
			, sref(sref)
			, ixVTagtype(ixVTagtype)
			, Comment(Comment)
		{
};

bool WdbeAMCoreversionIp::operator==(
			const WdbeAMCoreversionIp& comp
		) {
	return false;
};

bool WdbeAMCoreversionIp::operator!=(
			const WdbeAMCoreversionIp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMCoreversionIp
 ******************************************************************************/

ListWdbeAMCoreversionIp::ListWdbeAMCoreversionIp() {
};

ListWdbeAMCoreversionIp::ListWdbeAMCoreversionIp(
			const ListWdbeAMCoreversionIp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMCoreversionIp(*(src.nodes[i]));
};

ListWdbeAMCoreversionIp::~ListWdbeAMCoreversionIp() {
	clear();
};

void ListWdbeAMCoreversionIp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMCoreversionIp::size() const {
	return(nodes.size());
};

void ListWdbeAMCoreversionIp::append(
			WdbeAMCoreversionIp* rec
		) {
	nodes.push_back(rec);
};

WdbeAMCoreversionIp* ListWdbeAMCoreversionIp::operator[](
			const uint ix
		) {
	WdbeAMCoreversionIp* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMCoreversionIp& ListWdbeAMCoreversionIp::operator=(
			const ListWdbeAMCoreversionIp& src
		) {
	WdbeAMCoreversionIp* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMCoreversionIp(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMCoreversionIp::operator==(
			const ListWdbeAMCoreversionIp& comp
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

bool ListWdbeAMCoreversionIp::operator!=(
			const ListWdbeAMCoreversionIp& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMCoreversionIp
 ******************************************************************************/

TblWdbeAMCoreversionIp::TblWdbeAMCoreversionIp() {
};

TblWdbeAMCoreversionIp::~TblWdbeAMCoreversionIp() {
};

bool TblWdbeAMCoreversionIp::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCoreversionIp** rec
		) {
	return false;
};

ubigint TblWdbeAMCoreversionIp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCoreversionIp& rst
		) {
	return 0;
};

ubigint TblWdbeAMCoreversionIp::insertRec(
			WdbeAMCoreversionIp* rec
		) {
	return 0;
};

ubigint TblWdbeAMCoreversionIp::insertNewRec(
			WdbeAMCoreversionIp** rec
			, const ubigint cvrRefWdbeMCoreversion
			, const uint cvrNum
			, const string sref
			, const uint ixVTagtype
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAMCoreversionIp* _rec = NULL;

	_rec = new WdbeAMCoreversionIp(0, cvrRefWdbeMCoreversion, cvrNum, sref, ixVTagtype, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMCoreversionIp::appendNewRecToRst(
			ListWdbeAMCoreversionIp& rst
			, WdbeAMCoreversionIp** rec
			, const ubigint cvrRefWdbeMCoreversion
			, const uint cvrNum
			, const string sref
			, const uint ixVTagtype
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAMCoreversionIp* _rec = NULL;

	retval = insertNewRec(&_rec, cvrRefWdbeMCoreversion, cvrNum, sref, ixVTagtype, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMCoreversionIp::insertRst(
			ListWdbeAMCoreversionIp& rst
			, bool transact
		) {
};

void TblWdbeAMCoreversionIp::updateRec(
			WdbeAMCoreversionIp* rec
		) {
};

void TblWdbeAMCoreversionIp::updateRst(
			ListWdbeAMCoreversionIp& rst
			, bool transact
		) {
};

void TblWdbeAMCoreversionIp::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMCoreversionIp::loadRecByRef(
			ubigint ref
			, WdbeAMCoreversionIp** rec
		) {
	return false;
};

ubigint TblWdbeAMCoreversionIp::loadRstByCvr(
			ubigint cvrRefWdbeMCoreversion
			, const bool append
			, ListWdbeAMCoreversionIp& rst
		) {
	return 0;
};

ubigint TblWdbeAMCoreversionIp::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMCoreversionIp& rst
		) {
	ubigint numload = 0;
	WdbeAMCoreversionIp* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMCoreversionIp
 ******************************************************************************/

MyTblWdbeAMCoreversionIp::MyTblWdbeAMCoreversionIp() :
			TblWdbeAMCoreversionIp()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMCoreversionIp::~MyTblWdbeAMCoreversionIp() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMCoreversionIp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMCoreversionIp (cvrRefWdbeMCoreversion, cvrNum, sref, ixVTagtype, Comment) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMCoreversionIp SET cvrRefWdbeMCoreversion = ?, cvrNum = ?, sref = ?, ixVTagtype = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMCoreversionIp WHERE ref = ?", false);
};

bool MyTblWdbeAMCoreversionIp::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCoreversionIp** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMCoreversionIp* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMCoreversionIp::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMCoreversionIp::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMCoreversionIp();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->cvrRefWdbeMCoreversion = atoll((char*) dbrow[1]); else _rec->cvrRefWdbeMCoreversion = 0;
		if (dbrow[2]) _rec->cvrNum = atol((char*) dbrow[2]); else _rec->cvrNum = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->ixVTagtype = atol((char*) dbrow[4]); else _rec->ixVTagtype = 0;
		if (dbrow[5]) _rec->Comment.assign(dbrow[5], dblengths[5]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMCoreversionIp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCoreversionIp& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMCoreversionIp* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMCoreversionIp::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMCoreversionIp::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMCoreversionIp();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->cvrRefWdbeMCoreversion = atoll((char*) dbrow[1]); else rec->cvrRefWdbeMCoreversion = 0;
			if (dbrow[2]) rec->cvrNum = atol((char*) dbrow[2]); else rec->cvrNum = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->ixVTagtype = atol((char*) dbrow[4]); else rec->ixVTagtype = 0;
			if (dbrow[5]) rec->Comment.assign(dbrow[5], dblengths[5]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMCoreversionIp::insertRec(
			WdbeAMCoreversionIp* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->cvrRefWdbeMCoreversion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->cvrNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVTagtype,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMCoreversionIp::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMCoreversionIp::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMCoreversionIp::insertRst(
			ListWdbeAMCoreversionIp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMCoreversionIp::updateRec(
			WdbeAMCoreversionIp* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->sref.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->cvrRefWdbeMCoreversion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->cvrNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVTagtype,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMCoreversionIp::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMCoreversionIp::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMCoreversionIp::updateRst(
			ListWdbeAMCoreversionIp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMCoreversionIp::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMCoreversionIp::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMCoreversionIp::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMCoreversionIp::loadRecByRef(
			ubigint ref
			, WdbeAMCoreversionIp** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMCoreversionIp WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMCoreversionIp::loadRstByCvr(
			ubigint cvrRefWdbeMCoreversion
			, const bool append
			, ListWdbeAMCoreversionIp& rst
		) {
	return loadRstBySQL("SELECT ref, cvrRefWdbeMCoreversion, cvrNum, sref, ixVTagtype, Comment FROM TblWdbeAMCoreversionIp WHERE cvrRefWdbeMCoreversion = " + to_string(cvrRefWdbeMCoreversion) + " ORDER BY cvrNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMCoreversionIp
 ******************************************************************************/

PgTblWdbeAMCoreversionIp::PgTblWdbeAMCoreversionIp() :
			TblWdbeAMCoreversionIp()
			, PgTable()
		{
};

PgTblWdbeAMCoreversionIp::~PgTblWdbeAMCoreversionIp() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMCoreversionIp::initStatements() {
	createStatement("TblWdbeAMCoreversionIp_insertRec", "INSERT INTO TblWdbeAMCoreversionIp (cvrRefWdbeMCoreversion, cvrNum, sref, ixVTagtype, Comment) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWdbeAMCoreversionIp_updateRec", "UPDATE TblWdbeAMCoreversionIp SET cvrRefWdbeMCoreversion = $1, cvrNum = $2, sref = $3, ixVTagtype = $4, Comment = $5 WHERE ref = $6", 6);
	createStatement("TblWdbeAMCoreversionIp_removeRecByRef", "DELETE FROM TblWdbeAMCoreversionIp WHERE ref = $1", 1);

	createStatement("TblWdbeAMCoreversionIp_loadRecByRef", "SELECT ref, cvrRefWdbeMCoreversion, cvrNum, sref, ixVTagtype, Comment FROM TblWdbeAMCoreversionIp WHERE ref = $1", 1);
	createStatement("TblWdbeAMCoreversionIp_loadRstByCvr", "SELECT ref, cvrRefWdbeMCoreversion, cvrNum, sref, ixVTagtype, Comment FROM TblWdbeAMCoreversionIp WHERE cvrRefWdbeMCoreversion = $1 ORDER BY cvrNum ASC", 1);
};

bool PgTblWdbeAMCoreversionIp::loadRec(
			PGresult* res
			, WdbeAMCoreversionIp** rec
		) {
	char* ptr;

	WdbeAMCoreversionIp* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMCoreversionIp();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "cvrrefwdbemcoreversion"),
			PQfnumber(res, "cvrnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvtagtype"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->cvrRefWdbeMCoreversion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->cvrNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVTagtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMCoreversionIp::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMCoreversionIp& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMCoreversionIp* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "cvrrefwdbemcoreversion"),
			PQfnumber(res, "cvrnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvtagtype"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeAMCoreversionIp();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->cvrRefWdbeMCoreversion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->cvrNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVTagtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMCoreversionIp::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMCoreversionIp** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCoreversionIp::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMCoreversionIp::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMCoreversionIp& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCoreversionIp::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMCoreversionIp::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCoreversionIp** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCoreversionIp::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMCoreversionIp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCoreversionIp& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCoreversionIp::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMCoreversionIp::insertRec(
			WdbeAMCoreversionIp* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _cvrRefWdbeMCoreversion = htonl64(rec->cvrRefWdbeMCoreversion);
	uint _cvrNum = htonl(rec->cvrNum);
	uint _ixVTagtype = htonl(rec->ixVTagtype);

	const char* vals[] = {
		(char*) &_cvrRefWdbeMCoreversion,
		(char*) &_cvrNum,
		rec->sref.c_str(),
		(char*) &_ixVTagtype,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMCoreversionIp_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCoreversionIp::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMCoreversionIp::insertRst(
			ListWdbeAMCoreversionIp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMCoreversionIp::updateRec(
			WdbeAMCoreversionIp* rec
		) {
	PGresult* res;

	ubigint _cvrRefWdbeMCoreversion = htonl64(rec->cvrRefWdbeMCoreversion);
	uint _cvrNum = htonl(rec->cvrNum);
	uint _ixVTagtype = htonl(rec->ixVTagtype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_cvrRefWdbeMCoreversion,
		(char*) &_cvrNum,
		rec->sref.c_str(),
		(char*) &_ixVTagtype,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMCoreversionIp_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMCoreversionIp::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMCoreversionIp::updateRst(
			ListWdbeAMCoreversionIp& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMCoreversionIp::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMCoreversionIp_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMCoreversionIp::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMCoreversionIp::loadRecByRef(
			ubigint ref
			, WdbeAMCoreversionIp** rec
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

	return loadRecByStmt("TblWdbeAMCoreversionIp_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMCoreversionIp::loadRstByCvr(
			ubigint cvrRefWdbeMCoreversion
			, const bool append
			, ListWdbeAMCoreversionIp& rst
		) {
	ubigint _cvrRefWdbeMCoreversion = htonl64(cvrRefWdbeMCoreversion);

	const char* vals[] = {
		(char*) &_cvrRefWdbeMCoreversion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMCoreversionIp_loadRstByCvr", 1, vals, l, f, append, rst);
};

#endif
