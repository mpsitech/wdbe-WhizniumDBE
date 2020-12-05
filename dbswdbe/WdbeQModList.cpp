/**
	* \file WdbeQModList.cpp
	* Dbs and XML wrapper for table TblWdbeQModList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQModList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModList
 ******************************************************************************/

WdbeQModList::WdbeQModList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const ubigint supRefWdbeMModule
			, const string stubSupRefWdbeMModule
			, const ubigint tplRefWdbeMModule
			, const string stubTplRefWdbeMModule
			, const string Srefrule
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->hkIxVTbl = hkIxVTbl;
	this->srefHkIxVTbl = srefHkIxVTbl;
	this->titHkIxVTbl = titHkIxVTbl;
	this->hkUref = hkUref;
	this->stubHkUref = stubHkUref;
	this->supRefWdbeMModule = supRefWdbeMModule;
	this->stubSupRefWdbeMModule = stubSupRefWdbeMModule;
	this->tplRefWdbeMModule = tplRefWdbeMModule;
	this->stubTplRefWdbeMModule = stubTplRefWdbeMModule;
	this->Srefrule = Srefrule;
};

void WdbeQModList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQModList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "hkt", srefHkIxVTbl);
		writeString(wr, "hkt2", titHkIxVTbl);
		writeString(wr, "hku", stubHkUref);
		writeString(wr, "sup", stubSupRefWdbeMModule);
		writeString(wr, "tpl", stubTplRefWdbeMModule);
		writeString(wr, "srr", Srefrule);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "srefHkIxVTbl", srefHkIxVTbl);
		writeString(wr, "titHkIxVTbl", titHkIxVTbl);
		writeString(wr, "stubHkUref", stubHkUref);
		writeString(wr, "stubSupRefWdbeMModule", stubSupRefWdbeMModule);
		writeString(wr, "stubTplRefWdbeMModule", stubTplRefWdbeMModule);
		writeString(wr, "Srefrule", Srefrule);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQModList
 ******************************************************************************/

ListWdbeQModList::ListWdbeQModList() {
};

ListWdbeQModList::ListWdbeQModList(
			const ListWdbeQModList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModList(*(src.nodes[i]));
};

ListWdbeQModList::~ListWdbeQModList() {
	clear();
};

void ListWdbeQModList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQModList::size() const {
	return(nodes.size());
};

