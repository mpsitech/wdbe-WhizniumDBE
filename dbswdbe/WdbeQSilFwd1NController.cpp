/**
	* \file WdbeQSilFwd1NController.cpp
	* Dbs and XML wrapper for table TblWdbeQSilFwd1NController (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQSilFwd1NController.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSilFwd1NController
 ******************************************************************************/

WdbeQSilFwd1NController::WdbeQSilFwd1NController(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void WdbeQSilFwd1NController::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQSilFwd1NController";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQSilFwd1NController
 ******************************************************************************/

ListWdbeQSilFwd1NController::ListWdbeQSilFwd1NController() {
};

ListWdbeQSilFwd1NController::ListWdbeQSilFwd1NController(
			const ListWdbeQSilFwd1NController& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSilFwd1NController(*(src.nodes[i]));
};

ListWdbeQSilFwd1NController::~ListWdbeQSilFwd1NController() {
	clear();
};

void ListWdbeQSilFwd1NController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQSilFwd1NController::size() const {
	return(nodes.size());
};

void ListWdbeQSilFwd1NController::append(
			WdbeQSilFwd1NController* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQSilFwd1NController& ListWdbeQSilFwd1NController::operator=(
			const ListWdbeQSilFwd1NController& src
		) {
	WdbeQSilFwd1NController* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQSilFwd1NController(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQSilFwd1NController::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQSilFwd1NController";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQSilFwd1NController
 ******************************************************************************/

TblWdbeQSilFwd1NController::TblWdbeQSilFwd1NController() {
};

TblWdbeQSilFwd1NController::~TblWdbeQSilFwd1NController() {
};

bool TblWdbeQSilFwd1NController::loadRecBySQL(
			const string& sqlstr
			, WdbeQSilFwd1NController** rec
		) {
	return false;
};

ubigint TblWdbeQSilFwd1NController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSilFwd1NController& rst
		) {
	return 0;
};

ubigint TblWdbeQSilFwd1NController::insertRec(
			WdbeQSilFwd1NController* rec
		) {
	return 0;
};

ubigint TblWdbeQSilFwd1NController::insertNewRec(
			WdbeQSilFwd1NController** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQSilFwd1NController* _rec = NULL;

	_rec = new WdbeQSilFwd1NController(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQSilFwd1NController::appendNewRecToRst(
			ListWdbeQSilFwd1NController& rst
			, WdbeQSilFwd1NController** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQSilFwd1NController* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQSilFwd1NController::insertRst(
			ListWdbeQSilFwd1NController& rst
		) {
};

void TblWdbeQSilFwd1NController::updateRec(
			WdbeQSilFwd1NController* rec
		) {
};

void TblWdbeQSilFwd1NController::updateRst(
			ListWdbeQSilFwd1NController& rst
		) {
};

void TblWdbeQSilFwd1NController::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQSilFwd1NController::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQSilFwd1NController::loadRecByQref(
			ubigint qref
			, WdbeQSilFwd1NController** rec
		) {
	return false;
};

ubigint TblWdbeQSilFwd1NController::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSilFwd1NController& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQSilFwd1NController
 ******************************************************************************/

MyTblWdbeQSilFwd1NController::MyTblWdbeQSilFwd1NController() :
			TblWdbeQSilFwd1NController()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQSilFwd1NController::~MyTblWdbeQSilFwd1NController() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQSilFwd1NController::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQSilFwd1NController (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQSilFwd1NController SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQSilFwd1NController WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQSilFwd1NController WHERE jref = ?", false);
};

bool MyTblWdbeQSilFwd1NController::loadRecBySQL(
			const string& sqlstr
			, WdbeQSilFwd1NController** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQSilFwd1NController* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSilFwd1NController::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSilFwd1NController::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQSilFwd1NController();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQSilFwd1NController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSilFwd1NController& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQSilFwd1NController* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSilFwd1NController::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSilFwd1NController::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQSilFwd1NController();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQSilFwd1NController::insertRec(
			WdbeQSilFwd1NController* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQSilFwd1NController::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQSilFwd1NController::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQSilFwd1NController::insertRst(
			ListWdbeQSilFwd1NController& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQSilFwd1NController::updateRec(
			WdbeQSilFwd1NController* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQSilFwd1NController::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQSilFwd1NController::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSilFwd1NController::updateRst(
			ListWdbeQSilFwd1NController& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQSilFwd1NController::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQSilFwd1NController::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQSilFwd1NController::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSilFwd1NController::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQSilFwd1NController::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQSilFwd1NController::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQSilFwd1NController::loadRecByQref(
			ubigint qref
			, WdbeQSilFwd1NController** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQSilFwd1NController WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQSilFwd1NController::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSilFwd1NController& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQSilFwd1NController WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQSilFwd1NController
 ******************************************************************************/

PgTblWdbeQSilFwd1NController::PgTblWdbeQSilFwd1NController() :
			TblWdbeQSilFwd1NController()
			, PgTable()
		{
};

PgTblWdbeQSilFwd1NController::~PgTblWdbeQSilFwd1NController() {
};

void PgTblWdbeQSilFwd1NController::initStatements() {
	createStatement("TblWdbeQSilFwd1NController_insertRec", "INSERT INTO TblWdbeQSilFwd1NController (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWdbeQSilFwd1NController_updateRec", "UPDATE TblWdbeQSilFwd1NController SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWdbeQSilFwd1NController_removeRecByQref", "DELETE FROM TblWdbeQSilFwd1NController WHERE qref = $1", 1);
	createStatement("TblWdbeQSilFwd1NController_removeRstByJref", "DELETE FROM TblWdbeQSilFwd1NController WHERE jref = $1", 1);

	createStatement("TblWdbeQSilFwd1NController_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWdbeQSilFwd1NController WHERE qref = $1", 1);
	createStatement("TblWdbeQSilFwd1NController_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWdbeQSilFwd1NController WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQSilFwd1NController::loadRec(
			PGresult* res
			, WdbeQSilFwd1NController** rec
		) {
	char* ptr;

	WdbeQSilFwd1NController* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQSilFwd1NController();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQSilFwd1NController::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQSilFwd1NController& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQSilFwd1NController* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new WdbeQSilFwd1NController();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQSilFwd1NController::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQSilFwd1NController** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSilFwd1NController::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSilFwd1NController::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQSilFwd1NController& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSilFwd1NController::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQSilFwd1NController::loadRecBySQL(
			const string& sqlstr
			, WdbeQSilFwd1NController** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSilFwd1NController::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSilFwd1NController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSilFwd1NController& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSilFwd1NController::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQSilFwd1NController::insertRec(
			WdbeQSilFwd1NController* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQSilFwd1NController_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSilFwd1NController::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQSilFwd1NController::insertRst(
			ListWdbeQSilFwd1NController& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQSilFwd1NController::updateRec(
			WdbeQSilFwd1NController* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQSilFwd1NController_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSilFwd1NController::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSilFwd1NController::updateRst(
			ListWdbeQSilFwd1NController& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQSilFwd1NController::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWdbeQSilFwd1NController_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSilFwd1NController::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSilFwd1NController::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWdbeQSilFwd1NController_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSilFwd1NController::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQSilFwd1NController::loadRecByQref(
			ubigint qref
			, WdbeQSilFwd1NController** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeQSilFwd1NController_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQSilFwd1NController::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSilFwd1NController& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQSilFwd1NController_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

