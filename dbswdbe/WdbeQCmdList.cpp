/**
	* \file WdbeQCmdList.cpp
	* Dbs and XML wrapper for table TblWdbeQCmdList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQCmdList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCmdList
 ******************************************************************************/

WdbeQCmdList::WdbeQCmdList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Fullsref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint ixVRettype
			, const string srefIxVRettype
			, const string titIxVRettype
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Fullsref = Fullsref;
	this->refIxVTbl = refIxVTbl;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->refUref = refUref;
	this->stubRefUref = stubRefUref;
	this->ixVRettype = ixVRettype;
	this->srefIxVRettype = srefIxVRettype;
	this->titIxVRettype = titIxVRettype;
};

void WdbeQCmdList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQCmdList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "fsr", Fullsref);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeString(wr, "rty", srefIxVRettype);
		writeString(wr, "rty2", titIxVRettype);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Fullsref", Fullsref);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeString(wr, "srefIxVRettype", srefIxVRettype);
		writeString(wr, "titIxVRettype", titIxVRettype);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQCmdList
 ******************************************************************************/

ListWdbeQCmdList::ListWdbeQCmdList() {
};

ListWdbeQCmdList::ListWdbeQCmdList(
			const ListWdbeQCmdList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdList(*(src.nodes[i]));
};

ListWdbeQCmdList::~ListWdbeQCmdList() {
	clear();
};

void ListWdbeQCmdList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQCmdList::size() const {
	return(nodes.size());
};

void ListWdbeQCmdList::append(
			WdbeQCmdList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQCmdList& ListWdbeQCmdList::operator=(
			const ListWdbeQCmdList& src
		) {
	WdbeQCmdList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQCmdList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQCmdList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQCmdList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQCmdList
 ******************************************************************************/

TblWdbeQCmdList::TblWdbeQCmdList() {
};

TblWdbeQCmdList::~TblWdbeQCmdList() {
};

bool TblWdbeQCmdList::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdList** rec
		) {
	return false;
};

ubigint TblWdbeQCmdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdList& rst
		) {
	return 0;
};

ubigint TblWdbeQCmdList::insertRec(
			WdbeQCmdList* rec
		) {
	return 0;
};

