/**
	* \file WdbeMCommand.cpp
	* database access for table TblWdbeMCommand (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeMCommand.h"

#include "WdbeMCommand_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMCommand
 ******************************************************************************/

WdbeMCommand::WdbeMCommand(
			const ubigint ref
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const string sref
			, const string Fullsref
			, const uint ixVRettype
			, const ubigint ivrRefWdbeMSignal
			, const ubigint rvrRefWdbeMSignal
			, const ubigint rerRefWdbeMSignal
			, const string Comment
		) {

	this->ref = ref;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->refNum = refNum;
	this->sref = sref;
	this->Fullsref = Fullsref;
	this->ixVRettype = ixVRettype;
	this->ivrRefWdbeMSignal = ivrRefWdbeMSignal;
	this->rvrRefWdbeMSignal = rvrRefWdbeMSignal;
	this->rerRefWdbeMSignal = rerRefWdbeMSignal;
	this->Comment = Comment;
};

bool WdbeMCommand::operator==(
			const WdbeMCommand& comp
		) {
	return false;
};

bool WdbeMCommand::operator!=(
			const WdbeMCommand& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMCommand
 ******************************************************************************/

ListWdbeMCommand::ListWdbeMCommand() {
};

ListWdbeMCommand::ListWdbeMCommand(
			const ListWdbeMCommand& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMCommand(*(src.nodes[i]));
};

ListWdbeMCommand::~ListWdbeMCommand() {
	clear();
};

void ListWdbeMCommand::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMCommand::size() const {
	return(nodes.size());
};

void ListWdbeMCommand::append(
			WdbeMCommand* rec
		) {
	nodes.push_back(rec);
};

WdbeMCommand* ListWdbeMCommand::operator[](
			const uint ix
		) {
	WdbeMCommand* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMCommand& ListWdbeMCommand::operator=(
			const ListWdbeMCommand& src
		) {
	WdbeMCommand* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMCommand(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMCommand::operator==(
			const ListWdbeMCommand& comp
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

bool ListWdbeMCommand::operator!=(
			const ListWdbeMCommand& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMCommand
 ******************************************************************************/

TblWdbeMCommand::TblWdbeMCommand() {
};

TblWdbeMCommand::~TblWdbeMCommand() {
};

bool TblWdbeMCommand::loadRecBySQL(
			const string& sqlstr
			, WdbeMCommand** rec
		) {
	return false;
};

ubigint TblWdbeMCommand::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCommand& rst
		) {
	return 0;
};

ubigint TblWdbeMCommand::insertRec(
			WdbeMCommand* rec
		) {
	return 0;
};

ubigint TblWdbeMCommand::insertNewRec(
			WdbeMCommand** rec
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const string sref
			, const string Fullsref
			, const uint ixVRettype
			, const ubigint ivrRefWdbeMSignal
			, const ubigint rvrRefWdbeMSignal
			, const ubigint rerRefWdbeMSignal
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMCommand* _rec = NULL;

	_rec = new WdbeMCommand(0, refIxVTbl, refUref, refNum, sref, Fullsref, ixVRettype, ivrRefWdbeMSignal, rvrRefWdbeMSignal, rerRefWdbeMSignal, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMCommand::appendNewRecToRst(
			ListWdbeMCommand& rst
			, WdbeMCommand** rec
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const string sref
			, const string Fullsref
			, const uint ixVRettype
			, const ubigint ivrRefWdbeMSignal
			, const ubigint rvrRefWdbeMSignal
			, const ubigint rerRefWdbeMSignal
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMCommand* _rec = NULL;

	retval = insertNewRec(&_rec, refIxVTbl, refUref, refNum, sref, Fullsref, ixVRettype, ivrRefWdbeMSignal, rvrRefWdbeMSignal, rerRefWdbeMSignal, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMCommand::insertRst(
			ListWdbeMCommand& rst
			, bool transact
		) {
};

void TblWdbeMCommand::updateRec(
			WdbeMCommand* rec
		) {
};

void TblWdbeMCommand::updateRst(
			ListWdbeMCommand& rst
			, bool transact
		) {
};

void TblWdbeMCommand::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMCommand::loadRecByRef(
			ubigint ref
			, WdbeMCommand** rec
		) {
	return false;
};

ubigint TblWdbeMCommand::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMCommand::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMCommand& rst
		) {
	return 0;
};

ubigint TblWdbeMCommand::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMCommand& rst
		) {
	ubigint numload = 0;
	WdbeMCommand* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMCommand
 ******************************************************************************/

MyTblWdbeMCommand::MyTblWdbeMCommand() :
			TblWdbeMCommand()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMCommand::~MyTblWdbeMCommand() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMCommand::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMCommand (refIxVTbl, refUref, refNum, sref, Fullsref, ixVRettype, ivrRefWdbeMSignal, rvrRefWdbeMSignal, rerRefWdbeMSignal, Comment) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMCommand SET refIxVTbl = ?, refUref = ?, refNum = ?, sref = ?, Fullsref = ?, ixVRettype = ?, ivrRefWdbeMSignal = ?, rvrRefWdbeMSignal = ?, rerRefWdbeMSignal = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMCommand WHERE ref = ?", false);
};

bool MyTblWdbeMCommand::loadRecBySQL(
			const string& sqlstr
			, WdbeMCommand** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMCommand* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMCommand::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMCommand::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMCommand();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refIxVTbl = atol((char*) dbrow[1]); else _rec->refIxVTbl = 0;
		if (dbrow[2]) _rec->refUref = atoll((char*) dbrow[2]); else _rec->refUref = 0;
		if (dbrow[3]) _rec->refNum = atol((char*) dbrow[3]); else _rec->refNum = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Fullsref.assign(dbrow[5], dblengths[5]); else _rec->Fullsref = "";
		if (dbrow[6]) _rec->ixVRettype = atol((char*) dbrow[6]); else _rec->ixVRettype = 0;
		if (dbrow[7]) _rec->ivrRefWdbeMSignal = atoll((char*) dbrow[7]); else _rec->ivrRefWdbeMSignal = 0;
		if (dbrow[8]) _rec->rvrRefWdbeMSignal = atoll((char*) dbrow[8]); else _rec->rvrRefWdbeMSignal = 0;
		if (dbrow[9]) _rec->rerRefWdbeMSignal = atoll((char*) dbrow[9]); else _rec->rerRefWdbeMSignal = 0;
		if (dbrow[10]) _rec->Comment.assign(dbrow[10], dblengths[10]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMCommand::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCommand& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMCommand* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMCommand::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMCommand::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMCommand();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refIxVTbl = atol((char*) dbrow[1]); else rec->refIxVTbl = 0;
			if (dbrow[2]) rec->refUref = atoll((char*) dbrow[2]); else rec->refUref = 0;
			if (dbrow[3]) rec->refNum = atol((char*) dbrow[3]); else rec->refNum = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Fullsref.assign(dbrow[5], dblengths[5]); else rec->Fullsref = "";
			if (dbrow[6]) rec->ixVRettype = atol((char*) dbrow[6]); else rec->ixVRettype = 0;
			if (dbrow[7]) rec->ivrRefWdbeMSignal = atoll((char*) dbrow[7]); else rec->ivrRefWdbeMSignal = 0;
			if (dbrow[8]) rec->rvrRefWdbeMSignal = atoll((char*) dbrow[8]); else rec->rvrRefWdbeMSignal = 0;
			if (dbrow[9]) rec->rerRefWdbeMSignal = atoll((char*) dbrow[9]); else rec->rerRefWdbeMSignal = 0;
			if (dbrow[10]) rec->Comment.assign(dbrow[10], dblengths[10]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMCommand::insertRec(
			WdbeMCommand* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	l[4] = rec->Fullsref.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->refIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refUref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVRettype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ivrRefWdbeMSignal,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->rvrRefWdbeMSignal,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->rerRefWdbeMSignal,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMCommand::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMCommand::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMCommand::insertRst(
			ListWdbeMCommand& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMCommand::updateRec(
			WdbeMCommand* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->sref.length();
	l[4] = rec->Fullsref.length();
	l[9] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->refIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refUref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refNum,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVRettype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ivrRefWdbeMSignal,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->rvrRefWdbeMSignal,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->rerRefWdbeMSignal,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMCommand::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMCommand::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMCommand::updateRst(
			ListWdbeMCommand& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMCommand::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMCommand::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMCommand::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMCommand::loadRecByRef(
			ubigint ref
			, WdbeMCommand** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMCommand WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMCommand::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", append, refs);
};

ubigint MyTblWdbeMCommand::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMCommand& rst
		) {
	return loadRstBySQL("SELECT ref, refIxVTbl, refUref, refNum, sref, Fullsref, ixVRettype, ivrRefWdbeMSignal, rvrRefWdbeMSignal, rerRefWdbeMSignal, Comment FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " ORDER BY refNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMCommand
 ******************************************************************************/

PgTblWdbeMCommand::PgTblWdbeMCommand() :
			TblWdbeMCommand()
			, PgTable()
		{
};

PgTblWdbeMCommand::~PgTblWdbeMCommand() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMCommand::initStatements() {
	createStatement("TblWdbeMCommand_insertRec", "INSERT INTO TblWdbeMCommand (refIxVTbl, refUref, refNum, sref, Fullsref, ixVRettype, ivrRefWdbeMSignal, rvrRefWdbeMSignal, rerRefWdbeMSignal, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10);
	createStatement("TblWdbeMCommand_updateRec", "UPDATE TblWdbeMCommand SET refIxVTbl = $1, refUref = $2, refNum = $3, sref = $4, Fullsref = $5, ixVRettype = $6, ivrRefWdbeMSignal = $7, rvrRefWdbeMSignal = $8, rerRefWdbeMSignal = $9, Comment = $10 WHERE ref = $11", 11);
	createStatement("TblWdbeMCommand_removeRecByRef", "DELETE FROM TblWdbeMCommand WHERE ref = $1", 1);

	createStatement("TblWdbeMCommand_loadRecByRef", "SELECT ref, refIxVTbl, refUref, refNum, sref, Fullsref, ixVRettype, ivrRefWdbeMSignal, rvrRefWdbeMSignal, rerRefWdbeMSignal, Comment FROM TblWdbeMCommand WHERE ref = $1", 1);
	createStatement("TblWdbeMCommand_loadRefsByRetReu", "SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = $1 AND refUref = $2", 2);
	createStatement("TblWdbeMCommand_loadRstByRetReu", "SELECT ref, refIxVTbl, refUref, refNum, sref, Fullsref, ixVRettype, ivrRefWdbeMSignal, rvrRefWdbeMSignal, rerRefWdbeMSignal, Comment FROM TblWdbeMCommand WHERE refIxVTbl = $1 AND refUref = $2 ORDER BY refNum ASC", 2);
};

bool PgTblWdbeMCommand::loadRec(
			PGresult* res
			, WdbeMCommand** rec
		) {
	char* ptr;

	WdbeMCommand* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMCommand();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "ixvrettype"),
			PQfnumber(res, "ivrrefwdbemsignal"),
			PQfnumber(res, "rvrrefwdbemsignal"),
			PQfnumber(res, "rerrefwdbemsignal"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fullsref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVRettype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ivrRefWdbeMSignal = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->rvrRefWdbeMSignal = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->rerRefWdbeMSignal = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMCommand::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMCommand& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMCommand* rec;

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
			PQfnumber(res, "ixvrettype"),
			PQfnumber(res, "ivrrefwdbemsignal"),
			PQfnumber(res, "rvrrefwdbemsignal"),
			PQfnumber(res, "rerrefwdbemsignal"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMCommand();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fullsref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVRettype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ivrRefWdbeMSignal = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->rvrRefWdbeMSignal = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->rerRefWdbeMSignal = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMCommand::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMCommand** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCommand::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMCommand::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMCommand& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCommand::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMCommand::loadRecBySQL(
			const string& sqlstr
			, WdbeMCommand** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCommand::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMCommand::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMCommand& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCommand::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMCommand::insertRec(
			WdbeMCommand* rec
		) {
	PGresult* res;
	char* ptr;

	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _refNum = htonl(rec->refNum);
	uint _ixVRettype = htonl(rec->ixVRettype);
	ubigint _ivrRefWdbeMSignal = htonl64(rec->ivrRefWdbeMSignal);
	ubigint _rvrRefWdbeMSignal = htonl64(rec->rvrRefWdbeMSignal);
	ubigint _rerRefWdbeMSignal = htonl64(rec->rerRefWdbeMSignal);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refNum,
		rec->sref.c_str(),
		rec->Fullsref.c_str(),
		(char*) &_ixVRettype,
		(char*) &_ivrRefWdbeMSignal,
		(char*) &_rvrRefWdbeMSignal,
		(char*) &_rerRefWdbeMSignal,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeMCommand_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMCommand::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMCommand::insertRst(
			ListWdbeMCommand& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMCommand::updateRec(
			WdbeMCommand* rec
		) {
	PGresult* res;

	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _refNum = htonl(rec->refNum);
	uint _ixVRettype = htonl(rec->ixVRettype);
	ubigint _ivrRefWdbeMSignal = htonl64(rec->ivrRefWdbeMSignal);
	ubigint _rvrRefWdbeMSignal = htonl64(rec->rvrRefWdbeMSignal);
	ubigint _rerRefWdbeMSignal = htonl64(rec->rerRefWdbeMSignal);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refNum,
		rec->sref.c_str(),
		rec->Fullsref.c_str(),
		(char*) &_ixVRettype,
		(char*) &_ivrRefWdbeMSignal,
		(char*) &_rvrRefWdbeMSignal,
		(char*) &_rerRefWdbeMSignal,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMCommand_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMCommand::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMCommand::updateRst(
			ListWdbeMCommand& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMCommand::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMCommand_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMCommand::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMCommand::loadRecByRef(
			ubigint ref
			, WdbeMCommand** rec
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

	return loadRecByStmt("TblWdbeMCommand_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMCommand::loadRefsByRetReu(
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

	return loadRefsByStmt("TblWdbeMCommand_loadRefsByRetReu", 2, vals, l, f, append, refs);
};

ubigint PgTblWdbeMCommand::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMCommand& rst
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

	return loadRstByStmt("TblWdbeMCommand_loadRstByRetReu", 2, vals, l, f, append, rst);
};

#endif

