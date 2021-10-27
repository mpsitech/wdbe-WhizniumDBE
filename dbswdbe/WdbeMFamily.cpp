/**
	* \file WdbeMFamily.cpp
	* database access for table TblWdbeMFamily (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMFamily.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMFamily
 ******************************************************************************/

WdbeMFamily::WdbeMFamily(
			const ubigint ref
			, const string srefWdbeKVendor
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->srefWdbeKVendor = srefWdbeKVendor;
	this->Title = Title;
	this->Comment = Comment;
};

bool WdbeMFamily::operator==(
			const WdbeMFamily& comp
		) {
	return false;
};

bool WdbeMFamily::operator!=(
			const WdbeMFamily& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMFamily
 ******************************************************************************/

ListWdbeMFamily::ListWdbeMFamily() {
};

ListWdbeMFamily::ListWdbeMFamily(
			const ListWdbeMFamily& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMFamily(*(src.nodes[i]));
};

ListWdbeMFamily::~ListWdbeMFamily() {
	clear();
};

void ListWdbeMFamily::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMFamily::size() const {
	return(nodes.size());
};

void ListWdbeMFamily::append(
			WdbeMFamily* rec
		) {
	nodes.push_back(rec);
};

WdbeMFamily* ListWdbeMFamily::operator[](
			const uint ix
		) {
	WdbeMFamily* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMFamily& ListWdbeMFamily::operator=(
			const ListWdbeMFamily& src
		) {
	WdbeMFamily* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMFamily(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMFamily::operator==(
			const ListWdbeMFamily& comp
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

bool ListWdbeMFamily::operator!=(
			const ListWdbeMFamily& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMFamily
 ******************************************************************************/

TblWdbeMFamily::TblWdbeMFamily() {
};

TblWdbeMFamily::~TblWdbeMFamily() {
};

bool TblWdbeMFamily::loadRecBySQL(
			const string& sqlstr
			, WdbeMFamily** rec
		) {
	return false;
};

ubigint TblWdbeMFamily::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFamily& rst
		) {
	return 0;
};

ubigint TblWdbeMFamily::insertRec(
			WdbeMFamily* rec
		) {
	return 0;
};

ubigint TblWdbeMFamily::insertNewRec(
			WdbeMFamily** rec
			, const string srefWdbeKVendor
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMFamily* _rec = NULL;

	_rec = new WdbeMFamily(0, srefWdbeKVendor, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMFamily::appendNewRecToRst(
			ListWdbeMFamily& rst
			, WdbeMFamily** rec
			, const string srefWdbeKVendor
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMFamily* _rec = NULL;

	retval = insertNewRec(&_rec, srefWdbeKVendor, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMFamily::insertRst(
			ListWdbeMFamily& rst
			, bool transact
		) {
};

void TblWdbeMFamily::updateRec(
			WdbeMFamily* rec
		) {
};

void TblWdbeMFamily::updateRst(
			ListWdbeMFamily& rst
			, bool transact
		) {
};

void TblWdbeMFamily::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMFamily::loadRecByRef(
			ubigint ref
			, WdbeMFamily** rec
		) {
	return false;
};

ubigint TblWdbeMFamily::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMFamily& rst
		) {
	ubigint numload = 0;
	WdbeMFamily* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMFamily
 ******************************************************************************/

MyTblWdbeMFamily::MyTblWdbeMFamily() :
			TblWdbeMFamily()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMFamily::~MyTblWdbeMFamily() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMFamily::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMFamily (srefWdbeKVendor, Title, Comment) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMFamily SET srefWdbeKVendor = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMFamily WHERE ref = ?", false);
};

bool MyTblWdbeMFamily::loadRecBySQL(
			const string& sqlstr
			, WdbeMFamily** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMFamily* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMFamily::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMFamily::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMFamily();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->srefWdbeKVendor.assign(dbrow[1], dblengths[1]); else _rec->srefWdbeKVendor = "";
		if (dbrow[2]) _rec->Title.assign(dbrow[2], dblengths[2]); else _rec->Title = "";
		if (dbrow[3]) _rec->Comment.assign(dbrow[3], dblengths[3]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMFamily::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFamily& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMFamily* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMFamily::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMFamily::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMFamily();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->srefWdbeKVendor.assign(dbrow[1], dblengths[1]); else rec->srefWdbeKVendor = "";
			if (dbrow[2]) rec->Title.assign(dbrow[2], dblengths[2]); else rec->Title = "";
			if (dbrow[3]) rec->Comment.assign(dbrow[3], dblengths[3]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMFamily::insertRec(
			WdbeMFamily* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[0] = rec->srefWdbeKVendor.length();
	l[1] = rec->Title.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->srefWdbeKVendor.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Title.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMFamily::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMFamily::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMFamily::insertRst(
			ListWdbeMFamily& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMFamily::updateRec(
			WdbeMFamily* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[0] = rec->srefWdbeKVendor.length();
	l[1] = rec->Title.length();
	l[2] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->srefWdbeKVendor.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Title.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMFamily::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMFamily::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMFamily::updateRst(
			ListWdbeMFamily& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMFamily::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMFamily::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMFamily::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMFamily::loadRecByRef(
			ubigint ref
			, WdbeMFamily** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMFamily WHERE ref = " + to_string(ref), rec);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMFamily
 ******************************************************************************/

PgTblWdbeMFamily::PgTblWdbeMFamily() :
			TblWdbeMFamily()
			, PgTable()
		{
};

PgTblWdbeMFamily::~PgTblWdbeMFamily() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMFamily::initStatements() {
	createStatement("TblWdbeMFamily_insertRec", "INSERT INTO TblWdbeMFamily (srefWdbeKVendor, Title, Comment) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeMFamily_updateRec", "UPDATE TblWdbeMFamily SET srefWdbeKVendor = $1, Title = $2, Comment = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeMFamily_removeRecByRef", "DELETE FROM TblWdbeMFamily WHERE ref = $1", 1);

	createStatement("TblWdbeMFamily_loadRecByRef", "SELECT ref, srefWdbeKVendor, Title, Comment FROM TblWdbeMFamily WHERE ref = $1", 1);
};

bool PgTblWdbeMFamily::loadRec(
			PGresult* res
			, WdbeMFamily** rec
		) {
	char* ptr;

	WdbeMFamily* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMFamily();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "srefwdbekvendor"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->srefWdbeKVendor.assign(ptr, PQgetlength(res, 0, fnum[1]));
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMFamily::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMFamily& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMFamily* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "srefwdbekvendor"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMFamily();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->srefWdbeKVendor.assign(ptr, PQgetlength(res, numread, fnum[1]));
			ptr = PQgetvalue(res, numread, fnum[2]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMFamily::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMFamily** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFamily::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeMFamily::loadRecBySQL(
			const string& sqlstr
			, WdbeMFamily** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFamily::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMFamily::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFamily& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFamily::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMFamily::insertRec(
			WdbeMFamily* rec
		) {
	PGresult* res;
	char* ptr;

	const char* vals[] = {
		rec->srefWdbeKVendor.c_str(),
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		0,
		0,
		0
	};
	const int f[] = {0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMFamily_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFamily::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMFamily::insertRst(
			ListWdbeMFamily& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMFamily::updateRec(
			WdbeMFamily* rec
		) {
	PGresult* res;

	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		rec->srefWdbeKVendor.c_str(),
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMFamily_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMFamily::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMFamily::updateRst(
			ListWdbeMFamily& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMFamily::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMFamily_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMFamily::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMFamily::loadRecByRef(
			ubigint ref
			, WdbeMFamily** rec
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

	return loadRecByStmt("TblWdbeMFamily_loadRecByRef", 1, vals, l, f, rec);
};

#endif
