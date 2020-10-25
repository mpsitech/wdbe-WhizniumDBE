/**
	* \file WdbeQSilList.cpp
	* Dbs and XML wrapper for table TblWdbeQSilList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQSilList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSilList
 ******************************************************************************/

WdbeQSilList::WdbeQSilList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const string Fullsref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const ubigint refWdbeMSystem
			, const string stubRefWdbeMSystem
			, const ubigint refWdbeMModule
			, const string stubRefWdbeMModule
			, const string srefKPackage
			, const string titSrefKPackage
			, const bool Easy
			, const string yesnoEasy
			, const string srefKToolch
			, const string titSrefKToolch
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->Fullsref = Fullsref;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->refIxVTbl = refIxVTbl;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->refUref = refUref;
	this->stubRefUref = stubRefUref;
	this->refWdbeMSystem = refWdbeMSystem;
	this->stubRefWdbeMSystem = stubRefWdbeMSystem;
	this->refWdbeMModule = refWdbeMModule;
	this->stubRefWdbeMModule = stubRefWdbeMModule;
	this->srefKPackage = srefKPackage;
	this->titSrefKPackage = titSrefKPackage;
	this->Easy = Easy;
	this->yesnoEasy = yesnoEasy;
	this->srefKToolch = srefKToolch;
	this->titSrefKToolch = titSrefKToolch;
};

void WdbeQSilList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQSilList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "fsr", Fullsref);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeString(wr, "sys", stubRefWdbeMSystem);
		writeString(wr, "mdl", stubRefWdbeMModule);
		writeString(wr, "pkg", srefKPackage);
		writeString(wr, "pkg2", titSrefKPackage);
		writeString(wr, "esy", yesnoEasy);
		writeString(wr, "tch", srefKToolch);
		writeString(wr, "tch2", titSrefKToolch);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "Fullsref", Fullsref);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeString(wr, "stubRefWdbeMSystem", stubRefWdbeMSystem);
		writeString(wr, "stubRefWdbeMModule", stubRefWdbeMModule);
		writeString(wr, "srefKPackage", srefKPackage);
		writeString(wr, "titSrefKPackage", titSrefKPackage);
		writeString(wr, "yesnoEasy", yesnoEasy);
		writeString(wr, "srefKToolch", srefKToolch);
		writeString(wr, "titSrefKToolch", titSrefKToolch);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQSilList
 ******************************************************************************/

ListWdbeQSilList::ListWdbeQSilList() {
};

ListWdbeQSilList::ListWdbeQSilList(
			const ListWdbeQSilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSilList(*(src.nodes[i]));
};

ListWdbeQSilList::~ListWdbeQSilList() {
	clear();
};

void ListWdbeQSilList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQSilList::size() const {
	return(nodes.size());
};

void ListWdbeQSilList::append(
			WdbeQSilList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQSilList& ListWdbeQSilList::operator=(
			const ListWdbeQSilList& src
		) {
	WdbeQSilList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQSilList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQSilList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQSilList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQSilList
 ******************************************************************************/

TblWdbeQSilList::TblWdbeQSilList() {
};

TblWdbeQSilList::~TblWdbeQSilList() {
};

bool TblWdbeQSilList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSilList** rec
		) {
	return false;
};

ubigint TblWdbeQSilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSilList& rst
		) {
	return 0;
};

ubigint TblWdbeQSilList::insertRec(
			WdbeQSilList* rec
		) {
	return 0;
};

