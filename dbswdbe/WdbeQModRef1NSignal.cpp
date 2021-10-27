/**
	* \file WdbeQModRef1NSignal.cpp
	* Dbs and XML wrapper for table TblWdbeQModRef1NSignal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Sep 2021
  */
// IP header --- ABOVE

#include "WdbeQModRef1NSignal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModRef1NSignal
 ******************************************************************************/

WdbeQModRef1NSignal::WdbeQModRef1NSignal(
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

void WdbeQModRef1NSignal::writeJSON(
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

void WdbeQModRef1NSignal::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQModRef1NSignal";

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
 class ListWdbeQModRef1NSignal
 ******************************************************************************/

ListWdbeQModRef1NSignal::ListWdbeQModRef1NSignal() {
};

ListWdbeQModRef1NSignal::ListWdbeQModRef1NSignal(
			const ListWdbeQModRef1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModRef1NSignal(*(src.nodes[i]));
};

ListWdbeQModRef1NSignal::~ListWdbeQModRef1NSignal() {
	clear();
};

void ListWdbeQModRef1NSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQModRef1NSignal::size() const {
	return(nodes.size());
};

void ListWdbeQModRef1NSignal::append(
			WdbeQModRef1NSignal* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQModRef1NSignal& ListWdbeQModRef1NSignal::operator=(
			const ListWdbeQModRef1NSignal& src
		) {
	WdbeQModRef1NSignal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQModRef1NSignal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQModRef1NSignal::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQModRef1NSignal";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQModRef1NSignal::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQModRef1NSignal";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQModRef1NSignal
 ******************************************************************************/

TblWdbeQModRef1NSignal::TblWdbeQModRef1NSignal() {
};

TblWdbeQModRef1NSignal::~TblWdbeQModRef1NSignal() {
};

bool TblWdbeQModRef1NSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeQModRef1NSignal** rec
		) {
	return false;
};

ubigint TblWdbeQModRef1NSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModRef1NSignal& rst
		) {
	return 0;
};

ubigint TblWdbeQModRef1NSignal::insertRec(
			WdbeQModRef1NSignal* rec
		) {
	return 0;
};

ubigint TblWdbeQModRef1NSignal::insertNewRec(
			WdbeQModRef1NSignal** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint refNum
		) {
	ubigint retval = 0;
	WdbeQModRef1NSignal* _rec = NULL;

	_rec = new WdbeQModRef1NSignal(0, jref, jnum, ref, stubRef, refNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQModRef1NSignal::appendNewRecToRst(
			ListWdbeQModRef1NSignal& rst
			, WdbeQModRef1NSignal** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint refNum
		) {
	ubigint retval = 0;
	WdbeQModRef1NSignal* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, refNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQModRef1NSignal::insertRst(
			ListWdbeQModRef1NSignal& rst
		) {
};

void TblWdbeQModRef1NSignal::updateRec(
			WdbeQModRef1NSignal* rec
		) {
};

void TblWdbeQModRef1NSignal::updateRst(
			ListWdbeQModRef1NSignal& rst
		) {
};

void TblWdbeQModRef1NSignal::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQModRef1NSignal::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQModRef1NSignal::loadRecByQref(
			ubigint qref
			, WdbeQModRef1NSignal** rec
		) {
	return false;
};

ubigint TblWdbeQModRef1NSignal::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModRef1NSignal& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQModRef1NSignal
 ******************************************************************************/

MyTblWdbeQModRef1NSignal::MyTblWdbeQModRef1NSignal() :
			TblWdbeQModRef1NSignal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQModRef1NSignal::~MyTblWdbeQModRef1NSignal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQModRef1NSignal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQModRef1NSignal (jref, jnum, ref, refNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQModRef1NSignal SET jref = ?, jnum = ?, ref = ?, refNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQModRef1NSignal WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQModRef1NSignal WHERE jref = ?", false);
};

bool MyTblWdbeQModRef1NSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeQModRef1NSignal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQModRef1NSignal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModRef1NSignal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModRef1NSignal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQModRef1NSignal();

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

ubigint MyTblWdbeQModRef1NSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModRef1NSignal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQModRef1NSignal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModRef1NSignal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModRef1NSignal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQModRef1NSignal();

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

ubigint MyTblWdbeQModRef1NSignal::insertRec(
			WdbeQModRef1NSignal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQModRef1NSignal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQModRef1NSignal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQModRef1NSignal::insertRst(
			ListWdbeQModRef1NSignal& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQModRef1NSignal::updateRec(
			WdbeQModRef1NSignal* rec
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
		string dbms = "MyTblWdbeQModRef1NSignal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQModRef1NSignal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModRef1NSignal::updateRst(
			ListWdbeQModRef1NSignal& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQModRef1NSignal::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQModRef1NSignal::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQModRef1NSignal::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModRef1NSignal::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQModRef1NSignal::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQModRef1NSignal::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQModRef1NSignal::loadRecByQref(
			ubigint qref
			, WdbeQModRef1NSignal** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQModRef1NSignal WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQModRef1NSignal::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModRef1NSignal& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQModRef1NSignal WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQModRef1NSignal
 ******************************************************************************/

PgTblWdbeQModRef1NSignal::PgTblWdbeQModRef1NSignal() :
			TblWdbeQModRef1NSignal()
			, PgTable()
		{
};

PgTblWdbeQModRef1NSignal::~PgTblWdbeQModRef1NSignal() {
};

void PgTblWdbeQModRef1NSignal::initStatements() {
	createStatement("TblWdbeQModRef1NSignal_insertRec", "INSERT INTO TblWdbeQModRef1NSignal (jref, jnum, ref, refNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWdbeQModRef1NSignal_updateRec", "UPDATE TblWdbeQModRef1NSignal SET jref = $1, jnum = $2, ref = $3, refNum = $4 WHERE qref = $5", 5);
	createStatement("TblWdbeQModRef1NSignal_removeRecByQref", "DELETE FROM TblWdbeQModRef1NSignal WHERE qref = $1", 1);
	createStatement("TblWdbeQModRef1NSignal_removeRstByJref", "DELETE FROM TblWdbeQModRef1NSignal WHERE jref = $1", 1);

	createStatement("TblWdbeQModRef1NSignal_loadRecByQref", "SELECT qref, jref, jnum, ref, refNum FROM TblWdbeQModRef1NSignal WHERE qref = $1", 1);
	createStatement("TblWdbeQModRef1NSignal_loadRstByJref", "SELECT qref, jref, jnum, ref, refNum FROM TblWdbeQModRef1NSignal WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQModRef1NSignal::loadRec(
			PGresult* res
			, WdbeQModRef1NSignal** rec
		) {
	char* ptr;

	WdbeQModRef1NSignal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQModRef1NSignal();

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

ubigint PgTblWdbeQModRef1NSignal::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQModRef1NSignal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQModRef1NSignal* rec;

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
			rec = new WdbeQModRef1NSignal();

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

bool PgTblWdbeQModRef1NSignal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQModRef1NSignal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModRef1NSignal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModRef1NSignal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQModRef1NSignal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModRef1NSignal::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQModRef1NSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeQModRef1NSignal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModRef1NSignal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModRef1NSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModRef1NSignal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModRef1NSignal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQModRef1NSignal::insertRec(
			WdbeQModRef1NSignal* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQModRef1NSignal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModRef1NSignal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQModRef1NSignal::insertRst(
			ListWdbeQModRef1NSignal& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQModRef1NSignal::updateRec(
			WdbeQModRef1NSignal* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQModRef1NSignal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModRef1NSignal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModRef1NSignal::updateRst(
			ListWdbeQModRef1NSignal& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQModRef1NSignal::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModRef1NSignal_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModRef1NSignal::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModRef1NSignal::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModRef1NSignal_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModRef1NSignal::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQModRef1NSignal::loadRecByQref(
			ubigint qref
			, WdbeQModRef1NSignal** rec
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

	return loadRecByStmt("TblWdbeQModRef1NSignal_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQModRef1NSignal::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModRef1NSignal& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQModRef1NSignal_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
