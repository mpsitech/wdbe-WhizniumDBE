/**
	* \file WdbeQCmdMNController.cpp
	* Dbs and XML wrapper for table TblWdbeQCmdMNController (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQCmdMNController.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCmdMNController
 ******************************************************************************/

WdbeQCmdMNController::WdbeQCmdMNController(
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
		) :
			qref(qref)
			, jref(jref)
			, jnum(jnum)
			, mref(mref)
			, stubMref(stubMref)
			, ref(ref)
			, ivrRefWdbeMSignal(ivrRefWdbeMSignal)
			, stubIvrRefWdbeMSignal(stubIvrRefWdbeMSignal)
			, rvrRefWdbeMSignal(rvrRefWdbeMSignal)
			, stubRvrRefWdbeMSignal(stubRvrRefWdbeMSignal)
		{
};

void WdbeQCmdMNController::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["mref"] = stubMref;
		me["ivr"] = stubIvrRefWdbeMSignal;
		me["rvr"] = stubRvrRefWdbeMSignal;
	} else {
		me["stubMref"] = stubMref;
		me["stubIvrRefWdbeMSignal"] = stubIvrRefWdbeMSignal;
		me["stubRvrRefWdbeMSignal"] = stubRvrRefWdbeMSignal;
	};
};

void WdbeQCmdMNController::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQCmdMNController";

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
 class ListWdbeQCmdMNController
 ******************************************************************************/

ListWdbeQCmdMNController::ListWdbeQCmdMNController() {
};

ListWdbeQCmdMNController::ListWdbeQCmdMNController(
			const ListWdbeQCmdMNController& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCmdMNController(*(src.nodes[i]));
};

ListWdbeQCmdMNController::~ListWdbeQCmdMNController() {
	clear();
};

void ListWdbeQCmdMNController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQCmdMNController::size() const {
	return(nodes.size());
};

