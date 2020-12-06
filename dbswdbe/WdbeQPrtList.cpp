/**
	* \file WdbeQPrtList.cpp
	* Dbs and XML wrapper for table TblWdbeQPrtList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQPrtList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrtList
 ******************************************************************************/

WdbeQPrtList::WdbeQPrtList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint mdlRefWdbeMModule
			, const string stubMdlRefWdbeMModule
			, const uint mdlIxVCat
			, const string srefMdlIxVCat
			, const string titMdlIxVCat
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->mdlRefWdbeMModule = mdlRefWdbeMModule;
	this->stubMdlRefWdbeMModule = stubMdlRefWdbeMModule;
	this->mdlIxVCat = mdlIxVCat;
	this->srefMdlIxVCat = srefMdlIxVCat;
	this->titMdlIxVCat = titMdlIxVCat;
	this->ixVDir = ixVDir;
	this->srefIxVDir = srefIxVDir;
	this->titIxVDir = titIxVDir;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->titSrefWdbeKHdltype = titSrefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
};

void WdbeQPrtList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQPrtList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "mdl", stubMdlRefWdbeMModule);
		writeString(wr, "mdc", srefMdlIxVCat);
		writeString(wr, "mdc2", titMdlIxVCat);
		writeString(wr, "dir", srefIxVDir);
		writeString(wr, "dir2", titIxVDir);
		writeString(wr, "hty", srefWdbeKHdltype);
		writeString(wr, "hty2", titSrefWdbeKHdltype);
		writeUint(wr, "wid", Width);
		writeString(wr, "mmx", Minmax);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubMdlRefWdbeMModule", stubMdlRefWdbeMModule);
		writeString(wr, "srefMdlIxVCat", srefMdlIxVCat);
		writeString(wr, "titMdlIxVCat", titMdlIxVCat);
		writeString(wr, "srefIxVDir", srefIxVDir);
		writeString(wr, "titIxVDir", titIxVDir);
		writeString(wr, "srefWdbeKHdltype", srefWdbeKHdltype);
		writeString(wr, "titSrefWdbeKHdltype", titSrefWdbeKHdltype);
		writeUint(wr, "Width", Width);
		writeString(wr, "Minmax", Minmax);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQPrtList
 ******************************************************************************/

ListWdbeQPrtList::ListWdbeQPrtList() {
};

ListWdbeQPrtList::ListWdbeQPrtList(
			const ListWdbeQPrtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrtList(*(src.nodes[i]));
};

ListWdbeQPrtList::~ListWdbeQPrtList() {
	clear();
};

void ListWdbeQPrtList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQPrtList::size() const {
	return(nodes.size());
};

void ListWdbeQPrtList::append(
			WdbeQPrtList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQPrtList& ListWdbeQPrtList::operator=(
			const ListWdbeQPrtList& src
		) {
	WdbeQPrtList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQPrtList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQPrtList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQPrtList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQPrtList
 ******************************************************************************/

TblWdbeQPrtList::TblWdbeQPrtList() {
};

TblWdbeQPrtList::~TblWdbeQPrtList() {
};

bool TblWdbeQPrtList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrtList** rec
		) {
	return false;
};

ubigint TblWdbeQPrtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrtList& rst
		) {
	return 0;
};

ubigint TblWdbeQPrtList::insertRec(
			WdbeQPrtList* rec
		) {
	return 0;
};

