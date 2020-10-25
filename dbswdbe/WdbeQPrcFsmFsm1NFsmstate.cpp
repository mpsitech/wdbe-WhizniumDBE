/**
	* \file WdbeQPrcFsmFsm1NFsmstate.cpp
	* Dbs and XML wrapper for table TblWdbeQPrcFsmFsm1NFsmstate (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQPrcFsmFsm1NFsmstate.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrcFsmFsm1NFsmstate
 ******************************************************************************/

WdbeQPrcFsmFsm1NFsmstate::WdbeQPrcFsmFsm1NFsmstate(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint fsmNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->fsmNum = fsmNum;
};

void WdbeQPrcFsmFsm1NFsmstate::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQPrcFsmFsm1NFsmstate";

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
 class ListWdbeQPrcFsmFsm1NFsmstate
 ******************************************************************************/

ListWdbeQPrcFsmFsm1NFsmstate::ListWdbeQPrcFsmFsm1NFsmstate() {
};

ListWdbeQPrcFsmFsm1NFsmstate::ListWdbeQPrcFsmFsm1NFsmstate(
			const ListWdbeQPrcFsmFsm1NFsmstate& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcFsmFsm1NFsmstate(*(src.nodes[i]));
};

ListWdbeQPrcFsmFsm1NFsmstate::~ListWdbeQPrcFsmFsm1NFsmstate() {
	clear();
};

void ListWdbeQPrcFsmFsm1NFsmstate::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQPrcFsmFsm1NFsmstate::size() const {
	return(nodes.size());
};

