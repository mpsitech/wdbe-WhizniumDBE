/**
	* \file WdbeQMod1NCdc.cpp
	* Dbs and XML wrapper for table TblWdbeQMod1NCdc (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

#include "WdbeQMod1NCdc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQMod1NCdc
 ******************************************************************************/

WdbeQMod1NCdc::WdbeQMod1NCdc(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void WdbeQMod1NCdc::writeJSON(
			Json::Value& sup
			, bool jnumattr
			, bool shorttags
		) {
	Json::Value& me = sup.append(Json::Value(Json::objectValue));

	if (jnumattr) me["jnum"] = jnum;
	if (shorttags) {
		me["ref"] = stubRef;
	} else {
		me["stubRef"] = stubRef;
	};
};

void WdbeQMod1NCdc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQMod1NCdc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQMod1NCdc
 ******************************************************************************/

ListWdbeQMod1NCdc::ListWdbeQMod1NCdc() {
};

ListWdbeQMod1NCdc::ListWdbeQMod1NCdc(
			const ListWdbeQMod1NCdc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQMod1NCdc(*(src.nodes[i]));
};

ListWdbeQMod1NCdc::~ListWdbeQMod1NCdc() {
	clear();
};

void ListWdbeQMod1NCdc::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQMod1NCdc::size() const {
	return(nodes.size());
};

void ListWdbeQMod1NCdc::append(
			WdbeQMod1NCdc* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQMod1NCdc& ListWdbeQMod1NCdc::operator=(
			const ListWdbeQMod1NCdc& src
		) {
	WdbeQMod1NCdc* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQMod1NCdc(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQMod1NCdc::writeJSON(
			Json::Value& sup
			, std::string difftag
		) {
	if (difftag == "") difftag = "ListWdbeQMod1NCdc";

	Json::Value& me = sup[difftag] = Json::Value(Json::arrayValue);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeJSON(me, true, true);
};

void ListWdbeQMod1NCdc::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQMod1NCdc";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQMod1NCdc
 ******************************************************************************/

TblWdbeQMod1NCdc::TblWdbeQMod1NCdc() {
};

TblWdbeQMod1NCdc::~TblWdbeQMod1NCdc() {
};

bool TblWdbeQMod1NCdc::loadRecBySQL(
			const string& sqlstr
			, WdbeQMod1NCdc** rec
		) {
	return false;
};

ubigint TblWdbeQMod1NCdc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMod1NCdc& rst
		) {
	return 0;
};

ubigint TblWdbeQMod1NCdc::insertRec(
			WdbeQMod1NCdc* rec
		) {
	return 0;
};

ubigint TblWdbeQMod1NCdc::insertNewRec(
			WdbeQMod1NCdc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQMod1NCdc* _rec = NULL;

	_rec = new WdbeQMod1NCdc(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQMod1NCdc::appendNewRecToRst(
			ListWdbeQMod1NCdc& rst
			, WdbeQMod1NCdc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQMod1NCdc* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQMod1NCdc::insertRst(
			ListWdbeQMod1NCdc& rst
		) {
};

void TblWdbeQMod1NCdc::updateRec(
			WdbeQMod1NCdc* rec
		) {
};

void TblWdbeQMod1NCdc::updateRst(
			ListWdbeQMod1NCdc& rst
		) {
};

void TblWdbeQMod1NCdc::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQMod1NCdc::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQMod1NCdc::loadRecByQref(
			ubigint qref
			, WdbeQMod1NCdc** rec
		) {
	return false;
};

ubigint TblWdbeQMod1NCdc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMod1NCdc& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQMod1NCdc
 ******************************************************************************/

MyTblWdbeQMod1NCdc::MyTblWdbeQMod1NCdc() :
			TblWdbeQMod1NCdc()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQMod1NCdc::~MyTblWdbeQMod1NCdc() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQMod1NCdc::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQMod1NCdc (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQMod1NCdc SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQMod1NCdc WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQMod1NCdc WHERE jref = ?", false);
};

bool MyTblWdbeQMod1NCdc::loadRecBySQL(
			const string& sqlstr
			, WdbeQMod1NCdc** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQMod1NCdc* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQMod1NCdc::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQMod1NCdc::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQMod1NCdc();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQMod1NCdc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMod1NCdc& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQMod1NCdc* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQMod1NCdc::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQMod1NCdc::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQMod1NCdc();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQMod1NCdc::insertRec(
			WdbeQMod1NCdc* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQMod1NCdc::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQMod1NCdc::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQMod1NCdc::insertRst(
			ListWdbeQMod1NCdc& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQMod1NCdc::updateRec(
			WdbeQMod1NCdc* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQMod1NCdc::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQMod1NCdc::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQMod1NCdc::updateRst(
			ListWdbeQMod1NCdc& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQMod1NCdc::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQMod1NCdc::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQMod1NCdc::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQMod1NCdc::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQMod1NCdc::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQMod1NCdc::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQMod1NCdc::loadRecByQref(
			ubigint qref
			, WdbeQMod1NCdc** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQMod1NCdc WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQMod1NCdc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMod1NCdc& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQMod1NCdc WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQMod1NCdc
 ******************************************************************************/

PgTblWdbeQMod1NCdc::PgTblWdbeQMod1NCdc() :
			TblWdbeQMod1NCdc()
			, PgTable()
		{
};

PgTblWdbeQMod1NCdc::~PgTblWdbeQMod1NCdc() {
};

void PgTblWdbeQMod1NCdc::initStatements() {
	createStatement("TblWdbeQMod1NCdc_insertRec", "INSERT INTO TblWdbeQMod1NCdc (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWdbeQMod1NCdc_updateRec", "UPDATE TblWdbeQMod1NCdc SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWdbeQMod1NCdc_removeRecByQref", "DELETE FROM TblWdbeQMod1NCdc WHERE qref = $1", 1);
	createStatement("TblWdbeQMod1NCdc_removeRstByJref", "DELETE FROM TblWdbeQMod1NCdc WHERE jref = $1", 1);

	createStatement("TblWdbeQMod1NCdc_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWdbeQMod1NCdc WHERE qref = $1", 1);
	createStatement("TblWdbeQMod1NCdc_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWdbeQMod1NCdc WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQMod1NCdc::loadRec(
			PGresult* res
			, WdbeQMod1NCdc** rec
		) {
	char* ptr;

	WdbeQMod1NCdc* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQMod1NCdc();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQMod1NCdc::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQMod1NCdc& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQMod1NCdc* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new WdbeQMod1NCdc();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQMod1NCdc::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQMod1NCdc** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMod1NCdc::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQMod1NCdc::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQMod1NCdc& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMod1NCdc::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQMod1NCdc::loadRecBySQL(
			const string& sqlstr
			, WdbeQMod1NCdc** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQMod1NCdc::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQMod1NCdc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQMod1NCdc& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQMod1NCdc::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQMod1NCdc::insertRec(
			WdbeQMod1NCdc* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQMod1NCdc_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQMod1NCdc::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQMod1NCdc::insertRst(
			ListWdbeQMod1NCdc& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQMod1NCdc::updateRec(
			WdbeQMod1NCdc* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQMod1NCdc_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMod1NCdc::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQMod1NCdc::updateRst(
			ListWdbeQMod1NCdc& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQMod1NCdc::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQMod1NCdc_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMod1NCdc::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQMod1NCdc::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQMod1NCdc_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQMod1NCdc::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQMod1NCdc::loadRecByQref(
			ubigint qref
			, WdbeQMod1NCdc** rec
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

	return loadRecByStmt("TblWdbeQMod1NCdc_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQMod1NCdc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQMod1NCdc& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQMod1NCdc_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
