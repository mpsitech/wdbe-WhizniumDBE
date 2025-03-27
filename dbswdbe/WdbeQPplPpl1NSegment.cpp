/**
	* \file WdbeQPplPpl1NSegment.cpp
	* Dbs and XML wrapper for table TblWdbeQPplPpl1NSegment (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQPplPpl1NSegment.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPplPpl1NSegment
 ******************************************************************************/

WdbeQPplPpl1NSegment::WdbeQPplPpl1NSegment(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint pplNum
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, stubRef(stubRef)
			, pplNum(pplNum)
		{
};

void WdbeQPplPpl1NSegment::writeJSON(
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

void WdbeQPplPpl1NSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQPplPpl1NSegment";

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
 class ListWdbeQPplPpl1NSegment
 ******************************************************************************/

ListWdbeQPplPpl1NSegment::ListWdbeQPplPpl1NSegment() {
};

ListWdbeQPplPpl1NSegment::ListWdbeQPplPpl1NSegment(
			const ListWdbeQPplPpl1NSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPplPpl1NSegment(*(src.nodes[i]));
};

ListWdbeQPplPpl1NSegment::~ListWdbeQPplPpl1NSegment() {
	clear();
};

void ListWdbeQPplPpl1NSegment::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQPplPpl1NSegment::size() const {
	return(nodes.size());
};

void ListWdbeQPplPpl1NSegment::append(
			WdbeQPplPpl1NSegment* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQPplPpl1NSegment& ListWdbeQPplPpl1NSegment::operator=(
			const ListWdbeQPplPpl1NSegment& src
		) {
	WdbeQPplPpl1NSegment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQPplPpl1NSegment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQPplPpl1NSegment::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQPplPpl1NSegment";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQPplPpl1NSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQPplPpl1NSegment";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQPplPpl1NSegment
 ******************************************************************************/

TblWdbeQPplPpl1NSegment::TblWdbeQPplPpl1NSegment() {
};

TblWdbeQPplPpl1NSegment::~TblWdbeQPplPpl1NSegment() {
};

bool TblWdbeQPplPpl1NSegment::loadRecBySQL(
			const string& sqlstr
			, WdbeQPplPpl1NSegment** rec
		) {
	return false;
};

ubigint TblWdbeQPplPpl1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPplPpl1NSegment& rst
		) {
	return 0;
};

ubigint TblWdbeQPplPpl1NSegment::insertRec(
			WdbeQPplPpl1NSegment* rec
		) {
	return 0;
};

ubigint TblWdbeQPplPpl1NSegment::insertNewRec(
			WdbeQPplPpl1NSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint pplNum
		) {
	ubigint retval = 0;
	WdbeQPplPpl1NSegment* _rec = NULL;

	_rec = new WdbeQPplPpl1NSegment(0, jref, jnum, ref, stubRef, pplNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQPplPpl1NSegment::appendNewRecToRst(
			ListWdbeQPplPpl1NSegment& rst
			, WdbeQPplPpl1NSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint pplNum
		) {
	ubigint retval = 0;
	WdbeQPplPpl1NSegment* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, pplNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQPplPpl1NSegment::insertRst(
			ListWdbeQPplPpl1NSegment& rst
		) {
};

void TblWdbeQPplPpl1NSegment::updateRec(
			WdbeQPplPpl1NSegment* rec
		) {
};

void TblWdbeQPplPpl1NSegment::updateRst(
			ListWdbeQPplPpl1NSegment& rst
		) {
};

void TblWdbeQPplPpl1NSegment::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQPplPpl1NSegment::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQPplPpl1NSegment::loadRecByQref(
			ubigint qref
			, WdbeQPplPpl1NSegment** rec
		) {
	return false;
};

ubigint TblWdbeQPplPpl1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPplPpl1NSegment& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQPplPpl1NSegment
 ******************************************************************************/

MyTblWdbeQPplPpl1NSegment::MyTblWdbeQPplPpl1NSegment() :
			TblWdbeQPplPpl1NSegment()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQPplPpl1NSegment::~MyTblWdbeQPplPpl1NSegment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQPplPpl1NSegment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQPplPpl1NSegment (jref, jnum, ref, pplNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQPplPpl1NSegment SET jref = ?, jnum = ?, ref = ?, pplNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQPplPpl1NSegment WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQPplPpl1NSegment WHERE jref = ?", false);
};

bool MyTblWdbeQPplPpl1NSegment::loadRecBySQL(
			const string& sqlstr
			, WdbeQPplPpl1NSegment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQPplPpl1NSegment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQPplPpl1NSegment();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->pplNum = atol((char*) dbrow[4]); else _rec->pplNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQPplPpl1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPplPpl1NSegment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQPplPpl1NSegment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQPplPpl1NSegment();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->pplNum = atol((char*) dbrow[4]); else rec->pplNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQPplPpl1NSegment::insertRec(
			WdbeQPplPpl1NSegment* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->pplNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQPplPpl1NSegment::insertRst(
			ListWdbeQPplPpl1NSegment& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQPplPpl1NSegment::updateRec(
			WdbeQPplPpl1NSegment* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->pplNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPplPpl1NSegment::updateRst(
			ListWdbeQPplPpl1NSegment& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQPplPpl1NSegment::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPplPpl1NSegment::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQPplPpl1NSegment::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQPplPpl1NSegment::loadRecByQref(
			ubigint qref
			, WdbeQPplPpl1NSegment** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQPplPpl1NSegment WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQPplPpl1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPplPpl1NSegment& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQPplPpl1NSegment WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQPplPpl1NSegment
 ******************************************************************************/

PgTblWdbeQPplPpl1NSegment::PgTblWdbeQPplPpl1NSegment() :
			TblWdbeQPplPpl1NSegment()
			, PgTable()
		{
};

PgTblWdbeQPplPpl1NSegment::~PgTblWdbeQPplPpl1NSegment() {
};

void PgTblWdbeQPplPpl1NSegment::initStatements() {
	createStatement("TblWdbeQPplPpl1NSegment_insertRec", "INSERT INTO TblWdbeQPplPpl1NSegment (jref, jnum, ref, pplNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWdbeQPplPpl1NSegment_updateRec", "UPDATE TblWdbeQPplPpl1NSegment SET jref = $1, jnum = $2, ref = $3, pplNum = $4 WHERE qref = $5", 5);
	createStatement("TblWdbeQPplPpl1NSegment_removeRecByQref", "DELETE FROM TblWdbeQPplPpl1NSegment WHERE qref = $1", 1);
	createStatement("TblWdbeQPplPpl1NSegment_removeRstByJref", "DELETE FROM TblWdbeQPplPpl1NSegment WHERE jref = $1", 1);

	createStatement("TblWdbeQPplPpl1NSegment_loadRecByQref", "SELECT qref, jref, jnum, ref, pplNum FROM TblWdbeQPplPpl1NSegment WHERE qref = $1", 1);
	createStatement("TblWdbeQPplPpl1NSegment_loadRstByJref", "SELECT qref, jref, jnum, ref, pplNum FROM TblWdbeQPplPpl1NSegment WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQPplPpl1NSegment::loadRec(
			PGresult* res
			, WdbeQPplPpl1NSegment** rec
		) {
	char* ptr;

	WdbeQPplPpl1NSegment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQPplPpl1NSegment();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "pplnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->pplNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQPplPpl1NSegment::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQPplPpl1NSegment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQPplPpl1NSegment* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "pplnum")
		};

		while (numread < numrow) {
			rec = new WdbeQPplPpl1NSegment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->pplNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQPplPpl1NSegment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQPplPpl1NSegment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPplPpl1NSegment::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPplPpl1NSegment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQPplPpl1NSegment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPplPpl1NSegment::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQPplPpl1NSegment::loadRecBySQL(
			const string& sqlstr
			, WdbeQPplPpl1NSegment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPplPpl1NSegment::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPplPpl1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPplPpl1NSegment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPplPpl1NSegment::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQPplPpl1NSegment::insertRec(
			WdbeQPplPpl1NSegment* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _pplNum = htonl(rec->pplNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_pplNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQPplPpl1NSegment_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPplPpl1NSegment::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQPplPpl1NSegment::insertRst(
			ListWdbeQPplPpl1NSegment& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQPplPpl1NSegment::updateRec(
			WdbeQPplPpl1NSegment* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _pplNum = htonl(rec->pplNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_pplNum,
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

	res = PQexecPrepared(dbs, "TblWdbeQPplPpl1NSegment_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPplPpl1NSegment::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPplPpl1NSegment::updateRst(
			ListWdbeQPplPpl1NSegment& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQPplPpl1NSegment::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPplPpl1NSegment_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPplPpl1NSegment::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPplPpl1NSegment::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPplPpl1NSegment_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPplPpl1NSegment::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQPplPpl1NSegment::loadRecByQref(
			ubigint qref
			, WdbeQPplPpl1NSegment** rec
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

	return loadRecByStmt("TblWdbeQPplPpl1NSegment_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQPplPpl1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPplPpl1NSegment& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQPplPpl1NSegment_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
