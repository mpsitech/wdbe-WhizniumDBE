/**
	* \file WdbeQGenList.cpp
	* Dbs and XML wrapper for table TblWdbeQGenList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQGenList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQGenList
 ******************************************************************************/

WdbeQGenList::WdbeQGenList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint mdlRefWdbeMModule
			, const string stubMdlRefWdbeMModule
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
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->titSrefWdbeKHdltype = titSrefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
};

void WdbeQGenList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQGenList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "mdl", stubMdlRefWdbeMModule);
		writeString(wr, "hty", srefWdbeKHdltype);
		writeString(wr, "hty2", titSrefWdbeKHdltype);
		writeUint(wr, "wid", Width);
		writeString(wr, "mmx", Minmax);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubMdlRefWdbeMModule", stubMdlRefWdbeMModule);
		writeString(wr, "srefWdbeKHdltype", srefWdbeKHdltype);
		writeString(wr, "titSrefWdbeKHdltype", titSrefWdbeKHdltype);
		writeUint(wr, "Width", Width);
		writeString(wr, "Minmax", Minmax);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQGenList
 ******************************************************************************/

ListWdbeQGenList::ListWdbeQGenList() {
};

ListWdbeQGenList::ListWdbeQGenList(
			const ListWdbeQGenList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQGenList(*(src.nodes[i]));
};

ListWdbeQGenList::~ListWdbeQGenList() {
	clear();
};

void ListWdbeQGenList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQGenList::size() const {
	return(nodes.size());
};

