/**
	* \file WdbeQModCtrMNCommand.cpp
	* Dbs and XML wrapper for table TblWdbeQModCtrMNCommand (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQModCtrMNCommand.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQModCtrMNCommand
 ******************************************************************************/

WdbeQModCtrMNCommand::WdbeQModCtrMNCommand(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint ivrRefWdbeMSignal
			, const string stubIvrRefWdbeMSignal
			, const ubigint rvrRefWdbeMSignal
			, const string stubRvrRefWdbeMSignal
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->ivrRefWdbeMSignal = ivrRefWdbeMSignal;
	this->stubIvrRefWdbeMSignal = stubIvrRefWdbeMSignal;
	this->rvrRefWdbeMSignal = rvrRefWdbeMSignal;
	this->stubRvrRefWdbeMSignal = stubRvrRefWdbeMSignal;
};

void WdbeQModCtrMNCommand::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQModCtrMNCommand";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "ivr", stubIvrRefWdbeMSignal);
		writeString(wr, "rvr", stubRvrRefWdbeMSignal);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "stubIvrRefWdbeMSignal", stubIvrRefWdbeMSignal);
		writeString(wr, "stubRvrRefWdbeMSignal", stubRvrRefWdbeMSignal);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQModCtrMNCommand
 ******************************************************************************/

ListWdbeQModCtrMNCommand::ListWdbeQModCtrMNCommand() {
};

ListWdbeQModCtrMNCommand::ListWdbeQModCtrMNCommand(
			const ListWdbeQModCtrMNCommand& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQModCtrMNCommand(*(src.nodes[i]));
};

ListWdbeQModCtrMNCommand::~ListWdbeQModCtrMNCommand() {
	clear();
};

void ListWdbeQModCtrMNCommand::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQModCtrMNCommand::size() const {
	return(nodes.size());
};

