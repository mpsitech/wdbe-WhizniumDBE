/**
	* \file WdbeQCvrList.cpp
	* Dbs and XML wrapper for table TblWdbeQCvrList (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQCvrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCvrList
 ******************************************************************************/

WdbeQCvrList::WdbeQCvrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWdbeMCoreproject
			, const string stubRefWdbeMCoreproject
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint bcvRefWdbeMCoreversion
			, const string stubBcvRefWdbeMCoreversion
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->grp = grp;
	this->stubGrp = stubGrp;
	this->own = own;
	this->stubOwn = stubOwn;
	this->refWdbeMCoreproject = refWdbeMCoreproject;
	this->stubRefWdbeMCoreproject = stubRefWdbeMCoreproject;
	this->Major = Major;
	this->Minor = Minor;
	this->Sub = Sub;
	this->bcvRefWdbeMCoreversion = bcvRefWdbeMCoreversion;
	this->stubBcvRefWdbeMCoreversion = stubBcvRefWdbeMCoreversion;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
};

void WdbeQCvrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQCvrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "grp", stubGrp);
		writeString(wr, "own", stubOwn);
		writeString(wr, "cpr", stubRefWdbeMCoreproject);
		writeUint(wr, "maj", Major);
		writeUint(wr, "min", Minor);
		writeUint(wr, "sub", Sub);
		writeString(wr, "bcv", stubBcvRefWdbeMCoreversion);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
	} else {
		writeString(wr, "stubGrp", stubGrp);
		writeString(wr, "stubOwn", stubOwn);
		writeString(wr, "stubRefWdbeMCoreproject", stubRefWdbeMCoreproject);
		writeUint(wr, "Major", Major);
		writeUint(wr, "Minor", Minor);
		writeUint(wr, "Sub", Sub);
		writeString(wr, "stubBcvRefWdbeMCoreversion", stubBcvRefWdbeMCoreversion);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQCvrList
 ******************************************************************************/

ListWdbeQCvrList::ListWdbeQCvrList() {
};

ListWdbeQCvrList::ListWdbeQCvrList(
			const ListWdbeQCvrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrList(*(src.nodes[i]));
};

ListWdbeQCvrList::~ListWdbeQCvrList() {
	clear();
};

void ListWdbeQCvrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQCvrList::size() const {
	return(nodes.size());
};

void ListWdbeQCvrList::append(
			WdbeQCvrList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQCvrList& ListWdbeQCvrList::operator=(
			const ListWdbeQCvrList& src
		) {
	WdbeQCvrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQCvrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQCvrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQCvrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQCvrList
 ******************************************************************************/

TblWdbeQCvrList::TblWdbeQCvrList() {
};

TblWdbeQCvrList::~TblWdbeQCvrList() {
};

bool TblWdbeQCvrList::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrList** rec
		) {
	return false;
};

ubigint TblWdbeQCvrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrList& rst
		) {
	return 0;
};

ubigint TblWdbeQCvrList::insertRec(
			WdbeQCvrList* rec
		) {
	return 0;
};

ubigint TblWdbeQCvrList::insertNewRec(
			WdbeQCvrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWdbeMCoreproject
			, const string stubRefWdbeMCoreproject
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint bcvRefWdbeMCoreversion
			, const string stubBcvRefWdbeMCoreversion
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	ubigint retval = 0;
	WdbeQCvrList* _rec = NULL;

	_rec = new WdbeQCvrList(0, jref, jnum, ref, grp, stubGrp, own, stubOwn, refWdbeMCoreproject, stubRefWdbeMCoreproject, Major, Minor, Sub, bcvRefWdbeMCoreversion, stubBcvRefWdbeMCoreversion, ixVState, srefIxVState, titIxVState);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQCvrList::appendNewRecToRst(
			ListWdbeQCvrList& rst
			, WdbeQCvrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint grp
			, const string stubGrp
			, const ubigint own
			, const string stubOwn
			, const ubigint refWdbeMCoreproject
			, const string stubRefWdbeMCoreproject
			, const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const ubigint bcvRefWdbeMCoreversion
			, const string stubBcvRefWdbeMCoreversion
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
		) {
	ubigint retval = 0;
	WdbeQCvrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, grp, stubGrp, own, stubOwn, refWdbeMCoreproject, stubRefWdbeMCoreproject, Major, Minor, Sub, bcvRefWdbeMCoreversion, stubBcvRefWdbeMCoreversion, ixVState, srefIxVState, titIxVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQCvrList::insertRst(
			ListWdbeQCvrList& rst
		) {
};

void TblWdbeQCvrList::updateRec(
			WdbeQCvrList* rec
		) {
};

void TblWdbeQCvrList::updateRst(
			ListWdbeQCvrList& rst
		) {
};

void TblWdbeQCvrList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQCvrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQCvrList::loadRecByQref(
			ubigint qref
			, WdbeQCvrList** rec
		) {
	return false;
};

ubigint TblWdbeQCvrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQCvrList
 ******************************************************************************/

MyTblWdbeQCvrList::MyTblWdbeQCvrList() :
			TblWdbeQCvrList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQCvrList::~MyTblWdbeQCvrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQCvrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQCvrList (jref, jnum, ref, grp, own, refWdbeMCoreproject, Major, Minor, Sub, bcvRefWdbeMCoreversion, ixVState) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQCvrList SET jref = ?, jnum = ?, ref = ?, grp = ?, own = ?, refWdbeMCoreproject = ?, Major = ?, Minor = ?, Sub = ?, bcvRefWdbeMCoreversion = ?, ixVState = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQCvrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQCvrList WHERE jref = ?", false);
};

bool MyTblWdbeQCvrList::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQCvrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCvrList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCvrList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQCvrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->grp = atoll((char*) dbrow[4]); else _rec->grp = 0;
		if (dbrow[5]) _rec->own = atoll((char*) dbrow[5]); else _rec->own = 0;
		if (dbrow[6]) _rec->refWdbeMCoreproject = atoll((char*) dbrow[6]); else _rec->refWdbeMCoreproject = 0;
		if (dbrow[7]) _rec->Major = atoi((char*) dbrow[7]); else _rec->Major = 0;
		if (dbrow[8]) _rec->Minor = atoi((char*) dbrow[8]); else _rec->Minor = 0;
		if (dbrow[9]) _rec->Sub = atoi((char*) dbrow[9]); else _rec->Sub = 0;
		if (dbrow[10]) _rec->bcvRefWdbeMCoreversion = atoll((char*) dbrow[10]); else _rec->bcvRefWdbeMCoreversion = 0;
		if (dbrow[11]) _rec->ixVState = atol((char*) dbrow[11]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQCvrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQCvrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCvrList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCvrList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQCvrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->grp = atoll((char*) dbrow[4]); else rec->grp = 0;
			if (dbrow[5]) rec->own = atoll((char*) dbrow[5]); else rec->own = 0;
			if (dbrow[6]) rec->refWdbeMCoreproject = atoll((char*) dbrow[6]); else rec->refWdbeMCoreproject = 0;
			if (dbrow[7]) rec->Major = atoi((char*) dbrow[7]); else rec->Major = 0;
			if (dbrow[8]) rec->Minor = atoi((char*) dbrow[8]); else rec->Minor = 0;
			if (dbrow[9]) rec->Sub = atoi((char*) dbrow[9]); else rec->Sub = 0;
			if (dbrow[10]) rec->bcvRefWdbeMCoreversion = atoll((char*) dbrow[10]); else rec->bcvRefWdbeMCoreversion = 0;
			if (dbrow[11]) rec->ixVState = atol((char*) dbrow[11]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQCvrList::insertRec(
			WdbeQCvrList* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWdbeMCoreproject,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Major,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Minor,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Sub,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->bcvRefWdbeMCoreversion,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixVState,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQCvrList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQCvrList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQCvrList::insertRst(
			ListWdbeQCvrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQCvrList::updateRec(
			WdbeQCvrList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->grp,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->own,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWdbeMCoreproject,&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Major,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Minor,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Sub,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->bcvRefWdbeMCoreversion,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->ixVState,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->qref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQCvrList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQCvrList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCvrList::updateRst(
			ListWdbeQCvrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQCvrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQCvrList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQCvrList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCvrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQCvrList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQCvrList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQCvrList::loadRecByQref(
			ubigint qref
			, WdbeQCvrList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQCvrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQCvrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQCvrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQCvrList
 ******************************************************************************/

PgTblWdbeQCvrList::PgTblWdbeQCvrList() :
			TblWdbeQCvrList()
			, PgTable()
		{
};

PgTblWdbeQCvrList::~PgTblWdbeQCvrList() {
};

void PgTblWdbeQCvrList::initStatements() {
	createStatement("TblWdbeQCvrList_insertRec", "INSERT INTO TblWdbeQCvrList (jref, jnum, ref, grp, own, refWdbeMCoreproject, Major, Minor, Sub, bcvRefWdbeMCoreversion, ixVState) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING qref", 11);
	createStatement("TblWdbeQCvrList_updateRec", "UPDATE TblWdbeQCvrList SET jref = $1, jnum = $2, ref = $3, grp = $4, own = $5, refWdbeMCoreproject = $6, Major = $7, Minor = $8, Sub = $9, bcvRefWdbeMCoreversion = $10, ixVState = $11 WHERE qref = $12", 12);
	createStatement("TblWdbeQCvrList_removeRecByQref", "DELETE FROM TblWdbeQCvrList WHERE qref = $1", 1);
	createStatement("TblWdbeQCvrList_removeRstByJref", "DELETE FROM TblWdbeQCvrList WHERE jref = $1", 1);

	createStatement("TblWdbeQCvrList_loadRecByQref", "SELECT qref, jref, jnum, ref, grp, own, refWdbeMCoreproject, Major, Minor, Sub, bcvRefWdbeMCoreversion, ixVState FROM TblWdbeQCvrList WHERE qref = $1", 1);
	createStatement("TblWdbeQCvrList_loadRstByJref", "SELECT qref, jref, jnum, ref, grp, own, refWdbeMCoreproject, Major, Minor, Sub, bcvRefWdbeMCoreversion, ixVState FROM TblWdbeQCvrList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQCvrList::loadRec(
			PGresult* res
			, WdbeQCvrList** rec
		) {
	char* ptr;

	WdbeQCvrList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQCvrList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwdbemcoreproject"),
			PQfnumber(res, "major"),
			PQfnumber(res, "minor"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "bcvrefwdbemcoreversion"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWdbeMCoreproject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Major = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Minor = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Sub = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->bcvRefWdbeMCoreversion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQCvrList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQCvrList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQCvrList* rec;

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
			PQfnumber(res, "refwdbemcoreproject"),
			PQfnumber(res, "major"),
			PQfnumber(res, "minor"),
			PQfnumber(res, "sub"),
			PQfnumber(res, "bcvrefwdbemcoreversion"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new WdbeQCvrList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWdbeMCoreproject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Major = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Minor = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Sub = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->bcvRefWdbeMCoreversion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQCvrList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQCvrList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCvrList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQCvrList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQCvrList::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCvrList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCvrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCvrList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQCvrList::insertRec(
			WdbeQCvrList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeMCoreproject = htonl64(rec->refWdbeMCoreproject);
	usmallint _Major = htons(rec->Major);
	usmallint _Minor = htons(rec->Minor);
	usmallint _Sub = htons(rec->Sub);
	ubigint _bcvRefWdbeMCoreversion = htonl64(rec->bcvRefWdbeMCoreversion);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWdbeMCoreproject,
		(char*) &_Major,
		(char*) &_Minor,
		(char*) &_Sub,
		(char*) &_bcvRefWdbeMCoreversion,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQCvrList_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQCvrList::insertRst(
			ListWdbeQCvrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQCvrList::updateRec(
			WdbeQCvrList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeMCoreproject = htonl64(rec->refWdbeMCoreproject);
	usmallint _Major = htons(rec->Major);
	usmallint _Minor = htons(rec->Minor);
	usmallint _Sub = htons(rec->Sub);
	ubigint _bcvRefWdbeMCoreversion = htonl64(rec->bcvRefWdbeMCoreversion);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWdbeMCoreproject,
		(char*) &_Major,
		(char*) &_Minor,
		(char*) &_Sub,
		(char*) &_bcvRefWdbeMCoreversion,
		(char*) &_ixVState,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(usmallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQCvrList_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCvrList::updateRst(
			ListWdbeQCvrList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQCvrList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCvrList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCvrList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCvrList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQCvrList::loadRecByQref(
			ubigint qref
			, WdbeQCvrList** rec
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

	return loadRecByStmt("TblWdbeQCvrList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQCvrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQCvrList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

