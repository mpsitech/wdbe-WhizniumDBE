/**
	* \file WdbeMImbuf.cpp
	* database access for table TblWdbeMImbuf (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMImbuf.h"

#include "WdbeMImbuf_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMImbuf
 ******************************************************************************/

WdbeMImbuf::WdbeMImbuf(
			const ubigint ref
			, const uint ixVRotype
			, const ubigint refWdbeMModule
			, const string Fullsref
			, const usmallint Width
			, const string Minmax
			, const utinyint Prio
		) {

	this->ref = ref;
	this->ixVRotype = ixVRotype;
	this->refWdbeMModule = refWdbeMModule;
	this->Fullsref = Fullsref;
	this->Width = Width;
	this->Minmax = Minmax;
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
			, const uint ixVRotype
			, const ubigint refWdbeMModule
			, const string Fullsref
			, const usmallint Width
			, const string Minmax
			, const utinyint Prio
		) {
	ubigint retval = 0;
	WdbeMImbuf* _rec = NULL;

	_rec = new WdbeMImbuf(0, ixVRotype, refWdbeMModule, Fullsref, Width, Minmax, Prio);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMImbuf::appendNewRecToRst(
			ListWdbeMImbuf& rst
			, WdbeMImbuf** rec
			, const uint ixVRotype
			, const ubigint refWdbeMModule
			, const string Fullsref
			, const usmallint Width
			, const string Minmax
			, const utinyint Prio
		) {
	ubigint retval = 0;
	WdbeMImbuf* _rec = NULL;

	retval = insertNewRec(&_rec, ixVRotype, refWdbeMModule, Fullsref, Width, Minmax, Prio);
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

bool TblWdbeMImbuf::loadFsrByRef(
			ubigint ref
			, string& Fullsref
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
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMImbuf (ixVRotype, refWdbeMModule, Fullsref, Width, Minmax, Prio) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMImbuf SET ixVRotype = ?, refWdbeMModule = ?, Fullsref = ?, Width = ?, Minmax = ?, Prio = ? WHERE ref = ?", false);
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
		if (dbrow[1]) _rec->ixVRotype = atol((char*) dbrow[1]); else _rec->ixVRotype = 0;
		if (dbrow[2]) _rec->refWdbeMModule = atoll((char*) dbrow[2]); else _rec->refWdbeMModule = 0;
		if (dbrow[3]) _rec->Fullsref.assign(dbrow[3], dblengths[3]); else _rec->Fullsref = "";
		if (dbrow[4]) _rec->Width = atoi((char*) dbrow[4]); else _rec->Width = 0;
		if (dbrow[5]) _rec->Minmax.assign(dbrow[5], dblengths[5]); else _rec->Minmax = "";
		if (dbrow[6]) _rec->Prio = atoi((char*) dbrow[6]); else _rec->Prio = 0;

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
			if (dbrow[1]) rec->ixVRotype = atol((char*) dbrow[1]); else rec->ixVRotype = 0;
			if (dbrow[2]) rec->refWdbeMModule = atoll((char*) dbrow[2]); else rec->refWdbeMModule = 0;
			if (dbrow[3]) rec->Fullsref.assign(dbrow[3], dblengths[3]); else rec->Fullsref = "";
			if (dbrow[4]) rec->Width = atoi((char*) dbrow[4]); else rec->Width = 0;
			if (dbrow[5]) rec->Minmax.assign(dbrow[5], dblengths[5]); else rec->Minmax = "";
			if (dbrow[6]) rec->Prio = atoi((char*) dbrow[6]); else rec->Prio = 0;
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
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->Fullsref.length();
	l[4] = rec->Minmax.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVRotype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMModule,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUsmallint(&rec->Width,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUtinyint(&rec->Prio,&(l[5]),&(n[5]),&(e[5]))
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
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[2] = rec->Fullsref.length();
	l[4] = rec->Minmax.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVRotype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMModule,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUsmallint(&rec->Width,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUtinyint(&rec->Prio,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
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

bool MyTblWdbeMImbuf::loadFsrByRef(
			ubigint ref
			, string& Fullsref
		) {
	return loadStringBySQL("SELECT Fullsref FROM TblWdbeMImbuf WHERE ref = " + to_string(ref) + "", Fullsref);
};

bool MyTblWdbeMImbuf::loadRecByMdl(
			ubigint refWdbeMModule
			, WdbeMImbuf** rec
		) {
	return loadRecBySQL("SELECT ref, ixVRotype, refWdbeMModule, Fullsref, Width, Minmax, Prio FROM TblWdbeMImbuf WHERE refWdbeMModule = " + to_string(refWdbeMModule) + "", rec);
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
	createStatement("TblWdbeMImbuf_insertRec", "INSERT INTO TblWdbeMImbuf (ixVRotype, refWdbeMModule, Fullsref, Width, Minmax, Prio) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6);
	createStatement("TblWdbeMImbuf_updateRec", "UPDATE TblWdbeMImbuf SET ixVRotype = $1, refWdbeMModule = $2, Fullsref = $3, Width = $4, Minmax = $5, Prio = $6 WHERE ref = $7", 7);
	createStatement("TblWdbeMImbuf_removeRecByRef", "DELETE FROM TblWdbeMImbuf WHERE ref = $1", 1);

	createStatement("TblWdbeMImbuf_loadRecByRef", "SELECT ref, ixVRotype, refWdbeMModule, Fullsref, Width, Minmax, Prio FROM TblWdbeMImbuf WHERE ref = $1", 1);
	createStatement("TblWdbeMImbuf_loadFsrByRef", "SELECT Fullsref FROM TblWdbeMImbuf WHERE ref = $1", 1);
	createStatement("TblWdbeMImbuf_loadRecByMdl", "SELECT ref, ixVRotype, refWdbeMModule, Fullsref, Width, Minmax, Prio FROM TblWdbeMImbuf WHERE refWdbeMModule = $1", 1);
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
			PQfnumber(res, "ixvrotype"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax"),
			PQfnumber(res, "prio")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVRotype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Fullsref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Width = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Minmax.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Prio = atoi(ptr);

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
			PQfnumber(res, "ixvrotype"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax"),
			PQfnumber(res, "prio")
		};

		while (numread < numrow) {
			rec = new WdbeMImbuf();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVRotype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Fullsref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Width = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Minmax.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Prio = atoi(ptr);

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

	uint _ixVRotype = htonl(rec->ixVRotype);
	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	usmallint _Width = htons(rec->Width);
	usmallint _Prio = htons(rec->Prio);

	const char* vals[] = {
		(char*) &_ixVRotype,
		(char*) &_refWdbeMModule,
		rec->Fullsref.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str(),
		(char*) &_Prio
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(usmallint),
		0,
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMImbuf_insertRec", 6, vals, l, f, 0);

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

	uint _ixVRotype = htonl(rec->ixVRotype);
	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	usmallint _Width = htons(rec->Width);
	usmallint _Prio = htons(rec->Prio);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVRotype,
		(char*) &_refWdbeMModule,
		rec->Fullsref.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str(),
		(char*) &_Prio,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(usmallint),
		0,
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeMImbuf_updateRec", 7, vals, l, f, 0);

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

bool PgTblWdbeMImbuf::loadFsrByRef(
			ubigint ref
			, string& Fullsref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMImbuf_loadFsrByRef", 1, vals, l, f, Fullsref);
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
