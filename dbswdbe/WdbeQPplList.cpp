/**
	* \file WdbeQPplList.cpp
	* Dbs and XML wrapper for table TblWdbeQPplList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQPplList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPplList
 ******************************************************************************/

WdbeQPplList::WdbeQPplList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint hsmRefWdbeMModule
			, const string stubHsmRefWdbeMModule
			, const usmallint Depth
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->hsmRefWdbeMModule = hsmRefWdbeMModule;
	this->stubHsmRefWdbeMModule = stubHsmRefWdbeMModule;
	this->Depth = Depth;
};

void WdbeQPplList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["hsm"] = stubHsmRefWdbeMModule;
		me["dpt"] = Depth;
	} else {
		me["sref"] = sref;
		me["stubHsmRefWdbeMModule"] = stubHsmRefWdbeMModule;
		me["Depth"] = Depth;
	};
};

void WdbeQPplList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQPplList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "hsm", stubHsmRefWdbeMModule);
		writeUint(wr, "dpt", Depth);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubHsmRefWdbeMModule", stubHsmRefWdbeMModule);
		writeUint(wr, "Depth", Depth);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQPplList
 ******************************************************************************/

ListWdbeQPplList::ListWdbeQPplList() {
};

ListWdbeQPplList::ListWdbeQPplList(
			const ListWdbeQPplList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPplList(*(src.nodes[i]));
};

ListWdbeQPplList::~ListWdbeQPplList() {
	clear();
};

void ListWdbeQPplList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQPplList::size() const {
	return(nodes.size());
};

void ListWdbeQPplList::append(
			WdbeQPplList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQPplList& ListWdbeQPplList::operator=(
			const ListWdbeQPplList& src
		) {
	WdbeQPplList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQPplList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQPplList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQPplList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQPplList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQPplList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQPplList
 ******************************************************************************/

TblWdbeQPplList::TblWdbeQPplList() {
};

TblWdbeQPplList::~TblWdbeQPplList() {
};

bool TblWdbeQPplList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPplList** rec
		) {
	return false;
};

ubigint TblWdbeQPplList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPplList& rst
		) {
	return 0;
};

ubigint TblWdbeQPplList::insertRec(
			WdbeQPplList* rec
		) {
	return 0;
};

ubigint TblWdbeQPplList::insertNewRec(
			WdbeQPplList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint hsmRefWdbeMModule
			, const string stubHsmRefWdbeMModule
			, const usmallint Depth
		) {
	ubigint retval = 0;
	WdbeQPplList* _rec = NULL;

	_rec = new WdbeQPplList(0, jref, jnum, ref, sref, hsmRefWdbeMModule, stubHsmRefWdbeMModule, Depth);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQPplList::appendNewRecToRst(
			ListWdbeQPplList& rst
			, WdbeQPplList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint hsmRefWdbeMModule
			, const string stubHsmRefWdbeMModule
			, const usmallint Depth
		) {
	ubigint retval = 0;
	WdbeQPplList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, hsmRefWdbeMModule, stubHsmRefWdbeMModule, Depth);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQPplList::insertRst(
			ListWdbeQPplList& rst
		) {
};

void TblWdbeQPplList::updateRec(
			WdbeQPplList* rec
		) {
};

void TblWdbeQPplList::updateRst(
			ListWdbeQPplList& rst
		) {
};

void TblWdbeQPplList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQPplList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQPplList::loadRecByQref(
			ubigint qref
			, WdbeQPplList** rec
		) {
	return false;
};

ubigint TblWdbeQPplList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPplList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQPplList
 ******************************************************************************/

MyTblWdbeQPplList::MyTblWdbeQPplList() :
			TblWdbeQPplList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQPplList::~MyTblWdbeQPplList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQPplList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQPplList (jref, jnum, ref, sref, hsmRefWdbeMModule, Depth) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQPplList SET jref = ?, jnum = ?, ref = ?, sref = ?, hsmRefWdbeMModule = ?, Depth = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQPplList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQPplList WHERE jref = ?", false);
};

