/**
	* \file WdbeQUnt1NPeripheral.cpp
	* Dbs and XML wrapper for table TblWdbeQUnt1NPeripheral (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQUnt1NPeripheral.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUnt1NPeripheral
 ******************************************************************************/

WdbeQUnt1NPeripheral::WdbeQUnt1NPeripheral(
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

void WdbeQUnt1NPeripheral::writeJSON(
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

void WdbeQUnt1NPeripheral::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQUnt1NPeripheral";

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
 class ListWdbeQUnt1NPeripheral
 ******************************************************************************/

ListWdbeQUnt1NPeripheral::ListWdbeQUnt1NPeripheral() {
};

ListWdbeQUnt1NPeripheral::ListWdbeQUnt1NPeripheral(
			const ListWdbeQUnt1NPeripheral& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUnt1NPeripheral(*(src.nodes[i]));
};

ListWdbeQUnt1NPeripheral::~ListWdbeQUnt1NPeripheral() {
	clear();
};

void ListWdbeQUnt1NPeripheral::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQUnt1NPeripheral::size() const {
	return(nodes.size());
};

void ListWdbeQUnt1NPeripheral::append(
			WdbeQUnt1NPeripheral* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQUnt1NPeripheral& ListWdbeQUnt1NPeripheral::operator=(
			const ListWdbeQUnt1NPeripheral& src
		) {
	WdbeQUnt1NPeripheral* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQUnt1NPeripheral(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQUnt1NPeripheral::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQUnt1NPeripheral";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQUnt1NPeripheral::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQUnt1NPeripheral";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQUnt1NPeripheral
 ******************************************************************************/

TblWdbeQUnt1NPeripheral::TblWdbeQUnt1NPeripheral() {
};

TblWdbeQUnt1NPeripheral::~TblWdbeQUnt1NPeripheral() {
};

bool TblWdbeQUnt1NPeripheral::loadRecBySQL(
			const string& sqlstr
			, WdbeQUnt1NPeripheral** rec
		) {
	return false;
};

ubigint TblWdbeQUnt1NPeripheral::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUnt1NPeripheral& rst
		) {
	return 0;
};

ubigint TblWdbeQUnt1NPeripheral::insertRec(
			WdbeQUnt1NPeripheral* rec
		) {
	return 0;
};

ubigint TblWdbeQUnt1NPeripheral::insertNewRec(
			WdbeQUnt1NPeripheral** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQUnt1NPeripheral* _rec = NULL;

	_rec = new WdbeQUnt1NPeripheral(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQUnt1NPeripheral::appendNewRecToRst(
			ListWdbeQUnt1NPeripheral& rst
			, WdbeQUnt1NPeripheral** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQUnt1NPeripheral* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQUnt1NPeripheral::insertRst(
			ListWdbeQUnt1NPeripheral& rst
		) {
};

void TblWdbeQUnt1NPeripheral::updateRec(
			WdbeQUnt1NPeripheral* rec
		) {
};

void TblWdbeQUnt1NPeripheral::updateRst(
			ListWdbeQUnt1NPeripheral& rst
		) {
};

void TblWdbeQUnt1NPeripheral::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQUnt1NPeripheral::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQUnt1NPeripheral::loadRecByQref(
			ubigint qref
			, WdbeQUnt1NPeripheral** rec
		) {
	return false;
};

ubigint TblWdbeQUnt1NPeripheral::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUnt1NPeripheral& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQUnt1NPeripheral
 ******************************************************************************/

MyTblWdbeQUnt1NPeripheral::MyTblWdbeQUnt1NPeripheral() :
			TblWdbeQUnt1NPeripheral()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQUnt1NPeripheral::~MyTblWdbeQUnt1NPeripheral() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQUnt1NPeripheral::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQUnt1NPeripheral (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQUnt1NPeripheral SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQUnt1NPeripheral WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQUnt1NPeripheral WHERE jref = ?", false);
};

bool MyTblWdbeQUnt1NPeripheral::loadRecBySQL(
			const string& sqlstr
			, WdbeQUnt1NPeripheral** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQUnt1NPeripheral* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQUnt1NPeripheral();

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

ubigint MyTblWdbeQUnt1NPeripheral::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUnt1NPeripheral& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQUnt1NPeripheral* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQUnt1NPeripheral();

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

ubigint MyTblWdbeQUnt1NPeripheral::insertRec(
			WdbeQUnt1NPeripheral* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQUnt1NPeripheral::insertRst(
			ListWdbeQUnt1NPeripheral& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQUnt1NPeripheral::updateRec(
			WdbeQUnt1NPeripheral* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQUnt1NPeripheral::updateRst(
			ListWdbeQUnt1NPeripheral& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQUnt1NPeripheral::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQUnt1NPeripheral::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQUnt1NPeripheral::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQUnt1NPeripheral::loadRecByQref(
			ubigint qref
			, WdbeQUnt1NPeripheral** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQUnt1NPeripheral WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQUnt1NPeripheral::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUnt1NPeripheral& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQUnt1NPeripheral WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQUnt1NPeripheral
 ******************************************************************************/

PgTblWdbeQUnt1NPeripheral::PgTblWdbeQUnt1NPeripheral() :
			TblWdbeQUnt1NPeripheral()
			, PgTable()
		{
};

PgTblWdbeQUnt1NPeripheral::~PgTblWdbeQUnt1NPeripheral() {
};

void PgTblWdbeQUnt1NPeripheral::initStatements() {
	createStatement("TblWdbeQUnt1NPeripheral_insertRec", "INSERT INTO TblWdbeQUnt1NPeripheral (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWdbeQUnt1NPeripheral_updateRec", "UPDATE TblWdbeQUnt1NPeripheral SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWdbeQUnt1NPeripheral_removeRecByQref", "DELETE FROM TblWdbeQUnt1NPeripheral WHERE qref = $1", 1);
	createStatement("TblWdbeQUnt1NPeripheral_removeRstByJref", "DELETE FROM TblWdbeQUnt1NPeripheral WHERE jref = $1", 1);

	createStatement("TblWdbeQUnt1NPeripheral_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWdbeQUnt1NPeripheral WHERE qref = $1", 1);
	createStatement("TblWdbeQUnt1NPeripheral_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWdbeQUnt1NPeripheral WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQUnt1NPeripheral::loadRec(
			PGresult* res
			, WdbeQUnt1NPeripheral** rec
		) {
	char* ptr;

	WdbeQUnt1NPeripheral* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQUnt1NPeripheral();

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

ubigint PgTblWdbeQUnt1NPeripheral::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQUnt1NPeripheral& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQUnt1NPeripheral* rec;

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
			rec = new WdbeQUnt1NPeripheral();

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

bool PgTblWdbeQUnt1NPeripheral::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQUnt1NPeripheral** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUnt1NPeripheral::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQUnt1NPeripheral::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQUnt1NPeripheral& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUnt1NPeripheral::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQUnt1NPeripheral::loadRecBySQL(
			const string& sqlstr
			, WdbeQUnt1NPeripheral** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQUnt1NPeripheral::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQUnt1NPeripheral::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUnt1NPeripheral& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQUnt1NPeripheral::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQUnt1NPeripheral::insertRec(
			WdbeQUnt1NPeripheral* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQUnt1NPeripheral_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUnt1NPeripheral::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQUnt1NPeripheral::insertRst(
			ListWdbeQUnt1NPeripheral& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQUnt1NPeripheral::updateRec(
			WdbeQUnt1NPeripheral* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQUnt1NPeripheral_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUnt1NPeripheral::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQUnt1NPeripheral::updateRst(
			ListWdbeQUnt1NPeripheral& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQUnt1NPeripheral::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQUnt1NPeripheral_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUnt1NPeripheral::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQUnt1NPeripheral::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQUnt1NPeripheral_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUnt1NPeripheral::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQUnt1NPeripheral::loadRecByQref(
			ubigint qref
			, WdbeQUnt1NPeripheral** rec
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

	return loadRecByStmt("TblWdbeQUnt1NPeripheral_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQUnt1NPeripheral::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUnt1NPeripheral& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQUnt1NPeripheral_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
