/**
	* \file WdbeQPrsMNProject.cpp
	* Dbs and XML wrapper for table TblWdbeQPrsMNProject (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQPrsMNProject.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrsMNProject
 ******************************************************************************/

WdbeQPrsMNProject::WdbeQPrsMNProject(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x1Stopd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->x1Startd = x1Startd;
	this->ftmX1Startd = ftmX1Startd;
	this->x1Stopd = x1Stopd;
	this->ftmX1Stopd = ftmX1Stopd;
	this->srefKFunction = srefKFunction;
	this->titSrefKFunction = titSrefKFunction;
};

void WdbeQPrsMNProject::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
		me["sta"] = ftmX1Startd;
		me["sto"] = ftmX1Stopd;
		me["fct"] = srefKFunction;
		me["fct2"] = titSrefKFunction;
	} else {
		me["stubMref"] = stubMref;
		me["ftmX1Startd"] = ftmX1Startd;
		me["ftmX1Stopd"] = ftmX1Stopd;
		me["srefKFunction"] = srefKFunction;
		me["titSrefKFunction"] = titSrefKFunction;
	};
};

void WdbeQPrsMNProject::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQPrsMNProject";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "sta", ftmX1Startd);
		writeString(wr, "sto", ftmX1Stopd);
		writeString(wr, "fct", srefKFunction);
		writeString(wr, "fct2", titSrefKFunction);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "ftmX1Startd", ftmX1Startd);
		writeString(wr, "ftmX1Stopd", ftmX1Stopd);
		writeString(wr, "srefKFunction", srefKFunction);
		writeString(wr, "titSrefKFunction", titSrefKFunction);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQPrsMNProject
 ******************************************************************************/

ListWdbeQPrsMNProject::ListWdbeQPrsMNProject() {
};

ListWdbeQPrsMNProject::ListWdbeQPrsMNProject(
			const ListWdbeQPrsMNProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrsMNProject(*(src.nodes[i]));
};

ListWdbeQPrsMNProject::~ListWdbeQPrsMNProject() {
	clear();
};

void ListWdbeQPrsMNProject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQPrsMNProject::size() const {
	return(nodes.size());
};

void ListWdbeQPrsMNProject::append(
			WdbeQPrsMNProject* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQPrsMNProject& ListWdbeQPrsMNProject::operator=(
			const ListWdbeQPrsMNProject& src
		) {
	WdbeQPrsMNProject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQPrsMNProject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQPrsMNProject::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQPrsMNProject";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQPrsMNProject::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQPrsMNProject";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQPrsMNProject
 ******************************************************************************/

TblWdbeQPrsMNProject::TblWdbeQPrsMNProject() {
};

TblWdbeQPrsMNProject::~TblWdbeQPrsMNProject() {
};

bool TblWdbeQPrsMNProject::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrsMNProject** rec
		) {
	return false;
};

ubigint TblWdbeQPrsMNProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrsMNProject& rst
		) {
	return 0;
};

ubigint TblWdbeQPrsMNProject::insertRec(
			WdbeQPrsMNProject* rec
		) {
	return 0;
};