void ListWdbeQPrcFsmFsm1NFsmstate::append(
			WdbeQPrcFsmFsm1NFsmstate* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQPrcFsmFsm1NFsmstate& ListWdbeQPrcFsmFsm1NFsmstate::operator=(
			const ListWdbeQPrcFsmFsm1NFsmstate& src
		) {
	WdbeQPrcFsmFsm1NFsmstate* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQPrcFsmFsm1NFsmstate(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQPrcFsmFsm1NFsmstate::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQPrcFsmFsm1NFsmstate";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQPrcFsmFsm1NFsmstate
 ******************************************************************************/

TblWdbeQPrcFsmFsm1NFsmstate::TblWdbeQPrcFsmFsm1NFsmstate() {
};

TblWdbeQPrcFsmFsm1NFsmstate::~TblWdbeQPrcFsmFsm1NFsmstate() {
};

bool TblWdbeQPrcFsmFsm1NFsmstate::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrcFsmFsm1NFsmstate** rec
		) {
	return false;
};

ubigint TblWdbeQPrcFsmFsm1NFsmstate::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	return 0;
};

ubigint TblWdbeQPrcFsmFsm1NFsmstate::insertRec(
			WdbeQPrcFsmFsm1NFsmstate* rec
		) {
	return 0;
};

ubigint TblWdbeQPrcFsmFsm1NFsmstate::insertNewRec(
			WdbeQPrcFsmFsm1NFsmstate** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint fsmNum
		) {
	ubigint retval = 0;
	WdbeQPrcFsmFsm1NFsmstate* _rec = NULL;

	_rec = new WdbeQPrcFsmFsm1NFsmstate(0, jref, jnum, ref, stubRef, fsmNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQPrcFsmFsm1NFsmstate::appendNewRecToRst(
			ListWdbeQPrcFsmFsm1NFsmstate& rst
			, WdbeQPrcFsmFsm1NFsmstate** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint fsmNum
		) {
	ubigint retval = 0;
	WdbeQPrcFsmFsm1NFsmstate* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, fsmNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQPrcFsmFsm1NFsmstate::insertRst(
			ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
};

void TblWdbeQPrcFsmFsm1NFsmstate::updateRec(
			WdbeQPrcFsmFsm1NFsmstate* rec
		) {
};

void TblWdbeQPrcFsmFsm1NFsmstate::updateRst(
			ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
};

void TblWdbeQPrcFsmFsm1NFsmstate::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQPrcFsmFsm1NFsmstate::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQPrcFsmFsm1NFsmstate::loadRecByQref(
			ubigint qref
			, WdbeQPrcFsmFsm1NFsmstate** rec
		) {
	return false;
};

ubigint TblWdbeQPrcFsmFsm1NFsmstate::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQPrcFsmFsm1NFsmstate
 ******************************************************************************/

MyTblWdbeQPrcFsmFsm1NFsmstate::MyTblWdbeQPrcFsmFsm1NFsmstate() :
			TblWdbeQPrcFsmFsm1NFsmstate()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQPrcFsmFsm1NFsmstate::~MyTblWdbeQPrcFsmFsm1NFsmstate() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQPrcFsmFsm1NFsmstate::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQPrcFsmFsm1NFsmstate (jref, jnum, ref, fsmNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQPrcFsmFsm1NFsmstate SET jref = ?, jnum = ?, ref = ?, fsmNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQPrcFsmFsm1NFsmstate WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQPrcFsmFsm1NFsmstate WHERE jref = ?", false);
};

bool MyTblWdbeQPrcFsmFsm1NFsmstate::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrcFsmFsm1NFsmstate** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQPrcFsmFsm1NFsmstate* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQPrcFsmFsm1NFsmstate();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->fsmNum = atol((char*) dbrow[4]); else _rec->fsmNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQPrcFsmFsm1NFsmstate::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQPrcFsmFsm1NFsmstate* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQPrcFsmFsm1NFsmstate();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->fsmNum = atol((char*) dbrow[4]); else rec->fsmNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQPrcFsmFsm1NFsmstate::insertRec(
			WdbeQPrcFsmFsm1NFsmstate* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->fsmNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQPrcFsmFsm1NFsmstate::insertRst(
			ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQPrcFsmFsm1NFsmstate::updateRec(
			WdbeQPrcFsmFsm1NFsmstate* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->fsmNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrcFsmFsm1NFsmstate::updateRst(
			ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQPrcFsmFsm1NFsmstate::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrcFsmFsm1NFsmstate::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQPrcFsmFsm1NFsmstate::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQPrcFsmFsm1NFsmstate::loadRecByQref(
			ubigint qref
			, WdbeQPrcFsmFsm1NFsmstate** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQPrcFsmFsm1NFsmstate WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQPrcFsmFsm1NFsmstate::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQPrcFsmFsm1NFsmstate WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQPrcFsmFsm1NFsmstate
 ******************************************************************************/

PgTblWdbeQPrcFsmFsm1NFsmstate::PgTblWdbeQPrcFsmFsm1NFsmstate() :
			TblWdbeQPrcFsmFsm1NFsmstate()
			, PgTable()
		{
};

PgTblWdbeQPrcFsmFsm1NFsmstate::~PgTblWdbeQPrcFsmFsm1NFsmstate() {
};

void PgTblWdbeQPrcFsmFsm1NFsmstate::initStatements() {
	createStatement("TblWdbeQPrcFsmFsm1NFsmstate_insertRec", "INSERT INTO TblWdbeQPrcFsmFsm1NFsmstate (jref, jnum, ref, fsmNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWdbeQPrcFsmFsm1NFsmstate_updateRec", "UPDATE TblWdbeQPrcFsmFsm1NFsmstate SET jref = $1, jnum = $2, ref = $3, fsmNum = $4 WHERE qref = $5", 5);
	createStatement("TblWdbeQPrcFsmFsm1NFsmstate_removeRecByQref", "DELETE FROM TblWdbeQPrcFsmFsm1NFsmstate WHERE qref = $1", 1);
	createStatement("TblWdbeQPrcFsmFsm1NFsmstate_removeRstByJref", "DELETE FROM TblWdbeQPrcFsmFsm1NFsmstate WHERE jref = $1", 1);

	createStatement("TblWdbeQPrcFsmFsm1NFsmstate_loadRecByQref", "SELECT qref, jref, jnum, ref, fsmNum FROM TblWdbeQPrcFsmFsm1NFsmstate WHERE qref = $1", 1);
	createStatement("TblWdbeQPrcFsmFsm1NFsmstate_loadRstByJref", "SELECT qref, jref, jnum, ref, fsmNum FROM TblWdbeQPrcFsmFsm1NFsmstate WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQPrcFsmFsm1NFsmstate::loadRec(
			PGresult* res
			, WdbeQPrcFsmFsm1NFsmstate** rec
		) {
	char* ptr;

	WdbeQPrcFsmFsm1NFsmstate* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQPrcFsmFsm1NFsmstate();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "fsmnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->fsmNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQPrcFsmFsm1NFsmstate::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQPrcFsmFsm1NFsmstate* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "fsmnum")
		};

		while (numread < numrow) {
			rec = new WdbeQPrcFsmFsm1NFsmstate();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->fsmNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQPrcFsmFsm1NFsmstate::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQPrcFsmFsm1NFsmstate** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrcFsmFsm1NFsmstate::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrcFsmFsm1NFsmstate::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrcFsmFsm1NFsmstate::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQPrcFsmFsm1NFsmstate::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrcFsmFsm1NFsmstate** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrcFsmFsm1NFsmstate::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrcFsmFsm1NFsmstate::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrcFsmFsm1NFsmstate::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQPrcFsmFsm1NFsmstate::insertRec(
			WdbeQPrcFsmFsm1NFsmstate* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _fsmNum = htonl(rec->fsmNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_fsmNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQPrcFsmFsm1NFsmstate_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrcFsmFsm1NFsmstate::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQPrcFsmFsm1NFsmstate::insertRst(
			ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQPrcFsmFsm1NFsmstate::updateRec(
			WdbeQPrcFsmFsm1NFsmstate* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _fsmNum = htonl(rec->fsmNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_fsmNum,
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

	res = PQexecPrepared(dbs, "TblWdbeQPrcFsmFsm1NFsmstate_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrcFsmFsm1NFsmstate::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrcFsmFsm1NFsmstate::updateRst(
			ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQPrcFsmFsm1NFsmstate::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrcFsmFsm1NFsmstate_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrcFsmFsm1NFsmstate::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrcFsmFsm1NFsmstate::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrcFsmFsm1NFsmstate_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrcFsmFsm1NFsmstate::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQPrcFsmFsm1NFsmstate::loadRecByQref(
			ubigint qref
			, WdbeQPrcFsmFsm1NFsmstate** rec
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

	return loadRecByStmt("TblWdbeQPrcFsmFsm1NFsmstate_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQPrcFsmFsm1NFsmstate::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrcFsmFsm1NFsmstate& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQPrcFsmFsm1NFsmstate_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

