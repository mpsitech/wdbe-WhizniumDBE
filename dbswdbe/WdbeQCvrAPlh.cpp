/**
	* \file WdbeQCvrAPlh.cpp
	* Dbs and XML wrapper for table TblWdbeQCvrAPlh (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQCvrAPlh.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCvrAPlh
 ******************************************************************************/

WdbeQCvrAPlh::WdbeQCvrAPlh(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cvrNum
			, const string sref
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->cvrNum = cvrNum;
	this->sref = sref;
	this->Comment = Comment;
};

void WdbeQCvrAPlh::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["cmt"] = Comment;
	} else {
		me["sref"] = sref;
		me["Comment"] = Comment;
	};
};

void WdbeQCvrAPlh::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQCvrAPlh";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQCvrAPlh
 ******************************************************************************/

ListWdbeQCvrAPlh::ListWdbeQCvrAPlh() {
};

ListWdbeQCvrAPlh::ListWdbeQCvrAPlh(
			const ListWdbeQCvrAPlh& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrAPlh(*(src.nodes[i]));
};

ListWdbeQCvrAPlh::~ListWdbeQCvrAPlh() {
	clear();
};

void ListWdbeQCvrAPlh::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQCvrAPlh::size() const {
	return(nodes.size());
};

void ListWdbeQCvrAPlh::append(
			WdbeQCvrAPlh* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQCvrAPlh& ListWdbeQCvrAPlh::operator=(
			const ListWdbeQCvrAPlh& src
		) {
	WdbeQCvrAPlh* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQCvrAPlh(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQCvrAPlh::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQCvrAPlh";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQCvrAPlh::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQCvrAPlh";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQCvrAPlh
 ******************************************************************************/

TblWdbeQCvrAPlh::TblWdbeQCvrAPlh() {
};

TblWdbeQCvrAPlh::~TblWdbeQCvrAPlh() {
};

bool TblWdbeQCvrAPlh::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrAPlh** rec
		) {
	return false;
};

ubigint TblWdbeQCvrAPlh::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrAPlh& rst
		) {
	return 0;
};

ubigint TblWdbeQCvrAPlh::insertRec(
			WdbeQCvrAPlh* rec
		) {
	return 0;
};

ubigint TblWdbeQCvrAPlh::insertNewRec(
			WdbeQCvrAPlh** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cvrNum
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeQCvrAPlh* _rec = NULL;

	_rec = new WdbeQCvrAPlh(0, jref, jnum, ref, cvrNum, sref, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQCvrAPlh::appendNewRecToRst(
			ListWdbeQCvrAPlh& rst
			, WdbeQCvrAPlh** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cvrNum
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeQCvrAPlh* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, cvrNum, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQCvrAPlh::insertRst(
			ListWdbeQCvrAPlh& rst
		) {
};

void TblWdbeQCvrAPlh::updateRec(
			WdbeQCvrAPlh* rec
		) {
};

void TblWdbeQCvrAPlh::updateRst(
			ListWdbeQCvrAPlh& rst
		) {
};

void TblWdbeQCvrAPlh::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQCvrAPlh::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQCvrAPlh::loadRecByQref(
			ubigint qref
			, WdbeQCvrAPlh** rec
		) {
	return false;
};

ubigint TblWdbeQCvrAPlh::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrAPlh& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQCvrAPlh
 ******************************************************************************/

MyTblWdbeQCvrAPlh::MyTblWdbeQCvrAPlh() :
			TblWdbeQCvrAPlh()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQCvrAPlh::~MyTblWdbeQCvrAPlh() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQCvrAPlh::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQCvrAPlh (jref, jnum, ref, cvrNum, sref, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQCvrAPlh SET jref = ?, jnum = ?, ref = ?, cvrNum = ?, sref = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQCvrAPlh WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQCvrAPlh WHERE jref = ?", false);
};

bool MyTblWdbeQCvrAPlh::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrAPlh** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQCvrAPlh* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCvrAPlh::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCvrAPlh::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQCvrAPlh();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->cvrNum = atol((char*) dbrow[4]); else _rec->cvrNum = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQCvrAPlh::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrAPlh& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQCvrAPlh* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCvrAPlh::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCvrAPlh::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQCvrAPlh();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->cvrNum = atol((char*) dbrow[4]); else rec->cvrNum = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQCvrAPlh::insertRec(
			WdbeQCvrAPlh* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->sref.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->cvrNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQCvrAPlh::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQCvrAPlh::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQCvrAPlh::insertRst(
			ListWdbeQCvrAPlh& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQCvrAPlh::updateRec(
			WdbeQCvrAPlh* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->sref.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->cvrNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQCvrAPlh::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQCvrAPlh::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCvrAPlh::updateRst(
			ListWdbeQCvrAPlh& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQCvrAPlh::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQCvrAPlh::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQCvrAPlh::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCvrAPlh::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQCvrAPlh::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQCvrAPlh::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQCvrAPlh::loadRecByQref(
			ubigint qref
			, WdbeQCvrAPlh** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQCvrAPlh WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQCvrAPlh::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrAPlh& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQCvrAPlh WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQCvrAPlh
 ******************************************************************************/

PgTblWdbeQCvrAPlh::PgTblWdbeQCvrAPlh() :
			TblWdbeQCvrAPlh()
			, PgTable()
		{
};

PgTblWdbeQCvrAPlh::~PgTblWdbeQCvrAPlh() {
};

void PgTblWdbeQCvrAPlh::initStatements() {
	createStatement("TblWdbeQCvrAPlh_insertRec", "INSERT INTO TblWdbeQCvrAPlh (jref, jnum, ref, cvrNum, sref, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWdbeQCvrAPlh_updateRec", "UPDATE TblWdbeQCvrAPlh SET jref = $1, jnum = $2, ref = $3, cvrNum = $4, sref = $5, Comment = $6 WHERE qref = $7", 7);
	createStatement("TblWdbeQCvrAPlh_removeRecByQref", "DELETE FROM TblWdbeQCvrAPlh WHERE qref = $1", 1);
	createStatement("TblWdbeQCvrAPlh_removeRstByJref", "DELETE FROM TblWdbeQCvrAPlh WHERE jref = $1", 1);

	createStatement("TblWdbeQCvrAPlh_loadRecByQref", "SELECT qref, jref, jnum, ref, cvrNum, sref, Comment FROM TblWdbeQCvrAPlh WHERE qref = $1", 1);
	createStatement("TblWdbeQCvrAPlh_loadRstByJref", "SELECT qref, jref, jnum, ref, cvrNum, sref, Comment FROM TblWdbeQCvrAPlh WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQCvrAPlh::loadRec(
			PGresult* res
			, WdbeQCvrAPlh** rec
		) {
	char* ptr;

	WdbeQCvrAPlh* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQCvrAPlh();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "cvrnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->cvrNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQCvrAPlh::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQCvrAPlh& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQCvrAPlh* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "cvrnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeQCvrAPlh();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->cvrNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQCvrAPlh::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQCvrAPlh** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrAPlh::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCvrAPlh::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQCvrAPlh& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrAPlh::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQCvrAPlh::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrAPlh** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCvrAPlh::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCvrAPlh::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrAPlh& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCvrAPlh::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQCvrAPlh::insertRec(
			WdbeQCvrAPlh* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _cvrNum = htonl(rec->cvrNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_cvrNum,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeQCvrAPlh_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrAPlh::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQCvrAPlh::insertRst(
			ListWdbeQCvrAPlh& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQCvrAPlh::updateRec(
			WdbeQCvrAPlh* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _cvrNum = htonl(rec->cvrNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_cvrNum,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQCvrAPlh_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrAPlh::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCvrAPlh::updateRst(
			ListWdbeQCvrAPlh& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQCvrAPlh::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCvrAPlh_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrAPlh::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCvrAPlh::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCvrAPlh_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrAPlh::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQCvrAPlh::loadRecByQref(
			ubigint qref
			, WdbeQCvrAPlh** rec
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

	return loadRecByStmt("TblWdbeQCvrAPlh_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQCvrAPlh::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrAPlh& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQCvrAPlh_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
