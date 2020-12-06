/**
	* \file WdbeQLibAMakefile.cpp
	* Dbs and XML wrapper for table TblWdbeQLibAMakefile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeQLibAMakefile.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQLibAMakefile
 ******************************************************************************/

WdbeQLibAMakefile::WdbeQLibAMakefile(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefWdbeMMachine
			, const string stubX1RefWdbeMMachine
			, const string x2SrefKTag
			, const string titX2SrefKTag
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1RefWdbeMMachine = x1RefWdbeMMachine;
	this->stubX1RefWdbeMMachine = stubX1RefWdbeMMachine;
	this->x2SrefKTag = x2SrefKTag;
	this->titX2SrefKTag = titX2SrefKTag;
	this->Val = Val;
};

void WdbeQLibAMakefile::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQLibAMakefile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mch", stubX1RefWdbeMMachine);
		writeString(wr, "tag", x2SrefKTag);
		writeString(wr, "tag2", titX2SrefKTag);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "stubX1RefWdbeMMachine", stubX1RefWdbeMMachine);
		writeString(wr, "x2SrefKTag", x2SrefKTag);
		writeString(wr, "titX2SrefKTag", titX2SrefKTag);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQLibAMakefile
 ******************************************************************************/

ListWdbeQLibAMakefile::ListWdbeQLibAMakefile() {
};

ListWdbeQLibAMakefile::ListWdbeQLibAMakefile(
			const ListWdbeQLibAMakefile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQLibAMakefile(*(src.nodes[i]));
};

ListWdbeQLibAMakefile::~ListWdbeQLibAMakefile() {
	clear();
};

void ListWdbeQLibAMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQLibAMakefile::size() const {
	return(nodes.size());
};

