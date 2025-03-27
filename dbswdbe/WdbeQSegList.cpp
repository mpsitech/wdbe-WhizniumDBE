/**
	* \file WdbeQSegList.cpp
	* Dbs and XML wrapper for table TblWdbeQSegList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeQSegList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQSegList
 ******************************************************************************/

WdbeQSegList::WdbeQSegList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint pplRefWdbeMPipeline
			, const string stubPplRefWdbeMPipeline
			, const ubigint supRefWdbeMSegment
			, const string stubSupRefWdbeMSegment
			, const string Infmt
			, const string Outfmt
			, const usmallint Latency
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, ref(ref)
			, sref(sref)
			, pplRefWdbeMPipeline(pplRefWdbeMPipeline)
			, stubPplRefWdbeMPipeline(stubPplRefWdbeMPipeline)
			, supRefWdbeMSegment(supRefWdbeMSegment)
			, stubSupRefWdbeMSegment(stubSupRefWdbeMSegment)
			, Infmt(Infmt)
			, Outfmt(Outfmt)
			, Latency(Latency)
		{
};

void WdbeQSegList::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["srf"] = sref;
		me["ppl"] = stubPplRefWdbeMPipeline;
		me["sup"] = stubSupRefWdbeMSegment;
		me["ifm"] = Infmt;
		me["ofm"] = Outfmt;
		me["lcy"] = Latency;
	} else {
		me["sref"] = sref;
		me["stubPplRefWdbeMPipeline"] = stubPplRefWdbeMPipeline;
		me["stubSupRefWdbeMSegment"] = stubSupRefWdbeMSegment;
		me["Infmt"] = Infmt;
		me["Outfmt"] = Outfmt;
		me["Latency"] = Latency;
	};
};

void WdbeQSegList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQSegList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "ppl", stubPplRefWdbeMPipeline);
		writeString(wr, "sup", stubSupRefWdbeMSegment);
		writeString(wr, "ifm", Infmt);
		writeString(wr, "ofm", Outfmt);
		writeUint(wr, "lcy", Latency);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubPplRefWdbeMPipeline", stubPplRefWdbeMPipeline);
		writeString(wr, "stubSupRefWdbeMSegment", stubSupRefWdbeMSegment);
		writeString(wr, "Infmt", Infmt);
		writeString(wr, "Outfmt", Outfmt);
		writeUint(wr, "Latency", Latency);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQSegList
 ******************************************************************************/

ListWdbeQSegList::ListWdbeQSegList() {
};

ListWdbeQSegList::ListWdbeQSegList(
			const ListWdbeQSegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQSegList(*(src.nodes[i]));
};

ListWdbeQSegList::~ListWdbeQSegList() {
	clear();
};

void ListWdbeQSegList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQSegList::size() const {
	return(nodes.size());
};

void ListWdbeQSegList::append(
			WdbeQSegList* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQSegList& ListWdbeQSegList::operator=(
			const ListWdbeQSegList& src
		) {
	WdbeQSegList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQSegList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQSegList::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQSegList";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQSegList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQSegList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQSegList
 ******************************************************************************/

TblWdbeQSegList::TblWdbeQSegList() {
};

TblWdbeQSegList::~TblWdbeQSegList() {
};

bool TblWdbeQSegList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSegList** rec
		) {
	return false;
};

ubigint TblWdbeQSegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSegList& rst
		) {
	return 0;
};

ubigint TblWdbeQSegList::insertRec(
			WdbeQSegList* rec
		) {
	return 0;
};

