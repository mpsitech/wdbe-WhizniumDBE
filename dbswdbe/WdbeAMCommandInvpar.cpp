/**
	* \file WdbeAMCommandInvpar.cpp
	* database access for table TblWdbeAMCommandInvpar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeAMCommandInvpar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMCommandInvpar
 ******************************************************************************/

WdbeAMCommandInvpar::WdbeAMCommandInvpar(
			const ubigint ref
			, const ubigint cmdRefWdbeMCommand
			, const uint cmdNum
			, const string sref
			, const uint ixWdbeVPartype
			, const ubigint refWdbeMVector
			, const utinyint Length
			, const string Defval
			, const ubigint refWdbeMVectoritem
			, const string Comment
		) {

	this->ref = ref;
	this->cmdRefWdbeMCommand = cmdRefWdbeMCommand;
	this->cmdNum = cmdNum;
	this->sref = sref;
	this->ixWdbeVPartype = ixWdbeVPartype;
	this->refWdbeMVector = refWdbeMVector;
	this->Length = Length;
	this->Defval = Defval;
	this->refWdbeMVectoritem = refWdbeMVectoritem;
	this->Comment = Comment;
};

bool WdbeAMCommandInvpar::operator==(
			const WdbeAMCommandInvpar& comp
		) {
	return false;
};

