/**
	* \file WdbeQVarList.cpp
	* Dbs and XML wrapper for table TblWdbeQVarList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQVarList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQVarList
 ******************************************************************************/

WdbeQVarList::WdbeQVarList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const bool Const
			, const string yesnoConst
			, const bool Falling
			, const string yesnoFalling
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, sref(sref)
			, refIxVTbl(refIxVTbl)
			, srefRefIxVTbl(srefRefIxVTbl)
			, titRefIxVTbl(titRefIxVTbl)
			, refUref(refUref)
			, stubRefUref(stubRefUref)
			, Const(Const)
			, yesnoConst(yesnoConst)
			, Falling(Falling)
			, yesnoFalling(yesnoFalling)
			, srefWdbeKHdltype(srefWdbeKHdltype)
			, titSrefWdbeKHdltype(titSrefWdbeKHdltype)
			, Width(Width)
			, Minmax(Minmax)
		{
};

void WdbeQVarList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["ret"] = srefRefIxVTbl;
		me["ret2"] = titRefIxVTbl;
		me["reu"] = stubRefUref;
		me["con"] = yesnoConst;
		me["fal"] = yesnoFalling;
		me["hty"] = srefWdbeKHdltype;
		me["hty2"] = titSrefWdbeKHdltype;
		me["wid"] = Width;
		me["mmx"] = Minmax;
	} else {
		me["sref"] = sref;
		me["srefRefIxVTbl"] = srefRefIxVTbl;
		me["titRefIxVTbl"] = titRefIxVTbl;
		me["stubRefUref"] = stubRefUref;
		me["yesnoConst"] = yesnoConst;
		me["yesnoFalling"] = yesnoFalling;
		me["srefWdbeKHdltype"] = srefWdbeKHdltype;
		me["titSrefWdbeKHdltype"] = titSrefWdbeKHdltype;
		me["Width"] = Width;
		me["Minmax"] = Minmax;
	};
};

void WdbeQVarList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQVarList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeString(wr, "con", yesnoConst);
		writeString(wr, "fal", yesnoFalling);
		writeString(wr, "hty", srefWdbeKHdltype);
		writeString(wr, "hty2", titSrefWdbeKHdltype);
		writeUint(wr, "wid", Width);
		writeString(wr, "mmx", Minmax);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeString(wr, "yesnoConst", yesnoConst);
		writeString(wr, "yesnoFalling", yesnoFalling);
		writeString(wr, "srefWdbeKHdltype", srefWdbeKHdltype);
		writeString(wr, "titSrefWdbeKHdltype", titSrefWdbeKHdltype);
		writeUint(wr, "Width", Width);
		writeString(wr, "Minmax", Minmax);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQVarList
 ******************************************************************************/

ListWdbeQVarList::ListWdbeQVarList() {
};

ListWdbeQVarList::ListWdbeQVarList(
			const ListWdbeQVarList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQVarList(*(src.nodes[i]));
};

ListWdbeQVarList::~ListWdbeQVarList() {
	clear();
};

void ListWdbeQVarList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQVarList::size() const {
	return(nodes.size());
};

