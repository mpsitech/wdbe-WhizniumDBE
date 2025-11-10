/**
	* \file WdbeMVersion.cpp
	* database access for table TblWdbeMVersion (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMVersion.h"

#include "WdbeMVersion_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMVersion
 ******************************************************************************/

WdbeMVersion::WdbeMVersion(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint prjRefWdbeMProject
			, const uint prjNum
			, const ubigint bvrRefWdbeMVersion
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const string About
			, const string Comment
		) :
			ref(ref)
			, grp(grp)
			, own(own)
			, prjRefWdbeMProject(prjRefWdbeMProject)
			, prjNum(prjNum)
			, bvrRefWdbeMVersion(bvrRefWdbeMVersion)
			, Major(Major)
			, Minor(Minor)
			, Sub(Sub)
			, refJState(refJState)
			, ixVState(ixVState)
			, About(About)
			, Comment(Comment)
		{
};

bool WdbeMVersion::operator==(
			const WdbeMVersion& comp
		) {
	return false;
};

bool WdbeMVersion::operator!=(
			const WdbeMVersion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMVersion
 ******************************************************************************/

ListWdbeMVersion::ListWdbeMVersion() {
};

ListWdbeMVersion::ListWdbeMVersion(
			const ListWdbeMVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMVersion(*(src.nodes[i]));
};

ListWdbeMVersion::~ListWdbeMVersion() {
	clear();
};

void ListWdbeMVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMVersion::size() const {
	return(nodes.size());
};

void ListWdbeMVersion::append(
			WdbeMVersion* rec
		) {
	nodes.push_back(rec);
};

WdbeMVersion* ListWdbeMVersion::operator[](
			const uint ix
		) {
	WdbeMVersion* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMVersion& ListWdbeMVersion::operator=(
			const ListWdbeMVersion& src
		) {
	WdbeMVersion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMVersion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMVersion::operator==(
			const ListWdbeMVersion& comp
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

bool ListWdbeMVersion::operator!=(
			const ListWdbeMVersion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMVersion
 ******************************************************************************/

TblWdbeMVersion::TblWdbeMVersion() {
};

TblWdbeMVersion::~TblWdbeMVersion() {
};

bool TblWdbeMVersion::loadRecBySQL(
			const string& sqlstr
			, WdbeMVersion** rec
		) {
	return false;
};

ubigint TblWdbeMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMVersion& rst
		) {
	return 0;
};

ubigint TblWdbeMVersion::insertRec(
			WdbeMVersion* rec
		) {
	return 0;
};

ubigint TblWdbeMVersion::insertNewRec(
			WdbeMVersion** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint prjRefWdbeMProject
			, const uint prjNum
			, const ubigint bvrRefWdbeMVersion
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const string About
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMVersion* _rec = NULL;

	_rec = new WdbeMVersion(0, grp, own, prjRefWdbeMProject, prjNum, bvrRefWdbeMVersion, Major, Minor, Sub, refJState, ixVState, About, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMVersion::appendNewRecToRst(
			ListWdbeMVersion& rst
			, WdbeMVersion** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint prjRefWdbeMProject
			, const uint prjNum
			, const ubigint bvrRefWdbeMVersion
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint refJState
			, const uint ixVState
			, const string About
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMVersion* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, prjRefWdbeMProject, prjNum, bvrRefWdbeMVersion, Major, Minor, Sub, refJState, ixVState, About, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMVersion::insertRst(
			ListWdbeMVersion& rst
			, bool transact
		) {
};

void TblWdbeMVersion::updateRec(
			WdbeMVersion* rec
		) {
};

void TblWdbeMVersion::updateRst(
			ListWdbeMVersion& rst
			, bool transact
		) {
};

void TblWdbeMVersion::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMVersion::loadRecByRef(
			ubigint ref
			, WdbeMVersion** rec
		) {
	return false;
};

ubigint TblWdbeMVersion::loadRefsByPrj(
			ubigint prjRefWdbeMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMVersion::loadRstByPrj(
			ubigint prjRefWdbeMProject
			, const bool append
			, ListWdbeMVersion& rst
		) {
	return 0;
};

ubigint TblWdbeMVersion::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMVersion& rst
		) {
	ubigint numload = 0;
	WdbeMVersion* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMVersion
 ******************************************************************************/

MyTblWdbeMVersion::MyTblWdbeMVersion() :
			TblWdbeMVersion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMVersion::~MyTblWdbeMVersion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMVersion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMVersion (grp, own, prjRefWdbeMProject, prjNum, bvrRefWdbeMVersion, Major, Minor, Sub, refJState, ixVState, About, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMVersion SET grp = ?, own = ?, prjRefWdbeMProject = ?, prjNum = ?, bvrRefWdbeMVersion = ?, Major = ?, Minor = ?, Sub = ?, refJState = ?, ixVState = ?, About = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMVersion WHERE ref = ?", false);
};

bool MyTblWdbeMVersion::loadRecBySQL(
			const string& sqlstr
			, WdbeMVersion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMVersion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMVersion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMVersion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMVersion();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->prjRefWdbeMProject = atoll((char*) dbrow[3]); else _rec->prjRefWdbeMProject = 0;
		if (dbrow[4]) _rec->prjNum = atol((char*) dbrow[4]); else _rec->prjNum = 0;
		if (dbrow[5]) _rec->bvrRefWdbeMVersion = atoll((char*) dbrow[5]); else _rec->bvrRefWdbeMVersion = 0;
		if (dbrow[6]) _rec->Major = atoi((char*) dbrow[6]); else _rec->Major = 0;
		if (dbrow[7]) _rec->Minor = atoi((char*) dbrow[7]); else _rec->Minor = 0;
		if (dbrow[8]) _rec->Sub = atoi((char*) dbrow[8]); else _rec->Sub = 0;
		if (dbrow[9]) _rec->refJState = atoll((char*) dbrow[9]); else _rec->refJState = 0;
		if (dbrow[10]) _rec->ixVState = atol((char*) dbrow[10]); else _rec->ixVState = 0;
		if (dbrow[11]) _rec->About.assign(dbrow[11], dblengths[11]); else _rec->About = "";
		if (dbrow[12]) _rec->Comment.assign(dbrow[12], dblengths[12]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMVersion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMVersion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMVersion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMVersion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMVersion();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->prjRefWdbeMProject = atoll((char*) dbrow[3]); else rec->prjRefWdbeMProject = 0;
			if (dbrow[4]) rec->prjNum = atol((char*) dbrow[4]); else rec->prjNum = 0;
			if (dbrow[5]) rec->bvrRefWdbeMVersion = atoll((char*) dbrow[5]); else rec->bvrRefWdbeMVersion = 0;
			if (dbrow[6]) rec->Major = atoi((char*) dbrow[6]); else rec->Major = 0;
			if (dbrow[7]) rec->Minor = atoi((char*) dbrow[7]); else rec->Minor = 0;
			if (dbrow[8]) rec->Sub = atoi((char*) dbrow[8]); else rec->Sub = 0;
			if (dbrow[9]) rec->refJState = atoll((char*) dbrow[9]); else rec->refJState = 0;
			if (dbrow[10]) rec->ixVState = atol((char*) dbrow[10]); else rec->ixVState = 0;
			if (dbrow[11]) rec->About.assign(dbrow[11], dblengths[11]); else rec->About = "";
			if (dbrow[12]) rec->Comment.assign(dbrow[12], dblengths[12]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMVersion::insertRec(
			WdbeMVersion* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[10] = rec->About.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->prjRefWdbeMProject,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->prjNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->bvrRefWdbeMVersion,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Major,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Minor,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Sub,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixVState,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->About.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMVersion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMVersion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMVersion::insertRst(
			ListWdbeMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMVersion::updateRec(
			WdbeMVersion* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[10] = rec->About.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->prjRefWdbeMProject,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->prjNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->bvrRefWdbeMVersion,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Major,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Minor,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Sub,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJState,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixVState,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->About.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMVersion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMVersion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMVersion::updateRst(
			ListWdbeMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMVersion::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMVersion::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMVersion::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMVersion::loadRecByRef(
			ubigint ref
			, WdbeMVersion** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMVersion WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMVersion::loadRefsByPrj(
			ubigint prjRefWdbeMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMVersion WHERE prjRefWdbeMProject = " + to_string(prjRefWdbeMProject) + "", append, refs);
};

ubigint MyTblWdbeMVersion::loadRstByPrj(
			ubigint prjRefWdbeMProject
			, const bool append
			, ListWdbeMVersion& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, prjRefWdbeMProject, prjNum, bvrRefWdbeMVersion, Major, Minor, Sub, refJState, ixVState, About, Comment FROM TblWdbeMVersion WHERE prjRefWdbeMProject = " + to_string(prjRefWdbeMProject) + " ORDER BY prjNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMVersion
 ******************************************************************************/

PgTblWdbeMVersion::PgTblWdbeMVersion() :
			TblWdbeMVersion()
			, PgTable()
		{
};

PgTblWdbeMVersion::~PgTblWdbeMVersion() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMVersion::initStatements() {
	createStatement("TblWdbeMVersion_insertRec", "INSERT INTO TblWdbeMVersion (grp, own, prjRefWdbeMProject, prjNum, bvrRefWdbeMVersion, Major, Minor, Sub, refJState, ixVState, About, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING ref", 12);
	createStatement("TblWdbeMVersion_updateRec", "UPDATE TblWdbeMVersion SET grp = $1, own = $2, prjRefWdbeMProject = $3, prjNum = $4, bvrRefWdbeMVersion = $5, Major = $6, Minor = $7, Sub = $8, refJState = $9, ixVState = $10, About = $11, Comment = $12 WHERE ref = $13", 13);
	createStatement("TblWdbeMVersion_removeRecByRef", "DELETE FROM TblWdbeMVersion WHERE ref = $1", 1);

	createStatement("TblWdbeMVersion_loadRecByRef", "SELECT ref, grp, own, prjRefWdbeMProject, prjNum, bvrRefWdbeMVersion, Major, Minor, Sub, refJState, ixVState, About, Comment FROM TblWdbeMVersion WHERE ref = $1", 1);
	createStatement("TblWdbeMVersion_loadRefsByPrj", "SELECT ref FROM TblWdbeMVersion WHERE prjRefWdbeMProject = $1", 1);
	createStatement("TblWdbeMVersion_loadRstByPrj", "SELECT ref, grp, own, prjRefWdbeMProject, prjNum, bvrRefWdbeMVersion, Major, Minor, Sub, refJState, ixVState, About, Comment FROM TblWdbeMVersion WHERE prjRefWdbeMProject = $1 ORDER BY prjNum ASC", 1);
};

bool PgTblWdbeMVersion::loadRec(
			PGresult* res
			, WdbeMVersion** rec
		) {
	char* ptr;

	WdbeMVersion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMVersion();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "prjrefwdbemproject"),
			PQfnumber(res, "prjnum"),
			PQfnumber(res, "bvrrefwdbemversion"),
			PQfnumber(res, "major"),
			PQfnumber(res, "minor"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "about"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->prjRefWdbeMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->prjNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->bvrRefWdbeMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Major = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Minor = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Sub = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->About.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMVersion::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMVersion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMVersion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "prjrefwdbemproject"),
			PQfnumber(res, "prjnum"),
			PQfnumber(res, "bvrrefwdbemversion"),
			PQfnumber(res, "major"),
			PQfnumber(res, "minor"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "about"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMVersion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->prjRefWdbeMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->prjNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->bvrRefWdbeMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Major = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Minor = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Sub = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->About.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMVersion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMVersion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVersion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMVersion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMVersion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVersion::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMVersion::loadRecBySQL(
			const string& sqlstr
			, WdbeMVersion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVersion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMVersion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVersion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMVersion::insertRec(
			WdbeMVersion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _prjRefWdbeMProject = htonl64(rec->prjRefWdbeMProject);
	uint _prjNum = htonl(rec->prjNum);
	ubigint _bvrRefWdbeMVersion = htonl64(rec->bvrRefWdbeMVersion);
	usmallint _Major = htons(rec->Major);
	usmallint _Minor = htons(rec->Minor);
	usmallint _Sub = htons(rec->Sub);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_prjRefWdbeMProject,
		(char*) &_prjNum,
		(char*) &_bvrRefWdbeMVersion,
		(char*) &_Major,
		(char*) &_Minor,
		(char*) &_Sub,
		(char*) &_refJState,
		(char*) &_ixVState,
		rec->About.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMVersion_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVersion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMVersion::insertRst(
			ListWdbeMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMVersion::updateRec(
			WdbeMVersion* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _prjRefWdbeMProject = htonl64(rec->prjRefWdbeMProject);
	uint _prjNum = htonl(rec->prjNum);
	ubigint _bvrRefWdbeMVersion = htonl64(rec->bvrRefWdbeMVersion);
	usmallint _Major = htons(rec->Major);
	usmallint _Minor = htons(rec->Minor);
	usmallint _Sub = htons(rec->Sub);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_prjRefWdbeMProject,
		(char*) &_prjNum,
		(char*) &_bvrRefWdbeMVersion,
		(char*) &_Major,
		(char*) &_Minor,
		(char*) &_Sub,
		(char*) &_refJState,
		(char*) &_ixVState,
		rec->About.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMVersion_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMVersion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMVersion::updateRst(
			ListWdbeMVersion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMVersion::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMVersion_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMVersion::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMVersion::loadRecByRef(
			ubigint ref
			, WdbeMVersion** rec
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

	return loadRecByStmt("TblWdbeMVersion_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMVersion::loadRefsByPrj(
			ubigint prjRefWdbeMProject
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _prjRefWdbeMProject = htonl64(prjRefWdbeMProject);

	const char* vals[] = {
		(char*) &_prjRefWdbeMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMVersion_loadRefsByPrj", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMVersion::loadRstByPrj(
			ubigint prjRefWdbeMProject
			, const bool append
			, ListWdbeMVersion& rst
		) {
	ubigint _prjRefWdbeMProject = htonl64(prjRefWdbeMProject);

	const char* vals[] = {
		(char*) &_prjRefWdbeMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMVersion_loadRstByPrj", 1, vals, l, f, append, rst);
};

#endif
