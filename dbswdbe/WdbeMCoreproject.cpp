/**
	* \file WdbeMCoreproject.cpp
	* database access for table TblWdbeMCoreproject (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMCoreproject.h"

#include "WdbeMCoreproject_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMCoreproject
 ******************************************************************************/

WdbeMCoreproject::WdbeMCoreproject(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint refWdbeMCoreversion
			, const string sref
			, const string Title
			, const string Giturl
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->ixVBasetype = ixVBasetype;
	this->refWdbeMCoreversion = refWdbeMCoreversion;
	this->sref = sref;
	this->Title = Title;
	this->Giturl = Giturl;
	this->Comment = Comment;
};

bool WdbeMCoreproject::operator==(
			const WdbeMCoreproject& comp
		) {
	return false;
};

bool WdbeMCoreproject::operator!=(
			const WdbeMCoreproject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMCoreproject
 ******************************************************************************/

ListWdbeMCoreproject::ListWdbeMCoreproject() {
};

ListWdbeMCoreproject::ListWdbeMCoreproject(
			const ListWdbeMCoreproject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMCoreproject(*(src.nodes[i]));
};

ListWdbeMCoreproject::~ListWdbeMCoreproject() {
	clear();
};

void ListWdbeMCoreproject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMCoreproject::size() const {
	return(nodes.size());
};

void ListWdbeMCoreproject::append(
			WdbeMCoreproject* rec
		) {
	nodes.push_back(rec);
};

WdbeMCoreproject* ListWdbeMCoreproject::operator[](
			const uint ix
		) {
	WdbeMCoreproject* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMCoreproject& ListWdbeMCoreproject::operator=(
			const ListWdbeMCoreproject& src
		) {
	WdbeMCoreproject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMCoreproject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMCoreproject::operator==(
			const ListWdbeMCoreproject& comp
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

bool ListWdbeMCoreproject::operator!=(
			const ListWdbeMCoreproject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMCoreproject
 ******************************************************************************/

TblWdbeMCoreproject::TblWdbeMCoreproject() {
};

TblWdbeMCoreproject::~TblWdbeMCoreproject() {
};

bool TblWdbeMCoreproject::loadRecBySQL(
			const string& sqlstr
			, WdbeMCoreproject** rec
		) {
	return false;
};

ubigint TblWdbeMCoreproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCoreproject& rst
		) {
	return 0;
};

ubigint TblWdbeMCoreproject::insertRec(
			WdbeMCoreproject* rec
		) {
	return 0;
};

ubigint TblWdbeMCoreproject::insertNewRec(
			WdbeMCoreproject** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint refWdbeMCoreversion
			, const string sref
			, const string Title
			, const string Giturl
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMCoreproject* _rec = NULL;

	_rec = new WdbeMCoreproject(0, grp, own, ixVBasetype, refWdbeMCoreversion, sref, Title, Giturl, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMCoreproject::appendNewRecToRst(
			ListWdbeMCoreproject& rst
			, WdbeMCoreproject** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint refWdbeMCoreversion
			, const string sref
			, const string Title
			, const string Giturl
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMCoreproject* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, ixVBasetype, refWdbeMCoreversion, sref, Title, Giturl, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMCoreproject::insertRst(
			ListWdbeMCoreproject& rst
			, bool transact
		) {
};

void TblWdbeMCoreproject::updateRec(
			WdbeMCoreproject* rec
		) {
};

void TblWdbeMCoreproject::updateRst(
			ListWdbeMCoreproject& rst
			, bool transact
		) {
};

void TblWdbeMCoreproject::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMCoreproject::loadRecByRef(
			ubigint ref
			, WdbeMCoreproject** rec
		) {
	return false;
};

bool TblWdbeMCoreproject::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblWdbeMCoreproject::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMCoreproject& rst
		) {
	ubigint numload = 0;
	WdbeMCoreproject* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMCoreproject
 ******************************************************************************/

MyTblWdbeMCoreproject::MyTblWdbeMCoreproject() :
			TblWdbeMCoreproject()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMCoreproject::~MyTblWdbeMCoreproject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMCoreproject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMCoreproject (grp, own, ixVBasetype, refWdbeMCoreversion, sref, Title, Giturl, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMCoreproject SET grp = ?, own = ?, ixVBasetype = ?, refWdbeMCoreversion = ?, sref = ?, Title = ?, Giturl = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMCoreproject WHERE ref = ?", false);
};

bool MyTblWdbeMCoreproject::loadRecBySQL(
			const string& sqlstr
			, WdbeMCoreproject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMCoreproject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMCoreproject::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMCoreproject::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMCoreproject();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->ixVBasetype = atol((char*) dbrow[3]); else _rec->ixVBasetype = 0;
		if (dbrow[4]) _rec->refWdbeMCoreversion = atoll((char*) dbrow[4]); else _rec->refWdbeMCoreversion = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";
		if (dbrow[7]) _rec->Giturl.assign(dbrow[7], dblengths[7]); else _rec->Giturl = "";
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMCoreproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCoreproject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMCoreproject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMCoreproject::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMCoreproject::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMCoreproject();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->ixVBasetype = atol((char*) dbrow[3]); else rec->ixVBasetype = 0;
			if (dbrow[4]) rec->refWdbeMCoreversion = atoll((char*) dbrow[4]); else rec->refWdbeMCoreversion = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			if (dbrow[7]) rec->Giturl.assign(dbrow[7], dblengths[7]); else rec->Giturl = "";
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMCoreproject::insertRec(
			WdbeMCoreproject* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->sref.length();
	l[5] = rec->Title.length();
	l[6] = rec->Giturl.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWdbeMCoreversion,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Giturl.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMCoreproject::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMCoreproject::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMCoreproject::insertRst(
			ListWdbeMCoreproject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMCoreproject::updateRec(
			WdbeMCoreproject* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	l[5] = rec->Title.length();
	l[6] = rec->Giturl.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWdbeMCoreversion,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Giturl.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMCoreproject::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMCoreproject::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMCoreproject::updateRst(
			ListWdbeMCoreproject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMCoreproject::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMCoreproject::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMCoreproject::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMCoreproject::loadRecByRef(
			ubigint ref
			, WdbeMCoreproject** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMCoreproject WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMCoreproject::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWdbeMCoreproject WHERE ref = " + to_string(ref) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMCoreproject
 ******************************************************************************/

PgTblWdbeMCoreproject::PgTblWdbeMCoreproject() :
			TblWdbeMCoreproject()
			, PgTable()
		{
};

PgTblWdbeMCoreproject::~PgTblWdbeMCoreproject() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMCoreproject::initStatements() {
	createStatement("TblWdbeMCoreproject_insertRec", "INSERT INTO TblWdbeMCoreproject (grp, own, ixVBasetype, refWdbeMCoreversion, sref, Title, Giturl, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWdbeMCoreproject_updateRec", "UPDATE TblWdbeMCoreproject SET grp = $1, own = $2, ixVBasetype = $3, refWdbeMCoreversion = $4, sref = $5, Title = $6, Giturl = $7, Comment = $8 WHERE ref = $9", 9);
	createStatement("TblWdbeMCoreproject_removeRecByRef", "DELETE FROM TblWdbeMCoreproject WHERE ref = $1", 1);

	createStatement("TblWdbeMCoreproject_loadRecByRef", "SELECT ref, grp, own, ixVBasetype, refWdbeMCoreversion, sref, Title, Giturl, Comment FROM TblWdbeMCoreproject WHERE ref = $1", 1);
	createStatement("TblWdbeMCoreproject_loadTitByRef", "SELECT Title FROM TblWdbeMCoreproject WHERE ref = $1", 1);
};

bool PgTblWdbeMCoreproject::loadRec(
			PGresult* res
			, WdbeMCoreproject** rec
		) {
	char* ptr;

	WdbeMCoreproject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMCoreproject();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwdbemcoreversion"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "giturl"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWdbeMCoreversion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Giturl.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMCoreproject::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMCoreproject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMCoreproject* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwdbemcoreversion"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "giturl"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMCoreproject();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWdbeMCoreversion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Giturl.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMCoreproject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMCoreproject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCoreproject::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeMCoreproject::loadRecBySQL(
			const string& sqlstr
			, WdbeMCoreproject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCoreproject::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMCoreproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCoreproject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCoreproject::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMCoreproject::insertRec(
			WdbeMCoreproject* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWdbeMCoreversion = htonl64(rec->refWdbeMCoreversion);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		(char*) &_refWdbeMCoreversion,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Giturl.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMCoreproject_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCoreproject::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMCoreproject::insertRst(
			ListWdbeMCoreproject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMCoreproject::updateRec(
			WdbeMCoreproject* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWdbeMCoreversion = htonl64(rec->refWdbeMCoreversion);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		(char*) &_refWdbeMCoreversion,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Giturl.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMCoreproject_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMCoreproject::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMCoreproject::updateRst(
			ListWdbeMCoreproject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMCoreproject::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMCoreproject_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMCoreproject::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMCoreproject::loadRecByRef(
			ubigint ref
			, WdbeMCoreproject** rec
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

	return loadRecByStmt("TblWdbeMCoreproject_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMCoreproject::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMCoreproject_loadTitByRef", 1, vals, l, f, Title);
};

#endif

