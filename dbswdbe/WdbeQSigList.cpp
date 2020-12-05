/**
	* \file WdbeQSigList.cpp
	* Dbs and XML wrapper for table TblWdbeQSigList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQSigList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSigList
 ******************************************************************************/

WdbeQSigList::WdbeQSigList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint mdlRefWdbeMModule
			, const string stubMdlRefWdbeMModule
			, const uint mgeIxVTbl
			, const string srefMgeIxVTbl
			, const string titMgeIxVTbl
			, const ubigint mgeUref
			, const string stubMgeUref
			, const ubigint refWdbeMVector
			, const string stubRefWdbeMVector
			, const bool Const
			, const string yesnoConst
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
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->mdlRefWdbeMModule = mdlRefWdbeMModule;
	this->stubMdlRefWdbeMModule = stubMdlRefWdbeMModule;
	this->mgeIxVTbl = mgeIxVTbl;
	this->srefMgeIxVTbl = srefMgeIxVTbl;
	this->titMgeIxVTbl = titMgeIxVTbl;
	this->mgeUref = mgeUref;
	this->stubMgeUref = stubMgeUref;
	this->refWdbeMVector = refWdbeMVector;
	this->stubRefWdbeMVector = stubRefWdbeMVector;
	this->Const = Const;
	this->yesnoConst = yesnoConst;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->titSrefWdbeKHdltype = titSrefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
};

void WdbeQSigList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQSigList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "mdl", stubMdlRefWdbeMModule);
		writeString(wr, "mgt", srefMgeIxVTbl);
		writeString(wr, "mgt2", titMgeIxVTbl);
		writeString(wr, "mgu", stubMgeUref);
		writeString(wr, "vec", stubRefWdbeMVector);
		writeString(wr, "con", yesnoConst);
		writeString(wr, "hty", srefWdbeKHdltype);
		writeString(wr, "hty2", titSrefWdbeKHdltype);
		writeUint(wr, "wid", Width);
		writeString(wr, "mmx", Minmax);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubMdlRefWdbeMModule", stubMdlRefWdbeMModule);
		writeString(wr, "srefMgeIxVTbl", srefMgeIxVTbl);
		writeString(wr, "titMgeIxVTbl", titMgeIxVTbl);
		writeString(wr, "stubMgeUref", stubMgeUref);
		writeString(wr, "stubRefWdbeMVector", stubRefWdbeMVector);
		writeString(wr, "yesnoConst", yesnoConst);
		writeString(wr, "srefWdbeKHdltype", srefWdbeKHdltype);
		writeString(wr, "titSrefWdbeKHdltype", titSrefWdbeKHdltype);
		writeUint(wr, "Width", Width);
		writeString(wr, "Minmax", Minmax);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQSigList
 ******************************************************************************/

ListWdbeQSigList::ListWdbeQSigList() {
};

ListWdbeQSigList::ListWdbeQSigList(
			const ListWdbeQSigList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSigList(*(src.nodes[i]));
};

ListWdbeQSigList::~ListWdbeQSigList() {
	clear();
};

void ListWdbeQSigList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQSigList::size() const {
	return(nodes.size());
};

void ListWdbeQSigList::append(
			WdbeQSigList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQSigList& ListWdbeQSigList::operator=(
			const ListWdbeQSigList& src
		) {
	WdbeQSigList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQSigList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQSigList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQSigList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQSigList
 ******************************************************************************/

TblWdbeQSigList::TblWdbeQSigList() {
};

TblWdbeQSigList::~TblWdbeQSigList() {
};

bool TblWdbeQSigList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSigList** rec
		) {
	return false;
};

ubigint TblWdbeQSigList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSigList& rst
		) {
	return 0;
};

ubigint TblWdbeQSigList::insertRec(
			WdbeQSigList* rec
		) {
	return 0;
};

