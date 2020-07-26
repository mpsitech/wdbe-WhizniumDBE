/**
	* \file WdbeQErrAPar.cpp
	* Dbs and XML wrapper for table TblWdbeQErrAPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQErrAPar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQErrAPar
 ******************************************************************************/

WdbeQErrAPar::WdbeQErrAPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint errNum
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
	this->errNum = errNum;
	this->sref = sref;
	this->ixWdbeVPartype = ixWdbeVPartype;
	this->srefIxWdbeVPartype = srefIxWdbeVPartype;
	this->titIxWdbeVPartype = titIxWdbeVPartype;
	this->refWdbeMVector = refWdbeMVector;
	this->stubRefWdbeMVector = stubRefWdbeMVector;
	this->Length = Length;
	this->Comment = Comment;
};

void WdbeQErrAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQErrAPar";

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
 class ListWdbeQErrAPar
 ******************************************************************************/

ListWdbeQErrAPar::ListWdbeQErrAPar() {
};

ListWdbeQErrAPar::ListWdbeQErrAPar(
			const ListWdbeQErrAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQErrAPar(*(src.nodes[i]));
};

ListWdbeQErrAPar::~ListWdbeQErrAPar() {
	clear();
};

void ListWdbeQErrAPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQErrAPar::size() const {
	return(nodes.size());
};

