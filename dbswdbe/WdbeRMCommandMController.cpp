/**
	* \file WdbeRMCommandMController.cpp
	* database access for table TblWdbeRMCommandMController (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeRMCommandMController.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeRMCommandMController
 ******************************************************************************/

WdbeRMCommandMController::WdbeRMCommandMController(
			const ubigint ref
			, const ubigint refWdbeMCommand
			, const ubigint refWdbeMController
			, const ubigint ivrRefWdbeMSignal
			, const ubigint rvrRefWdbeMSignal
		) {

	this->ref = ref;
	this->refWdbeMCommand = refWdbeMCommand;
	this->refWdbeMController = refWdbeMController;
	this->ivrRefWdbeMSignal = ivrRefWdbeMSignal;
	this->rvrRefWdbeMSignal = rvrRefWdbeMSignal;
};

bool WdbeRMCommandMController::operator==(
			const WdbeRMCommandMController& comp
		) {
	return false;
};

bool WdbeRMCommandMController::operator!=(
			const WdbeRMCommandMController& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeRMCommandMController
 ******************************************************************************/

ListWdbeRMCommandMController::ListWdbeRMCommandMController() {
};

ListWdbeRMCommandMController::ListWdbeRMCommandMController(
			const ListWdbeRMCommandMController& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeRMCommandMController(*(src.nodes[i]));
};

ListWdbeRMCommandMController::~ListWdbeRMCommandMController() {
	clear();
};

void ListWdbeRMCommandMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeRMCommandMController::size() const {
	return(nodes.size());
};

void ListWdbeRMCommandMController::append(
			WdbeRMCommandMController* rec
		) {
	nodes.push_back(rec);
};

WdbeRMCommandMController* ListWdbeRMCommandMController::operator[](
			const uint ix
		) {
	WdbeRMCommandMController* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeRMCommandMController& ListWdbeRMCommandMController::operator=(
			const ListWdbeRMCommandMController& src
		) {
	WdbeRMCommandMController* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeRMCommandMController(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeRMCommandMController::operator==(
			const ListWdbeRMCommandMController& comp
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

bool ListWdbeRMCommandMController::operator!=(
			const ListWdbeRMCommandMController& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeRMCommandMController
 ******************************************************************************/

TblWdbeRMCommandMController::TblWdbeRMCommandMController() {
};

TblWdbeRMCommandMController::~TblWdbeRMCommandMController() {
};

bool TblWdbeRMCommandMController::loadRecBySQL(
			const string& sqlstr
			, WdbeRMCommandMController** rec
		) {
	return false;
};

ubigint TblWdbeRMCommandMController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	return 0;
};

ubigint TblWdbeRMCommandMController::insertRec(
			WdbeRMCommandMController* rec
		) {
	return 0;
};

ubigint TblWdbeRMCommandMController::insertNewRec(
			WdbeRMCommandMController** rec
			, const ubigint refWdbeMCommand
			, const ubigint refWdbeMController
			, const ubigint ivrRefWdbeMSignal
			, const ubigint rvrRefWdbeMSignal
		) {
	ubigint retval = 0;
	WdbeRMCommandMController* _rec = NULL;

	_rec = new WdbeRMCommandMController(0, refWdbeMCommand, refWdbeMController, ivrRefWdbeMSignal, rvrRefWdbeMSignal);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeRMCommandMController::appendNewRecToRst(
			ListWdbeRMCommandMController& rst
			, WdbeRMCommandMController** rec
			, const ubigint refWdbeMCommand
			, const ubigint refWdbeMController
			, const ubigint ivrRefWdbeMSignal
			, const ubigint rvrRefWdbeMSignal
		) {
	ubigint retval = 0;
	WdbeRMCommandMController* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMCommand, refWdbeMController, ivrRefWdbeMSignal, rvrRefWdbeMSignal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeRMCommandMController::insertRst(
			ListWdbeRMCommandMController& rst
			, bool transact
		) {
};

void TblWdbeRMCommandMController::updateRec(
			WdbeRMCommandMController* rec
		) {
};

void TblWdbeRMCommandMController::updateRst(
			ListWdbeRMCommandMController& rst
			, bool transact
		) {
};

void TblWdbeRMCommandMController::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeRMCommandMController::loadRecByRef(
			ubigint ref
			, WdbeRMCommandMController** rec
		) {
	return false;
};

ubigint TblWdbeRMCommandMController::loadRefsByCtr(
			ubigint refWdbeMController
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeRMCommandMController::loadRstByCmd(
			ubigint refWdbeMCommand
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	return 0;
};

ubigint TblWdbeRMCommandMController::loadRstByCtr(
			ubigint refWdbeMController
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	return 0;
};

ubigint TblWdbeRMCommandMController::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	ubigint numload = 0;
	WdbeRMCommandMController* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeRMCommandMController
 ******************************************************************************/

MyTblWdbeRMCommandMController::MyTblWdbeRMCommandMController() :
			TblWdbeRMCommandMController()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeRMCommandMController::~MyTblWdbeRMCommandMController() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeRMCommandMController::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeRMCommandMController (refWdbeMCommand, refWdbeMController, ivrRefWdbeMSignal, rvrRefWdbeMSignal) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeRMCommandMController SET refWdbeMCommand = ?, refWdbeMController = ?, ivrRefWdbeMSignal = ?, rvrRefWdbeMSignal = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeRMCommandMController WHERE ref = ?", false);
};

bool MyTblWdbeRMCommandMController::loadRecBySQL(
			const string& sqlstr
			, WdbeRMCommandMController** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeRMCommandMController* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMCommandMController::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMCommandMController::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeRMCommandMController();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMCommand = atoll((char*) dbrow[1]); else _rec->refWdbeMCommand = 0;
		if (dbrow[2]) _rec->refWdbeMController = atoll((char*) dbrow[2]); else _rec->refWdbeMController = 0;
		if (dbrow[3]) _rec->ivrRefWdbeMSignal = atoll((char*) dbrow[3]); else _rec->ivrRefWdbeMSignal = 0;
		if (dbrow[4]) _rec->rvrRefWdbeMSignal = atoll((char*) dbrow[4]); else _rec->rvrRefWdbeMSignal = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeRMCommandMController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeRMCommandMController* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeRMCommandMController::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeRMCommandMController::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeRMCommandMController();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMCommand = atoll((char*) dbrow[1]); else rec->refWdbeMCommand = 0;
			if (dbrow[2]) rec->refWdbeMController = atoll((char*) dbrow[2]); else rec->refWdbeMController = 0;
			if (dbrow[3]) rec->ivrRefWdbeMSignal = atoll((char*) dbrow[3]); else rec->ivrRefWdbeMSignal = 0;
			if (dbrow[4]) rec->rvrRefWdbeMSignal = atoll((char*) dbrow[4]); else rec->rvrRefWdbeMSignal = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeRMCommandMController::insertRec(
			WdbeRMCommandMController* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMCommand,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMController,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ivrRefWdbeMSignal,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->rvrRefWdbeMSignal,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeRMCommandMController::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeRMCommandMController::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeRMCommandMController::insertRst(
			ListWdbeRMCommandMController& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeRMCommandMController::updateRec(
			WdbeRMCommandMController* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMCommand,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeMController,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ivrRefWdbeMSignal,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->rvrRefWdbeMSignal,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeRMCommandMController::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeRMCommandMController::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeRMCommandMController::updateRst(
			ListWdbeRMCommandMController& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeRMCommandMController::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeRMCommandMController::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeRMCommandMController::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeRMCommandMController::loadRecByRef(
			ubigint ref
			, WdbeRMCommandMController** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeRMCommandMController WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeRMCommandMController::loadRefsByCtr(
			ubigint refWdbeMController
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeRMCommandMController WHERE refWdbeMController = " + to_string(refWdbeMController) + "", append, refs);
};

ubigint MyTblWdbeRMCommandMController::loadRstByCmd(
			ubigint refWdbeMCommand
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMCommand, refWdbeMController, ivrRefWdbeMSignal, rvrRefWdbeMSignal FROM TblWdbeRMCommandMController WHERE refWdbeMCommand = " + to_string(refWdbeMCommand) + "", append, rst);
};

ubigint MyTblWdbeRMCommandMController::loadRstByCtr(
			ubigint refWdbeMController
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMCommand, refWdbeMController, ivrRefWdbeMSignal, rvrRefWdbeMSignal FROM TblWdbeRMCommandMController WHERE refWdbeMController = " + to_string(refWdbeMController) + "", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeRMCommandMController
 ******************************************************************************/

PgTblWdbeRMCommandMController::PgTblWdbeRMCommandMController() :
			TblWdbeRMCommandMController()
			, PgTable()
		{
};

PgTblWdbeRMCommandMController::~PgTblWdbeRMCommandMController() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeRMCommandMController::initStatements() {
	createStatement("TblWdbeRMCommandMController_insertRec", "INSERT INTO TblWdbeRMCommandMController (refWdbeMCommand, refWdbeMController, ivrRefWdbeMSignal, rvrRefWdbeMSignal) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeRMCommandMController_updateRec", "UPDATE TblWdbeRMCommandMController SET refWdbeMCommand = $1, refWdbeMController = $2, ivrRefWdbeMSignal = $3, rvrRefWdbeMSignal = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeRMCommandMController_removeRecByRef", "DELETE FROM TblWdbeRMCommandMController WHERE ref = $1", 1);

	createStatement("TblWdbeRMCommandMController_loadRecByRef", "SELECT ref, refWdbeMCommand, refWdbeMController, ivrRefWdbeMSignal, rvrRefWdbeMSignal FROM TblWdbeRMCommandMController WHERE ref = $1", 1);
	createStatement("TblWdbeRMCommandMController_loadRefsByCtr", "SELECT ref FROM TblWdbeRMCommandMController WHERE refWdbeMController = $1", 1);
	createStatement("TblWdbeRMCommandMController_loadRstByCmd", "SELECT ref, refWdbeMCommand, refWdbeMController, ivrRefWdbeMSignal, rvrRefWdbeMSignal FROM TblWdbeRMCommandMController WHERE refWdbeMCommand = $1", 1);
	createStatement("TblWdbeRMCommandMController_loadRstByCtr", "SELECT ref, refWdbeMCommand, refWdbeMController, ivrRefWdbeMSignal, rvrRefWdbeMSignal FROM TblWdbeRMCommandMController WHERE refWdbeMController = $1", 1);
};

bool PgTblWdbeRMCommandMController::loadRec(
			PGresult* res
			, WdbeRMCommandMController** rec
		) {
	char* ptr;

	WdbeRMCommandMController* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeRMCommandMController();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemcommand"),
			PQfnumber(res, "refwdbemcontroller"),
			PQfnumber(res, "ivrrefwdbemsignal"),
			PQfnumber(res, "rvrrefwdbemsignal")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMCommand = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeMController = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ivrRefWdbeMSignal = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->rvrRefWdbeMSignal = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeRMCommandMController::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeRMCommandMController* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemcommand"),
			PQfnumber(res, "refwdbemcontroller"),
			PQfnumber(res, "ivrrefwdbemsignal"),
			PQfnumber(res, "rvrrefwdbemsignal")
		};

		while (numread < numrow) {
			rec = new WdbeRMCommandMController();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMCommand = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeMController = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ivrRefWdbeMSignal = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->rvrRefWdbeMSignal = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeRMCommandMController::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeRMCommandMController** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCommandMController::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMCommandMController::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCommandMController::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeRMCommandMController::loadRecBySQL(
			const string& sqlstr
			, WdbeRMCommandMController** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCommandMController::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeRMCommandMController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCommandMController::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeRMCommandMController::insertRec(
			WdbeRMCommandMController* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMCommand = htonl64(rec->refWdbeMCommand);
	ubigint _refWdbeMController = htonl64(rec->refWdbeMController);
	ubigint _ivrRefWdbeMSignal = htonl64(rec->ivrRefWdbeMSignal);
	ubigint _rvrRefWdbeMSignal = htonl64(rec->rvrRefWdbeMSignal);

	const char* vals[] = {
		(char*) &_refWdbeMCommand,
		(char*) &_refWdbeMController,
		(char*) &_ivrRefWdbeMSignal,
		(char*) &_rvrRefWdbeMSignal
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMCommandMController_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeRMCommandMController::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeRMCommandMController::insertRst(
			ListWdbeRMCommandMController& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeRMCommandMController::updateRec(
			WdbeRMCommandMController* rec
		) {
	PGresult* res;

	ubigint _refWdbeMCommand = htonl64(rec->refWdbeMCommand);
	ubigint _refWdbeMController = htonl64(rec->refWdbeMController);
	ubigint _ivrRefWdbeMSignal = htonl64(rec->ivrRefWdbeMSignal);
	ubigint _rvrRefWdbeMSignal = htonl64(rec->rvrRefWdbeMSignal);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMCommand,
		(char*) &_refWdbeMController,
		(char*) &_ivrRefWdbeMSignal,
		(char*) &_rvrRefWdbeMSignal,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeRMCommandMController_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMCommandMController::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeRMCommandMController::updateRst(
			ListWdbeRMCommandMController& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeRMCommandMController::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeRMCommandMController_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeRMCommandMController::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeRMCommandMController::loadRecByRef(
			ubigint ref
			, WdbeRMCommandMController** rec
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

	return loadRecByStmt("TblWdbeRMCommandMController_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeRMCommandMController::loadRefsByCtr(
			ubigint refWdbeMController
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMController = htonl64(refWdbeMController);

	const char* vals[] = {
		(char*) &_refWdbeMController
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeRMCommandMController_loadRefsByCtr", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeRMCommandMController::loadRstByCmd(
			ubigint refWdbeMCommand
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	ubigint _refWdbeMCommand = htonl64(refWdbeMCommand);

	const char* vals[] = {
		(char*) &_refWdbeMCommand
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMCommandMController_loadRstByCmd", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeRMCommandMController::loadRstByCtr(
			ubigint refWdbeMController
			, const bool append
			, ListWdbeRMCommandMController& rst
		) {
	ubigint _refWdbeMController = htonl64(refWdbeMController);

	const char* vals[] = {
		(char*) &_refWdbeMController
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeRMCommandMController_loadRstByCtr", 1, vals, l, f, append, rst);
};

#endif