ubigint TblWdbeQPrtList::insertNewRec(
			WdbeQPrtList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint mdlRefWdbeMModule
			, const string stubMdlRefWdbeMModule
			, const uint mdlIxVCat
			, const string srefMdlIxVCat
			, const string titMdlIxVCat
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	ubigint retval = 0;
	WdbeQPrtList* _rec = NULL;

	_rec = new WdbeQPrtList(0, jref, jnum, ref, sref, mdlRefWdbeMModule, stubMdlRefWdbeMModule, mdlIxVCat, srefMdlIxVCat, titMdlIxVCat, ixVDir, srefIxVDir, titIxVDir, srefWdbeKHdltype, titSrefWdbeKHdltype, Width, Minmax);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQPrtList::appendNewRecToRst(
			ListWdbeQPrtList& rst
			, WdbeQPrtList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint mdlRefWdbeMModule
			, const string stubMdlRefWdbeMModule
			, const uint mdlIxVCat
			, const string srefMdlIxVCat
			, const string titMdlIxVCat
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	ubigint retval = 0;
	WdbeQPrtList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, mdlRefWdbeMModule, stubMdlRefWdbeMModule, mdlIxVCat, srefMdlIxVCat, titMdlIxVCat, ixVDir, srefIxVDir, titIxVDir, srefWdbeKHdltype, titSrefWdbeKHdltype, Width, Minmax);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQPrtList::insertRst(
			ListWdbeQPrtList& rst
		) {
};

void TblWdbeQPrtList::updateRec(
			WdbeQPrtList* rec
		) {
};

void TblWdbeQPrtList::updateRst(
			ListWdbeQPrtList& rst
		) {
};

void TblWdbeQPrtList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQPrtList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQPrtList::loadRecByQref(
			ubigint qref
			, WdbeQPrtList** rec
		) {
	return false;
};

ubigint TblWdbeQPrtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrtList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQPrtList
 ******************************************************************************/

MyTblWdbeQPrtList::MyTblWdbeQPrtList() :
			TblWdbeQPrtList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQPrtList::~MyTblWdbeQPrtList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQPrtList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQPrtList (jref, jnum, ref, sref, mdlRefWdbeMModule, mdlIxVCat, ixVDir, srefWdbeKHdltype, Width, Minmax) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQPrtList SET jref = ?, jnum = ?, ref = ?, sref = ?, mdlRefWdbeMModule = ?, mdlIxVCat = ?, ixVDir = ?, srefWdbeKHdltype = ?, Width = ?, Minmax = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQPrtList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQPrtList WHERE jref = ?", false);
};

