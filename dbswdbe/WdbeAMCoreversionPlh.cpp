/**
	* \file WdbeAMCoreversionPlh.cpp
	* database access for table TblWdbeAMCoreversionPlh (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAMCoreversionPlh.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMCoreversionPlh
 ******************************************************************************/

WdbeAMCoreversionPlh::WdbeAMCoreversionPlh(
			const ubigint ref
			, const ubigint cvrRefWdbeMCoreversion
			, const uint cvrNum
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->cvrRefWdbeMCoreversion = cvrRefWdbeMCoreversion;
	this->cvrNum = cvrNum;
	this->sref = sref;
	this->Comment = Comment;
};

bool WdbeAMCoreversionPlh::operator==(
			const WdbeAMCoreversionPlh& comp
		) {
	return false;
};

bool WdbeAMCoreversionPlh::operator!=(
			const WdbeAMCoreversionPlh& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMCoreversionPlh
 ******************************************************************************/

ListWdbeAMCoreversionPlh::ListWdbeAMCoreversionPlh() {
};

ListWdbeAMCoreversionPlh::ListWdbeAMCoreversionPlh(
			const ListWdbeAMCoreversionPlh& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMCoreversionPlh(*(src.nodes[i]));
};

ListWdbeAMCoreversionPlh::~ListWdbeAMCoreversionPlh() {
	clear();
};

void ListWdbeAMCoreversionPlh::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMCoreversionPlh::size() const {
	return(nodes.size());
};

void ListWdbeAMCoreversionPlh::append(
			WdbeAMCoreversionPlh* rec
		) {
	nodes.push_back(rec);
};

WdbeAMCoreversionPlh* ListWdbeAMCoreversionPlh::operator[](
			const uint ix
		) {
	WdbeAMCoreversionPlh* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMCoreversionPlh& ListWdbeAMCoreversionPlh::operator=(
			const ListWdbeAMCoreversionPlh& src
		) {
	WdbeAMCoreversionPlh* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMCoreversionPlh(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMCoreversionPlh::operator==(
			const ListWdbeAMCoreversionPlh& comp
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

bool ListWdbeAMCoreversionPlh::operator!=(
			const ListWdbeAMCoreversionPlh& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMCoreversionPlh
 ******************************************************************************/

TblWdbeAMCoreversionPlh::TblWdbeAMCoreversionPlh() {
};

TblWdbeAMCoreversionPlh::~TblWdbeAMCoreversionPlh() {
};

bool TblWdbeAMCoreversionPlh::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCoreversionPlh** rec
		) {
	return false;
};

ubigint TblWdbeAMCoreversionPlh::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCoreversionPlh& rst
		) {
	return 0;
};

ubigint TblWdbeAMCoreversionPlh::insertRec(
			WdbeAMCoreversionPlh* rec
		) {
	return 0;
};

ubigint TblWdbeAMCoreversionPlh::insertNewRec(
			WdbeAMCoreversionPlh** rec
			, const ubigint cvrRefWdbeMCoreversion
			, const uint cvrNum
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAMCoreversionPlh* _rec = NULL;

	_rec = new WdbeAMCoreversionPlh(0, cvrRefWdbeMCoreversion, cvrNum, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMCoreversionPlh::appendNewRecToRst(
			ListWdbeAMCoreversionPlh& rst
			, WdbeAMCoreversionPlh** rec
			, const ubigint cvrRefWdbeMCoreversion
			, const uint cvrNum
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAMCoreversionPlh* _rec = NULL;

	retval = insertNewRec(&_rec, cvrRefWdbeMCoreversion, cvrNum, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMCoreversionPlh::insertRst(
			ListWdbeAMCoreversionPlh& rst
			, bool transact
		) {
};

void TblWdbeAMCoreversionPlh::updateRec(
			WdbeAMCoreversionPlh* rec
		) {
};

void TblWdbeAMCoreversionPlh::updateRst(
			ListWdbeAMCoreversionPlh& rst
			, bool transact
		) {
};

void TblWdbeAMCoreversionPlh::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMCoreversionPlh::loadRecByRef(
			ubigint ref
			, WdbeAMCoreversionPlh** rec
		) {
	return false;
};

ubigint TblWdbeAMCoreversionPlh::loadRstByCvr(
			ubigint cvrRefWdbeMCoreversion
			, const bool append
			, ListWdbeAMCoreversionPlh& rst
		) {
	return 0;
};

ubigint TblWdbeAMCoreversionPlh::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMCoreversionPlh& rst
		) {
	ubigint numload = 0;
	WdbeAMCoreversionPlh* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMCoreversionPlh
 ******************************************************************************/

MyTblWdbeAMCoreversionPlh::MyTblWdbeAMCoreversionPlh() :
			TblWdbeAMCoreversionPlh()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMCoreversionPlh::~MyTblWdbeAMCoreversionPlh() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMCoreversionPlh::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMCoreversionPlh (cvrRefWdbeMCoreversion, cvrNum, sref, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMCoreversionPlh SET cvrRefWdbeMCoreversion = ?, cvrNum = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMCoreversionPlh WHERE ref = ?", false);
};

bool MyTblWdbeAMCoreversionPlh::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCoreversionPlh** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMCoreversionPlh* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMCoreversionPlh::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMCoreversionPlh::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMCoreversionPlh();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->cvrRefWdbeMCoreversion = atoll((char*) dbrow[1]); else _rec->cvrRefWdbeMCoreversion = 0;
		if (dbrow[2]) _rec->cvrNum = atol((char*) dbrow[2]); else _rec->cvrNum = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMCoreversionPlh::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCoreversionPlh& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMCoreversionPlh* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMCoreversionPlh::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMCoreversionPlh::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMCoreversionPlh();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->cvrRefWdbeMCoreversion = atoll((char*) dbrow[1]); else rec->cvrRefWdbeMCoreversion = 0;
			if (dbrow[2]) rec->cvrNum = atol((char*) dbrow[2]); else rec->cvrNum = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMCoreversionPlh::insertRec(
			WdbeAMCoreversionPlh* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->cvrRefWdbeMCoreversion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->cvrNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMCoreversionPlh::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMCoreversionPlh::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMCoreversionPlh::insertRst(
			ListWdbeAMCoreversionPlh& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMCoreversionPlh::updateRec(
			WdbeAMCoreversionPlh* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->cvrRefWdbeMCoreversion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->cvrNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMCoreversionPlh::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMCoreversionPlh::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMCoreversionPlh::updateRst(
			ListWdbeAMCoreversionPlh& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMCoreversionPlh::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMCoreversionPlh::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMCoreversionPlh::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMCoreversionPlh::loadRecByRef(
			ubigint ref
			, WdbeAMCoreversionPlh** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMCoreversionPlh WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMCoreversionPlh::loadRstByCvr(
			ubigint cvrRefWdbeMCoreversion
			, const bool append
			, ListWdbeAMCoreversionPlh& rst
		) {
	return loadRstBySQL("SELECT ref, cvrRefWdbeMCoreversion, cvrNum, sref, Comment FROM TblWdbeAMCoreversionPlh WHERE cvrRefWdbeMCoreversion = " + to_string(cvrRefWdbeMCoreversion) + " ORDER BY cvrNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMCoreversionPlh
 ******************************************************************************/

PgTblWdbeAMCoreversionPlh::PgTblWdbeAMCoreversionPlh() :
			TblWdbeAMCoreversionPlh()
			, PgTable()
		{
};

PgTblWdbeAMCoreversionPlh::~PgTblWdbeAMCoreversionPlh() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMCoreversionPlh::initStatements() {
	createStatement("TblWdbeAMCoreversionPlh_insertRec", "INSERT INTO TblWdbeAMCoreversionPlh (cvrRefWdbeMCoreversion, cvrNum, sref, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeAMCoreversionPlh_updateRec", "UPDATE TblWdbeAMCoreversionPlh SET cvrRefWdbeMCoreversion = $1, cvrNum = $2, sref = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeAMCoreversionPlh_removeRecByRef", "DELETE FROM TblWdbeAMCoreversionPlh WHERE ref = $1", 1);

	createStatement("TblWdbeAMCoreversionPlh_loadRecByRef", "SELECT ref, cvrRefWdbeMCoreversion, cvrNum, sref, Comment FROM TblWdbeAMCoreversionPlh WHERE ref = $1", 1);
	createStatement("TblWdbeAMCoreversionPlh_loadRstByCvr", "SELECT ref, cvrRefWdbeMCoreversion, cvrNum, sref, Comment FROM TblWdbeAMCoreversionPlh WHERE cvrRefWdbeMCoreversion = $1 ORDER BY cvrNum ASC", 1);
};

bool PgTblWdbeAMCoreversionPlh::loadRec(
			PGresult* res
			, WdbeAMCoreversionPlh** rec
		) {
	char* ptr;

	WdbeAMCoreversionPlh* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMCoreversionPlh();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "cvrrefwdbemcoreversion"),
			PQfnumber(res, "cvrnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->cvrRefWdbeMCoreversion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->cvrNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMCoreversionPlh::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMCoreversionPlh& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMCoreversionPlh* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "cvrrefwdbemcoreversion"),
			PQfnumber(res, "cvrnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeAMCoreversionPlh();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->cvrRefWdbeMCoreversion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->cvrNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMCoreversionPlh::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMCoreversionPlh** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCoreversionPlh::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMCoreversionPlh::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMCoreversionPlh& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCoreversionPlh::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMCoreversionPlh::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCoreversionPlh** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCoreversionPlh::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMCoreversionPlh::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCoreversionPlh& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCoreversionPlh::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMCoreversionPlh::insertRec(
			WdbeAMCoreversionPlh* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _cvrRefWdbeMCoreversion = htonl64(rec->cvrRefWdbeMCoreversion);
	uint _cvrNum = htonl(rec->cvrNum);

	const char* vals[] = {
		(char*) &_cvrRefWdbeMCoreversion,
		(char*) &_cvrNum,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMCoreversionPlh_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCoreversionPlh::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMCoreversionPlh::insertRst(
			ListWdbeAMCoreversionPlh& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMCoreversionPlh::updateRec(
			WdbeAMCoreversionPlh* rec
		) {
	PGresult* res;

	ubigint _cvrRefWdbeMCoreversion = htonl64(rec->cvrRefWdbeMCoreversion);
	uint _cvrNum = htonl(rec->cvrNum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_cvrRefWdbeMCoreversion,
		(char*) &_cvrNum,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMCoreversionPlh_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMCoreversionPlh::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMCoreversionPlh::updateRst(
			ListWdbeAMCoreversionPlh& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMCoreversionPlh::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMCoreversionPlh_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMCoreversionPlh::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMCoreversionPlh::loadRecByRef(
			ubigint ref
			, WdbeAMCoreversionPlh** rec
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

	return loadRecByStmt("TblWdbeAMCoreversionPlh_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMCoreversionPlh::loadRstByCvr(
			ubigint cvrRefWdbeMCoreversion
			, const bool append
			, ListWdbeAMCoreversionPlh& rst
		) {
	ubigint _cvrRefWdbeMCoreversion = htonl64(cvrRefWdbeMCoreversion);

	const char* vals[] = {
		(char*) &_cvrRefWdbeMCoreversion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMCoreversionPlh_loadRstByCvr", 1, vals, l, f, append, rst);
};

#endif
