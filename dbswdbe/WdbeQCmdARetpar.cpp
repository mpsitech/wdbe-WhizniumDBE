/**
	* \file WdbeQCmdARetpar.cpp
	* Dbs and XML wrapper for table TblWdbeQCmdARetpar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQCmdARetpar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCmdARetpar
 ******************************************************************************/

WdbeQCmdARetpar::WdbeQCmdARetpar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cmdNum
			, const string sref
			, const uint ixWdbeVPartype
			, const string srefIxWdbeVPartype
			, const string titIxWdbeVPartype
			, const ubigint refWdbeMVector
			, const string stubRefWdbeMVector
			, const utinyint Length
			, const string Comment
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->cmdNum = cmdNum;
	this->sref = sref;
	this->ixWdbeVPartype = ixWdbeVPartype;
	this->srefIxWdbeVPartype = srefIxWdbeVPartype;
	this->titIxWdbeVPartype = titIxWdbeVPartype;
	this->refWdbeMVector = refWdbeMVector;
	this->stubRefWdbeMVector = stubRefWdbeMVector;
	this->Length = Length;
	this->Comment = Comment;
};

void WdbeQCmdARetpar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQCmdARetpar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "pty", srefIxWdbeVPartype);
		writeString(wr, "pty2", titIxWdbeVPartype);
		writeString(wr, "vec", stubRefWdbeMVector);
		writeUint(wr, "len", Length);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxWdbeVPartype", srefIxWdbeVPartype);
		writeString(wr, "titIxWdbeVPartype", titIxWdbeVPartype);
		writeString(wr, "stubRefWdbeMVector", stubRefWdbeMVector);
		writeUint(wr, "Length", Length);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQCmdARetpar
 ******************************************************************************/

ListWdbeQCmdARetpar::ListWdbeQCmdARetpar() {
};

ListWdbeQCmdARetpar::ListWdbeQCmdARetpar(
			const ListWdbeQCmdARetpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdARetpar(*(src.nodes[i]));
};

ListWdbeQCmdARetpar::~ListWdbeQCmdARetpar() {
	clear();
};

void ListWdbeQCmdARetpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQCmdARetpar::size() const {
	return(nodes.size());
};

void ListWdbeQCmdARetpar::append(
			WdbeQCmdARetpar* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQCmdARetpar& ListWdbeQCmdARetpar::operator=(
			const ListWdbeQCmdARetpar& src
		) {
	WdbeQCmdARetpar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQCmdARetpar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQCmdARetpar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQCmdARetpar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQCmdARetpar
 ******************************************************************************/

TblWdbeQCmdARetpar::TblWdbeQCmdARetpar() {
};

TblWdbeQCmdARetpar::~TblWdbeQCmdARetpar() {
};

bool TblWdbeQCmdARetpar::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdARetpar** rec
		) {
	return false;
};

ubigint TblWdbeQCmdARetpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdARetpar& rst
		) {
	return 0;
};

ubigint TblWdbeQCmdARetpar::insertRec(
			WdbeQCmdARetpar* rec
		) {
	return 0;
};