void ListWdbeQVarList::append(
			WdbeQVarList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQVarList& ListWdbeQVarList::operator=(
			const ListWdbeQVarList& src
		) {
	WdbeQVarList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQVarList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQVarList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQVarList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQVarList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQVarList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQVarList
 ******************************************************************************/

TblWdbeQVarList::TblWdbeQVarList() {
};

TblWdbeQVarList::~TblWdbeQVarList() {
};

bool TblWdbeQVarList::loadRecBySQL(
			const string& sqlstr
			, WdbeQVarList** rec
		) {
	return false;
};

ubigint TblWdbeQVarList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQVarList& rst
		) {
	return 0;
};

ubigint TblWdbeQVarList::insertRec(
			WdbeQVarList* rec
		) {
	return 0;
};

ubigint TblWdbeQVarList::insertNewRec(
			WdbeQVarList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const bool Const
			, const string yesnoConst
			, const bool Falling
			, const string yesnoFalling
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	ubigint retval = 0;
	WdbeQVarList* _rec = NULL;

	_rec = new WdbeQVarList(0, jref, jnum, ref, sref, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, Const, yesnoConst, Falling, yesnoFalling, srefWdbeKHdltype, titSrefWdbeKHdltype, Width, Minmax);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQVarList::appendNewRecToRst(
			ListWdbeQVarList& rst
			, WdbeQVarList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const bool Const
			, const string yesnoConst
			, const bool Falling
			, const string yesnoFalling
			, const string srefWdbeKHdltype
			, const string titSrefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
		) {
	ubigint retval = 0;
	WdbeQVarList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, Const, yesnoConst, Falling, yesnoFalling, srefWdbeKHdltype, titSrefWdbeKHdltype, Width, Minmax);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQVarList::insertRst(
			ListWdbeQVarList& rst
		) {
};

void TblWdbeQVarList::updateRec(
			WdbeQVarList* rec
		) {
};

void TblWdbeQVarList::updateRst(
			ListWdbeQVarList& rst
		) {
};

void TblWdbeQVarList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQVarList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQVarList::loadRecByQref(
			ubigint qref
			, WdbeQVarList** rec
		) {
	return false;
};

ubigint TblWdbeQVarList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQVarList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQVarList
 ******************************************************************************/

MyTblWdbeQVarList::MyTblWdbeQVarList() :
			TblWdbeQVarList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQVarList::~MyTblWdbeQVarList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQVarList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQVarList (jref, jnum, ref, sref, refIxVTbl, refUref, Const, Falling, srefWdbeKHdltype, Width, Minmax) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQVarList SET jref = ?, jnum = ?, ref = ?, sref = ?, refIxVTbl = ?, refUref = ?, Const = ?, Falling = ?, srefWdbeKHdltype = ?, Width = ?, Minmax = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQVarList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQVarList WHERE jref = ?", false);
};

bool MyTblWdbeQVarList::loadRecBySQL(
			const string& sqlstr
			, WdbeQVarList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQVarList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQVarList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQVarList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQVarList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->refIxVTbl = atol((char*) dbrow[5]); else _rec->refIxVTbl = 0;
		if (dbrow[6]) _rec->refUref = atoll((char*) dbrow[6]); else _rec->refUref = 0;
		if (dbrow[7]) _rec->Const = (atoi((char*) dbrow[7]) != 0); else _rec->Const = false;
		if (dbrow[8]) _rec->Falling = (atoi((char*) dbrow[8]) != 0); else _rec->Falling = false;
		if (dbrow[9]) _rec->srefWdbeKHdltype.assign(dbrow[9], dblengths[9]); else _rec->srefWdbeKHdltype = "";
		if (dbrow[10]) _rec->Width = atoi((char*) dbrow[10]); else _rec->Width = 0;
		if (dbrow[11]) _rec->Minmax.assign(dbrow[11], dblengths[11]); else _rec->Minmax = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQVarList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQVarList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQVarList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQVarList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQVarList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQVarList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->refIxVTbl = atol((char*) dbrow[5]); else rec->refIxVTbl = 0;
			if (dbrow[6]) rec->refUref = atoll((char*) dbrow[6]); else rec->refUref = 0;
			if (dbrow[7]) rec->Const = (atoi((char*) dbrow[7]) != 0); else rec->Const = false;
			if (dbrow[8]) rec->Falling = (atoi((char*) dbrow[8]) != 0); else rec->Falling = false;
			if (dbrow[9]) rec->srefWdbeKHdltype.assign(dbrow[9], dblengths[9]); else rec->srefWdbeKHdltype = "";
			if (dbrow[10]) rec->Width = atoi((char*) dbrow[10]); else rec->Width = 0;
			if (dbrow[11]) rec->Minmax.assign(dbrow[11], dblengths[11]); else rec->Minmax = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQVarList::insertRec(
			WdbeQVarList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->sref.length();
	tinyint Const = rec->Const;
	tinyint Falling = rec->Falling;
	l[8] = rec->srefWdbeKHdltype.length();
	l[10] = rec->Minmax.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->refIxVTbl,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refUref,&(l[5]),&(n[5]),&(e[5])),
		bindTinyint(&Const,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Falling,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUsmallint(&rec->Width,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQVarList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQVarList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQVarList::insertRst(
			ListWdbeQVarList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQVarList::updateRec(
			WdbeQVarList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[3] = rec->sref.length();
	tinyint Const = rec->Const;
	tinyint Falling = rec->Falling;
	l[8] = rec->srefWdbeKHdltype.length();
	l[10] = rec->Minmax.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->refIxVTbl,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refUref,&(l[5]),&(n[5]),&(e[5])),
		bindTinyint(&Const,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Falling,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUsmallint(&rec->Width,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQVarList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQVarList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQVarList::updateRst(
			ListWdbeQVarList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQVarList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQVarList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQVarList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQVarList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQVarList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQVarList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQVarList::loadRecByQref(
			ubigint qref
			, WdbeQVarList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQVarList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQVarList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQVarList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQVarList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQVarList
 ******************************************************************************/

PgTblWdbeQVarList::PgTblWdbeQVarList() :
			TblWdbeQVarList()
			, PgTable()
		{
};

PgTblWdbeQVarList::~PgTblWdbeQVarList() {
};

void PgTblWdbeQVarList::initStatements() {
	createStatement("TblWdbeQVarList_insertRec", "INSERT INTO TblWdbeQVarList (jref, jnum, ref, sref, refIxVTbl, refUref, Const, Falling, srefWdbeKHdltype, Width, Minmax) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblWdbeQVarList_updateRec", "UPDATE TblWdbeQVarList SET jref = $1, jnum = $2, ref = $3, sref = $4, refIxVTbl = $5, refUref = $6, Const = $7, Falling = $8, srefWdbeKHdltype = $9, Width = $10, Minmax = $11 WHERE qref = $12", 12);
	createStatement("TblWdbeQVarList_removeRecByQref", "DELETE FROM TblWdbeQVarList WHERE qref = $1", 1);
	createStatement("TblWdbeQVarList_removeRstByJref", "DELETE FROM TblWdbeQVarList WHERE jref = $1", 1);

	createStatement("TblWdbeQVarList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, refIxVTbl, refUref, Const, Falling, srefWdbeKHdltype, Width, Minmax FROM TblWdbeQVarList WHERE qref = $1", 1);
	createStatement("TblWdbeQVarList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, refIxVTbl, refUref, Const, Falling, srefWdbeKHdltype, Width, Minmax FROM TblWdbeQVarList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQVarList::loadRec(
			PGresult* res
			, WdbeQVarList** rec
		) {
	char* ptr;

	WdbeQVarList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQVarList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "const"),
			PQfnumber(res, "falling"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Const = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Falling = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Width = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Minmax.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQVarList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQVarList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQVarList* rec;

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
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "const"),
			PQfnumber(res, "falling"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax")
		};

		while (numread < numrow) {
			rec = new WdbeQVarList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Const = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Falling = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Width = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Minmax.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQVarList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQVarList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQVarList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQVarList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQVarList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQVarList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQVarList::loadRecBySQL(
			const string& sqlstr
			, WdbeQVarList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQVarList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQVarList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQVarList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQVarList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQVarList::insertRec(
			WdbeQVarList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	smallint _Const = htons((smallint) rec->Const);
	smallint _Falling = htons((smallint) rec->Falling);
	usmallint _Width = htons(rec->Width);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_Const,
		(char*) &_Falling,
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
		sizeof(smallint),
		sizeof(smallint),
		0,
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQVarList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQVarList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQVarList::insertRst(
			ListWdbeQVarList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQVarList::updateRec(
			WdbeQVarList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	smallint _Const = htons((smallint) rec->Const);
	smallint _Falling = htons((smallint) rec->Falling);
	usmallint _Width = htons(rec->Width);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_Const,
		(char*) &_Falling,
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
		sizeof(smallint),
		sizeof(smallint),
		0,
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQVarList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQVarList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQVarList::updateRst(
			ListWdbeQVarList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQVarList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQVarList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQVarList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQVarList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQVarList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQVarList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQVarList::loadRecByQref(
			ubigint qref
			, WdbeQVarList** rec
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

	return loadRecByStmt("TblWdbeQVarList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQVarList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQVarList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQVarList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
