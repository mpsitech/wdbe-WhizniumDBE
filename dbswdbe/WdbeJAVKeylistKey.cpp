/**
	* \file WdbeJAVKeylistKey.cpp
	* database access for table TblWdbeJAVKeylistKey (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeJAVKeylistKey.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeJAVKeylistKey
 ******************************************************************************/

WdbeJAVKeylistKey::WdbeJAVKeylistKey(
			const ubigint ref
			, const ubigint refWdbeAVKeylistKey
			, const uint x1IxWdbeVLocale
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->refWdbeAVKeylistKey = refWdbeAVKeylistKey;
	this->x1IxWdbeVLocale = x1IxWdbeVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

bool WdbeJAVKeylistKey::operator==(
			const WdbeJAVKeylistKey& comp
		) {
	return false;
};

bool WdbeJAVKeylistKey::operator!=(
			const WdbeJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeJAVKeylistKey
 ******************************************************************************/

ListWdbeJAVKeylistKey::ListWdbeJAVKeylistKey() {
};

ListWdbeJAVKeylistKey::ListWdbeJAVKeylistKey(
			const ListWdbeJAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeJAVKeylistKey(*(src.nodes[i]));
};

ListWdbeJAVKeylistKey::~ListWdbeJAVKeylistKey() {
	clear();
};

void ListWdbeJAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeJAVKeylistKey::size() const {
	return(nodes.size());
};

void ListWdbeJAVKeylistKey::append(
			WdbeJAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

WdbeJAVKeylistKey* ListWdbeJAVKeylistKey::operator[](
			const uint ix
		) {
	WdbeJAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeJAVKeylistKey& ListWdbeJAVKeylistKey::operator=(
			const ListWdbeJAVKeylistKey& src
		) {
	WdbeJAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeJAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeJAVKeylistKey::operator==(
			const ListWdbeJAVKeylistKey& comp
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

bool ListWdbeJAVKeylistKey::operator!=(
			const ListWdbeJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeJAVKeylistKey
 ******************************************************************************/

TblWdbeJAVKeylistKey::TblWdbeJAVKeylistKey() {
};

TblWdbeJAVKeylistKey::~TblWdbeJAVKeylistKey() {
};

bool TblWdbeJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WdbeJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWdbeJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWdbeJAVKeylistKey::insertRec(
			WdbeJAVKeylistKey* rec
		) {
	return 0;
};

ubigint TblWdbeJAVKeylistKey::insertNewRec(
			WdbeJAVKeylistKey** rec
			, const ubigint refWdbeAVKeylistKey
			, const uint x1IxWdbeVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeJAVKeylistKey* _rec = NULL;

	_rec = new WdbeJAVKeylistKey(0, refWdbeAVKeylistKey, x1IxWdbeVLocale, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeJAVKeylistKey::appendNewRecToRst(
			ListWdbeJAVKeylistKey& rst
			, WdbeJAVKeylistKey** rec
			, const ubigint refWdbeAVKeylistKey
			, const uint x1IxWdbeVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeJAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeAVKeylistKey, x1IxWdbeVLocale, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeJAVKeylistKey::insertRst(
			ListWdbeJAVKeylistKey& rst
			, bool transact
		) {
};

void TblWdbeJAVKeylistKey::updateRec(
			WdbeJAVKeylistKey* rec
		) {
};

void TblWdbeJAVKeylistKey::updateRst(
			ListWdbeJAVKeylistKey& rst
			, bool transact
		) {
};

void TblWdbeJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WdbeJAVKeylistKey** rec
		) {
	return false;
};

bool TblWdbeJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWdbeAVKeylistKey
			, uint x1IxWdbeVLocale
			, WdbeJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWdbeJAVKeylistKey::loadRefsByKlk(
			ubigint refWdbeAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeJAVKeylistKey::loadRstByKlk(
			ubigint refWdbeAVKeylistKey
			, const bool append
			, ListWdbeJAVKeylistKey& rst
		) {
	return 0;
};

bool TblWdbeJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWdbeAVKeylistKey
			, uint x1IxWdbeVLocale
			, string& Title
		) {
	return false;
};

ubigint TblWdbeJAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeJAVKeylistKey& rst
		) {
	ubigint numload = 0;
	WdbeJAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeJAVKeylistKey
 ******************************************************************************/

MyTblWdbeJAVKeylistKey::MyTblWdbeJAVKeylistKey() :
			TblWdbeJAVKeylistKey()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeJAVKeylistKey::~MyTblWdbeJAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeJAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeJAVKeylistKey (refWdbeAVKeylistKey, x1IxWdbeVLocale, Title, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeJAVKeylistKey SET refWdbeAVKeylistKey = ?, x1IxWdbeVLocale = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeJAVKeylistKey WHERE ref = ?", false);
};

bool MyTblWdbeJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WdbeJAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeJAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJAVKeylistKey::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJAVKeylistKey::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeJAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeAVKeylistKey = atoll((char*) dbrow[1]); else _rec->refWdbeAVKeylistKey = 0;
		if (dbrow[2]) _rec->x1IxWdbeVLocale = atol((char*) dbrow[2]); else _rec->x1IxWdbeVLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeJAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJAVKeylistKey::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJAVKeylistKey::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeJAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeAVKeylistKey = atoll((char*) dbrow[1]); else rec->refWdbeAVKeylistKey = 0;
			if (dbrow[2]) rec->x1IxWdbeVLocale = atol((char*) dbrow[2]); else rec->x1IxWdbeVLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeJAVKeylistKey::insertRec(
			WdbeJAVKeylistKey* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWdbeVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeJAVKeylistKey::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeJAVKeylistKey::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeJAVKeylistKey::insertRst(
			ListWdbeJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeJAVKeylistKey::updateRec(
			WdbeJAVKeylistKey* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxWdbeVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeJAVKeylistKey::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeJAVKeylistKey::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeJAVKeylistKey::updateRst(
			ListWdbeJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeJAVKeylistKey::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeJAVKeylistKey::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WdbeJAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeJAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWdbeAVKeylistKey
			, uint x1IxWdbeVLocale
			, WdbeJAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeAVKeylistKey, x1IxWdbeVLocale, Title, Comment FROM TblWdbeJAVKeylistKey WHERE refWdbeAVKeylistKey = " + to_string(refWdbeAVKeylistKey) + " AND x1IxWdbeVLocale = " + to_string(x1IxWdbeVLocale) + "", rec);
};

ubigint MyTblWdbeJAVKeylistKey::loadRefsByKlk(
			ubigint refWdbeAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeJAVKeylistKey WHERE refWdbeAVKeylistKey = " + to_string(refWdbeAVKeylistKey) + "", append, refs);
};

ubigint MyTblWdbeJAVKeylistKey::loadRstByKlk(
			ubigint refWdbeAVKeylistKey
			, const bool append
			, ListWdbeJAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeAVKeylistKey, x1IxWdbeVLocale, Title, Comment FROM TblWdbeJAVKeylistKey WHERE refWdbeAVKeylistKey = " + to_string(refWdbeAVKeylistKey) + " ORDER BY x1IxWdbeVLocale ASC", append, rst);
};

bool MyTblWdbeJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWdbeAVKeylistKey
			, uint x1IxWdbeVLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWdbeJAVKeylistKey WHERE refWdbeAVKeylistKey = " + to_string(refWdbeAVKeylistKey) + " AND x1IxWdbeVLocale = " + to_string(x1IxWdbeVLocale) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeJAVKeylistKey
 ******************************************************************************/

PgTblWdbeJAVKeylistKey::PgTblWdbeJAVKeylistKey() :
			TblWdbeJAVKeylistKey()
			, PgTable()
		{
};

PgTblWdbeJAVKeylistKey::~PgTblWdbeJAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeJAVKeylistKey::initStatements() {
	createStatement("TblWdbeJAVKeylistKey_insertRec", "INSERT INTO TblWdbeJAVKeylistKey (refWdbeAVKeylistKey, x1IxWdbeVLocale, Title, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeJAVKeylistKey_updateRec", "UPDATE TblWdbeJAVKeylistKey SET refWdbeAVKeylistKey = $1, x1IxWdbeVLocale = $2, Title = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeJAVKeylistKey_removeRecByRef", "DELETE FROM TblWdbeJAVKeylistKey WHERE ref = $1", 1);

	createStatement("TblWdbeJAVKeylistKey_loadRecByRef", "SELECT ref, refWdbeAVKeylistKey, x1IxWdbeVLocale, Title, Comment FROM TblWdbeJAVKeylistKey WHERE ref = $1", 1);
	createStatement("TblWdbeJAVKeylistKey_loadRecByKlkLcl", "SELECT ref, refWdbeAVKeylistKey, x1IxWdbeVLocale, Title, Comment FROM TblWdbeJAVKeylistKey WHERE refWdbeAVKeylistKey = $1 AND x1IxWdbeVLocale = $2", 2);
	createStatement("TblWdbeJAVKeylistKey_loadRefsByKlk", "SELECT ref FROM TblWdbeJAVKeylistKey WHERE refWdbeAVKeylistKey = $1", 1);
	createStatement("TblWdbeJAVKeylistKey_loadRstByKlk", "SELECT ref, refWdbeAVKeylistKey, x1IxWdbeVLocale, Title, Comment FROM TblWdbeJAVKeylistKey WHERE refWdbeAVKeylistKey = $1 ORDER BY x1IxWdbeVLocale ASC", 1);
	createStatement("TblWdbeJAVKeylistKey_loadTitByKlkLcl", "SELECT Title FROM TblWdbeJAVKeylistKey WHERE refWdbeAVKeylistKey = $1 AND x1IxWdbeVLocale = $2", 2);
};

bool PgTblWdbeJAVKeylistKey::loadRec(
			PGresult* res
			, WdbeJAVKeylistKey** rec
		) {
	char* ptr;

	WdbeJAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeJAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbeavkeylistkey"),
			PQfnumber(res, "x1ixwdbevlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeAVKeylistKey = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxWdbeVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeJAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeJAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeJAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbeavkeylistkey"),
			PQfnumber(res, "x1ixwdbevlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeJAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeAVKeylistKey = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxWdbeVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeJAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJAVKeylistKey::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJAVKeylistKey::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WdbeJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJAVKeylistKey::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJAVKeylistKey::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeJAVKeylistKey::insertRec(
			WdbeJAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeAVKeylistKey = htonl64(rec->refWdbeAVKeylistKey);
	uint _x1IxWdbeVLocale = htonl(rec->x1IxWdbeVLocale);

	const char* vals[] = {
		(char*) &_refWdbeAVKeylistKey,
		(char*) &_x1IxWdbeVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeJAVKeylistKey_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJAVKeylistKey::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeJAVKeylistKey::insertRst(
			ListWdbeJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeJAVKeylistKey::updateRec(
			WdbeJAVKeylistKey* rec
		) {
	PGresult* res;

	ubigint _refWdbeAVKeylistKey = htonl64(rec->refWdbeAVKeylistKey);
	uint _x1IxWdbeVLocale = htonl(rec->x1IxWdbeVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeAVKeylistKey,
		(char*) &_x1IxWdbeVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeJAVKeylistKey_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJAVKeylistKey::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeJAVKeylistKey::updateRst(
			ListWdbeJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeJAVKeylistKey::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeJAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJAVKeylistKey::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeJAVKeylistKey::loadRecByRef(
			ubigint ref
			, WdbeJAVKeylistKey** rec
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

	return loadRecByStmt("TblWdbeJAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeJAVKeylistKey::loadRecByKlkLcl(
			ubigint refWdbeAVKeylistKey
			, uint x1IxWdbeVLocale
			, WdbeJAVKeylistKey** rec
		) {
	ubigint _refWdbeAVKeylistKey = htonl64(refWdbeAVKeylistKey);
	uint _x1IxWdbeVLocale = htonl(x1IxWdbeVLocale);

	const char* vals[] = {
		(char*) &_refWdbeAVKeylistKey,
		(char*) &_x1IxWdbeVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWdbeJAVKeylistKey_loadRecByKlkLcl", 2, vals, l, f, rec);
};

ubigint PgTblWdbeJAVKeylistKey::loadRefsByKlk(
			ubigint refWdbeAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeAVKeylistKey = htonl64(refWdbeAVKeylistKey);

	const char* vals[] = {
		(char*) &_refWdbeAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeJAVKeylistKey_loadRefsByKlk", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeJAVKeylistKey::loadRstByKlk(
			ubigint refWdbeAVKeylistKey
			, const bool append
			, ListWdbeJAVKeylistKey& rst
		) {
	ubigint _refWdbeAVKeylistKey = htonl64(refWdbeAVKeylistKey);

	const char* vals[] = {
		(char*) &_refWdbeAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeJAVKeylistKey_loadRstByKlk", 1, vals, l, f, append, rst);
};

bool PgTblWdbeJAVKeylistKey::loadTitByKlkLcl(
			ubigint refWdbeAVKeylistKey
			, uint x1IxWdbeVLocale
			, string& Title
		) {
	ubigint _refWdbeAVKeylistKey = htonl64(refWdbeAVKeylistKey);
	uint _x1IxWdbeVLocale = htonl(x1IxWdbeVLocale);

	const char* vals[] = {
		(char*) &_refWdbeAVKeylistKey,
		(char*) &_x1IxWdbeVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblWdbeJAVKeylistKey_loadTitByKlkLcl", 2, vals, l, f, Title);
};

#endif

