/**
	* \file WdbeQMtpMdl1NPort.cpp
	* Dbs and XML wrapper for table TblWdbeQMtpMdl1NPort (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQMtpMdl1NPort.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMtpMdl1NPort
 ******************************************************************************/

WdbeQMtpMdl1NPort::WdbeQMtpMdl1NPort(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint mdlNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->mdlNum = mdlNum;
};

void WdbeQMtpMdl1NPort::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQMtpMdl1NPort";

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
 class ListWdbeQMtpMdl1NPort
 ******************************************************************************/

ListWdbeQMtpMdl1NPort::ListWdbeQMtpMdl1NPort() {
};

ListWdbeQMtpMdl1NPort::ListWdbeQMtpMdl1NPort(
			const ListWdbeQMtpMdl1NPort& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpMdl1NPort(*(src.nodes[i]));
};

ListWdbeQMtpMdl1NPort::~ListWdbeQMtpMdl1NPort() {
	clear();
};

void ListWdbeQMtpMdl1NPort::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQMtpMdl1NPort::size() const {
	return(nodes.size());
};

void ListWdbeQMtpMdl1NPort::append(
			WdbeQMtpMdl1NPort* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQMtpMdl1NPort& ListWdbeQMtpMdl1NPort::operator=(
			const ListWdbeQMtpMdl1NPort& src
		) {
	WdbeQMtpMdl1NPort* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQMtpMdl1NPort(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQMtpMdl1NPort::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQMtpMdl1NPort";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQMtpMdl1NPort
 ******************************************************************************/

TblWdbeQMtpMdl1NPort::TblWdbeQMtpMdl1NPort() {
};

TblWdbeQMtpMdl1NPort::~TblWdbeQMtpMdl1NPort() {
};

bool TblWdbeQMtpMdl1NPort::loadRecBySQL(
			const string& sqlstr
			, WdbeQMtpMdl1NPort** rec
		) {
	return false;
};

ubigint TblWdbeQMtpMdl1NPort::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMtpMdl1NPort& rst
		) {
	return 0;
};

ubigint TblWdbeQMtpMdl1NPort::insertRec(
			WdbeQMtpMdl1NPort* rec
		) {
	return 0;
};

ubigint TblWdbeQMtpMdl1NPort::insertNewRec(
			WdbeQMtpMdl1NPort** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint mdlNum
		) {
	ubigint retval = 0;
	WdbeQMtpMdl1NPort* _rec = NULL;

	_rec = new WdbeQMtpMdl1NPort(0, jref, jnum, ref, stubRef, mdlNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQMtpMdl1NPort::appendNewRecToRst(
			ListWdbeQMtpMdl1NPort& rst
			, WdbeQMtpMdl1NPort** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint mdlNum
		) {
	ubigint retval = 0;
	WdbeQMtpMdl1NPort* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, mdlNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQMtpMdl1NPort::insertRst(
			ListWdbeQMtpMdl1NPort& rst
		) {
};

void TblWdbeQMtpMdl1NPort::updateRec(
			WdbeQMtpMdl1NPort* rec
		) {
};

void TblWdbeQMtpMdl1NPort::updateRst(
			ListWdbeQMtpMdl1NPort& rst
		) {
};

void TblWdbeQMtpMdl1NPort::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQMtpMdl1NPort::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQMtpMdl1NPort::loadRecByQref(
			ubigint qref
			, WdbeQMtpMdl1NPort** rec
		) {
	return false;
};

ubigint TblWdbeQMtpMdl1NPort::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMtpMdl1NPort& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQMtpMdl1NPort
 ******************************************************************************/

MyTblWdbeQMtpMdl1NPort::MyTblWdbeQMtpMdl1NPort() :
			TblWdbeQMtpMdl1NPort()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQMtpMdl1NPort::~MyTblWdbeQMtpMdl1NPort() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQMtpMdl1NPort::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQMtpMdl1NPort (jref, jnum, ref, mdlNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQMtpMdl1NPort SET jref = ?, jnum = ?, ref = ?, mdlNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQMtpMdl1NPort WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQMtpMdl1NPort WHERE jref = ?", false);
};

bool MyTblWdbeQMtpMdl1NPort::loadRecBySQL(
			const string& sqlstr
			, WdbeQMtpMdl1NPort** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQMtpMdl1NPort* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQMtpMdl1NPort();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->mdlNum = atol((char*) dbrow[4]); else _rec->mdlNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQMtpMdl1NPort::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMtpMdl1NPort& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQMtpMdl1NPort* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQMtpMdl1NPort();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->mdlNum = atol((char*) dbrow[4]); else rec->mdlNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQMtpMdl1NPort::insertRec(
			WdbeQMtpMdl1NPort* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->mdlNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQMtpMdl1NPort::insertRst(
			ListWdbeQMtpMdl1NPort& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQMtpMdl1NPort::updateRec(
			WdbeQMtpMdl1NPort* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->mdlNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQMtpMdl1NPort::updateRst(
			ListWdbeQMtpMdl1NPort& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQMtpMdl1NPort::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQMtpMdl1NPort::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQMtpMdl1NPort::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQMtpMdl1NPort::loadRecByQref(
			ubigint qref
			, WdbeQMtpMdl1NPort** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQMtpMdl1NPort WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQMtpMdl1NPort::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMtpMdl1NPort& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQMtpMdl1NPort WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQMtpMdl1NPort
 ******************************************************************************/

PgTblWdbeQMtpMdl1NPort::PgTblWdbeQMtpMdl1NPort() :
			TblWdbeQMtpMdl1NPort()
			, PgTable()
		{
};

PgTblWdbeQMtpMdl1NPort::~PgTblWdbeQMtpMdl1NPort() {
};

void PgTblWdbeQMtpMdl1NPort::initStatements() {
	createStatement("TblWdbeQMtpMdl1NPort_insertRec", "INSERT INTO TblWdbeQMtpMdl1NPort (jref, jnum, ref, mdlNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWdbeQMtpMdl1NPort_updateRec", "UPDATE TblWdbeQMtpMdl1NPort SET jref = $1, jnum = $2, ref = $3, mdlNum = $4 WHERE qref = $5", 5);
	createStatement("TblWdbeQMtpMdl1NPort_removeRecByQref", "DELETE FROM TblWdbeQMtpMdl1NPort WHERE qref = $1", 1);
	createStatement("TblWdbeQMtpMdl1NPort_removeRstByJref", "DELETE FROM TblWdbeQMtpMdl1NPort WHERE jref = $1", 1);

	createStatement("TblWdbeQMtpMdl1NPort_loadRecByQref", "SELECT qref, jref, jnum, ref, mdlNum FROM TblWdbeQMtpMdl1NPort WHERE qref = $1", 1);
	createStatement("TblWdbeQMtpMdl1NPort_loadRstByJref", "SELECT qref, jref, jnum, ref, mdlNum FROM TblWdbeQMtpMdl1NPort WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQMtpMdl1NPort::loadRec(
			PGresult* res
			, WdbeQMtpMdl1NPort** rec
		) {
	char* ptr;

	WdbeQMtpMdl1NPort* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQMtpMdl1NPort();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "mdlnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->mdlNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQMtpMdl1NPort::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQMtpMdl1NPort& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQMtpMdl1NPort* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "mdlnum")
		};

		while (numread < numrow) {
			rec = new WdbeQMtpMdl1NPort();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->mdlNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQMtpMdl1NPort::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQMtpMdl1NPort** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMtpMdl1NPort::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQMtpMdl1NPort::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQMtpMdl1NPort& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMtpMdl1NPort::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQMtpMdl1NPort::loadRecBySQL(
			const string& sqlstr
			, WdbeQMtpMdl1NPort** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQMtpMdl1NPort::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQMtpMdl1NPort::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMtpMdl1NPort& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQMtpMdl1NPort::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQMtpMdl1NPort::insertRec(
			WdbeQMtpMdl1NPort* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _mdlNum = htonl(rec->mdlNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_mdlNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQMtpMdl1NPort_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMtpMdl1NPort::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQMtpMdl1NPort::insertRst(
			ListWdbeQMtpMdl1NPort& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQMtpMdl1NPort::updateRec(
			WdbeQMtpMdl1NPort* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _mdlNum = htonl(rec->mdlNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_mdlNum,
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

	res = PQexecPrepared(dbs, "TblWdbeQMtpMdl1NPort_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMtpMdl1NPort::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQMtpMdl1NPort::updateRst(
			ListWdbeQMtpMdl1NPort& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQMtpMdl1NPort::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQMtpMdl1NPort_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMtpMdl1NPort::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQMtpMdl1NPort::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQMtpMdl1NPort_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMtpMdl1NPort::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQMtpMdl1NPort::loadRecByQref(
			ubigint qref
			, WdbeQMtpMdl1NPort** rec
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

	return loadRecByStmt("TblWdbeQMtpMdl1NPort_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQMtpMdl1NPort::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMtpMdl1NPort& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQMtpMdl1NPort_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