ubigint TblWdbeQPrsMNProject::insertNewRec(
			WdbeQPrsMNProject** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x1Stopd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	ubigint retval = 0;
	WdbeQPrsMNProject* _rec = NULL;

	_rec = new WdbeQPrsMNProject(0, jref, jnum, mref, stubMref, ref, x1Startd, ftmX1Startd, x1Stopd, ftmX1Stopd, srefKFunction, titSrefKFunction);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQPrsMNProject::appendNewRecToRst(
			ListWdbeQPrsMNProject& rst
			, WdbeQPrsMNProject** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Startd
			, const string ftmX1Startd
			, const uint x1Stopd
			, const string ftmX1Stopd
			, const string srefKFunction
			, const string titSrefKFunction
		) {
	ubigint retval = 0;
	WdbeQPrsMNProject* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1Startd, ftmX1Startd, x1Stopd, ftmX1Stopd, srefKFunction, titSrefKFunction);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQPrsMNProject::insertRst(
			ListWdbeQPrsMNProject& rst
		) {
};

void TblWdbeQPrsMNProject::updateRec(
			WdbeQPrsMNProject* rec
		) {
};

void TblWdbeQPrsMNProject::updateRst(
			ListWdbeQPrsMNProject& rst
		) {
};

void TblWdbeQPrsMNProject::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQPrsMNProject::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQPrsMNProject::loadRecByQref(
			ubigint qref
			, WdbeQPrsMNProject** rec
		) {
	return false;
};

ubigint TblWdbeQPrsMNProject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrsMNProject& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQPrsMNProject
 ******************************************************************************/

MyTblWdbeQPrsMNProject::MyTblWdbeQPrsMNProject() :
			TblWdbeQPrsMNProject()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQPrsMNProject::~MyTblWdbeQPrsMNProject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQPrsMNProject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQPrsMNProject (jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQPrsMNProject SET jref = ?, jnum = ?, mref = ?, ref = ?, x1Startd = ?, x1Stopd = ?, srefKFunction = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQPrsMNProject WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQPrsMNProject WHERE jref = ?", false);
};

bool MyTblWdbeQPrsMNProject::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrsMNProject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQPrsMNProject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrsMNProject::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrsMNProject::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQPrsMNProject();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1Startd = atol((char*) dbrow[5]); else _rec->x1Startd = 0;
		if (dbrow[6]) _rec->x1Stopd = atol((char*) dbrow[6]); else _rec->x1Stopd = 0;
		if (dbrow[7]) _rec->srefKFunction.assign(dbrow[7], dblengths[7]); else _rec->srefKFunction = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQPrsMNProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrsMNProject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQPrsMNProject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrsMNProject::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrsMNProject::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQPrsMNProject();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1Startd = atol((char*) dbrow[5]); else rec->x1Startd = 0;
			if (dbrow[6]) rec->x1Stopd = atol((char*) dbrow[6]); else rec->x1Stopd = 0;
			if (dbrow[7]) rec->srefKFunction.assign(dbrow[7], dblengths[7]); else rec->srefKFunction = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQPrsMNProject::insertRec(
			WdbeQPrsMNProject* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[6] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Startd,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stopd,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQPrsMNProject::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQPrsMNProject::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQPrsMNProject::insertRst(
			ListWdbeQPrsMNProject& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQPrsMNProject::updateRec(
			WdbeQPrsMNProject* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[6] = rec->srefKFunction.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Startd,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stopd,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->srefKFunction.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQPrsMNProject::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQPrsMNProject::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrsMNProject::updateRst(
			ListWdbeQPrsMNProject& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQPrsMNProject::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQPrsMNProject::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQPrsMNProject::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrsMNProject::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQPrsMNProject::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQPrsMNProject::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQPrsMNProject::loadRecByQref(
			ubigint qref
			, WdbeQPrsMNProject** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQPrsMNProject WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQPrsMNProject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrsMNProject& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQPrsMNProject WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQPrsMNProject
 ******************************************************************************/

PgTblWdbeQPrsMNProject::PgTblWdbeQPrsMNProject() :
			TblWdbeQPrsMNProject()
			, PgTable()
		{
};

PgTblWdbeQPrsMNProject::~PgTblWdbeQPrsMNProject() {
};

void PgTblWdbeQPrsMNProject::initStatements() {
	createStatement("TblWdbeQPrsMNProject_insertRec", "INSERT INTO TblWdbeQPrsMNProject (jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWdbeQPrsMNProject_updateRec", "UPDATE TblWdbeQPrsMNProject SET jref = $1, jnum = $2, mref = $3, ref = $4, x1Startd = $5, x1Stopd = $6, srefKFunction = $7 WHERE qref = $8", 8);
	createStatement("TblWdbeQPrsMNProject_removeRecByQref", "DELETE FROM TblWdbeQPrsMNProject WHERE qref = $1", 1);
	createStatement("TblWdbeQPrsMNProject_removeRstByJref", "DELETE FROM TblWdbeQPrsMNProject WHERE jref = $1", 1);

	createStatement("TblWdbeQPrsMNProject_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction FROM TblWdbeQPrsMNProject WHERE qref = $1", 1);
	createStatement("TblWdbeQPrsMNProject_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction FROM TblWdbeQPrsMNProject WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQPrsMNProject::loadRec(
			PGresult* res
			, WdbeQPrsMNProject** rec
		) {
	char* ptr;

	WdbeQPrsMNProject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQPrsMNProject();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "srefkfunction")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1Stopd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->srefKFunction.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQPrsMNProject::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQPrsMNProject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQPrsMNProject* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "srefkfunction")
		};

		while (numread < numrow) {
			rec = new WdbeQPrsMNProject();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1Stopd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->srefKFunction.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQPrsMNProject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQPrsMNProject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrsMNProject::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrsMNProject::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQPrsMNProject& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrsMNProject::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQPrsMNProject::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrsMNProject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrsMNProject::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrsMNProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrsMNProject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrsMNProject::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQPrsMNProject::insertRec(
			WdbeQPrsMNProject* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		rec->srefKFunction.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeQPrsMNProject_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrsMNProject::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQPrsMNProject::insertRst(
			ListWdbeQPrsMNProject& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQPrsMNProject::updateRec(
			WdbeQPrsMNProject* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		rec->srefKFunction.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQPrsMNProject_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrsMNProject::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrsMNProject::updateRst(
			ListWdbeQPrsMNProject& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQPrsMNProject::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrsMNProject_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrsMNProject::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrsMNProject::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrsMNProject_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrsMNProject::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQPrsMNProject::loadRecByQref(
			ubigint qref
			, WdbeQPrsMNProject** rec
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

	return loadRecByStmt("TblWdbeQPrsMNProject_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQPrsMNProject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrsMNProject& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQPrsMNProject_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
