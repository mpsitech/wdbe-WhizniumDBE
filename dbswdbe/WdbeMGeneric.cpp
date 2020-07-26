/**
	* \file WdbeMGeneric.cpp
	* database access for table TblWdbeMGeneric (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeMGeneric.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMGeneric
 ******************************************************************************/

WdbeMGeneric::WdbeMGeneric(
			const ubigint ref
			, const ubigint refWdbeCGeneric
			, const ubigint mdlRefWdbeMModule
			, const uint mdlNum
			, const string sref
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Defval
			, const string srcSrefWdbeMGeneric
			, const string Comment
		) {

	this->ref = ref;
	this->refWdbeCGeneric = refWdbeCGeneric;
	this->mdlRefWdbeMModule = mdlRefWdbeMModule;
	this->mdlNum = mdlNum;
	this->sref = sref;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Defval = Defval;
	this->srcSrefWdbeMGeneric = srcSrefWdbeMGeneric;
	this->Comment = Comment;
};

bool WdbeMGeneric::operator==(
			const WdbeMGeneric& comp
		) {
	return false;
};

bool WdbeMGeneric::operator!=(
			const WdbeMGeneric& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMGeneric
 ******************************************************************************/

ListWdbeMGeneric::ListWdbeMGeneric() {
};

ListWdbeMGeneric::ListWdbeMGeneric(
			const ListWdbeMGeneric& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMGeneric(*(src.nodes[i]));
};

ListWdbeMGeneric::~ListWdbeMGeneric() {
	clear();
};

void ListWdbeMGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMGeneric::size() const {
	return(nodes.size());
};

void ListWdbeMGeneric::append(
			WdbeMGeneric* rec
		) {
	nodes.push_back(rec);
};

WdbeMGeneric* ListWdbeMGeneric::operator[](
			const uint ix
		) {
	WdbeMGeneric* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMGeneric& ListWdbeMGeneric::operator=(
			const ListWdbeMGeneric& src
		) {
	WdbeMGeneric* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMGeneric(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMGeneric::operator==(
			const ListWdbeMGeneric& comp
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

bool ListWdbeMGeneric::operator!=(
			const ListWdbeMGeneric& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMGeneric
 ******************************************************************************/

TblWdbeMGeneric::TblWdbeMGeneric() {
};

TblWdbeMGeneric::~TblWdbeMGeneric() {
};

bool TblWdbeMGeneric::loadRecBySQL(
			const string& sqlstr
			, WdbeMGeneric** rec
		) {
	return false;
};

ubigint TblWdbeMGeneric::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	return 0;
};

ubigint TblWdbeMGeneric::insertRec(
			WdbeMGeneric* rec
		) {
	return 0;
};

ubigint TblWdbeMGeneric::insertNewRec(
			WdbeMGeneric** rec
			, const ubigint refWdbeCGeneric
			, const ubigint mdlRefWdbeMModule
			, const uint mdlNum
			, const string sref
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Defval
			, const string srcSrefWdbeMGeneric
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMGeneric* _rec = NULL;

	_rec = new WdbeMGeneric(0, refWdbeCGeneric, mdlRefWdbeMModule, mdlNum, sref, srefWdbeKHdltype, Width, Minmax, Defval, srcSrefWdbeMGeneric, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMGeneric::appendNewRecToRst(
			ListWdbeMGeneric& rst
			, WdbeMGeneric** rec
			, const ubigint refWdbeCGeneric
			, const ubigint mdlRefWdbeMModule
			, const uint mdlNum
			, const string sref
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Defval
			, const string srcSrefWdbeMGeneric
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMGeneric* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeCGeneric, mdlRefWdbeMModule, mdlNum, sref, srefWdbeKHdltype, Width, Minmax, Defval, srcSrefWdbeMGeneric, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMGeneric::insertRst(
			ListWdbeMGeneric& rst
			, bool transact
		) {
};

void TblWdbeMGeneric::updateRec(
			WdbeMGeneric* rec
		) {
};

void TblWdbeMGeneric::updateRst(
			ListWdbeMGeneric& rst
			, bool transact
		) {
};

void TblWdbeMGeneric::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMGeneric::loadRecByRef(
			ubigint ref
			, WdbeMGeneric** rec
		) {
	return false;
};

ubigint TblWdbeMGeneric::loadRefsByClu(
			ubigint refWdbeCGeneric
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMGeneric::loadRefsByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMGeneric::loadRstByClu(
			ubigint refWdbeCGeneric
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	return 0;
};

ubigint TblWdbeMGeneric::loadRstByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	return 0;
};

bool TblWdbeMGeneric::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMGeneric::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	ubigint numload = 0;
	WdbeMGeneric* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMGeneric
 ******************************************************************************/

MyTblWdbeMGeneric::MyTblWdbeMGeneric() :
			TblWdbeMGeneric()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMGeneric::~MyTblWdbeMGeneric() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMGeneric::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMGeneric (refWdbeCGeneric, mdlRefWdbeMModule, mdlNum, sref, srefWdbeKHdltype, Width, Minmax, Defval, srcSrefWdbeMGeneric, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMGeneric SET refWdbeCGeneric = ?, mdlRefWdbeMModule = ?, mdlNum = ?, sref = ?, srefWdbeKHdltype = ?, Width = ?, Minmax = ?, Defval = ?, srcSrefWdbeMGeneric = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMGeneric WHERE ref = ?", false);
};

bool MyTblWdbeMGeneric::loadRecBySQL(
			const string& sqlstr
			, WdbeMGeneric** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMGeneric* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMGeneric::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMGeneric::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMGeneric();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeCGeneric = atoll((char*) dbrow[1]); else _rec->refWdbeCGeneric = 0;
		if (dbrow[2]) _rec->mdlRefWdbeMModule = atoll((char*) dbrow[2]); else _rec->mdlRefWdbeMModule = 0;
		if (dbrow[3]) _rec->mdlNum = atol((char*) dbrow[3]); else _rec->mdlNum = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->srefWdbeKHdltype.assign(dbrow[5], dblengths[5]); else _rec->srefWdbeKHdltype = "";
		if (dbrow[6]) _rec->Width = atoi((char*) dbrow[6]); else _rec->Width = 0;
		if (dbrow[7]) _rec->Minmax.assign(dbrow[7], dblengths[7]); else _rec->Minmax = "";
		if (dbrow[8]) _rec->Defval.assign(dbrow[8], dblengths[8]); else _rec->Defval = "";
		if (dbrow[9]) _rec->srcSrefWdbeMGeneric.assign(dbrow[9], dblengths[9]); else _rec->srcSrefWdbeMGeneric = "";
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMGeneric::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMGeneric* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMGeneric::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMGeneric::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMGeneric();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeCGeneric = atoll((char*) dbrow[1]); else rec->refWdbeCGeneric = 0;
			if (dbrow[2]) rec->mdlRefWdbeMModule = atoll((char*) dbrow[2]); else rec->mdlRefWdbeMModule = 0;
			if (dbrow[3]) rec->mdlNum = atol((char*) dbrow[3]); else rec->mdlNum = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->srefWdbeKHdltype.assign(dbrow[5], dblengths[5]); else rec->srefWdbeKHdltype = "";
			if (dbrow[6]) rec->Width = atoi((char*) dbrow[6]); else rec->Width = 0;
			if (dbrow[7]) rec->Minmax.assign(dbrow[7], dblengths[7]); else rec->Minmax = "";
			if (dbrow[8]) rec->Defval.assign(dbrow[8], dblengths[8]); else rec->Defval = "";
			if (dbrow[9]) rec->srcSrefWdbeMGeneric.assign(dbrow[9], dblengths[9]); else rec->srcSrefWdbeMGeneric = "";
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMGeneric::insertRec(
			WdbeMGeneric* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	l[4] = rec->srefWdbeKHdltype.length();
	l[6] = rec->Minmax.length();
	l[7] = rec->Defval.length();
	l[8] = rec->srcSrefWdbeMGeneric.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCGeneric,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->mdlNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Width,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->srcSrefWdbeMGeneric.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMGeneric::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMGeneric::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMGeneric::insertRst(
			ListWdbeMGeneric& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMGeneric::updateRec(
			WdbeMGeneric* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->sref.length();
	l[4] = rec->srefWdbeKHdltype.length();
	l[6] = rec->Minmax.length();
	l[7] = rec->Defval.length();
	l[8] = rec->srcSrefWdbeMGeneric.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCGeneric,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->mdlNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Width,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->srcSrefWdbeMGeneric.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMGeneric::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMGeneric::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMGeneric::updateRst(
			ListWdbeMGeneric& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMGeneric::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMGeneric::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMGeneric::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMGeneric::loadRecByRef(
			ubigint ref
			, WdbeMGeneric** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMGeneric WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMGeneric::loadRefsByClu(
			ubigint refWdbeCGeneric
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMGeneric WHERE refWdbeCGeneric = " + to_string(refWdbeCGeneric) + "", append, refs);
};

ubigint MyTblWdbeMGeneric::loadRefsByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMGeneric WHERE mdlRefWdbeMModule = " + to_string(mdlRefWdbeMModule) + "", append, refs);
};

ubigint MyTblWdbeMGeneric::loadRstByClu(
			ubigint refWdbeCGeneric
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCGeneric, mdlRefWdbeMModule, mdlNum, sref, srefWdbeKHdltype, Width, Minmax, Defval, srcSrefWdbeMGeneric, Comment FROM TblWdbeMGeneric WHERE refWdbeCGeneric = " + to_string(refWdbeCGeneric) + "", append, rst);
};

ubigint MyTblWdbeMGeneric::loadRstByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCGeneric, mdlRefWdbeMModule, mdlNum, sref, srefWdbeKHdltype, Width, Minmax, Defval, srcSrefWdbeMGeneric, Comment FROM TblWdbeMGeneric WHERE mdlRefWdbeMModule = " + to_string(mdlRefWdbeMModule) + " ORDER BY mdlNum ASC", append, rst);
};

bool MyTblWdbeMGeneric::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMGeneric WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMGeneric
 ******************************************************************************/

PgTblWdbeMGeneric::PgTblWdbeMGeneric() :
			TblWdbeMGeneric()
			, PgTable()
		{
};

PgTblWdbeMGeneric::~PgTblWdbeMGeneric() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMGeneric::initStatements() {
	createStatement("TblWdbeMGeneric_insertRec", "INSERT INTO TblWdbeMGeneric (refWdbeCGeneric, mdlRefWdbeMModule, mdlNum, sref, srefWdbeKHdltype, Width, Minmax, Defval, srcSrefWdbeMGeneric, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10);
	createStatement("TblWdbeMGeneric_updateRec", "UPDATE TblWdbeMGeneric SET refWdbeCGeneric = $1, mdlRefWdbeMModule = $2, mdlNum = $3, sref = $4, srefWdbeKHdltype = $5, Width = $6, Minmax = $7, Defval = $8, srcSrefWdbeMGeneric = $9, Comment = $10 WHERE ref = $11", 11);
	createStatement("TblWdbeMGeneric_removeRecByRef", "DELETE FROM TblWdbeMGeneric WHERE ref = $1", 1);

	createStatement("TblWdbeMGeneric_loadRecByRef", "SELECT ref, refWdbeCGeneric, mdlRefWdbeMModule, mdlNum, sref, srefWdbeKHdltype, Width, Minmax, Defval, srcSrefWdbeMGeneric, Comment FROM TblWdbeMGeneric WHERE ref = $1", 1);
	createStatement("TblWdbeMGeneric_loadRefsByClu", "SELECT ref FROM TblWdbeMGeneric WHERE refWdbeCGeneric = $1", 1);
	createStatement("TblWdbeMGeneric_loadRefsByMdl", "SELECT ref FROM TblWdbeMGeneric WHERE mdlRefWdbeMModule = $1", 1);
	createStatement("TblWdbeMGeneric_loadRstByClu", "SELECT ref, refWdbeCGeneric, mdlRefWdbeMModule, mdlNum, sref, srefWdbeKHdltype, Width, Minmax, Defval, srcSrefWdbeMGeneric, Comment FROM TblWdbeMGeneric WHERE refWdbeCGeneric = $1", 1);
	createStatement("TblWdbeMGeneric_loadRstByMdl", "SELECT ref, refWdbeCGeneric, mdlRefWdbeMModule, mdlNum, sref, srefWdbeKHdltype, Width, Minmax, Defval, srcSrefWdbeMGeneric, Comment FROM TblWdbeMGeneric WHERE mdlRefWdbeMModule = $1 ORDER BY mdlNum ASC", 1);
	createStatement("TblWdbeMGeneric_loadSrfByRef", "SELECT sref FROM TblWdbeMGeneric WHERE ref = $1", 1);
};

bool PgTblWdbeMGeneric::loadRec(
			PGresult* res
			, WdbeMGeneric** rec
		) {
	char* ptr;

	WdbeMGeneric* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMGeneric();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecgeneric"),
			PQfnumber(res, "mdlrefwdbemmodule"),
			PQfnumber(res, "mdlnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "srcsrefwdbemgeneric"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeCGeneric = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->mdlRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mdlNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Width = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Minmax.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Defval.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->srcSrefWdbeMGeneric.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMGeneric::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMGeneric* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecgeneric"),
			PQfnumber(res, "mdlrefwdbemmodule"),
			PQfnumber(res, "mdlnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "srcsrefwdbemgeneric"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMGeneric();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeCGeneric = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->mdlRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mdlNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Width = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Minmax.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Defval.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->srcSrefWdbeMGeneric.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMGeneric::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMGeneric** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMGeneric::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMGeneric::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMGeneric::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMGeneric::loadRecBySQL(
			const string& sqlstr
			, WdbeMGeneric** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMGeneric::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMGeneric::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMGeneric::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMGeneric::insertRec(
			WdbeMGeneric* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeCGeneric = htonl64(rec->refWdbeCGeneric);
	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	uint _mdlNum = htonl(rec->mdlNum);
	usmallint _Width = htons(rec->Width);

	const char* vals[] = {
		(char*) &_refWdbeCGeneric,
		(char*) &_mdlRefWdbeMModule,
		(char*) &_mdlNum,
		rec->sref.c_str(),
		rec->srefWdbeKHdltype.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str(),
		rec->Defval.c_str(),
		rec->srcSrefWdbeMGeneric.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(usmallint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMGeneric_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMGeneric::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMGeneric::insertRst(
			ListWdbeMGeneric& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMGeneric::updateRec(
			WdbeMGeneric* rec
		) {
	PGresult* res;

	ubigint _refWdbeCGeneric = htonl64(rec->refWdbeCGeneric);
	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	uint _mdlNum = htonl(rec->mdlNum);
	usmallint _Width = htons(rec->Width);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeCGeneric,
		(char*) &_mdlRefWdbeMModule,
		(char*) &_mdlNum,
		rec->sref.c_str(),
		rec->srefWdbeKHdltype.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str(),
		rec->Defval.c_str(),
		rec->srcSrefWdbeMGeneric.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(usmallint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMGeneric_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMGeneric::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMGeneric::updateRst(
			ListWdbeMGeneric& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMGeneric::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMGeneric_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMGeneric::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMGeneric::loadRecByRef(
			ubigint ref
			, WdbeMGeneric** rec
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

	return loadRecByStmt("TblWdbeMGeneric_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMGeneric::loadRefsByClu(
			ubigint refWdbeCGeneric
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeCGeneric = htonl64(refWdbeCGeneric);

	const char* vals[] = {
		(char*) &_refWdbeCGeneric
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMGeneric_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMGeneric::loadRefsByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _mdlRefWdbeMModule = htonl64(mdlRefWdbeMModule);

	const char* vals[] = {
		(char*) &_mdlRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMGeneric_loadRefsByMdl", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMGeneric::loadRstByClu(
			ubigint refWdbeCGeneric
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	ubigint _refWdbeCGeneric = htonl64(refWdbeCGeneric);

	const char* vals[] = {
		(char*) &_refWdbeCGeneric
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMGeneric_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeMGeneric::loadRstByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, ListWdbeMGeneric& rst
		) {
	ubigint _mdlRefWdbeMModule = htonl64(mdlRefWdbeMModule);

	const char* vals[] = {
		(char*) &_mdlRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMGeneric_loadRstByMdl", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMGeneric::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMGeneric_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