void ListWdbeQCmdMNController::append(
			WdbeQCmdMNController* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQCmdMNController& ListWdbeQCmdMNController::operator=(
			const ListWdbeQCmdMNController& src
		) {
	WdbeQCmdMNController* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQCmdMNController(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQCmdMNController::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQCmdMNController";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQCmdMNController::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQCmdMNController";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQCmdMNController
 ******************************************************************************/

TblWdbeQCmdMNController::TblWdbeQCmdMNController() {
};

TblWdbeQCmdMNController::~TblWdbeQCmdMNController() {
};

bool TblWdbeQCmdMNController::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdMNController** rec
		) {
	return false;
};

ubigint TblWdbeQCmdMNController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdMNController& rst
		) {
	return 0;
};

ubigint TblWdbeQCmdMNController::insertRec(
			WdbeQCmdMNController* rec
		) {
	return 0;
};

ubigint TblWdbeQCmdMNController::insertNewRec(
			WdbeQCmdMNController** rec
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
	WdbeQCmdMNController* _rec = NULL;

	_rec = new WdbeQCmdMNController(0, jref, jnum, mref, stubMref, ref, ivrRefWdbeMSignal, stubIvrRefWdbeMSignal, rvrRefWdbeMSignal, stubRvrRefWdbeMSignal);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQCmdMNController::appendNewRecToRst(
			ListWdbeQCmdMNController& rst
			, WdbeQCmdMNController** rec
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
	WdbeQCmdMNController* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ivrRefWdbeMSignal, stubIvrRefWdbeMSignal, rvrRefWdbeMSignal, stubRvrRefWdbeMSignal);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQCmdMNController::insertRst(
			ListWdbeQCmdMNController& rst
		) {
};

void TblWdbeQCmdMNController::updateRec(
			WdbeQCmdMNController* rec
		) {
};

void TblWdbeQCmdMNController::updateRst(
			ListWdbeQCmdMNController& rst
		) {
};

void TblWdbeQCmdMNController::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQCmdMNController::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQCmdMNController::loadRecByQref(
			ubigint qref
			, WdbeQCmdMNController** rec
		) {
	return false;
};

ubigint TblWdbeQCmdMNController::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdMNController& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQCmdMNController
 ******************************************************************************/

MyTblWdbeQCmdMNController::MyTblWdbeQCmdMNController() :
			TblWdbeQCmdMNController()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQCmdMNController::~MyTblWdbeQCmdMNController() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQCmdMNController::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQCmdMNController (jref, jnum, mref, ref, ivrRefWdbeMSignal, rvrRefWdbeMSignal) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQCmdMNController SET jref = ?, jnum = ?, mref = ?, ref = ?, ivrRefWdbeMSignal = ?, rvrRefWdbeMSignal = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQCmdMNController WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQCmdMNController WHERE jref = ?", false);
};

bool MyTblWdbeQCmdMNController::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdMNController** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQCmdMNController* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCmdMNController::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCmdMNController::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQCmdMNController();

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

ubigint MyTblWdbeQCmdMNController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdMNController& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQCmdMNController* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCmdMNController::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCmdMNController::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQCmdMNController();

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

ubigint MyTblWdbeQCmdMNController::insertRec(
			WdbeQCmdMNController* rec
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
		string dbms = "MyTblWdbeQCmdMNController::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQCmdMNController::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQCmdMNController::insertRst(
			ListWdbeQCmdMNController& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQCmdMNController::updateRec(
			WdbeQCmdMNController* rec
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
		string dbms = "MyTblWdbeQCmdMNController::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQCmdMNController::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCmdMNController::updateRst(
			ListWdbeQCmdMNController& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQCmdMNController::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQCmdMNController::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQCmdMNController::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCmdMNController::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQCmdMNController::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQCmdMNController::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQCmdMNController::loadRecByQref(
			ubigint qref
			, WdbeQCmdMNController** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQCmdMNController WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQCmdMNController::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdMNController& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQCmdMNController WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQCmdMNController
 ******************************************************************************/

PgTblWdbeQCmdMNController::PgTblWdbeQCmdMNController() :
			TblWdbeQCmdMNController()
			, PgTable()
		{
};

PgTblWdbeQCmdMNController::~PgTblWdbeQCmdMNController() {
};

void PgTblWdbeQCmdMNController::initStatements() {
	createStatement("TblWdbeQCmdMNController_insertRec", "INSERT INTO TblWdbeQCmdMNController (jref, jnum, mref, ref, ivrRefWdbeMSignal, rvrRefWdbeMSignal) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWdbeQCmdMNController_updateRec", "UPDATE TblWdbeQCmdMNController SET jref = $1, jnum = $2, mref = $3, ref = $4, ivrRefWdbeMSignal = $5, rvrRefWdbeMSignal = $6 WHERE qref = $7", 7);
	createStatement("TblWdbeQCmdMNController_removeRecByQref", "DELETE FROM TblWdbeQCmdMNController WHERE qref = $1", 1);
	createStatement("TblWdbeQCmdMNController_removeRstByJref", "DELETE FROM TblWdbeQCmdMNController WHERE jref = $1", 1);

	createStatement("TblWdbeQCmdMNController_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ivrRefWdbeMSignal, rvrRefWdbeMSignal FROM TblWdbeQCmdMNController WHERE qref = $1", 1);
	createStatement("TblWdbeQCmdMNController_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ivrRefWdbeMSignal, rvrRefWdbeMSignal FROM TblWdbeQCmdMNController WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQCmdMNController::loadRec(
			PGresult* res
			, WdbeQCmdMNController** rec
		) {
	char* ptr;

	WdbeQCmdMNController* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQCmdMNController();

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

ubigint PgTblWdbeQCmdMNController::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQCmdMNController& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQCmdMNController* rec;

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
			rec = new WdbeQCmdMNController();

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

bool PgTblWdbeQCmdMNController::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQCmdMNController** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdMNController::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCmdMNController::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQCmdMNController& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdMNController::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQCmdMNController::loadRecBySQL(
			const string& sqlstr
			, WdbeQCmdMNController** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCmdMNController::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCmdMNController::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCmdMNController& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCmdMNController::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQCmdMNController::insertRec(
			WdbeQCmdMNController* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQCmdMNController_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCmdMNController::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQCmdMNController::insertRst(
			ListWdbeQCmdMNController& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQCmdMNController::updateRec(
			WdbeQCmdMNController* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQCmdMNController_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdMNController::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCmdMNController::updateRst(
			ListWdbeQCmdMNController& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQCmdMNController::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCmdMNController_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdMNController::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCmdMNController::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCmdMNController_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCmdMNController::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQCmdMNController::loadRecByQref(
			ubigint qref
			, WdbeQCmdMNController** rec
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

	return loadRecByStmt("TblWdbeQCmdMNController_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQCmdMNController::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCmdMNController& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQCmdMNController_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
