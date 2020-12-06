/**
	* \file WdbeMPin.cpp
	* database access for table TblWdbeMPin (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMPin.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMPin
 ******************************************************************************/

WdbeMPin::WdbeMPin(
			const ubigint ref
			, const ubigint refWdbeCPin
			, const ubigint refWdbeMBank
			, const ubigint refJSref
			, const string sref
			, const string Location
		) {

	this->ref = ref;
	this->refWdbeCPin = refWdbeCPin;
	this->refWdbeMBank = refWdbeMBank;
	this->refJSref = refJSref;
	this->sref = sref;
	this->Location = Location;
};

bool WdbeMPin::operator==(
			const WdbeMPin& comp
		) {
	return false;
};

bool WdbeMPin::operator!=(
			const WdbeMPin& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMPin
 ******************************************************************************/

ListWdbeMPin::ListWdbeMPin() {
};

ListWdbeMPin::ListWdbeMPin(
			const ListWdbeMPin& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMPin(*(src.nodes[i]));
};

ListWdbeMPin::~ListWdbeMPin() {
	clear();
};

void ListWdbeMPin::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMPin::size() const {
	return(nodes.size());
};

void ListWdbeMPin::append(
			WdbeMPin* rec
		) {
	nodes.push_back(rec);
};

WdbeMPin* ListWdbeMPin::operator[](
			const uint ix
		) {
	WdbeMPin* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMPin& ListWdbeMPin::operator=(
			const ListWdbeMPin& src
		) {
	WdbeMPin* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMPin(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMPin::operator==(
			const ListWdbeMPin& comp
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

bool ListWdbeMPin::operator!=(
			const ListWdbeMPin& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMPin
 ******************************************************************************/

TblWdbeMPin::TblWdbeMPin() {
};

TblWdbeMPin::~TblWdbeMPin() {
};

bool TblWdbeMPin::loadRecBySQL(
			const string& sqlstr
			, WdbeMPin** rec
		) {
	return false;
};

ubigint TblWdbeMPin::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPin& rst
		) {
	return 0;
};

ubigint TblWdbeMPin::insertRec(
			WdbeMPin* rec
		) {
	return 0;
};

ubigint TblWdbeMPin::insertNewRec(
			WdbeMPin** rec
			, const ubigint refWdbeCPin
			, const ubigint refWdbeMBank
			, const ubigint refJSref
			, const string sref
			, const string Location
		) {
	ubigint retval = 0;
	WdbeMPin* _rec = NULL;

	_rec = new WdbeMPin(0, refWdbeCPin, refWdbeMBank, refJSref, sref, Location);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMPin::appendNewRecToRst(
			ListWdbeMPin& rst
			, WdbeMPin** rec
			, const ubigint refWdbeCPin
			, const ubigint refWdbeMBank
			, const ubigint refJSref
			, const string sref
			, const string Location
		) {
	ubigint retval = 0;
	WdbeMPin* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeCPin, refWdbeMBank, refJSref, sref, Location);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMPin::insertRst(
			ListWdbeMPin& rst
			, bool transact
		) {
};

void TblWdbeMPin::updateRec(
			WdbeMPin* rec
		) {
};

void TblWdbeMPin::updateRst(
			ListWdbeMPin& rst
			, bool transact
		) {
};

void TblWdbeMPin::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMPin::loadRecByRef(
			ubigint ref
			, WdbeMPin** rec
		) {
	return false;
};

ubigint TblWdbeMPin::loadRefsByBnk(
			ubigint refWdbeMBank
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMPin::loadRefsByClu(
			ubigint refWdbeCPin
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMPin::loadRstByBnk(
			ubigint refWdbeMBank
			, const bool append
			, ListWdbeMPin& rst
		) {
	return 0;
};

ubigint TblWdbeMPin::loadRstByClu(
			ubigint refWdbeCPin
			, const bool append
			, ListWdbeMPin& rst
		) {
	return 0;
};

ubigint TblWdbeMPin::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMPin& rst
		) {
	ubigint numload = 0;
	WdbeMPin* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMPin
 ******************************************************************************/

MyTblWdbeMPin::MyTblWdbeMPin() :
			TblWdbeMPin()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMPin::~MyTblWdbeMPin() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMPin::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMPin (refWdbeCPin, refWdbeMBank, refJSref, sref, Location) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMPin SET refWdbeCPin = ?, refWdbeMBank = ?, refJSref = ?, sref = ?, Location = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMPin WHERE ref = ?", false);
};

bool MyTblWdbeMPin::loadRecBySQL(
			const string& sqlstr
			, WdbeMPin** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMPin* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMPin::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMPin::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMPin();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeCPin = atoll((char*) dbrow[1]); else _rec->refWdbeCPin = 0;
		if (dbrow[2]) _rec->refWdbeMBank = atoll((char*) dbrow[2]); else _rec->refWdbeMBank = 0;
		if (dbrow[3]) _rec->refJSref = atoll((char*) dbrow[3]); else _rec->refJSref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Location.assign(dbrow[5], dblengths[5]); else _rec->Location = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMPin::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPin& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMPin* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMPin::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMPin::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMPin();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeCPin = atoll((char*) dbrow[1]); else rec->refWdbeCPin = 0;
			if (dbrow[2]) rec->refWdbeMBank = atoll((char*) dbrow[2]); else rec->refWdbeMBank = 0;
			if (dbrow[3]) rec->refJSref = atoll((char*) dbrow[3]); else rec->refJSref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Location.assign(dbrow[5], dblengths[5]); else rec->Location = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMPin::insertRec(
			WdbeMPin* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->sref.length();
	l[4] = rec->Location.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCPin,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMBank,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refJSref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Location.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMPin::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMPin::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMPin::insertRst(
			ListWdbeMPin& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMPin::updateRec(
			WdbeMPin* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();
	l[4] = rec->Location.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCPin,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMBank,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refJSref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Location.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMPin::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMPin::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMPin::updateRst(
			ListWdbeMPin& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMPin::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMPin::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMPin::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMPin::loadRecByRef(
			ubigint ref
			, WdbeMPin** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMPin WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMPin::loadRefsByBnk(
			ubigint refWdbeMBank
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMPin WHERE refWdbeMBank = " + to_string(refWdbeMBank) + "", append, refs);
};

ubigint MyTblWdbeMPin::loadRefsByClu(
			ubigint refWdbeCPin
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMPin WHERE refWdbeCPin = " + to_string(refWdbeCPin) + "", append, refs);
};

ubigint MyTblWdbeMPin::loadRstByBnk(
			ubigint refWdbeMBank
			, const bool append
			, ListWdbeMPin& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCPin, refWdbeMBank, refJSref, sref, Location FROM TblWdbeMPin WHERE refWdbeMBank = " + to_string(refWdbeMBank) + " ORDER BY sref ASC", append, rst);
};

ubigint MyTblWdbeMPin::loadRstByClu(
			ubigint refWdbeCPin
			, const bool append
			, ListWdbeMPin& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCPin, refWdbeMBank, refJSref, sref, Location FROM TblWdbeMPin WHERE refWdbeCPin = " + to_string(refWdbeCPin) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMPin
 ******************************************************************************/

PgTblWdbeMPin::PgTblWdbeMPin() :
			TblWdbeMPin()
			, PgTable()
		{
};

PgTblWdbeMPin::~PgTblWdbeMPin() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMPin::initStatements() {
	createStatement("TblWdbeMPin_insertRec", "INSERT INTO TblWdbeMPin (refWdbeCPin, refWdbeMBank, refJSref, sref, Location) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWdbeMPin_updateRec", "UPDATE TblWdbeMPin SET refWdbeCPin = $1, refWdbeMBank = $2, refJSref = $3, sref = $4, Location = $5 WHERE ref = $6", 6);
	createStatement("TblWdbeMPin_removeRecByRef", "DELETE FROM TblWdbeMPin WHERE ref = $1", 1);

	createStatement("TblWdbeMPin_loadRecByRef", "SELECT ref, refWdbeCPin, refWdbeMBank, refJSref, sref, Location FROM TblWdbeMPin WHERE ref = $1", 1);
	createStatement("TblWdbeMPin_loadRefsByBnk", "SELECT ref FROM TblWdbeMPin WHERE refWdbeMBank = $1", 1);
	createStatement("TblWdbeMPin_loadRefsByClu", "SELECT ref FROM TblWdbeMPin WHERE refWdbeCPin = $1", 1);
	createStatement("TblWdbeMPin_loadRstByBnk", "SELECT ref, refWdbeCPin, refWdbeMBank, refJSref, sref, Location FROM TblWdbeMPin WHERE refWdbeMBank = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMPin_loadRstByClu", "SELECT ref, refWdbeCPin, refWdbeMBank, refJSref, sref, Location FROM TblWdbeMPin WHERE refWdbeCPin = $1", 1);
};

bool PgTblWdbeMPin::loadRec(
			PGresult* res
			, WdbeMPin** rec
		) {
	char* ptr;

	WdbeMPin* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMPin();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecpin"),
			PQfnumber(res, "refwdbembank"),
			PQfnumber(res, "refjsref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "location")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeCPin = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMBank = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refJSref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Location.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMPin::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMPin& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMPin* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecpin"),
			PQfnumber(res, "refwdbembank"),
			PQfnumber(res, "refjsref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "location")
		};

		while (numread < numrow) {
			rec = new WdbeMPin();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeCPin = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMBank = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refJSref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Location.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMPin::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMPin** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPin::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMPin::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMPin& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPin::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMPin::loadRecBySQL(
			const string& sqlstr
			, WdbeMPin** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPin::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMPin::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPin& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPin::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMPin::insertRec(
			WdbeMPin* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeCPin = htonl64(rec->refWdbeCPin);
	ubigint _refWdbeMBank = htonl64(rec->refWdbeMBank);
	ubigint _refJSref = htonl64(rec->refJSref);

	const char* vals[] = {
		(char*) &_refWdbeCPin,
		(char*) &_refWdbeMBank,
		(char*) &_refJSref,
		rec->sref.c_str(),
		rec->Location.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMPin_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPin::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMPin::insertRst(
			ListWdbeMPin& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMPin::updateRec(
			WdbeMPin* rec
		) {
	PGresult* res;

	ubigint _refWdbeCPin = htonl64(rec->refWdbeCPin);
	ubigint _refWdbeMBank = htonl64(rec->refWdbeMBank);
	ubigint _refJSref = htonl64(rec->refJSref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeCPin,
		(char*) &_refWdbeMBank,
		(char*) &_refJSref,
		rec->sref.c_str(),
		rec->Location.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMPin_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMPin::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMPin::updateRst(
			ListWdbeMPin& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMPin::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMPin_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMPin::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMPin::loadRecByRef(
			ubigint ref
			, WdbeMPin** rec
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

	return loadRecByStmt("TblWdbeMPin_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMPin::loadRefsByBnk(
			ubigint refWdbeMBank
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMBank = htonl64(refWdbeMBank);

	const char* vals[] = {
		(char*) &_refWdbeMBank
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMPin_loadRefsByBnk", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMPin::loadRefsByClu(
			ubigint refWdbeCPin
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeCPin = htonl64(refWdbeCPin);

	const char* vals[] = {
		(char*) &_refWdbeCPin
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMPin_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMPin::loadRstByBnk(
			ubigint refWdbeMBank
			, const bool append
			, ListWdbeMPin& rst
		) {
	ubigint _refWdbeMBank = htonl64(refWdbeMBank);

	const char* vals[] = {
		(char*) &_refWdbeMBank
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMPin_loadRstByBnk", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeMPin::loadRstByClu(
			ubigint refWdbeCPin
			, const bool append
			, ListWdbeMPin& rst
		) {
	ubigint _refWdbeCPin = htonl64(refWdbeCPin);

	const char* vals[] = {
		(char*) &_refWdbeCPin
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMPin_loadRstByClu", 1, vals, l, f, append, rst);
};

#endif
