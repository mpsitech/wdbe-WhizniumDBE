/**
	* \file WdbeQUsgAAccess.cpp
	* Dbs and XML wrapper for table TblWdbeQUsgAAccess (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQUsgAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQUsgAAccess
 ******************************************************************************/

WdbeQUsgAAccess::WdbeQUsgAAccess(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWdbeVFeatgroup
			, const string srefX1IxWdbeVFeatgroup
			, const string titX1IxWdbeVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWdbeWAccess
			, const string srefsIxWdbeWAccess
			, const string titsIxWdbeWAccess
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1IxWdbeVFeatgroup = x1IxWdbeVFeatgroup;
	this->srefX1IxWdbeVFeatgroup = srefX1IxWdbeVFeatgroup;
	this->titX1IxWdbeVFeatgroup = titX1IxWdbeVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWdbeWAccess = ixWdbeWAccess;
	this->srefsIxWdbeWAccess = srefsIxWdbeWAccess;
	this->titsIxWdbeWAccess = titsIxWdbeWAccess;
};

void WdbeQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQUsgAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "feg", srefX1IxWdbeVFeatgroup);
		writeString(wr, "feg2", titX1IxWdbeVFeatgroup);
		writeString(wr, "fea", x2FeaSrefUix);
		writeString(wr, "acc", srefsIxWdbeWAccess);
		writeString(wr, "acc2", titsIxWdbeWAccess);
	} else {
		writeString(wr, "srefX1IxWdbeVFeatgroup", srefX1IxWdbeVFeatgroup);
		writeString(wr, "titX1IxWdbeVFeatgroup", titX1IxWdbeVFeatgroup);
		writeString(wr, "x2FeaSrefUix", x2FeaSrefUix);
		writeString(wr, "srefsIxWdbeWAccess", srefsIxWdbeWAccess);
		writeString(wr, "titsIxWdbeWAccess", titsIxWdbeWAccess);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQUsgAAccess
 ******************************************************************************/

ListWdbeQUsgAAccess::ListWdbeQUsgAAccess() {
};

ListWdbeQUsgAAccess::ListWdbeQUsgAAccess(
			const ListWdbeQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQUsgAAccess(*(src.nodes[i]));
};

ListWdbeQUsgAAccess::~ListWdbeQUsgAAccess() {
	clear();
};

void ListWdbeQUsgAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQUsgAAccess::size() const {
	return(nodes.size());
};

void ListWdbeQUsgAAccess::append(
			WdbeQUsgAAccess* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQUsgAAccess& ListWdbeQUsgAAccess::operator=(
			const ListWdbeQUsgAAccess& src
		) {
	WdbeQUsgAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQUsgAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQUsgAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQUsgAAccess
 ******************************************************************************/

TblWdbeQUsgAAccess::TblWdbeQUsgAAccess() {
};

TblWdbeQUsgAAccess::~TblWdbeQUsgAAccess() {
};

bool TblWdbeQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, WdbeQUsgAAccess** rec
		) {
	return false;
};

ubigint TblWdbeQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUsgAAccess& rst
		) {
	return 0;
};

ubigint TblWdbeQUsgAAccess::insertRec(
			WdbeQUsgAAccess* rec
		) {
	return 0;
};

ubigint TblWdbeQUsgAAccess::insertNewRec(
			WdbeQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWdbeVFeatgroup
			, const string srefX1IxWdbeVFeatgroup
			, const string titX1IxWdbeVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWdbeWAccess
			, const string srefsIxWdbeWAccess
			, const string titsIxWdbeWAccess
		) {
	ubigint retval = 0;
	WdbeQUsgAAccess* _rec = NULL;

	_rec = new WdbeQUsgAAccess(0, jref, jnum, ref, x1IxWdbeVFeatgroup, srefX1IxWdbeVFeatgroup, titX1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess, srefsIxWdbeWAccess, titsIxWdbeWAccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQUsgAAccess::appendNewRecToRst(
			ListWdbeQUsgAAccess& rst
			, WdbeQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxWdbeVFeatgroup
			, const string srefX1IxWdbeVFeatgroup
			, const string titX1IxWdbeVFeatgroup
			, const string x2FeaSrefUix
			, const uint ixWdbeWAccess
			, const string srefsIxWdbeWAccess
			, const string titsIxWdbeWAccess
		) {
	ubigint retval = 0;
	WdbeQUsgAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxWdbeVFeatgroup, srefX1IxWdbeVFeatgroup, titX1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess, srefsIxWdbeWAccess, titsIxWdbeWAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQUsgAAccess::insertRst(
			ListWdbeQUsgAAccess& rst
		) {
};

void TblWdbeQUsgAAccess::updateRec(
			WdbeQUsgAAccess* rec
		) {
};

void TblWdbeQUsgAAccess::updateRst(
			ListWdbeQUsgAAccess& rst
		) {
};

void TblWdbeQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQUsgAAccess::loadRecByQref(
			ubigint qref
			, WdbeQUsgAAccess** rec
		) {
	return false;
};

ubigint TblWdbeQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUsgAAccess& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQUsgAAccess
 ******************************************************************************/

MyTblWdbeQUsgAAccess::MyTblWdbeQUsgAAccess() :
			TblWdbeQUsgAAccess()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQUsgAAccess::~MyTblWdbeQUsgAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQUsgAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQUsgAAccess (jref, jnum, ref, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQUsgAAccess SET jref = ?, jnum = ?, ref = ?, x1IxWdbeVFeatgroup = ?, x2FeaSrefUix = ?, ixWdbeWAccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQUsgAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQUsgAAccess WHERE jref = ?", false);
};

bool MyTblWdbeQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, WdbeQUsgAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQUsgAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQUsgAAccess::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQUsgAAccess::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQUsgAAccess();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1IxWdbeVFeatgroup = atol((char*) dbrow[4]); else _rec->x1IxWdbeVFeatgroup = 0;
		if (dbrow[5]) _rec->x2FeaSrefUix.assign(dbrow[5], dblengths[5]); else _rec->x2FeaSrefUix = "";
		if (dbrow[6]) _rec->ixWdbeWAccess = atol((char*) dbrow[6]); else _rec->ixWdbeWAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUsgAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQUsgAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQUsgAAccess::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQUsgAAccess::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQUsgAAccess();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1IxWdbeVFeatgroup = atol((char*) dbrow[4]); else rec->x1IxWdbeVFeatgroup = 0;
			if (dbrow[5]) rec->x2FeaSrefUix.assign(dbrow[5], dblengths[5]); else rec->x2FeaSrefUix = "";
			if (dbrow[6]) rec->ixWdbeWAccess = atol((char*) dbrow[6]); else rec->ixWdbeWAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQUsgAAccess::insertRec(
			WdbeQUsgAAccess* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxWdbeVFeatgroup,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWdbeWAccess,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQUsgAAccess::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQUsgAAccess::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQUsgAAccess::insertRst(
			ListWdbeQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQUsgAAccess::updateRec(
			WdbeQUsgAAccess* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x2FeaSrefUix.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxWdbeVFeatgroup,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2FeaSrefUix.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixWdbeWAccess,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQUsgAAccess::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQUsgAAccess::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQUsgAAccess::updateRst(
			ListWdbeQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQUsgAAccess::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQUsgAAccess::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQUsgAAccess::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQUsgAAccess::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQUsgAAccess::loadRecByQref(
			ubigint qref
			, WdbeQUsgAAccess** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQUsgAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUsgAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQUsgAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQUsgAAccess
 ******************************************************************************/

PgTblWdbeQUsgAAccess::PgTblWdbeQUsgAAccess() :
			TblWdbeQUsgAAccess()
			, PgTable()
		{
};

PgTblWdbeQUsgAAccess::~PgTblWdbeQUsgAAccess() {
};

void PgTblWdbeQUsgAAccess::initStatements() {
	createStatement("TblWdbeQUsgAAccess_insertRec", "INSERT INTO TblWdbeQUsgAAccess (jref, jnum, ref, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6);
	createStatement("TblWdbeQUsgAAccess_updateRec", "UPDATE TblWdbeQUsgAAccess SET jref = $1, jnum = $2, ref = $3, x1IxWdbeVFeatgroup = $4, x2FeaSrefUix = $5, ixWdbeWAccess = $6 WHERE qref = $7", 7);
	createStatement("TblWdbeQUsgAAccess_removeRecByQref", "DELETE FROM TblWdbeQUsgAAccess WHERE qref = $1", 1);
	createStatement("TblWdbeQUsgAAccess_removeRstByJref", "DELETE FROM TblWdbeQUsgAAccess WHERE jref = $1", 1);

	createStatement("TblWdbeQUsgAAccess_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess FROM TblWdbeQUsgAAccess WHERE qref = $1", 1);
	createStatement("TblWdbeQUsgAAccess_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxWdbeVFeatgroup, x2FeaSrefUix, ixWdbeWAccess FROM TblWdbeQUsgAAccess WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQUsgAAccess::loadRec(
			PGresult* res
			, WdbeQUsgAAccess** rec
		) {
	char* ptr;

	WdbeQUsgAAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQUsgAAccess();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixwdbevfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwdbewaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1IxWdbeVFeatgroup = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixWdbeWAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQUsgAAccess::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQUsgAAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQUsgAAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixwdbevfeatgroup"),
			PQfnumber(res, "x2feasrefuix"),
			PQfnumber(res, "ixwdbewaccess")
		};

		while (numread < numrow) {
			rec = new WdbeQUsgAAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1IxWdbeVFeatgroup = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2FeaSrefUix.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixWdbeWAccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQUsgAAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQUsgAAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUsgAAccess::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQUsgAAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQUsgAAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUsgAAccess::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, WdbeQUsgAAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQUsgAAccess::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQUsgAAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQUsgAAccess::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQUsgAAccess::insertRec(
			WdbeQUsgAAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxWdbeVFeatgroup = htonl(rec->x1IxWdbeVFeatgroup);
	uint _ixWdbeWAccess = htonl(rec->ixWdbeWAccess);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxWdbeVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWdbeWAccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQUsgAAccess_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQUsgAAccess::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQUsgAAccess::insertRst(
			ListWdbeQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQUsgAAccess::updateRec(
			WdbeQUsgAAccess* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxWdbeVFeatgroup = htonl(rec->x1IxWdbeVFeatgroup);
	uint _ixWdbeWAccess = htonl(rec->ixWdbeWAccess);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxWdbeVFeatgroup,
		rec->x2FeaSrefUix.c_str(),
		(char*) &_ixWdbeWAccess,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeQUsgAAccess_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUsgAAccess::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQUsgAAccess::updateRst(
			ListWdbeQUsgAAccess& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQUsgAAccess::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblWdbeQUsgAAccess_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUsgAAccess::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQUsgAAccess::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblWdbeQUsgAAccess_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQUsgAAccess::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQUsgAAccess::loadRecByQref(
			ubigint qref
			, WdbeQUsgAAccess** rec
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

	return loadRecByStmt("TblWdbeQUsgAAccess_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQUsgAAccess& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQUsgAAccess_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

