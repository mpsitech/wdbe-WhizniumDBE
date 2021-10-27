/**
	* \file WdbeQUnt1NInterrupt.cpp
	* Dbs and XML wrapper for table TblWdbeQUnt1NInterrupt (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQUnt1NInterrupt.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUnt1NInterrupt
 ******************************************************************************/

WdbeQUnt1NInterrupt::WdbeQUnt1NInterrupt(
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

void WdbeQUnt1NInterrupt::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["ref"] = stubRef;
	} else {
		me["stubRef"] = stubRef;
	};
};

void WdbeQUnt1NInterrupt::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQUnt1NInterrupt";

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
 class ListWdbeQUnt1NInterrupt
 ******************************************************************************/

ListWdbeQUnt1NInterrupt::ListWdbeQUnt1NInterrupt() {
};

ListWdbeQUnt1NInterrupt::ListWdbeQUnt1NInterrupt(
			const ListWdbeQUnt1NInterrupt& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUnt1NInterrupt(*(src.nodes[i]));
};

ListWdbeQUnt1NInterrupt::~ListWdbeQUnt1NInterrupt() {
	clear();
};

void ListWdbeQUnt1NInterrupt::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQUnt1NInterrupt::size() const {
	return(nodes.size());
};

void ListWdbeQUnt1NInterrupt::append(
			WdbeQUnt1NInterrupt* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQUnt1NInterrupt& ListWdbeQUnt1NInterrupt::operator=(
			const ListWdbeQUnt1NInterrupt& src
		) {
	WdbeQUnt1NInterrupt* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQUnt1NInterrupt(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQUnt1NInterrupt::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQUnt1NInterrupt";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQUnt1NInterrupt::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQUnt1NInterrupt";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQUnt1NInterrupt
 ******************************************************************************/

TblWdbeQUnt1NInterrupt::TblWdbeQUnt1NInterrupt() {
};

TblWdbeQUnt1NInterrupt::~TblWdbeQUnt1NInterrupt() {
};

bool TblWdbeQUnt1NInterrupt::loadRecBySQL(
			const string& sqlstr
			, WdbeQUnt1NInterrupt** rec
		) {
	return false;
};

ubigint TblWdbeQUnt1NInterrupt::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUnt1NInterrupt& rst
		) {
	return 0;
};

ubigint TblWdbeQUnt1NInterrupt::insertRec(
			WdbeQUnt1NInterrupt* rec
		) {
	return 0;
};

ubigint TblWdbeQUnt1NInterrupt::insertNewRec(
			WdbeQUnt1NInterrupt** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQUnt1NInterrupt* _rec = NULL;

	_rec = new WdbeQUnt1NInterrupt(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQUnt1NInterrupt::appendNewRecToRst(
			ListWdbeQUnt1NInterrupt& rst
			, WdbeQUnt1NInterrupt** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQUnt1NInterrupt* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQUnt1NInterrupt::insertRst(
			ListWdbeQUnt1NInterrupt& rst
		) {
};

void TblWdbeQUnt1NInterrupt::updateRec(
			WdbeQUnt1NInterrupt* rec
		) {
};

void TblWdbeQUnt1NInterrupt::updateRst(
			ListWdbeQUnt1NInterrupt& rst
		) {
};

void TblWdbeQUnt1NInterrupt::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQUnt1NInterrupt::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQUnt1NInterrupt::loadRecByQref(
			ubigint qref
			, WdbeQUnt1NInterrupt** rec
		) {
	return false;
};

ubigint TblWdbeQUnt1NInterrupt::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUnt1NInterrupt& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQUnt1NInterrupt
 ******************************************************************************/

MyTblWdbeQUnt1NInterrupt::MyTblWdbeQUnt1NInterrupt() :
			TblWdbeQUnt1NInterrupt()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQUnt1NInterrupt::~MyTblWdbeQUnt1NInterrupt() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQUnt1NInterrupt::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQUnt1NInterrupt (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQUnt1NInterrupt SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQUnt1NInterrupt WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQUnt1NInterrupt WHERE jref = ?", false);
};

bool MyTblWdbeQUnt1NInterrupt::loadRecBySQL(
			const string& sqlstr
			, WdbeQUnt1NInterrupt** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQUnt1NInterrupt* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQUnt1NInterrupt();

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

ubigint MyTblWdbeQUnt1NInterrupt::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUnt1NInterrupt& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQUnt1NInterrupt* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQUnt1NInterrupt();

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

ubigint MyTblWdbeQUnt1NInterrupt::insertRec(
			WdbeQUnt1NInterrupt* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQUnt1NInterrupt::insertRst(
			ListWdbeQUnt1NInterrupt& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQUnt1NInterrupt::updateRec(
			WdbeQUnt1NInterrupt* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQUnt1NInterrupt::updateRst(
			ListWdbeQUnt1NInterrupt& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQUnt1NInterrupt::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQUnt1NInterrupt::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQUnt1NInterrupt::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQUnt1NInterrupt::loadRecByQref(
			ubigint qref
			, WdbeQUnt1NInterrupt** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQUnt1NInterrupt WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQUnt1NInterrupt::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUnt1NInterrupt& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQUnt1NInterrupt WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQUnt1NInterrupt
 ******************************************************************************/

PgTblWdbeQUnt1NInterrupt::PgTblWdbeQUnt1NInterrupt() :
			TblWdbeQUnt1NInterrupt()
			, PgTable()
		{
};

PgTblWdbeQUnt1NInterrupt::~PgTblWdbeQUnt1NInterrupt() {
};

void PgTblWdbeQUnt1NInterrupt::initStatements() {
	createStatement("TblWdbeQUnt1NInterrupt_insertRec", "INSERT INTO TblWdbeQUnt1NInterrupt (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWdbeQUnt1NInterrupt_updateRec", "UPDATE TblWdbeQUnt1NInterrupt SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWdbeQUnt1NInterrupt_removeRecByQref", "DELETE FROM TblWdbeQUnt1NInterrupt WHERE qref = $1", 1);
	createStatement("TblWdbeQUnt1NInterrupt_removeRstByJref", "DELETE FROM TblWdbeQUnt1NInterrupt WHERE jref = $1", 1);

	createStatement("TblWdbeQUnt1NInterrupt_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWdbeQUnt1NInterrupt WHERE qref = $1", 1);
	createStatement("TblWdbeQUnt1NInterrupt_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWdbeQUnt1NInterrupt WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQUnt1NInterrupt::loadRec(
			PGresult* res
			, WdbeQUnt1NInterrupt** rec
		) {
	char* ptr;

	WdbeQUnt1NInterrupt* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQUnt1NInterrupt();

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

ubigint PgTblWdbeQUnt1NInterrupt::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQUnt1NInterrupt& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQUnt1NInterrupt* rec;

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
			rec = new WdbeQUnt1NInterrupt();

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

bool PgTblWdbeQUnt1NInterrupt::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQUnt1NInterrupt** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUnt1NInterrupt::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQUnt1NInterrupt::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQUnt1NInterrupt& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUnt1NInterrupt::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQUnt1NInterrupt::loadRecBySQL(
			const string& sqlstr
			, WdbeQUnt1NInterrupt** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQUnt1NInterrupt::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQUnt1NInterrupt::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUnt1NInterrupt& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQUnt1NInterrupt::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQUnt1NInterrupt::insertRec(
			WdbeQUnt1NInterrupt* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQUnt1NInterrupt_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUnt1NInterrupt::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQUnt1NInterrupt::insertRst(
			ListWdbeQUnt1NInterrupt& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQUnt1NInterrupt::updateRec(
			WdbeQUnt1NInterrupt* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQUnt1NInterrupt_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUnt1NInterrupt::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQUnt1NInterrupt::updateRst(
			ListWdbeQUnt1NInterrupt& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQUnt1NInterrupt::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQUnt1NInterrupt_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUnt1NInterrupt::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQUnt1NInterrupt::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQUnt1NInterrupt_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUnt1NInterrupt::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQUnt1NInterrupt::loadRecByQref(
			ubigint qref
			, WdbeQUnt1NInterrupt** rec
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

	return loadRecByStmt("TblWdbeQUnt1NInterrupt_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQUnt1NInterrupt::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUnt1NInterrupt& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQUnt1NInterrupt_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
