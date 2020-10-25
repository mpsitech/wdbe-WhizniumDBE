/**
	* \file WdbeQMtpMdl1NGeneric.cpp
	* Dbs and XML wrapper for table TblWdbeQMtpMdl1NGeneric (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQMtpMdl1NGeneric.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMtpMdl1NGeneric
 ******************************************************************************/

WdbeQMtpMdl1NGeneric::WdbeQMtpMdl1NGeneric(
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

void WdbeQMtpMdl1NGeneric::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQMtpMdl1NGeneric";

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
 class ListWdbeQMtpMdl1NGeneric
 ******************************************************************************/

ListWdbeQMtpMdl1NGeneric::ListWdbeQMtpMdl1NGeneric() {
};

ListWdbeQMtpMdl1NGeneric::ListWdbeQMtpMdl1NGeneric(
			const ListWdbeQMtpMdl1NGeneric& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMtpMdl1NGeneric(*(src.nodes[i]));
};

ListWdbeQMtpMdl1NGeneric::~ListWdbeQMtpMdl1NGeneric() {
	clear();
};

void ListWdbeQMtpMdl1NGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQMtpMdl1NGeneric::size() const {
	return(nodes.size());
};

void ListWdbeQMtpMdl1NGeneric::append(
			WdbeQMtpMdl1NGeneric* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQMtpMdl1NGeneric& ListWdbeQMtpMdl1NGeneric::operator=(
			const ListWdbeQMtpMdl1NGeneric& src
		) {
	WdbeQMtpMdl1NGeneric* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQMtpMdl1NGeneric(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQMtpMdl1NGeneric::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQMtpMdl1NGeneric";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQMtpMdl1NGeneric
 ******************************************************************************/

TblWdbeQMtpMdl1NGeneric::TblWdbeQMtpMdl1NGeneric() {
};

TblWdbeQMtpMdl1NGeneric::~TblWdbeQMtpMdl1NGeneric() {
};

bool TblWdbeQMtpMdl1NGeneric::loadRecBySQL(
			const string& sqlstr
			, WdbeQMtpMdl1NGeneric** rec
		) {
	return false;
};

ubigint TblWdbeQMtpMdl1NGeneric::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMtpMdl1NGeneric& rst
		) {
	return 0;
};

ubigint TblWdbeQMtpMdl1NGeneric::insertRec(
			WdbeQMtpMdl1NGeneric* rec
		) {
	return 0;
};

ubigint TblWdbeQMtpMdl1NGeneric::insertNewRec(
			WdbeQMtpMdl1NGeneric** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint mdlNum
		) {
	ubigint retval = 0;
	WdbeQMtpMdl1NGeneric* _rec = NULL;

	_rec = new WdbeQMtpMdl1NGeneric(0, jref, jnum, ref, stubRef, mdlNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQMtpMdl1NGeneric::appendNewRecToRst(
			ListWdbeQMtpMdl1NGeneric& rst
			, WdbeQMtpMdl1NGeneric** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint mdlNum
		) {
	ubigint retval = 0;
	WdbeQMtpMdl1NGeneric* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, mdlNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQMtpMdl1NGeneric::insertRst(
			ListWdbeQMtpMdl1NGeneric& rst
		) {
};

void TblWdbeQMtpMdl1NGeneric::updateRec(
			WdbeQMtpMdl1NGeneric* rec
		) {
};

void TblWdbeQMtpMdl1NGeneric::updateRst(
			ListWdbeQMtpMdl1NGeneric& rst
		) {
};

void TblWdbeQMtpMdl1NGeneric::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQMtpMdl1NGeneric::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQMtpMdl1NGeneric::loadRecByQref(
			ubigint qref
			, WdbeQMtpMdl1NGeneric** rec
		) {
	return false;
};

ubigint TblWdbeQMtpMdl1NGeneric::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMtpMdl1NGeneric& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQMtpMdl1NGeneric
 ******************************************************************************/

MyTblWdbeQMtpMdl1NGeneric::MyTblWdbeQMtpMdl1NGeneric() :
			TblWdbeQMtpMdl1NGeneric()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQMtpMdl1NGeneric::~MyTblWdbeQMtpMdl1NGeneric() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQMtpMdl1NGeneric::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQMtpMdl1NGeneric (jref, jnum, ref, mdlNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQMtpMdl1NGeneric SET jref = ?, jnum = ?, ref = ?, mdlNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQMtpMdl1NGeneric WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQMtpMdl1NGeneric WHERE jref = ?", false);
};

bool MyTblWdbeQMtpMdl1NGeneric::loadRecBySQL(
			const string& sqlstr
			, WdbeQMtpMdl1NGeneric** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQMtpMdl1NGeneric* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQMtpMdl1NGeneric();

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

ubigint MyTblWdbeQMtpMdl1NGeneric::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMtpMdl1NGeneric& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQMtpMdl1NGeneric* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQMtpMdl1NGeneric();

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

ubigint MyTblWdbeQMtpMdl1NGeneric::insertRec(
			WdbeQMtpMdl1NGeneric* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->mdlNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQMtpMdl1NGeneric::insertRst(
			ListWdbeQMtpMdl1NGeneric& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQMtpMdl1NGeneric::updateRec(
			WdbeQMtpMdl1NGeneric* rec
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
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQMtpMdl1NGeneric::updateRst(
			ListWdbeQMtpMdl1NGeneric& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQMtpMdl1NGeneric::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQMtpMdl1NGeneric::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQMtpMdl1NGeneric::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQMtpMdl1NGeneric::loadRecByQref(
			ubigint qref
			, WdbeQMtpMdl1NGeneric** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQMtpMdl1NGeneric WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQMtpMdl1NGeneric::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMtpMdl1NGeneric& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQMtpMdl1NGeneric WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQMtpMdl1NGeneric
 ******************************************************************************/

PgTblWdbeQMtpMdl1NGeneric::PgTblWdbeQMtpMdl1NGeneric() :
			TblWdbeQMtpMdl1NGeneric()
			, PgTable()
		{
};

PgTblWdbeQMtpMdl1NGeneric::~PgTblWdbeQMtpMdl1NGeneric() {
};

void PgTblWdbeQMtpMdl1NGeneric::initStatements() {
	createStatement("TblWdbeQMtpMdl1NGeneric_insertRec", "INSERT INTO TblWdbeQMtpMdl1NGeneric (jref, jnum, ref, mdlNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWdbeQMtpMdl1NGeneric_updateRec", "UPDATE TblWdbeQMtpMdl1NGeneric SET jref = $1, jnum = $2, ref = $3, mdlNum = $4 WHERE qref = $5", 5);
	createStatement("TblWdbeQMtpMdl1NGeneric_removeRecByQref", "DELETE FROM TblWdbeQMtpMdl1NGeneric WHERE qref = $1", 1);
	createStatement("TblWdbeQMtpMdl1NGeneric_removeRstByJref", "DELETE FROM TblWdbeQMtpMdl1NGeneric WHERE jref = $1", 1);

	createStatement("TblWdbeQMtpMdl1NGeneric_loadRecByQref", "SELECT qref, jref, jnum, ref, mdlNum FROM TblWdbeQMtpMdl1NGeneric WHERE qref = $1", 1);
	createStatement("TblWdbeQMtpMdl1NGeneric_loadRstByJref", "SELECT qref, jref, jnum, ref, mdlNum FROM TblWdbeQMtpMdl1NGeneric WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQMtpMdl1NGeneric::loadRec(
			PGresult* res
			, WdbeQMtpMdl1NGeneric** rec
		) {
	char* ptr;

	WdbeQMtpMdl1NGeneric* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQMtpMdl1NGeneric();

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

ubigint PgTblWdbeQMtpMdl1NGeneric::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQMtpMdl1NGeneric& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQMtpMdl1NGeneric* rec;

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
			rec = new WdbeQMtpMdl1NGeneric();

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

bool PgTblWdbeQMtpMdl1NGeneric::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQMtpMdl1NGeneric** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMtpMdl1NGeneric::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQMtpMdl1NGeneric::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQMtpMdl1NGeneric& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMtpMdl1NGeneric::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQMtpMdl1NGeneric::loadRecBySQL(
			const string& sqlstr
			, WdbeQMtpMdl1NGeneric** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQMtpMdl1NGeneric::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQMtpMdl1NGeneric::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMtpMdl1NGeneric& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQMtpMdl1NGeneric::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQMtpMdl1NGeneric::insertRec(
			WdbeQMtpMdl1NGeneric* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQMtpMdl1NGeneric_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMtpMdl1NGeneric::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQMtpMdl1NGeneric::insertRst(
			ListWdbeQMtpMdl1NGeneric& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQMtpMdl1NGeneric::updateRec(
			WdbeQMtpMdl1NGeneric* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQMtpMdl1NGeneric_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMtpMdl1NGeneric::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQMtpMdl1NGeneric::updateRst(
			ListWdbeQMtpMdl1NGeneric& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQMtpMdl1NGeneric::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQMtpMdl1NGeneric_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMtpMdl1NGeneric::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQMtpMdl1NGeneric::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQMtpMdl1NGeneric_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMtpMdl1NGeneric::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQMtpMdl1NGeneric::loadRecByQref(
			ubigint qref
			, WdbeQMtpMdl1NGeneric** rec
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

	return loadRecByStmt("TblWdbeQMtpMdl1NGeneric_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQMtpMdl1NGeneric::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMtpMdl1NGeneric& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQMtpMdl1NGeneric_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

