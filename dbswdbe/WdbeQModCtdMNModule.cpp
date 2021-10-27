/**
	* \file WdbeQModCtdMNModule.cpp
	* Dbs and XML wrapper for table TblWdbeQModCtdMNModule (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 Oct 2021
  */
// IP header --- ABOVE

#include "WdbeQModCtdMNModule.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModCtdMNModule
 ******************************************************************************/

WdbeQModCtdMNModule::WdbeQModCtdMNModule(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->srefKFunction = srefKFunction;
	this->titSrefKFunction = titSrefKFunction;
};

void WdbeQModCtdMNModule::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
		me["fct"] = srefKFunction;
		me["fct2"] = titSrefKFunction;
	} else {
		me["stubMref"] = stubMref;
		me["srefKFunction"] = srefKFunction;
		me["titSrefKFunction"] = titSrefKFunction;
	};
};

void WdbeQModCtdMNModule::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQModCtdMNModule";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "fct", srefKFunction);
		writeString(wr, "fct2", titSrefKFunction);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefKFunction", srefKFunction);
		writeString(wr, "titSrefKFunction", titSrefKFunction);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQModCtdMNModule
 ******************************************************************************/

ListWdbeQModCtdMNModule::ListWdbeQModCtdMNModule() {
};

ListWdbeQModCtdMNModule::ListWdbeQModCtdMNModule(
			const ListWdbeQModCtdMNModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCtdMNModule(*(src.nodes[i]));
};

ListWdbeQModCtdMNModule::~ListWdbeQModCtdMNModule() {
	clear();
};

void ListWdbeQModCtdMNModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQModCtdMNModule::size() const {
	return(nodes.size());
};

