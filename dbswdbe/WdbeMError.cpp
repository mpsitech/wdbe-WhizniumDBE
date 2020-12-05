/**
	* \file WdbeMError.cpp
	* database access for table TblWdbeMError (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMError.h"

#include "WdbeMError_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMError
 ******************************************************************************/

WdbeMError::WdbeMError(
			const ubigint ref
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const string sref
			, const string Fullsref
			, const ubigint traRefWdbeMSignal
			, const string Comment
		) {

	this->ref = ref;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->refNum = refNum;
	this->sref = sref;
	this->Fullsref = Fullsref;
	this->traRefWdbeMSignal = traRefWdbeMSignal;
	this->Comment = Comment;
};

bool WdbeMError::operator==(
			const WdbeMError& comp
		) {
	return false;
};

bool WdbeMError::operator!=(
			const WdbeMError& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMError
 ******************************************************************************/

ListWdbeMError::ListWdbeMError() {
};

ListWdbeMError::ListWdbeMError(
			const ListWdbeMError& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMError(*(src.nodes[i]));
};

ListWdbeMError::~ListWdbeMError() {
	clear();
};

void ListWdbeMError::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMError::size() const {
	return(nodes.size());
};

void ListWdbeMError::append(
			WdbeMError* rec
		) {
	nodes.push_back(rec);
};

WdbeMError* ListWdbeMError::operator[](
			const uint ix
		) {
	WdbeMError* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMError& ListWdbeMError::operator=(
			const ListWdbeMError& src
		) {
	WdbeMError* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMError(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMError::operator==(
			const ListWdbeMError& comp
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

bool ListWdbeMError::operator!=(
			const ListWdbeMError& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMError
 ******************************************************************************/

TblWdbeMError::TblWdbeMError() {
};

TblWdbeMError::~TblWdbeMError() {
};

bool TblWdbeMError::loadRecBySQL(
			const string& sqlstr
			, WdbeMError** rec
		) {
	return false;
};

ubigint TblWdbeMError::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMError& rst
		) {
	return 0;
};

ubigint TblWdbeMError::insertRec(
			WdbeMError* rec
		) {
	return 0;
};

ubigint TblWdbeMError::insertNewRec(
			WdbeMError** rec
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const string sref
			, const string Fullsref
			, const ubigint traRefWdbeMSignal
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMError* _rec = NULL;

	_rec = new WdbeMError(0, refIxVTbl, refUref, refNum, sref, Fullsref, traRefWdbeMSignal, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMError::appendNewRecToRst(
			ListWdbeMError& rst
			, WdbeMError** rec
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const string sref
			, const string Fullsref
			, const ubigint traRefWdbeMSignal
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMError* _rec = NULL;

	retval = insertNewRec(&_rec, refIxVTbl, refUref, refNum, sref, Fullsref, traRefWdbeMSignal, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMError::insertRst(
			ListWdbeMError& rst
			, bool transact
		) {
};

void TblWdbeMError::updateRec(
			WdbeMError* rec
		) {
};

void TblWdbeMError::updateRst(
			ListWdbeMError& rst
			, bool transact
		) {
};

void TblWdbeMError::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMError::loadRecByRef(
			ubigint ref
			, WdbeMError** rec
		) {
	return false;
};

ubigint TblWdbeMError::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMError::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMError& rst
		) {
	return 0;
};

ubigint TblWdbeMError::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMError& rst
		) {
	ubigint numload = 0;
	WdbeMError* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMError
 ******************************************************************************/

MyTblWdbeMError::MyTblWdbeMError() :
			TblWdbeMError()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMError::~MyTblWdbeMError() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMError::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMError (refIxVTbl, refUref, refNum, sref, Fullsref, traRefWdbeMSignal, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMError SET refIxVTbl = ?, refUref = ?, refNum = ?, sref = ?, Fullsref = ?, traRefWdbeMSignal = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMError WHERE ref = ?", false);
};

bool MyTblWdbeMError::loadRecBySQL(
			const string& sqlstr
			, WdbeMError** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMError* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMError::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMError::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMError();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refIxVTbl = atol((char*) dbrow[1]); else _rec->refIxVTbl = 0;
		if (dbrow[2]) _rec->refUref = atoll((char*) dbrow[2]); else _rec->refUref = 0;
		if (dbrow[3]) _rec->refNum = atol((char*) dbrow[3]); else _rec->refNum = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Fullsref.assign(dbrow[5], dblengths[5]); else _rec->Fullsref = "";
		if (dbrow[6]) _rec->traRefWdbeMSignal = atoll((char*) dbrow[6]); else _rec->traRefWdbeMSignal = 0;
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMError::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMError& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMError* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMError::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMError::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMError();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refIxVTbl = atol((char*) dbrow[1]); else rec->refIxVTbl = 0;
			if (dbrow[2]) rec->refUref = atoll((char*) dbrow[2]); else rec->refUref = 0;
			if (dbrow[3]) rec->refNum = atol((char*) dbrow[3]); else rec->refNum = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Fullsref.assign(dbrow[5], dblengths[5]); else rec->Fullsref = "";
			if (dbrow[6]) rec->traRefWdbeMSignal = atoll((char*) dbrow[6]); else rec->traRefWdbeMSignal = 0;
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMError::insertRec(
			WdbeMError* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	l[4] = rec->Fullsref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->refIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refUref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->traRefWdbeMSignal,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMError::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMError::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMError::insertRst(
			ListWdbeMError& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMError::updateRec(
			WdbeMError* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Fullsref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->refIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refUref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->traRefWdbeMSignal,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMError::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMError::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMError::updateRst(
			ListWdbeMError& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMError::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMError::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMError::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMError::loadRecByRef(
			ubigint ref
			, WdbeMError** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMError WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMError::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMError WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", append, refs);
};

ubigint MyTblWdbeMError::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMError& rst
		) {
	return loadRstBySQL("SELECT ref, refIxVTbl, refUref, refNum, sref, Fullsref, traRefWdbeMSignal, Comment FROM TblWdbeMError WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " ORDER BY refNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMError
 ******************************************************************************/

PgTblWdbeMError::PgTblWdbeMError() :
			TblWdbeMError()
			, PgTable()
		{
};

PgTblWdbeMError::~PgTblWdbeMError() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMError::initStatements() {
	createStatement("TblWdbeMError_insertRec", "INSERT INTO TblWdbeMError (refIxVTbl, refUref, refNum, sref, Fullsref, traRefWdbeMSignal, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWdbeMError_updateRec", "UPDATE TblWdbeMError SET refIxVTbl = $1, refUref = $2, refNum = $3, sref = $4, Fullsref = $5, traRefWdbeMSignal = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWdbeMError_removeRecByRef", "DELETE FROM TblWdbeMError WHERE ref = $1", 1);

	createStatement("TblWdbeMError_loadRecByRef", "SELECT ref, refIxVTbl, refUref, refNum, sref, Fullsref, traRefWdbeMSignal, Comment FROM TblWdbeMError WHERE ref = $1", 1);
	createStatement("TblWdbeMError_loadRefsByRetReu", "SELECT ref FROM TblWdbeMError WHERE refIxVTbl = $1 AND refUref = $2", 2);
	createStatement("TblWdbeMError_loadRstByRetReu", "SELECT ref, refIxVTbl, refUref, refNum, sref, Fullsref, traRefWdbeMSignal, Comment FROM TblWdbeMError WHERE refIxVTbl = $1 AND refUref = $2 ORDER BY refNum ASC", 2);
};

bool PgTblWdbeMError::loadRec(
			PGresult* res
			, WdbeMError** rec
		) {
	char* ptr;

	WdbeMError* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMError();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "trarefwdbemsignal"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fullsref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->traRefWdbeMSignal = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMError::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMError& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMError* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "trarefwdbemsignal"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMError();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fullsref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->traRefWdbeMSignal = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMError::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMError** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMError::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMError::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMError& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMError::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMError::loadRecBySQL(
			const string& sqlstr
			, WdbeMError** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMError::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMError::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMError& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMError::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMError::insertRec(
			WdbeMError* rec
		) {
	PGresult* res;
	char* ptr;

	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _refNum = htonl(rec->refNum);
	ubigint _traRefWdbeMSignal = htonl64(rec->traRefWdbeMSignal);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refNum,
		rec->sref.c_str(),
		rec->Fullsref.c_str(),
		(char*) &_traRefWdbeMSignal,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeMError_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMError::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMError::insertRst(
			ListWdbeMError& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMError::updateRec(
			WdbeMError* rec
		) {
	PGresult* res;

	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _refNum = htonl(rec->refNum);
	ubigint _traRefWdbeMSignal = htonl64(rec->traRefWdbeMSignal);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refNum,
		rec->sref.c_str(),
		rec->Fullsref.c_str(),
		(char*) &_traRefWdbeMSignal,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMError_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMError::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMError::updateRst(
			ListWdbeMError& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMError::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMError_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMError::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMError::loadRecByRef(
			ubigint ref
			, WdbeMError** rec
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

	return loadRecByStmt("TblWdbeMError_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMError::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblWdbeMError_loadRefsByRetReu", 2, vals, l, f, append, refs);
};

ubigint PgTblWdbeMError::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMError& rst
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWdbeMError_loadRstByRetReu", 2, vals, l, f, append, rst);
};

#endif

