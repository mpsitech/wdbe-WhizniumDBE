/**
	* \file WdbeMProject.cpp
	* database access for table TblWdbeMProject (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeMProject.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMProject
 ******************************************************************************/

WdbeMProject::WdbeMProject(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refWdbeMVersion
			, const string Short
			, const string Title
			, const bool Easy
			, const string Giturl
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refWdbeMVersion = refWdbeMVersion;
	this->Short = Short;
	this->Title = Title;
	this->Easy = Easy;
	this->Giturl = Giturl;
	this->Comment = Comment;
};

bool WdbeMProject::operator==(
			const WdbeMProject& comp
		) {
	return false;
};

bool WdbeMProject::operator!=(
			const WdbeMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMProject
 ******************************************************************************/

ListWdbeMProject::ListWdbeMProject() {
};

ListWdbeMProject::ListWdbeMProject(
			const ListWdbeMProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMProject(*(src.nodes[i]));
};

ListWdbeMProject::~ListWdbeMProject() {
	clear();
};

void ListWdbeMProject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMProject::size() const {
	return(nodes.size());
};

void ListWdbeMProject::append(
			WdbeMProject* rec
		) {
	nodes.push_back(rec);
};

WdbeMProject* ListWdbeMProject::operator[](
			const uint ix
		) {
	WdbeMProject* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMProject& ListWdbeMProject::operator=(
			const ListWdbeMProject& src
		) {
	WdbeMProject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMProject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMProject::operator==(
			const ListWdbeMProject& comp
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

bool ListWdbeMProject::operator!=(
			const ListWdbeMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMProject
 ******************************************************************************/

TblWdbeMProject::TblWdbeMProject() {
};

TblWdbeMProject::~TblWdbeMProject() {
};

bool TblWdbeMProject::loadRecBySQL(
			const string& sqlstr
			, WdbeMProject** rec
		) {
	return false;
};

ubigint TblWdbeMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMProject& rst
		) {
	return 0;
};

ubigint TblWdbeMProject::insertRec(
			WdbeMProject* rec
		) {
	return 0;
};

ubigint TblWdbeMProject::insertNewRec(
			WdbeMProject** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refWdbeMVersion
			, const string Short
			, const string Title
			, const bool Easy
			, const string Giturl
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMProject* _rec = NULL;

	_rec = new WdbeMProject(0, grp, own, refWdbeMVersion, Short, Title, Easy, Giturl, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMProject::appendNewRecToRst(
			ListWdbeMProject& rst
			, WdbeMProject** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refWdbeMVersion
			, const string Short
			, const string Title
			, const bool Easy
			, const string Giturl
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMProject* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refWdbeMVersion, Short, Title, Easy, Giturl, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMProject::insertRst(
			ListWdbeMProject& rst
			, bool transact
		) {
};

void TblWdbeMProject::updateRec(
			WdbeMProject* rec
		) {
};

void TblWdbeMProject::updateRst(
			ListWdbeMProject& rst
			, bool transact
		) {
};

void TblWdbeMProject::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMProject::loadRecByRef(
			ubigint ref
			, WdbeMProject** rec
		) {
	return false;
};

bool TblWdbeMProject::loadShoByRef(
			ubigint ref
			, string& Short
		) {
	return false;
};

bool TblWdbeMProject::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblWdbeMProject::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMProject& rst
		) {
	ubigint numload = 0;
	WdbeMProject* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMProject
 ******************************************************************************/

MyTblWdbeMProject::MyTblWdbeMProject() :
			TblWdbeMProject()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMProject::~MyTblWdbeMProject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMProject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMProject (grp, own, refWdbeMVersion, Short, Title, Easy, Giturl, Comment) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMProject SET grp = ?, own = ?, refWdbeMVersion = ?, Short = ?, Title = ?, Easy = ?, Giturl = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMProject WHERE ref = ?", false);
};

bool MyTblWdbeMProject::loadRecBySQL(
			const string& sqlstr
			, WdbeMProject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMProject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMProject::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMProject::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMProject();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refWdbeMVersion = atoll((char*) dbrow[3]); else _rec->refWdbeMVersion = 0;
		if (dbrow[4]) _rec->Short.assign(dbrow[4], dblengths[4]); else _rec->Short = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->Easy = (atoi((char*) dbrow[6]) != 0); else _rec->Easy = false;
		if (dbrow[7]) _rec->Giturl.assign(dbrow[7], dblengths[7]); else _rec->Giturl = "";
		if (dbrow[8]) _rec->Comment.assign(dbrow[8], dblengths[8]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMProject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMProject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMProject::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMProject::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMProject();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refWdbeMVersion = atoll((char*) dbrow[3]); else rec->refWdbeMVersion = 0;
			if (dbrow[4]) rec->Short.assign(dbrow[4], dblengths[4]); else rec->Short = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->Easy = (atoi((char*) dbrow[6]) != 0); else rec->Easy = false;
			if (dbrow[7]) rec->Giturl.assign(dbrow[7], dblengths[7]); else rec->Giturl = "";
			if (dbrow[8]) rec->Comment.assign(dbrow[8], dblengths[8]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMProject::insertRec(
			WdbeMProject* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->Short.length();
	l[4] = rec->Title.length();
	tinyint Easy = rec->Easy;
	l[6] = rec->Giturl.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeMVersion,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Short.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Easy,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Giturl.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMProject::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMProject::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMProject::insertRst(
			ListWdbeMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMProject::updateRec(
			WdbeMProject* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->Short.length();
	l[4] = rec->Title.length();
	tinyint Easy = rec->Easy;
	l[6] = rec->Giturl.length();
	l[7] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeMVersion,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Short.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Easy,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Giturl.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMProject::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMProject::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMProject::updateRst(
			ListWdbeMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMProject::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMProject::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMProject::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMProject::loadRecByRef(
			ubigint ref
			, WdbeMProject** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMProject WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMProject::loadShoByRef(
			ubigint ref
			, string& Short
		) {
	return loadStringBySQL("SELECT Short FROM TblWdbeMProject WHERE ref = " + to_string(ref) + "", Short);
};

bool MyTblWdbeMProject::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWdbeMProject WHERE ref = " + to_string(ref) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMProject
 ******************************************************************************/

PgTblWdbeMProject::PgTblWdbeMProject() :
			TblWdbeMProject()
			, PgTable()
		{
};

PgTblWdbeMProject::~PgTblWdbeMProject() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMProject::initStatements() {
	createStatement("TblWdbeMProject_insertRec", "INSERT INTO TblWdbeMProject (grp, own, refWdbeMVersion, Short, Title, Easy, Giturl, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWdbeMProject_updateRec", "UPDATE TblWdbeMProject SET grp = $1, own = $2, refWdbeMVersion = $3, Short = $4, Title = $5, Easy = $6, Giturl = $7, Comment = $8 WHERE ref = $9", 9);
	createStatement("TblWdbeMProject_removeRecByRef", "DELETE FROM TblWdbeMProject WHERE ref = $1", 1);

	createStatement("TblWdbeMProject_loadRecByRef", "SELECT ref, grp, own, refWdbeMVersion, Short, Title, Easy, Giturl, Comment FROM TblWdbeMProject WHERE ref = $1", 1);
	createStatement("TblWdbeMProject_loadShoByRef", "SELECT Short FROM TblWdbeMProject WHERE ref = $1", 1);
	createStatement("TblWdbeMProject_loadTitByRef", "SELECT Title FROM TblWdbeMProject WHERE ref = $1", 1);
};

bool PgTblWdbeMProject::loadRec(
			PGresult* res
			, WdbeMProject** rec
		) {
	char* ptr;

	WdbeMProject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMProject();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwdbemversion"),
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "easy"),
			PQfnumber(res, "giturl"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWdbeMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Easy = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Giturl.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMProject::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMProject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMProject* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwdbemversion"),
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "easy"),
			PQfnumber(res, "giturl"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMProject();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWdbeMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Easy = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Giturl.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMProject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMProject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMProject::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeMProject::loadRecBySQL(
			const string& sqlstr
			, WdbeMProject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMProject::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMProject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMProject::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMProject::insertRec(
			WdbeMProject* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);
	smallint _Easy = htons((smallint) rec->Easy);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWdbeMVersion,
		rec->Short.c_str(),
		rec->Title.c_str(),
		(char*) &_Easy,
		rec->Giturl.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(smallint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMProject_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMProject::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMProject::insertRst(
			ListWdbeMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMProject::updateRec(
			WdbeMProject* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);
	smallint _Easy = htons((smallint) rec->Easy);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWdbeMVersion,
		rec->Short.c_str(),
		rec->Title.c_str(),
		(char*) &_Easy,
		rec->Giturl.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(smallint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMProject_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMProject::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMProject::updateRst(
			ListWdbeMProject& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMProject::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMProject_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMProject::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMProject::loadRecByRef(
			ubigint ref
			, WdbeMProject** rec
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

	return loadRecByStmt("TblWdbeMProject_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMProject::loadShoByRef(
			ubigint ref
			, string& Short
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMProject_loadShoByRef", 1, vals, l, f, Short);
};

bool PgTblWdbeMProject::loadTitByRef(
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

	return loadStringByStmt("TblWdbeMProject_loadTitByRef", 1, vals, l, f, Title);
};

#endif

