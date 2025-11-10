/**
	* \file WdbeAMErrorPar.cpp
	* database access for table TblWdbeAMErrorPar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAMErrorPar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMErrorPar
 ******************************************************************************/

WdbeAMErrorPar::WdbeAMErrorPar(
			const ubigint ref
			, const ubigint errRefWdbeMError
			, const uint errNum
			, const string sref
			, const uint ixWdbeVPartype
			, const ubigint refWdbeMVector
			, const utinyint Length
			, const string Comment
		) :
			ref(ref)
			, errRefWdbeMError(errRefWdbeMError)
			, errNum(errNum)
			, sref(sref)
			, ixWdbeVPartype(ixWdbeVPartype)
			, refWdbeMVector(refWdbeMVector)
			, Length(Length)
			, Comment(Comment)
		{
};

bool WdbeAMErrorPar::operator==(
			const WdbeAMErrorPar& comp
		) {
	return false;
};

bool WdbeAMErrorPar::operator!=(
			const WdbeAMErrorPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMErrorPar
 ******************************************************************************/

ListWdbeAMErrorPar::ListWdbeAMErrorPar() {
};

ListWdbeAMErrorPar::ListWdbeAMErrorPar(
			const ListWdbeAMErrorPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMErrorPar(*(src.nodes[i]));
};

ListWdbeAMErrorPar::~ListWdbeAMErrorPar() {
	clear();
};

void ListWdbeAMErrorPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMErrorPar::size() const {
	return(nodes.size());
};

void ListWdbeAMErrorPar::append(
			WdbeAMErrorPar* rec
		) {
	nodes.push_back(rec);
};

WdbeAMErrorPar* ListWdbeAMErrorPar::operator[](
			const uint ix
		) {
	WdbeAMErrorPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMErrorPar& ListWdbeAMErrorPar::operator=(
			const ListWdbeAMErrorPar& src
		) {
	WdbeAMErrorPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMErrorPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMErrorPar::operator==(
			const ListWdbeAMErrorPar& comp
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

bool ListWdbeAMErrorPar::operator!=(
			const ListWdbeAMErrorPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMErrorPar
 ******************************************************************************/

TblWdbeAMErrorPar::TblWdbeAMErrorPar() {
};

TblWdbeAMErrorPar::~TblWdbeAMErrorPar() {
};

bool TblWdbeAMErrorPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMErrorPar** rec
		) {
	return false;
};

ubigint TblWdbeAMErrorPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMErrorPar& rst
		) {
	return 0;
};

ubigint TblWdbeAMErrorPar::insertRec(
			WdbeAMErrorPar* rec
		) {
	return 0;
};

ubigint TblWdbeAMErrorPar::insertNewRec(
			WdbeAMErrorPar** rec
			, const ubigint errRefWdbeMError
			, const uint errNum
			, const string sref
			, const uint ixWdbeVPartype
			, const ubigint refWdbeMVector
			, const utinyint Length
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAMErrorPar* _rec = NULL;

	_rec = new WdbeAMErrorPar(0, errRefWdbeMError, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMErrorPar::appendNewRecToRst(
			ListWdbeAMErrorPar& rst
			, WdbeAMErrorPar** rec
			, const ubigint errRefWdbeMError
			, const uint errNum
			, const string sref
			, const uint ixWdbeVPartype
			, const ubigint refWdbeMVector
			, const utinyint Length
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAMErrorPar* _rec = NULL;

	retval = insertNewRec(&_rec, errRefWdbeMError, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMErrorPar::insertRst(
			ListWdbeAMErrorPar& rst
			, bool transact
		) {
};

void TblWdbeAMErrorPar::updateRec(
			WdbeAMErrorPar* rec
		) {
};

void TblWdbeAMErrorPar::updateRst(
			ListWdbeAMErrorPar& rst
			, bool transact
		) {
};

void TblWdbeAMErrorPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMErrorPar::loadRecByRef(
			ubigint ref
			, WdbeAMErrorPar** rec
		) {
	return false;
};

ubigint TblWdbeAMErrorPar::loadRefsByErr(
			ubigint errRefWdbeMError
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMErrorPar::loadRstByErr(
			ubigint errRefWdbeMError
			, const bool append
			, ListWdbeAMErrorPar& rst
		) {
	return 0;
};

ubigint TblWdbeAMErrorPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMErrorPar& rst
		) {
	ubigint numload = 0;
	WdbeAMErrorPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMErrorPar
 ******************************************************************************/

MyTblWdbeAMErrorPar::MyTblWdbeAMErrorPar() :
			TblWdbeAMErrorPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMErrorPar::~MyTblWdbeAMErrorPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMErrorPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMErrorPar (errRefWdbeMError, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMErrorPar SET errRefWdbeMError = ?, errNum = ?, sref = ?, ixWdbeVPartype = ?, refWdbeMVector = ?, Length = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMErrorPar WHERE ref = ?", false);
};

bool MyTblWdbeAMErrorPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMErrorPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMErrorPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMErrorPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMErrorPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMErrorPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->errRefWdbeMError = atoll((char*) dbrow[1]); else _rec->errRefWdbeMError = 0;
		if (dbrow[2]) _rec->errNum = atol((char*) dbrow[2]); else _rec->errNum = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->ixWdbeVPartype = atol((char*) dbrow[4]); else _rec->ixWdbeVPartype = 0;
		if (dbrow[5]) _rec->refWdbeMVector = atoll((char*) dbrow[5]); else _rec->refWdbeMVector = 0;
		if (dbrow[6]) _rec->Length = atoi((char*) dbrow[6]); else _rec->Length = 0;
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMErrorPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMErrorPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMErrorPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMErrorPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMErrorPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMErrorPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->errRefWdbeMError = atoll((char*) dbrow[1]); else rec->errRefWdbeMError = 0;
			if (dbrow[2]) rec->errNum = atol((char*) dbrow[2]); else rec->errNum = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->ixWdbeVPartype = atol((char*) dbrow[4]); else rec->ixWdbeVPartype = 0;
			if (dbrow[5]) rec->refWdbeMVector = atoll((char*) dbrow[5]); else rec->refWdbeMVector = 0;
			if (dbrow[6]) rec->Length = atoi((char*) dbrow[6]); else rec->Length = 0;
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMErrorPar::insertRec(
			WdbeAMErrorPar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[2] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->errRefWdbeMError,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->errNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVPartype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMVector,&(l[4]),&(n[4]),&(e[4])),
		bindUtinyint(&rec->Length,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMErrorPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMErrorPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMErrorPar::insertRst(
			ListWdbeAMErrorPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMErrorPar::updateRec(
			WdbeAMErrorPar* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[2] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->errRefWdbeMError,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->errNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVPartype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMVector,&(l[4]),&(n[4]),&(e[4])),
		bindUtinyint(&rec->Length,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->ref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMErrorPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMErrorPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMErrorPar::updateRst(
			ListWdbeAMErrorPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMErrorPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMErrorPar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMErrorPar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMErrorPar::loadRecByRef(
			ubigint ref
			, WdbeAMErrorPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMErrorPar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMErrorPar::loadRefsByErr(
			ubigint errRefWdbeMError
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMErrorPar WHERE errRefWdbeMError = " + to_string(errRefWdbeMError) + "", append, refs);
};

ubigint MyTblWdbeAMErrorPar::loadRstByErr(
			ubigint errRefWdbeMError
			, const bool append
			, ListWdbeAMErrorPar& rst
		) {
	return loadRstBySQL("SELECT ref, errRefWdbeMError, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment FROM TblWdbeAMErrorPar WHERE errRefWdbeMError = " + to_string(errRefWdbeMError) + " ORDER BY errNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMErrorPar
 ******************************************************************************/

PgTblWdbeAMErrorPar::PgTblWdbeAMErrorPar() :
			TblWdbeAMErrorPar()
			, PgTable()
		{
};

PgTblWdbeAMErrorPar::~PgTblWdbeAMErrorPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMErrorPar::initStatements() {
	createStatement("TblWdbeAMErrorPar_insertRec", "INSERT INTO TblWdbeAMErrorPar (errRefWdbeMError, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING ref", 7);
	createStatement("TblWdbeAMErrorPar_updateRec", "UPDATE TblWdbeAMErrorPar SET errRefWdbeMError = $1, errNum = $2, sref = $3, ixWdbeVPartype = $4, refWdbeMVector = $5, Length = $6, Comment = $7 WHERE ref = $8", 8);
	createStatement("TblWdbeAMErrorPar_removeRecByRef", "DELETE FROM TblWdbeAMErrorPar WHERE ref = $1", 1);

	createStatement("TblWdbeAMErrorPar_loadRecByRef", "SELECT ref, errRefWdbeMError, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment FROM TblWdbeAMErrorPar WHERE ref = $1", 1);
	createStatement("TblWdbeAMErrorPar_loadRefsByErr", "SELECT ref FROM TblWdbeAMErrorPar WHERE errRefWdbeMError = $1", 1);
	createStatement("TblWdbeAMErrorPar_loadRstByErr", "SELECT ref, errRefWdbeMError, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment FROM TblWdbeAMErrorPar WHERE errRefWdbeMError = $1 ORDER BY errNum ASC", 1);
};

bool PgTblWdbeAMErrorPar::loadRec(
			PGresult* res
			, WdbeAMErrorPar** rec
		) {
	char* ptr;

	WdbeAMErrorPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMErrorPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "errrefwdbemerror"),
			PQfnumber(res, "errnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwdbevpartype"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->errRefWdbeMError = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->errNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWdbeVPartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWdbeMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Length = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMErrorPar::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMErrorPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMErrorPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "errrefwdbemerror"),
			PQfnumber(res, "errnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwdbevpartype"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeAMErrorPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->errRefWdbeMError = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->errNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWdbeVPartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWdbeMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Length = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMErrorPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMErrorPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMErrorPar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMErrorPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMErrorPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMErrorPar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMErrorPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMErrorPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMErrorPar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMErrorPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMErrorPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMErrorPar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMErrorPar::insertRec(
			WdbeAMErrorPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _errRefWdbeMError = htonl64(rec->errRefWdbeMError);
	uint _errNum = htonl(rec->errNum);
	uint _ixWdbeVPartype = htonl(rec->ixWdbeVPartype);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	usmallint _Length = htons(rec->Length);

	const char* vals[] = {
		(char*) &_errRefWdbeMError,
		(char*) &_errNum,
		rec->sref.c_str(),
		(char*) &_ixWdbeVPartype,
		(char*) &_refWdbeMVector,
		(char*) &_Length,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 1, 0, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMErrorPar_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMErrorPar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMErrorPar::insertRst(
			ListWdbeAMErrorPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMErrorPar::updateRec(
			WdbeAMErrorPar* rec
		) {
	PGresult* res;

	ubigint _errRefWdbeMError = htonl64(rec->errRefWdbeMError);
	uint _errNum = htonl(rec->errNum);
	uint _ixWdbeVPartype = htonl(rec->ixWdbeVPartype);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	usmallint _Length = htons(rec->Length);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_errRefWdbeMError,
		(char*) &_errNum,
		rec->sref.c_str(),
		(char*) &_ixWdbeVPartype,
		(char*) &_refWdbeMVector,
		(char*) &_Length,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMErrorPar_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMErrorPar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMErrorPar::updateRst(
			ListWdbeAMErrorPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMErrorPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMErrorPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMErrorPar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMErrorPar::loadRecByRef(
			ubigint ref
			, WdbeAMErrorPar** rec
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

	return loadRecByStmt("TblWdbeAMErrorPar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMErrorPar::loadRefsByErr(
			ubigint errRefWdbeMError
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _errRefWdbeMError = htonl64(errRefWdbeMError);

	const char* vals[] = {
		(char*) &_errRefWdbeMError
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMErrorPar_loadRefsByErr", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMErrorPar::loadRstByErr(
			ubigint errRefWdbeMError
			, const bool append
			, ListWdbeAMErrorPar& rst
		) {
	ubigint _errRefWdbeMError = htonl64(errRefWdbeMError);

	const char* vals[] = {
		(char*) &_errRefWdbeMError
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMErrorPar_loadRstByErr", 1, vals, l, f, append, rst);
};

#endif