ubigint TblWdbeQSilList::insertNewRec(
			WdbeQSilList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const string Fullsref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const ubigint refWdbeMSystem
			, const string stubRefWdbeMSystem
			, const ubigint refWdbeMModule
			, const string stubRefWdbeMModule
			, const string srefKPackage
			, const string titSrefKPackage
			, const bool Easy
			, const string yesnoEasy
			, const string srefKToolch
			, const string titSrefKToolch
		) {
	ubigint retval = 0;
	WdbeQSilList* _rec = NULL;

	_rec = new WdbeQSilList(0, jref, jnum, ref, sref, Title, Fullsref, ixVBasetype, srefIxVBasetype, titIxVBasetype, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, refWdbeMSystem, stubRefWdbeMSystem, refWdbeMModule, stubRefWdbeMModule, srefKPackage, titSrefKPackage, Easy, yesnoEasy, srefKToolch, titSrefKToolch);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQSilList::appendNewRecToRst(
			ListWdbeQSilList& rst
			, WdbeQSilList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const string Fullsref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const ubigint refWdbeMSystem
			, const string stubRefWdbeMSystem
			, const ubigint refWdbeMModule
			, const string stubRefWdbeMModule
			, const string srefKPackage
			, const string titSrefKPackage
			, const bool Easy
			, const string yesnoEasy
			, const string srefKToolch
			, const string titSrefKToolch
		) {
	ubigint retval = 0;
	WdbeQSilList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, Fullsref, ixVBasetype, srefIxVBasetype, titIxVBasetype, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, refWdbeMSystem, stubRefWdbeMSystem, refWdbeMModule, stubRefWdbeMModule, srefKPackage, titSrefKPackage, Easy, yesnoEasy, srefKToolch, titSrefKToolch);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQSilList::insertRst(
			ListWdbeQSilList& rst
		) {
};

void TblWdbeQSilList::updateRec(
			WdbeQSilList* rec
		) {
};

void TblWdbeQSilList::updateRst(
			ListWdbeQSilList& rst
		) {
};

void TblWdbeQSilList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQSilList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQSilList::loadRecByQref(
			ubigint qref
			, WdbeQSilList** rec
		) {
	return false;
};

ubigint TblWdbeQSilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSilList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQSilList
 ******************************************************************************/

MyTblWdbeQSilList::MyTblWdbeQSilList() :
			TblWdbeQSilList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQSilList::~MyTblWdbeQSilList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQSilList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQSilList (jref, jnum, ref, sref, Title, Fullsref, ixVBasetype, refIxVTbl, refUref, refWdbeMSystem, refWdbeMModule, srefKPackage, Easy, srefKToolch) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQSilList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, Fullsref = ?, ixVBasetype = ?, refIxVTbl = ?, refUref = ?, refWdbeMSystem = ?, refWdbeMModule = ?, srefKPackage = ?, Easy = ?, srefKToolch = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQSilList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQSilList WHERE jref = ?", false);
};

