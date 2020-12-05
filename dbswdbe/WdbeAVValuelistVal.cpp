/**
	* \file WdbeAVValuelistVal.cpp
	* database access for table TblWdbeAVValuelistVal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAVValuelistVal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAVValuelistVal
 ******************************************************************************/

WdbeAVValuelistVal::WdbeAVValuelistVal(
			const ubigint ref
			, const uint vlsIxWdbeVValuelist
			, const uint vlsNum
			, const uint x1IxWdbeVLocale
			, const string Val
		) {

	this->ref = ref;
	this->vlsIxWdbeVValuelist = vlsIxWdbeVValuelist;
	this->vlsNum = vlsNum;
	this->x1IxWdbeVLocale = x1IxWdbeVLocale;
	this->Val = Val;
};

bool WdbeAVValuelistVal::operator==(
			const WdbeAVValuelistVal& comp
		) {
	return false;
};

bool WdbeAVValuelistVal::operator!=(
			const WdbeAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAVValuelistVal
 ******************************************************************************/

ListWdbeAVValuelistVal::ListWdbeAVValuelistVal() {
};

ListWdbeAVValuelistVal::ListWdbeAVValuelistVal(
			const ListWdbeAVValuelistVal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAVValuelistVal(*(src.nodes[i]));
};

ListWdbeAVValuelistVal::~ListWdbeAVValuelistVal() {
	clear();
};

void ListWdbeAVValuelistVal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAVValuelistVal::size() const {
	return(nodes.size());
};

void ListWdbeAVValuelistVal::append(
			WdbeAVValuelistVal* rec
		) {
	nodes.push_back(rec);
};

WdbeAVValuelistVal* ListWdbeAVValuelistVal::operator[](
			const uint ix
		) {
	WdbeAVValuelistVal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAVValuelistVal& ListWdbeAVValuelistVal::operator=(
			const ListWdbeAVValuelistVal& src
		) {
	WdbeAVValuelistVal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAVValuelistVal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAVValuelistVal::operator==(
			const ListWdbeAVValuelistVal& comp
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

bool ListWdbeAVValuelistVal::operator!=(
			const ListWdbeAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAVValuelistVal
 ******************************************************************************/

TblWdbeAVValuelistVal::TblWdbeAVValuelistVal() {
};

TblWdbeAVValuelistVal::~TblWdbeAVValuelistVal() {
};

bool TblWdbeAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WdbeAVValuelistVal** rec
		) {
	return false;
};

ubigint TblWdbeAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblWdbeAVValuelistVal::insertRec(
			WdbeAVValuelistVal* rec
		) {
	return 0;
};

ubigint TblWdbeAVValuelistVal::insertNewRec(
			WdbeAVValuelistVal** rec
			, const uint vlsIxWdbeVValuelist
			, const uint vlsNum
			, const uint x1IxWdbeVLocale
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAVValuelistVal* _rec = NULL;

	_rec = new WdbeAVValuelistVal(0, vlsIxWdbeVValuelist, vlsNum, x1IxWdbeVLocale, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAVValuelistVal::appendNewRecToRst(
			ListWdbeAVValuelistVal& rst
			, WdbeAVValuelistVal** rec
			, const uint vlsIxWdbeVValuelist
			, const uint vlsNum
			, const uint x1IxWdbeVLocale
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAVValuelistVal* _rec = NULL;

	retval = insertNewRec(&_rec, vlsIxWdbeVValuelist, vlsNum, x1IxWdbeVLocale, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAVValuelistVal::insertRst(
			ListWdbeAVValuelistVal& rst
			, bool transact
		) {
};

void TblWdbeAVValuelistVal::updateRec(
			WdbeAVValuelistVal* rec
		) {
};

void TblWdbeAVValuelistVal::updateRst(
			ListWdbeAVValuelistVal& rst
			, bool transact
		) {
};

void TblWdbeAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAVValuelistVal::loadRecByRef(
			ubigint ref
			, WdbeAVValuelistVal** rec
		) {
	return false;
};

ubigint TblWdbeAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWdbeVValuelist
			, uint x1IxWdbeVLocale
			, const bool append
			, ListWdbeAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblWdbeAVValuelistVal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAVValuelistVal& rst
		) {
	ubigint numload = 0;
	WdbeAVValuelistVal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAVValuelistVal
 ******************************************************************************/

MyTblWdbeAVValuelistVal::MyTblWdbeAVValuelistVal() :
			TblWdbeAVValuelistVal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAVValuelistVal::~MyTblWdbeAVValuelistVal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAVValuelistVal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAVValuelistVal (vlsIxWdbeVValuelist, vlsNum, x1IxWdbeVLocale, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAVValuelistVal SET vlsIxWdbeVValuelist = ?, vlsNum = ?, x1IxWdbeVLocale = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAVValuelistVal WHERE ref = ?", false);
};

bool MyTblWdbeAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WdbeAVValuelistVal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAVValuelistVal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAVValuelistVal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAVValuelistVal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAVValuelistVal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->vlsIxWdbeVValuelist = atol((char*) dbrow[1]); else _rec->vlsIxWdbeVValuelist = 0;
		if (dbrow[2]) _rec->vlsNum = atol((char*) dbrow[2]); else _rec->vlsNum = 0;
		if (dbrow[3]) _rec->x1IxWdbeVLocale = atol((char*) dbrow[3]); else _rec->x1IxWdbeVLocale = 0;
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAVValuelistVal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAVValuelistVal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAVValuelistVal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAVValuelistVal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAVValuelistVal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->vlsIxWdbeVValuelist = atol((char*) dbrow[1]); else rec->vlsIxWdbeVValuelist = 0;
			if (dbrow[2]) rec->vlsNum = atol((char*) dbrow[2]); else rec->vlsNum = 0;
			if (dbrow[3]) rec->x1IxWdbeVLocale = atol((char*) dbrow[3]); else rec->x1IxWdbeVLocale = 0;
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAVValuelistVal::insertRec(
			WdbeAVValuelistVal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxWdbeVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWdbeVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAVValuelistVal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAVValuelistVal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAVValuelistVal::insertRst(
			ListWdbeAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAVValuelistVal::updateRec(
			WdbeAVValuelistVal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxWdbeVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWdbeVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAVValuelistVal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAVValuelistVal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAVValuelistVal::updateRst(
			ListWdbeAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAVValuelistVal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAVValuelistVal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAVValuelistVal::loadRecByRef(
			ubigint ref
			, WdbeAVValuelistVal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAVValuelistVal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWdbeVValuelist
			, uint x1IxWdbeVLocale
			, const bool append
			, ListWdbeAVValuelistVal& rst
		) {
	return loadRstBySQL("SELECT ref, vlsIxWdbeVValuelist, vlsNum, x1IxWdbeVLocale, Val FROM TblWdbeAVValuelistVal WHERE vlsIxWdbeVValuelist = " + to_string(vlsIxWdbeVValuelist) + " AND x1IxWdbeVLocale = " + to_string(x1IxWdbeVLocale) + " ORDER BY vlsNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAVValuelistVal
 ******************************************************************************/

PgTblWdbeAVValuelistVal::PgTblWdbeAVValuelistVal() :
			TblWdbeAVValuelistVal()
			, PgTable()
		{
};

PgTblWdbeAVValuelistVal::~PgTblWdbeAVValuelistVal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAVValuelistVal::initStatements() {
	createStatement("TblWdbeAVValuelistVal_insertRec", "INSERT INTO TblWdbeAVValuelistVal (vlsIxWdbeVValuelist, vlsNum, x1IxWdbeVLocale, Val) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeAVValuelistVal_updateRec", "UPDATE TblWdbeAVValuelistVal SET vlsIxWdbeVValuelist = $1, vlsNum = $2, x1IxWdbeVLocale = $3, Val = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeAVValuelistVal_removeRecByRef", "DELETE FROM TblWdbeAVValuelistVal WHERE ref = $1", 1);

	createStatement("TblWdbeAVValuelistVal_loadRecByRef", "SELECT ref, vlsIxWdbeVValuelist, vlsNum, x1IxWdbeVLocale, Val FROM TblWdbeAVValuelistVal WHERE ref = $1", 1);
	createStatement("TblWdbeAVValuelistVal_loadRstByVlsLcl", "SELECT ref, vlsIxWdbeVValuelist, vlsNum, x1IxWdbeVLocale, Val FROM TblWdbeAVValuelistVal WHERE vlsIxWdbeVValuelist = $1 AND x1IxWdbeVLocale = $2 ORDER BY vlsNum ASC", 2);
};

bool PgTblWdbeAVValuelistVal::loadRec(
			PGresult* res
			, WdbeAVValuelistVal** rec
		) {
	char* ptr;

	WdbeAVValuelistVal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAVValuelistVal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixwdbevvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixwdbevlocale"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->vlsIxWdbeVValuelist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->vlsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxWdbeVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAVValuelistVal::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAVValuelistVal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAVValuelistVal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixwdbevvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixwdbevlocale"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WdbeAVValuelistVal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->vlsIxWdbeVValuelist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->vlsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxWdbeVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAVValuelistVal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVValuelistVal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAVValuelistVal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVValuelistVal::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, WdbeAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVValuelistVal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVValuelistVal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAVValuelistVal::insertRec(
			WdbeAVValuelistVal* rec
		) {
	PGresult* res;
	char* ptr;

	uint _vlsIxWdbeVValuelist = htonl(rec->vlsIxWdbeVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxWdbeVLocale = htonl(rec->x1IxWdbeVLocale);

	const char* vals[] = {
		(char*) &_vlsIxWdbeVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxWdbeVLocale,
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeAVValuelistVal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVValuelistVal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAVValuelistVal::insertRst(
			ListWdbeAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAVValuelistVal::updateRec(
			WdbeAVValuelistVal* rec
		) {
	PGresult* res;

	uint _vlsIxWdbeVValuelist = htonl(rec->vlsIxWdbeVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxWdbeVLocale = htonl(rec->x1IxWdbeVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_vlsIxWdbeVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxWdbeVLocale,
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAVValuelistVal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAVValuelistVal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAVValuelistVal::updateRst(
			ListWdbeAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAVValuelistVal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAVValuelistVal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAVValuelistVal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAVValuelistVal::loadRecByRef(
			ubigint ref
			, WdbeAVValuelistVal** rec
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

	return loadRecByStmt("TblWdbeAVValuelistVal_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxWdbeVValuelist
			, uint x1IxWdbeVLocale
			, const bool append
			, ListWdbeAVValuelistVal& rst
		) {
	uint _vlsIxWdbeVValuelist = htonl(vlsIxWdbeVValuelist);
	uint _x1IxWdbeVLocale = htonl(x1IxWdbeVLocale);

	const char* vals[] = {
		(char*) &_vlsIxWdbeVValuelist,
		(char*) &_x1IxWdbeVLocale
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWdbeAVValuelistVal_loadRstByVlsLcl", 2, vals, l, f, append, rst);
};

#endif

