/**
	* \file WdbeMVariable.cpp
	* database access for table TblWdbeMVariable (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeMVariable.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMVariable
 ******************************************************************************/

WdbeMVariable::WdbeMVariable(
			const ubigint ref
			, const ubigint refWdbeCVariable
			, const ubigint prcRefWdbeMProcess
			, const uint prcNum
			, const string sref
			, const bool Const
			, const bool Falling
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Onval
			, const string Offval
			, const bool Defon
			, const string Comment
		) {

	this->ref = ref;
	this->refWdbeCVariable = refWdbeCVariable;
	this->prcRefWdbeMProcess = prcRefWdbeMProcess;
	this->prcNum = prcNum;
	this->sref = sref;
	this->Const = Const;
	this->Falling = Falling;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Onval = Onval;
	this->Offval = Offval;
	this->Defon = Defon;
	this->Comment = Comment;
};

bool WdbeMVariable::operator==(
			const WdbeMVariable& comp
		) {
	return false;
};

bool WdbeMVariable::operator!=(
			const WdbeMVariable& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMVariable
 ******************************************************************************/

ListWdbeMVariable::ListWdbeMVariable() {
};

ListWdbeMVariable::ListWdbeMVariable(
			const ListWdbeMVariable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMVariable(*(src.nodes[i]));
};

ListWdbeMVariable::~ListWdbeMVariable() {
	clear();
};

void ListWdbeMVariable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMVariable::size() const {
	return(nodes.size());
};

void ListWdbeMVariable::append(
			WdbeMVariable* rec
		) {
	nodes.push_back(rec);
};

WdbeMVariable* ListWdbeMVariable::operator[](
			const uint ix
		) {
	WdbeMVariable* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMVariable& ListWdbeMVariable::operator=(
			const ListWdbeMVariable& src
		) {
	WdbeMVariable* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMVariable(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMVariable::operator==(
			const ListWdbeMVariable& comp
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

bool ListWdbeMVariable::operator!=(
			const ListWdbeMVariable& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMVariable
 ******************************************************************************/

TblWdbeMVariable::TblWdbeMVariable() {
};

TblWdbeMVariable::~TblWdbeMVariable() {
};

bool TblWdbeMVariable::loadRecBySQL(
			const string& sqlstr
			, WdbeMVariable** rec
		) {
	return false;
};

ubigint TblWdbeMVariable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMVariable& rst
		) {
	return 0;
};

ubigint TblWdbeMVariable::insertRec(
			WdbeMVariable* rec
		) {
	return 0;
};

ubigint TblWdbeMVariable::insertNewRec(
			WdbeMVariable** rec
			, const ubigint refWdbeCVariable
			, const ubigint prcRefWdbeMProcess
			, const uint prcNum
			, const string sref
			, const bool Const
			, const bool Falling
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Onval
			, const string Offval
			, const bool Defon
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMVariable* _rec = NULL;

	_rec = new WdbeMVariable(0, refWdbeCVariable, prcRefWdbeMProcess, prcNum, sref, Const, Falling, srefWdbeKHdltype, Width, Minmax, Onval, Offval, Defon, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMVariable::appendNewRecToRst(
			ListWdbeMVariable& rst
			, WdbeMVariable** rec
			, const ubigint refWdbeCVariable
			, const ubigint prcRefWdbeMProcess
			, const uint prcNum
			, const string sref
			, const bool Const
			, const bool Falling
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Onval
			, const string Offval
			, const bool Defon
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMVariable* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeCVariable, prcRefWdbeMProcess, prcNum, sref, Const, Falling, srefWdbeKHdltype, Width, Minmax, Onval, Offval, Defon, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMVariable::insertRst(
			ListWdbeMVariable& rst
			, bool transact
		) {
};

void TblWdbeMVariable::updateRec(
			WdbeMVariable* rec
		) {
};

void TblWdbeMVariable::updateRst(
			ListWdbeMVariable& rst
			, bool transact
		) {
};

void TblWdbeMVariable::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMVariable::loadRecByRef(
			ubigint ref
			, WdbeMVariable** rec
		) {
	return false;
};

ubigint TblWdbeMVariable::loadRefsByClu(
			ubigint refWdbeCVariable
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMVariable::loadRefsByPrc(
			ubigint prcRefWdbeMProcess
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMVariable::loadRstByClu(
			ubigint refWdbeCVariable
			, const bool append
			, ListWdbeMVariable& rst
		) {
	return 0;
};

ubigint TblWdbeMVariable::loadRstByPrc(
			ubigint prcRefWdbeMProcess
			, const bool append
			, ListWdbeMVariable& rst
		) {
	return 0;
};

bool TblWdbeMVariable::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMVariable::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMVariable& rst
		) {
	ubigint numload = 0;
	WdbeMVariable* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMVariable
 ******************************************************************************/

MyTblWdbeMVariable::MyTblWdbeMVariable() :
			TblWdbeMVariable()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMVariable::~MyTblWdbeMVariable() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMVariable::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMVariable (refWdbeCVariable, prcRefWdbeMProcess, prcNum, sref, Const, Falling, srefWdbeKHdltype, Width, Minmax, Onval, Offval, Defon, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMVariable SET refWdbeCVariable = ?, prcRefWdbeMProcess = ?, prcNum = ?, sref = ?, Const = ?, Falling = ?, srefWdbeKHdltype = ?, Width = ?, Minmax = ?, Onval = ?, Offval = ?, Defon = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMVariable WHERE ref = ?", false);
};

bool MyTblWdbeMVariable::loadRecBySQL(
			const string& sqlstr
			, WdbeMVariable** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMVariable* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMVariable::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMVariable::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMVariable();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeCVariable = atoll((char*) dbrow[1]); else _rec->refWdbeCVariable = 0;
		if (dbrow[2]) _rec->prcRefWdbeMProcess = atoll((char*) dbrow[2]); else _rec->prcRefWdbeMProcess = 0;
		if (dbrow[3]) _rec->prcNum = atol((char*) dbrow[3]); else _rec->prcNum = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Const = (atoi((char*) dbrow[5]) != 0); else _rec->Const = false;
		if (dbrow[6]) _rec->Falling = (atoi((char*) dbrow[6]) != 0); else _rec->Falling = false;
		if (dbrow[7]) _rec->srefWdbeKHdltype.assign(dbrow[7], dblengths[7]); else _rec->srefWdbeKHdltype = "";
		if (dbrow[8]) _rec->Width = atoi((char*) dbrow[8]); else _rec->Width = 0;
		if (dbrow[9]) _rec->Minmax.assign(dbrow[9], dblengths[9]); else _rec->Minmax = "";
		if (dbrow[10]) _rec->Onval.assign(dbrow[10], dblengths[10]); else _rec->Onval = "";
		if (dbrow[11]) _rec->Offval.assign(dbrow[11], dblengths[11]); else _rec->Offval = "";
		if (dbrow[12]) _rec->Defon = (atoi((char*) dbrow[12]) != 0); else _rec->Defon = false;
		if (dbrow[13]) _rec->Comment.assign(dbrow[13], dblengths[13]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMVariable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMVariable& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMVariable* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMVariable::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMVariable::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMVariable();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeCVariable = atoll((char*) dbrow[1]); else rec->refWdbeCVariable = 0;
			if (dbrow[2]) rec->prcRefWdbeMProcess = atoll((char*) dbrow[2]); else rec->prcRefWdbeMProcess = 0;
			if (dbrow[3]) rec->prcNum = atol((char*) dbrow[3]); else rec->prcNum = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Const = (atoi((char*) dbrow[5]) != 0); else rec->Const = false;
			if (dbrow[6]) rec->Falling = (atoi((char*) dbrow[6]) != 0); else rec->Falling = false;
			if (dbrow[7]) rec->srefWdbeKHdltype.assign(dbrow[7], dblengths[7]); else rec->srefWdbeKHdltype = "";
			if (dbrow[8]) rec->Width = atoi((char*) dbrow[8]); else rec->Width = 0;
			if (dbrow[9]) rec->Minmax.assign(dbrow[9], dblengths[9]); else rec->Minmax = "";
			if (dbrow[10]) rec->Onval.assign(dbrow[10], dblengths[10]); else rec->Onval = "";
			if (dbrow[11]) rec->Offval.assign(dbrow[11], dblengths[11]); else rec->Offval = "";
			if (dbrow[12]) rec->Defon = (atoi((char*) dbrow[12]) != 0); else rec->Defon = false;
			if (dbrow[13]) rec->Comment.assign(dbrow[13], dblengths[13]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMVariable::insertRec(
			WdbeMVariable* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[3] = rec->sref.length();
	tinyint Const = rec->Const;
	tinyint Falling = rec->Falling;
	l[6] = rec->srefWdbeKHdltype.length();
	l[8] = rec->Minmax.length();
	l[9] = rec->Onval.length();
	l[10] = rec->Offval.length();
	tinyint Defon = rec->Defon;
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCVariable,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->prcRefWdbeMProcess,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->prcNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Const,&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Falling,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Width,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Onval.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Offval.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindTinyint(&Defon,&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMVariable::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMVariable::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMVariable::insertRst(
			ListWdbeMVariable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMVariable::updateRec(
			WdbeMVariable* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[3] = rec->sref.length();
	tinyint Const = rec->Const;
	tinyint Falling = rec->Falling;
	l[6] = rec->srefWdbeKHdltype.length();
	l[8] = rec->Minmax.length();
	l[9] = rec->Onval.length();
	l[10] = rec->Offval.length();
	tinyint Defon = rec->Defon;
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCVariable,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->prcRefWdbeMProcess,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->prcNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Const,&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Falling,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Width,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Onval.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Offval.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindTinyint(&Defon,&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMVariable::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMVariable::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMVariable::updateRst(
			ListWdbeMVariable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMVariable::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMVariable::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMVariable::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMVariable::loadRecByRef(
			ubigint ref
			, WdbeMVariable** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMVariable WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMVariable::loadRefsByClu(
			ubigint refWdbeCVariable
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMVariable WHERE refWdbeCVariable = " + to_string(refWdbeCVariable) + "", append, refs);
};

ubigint MyTblWdbeMVariable::loadRefsByPrc(
			ubigint prcRefWdbeMProcess
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMVariable WHERE prcRefWdbeMProcess = " + to_string(prcRefWdbeMProcess) + "", append, refs);
};

ubigint MyTblWdbeMVariable::loadRstByClu(
			ubigint refWdbeCVariable
			, const bool append
			, ListWdbeMVariable& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCVariable, prcRefWdbeMProcess, prcNum, sref, Const, Falling, srefWdbeKHdltype, Width, Minmax, Onval, Offval, Defon, Comment FROM TblWdbeMVariable WHERE refWdbeCVariable = " + to_string(refWdbeCVariable) + "", append, rst);
};

ubigint MyTblWdbeMVariable::loadRstByPrc(
			ubigint prcRefWdbeMProcess
			, const bool append
			, ListWdbeMVariable& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCVariable, prcRefWdbeMProcess, prcNum, sref, Const, Falling, srefWdbeKHdltype, Width, Minmax, Onval, Offval, Defon, Comment FROM TblWdbeMVariable WHERE prcRefWdbeMProcess = " + to_string(prcRefWdbeMProcess) + " ORDER BY prcNum ASC", append, rst);
};

bool MyTblWdbeMVariable::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMVariable WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMVariable
 ******************************************************************************/

PgTblWdbeMVariable::PgTblWdbeMVariable() :
			TblWdbeMVariable()
			, PgTable()
		{
};

PgTblWdbeMVariable::~PgTblWdbeMVariable() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMVariable::initStatements() {
	createStatement("TblWdbeMVariable_insertRec", "INSERT INTO TblWdbeMVariable (refWdbeCVariable, prcRefWdbeMProcess, prcNum, sref, Const, Falling, srefWdbeKHdltype, Width, Minmax, Onval, Offval, Defon, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13);
	createStatement("TblWdbeMVariable_updateRec", "UPDATE TblWdbeMVariable SET refWdbeCVariable = $1, prcRefWdbeMProcess = $2, prcNum = $3, sref = $4, Const = $5, Falling = $6, srefWdbeKHdltype = $7, Width = $8, Minmax = $9, Onval = $10, Offval = $11, Defon = $12, Comment = $13 WHERE ref = $14", 14);
	createStatement("TblWdbeMVariable_removeRecByRef", "DELETE FROM TblWdbeMVariable WHERE ref = $1", 1);

	createStatement("TblWdbeMVariable_loadRecByRef", "SELECT ref, refWdbeCVariable, prcRefWdbeMProcess, prcNum, sref, Const, Falling, srefWdbeKHdltype, Width, Minmax, Onval, Offval, Defon, Comment FROM TblWdbeMVariable WHERE ref = $1", 1);
	createStatement("TblWdbeMVariable_loadRefsByClu", "SELECT ref FROM TblWdbeMVariable WHERE refWdbeCVariable = $1", 1);
	createStatement("TblWdbeMVariable_loadRefsByPrc", "SELECT ref FROM TblWdbeMVariable WHERE prcRefWdbeMProcess = $1", 1);
	createStatement("TblWdbeMVariable_loadRstByClu", "SELECT ref, refWdbeCVariable, prcRefWdbeMProcess, prcNum, sref, Const, Falling, srefWdbeKHdltype, Width, Minmax, Onval, Offval, Defon, Comment FROM TblWdbeMVariable WHERE refWdbeCVariable = $1", 1);
	createStatement("TblWdbeMVariable_loadRstByPrc", "SELECT ref, refWdbeCVariable, prcRefWdbeMProcess, prcNum, sref, Const, Falling, srefWdbeKHdltype, Width, Minmax, Onval, Offval, Defon, Comment FROM TblWdbeMVariable WHERE prcRefWdbeMProcess = $1 ORDER BY prcNum ASC", 1);
	createStatement("TblWdbeMVariable_loadSrfByRef", "SELECT sref FROM TblWdbeMVariable WHERE ref = $1", 1);
};

bool PgTblWdbeMVariable::loadRec(
			PGresult* res
			, WdbeMVariable** rec
		) {
	char* ptr;

	WdbeMVariable* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMVariable();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecvariable"),
			PQfnumber(res, "prcrefwdbemprocess"),
			PQfnumber(res, "prcnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "const"),
			PQfnumber(res, "falling"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax"),
			PQfnumber(res, "onval"),
			PQfnumber(res, "offval"),
			PQfnumber(res, "defon"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeCVariable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->prcRefWdbeMProcess = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->prcNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Const = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Falling = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Width = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Minmax.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Onval.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Offval.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Defon = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMVariable::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMVariable& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMVariable* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecvariable"),
			PQfnumber(res, "prcrefwdbemprocess"),
			PQfnumber(res, "prcnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "const"),
			PQfnumber(res, "falling"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax"),
			PQfnumber(res, "onval"),
			PQfnumber(res, "offval"),
			PQfnumber(res, "defon"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMVariable();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeCVariable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->prcRefWdbeMProcess = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->prcNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Const = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Falling = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Width = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Minmax.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Onval.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Offval.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Defon = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMVariable::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMVariable** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVariable::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMVariable::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMVariable& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVariable::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMVariable::loadRecBySQL(
			const string& sqlstr
			, WdbeMVariable** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVariable::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMVariable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMVariable& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVariable::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMVariable::insertRec(
			WdbeMVariable* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeCVariable = htonl64(rec->refWdbeCVariable);
	ubigint _prcRefWdbeMProcess = htonl64(rec->prcRefWdbeMProcess);
	uint _prcNum = htonl(rec->prcNum);
	smallint _Const = htons((smallint) rec->Const);
	smallint _Falling = htons((smallint) rec->Falling);
	usmallint _Width = htons(rec->Width);
	smallint _Defon = htons((smallint) rec->Defon);

	const char* vals[] = {
		(char*) &_refWdbeCVariable,
		(char*) &_prcRefWdbeMProcess,
		(char*) &_prcNum,
		rec->sref.c_str(),
		(char*) &_Const,
		(char*) &_Falling,
		rec->srefWdbeKHdltype.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str(),
		rec->Onval.c_str(),
		rec->Offval.c_str(),
		(char*) &_Defon,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(smallint),
		sizeof(smallint),
		0,
		sizeof(usmallint),
		0,
		0,
		0,
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeMVariable_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMVariable::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMVariable::insertRst(
			ListWdbeMVariable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMVariable::updateRec(
			WdbeMVariable* rec
		) {
	PGresult* res;

	ubigint _refWdbeCVariable = htonl64(rec->refWdbeCVariable);
	ubigint _prcRefWdbeMProcess = htonl64(rec->prcRefWdbeMProcess);
	uint _prcNum = htonl(rec->prcNum);
	smallint _Const = htons((smallint) rec->Const);
	smallint _Falling = htons((smallint) rec->Falling);
	usmallint _Width = htons(rec->Width);
	smallint _Defon = htons((smallint) rec->Defon);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeCVariable,
		(char*) &_prcRefWdbeMProcess,
		(char*) &_prcNum,
		rec->sref.c_str(),
		(char*) &_Const,
		(char*) &_Falling,
		rec->srefWdbeKHdltype.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str(),
		rec->Onval.c_str(),
		rec->Offval.c_str(),
		(char*) &_Defon,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(smallint),
		sizeof(smallint),
		0,
		sizeof(usmallint),
		0,
		0,
		0,
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMVariable_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMVariable::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMVariable::updateRst(
			ListWdbeMVariable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMVariable::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMVariable_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMVariable::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMVariable::loadRecByRef(
			ubigint ref
			, WdbeMVariable** rec
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

	return loadRecByStmt("TblWdbeMVariable_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMVariable::loadRefsByClu(
			ubigint refWdbeCVariable
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeCVariable = htonl64(refWdbeCVariable);

	const char* vals[] = {
		(char*) &_refWdbeCVariable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMVariable_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMVariable::loadRefsByPrc(
			ubigint prcRefWdbeMProcess
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _prcRefWdbeMProcess = htonl64(prcRefWdbeMProcess);

	const char* vals[] = {
		(char*) &_prcRefWdbeMProcess
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMVariable_loadRefsByPrc", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMVariable::loadRstByClu(
			ubigint refWdbeCVariable
			, const bool append
			, ListWdbeMVariable& rst
		) {
	ubigint _refWdbeCVariable = htonl64(refWdbeCVariable);

	const char* vals[] = {
		(char*) &_refWdbeCVariable
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMVariable_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeMVariable::loadRstByPrc(
			ubigint prcRefWdbeMProcess
			, const bool append
			, ListWdbeMVariable& rst
		) {
	ubigint _prcRefWdbeMProcess = htonl64(prcRefWdbeMProcess);

	const char* vals[] = {
		(char*) &_prcRefWdbeMProcess
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMVariable_loadRstByPrc", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMVariable::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMVariable_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

