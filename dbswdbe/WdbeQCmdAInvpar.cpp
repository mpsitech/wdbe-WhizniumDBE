/**
	* \file WdbeQCmdAInvpar.cpp
	* Dbs and XML wrapper for table TblWdbeQCmdAInvpar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQCmdAInvpar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCmdAInvpar
 ******************************************************************************/

WdbeQCmdAInvpar::WdbeQCmdAInvpar(
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
			, const string Defval
			, const ubigint refWdbeMVectoritem
			, const string stubRefWdbeMVectoritem
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
	this->Defval = Defval;
	this->refWdbeMVectoritem = refWdbeMVectoritem;
	this->stubRefWdbeMVectoritem = stubRefWdbeMVectoritem;
	this->Comment = Comment;
};

void WdbeQCmdAInvpar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQCmdAInvpar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "pty", srefIxWdbeVPartype);
		writeString(wr, "pty2", titIxWdbeVPartype);
		writeString(wr, "vec", stubRefWdbeMVector);
		writeUint(wr, "len", Length);
		writeString(wr, "dfv", Defval);
		writeString(wr, "vit", stubRefWdbeMVectoritem);
		writeString(wr, "cmt", Comment);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxWdbeVPartype", srefIxWdbeVPartype);
		writeString(wr, "titIxWdbeVPartype", titIxWdbeVPartype);
		writeString(wr, "stubRefWdbeMVector", stubRefWdbeMVector);
		writeUint(wr, "Length", Length);
		writeString(wr, "Defval", Defval);
		writeString(wr, "stubRefWdbeMVectoritem", stubRefWdbeMVectoritem);
		writeString(wr, "Comment", Comment);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQCmdAInvpar
 ******************************************************************************/

ListWdbeQCmdAInvpar::ListWdbeQCmdAInvpar() {
};

ListWdbeQCmdAInvpar::ListWdbeQCmdAInvpar(
			const ListWdbeQCmdAInvpar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdAInvpar(*(src.nodes[i]));
};

ListWdbeQCmdAInvpar::~ListWdbeQCmdAInvpar() {
	clear();
};

void ListWdbeQCmdAInvpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQCmdAInvpar::size() const {
	return(nodes.size());
};

void ListWdbeQCmdAInvpar::append(
			WdbeQCmdAInvpar* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQCmdAInvpar& ListWdbeQCmdAInvpar::operator=(
			const ListWdbeQCmdAInvpar& src
		) {
	WdbeQCmdAInvpar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQCmdAInvpar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQCmdAInvpar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQCmdAInvpar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQCmdAInvpar
 ******************************************************************************/

TblWdbeQCmdAInvpar::TblWdbeQCmdAInvpar() {
};

TblWdbeQCmdAInvpar::~TblWdbeQCmdAInvpar() {
};

bool TblWdbeQCmdAInvpar::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdAInvpar** rec
		) {
	return false;
};

ubigint TblWdbeQCmdAInvpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdAInvpar& rst
		) {
	return 0;
};

ubigint TblWdbeQCmdAInvpar::insertRec(
			WdbeQCmdAInvpar* rec
		) {
	return 0;
};

