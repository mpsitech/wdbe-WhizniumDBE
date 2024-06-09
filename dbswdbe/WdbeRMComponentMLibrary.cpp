/**
	* \file WdbeRMComponentMLibrary.cpp
	* database access for table TblWdbeRMComponentMLibrary (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#include "WdbeRMComponentMLibrary.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeRMComponentMLibrary
 ******************************************************************************/

WdbeRMComponentMLibrary::WdbeRMComponentMLibrary(
			const ubigint ref
			, const ubigint refWdbeMComponent
			, const ubigint refWdbeMLibrary
		) {

	this->ref = ref;
	this->refWdbeMComponent = refWdbeMComponent;
	this->refWdbeMLibrary = refWdbeMLibrary;
};

bool WdbeRMComponentMLibrary::operator==(
			const WdbeRMComponentMLibrary& comp
		) {
	return false;
};

bool WdbeRMComponentMLibrary::operator!=(
			const WdbeRMComponentMLibrary& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeRMComponentMLibrary
 ******************************************************************************/

ListWdbeRMComponentMLibrary::ListWdbeRMComponentMLibrary() {
};

ListWdbeRMComponentMLibrary::ListWdbeRMComponentMLibrary(
			const ListWdbeRMComponentMLibrary& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeRMComponentMLibrary(*(src.nodes[i]));
};

ListWdbeRMComponentMLibrary::~ListWdbeRMComponentMLibrary() {
	clear();
};

void ListWdbeRMComponentMLibrary::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeRMComponentMLibrary::size() const {
	return(nodes.size());
};

void ListWdbeRMComponentMLibrary::append(
			WdbeRMComponentMLibrary* rec
		) {
	nodes.push_back(rec);
};

WdbeRMComponentMLibrary* ListWdbeRMComponentMLibrary::operator[](
			const uint ix
		) {
	WdbeRMComponentMLibrary* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeRMComponentMLibrary& ListWdbeRMComponentMLibrary::operator=(
			const ListWdbeRMComponentMLibrary& src
		) {
	WdbeRMComponentMLibrary* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeRMComponentMLibrary(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeRMComponentMLibrary::operator==(
			const ListWdbeRMComponentMLibrary& comp
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

bool ListWdbeRMComponentMLibrary::operator!=(
			const ListWdbeRMComponentMLibrary& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeRMComponentMLibrary
 ******************************************************************************/

TblWdbeRMComponentMLibrary::TblWdbeRMComponentMLibrary() {
};

TblWdbeRMComponentMLibrary::~TblWdbeRMComponentMLibrary() {
};

bool TblWdbeRMComponentMLibrary::loadRecBySQL(
			const string& sqlstr
			, WdbeRMComponentMLibrary** rec
		) {
	return false;
};

ubigint TblWdbeRMComponentMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMComponentMLibrary& rst
		) {
	return 0;
};

ubigint TblWdbeRMComponentMLibrary::insertRec(
			WdbeRMComponentMLibrary* rec
		) {
	return 0;
};

ubigint TblWdbeRMComponentMLibrary::insertNewRec(
			WdbeRMComponentMLibrary** rec
			, const ubigint refWdbeMComponent
			, const ubigint refWdbeMLibrary
		) {
	ubigint retval = 0;
	WdbeRMComponentMLibrary* _rec = NULL;

	_rec = new WdbeRMComponentMLibrary(0, refWdbeMComponent, refWdbeMLibrary);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeRMComponentMLibrary::appendNewRecToRst(
			ListWdbeRMComponentMLibrary& rst
			, WdbeRMComponentMLibrary** rec
			, const ubigint refWdbeMComponent
			, const ubigint refWdbeMLibrary
		) {
	ubigint retval = 0;
	WdbeRMComponentMLibrary* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMComponent, refWdbeMLibrary);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeRMComponentMLibrary::insertRst(
			ListWdbeRMComponentMLibrary& rst
			, bool transact
		) {
};

void TblWdbeRMComponentMLibrary::updateRec(
			WdbeRMComponentMLibrary* rec
		) {
};

void TblWdbeRMComponentMLibrary::updateRst(
			ListWdbeRMComponentMLibrary& rst
			, bool transact
		) {
};

void TblWdbeRMComponentMLibrary::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeRMComponentMLibrary::loadRecByRef(
			ubigint ref
			, WdbeRMComponentMLibrary** rec
		) {
	return false;
};

ubigint TblWdbeRMComponentMLibrary::loadCmpsByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, vector<ubigint>& refWdbeMComponents
		) {
	return 0;
};

ubigint TblWdbeRMComponentMLibrary::loadLibsByCmp(
			ubigint refWdbeMComponent
			, const bool append
			, vector<ubigint>& refWdbeMLibrarys
		) {
	return 0;
};

ubigint TblWdbeRMComponentMLibrary::loadRefsByCmp(
			ubigint refWdbeMComponent
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeRMComponentMLibrary::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeRMComponentMLibrary& rst
		) {
	ubigint numload = 0;
	WdbeRMComponentMLibrary* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeRMComponentMLibrary
 ******************************************************************************/

MyTblWdbeRMComponentMLibrary::MyTblWdbeRMComponentMLibrary() :
			TblWdbeRMComponentMLibrary()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeRMComponentMLibrary::~MyTblWdbeRMComponentMLibrary() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeRMComponentMLibrary::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeRMComponentMLibrary (refWdbeMComponent, refWdbeMLibrary) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeRMComponentMLibrary SET refWdbeMComponent = ?, refWdbeMLibrary = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeRMComponentMLibrary WHERE ref = ?", false);
};

bool MyTblWdbeRMComponentMLibrary::loadRecBySQL(
			const string& sqlstr
			, WdbeRMComponentMLibrary** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeRMComponentMLibrary* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMComponentMLibrary::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMComponentMLibrary::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeRMComponentMLibrary();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMComponent = atoll((char*) dbrow[1]); else _rec->refWdbeMComponent = 0;
		if (dbrow[2]) _rec->refWdbeMLibrary = atoll((char*) dbrow[2]); else _rec->refWdbeMLibrary = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeRMComponentMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMComponentMLibrary& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeRMComponentMLibrary* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMComponentMLibrary::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMComponentMLibrary::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeRMComponentMLibrary();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMComponent = atoll((char*) dbrow[1]); else rec->refWdbeMComponent = 0;
			if (dbrow[2]) rec->refWdbeMLibrary = atoll((char*) dbrow[2]); else rec->refWdbeMLibrary = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeRMComponentMLibrary::insertRec(
			WdbeRMComponentMLibrary* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMComponent,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMLibrary,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeRMComponentMLibrary::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeRMComponentMLibrary::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeRMComponentMLibrary::insertRst(
			ListWdbeRMComponentMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeRMComponentMLibrary::updateRec(
			WdbeRMComponentMLibrary* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMComponent,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMLibrary,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeRMComponentMLibrary::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeRMComponentMLibrary::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeRMComponentMLibrary::updateRst(
			ListWdbeRMComponentMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeRMComponentMLibrary::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeRMComponentMLibrary::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeRMComponentMLibrary::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeRMComponentMLibrary::loadRecByRef(
			ubigint ref
			, WdbeRMComponentMLibrary** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeRMComponentMLibrary WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeRMComponentMLibrary::loadCmpsByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, vector<ubigint>& refWdbeMComponents
		) {
	return loadRefsBySQL("SELECT refWdbeMComponent FROM TblWdbeRMComponentMLibrary WHERE refWdbeMLibrary = " + to_string(refWdbeMLibrary) + "", append, refWdbeMComponents);
};

ubigint MyTblWdbeRMComponentMLibrary::loadLibsByCmp(
			ubigint refWdbeMComponent
			, const bool append
			, vector<ubigint>& refWdbeMLibrarys
		) {
	return loadRefsBySQL("SELECT refWdbeMLibrary FROM TblWdbeRMComponentMLibrary WHERE refWdbeMComponent = " + to_string(refWdbeMComponent) + "", append, refWdbeMLibrarys);
};

ubigint MyTblWdbeRMComponentMLibrary::loadRefsByCmp(
			ubigint refWdbeMComponent
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeRMComponentMLibrary WHERE refWdbeMComponent = " + to_string(refWdbeMComponent) + "", append, refs);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeRMComponentMLibrary
 ******************************************************************************/

PgTblWdbeRMComponentMLibrary::PgTblWdbeRMComponentMLibrary() :
			TblWdbeRMComponentMLibrary()
			, PgTable()
		{
};

PgTblWdbeRMComponentMLibrary::~PgTblWdbeRMComponentMLibrary() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeRMComponentMLibrary::initStatements() {
	createStatement("TblWdbeRMComponentMLibrary_insertRec", "INSERT INTO TblWdbeRMComponentMLibrary (refWdbeMComponent, refWdbeMLibrary) VALUES ($1,$2) RETURNING ref", 2);
	createStatement("TblWdbeRMComponentMLibrary_updateRec", "UPDATE TblWdbeRMComponentMLibrary SET refWdbeMComponent = $1, refWdbeMLibrary = $2 WHERE ref = $3", 3);
	createStatement("TblWdbeRMComponentMLibrary_removeRecByRef", "DELETE FROM TblWdbeRMComponentMLibrary WHERE ref = $1", 1);

	createStatement("TblWdbeRMComponentMLibrary_loadRecByRef", "SELECT ref, refWdbeMComponent, refWdbeMLibrary FROM TblWdbeRMComponentMLibrary WHERE ref = $1", 1);
	createStatement("TblWdbeRMComponentMLibrary_loadCmpsByLib", "SELECT refWdbeMComponent FROM TblWdbeRMComponentMLibrary WHERE refWdbeMLibrary = $1", 1);
	createStatement("TblWdbeRMComponentMLibrary_loadLibsByCmp", "SELECT refWdbeMLibrary FROM TblWdbeRMComponentMLibrary WHERE refWdbeMComponent = $1", 1);
	createStatement("TblWdbeRMComponentMLibrary_loadRefsByCmp", "SELECT ref FROM TblWdbeRMComponentMLibrary WHERE refWdbeMComponent = $1", 1);
};

bool PgTblWdbeRMComponentMLibrary::loadRec(
			PGresult* res
			, WdbeRMComponentMLibrary** rec
		) {
	char* ptr;

	WdbeRMComponentMLibrary* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeRMComponentMLibrary();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemcomponent"),
			PQfnumber(res, "refwdbemlibrary")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMComponent = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMLibrary = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeRMComponentMLibrary::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeRMComponentMLibrary& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeRMComponentMLibrary* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemcomponent"),
			PQfnumber(res, "refwdbemlibrary")
		};

		while (numread < numrow) {
			rec = new WdbeRMComponentMLibrary();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMComponent = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMLibrary = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeRMComponentMLibrary::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeRMComponentMLibrary** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMComponentMLibrary::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeRMComponentMLibrary::loadRecBySQL(
			const string& sqlstr
			, WdbeRMComponentMLibrary** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMComponentMLibrary::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMComponentMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMComponentMLibrary& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMComponentMLibrary::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeRMComponentMLibrary::insertRec(
			WdbeRMComponentMLibrary* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMComponent = htonl64(rec->refWdbeMComponent);
	ubigint _refWdbeMLibrary = htonl64(rec->refWdbeMLibrary);

	const char* vals[] = {
		(char*) &_refWdbeMComponent,
		(char*) &_refWdbeMLibrary
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMComponentMLibrary_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMComponentMLibrary::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeRMComponentMLibrary::insertRst(
			ListWdbeRMComponentMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeRMComponentMLibrary::updateRec(
			WdbeRMComponentMLibrary* rec
		) {
	PGresult* res;

	ubigint _refWdbeMComponent = htonl64(rec->refWdbeMComponent);
	ubigint _refWdbeMLibrary = htonl64(rec->refWdbeMLibrary);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMComponent,
		(char*) &_refWdbeMLibrary,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMComponentMLibrary_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMComponentMLibrary::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeRMComponentMLibrary::updateRst(
			ListWdbeRMComponentMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeRMComponentMLibrary::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeRMComponentMLibrary_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMComponentMLibrary::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeRMComponentMLibrary::loadRecByRef(
			ubigint ref
			, WdbeRMComponentMLibrary** rec
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

	return loadRecByStmt("TblWdbeRMComponentMLibrary_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeRMComponentMLibrary::loadCmpsByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, vector<ubigint>& refWdbeMComponents
		) {
	ubigint _refWdbeMLibrary = htonl64(refWdbeMLibrary);

	const char* vals[] = {
		(char*) &_refWdbeMLibrary
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMComponentMLibrary_loadCmpsByLib", 1, vals, l, f, append, refWdbeMComponents);
};

ubigint PgTblWdbeRMComponentMLibrary::loadLibsByCmp(
			ubigint refWdbeMComponent
			, const bool append
			, vector<ubigint>& refWdbeMLibrarys
		) {
	ubigint _refWdbeMComponent = htonl64(refWdbeMComponent);

	const char* vals[] = {
		(char*) &_refWdbeMComponent
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMComponentMLibrary_loadLibsByCmp", 1, vals, l, f, append, refWdbeMLibrarys);
};

ubigint PgTblWdbeRMComponentMLibrary::loadRefsByCmp(
			ubigint refWdbeMComponent
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMComponent = htonl64(refWdbeMComponent);

	const char* vals[] = {
		(char*) &_refWdbeMComponent
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMComponentMLibrary_loadRefsByCmp", 1, vals, l, f, append, refs);
};

#endif
