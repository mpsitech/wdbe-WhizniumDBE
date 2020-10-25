/**
	* \file WdbeQModMdl1NSignal.cpp
	* Dbs and XML wrapper for table TblWdbeQModMdl1NSignal (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQModMdl1NSignal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModMdl1NSignal
 ******************************************************************************/

WdbeQModMdl1NSignal::WdbeQModMdl1NSignal(
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

void WdbeQModMdl1NSignal::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQModMdl1NSignal";

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
 class ListWdbeQModMdl1NSignal
 ******************************************************************************/

ListWdbeQModMdl1NSignal::ListWdbeQModMdl1NSignal() {
};

ListWdbeQModMdl1NSignal::ListWdbeQModMdl1NSignal(
			const ListWdbeQModMdl1NSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModMdl1NSignal(*(src.nodes[i]));
};

ListWdbeQModMdl1NSignal::~ListWdbeQModMdl1NSignal() {
	clear();
};

void ListWdbeQModMdl1NSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQModMdl1NSignal::size() const {
	return(nodes.size());
};

void ListWdbeQModMdl1NSignal::append(
			WdbeQModMdl1NSignal* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQModMdl1NSignal& ListWdbeQModMdl1NSignal::operator=(
			const ListWdbeQModMdl1NSignal& src
		) {
	WdbeQModMdl1NSignal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQModMdl1NSignal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQModMdl1NSignal::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQModMdl1NSignal";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQModMdl1NSignal
 ******************************************************************************/

TblWdbeQModMdl1NSignal::TblWdbeQModMdl1NSignal() {
};

TblWdbeQModMdl1NSignal::~TblWdbeQModMdl1NSignal() {
};

bool TblWdbeQModMdl1NSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeQModMdl1NSignal** rec
		) {
	return false;
};

ubigint TblWdbeQModMdl1NSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModMdl1NSignal& rst
		) {
	return 0;
};

ubigint TblWdbeQModMdl1NSignal::insertRec(
			WdbeQModMdl1NSignal* rec
		) {
	return 0;
};

ubigint TblWdbeQModMdl1NSignal::insertNewRec(
			WdbeQModMdl1NSignal** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint mdlNum
		) {
	ubigint retval = 0;
	WdbeQModMdl1NSignal* _rec = NULL;

	_rec = new WdbeQModMdl1NSignal(0, jref, jnum, ref, stubRef, mdlNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQModMdl1NSignal::appendNewRecToRst(
			ListWdbeQModMdl1NSignal& rst
			, WdbeQModMdl1NSignal** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint mdlNum
		) {
	ubigint retval = 0;
	WdbeQModMdl1NSignal* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, mdlNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQModMdl1NSignal::insertRst(
			ListWdbeQModMdl1NSignal& rst
		) {
};

void TblWdbeQModMdl1NSignal::updateRec(
			WdbeQModMdl1NSignal* rec
		) {
};

void TblWdbeQModMdl1NSignal::updateRst(
			ListWdbeQModMdl1NSignal& rst
		) {
};

void TblWdbeQModMdl1NSignal::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQModMdl1NSignal::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQModMdl1NSignal::loadRecByQref(
			ubigint qref
			, WdbeQModMdl1NSignal** rec
		) {
	return false;
};

ubigint TblWdbeQModMdl1NSignal::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModMdl1NSignal& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQModMdl1NSignal
 ******************************************************************************/

MyTblWdbeQModMdl1NSignal::MyTblWdbeQModMdl1NSignal() :
			TblWdbeQModMdl1NSignal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQModMdl1NSignal::~MyTblWdbeQModMdl1NSignal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQModMdl1NSignal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQModMdl1NSignal (jref, jnum, ref, mdlNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQModMdl1NSignal SET jref = ?, jnum = ?, ref = ?, mdlNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQModMdl1NSignal WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQModMdl1NSignal WHERE jref = ?", false);
};

bool MyTblWdbeQModMdl1NSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeQModMdl1NSignal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQModMdl1NSignal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModMdl1NSignal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModMdl1NSignal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQModMdl1NSignal();

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

ubigint MyTblWdbeQModMdl1NSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModMdl1NSignal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQModMdl1NSignal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModMdl1NSignal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModMdl1NSignal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQModMdl1NSignal();

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

ubigint MyTblWdbeQModMdl1NSignal::insertRec(
			WdbeQModMdl1NSignal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->mdlNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQModMdl1NSignal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQModMdl1NSignal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQModMdl1NSignal::insertRst(
			ListWdbeQModMdl1NSignal& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQModMdl1NSignal::updateRec(
			WdbeQModMdl1NSignal* rec
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
		string dbms = "MyTblWdbeQModMdl1NSignal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQModMdl1NSignal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModMdl1NSignal::updateRst(
			ListWdbeQModMdl1NSignal& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQModMdl1NSignal::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQModMdl1NSignal::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQModMdl1NSignal::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModMdl1NSignal::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQModMdl1NSignal::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQModMdl1NSignal::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQModMdl1NSignal::loadRecByQref(
			ubigint qref
			, WdbeQModMdl1NSignal** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQModMdl1NSignal WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQModMdl1NSignal::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModMdl1NSignal& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQModMdl1NSignal WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQModMdl1NSignal
 ******************************************************************************/

PgTblWdbeQModMdl1NSignal::PgTblWdbeQModMdl1NSignal() :
			TblWdbeQModMdl1NSignal()
			, PgTable()
		{
};

PgTblWdbeQModMdl1NSignal::~PgTblWdbeQModMdl1NSignal() {
};

void PgTblWdbeQModMdl1NSignal::initStatements() {
	createStatement("TblWdbeQModMdl1NSignal_insertRec", "INSERT INTO TblWdbeQModMdl1NSignal (jref, jnum, ref, mdlNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWdbeQModMdl1NSignal_updateRec", "UPDATE TblWdbeQModMdl1NSignal SET jref = $1, jnum = $2, ref = $3, mdlNum = $4 WHERE qref = $5", 5);
	createStatement("TblWdbeQModMdl1NSignal_removeRecByQref", "DELETE FROM TblWdbeQModMdl1NSignal WHERE qref = $1", 1);
	createStatement("TblWdbeQModMdl1NSignal_removeRstByJref", "DELETE FROM TblWdbeQModMdl1NSignal WHERE jref = $1", 1);

	createStatement("TblWdbeQModMdl1NSignal_loadRecByQref", "SELECT qref, jref, jnum, ref, mdlNum FROM TblWdbeQModMdl1NSignal WHERE qref = $1", 1);
	createStatement("TblWdbeQModMdl1NSignal_loadRstByJref", "SELECT qref, jref, jnum, ref, mdlNum FROM TblWdbeQModMdl1NSignal WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQModMdl1NSignal::loadRec(
			PGresult* res
			, WdbeQModMdl1NSignal** rec
		) {
	char* ptr;

	WdbeQModMdl1NSignal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQModMdl1NSignal();

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

ubigint PgTblWdbeQModMdl1NSignal::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQModMdl1NSignal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQModMdl1NSignal* rec;

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
			rec = new WdbeQModMdl1NSignal();

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

bool PgTblWdbeQModMdl1NSignal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQModMdl1NSignal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModMdl1NSignal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModMdl1NSignal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQModMdl1NSignal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModMdl1NSignal::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQModMdl1NSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeQModMdl1NSignal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModMdl1NSignal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModMdl1NSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModMdl1NSignal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModMdl1NSignal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQModMdl1NSignal::insertRec(
			WdbeQModMdl1NSignal* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQModMdl1NSignal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModMdl1NSignal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQModMdl1NSignal::insertRst(
			ListWdbeQModMdl1NSignal& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQModMdl1NSignal::updateRec(
			WdbeQModMdl1NSignal* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQModMdl1NSignal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModMdl1NSignal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModMdl1NSignal::updateRst(
			ListWdbeQModMdl1NSignal& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQModMdl1NSignal::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModMdl1NSignal_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModMdl1NSignal::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModMdl1NSignal::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModMdl1NSignal_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModMdl1NSignal::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQModMdl1NSignal::loadRecByQref(
			ubigint qref
			, WdbeQModMdl1NSignal** rec
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

	return loadRecByStmt("TblWdbeQModMdl1NSignal_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQModMdl1NSignal::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModMdl1NSignal& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQModMdl1NSignal_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

