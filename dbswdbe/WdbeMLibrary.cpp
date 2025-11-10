/**
	* \file WdbeMLibrary.cpp
	* database access for table TblWdbeMLibrary (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMLibrary.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMLibrary
 ******************************************************************************/

WdbeMLibrary::WdbeMLibrary(
			const ubigint ref
			, const string sref
			, const string Title
			, const string Version
			, const string depSrefsWdbeMLibrary
			, const string Comment
		) :
			ref(ref)
			, sref(sref)
			, Title(Title)
			, Version(Version)
			, depSrefsWdbeMLibrary(depSrefsWdbeMLibrary)
			, Comment(Comment)
		{
};

bool WdbeMLibrary::operator==(
			const WdbeMLibrary& comp
		) {
	return false;
};

bool WdbeMLibrary::operator!=(
			const WdbeMLibrary& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMLibrary
 ******************************************************************************/

ListWdbeMLibrary::ListWdbeMLibrary() {
};

ListWdbeMLibrary::ListWdbeMLibrary(
			const ListWdbeMLibrary& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMLibrary(*(src.nodes[i]));
};

ListWdbeMLibrary::~ListWdbeMLibrary() {
	clear();
};

void ListWdbeMLibrary::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMLibrary::size() const {
	return(nodes.size());
};

void ListWdbeMLibrary::append(
			WdbeMLibrary* rec
		) {
	nodes.push_back(rec);
};

WdbeMLibrary* ListWdbeMLibrary::operator[](
			const uint ix
		) {
	WdbeMLibrary* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMLibrary& ListWdbeMLibrary::operator=(
			const ListWdbeMLibrary& src
		) {
	WdbeMLibrary* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMLibrary(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMLibrary::operator==(
			const ListWdbeMLibrary& comp
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

bool ListWdbeMLibrary::operator!=(
			const ListWdbeMLibrary& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMLibrary
 ******************************************************************************/

TblWdbeMLibrary::TblWdbeMLibrary() {
};

TblWdbeMLibrary::~TblWdbeMLibrary() {
};

bool TblWdbeMLibrary::loadRecBySQL(
			const string& sqlstr
			, WdbeMLibrary** rec
		) {
	return false;
};

ubigint TblWdbeMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMLibrary& rst
		) {
	return 0;
};

ubigint TblWdbeMLibrary::insertRec(
			WdbeMLibrary* rec
		) {
	return 0;
};

ubigint TblWdbeMLibrary::insertNewRec(
			WdbeMLibrary** rec
			, const string sref
			, const string Title
			, const string Version
			, const string depSrefsWdbeMLibrary
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMLibrary* _rec = NULL;

	_rec = new WdbeMLibrary(0, sref, Title, Version, depSrefsWdbeMLibrary, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMLibrary::appendNewRecToRst(
			ListWdbeMLibrary& rst
			, WdbeMLibrary** rec
			, const string sref
			, const string Title
			, const string Version
			, const string depSrefsWdbeMLibrary
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMLibrary* _rec = NULL;

	retval = insertNewRec(&_rec, sref, Title, Version, depSrefsWdbeMLibrary, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMLibrary::insertRst(
			ListWdbeMLibrary& rst
			, bool transact
		) {
};

void TblWdbeMLibrary::updateRec(
			WdbeMLibrary* rec
		) {
};

void TblWdbeMLibrary::updateRst(
			ListWdbeMLibrary& rst
			, bool transact
		) {
};

void TblWdbeMLibrary::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMLibrary::loadRecByRef(
			ubigint ref
			, WdbeMLibrary** rec
		) {
	return false;
};

bool TblWdbeMLibrary::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

bool TblWdbeMLibrary::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMLibrary::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMLibrary& rst
		) {
	ubigint numload = 0;
	WdbeMLibrary* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMLibrary
 ******************************************************************************/

MyTblWdbeMLibrary::MyTblWdbeMLibrary() :
			TblWdbeMLibrary()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMLibrary::~MyTblWdbeMLibrary() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMLibrary::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMLibrary (sref, Title, Version, depSrefsWdbeMLibrary, Comment) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMLibrary SET sref = ?, Title = ?, Version = ?, depSrefsWdbeMLibrary = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMLibrary WHERE ref = ?", false);
};

bool MyTblWdbeMLibrary::loadRecBySQL(
			const string& sqlstr
			, WdbeMLibrary** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMLibrary* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMLibrary::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMLibrary::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMLibrary();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->sref.assign(dbrow[1], dblengths[1]); else _rec->sref = "";
		if (dbrow[2]) _rec->Title.assign(dbrow[2], dblengths[2]); else _rec->Title = "";
		if (dbrow[3]) _rec->Version.assign(dbrow[3], dblengths[3]); else _rec->Version = "";
		if (dbrow[4]) _rec->depSrefsWdbeMLibrary.assign(dbrow[4], dblengths[4]); else _rec->depSrefsWdbeMLibrary = "";
		if (dbrow[5]) _rec->Comment.assign(dbrow[5], dblengths[5]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMLibrary& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMLibrary* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMLibrary::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMLibrary::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMLibrary();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->sref.assign(dbrow[1], dblengths[1]); else rec->sref = "";
			if (dbrow[2]) rec->Title.assign(dbrow[2], dblengths[2]); else rec->Title = "";
			if (dbrow[3]) rec->Version.assign(dbrow[3], dblengths[3]); else rec->Version = "";
			if (dbrow[4]) rec->depSrefsWdbeMLibrary.assign(dbrow[4], dblengths[4]); else rec->depSrefsWdbeMLibrary = "";
			if (dbrow[5]) rec->Comment.assign(dbrow[5], dblengths[5]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMLibrary::insertRec(
			WdbeMLibrary* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[0] = rec->sref.length();
	l[1] = rec->Title.length();
	l[2] = rec->Version.length();
	l[3] = rec->depSrefsWdbeMLibrary.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Title.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Version.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->depSrefsWdbeMLibrary.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMLibrary::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMLibrary::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMLibrary::insertRst(
			ListWdbeMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMLibrary::updateRec(
			WdbeMLibrary* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[0] = rec->sref.length();
	l[1] = rec->Title.length();
	l[2] = rec->Version.length();
	l[3] = rec->depSrefsWdbeMLibrary.length();
	l[4] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Title.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Version.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->depSrefsWdbeMLibrary.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMLibrary::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMLibrary::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMLibrary::updateRst(
			ListWdbeMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMLibrary::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMLibrary::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMLibrary::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMLibrary::loadRecByRef(
			ubigint ref
			, WdbeMLibrary** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMLibrary WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMLibrary::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWdbeMLibrary WHERE sref = '" + sref + "'", ref);
};

bool MyTblWdbeMLibrary::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMLibrary WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMLibrary
 ******************************************************************************/

PgTblWdbeMLibrary::PgTblWdbeMLibrary() :
			TblWdbeMLibrary()
			, PgTable()
		{
};

PgTblWdbeMLibrary::~PgTblWdbeMLibrary() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMLibrary::initStatements() {
	createStatement("TblWdbeMLibrary_insertRec", "INSERT INTO TblWdbeMLibrary (sref, Title, Version, depSrefsWdbeMLibrary, Comment) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWdbeMLibrary_updateRec", "UPDATE TblWdbeMLibrary SET sref = $1, Title = $2, Version = $3, depSrefsWdbeMLibrary = $4, Comment = $5 WHERE ref = $6", 6);
	createStatement("TblWdbeMLibrary_removeRecByRef", "DELETE FROM TblWdbeMLibrary WHERE ref = $1", 1);

	createStatement("TblWdbeMLibrary_loadRecByRef", "SELECT ref, sref, Title, Version, depSrefsWdbeMLibrary, Comment FROM TblWdbeMLibrary WHERE ref = $1", 1);
	createStatement("TblWdbeMLibrary_loadRefBySrf", "SELECT ref FROM TblWdbeMLibrary WHERE sref = $1", 1);
	createStatement("TblWdbeMLibrary_loadSrfByRef", "SELECT sref FROM TblWdbeMLibrary WHERE ref = $1", 1);
};

bool PgTblWdbeMLibrary::loadRec(
			PGresult* res
			, WdbeMLibrary** rec
		) {
	char* ptr;

	WdbeMLibrary* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMLibrary();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "version"),
			PQfnumber(res, "depsrefswdbemlibrary"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[1]));
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Version.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->depSrefsWdbeMLibrary.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMLibrary::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMLibrary& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMLibrary* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "version"),
			PQfnumber(res, "depsrefswdbemlibrary"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMLibrary();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[1]));
			ptr = PQgetvalue(res, numread, fnum[2]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Version.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->depSrefsWdbeMLibrary.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMLibrary::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMLibrary** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMLibrary::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeMLibrary::loadRecBySQL(
			const string& sqlstr
			, WdbeMLibrary** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMLibrary::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMLibrary::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMLibrary& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMLibrary::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMLibrary::insertRec(
			WdbeMLibrary* rec
		) {
	PGresult* res;
	char* ptr;

	const char* vals[] = {
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Version.c_str(),
		rec->depSrefsWdbeMLibrary.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMLibrary_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMLibrary::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMLibrary::insertRst(
			ListWdbeMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMLibrary::updateRec(
			WdbeMLibrary* rec
		) {
	PGresult* res;

	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Version.c_str(),
		rec->depSrefsWdbeMLibrary.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMLibrary_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMLibrary::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMLibrary::updateRst(
			ListWdbeMLibrary& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMLibrary::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMLibrary_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMLibrary::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMLibrary::loadRecByRef(
			ubigint ref
			, WdbeMLibrary** rec
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

	return loadRecByStmt("TblWdbeMLibrary_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMLibrary::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRefByStmt("TblWdbeMLibrary_loadRefBySrf", 1, vals, l, f, ref);
};

bool PgTblWdbeMLibrary::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMLibrary_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
