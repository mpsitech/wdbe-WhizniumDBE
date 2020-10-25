/**
	* \file WdbeMImbuf.cpp
	* database access for table TblWdbeMImbuf (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeMImbuf.h"

#include "WdbeMImbuf_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMImbuf
 ******************************************************************************/

WdbeMImbuf::WdbeMImbuf(
			const ubigint ref
			, const ubigint refWdbeMModule
			, const ubigint corRefWdbeMModule
			, const string sref
			, const uint ixVDir
			, const utinyint Prio
		) {

	this->ref = ref;
	this->refWdbeMModule = refWdbeMModule;
	this->corRefWdbeMModule = corRefWdbeMModule;
	this->sref = sref;
	this->ixVDir = ixVDir;
	this->Prio = Prio;
};

bool WdbeMImbuf::operator==(
			const WdbeMImbuf& comp
		) {
	return false;
};

bool WdbeMImbuf::operator!=(
			const WdbeMImbuf& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMImbuf
 ******************************************************************************/

ListWdbeMImbuf::ListWdbeMImbuf() {
};

ListWdbeMImbuf::ListWdbeMImbuf(
			const ListWdbeMImbuf& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMImbuf(*(src.nodes[i]));
};

ListWdbeMImbuf::~ListWdbeMImbuf() {
	clear();
};

void ListWdbeMImbuf::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMImbuf::size() const {
	return(nodes.size());
};

void ListWdbeMImbuf::append(
			WdbeMImbuf* rec
		) {
	nodes.push_back(rec);
};

WdbeMImbuf* ListWdbeMImbuf::operator[](
			const uint ix
		) {
	WdbeMImbuf* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMImbuf& ListWdbeMImbuf::operator=(
			const ListWdbeMImbuf& src
		) {
	WdbeMImbuf* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMImbuf(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMImbuf::operator==(
			const ListWdbeMImbuf& comp
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

bool ListWdbeMImbuf::operator!=(
			const ListWdbeMImbuf& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMImbuf
 ******************************************************************************/

TblWdbeMImbuf::TblWdbeMImbuf() {
};

TblWdbeMImbuf::~TblWdbeMImbuf() {
};

bool TblWdbeMImbuf::loadRecBySQL(
			const string& sqlstr
			, WdbeMImbuf** rec
		) {
	return false;
};

ubigint TblWdbeMImbuf::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMImbuf& rst
		) {
	return 0;
};

ubigint TblWdbeMImbuf::insertRec(
			WdbeMImbuf* rec
		) {
	return 0;
};

ubigint TblWdbeMImbuf::insertNewRec(
			WdbeMImbuf** rec
			, const ubigint refWdbeMModule
			, const ubigint corRefWdbeMModule
			, const string sref
			, const uint ixVDir
			, const utinyint Prio
		) {
	ubigint retval = 0;
	WdbeMImbuf* _rec = NULL;

	_rec = new WdbeMImbuf(0, refWdbeMModule, corRefWdbeMModule, sref, ixVDir, Prio);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMImbuf::appendNewRecToRst(
			ListWdbeMImbuf& rst
			, WdbeMImbuf** rec
			, const ubigint refWdbeMModule
			, const ubigint corRefWdbeMModule
			, const string sref
			, const uint ixVDir
			, const utinyint Prio
		) {
	ubigint retval = 0;
	WdbeMImbuf* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMModule, corRefWdbeMModule, sref, ixVDir, Prio);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMImbuf::insertRst(
			ListWdbeMImbuf& rst
			, bool transact
		) {
};

void TblWdbeMImbuf::updateRec(
			WdbeMImbuf* rec
		) {
};

void TblWdbeMImbuf::updateRst(
			ListWdbeMImbuf& rst
			, bool transact
		) {
};

void TblWdbeMImbuf::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMImbuf::loadRecByRef(
			ubigint ref
			, WdbeMImbuf** rec
		) {
	return false;
};

bool TblWdbeMImbuf::loadRecByMdl(
			ubigint refWdbeMModule
			, WdbeMImbuf** rec
		) {
	return false;
};

ubigint TblWdbeMImbuf::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMImbuf::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMImbuf& rst
		) {
	ubigint numload = 0;
	WdbeMImbuf* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMImbuf
 ******************************************************************************/

MyTblWdbeMImbuf::MyTblWdbeMImbuf() :
			TblWdbeMImbuf()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMImbuf::~MyTblWdbeMImbuf() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMImbuf::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMImbuf (refWdbeMModule, corRefWdbeMModule, sref, ixVDir, Prio) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMImbuf SET refWdbeMModule = ?, corRefWdbeMModule = ?, sref = ?, ixVDir = ?, Prio = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMImbuf WHERE ref = ?", false);
};

bool MyTblWdbeMImbuf::loadRecBySQL(
			const string& sqlstr
			, WdbeMImbuf** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMImbuf* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMImbuf::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMImbuf::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMImbuf();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMModule = atoll((char*) dbrow[1]); else _rec->refWdbeMModule = 0;
		if (dbrow[2]) _rec->corRefWdbeMModule = atoll((char*) dbrow[2]); else _rec->corRefWdbeMModule = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->ixVDir = atol((char*) dbrow[4]); else _rec->ixVDir = 0;
		if (dbrow[5]) _rec->Prio = atoi((char*) dbrow[5]); else _rec->Prio = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMImbuf::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMImbuf& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMImbuf* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMImbuf::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMImbuf::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMImbuf();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMModule = atoll((char*) dbrow[1]); else rec->refWdbeMModule = 0;
			if (dbrow[2]) rec->corRefWdbeMModule = atoll((char*) dbrow[2]); else rec->corRefWdbeMModule = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->ixVDir = atol((char*) dbrow[4]); else rec->ixVDir = 0;
			if (dbrow[5]) rec->Prio = atoi((char*) dbrow[5]); else rec->Prio = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMImbuf::insertRec(
			WdbeMImbuf* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->corRefWdbeMModule,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVDir,&(l[3]),&(n[3]),&(e[3])),
		bindUtinyint(&rec->Prio,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMImbuf::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMImbuf::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMImbuf::insertRst(
			ListWdbeMImbuf& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMImbuf::updateRec(
			WdbeMImbuf* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->corRefWdbeMModule,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVDir,&(l[3]),&(n[3]),&(e[3])),
		bindUtinyint(&rec->Prio,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMImbuf::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMImbuf::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMImbuf::updateRst(
			ListWdbeMImbuf& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMImbuf::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMImbuf::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMImbuf::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMImbuf::loadRecByRef(
			ubigint ref
			, WdbeMImbuf** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMImbuf WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMImbuf::loadRecByMdl(
			ubigint refWdbeMModule
			, WdbeMImbuf** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMModule, corRefWdbeMModule, sref, ixVDir, Prio FROM TblWdbeMImbuf WHERE refWdbeMModule = " + to_string(refWdbeMModule) + "", rec);
};

ubigint MyTblWdbeMImbuf::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMImbuf WHERE refWdbeMModule = " + to_string(refWdbeMModule) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMImbuf
 ******************************************************************************/

PgTblWdbeMImbuf::PgTblWdbeMImbuf() :
			TblWdbeMImbuf()
			, PgTable()
		{
};

PgTblWdbeMImbuf::~PgTblWdbeMImbuf() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMImbuf::initStatements() {
	createStatement("TblWdbeMImbuf_insertRec", "INSERT INTO TblWdbeMImbuf (refWdbeMModule, corRefWdbeMModule, sref, ixVDir, Prio) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWdbeMImbuf_updateRec", "UPDATE TblWdbeMImbuf SET refWdbeMModule = $1, corRefWdbeMModule = $2, sref = $3, ixVDir = $4, Prio = $5 WHERE ref = $6", 6);
	createStatement("TblWdbeMImbuf_removeRecByRef", "DELETE FROM TblWdbeMImbuf WHERE ref = $1", 1);

	createStatement("TblWdbeMImbuf_loadRecByRef", "SELECT ref, refWdbeMModule, corRefWdbeMModule, sref, ixVDir, Prio FROM TblWdbeMImbuf WHERE ref = $1", 1);
	createStatement("TblWdbeMImbuf_loadRecByMdl", "SELECT ref, refWdbeMModule, corRefWdbeMModule, sref, ixVDir, Prio FROM TblWdbeMImbuf WHERE refWdbeMModule = $1", 1);
	createStatement("TblWdbeMImbuf_loadRefsByMdl", "SELECT ref FROM TblWdbeMImbuf WHERE refWdbeMModule = $1", 1);
};

bool PgTblWdbeMImbuf::loadRec(
			PGresult* res
			, WdbeMImbuf** rec
		) {
	char* ptr;

	WdbeMImbuf* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMImbuf();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "correfwdbemmodule"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "prio")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->corRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVDir = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Prio = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMImbuf::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMImbuf& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMImbuf* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "correfwdbemmodule"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "prio")
		};

		while (numread < numrow) {
			rec = new WdbeMImbuf();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->corRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVDir = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Prio = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMImbuf::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMImbuf** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMImbuf::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeMImbuf::loadRecBySQL(
			const string& sqlstr
			, WdbeMImbuf** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMImbuf::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMImbuf::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMImbuf& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMImbuf::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMImbuf::insertRec(
			WdbeMImbuf* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	ubigint _corRefWdbeMModule = htonl64(rec->corRefWdbeMModule);
	uint _ixVDir = htonl(rec->ixVDir);
	usmallint _Prio = htons(rec->Prio);

	const char* vals[] = {
		(char*) &_refWdbeMModule,
		(char*) &_corRefWdbeMModule,
		rec->sref.c_str(),
		(char*) &_ixVDir,
		(char*) &_Prio
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeMImbuf_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMImbuf::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMImbuf::insertRst(
			ListWdbeMImbuf& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMImbuf::updateRec(
			WdbeMImbuf* rec
		) {
	PGresult* res;

	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	ubigint _corRefWdbeMModule = htonl64(rec->corRefWdbeMModule);
	uint _ixVDir = htonl(rec->ixVDir);
	usmallint _Prio = htons(rec->Prio);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMModule,
		(char*) &_corRefWdbeMModule,
		rec->sref.c_str(),
		(char*) &_ixVDir,
		(char*) &_Prio,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeMImbuf_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMImbuf::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMImbuf::updateRst(
			ListWdbeMImbuf& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMImbuf::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMImbuf_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMImbuf::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMImbuf::loadRecByRef(
			ubigint ref
			, WdbeMImbuf** rec
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

	return loadRecByStmt("TblWdbeMImbuf_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMImbuf::loadRecByMdl(
			ubigint refWdbeMModule
			, WdbeMImbuf** rec
		) {
	ubigint _refWdbeMModule = htonl64(refWdbeMModule);

	const char* vals[] = {
		(char*) &_refWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMImbuf_loadRecByMdl", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMImbuf::loadRefsByMdl(
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

	return loadRefsByStmt("TblWdbeMImbuf_loadRefsByMdl", 1, vals, l, f, append, refs);
};

#endif

