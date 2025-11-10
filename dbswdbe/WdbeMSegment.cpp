/**
	* \file WdbeMSegment.cpp
	* database access for table TblWdbeMSegment (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeMSegment.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMSegment
 ******************************************************************************/

WdbeMSegment::WdbeMSegment(
			const ubigint ref
			, const ubigint refWdbeCSegment
			, const ubigint pplRefWdbeMPipeline
			, const uint pplNum
			, const ubigint supRefWdbeMSegment
			, const string sref
			, const string Infmt
			, const string Outfmt
			, const usmallint Latency
			, const string Comment
		) :
			ref(ref)
			, refWdbeCSegment(refWdbeCSegment)
			, pplRefWdbeMPipeline(pplRefWdbeMPipeline)
			, pplNum(pplNum)
			, supRefWdbeMSegment(supRefWdbeMSegment)
			, sref(sref)
			, Infmt(Infmt)
			, Outfmt(Outfmt)
			, Latency(Latency)
			, Comment(Comment)
		{
};

bool WdbeMSegment::operator==(
			const WdbeMSegment& comp
		) {
	return false;
};

bool WdbeMSegment::operator!=(
			const WdbeMSegment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMSegment
 ******************************************************************************/

ListWdbeMSegment::ListWdbeMSegment() {
};

ListWdbeMSegment::ListWdbeMSegment(
			const ListWdbeMSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMSegment(*(src.nodes[i]));
};

ListWdbeMSegment::~ListWdbeMSegment() {
	clear();
};

void ListWdbeMSegment::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMSegment::size() const {
	return(nodes.size());
};

void ListWdbeMSegment::append(
			WdbeMSegment* rec
		) {
	nodes.push_back(rec);
};

WdbeMSegment* ListWdbeMSegment::operator[](
			const uint ix
		) {
	WdbeMSegment* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMSegment& ListWdbeMSegment::operator=(
			const ListWdbeMSegment& src
		) {
	WdbeMSegment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMSegment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMSegment::operator==(
			const ListWdbeMSegment& comp
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

bool ListWdbeMSegment::operator!=(
			const ListWdbeMSegment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMSegment
 ******************************************************************************/

TblWdbeMSegment::TblWdbeMSegment() {
};

TblWdbeMSegment::~TblWdbeMSegment() {
};

bool TblWdbeMSegment::loadRecBySQL(
			const string& sqlstr
			, WdbeMSegment** rec
		) {
	return false;
};

ubigint TblWdbeMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSegment& rst
		) {
	return 0;
};

ubigint TblWdbeMSegment::insertRec(
			WdbeMSegment* rec
		) {
	return 0;
};

ubigint TblWdbeMSegment::insertNewRec(
			WdbeMSegment** rec
			, const ubigint refWdbeCSegment
			, const ubigint pplRefWdbeMPipeline
			, const uint pplNum
			, const ubigint supRefWdbeMSegment
			, const string sref
			, const string Infmt
			, const string Outfmt
			, const usmallint Latency
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMSegment* _rec = NULL;

	_rec = new WdbeMSegment(0, refWdbeCSegment, pplRefWdbeMPipeline, pplNum, supRefWdbeMSegment, sref, Infmt, Outfmt, Latency, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMSegment::appendNewRecToRst(
			ListWdbeMSegment& rst
			, WdbeMSegment** rec
			, const ubigint refWdbeCSegment
			, const ubigint pplRefWdbeMPipeline
			, const uint pplNum
			, const ubigint supRefWdbeMSegment
			, const string sref
			, const string Infmt
			, const string Outfmt
			, const usmallint Latency
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMSegment* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeCSegment, pplRefWdbeMPipeline, pplNum, supRefWdbeMSegment, sref, Infmt, Outfmt, Latency, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMSegment::insertRst(
			ListWdbeMSegment& rst
			, bool transact
		) {
};

void TblWdbeMSegment::updateRec(
			WdbeMSegment* rec
		) {
};

void TblWdbeMSegment::updateRst(
			ListWdbeMSegment& rst
			, bool transact
		) {
};

void TblWdbeMSegment::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMSegment::loadRecByRef(
			ubigint ref
			, WdbeMSegment** rec
		) {
	return false;
};

bool TblWdbeMSegment::confirmByRef(
			ubigint ref
		) {
	return false;
};

bool TblWdbeMSegment::loadRefBySupSrf(
			ubigint supRefWdbeMSegment
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWdbeMSegment::loadRefsByClu(
			ubigint refWdbeCSegment
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMSegment::loadRefsByPpl(
			ubigint pplRefWdbeMPipeline
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMSegment::loadRefsBySup(
			ubigint supRefWdbeMSegment
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMSegment::loadRstByClu(
			ubigint refWdbeCSegment
			, const bool append
			, ListWdbeMSegment& rst
		) {
	return 0;
};

ubigint TblWdbeMSegment::loadRstByPpl(
			ubigint pplRefWdbeMPipeline
			, const bool append
			, ListWdbeMSegment& rst
		) {
	return 0;
};

ubigint TblWdbeMSegment::loadRstBySup(
			ubigint supRefWdbeMSegment
			, const bool append
			, ListWdbeMSegment& rst
		) {
	return 0;
};

bool TblWdbeMSegment::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

bool TblWdbeMSegment::loadSupByRef(
			ubigint ref
			, ubigint& supRefWdbeMSegment
		) {
	return false;
};

ubigint TblWdbeMSegment::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMSegment& rst
		) {
	ubigint numload = 0;
	WdbeMSegment* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

ubigint TblWdbeMSegment::loadHrefsup(
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

ubigint TblWdbeMSegment::loadHrefsdown(
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

ubigint TblWdbeMSegment::loadHrstup(
			ubigint ref
			, ListWdbeMSegment& rst
		) {
	WdbeMSegment* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefWdbeMSegment;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWdbeMSegment::loadHrstdown(
			ubigint ref
			, const bool append
			, ListWdbeMSegment& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	WdbeMSegment* rec = NULL;

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
 class MyTblWdbeMSegment
 ******************************************************************************/

MyTblWdbeMSegment::MyTblWdbeMSegment() :
			TblWdbeMSegment()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMSegment::~MyTblWdbeMSegment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMSegment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMSegment (refWdbeCSegment, pplRefWdbeMPipeline, pplNum, supRefWdbeMSegment, sref, Infmt, Outfmt, Latency, Comment) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMSegment SET refWdbeCSegment = ?, pplRefWdbeMPipeline = ?, pplNum = ?, supRefWdbeMSegment = ?, sref = ?, Infmt = ?, Outfmt = ?, Latency = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMSegment WHERE ref = ?", false);
};

bool MyTblWdbeMSegment::loadRecBySQL(
			const string& sqlstr
			, WdbeMSegment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMSegment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMSegment::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMSegment::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMSegment();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeCSegment = atoll((char*) dbrow[1]); else _rec->refWdbeCSegment = 0;
		if (dbrow[2]) _rec->pplRefWdbeMPipeline = atoll((char*) dbrow[2]); else _rec->pplRefWdbeMPipeline = 0;
		if (dbrow[3]) _rec->pplNum = atol((char*) dbrow[3]); else _rec->pplNum = 0;
		if (dbrow[4]) _rec->supRefWdbeMSegment = atoll((char*) dbrow[4]); else _rec->supRefWdbeMSegment = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->Infmt.assign(dbrow[6], dblengths[6]); else _rec->Infmt = "";
		if (dbrow[7]) _rec->Outfmt.assign(dbrow[7], dblengths[7]); else _rec->Outfmt = "";
		if (dbrow[8]) _rec->Latency = atoi((char*) dbrow[8]); else _rec->Latency = 0;
		if (dbrow[9]) _rec->Comment.assign(dbrow[9], dblengths[9]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSegment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMSegment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMSegment::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMSegment::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMSegment();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeCSegment = atoll((char*) dbrow[1]); else rec->refWdbeCSegment = 0;
			if (dbrow[2]) rec->pplRefWdbeMPipeline = atoll((char*) dbrow[2]); else rec->pplRefWdbeMPipeline = 0;
			if (dbrow[3]) rec->pplNum = atol((char*) dbrow[3]); else rec->pplNum = 0;
			if (dbrow[4]) rec->supRefWdbeMSegment = atoll((char*) dbrow[4]); else rec->supRefWdbeMSegment = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->Infmt.assign(dbrow[6], dblengths[6]); else rec->Infmt = "";
			if (dbrow[7]) rec->Outfmt.assign(dbrow[7], dblengths[7]); else rec->Outfmt = "";
			if (dbrow[8]) rec->Latency = atoi((char*) dbrow[8]); else rec->Latency = 0;
			if (dbrow[9]) rec->Comment.assign(dbrow[9], dblengths[9]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMSegment::insertRec(
			WdbeMSegment* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();
	l[5] = rec->Infmt.length();
	l[6] = rec->Outfmt.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCSegment,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->pplRefWdbeMPipeline,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->pplNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->supRefWdbeMSegment,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Infmt.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Outfmt.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Latency,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMSegment::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMSegment::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMSegment::insertRst(
			ListWdbeMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMSegment::updateRec(
			WdbeMSegment* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();
	l[5] = rec->Infmt.length();
	l[6] = rec->Outfmt.length();
	l[8] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCSegment,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->pplRefWdbeMPipeline,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->pplNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->supRefWdbeMSegment,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Infmt.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Outfmt.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Latency,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->ref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMSegment::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMSegment::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMSegment::updateRst(
			ListWdbeMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMSegment::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMSegment::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMSegment::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMSegment::loadRecByRef(
			ubigint ref
			, WdbeMSegment** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMSegment WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMSegment::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadRefBySQL("SELECT ref FROM TblWdbeMSegment WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblWdbeMSegment::loadRefBySupSrf(
			ubigint supRefWdbeMSegment
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWdbeMSegment WHERE supRefWdbeMSegment = " + to_string(supRefWdbeMSegment) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWdbeMSegment::loadRefsByClu(
			ubigint refWdbeCSegment
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMSegment WHERE refWdbeCSegment = " + to_string(refWdbeCSegment) + "", append, refs);
};

ubigint MyTblWdbeMSegment::loadRefsByPpl(
			ubigint pplRefWdbeMPipeline
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMSegment WHERE pplRefWdbeMPipeline = " + to_string(pplRefWdbeMPipeline) + "", append, refs);
};

ubigint MyTblWdbeMSegment::loadRefsBySup(
			ubigint supRefWdbeMSegment
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMSegment WHERE supRefWdbeMSegment = " + to_string(supRefWdbeMSegment) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblWdbeMSegment::loadRstByClu(
			ubigint refWdbeCSegment
			, const bool append
			, ListWdbeMSegment& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCSegment, pplRefWdbeMPipeline, pplNum, supRefWdbeMSegment, sref, Infmt, Outfmt, Latency, Comment FROM TblWdbeMSegment WHERE refWdbeCSegment = " + to_string(refWdbeCSegment) + "", append, rst);
};

ubigint MyTblWdbeMSegment::loadRstByPpl(
			ubigint pplRefWdbeMPipeline
			, const bool append
			, ListWdbeMSegment& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCSegment, pplRefWdbeMPipeline, pplNum, supRefWdbeMSegment, sref, Infmt, Outfmt, Latency, Comment FROM TblWdbeMSegment WHERE pplRefWdbeMPipeline = " + to_string(pplRefWdbeMPipeline) + " ORDER BY pplNum ASC", append, rst);
};

ubigint MyTblWdbeMSegment::loadRstBySup(
			ubigint supRefWdbeMSegment
			, const bool append
			, ListWdbeMSegment& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCSegment, pplRefWdbeMPipeline, pplNum, supRefWdbeMSegment, sref, Infmt, Outfmt, Latency, Comment FROM TblWdbeMSegment WHERE supRefWdbeMSegment = " + to_string(supRefWdbeMSegment) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMSegment::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMSegment WHERE ref = " + to_string(ref) + "", sref);
};

bool MyTblWdbeMSegment::loadSupByRef(
			ubigint ref
			, ubigint& supRefWdbeMSegment
		) {
	return loadRefBySQL("SELECT supRefWdbeMSegment FROM TblWdbeMSegment WHERE ref = " + to_string(ref) + "", supRefWdbeMSegment);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMSegment
 ******************************************************************************/

PgTblWdbeMSegment::PgTblWdbeMSegment() :
			TblWdbeMSegment()
			, PgTable()
		{
};

PgTblWdbeMSegment::~PgTblWdbeMSegment() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMSegment::initStatements() {
	createStatement("TblWdbeMSegment_insertRec", "INSERT INTO TblWdbeMSegment (refWdbeCSegment, pplRefWdbeMPipeline, pplNum, supRefWdbeMSegment, sref, Infmt, Outfmt, Latency, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING ref", 9);
	createStatement("TblWdbeMSegment_updateRec", "UPDATE TblWdbeMSegment SET refWdbeCSegment = $1, pplRefWdbeMPipeline = $2, pplNum = $3, supRefWdbeMSegment = $4, sref = $5, Infmt = $6, Outfmt = $7, Latency = $8, Comment = $9 WHERE ref = $10", 10);
	createStatement("TblWdbeMSegment_removeRecByRef", "DELETE FROM TblWdbeMSegment WHERE ref = $1", 1);

	createStatement("TblWdbeMSegment_loadRecByRef", "SELECT ref, refWdbeCSegment, pplRefWdbeMPipeline, pplNum, supRefWdbeMSegment, sref, Infmt, Outfmt, Latency, Comment FROM TblWdbeMSegment WHERE ref = $1", 1);
	createStatement("TblWdbeMSegment_confirmByRef", "SELECT ref FROM TblWdbeMSegment WHERE ref = $1", 1);
	createStatement("TblWdbeMSegment_loadRefBySupSrf", "SELECT ref FROM TblWdbeMSegment WHERE supRefWdbeMSegment = $1 AND sref = $2", 2);
	createStatement("TblWdbeMSegment_loadRefsByClu", "SELECT ref FROM TblWdbeMSegment WHERE refWdbeCSegment = $1", 1);
	createStatement("TblWdbeMSegment_loadRefsByPpl", "SELECT ref FROM TblWdbeMSegment WHERE pplRefWdbeMPipeline = $1", 1);
	createStatement("TblWdbeMSegment_loadRefsBySup", "SELECT ref FROM TblWdbeMSegment WHERE supRefWdbeMSegment = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMSegment_loadRstByClu", "SELECT ref, refWdbeCSegment, pplRefWdbeMPipeline, pplNum, supRefWdbeMSegment, sref, Infmt, Outfmt, Latency, Comment FROM TblWdbeMSegment WHERE refWdbeCSegment = $1", 1);
	createStatement("TblWdbeMSegment_loadRstByPpl", "SELECT ref, refWdbeCSegment, pplRefWdbeMPipeline, pplNum, supRefWdbeMSegment, sref, Infmt, Outfmt, Latency, Comment FROM TblWdbeMSegment WHERE pplRefWdbeMPipeline = $1 ORDER BY pplNum ASC", 1);
	createStatement("TblWdbeMSegment_loadRstBySup", "SELECT ref, refWdbeCSegment, pplRefWdbeMPipeline, pplNum, supRefWdbeMSegment, sref, Infmt, Outfmt, Latency, Comment FROM TblWdbeMSegment WHERE supRefWdbeMSegment = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMSegment_loadSrfByRef", "SELECT sref FROM TblWdbeMSegment WHERE ref = $1", 1);
	createStatement("TblWdbeMSegment_loadSupByRef", "SELECT supRefWdbeMSegment FROM TblWdbeMSegment WHERE ref = $1", 1);
};

bool PgTblWdbeMSegment::loadRec(
			PGresult* res
			, WdbeMSegment** rec
		) {
	char* ptr;

	WdbeMSegment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMSegment();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecsegment"),
			PQfnumber(res, "pplrefwdbempipeline"),
			PQfnumber(res, "pplnum"),
			PQfnumber(res, "suprefwdbemsegment"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "infmt"),
			PQfnumber(res, "outfmt"),
			PQfnumber(res, "latency"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeCSegment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->pplRefWdbeMPipeline = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->pplNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->supRefWdbeMSegment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Infmt.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Outfmt.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Latency = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMSegment::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMSegment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMSegment* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecsegment"),
			PQfnumber(res, "pplrefwdbempipeline"),
			PQfnumber(res, "pplnum"),
			PQfnumber(res, "suprefwdbemsegment"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "infmt"),
			PQfnumber(res, "outfmt"),
			PQfnumber(res, "latency"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMSegment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeCSegment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->pplRefWdbeMPipeline = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->pplNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->supRefWdbeMSegment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Infmt.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Outfmt.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Latency = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMSegment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMSegment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSegment::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMSegment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMSegment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSegment::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMSegment::loadRecBySQL(
			const string& sqlstr
			, WdbeMSegment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSegment::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSegment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSegment::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMSegment::insertRec(
			WdbeMSegment* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeCSegment = htonl64(rec->refWdbeCSegment);
	ubigint _pplRefWdbeMPipeline = htonl64(rec->pplRefWdbeMPipeline);
	uint _pplNum = htonl(rec->pplNum);
	ubigint _supRefWdbeMSegment = htonl64(rec->supRefWdbeMSegment);
	usmallint _Latency = htons(rec->Latency);

	const char* vals[] = {
		(char*) &_refWdbeCSegment,
		(char*) &_pplRefWdbeMPipeline,
		(char*) &_pplNum,
		(char*) &_supRefWdbeMSegment,
		rec->sref.c_str(),
		rec->Infmt.c_str(),
		rec->Outfmt.c_str(),
		(char*) &_Latency,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeMSegment_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSegment::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMSegment::insertRst(
			ListWdbeMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMSegment::updateRec(
			WdbeMSegment* rec
		) {
	PGresult* res;

	ubigint _refWdbeCSegment = htonl64(rec->refWdbeCSegment);
	ubigint _pplRefWdbeMPipeline = htonl64(rec->pplRefWdbeMPipeline);
	uint _pplNum = htonl(rec->pplNum);
	ubigint _supRefWdbeMSegment = htonl64(rec->supRefWdbeMSegment);
	usmallint _Latency = htons(rec->Latency);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeCSegment,
		(char*) &_pplRefWdbeMPipeline,
		(char*) &_pplNum,
		(char*) &_supRefWdbeMSegment,
		rec->sref.c_str(),
		rec->Infmt.c_str(),
		rec->Outfmt.c_str(),
		(char*) &_Latency,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMSegment_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMSegment::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMSegment::updateRst(
			ListWdbeMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMSegment::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMSegment_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMSegment::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMSegment::loadRecByRef(
			ubigint ref
			, WdbeMSegment** rec
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

	return loadRecByStmt("TblWdbeMSegment_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMSegment::confirmByRef(
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

	return loadRefByStmt("TblWdbeMSegment_confirmByRef", 1, vals, l, f, _ref);
};

bool PgTblWdbeMSegment::loadRefBySupSrf(
			ubigint supRefWdbeMSegment
			, string sref
			, ubigint& ref
		) {
	ubigint _supRefWdbeMSegment = htonl64(supRefWdbeMSegment);

	const char* vals[] = {
		(char*) &_supRefWdbeMSegment,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRefByStmt("TblWdbeMSegment_loadRefBySupSrf", 2, vals, l, f, ref);
};

ubigint PgTblWdbeMSegment::loadRefsByClu(
			ubigint refWdbeCSegment
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeCSegment = htonl64(refWdbeCSegment);

	const char* vals[] = {
		(char*) &_refWdbeCSegment
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMSegment_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMSegment::loadRefsByPpl(
			ubigint pplRefWdbeMPipeline
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _pplRefWdbeMPipeline = htonl64(pplRefWdbeMPipeline);

	const char* vals[] = {
		(char*) &_pplRefWdbeMPipeline
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMSegment_loadRefsByPpl", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMSegment::loadRefsBySup(
			ubigint supRefWdbeMSegment
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefWdbeMSegment = htonl64(supRefWdbeMSegment);

	const char* vals[] = {
		(char*) &_supRefWdbeMSegment
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMSegment_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMSegment::loadRstByClu(
			ubigint refWdbeCSegment
			, const bool append
			, ListWdbeMSegment& rst
		) {
	ubigint _refWdbeCSegment = htonl64(refWdbeCSegment);

	const char* vals[] = {
		(char*) &_refWdbeCSegment
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMSegment_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeMSegment::loadRstByPpl(
			ubigint pplRefWdbeMPipeline
			, const bool append
			, ListWdbeMSegment& rst
		) {
	ubigint _pplRefWdbeMPipeline = htonl64(pplRefWdbeMPipeline);

	const char* vals[] = {
		(char*) &_pplRefWdbeMPipeline
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMSegment_loadRstByPpl", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeMSegment::loadRstBySup(
			ubigint supRefWdbeMSegment
			, const bool append
			, ListWdbeMSegment& rst
		) {
	ubigint _supRefWdbeMSegment = htonl64(supRefWdbeMSegment);

	const char* vals[] = {
		(char*) &_supRefWdbeMSegment
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMSegment_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMSegment::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMSegment_loadSrfByRef", 1, vals, l, f, sref);
};

bool PgTblWdbeMSegment::loadSupByRef(
			ubigint ref
			, ubigint& supRefWdbeMSegment
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWdbeMSegment_loadSupByRef", 1, vals, l, f, supRefWdbeMSegment);
};

#endif