ubigint TblWdbeQCmdARetpar::insertNewRec(
			WdbeQCmdARetpar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cmdNum
			, const string sref
			, const uint ixWdbeVPartype
			, const string srefIxWdbeVPartype
			, const string titIxWdbeVPartype
			, const ubigint refWdbeMVector
			, const string stubRefWdbeMVector
			, const utinyint Length
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeQCmdARetpar* _rec = NULL;

	_rec = new WdbeQCmdARetpar(0, jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, srefIxWdbeVPartype, titIxWdbeVPartype, refWdbeMVector, stubRefWdbeMVector, Length, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQCmdARetpar::appendNewRecToRst(
			ListWdbeQCmdARetpar& rst
			, WdbeQCmdARetpar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint cmdNum
			, const string sref
			, const uint ixWdbeVPartype
			, const string srefIxWdbeVPartype
			, const string titIxWdbeVPartype
			, const ubigint refWdbeMVector
			, const string stubRefWdbeMVector
			, const utinyint Length
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeQCmdARetpar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, srefIxWdbeVPartype, titIxWdbeVPartype, refWdbeMVector, stubRefWdbeMVector, Length, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQCmdARetpar::insertRst(
			ListWdbeQCmdARetpar& rst
		) {
};

void TblWdbeQCmdARetpar::updateRec(
			WdbeQCmdARetpar* rec
		) {
};

void TblWdbeQCmdARetpar::updateRst(
			ListWdbeQCmdARetpar& rst
		) {
};

void TblWdbeQCmdARetpar::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQCmdARetpar::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQCmdARetpar::loadRecByQref(
			ubigint qref
			, WdbeQCmdARetpar** rec
		) {
	return false;
};

ubigint TblWdbeQCmdARetpar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdARetpar& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQCmdARetpar
 ******************************************************************************/

MyTblWdbeQCmdARetpar::MyTblWdbeQCmdARetpar() :
			TblWdbeQCmdARetpar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQCmdARetpar::~MyTblWdbeQCmdARetpar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQCmdARetpar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQCmdARetpar (jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQCmdARetpar SET jref = ?, jnum = ?, ref = ?, cmdNum = ?, sref = ?, ixWdbeVPartype = ?, refWdbeMVector = ?, Length = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQCmdARetpar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQCmdARetpar WHERE jref = ?", false);
};

bool MyTblWdbeQCmdARetpar::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdARetpar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQCmdARetpar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCmdARetpar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCmdARetpar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQCmdARetpar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->cmdNum = atol((char*) dbrow[4]); else _rec->cmdNum = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->ixWdbeVPartype = atol((char*) dbrow[6]); else _rec->ixWdbeVPartype = 0;
		if (dbrow[7]) _rec->refWdbeMVector = atoll((char*) dbrow[7]); else _rec->refWdbeMVector = 0;
		if (dbrow[8]) _rec->Length = atoi((char*) dbrow[8]); else _rec->Length = 0;
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQCmdARetpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdARetpar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQCmdARetpar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCmdARetpar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCmdARetpar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQCmdARetpar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->cmdNum = atol((char*) dbrow[4]); else rec->cmdNum = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->ixWdbeVPartype = atol((char*) dbrow[6]); else rec->ixWdbeVPartype = 0;
			if (dbrow[7]) rec->refWdbeMVector = atoll((char*) dbrow[7]); else rec->refWdbeMVector = 0;
			if (dbrow[8]) rec->Length = atoi((char*) dbrow[8]); else rec->Length = 0;
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQCmdARetpar::insertRec(
			WdbeQCmdARetpar* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->cmdNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWdbeVPartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWdbeMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUtinyint(&rec->Length,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQCmdARetpar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQCmdARetpar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQCmdARetpar::insertRst(
			ListWdbeQCmdARetpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQCmdARetpar::updateRec(
			WdbeQCmdARetpar* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->cmdNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWdbeVPartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWdbeMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUtinyint(&rec->Length,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQCmdARetpar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQCmdARetpar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCmdARetpar::updateRst(
			ListWdbeQCmdARetpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQCmdARetpar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQCmdARetpar::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQCmdARetpar::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCmdARetpar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQCmdARetpar::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQCmdARetpar::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQCmdARetpar::loadRecByQref(
			ubigint qref
			, WdbeQCmdARetpar** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQCmdARetpar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQCmdARetpar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdARetpar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQCmdARetpar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQCmdARetpar
 ******************************************************************************/

PgTblWdbeQCmdARetpar::PgTblWdbeQCmdARetpar() :
			TblWdbeQCmdARetpar()
			, PgTable()
		{
};

PgTblWdbeQCmdARetpar::~PgTblWdbeQCmdARetpar() {
};

void PgTblWdbeQCmdARetpar::initStatements() {
	createStatement("TblWdbeQCmdARetpar_insertRec", "INSERT INTO TblWdbeQCmdARetpar (jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblWdbeQCmdARetpar_updateRec", "UPDATE TblWdbeQCmdARetpar SET jref = $1, jnum = $2, ref = $3, cmdNum = $4, sref = $5, ixWdbeVPartype = $6, refWdbeMVector = $7, Length = $8, Comment = $9 WHERE qref = $10", 10);
	createStatement("TblWdbeQCmdARetpar_removeRecByQref", "DELETE FROM TblWdbeQCmdARetpar WHERE qref = $1", 1);
	createStatement("TblWdbeQCmdARetpar_removeRstByJref", "DELETE FROM TblWdbeQCmdARetpar WHERE jref = $1", 1);

	createStatement("TblWdbeQCmdARetpar_loadRecByQref", "SELECT qref, jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment FROM TblWdbeQCmdARetpar WHERE qref = $1", 1);
	createStatement("TblWdbeQCmdARetpar_loadRstByJref", "SELECT qref, jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment FROM TblWdbeQCmdARetpar WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQCmdARetpar::loadRec(
			PGresult* res
			, WdbeQCmdARetpar** rec
		) {
	char* ptr;

	WdbeQCmdARetpar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQCmdARetpar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "cmdnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwdbevpartype"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->cmdNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWdbeVPartype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWdbeMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Length = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQCmdARetpar::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQCmdARetpar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQCmdARetpar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "cmdnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwdbevpartype"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeQCmdARetpar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->cmdNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWdbeVPartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWdbeMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Length = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQCmdARetpar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQCmdARetpar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdARetpar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCmdARetpar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQCmdARetpar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdARetpar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQCmdARetpar::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdARetpar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCmdARetpar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCmdARetpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdARetpar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCmdARetpar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQCmdARetpar::insertRec(
			WdbeQCmdARetpar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _cmdNum = htonl(rec->cmdNum);
	uint _ixWdbeVPartype = htonl(rec->ixWdbeVPartype);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	usmallint _Length = htons(rec->Length);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_cmdNum,
		rec->sref.c_str(),
		(char*) &_ixWdbeVPartype,
		(char*) &_refWdbeMVector,
		(char*) &_Length,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQCmdARetpar_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdARetpar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQCmdARetpar::insertRst(
			ListWdbeQCmdARetpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQCmdARetpar::updateRec(
			WdbeQCmdARetpar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _cmdNum = htonl(rec->cmdNum);
	uint _ixWdbeVPartype = htonl(rec->ixWdbeVPartype);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	usmallint _Length = htons(rec->Length);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_cmdNum,
		rec->sref.c_str(),
		(char*) &_ixWdbeVPartype,
		(char*) &_refWdbeMVector,
		(char*) &_Length,
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
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQCmdARetpar_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdARetpar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCmdARetpar::updateRst(
			ListWdbeQCmdARetpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQCmdARetpar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCmdARetpar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdARetpar::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCmdARetpar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCmdARetpar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdARetpar::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQCmdARetpar::loadRecByQref(
			ubigint qref
			, WdbeQCmdARetpar** rec
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

	return loadRecByStmt("TblWdbeQCmdARetpar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQCmdARetpar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdARetpar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQCmdARetpar_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