void ListWdbeQErrAPar::append(
			WdbeQErrAPar* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQErrAPar& ListWdbeQErrAPar::operator=(
			const ListWdbeQErrAPar& src
		) {
	WdbeQErrAPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQErrAPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQErrAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQErrAPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQErrAPar
 ******************************************************************************/

TblWdbeQErrAPar::TblWdbeQErrAPar() {
};

TblWdbeQErrAPar::~TblWdbeQErrAPar() {
};

bool TblWdbeQErrAPar::loadRecBySQL(
			const string& sqlstr
			, WdbeQErrAPar** rec
		) {
	return false;
};

ubigint TblWdbeQErrAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQErrAPar& rst
		) {
	return 0;
};

ubigint TblWdbeQErrAPar::insertRec(
			WdbeQErrAPar* rec
		) {
	return 0;
};

ubigint TblWdbeQErrAPar::insertNewRec(
			WdbeQErrAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint errNum
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
	WdbeQErrAPar* _rec = NULL;

	_rec = new WdbeQErrAPar(0, jref, jnum, ref, errNum, sref, ixWdbeVPartype, srefIxWdbeVPartype, titIxWdbeVPartype, refWdbeMVector, stubRefWdbeMVector, Length, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQErrAPar::appendNewRecToRst(
			ListWdbeQErrAPar& rst
			, WdbeQErrAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint errNum
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
	WdbeQErrAPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, errNum, sref, ixWdbeVPartype, srefIxWdbeVPartype, titIxWdbeVPartype, refWdbeMVector, stubRefWdbeMVector, Length, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQErrAPar::insertRst(
			ListWdbeQErrAPar& rst
		) {
};

void TblWdbeQErrAPar::updateRec(
			WdbeQErrAPar* rec
		) {
};

void TblWdbeQErrAPar::updateRst(
			ListWdbeQErrAPar& rst
		) {
};

void TblWdbeQErrAPar::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQErrAPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQErrAPar::loadRecByQref(
			ubigint qref
			, WdbeQErrAPar** rec
		) {
	return false;
};

ubigint TblWdbeQErrAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQErrAPar& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQErrAPar
 ******************************************************************************/

MyTblWdbeQErrAPar::MyTblWdbeQErrAPar() :
			TblWdbeQErrAPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQErrAPar::~MyTblWdbeQErrAPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQErrAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQErrAPar (jref, jnum, ref, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQErrAPar SET jref = ?, jnum = ?, ref = ?, errNum = ?, sref = ?, ixWdbeVPartype = ?, refWdbeMVector = ?, Length = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQErrAPar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQErrAPar WHERE jref = ?", false);
};

bool MyTblWdbeQErrAPar::loadRecBySQL(
			const string& sqlstr
			, WdbeQErrAPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQErrAPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQErrAPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQErrAPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQErrAPar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->errNum = atol((char*) dbrow[4]); else _rec->errNum = 0;
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

ubigint MyTblWdbeQErrAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQErrAPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQErrAPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQErrAPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQErrAPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQErrAPar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->errNum = atol((char*) dbrow[4]); else rec->errNum = 0;
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

ubigint MyTblWdbeQErrAPar::insertRec(
			WdbeQErrAPar* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->errNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWdbeVPartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWdbeMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUtinyint(&rec->Length,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQErrAPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQErrAPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQErrAPar::insertRst(
			ListWdbeQErrAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQErrAPar::updateRec(
			WdbeQErrAPar* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->errNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWdbeVPartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWdbeMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUtinyint(&rec->Length,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQErrAPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQErrAPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQErrAPar::updateRst(
			ListWdbeQErrAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQErrAPar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQErrAPar::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQErrAPar::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQErrAPar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQErrAPar::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQErrAPar::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQErrAPar::loadRecByQref(
			ubigint qref
			, WdbeQErrAPar** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQErrAPar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQErrAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQErrAPar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQErrAPar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQErrAPar
 ******************************************************************************/

PgTblWdbeQErrAPar::PgTblWdbeQErrAPar() :
			TblWdbeQErrAPar()
			, PgTable()
		{
};

PgTblWdbeQErrAPar::~PgTblWdbeQErrAPar() {
};

void PgTblWdbeQErrAPar::initStatements() {
	createStatement("TblWdbeQErrAPar_insertRec", "INSERT INTO TblWdbeQErrAPar (jref, jnum, ref, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblWdbeQErrAPar_updateRec", "UPDATE TblWdbeQErrAPar SET jref = $1, jnum = $2, ref = $3, errNum = $4, sref = $5, ixWdbeVPartype = $6, refWdbeMVector = $7, Length = $8, Comment = $9 WHERE qref = $10", 10);
	createStatement("TblWdbeQErrAPar_removeRecByQref", "DELETE FROM TblWdbeQErrAPar WHERE qref = $1", 1);
	createStatement("TblWdbeQErrAPar_removeRstByJref", "DELETE FROM TblWdbeQErrAPar WHERE jref = $1", 1);

	createStatement("TblWdbeQErrAPar_loadRecByQref", "SELECT qref, jref, jnum, ref, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment FROM TblWdbeQErrAPar WHERE qref = $1", 1);
	createStatement("TblWdbeQErrAPar_loadRstByJref", "SELECT qref, jref, jnum, ref, errNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Comment FROM TblWdbeQErrAPar WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQErrAPar::loadRec(
			PGresult* res
			, WdbeQErrAPar** rec
		) {
	char* ptr;

	WdbeQErrAPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQErrAPar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "errnum"),
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
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->errNum = atol(ptr);
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

ubigint PgTblWdbeQErrAPar::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQErrAPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQErrAPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "errnum"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixwdbevpartype"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "length"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeQErrAPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->errNum = atol(ptr);
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

bool PgTblWdbeQErrAPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQErrAPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQErrAPar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQErrAPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQErrAPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQErrAPar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQErrAPar::loadRecBySQL(
			const string& sqlstr
			, WdbeQErrAPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQErrAPar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQErrAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQErrAPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQErrAPar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQErrAPar::insertRec(
			WdbeQErrAPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _errNum = htonl(rec->errNum);
	uint _ixWdbeVPartype = htonl(rec->ixWdbeVPartype);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	usmallint _Length = htons(rec->Length);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_errNum,
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

	res = PQexecPrepared(dbs, "TblWdbeQErrAPar_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQErrAPar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQErrAPar::insertRst(
			ListWdbeQErrAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQErrAPar::updateRec(
			WdbeQErrAPar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _errNum = htonl(rec->errNum);
	uint _ixWdbeVPartype = htonl(rec->ixWdbeVPartype);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	usmallint _Length = htons(rec->Length);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_errNum,
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

	res = PQexecPrepared(dbs, "TblWdbeQErrAPar_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQErrAPar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQErrAPar::updateRst(
			ListWdbeQErrAPar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQErrAPar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQErrAPar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQErrAPar::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQErrAPar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQErrAPar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQErrAPar::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQErrAPar::loadRecByQref(
			ubigint qref
			, WdbeQErrAPar** rec
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

	return loadRecByStmt("TblWdbeQErrAPar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQErrAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQErrAPar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQErrAPar_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