bool MyTblWdbeQPplList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPplList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQPplList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPplList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPplList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQPplList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->hsmRefWdbeMModule = atoll((char*) dbrow[5]); else _rec->hsmRefWdbeMModule = 0;
		if (dbrow[6]) _rec->Depth = atoi((char*) dbrow[6]); else _rec->Depth = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQPplList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPplList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQPplList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPplList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPplList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQPplList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->hsmRefWdbeMModule = atoll((char*) dbrow[5]); else rec->hsmRefWdbeMModule = 0;
			if (dbrow[6]) rec->Depth = atoi((char*) dbrow[6]); else rec->Depth = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQPplList::insertRec(
			WdbeQPplList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->hsmRefWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Depth,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQPplList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQPplList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQPplList::insertRst(
			ListWdbeQPplList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQPplList::updateRec(
			WdbeQPplList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->hsmRefWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Depth,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQPplList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQPplList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPplList::updateRst(
			ListWdbeQPplList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQPplList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQPplList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQPplList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPplList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQPplList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQPplList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQPplList::loadRecByQref(
			ubigint qref
			, WdbeQPplList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQPplList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQPplList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPplList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQPplList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQPplList
 ******************************************************************************/

PgTblWdbeQPplList::PgTblWdbeQPplList() :
			TblWdbeQPplList()
			, PgTable()
		{
};

PgTblWdbeQPplList::~PgTblWdbeQPplList() {
};

void PgTblWdbeQPplList::initStatements() {
	createStatement("TblWdbeQPplList_insertRec", "INSERT INTO TblWdbeQPplList (jref, jnum, ref, sref, hsmRefWdbeMModule, Depth) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWdbeQPplList_updateRec", "UPDATE TblWdbeQPplList SET jref = $1, jnum = $2, ref = $3, sref = $4, hsmRefWdbeMModule = $5, Depth = $6 WHERE qref = $7", 7);
	createStatement("TblWdbeQPplList_removeRecByQref", "DELETE FROM TblWdbeQPplList WHERE qref = $1", 1);
	createStatement("TblWdbeQPplList_removeRstByJref", "DELETE FROM TblWdbeQPplList WHERE jref = $1", 1);

	createStatement("TblWdbeQPplList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, hsmRefWdbeMModule, Depth FROM TblWdbeQPplList WHERE qref = $1", 1);
	createStatement("TblWdbeQPplList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, hsmRefWdbeMModule, Depth FROM TblWdbeQPplList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQPplList::loadRec(
			PGresult* res
			, WdbeQPplList** rec
		) {
	char* ptr;

	WdbeQPplList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQPplList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "hsmrefwdbemmodule"),
			PQfnumber(res, "depth")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->hsmRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Depth = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQPplList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQPplList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQPplList* rec;

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
			PQfnumber(res, "hsmrefwdbemmodule"),
			PQfnumber(res, "depth")
		};

		while (numread < numrow) {
			rec = new WdbeQPplList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->hsmRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Depth = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQPplList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQPplList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPplList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPplList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQPplList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPplList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQPplList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPplList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPplList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPplList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPplList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPplList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQPplList::insertRec(
			WdbeQPplList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _hsmRefWdbeMModule = htonl64(rec->hsmRefWdbeMModule);
	usmallint _Depth = htons(rec->Depth);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_hsmRefWdbeMModule,
		(char*) &_Depth
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQPplList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPplList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQPplList::insertRst(
			ListWdbeQPplList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQPplList::updateRec(
			WdbeQPplList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _hsmRefWdbeMModule = htonl64(rec->hsmRefWdbeMModule);
	usmallint _Depth = htons(rec->Depth);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_hsmRefWdbeMModule,
		(char*) &_Depth,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQPplList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPplList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPplList::updateRst(
			ListWdbeQPplList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQPplList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPplList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPplList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPplList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPplList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPplList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQPplList::loadRecByQref(
			ubigint qref
			, WdbeQPplList** rec
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

	return loadRecByStmt("TblWdbeQPplList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQPplList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPplList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQPplList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
