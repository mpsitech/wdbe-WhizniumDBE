/**
	* \file WdbeAMMachineMakefile.cpp
	* database access for table TblWdbeAMMachineMakefile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAMMachineMakefile.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMMachineMakefile
 ******************************************************************************/

WdbeAMMachineMakefile::WdbeAMMachineMakefile(
			const ubigint ref
			, const ubigint refWdbeMMachine
			, const string x1SrefKTag
			, const string Val
		) {

	this->ref = ref;
	this->refWdbeMMachine = refWdbeMMachine;
	this->x1SrefKTag = x1SrefKTag;
	this->Val = Val;
};

bool WdbeAMMachineMakefile::operator==(
			const WdbeAMMachineMakefile& comp
		) {
	return false;
};

bool WdbeAMMachineMakefile::operator!=(
			const WdbeAMMachineMakefile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMMachineMakefile
 ******************************************************************************/

ListWdbeAMMachineMakefile::ListWdbeAMMachineMakefile() {
};

ListWdbeAMMachineMakefile::ListWdbeAMMachineMakefile(
			const ListWdbeAMMachineMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMMachineMakefile(*(src.nodes[i]));
};

ListWdbeAMMachineMakefile::~ListWdbeAMMachineMakefile() {
	clear();
};

void ListWdbeAMMachineMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMMachineMakefile::size() const {
	return(nodes.size());
};

void ListWdbeAMMachineMakefile::append(
			WdbeAMMachineMakefile* rec
		) {
	nodes.push_back(rec);
};

WdbeAMMachineMakefile* ListWdbeAMMachineMakefile::operator[](
			const uint ix
		) {
	WdbeAMMachineMakefile* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMMachineMakefile& ListWdbeAMMachineMakefile::operator=(
			const ListWdbeAMMachineMakefile& src
		) {
	WdbeAMMachineMakefile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMMachineMakefile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMMachineMakefile::operator==(
			const ListWdbeAMMachineMakefile& comp
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

bool ListWdbeAMMachineMakefile::operator!=(
			const ListWdbeAMMachineMakefile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMMachineMakefile
 ******************************************************************************/

TblWdbeAMMachineMakefile::TblWdbeAMMachineMakefile() {
};

TblWdbeAMMachineMakefile::~TblWdbeAMMachineMakefile() {
};

bool TblWdbeAMMachineMakefile::loadRecBySQL(
			const string& sqlstr
			, WdbeAMMachineMakefile** rec
		) {
	return false;
};

ubigint TblWdbeAMMachineMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMMachineMakefile& rst
		) {
	return 0;
};

ubigint TblWdbeAMMachineMakefile::insertRec(
			WdbeAMMachineMakefile* rec
		) {
	return 0;
};

ubigint TblWdbeAMMachineMakefile::insertNewRec(
			WdbeAMMachineMakefile** rec
			, const ubigint refWdbeMMachine
			, const string x1SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMMachineMakefile* _rec = NULL;

	_rec = new WdbeAMMachineMakefile(0, refWdbeMMachine, x1SrefKTag, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMMachineMakefile::appendNewRecToRst(
			ListWdbeAMMachineMakefile& rst
			, WdbeAMMachineMakefile** rec
			, const ubigint refWdbeMMachine
			, const string x1SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMMachineMakefile* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMMachine, x1SrefKTag, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMMachineMakefile::insertRst(
			ListWdbeAMMachineMakefile& rst
			, bool transact
		) {
};

void TblWdbeAMMachineMakefile::updateRec(
			WdbeAMMachineMakefile* rec
		) {
};

void TblWdbeAMMachineMakefile::updateRst(
			ListWdbeAMMachineMakefile& rst
			, bool transact
		) {
};

void TblWdbeAMMachineMakefile::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMMachineMakefile::loadRecByRef(
			ubigint ref
			, WdbeAMMachineMakefile** rec
		) {
	return false;
};

ubigint TblWdbeAMMachineMakefile::loadRefsByMch(
			ubigint refWdbeMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMMachineMakefile::loadRstByMch(
			ubigint refWdbeMMachine
			, const bool append
			, ListWdbeAMMachineMakefile& rst
		) {
	return 0;
};

bool TblWdbeAMMachineMakefile::loadValByMchTag(
			ubigint refWdbeMMachine
			, string x1SrefKTag
			, string& Val
		) {
	return false;
};

ubigint TblWdbeAMMachineMakefile::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMMachineMakefile& rst
		) {
	ubigint numload = 0;
	WdbeAMMachineMakefile* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMMachineMakefile
 ******************************************************************************/

MyTblWdbeAMMachineMakefile::MyTblWdbeAMMachineMakefile() :
			TblWdbeAMMachineMakefile()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMMachineMakefile::~MyTblWdbeAMMachineMakefile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMMachineMakefile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMMachineMakefile (refWdbeMMachine, x1SrefKTag, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMMachineMakefile SET refWdbeMMachine = ?, x1SrefKTag = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMMachineMakefile WHERE ref = ?", false);
};

bool MyTblWdbeAMMachineMakefile::loadRecBySQL(
			const string& sqlstr
			, WdbeAMMachineMakefile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMMachineMakefile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMMachineMakefile::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMMachineMakefile::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMMachineMakefile();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMMachine = atoll((char*) dbrow[1]); else _rec->refWdbeMMachine = 0;
		if (dbrow[2]) _rec->x1SrefKTag.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKTag = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMMachineMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMMachineMakefile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMMachineMakefile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMMachineMakefile::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMMachineMakefile::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMMachineMakefile();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMMachine = atoll((char*) dbrow[1]); else rec->refWdbeMMachine = 0;
			if (dbrow[2]) rec->x1SrefKTag.assign(dbrow[2], dblengths[2]); else rec->x1SrefKTag = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMMachineMakefile::insertRec(
			WdbeAMMachineMakefile* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKTag.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKTag.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMMachineMakefile::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMMachineMakefile::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMMachineMakefile::insertRst(
			ListWdbeAMMachineMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMMachineMakefile::updateRec(
			WdbeAMMachineMakefile* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKTag.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKTag.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMMachineMakefile::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMMachineMakefile::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMMachineMakefile::updateRst(
			ListWdbeAMMachineMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMMachineMakefile::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMMachineMakefile::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMMachineMakefile::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMMachineMakefile::loadRecByRef(
			ubigint ref
			, WdbeAMMachineMakefile** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMMachineMakefile WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMMachineMakefile::loadRefsByMch(
			ubigint refWdbeMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMMachineMakefile WHERE refWdbeMMachine = " + to_string(refWdbeMMachine) + "", append, refs);
};

ubigint MyTblWdbeAMMachineMakefile::loadRstByMch(
			ubigint refWdbeMMachine
			, const bool append
			, ListWdbeAMMachineMakefile& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMMachine, x1SrefKTag, Val FROM TblWdbeAMMachineMakefile WHERE refWdbeMMachine = " + to_string(refWdbeMMachine) + " ORDER BY x1SrefKTag ASC", append, rst);
};

bool MyTblWdbeAMMachineMakefile::loadValByMchTag(
			ubigint refWdbeMMachine
			, string x1SrefKTag
			, string& Val
		) {
	return loadStringBySQL("SELECT Val FROM TblWdbeAMMachineMakefile WHERE refWdbeMMachine = " + to_string(refWdbeMMachine) + " AND x1SrefKTag = '" + x1SrefKTag + "'", Val);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMMachineMakefile
 ******************************************************************************/

PgTblWdbeAMMachineMakefile::PgTblWdbeAMMachineMakefile() :
			TblWdbeAMMachineMakefile()
			, PgTable()
		{
};

PgTblWdbeAMMachineMakefile::~PgTblWdbeAMMachineMakefile() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMMachineMakefile::initStatements() {
	createStatement("TblWdbeAMMachineMakefile_insertRec", "INSERT INTO TblWdbeAMMachineMakefile (refWdbeMMachine, x1SrefKTag, Val) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeAMMachineMakefile_updateRec", "UPDATE TblWdbeAMMachineMakefile SET refWdbeMMachine = $1, x1SrefKTag = $2, Val = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeAMMachineMakefile_removeRecByRef", "DELETE FROM TblWdbeAMMachineMakefile WHERE ref = $1", 1);

	createStatement("TblWdbeAMMachineMakefile_loadRecByRef", "SELECT ref, refWdbeMMachine, x1SrefKTag, Val FROM TblWdbeAMMachineMakefile WHERE ref = $1", 1);
	createStatement("TblWdbeAMMachineMakefile_loadRefsByMch", "SELECT ref FROM TblWdbeAMMachineMakefile WHERE refWdbeMMachine = $1", 1);
	createStatement("TblWdbeAMMachineMakefile_loadRstByMch", "SELECT ref, refWdbeMMachine, x1SrefKTag, Val FROM TblWdbeAMMachineMakefile WHERE refWdbeMMachine = $1 ORDER BY x1SrefKTag ASC", 1);
	createStatement("TblWdbeAMMachineMakefile_loadValByMchTag", "SELECT Val FROM TblWdbeAMMachineMakefile WHERE refWdbeMMachine = $1 AND x1SrefKTag = $2", 2);
};

bool PgTblWdbeAMMachineMakefile::loadRec(
			PGresult* res
			, WdbeAMMachineMakefile** rec
		) {
	char* ptr;

	WdbeAMMachineMakefile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMMachineMakefile();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmachine"),
			PQfnumber(res, "x1srefktag"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKTag.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMMachineMakefile::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMMachineMakefile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMMachineMakefile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmachine"),
			PQfnumber(res, "x1srefktag"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WdbeAMMachineMakefile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKTag.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMMachineMakefile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMMachineMakefile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMMachineMakefile::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMMachineMakefile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMMachineMakefile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMMachineMakefile::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMMachineMakefile::loadRecBySQL(
			const string& sqlstr
			, WdbeAMMachineMakefile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMMachineMakefile::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMMachineMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMMachineMakefile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMMachineMakefile::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMMachineMakefile::insertRec(
			WdbeAMMachineMakefile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMMachine = htonl64(rec->refWdbeMMachine);

	const char* vals[] = {
		(char*) &_refWdbeMMachine,
		rec->x1SrefKTag.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMMachineMakefile_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMMachineMakefile::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMMachineMakefile::insertRst(
			ListWdbeAMMachineMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMMachineMakefile::updateRec(
			WdbeAMMachineMakefile* rec
		) {
	PGresult* res;

	ubigint _refWdbeMMachine = htonl64(rec->refWdbeMMachine);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMMachine,
		rec->x1SrefKTag.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMMachineMakefile_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMMachineMakefile::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMMachineMakefile::updateRst(
			ListWdbeAMMachineMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMMachineMakefile::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMMachineMakefile_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMMachineMakefile::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMMachineMakefile::loadRecByRef(
			ubigint ref
			, WdbeAMMachineMakefile** rec
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

	return loadRecByStmt("TblWdbeAMMachineMakefile_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMMachineMakefile::loadRefsByMch(
			ubigint refWdbeMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMMachine = htonl64(refWdbeMMachine);

	const char* vals[] = {
		(char*) &_refWdbeMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMMachineMakefile_loadRefsByMch", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMMachineMakefile::loadRstByMch(
			ubigint refWdbeMMachine
			, const bool append
			, ListWdbeAMMachineMakefile& rst
		) {
	ubigint _refWdbeMMachine = htonl64(refWdbeMMachine);

	const char* vals[] = {
		(char*) &_refWdbeMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMMachineMakefile_loadRstByMch", 1, vals, l, f, append, rst);
};

bool PgTblWdbeAMMachineMakefile::loadValByMchTag(
			ubigint refWdbeMMachine
			, string x1SrefKTag
			, string& Val
		) {
	ubigint _refWdbeMMachine = htonl64(refWdbeMMachine);

	const char* vals[] = {
		(char*) &_refWdbeMMachine,
		x1SrefKTag.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadStringByStmt("TblWdbeAMMachineMakefile_loadValByMchTag", 2, vals, l, f, Val);
};

#endif

