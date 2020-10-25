/**
	* \file WdbeQCprList.cpp
	* Dbs and XML wrapper for table TblWdbeQCprList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQCprList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCprList
 ******************************************************************************/

WdbeQCprList::WdbeQCprList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string sref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWdbeMCoreversion
			, const string stubRefWdbeMCoreversion
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
	this->sref = sref;
	this->Title = Title;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->refWdbeMCoreversion = refWdbeMCoreversion;
	this->stubRefWdbeMCoreversion = stubRefWdbeMCoreversion;
	this->Giturl = Giturl;
};

void WdbeQCprList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQCprList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "cvr", stubRefWdbeMCoreversion);
		writeString(wr, "grl", Giturl);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubRefWdbeMCoreversion", stubRefWdbeMCoreversion);
		writeString(wr, "Giturl", Giturl);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQCprList
 ******************************************************************************/

ListWdbeQCprList::ListWdbeQCprList() {
};

ListWdbeQCprList::ListWdbeQCprList(
			const ListWdbeQCprList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCprList(*(src.nodes[i]));
};

ListWdbeQCprList::~ListWdbeQCprList() {
	clear();
};

void ListWdbeQCprList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQCprList::size() const {
	return(nodes.size());
};

void ListWdbeQCprList::append(
			WdbeQCprList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQCprList& ListWdbeQCprList::operator=(
			const ListWdbeQCprList& src
		) {
	WdbeQCprList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQCprList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQCprList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQCprList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQCprList
 ******************************************************************************/

TblWdbeQCprList::TblWdbeQCprList() {
};

TblWdbeQCprList::~TblWdbeQCprList() {
};

bool TblWdbeQCprList::loadRecBySQL(
			const string& sqlstr
			, WdbeQCprList** rec
		) {
	return false;
};

ubigint TblWdbeQCprList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCprList& rst
		) {
	return 0;
};

ubigint TblWdbeQCprList::insertRec(
			WdbeQCprList* rec
		) {
	return 0;
};

ubigint TblWdbeQCprList::insertNewRec(
			WdbeQCprList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string sref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWdbeMCoreversion
			, const string stubRefWdbeMCoreversion
			, const string Giturl
		) {
	ubigint retval = 0;
	WdbeQCprList* _rec = NULL;

	_rec = new WdbeQCprList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, sref, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, refWdbeMCoreversion, stubRefWdbeMCoreversion, Giturl);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQCprList::appendNewRecToRst(
			ListWdbeQCprList& rst
			, WdbeQCprList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const string sref
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refWdbeMCoreversion
			, const string stubRefWdbeMCoreversion
			, const string Giturl
		) {
	ubigint retval = 0;
	WdbeQCprList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, sref, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, refWdbeMCoreversion, stubRefWdbeMCoreversion, Giturl);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQCprList::insertRst(
			ListWdbeQCprList& rst
		) {
};

void TblWdbeQCprList::updateRec(
			WdbeQCprList* rec
		) {
};

void TblWdbeQCprList::updateRst(
			ListWdbeQCprList& rst
		) {
};

void TblWdbeQCprList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQCprList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQCprList::loadRecByQref(
			ubigint qref
			, WdbeQCprList** rec
		) {
	return false;
};

ubigint TblWdbeQCprList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCprList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQCprList
 ******************************************************************************/

MyTblWdbeQCprList::MyTblWdbeQCprList() :
			TblWdbeQCprList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQCprList::~MyTblWdbeQCprList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQCprList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQCprList (jref, jnum, ref, grp, own, sref, Title, ixVBasetype, refWdbeMCoreversion, Giturl) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQCprList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, sref = ?, Title = ?, ixVBasetype = ?, refWdbeMCoreversion = ?, Giturl = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQCprList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQCprList WHERE jref = ?", false);
};

