/**
	* \file WdbeMBank.cpp
	* database access for table TblWdbeMBank (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeMBank.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMBank
 ******************************************************************************/

WdbeMBank::WdbeMBank(
			const ubigint ref
			, const ubigint refWdbeMUnit
			, const string sref
			, const string srefKVoltstd
		) {

	this->ref = ref;
	this->refWdbeMUnit = refWdbeMUnit;
	this->sref = sref;
	this->srefKVoltstd = srefKVoltstd;
};

bool WdbeMBank::operator==(
			const WdbeMBank& comp
		) {
	return false;
};

bool WdbeMBank::operator!=(
			const WdbeMBank& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMBank
 ******************************************************************************/

ListWdbeMBank::ListWdbeMBank() {
};

ListWdbeMBank::ListWdbeMBank(
			const ListWdbeMBank& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMBank(*(src.nodes[i]));
};

ListWdbeMBank::~ListWdbeMBank() {
	clear();
};

void ListWdbeMBank::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMBank::size() const {
	return(nodes.size());
};

void ListWdbeMBank::append(
			WdbeMBank* rec
		) {
	nodes.push_back(rec);
};

WdbeMBank* ListWdbeMBank::operator[](
			const uint ix
		) {
	WdbeMBank* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMBank& ListWdbeMBank::operator=(
			const ListWdbeMBank& src
		) {
	WdbeMBank* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMBank(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMBank::operator==(
			const ListWdbeMBank& comp
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

bool ListWdbeMBank::operator!=(
			const ListWdbeMBank& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMBank
 ******************************************************************************/

TblWdbeMBank::TblWdbeMBank() {
};

TblWdbeMBank::~TblWdbeMBank() {
};

bool TblWdbeMBank::loadRecBySQL(
			const string& sqlstr
			, WdbeMBank** rec
		) {
	return false;
};

ubigint TblWdbeMBank::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMBank& rst
		) {
	return 0;
};

ubigint TblWdbeMBank::insertRec(
			WdbeMBank* rec
		) {
	return 0;
};

ubigint TblWdbeMBank::insertNewRec(
			WdbeMBank** rec
			, const ubigint refWdbeMUnit
			, const string sref
			, const string srefKVoltstd
		) {
	ubigint retval = 0;
	WdbeMBank* _rec = NULL;

	_rec = new WdbeMBank(0, refWdbeMUnit, sref, srefKVoltstd);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMBank::appendNewRecToRst(
			ListWdbeMBank& rst
			, WdbeMBank** rec
			, const ubigint refWdbeMUnit
			, const string sref
			, const string srefKVoltstd
		) {
	ubigint retval = 0;
	WdbeMBank* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMUnit, sref, srefKVoltstd);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMBank::insertRst(
			ListWdbeMBank& rst
			, bool transact
		) {
};

void TblWdbeMBank::updateRec(
			WdbeMBank* rec
		) {
};

void TblWdbeMBank::updateRst(
			ListWdbeMBank& rst
			, bool transact
		) {
};

void TblWdbeMBank::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMBank::loadRecByRef(
			ubigint ref
			, WdbeMBank** rec
		) {
	return false;
};

ubigint TblWdbeMBank::loadRefsByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMBank::loadRstByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, ListWdbeMBank& rst
		) {
	return 0;
};

bool TblWdbeMBank::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMBank::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMBank& rst
		) {
	ubigint numload = 0;
	WdbeMBank* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMBank
 ******************************************************************************/

MyTblWdbeMBank::MyTblWdbeMBank() :
			TblWdbeMBank()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMBank::~MyTblWdbeMBank() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMBank::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMBank (refWdbeMUnit, sref, srefKVoltstd) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMBank SET refWdbeMUnit = ?, sref = ?, srefKVoltstd = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMBank WHERE ref = ?", false);
};

bool MyTblWdbeMBank::loadRecBySQL(
			const string& sqlstr
			, WdbeMBank** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMBank* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMBank::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMBank::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMBank();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMUnit = atoll((char*) dbrow[1]); else _rec->refWdbeMUnit = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->srefKVoltstd.assign(dbrow[3], dblengths[3]); else _rec->srefKVoltstd = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMBank::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMBank& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMBank* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMBank::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMBank::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMBank();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMUnit = atoll((char*) dbrow[1]); else rec->refWdbeMUnit = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->srefKVoltstd.assign(dbrow[3], dblengths[3]); else rec->srefKVoltstd = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMBank::insertRec(
			WdbeMBank* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->sref.length();
	l[2] = rec->srefKVoltstd.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUnit,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefKVoltstd.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMBank::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMBank::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMBank::insertRst(
			ListWdbeMBank& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMBank::updateRec(
			WdbeMBank* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->sref.length();
	l[2] = rec->srefKVoltstd.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUnit,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefKVoltstd.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMBank::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMBank::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMBank::updateRst(
			ListWdbeMBank& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMBank::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMBank::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMBank::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMBank::loadRecByRef(
			ubigint ref
			, WdbeMBank** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMBank WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMBank::loadRefsByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMBank WHERE refWdbeMUnit = " + to_string(refWdbeMUnit) + "", append, refs);
};

ubigint MyTblWdbeMBank::loadRstByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, ListWdbeMBank& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMUnit, sref, srefKVoltstd FROM TblWdbeMBank WHERE refWdbeMUnit = " + to_string(refWdbeMUnit) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMBank::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMBank WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMBank
 ******************************************************************************/

PgTblWdbeMBank::PgTblWdbeMBank() :
			TblWdbeMBank()
			, PgTable()
		{
};

PgTblWdbeMBank::~PgTblWdbeMBank() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMBank::initStatements() {
	createStatement("TblWdbeMBank_insertRec", "INSERT INTO TblWdbeMBank (refWdbeMUnit, sref, srefKVoltstd) VALUES ($1,$2,$3) RETURNING ref", 3);
	createStatement("TblWdbeMBank_updateRec", "UPDATE TblWdbeMBank SET refWdbeMUnit = $1, sref = $2, srefKVoltstd = $3 WHERE ref = $4", 4);
	createStatement("TblWdbeMBank_removeRecByRef", "DELETE FROM TblWdbeMBank WHERE ref = $1", 1);

	createStatement("TblWdbeMBank_loadRecByRef", "SELECT ref, refWdbeMUnit, sref, srefKVoltstd FROM TblWdbeMBank WHERE ref = $1", 1);
	createStatement("TblWdbeMBank_loadRefsByUnt", "SELECT ref FROM TblWdbeMBank WHERE refWdbeMUnit = $1", 1);
	createStatement("TblWdbeMBank_loadRstByUnt", "SELECT ref, refWdbeMUnit, sref, srefKVoltstd FROM TblWdbeMBank WHERE refWdbeMUnit = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMBank_loadSrfByRef", "SELECT sref FROM TblWdbeMBank WHERE ref = $1", 1);
};

bool PgTblWdbeMBank::loadRec(
			PGresult* res
			, WdbeMBank** rec
		) {
	char* ptr;

	WdbeMBank* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMBank();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemunit"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefkvoltstd")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMUnit = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->srefKVoltstd.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMBank::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMBank& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMBank* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemunit"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefkvoltstd")
		};

		while (numread < numrow) {
			rec = new WdbeMBank();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMUnit = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->srefKVoltstd.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMBank::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMBank** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMBank::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMBank::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMBank& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMBank::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMBank::loadRecBySQL(
			const string& sqlstr
			, WdbeMBank** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMBank::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMBank::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMBank& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMBank::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMBank::insertRec(
			WdbeMBank* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);

	const char* vals[] = {
		(char*) &_refWdbeMUnit,
		rec->sref.c_str(),
		rec->srefKVoltstd.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMBank_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMBank::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMBank::insertRst(
			ListWdbeMBank& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMBank::updateRec(
			WdbeMBank* rec
		) {
	PGresult* res;

	ubigint _refWdbeMUnit = htonl64(rec->refWdbeMUnit);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMUnit,
		rec->sref.c_str(),
		rec->srefKVoltstd.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMBank_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMBank::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMBank::updateRst(
			ListWdbeMBank& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMBank::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMBank_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMBank::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMBank::loadRecByRef(
			ubigint ref
			, WdbeMBank** rec
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

	return loadRecByStmt("TblWdbeMBank_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMBank::loadRefsByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMUnit = htonl64(refWdbeMUnit);

	const char* vals[] = {
		(char*) &_refWdbeMUnit
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMBank_loadRefsByUnt", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMBank::loadRstByUnt(
			ubigint refWdbeMUnit
			, const bool append
			, ListWdbeMBank& rst
		) {
	ubigint _refWdbeMUnit = htonl64(refWdbeMUnit);

	const char* vals[] = {
		(char*) &_refWdbeMUnit
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMBank_loadRstByUnt", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMBank::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMBank_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

