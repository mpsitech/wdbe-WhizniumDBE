/**
	* \file WdbeMCdc.cpp
	* database access for table TblWdbeMCdc (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#include "WdbeMCdc.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMCdc
 ******************************************************************************/

WdbeMCdc::WdbeMCdc(
			const ubigint ref
			, const ubigint refWdbeMModule
			, const string fckSrefWdbeMSignal
			, const string farSrefWdbeMSignal
			, const string sckSrefWdbeMSignal
			, const string sarSrefWdbeMSignal
			, const double Ratio
		) :
			ref(ref)
			, refWdbeMModule(refWdbeMModule)
			, fckSrefWdbeMSignal(fckSrefWdbeMSignal)
			, farSrefWdbeMSignal(farSrefWdbeMSignal)
			, sckSrefWdbeMSignal(sckSrefWdbeMSignal)
			, sarSrefWdbeMSignal(sarSrefWdbeMSignal)
			, Ratio(Ratio)
		{
};

bool WdbeMCdc::operator==(
			const WdbeMCdc& comp
		) {
	return false;
};

bool WdbeMCdc::operator!=(
			const WdbeMCdc& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMCdc
 ******************************************************************************/

ListWdbeMCdc::ListWdbeMCdc() {
};

ListWdbeMCdc::ListWdbeMCdc(
			const ListWdbeMCdc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMCdc(*(src.nodes[i]));
};

ListWdbeMCdc::~ListWdbeMCdc() {
	clear();
};

void ListWdbeMCdc::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMCdc::size() const {
	return(nodes.size());
};

void ListWdbeMCdc::append(
			WdbeMCdc* rec
		) {
	nodes.push_back(rec);
};

WdbeMCdc* ListWdbeMCdc::operator[](
			const uint ix
		) {
	WdbeMCdc* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMCdc& ListWdbeMCdc::operator=(
			const ListWdbeMCdc& src
		) {
	WdbeMCdc* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMCdc(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMCdc::operator==(
			const ListWdbeMCdc& comp
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

bool ListWdbeMCdc::operator!=(
			const ListWdbeMCdc& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMCdc
 ******************************************************************************/

TblWdbeMCdc::TblWdbeMCdc() {
};

TblWdbeMCdc::~TblWdbeMCdc() {
};

bool TblWdbeMCdc::loadRecBySQL(
			const string& sqlstr
			, WdbeMCdc** rec
		) {
	return false;
};

ubigint TblWdbeMCdc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCdc& rst
		) {
	return 0;
};

ubigint TblWdbeMCdc::insertRec(
			WdbeMCdc* rec
		) {
	return 0;
};

ubigint TblWdbeMCdc::insertNewRec(
			WdbeMCdc** rec
			, const ubigint refWdbeMModule
			, const string fckSrefWdbeMSignal
			, const string farSrefWdbeMSignal
			, const string sckSrefWdbeMSignal
			, const string sarSrefWdbeMSignal
			, const double Ratio
		) {
	ubigint retval = 0;
	WdbeMCdc* _rec = NULL;

	_rec = new WdbeMCdc(0, refWdbeMModule, fckSrefWdbeMSignal, farSrefWdbeMSignal, sckSrefWdbeMSignal, sarSrefWdbeMSignal, Ratio);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMCdc::appendNewRecToRst(
			ListWdbeMCdc& rst
			, WdbeMCdc** rec
			, const ubigint refWdbeMModule
			, const string fckSrefWdbeMSignal
			, const string farSrefWdbeMSignal
			, const string sckSrefWdbeMSignal
			, const string sarSrefWdbeMSignal
			, const double Ratio
		) {
	ubigint retval = 0;
	WdbeMCdc* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMModule, fckSrefWdbeMSignal, farSrefWdbeMSignal, sckSrefWdbeMSignal, sarSrefWdbeMSignal, Ratio);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMCdc::insertRst(
			ListWdbeMCdc& rst
			, bool transact
		) {
};

void TblWdbeMCdc::updateRec(
			WdbeMCdc* rec
		) {
};

void TblWdbeMCdc::updateRst(
			ListWdbeMCdc& rst
			, bool transact
		) {
};

void TblWdbeMCdc::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMCdc::loadRecByRef(
			ubigint ref
			, WdbeMCdc** rec
		) {
	return false;
};

ubigint TblWdbeMCdc::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMCdc::loadRstByMdl(
			ubigint refWdbeMModule
			, const bool append
			, ListWdbeMCdc& rst
		) {
	return 0;
};

ubigint TblWdbeMCdc::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMCdc& rst
		) {
	ubigint numload = 0;
	WdbeMCdc* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMCdc
 ******************************************************************************/

MyTblWdbeMCdc::MyTblWdbeMCdc() :
			TblWdbeMCdc()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMCdc::~MyTblWdbeMCdc() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMCdc::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMCdc (refWdbeMModule, fckSrefWdbeMSignal, farSrefWdbeMSignal, sckSrefWdbeMSignal, sarSrefWdbeMSignal, Ratio) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMCdc SET refWdbeMModule = ?, fckSrefWdbeMSignal = ?, farSrefWdbeMSignal = ?, sckSrefWdbeMSignal = ?, sarSrefWdbeMSignal = ?, Ratio = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMCdc WHERE ref = ?", false);
};

bool MyTblWdbeMCdc::loadRecBySQL(
			const string& sqlstr
			, WdbeMCdc** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMCdc* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMCdc::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMCdc::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMCdc();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMModule = atoll((char*) dbrow[1]); else _rec->refWdbeMModule = 0;
		if (dbrow[2]) _rec->fckSrefWdbeMSignal.assign(dbrow[2], dblengths[2]); else _rec->fckSrefWdbeMSignal = "";
		if (dbrow[3]) _rec->farSrefWdbeMSignal.assign(dbrow[3], dblengths[3]); else _rec->farSrefWdbeMSignal = "";
		if (dbrow[4]) _rec->sckSrefWdbeMSignal.assign(dbrow[4], dblengths[4]); else _rec->sckSrefWdbeMSignal = "";
		if (dbrow[5]) _rec->sarSrefWdbeMSignal.assign(dbrow[5], dblengths[5]); else _rec->sarSrefWdbeMSignal = "";
		if (dbrow[6]) _rec->Ratio = atof((char*) dbrow[6]); else _rec->Ratio = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMCdc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCdc& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMCdc* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMCdc::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMCdc::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMCdc();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMModule = atoll((char*) dbrow[1]); else rec->refWdbeMModule = 0;
			if (dbrow[2]) rec->fckSrefWdbeMSignal.assign(dbrow[2], dblengths[2]); else rec->fckSrefWdbeMSignal = "";
			if (dbrow[3]) rec->farSrefWdbeMSignal.assign(dbrow[3], dblengths[3]); else rec->farSrefWdbeMSignal = "";
			if (dbrow[4]) rec->sckSrefWdbeMSignal.assign(dbrow[4], dblengths[4]); else rec->sckSrefWdbeMSignal = "";
			if (dbrow[5]) rec->sarSrefWdbeMSignal.assign(dbrow[5], dblengths[5]); else rec->sarSrefWdbeMSignal = "";
			if (dbrow[6]) rec->Ratio = atof((char*) dbrow[6]); else rec->Ratio = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMCdc::insertRec(
			WdbeMCdc* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[1] = rec->fckSrefWdbeMSignal.length();
	l[2] = rec->farSrefWdbeMSignal.length();
	l[3] = rec->sckSrefWdbeMSignal.length();
	l[4] = rec->sarSrefWdbeMSignal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->fckSrefWdbeMSignal.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->farSrefWdbeMSignal.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sckSrefWdbeMSignal.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sarSrefWdbeMSignal.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->Ratio,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMCdc::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMCdc::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMCdc::insertRst(
			ListWdbeMCdc& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMCdc::updateRec(
			WdbeMCdc* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[1] = rec->fckSrefWdbeMSignal.length();
	l[2] = rec->farSrefWdbeMSignal.length();
	l[3] = rec->sckSrefWdbeMSignal.length();
	l[4] = rec->sarSrefWdbeMSignal.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMModule,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->fckSrefWdbeMSignal.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->farSrefWdbeMSignal.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sckSrefWdbeMSignal.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sarSrefWdbeMSignal.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->Ratio,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMCdc::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMCdc::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMCdc::updateRst(
			ListWdbeMCdc& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMCdc::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMCdc::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMCdc::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMCdc::loadRecByRef(
			ubigint ref
			, WdbeMCdc** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMCdc WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMCdc::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMCdc WHERE refWdbeMModule = " + to_string(refWdbeMModule) + "", append, refs);
};

ubigint MyTblWdbeMCdc::loadRstByMdl(
			ubigint refWdbeMModule
			, const bool append
			, ListWdbeMCdc& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMModule, fckSrefWdbeMSignal, farSrefWdbeMSignal, sckSrefWdbeMSignal, sarSrefWdbeMSignal, Ratio FROM TblWdbeMCdc WHERE refWdbeMModule = " + to_string(refWdbeMModule) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMCdc
 ******************************************************************************/

PgTblWdbeMCdc::PgTblWdbeMCdc() :
			TblWdbeMCdc()
			, PgTable()
		{
};

PgTblWdbeMCdc::~PgTblWdbeMCdc() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMCdc::initStatements() {
	createStatement("TblWdbeMCdc_insertRec", "INSERT INTO TblWdbeMCdc (refWdbeMModule, fckSrefWdbeMSignal, farSrefWdbeMSignal, sckSrefWdbeMSignal, sarSrefWdbeMSignal, Ratio) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6);
	createStatement("TblWdbeMCdc_updateRec", "UPDATE TblWdbeMCdc SET refWdbeMModule = $1, fckSrefWdbeMSignal = $2, farSrefWdbeMSignal = $3, sckSrefWdbeMSignal = $4, sarSrefWdbeMSignal = $5, Ratio = $6 WHERE ref = $7", 7);
	createStatement("TblWdbeMCdc_removeRecByRef", "DELETE FROM TblWdbeMCdc WHERE ref = $1", 1);

	createStatement("TblWdbeMCdc_loadRecByRef", "SELECT ref, refWdbeMModule, fckSrefWdbeMSignal, farSrefWdbeMSignal, sckSrefWdbeMSignal, sarSrefWdbeMSignal, Ratio FROM TblWdbeMCdc WHERE ref = $1", 1);
	createStatement("TblWdbeMCdc_loadRefsByMdl", "SELECT ref FROM TblWdbeMCdc WHERE refWdbeMModule = $1", 1);
	createStatement("TblWdbeMCdc_loadRstByMdl", "SELECT ref, refWdbeMModule, fckSrefWdbeMSignal, farSrefWdbeMSignal, sckSrefWdbeMSignal, sarSrefWdbeMSignal, Ratio FROM TblWdbeMCdc WHERE refWdbeMModule = $1", 1);
};

bool PgTblWdbeMCdc::loadRec(
			PGresult* res
			, WdbeMCdc** rec
		) {
	char* ptr;

	WdbeMCdc* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMCdc();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "fcksrefwdbemsignal"),
			PQfnumber(res, "farsrefwdbemsignal"),
			PQfnumber(res, "scksrefwdbemsignal"),
			PQfnumber(res, "sarsrefwdbemsignal"),
			PQfnumber(res, "ratio")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->fckSrefWdbeMSignal.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->farSrefWdbeMSignal.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sckSrefWdbeMSignal.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sarSrefWdbeMSignal.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Ratio = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMCdc::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMCdc& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMCdc* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "fcksrefwdbemsignal"),
			PQfnumber(res, "farsrefwdbemsignal"),
			PQfnumber(res, "scksrefwdbemsignal"),
			PQfnumber(res, "sarsrefwdbemsignal"),
			PQfnumber(res, "ratio")
		};

		while (numread < numrow) {
			rec = new WdbeMCdc();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->fckSrefWdbeMSignal.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->farSrefWdbeMSignal.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sckSrefWdbeMSignal.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sarSrefWdbeMSignal.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Ratio = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMCdc::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMCdc** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCdc::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMCdc::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMCdc& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCdc::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMCdc::loadRecBySQL(
			const string& sqlstr
			, WdbeMCdc** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCdc::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMCdc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCdc& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCdc::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMCdc::insertRec(
			WdbeMCdc* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	string _Ratio = to_string(rec->Ratio);

	const char* vals[] = {
		(char*) &_refWdbeMModule,
		rec->fckSrefWdbeMSignal.c_str(),
		rec->farSrefWdbeMSignal.c_str(),
		rec->sckSrefWdbeMSignal.c_str(),
		rec->sarSrefWdbeMSignal.c_str(),
		_Ratio.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMCdc_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCdc::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMCdc::insertRst(
			ListWdbeMCdc& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMCdc::updateRec(
			WdbeMCdc* rec
		) {
	PGresult* res;

	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	string _Ratio = to_string(rec->Ratio);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMModule,
		rec->fckSrefWdbeMSignal.c_str(),
		rec->farSrefWdbeMSignal.c_str(),
		rec->sckSrefWdbeMSignal.c_str(),
		rec->sarSrefWdbeMSignal.c_str(),
		_Ratio.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMCdc_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMCdc::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMCdc::updateRst(
			ListWdbeMCdc& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMCdc::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMCdc_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMCdc::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMCdc::loadRecByRef(
			ubigint ref
			, WdbeMCdc** rec
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

	return loadRecByStmt("TblWdbeMCdc_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMCdc::loadRefsByMdl(
			ubigint refWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMModule = htonl64(refWdbeMModule);

	const char* vals[] = {
		(char*) &_refWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMCdc_loadRefsByMdl", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMCdc::loadRstByMdl(
			ubigint refWdbeMModule
			, const bool append
			, ListWdbeMCdc& rst
		) {
	ubigint _refWdbeMModule = htonl64(refWdbeMModule);

	const char* vals[] = {
		(char*) &_refWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMCdc_loadRstByMdl", 1, vals, l, f, append, rst);
};

#endif
