/**
	* \file WdbeQSegSup1NSegment.cpp
	* Dbs and XML wrapper for table TblWdbeQSegSup1NSegment (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQSegSup1NSegment.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSegSup1NSegment
 ******************************************************************************/

WdbeQSegSup1NSegment::WdbeQSegSup1NSegment(
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

void WdbeQSegSup1NSegment::writeJSON(
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

void WdbeQSegSup1NSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQSegSup1NSegment";

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
 class ListWdbeQSegSup1NSegment
 ******************************************************************************/

ListWdbeQSegSup1NSegment::ListWdbeQSegSup1NSegment() {
};

ListWdbeQSegSup1NSegment::ListWdbeQSegSup1NSegment(
			const ListWdbeQSegSup1NSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSegSup1NSegment(*(src.nodes[i]));
};

ListWdbeQSegSup1NSegment::~ListWdbeQSegSup1NSegment() {
	clear();
};

void ListWdbeQSegSup1NSegment::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQSegSup1NSegment::size() const {
	return(nodes.size());
};

void ListWdbeQSegSup1NSegment::append(
			WdbeQSegSup1NSegment* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQSegSup1NSegment& ListWdbeQSegSup1NSegment::operator=(
			const ListWdbeQSegSup1NSegment& src
		) {
	WdbeQSegSup1NSegment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQSegSup1NSegment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQSegSup1NSegment::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQSegSup1NSegment";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQSegSup1NSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQSegSup1NSegment";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQSegSup1NSegment
 ******************************************************************************/

TblWdbeQSegSup1NSegment::TblWdbeQSegSup1NSegment() {
};

TblWdbeQSegSup1NSegment::~TblWdbeQSegSup1NSegment() {
};

bool TblWdbeQSegSup1NSegment::loadRecBySQL(
			const string& sqlstr
			, WdbeQSegSup1NSegment** rec
		) {
	return false;
};

ubigint TblWdbeQSegSup1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSegSup1NSegment& rst
		) {
	return 0;
};

ubigint TblWdbeQSegSup1NSegment::insertRec(
			WdbeQSegSup1NSegment* rec
		) {
	return 0;
};

ubigint TblWdbeQSegSup1NSegment::insertNewRec(
			WdbeQSegSup1NSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQSegSup1NSegment* _rec = NULL;

	_rec = new WdbeQSegSup1NSegment(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQSegSup1NSegment::appendNewRecToRst(
			ListWdbeQSegSup1NSegment& rst
			, WdbeQSegSup1NSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQSegSup1NSegment* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQSegSup1NSegment::insertRst(
			ListWdbeQSegSup1NSegment& rst
		) {
};

void TblWdbeQSegSup1NSegment::updateRec(
			WdbeQSegSup1NSegment* rec
		) {
};

void TblWdbeQSegSup1NSegment::updateRst(
			ListWdbeQSegSup1NSegment& rst
		) {
};

void TblWdbeQSegSup1NSegment::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQSegSup1NSegment::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQSegSup1NSegment::loadRecByQref(
			ubigint qref
			, WdbeQSegSup1NSegment** rec
		) {
	return false;
};

ubigint TblWdbeQSegSup1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSegSup1NSegment& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQSegSup1NSegment
 ******************************************************************************/

MyTblWdbeQSegSup1NSegment::MyTblWdbeQSegSup1NSegment() :
			TblWdbeQSegSup1NSegment()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQSegSup1NSegment::~MyTblWdbeQSegSup1NSegment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQSegSup1NSegment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQSegSup1NSegment (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQSegSup1NSegment SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQSegSup1NSegment WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQSegSup1NSegment WHERE jref = ?", false);
};

bool MyTblWdbeQSegSup1NSegment::loadRecBySQL(
			const string& sqlstr
			, WdbeQSegSup1NSegment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQSegSup1NSegment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSegSup1NSegment::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSegSup1NSegment::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQSegSup1NSegment();

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

ubigint MyTblWdbeQSegSup1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSegSup1NSegment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQSegSup1NSegment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSegSup1NSegment::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSegSup1NSegment::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQSegSup1NSegment();

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

ubigint MyTblWdbeQSegSup1NSegment::insertRec(
			WdbeQSegSup1NSegment* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQSegSup1NSegment::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQSegSup1NSegment::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQSegSup1NSegment::insertRst(
			ListWdbeQSegSup1NSegment& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQSegSup1NSegment::updateRec(
			WdbeQSegSup1NSegment* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQSegSup1NSegment::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQSegSup1NSegment::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSegSup1NSegment::updateRst(
			ListWdbeQSegSup1NSegment& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQSegSup1NSegment::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQSegSup1NSegment::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQSegSup1NSegment::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSegSup1NSegment::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQSegSup1NSegment::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQSegSup1NSegment::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQSegSup1NSegment::loadRecByQref(
			ubigint qref
			, WdbeQSegSup1NSegment** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQSegSup1NSegment WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQSegSup1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSegSup1NSegment& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQSegSup1NSegment WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQSegSup1NSegment
 ******************************************************************************/

PgTblWdbeQSegSup1NSegment::PgTblWdbeQSegSup1NSegment() :
			TblWdbeQSegSup1NSegment()
			, PgTable()
		{
};

PgTblWdbeQSegSup1NSegment::~PgTblWdbeQSegSup1NSegment() {
};

void PgTblWdbeQSegSup1NSegment::initStatements() {
	createStatement("TblWdbeQSegSup1NSegment_insertRec", "INSERT INTO TblWdbeQSegSup1NSegment (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWdbeQSegSup1NSegment_updateRec", "UPDATE TblWdbeQSegSup1NSegment SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWdbeQSegSup1NSegment_removeRecByQref", "DELETE FROM TblWdbeQSegSup1NSegment WHERE qref = $1", 1);
	createStatement("TblWdbeQSegSup1NSegment_removeRstByJref", "DELETE FROM TblWdbeQSegSup1NSegment WHERE jref = $1", 1);

	createStatement("TblWdbeQSegSup1NSegment_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWdbeQSegSup1NSegment WHERE qref = $1", 1);
	createStatement("TblWdbeQSegSup1NSegment_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWdbeQSegSup1NSegment WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQSegSup1NSegment::loadRec(
			PGresult* res
			, WdbeQSegSup1NSegment** rec
		) {
	char* ptr;

	WdbeQSegSup1NSegment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQSegSup1NSegment();

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

ubigint PgTblWdbeQSegSup1NSegment::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQSegSup1NSegment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQSegSup1NSegment* rec;

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
			rec = new WdbeQSegSup1NSegment();

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

bool PgTblWdbeQSegSup1NSegment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQSegSup1NSegment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSegSup1NSegment::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSegSup1NSegment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQSegSup1NSegment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSegSup1NSegment::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQSegSup1NSegment::loadRecBySQL(
			const string& sqlstr
			, WdbeQSegSup1NSegment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSegSup1NSegment::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSegSup1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSegSup1NSegment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSegSup1NSegment::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQSegSup1NSegment::insertRec(
			WdbeQSegSup1NSegment* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQSegSup1NSegment_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSegSup1NSegment::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQSegSup1NSegment::insertRst(
			ListWdbeQSegSup1NSegment& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQSegSup1NSegment::updateRec(
			WdbeQSegSup1NSegment* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQSegSup1NSegment_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSegSup1NSegment::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSegSup1NSegment::updateRst(
			ListWdbeQSegSup1NSegment& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQSegSup1NSegment::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSegSup1NSegment_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSegSup1NSegment::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSegSup1NSegment::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSegSup1NSegment_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSegSup1NSegment::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQSegSup1NSegment::loadRecByQref(
			ubigint qref
			, WdbeQSegSup1NSegment** rec
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

	return loadRecByStmt("TblWdbeQSegSup1NSegment_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQSegSup1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSegSup1NSegment& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQSegSup1NSegment_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
