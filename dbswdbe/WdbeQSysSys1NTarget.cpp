/**
	* \file WdbeQSysSys1NTarget.cpp
	* Dbs and XML wrapper for table TblWdbeQSysSys1NTarget (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQSysSys1NTarget.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSysSys1NTarget
 ******************************************************************************/

WdbeQSysSys1NTarget::WdbeQSysSys1NTarget(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint sysNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->sysNum = sysNum;
};

void WdbeQSysSys1NTarget::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQSysSys1NTarget";

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
 class ListWdbeQSysSys1NTarget
 ******************************************************************************/

ListWdbeQSysSys1NTarget::ListWdbeQSysSys1NTarget() {
};

ListWdbeQSysSys1NTarget::ListWdbeQSysSys1NTarget(
			const ListWdbeQSysSys1NTarget& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSysSys1NTarget(*(src.nodes[i]));
};

ListWdbeQSysSys1NTarget::~ListWdbeQSysSys1NTarget() {
	clear();
};

void ListWdbeQSysSys1NTarget::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQSysSys1NTarget::size() const {
	return(nodes.size());
};

void ListWdbeQSysSys1NTarget::append(
			WdbeQSysSys1NTarget* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQSysSys1NTarget& ListWdbeQSysSys1NTarget::operator=(
			const ListWdbeQSysSys1NTarget& src
		) {
	WdbeQSysSys1NTarget* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQSysSys1NTarget(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQSysSys1NTarget::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQSysSys1NTarget";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQSysSys1NTarget
 ******************************************************************************/

TblWdbeQSysSys1NTarget::TblWdbeQSysSys1NTarget() {
};

TblWdbeQSysSys1NTarget::~TblWdbeQSysSys1NTarget() {
};

bool TblWdbeQSysSys1NTarget::loadRecBySQL(
			const string& sqlstr
			, WdbeQSysSys1NTarget** rec
		) {
	return false;
};

ubigint TblWdbeQSysSys1NTarget::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSysSys1NTarget& rst
		) {
	return 0;
};

ubigint TblWdbeQSysSys1NTarget::insertRec(
			WdbeQSysSys1NTarget* rec
		) {
	return 0;
};

ubigint TblWdbeQSysSys1NTarget::insertNewRec(
			WdbeQSysSys1NTarget** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint sysNum
		) {
	ubigint retval = 0;
	WdbeQSysSys1NTarget* _rec = NULL;

	_rec = new WdbeQSysSys1NTarget(0, jref, jnum, ref, stubRef, sysNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQSysSys1NTarget::appendNewRecToRst(
			ListWdbeQSysSys1NTarget& rst
			, WdbeQSysSys1NTarget** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint sysNum
		) {
	ubigint retval = 0;
	WdbeQSysSys1NTarget* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, sysNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQSysSys1NTarget::insertRst(
			ListWdbeQSysSys1NTarget& rst
		) {
};

void TblWdbeQSysSys1NTarget::updateRec(
			WdbeQSysSys1NTarget* rec
		) {
};

void TblWdbeQSysSys1NTarget::updateRst(
			ListWdbeQSysSys1NTarget& rst
		) {
};

void TblWdbeQSysSys1NTarget::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQSysSys1NTarget::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQSysSys1NTarget::loadRecByQref(
			ubigint qref
			, WdbeQSysSys1NTarget** rec
		) {
	return false;
};

ubigint TblWdbeQSysSys1NTarget::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSysSys1NTarget& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQSysSys1NTarget
 ******************************************************************************/

MyTblWdbeQSysSys1NTarget::MyTblWdbeQSysSys1NTarget() :
			TblWdbeQSysSys1NTarget()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQSysSys1NTarget::~MyTblWdbeQSysSys1NTarget() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQSysSys1NTarget::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQSysSys1NTarget (jref, jnum, ref, sysNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQSysSys1NTarget SET jref = ?, jnum = ?, ref = ?, sysNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQSysSys1NTarget WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQSysSys1NTarget WHERE jref = ?", false);
};

bool MyTblWdbeQSysSys1NTarget::loadRecBySQL(
			const string& sqlstr
			, WdbeQSysSys1NTarget** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQSysSys1NTarget* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSysSys1NTarget::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSysSys1NTarget::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQSysSys1NTarget();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sysNum = atol((char*) dbrow[4]); else _rec->sysNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQSysSys1NTarget::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSysSys1NTarget& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQSysSys1NTarget* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSysSys1NTarget::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSysSys1NTarget::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQSysSys1NTarget();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sysNum = atol((char*) dbrow[4]); else rec->sysNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQSysSys1NTarget::insertRec(
			WdbeQSysSys1NTarget* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->sysNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQSysSys1NTarget::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQSysSys1NTarget::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQSysSys1NTarget::insertRst(
			ListWdbeQSysSys1NTarget& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQSysSys1NTarget::updateRec(
			WdbeQSysSys1NTarget* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->sysNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQSysSys1NTarget::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQSysSys1NTarget::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSysSys1NTarget::updateRst(
			ListWdbeQSysSys1NTarget& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQSysSys1NTarget::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQSysSys1NTarget::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQSysSys1NTarget::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSysSys1NTarget::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQSysSys1NTarget::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQSysSys1NTarget::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQSysSys1NTarget::loadRecByQref(
			ubigint qref
			, WdbeQSysSys1NTarget** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQSysSys1NTarget WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQSysSys1NTarget::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSysSys1NTarget& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQSysSys1NTarget WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQSysSys1NTarget
 ******************************************************************************/

PgTblWdbeQSysSys1NTarget::PgTblWdbeQSysSys1NTarget() :
			TblWdbeQSysSys1NTarget()
			, PgTable()
		{
};

PgTblWdbeQSysSys1NTarget::~PgTblWdbeQSysSys1NTarget() {
};

void PgTblWdbeQSysSys1NTarget::initStatements() {
	createStatement("TblWdbeQSysSys1NTarget_insertRec", "INSERT INTO TblWdbeQSysSys1NTarget (jref, jnum, ref, sysNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWdbeQSysSys1NTarget_updateRec", "UPDATE TblWdbeQSysSys1NTarget SET jref = $1, jnum = $2, ref = $3, sysNum = $4 WHERE qref = $5", 5);
	createStatement("TblWdbeQSysSys1NTarget_removeRecByQref", "DELETE FROM TblWdbeQSysSys1NTarget WHERE qref = $1", 1);
	createStatement("TblWdbeQSysSys1NTarget_removeRstByJref", "DELETE FROM TblWdbeQSysSys1NTarget WHERE jref = $1", 1);

	createStatement("TblWdbeQSysSys1NTarget_loadRecByQref", "SELECT qref, jref, jnum, ref, sysNum FROM TblWdbeQSysSys1NTarget WHERE qref = $1", 1);
	createStatement("TblWdbeQSysSys1NTarget_loadRstByJref", "SELECT qref, jref, jnum, ref, sysNum FROM TblWdbeQSysSys1NTarget WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQSysSys1NTarget::loadRec(
			PGresult* res
			, WdbeQSysSys1NTarget** rec
		) {
	char* ptr;

	WdbeQSysSys1NTarget* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQSysSys1NTarget();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sysnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sysNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQSysSys1NTarget::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQSysSys1NTarget& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQSysSys1NTarget* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sysnum")
		};

		while (numread < numrow) {
			rec = new WdbeQSysSys1NTarget();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sysNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQSysSys1NTarget::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQSysSys1NTarget** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSysSys1NTarget::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSysSys1NTarget::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQSysSys1NTarget& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSysSys1NTarget::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQSysSys1NTarget::loadRecBySQL(
			const string& sqlstr
			, WdbeQSysSys1NTarget** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSysSys1NTarget::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSysSys1NTarget::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSysSys1NTarget& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSysSys1NTarget::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQSysSys1NTarget::insertRec(
			WdbeQSysSys1NTarget* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _sysNum = htonl(rec->sysNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_sysNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQSysSys1NTarget_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSysSys1NTarget::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQSysSys1NTarget::insertRst(
			ListWdbeQSysSys1NTarget& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQSysSys1NTarget::updateRec(
			WdbeQSysSys1NTarget* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _sysNum = htonl(rec->sysNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_sysNum,
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

	res = PQexecPrepared(dbs, "TblWdbeQSysSys1NTarget_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSysSys1NTarget::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSysSys1NTarget::updateRst(
			ListWdbeQSysSys1NTarget& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQSysSys1NTarget::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSysSys1NTarget_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSysSys1NTarget::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSysSys1NTarget::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSysSys1NTarget_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSysSys1NTarget::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQSysSys1NTarget::loadRecByQref(
			ubigint qref
			, WdbeQSysSys1NTarget** rec
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

	return loadRecByStmt("TblWdbeQSysSys1NTarget_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQSysSys1NTarget::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSysSys1NTarget& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQSysSys1NTarget_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