void ListWdbeQLibAMakefile::append(
			WdbeQLibAMakefile* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQLibAMakefile& ListWdbeQLibAMakefile::operator=(
			const ListWdbeQLibAMakefile& src
		) {
	WdbeQLibAMakefile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQLibAMakefile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQLibAMakefile::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQLibAMakefile";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQLibAMakefile
 ******************************************************************************/

TblWdbeQLibAMakefile::TblWdbeQLibAMakefile() {
};

TblWdbeQLibAMakefile::~TblWdbeQLibAMakefile() {
};

bool TblWdbeQLibAMakefile::loadRecBySQL(
			const string& sqlstr
			, WdbeQLibAMakefile** rec
		) {
	return false;
};

ubigint TblWdbeQLibAMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQLibAMakefile& rst
		) {
	return 0;
};

ubigint TblWdbeQLibAMakefile::insertRec(
			WdbeQLibAMakefile* rec
		) {
	return 0;
};

ubigint TblWdbeQLibAMakefile::insertNewRec(
			WdbeQLibAMakefile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefWdbeMMachine
			, const string stubX1RefWdbeMMachine
			, const string x2SrefKTag
			, const string titX2SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WdbeQLibAMakefile* _rec = NULL;

	_rec = new WdbeQLibAMakefile(0, jref, jnum, ref, x1RefWdbeMMachine, stubX1RefWdbeMMachine, x2SrefKTag, titX2SrefKTag, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQLibAMakefile::appendNewRecToRst(
			ListWdbeQLibAMakefile& rst
			, WdbeQLibAMakefile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefWdbeMMachine
			, const string stubX1RefWdbeMMachine
			, const string x2SrefKTag
			, const string titX2SrefKTag
			, const string Val
		) {
	ubigint retval = 0;
	WdbeQLibAMakefile* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1RefWdbeMMachine, stubX1RefWdbeMMachine, x2SrefKTag, titX2SrefKTag, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQLibAMakefile::insertRst(
			ListWdbeQLibAMakefile& rst
		) {
};

void TblWdbeQLibAMakefile::updateRec(
			WdbeQLibAMakefile* rec
		) {
};

void TblWdbeQLibAMakefile::updateRst(
			ListWdbeQLibAMakefile& rst
		) {
};

void TblWdbeQLibAMakefile::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQLibAMakefile::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQLibAMakefile::loadRecByQref(
			ubigint qref
			, WdbeQLibAMakefile** rec
		) {
	return false;
};

ubigint TblWdbeQLibAMakefile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQLibAMakefile& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQLibAMakefile
 ******************************************************************************/

MyTblWdbeQLibAMakefile::MyTblWdbeQLibAMakefile() :
			TblWdbeQLibAMakefile()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQLibAMakefile::~MyTblWdbeQLibAMakefile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQLibAMakefile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQLibAMakefile (jref, jnum, ref, x1RefWdbeMMachine, x2SrefKTag, Val) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQLibAMakefile SET jref = ?, jnum = ?, ref = ?, x1RefWdbeMMachine = ?, x2SrefKTag = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQLibAMakefile WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQLibAMakefile WHERE jref = ?", false);
};

bool MyTblWdbeQLibAMakefile::loadRecBySQL(
			const string& sqlstr
			, WdbeQLibAMakefile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQLibAMakefile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQLibAMakefile::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQLibAMakefile::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQLibAMakefile();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1RefWdbeMMachine = atoll((char*) dbrow[4]); else _rec->x1RefWdbeMMachine = 0;
		if (dbrow[5]) _rec->x2SrefKTag.assign(dbrow[5], dblengths[5]); else _rec->x2SrefKTag = "";
		if (dbrow[6]) _rec->Val.assign(dbrow[6], dblengths[6]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQLibAMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQLibAMakefile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQLibAMakefile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQLibAMakefile::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQLibAMakefile::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQLibAMakefile();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1RefWdbeMMachine = atoll((char*) dbrow[4]); else rec->x1RefWdbeMMachine = 0;
			if (dbrow[5]) rec->x2SrefKTag.assign(dbrow[5], dblengths[5]); else rec->x2SrefKTag = "";
			if (dbrow[6]) rec->Val.assign(dbrow[6], dblengths[6]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQLibAMakefile::insertRec(
			WdbeQLibAMakefile* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->x2SrefKTag.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1RefWdbeMMachine,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2SrefKTag.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQLibAMakefile::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQLibAMakefile::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQLibAMakefile::insertRst(
			ListWdbeQLibAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQLibAMakefile::updateRec(
			WdbeQLibAMakefile* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x2SrefKTag.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1RefWdbeMMachine,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2SrefKTag.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQLibAMakefile::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQLibAMakefile::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQLibAMakefile::updateRst(
			ListWdbeQLibAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQLibAMakefile::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQLibAMakefile::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQLibAMakefile::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQLibAMakefile::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQLibAMakefile::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQLibAMakefile::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQLibAMakefile::loadRecByQref(
			ubigint qref
			, WdbeQLibAMakefile** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQLibAMakefile WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQLibAMakefile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQLibAMakefile& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQLibAMakefile WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQLibAMakefile
 ******************************************************************************/

PgTblWdbeQLibAMakefile::PgTblWdbeQLibAMakefile() :
			TblWdbeQLibAMakefile()
			, PgTable()
		{
};

PgTblWdbeQLibAMakefile::~PgTblWdbeQLibAMakefile() {
};

void PgTblWdbeQLibAMakefile::initStatements() {
	createStatement("TblWdbeQLibAMakefile_insertRec", "INSERT INTO TblWdbeQLibAMakefile (jref, jnum, ref, x1RefWdbeMMachine, x2SrefKTag, Val) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWdbeQLibAMakefile_updateRec", "UPDATE TblWdbeQLibAMakefile SET jref = $1, jnum = $2, ref = $3, x1RefWdbeMMachine = $4, x2SrefKTag = $5, Val = $6 WHERE qref = $7", 7);
	createStatement("TblWdbeQLibAMakefile_removeRecByQref", "DELETE FROM TblWdbeQLibAMakefile WHERE qref = $1", 1);
	createStatement("TblWdbeQLibAMakefile_removeRstByJref", "DELETE FROM TblWdbeQLibAMakefile WHERE jref = $1", 1);

	createStatement("TblWdbeQLibAMakefile_loadRecByQref", "SELECT qref, jref, jnum, ref, x1RefWdbeMMachine, x2SrefKTag, Val FROM TblWdbeQLibAMakefile WHERE qref = $1", 1);
	createStatement("TblWdbeQLibAMakefile_loadRstByJref", "SELECT qref, jref, jnum, ref, x1RefWdbeMMachine, x2SrefKTag, Val FROM TblWdbeQLibAMakefile WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQLibAMakefile::loadRec(
			PGresult* res
			, WdbeQLibAMakefile** rec
		) {
	char* ptr;

	WdbeQLibAMakefile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQLibAMakefile();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refwdbemmachine"),
			PQfnumber(res, "x2srefktag"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1RefWdbeMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2SrefKTag.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQLibAMakefile::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQLibAMakefile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQLibAMakefile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refwdbemmachine"),
			PQfnumber(res, "x2srefktag"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WdbeQLibAMakefile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1RefWdbeMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2SrefKTag.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQLibAMakefile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQLibAMakefile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQLibAMakefile::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQLibAMakefile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQLibAMakefile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQLibAMakefile::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQLibAMakefile::loadRecBySQL(
			const string& sqlstr
			, WdbeQLibAMakefile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQLibAMakefile::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQLibAMakefile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQLibAMakefile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQLibAMakefile::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQLibAMakefile::insertRec(
			WdbeQLibAMakefile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefWdbeMMachine = htonl64(rec->x1RefWdbeMMachine);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefWdbeMMachine,
		rec->x2SrefKTag.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeQLibAMakefile_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQLibAMakefile::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQLibAMakefile::insertRst(
			ListWdbeQLibAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQLibAMakefile::updateRec(
			WdbeQLibAMakefile* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefWdbeMMachine = htonl64(rec->x1RefWdbeMMachine);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefWdbeMMachine,
		rec->x2SrefKTag.c_str(),
		rec->Val.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQLibAMakefile_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQLibAMakefile::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQLibAMakefile::updateRst(
			ListWdbeQLibAMakefile& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQLibAMakefile::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQLibAMakefile_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQLibAMakefile::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQLibAMakefile::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQLibAMakefile_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQLibAMakefile::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQLibAMakefile::loadRecByQref(
			ubigint qref
			, WdbeQLibAMakefile** rec
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

	return loadRecByStmt("TblWdbeQLibAMakefile_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQLibAMakefile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQLibAMakefile& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQLibAMakefile_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif
