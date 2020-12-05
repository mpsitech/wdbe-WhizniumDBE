/**
	* \file WdbeQPrjList.cpp
	* Dbs and XML wrapper for table TblWdbeQPrjList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQPrjList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrjList
 ******************************************************************************/

WdbeQPrjList::WdbeQPrjList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Short
			, const string Title
			, const ubigint refWdbeMVersion
			, const string stubRefWdbeMVersion
			, const bool Easy
			, const string yesnoEasy
			, const string Giturl
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->Short = Short;
	this->Title = Title;
	this->refWdbeMVersion = refWdbeMVersion;
	this->stubRefWdbeMVersion = stubRefWdbeMVersion;
	this->Easy = Easy;
	this->yesnoEasy = yesnoEasy;
	this->Giturl = Giturl;
};

void WdbeQPrjList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQPrjList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "sho", Short);
		writeString(wr, "tit", Title);
		writeString(wr, "ver", stubRefWdbeMVersion);
		writeString(wr, "esy", yesnoEasy);
		writeString(wr, "grl", Giturl);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "Short", Short);
		writeString(wr, "Title", Title);
		writeString(wr, "stubRefWdbeMVersion", stubRefWdbeMVersion);
		writeString(wr, "yesnoEasy", yesnoEasy);
		writeString(wr, "Giturl", Giturl);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQPrjList
 ******************************************************************************/

ListWdbeQPrjList::ListWdbeQPrjList() {
};

ListWdbeQPrjList::ListWdbeQPrjList(
			const ListWdbeQPrjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrjList(*(src.nodes[i]));
};

ListWdbeQPrjList::~ListWdbeQPrjList() {
	clear();
};

void ListWdbeQPrjList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQPrjList::size() const {
	return(nodes.size());
};

void ListWdbeQPrjList::append(
			WdbeQPrjList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQPrjList& ListWdbeQPrjList::operator=(
			const ListWdbeQPrjList& src
		) {
	WdbeQPrjList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQPrjList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQPrjList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQPrjList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQPrjList
 ******************************************************************************/

TblWdbeQPrjList::TblWdbeQPrjList() {
};

TblWdbeQPrjList::~TblWdbeQPrjList() {
};

bool TblWdbeQPrjList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrjList** rec
		) {
	return false;
};

ubigint TblWdbeQPrjList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrjList& rst
		) {
	return 0;
};

ubigint TblWdbeQPrjList::insertRec(
			WdbeQPrjList* rec
		) {
	return 0;
};

ubigint TblWdbeQPrjList::insertNewRec(
			WdbeQPrjList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Short
			, const string Title
			, const ubigint refWdbeMVersion
			, const string stubRefWdbeMVersion
			, const bool Easy
			, const string yesnoEasy
			, const string Giturl
		) {
	ubigint retval = 0;
	WdbeQPrjList* _rec = NULL;

	_rec = new WdbeQPrjList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, Short, Title, refWdbeMVersion, stubRefWdbeMVersion, Easy, yesnoEasy, Giturl);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQPrjList::appendNewRecToRst(
			ListWdbeQPrjList& rst
			, WdbeQPrjList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string Short
			, const string Title
			, const ubigint refWdbeMVersion
			, const string stubRefWdbeMVersion
			, const bool Easy
			, const string yesnoEasy
			, const string Giturl
		) {
	ubigint retval = 0;
	WdbeQPrjList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, Short, Title, refWdbeMVersion, stubRefWdbeMVersion, Easy, yesnoEasy, Giturl);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQPrjList::insertRst(
			ListWdbeQPrjList& rst
		) {
};

void TblWdbeQPrjList::updateRec(
			WdbeQPrjList* rec
		) {
};

void TblWdbeQPrjList::updateRst(
			ListWdbeQPrjList& rst
		) {
};

void TblWdbeQPrjList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQPrjList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQPrjList::loadRecByQref(
			ubigint qref
			, WdbeQPrjList** rec
		) {
	return false;
};

ubigint TblWdbeQPrjList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrjList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQPrjList
 ******************************************************************************/

MyTblWdbeQPrjList::MyTblWdbeQPrjList() :
			TblWdbeQPrjList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQPrjList::~MyTblWdbeQPrjList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQPrjList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQPrjList (jref, jnum, ref, grp, own, Short, Title, refWdbeMVersion, Easy, Giturl) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQPrjList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, Short = ?, Title = ?, refWdbeMVersion = ?, Easy = ?, Giturl = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQPrjList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQPrjList WHERE jref = ?", false);
};

bool MyTblWdbeQPrjList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrjList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQPrjList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrjList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrjList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQPrjList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->Short.assign(dbrow[6], dblengths[6]); else _rec->Short = "";
		if (dbrow[7]) _rec->Title.assign(dbrow[7], dblengths[7]); else _rec->Title = "";
		if (dbrow[8]) _rec->refWdbeMVersion = atoll((char*) dbrow[8]); else _rec->refWdbeMVersion = 0;
		if (dbrow[9]) _rec->Easy = (atoi((char*) dbrow[9]) != 0); else _rec->Easy = false;
		if (dbrow[10]) _rec->Giturl.assign(dbrow[10], dblengths[10]); else _rec->Giturl = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQPrjList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrjList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQPrjList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrjList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrjList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQPrjList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->Short.assign(dbrow[6], dblengths[6]); else rec->Short = "";
			if (dbrow[7]) rec->Title.assign(dbrow[7], dblengths[7]); else rec->Title = "";
			if (dbrow[8]) rec->refWdbeMVersion = atoll((char*) dbrow[8]); else rec->refWdbeMVersion = 0;
			if (dbrow[9]) rec->Easy = (atoi((char*) dbrow[9]) != 0); else rec->Easy = false;
			if (dbrow[10]) rec->Giturl.assign(dbrow[10], dblengths[10]); else rec->Giturl = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQPrjList::insertRec(
			WdbeQPrjList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[5] = rec->Short.length();
	l[6] = rec->Title.length();
	tinyint Easy = rec->Easy;
	l[9] = rec->Giturl.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Short.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWdbeMVersion,&(l[7]),&(n[7]),&(e[7])),
		bindTinyint(&Easy,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Giturl.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQPrjList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQPrjList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQPrjList::insertRst(
			ListWdbeQPrjList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQPrjList::updateRec(
			WdbeQPrjList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->Short.length();
	l[6] = rec->Title.length();
	tinyint Easy = rec->Easy;
	l[9] = rec->Giturl.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Short.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWdbeMVersion,&(l[7]),&(n[7]),&(e[7])),
		bindTinyint(&Easy,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Giturl.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQPrjList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQPrjList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrjList::updateRst(
			ListWdbeQPrjList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQPrjList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQPrjList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQPrjList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrjList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQPrjList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQPrjList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQPrjList::loadRecByQref(
			ubigint qref
			, WdbeQPrjList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQPrjList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQPrjList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrjList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQPrjList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQPrjList
 ******************************************************************************/

PgTblWdbeQPrjList::PgTblWdbeQPrjList() :
			TblWdbeQPrjList()
			, PgTable()
		{
};

PgTblWdbeQPrjList::~PgTblWdbeQPrjList() {
};

void PgTblWdbeQPrjList::initStatements() {
	createStatement("TblWdbeQPrjList_insertRec", "INSERT INTO TblWdbeQPrjList (jref, jnum, ref, grp, own, Short, Title, refWdbeMVersion, Easy, Giturl) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWdbeQPrjList_updateRec", "UPDATE TblWdbeQPrjList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, Short = $6, Title = $7, refWdbeMVersion = $8, Easy = $9, Giturl = $10 WHERE qref = $11", 11);
	createStatement("TblWdbeQPrjList_removeRecByQref", "DELETE FROM TblWdbeQPrjList WHERE qref = $1", 1);
	createStatement("TblWdbeQPrjList_removeRstByJref", "DELETE FROM TblWdbeQPrjList WHERE jref = $1", 1);

	createStatement("TblWdbeQPrjList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, Short, Title, refWdbeMVersion, Easy, Giturl FROM TblWdbeQPrjList WHERE qref = $1", 1);
	createStatement("TblWdbeQPrjList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, Short, Title, refWdbeMVersion, Easy, Giturl FROM TblWdbeQPrjList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQPrjList::loadRec(
			PGresult* res
			, WdbeQPrjList** rec
		) {
	char* ptr;

	WdbeQPrjList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQPrjList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refwdbemversion"),
			PQfnumber(res, "easy"),
			PQfnumber(res, "giturl")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Short.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWdbeMVersion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Easy = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Giturl.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQPrjList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQPrjList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQPrjList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "short"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refwdbemversion"),
			PQfnumber(res, "easy"),
			PQfnumber(res, "giturl")
		};

		while (numread < numrow) {
			rec = new WdbeQPrjList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Short.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWdbeMVersion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Easy = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Giturl.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQPrjList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQPrjList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrjList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrjList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQPrjList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrjList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQPrjList::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrjList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrjList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrjList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrjList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrjList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQPrjList::insertRec(
			WdbeQPrjList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);
	smallint _Easy = htons((smallint) rec->Easy);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->Short.c_str(),
		rec->Title.c_str(),
		(char*) &_refWdbeMVersion,
		(char*) &_Easy,
		rec->Giturl.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(smallint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQPrjList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrjList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQPrjList::insertRst(
			ListWdbeQPrjList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQPrjList::updateRec(
			WdbeQPrjList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeMVersion = htonl64(rec->refWdbeMVersion);
	smallint _Easy = htons((smallint) rec->Easy);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->Short.c_str(),
		rec->Title.c_str(),
		(char*) &_refWdbeMVersion,
		(char*) &_Easy,
		rec->Giturl.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(smallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQPrjList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrjList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrjList::updateRst(
			ListWdbeQPrjList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQPrjList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrjList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrjList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrjList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrjList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrjList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQPrjList::loadRecByQref(
			ubigint qref
			, WdbeQPrjList** rec
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

	return loadRecByStmt("TblWdbeQPrjList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQPrjList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrjList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQPrjList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

