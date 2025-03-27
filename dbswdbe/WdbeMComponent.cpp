/**
	* \file WdbeMComponent.cpp
	* database access for table TblWdbeMComponent (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
  */
// IP header --- ABOVE

#include "WdbeMComponent.h"

#include "WdbeMComponent_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMComponent
 ******************************************************************************/

WdbeMComponent::WdbeMComponent(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWdbeMVersion
			, const string sref
			, const string Comment
		) :
			ref(ref)
			, ixVBasetype(ixVBasetype)
			, refWdbeMVersion(refWdbeMVersion)
			, sref(sref)
			, Comment(Comment)
		{
};

bool WdbeMComponent::operator==(
			const WdbeMComponent& comp
		) {
	return false;
};

bool WdbeMComponent::operator!=(
			const WdbeMComponent& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMComponent
 ******************************************************************************/

ListWdbeMComponent::ListWdbeMComponent() {
};

ListWdbeMComponent::ListWdbeMComponent(
			const ListWdbeMComponent& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMComponent(*(src.nodes[i]));
};

ListWdbeMComponent::~ListWdbeMComponent() {
	clear();
};

void ListWdbeMComponent::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMComponent::size() const {
	return(nodes.size());
};

void ListWdbeMComponent::append(
			WdbeMComponent* rec
		) {
	nodes.push_back(rec);
};

WdbeMComponent* ListWdbeMComponent::operator[](
			const uint ix
		) {
	WdbeMComponent* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMComponent& ListWdbeMComponent::operator=(
			const ListWdbeMComponent& src
		) {
	WdbeMComponent* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMComponent(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMComponent::operator==(
			const ListWdbeMComponent& comp
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

bool ListWdbeMComponent::operator!=(
			const ListWdbeMComponent& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMComponent
 ******************************************************************************/

TblWdbeMComponent::TblWdbeMComponent() {
};

TblWdbeMComponent::~TblWdbeMComponent() {
};

bool TblWdbeMComponent::loadRecBySQL(
			const string& sqlstr
			, WdbeMComponent** rec
		) {
	return false;
};

ubigint TblWdbeMComponent::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMComponent& rst
		) {
	return 0;
};

ubigint TblWdbeMComponent::insertRec(
			WdbeMComponent* rec
		) {
	return 0;
};

ubigint TblWdbeMComponent::insertNewRec(
			WdbeMComponent** rec
			, const uint ixVBasetype
			, const ubigint refWdbeMVersion
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMComponent* _rec = NULL;

	_rec = new WdbeMComponent(0, ixVBasetype, refWdbeMVersion, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMComponent::appendNewRecToRst(
			ListWdbeMComponent& rst
			, WdbeMComponent** rec
			, const uint ixVBasetype
			, const ubigint refWdbeMVersion
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMComponent* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWdbeMVersion, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMComponent::insertRst(
			ListWdbeMComponent& rst
			, bool transact
		) {
};

void TblWdbeMComponent::updateRec(
			WdbeMComponent* rec
		) {
};

void TblWdbeMComponent::updateRst(
			ListWdbeMComponent& rst
			, bool transact
		) {
};

void TblWdbeMComponent::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMComponent::loadRecByRef(
			ubigint ref
			, WdbeMComponent** rec
		) {
	return false;
};

ubigint TblWdbeMComponent::loadRstByVer(
			ubigint refWdbeMVersion
			, const bool append
			, ListWdbeMComponent& rst
		) {
	return 0;
};

bool TblWdbeMComponent::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMComponent::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMComponent& rst
		) {
	ubigint numload = 0;
	WdbeMComponent* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMComponent
 ******************************************************************************/

MyTblWdbeMComponent::MyTblWdbeMComponent() :
			TblWdbeMComponent()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMComponent::~MyTblWdbeMComponent() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMComponent::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMComponent (ixVBasetype, refWdbeMVersion, sref, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMComponent SET ixVBasetype = ?, refWdbeMVersion = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMComponent WHERE ref = ?", false);
};

bool MyTblWdbeMComponent::loadRecBySQL(
			const string& sqlstr
			, WdbeMComponent** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMComponent* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMComponent::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMComponent::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMComponent();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWdbeMVersion = atoll((char*) dbrow[2]); else _rec->refWdbeMVersion = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMComponent::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMComponent& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMComponent* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMComponent::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMComponent::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMComponent();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWdbeMVersion = atoll((char*) dbrow[2]); else rec->refWdbeMVersion = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMComponent::insertRec(
			WdbeMComponent* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMComponent::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMComponent::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMComponent::insertRst(
			ListWdbeMComponent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMComponent::updateRec(
			WdbeMComponent* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMVersion,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMComponent::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMComponent::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMComponent::updateRst(
			ListWdbeMComponent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMComponent::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMComponent::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMComponent::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMComponent::loadRecByRef(
			ubigint ref
			, WdbeMComponent** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMComponent WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMComponent::loadRstByVer(
			ubigint refWdbeMVersion
			, const bool append
			, ListWdbeMComponent& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWdbeMVersion, sref, Comment FROM TblWdbeMComponent WHERE refWdbeMVersion = " + to_string(refWdbeMVersion) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMComponent::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMComponent WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMComponent
 ******************************************************************************/

PgTblWdbeMComponent::PgTblWdbeMComponent() :
			TblWdbeMComponent()
			, PgTable()
		{
};

PgTblWdbeMComponent::~PgTblWdbeMComponent() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMComponent::initStatements() {
	createStatement("TblWdbeMComponent_insertRec", "INSERT INTO TblWdbeMComponent (ixVBasetype, refWdbeMVersion, sref, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeMComponent_updateRec", "UPDATE TblWdbeMComponent SET ixVBasetype = $1, refWdbeMVersion = $2, sref = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeMComponent_removeRecByRef", "DELETE FROM TblWdbeMComponent WHERE ref = $1", 1);

	createStatement("TblWdbeMComponent_loadRecByRef", "SELECT ref, ixVBasetype, refWdbeMVersion, sref, Comment FROM TblWdbeMComponent WHERE ref = $1", 1);
	createStatement("TblWdbeMComponent_loadRstByVer", "SELECT ref, ixVBasetype, refWdbeMVersion, sref, Comment FROM TblWdbeMComponent WHERE refWdbeMVersion = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMComponent_loadSrfByRef", "SELECT sref FROM TblWdbeMComponent WHERE ref = $1", 1);
};

bool PgTblWdbeMComponent::loadRec(
			PGresult* res
			, WdbeMComponent** rec
		) {
	char* ptr;

	WdbeMComponent* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMComponent();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwdbemversion"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMComponent::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMComponent& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMComponent* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwdbemversion"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMComponent();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMComponent::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMComponent** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMComponent::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMComponent::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMComponent& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMComponent::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMComponent::loadRecBySQL(
			const string& sqlstr
			, WdbeMComponent** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMComponent::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMComponent::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMComponent& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMComponent::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMComponent::insertRec(
			WdbeMComponent* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWdbeMVersion,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMComponent_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMComponent::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMComponent::insertRst(
			ListWdbeMComponent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMComponent::updateRec(
			WdbeMComponent* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWdbeMVersion,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMComponent_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMComponent::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMComponent::updateRst(
			ListWdbeMComponent& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMComponent::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMComponent_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMComponent::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMComponent::loadRecByRef(
			ubigint ref
			, WdbeMComponent** rec
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

	return loadRecByStmt("TblWdbeMComponent_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMComponent::loadRstByVer(
			ubigint refWdbeMVersion
			, const bool append
			, ListWdbeMComponent& rst
		) {
	ubigint _refWdbeMVersion = htonl64(refWdbeMVersion);

	const char* vals[] = {
		(char*) &_refWdbeMVersion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMComponent_loadRstByVer", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMComponent::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMComponent_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
