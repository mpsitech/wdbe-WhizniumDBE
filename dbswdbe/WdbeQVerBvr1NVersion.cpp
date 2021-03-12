/**
	* \file WdbeQVerBvr1NVersion.cpp
	* Dbs and XML wrapper for table TblWdbeQVerBvr1NVersion (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQVerBvr1NVersion.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQVerBvr1NVersion
 ******************************************************************************/

WdbeQVerBvr1NVersion::WdbeQVerBvr1NVersion(
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

void WdbeQVerBvr1NVersion::writeJSON(
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

void WdbeQVerBvr1NVersion::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQVerBvr1NVersion";

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
 class ListWdbeQVerBvr1NVersion
 ******************************************************************************/

ListWdbeQVerBvr1NVersion::ListWdbeQVerBvr1NVersion() {
};

ListWdbeQVerBvr1NVersion::ListWdbeQVerBvr1NVersion(
			const ListWdbeQVerBvr1NVersion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQVerBvr1NVersion(*(src.nodes[i]));
};

ListWdbeQVerBvr1NVersion::~ListWdbeQVerBvr1NVersion() {
	clear();
};

void ListWdbeQVerBvr1NVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQVerBvr1NVersion::size() const {
	return(nodes.size());
};

void ListWdbeQVerBvr1NVersion::append(
			WdbeQVerBvr1NVersion* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQVerBvr1NVersion& ListWdbeQVerBvr1NVersion::operator=(
			const ListWdbeQVerBvr1NVersion& src
		) {
	WdbeQVerBvr1NVersion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQVerBvr1NVersion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQVerBvr1NVersion::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQVerBvr1NVersion";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQVerBvr1NVersion::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQVerBvr1NVersion";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQVerBvr1NVersion
 ******************************************************************************/

TblWdbeQVerBvr1NVersion::TblWdbeQVerBvr1NVersion() {
};

TblWdbeQVerBvr1NVersion::~TblWdbeQVerBvr1NVersion() {
};

bool TblWdbeQVerBvr1NVersion::loadRecBySQL(
			const string& sqlstr
			, WdbeQVerBvr1NVersion** rec
		) {
	return false;
};

ubigint TblWdbeQVerBvr1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQVerBvr1NVersion& rst
		) {
	return 0;
};

ubigint TblWdbeQVerBvr1NVersion::insertRec(
			WdbeQVerBvr1NVersion* rec
		) {
	return 0;
};

ubigint TblWdbeQVerBvr1NVersion::insertNewRec(
			WdbeQVerBvr1NVersion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQVerBvr1NVersion* _rec = NULL;

	_rec = new WdbeQVerBvr1NVersion(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQVerBvr1NVersion::appendNewRecToRst(
			ListWdbeQVerBvr1NVersion& rst
			, WdbeQVerBvr1NVersion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQVerBvr1NVersion* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQVerBvr1NVersion::insertRst(
			ListWdbeQVerBvr1NVersion& rst
		) {
};

void TblWdbeQVerBvr1NVersion::updateRec(
			WdbeQVerBvr1NVersion* rec
		) {
};

void TblWdbeQVerBvr1NVersion::updateRst(
			ListWdbeQVerBvr1NVersion& rst
		) {
};

void TblWdbeQVerBvr1NVersion::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQVerBvr1NVersion::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQVerBvr1NVersion::loadRecByQref(
			ubigint qref
			, WdbeQVerBvr1NVersion** rec
		) {
	return false;
};

ubigint TblWdbeQVerBvr1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQVerBvr1NVersion& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQVerBvr1NVersion
 ******************************************************************************/

MyTblWdbeQVerBvr1NVersion::MyTblWdbeQVerBvr1NVersion() :
			TblWdbeQVerBvr1NVersion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQVerBvr1NVersion::~MyTblWdbeQVerBvr1NVersion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQVerBvr1NVersion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQVerBvr1NVersion (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQVerBvr1NVersion SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQVerBvr1NVersion WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQVerBvr1NVersion WHERE jref = ?", false);
};

bool MyTblWdbeQVerBvr1NVersion::loadRecBySQL(
			const string& sqlstr
			, WdbeQVerBvr1NVersion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQVerBvr1NVersion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQVerBvr1NVersion();

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

ubigint MyTblWdbeQVerBvr1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQVerBvr1NVersion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQVerBvr1NVersion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQVerBvr1NVersion();

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

ubigint MyTblWdbeQVerBvr1NVersion::insertRec(
			WdbeQVerBvr1NVersion* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQVerBvr1NVersion::insertRst(
			ListWdbeQVerBvr1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQVerBvr1NVersion::updateRec(
			WdbeQVerBvr1NVersion* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQVerBvr1NVersion::updateRst(
			ListWdbeQVerBvr1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQVerBvr1NVersion::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQVerBvr1NVersion::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQVerBvr1NVersion::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQVerBvr1NVersion::loadRecByQref(
			ubigint qref
			, WdbeQVerBvr1NVersion** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQVerBvr1NVersion WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQVerBvr1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQVerBvr1NVersion& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQVerBvr1NVersion WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQVerBvr1NVersion
 ******************************************************************************/

PgTblWdbeQVerBvr1NVersion::PgTblWdbeQVerBvr1NVersion() :
			TblWdbeQVerBvr1NVersion()
			, PgTable()
		{
};

PgTblWdbeQVerBvr1NVersion::~PgTblWdbeQVerBvr1NVersion() {
};

void PgTblWdbeQVerBvr1NVersion::initStatements() {
	createStatement("TblWdbeQVerBvr1NVersion_insertRec", "INSERT INTO TblWdbeQVerBvr1NVersion (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWdbeQVerBvr1NVersion_updateRec", "UPDATE TblWdbeQVerBvr1NVersion SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWdbeQVerBvr1NVersion_removeRecByQref", "DELETE FROM TblWdbeQVerBvr1NVersion WHERE qref = $1", 1);
	createStatement("TblWdbeQVerBvr1NVersion_removeRstByJref", "DELETE FROM TblWdbeQVerBvr1NVersion WHERE jref = $1", 1);

	createStatement("TblWdbeQVerBvr1NVersion_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWdbeQVerBvr1NVersion WHERE qref = $1", 1);
	createStatement("TblWdbeQVerBvr1NVersion_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWdbeQVerBvr1NVersion WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQVerBvr1NVersion::loadRec(
			PGresult* res
			, WdbeQVerBvr1NVersion** rec
		) {
	char* ptr;

	WdbeQVerBvr1NVersion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQVerBvr1NVersion();

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

ubigint PgTblWdbeQVerBvr1NVersion::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQVerBvr1NVersion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQVerBvr1NVersion* rec;

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
			rec = new WdbeQVerBvr1NVersion();

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

bool PgTblWdbeQVerBvr1NVersion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQVerBvr1NVersion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQVerBvr1NVersion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQVerBvr1NVersion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQVerBvr1NVersion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQVerBvr1NVersion::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQVerBvr1NVersion::loadRecBySQL(
			const string& sqlstr
			, WdbeQVerBvr1NVersion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQVerBvr1NVersion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQVerBvr1NVersion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQVerBvr1NVersion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQVerBvr1NVersion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQVerBvr1NVersion::insertRec(
			WdbeQVerBvr1NVersion* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQVerBvr1NVersion_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQVerBvr1NVersion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQVerBvr1NVersion::insertRst(
			ListWdbeQVerBvr1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQVerBvr1NVersion::updateRec(
			WdbeQVerBvr1NVersion* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQVerBvr1NVersion_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQVerBvr1NVersion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQVerBvr1NVersion::updateRst(
			ListWdbeQVerBvr1NVersion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQVerBvr1NVersion::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQVerBvr1NVersion_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQVerBvr1NVersion::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQVerBvr1NVersion::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQVerBvr1NVersion_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQVerBvr1NVersion::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQVerBvr1NVersion::loadRecByQref(
			ubigint qref
			, WdbeQVerBvr1NVersion** rec
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

	return loadRecByStmt("TblWdbeQVerBvr1NVersion_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQVerBvr1NVersion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQVerBvr1NVersion& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQVerBvr1NVersion_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