ubigint TblWdbeQCmdAInvpar::insertNewRec(
			WdbeQCmdAInvpar** rec
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
			, const string Defval
			, const ubigint refWdbeMVectoritem
			, const string stubRefWdbeMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeQCmdAInvpar* _rec = NULL;

	_rec = new WdbeQCmdAInvpar(0, jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, srefIxWdbeVPartype, titIxWdbeVPartype, refWdbeMVector, stubRefWdbeMVector, Length, Defval, refWdbeMVectoritem, stubRefWdbeMVectoritem, Comment);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQCmdAInvpar::appendNewRecToRst(
			ListWdbeQCmdAInvpar& rst
			, WdbeQCmdAInvpar** rec
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
			, const string Defval
			, const ubigint refWdbeMVectoritem
			, const string stubRefWdbeMVectoritem
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeQCmdAInvpar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, srefIxWdbeVPartype, titIxWdbeVPartype, refWdbeMVector, stubRefWdbeMVector, Length, Defval, refWdbeMVectoritem, stubRefWdbeMVectoritem, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQCmdAInvpar::insertRst(
			ListWdbeQCmdAInvpar& rst
		) {
};

void TblWdbeQCmdAInvpar::updateRec(
			WdbeQCmdAInvpar* rec
		) {
};

void TblWdbeQCmdAInvpar::updateRst(
			ListWdbeQCmdAInvpar& rst
		) {
};

void TblWdbeQCmdAInvpar::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQCmdAInvpar::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQCmdAInvpar::loadRecByQref(
			ubigint qref
			, WdbeQCmdAInvpar** rec
		) {
	return false;
};

ubigint TblWdbeQCmdAInvpar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdAInvpar& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQCmdAInvpar
 ******************************************************************************/

MyTblWdbeQCmdAInvpar::MyTblWdbeQCmdAInvpar() :
			TblWdbeQCmdAInvpar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQCmdAInvpar::~MyTblWdbeQCmdAInvpar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQCmdAInvpar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQCmdAInvpar (jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQCmdAInvpar SET jref = ?, jnum = ?, ref = ?, cmdNum = ?, sref = ?, ixWdbeVPartype = ?, refWdbeMVector = ?, Length = ?, Defval = ?, refWdbeMVectoritem = ?, Comment = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQCmdAInvpar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQCmdAInvpar WHERE jref = ?", false);
};

bool MyTblWdbeQCmdAInvpar::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdAInvpar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQCmdAInvpar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCmdAInvpar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCmdAInvpar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQCmdAInvpar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->cmdNum = atol((char*) dbrow[4]); else _rec->cmdNum = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->ixWdbeVPartype = atol((char*) dbrow[6]); else _rec->ixWdbeVPartype = 0;
		if (dbrow[7]) _rec->refWdbeMVector = atoll((char*) dbrow[7]); else _rec->refWdbeMVector = 0;
		if (dbrow[8]) _rec->Length = atoi((char*) dbrow[8]); else _rec->Length = 0;
		if (dbrow[9]) _rec->Defval.assign(dbrow[9], dblengths[9]); else _rec->Defval = "";
		if (dbrow[10]) _rec->refWdbeMVectoritem = atoll((char*) dbrow[10]); else _rec->refWdbeMVectoritem = 0;
		if (dbrow[11]) _rec->Comment.assign(dbrow[11], dblengths[11]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQCmdAInvpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdAInvpar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQCmdAInvpar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCmdAInvpar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCmdAInvpar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQCmdAInvpar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->cmdNum = atol((char*) dbrow[4]); else rec->cmdNum = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->ixWdbeVPartype = atol((char*) dbrow[6]); else rec->ixWdbeVPartype = 0;
			if (dbrow[7]) rec->refWdbeMVector = atoll((char*) dbrow[7]); else rec->refWdbeMVector = 0;
			if (dbrow[8]) rec->Length = atoi((char*) dbrow[8]); else rec->Length = 0;
			if (dbrow[9]) rec->Defval.assign(dbrow[9], dblengths[9]); else rec->Defval = "";
			if (dbrow[10]) rec->refWdbeMVectoritem = atoll((char*) dbrow[10]); else rec->refWdbeMVectoritem = 0;
			if (dbrow[11]) rec->Comment.assign(dbrow[11], dblengths[11]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQCmdAInvpar::insertRec(
			WdbeQCmdAInvpar* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[4] = rec->sref.length();
	l[8] = rec->Defval.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->cmdNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWdbeVPartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWdbeMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUtinyint(&rec->Length,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWdbeMVectoritem,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQCmdAInvpar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQCmdAInvpar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQCmdAInvpar::insertRst(
			ListWdbeQCmdAInvpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQCmdAInvpar::updateRec(
			WdbeQCmdAInvpar* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[4] = rec->sref.length();
	l[8] = rec->Defval.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->cmdNum,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWdbeVPartype,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWdbeMVector,&(l[6]),&(n[6]),&(e[6])),
		bindUtinyint(&rec->Length,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWdbeMVectoritem,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQCmdAInvpar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQCmdAInvpar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCmdAInvpar::updateRst(
			ListWdbeQCmdAInvpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQCmdAInvpar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQCmdAInvpar::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQCmdAInvpar::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCmdAInvpar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQCmdAInvpar::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQCmdAInvpar::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQCmdAInvpar::loadRecByQref(
			ubigint qref
			, WdbeQCmdAInvpar** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQCmdAInvpar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQCmdAInvpar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdAInvpar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQCmdAInvpar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQCmdAInvpar
 ******************************************************************************/

PgTblWdbeQCmdAInvpar::PgTblWdbeQCmdAInvpar() :
			TblWdbeQCmdAInvpar()
			, PgTable()
		{
};

PgTblWdbeQCmdAInvpar::~PgTblWdbeQCmdAInvpar() {
};

void PgTblWdbeQCmdAInvpar::initStatements() {
	createStatement("TblWdbeQCmdAInvpar_insertRec", "INSERT INTO TblWdbeQCmdAInvpar (jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblWdbeQCmdAInvpar_updateRec", "UPDATE TblWdbeQCmdAInvpar SET jref = $1, jnum = $2, ref = $3, cmdNum = $4, sref = $5, ixWdbeVPartype = $6, refWdbeMVector = $7, Length = $8, Defval = $9, refWdbeMVectoritem = $10, Comment = $11 WHERE qref = $12", 12);
	createStatement("TblWdbeQCmdAInvpar_removeRecByQref", "DELETE FROM TblWdbeQCmdAInvpar WHERE qref = $1", 1);
	createStatement("TblWdbeQCmdAInvpar_removeRstByJref", "DELETE FROM TblWdbeQCmdAInvpar WHERE jref = $1", 1);

	createStatement("TblWdbeQCmdAInvpar_loadRecByQref", "SELECT qref, jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment FROM TblWdbeQCmdAInvpar WHERE qref = $1", 1);
	createStatement("TblWdbeQCmdAInvpar_loadRstByJref", "SELECT qref, jref, jnum, ref, cmdNum, sref, ixWdbeVPartype, refWdbeMVector, Length, Defval, refWdbeMVectoritem, Comment FROM TblWdbeQCmdAInvpar WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQCmdAInvpar::loadRec(
			PGresult* res
			, WdbeQCmdAInvpar** rec
		) {
	char* ptr;

	WdbeQCmdAInvpar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQCmdAInvpar();

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
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwdbemvectoritem"),
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
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Defval.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refWdbeMVectoritem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQCmdAInvpar::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQCmdAInvpar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQCmdAInvpar* rec;

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
			PQfnumber(res, "defval"),
			PQfnumber(res, "refwdbemvectoritem"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeQCmdAInvpar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->cmdNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWdbeVPartype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWdbeMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Length = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Defval.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refWdbeMVectoritem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQCmdAInvpar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQCmdAInvpar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdAInvpar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCmdAInvpar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQCmdAInvpar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdAInvpar::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQCmdAInvpar::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdAInvpar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCmdAInvpar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCmdAInvpar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdAInvpar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCmdAInvpar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQCmdAInvpar::insertRec(
			WdbeQCmdAInvpar* rec
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
	ubigint _refWdbeMVectoritem = htonl64(rec->refWdbeMVectoritem);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_cmdNum,
		rec->sref.c_str(),
		(char*) &_ixWdbeVPartype,
		(char*) &_refWdbeMVector,
		(char*) &_Length,
		rec->Defval.c_str(),
		(char*) &_refWdbeMVectoritem,
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
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQCmdAInvpar_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdAInvpar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQCmdAInvpar::insertRst(
			ListWdbeQCmdAInvpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQCmdAInvpar::updateRec(
			WdbeQCmdAInvpar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _cmdNum = htonl(rec->cmdNum);
	uint _ixWdbeVPartype = htonl(rec->ixWdbeVPartype);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	usmallint _Length = htons(rec->Length);
	ubigint _refWdbeMVectoritem = htonl64(rec->refWdbeMVectoritem);
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
		rec->Defval.c_str(),
		(char*) &_refWdbeMVectoritem,
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
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQCmdAInvpar_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdAInvpar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCmdAInvpar::updateRst(
			ListWdbeQCmdAInvpar& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQCmdAInvpar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCmdAInvpar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdAInvpar::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCmdAInvpar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCmdAInvpar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdAInvpar::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQCmdAInvpar::loadRecByQref(
			ubigint qref
			, WdbeQCmdAInvpar** rec
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

	return loadRecByStmt("TblWdbeQCmdAInvpar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQCmdAInvpar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdAInvpar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQCmdAInvpar_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

