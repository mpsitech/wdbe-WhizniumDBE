/**
	* \file WdbeMMachine.cpp
	* database access for table TblWdbeMMachine (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMMachine.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMMachine
 ******************************************************************************/

WdbeMMachine::WdbeMMachine(
			const ubigint ref
			, const ubigint supRefWdbeMMachine
			, const string sref
			, const ubigint cchRefWdbeMMachine
			, const string Comment
		) {

	this->ref = ref;
	this->supRefWdbeMMachine = supRefWdbeMMachine;
	this->sref = sref;
	this->cchRefWdbeMMachine = cchRefWdbeMMachine;
	this->Comment = Comment;
};

bool WdbeMMachine::operator==(
			const WdbeMMachine& comp
		) {
	return false;
};

bool WdbeMMachine::operator!=(
			const WdbeMMachine& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMMachine
 ******************************************************************************/

ListWdbeMMachine::ListWdbeMMachine() {
};

ListWdbeMMachine::ListWdbeMMachine(
			const ListWdbeMMachine& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMMachine(*(src.nodes[i]));
};

ListWdbeMMachine::~ListWdbeMMachine() {
	clear();
};

void ListWdbeMMachine::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMMachine::size() const {
	return(nodes.size());
};

void ListWdbeMMachine::append(
			WdbeMMachine* rec
		) {
	nodes.push_back(rec);
};

WdbeMMachine* ListWdbeMMachine::operator[](
			const uint ix
		) {
	WdbeMMachine* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMMachine& ListWdbeMMachine::operator=(
			const ListWdbeMMachine& src
		) {
	WdbeMMachine* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMMachine(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMMachine::operator==(
			const ListWdbeMMachine& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListWdbeMMachine::operator!=(
			const ListWdbeMMachine& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMMachine
 ******************************************************************************/

TblWdbeMMachine::TblWdbeMMachine() {
};

TblWdbeMMachine::~TblWdbeMMachine() {
};

bool TblWdbeMMachine::loadRecBySQL(
			const string& sqlstr
			, WdbeMMachine** rec
		) {
	return false;
};

ubigint TblWdbeMMachine::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMMachine& rst
		) {
	return 0;
};

ubigint TblWdbeMMachine::insertRec(
			WdbeMMachine* rec
		) {
	return 0;
};

ubigint TblWdbeMMachine::insertNewRec(
			WdbeMMachine** rec
			, const ubigint supRefWdbeMMachine
			, const string sref
			, const ubigint cchRefWdbeMMachine
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMMachine* _rec = NULL;

	_rec = new WdbeMMachine(0, supRefWdbeMMachine, sref, cchRefWdbeMMachine, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMMachine::appendNewRecToRst(
			ListWdbeMMachine& rst
			, WdbeMMachine** rec
			, const ubigint supRefWdbeMMachine
			, const string sref
			, const ubigint cchRefWdbeMMachine
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMMachine* _rec = NULL;

	retval = insertNewRec(&_rec, supRefWdbeMMachine, sref, cchRefWdbeMMachine, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMMachine::insertRst(
			ListWdbeMMachine& rst
			, bool transact
		) {
};

void TblWdbeMMachine::updateRec(
			WdbeMMachine* rec
		) {
};

void TblWdbeMMachine::updateRst(
			ListWdbeMMachine& rst
			, bool transact
		) {
};

void TblWdbeMMachine::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMMachine::loadRecByRef(
			ubigint ref
			, WdbeMMachine** rec
		) {
	return false;
};

bool TblWdbeMMachine::confirmByRef(
			ubigint ref
		) {
	return false;
};

ubigint TblWdbeMMachine::loadRefsBySup(
			ubigint supRefWdbeMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMMachine::loadRstBySup(
			ubigint supRefWdbeMMachine
			, const bool append
			, ListWdbeMMachine& rst
		) {
	return 0;
};

bool TblWdbeMMachine::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

bool TblWdbeMMachine::loadSupByRef(
			ubigint ref
			, ubigint& supRefWdbeMMachine
		) {
	return false;
};

ubigint TblWdbeMMachine::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMMachine& rst
		) {
	ubigint numload = 0;
	WdbeMMachine* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

ubigint TblWdbeMMachine::loadHrefsup(
			ubigint ref
			, vector<ubigint>& refs
		) {
	ubigint sup;

	refs.resize(0);
	ubigint retval = 0;

	while (loadSupByRef(ref, sup)) {
		refs.push_back(ref);
		retval++;

		ref = sup;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWdbeMMachine::loadHrefsdown(
			ubigint ref
			, const bool append
			, vector<ubigint>& refs
			, unsigned int firstix
			, unsigned int lastix
		) {
	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) refs.resize(0);

		if (confirmByRef(ref)) {
			refs.push_back(ref);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i = firstix; i <= lastix; i++) {
		newfirstix = refs.size();
		retval += loadRefsBySup(refs[i], true, refs);
		newlastix = refs.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrefsdown(0, true, refs, newfirstix, newlastix);
	};

	return retval;
};

ubigint TblWdbeMMachine::loadHrstup(
			ubigint ref
			, ListWdbeMMachine& rst
		) {
	WdbeMMachine* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefWdbeMMachine;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWdbeMMachine::loadHrstdown(
			ubigint ref
			, const bool append
			, ListWdbeMMachine& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	WdbeMMachine* rec = NULL;

	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) rst.clear();

		if (loadRecByRef(ref, &rec)) {
			rst.nodes.push_back(rec);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i = firstix; i <= lastix; i++) {
		rec = rst.nodes[i];

		newfirstix = rst.nodes.size();
		retval += loadRstBySup(rec->ref, true, rst);
		newlastix = rst.nodes.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrstdown(0, true, rst, newfirstix, newlastix);
	};

	return retval;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMMachine
 ******************************************************************************/

MyTblWdbeMMachine::MyTblWdbeMMachine() :
			TblWdbeMMachine()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMMachine::~MyTblWdbeMMachine() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMMachine::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMMachine (supRefWdbeMMachine, sref, cchRefWdbeMMachine, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMMachine SET supRefWdbeMMachine = ?, sref = ?, cchRefWdbeMMachine = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMMachine WHERE ref = ?", false);
};

bool MyTblWdbeMMachine::loadRecBySQL(
			const string& sqlstr
			, WdbeMMachine** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMMachine* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMMachine::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMMachine::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMMachine();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->supRefWdbeMMachine = atoll((char*) dbrow[1]); else _rec->supRefWdbeMMachine = 0;
		if (dbrow[2]) _rec->sref.assign(dbrow[2], dblengths[2]); else _rec->sref = "";
		if (dbrow[3]) _rec->cchRefWdbeMMachine = atoll((char*) dbrow[3]); else _rec->cchRefWdbeMMachine = 0;
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMMachine::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMMachine& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMMachine* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMMachine::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMMachine::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMMachine();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->supRefWdbeMMachine = atoll((char*) dbrow[1]); else rec->supRefWdbeMMachine = 0;
			if (dbrow[2]) rec->sref.assign(dbrow[2], dblengths[2]); else rec->sref = "";
			if (dbrow[3]) rec->cchRefWdbeMMachine = atoll((char*) dbrow[3]); else rec->cchRefWdbeMMachine = 0;
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMMachine::insertRec(
			WdbeMMachine* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefWdbeMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->cchRefWdbeMMachine,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMMachine::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMMachine::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMMachine::insertRst(
			ListWdbeMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMMachine::updateRec(
			WdbeMMachine* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[1] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefWdbeMMachine,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->sref.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->cchRefWdbeMMachine,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMMachine::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMMachine::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMMachine::updateRst(
			ListWdbeMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMMachine::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMMachine::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMMachine::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMMachine::loadRecByRef(
			ubigint ref
			, WdbeMMachine** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMMachine WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMMachine::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadRefBySQL("SELECT ref FROM TblWdbeMMachine WHERE ref = " + to_string(ref) + "", val);
};

ubigint MyTblWdbeMMachine::loadRefsBySup(
			ubigint supRefWdbeMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMMachine WHERE supRefWdbeMMachine = " + to_string(supRefWdbeMMachine) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblWdbeMMachine::loadRstBySup(
			ubigint supRefWdbeMMachine
			, const bool append
			, ListWdbeMMachine& rst
		) {
	return loadRstBySQL("SELECT ref, supRefWdbeMMachine, sref, cchRefWdbeMMachine, Comment FROM TblWdbeMMachine WHERE supRefWdbeMMachine = " + to_string(supRefWdbeMMachine) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMMachine::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMMachine WHERE ref = " + to_string(ref) + "", sref);
};

bool MyTblWdbeMMachine::loadSupByRef(
			ubigint ref
			, ubigint& supRefWdbeMMachine
		) {
	return loadRefBySQL("SELECT supRefWdbeMMachine FROM TblWdbeMMachine WHERE ref = " + to_string(ref) + "", supRefWdbeMMachine);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMMachine
 ******************************************************************************/

PgTblWdbeMMachine::PgTblWdbeMMachine() :
			TblWdbeMMachine()
			, PgTable()
		{
};

PgTblWdbeMMachine::~PgTblWdbeMMachine() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMMachine::initStatements() {
	createStatement("TblWdbeMMachine_insertRec", "INSERT INTO TblWdbeMMachine (supRefWdbeMMachine, sref, cchRefWdbeMMachine, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4);
	createStatement("TblWdbeMMachine_updateRec", "UPDATE TblWdbeMMachine SET supRefWdbeMMachine = $1, sref = $2, cchRefWdbeMMachine = $3, Comment = $4 WHERE ref = $5", 5);
	createStatement("TblWdbeMMachine_removeRecByRef", "DELETE FROM TblWdbeMMachine WHERE ref = $1", 1);

	createStatement("TblWdbeMMachine_loadRecByRef", "SELECT ref, supRefWdbeMMachine, sref, cchRefWdbeMMachine, Comment FROM TblWdbeMMachine WHERE ref = $1", 1);
	createStatement("TblWdbeMMachine_confirmByRef", "SELECT ref FROM TblWdbeMMachine WHERE ref = $1", 1);
	createStatement("TblWdbeMMachine_loadRefsBySup", "SELECT ref FROM TblWdbeMMachine WHERE supRefWdbeMMachine = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMMachine_loadRstBySup", "SELECT ref, supRefWdbeMMachine, sref, cchRefWdbeMMachine, Comment FROM TblWdbeMMachine WHERE supRefWdbeMMachine = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMMachine_loadSrfByRef", "SELECT sref FROM TblWdbeMMachine WHERE ref = $1", 1);
	createStatement("TblWdbeMMachine_loadSupByRef", "SELECT supRefWdbeMMachine FROM TblWdbeMMachine WHERE ref = $1", 1);
};

bool PgTblWdbeMMachine::loadRec(
			PGresult* res
			, WdbeMMachine** rec
		) {
	char* ptr;

	WdbeMMachine* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMMachine();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "suprefwdbemmachine"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "cchrefwdbemmachine"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->supRefWdbeMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->cchRefWdbeMMachine = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMMachine::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMMachine& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMMachine* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "suprefwdbemmachine"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "cchrefwdbemmachine"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMMachine();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->supRefWdbeMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->cchRefWdbeMMachine = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMMachine::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMMachine** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMMachine::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMMachine::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMMachine& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMMachine::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMMachine::loadRecBySQL(
			const string& sqlstr
			, WdbeMMachine** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMMachine::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMMachine::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMMachine& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMMachine::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMMachine::insertRec(
			WdbeMMachine* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _supRefWdbeMMachine = htonl64(rec->supRefWdbeMMachine);
	ubigint _cchRefWdbeMMachine = htonl64(rec->cchRefWdbeMMachine);

	const char* vals[] = {
		(char*) &_supRefWdbeMMachine,
		rec->sref.c_str(),
		(char*) &_cchRefWdbeMMachine,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeMMachine_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMMachine::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMMachine::insertRst(
			ListWdbeMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMMachine::updateRec(
			WdbeMMachine* rec
		) {
	PGresult* res;

	ubigint _supRefWdbeMMachine = htonl64(rec->supRefWdbeMMachine);
	ubigint _cchRefWdbeMMachine = htonl64(rec->cchRefWdbeMMachine);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_supRefWdbeMMachine,
		rec->sref.c_str(),
		(char*) &_cchRefWdbeMMachine,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMMachine_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMMachine::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMMachine::updateRst(
			ListWdbeMMachine& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMMachine::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWdbeMMachine_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMMachine::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMMachine::loadRecByRef(
			ubigint ref
			, WdbeMMachine** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMMachine_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMMachine::confirmByRef(
			ubigint ref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWdbeMMachine_confirmByRef", 1, vals, l, f, _ref);
};

ubigint PgTblWdbeMMachine::loadRefsBySup(
			ubigint supRefWdbeMMachine
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefWdbeMMachine = htonl64(supRefWdbeMMachine);

	const char* vals[] = {
		(char*) &_supRefWdbeMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMMachine_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMMachine::loadRstBySup(
			ubigint supRefWdbeMMachine
			, const bool append
			, ListWdbeMMachine& rst
		) {
	ubigint _supRefWdbeMMachine = htonl64(supRefWdbeMMachine);

	const char* vals[] = {
		(char*) &_supRefWdbeMMachine
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMMachine_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMMachine::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMMachine_loadSrfByRef", 1, vals, l, f, sref);
};

bool PgTblWdbeMMachine::loadSupByRef(
			ubigint ref
			, ubigint& supRefWdbeMMachine
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWdbeMMachine_loadSupByRef", 1, vals, l, f, supRefWdbeMMachine);
};

#endif

