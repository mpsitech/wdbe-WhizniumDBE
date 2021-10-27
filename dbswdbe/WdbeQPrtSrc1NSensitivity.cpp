/**
	* \file WdbeQPrtSrc1NSensitivity.cpp
	* Dbs and XML wrapper for table TblWdbeQPrtSrc1NSensitivity (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQPrtSrc1NSensitivity.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrtSrc1NSensitivity
 ******************************************************************************/

WdbeQPrtSrc1NSensitivity::WdbeQPrtSrc1NSensitivity(
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

void WdbeQPrtSrc1NSensitivity::writeJSON(
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

void WdbeQPrtSrc1NSensitivity::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQPrtSrc1NSensitivity";

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
 class ListWdbeQPrtSrc1NSensitivity
 ******************************************************************************/

ListWdbeQPrtSrc1NSensitivity::ListWdbeQPrtSrc1NSensitivity() {
};

ListWdbeQPrtSrc1NSensitivity::ListWdbeQPrtSrc1NSensitivity(
			const ListWdbeQPrtSrc1NSensitivity& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrtSrc1NSensitivity(*(src.nodes[i]));
};

ListWdbeQPrtSrc1NSensitivity::~ListWdbeQPrtSrc1NSensitivity() {
	clear();
};

void ListWdbeQPrtSrc1NSensitivity::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQPrtSrc1NSensitivity::size() const {
	return(nodes.size());
};

void ListWdbeQPrtSrc1NSensitivity::append(
			WdbeQPrtSrc1NSensitivity* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQPrtSrc1NSensitivity& ListWdbeQPrtSrc1NSensitivity::operator=(
			const ListWdbeQPrtSrc1NSensitivity& src
		) {
	WdbeQPrtSrc1NSensitivity* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQPrtSrc1NSensitivity(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQPrtSrc1NSensitivity::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQPrtSrc1NSensitivity";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQPrtSrc1NSensitivity::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQPrtSrc1NSensitivity";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQPrtSrc1NSensitivity
 ******************************************************************************/

TblWdbeQPrtSrc1NSensitivity::TblWdbeQPrtSrc1NSensitivity() {
};

TblWdbeQPrtSrc1NSensitivity::~TblWdbeQPrtSrc1NSensitivity() {
};

bool TblWdbeQPrtSrc1NSensitivity::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrtSrc1NSensitivity** rec
		) {
	return false;
};

ubigint TblWdbeQPrtSrc1NSensitivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrtSrc1NSensitivity& rst
		) {
	return 0;
};

ubigint TblWdbeQPrtSrc1NSensitivity::insertRec(
			WdbeQPrtSrc1NSensitivity* rec
		) {
	return 0;
};

ubigint TblWdbeQPrtSrc1NSensitivity::insertNewRec(
			WdbeQPrtSrc1NSensitivity** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQPrtSrc1NSensitivity* _rec = NULL;

	_rec = new WdbeQPrtSrc1NSensitivity(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQPrtSrc1NSensitivity::appendNewRecToRst(
			ListWdbeQPrtSrc1NSensitivity& rst
			, WdbeQPrtSrc1NSensitivity** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQPrtSrc1NSensitivity* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQPrtSrc1NSensitivity::insertRst(
			ListWdbeQPrtSrc1NSensitivity& rst
		) {
};

void TblWdbeQPrtSrc1NSensitivity::updateRec(
			WdbeQPrtSrc1NSensitivity* rec
		) {
};

void TblWdbeQPrtSrc1NSensitivity::updateRst(
			ListWdbeQPrtSrc1NSensitivity& rst
		) {
};

void TblWdbeQPrtSrc1NSensitivity::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQPrtSrc1NSensitivity::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQPrtSrc1NSensitivity::loadRecByQref(
			ubigint qref
			, WdbeQPrtSrc1NSensitivity** rec
		) {
	return false;
};

ubigint TblWdbeQPrtSrc1NSensitivity::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrtSrc1NSensitivity& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQPrtSrc1NSensitivity
 ******************************************************************************/

MyTblWdbeQPrtSrc1NSensitivity::MyTblWdbeQPrtSrc1NSensitivity() :
			TblWdbeQPrtSrc1NSensitivity()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQPrtSrc1NSensitivity::~MyTblWdbeQPrtSrc1NSensitivity() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQPrtSrc1NSensitivity::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQPrtSrc1NSensitivity (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQPrtSrc1NSensitivity SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQPrtSrc1NSensitivity WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQPrtSrc1NSensitivity WHERE jref = ?", false);
};

bool MyTblWdbeQPrtSrc1NSensitivity::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrtSrc1NSensitivity** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQPrtSrc1NSensitivity* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQPrtSrc1NSensitivity();

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

ubigint MyTblWdbeQPrtSrc1NSensitivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrtSrc1NSensitivity& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQPrtSrc1NSensitivity* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQPrtSrc1NSensitivity();

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

ubigint MyTblWdbeQPrtSrc1NSensitivity::insertRec(
			WdbeQPrtSrc1NSensitivity* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQPrtSrc1NSensitivity::insertRst(
			ListWdbeQPrtSrc1NSensitivity& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQPrtSrc1NSensitivity::updateRec(
			WdbeQPrtSrc1NSensitivity* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrtSrc1NSensitivity::updateRst(
			ListWdbeQPrtSrc1NSensitivity& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQPrtSrc1NSensitivity::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrtSrc1NSensitivity::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQPrtSrc1NSensitivity::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQPrtSrc1NSensitivity::loadRecByQref(
			ubigint qref
			, WdbeQPrtSrc1NSensitivity** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQPrtSrc1NSensitivity WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQPrtSrc1NSensitivity::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrtSrc1NSensitivity& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQPrtSrc1NSensitivity WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQPrtSrc1NSensitivity
 ******************************************************************************/

PgTblWdbeQPrtSrc1NSensitivity::PgTblWdbeQPrtSrc1NSensitivity() :
			TblWdbeQPrtSrc1NSensitivity()
			, PgTable()
		{
};

PgTblWdbeQPrtSrc1NSensitivity::~PgTblWdbeQPrtSrc1NSensitivity() {
};

void PgTblWdbeQPrtSrc1NSensitivity::initStatements() {
	createStatement("TblWdbeQPrtSrc1NSensitivity_insertRec", "INSERT INTO TblWdbeQPrtSrc1NSensitivity (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWdbeQPrtSrc1NSensitivity_updateRec", "UPDATE TblWdbeQPrtSrc1NSensitivity SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWdbeQPrtSrc1NSensitivity_removeRecByQref", "DELETE FROM TblWdbeQPrtSrc1NSensitivity WHERE qref = $1", 1);
	createStatement("TblWdbeQPrtSrc1NSensitivity_removeRstByJref", "DELETE FROM TblWdbeQPrtSrc1NSensitivity WHERE jref = $1", 1);

	createStatement("TblWdbeQPrtSrc1NSensitivity_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWdbeQPrtSrc1NSensitivity WHERE qref = $1", 1);
	createStatement("TblWdbeQPrtSrc1NSensitivity_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWdbeQPrtSrc1NSensitivity WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQPrtSrc1NSensitivity::loadRec(
			PGresult* res
			, WdbeQPrtSrc1NSensitivity** rec
		) {
	char* ptr;

	WdbeQPrtSrc1NSensitivity* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQPrtSrc1NSensitivity();

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

ubigint PgTblWdbeQPrtSrc1NSensitivity::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQPrtSrc1NSensitivity& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQPrtSrc1NSensitivity* rec;

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
			rec = new WdbeQPrtSrc1NSensitivity();

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

bool PgTblWdbeQPrtSrc1NSensitivity::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQPrtSrc1NSensitivity** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrtSrc1NSensitivity::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrtSrc1NSensitivity::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQPrtSrc1NSensitivity& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrtSrc1NSensitivity::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQPrtSrc1NSensitivity::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrtSrc1NSensitivity** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrtSrc1NSensitivity::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrtSrc1NSensitivity::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrtSrc1NSensitivity& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrtSrc1NSensitivity::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQPrtSrc1NSensitivity::insertRec(
			WdbeQPrtSrc1NSensitivity* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQPrtSrc1NSensitivity_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrtSrc1NSensitivity::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQPrtSrc1NSensitivity::insertRst(
			ListWdbeQPrtSrc1NSensitivity& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQPrtSrc1NSensitivity::updateRec(
			WdbeQPrtSrc1NSensitivity* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQPrtSrc1NSensitivity_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrtSrc1NSensitivity::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrtSrc1NSensitivity::updateRst(
			ListWdbeQPrtSrc1NSensitivity& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQPrtSrc1NSensitivity::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrtSrc1NSensitivity_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrtSrc1NSensitivity::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrtSrc1NSensitivity::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrtSrc1NSensitivity_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrtSrc1NSensitivity::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQPrtSrc1NSensitivity::loadRecByQref(
			ubigint qref
			, WdbeQPrtSrc1NSensitivity** rec
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

	return loadRecByStmt("TblWdbeQPrtSrc1NSensitivity_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQPrtSrc1NSensitivity::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrtSrc1NSensitivity& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQPrtSrc1NSensitivity_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