void ListWdbeQModCtdMNModule::append(
			WdbeQModCtdMNModule* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQModCtdMNModule& ListWdbeQModCtdMNModule::operator=(
			const ListWdbeQModCtdMNModule& src
		) {
	WdbeQModCtdMNModule* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQModCtdMNModule(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQModCtdMNModule::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQModCtdMNModule";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQModCtdMNModule::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQModCtdMNModule";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQModCtdMNModule
 ******************************************************************************/

TblWdbeQModCtdMNModule::TblWdbeQModCtdMNModule() {
};

TblWdbeQModCtdMNModule::~TblWdbeQModCtdMNModule() {
};

bool TblWdbeQModCtdMNModule::loadRecBySQL(
			const string& sqlstr
			, WdbeQModCtdMNModule** rec
		) {
	return false;
};

ubigint TblWdbeQModCtdMNModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModCtdMNModule& rst
		) {
	return 0;
};

ubigint TblWdbeQModCtdMNModule::insertRec(
			WdbeQModCtdMNModule* rec
		) {
	return 0;
};

ubigint TblWdbeQModCtdMNModule::insertNewRec(
			WdbeQModCtdMNModule** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	ubigint retval = 0;
	WdbeQModCtdMNModule* _rec = NULL;

	_rec = new WdbeQModCtdMNModule(0, jref, jnum, mref, stubMref, ref, srefKFunction, titSrefKFunction);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQModCtdMNModule::appendNewRecToRst(
			ListWdbeQModCtdMNModule& rst
			, WdbeQModCtdMNModule** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	ubigint retval = 0;
	WdbeQModCtdMNModule* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, srefKFunction, titSrefKFunction);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQModCtdMNModule::insertRst(
			ListWdbeQModCtdMNModule& rst
		) {
};

void TblWdbeQModCtdMNModule::updateRec(
			WdbeQModCtdMNModule* rec
		) {
};

void TblWdbeQModCtdMNModule::updateRst(
			ListWdbeQModCtdMNModule& rst
		) {
};

void TblWdbeQModCtdMNModule::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQModCtdMNModule::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQModCtdMNModule::loadRecByQref(
			ubigint qref
			, WdbeQModCtdMNModule** rec
		) {
	return false;
};

ubigint TblWdbeQModCtdMNModule::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModCtdMNModule& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQModCtdMNModule
 ******************************************************************************/

MyTblWdbeQModCtdMNModule::MyTblWdbeQModCtdMNModule() :
			TblWdbeQModCtdMNModule()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQModCtdMNModule::~MyTblWdbeQModCtdMNModule() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQModCtdMNModule::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQModCtdMNModule (jref, jnum, mref, ref, srefKFunction) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQModCtdMNModule SET jref = ?, jnum = ?, mref = ?, ref = ?, srefKFunction = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQModCtdMNModule WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQModCtdMNModule WHERE jref = ?", false);
};

bool MyTblWdbeQModCtdMNModule::loadRecBySQL(
			const string& sqlstr
			, WdbeQModCtdMNModule** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQModCtdMNModule* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModCtdMNModule::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModCtdMNModule::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQModCtdMNModule();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->srefKFunction.assign(dbrow[5], dblengths[5]); else _rec->srefKFunction = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQModCtdMNModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModCtdMNModule& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQModCtdMNModule* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModCtdMNModule::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModCtdMNModule::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQModCtdMNModule();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->srefKFunction.assign(dbrow[5], dblengths[5]); else rec->srefKFunction = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQModCtdMNModule::insertRec(
			WdbeQModCtdMNModule* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[4] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQModCtdMNModule::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQModCtdMNModule::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQModCtdMNModule::insertRst(
			ListWdbeQModCtdMNModule& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQModCtdMNModule::updateRec(
			WdbeQModCtdMNModule* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQModCtdMNModule::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQModCtdMNModule::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModCtdMNModule::updateRst(
			ListWdbeQModCtdMNModule& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQModCtdMNModule::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQModCtdMNModule::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQModCtdMNModule::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModCtdMNModule::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQModCtdMNModule::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQModCtdMNModule::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQModCtdMNModule::loadRecByQref(
			ubigint qref
			, WdbeQModCtdMNModule** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQModCtdMNModule WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQModCtdMNModule::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModCtdMNModule& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQModCtdMNModule WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQModCtdMNModule
 ******************************************************************************/

PgTblWdbeQModCtdMNModule::PgTblWdbeQModCtdMNModule() :
			TblWdbeQModCtdMNModule()
			, PgTable()
		{
};

PgTblWdbeQModCtdMNModule::~PgTblWdbeQModCtdMNModule() {
};

void PgTblWdbeQModCtdMNModule::initStatements() {
	createStatement("TblWdbeQModCtdMNModule_insertRec", "INSERT INTO TblWdbeQModCtdMNModule (jref, jnum, mref, ref, srefKFunction) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5);
	createStatement("TblWdbeQModCtdMNModule_updateRec", "UPDATE TblWdbeQModCtdMNModule SET jref = $1, jnum = $2, mref = $3, ref = $4, srefKFunction = $5 WHERE qref = $6", 6);
	createStatement("TblWdbeQModCtdMNModule_removeRecByQref", "DELETE FROM TblWdbeQModCtdMNModule WHERE qref = $1", 1);
	createStatement("TblWdbeQModCtdMNModule_removeRstByJref", "DELETE FROM TblWdbeQModCtdMNModule WHERE jref = $1", 1);

	createStatement("TblWdbeQModCtdMNModule_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, srefKFunction FROM TblWdbeQModCtdMNModule WHERE qref = $1", 1);
	createStatement("TblWdbeQModCtdMNModule_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, srefKFunction FROM TblWdbeQModCtdMNModule WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQModCtdMNModule::loadRec(
			PGresult* res
			, WdbeQModCtdMNModule** rec
		) {
	char* ptr;

	WdbeQModCtdMNModule* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQModCtdMNModule();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "srefkfunction")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefKFunction.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQModCtdMNModule::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQModCtdMNModule& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQModCtdMNModule* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "srefkfunction")
		};

		while (numread < numrow) {
			rec = new WdbeQModCtdMNModule();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefKFunction.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQModCtdMNModule::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQModCtdMNModule** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModCtdMNModule::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModCtdMNModule::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQModCtdMNModule& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModCtdMNModule::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQModCtdMNModule::loadRecBySQL(
			const string& sqlstr
			, WdbeQModCtdMNModule** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModCtdMNModule::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModCtdMNModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModCtdMNModule& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModCtdMNModule::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQModCtdMNModule::insertRec(
			WdbeQModCtdMNModule* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		rec->srefKFunction.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQModCtdMNModule_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModCtdMNModule::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQModCtdMNModule::insertRst(
			ListWdbeQModCtdMNModule& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQModCtdMNModule::updateRec(
			WdbeQModCtdMNModule* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		rec->srefKFunction.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQModCtdMNModule_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModCtdMNModule::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModCtdMNModule::updateRst(
			ListWdbeQModCtdMNModule& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQModCtdMNModule::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModCtdMNModule_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModCtdMNModule::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModCtdMNModule::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModCtdMNModule_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModCtdMNModule::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQModCtdMNModule::loadRecByQref(
			ubigint qref
			, WdbeQModCtdMNModule** rec
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

	return loadRecByStmt("TblWdbeQModCtdMNModule_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQModCtdMNModule::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModCtdMNModule& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQModCtdMNModule_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