bool MyTblWdbeQSilList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSilList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQSilList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSilList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSilList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQSilList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->Fullsref.assign(dbrow[6], dblengths[6]); else _rec->Fullsref = "";
		if (dbrow[7]) _rec->ixVBasetype = atol((char*) dbrow[7]); else _rec->ixVBasetype = 0;
		if (dbrow[8]) _rec->refIxVTbl = atol((char*) dbrow[8]); else _rec->refIxVTbl = 0;
		if (dbrow[9]) _rec->refUref = atoll((char*) dbrow[9]); else _rec->refUref = 0;
		if (dbrow[10]) _rec->refWdbeMSystem = atoll((char*) dbrow[10]); else _rec->refWdbeMSystem = 0;
		if (dbrow[11]) _rec->refWdbeMModule = atoll((char*) dbrow[11]); else _rec->refWdbeMModule = 0;
		if (dbrow[12]) _rec->srefKPackage.assign(dbrow[12], dblengths[12]); else _rec->srefKPackage = "";
		if (dbrow[13]) _rec->Easy = (atoi((char*) dbrow[13]) != 0); else _rec->Easy = false;
		if (dbrow[14]) _rec->srefKToolch.assign(dbrow[14], dblengths[14]); else _rec->srefKToolch = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQSilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSilList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQSilList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSilList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSilList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQSilList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->Fullsref.assign(dbrow[6], dblengths[6]); else rec->Fullsref = "";
			if (dbrow[7]) rec->ixVBasetype = atol((char*) dbrow[7]); else rec->ixVBasetype = 0;
			if (dbrow[8]) rec->refIxVTbl = atol((char*) dbrow[8]); else rec->refIxVTbl = 0;
			if (dbrow[9]) rec->refUref = atoll((char*) dbrow[9]); else rec->refUref = 0;
			if (dbrow[10]) rec->refWdbeMSystem = atoll((char*) dbrow[10]); else rec->refWdbeMSystem = 0;
			if (dbrow[11]) rec->refWdbeMModule = atoll((char*) dbrow[11]); else rec->refWdbeMModule = 0;
			if (dbrow[12]) rec->srefKPackage.assign(dbrow[12], dblengths[12]); else rec->srefKPackage = "";
			if (dbrow[13]) rec->Easy = (atoi((char*) dbrow[13]) != 0); else rec->Easy = false;
			if (dbrow[14]) rec->srefKToolch.assign(dbrow[14], dblengths[14]); else rec->srefKToolch = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQSilList::insertRec(
			WdbeQSilList* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();
	l[5] = rec->Fullsref.length();
	l[11] = rec->srefKPackage.length();
	tinyint Easy = rec->Easy;
	l[13] = rec->srefKToolch.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVBasetype,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->refIxVTbl,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refUref,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWdbeMSystem,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWdbeMModule,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->srefKPackage.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindTinyint(&Easy,&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->srefKToolch.c_str()),&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQSilList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQSilList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQSilList::insertRst(
			ListWdbeQSilList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQSilList::updateRec(
			WdbeQSilList* rec
		) {
	unsigned long l[15]; my_bool n[15]; my_bool e[15];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();
	l[5] = rec->Fullsref.length();
	l[11] = rec->srefKPackage.length();
	tinyint Easy = rec->Easy;
	l[13] = rec->srefKToolch.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVBasetype,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->refIxVTbl,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refUref,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->refWdbeMSystem,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->refWdbeMModule,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->srefKPackage.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindTinyint(&Easy,&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->srefKToolch.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindUbigint(&rec->qref,&(l[14]),&(n[14]),&(e[14]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQSilList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQSilList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSilList::updateRst(
			ListWdbeQSilList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQSilList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQSilList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQSilList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSilList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQSilList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQSilList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQSilList::loadRecByQref(
			ubigint qref
			, WdbeQSilList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQSilList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQSilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSilList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQSilList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQSilList
 ******************************************************************************/

PgTblWdbeQSilList::PgTblWdbeQSilList() :
			TblWdbeQSilList()
			, PgTable()
		{
};

PgTblWdbeQSilList::~PgTblWdbeQSilList() {
};

void PgTblWdbeQSilList::initStatements() {
	createStatement("TblWdbeQSilList_insertRec", "INSERT INTO TblWdbeQSilList (jref, jnum, ref, sref, Title, Fullsref, ixVBasetype, refIxVTbl, refUref, refWdbeMSystem, refWdbeMModule, srefKPackage, Easy, srefKToolch) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14) RETURNING qref", 14);
	createStatement("TblWdbeQSilList_updateRec", "UPDATE TblWdbeQSilList SET jref = $1, jnum = $2, ref = $3, sref = $4, Title = $5, Fullsref = $6, ixVBasetype = $7, refIxVTbl = $8, refUref = $9, refWdbeMSystem = $10, refWdbeMModule = $11, srefKPackage = $12, Easy = $13, srefKToolch = $14 WHERE qref = $15", 15);
	createStatement("TblWdbeQSilList_removeRecByQref", "DELETE FROM TblWdbeQSilList WHERE qref = $1", 1);
	createStatement("TblWdbeQSilList_removeRstByJref", "DELETE FROM TblWdbeQSilList WHERE jref = $1", 1);

	createStatement("TblWdbeQSilList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Title, Fullsref, ixVBasetype, refIxVTbl, refUref, refWdbeMSystem, refWdbeMModule, srefKPackage, Easy, srefKToolch FROM TblWdbeQSilList WHERE qref = $1", 1);
	createStatement("TblWdbeQSilList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Title, Fullsref, ixVBasetype, refIxVTbl, refUref, refWdbeMSystem, refWdbeMModule, srefKPackage, Easy, srefKToolch FROM TblWdbeQSilList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQSilList::loadRec(
			PGresult* res
			, WdbeQSilList** rec
		) {
	char* ptr;

	WdbeQSilList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQSilList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refwdbemsystem"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "srefkpackage"),
			PQfnumber(res, "easy"),
			PQfnumber(res, "srefktoolch")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Fullsref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->refWdbeMSystem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->refWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->srefKPackage.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Easy = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->srefKToolch.assign(ptr, PQgetlength(res, 0, fnum[14]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQSilList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQSilList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQSilList* rec;

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
			PQfnumber(res, "title"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refwdbemsystem"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "srefkpackage"),
			PQfnumber(res, "easy"),
			PQfnumber(res, "srefktoolch")
		};

		while (numread < numrow) {
			rec = new WdbeQSilList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Fullsref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->refWdbeMSystem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->refWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->srefKPackage.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Easy = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->srefKToolch.assign(ptr, PQgetlength(res, numread, fnum[14]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQSilList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQSilList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSilList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSilList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQSilList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSilList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQSilList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSilList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSilList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSilList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSilList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQSilList::insertRec(
			WdbeQSilList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refWdbeMSystem = htonl64(rec->refWdbeMSystem);
	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	smallint _Easy = htons((smallint) rec->Easy);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Fullsref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refWdbeMSystem,
		(char*) &_refWdbeMModule,
		rec->srefKPackage.c_str(),
		(char*) &_Easy,
		rec->srefKToolch.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQSilList_insertRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSilList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQSilList::insertRst(
			ListWdbeQSilList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQSilList::updateRec(
			WdbeQSilList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _refWdbeMSystem = htonl64(rec->refWdbeMSystem);
	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	smallint _Easy = htons((smallint) rec->Easy);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Fullsref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refWdbeMSystem,
		(char*) &_refWdbeMModule,
		rec->srefKPackage.c_str(),
		(char*) &_Easy,
		rec->srefKToolch.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQSilList_updateRec", 15, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSilList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSilList::updateRst(
			ListWdbeQSilList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQSilList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSilList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSilList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSilList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSilList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSilList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQSilList::loadRecByQref(
			ubigint qref
			, WdbeQSilList** rec
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

	return loadRecByStmt("TblWdbeQSilList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQSilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSilList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQSilList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

