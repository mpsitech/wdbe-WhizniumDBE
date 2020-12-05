/**
	* \file WdbeAMLibraryMakefile.cpp
	* database access for table TblWdbeAMLibraryMakefile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAMLibraryMakefile.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMLibraryMakefile
 ******************************************************************************/

WdbeAMLibraryMakefile::WdbeAMLibraryMakefile(
			const ubigint ref
			, const ubigint refWdbeMLibrary
			, const ubigint x1RefWdbeMMachine
			, const string x2SrefKTag
			, const string Val
		) {

	this->ref = ref;
	this->refWdbeMLibrary = refWdbeMLibrary;
	this->x1RefWdbeMMachine = x1RefWdbeMMachine;
	this->x2SrefKTag = x2SrefKTag;
	this->Val = Val;
};

bool WdbeAMLibraryMakefile::operator==(
			const WdbeAMLibraryMakefile& comp
		) {
	return false;
};

bool WdbeAMLibraryMakefile::operator!=(
			const WdbeAMLibraryMakefile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMLibraryMakefile
 ******************************************************************************/

ListWdbeAMLibraryMakefile::ListWdbeAMLibraryMakefile() {
};

ListWdbeAMLibraryMakefile::ListWdbeAMLibraryMakefile(
			const ListWdbeAMLibraryMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMLibraryMakefile(*(src.nodes[i]));
};

ListWdbeAMLibraryMakefile::~ListWdbeAMLibraryMakefile() {
	clear();
};

void ListWdbeAMLibraryMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMLibraryMakefile::size() const {
	return(nodes.size());
};

void ListWdbeAMLibraryMakefile::append(
			WdbeAMLibraryMakefile* rec
		) {
	nodes.push_back(rec);
};

WdbeAMLibraryMakefile* ListWdbeAMLibraryMakefile::operator[](
			const uint ix
		) {
	WdbeAMLibraryMakefile* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMLibraryMakefile& ListWdbeAMLibraryMakefile::operator=(
			const ListWdbeAMLibraryMakefile& src
		) {
	WdbeAMLibraryMakefile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMLibraryMakefile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMLibraryMakefile::operator==(
			const ListWdbeAMLibraryMakefile& comp
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

bool ListWdbeAMLibraryMakefile::operator!=(
			const ListWdbeAMLibraryMakefile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMLibraryMakefile
 ******************************************************************************/

TblWdbeAMLibraryMakefile::TblWdbeAMLibraryMakefile() {
};

TblWdbeAMLibraryMakefile::~TblWdbeAMLibraryMakefile() {
};

bool TblWdbeAMLibraryMakefile::loadRecBySQL(
			const string& sqlstr
			, WdbeAMLibraryMakefile** rec
		) {
	return false;
};

ubigint TblWdbeAMLibraryMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	return 0;
};

ubigint TblWdbeAMLibraryMakefile::insertRec(
			WdbeAMLibraryMakefile* rec
		) {
	return 0;
};

ubigint TblWdbeAMLibraryMakefile::insertNewRec(
			WdbeAMLibraryMakefile** rec
			, const ubigint refWdbeMLibrary
			, const ubigint x1RefWdbeMMachine
			, const string x2SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMLibraryMakefile* _rec = NULL;

	_rec = new WdbeAMLibraryMakefile(0, refWdbeMLibrary, x1RefWdbeMMachine, x2SrefKTag, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMLibraryMakefile::appendNewRecToRst(
			ListWdbeAMLibraryMakefile& rst
			, WdbeAMLibraryMakefile** rec
			, const ubigint refWdbeMLibrary
			, const ubigint x1RefWdbeMMachine
			, const string x2SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAMLibraryMakefile* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMLibrary, x1RefWdbeMMachine, x2SrefKTag, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMLibraryMakefile::insertRst(
			ListWdbeAMLibraryMakefile& rst
			, bool transact
		) {
};

void TblWdbeAMLibraryMakefile::updateRec(
			WdbeAMLibraryMakefile* rec
		) {
};

void TblWdbeAMLibraryMakefile::updateRst(
			ListWdbeAMLibraryMakefile& rst
			, bool transact
		) {
};

void TblWdbeAMLibraryMakefile::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMLibraryMakefile::loadRecByRef(
			ubigint ref
			, WdbeAMLibraryMakefile** rec
		) {
	return false;
};

ubigint TblWdbeAMLibraryMakefile::loadRefsByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMLibraryMakefile::loadRstByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	return 0;
};

ubigint TblWdbeAMLibraryMakefile::loadRstByLibMch(
			ubigint refWdbeMLibrary
			, ubigint x1RefWdbeMMachine
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	return 0;
};

bool TblWdbeAMLibraryMakefile::loadValByLibMchTag(
			ubigint refWdbeMLibrary
			, ubigint x1RefWdbeMMachine
			, string x2SrefKTag
			, string& Val
		) {
	return false;
};

ubigint TblWdbeAMLibraryMakefile::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	ubigint numload = 0;
	WdbeAMLibraryMakefile* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMLibraryMakefile
 ******************************************************************************/

MyTblWdbeAMLibraryMakefile::MyTblWdbeAMLibraryMakefile() :
			TblWdbeAMLibraryMakefile()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMLibraryMakefile::~MyTblWdbeAMLibraryMakefile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMLibraryMakefile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMLibraryMakefile (refWdbeMLibrary, x1RefWdbeMMachine, x2SrefKTag, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMLibraryMakefile SET refWdbeMLibrary = ?, x1RefWdbeMMachine = ?, x2SrefKTag = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMLibraryMakefile WHERE ref = ?", false);
};

bool MyTblWdbeAMLibraryMakefile::loadRecBySQL(
			const string& sqlstr
			, WdbeAMLibraryMakefile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMLibraryMakefile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMLibraryMakefile::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMLibraryMakefile::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMLibraryMakefile();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMLibrary = atoll((char*) dbrow[1]); else _rec->refWdbeMLibrary = 0;
		if (dbrow[2]) _rec->x1RefWdbeMMachine = atoll((char*) dbrow[2]); else _rec->x1RefWdbeMMachine = 0;
		if (dbrow[3]) _rec->x2SrefKTag.assign(dbrow[3], dblengths[3]); else _rec->x2SrefKTag = "";
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMLibraryMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMLibraryMakefile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMLibraryMakefile::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMLibraryMakefile::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMLibraryMakefile();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMLibrary = atoll((char*) dbrow[1]); else rec->refWdbeMLibrary = 0;
			if (dbrow[2]) rec->x1RefWdbeMMachine = atoll((char*) dbrow[2]); else rec->x1RefWdbeMMachine = 0;
			if (dbrow[3]) rec->x2SrefKTag.assign(dbrow[3], dblengths[3]); else rec->x2SrefKTag = "";
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMLibraryMakefile::insertRec(
			WdbeAMLibraryMakefile* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2SrefKTag.length();
	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMLibrary,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWdbeMMachine,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2SrefKTag.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMLibraryMakefile::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMLibraryMakefile::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMLibraryMakefile::insertRst(
			ListWdbeAMLibraryMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMLibraryMakefile::updateRec(
			WdbeAMLibraryMakefile* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2SrefKTag.length();
	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMLibrary,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWdbeMMachine,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2SrefKTag.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMLibraryMakefile::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMLibraryMakefile::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMLibraryMakefile::updateRst(
			ListWdbeAMLibraryMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMLibraryMakefile::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMLibraryMakefile::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMLibraryMakefile::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMLibraryMakefile::loadRecByRef(
			ubigint ref
			, WdbeAMLibraryMakefile** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMLibraryMakefile WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMLibraryMakefile::loadRefsByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMLibraryMakefile WHERE refWdbeMLibrary = " + to_string(refWdbeMLibrary) + "", append, refs);
};

ubigint MyTblWdbeAMLibraryMakefile::loadRstByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMLibrary, x1RefWdbeMMachine, x2SrefKTag, Val FROM TblWdbeAMLibraryMakefile WHERE refWdbeMLibrary = " + to_string(refWdbeMLibrary) + " ORDER BY x1RefWdbeMMachine ASC, x2SrefKTag ASC", append, rst);
};

ubigint MyTblWdbeAMLibraryMakefile::loadRstByLibMch(
			ubigint refWdbeMLibrary
			, ubigint x1RefWdbeMMachine
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMLibrary, x1RefWdbeMMachine, x2SrefKTag, Val FROM TblWdbeAMLibraryMakefile WHERE refWdbeMLibrary = " + to_string(refWdbeMLibrary) + " AND x1RefWdbeMMachine = " + to_string(x1RefWdbeMMachine) + " ORDER BY x2SrefKTag ASC", append, rst);
};

bool MyTblWdbeAMLibraryMakefile::loadValByLibMchTag(
			ubigint refWdbeMLibrary
			, ubigint x1RefWdbeMMachine
			, string x2SrefKTag
			, string& Val
		) {
	return loadStringBySQL("SELECT Val FROM TblWdbeAMLibraryMakefile WHERE refWdbeMLibrary = " + to_string(refWdbeMLibrary) + " AND x1RefWdbeMMachine = " + to_string(x1RefWdbeMMachine) + " AND x2SrefKTag = '" + x2SrefKTag + "'", Val);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMLibraryMakefile
 ******************************************************************************/

PgTblWdbeAMLibraryMakefile::PgTblWdbeAMLibraryMakefile() :
			TblWdbeAMLibraryMakefile()
			, PgTable()
		{
};

PgTblWdbeAMLibraryMakefile::~PgTblWdbeAMLibraryMakefile() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMLibraryMakefile::initStatements() {
	createStatement("TblWdbeAMLibraryMakefile_insertRec", "INSERT INTO TblWdbeAMLibraryMakefile (refWdbeMLibrary, x1RefWdbeMMachine, x2SrefKTag, Val) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeAMLibraryMakefile_updateRec", "UPDATE TblWdbeAMLibraryMakefile SET refWdbeMLibrary = $1, x1RefWdbeMMachine = $2, x2SrefKTag = $3, Val = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeAMLibraryMakefile_removeRecByRef", "DELETE FROM TblWdbeAMLibraryMakefile WHERE ref = $1", 1);

	createStatement("TblWdbeAMLibraryMakefile_loadRecByRef", "SELECT ref, refWdbeMLibrary, x1RefWdbeMMachine, x2SrefKTag, Val FROM TblWdbeAMLibraryMakefile WHERE ref = $1", 1);
	createStatement("TblWdbeAMLibraryMakefile_loadRefsByLib", "SELECT ref FROM TblWdbeAMLibraryMakefile WHERE refWdbeMLibrary = $1", 1);
	createStatement("TblWdbeAMLibraryMakefile_loadRstByLib", "SELECT ref, refWdbeMLibrary, x1RefWdbeMMachine, x2SrefKTag, Val FROM TblWdbeAMLibraryMakefile WHERE refWdbeMLibrary = $1 ORDER BY x1RefWdbeMMachine ASC, x2SrefKTag ASC", 1);
	createStatement("TblWdbeAMLibraryMakefile_loadRstByLibMch", "SELECT ref, refWdbeMLibrary, x1RefWdbeMMachine, x2SrefKTag, Val FROM TblWdbeAMLibraryMakefile WHERE refWdbeMLibrary = $1 AND x1RefWdbeMMachine = $2 ORDER BY x2SrefKTag ASC", 2);
	createStatement("TblWdbeAMLibraryMakefile_loadValByLibMchTag", "SELECT Val FROM TblWdbeAMLibraryMakefile WHERE refWdbeMLibrary = $1 AND x1RefWdbeMMachine = $2 AND x2SrefKTag = $3", 3);
};

bool PgTblWdbeAMLibraryMakefile::loadRec(
			PGresult* res
			, WdbeAMLibraryMakefile** rec
		) {
	char* ptr;

	WdbeAMLibraryMakefile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMLibraryMakefile();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemlibrary"),
			PQfnumber(res, "x1refwdbemmachine"),
			PQfnumber(res, "x2srefktag"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMLibrary = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWdbeMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2SrefKTag.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMLibraryMakefile::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMLibraryMakefile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemlibrary"),
			PQfnumber(res, "x1refwdbemmachine"),
			PQfnumber(res, "x2srefktag"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WdbeAMLibraryMakefile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMLibrary = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWdbeMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2SrefKTag.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMLibraryMakefile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMLibraryMakefile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMLibraryMakefile::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMLibraryMakefile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMLibraryMakefile::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMLibraryMakefile::loadRecBySQL(
			const string& sqlstr
			, WdbeAMLibraryMakefile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMLibraryMakefile::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMLibraryMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMLibraryMakefile::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMLibraryMakefile::insertRec(
			WdbeAMLibraryMakefile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMLibrary = htonl64(rec->refWdbeMLibrary);
	ubigint _x1RefWdbeMMachine = htonl64(rec->x1RefWdbeMMachine);

	const char* vals[] = {
		(char*) &_refWdbeMLibrary,
		(char*) &_x1RefWdbeMMachine,
		rec->x2SrefKTag.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMLibraryMakefile_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMLibraryMakefile::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMLibraryMakefile::insertRst(
			ListWdbeAMLibraryMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMLibraryMakefile::updateRec(
			WdbeAMLibraryMakefile* rec
		) {
	PGresult* res;

	ubigint _refWdbeMLibrary = htonl64(rec->refWdbeMLibrary);
	ubigint _x1RefWdbeMMachine = htonl64(rec->x1RefWdbeMMachine);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMLibrary,
		(char*) &_x1RefWdbeMMachine,
		rec->x2SrefKTag.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMLibraryMakefile_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMLibraryMakefile::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMLibraryMakefile::updateRst(
			ListWdbeAMLibraryMakefile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMLibraryMakefile::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMLibraryMakefile_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMLibraryMakefile::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMLibraryMakefile::loadRecByRef(
			ubigint ref
			, WdbeAMLibraryMakefile** rec
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

	return loadRecByStmt("TblWdbeAMLibraryMakefile_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMLibraryMakefile::loadRefsByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMLibrary = htonl64(refWdbeMLibrary);

	const char* vals[] = {
		(char*) &_refWdbeMLibrary
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMLibraryMakefile_loadRefsByLib", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMLibraryMakefile::loadRstByLib(
			ubigint refWdbeMLibrary
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	ubigint _refWdbeMLibrary = htonl64(refWdbeMLibrary);

	const char* vals[] = {
		(char*) &_refWdbeMLibrary
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMLibraryMakefile_loadRstByLib", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeAMLibraryMakefile::loadRstByLibMch(
			ubigint refWdbeMLibrary
			, ubigint x1RefWdbeMMachine
			, const bool append
			, ListWdbeAMLibraryMakefile& rst
		) {
	ubigint _refWdbeMLibrary = htonl64(refWdbeMLibrary);
	ubigint _x1RefWdbeMMachine = htonl64(x1RefWdbeMMachine);

	const char* vals[] = {
		(char*) &_refWdbeMLibrary,
		(char*) &_x1RefWdbeMMachine
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWdbeAMLibraryMakefile_loadRstByLibMch", 2, vals, l, f, append, rst);
};

bool PgTblWdbeAMLibraryMakefile::loadValByLibMchTag(
			ubigint refWdbeMLibrary
			, ubigint x1RefWdbeMMachine
			, string x2SrefKTag
			, string& Val
		) {
	ubigint _refWdbeMLibrary = htonl64(refWdbeMLibrary);
	ubigint _x1RefWdbeMMachine = htonl64(x1RefWdbeMMachine);

	const char* vals[] = {
		(char*) &_refWdbeMLibrary,
		(char*) &_x1RefWdbeMMachine,
		x2SrefKTag.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadStringByStmt("TblWdbeAMLibraryMakefile_loadValByLibMchTag", 3, vals, l, f, Val);
};

#endif