bool WdbeAMCommandInvpar::operator!=(
			const WdbeAMCommandInvpar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMCommandInvpar
 ******************************************************************************/

ListWdbeAMCommandInvpar::ListWdbeAMCommandInvpar() {
};

ListWdbeAMCommandInvpar::ListWdbeAMCommandInvpar(
			const ListWdbeAMCommandInvpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMCommandInvpar(*(src.nodes[i]));
};

ListWdbeAMCommandInvpar::~ListWdbeAMCommandInvpar() {
	clear();
};

void ListWdbeAMCommandInvpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMCommandInvpar::size() const {
	return(nodes.size());
};

void ListWdbeAMCommandInvpar::append(
			WdbeAMCommandInvpar* rec
		) {
	nodes.push_back(rec);
};

WdbeAMCommandInvpar* ListWdbeAMCommandInvpar::operator[](
			const uint ix
		) {
	WdbeAMCommandInvpar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMCommandInvpar& ListWdbeAMCommandInvpar::operator=(
			const ListWdbeAMCommandInvpar& src
		) {
	WdbeAMCommandInvpar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMCommandInvpar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMCommandInvpar::operator==(
			const ListWdbeAMCommandInvpar& comp
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

bool ListWdbeAMCommandInvpar::operator!=(
			const ListWdbeAMCommandInvpar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMCommandInvpar
 ******************************************************************************/

TblWdbeAMCommandInvpar::TblWdbeAMCommandInvpar() {
};

TblWdbeAMCommandInvpar::~TblWdbeAMCommandInvpar() {
};

bool TblWdbeAMCommandInvpar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCommandInvpar** rec
		) {
	return false;
};

ubigint TblWdbeAMCommandInvpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCommandInvpar& rst
		) {
	return 0;
};

ubigint TblWdbeAMCommandInvpar::insertRec(
			WdbeAMCommandInvpar* rec
		) {
	return 0;
};

ubigint TblWdbeAMCommandInvpar::insertNewRec(
			WdbeAMCommandInvpar** rec
			, const ubigint cmdRefWdbeMCommand
			, const uint cmdNum
			, const string sref
			, const uint ixWdbeVPartype
			, const ubigint refWdbeMVector
			, const utinyint Length
			, const string Defval
			, const ubigint refWdbeMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAMCommandInvpar* _rec = NULL;

	_rec = new WdbeAMCommandInvpar(0, cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMCommandInvpar::appendNewRecToRst(
			ListWdbeAMCommandInvpar& rst
			, WdbeAMCommandInvpar** rec
			, const ubigint cmdRefWdbeMCommand
			, const uint cmdNum
			, const string sref
			, const uint ixWdbeVPartype
			, const ubigint refWdbeMVector
			, const utinyint Length
			, const string Defval
			, const ubigint refWdbeMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAMCommandInvpar* _rec = NULL;

	retval = insertNewRec(&_rec, cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMCommandInvpar::insertRst(
			ListWdbeAMCommandInvpar& rst
			, bool transact
		) {
};

void TblWdbeAMCommandInvpar::updateRec(
			WdbeAMCommandInvpar* rec
		) {
};

void TblWdbeAMCommandInvpar::updateRst(
			ListWdbeAMCommandInvpar& rst
			, bool transact
		) {
};

void TblWdbeAMCommandInvpar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMCommandInvpar::loadRecByRef(
			ubigint ref
			, WdbeAMCommandInvpar** rec
		) {
	return false;
};

ubigint TblWdbeAMCommandInvpar::loadRefsByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMCommandInvpar::loadRstByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, ListWdbeAMCommandInvpar& rst
		) {
	return 0;
};

ubigint TblWdbeAMCommandInvpar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMCommandInvpar& rst
		) {
	ubigint numload = 0;
	WdbeAMCommandInvpar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMCommandInvpar
 ******************************************************************************/

MyTblWdbeAMCommandInvpar::MyTblWdbeAMCommandInvpar() :
			TblWdbeAMCommandInvpar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMCommandInvpar::~MyTblWdbeAMCommandInvpar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMCommandInvpar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMCommandInvpar (cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMCommandInvpar SET cmdRefWdbeMCommand = ?, cmdNum = ?, sref = ?, ixWdbeVPartype = ?, refWdbeMVector = ?, Length = ?, Defval = ?, refWdbeMVectoritem = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMCommandInvpar WHERE ref = ?", false);
};

bool MyTblWdbeAMCommandInvpar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCommandInvpar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMCommandInvpar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMCommandInvpar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMCommandInvpar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMCommandInvpar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->cmdRefWdbeMCommand = atoll((char*) dbrow[1]); else _rec->cmdRefWdbeMCommand = 0;
		if (dbrow[2]) _rec->cmdNum = atol((char*) dbrow[2]); else _rec->cmdNum = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->ixWdbeVPartype = atol((char*) dbrow[4]); else _rec->ixWdbeVPartype = 0;
		if (dbrow[5]) _rec->refWdbeMVector = atoll((char*) dbrow[5]); else _rec->refWdbeMVector = 0;
		if (dbrow[6]) _rec->Length = atoi((char*) dbrow[6]); else _rec->Length = 0;
		if (dbrow[7]) _rec->Defval.assign(dbrow[7], dblengths[7]); else _rec->Defval = "";
		if (dbrow[8]) _rec->refWdbeMVectoritem = atoll((char*) dbrow[8]); else _rec->refWdbeMVectoritem = 0;
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMCommandInvpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCommandInvpar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMCommandInvpar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMCommandInvpar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMCommandInvpar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMCommandInvpar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->cmdRefWdbeMCommand = atoll((char*) dbrow[1]); else rec->cmdRefWdbeMCommand = 0;
			if (dbrow[2]) rec->cmdNum = atol((char*) dbrow[2]); else rec->cmdNum = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->ixWdbeVPartype = atol((char*) dbrow[4]); else rec->ixWdbeVPartype = 0;
			if (dbrow[5]) rec->refWdbeMVector = atoll((char*) dbrow[5]); else rec->refWdbeMVector = 0;
			if (dbrow[6]) rec->Length = atoi((char*) dbrow[6]); else rec->Length = 0;
			if (dbrow[7]) rec->Defval.assign(dbrow[7], dblengths[7]); else rec->Defval = "";
			if (dbrow[8]) rec->refWdbeMVectoritem = atoll((char*) dbrow[8]); else rec->refWdbeMVectoritem = 0;
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMCommandInvpar::insertRec(
			WdbeAMCommandInvpar* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[2] = rec->sref.length();
	l[6] = rec->Defval.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->cmdRefWdbeMCommand,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->cmdNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVPartype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMVector,&(l[4]),&(n[4]),&(e[4])),
		bindUtinyint(&rec->Length,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWdbeMVectoritem,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMCommandInvpar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMCommandInvpar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMCommandInvpar::insertRst(
			ListWdbeAMCommandInvpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMCommandInvpar::updateRec(
			WdbeAMCommandInvpar* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[2] = rec->sref.length();
	l[6] = rec->Defval.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->cmdRefWdbeMCommand,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->cmdNum,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVPartype,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMVector,&(l[4]),&(n[4]),&(e[4])),
		bindUtinyint(&rec->Length,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWdbeMVectoritem,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->ref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMCommandInvpar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMCommandInvpar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMCommandInvpar::updateRst(
			ListWdbeAMCommandInvpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMCommandInvpar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMCommandInvpar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMCommandInvpar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMCommandInvpar::loadRecByRef(
			ubigint ref
			, WdbeAMCommandInvpar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMCommandInvpar WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMCommandInvpar::loadRefsByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = " + to_string(cmdRefWdbeMCommand) + "", append, refs);
};

ubigint MyTblWdbeAMCommandInvpar::loadRstByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, ListWdbeAMCommandInvpar& rst
		) {
	return loadRstBySQL("SELECT ref, cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = " + to_string(cmdRefWdbeMCommand) + " ORDER BY cmdNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMCommandInvpar
 ******************************************************************************/

PgTblWdbeAMCommandInvpar::PgTblWdbeAMCommandInvpar() :
			TblWdbeAMCommandInvpar()
			, PgTable()
		{
};

PgTblWdbeAMCommandInvpar::~PgTblWdbeAMCommandInvpar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMCommandInvpar::initStatements() {
	createStatement("TblWdbeAMCommandInvpar_insertRec", "INSERT INTO TblWdbeAMCommandInvpar (cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING ref", 9);
	createStatement("TblWdbeAMCommandInvpar_updateRec", "UPDATE TblWdbeAMCommandInvpar SET cmdRefWdbeMCommand = $1, cmdNum = $2, sref = $3, ixWdbeVPartype = $4, refWdbeMVector = $5, Length = $6, Defval = $7, refWdbeMVectoritem = $8, Comment = $9 WHERE ref = $10", 10);
	createStatement("TblWdbeAMCommandInvpar_removeRecByRef", "DELETE FROM TblWdbeAMCommandInvpar WHERE ref = $1", 1);

	createStatement("TblWdbeAMCommandInvpar_loadRecByRef", "SELECT ref, cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment FROM TblWdbeAMCommandInvpar WHERE ref = $1", 1);
	createStatement("TblWdbeAMCommandInvpar_loadRefsByCmd", "SELECT ref FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = $1", 1);
	createStatement("TblWdbeAMCommandInvpar_loadRstByCmd", "SELECT ref, cmdRefWdbeMCommand, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment FROM TblWdbeAMCommandInvpar WHERE cmdRefWdbeMCommand = $1 ORDER BY cmdNum ASC", 1);
};

bool PgTblWdbeAMCommandInvpar::loadRec(
			PGresult* res
			, WdbeAMCommandInvpar** rec
		) {
	char* ptr;

	WdbeAMCommandInvpar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMCommandInvpar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "cmdrefwdbemcommand"),
			PQfnumber(res, "cmdnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwdbevpartype"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwdbemvectoritem"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->cmdRefWdbeMCommand = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->cmdNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWdbeVPartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWdbeMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Length = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Defval.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWdbeMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMCommandInvpar::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMCommandInvpar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMCommandInvpar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "cmdrefwdbemcommand"),
			PQfnumber(res, "cmdnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwdbevpartype"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwdbemvectoritem"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeAMCommandInvpar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->cmdRefWdbeMCommand = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->cmdNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWdbeVPartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWdbeMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Length = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Defval.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWdbeMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMCommandInvpar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMCommandInvpar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCommandInvpar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMCommandInvpar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMCommandInvpar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCommandInvpar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMCommandInvpar::loadRecBySQL(
			const string& sqlstr
			, WdbeAMCommandInvpar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCommandInvpar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMCommandInvpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMCommandInvpar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCommandInvpar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMCommandInvpar::insertRec(
			WdbeAMCommandInvpar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _cmdRefWdbeMCommand = htonl64(rec->cmdRefWdbeMCommand);
	uint _cmdNum = htonl(rec->cmdNum);
	uint _ixWdbeVPartype = htonl(rec->ixWdbeVPartype);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	usmallint _Length = htons(rec->Length);
	ubigint _refWdbeMVectoritem = htonl64(rec->refWdbeMVectoritem);

	const char* vals[] = {
		(char*) &_cmdRefWdbeMCommand,
		(char*) &_cmdNum,
		rec->sref.c_str(),
		(char*) &_ixWdbeVPartype,
		(char*) &_refWdbeMVector,
		(char*) &_Length,
		rec->Defval.c_str(),
		(char*) &_refWdbeMVectoritem,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMCommandInvpar_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMCommandInvpar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMCommandInvpar::insertRst(
			ListWdbeAMCommandInvpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMCommandInvpar::updateRec(
			WdbeAMCommandInvpar* rec
		) {
	PGresult* res;

	ubigint _cmdRefWdbeMCommand = htonl64(rec->cmdRefWdbeMCommand);
	uint _cmdNum = htonl(rec->cmdNum);
	uint _ixWdbeVPartype = htonl(rec->ixWdbeVPartype);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	usmallint _Length = htons(rec->Length);
	ubigint _refWdbeMVectoritem = htonl64(rec->refWdbeMVectoritem);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_cmdRefWdbeMCommand,
		(char*) &_cmdNum,
		rec->sref.c_str(),
		(char*) &_ixWdbeVPartype,
		(char*) &_refWdbeMVector,
		(char*) &_Length,
		rec->Defval.c_str(),
		(char*) &_refWdbeMVectoritem,
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
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMCommandInvpar_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMCommandInvpar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMCommandInvpar::updateRst(
			ListWdbeAMCommandInvpar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMCommandInvpar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMCommandInvpar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMCommandInvpar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMCommandInvpar::loadRecByRef(
			ubigint ref
			, WdbeAMCommandInvpar** rec
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

	return loadRecByStmt("TblWdbeAMCommandInvpar_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMCommandInvpar::loadRefsByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _cmdRefWdbeMCommand = htonl64(cmdRefWdbeMCommand);

	const char* vals[] = {
		(char*) &_cmdRefWdbeMCommand
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMCommandInvpar_loadRefsByCmd", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMCommandInvpar::loadRstByCmd(
			ubigint cmdRefWdbeMCommand
			, const bool append
			, ListWdbeAMCommandInvpar& rst
		) {
	ubigint _cmdRefWdbeMCommand = htonl64(cmdRefWdbeMCommand);

	const char* vals[] = {
		(char*) &_cmdRefWdbeMCommand
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMCommandInvpar_loadRstByCmd", 1, vals, l, f, append, rst);
};

#endif