ubigint TblWdbeQSigList::insertNewRec(
			WdbeQSigList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint mdlRefWdbeMModule
			, const string stubMdlRefWdbeMModule
			, const uint mgeIxVTbl
			, const string srefMgeIxVTbl
			, const string titMgeIxVTbl
			, const ubigint mgeUref
			, const string stubMgeUref
			, const ubigint refWdbeMVector
			, const string stubRefWdbeMVector
			, const bool Const
			, const string yesnoConst
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	ubigint retval = 0;
	WdbeQSigList* _rec = NULL;

	_rec = new WdbeQSigList(0, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, mdlRefWdbeMModule, stubMdlRefWdbeMModule, mgeIxVTbl, srefMgeIxVTbl, titMgeIxVTbl, mgeUref, stubMgeUref, refWdbeMVector, stubRefWdbeMVector, Const, yesnoConst, srefWdbeKHdltype, titSrefWdbeKHdltype, Width, Minmax);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQSigList::appendNewRecToRst(
			ListWdbeQSigList& rst
			, WdbeQSigList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint mdlRefWdbeMModule
			, const string stubMdlRefWdbeMModule
			, const uint mgeIxVTbl
			, const string srefMgeIxVTbl
			, const string titMgeIxVTbl
			, const ubigint mgeUref
			, const string stubMgeUref
			, const ubigint refWdbeMVector
			, const string stubRefWdbeMVector
			, const bool Const
			, const string yesnoConst
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	ubigint retval = 0;
	WdbeQSigList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, mdlRefWdbeMModule, stubMdlRefWdbeMModule, mgeIxVTbl, srefMgeIxVTbl, titMgeIxVTbl, mgeUref, stubMgeUref, refWdbeMVector, stubRefWdbeMVector, Const, yesnoConst, srefWdbeKHdltype, titSrefWdbeKHdltype, Width, Minmax);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQSigList::insertRst(
			ListWdbeQSigList& rst
		) {
};

void TblWdbeQSigList::updateRec(
			WdbeQSigList* rec
		) {
};

void TblWdbeQSigList::updateRst(
			ListWdbeQSigList& rst
		) {
};

void TblWdbeQSigList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQSigList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQSigList::loadRecByQref(
			ubigint qref
			, WdbeQSigList** rec
		) {
	return false;
};

ubigint TblWdbeQSigList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSigList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQSigList
 ******************************************************************************/

MyTblWdbeQSigList::MyTblWdbeQSigList() :
			TblWdbeQSigList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQSigList::~MyTblWdbeQSigList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQSigList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQSigList (jref, jnum, ref, sref, ixVBasetype, mdlRefWdbeMModule, mgeIxVTbl, mgeUref, refWdbeMVector, Const, srefWdbeKHdltype, Width, Minmax) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQSigList SET jref = ?, jnum = ?, ref = ?, sref = ?, ixVBasetype = ?, mdlRefWdbeMModule = ?, mgeIxVTbl = ?, mgeUref = ?, refWdbeMVector = ?, Const = ?, srefWdbeKHdltype = ?, Width = ?, Minmax = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQSigList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQSigList WHERE jref = ?", false);
};