bool MyTblWdbeQCprList::loadRecBySQL(
			const string& sqlstr
			, WdbeQCprList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQCprList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCprList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCprList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQCprList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Title.assign(dbrow[7], dblengths[7]); else _rec->Title = "";
		if (dbrow[8]) _rec->ixVBasetype = atol((char*) dbrow[8]); else _rec->ixVBasetype = 0;
		if (dbrow[9]) _rec->refWdbeMCoreversion = atoll((char*) dbrow[9]); else _rec->refWdbeMCoreversion = 0;
		if (dbrow[10]) _rec->Giturl.assign(dbrow[10], dblengths[10]); else _rec->Giturl = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQCprList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCprList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQCprList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCprList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCprList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQCprList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Title.assign(dbrow[7], dblengths[7]); else rec->Title = "";
			if (dbrow[8]) rec->ixVBasetype = atol((char*) dbrow[8]); else rec->ixVBasetype = 0;
			if (dbrow[9]) rec->refWdbeMCoreversion = atoll((char*) dbrow[9]); else rec->refWdbeMCoreversion = 0;
			if (dbrow[10]) rec->Giturl.assign(dbrow[10], dblengths[10]); else rec->Giturl = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQCprList::insertRec(
			WdbeQCprList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[5] = rec->sref.length();
	l[6] = rec->Title.length();
	l[9] = rec->Giturl.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVBasetype,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWdbeMCoreversion,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Giturl.c_str()),&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQCprList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQCprList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQCprList::insertRst(
			ListWdbeQCprList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQCprList::updateRec(
			WdbeQCprList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[5] = rec->sref.length();
	l[6] = rec->Title.length();
	l[9] = rec->Giturl.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Title.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVBasetype,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refWdbeMCoreversion,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Giturl.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQCprList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQCprList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCprList::updateRst(
			ListWdbeQCprList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQCprList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQCprList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQCprList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCprList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQCprList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQCprList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQCprList::loadRecByQref(
			ubigint qref
			, WdbeQCprList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQCprList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQCprList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCprList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQCprList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQCprList
 ******************************************************************************/

PgTblWdbeQCprList::PgTblWdbeQCprList() :
			TblWdbeQCprList()
			, PgTable()
		{
};

PgTblWdbeQCprList::~PgTblWdbeQCprList() {
};

void PgTblWdbeQCprList::initStatements() {
	createStatement("TblWdbeQCprList_insertRec", "INSERT INTO TblWdbeQCprList (jref, jnum, ref, grp, own, sref, Title, ixVBasetype, refWdbeMCoreversion, Giturl) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10);
	createStatement("TblWdbeQCprList_updateRec", "UPDATE TblWdbeQCprList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, sref = $6, Title = $7, ixVBasetype = $8, refWdbeMCoreversion = $9, Giturl = $10 WHERE qref = $11", 11);
	createStatement("TblWdbeQCprList_removeRecByQref", "DELETE FROM TblWdbeQCprList WHERE qref = $1", 1);
	createStatement("TblWdbeQCprList_removeRstByJref", "DELETE FROM TblWdbeQCprList WHERE jref = $1", 1);

	createStatement("TblWdbeQCprList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, sref, Title, ixVBasetype, refWdbeMCoreversion, Giturl FROM TblWdbeQCprList WHERE qref = $1", 1);
	createStatement("TblWdbeQCprList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, sref, Title, ixVBasetype, refWdbeMCoreversion, Giturl FROM TblWdbeQCprList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQCprList::loadRec(
			PGresult* res
			, WdbeQCprList** rec
		) {
	char* ptr;

	WdbeQCprList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQCprList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwdbemcoreversion"),
			PQfnumber(res, "giturl")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refWdbeMCoreversion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Giturl.assign(ptr, PQgetlength(res, 0, fnum[10]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQCprList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQCprList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQCprList* rec;

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
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwdbemcoreversion"),
			PQfnumber(res, "giturl")
		};

		while (numread < numrow) {
			rec = new WdbeQCprList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refWdbeMCoreversion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Giturl.assign(ptr, PQgetlength(res, numread, fnum[10]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQCprList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQCprList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCprList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCprList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQCprList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCprList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQCprList::loadRecBySQL(
			const string& sqlstr
			, WdbeQCprList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCprList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCprList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCprList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCprList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQCprList::insertRec(
			WdbeQCprList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWdbeMCoreversion = htonl64(rec->refWdbeMCoreversion);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refWdbeMCoreversion,
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
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQCprList_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCprList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQCprList::insertRst(
			ListWdbeQCprList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQCprList::updateRec(
			WdbeQCprList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWdbeMCoreversion = htonl64(rec->refWdbeMCoreversion);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refWdbeMCoreversion,
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
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQCprList_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCprList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCprList::updateRst(
			ListWdbeQCprList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQCprList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCprList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCprList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCprList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCprList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCprList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQCprList::loadRecByQref(
			ubigint qref
			, WdbeQCprList** rec
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

	return loadRecByStmt("TblWdbeQCprList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQCprList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCprList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQCprList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