bool MyTblWdbeQPrtList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrtList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQPrtList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrtList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrtList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQPrtList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->mdlRefWdbeMModule = atoll((char*) dbrow[5]); else _rec->mdlRefWdbeMModule = 0;
		if (dbrow[6]) _rec->mdlIxVCat = atol((char*) dbrow[6]); else _rec->mdlIxVCat = 0;
		if (dbrow[7]) _rec->ixVDir = atol((char*) dbrow[7]); else _rec->ixVDir = 0;
		if (dbrow[8]) _rec->srefWdbeKHdltype.assign(dbrow[8], dblengths[8]); else _rec->srefWdbeKHdltype = "";
		if (dbrow[9]) _rec->Width = atoi((char*) dbrow[9]); else _rec->Width = 0;
		if (dbrow[10]) _rec->Minmax.assign(dbrow[10], dblengths[10]); else _rec->Minmax = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQPrtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrtList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQPrtList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrtList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrtList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQPrtList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->mdlRefWdbeMModule = atoll((char*) dbrow[5]); else rec->mdlRefWdbeMModule = 0;
			if (dbrow[6]) rec->mdlIxVCat = atol((char*) dbrow[6]); else rec->mdlIxVCat = 0;
			if (dbrow[7]) rec->ixVDir = atol((char*) dbrow[7]); else rec->ixVDir = 0;
			if (dbrow[8]) rec->srefWdbeKHdltype.assign(dbrow[8], dblengths[8]); else rec->srefWdbeKHdltype = "";
			if (dbrow[9]) rec->Width = atoi((char*) dbrow[9]); else rec->Width = 0;
			if (dbrow[10]) rec->Minmax.assign(dbrow[10], dblengths[10]); else rec->Minmax = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQPrtList::insertRec(
			WdbeQPrtList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	l[7] = rec->srefWdbeKHdltype.length();
	l[9] = rec->Minmax.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->mdlIxVCat,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVDir,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Width,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQPrtList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQPrtList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQPrtList::insertRst(
			ListWdbeQPrtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQPrtList::updateRec(
			WdbeQPrtList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->sref.length();
	l[7] = rec->srefWdbeKHdltype.length();
	l[9] = rec->Minmax.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->mdlIxVCat,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVDir,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Width,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQPrtList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQPrtList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrtList::updateRst(
			ListWdbeQPrtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQPrtList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQPrtList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQPrtList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrtList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQPrtList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQPrtList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQPrtList::loadRecByQref(
			ubigint qref
			, WdbeQPrtList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQPrtList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQPrtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrtList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQPrtList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQPrtList
 ******************************************************************************/

PgTblWdbeQPrtList::PgTblWdbeQPrtList() :
			TblWdbeQPrtList()
			, PgTable()
		{
};

PgTblWdbeQPrtList::~PgTblWdbeQPrtList() {
};

void PgTblWdbeQPrtList::initStatements() {
	createStatement("TblWdbeQPrtList_insertRec", "INSERT INTO TblWdbeQPrtList (jref, jnum, ref, sref, mdlRefWdbeMModule, mdlIxVCat, ixVDir, srefWdbeKHdltype, Width, Minmax) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWdbeQPrtList_updateRec", "UPDATE TblWdbeQPrtList SET jref = $1, jnum = $2, ref = $3, sref = $4, mdlRefWdbeMModule = $5, mdlIxVCat = $6, ixVDir = $7, srefWdbeKHdltype = $8, Width = $9, Minmax = $10 WHERE qref = $11", 11);
	createStatement("TblWdbeQPrtList_removeRecByQref", "DELETE FROM TblWdbeQPrtList WHERE qref = $1", 1);
	createStatement("TblWdbeQPrtList_removeRstByJref", "DELETE FROM TblWdbeQPrtList WHERE jref = $1", 1);

	createStatement("TblWdbeQPrtList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, mdlRefWdbeMModule, mdlIxVCat, ixVDir, srefWdbeKHdltype, Width, Minmax FROM TblWdbeQPrtList WHERE qref = $1", 1);
	createStatement("TblWdbeQPrtList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, mdlRefWdbeMModule, mdlIxVCat, ixVDir, srefWdbeKHdltype, Width, Minmax FROM TblWdbeQPrtList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQPrtList::loadRec(
			PGresult* res
			, WdbeQPrtList** rec
		) {
	char* ptr;

	WdbeQPrtList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQPrtList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "mdlrefwdbemmodule"),
			PQfnumber(res, "mdlixvcat"),
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->mdlRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->mdlIxVCat = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVDir = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Width = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Minmax.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQPrtList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQPrtList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQPrtList* rec;

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
			PQfnumber(res, "mdlrefwdbemmodule"),
			PQfnumber(res, "mdlixvcat"),
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax")
		};

		while (numread < numrow) {
			rec = new WdbeQPrtList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->mdlRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->mdlIxVCat = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVDir = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Width = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Minmax.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQPrtList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQPrtList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrtList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrtList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQPrtList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrtList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQPrtList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrtList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrtList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrtList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrtList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrtList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQPrtList::insertRec(
			WdbeQPrtList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	uint _mdlIxVCat = htonl(rec->mdlIxVCat);
	uint _ixVDir = htonl(rec->ixVDir);
	usmallint _Width = htons(rec->Width);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_mdlRefWdbeMModule,
		(char*) &_mdlIxVCat,
		(char*) &_ixVDir,
		rec->srefWdbeKHdltype.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQPrtList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrtList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQPrtList::insertRst(
			ListWdbeQPrtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQPrtList::updateRec(
			WdbeQPrtList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	uint _mdlIxVCat = htonl(rec->mdlIxVCat);
	uint _ixVDir = htonl(rec->ixVDir);
	usmallint _Width = htons(rec->Width);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_mdlRefWdbeMModule,
		(char*) &_mdlIxVCat,
		(char*) &_ixVDir,
		rec->srefWdbeKHdltype.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQPrtList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrtList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrtList::updateRst(
			ListWdbeQPrtList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQPrtList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrtList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrtList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrtList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrtList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrtList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQPrtList::loadRecByQref(
			ubigint qref
			, WdbeQPrtList** rec
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

	return loadRecByStmt("TblWdbeQPrtList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQPrtList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrtList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQPrtList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
