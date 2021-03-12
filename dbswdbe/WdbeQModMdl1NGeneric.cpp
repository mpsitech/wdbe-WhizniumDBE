/**
	* \file WdbeQModMdl1NGeneric.cpp
	* Dbs and XML wrapper for table TblWdbeQModMdl1NGeneric (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQModMdl1NGeneric.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModMdl1NGeneric
 ******************************************************************************/

WdbeQModMdl1NGeneric::WdbeQModMdl1NGeneric(
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

void WdbeQModMdl1NGeneric::writeJSON(
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

void WdbeQModMdl1NGeneric::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQModMdl1NGeneric";

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
 class ListWdbeQModMdl1NGeneric
 ******************************************************************************/

ListWdbeQModMdl1NGeneric::ListWdbeQModMdl1NGeneric() {
};

ListWdbeQModMdl1NGeneric::ListWdbeQModMdl1NGeneric(
			const ListWdbeQModMdl1NGeneric& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModMdl1NGeneric(*(src.nodes[i]));
};

ListWdbeQModMdl1NGeneric::~ListWdbeQModMdl1NGeneric() {
	clear();
};

void ListWdbeQModMdl1NGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQModMdl1NGeneric::size() const {
	return(nodes.size());
};

void ListWdbeQModMdl1NGeneric::append(
			WdbeQModMdl1NGeneric* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQModMdl1NGeneric& ListWdbeQModMdl1NGeneric::operator=(
			const ListWdbeQModMdl1NGeneric& src
		) {
	WdbeQModMdl1NGeneric* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQModMdl1NGeneric(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQModMdl1NGeneric::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQModMdl1NGeneric";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQModMdl1NGeneric::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQModMdl1NGeneric";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQModMdl1NGeneric
 ******************************************************************************/

TblWdbeQModMdl1NGeneric::TblWdbeQModMdl1NGeneric() {
};

TblWdbeQModMdl1NGeneric::~TblWdbeQModMdl1NGeneric() {
};

bool TblWdbeQModMdl1NGeneric::loadRecBySQL(
			const string& sqlstr
			, WdbeQModMdl1NGeneric** rec
		) {
	return false;
};

ubigint TblWdbeQModMdl1NGeneric::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModMdl1NGeneric& rst
		) {
	return 0;
};

ubigint TblWdbeQModMdl1NGeneric::insertRec(
			WdbeQModMdl1NGeneric* rec
		) {
	return 0;
};

ubigint TblWdbeQModMdl1NGeneric::insertNewRec(
			WdbeQModMdl1NGeneric** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint mdlNum
		) {
	ubigint retval = 0;
	WdbeQModMdl1NGeneric* _rec = NULL;

	_rec = new WdbeQModMdl1NGeneric(0, jref, jnum, ref, stubRef, mdlNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQModMdl1NGeneric::appendNewRecToRst(
			ListWdbeQModMdl1NGeneric& rst
			, WdbeQModMdl1NGeneric** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint mdlNum
		) {
	ubigint retval = 0;
	WdbeQModMdl1NGeneric* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, mdlNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQModMdl1NGeneric::insertRst(
			ListWdbeQModMdl1NGeneric& rst
		) {
};

void TblWdbeQModMdl1NGeneric::updateRec(
			WdbeQModMdl1NGeneric* rec
		) {
};

void TblWdbeQModMdl1NGeneric::updateRst(
			ListWdbeQModMdl1NGeneric& rst
		) {
};

void TblWdbeQModMdl1NGeneric::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQModMdl1NGeneric::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQModMdl1NGeneric::loadRecByQref(
			ubigint qref
			, WdbeQModMdl1NGeneric** rec
		) {
	return false;
};

ubigint TblWdbeQModMdl1NGeneric::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModMdl1NGeneric& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQModMdl1NGeneric
 ******************************************************************************/

MyTblWdbeQModMdl1NGeneric::MyTblWdbeQModMdl1NGeneric() :
			TblWdbeQModMdl1NGeneric()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQModMdl1NGeneric::~MyTblWdbeQModMdl1NGeneric() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQModMdl1NGeneric::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQModMdl1NGeneric (jref, jnum, ref, mdlNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQModMdl1NGeneric SET jref = ?, jnum = ?, ref = ?, mdlNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQModMdl1NGeneric WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQModMdl1NGeneric WHERE jref = ?", false);
};

bool MyTblWdbeQModMdl1NGeneric::loadRecBySQL(
			const string& sqlstr
			, WdbeQModMdl1NGeneric** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQModMdl1NGeneric* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModMdl1NGeneric::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModMdl1NGeneric::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQModMdl1NGeneric();

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

ubigint MyTblWdbeQModMdl1NGeneric::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModMdl1NGeneric& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQModMdl1NGeneric* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModMdl1NGeneric::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModMdl1NGeneric::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQModMdl1NGeneric();

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

ubigint MyTblWdbeQModMdl1NGeneric::insertRec(
			WdbeQModMdl1NGeneric* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->mdlNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQModMdl1NGeneric::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQModMdl1NGeneric::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQModMdl1NGeneric::insertRst(
			ListWdbeQModMdl1NGeneric& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQModMdl1NGeneric::updateRec(
			WdbeQModMdl1NGeneric* rec
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
		string dbms = "MyTblWdbeQModMdl1NGeneric::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQModMdl1NGeneric::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModMdl1NGeneric::updateRst(
			ListWdbeQModMdl1NGeneric& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQModMdl1NGeneric::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQModMdl1NGeneric::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQModMdl1NGeneric::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModMdl1NGeneric::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQModMdl1NGeneric::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQModMdl1NGeneric::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQModMdl1NGeneric::loadRecByQref(
			ubigint qref
			, WdbeQModMdl1NGeneric** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQModMdl1NGeneric WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQModMdl1NGeneric::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModMdl1NGeneric& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQModMdl1NGeneric WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQModMdl1NGeneric
 ******************************************************************************/

PgTblWdbeQModMdl1NGeneric::PgTblWdbeQModMdl1NGeneric() :
			TblWdbeQModMdl1NGeneric()
			, PgTable()
		{
};

PgTblWdbeQModMdl1NGeneric::~PgTblWdbeQModMdl1NGeneric() {
};

void PgTblWdbeQModMdl1NGeneric::initStatements() {
	createStatement("TblWdbeQModMdl1NGeneric_insertRec", "INSERT INTO TblWdbeQModMdl1NGeneric (jref, jnum, ref, mdlNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4);
	createStatement("TblWdbeQModMdl1NGeneric_updateRec", "UPDATE TblWdbeQModMdl1NGeneric SET jref = $1, jnum = $2, ref = $3, mdlNum = $4 WHERE qref = $5", 5);
	createStatement("TblWdbeQModMdl1NGeneric_removeRecByQref", "DELETE FROM TblWdbeQModMdl1NGeneric WHERE qref = $1", 1);
	createStatement("TblWdbeQModMdl1NGeneric_removeRstByJref", "DELETE FROM TblWdbeQModMdl1NGeneric WHERE jref = $1", 1);

	createStatement("TblWdbeQModMdl1NGeneric_loadRecByQref", "SELECT qref, jref, jnum, ref, mdlNum FROM TblWdbeQModMdl1NGeneric WHERE qref = $1", 1);
	createStatement("TblWdbeQModMdl1NGeneric_loadRstByJref", "SELECT qref, jref, jnum, ref, mdlNum FROM TblWdbeQModMdl1NGeneric WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQModMdl1NGeneric::loadRec(
			PGresult* res
			, WdbeQModMdl1NGeneric** rec
		) {
	char* ptr;

	WdbeQModMdl1NGeneric* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQModMdl1NGeneric();

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

ubigint PgTblWdbeQModMdl1NGeneric::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQModMdl1NGeneric& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQModMdl1NGeneric* rec;

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
			rec = new WdbeQModMdl1NGeneric();

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

bool PgTblWdbeQModMdl1NGeneric::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQModMdl1NGeneric** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModMdl1NGeneric::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModMdl1NGeneric::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQModMdl1NGeneric& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModMdl1NGeneric::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQModMdl1NGeneric::loadRecBySQL(
			const string& sqlstr
			, WdbeQModMdl1NGeneric** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModMdl1NGeneric::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModMdl1NGeneric::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModMdl1NGeneric& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModMdl1NGeneric::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQModMdl1NGeneric::insertRec(
			WdbeQModMdl1NGeneric* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQModMdl1NGeneric_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModMdl1NGeneric::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQModMdl1NGeneric::insertRst(
			ListWdbeQModMdl1NGeneric& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQModMdl1NGeneric::updateRec(
			WdbeQModMdl1NGeneric* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQModMdl1NGeneric_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModMdl1NGeneric::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModMdl1NGeneric::updateRst(
			ListWdbeQModMdl1NGeneric& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQModMdl1NGeneric::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModMdl1NGeneric_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModMdl1NGeneric::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModMdl1NGeneric::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModMdl1NGeneric_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModMdl1NGeneric::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQModMdl1NGeneric::loadRecByQref(
			ubigint qref
			, WdbeQModMdl1NGeneric** rec
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

	return loadRecByStmt("TblWdbeQModMdl1NGeneric_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQModMdl1NGeneric::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModMdl1NGeneric& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQModMdl1NGeneric_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
