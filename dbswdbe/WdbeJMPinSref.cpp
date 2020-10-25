/**
	* \file WdbeJMPinSref.cpp
	* database access for table TblWdbeJMPinSref (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeJMPinSref.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeJMPinSref
 ******************************************************************************/

WdbeJMPinSref::WdbeJMPinSref(
			const ubigint ref
			, const ubigint refWdbeMPin
			, const ubigint x1RefWdbeMPeripheral
			, const string sref
		) {

	this->ref = ref;
	this->refWdbeMPin = refWdbeMPin;
	this->x1RefWdbeMPeripheral = x1RefWdbeMPeripheral;
	this->sref = sref;
};

bool WdbeJMPinSref::operator==(
			const WdbeJMPinSref& comp
		) {
	return false;
};

bool WdbeJMPinSref::operator!=(
			const WdbeJMPinSref& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeJMPinSref
 ******************************************************************************/

ListWdbeJMPinSref::ListWdbeJMPinSref() {
};

ListWdbeJMPinSref::ListWdbeJMPinSref(
			const ListWdbeJMPinSref& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeJMPinSref(*(src.nodes[i]));
};

ListWdbeJMPinSref::~ListWdbeJMPinSref() {
	clear();
};

void ListWdbeJMPinSref::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeJMPinSref::size() const {
	return(nodes.size());
};

void ListWdbeJMPinSref::append(
			WdbeJMPinSref* rec
		) {
	nodes.push_back(rec);
};

WdbeJMPinSref* ListWdbeJMPinSref::operator[](
			const uint ix
		) {
	WdbeJMPinSref* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeJMPinSref& ListWdbeJMPinSref::operator=(
			const ListWdbeJMPinSref& src
		) {
	WdbeJMPinSref* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeJMPinSref(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeJMPinSref::operator==(
			const ListWdbeJMPinSref& comp
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

bool ListWdbeJMPinSref::operator!=(
			const ListWdbeJMPinSref& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeJMPinSref
 ******************************************************************************/

TblWdbeJMPinSref::TblWdbeJMPinSref() {
};

TblWdbeJMPinSref::~TblWdbeJMPinSref() {
};

bool TblWdbeJMPinSref::loadRecBySQL(
			const string& sqlstr
			, WdbeJMPinSref** rec
		) {
	return false;
};

ubigint TblWdbeJMPinSref::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMPinSref& rst
		) {
	return 0;
};

ubigint TblWdbeJMPinSref::insertRec(
			WdbeJMPinSref* rec
		) {
	return 0;
};

ubigint TblWdbeJMPinSref::insertNewRec(
			WdbeJMPinSref** rec
			, const ubigint refWdbeMPin
			, const ubigint x1RefWdbeMPeripheral
			, const string sref
		) {
	ubigint retval = 0;
	WdbeJMPinSref* _rec = NULL;

	_rec = new WdbeJMPinSref(0, refWdbeMPin, x1RefWdbeMPeripheral, sref);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeJMPinSref::appendNewRecToRst(
			ListWdbeJMPinSref& rst
			, WdbeJMPinSref** rec
			, const ubigint refWdbeMPin
			, const ubigint x1RefWdbeMPeripheral
			, const string sref
		) {
	ubigint retval = 0;
	WdbeJMPinSref* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMPin, x1RefWdbeMPeripheral, sref);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeJMPinSref::insertRst(
			ListWdbeJMPinSref& rst
			, bool transact
		) {
};

void TblWdbeJMPinSref::updateRec(
			WdbeJMPinSref* rec
		) {
};

void TblWdbeJMPinSref::updateRst(
			ListWdbeJMPinSref& rst
			, bool transact
		) {
};

void TblWdbeJMPinSref::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeJMPinSref::loadRecByRef(
			ubigint ref
			, WdbeJMPinSref** rec
		) {
	return false;
};

bool TblWdbeJMPinSref::loadRecByPinPph(
			ubigint refWdbeMPin
			, ubigint x1RefWdbeMPeripheral
			, WdbeJMPinSref** rec
		) {
	return false;
};

ubigint TblWdbeJMPinSref::loadRefsByPin(
			ubigint refWdbeMPin
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeJMPinSref::loadRstByPin(
			ubigint refWdbeMPin
			, const bool append
			, ListWdbeJMPinSref& rst
		) {
	return 0;
};

ubigint TblWdbeJMPinSref::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeJMPinSref& rst
		) {
	ubigint numload = 0;
	WdbeJMPinSref* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeJMPinSref
 ******************************************************************************/

MyTblWdbeJMPinSref::MyTblWdbeJMPinSref() :
			TblWdbeJMPinSref()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeJMPinSref::~MyTblWdbeJMPinSref() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeJMPinSref::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeJMPinSref (refWdbeMPin, x1RefWdbeMPeripheral, sref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeJMPinSref SET refWdbeMPin = ?, x1RefWdbeMPeripheral = ?, sref = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeJMPinSref WHERE ref = ?", false);
};

bool MyTblWdbeJMPinSref::loadRecBySQL(
			const string& sqlstr
			, WdbeJMPinSref** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeJMPinSref* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJMPinSref::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJMPinSref::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeJMPinSref();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMPin = atoll((char*) dbrow[1]); else _rec->refWdbeMPin = 0;
		if (dbrow[2]) _rec->x1RefWdbeMPeripheral = atoll((char*) dbrow[2]); else _rec->x1RefWdbeMPeripheral = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeJMPinSref::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMPinSref& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeJMPinSref* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeJMPinSref::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeJMPinSref::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeJMPinSref();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMPin = atoll((char*) dbrow[1]); else rec->refWdbeMPin = 0;
			if (dbrow[2]) rec->x1RefWdbeMPeripheral = atoll((char*) dbrow[2]); else rec->x1RefWdbeMPeripheral = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeJMPinSref::insertRec(
			WdbeJMPinSref* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMPin,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWdbeMPeripheral,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeJMPinSref::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeJMPinSref::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeJMPinSref::insertRst(
			ListWdbeJMPinSref& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeJMPinSref::updateRec(
			WdbeJMPinSref* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMPin,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWdbeMPeripheral,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeJMPinSref::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeJMPinSref::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeJMPinSref::updateRst(
			ListWdbeJMPinSref& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeJMPinSref::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeJMPinSref::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeJMPinSref::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeJMPinSref::loadRecByRef(
			ubigint ref
			, WdbeJMPinSref** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeJMPinSref WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeJMPinSref::loadRecByPinPph(
			ubigint refWdbeMPin
			, ubigint x1RefWdbeMPeripheral
			, WdbeJMPinSref** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMPin, x1RefWdbeMPeripheral, sref FROM TblWdbeJMPinSref WHERE refWdbeMPin = " + to_string(refWdbeMPin) + " AND x1RefWdbeMPeripheral = " + to_string(x1RefWdbeMPeripheral) + "", rec);
};

ubigint MyTblWdbeJMPinSref::loadRefsByPin(
			ubigint refWdbeMPin
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeJMPinSref WHERE refWdbeMPin = " + to_string(refWdbeMPin) + "", append, refs);
};

ubigint MyTblWdbeJMPinSref::loadRstByPin(
			ubigint refWdbeMPin
			, const bool append
			, ListWdbeJMPinSref& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMPin, x1RefWdbeMPeripheral, sref FROM TblWdbeJMPinSref WHERE refWdbeMPin = " + to_string(refWdbeMPin) + " ORDER BY x1RefWdbeMPeripheral ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeJMPinSref
 ******************************************************************************/

PgTblWdbeJMPinSref::PgTblWdbeJMPinSref() :
			TblWdbeJMPinSref()
			, PgTable()
		{
};

PgTblWdbeJMPinSref::~PgTblWdbeJMPinSref() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeJMPinSref::initStatements() {
	createStatement("TblWdbeJMPinSref_insertRec", "INSERT INTO TblWdbeJMPinSref (refWdbeMPin, x1RefWdbeMPeripheral, sref) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeJMPinSref_updateRec", "UPDATE TblWdbeJMPinSref SET refWdbeMPin = $1, x1RefWdbeMPeripheral = $2, sref = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeJMPinSref_removeRecByRef", "DELETE FROM TblWdbeJMPinSref WHERE ref = $1", 1);

	createStatement("TblWdbeJMPinSref_loadRecByRef", "SELECT ref, refWdbeMPin, x1RefWdbeMPeripheral, sref FROM TblWdbeJMPinSref WHERE ref = $1", 1);
	createStatement("TblWdbeJMPinSref_loadRecByPinPph", "SELECT ref, refWdbeMPin, x1RefWdbeMPeripheral, sref FROM TblWdbeJMPinSref WHERE refWdbeMPin = $1 AND x1RefWdbeMPeripheral = $2", 2);
	createStatement("TblWdbeJMPinSref_loadRefsByPin", "SELECT ref FROM TblWdbeJMPinSref WHERE refWdbeMPin = $1", 1);
	createStatement("TblWdbeJMPinSref_loadRstByPin", "SELECT ref, refWdbeMPin, x1RefWdbeMPeripheral, sref FROM TblWdbeJMPinSref WHERE refWdbeMPin = $1 ORDER BY x1RefWdbeMPeripheral ASC", 1);
};

bool PgTblWdbeJMPinSref::loadRec(
			PGresult* res
			, WdbeJMPinSref** rec
		) {
	char* ptr;

	WdbeJMPinSref* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeJMPinSref();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbempin"),
			PQfnumber(res, "x1refwdbemperipheral"),
			PQfnumber(res, "sref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMPin = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWdbeMPeripheral = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeJMPinSref::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeJMPinSref& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeJMPinSref* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbempin"),
			PQfnumber(res, "x1refwdbemperipheral"),
			PQfnumber(res, "sref")
		};

		while (numread < numrow) {
			rec = new WdbeJMPinSref();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMPin = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWdbeMPeripheral = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeJMPinSref::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeJMPinSref** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMPinSref::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJMPinSref::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeJMPinSref& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMPinSref::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeJMPinSref::loadRecBySQL(
			const string& sqlstr
			, WdbeJMPinSref** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMPinSref::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeJMPinSref::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeJMPinSref& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMPinSref::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeJMPinSref::insertRec(
			WdbeJMPinSref* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMPin = htonl64(rec->refWdbeMPin);
	ubigint _x1RefWdbeMPeripheral = htonl64(rec->x1RefWdbeMPeripheral);

	const char* vals[] = {
		(char*) &_refWdbeMPin,
		(char*) &_x1RefWdbeMPeripheral,
		rec->sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeJMPinSref_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeJMPinSref::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeJMPinSref::insertRst(
			ListWdbeJMPinSref& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeJMPinSref::updateRec(
			WdbeJMPinSref* rec
		) {
	PGresult* res;

	ubigint _refWdbeMPin = htonl64(rec->refWdbeMPin);
	ubigint _x1RefWdbeMPeripheral = htonl64(rec->x1RefWdbeMPeripheral);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMPin,
		(char*) &_x1RefWdbeMPeripheral,
		rec->sref.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeJMPinSref_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJMPinSref::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeJMPinSref::updateRst(
			ListWdbeJMPinSref& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeJMPinSref::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeJMPinSref_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeJMPinSref::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeJMPinSref::loadRecByRef(
			ubigint ref
			, WdbeJMPinSref** rec
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

	return loadRecByStmt("TblWdbeJMPinSref_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeJMPinSref::loadRecByPinPph(
			ubigint refWdbeMPin
			, ubigint x1RefWdbeMPeripheral
			, WdbeJMPinSref** rec
		) {
	ubigint _refWdbeMPin = htonl64(refWdbeMPin);
	ubigint _x1RefWdbeMPeripheral = htonl64(x1RefWdbeMPeripheral);

	const char* vals[] = {
		(char*) &_refWdbeMPin,
		(char*) &_x1RefWdbeMPeripheral
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblWdbeJMPinSref_loadRecByPinPph", 2, vals, l, f, rec);
};

ubigint PgTblWdbeJMPinSref::loadRefsByPin(
			ubigint refWdbeMPin
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMPin = htonl64(refWdbeMPin);

	const char* vals[] = {
		(char*) &_refWdbeMPin
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeJMPinSref_loadRefsByPin", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeJMPinSref::loadRstByPin(
			ubigint refWdbeMPin
			, const bool append
			, ListWdbeJMPinSref& rst
		) {
	ubigint _refWdbeMPin = htonl64(refWdbeMPin);

	const char* vals[] = {
		(char*) &_refWdbeMPin
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeJMPinSref_loadRstByPin", 1, vals, l, f, append, rst);
};

#endif