void ListWdbeQGenList::append(
			WdbeQGenList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQGenList& ListWdbeQGenList::operator=(
			const ListWdbeQGenList& src
		) {
	WdbeQGenList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQGenList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQGenList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQGenList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQGenList
 ******************************************************************************/

TblWdbeQGenList::TblWdbeQGenList() {
};

TblWdbeQGenList::~TblWdbeQGenList() {
};

bool TblWdbeQGenList::loadRecBySQL(
			const string& sqlstr
			, WdbeQGenList** rec
		) {
	return false;
};

ubigint TblWdbeQGenList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQGenList& rst
		) {
	return 0;
};

ubigint TblWdbeQGenList::insertRec(
			WdbeQGenList* rec
		) {
	return 0;
};

ubigint TblWdbeQGenList::insertNewRec(
			WdbeQGenList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint mdlRefWdbeMModule
			, const string stubMdlRefWdbeMModule
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	ubigint retval = 0;
	WdbeQGenList* _rec = NULL;

	_rec = new WdbeQGenList(0, jref, jnum, ref, sref, mdlRefWdbeMModule, stubMdlRefWdbeMModule, srefWdbeKHdltype, titSrefWdbeKHdltype, Width, Minmax);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQGenList::appendNewRecToRst(
			ListWdbeQGenList& rst
			, WdbeQGenList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint mdlRefWdbeMModule
			, const string stubMdlRefWdbeMModule
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	ubigint retval = 0;
	WdbeQGenList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, mdlRefWdbeMModule, stubMdlRefWdbeMModule, srefWdbeKHdltype, titSrefWdbeKHdltype, Width, Minmax);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQGenList::insertRst(
			ListWdbeQGenList& rst
		) {
};

void TblWdbeQGenList::updateRec(
			WdbeQGenList* rec
		) {
};

void TblWdbeQGenList::updateRst(
			ListWdbeQGenList& rst
		) {
};

void TblWdbeQGenList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQGenList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQGenList::loadRecByQref(
			ubigint qref
			, WdbeQGenList** rec
		) {
	return false;
};

ubigint TblWdbeQGenList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQGenList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQGenList
 ******************************************************************************/

MyTblWdbeQGenList::MyTblWdbeQGenList() :
			TblWdbeQGenList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQGenList::~MyTblWdbeQGenList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQGenList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQGenList (jref, jnum, ref, sref, mdlRefWdbeMModule, srefWdbeKHdltype, Width, Minmax) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQGenList SET jref = ?, jnum = ?, ref = ?, sref = ?, mdlRefWdbeMModule = ?, srefWdbeKHdltype = ?, Width = ?, Minmax = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQGenList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQGenList WHERE jref = ?", false);
};

bool MyTblWdbeQGenList::loadRecBySQL(
			const string& sqlstr
			, WdbeQGenList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQGenList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQGenList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQGenList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQGenList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->mdlRefWdbeMModule = atoll((char*) dbrow[5]); else _rec->mdlRefWdbeMModule = 0;
		if (dbrow[6]) _rec->srefWdbeKHdltype.assign(dbrow[6], dblengths[6]); else _rec->srefWdbeKHdltype = "";
		if (dbrow[7]) _rec->Width = atoi((char*) dbrow[7]); else _rec->Width = 0;
		if (dbrow[8]) _rec->Minmax.assign(dbrow[8], dblengths[8]); else _rec->Minmax = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQGenList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQGenList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQGenList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQGenList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQGenList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQGenList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->mdlRefWdbeMModule = atoll((char*) dbrow[5]); else rec->mdlRefWdbeMModule = 0;
			if (dbrow[6]) rec->srefWdbeKHdltype.assign(dbrow[6], dblengths[6]); else rec->srefWdbeKHdltype = "";
			if (dbrow[7]) rec->Width = atoi((char*) dbrow[7]); else rec->Width = 0;
			if (dbrow[8]) rec->Minmax.assign(dbrow[8], dblengths[8]); else rec->Minmax = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQGenList::insertRec(
			WdbeQGenList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[5] = rec->srefWdbeKHdltype.length();
	l[7] = rec->Minmax.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Width,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQGenList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQGenList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQGenList::insertRst(
			ListWdbeQGenList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQGenList::updateRec(
			WdbeQGenList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[5] = rec->srefWdbeKHdltype.length();
	l[7] = rec->Minmax.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Width,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQGenList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQGenList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQGenList::updateRst(
			ListWdbeQGenList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQGenList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQGenList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQGenList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQGenList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQGenList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQGenList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQGenList::loadRecByQref(
			ubigint qref
			, WdbeQGenList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQGenList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQGenList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQGenList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQGenList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQGenList
 ******************************************************************************/

PgTblWdbeQGenList::PgTblWdbeQGenList() :
			TblWdbeQGenList()
			, PgTable()
		{
};

PgTblWdbeQGenList::~PgTblWdbeQGenList() {
};

void PgTblWdbeQGenList::initStatements() {
	createStatement("TblWdbeQGenList_insertRec", "INSERT INTO TblWdbeQGenList (jref, jnum, ref, sref, mdlRefWdbeMModule, srefWdbeKHdltype, Width, Minmax) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8);
	createStatement("TblWdbeQGenList_updateRec", "UPDATE TblWdbeQGenList SET jref = $1, jnum = $2, ref = $3, sref = $4, mdlRefWdbeMModule = $5, srefWdbeKHdltype = $6, Width = $7, Minmax = $8 WHERE qref = $9", 9);
	createStatement("TblWdbeQGenList_removeRecByQref", "DELETE FROM TblWdbeQGenList WHERE qref = $1", 1);
	createStatement("TblWdbeQGenList_removeRstByJref", "DELETE FROM TblWdbeQGenList WHERE jref = $1", 1);

	createStatement("TblWdbeQGenList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, mdlRefWdbeMModule, srefWdbeKHdltype, Width, Minmax FROM TblWdbeQGenList WHERE qref = $1", 1);
	createStatement("TblWdbeQGenList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, mdlRefWdbeMModule, srefWdbeKHdltype, Width, Minmax FROM TblWdbeQGenList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQGenList::loadRec(
			PGresult* res
			, WdbeQGenList** rec
		) {
	char* ptr;

	WdbeQGenList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQGenList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "mdlrefwdbemmodule"),
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
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Width = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Minmax.assign(ptr, PQgetlength(res, 0, fnum[8]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQGenList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQGenList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQGenList* rec;

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
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax")
		};

		while (numread < numrow) {
			rec = new WdbeQGenList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->mdlRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Width = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Minmax.assign(ptr, PQgetlength(res, numread, fnum[8]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQGenList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQGenList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQGenList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQGenList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQGenList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQGenList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQGenList::loadRecBySQL(
			const string& sqlstr
			, WdbeQGenList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQGenList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQGenList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQGenList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQGenList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQGenList::insertRec(
			WdbeQGenList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	usmallint _Width = htons(rec->Width);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_mdlRefWdbeMModule,
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
		0,
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQGenList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQGenList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQGenList::insertRst(
			ListWdbeQGenList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQGenList::updateRec(
			WdbeQGenList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	usmallint _Width = htons(rec->Width);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_mdlRefWdbeMModule,
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
		0,
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQGenList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQGenList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQGenList::updateRst(
			ListWdbeQGenList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQGenList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQGenList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQGenList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQGenList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQGenList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQGenList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQGenList::loadRecByQref(
			ubigint qref
			, WdbeQGenList** rec
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

	return loadRecByStmt("TblWdbeQGenList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQGenList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQGenList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQGenList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

