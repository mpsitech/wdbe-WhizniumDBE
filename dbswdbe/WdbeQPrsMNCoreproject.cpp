/**
	* \file WdbeQPrsMNCoreproject.cpp
	* Dbs and XML wrapper for table TblWdbeQPrsMNCoreproject (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQPrsMNCoreproject.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQPrsMNCoreproject
 ******************************************************************************/

WdbeQPrsMNCoreproject::WdbeQPrsMNCoreproject(
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

void WdbeQPrsMNCoreproject::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQPrsMNCoreproject";

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
 class ListWdbeQPrsMNCoreproject
 ******************************************************************************/

ListWdbeQPrsMNCoreproject::ListWdbeQPrsMNCoreproject() {
};

ListWdbeQPrsMNCoreproject::ListWdbeQPrsMNCoreproject(
			const ListWdbeQPrsMNCoreproject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQPrsMNCoreproject(*(src.nodes[i]));
};

ListWdbeQPrsMNCoreproject::~ListWdbeQPrsMNCoreproject() {
	clear();
};

void ListWdbeQPrsMNCoreproject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQPrsMNCoreproject::size() const {
	return(nodes.size());
};

void ListWdbeQPrsMNCoreproject::append(
			WdbeQPrsMNCoreproject* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQPrsMNCoreproject& ListWdbeQPrsMNCoreproject::operator=(
			const ListWdbeQPrsMNCoreproject& src
		) {
	WdbeQPrsMNCoreproject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQPrsMNCoreproject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQPrsMNCoreproject::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQPrsMNCoreproject";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQPrsMNCoreproject
 ******************************************************************************/

TblWdbeQPrsMNCoreproject::TblWdbeQPrsMNCoreproject() {
};

TblWdbeQPrsMNCoreproject::~TblWdbeQPrsMNCoreproject() {
};

bool TblWdbeQPrsMNCoreproject::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrsMNCoreproject** rec
		) {
	return false;
};

ubigint TblWdbeQPrsMNCoreproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrsMNCoreproject& rst
		) {
	return 0;
};

ubigint TblWdbeQPrsMNCoreproject::insertRec(
			WdbeQPrsMNCoreproject* rec
		) {
	return 0;
};

ubigint TblWdbeQPrsMNCoreproject::insertNewRec(
			WdbeQPrsMNCoreproject** rec
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
	WdbeQPrsMNCoreproject* _rec = NULL;

	_rec = new WdbeQPrsMNCoreproject(0, jref, jnum, mref, stubMref, ref, x1Startd, ftmX1Startd, x1Stopd, ftmX1Stopd, srefKFunction, titSrefKFunction);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQPrsMNCoreproject::appendNewRecToRst(
			ListWdbeQPrsMNCoreproject& rst
			, WdbeQPrsMNCoreproject** rec
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
	WdbeQPrsMNCoreproject* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1Startd, ftmX1Startd, x1Stopd, ftmX1Stopd, srefKFunction, titSrefKFunction);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQPrsMNCoreproject::insertRst(
			ListWdbeQPrsMNCoreproject& rst
		) {
};

void TblWdbeQPrsMNCoreproject::updateRec(
			WdbeQPrsMNCoreproject* rec
		) {
};

void TblWdbeQPrsMNCoreproject::updateRst(
			ListWdbeQPrsMNCoreproject& rst
		) {
};

void TblWdbeQPrsMNCoreproject::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQPrsMNCoreproject::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQPrsMNCoreproject::loadRecByQref(
			ubigint qref
			, WdbeQPrsMNCoreproject** rec
		) {
	return false;
};

ubigint TblWdbeQPrsMNCoreproject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrsMNCoreproject& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQPrsMNCoreproject
 ******************************************************************************/

MyTblWdbeQPrsMNCoreproject::MyTblWdbeQPrsMNCoreproject() :
			TblWdbeQPrsMNCoreproject()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQPrsMNCoreproject::~MyTblWdbeQPrsMNCoreproject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQPrsMNCoreproject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQPrsMNCoreproject (jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQPrsMNCoreproject SET jref = ?, jnum = ?, mref = ?, ref = ?, x1Startd = ?, x1Stopd = ?, srefKFunction = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQPrsMNCoreproject WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQPrsMNCoreproject WHERE jref = ?", false);
};

bool MyTblWdbeQPrsMNCoreproject::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrsMNCoreproject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQPrsMNCoreproject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrsMNCoreproject::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrsMNCoreproject::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQPrsMNCoreproject();

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

ubigint MyTblWdbeQPrsMNCoreproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrsMNCoreproject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQPrsMNCoreproject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQPrsMNCoreproject::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQPrsMNCoreproject::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQPrsMNCoreproject();

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

ubigint MyTblWdbeQPrsMNCoreproject::insertRec(
			WdbeQPrsMNCoreproject* rec
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
		string dbms = "MyTblWdbeQPrsMNCoreproject::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQPrsMNCoreproject::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQPrsMNCoreproject::insertRst(
			ListWdbeQPrsMNCoreproject& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQPrsMNCoreproject::updateRec(
			WdbeQPrsMNCoreproject* rec
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
		string dbms = "MyTblWdbeQPrsMNCoreproject::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQPrsMNCoreproject::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrsMNCoreproject::updateRst(
			ListWdbeQPrsMNCoreproject& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQPrsMNCoreproject::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQPrsMNCoreproject::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQPrsMNCoreproject::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQPrsMNCoreproject::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQPrsMNCoreproject::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQPrsMNCoreproject::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQPrsMNCoreproject::loadRecByQref(
			ubigint qref
			, WdbeQPrsMNCoreproject** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQPrsMNCoreproject WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQPrsMNCoreproject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrsMNCoreproject& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQPrsMNCoreproject WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQPrsMNCoreproject
 ******************************************************************************/

PgTblWdbeQPrsMNCoreproject::PgTblWdbeQPrsMNCoreproject() :
			TblWdbeQPrsMNCoreproject()
			, PgTable()
		{
};

PgTblWdbeQPrsMNCoreproject::~PgTblWdbeQPrsMNCoreproject() {
};

void PgTblWdbeQPrsMNCoreproject::initStatements() {
	createStatement("TblWdbeQPrsMNCoreproject_insertRec", "INSERT INTO TblWdbeQPrsMNCoreproject (jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7);
	createStatement("TblWdbeQPrsMNCoreproject_updateRec", "UPDATE TblWdbeQPrsMNCoreproject SET jref = $1, jnum = $2, mref = $3, ref = $4, x1Startd = $5, x1Stopd = $6, srefKFunction = $7 WHERE qref = $8", 8);
	createStatement("TblWdbeQPrsMNCoreproject_removeRecByQref", "DELETE FROM TblWdbeQPrsMNCoreproject WHERE qref = $1", 1);
	createStatement("TblWdbeQPrsMNCoreproject_removeRstByJref", "DELETE FROM TblWdbeQPrsMNCoreproject WHERE jref = $1", 1);

	createStatement("TblWdbeQPrsMNCoreproject_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction FROM TblWdbeQPrsMNCoreproject WHERE qref = $1", 1);
	createStatement("TblWdbeQPrsMNCoreproject_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1Startd, x1Stopd, srefKFunction FROM TblWdbeQPrsMNCoreproject WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQPrsMNCoreproject::loadRec(
			PGresult* res
			, WdbeQPrsMNCoreproject** rec
		) {
	char* ptr;

	WdbeQPrsMNCoreproject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQPrsMNCoreproject();

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

ubigint PgTblWdbeQPrsMNCoreproject::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQPrsMNCoreproject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQPrsMNCoreproject* rec;

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
			rec = new WdbeQPrsMNCoreproject();

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

bool PgTblWdbeQPrsMNCoreproject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQPrsMNCoreproject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrsMNCoreproject::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrsMNCoreproject::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQPrsMNCoreproject& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrsMNCoreproject::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQPrsMNCoreproject::loadRecBySQL(
			const string& sqlstr
			, WdbeQPrsMNCoreproject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrsMNCoreproject::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQPrsMNCoreproject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQPrsMNCoreproject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQPrsMNCoreproject::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQPrsMNCoreproject::insertRec(
			WdbeQPrsMNCoreproject* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQPrsMNCoreproject_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQPrsMNCoreproject::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQPrsMNCoreproject::insertRst(
			ListWdbeQPrsMNCoreproject& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQPrsMNCoreproject::updateRec(
			WdbeQPrsMNCoreproject* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQPrsMNCoreproject_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrsMNCoreproject::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrsMNCoreproject::updateRst(
			ListWdbeQPrsMNCoreproject& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQPrsMNCoreproject::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrsMNCoreproject_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrsMNCoreproject::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQPrsMNCoreproject::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQPrsMNCoreproject_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQPrsMNCoreproject::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQPrsMNCoreproject::loadRecByQref(
			ubigint qref
			, WdbeQPrsMNCoreproject** rec
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

	return loadRecByStmt("TblWdbeQPrsMNCoreproject_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQPrsMNCoreproject::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQPrsMNCoreproject& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQPrsMNCoreproject_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