ubigint TblWdbeQCmdList::insertNewRec(
			WdbeQCmdList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Fullsref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint ixVRettype
			, const string srefIxVRettype
			, const string titIxVRettype
		) {
	ubigint retval = 0;
	WdbeQCmdList* _rec = NULL;

	_rec = new WdbeQCmdList(0, jref, jnum, ref, sref, Fullsref, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, ixVRettype, srefIxVRettype, titIxVRettype);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQCmdList::appendNewRecToRst(
			ListWdbeQCmdList& rst
			, WdbeQCmdList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Fullsref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const uint ixVRettype
			, const string srefIxVRettype
			, const string titIxVRettype
		) {
	ubigint retval = 0;
	WdbeQCmdList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Fullsref, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, ixVRettype, srefIxVRettype, titIxVRettype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQCmdList::insertRst(
			ListWdbeQCmdList& rst
		) {
};

void TblWdbeQCmdList::updateRec(
			WdbeQCmdList* rec
		) {
};

void TblWdbeQCmdList::updateRst(
			ListWdbeQCmdList& rst
		) {
};

void TblWdbeQCmdList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQCmdList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQCmdList::loadRecByQref(
			ubigint qref
			, WdbeQCmdList** rec
		) {
	return false;
};

ubigint TblWdbeQCmdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQCmdList
 ******************************************************************************/

MyTblWdbeQCmdList::MyTblWdbeQCmdList() :
			TblWdbeQCmdList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQCmdList::~MyTblWdbeQCmdList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQCmdList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQCmdList (jref, jnum, ref, sref, Fullsref, refIxVTbl, refUref, ixVRettype) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQCmdList SET jref = ?, jnum = ?, ref = ?, sref = ?, Fullsref = ?, refIxVTbl = ?, refUref = ?, ixVRettype = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQCmdList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQCmdList WHERE jref = ?", false);
};

bool MyTblWdbeQCmdList::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQCmdList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCmdList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCmdList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQCmdList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Fullsref.assign(dbrow[5], dblengths[5]); else _rec->Fullsref = "";
		if (dbrow[6]) _rec->refIxVTbl = atol((char*) dbrow[6]); else _rec->refIxVTbl = 0;
		if (dbrow[7]) _rec->refUref = atoll((char*) dbrow[7]); else _rec->refUref = 0;
		if (dbrow[8]) _rec->ixVRettype = atol((char*) dbrow[8]); else _rec->ixVRettype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQCmdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQCmdList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCmdList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCmdList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQCmdList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Fullsref.assign(dbrow[5], dblengths[5]); else rec->Fullsref = "";
			if (dbrow[6]) rec->refIxVTbl = atol((char*) dbrow[6]); else rec->refIxVTbl = 0;
			if (dbrow[7]) rec->refUref = atoll((char*) dbrow[7]); else rec->refUref = 0;
			if (dbrow[8]) rec->ixVRettype = atol((char*) dbrow[8]); else rec->ixVRettype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQCmdList::insertRec(
			WdbeQCmdList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Fullsref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->refIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVRettype,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQCmdList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQCmdList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQCmdList::insertRst(
			ListWdbeQCmdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQCmdList::updateRec(
			WdbeQCmdList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[4] = rec->Fullsref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->refIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVRettype,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQCmdList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQCmdList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCmdList::updateRst(
			ListWdbeQCmdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQCmdList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQCmdList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQCmdList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCmdList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQCmdList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQCmdList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQCmdList::loadRecByQref(
			ubigint qref
			, WdbeQCmdList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQCmdList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQCmdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQCmdList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQCmdList
 ******************************************************************************/

PgTblWdbeQCmdList::PgTblWdbeQCmdList() :
			TblWdbeQCmdList()
			, PgTable()
		{
};

PgTblWdbeQCmdList::~PgTblWdbeQCmdList() {
};

void PgTblWdbeQCmdList::initStatements() {
	createStatement("TblWdbeQCmdList_insertRec", "INSERT INTO TblWdbeQCmdList (jref, jnum, ref, sref, Fullsref, refIxVTbl, refUref, ixVRettype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8);
	createStatement("TblWdbeQCmdList_updateRec", "UPDATE TblWdbeQCmdList SET jref = $1, jnum = $2, ref = $3, sref = $4, Fullsref = $5, refIxVTbl = $6, refUref = $7, ixVRettype = $8 WHERE qref = $9", 9);
	createStatement("TblWdbeQCmdList_removeRecByQref", "DELETE FROM TblWdbeQCmdList WHERE qref = $1", 1);
	createStatement("TblWdbeQCmdList_removeRstByJref", "DELETE FROM TblWdbeQCmdList WHERE jref = $1", 1);

	createStatement("TblWdbeQCmdList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Fullsref, refIxVTbl, refUref, ixVRettype FROM TblWdbeQCmdList WHERE qref = $1", 1);
	createStatement("TblWdbeQCmdList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Fullsref, refIxVTbl, refUref, ixVRettype FROM TblWdbeQCmdList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQCmdList::loadRec(
			PGresult* res
			, WdbeQCmdList** rec
		) {
	char* ptr;

	WdbeQCmdList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQCmdList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "ixvrettype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fullsref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVRettype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQCmdList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQCmdList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQCmdList* rec;

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
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "ixvrettype")
		};

		while (numread < numrow) {
			rec = new WdbeQCmdList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fullsref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVRettype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQCmdList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQCmdList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCmdList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQCmdList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQCmdList::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCmdList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCmdList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCmdList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQCmdList::insertRec(
			WdbeQCmdList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _ixVRettype = htonl(rec->ixVRettype);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Fullsref.c_str(),
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_ixVRettype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQCmdList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQCmdList::insertRst(
			ListWdbeQCmdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQCmdList::updateRec(
			WdbeQCmdList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _ixVRettype = htonl(rec->ixVRettype);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Fullsref.c_str(),
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_ixVRettype,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQCmdList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCmdList::updateRst(
			ListWdbeQCmdList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQCmdList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCmdList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCmdList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCmdList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQCmdList::loadRecByQref(
			ubigint qref
			, WdbeQCmdList** rec
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

	return loadRecByStmt("TblWdbeQCmdList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQCmdList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQCmdList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