void ListWdbeQModCtrMNCommand::append(
			WdbeQModCtrMNCommand* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQModCtrMNCommand& ListWdbeQModCtrMNCommand::operator=(
			const ListWdbeQModCtrMNCommand& src
		) {
	WdbeQModCtrMNCommand* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQModCtrMNCommand(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQModCtrMNCommand::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQModCtrMNCommand";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQModCtrMNCommand
 ******************************************************************************/

TblWdbeQModCtrMNCommand::TblWdbeQModCtrMNCommand() {
};

TblWdbeQModCtrMNCommand::~TblWdbeQModCtrMNCommand() {
};

bool TblWdbeQModCtrMNCommand::loadRecBySQL(
			const string& sqlstr
			, WdbeQModCtrMNCommand** rec
		) {
	return false;
};

ubigint TblWdbeQModCtrMNCommand::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModCtrMNCommand& rst
		) {
	return 0;
};

ubigint TblWdbeQModCtrMNCommand::insertRec(
			WdbeQModCtrMNCommand* rec
		) {
	return 0;
};

ubigint TblWdbeQModCtrMNCommand::insertNewRec(
			WdbeQModCtrMNCommand** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint ivrRefWdbeMSignal
			, const string stubIvrRefWdbeMSignal
			, const ubigint rvrRefWdbeMSignal
			, const string stubRvrRefWdbeMSignal
		) {
	ubigint retval = 0;
	WdbeQModCtrMNCommand* _rec = NULL;

	_rec = new WdbeQModCtrMNCommand(0, jref, jnum, mref, stubMref, ref, ivrRefWdbeMSignal, stubIvrRefWdbeMSignal, rvrRefWdbeMSignal, stubRvrRefWdbeMSignal);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQModCtrMNCommand::appendNewRecToRst(
			ListWdbeQModCtrMNCommand& rst
			, WdbeQModCtrMNCommand** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint ivrRefWdbeMSignal
			, const string stubIvrRefWdbeMSignal
			, const ubigint rvrRefWdbeMSignal
			, const string stubRvrRefWdbeMSignal
		) {
	ubigint retval = 0;
	WdbeQModCtrMNCommand* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ivrRefWdbeMSignal, stubIvrRefWdbeMSignal, rvrRefWdbeMSignal, stubRvrRefWdbeMSignal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQModCtrMNCommand::insertRst(
			ListWdbeQModCtrMNCommand& rst
		) {
};

void TblWdbeQModCtrMNCommand::updateRec(
			WdbeQModCtrMNCommand* rec
		) {
};

void TblWdbeQModCtrMNCommand::updateRst(
			ListWdbeQModCtrMNCommand& rst
		) {
};

void TblWdbeQModCtrMNCommand::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQModCtrMNCommand::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQModCtrMNCommand::loadRecByQref(
			ubigint qref
			, WdbeQModCtrMNCommand** rec
		) {
	return false;
};

ubigint TblWdbeQModCtrMNCommand::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModCtrMNCommand& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQModCtrMNCommand
 ******************************************************************************/

MyTblWdbeQModCtrMNCommand::MyTblWdbeQModCtrMNCommand() :
			TblWdbeQModCtrMNCommand()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQModCtrMNCommand::~MyTblWdbeQModCtrMNCommand() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQModCtrMNCommand::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQModCtrMNCommand (jref, jnum, mref, ref, ivrRefWdbeMSignal, rvrRefWdbeMSignal) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQModCtrMNCommand SET jref = ?, jnum = ?, mref = ?, ref = ?, ivrRefWdbeMSignal = ?, rvrRefWdbeMSignal = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQModCtrMNCommand WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQModCtrMNCommand WHERE jref = ?", false);
};

bool MyTblWdbeQModCtrMNCommand::loadRecBySQL(
			const string& sqlstr
			, WdbeQModCtrMNCommand** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQModCtrMNCommand* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModCtrMNCommand::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModCtrMNCommand::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQModCtrMNCommand();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ivrRefWdbeMSignal = atoll((char*) dbrow[5]); else _rec->ivrRefWdbeMSignal = 0;
		if (dbrow[6]) _rec->rvrRefWdbeMSignal = atoll((char*) dbrow[6]); else _rec->rvrRefWdbeMSignal = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQModCtrMNCommand::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModCtrMNCommand& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQModCtrMNCommand* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQModCtrMNCommand::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQModCtrMNCommand::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQModCtrMNCommand();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ivrRefWdbeMSignal = atoll((char*) dbrow[5]); else rec->ivrRefWdbeMSignal = 0;
			if (dbrow[6]) rec->rvrRefWdbeMSignal = atoll((char*) dbrow[6]); else rec->rvrRefWdbeMSignal = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQModCtrMNCommand::insertRec(
			WdbeQModCtrMNCommand* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ivrRefWdbeMSignal,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->rvrRefWdbeMSignal,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQModCtrMNCommand::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQModCtrMNCommand::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQModCtrMNCommand::insertRst(
			ListWdbeQModCtrMNCommand& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQModCtrMNCommand::updateRec(
			WdbeQModCtrMNCommand* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ivrRefWdbeMSignal,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->rvrRefWdbeMSignal,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQModCtrMNCommand::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQModCtrMNCommand::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModCtrMNCommand::updateRst(
			ListWdbeQModCtrMNCommand& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQModCtrMNCommand::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQModCtrMNCommand::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQModCtrMNCommand::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQModCtrMNCommand::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQModCtrMNCommand::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQModCtrMNCommand::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQModCtrMNCommand::loadRecByQref(
			ubigint qref
			, WdbeQModCtrMNCommand** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQModCtrMNCommand WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQModCtrMNCommand::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModCtrMNCommand& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQModCtrMNCommand WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQModCtrMNCommand
 ******************************************************************************/

PgTblWdbeQModCtrMNCommand::PgTblWdbeQModCtrMNCommand() :
			TblWdbeQModCtrMNCommand()
			, PgTable()
		{
};

PgTblWdbeQModCtrMNCommand::~PgTblWdbeQModCtrMNCommand() {
};

void PgTblWdbeQModCtrMNCommand::initStatements() {
	createStatement("TblWdbeQModCtrMNCommand_insertRec", "INSERT INTO TblWdbeQModCtrMNCommand (jref, jnum, mref, ref, ivrRefWdbeMSignal, rvrRefWdbeMSignal) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWdbeQModCtrMNCommand_updateRec", "UPDATE TblWdbeQModCtrMNCommand SET jref = $1, jnum = $2, mref = $3, ref = $4, ivrRefWdbeMSignal = $5, rvrRefWdbeMSignal = $6 WHERE qref = $7", 7);
	createStatement("TblWdbeQModCtrMNCommand_removeRecByQref", "DELETE FROM TblWdbeQModCtrMNCommand WHERE qref = $1", 1);
	createStatement("TblWdbeQModCtrMNCommand_removeRstByJref", "DELETE FROM TblWdbeQModCtrMNCommand WHERE jref = $1", 1);

	createStatement("TblWdbeQModCtrMNCommand_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ivrRefWdbeMSignal, rvrRefWdbeMSignal FROM TblWdbeQModCtrMNCommand WHERE qref = $1", 1);
	createStatement("TblWdbeQModCtrMNCommand_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ivrRefWdbeMSignal, rvrRefWdbeMSignal FROM TblWdbeQModCtrMNCommand WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQModCtrMNCommand::loadRec(
			PGresult* res
			, WdbeQModCtrMNCommand** rec
		) {
	char* ptr;

	WdbeQModCtrMNCommand* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQModCtrMNCommand();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ivrrefwdbemsignal"),
			PQfnumber(res, "rvrrefwdbemsignal")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ivrRefWdbeMSignal = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->rvrRefWdbeMSignal = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQModCtrMNCommand::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQModCtrMNCommand& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQModCtrMNCommand* rec;

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
			PQfnumber(res, "ivrrefwdbemsignal"),
			PQfnumber(res, "rvrrefwdbemsignal")
		};

		while (numread < numrow) {
			rec = new WdbeQModCtrMNCommand();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ivrRefWdbeMSignal = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->rvrRefWdbeMSignal = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQModCtrMNCommand::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQModCtrMNCommand** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModCtrMNCommand::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModCtrMNCommand::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQModCtrMNCommand& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModCtrMNCommand::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQModCtrMNCommand::loadRecBySQL(
			const string& sqlstr
			, WdbeQModCtrMNCommand** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModCtrMNCommand::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQModCtrMNCommand::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQModCtrMNCommand& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQModCtrMNCommand::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQModCtrMNCommand::insertRec(
			WdbeQModCtrMNCommand* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _ivrRefWdbeMSignal = htonl64(rec->ivrRefWdbeMSignal);
	ubigint _rvrRefWdbeMSignal = htonl64(rec->rvrRefWdbeMSignal);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ivrRefWdbeMSignal,
		(char*) &_rvrRefWdbeMSignal
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQModCtrMNCommand_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQModCtrMNCommand::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQModCtrMNCommand::insertRst(
			ListWdbeQModCtrMNCommand& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQModCtrMNCommand::updateRec(
			WdbeQModCtrMNCommand* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _ivrRefWdbeMSignal = htonl64(rec->ivrRefWdbeMSignal);
	ubigint _rvrRefWdbeMSignal = htonl64(rec->rvrRefWdbeMSignal);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ivrRefWdbeMSignal,
		(char*) &_rvrRefWdbeMSignal,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQModCtrMNCommand_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModCtrMNCommand::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModCtrMNCommand::updateRst(
			ListWdbeQModCtrMNCommand& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQModCtrMNCommand::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModCtrMNCommand_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModCtrMNCommand::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQModCtrMNCommand::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQModCtrMNCommand_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQModCtrMNCommand::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQModCtrMNCommand::loadRecByQref(
			ubigint qref
			, WdbeQModCtrMNCommand** rec
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

	return loadRecByStmt("TblWdbeQModCtrMNCommand_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQModCtrMNCommand::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQModCtrMNCommand& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQModCtrMNCommand_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
