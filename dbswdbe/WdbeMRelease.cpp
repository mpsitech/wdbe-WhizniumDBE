/**
	* \file WdbeMRelease.cpp
	* database access for table TblWdbeMRelease (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMRelease.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMRelease
 ******************************************************************************/

WdbeMRelease::WdbeMRelease(
			const ubigint ref
			, const ubigint refWdbeMComponent
			, const ubigint refWdbeMMachine
			, const string sref
			, const string srefsKOption
			, const string Comment
		) {

	this->ref = ref;
	this->refWdbeMComponent = refWdbeMComponent;
	this->refWdbeMMachine = refWdbeMMachine;
	this->sref = sref;
	this->srefsKOption = srefsKOption;
	this->Comment = Comment;
};

bool WdbeMRelease::operator==(
			const WdbeMRelease& comp
		) {
	return false;
};

bool WdbeMRelease::operator!=(
			const WdbeMRelease& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMRelease
 ******************************************************************************/

ListWdbeMRelease::ListWdbeMRelease() {
};

ListWdbeMRelease::ListWdbeMRelease(
			const ListWdbeMRelease& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMRelease(*(src.nodes[i]));
};

ListWdbeMRelease::~ListWdbeMRelease() {
	clear();
};

void ListWdbeMRelease::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMRelease::size() const {
	return(nodes.size());
};

void ListWdbeMRelease::append(
			WdbeMRelease* rec
		) {
	nodes.push_back(rec);
};

WdbeMRelease* ListWdbeMRelease::operator[](
			const uint ix
		) {
	WdbeMRelease* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMRelease& ListWdbeMRelease::operator=(
			const ListWdbeMRelease& src
		) {
	WdbeMRelease* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMRelease(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMRelease::operator==(
			const ListWdbeMRelease& comp
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

bool ListWdbeMRelease::operator!=(
			const ListWdbeMRelease& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMRelease
 ******************************************************************************/

TblWdbeMRelease::TblWdbeMRelease() {
};

TblWdbeMRelease::~TblWdbeMRelease() {
};

bool TblWdbeMRelease::loadRecBySQL(
			const string& sqlstr
			, WdbeMRelease** rec
		) {
	return false;
};

ubigint TblWdbeMRelease::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMRelease& rst
		) {
	return 0;
};

ubigint TblWdbeMRelease::insertRec(
			WdbeMRelease* rec
		) {
	return 0;
};

ubigint TblWdbeMRelease::insertNewRec(
			WdbeMRelease** rec
			, const ubigint refWdbeMComponent
			, const ubigint refWdbeMMachine
			, const string sref
			, const string srefsKOption
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMRelease* _rec = NULL;

	_rec = new WdbeMRelease(0, refWdbeMComponent, refWdbeMMachine, sref, srefsKOption, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMRelease::appendNewRecToRst(
			ListWdbeMRelease& rst
			, WdbeMRelease** rec
			, const ubigint refWdbeMComponent
			, const ubigint refWdbeMMachine
			, const string sref
			, const string srefsKOption
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMRelease* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMComponent, refWdbeMMachine, sref, srefsKOption, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMRelease::insertRst(
			ListWdbeMRelease& rst
			, bool transact
		) {
};

void TblWdbeMRelease::updateRec(
			WdbeMRelease* rec
		) {
};

void TblWdbeMRelease::updateRst(
			ListWdbeMRelease& rst
			, bool transact
		) {
};

void TblWdbeMRelease::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMRelease::loadRecByRef(
			ubigint ref
			, WdbeMRelease** rec
		) {
	return false;
};

ubigint TblWdbeMRelease::loadRefsByCmp(
			ubigint refWdbeMComponent
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMRelease::loadRstByCmp(
			ubigint refWdbeMComponent
			, const bool append
			, ListWdbeMRelease& rst
		) {
	return 0;
};

bool TblWdbeMRelease::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMRelease::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMRelease& rst
		) {
	ubigint numload = 0;
	WdbeMRelease* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMRelease
 ******************************************************************************/

MyTblWdbeMRelease::MyTblWdbeMRelease() :
			TblWdbeMRelease()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMRelease::~MyTblWdbeMRelease() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMRelease::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMRelease (refWdbeMComponent, refWdbeMMachine, sref, srefsKOption, Comment) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMRelease SET refWdbeMComponent = ?, refWdbeMMachine = ?, sref = ?, srefsKOption = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMRelease WHERE ref = ?", false);
};

bool MyTblWdbeMRelease::loadRecBySQL(
			const string& sqlstr
			, WdbeMRelease** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMRelease* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMRelease::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMRelease::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMRelease();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMComponent = atoll((char*) dbrow[1]); else _rec->refWdbeMComponent = 0;
		if (dbrow[2]) _rec->refWdbeMMachine = atoll((char*) dbrow[2]); else _rec->refWdbeMMachine = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->srefsKOption.assign(dbrow[4], dblengths[4]); else _rec->srefsKOption = "";
		if (dbrow[5]) _rec->Comment.assign(dbrow[5], dblengths[5]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMRelease::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMRelease& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMRelease* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMRelease::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMRelease::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMRelease();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMComponent = atoll((char*) dbrow[1]); else rec->refWdbeMComponent = 0;
			if (dbrow[2]) rec->refWdbeMMachine = atoll((char*) dbrow[2]); else rec->refWdbeMMachine = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->srefsKOption.assign(dbrow[4], dblengths[4]); else rec->srefsKOption = "";
			if (dbrow[5]) rec->Comment.assign(dbrow[5], dblengths[5]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMRelease::insertRec(
			WdbeMRelease* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->srefsKOption.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMComponent,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMMachine,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMRelease::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMRelease::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMRelease::insertRst(
			ListWdbeMRelease& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMRelease::updateRec(
			WdbeMRelease* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->sref.length();
	l[3] = rec->srefsKOption.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMComponent,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMMachine,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->srefsKOption.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMRelease::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMRelease::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMRelease::updateRst(
			ListWdbeMRelease& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMRelease::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMRelease::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMRelease::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMRelease::loadRecByRef(
			ubigint ref
			, WdbeMRelease** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMRelease WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMRelease::loadRefsByCmp(
			ubigint refWdbeMComponent
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMRelease WHERE refWdbeMComponent = " + to_string(refWdbeMComponent) + "", append, refs);
};

ubigint MyTblWdbeMRelease::loadRstByCmp(
			ubigint refWdbeMComponent
			, const bool append
			, ListWdbeMRelease& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMComponent, refWdbeMMachine, sref, srefsKOption, Comment FROM TblWdbeMRelease WHERE refWdbeMComponent = " + to_string(refWdbeMComponent) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMRelease::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMRelease WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMRelease
 ******************************************************************************/

PgTblWdbeMRelease::PgTblWdbeMRelease() :
			TblWdbeMRelease()
			, PgTable()
		{
};

PgTblWdbeMRelease::~PgTblWdbeMRelease() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMRelease::initStatements() {
	createStatement("TblWdbeMRelease_insertRec", "INSERT INTO TblWdbeMRelease (refWdbeMComponent, refWdbeMMachine, sref, srefsKOption, Comment) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWdbeMRelease_updateRec", "UPDATE TblWdbeMRelease SET refWdbeMComponent = $1, refWdbeMMachine = $2, sref = $3, srefsKOption = $4, Comment = $5 WHERE ref = $6", 6);
	createStatement("TblWdbeMRelease_removeRecByRef", "DELETE FROM TblWdbeMRelease WHERE ref = $1", 1);

	createStatement("TblWdbeMRelease_loadRecByRef", "SELECT ref, refWdbeMComponent, refWdbeMMachine, sref, srefsKOption, Comment FROM TblWdbeMRelease WHERE ref = $1", 1);
	createStatement("TblWdbeMRelease_loadRefsByCmp", "SELECT ref FROM TblWdbeMRelease WHERE refWdbeMComponent = $1", 1);
	createStatement("TblWdbeMRelease_loadRstByCmp", "SELECT ref, refWdbeMComponent, refWdbeMMachine, sref, srefsKOption, Comment FROM TblWdbeMRelease WHERE refWdbeMComponent = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMRelease_loadSrfByRef", "SELECT sref FROM TblWdbeMRelease WHERE ref = $1", 1);
};

bool PgTblWdbeMRelease::loadRec(
			PGresult* res
			, WdbeMRelease** rec
		) {
	char* ptr;

	WdbeMRelease* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMRelease();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemcomponent"),
			PQfnumber(res, "refwdbemmachine"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefskoption"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMComponent = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->srefsKOption.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMRelease::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMRelease& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMRelease* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemcomponent"),
			PQfnumber(res, "refwdbemmachine"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefskoption"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMRelease();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMComponent = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->srefsKOption.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMRelease::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMRelease** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMRelease::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMRelease::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMRelease& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMRelease::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMRelease::loadRecBySQL(
			const string& sqlstr
			, WdbeMRelease** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMRelease::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMRelease::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMRelease& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMRelease::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMRelease::insertRec(
			WdbeMRelease* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMComponent = htonl64(rec->refWdbeMComponent);
	ubigint _refWdbeMMachine = htonl64(rec->refWdbeMMachine);

	const char* vals[] = {
		(char*) &_refWdbeMComponent,
		(char*) &_refWdbeMMachine,
		rec->sref.c_str(),
		rec->srefsKOption.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMRelease_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMRelease::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMRelease::insertRst(
			ListWdbeMRelease& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMRelease::updateRec(
			WdbeMRelease* rec
		) {
	PGresult* res;

	ubigint _refWdbeMComponent = htonl64(rec->refWdbeMComponent);
	ubigint _refWdbeMMachine = htonl64(rec->refWdbeMMachine);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMComponent,
		(char*) &_refWdbeMMachine,
		rec->sref.c_str(),
		rec->srefsKOption.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMRelease_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMRelease::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMRelease::updateRst(
			ListWdbeMRelease& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMRelease::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMRelease_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMRelease::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMRelease::loadRecByRef(
			ubigint ref
			, WdbeMRelease** rec
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

	return loadRecByStmt("TblWdbeMRelease_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMRelease::loadRefsByCmp(
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

	return loadRefsByStmt("TblWdbeMRelease_loadRefsByCmp", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMRelease::loadRstByCmp(
			ubigint refWdbeMComponent
			, const bool append
			, ListWdbeMRelease& rst
		) {
	ubigint _refWdbeMComponent = htonl64(refWdbeMComponent);

	const char* vals[] = {
		(char*) &_refWdbeMComponent
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMRelease_loadRstByCmp", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMRelease::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMRelease_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