ubigint TblWdbeQSegList::insertNewRec(
			WdbeQSegList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint pplRefWdbeMPipeline
			, const string stubPplRefWdbeMPipeline
			, const ubigint supRefWdbeMSegment
			, const string stubSupRefWdbeMSegment
			, const string Infmt
			, const string Outfmt
			, const usmallint Latency
		) {
	ubigint retval = 0;
	WdbeQSegList* _rec = NULL;

	_rec = new WdbeQSegList(0, jref, jnum, ref, sref, pplRefWdbeMPipeline, stubPplRefWdbeMPipeline, supRefWdbeMSegment, stubSupRefWdbeMSegment, Infmt, Outfmt, Latency);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQSegList::appendNewRecToRst(
			ListWdbeQSegList& rst
			, WdbeQSegList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint pplRefWdbeMPipeline
			, const string stubPplRefWdbeMPipeline
			, const ubigint supRefWdbeMSegment
			, const string stubSupRefWdbeMSegment
			, const string Infmt
			, const string Outfmt
			, const usmallint Latency
		) {
	ubigint retval = 0;
	WdbeQSegList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, pplRefWdbeMPipeline, stubPplRefWdbeMPipeline, supRefWdbeMSegment, stubSupRefWdbeMSegment, Infmt, Outfmt, Latency);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQSegList::insertRst(
			ListWdbeQSegList& rst
		) {
};

void TblWdbeQSegList::updateRec(
			WdbeQSegList* rec
		) {
};

void TblWdbeQSegList::updateRst(
			ListWdbeQSegList& rst
		) {
};

void TblWdbeQSegList::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQSegList::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQSegList::loadRecByQref(
			ubigint qref
			, WdbeQSegList** rec
		) {
	return false;
};

ubigint TblWdbeQSegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSegList& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQSegList
 ******************************************************************************/

MyTblWdbeQSegList::MyTblWdbeQSegList() :
			TblWdbeQSegList()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQSegList::~MyTblWdbeQSegList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQSegList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQSegList (jref, jnum, ref, sref, pplRefWdbeMPipeline, supRefWdbeMSegment, Infmt, Outfmt, Latency) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQSegList SET jref = ?, jnum = ?, ref = ?, sref = ?, pplRefWdbeMPipeline = ?, supRefWdbeMSegment = ?, Infmt = ?, Outfmt = ?, Latency = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQSegList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQSegList WHERE jref = ?", false);
};

bool MyTblWdbeQSegList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSegList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQSegList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSegList::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSegList::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQSegList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->pplRefWdbeMPipeline = atoll((char*) dbrow[5]); else _rec->pplRefWdbeMPipeline = 0;
		if (dbrow[6]) _rec->supRefWdbeMSegment = atoll((char*) dbrow[6]); else _rec->supRefWdbeMSegment = 0;
		if (dbrow[7]) _rec->Infmt.assign(dbrow[7], dblengths[7]); else _rec->Infmt = "";
		if (dbrow[8]) _rec->Outfmt.assign(dbrow[8], dblengths[8]); else _rec->Outfmt = "";
		if (dbrow[9]) _rec->Latency = atoi((char*) dbrow[9]); else _rec->Latency = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQSegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSegList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQSegList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQSegList::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQSegList::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQSegList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->pplRefWdbeMPipeline = atoll((char*) dbrow[5]); else rec->pplRefWdbeMPipeline = 0;
			if (dbrow[6]) rec->supRefWdbeMSegment = atoll((char*) dbrow[6]); else rec->supRefWdbeMSegment = 0;
			if (dbrow[7]) rec->Infmt.assign(dbrow[7], dblengths[7]); else rec->Infmt = "";
			if (dbrow[8]) rec->Outfmt.assign(dbrow[8], dblengths[8]); else rec->Outfmt = "";
			if (dbrow[9]) rec->Latency = atoi((char*) dbrow[9]); else rec->Latency = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQSegList::insertRec(
			WdbeQSegList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[6] = rec->Infmt.length();
	l[7] = rec->Outfmt.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->pplRefWdbeMPipeline,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefWdbeMSegment,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Infmt.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Outfmt.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Latency,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQSegList::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQSegList::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQSegList::insertRst(
			ListWdbeQSegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQSegList::updateRec(
			WdbeQSegList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();
	l[6] = rec->Infmt.length();
	l[7] = rec->Outfmt.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->pplRefWdbeMPipeline,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefWdbeMSegment,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Infmt.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Outfmt.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Latency,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQSegList::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQSegList::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSegList::updateRst(
			ListWdbeQSegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQSegList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQSegList::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQSegList::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQSegList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQSegList::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQSegList::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQSegList::loadRecByQref(
			ubigint qref
			, WdbeQSegList** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQSegList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQSegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSegList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQSegList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQSegList
 ******************************************************************************/

PgTblWdbeQSegList::PgTblWdbeQSegList() :
			TblWdbeQSegList()
			, PgTable()
		{
};

PgTblWdbeQSegList::~PgTblWdbeQSegList() {
};

void PgTblWdbeQSegList::initStatements() {
	createStatement("TblWdbeQSegList_insertRec", "INSERT INTO TblWdbeQSegList (jref, jnum, ref, sref, pplRefWdbeMPipeline, supRefWdbeMSegment, Infmt, Outfmt, Latency) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9);
	createStatement("TblWdbeQSegList_updateRec", "UPDATE TblWdbeQSegList SET jref = $1, jnum = $2, ref = $3, sref = $4, pplRefWdbeMPipeline = $5, supRefWdbeMSegment = $6, Infmt = $7, Outfmt = $8, Latency = $9 WHERE qref = $10", 10);
	createStatement("TblWdbeQSegList_removeRecByQref", "DELETE FROM TblWdbeQSegList WHERE qref = $1", 1);
	createStatement("TblWdbeQSegList_removeRstByJref", "DELETE FROM TblWdbeQSegList WHERE jref = $1", 1);

	createStatement("TblWdbeQSegList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, pplRefWdbeMPipeline, supRefWdbeMSegment, Infmt, Outfmt, Latency FROM TblWdbeQSegList WHERE qref = $1", 1);
	createStatement("TblWdbeQSegList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, pplRefWdbeMPipeline, supRefWdbeMSegment, Infmt, Outfmt, Latency FROM TblWdbeQSegList WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQSegList::loadRec(
			PGresult* res
			, WdbeQSegList** rec
		) {
	char* ptr;

	WdbeQSegList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQSegList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "pplrefwdbempipeline"),
			PQfnumber(res, "suprefwdbemsegment"),
			PQfnumber(res, "infmt"),
			PQfnumber(res, "outfmt"),
			PQfnumber(res, "latency")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->pplRefWdbeMPipeline = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->supRefWdbeMSegment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Infmt.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Outfmt.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Latency = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQSegList::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQSegList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQSegList* rec;

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
			PQfnumber(res, "pplrefwdbempipeline"),
			PQfnumber(res, "suprefwdbemsegment"),
			PQfnumber(res, "infmt"),
			PQfnumber(res, "outfmt"),
			PQfnumber(res, "latency")
		};

		while (numread < numrow) {
			rec = new WdbeQSegList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->pplRefWdbeMPipeline = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->supRefWdbeMSegment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Infmt.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Outfmt.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Latency = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQSegList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQSegList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSegList::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSegList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQSegList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSegList::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQSegList::loadRecBySQL(
			const string& sqlstr
			, WdbeQSegList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSegList::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQSegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQSegList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQSegList::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQSegList::insertRec(
			WdbeQSegList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _pplRefWdbeMPipeline = htonl64(rec->pplRefWdbeMPipeline);
	ubigint _supRefWdbeMSegment = htonl64(rec->supRefWdbeMSegment);
	usmallint _Latency = htons(rec->Latency);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_pplRefWdbeMPipeline,
		(char*) &_supRefWdbeMSegment,
		rec->Infmt.c_str(),
		rec->Outfmt.c_str(),
		(char*) &_Latency
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQSegList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQSegList::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQSegList::insertRst(
			ListWdbeQSegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQSegList::updateRec(
			WdbeQSegList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _pplRefWdbeMPipeline = htonl64(rec->pplRefWdbeMPipeline);
	ubigint _supRefWdbeMSegment = htonl64(rec->supRefWdbeMSegment);
	usmallint _Latency = htons(rec->Latency);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_pplRefWdbeMPipeline,
		(char*) &_supRefWdbeMSegment,
		rec->Infmt.c_str(),
		rec->Outfmt.c_str(),
		(char*) &_Latency,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQSegList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSegList::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSegList::updateRst(
			ListWdbeQSegList& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQSegList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSegList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSegList::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQSegList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQSegList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQSegList::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQSegList::loadRecByQref(
			ubigint qref
			, WdbeQSegList** rec
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

	return loadRecByStmt("TblWdbeQSegList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQSegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQSegList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQSegList_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
