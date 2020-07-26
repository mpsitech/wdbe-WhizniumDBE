/**
	* \file WdbeQCvrBcv1NCoreversion.cpp
	* Dbs and XML wrapper for table TblWdbeQCvrBcv1NCoreversion (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeQCvrBcv1NCoreversion.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQCvrBcv1NCoreversion
 ******************************************************************************/

WdbeQCvrBcv1NCoreversion::WdbeQCvrBcv1NCoreversion(
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

void WdbeQCvrBcv1NCoreversion::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQCvrBcv1NCoreversion";

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
 class ListWdbeQCvrBcv1NCoreversion
 ******************************************************************************/

ListWdbeQCvrBcv1NCoreversion::ListWdbeQCvrBcv1NCoreversion() {
};

ListWdbeQCvrBcv1NCoreversion::ListWdbeQCvrBcv1NCoreversion(
			const ListWdbeQCvrBcv1NCoreversion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQCvrBcv1NCoreversion(*(src.nodes[i]));
};

ListWdbeQCvrBcv1NCoreversion::~ListWdbeQCvrBcv1NCoreversion() {
	clear();
};

void ListWdbeQCvrBcv1NCoreversion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQCvrBcv1NCoreversion::size() const {
	return(nodes.size());
};

void ListWdbeQCvrBcv1NCoreversion::append(
			WdbeQCvrBcv1NCoreversion* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQCvrBcv1NCoreversion& ListWdbeQCvrBcv1NCoreversion::operator=(
			const ListWdbeQCvrBcv1NCoreversion& src
		) {
	WdbeQCvrBcv1NCoreversion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQCvrBcv1NCoreversion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQCvrBcv1NCoreversion::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQCvrBcv1NCoreversion";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQCvrBcv1NCoreversion
 ******************************************************************************/

TblWdbeQCvrBcv1NCoreversion::TblWdbeQCvrBcv1NCoreversion() {
};

TblWdbeQCvrBcv1NCoreversion::~TblWdbeQCvrBcv1NCoreversion() {
};

bool TblWdbeQCvrBcv1NCoreversion::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrBcv1NCoreversion** rec
		) {
	return false;
};

ubigint TblWdbeQCvrBcv1NCoreversion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrBcv1NCoreversion& rst
		) {
	return 0;
};

ubigint TblWdbeQCvrBcv1NCoreversion::insertRec(
			WdbeQCvrBcv1NCoreversion* rec
		) {
	return 0;
};

ubigint TblWdbeQCvrBcv1NCoreversion::insertNewRec(
			WdbeQCvrBcv1NCoreversion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQCvrBcv1NCoreversion* _rec = NULL;

	_rec = new WdbeQCvrBcv1NCoreversion(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQCvrBcv1NCoreversion::appendNewRecToRst(
			ListWdbeQCvrBcv1NCoreversion& rst
			, WdbeQCvrBcv1NCoreversion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	WdbeQCvrBcv1NCoreversion* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQCvrBcv1NCoreversion::insertRst(
			ListWdbeQCvrBcv1NCoreversion& rst
		) {
};

void TblWdbeQCvrBcv1NCoreversion::updateRec(
			WdbeQCvrBcv1NCoreversion* rec
		) {
};

void TblWdbeQCvrBcv1NCoreversion::updateRst(
			ListWdbeQCvrBcv1NCoreversion& rst
		) {
};

void TblWdbeQCvrBcv1NCoreversion::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQCvrBcv1NCoreversion::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQCvrBcv1NCoreversion::loadRecByQref(
			ubigint qref
			, WdbeQCvrBcv1NCoreversion** rec
		) {
	return false;
};

ubigint TblWdbeQCvrBcv1NCoreversion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrBcv1NCoreversion& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQCvrBcv1NCoreversion
 ******************************************************************************/

MyTblWdbeQCvrBcv1NCoreversion::MyTblWdbeQCvrBcv1NCoreversion() :
			TblWdbeQCvrBcv1NCoreversion()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQCvrBcv1NCoreversion::~MyTblWdbeQCvrBcv1NCoreversion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQCvrBcv1NCoreversion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQCvrBcv1NCoreversion (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQCvrBcv1NCoreversion SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQCvrBcv1NCoreversion WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQCvrBcv1NCoreversion WHERE jref = ?", false);
};

bool MyTblWdbeQCvrBcv1NCoreversion::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrBcv1NCoreversion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQCvrBcv1NCoreversion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeQCvrBcv1NCoreversion();

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

ubigint MyTblWdbeQCvrBcv1NCoreversion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrBcv1NCoreversion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQCvrBcv1NCoreversion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeQCvrBcv1NCoreversion();

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

ubigint MyTblWdbeQCvrBcv1NCoreversion::insertRec(
			WdbeQCvrBcv1NCoreversion* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQCvrBcv1NCoreversion::insertRst(
			ListWdbeQCvrBcv1NCoreversion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQCvrBcv1NCoreversion::updateRec(
			WdbeQCvrBcv1NCoreversion* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCvrBcv1NCoreversion::updateRst(
			ListWdbeQCvrBcv1NCoreversion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQCvrBcv1NCoreversion::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQCvrBcv1NCoreversion::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQCvrBcv1NCoreversion::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQCvrBcv1NCoreversion::loadRecByQref(
			ubigint qref
			, WdbeQCvrBcv1NCoreversion** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQCvrBcv1NCoreversion WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQCvrBcv1NCoreversion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrBcv1NCoreversion& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQCvrBcv1NCoreversion WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQCvrBcv1NCoreversion
 ******************************************************************************/

PgTblWdbeQCvrBcv1NCoreversion::PgTblWdbeQCvrBcv1NCoreversion() :
			TblWdbeQCvrBcv1NCoreversion()
			, PgTable()
		{
};

PgTblWdbeQCvrBcv1NCoreversion::~PgTblWdbeQCvrBcv1NCoreversion() {
};

void PgTblWdbeQCvrBcv1NCoreversion::initStatements() {
	createStatement("TblWdbeQCvrBcv1NCoreversion_insertRec", "INSERT INTO TblWdbeQCvrBcv1NCoreversion (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3);
	createStatement("TblWdbeQCvrBcv1NCoreversion_updateRec", "UPDATE TblWdbeQCvrBcv1NCoreversion SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4);
	createStatement("TblWdbeQCvrBcv1NCoreversion_removeRecByQref", "DELETE FROM TblWdbeQCvrBcv1NCoreversion WHERE qref = $1", 1);
	createStatement("TblWdbeQCvrBcv1NCoreversion_removeRstByJref", "DELETE FROM TblWdbeQCvrBcv1NCoreversion WHERE jref = $1", 1);

	createStatement("TblWdbeQCvrBcv1NCoreversion_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblWdbeQCvrBcv1NCoreversion WHERE qref = $1", 1);
	createStatement("TblWdbeQCvrBcv1NCoreversion_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblWdbeQCvrBcv1NCoreversion WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQCvrBcv1NCoreversion::loadRec(
			PGresult* res
			, WdbeQCvrBcv1NCoreversion** rec
		) {
	char* ptr;

	WdbeQCvrBcv1NCoreversion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQCvrBcv1NCoreversion();

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

ubigint PgTblWdbeQCvrBcv1NCoreversion::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQCvrBcv1NCoreversion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQCvrBcv1NCoreversion* rec;

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
			rec = new WdbeQCvrBcv1NCoreversion();

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

bool PgTblWdbeQCvrBcv1NCoreversion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQCvrBcv1NCoreversion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrBcv1NCoreversion::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCvrBcv1NCoreversion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQCvrBcv1NCoreversion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrBcv1NCoreversion::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQCvrBcv1NCoreversion::loadRecBySQL(
			const string& sqlstr
			, WdbeQCvrBcv1NCoreversion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCvrBcv1NCoreversion::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQCvrBcv1NCoreversion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQCvrBcv1NCoreversion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQCvrBcv1NCoreversion::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQCvrBcv1NCoreversion::insertRec(
			WdbeQCvrBcv1NCoreversion* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQCvrBcv1NCoreversion_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQCvrBcv1NCoreversion::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQCvrBcv1NCoreversion::insertRst(
			ListWdbeQCvrBcv1NCoreversion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQCvrBcv1NCoreversion::updateRec(
			WdbeQCvrBcv1NCoreversion* rec
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

	res = PQexecPrepared(dbs, "TblWdbeQCvrBcv1NCoreversion_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrBcv1NCoreversion::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCvrBcv1NCoreversion::updateRst(
			ListWdbeQCvrBcv1NCoreversion& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQCvrBcv1NCoreversion::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCvrBcv1NCoreversion_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrBcv1NCoreversion::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQCvrBcv1NCoreversion::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQCvrBcv1NCoreversion_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQCvrBcv1NCoreversion::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQCvrBcv1NCoreversion::loadRecByQref(
			ubigint qref
			, WdbeQCvrBcv1NCoreversion** rec
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

	return loadRecByStmt("TblWdbeQCvrBcv1NCoreversion_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQCvrBcv1NCoreversion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQCvrBcv1NCoreversion& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQCvrBcv1NCoreversion_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

