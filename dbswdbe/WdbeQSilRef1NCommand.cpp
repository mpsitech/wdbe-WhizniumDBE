/**
	* \file WdbeQSilRef1NCommand.cpp
	* Dbs and XML wrapper for table TblWdbeQSilRef1NCommand (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQSilRef1NCommand.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSilRef1NCommand
 ******************************************************************************/

WdbeQSilRef1NCommand::WdbeQSilRef1NCommand(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint refNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->refNum = refNum;
};

void WdbeQSilRef1NCommand::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQSilRef1NCommand";

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
 class ListWdbeQSilRef1NCommand
 ******************************************************************************/

ListWdbeQSilRef1NCommand::ListWdbeQSilRef1NCommand() {
};

ListWdbeQSilRef1NCommand::ListWdbeQSilRef1NCommand(
			const ListWdbeQSilRef1NCommand& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSilRef1NCommand(*(src.nodes[i]));
};

ListWdbeQSilRef1NCommand::~ListWdbeQSilRef1NCommand() {
	clear();
};

void ListWdbeQSilRef1NCommand::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQSilRef1NCommand::size() const {
	return(nodes.size());
};

void ListWdbeQSilRef1NCommand::append(
			WdbeQSilRef1NCommand* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQSilRef1NCommand& ListWdbeQSilRef1NCommand::operator=(
			const ListWdbeQSilRef1NCommand& src
		) {
	WdbeQSilRef1NCommand* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQSilRef1NCommand(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQSilRef1NCommand::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQSilRef1NCommand";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQSilRef1NCommand
 ******************************************************************************/

TblWdbeQSilRef1NCommand::TblWdbeQSilRef1NCommand() {
};

TblWdbeQSilRef1NCommand::~TblWdbeQSilRef1NCommand() {
};

bool TblWdbeQSilRef1NCommand::loadRecBySQL(
			const string& sqlstr
			, WdbeQSilRef1NCommand** rec
		) {
	return false;
};

ubigint TblWdbeQSilRef1NCommand::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSilRef1NCommand& rst
		) {
	return 0;
};

ubigint TblWdbeQSilRef1NCommand::insertRec(
			WdbeQSilRef1NCommand* rec
		) {
	return 0;
};

ubigint TblWdbeQSilRef1NCommand::insertNewRec(
			WdbeQSilRef1NCommand** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint refNum
		) {
	ubigint retval = 0;
	WdbeQSilRef1NCommand* _rec = NULL;

	_rec = new WdbeQSilRef1NCommand(0, jref, jnum, ref, stubRef, refNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQSilRef1NCommand::appendNewRecToRst(
			ListWdbeQSilRef1NCommand& rst
			, WdbeQSilRef1NCommand** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint refNum
		) {
	ubigint retval = 0;
	WdbeQSilRef1NCommand* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, refNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQSilRef1NCommand::insertRst(
			ListWdbeQSilRef1NCommand& rst
		) {
};

void TblWdbeQSilRef1NCommand::updateRec(
			WdbeQSilRef1NCommand* rec
		) {
};

void TblWdbeQSilRef1NCommand::updateRst(
			ListWdbeQSilRef1NCommand& rst
		) {
};

void TblWdbeQSilRef1NCommand::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQSilRef1NCommand::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQSilRef1NCommand::loadRecByQref(
			ubigint qref
			, WdbeQSilRef1NCommand** rec
		) {
	return false;
};

ubigint TblWdbeQSilRef1NCommand::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSilRef1NCommand& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQSilRef1NCommand
 ******************************************************************************/

MyTblWdbeQSilRef1NCommand::MyTblWdbeQSilRef1NCommand() :
			TblWdbeQSilRef1NCommand()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQSilRef1NCommand::~MyTblWdbeQSilRef1NCommand() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQSilRef1NCommand::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQSilRef1NCommand (jref, jnum, ref, refNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQSilRef1NCommand SET jref = ?, jnum = ?, ref = ?, refNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQSilRef1NCommand WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQSilRef1NCommand WHERE jref = ?", false);
};

bool MyTblWdbeQSilRef1NCommand::loadRecBySQL(
			const string& sqlstr
			, WdbeQSilRef1NCommand** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQSilRef1NCommand* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSilRef1NCommand::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSilRef1NCommand::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQSilRef1NCommand();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refNum = atol((char*) dbrow[4]); else _rec->refNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQSilRef1NCommand::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSilRef1NCommand& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQSilRef1NCommand* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSilRef1NCommand::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSilRef1NCommand::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQSilRef1NCommand();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refNum = atol((char*) dbrow[4]); else rec->refNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQSilRef1NCommand::insertRec(
			WdbeQSilRef1NCommand* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQSilRef1NCommand::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQSilRef1NCommand::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQSilRef1NCommand::insertRst(
			ListWdbeQSilRef1NCommand& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQSilRef1NCommand::updateRec(
			WdbeQSilRef1NCommand* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQSilRef1NCommand::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQSilRef1NCommand::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSilRef1NCommand::updateRst(
			ListWdbeQSilRef1NCommand& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQSilRef1NCommand::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQSilRef1NCommand::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQSilRef1NCommand::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSilRef1NCommand::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQSilRef1NCommand::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQSilRef1NCommand::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQSilRef1NCommand::loadRecByQref(
			ubigint qref
			, WdbeQSilRef1NCommand** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQSilRef1NCommand WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQSilRef1NCommand::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSilRef1NCommand& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQSilRef1NCommand WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQSilRef1NCommand
 ******************************************************************************/

PgTblWdbeQSilRef1NCommand::PgTblWdbeQSilRef1NCommand() :
			TblWdbeQSilRef1NCommand()
			, PgTable()
		{
};

PgTblWdbeQSilRef1NCommand::~PgTblWdbeQSilRef1NCommand() {
};

void PgTblWdbeQSilRef1NCommand::initStatements() {
	createStatement("TblWdbeQSilRef1NCommand_insertRec", "INSERT INTO TblWdbeQSilRef1NCommand (jref, jnum, ref, refNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWdbeQSilRef1NCommand_updateRec", "UPDATE TblWdbeQSilRef1NCommand SET jref = $1, jnum = $2, ref = $3, refNum = $4 WHERE qref = $5", 5);
	createStatement("TblWdbeQSilRef1NCommand_removeRecByQref", "DELETE FROM TblWdbeQSilRef1NCommand WHERE qref = $1", 1);
	createStatement("TblWdbeQSilRef1NCommand_removeRstByJref", "DELETE FROM TblWdbeQSilRef1NCommand WHERE jref = $1", 1);

	createStatement("TblWdbeQSilRef1NCommand_loadRecByQref", "SELECT qref, jref, jnum, ref, refNum FROM TblWdbeQSilRef1NCommand WHERE qref = $1", 1);
	createStatement("TblWdbeQSilRef1NCommand_loadRstByJref", "SELECT qref, jref, jnum, ref, refNum FROM TblWdbeQSilRef1NCommand WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQSilRef1NCommand::loadRec(
			PGresult* res
			, WdbeQSilRef1NCommand** rec
		) {
	char* ptr;

	WdbeQSilRef1NCommand* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQSilRef1NCommand();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQSilRef1NCommand::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQSilRef1NCommand& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQSilRef1NCommand* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refnum")
		};

		while (numread < numrow) {
			rec = new WdbeQSilRef1NCommand();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQSilRef1NCommand::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQSilRef1NCommand** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSilRef1NCommand::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSilRef1NCommand::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQSilRef1NCommand& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSilRef1NCommand::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQSilRef1NCommand::loadRecBySQL(
			const string& sqlstr
			, WdbeQSilRef1NCommand** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSilRef1NCommand::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSilRef1NCommand::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSilRef1NCommand& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSilRef1NCommand::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQSilRef1NCommand::insertRec(
			WdbeQSilRef1NCommand* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refNum = htonl(rec->refNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQSilRef1NCommand_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSilRef1NCommand::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQSilRef1NCommand::insertRst(
			ListWdbeQSilRef1NCommand& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQSilRef1NCommand::updateRec(
			WdbeQSilRef1NCommand* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refNum = htonl(rec->refNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refNum,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQSilRef1NCommand_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSilRef1NCommand::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSilRef1NCommand::updateRst(
			ListWdbeQSilRef1NCommand& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQSilRef1NCommand::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSilRef1NCommand_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSilRef1NCommand::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSilRef1NCommand::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSilRef1NCommand_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSilRef1NCommand::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQSilRef1NCommand::loadRecByQref(
			ubigint qref
			, WdbeQSilRef1NCommand** rec
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

	return loadRecByStmt("TblWdbeQSilRef1NCommand_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQSilRef1NCommand::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSilRef1NCommand& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQSilRef1NCommand_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

