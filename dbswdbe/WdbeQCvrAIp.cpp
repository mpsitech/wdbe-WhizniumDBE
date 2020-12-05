/**
	* \file WdbeQCvrAIp.cpp
	* Dbs and XML wrapper for table TblWdbeQCvrAIp (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQCvrAIp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCvrAIp
 ******************************************************************************/

WdbeQCvrAIp::WdbeQCvrAIp(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cvrNum
			, const string sref
			, const uint ixVTagtype
			, const string srefIxVTagtype
			, const string titIxVTagtype
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->cvrNum = cvrNum;
	this->sref = sref;
	this->ixVTagtype = ixVTagtype;
	this->srefIxVTagtype = srefIxVTagtype;
	this->titIxVTagtype = titIxVTagtype;
	this->Comment = Comment;
};

void WdbeQCvrAIp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQCvrAIp";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tty", srefIxVTagtype);
		writeString(wr, "tty2", titIxVTagtype);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVTagtype", srefIxVTagtype);
		writeString(wr, "titIxVTagtype", titIxVTagtype);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQCvrAIp
 ******************************************************************************/

ListWdbeQCvrAIp::ListWdbeQCvrAIp() {
};

ListWdbeQCvrAIp::ListWdbeQCvrAIp(
			const ListWdbeQCvrAIp& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrAIp(*(src.nodes[i]));
};

ListWdbeQCvrAIp::~ListWdbeQCvrAIp() {
	clear();
};

void ListWdbeQCvrAIp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQCvrAIp::size() const {
	return(nodes.size());
};