void ListWdbeQModList::append(
			WdbeQModList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQModList& ListWdbeQModList::operator=(
			const ListWdbeQModList& src
		) {
	WdbeQModList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQModList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQModList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQModList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQModList
 ******************************************************************************/

TblWdbeQModList::TblWdbeQModList() {
};

TblWdbeQModList::~TblWdbeQModList() {
};

bool TblWdbeQModList::loadRecBySQL(
			const string& sqlstr
			, WdbeQModList** rec
		) {
	return false;
};

ubigint TblWdbeQModList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModList& rst
		) {
	return 0;
};

ubigint TblWdbeQModList::insertRec(
			WdbeQModList* rec
		) {
	return 0;
};

ubigint TblWdbeQModList::insertNewRec(
			WdbeQModList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const ubigint supRefWdbeMModule
			, const string stubSupRefWdbeMModule
			, const ubigint tplRefWdbeMModule
			, const string stubTplRefWdbeMModule
			, const string Srefrule
		) {
	ubigint retval = 0;
	WdbeQModList* _rec = NULL;

	_rec = new WdbeQModList(0, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, supRefWdbeMModule, stubSupRefWdbeMModule, tplRefWdbeMModule, stubTplRefWdbeMModule, Srefrule);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQModList::appendNewRecToRst(
			ListWdbeQModList& rst
			, WdbeQModList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint hkIxVTbl
			, const string srefHkIxVTbl
			, const string titHkIxVTbl
			, const ubigint hkUref
			, const string stubHkUref
			, const ubigint supRefWdbeMModule
			, const string stubSupRefWdbeMModule
			, const ubigint tplRefWdbeMModule
			, const string stubTplRefWdbeMModule
			, const string Srefrule
		) {
	ubigint retval = 0;
	WdbeQModList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, hkIxVTbl, srefHkIxVTbl, titHkIxVTbl, hkUref, stubHkUref, supRefWdbeMModule, stubSupRefWdbeMModule, tplRefWdbeMModule, stubTplRefWdbeMModule, Srefrule);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQModList::insertRst(
			ListWdbeQModList& rst
		) {
};

void TblWdbeQModList::updateRec(
			WdbeQModList* rec
		) {
};

void TblWdbeQModList::updateRst(
			ListWdbeQModList& rst
		) {
};

void TblWdbeQModList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQModList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQModList::loadRecByQref(
			ubigint qref
			, WdbeQModList** rec
		) {
	return false;
};

ubigint TblWdbeQModList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQModList
 ******************************************************************************/

MyTblWdbeQModList::MyTblWdbeQModList() :
			TblWdbeQModList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQModList::~MyTblWdbeQModList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQModList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQModList (jref, jnum, ref, sref, ixVBasetype, hkIxVTbl, hkUref, supRefWdbeMModule, tplRefWdbeMModule, Srefrule) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQModList SET jref = ?, jnum = ?, ref = ?, sref = ?, ixVBasetype = ?, hkIxVTbl = ?, hkUref = ?, supRefWdbeMModule = ?, tplRefWdbeMModule = ?, Srefrule = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQModList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQModList WHERE jref = ?", false);
};

bool MyTblWdbeQModList::loadRecBySQL(
			const string& sqlstr
			, WdbeQModList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQModList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQModList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->hkIxVTbl = atol((char*) dbrow[6]); else _rec->hkIxVTbl = 0;
		if (dbrow[7]) _rec->hkUref = atoll((char*) dbrow[7]); else _rec->hkUref = 0;
		if (dbrow[8]) _rec->supRefWdbeMModule = atoll((char*) dbrow[8]); else _rec->supRefWdbeMModule = 0;
		if (dbrow[9]) _rec->tplRefWdbeMModule = atoll((char*) dbrow[9]); else _rec->tplRefWdbeMModule = 0;
		if (dbrow[10]) _rec->Srefrule.assign(dbrow[10], dblengths[10]); else _rec->Srefrule = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQModList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQModList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQModList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->hkIxVTbl = atol((char*) dbrow[6]); else rec->hkIxVTbl = 0;
			if (dbrow[7]) rec->hkUref = atoll((char*) dbrow[7]); else rec->hkUref = 0;
			if (dbrow[8]) rec->supRefWdbeMModule = atoll((char*) dbrow[8]); else rec->supRefWdbeMModule = 0;
			if (dbrow[9]) rec->tplRefWdbeMModule = atoll((char*) dbrow[9]); else rec->tplRefWdbeMModule = 0;
			if (dbrow[10]) rec->Srefrule.assign(dbrow[10], dblengths[10]); else rec->Srefrule = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQModList::insertRec(
			WdbeQModList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	l[9] = rec->Srefrule.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->hkIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->hkUref,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->supRefWdbeMModule,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->tplRefWdbeMModule,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Srefrule.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQModList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQModList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQModList::insertRst(
			ListWdbeQModList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQModList::updateRec(
			WdbeQModList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->sref.length();
	l[9] = rec->Srefrule.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->hkIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->hkUref,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->supRefWdbeMModule,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->tplRefWdbeMModule,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Srefrule.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQModList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQModList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModList::updateRst(
			ListWdbeQModList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQModList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQModList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQModList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQModList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQModList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQModList::loadRecByQref(
			ubigint qref
			, WdbeQModList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQModList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQModList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQModList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQModList
 ******************************************************************************/

PgTblWdbeQModList::PgTblWdbeQModList() :
			TblWdbeQModList()
			, PgTable()
		{
};

PgTblWdbeQModList::~PgTblWdbeQModList() {
};

void PgTblWdbeQModList::initStatements() {
	createStatement("TblWdbeQModList_insertRec", "INSERT INTO TblWdbeQModList (jref, jnum, ref, sref, ixVBasetype, hkIxVTbl, hkUref, supRefWdbeMModule, tplRefWdbeMModule, Srefrule) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWdbeQModList_updateRec", "UPDATE TblWdbeQModList SET jref = $1, jnum = $2, ref = $3, sref = $4, ixVBasetype = $5, hkIxVTbl = $6, hkUref = $7, supRefWdbeMModule = $8, tplRefWdbeMModule = $9, Srefrule = $10 WHERE qref = $11", 11);
	createStatement("TblWdbeQModList_removeRecByQref", "DELETE FROM TblWdbeQModList WHERE qref = $1", 1);
	createStatement("TblWdbeQModList_removeRstByJref", "DELETE FROM TblWdbeQModList WHERE jref = $1", 1);

	createStatement("TblWdbeQModList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, hkIxVTbl, hkUref, supRefWdbeMModule, tplRefWdbeMModule, Srefrule FROM TblWdbeQModList WHERE qref = $1", 1);
	createStatement("TblWdbeQModList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, hkIxVTbl, hkUref, supRefWdbeMModule, tplRefWdbeMModule, Srefrule FROM TblWdbeQModList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQModList::loadRec(
			PGresult* res
			, WdbeQModList** rec
		) {
	char* ptr;

	WdbeQModList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQModList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "suprefwdbemmodule"),
			PQfnumber(res, "tplrefwdbemmodule"),
			PQfnumber(res, "srefrule")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->supRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->tplRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Srefrule.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQModList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQModList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQModList* rec;

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
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "suprefwdbemmodule"),
			PQfnumber(res, "tplrefwdbemmodule"),
			PQfnumber(res, "srefrule")
		};

		while (numread < numrow) {
			rec = new WdbeQModList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->supRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->tplRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Srefrule.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQModList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQModList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQModList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQModList::loadRecBySQL(
			const string& sqlstr
			, WdbeQModList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQModList::insertRec(
			WdbeQModList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _supRefWdbeMModule = htonl64(rec->supRefWdbeMModule);
	ubigint _tplRefWdbeMModule = htonl64(rec->tplRefWdbeMModule);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_supRefWdbeMModule,
		(char*) &_tplRefWdbeMModule,
		rec->Srefrule.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQModList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQModList::insertRst(
			ListWdbeQModList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQModList::updateRec(
			WdbeQModList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _supRefWdbeMModule = htonl64(rec->supRefWdbeMModule);
	ubigint _tplRefWdbeMModule = htonl64(rec->tplRefWdbeMModule);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_supRefWdbeMModule,
		(char*) &_tplRefWdbeMModule,
		rec->Srefrule.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQModList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModList::updateRst(
			ListWdbeQModList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQModList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQModList::loadRecByQref(
			ubigint qref
			, WdbeQModList** rec
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

	return loadRecByStmt("TblWdbeQModList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQModList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQModList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

