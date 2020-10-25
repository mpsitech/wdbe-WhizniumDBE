/**
	* \file WdbeQPrcList.cpp
	* Dbs and XML wrapper for table TblWdbeQPrcList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQPrcList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrcList
 ******************************************************************************/

WdbeQPrcList::WdbeQPrcList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWdbeMModule
			, const string stubRefWdbeMModule
			, const bool Falling
			, const string yesnoFalling
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->refWdbeMModule = refWdbeMModule;
	this->stubRefWdbeMModule = stubRefWdbeMModule;
	this->Falling = Falling;
	this->yesnoFalling = yesnoFalling;
};

void WdbeQPrcList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQPrcList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "mdl", stubRefWdbeMModule);
		writeString(wr, "fal", yesnoFalling);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefWdbeMModule", stubRefWdbeMModule);
		writeString(wr, "yesnoFalling", yesnoFalling);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQPrcList
 ******************************************************************************/

ListWdbeQPrcList::ListWdbeQPrcList() {
};

ListWdbeQPrcList::ListWdbeQPrcList(
			const ListWdbeQPrcList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrcList(*(src.nodes[i]));
};

ListWdbeQPrcList::~ListWdbeQPrcList() {
	clear();
};

void ListWdbeQPrcList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQPrcList::size() const {
	return(nodes.size());
};

void ListWdbeQPrcList::append(
			WdbeQPrcList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQPrcList& ListWdbeQPrcList::operator=(
			const ListWdbeQPrcList& src
		) {
	WdbeQPrcList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQPrcList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQPrcList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQPrcList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQPrcList
 ******************************************************************************/

TblWdbeQPrcList::TblWdbeQPrcList() {
};

TblWdbeQPrcList::~TblWdbeQPrcList() {
};

bool TblWdbeQPrcList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrcList** rec
		) {
	return false;
};

ubigint TblWdbeQPrcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrcList& rst
		) {
	return 0;
};

ubigint TblWdbeQPrcList::insertRec(
			WdbeQPrcList* rec
		) {
	return 0;
};

ubigint TblWdbeQPrcList::insertNewRec(
			WdbeQPrcList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWdbeMModule
			, const string stubRefWdbeMModule
			, const bool Falling
			, const string yesnoFalling
		) {
	ubigint retval = 0;
	WdbeQPrcList* _rec = NULL;

	_rec = new WdbeQPrcList(0, jref, jnum, ref, sref, refWdbeMModule, stubRefWdbeMModule, Falling, yesnoFalling);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQPrcList::appendNewRecToRst(
			ListWdbeQPrcList& rst
			, WdbeQPrcList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refWdbeMModule
			, const string stubRefWdbeMModule
			, const bool Falling
			, const string yesnoFalling
		) {
	ubigint retval = 0;
	WdbeQPrcList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, refWdbeMModule, stubRefWdbeMModule, Falling, yesnoFalling);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQPrcList::insertRst(
			ListWdbeQPrcList& rst
		) {
};

void TblWdbeQPrcList::updateRec(
			WdbeQPrcList* rec
		) {
};

void TblWdbeQPrcList::updateRst(
			ListWdbeQPrcList& rst
		) {
};

void TblWdbeQPrcList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQPrcList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQPrcList::loadRecByQref(
			ubigint qref
			, WdbeQPrcList** rec
		) {
	return false;
};

ubigint TblWdbeQPrcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrcList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQPrcList
 ******************************************************************************/

MyTblWdbeQPrcList::MyTblWdbeQPrcList() :
			TblWdbeQPrcList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQPrcList::~MyTblWdbeQPrcList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQPrcList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQPrcList (jref, jnum, ref, sref, refWdbeMModule, Falling) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQPrcList SET jref = ?, jnum = ?, ref = ?, sref = ?, refWdbeMModule = ?, Falling = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQPrcList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQPrcList WHERE jref = ?", false);
};

bool MyTblWdbeQPrcList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrcList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQPrcList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrcList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrcList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQPrcList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->refWdbeMModule = atoll((char*) dbrow[5]); else _rec->refWdbeMModule = 0;
		if (dbrow[6]) _rec->Falling = (atoi((char*) dbrow[6]) != 0); else _rec->Falling = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQPrcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrcList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQPrcList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrcList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrcList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQPrcList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->refWdbeMModule = atoll((char*) dbrow[5]); else rec->refWdbeMModule = 0;
			if (dbrow[6]) rec->Falling = (atoi((char*) dbrow[6]) != 0); else rec->Falling = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQPrcList::insertRec(
			WdbeQPrcList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();
	tinyint Falling = rec->Falling;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Falling,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQPrcList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQPrcList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQPrcList::insertRst(
			ListWdbeQPrcList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQPrcList::updateRec(
			WdbeQPrcList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	tinyint Falling = rec->Falling;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Falling,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQPrcList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQPrcList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrcList::updateRst(
			ListWdbeQPrcList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQPrcList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQPrcList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQPrcList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrcList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQPrcList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQPrcList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQPrcList::loadRecByQref(
			ubigint qref
			, WdbeQPrcList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQPrcList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQPrcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrcList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQPrcList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQPrcList
 ******************************************************************************/

PgTblWdbeQPrcList::PgTblWdbeQPrcList() :
			TblWdbeQPrcList()
			, PgTable()
		{
};

PgTblWdbeQPrcList::~PgTblWdbeQPrcList() {
};

void PgTblWdbeQPrcList::initStatements() {
	createStatement("TblWdbeQPrcList_insertRec", "INSERT INTO TblWdbeQPrcList (jref, jnum, ref, sref, refWdbeMModule, Falling) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWdbeQPrcList_updateRec", "UPDATE TblWdbeQPrcList SET jref = $1, jnum = $2, ref = $3, sref = $4, refWdbeMModule = $5, Falling = $6 WHERE qref = $7", 7);
	createStatement("TblWdbeQPrcList_removeRecByQref", "DELETE FROM TblWdbeQPrcList WHERE qref = $1", 1);
	createStatement("TblWdbeQPrcList_removeRstByJref", "DELETE FROM TblWdbeQPrcList WHERE jref = $1", 1);

	createStatement("TblWdbeQPrcList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, refWdbeMModule, Falling FROM TblWdbeQPrcList WHERE qref = $1", 1);
	createStatement("TblWdbeQPrcList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, refWdbeMModule, Falling FROM TblWdbeQPrcList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQPrcList::loadRec(
			PGresult* res
			, WdbeQPrcList** rec
		) {
	char* ptr;

	WdbeQPrcList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQPrcList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "falling")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Falling = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQPrcList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQPrcList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQPrcList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "falling")
		};

		while (numread < numrow) {
			rec = new WdbeQPrcList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Falling = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQPrcList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQPrcList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrcList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrcList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQPrcList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrcList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQPrcList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrcList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrcList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrcList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrcList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrcList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQPrcList::insertRec(
			WdbeQPrcList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	smallint _Falling = htons((smallint) rec->Falling);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWdbeMModule,
		(char*) &_Falling
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQPrcList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrcList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQPrcList::insertRst(
			ListWdbeQPrcList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQPrcList::updateRec(
			WdbeQPrcList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	smallint _Falling = htons((smallint) rec->Falling);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refWdbeMModule,
		(char*) &_Falling,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQPrcList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrcList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrcList::updateRst(
			ListWdbeQPrcList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQPrcList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrcList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrcList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrcList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrcList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrcList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQPrcList::loadRecByQref(
			ubigint qref
			, WdbeQPrcList** rec
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

	return loadRecByStmt("TblWdbeQPrcList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQPrcList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrcList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQPrcList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