bool MyTblWdbeQSigList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSigList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQSigList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSigList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSigList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQSigList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->mdlRefWdbeMModule = atoll((char*) dbrow[6]); else _rec->mdlRefWdbeMModule = 0;
		if (dbrow[7]) _rec->mgeIxVTbl = atol((char*) dbrow[7]); else _rec->mgeIxVTbl = 0;
		if (dbrow[8]) _rec->mgeUref = atoll((char*) dbrow[8]); else _rec->mgeUref = 0;
		if (dbrow[9]) _rec->refWdbeMVector = atoll((char*) dbrow[9]); else _rec->refWdbeMVector = 0;
		if (dbrow[10]) _rec->Const = (atoi((char*) dbrow[10]) != 0); else _rec->Const = false;
		if (dbrow[11]) _rec->srefWdbeKHdltype.assign(dbrow[11], dblengths[11]); else _rec->srefWdbeKHdltype = "";
		if (dbrow[12]) _rec->Width = atoi((char*) dbrow[12]); else _rec->Width = 0;
		if (dbrow[13]) _rec->Minmax.assign(dbrow[13], dblengths[13]); else _rec->Minmax = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQSigList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSigList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQSigList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSigList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSigList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQSigList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->mdlRefWdbeMModule = atoll((char*) dbrow[6]); else rec->mdlRefWdbeMModule = 0;
			if (dbrow[7]) rec->mgeIxVTbl = atol((char*) dbrow[7]); else rec->mgeIxVTbl = 0;
			if (dbrow[8]) rec->mgeUref = atoll((char*) dbrow[8]); else rec->mgeUref = 0;
			if (dbrow[9]) rec->refWdbeMVector = atoll((char*) dbrow[9]); else rec->refWdbeMVector = 0;
			if (dbrow[10]) rec->Const = (atoi((char*) dbrow[10]) != 0); else rec->Const = false;
			if (dbrow[11]) rec->srefWdbeKHdltype.assign(dbrow[11], dblengths[11]); else rec->srefWdbeKHdltype = "";
			if (dbrow[12]) rec->Width = atoi((char*) dbrow[12]); else rec->Width = 0;
			if (dbrow[13]) rec->Minmax.assign(dbrow[13], dblengths[13]); else rec->Minmax = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQSigList::insertRec(
			WdbeQSigList* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[3] = rec->sref.length();
	tinyint Const = rec->Const;
	l[10] = rec->srefWdbeKHdltype.length();
	l[12] = rec->Minmax.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->mgeIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->mgeUref,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWdbeMVector,&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Const,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUsmallint(&rec->Width,&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQSigList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQSigList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQSigList::insertRst(
			ListWdbeQSigList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQSigList::updateRec(
			WdbeQSigList* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[3] = rec->sref.length();
	tinyint Const = rec->Const;
	l[10] = rec->srefWdbeKHdltype.length();
	l[12] = rec->Minmax.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->mgeIxVTbl,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->mgeUref,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWdbeMVector,&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Const,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUsmallint(&rec->Width,&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->qref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQSigList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQSigList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSigList::updateRst(
			ListWdbeQSigList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQSigList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQSigList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQSigList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSigList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQSigList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQSigList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQSigList::loadRecByQref(
			ubigint qref
			, WdbeQSigList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQSigList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQSigList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSigList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQSigList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQSigList
 ******************************************************************************/

PgTblWdbeQSigList::PgTblWdbeQSigList() :
			TblWdbeQSigList()
			, PgTable()
		{
};

PgTblWdbeQSigList::~PgTblWdbeQSigList() {
};

void PgTblWdbeQSigList::initStatements() {
	createStatement("TblWdbeQSigList_insertRec", "INSERT INTO TblWdbeQSigList (jref, jnum, ref, sref, ixVBasetype, mdlRefWdbeMModule, mgeIxVTbl, mgeUref, refWdbeMVector, Const, srefWdbeKHdltype, Width, Minmax) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING qref", 13);
	createStatement("TblWdbeQSigList_updateRec", "UPDATE TblWdbeQSigList SET jref = $1, jnum = $2, ref = $3, sref = $4, ixVBasetype = $5, mdlRefWdbeMModule = $6, mgeIxVTbl = $7, mgeUref = $8, refWdbeMVector = $9, Const = $10, srefWdbeKHdltype = $11, Width = $12, Minmax = $13 WHERE qref = $14", 14);
	createStatement("TblWdbeQSigList_removeRecByQref", "DELETE FROM TblWdbeQSigList WHERE qref = $1", 1);
	createStatement("TblWdbeQSigList_removeRstByJref", "DELETE FROM TblWdbeQSigList WHERE jref = $1", 1);

	createStatement("TblWdbeQSigList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, mdlRefWdbeMModule, mgeIxVTbl, mgeUref, refWdbeMVector, Const, srefWdbeKHdltype, Width, Minmax FROM TblWdbeQSigList WHERE qref = $1", 1);
	createStatement("TblWdbeQSigList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, mdlRefWdbeMModule, mgeIxVTbl, mgeUref, refWdbeMVector, Const, srefWdbeKHdltype, Width, Minmax FROM TblWdbeQSigList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQSigList::loadRec(
			PGresult* res
			, WdbeQSigList** rec
		) {
	char* ptr;

	WdbeQSigList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQSigList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "mdlrefwdbemmodule"),
			PQfnumber(res, "mgeixvtbl"),
			PQfnumber(res, "mgeuref"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "const"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->mdlRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->mgeIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->mgeUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWdbeMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Const = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Width = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Minmax.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQSigList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQSigList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQSigList* rec;

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
			PQfnumber(res, "mdlrefwdbemmodule"),
			PQfnumber(res, "mgeixvtbl"),
			PQfnumber(res, "mgeuref"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "const"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax")
		};

		while (numread < numrow) {
			rec = new WdbeQSigList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->mdlRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->mgeIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->mgeUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWdbeMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Const = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Width = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Minmax.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQSigList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQSigList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSigList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSigList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQSigList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSigList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQSigList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSigList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSigList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSigList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSigList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSigList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQSigList::insertRec(
			WdbeQSigList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	uint _mgeIxVTbl = htonl(rec->mgeIxVTbl);
	ubigint _mgeUref = htonl64(rec->mgeUref);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	smallint _Const = htons((smallint) rec->Const);
	usmallint _Width = htons(rec->Width);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_mdlRefWdbeMModule,
		(char*) &_mgeIxVTbl,
		(char*) &_mgeUref,
		(char*) &_refWdbeMVector,
		(char*) &_Const,
		rec->srefWdbeKHdltype.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQSigList_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSigList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQSigList::insertRst(
			ListWdbeQSigList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQSigList::updateRec(
			WdbeQSigList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	uint _mgeIxVTbl = htonl(rec->mgeIxVTbl);
	ubigint _mgeUref = htonl64(rec->mgeUref);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	smallint _Const = htons((smallint) rec->Const);
	usmallint _Width = htons(rec->Width);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_mdlRefWdbeMModule,
		(char*) &_mgeIxVTbl,
		(char*) &_mgeUref,
		(char*) &_refWdbeMVector,
		(char*) &_Const,
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
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQSigList_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSigList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSigList::updateRst(
			ListWdbeQSigList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQSigList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSigList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSigList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSigList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSigList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSigList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQSigList::loadRecByQref(
			ubigint qref
			, WdbeQSigList** rec
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

	return loadRecByStmt("TblWdbeQSigList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQSigList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSigList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQSigList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