void ListWdbeQCvrAIp::append(
			WdbeQCvrAIp* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQCvrAIp& ListWdbeQCvrAIp::operator=(
			const ListWdbeQCvrAIp& src
		) {
	WdbeQCvrAIp* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQCvrAIp(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQCvrAIp::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQCvrAIp";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQCvrAIp
 ******************************************************************************/

TblWdbeQCvrAIp::TblWdbeQCvrAIp() {
};

TblWdbeQCvrAIp::~TblWdbeQCvrAIp() {
};

bool TblWdbeQCvrAIp::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrAIp** rec
		) {
	return false;
};

ubigint TblWdbeQCvrAIp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrAIp& rst
		) {
	return 0;
};

ubigint TblWdbeQCvrAIp::insertRec(
			WdbeQCvrAIp* rec
		) {
	return 0;
};

ubigint TblWdbeQCvrAIp::insertNewRec(
			WdbeQCvrAIp** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cvrNum
			, const string sref
			, const uint ixVTagtype
			, const string srefIxVTagtype
			, const string titIxVTagtype
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeQCvrAIp* _rec = NULL;

	_rec = new WdbeQCvrAIp(0, jref, jnum, ref, cvrNum, sref, ixVTagtype, srefIxVTagtype, titIxVTagtype, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQCvrAIp::appendNewRecToRst(
			ListWdbeQCvrAIp& rst
			, WdbeQCvrAIp** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cvrNum
			, const string sref
			, const uint ixVTagtype
			, const string srefIxVTagtype
			, const string titIxVTagtype
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeQCvrAIp* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, cvrNum, sref, ixVTagtype, srefIxVTagtype, titIxVTagtype, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQCvrAIp::insertRst(
			ListWdbeQCvrAIp& rst
		) {
};

void TblWdbeQCvrAIp::updateRec(
			WdbeQCvrAIp* rec
		) {
};

void TblWdbeQCvrAIp::updateRst(
			ListWdbeQCvrAIp& rst
		) {
};

void TblWdbeQCvrAIp::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQCvrAIp::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQCvrAIp::loadRecByQref(
			ubigint qref
			, WdbeQCvrAIp** rec
		) {
	return false;
};

ubigint TblWdbeQCvrAIp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrAIp& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQCvrAIp
 ******************************************************************************/

MyTblWdbeQCvrAIp::MyTblWdbeQCvrAIp() :
			TblWdbeQCvrAIp()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQCvrAIp::~MyTblWdbeQCvrAIp() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQCvrAIp::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQCvrAIp (jref, jnum, ref, cvrNum, sref, ixVTagtype, Comment) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQCvrAIp SET jref = ?, jnum = ?, ref = ?, cvrNum = ?, sref = ?, ixVTagtype = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQCvrAIp WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQCvrAIp WHERE jref = ?", false);
};

bool MyTblWdbeQCvrAIp::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrAIp** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQCvrAIp* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCvrAIp::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCvrAIp::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQCvrAIp();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->cvrNum = atol((char*) dbrow[4]); else _rec->cvrNum = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->ixVTagtype = atol((char*) dbrow[6]); else _rec->ixVTagtype = 0;
		if (dbrow[7]) _rec->Comment.assign(dbrow[7], dblengths[7]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQCvrAIp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrAIp& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQCvrAIp* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCvrAIp::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCvrAIp::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQCvrAIp();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->cvrNum = atol((char*) dbrow[4]); else rec->cvrNum = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->ixVTagtype = atol((char*) dbrow[6]); else rec->ixVTagtype = 0;
			if (dbrow[7]) rec->Comment.assign(dbrow[7], dblengths[7]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQCvrAIp::insertRec(
			WdbeQCvrAIp* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->cvrNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVTagtype,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQCvrAIp::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQCvrAIp::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQCvrAIp::insertRst(
			ListWdbeQCvrAIp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQCvrAIp::updateRec(
			WdbeQCvrAIp* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->sref.length();
	l[6] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->cvrNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVTagtype,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQCvrAIp::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQCvrAIp::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCvrAIp::updateRst(
			ListWdbeQCvrAIp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQCvrAIp::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQCvrAIp::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQCvrAIp::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCvrAIp::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQCvrAIp::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQCvrAIp::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQCvrAIp::loadRecByQref(
			ubigint qref
			, WdbeQCvrAIp** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQCvrAIp WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQCvrAIp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrAIp& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQCvrAIp WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQCvrAIp
 ******************************************************************************/

PgTblWdbeQCvrAIp::PgTblWdbeQCvrAIp() :
			TblWdbeQCvrAIp()
			, PgTable()
		{
};

PgTblWdbeQCvrAIp::~PgTblWdbeQCvrAIp() {
};

void PgTblWdbeQCvrAIp::initStatements() {
	createStatement("TblWdbeQCvrAIp_insertRec", "INSERT INTO TblWdbeQCvrAIp (jref, jnum, ref, cvrNum, sref, ixVTagtype, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWdbeQCvrAIp_updateRec", "UPDATE TblWdbeQCvrAIp SET jref = $1, jnum = $2, ref = $3, cvrNum = $4, sref = $5, ixVTagtype = $6, Comment = $7 WHERE qref = $8", 8);
	createStatement("TblWdbeQCvrAIp_removeRecByQref", "DELETE FROM TblWdbeQCvrAIp WHERE qref = $1", 1);
	createStatement("TblWdbeQCvrAIp_removeRstByJref", "DELETE FROM TblWdbeQCvrAIp WHERE jref = $1", 1);

	createStatement("TblWdbeQCvrAIp_loadRecByQref", "SELECT qref, jref, jnum, ref, cvrNum, sref, ixVTagtype, Comment FROM TblWdbeQCvrAIp WHERE qref = $1", 1);
	createStatement("TblWdbeQCvrAIp_loadRstByJref", "SELECT qref, jref, jnum, ref, cvrNum, sref, ixVTagtype, Comment FROM TblWdbeQCvrAIp WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQCvrAIp::loadRec(
			PGresult* res
			, WdbeQCvrAIp** rec
		) {
	char* ptr;

	WdbeQCvrAIp* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQCvrAIp();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "cvrnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvtagtype"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->cvrNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVTagtype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQCvrAIp::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQCvrAIp& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQCvrAIp* rec;

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
			PQfnumber(res, "ixvtagtype"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeQCvrAIp();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->cvrNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVTagtype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQCvrAIp::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQCvrAIp** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrAIp::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCvrAIp::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQCvrAIp& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrAIp::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQCvrAIp::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrAIp** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCvrAIp::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCvrAIp::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrAIp& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCvrAIp::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQCvrAIp::insertRec(
			WdbeQCvrAIp* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _cvrNum = htonl(rec->cvrNum);
	uint _ixVTagtype = htonl(rec->ixVTagtype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_cvrNum,
		rec->sref.c_str(),
		(char*) &_ixVTagtype,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQCvrAIp_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrAIp::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQCvrAIp::insertRst(
			ListWdbeQCvrAIp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQCvrAIp::updateRec(
			WdbeQCvrAIp* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _cvrNum = htonl(rec->cvrNum);
	uint _ixVTagtype = htonl(rec->ixVTagtype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_cvrNum,
		rec->sref.c_str(),
		(char*) &_ixVTagtype,
		rec->Comment.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQCvrAIp_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrAIp::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCvrAIp::updateRst(
			ListWdbeQCvrAIp& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQCvrAIp::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCvrAIp_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrAIp::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCvrAIp::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCvrAIp_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrAIp::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQCvrAIp::loadRecByQref(
			ubigint qref
			, WdbeQCvrAIp** rec
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

	return loadRecByStmt("TblWdbeQCvrAIp_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQCvrAIp::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrAIp& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQCvrAIp_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

