/**
	* \file WdbeMModule.cpp
	* database access for table TblWdbeMModule (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMModule.h"

#include "WdbeMModule_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMModule
 ******************************************************************************/

WdbeMModule::WdbeMModule(
			const ubigint ref
			, const uint ixVBasetype
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const uint hkNum
			, const ubigint supRefWdbeMModule
			, const ubigint tplRefWdbeMModule
			, const ubigint refWdbeMController
			, const ubigint refWdbeMImbuf
			, const string sref
			, const string srefWdbeKVendor
			, const string Srefrule
			, const string Comment
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->hkNum = hkNum;
	this->supRefWdbeMModule = supRefWdbeMModule;
	this->tplRefWdbeMModule = tplRefWdbeMModule;
	this->refWdbeMController = refWdbeMController;
	this->refWdbeMImbuf = refWdbeMImbuf;
	this->sref = sref;
	this->srefWdbeKVendor = srefWdbeKVendor;
	this->Srefrule = Srefrule;
	this->Comment = Comment;
};

bool WdbeMModule::operator==(
			const WdbeMModule& comp
		) {
	return false;
};

bool WdbeMModule::operator!=(
			const WdbeMModule& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMModule
 ******************************************************************************/

ListWdbeMModule::ListWdbeMModule() {
};

ListWdbeMModule::ListWdbeMModule(
			const ListWdbeMModule& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMModule(*(src.nodes[i]));
};

ListWdbeMModule::~ListWdbeMModule() {
	clear();
};

void ListWdbeMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMModule::size() const {
	return(nodes.size());
};

void ListWdbeMModule::append(
			WdbeMModule* rec
		) {
	nodes.push_back(rec);
};

WdbeMModule* ListWdbeMModule::operator[](
			const uint ix
		) {
	WdbeMModule* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMModule& ListWdbeMModule::operator=(
			const ListWdbeMModule& src
		) {
	WdbeMModule* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMModule(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMModule::operator==(
			const ListWdbeMModule& comp
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

bool ListWdbeMModule::operator!=(
			const ListWdbeMModule& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMModule
 ******************************************************************************/

TblWdbeMModule::TblWdbeMModule() {
};

TblWdbeMModule::~TblWdbeMModule() {
};

bool TblWdbeMModule::loadRecBySQL(
			const string& sqlstr
			, WdbeMModule** rec
		) {
	return false;
};

ubigint TblWdbeMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMModule& rst
		) {
	return 0;
};

ubigint TblWdbeMModule::insertRec(
			WdbeMModule* rec
		) {
	return 0;
};

ubigint TblWdbeMModule::insertNewRec(
			WdbeMModule** rec
			, const uint ixVBasetype
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const uint hkNum
			, const ubigint supRefWdbeMModule
			, const ubigint tplRefWdbeMModule
			, const ubigint refWdbeMController
			, const ubigint refWdbeMImbuf
			, const string sref
			, const string srefWdbeKVendor
			, const string Srefrule
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMModule* _rec = NULL;

	_rec = new WdbeMModule(0, ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMModule::appendNewRecToRst(
			ListWdbeMModule& rst
			, WdbeMModule** rec
			, const uint ixVBasetype
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const uint hkNum
			, const ubigint supRefWdbeMModule
			, const ubigint tplRefWdbeMModule
			, const ubigint refWdbeMController
			, const ubigint refWdbeMImbuf
			, const string sref
			, const string srefWdbeKVendor
			, const string Srefrule
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMModule* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMModule::insertRst(
			ListWdbeMModule& rst
			, bool transact
		) {
};

void TblWdbeMModule::updateRec(
			WdbeMModule* rec
		) {
};

void TblWdbeMModule::updateRst(
			ListWdbeMModule& rst
			, bool transact
		) {
};

void TblWdbeMModule::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMModule::loadRecByRef(
			ubigint ref
			, WdbeMModule** rec
		) {
	return false;
};

bool TblWdbeMModule::confirmByRef(
			ubigint ref
		) {
	return false;
};

bool TblWdbeMModule::loadRecByCtr(
			ubigint refWdbeMController
			, WdbeMModule** rec
		) {
	return false;
};

bool TblWdbeMModule::loadRecByImb(
			ubigint refWdbeMImbuf
			, WdbeMModule** rec
		) {
	return false;
};

bool TblWdbeMModule::loadRefBySupSrf(
			ubigint supRefWdbeMModule
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWdbeMModule::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMModule::loadRefsBySup(
			ubigint supRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMModule::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListWdbeMModule& rst
		) {
	return 0;
};

ubigint TblWdbeMModule::loadRstBySup(
			ubigint supRefWdbeMModule
			, const bool append
			, ListWdbeMModule& rst
		) {
	return 0;
};

bool TblWdbeMModule::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

bool TblWdbeMModule::loadSupByRef(
			ubigint ref
			, ubigint& supRefWdbeMModule
		) {
	return false;
};

ubigint TblWdbeMModule::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMModule& rst
		) {
	ubigint numload = 0;
	WdbeMModule* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

ubigint TblWdbeMModule::loadHrefsup(
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

ubigint TblWdbeMModule::loadHrefsdown(
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

ubigint TblWdbeMModule::loadHrstup(
			ubigint ref
			, ListWdbeMModule& rst
		) {
	WdbeMModule* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefWdbeMModule;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblWdbeMModule::loadHrstdown(
			ubigint ref
			, const bool append
			, ListWdbeMModule& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	WdbeMModule* rec = NULL;

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
 class MyTblWdbeMModule
 ******************************************************************************/

MyTblWdbeMModule::MyTblWdbeMModule() :
			TblWdbeMModule()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMModule::~MyTblWdbeMModule() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMModule::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMModule (ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMModule SET ixVBasetype = ?, hkIxVTbl = ?, hkUref = ?, hkNum = ?, supRefWdbeMModule = ?, tplRefWdbeMModule = ?, refWdbeMController = ?, refWdbeMImbuf = ?, sref = ?, srefWdbeKVendor = ?, Srefrule = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMModule WHERE ref = ?", false);
};

bool MyTblWdbeMModule::loadRecBySQL(
			const string& sqlstr
			, WdbeMModule** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMModule* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMModule::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMModule::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMModule();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->hkIxVTbl = atol((char*) dbrow[2]); else _rec->hkIxVTbl = 0;
		if (dbrow[3]) _rec->hkUref = atoll((char*) dbrow[3]); else _rec->hkUref = 0;
		if (dbrow[4]) _rec->hkNum = atol((char*) dbrow[4]); else _rec->hkNum = 0;
		if (dbrow[5]) _rec->supRefWdbeMModule = atoll((char*) dbrow[5]); else _rec->supRefWdbeMModule = 0;
		if (dbrow[6]) _rec->tplRefWdbeMModule = atoll((char*) dbrow[6]); else _rec->tplRefWdbeMModule = 0;
		if (dbrow[7]) _rec->refWdbeMController = atoll((char*) dbrow[7]); else _rec->refWdbeMController = 0;
		if (dbrow[8]) _rec->refWdbeMImbuf = atoll((char*) dbrow[8]); else _rec->refWdbeMImbuf = 0;
		if (dbrow[9]) _rec->sref.assign(dbrow[9], dblengths[9]); else _rec->sref = "";
		if (dbrow[10]) _rec->srefWdbeKVendor.assign(dbrow[10], dblengths[10]); else _rec->srefWdbeKVendor = "";
		if (dbrow[11]) _rec->Srefrule.assign(dbrow[11], dblengths[11]); else _rec->Srefrule = "";
		if (dbrow[12]) _rec->Comment.assign(dbrow[12], dblengths[12]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMModule& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMModule* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMModule::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMModule::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMModule();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->hkIxVTbl = atol((char*) dbrow[2]); else rec->hkIxVTbl = 0;
			if (dbrow[3]) rec->hkUref = atoll((char*) dbrow[3]); else rec->hkUref = 0;
			if (dbrow[4]) rec->hkNum = atol((char*) dbrow[4]); else rec->hkNum = 0;
			if (dbrow[5]) rec->supRefWdbeMModule = atoll((char*) dbrow[5]); else rec->supRefWdbeMModule = 0;
			if (dbrow[6]) rec->tplRefWdbeMModule = atoll((char*) dbrow[6]); else rec->tplRefWdbeMModule = 0;
			if (dbrow[7]) rec->refWdbeMController = atoll((char*) dbrow[7]); else rec->refWdbeMController = 0;
			if (dbrow[8]) rec->refWdbeMImbuf = atoll((char*) dbrow[8]); else rec->refWdbeMImbuf = 0;
			if (dbrow[9]) rec->sref.assign(dbrow[9], dblengths[9]); else rec->sref = "";
			if (dbrow[10]) rec->srefWdbeKVendor.assign(dbrow[10], dblengths[10]); else rec->srefWdbeKVendor = "";
			if (dbrow[11]) rec->Srefrule.assign(dbrow[11], dblengths[11]); else rec->Srefrule = "";
			if (dbrow[12]) rec->Comment.assign(dbrow[12], dblengths[12]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMModule::insertRec(
			WdbeMModule* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[8] = rec->sref.length();
	l[9] = rec->srefWdbeKVendor.length();
	l[10] = rec->Srefrule.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->hkIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->hkUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->hkNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->supRefWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->tplRefWdbeMModule,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWdbeMController,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWdbeMImbuf,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->sref.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefWdbeKVendor.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Srefrule.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMModule::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMModule::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMModule::insertRst(
			ListWdbeMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMModule::updateRec(
			WdbeMModule* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[8] = rec->sref.length();
	l[9] = rec->srefWdbeKVendor.length();
	l[10] = rec->Srefrule.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->hkIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->hkUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->hkNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->supRefWdbeMModule,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->tplRefWdbeMModule,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refWdbeMController,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWdbeMImbuf,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->sref.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefWdbeKVendor.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Srefrule.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMModule::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMModule::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMModule::updateRst(
			ListWdbeMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMModule::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMModule::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMModule::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMModule::loadRecByRef(
			ubigint ref
			, WdbeMModule** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMModule WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMModule::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblWdbeMModule::loadRecByCtr(
			ubigint refWdbeMController
			, WdbeMModule** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(refWdbeMController) + "", rec);
};

bool MyTblWdbeMModule::loadRecByImb(
			ubigint refWdbeMImbuf
			, WdbeMModule** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment FROM TblWdbeMModule WHERE refWdbeMImbuf = " + to_string(refWdbeMImbuf) + "", rec);
};

bool MyTblWdbeMModule::loadRefBySupSrf(
			ubigint supRefWdbeMModule
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(supRefWdbeMModule) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWdbeMModule::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", append, refs);
};

ubigint MyTblWdbeMModule::loadRefsBySup(
			ubigint supRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(supRefWdbeMModule) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblWdbeMModule::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListWdbeMModule& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + " ORDER BY hkNum ASC", append, rst);
};

ubigint MyTblWdbeMModule::loadRstBySup(
			ubigint supRefWdbeMModule
			, const bool append
			, ListWdbeMModule& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment FROM TblWdbeMModule WHERE supRefWdbeMModule = " + to_string(supRefWdbeMModule) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMModule::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE ref = " + to_string(ref) + "", sref);
};

bool MyTblWdbeMModule::loadSupByRef(
			ubigint ref
			, ubigint& supRefWdbeMModule
		) {
	return loadRefBySQL("SELECT supRefWdbeMModule FROM TblWdbeMModule WHERE ref = " + to_string(ref) + "", supRefWdbeMModule);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMModule
 ******************************************************************************/

PgTblWdbeMModule::PgTblWdbeMModule() :
			TblWdbeMModule()
			, PgTable()
		{
};

PgTblWdbeMModule::~PgTblWdbeMModule() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMModule::initStatements() {
	createStatement("TblWdbeMModule_insertRec", "INSERT INTO TblWdbeMModule (ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING ref", 12);
	createStatement("TblWdbeMModule_updateRec", "UPDATE TblWdbeMModule SET ixVBasetype = $1, hkIxVTbl = $2, hkUref = $3, hkNum = $4, supRefWdbeMModule = $5, tplRefWdbeMModule = $6, refWdbeMController = $7, refWdbeMImbuf = $8, sref = $9, srefWdbeKVendor = $10, Srefrule = $11, Comment = $12 WHERE ref = $13", 13);
	createStatement("TblWdbeMModule_removeRecByRef", "DELETE FROM TblWdbeMModule WHERE ref = $1", 1);

	createStatement("TblWdbeMModule_loadRecByRef", "SELECT ref, ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment FROM TblWdbeMModule WHERE ref = $1", 1);
	createStatement("TblWdbeMModule_confirmByRef", "SELECT ref FROM TblWdbeMModule WHERE ref = $1", 1);
	createStatement("TblWdbeMModule_loadRecByCtr", "SELECT ref, ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment FROM TblWdbeMModule WHERE refWdbeMController = $1", 1);
	createStatement("TblWdbeMModule_loadRecByImb", "SELECT ref, ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment FROM TblWdbeMModule WHERE refWdbeMImbuf = $1", 1);
	createStatement("TblWdbeMModule_loadRefBySupSrf", "SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = $1 AND sref = $2", 2);
	createStatement("TblWdbeMModule_loadRefsByHktHku", "SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = $1 AND hkUref = $2", 2);
	createStatement("TblWdbeMModule_loadRefsBySup", "SELECT ref FROM TblWdbeMModule WHERE supRefWdbeMModule = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMModule_loadRstByHktHku", "SELECT ref, ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment FROM TblWdbeMModule WHERE hkIxVTbl = $1 AND hkUref = $2 ORDER BY hkNum ASC", 2);
	createStatement("TblWdbeMModule_loadRstBySup", "SELECT ref, ixVBasetype, hkIxVTbl, hkUref, hkNum, supRefWdbeMModule, tplRefWdbeMModule, refWdbeMController, refWdbeMImbuf, sref, srefWdbeKVendor, Srefrule, Comment FROM TblWdbeMModule WHERE supRefWdbeMModule = $1 ORDER BY sref ASC", 1);
	createStatement("TblWdbeMModule_loadSrfByRef", "SELECT sref FROM TblWdbeMModule WHERE ref = $1", 1);
	createStatement("TblWdbeMModule_loadSupByRef", "SELECT supRefWdbeMModule FROM TblWdbeMModule WHERE ref = $1", 1);
};

bool PgTblWdbeMModule::loadRec(
			PGresult* res
			, WdbeMModule** rec
		) {
	char* ptr;

	WdbeMModule* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMModule();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "hknum"),
			PQfnumber(res, "suprefwdbemmodule"),
			PQfnumber(res, "tplrefwdbemmodule"),
			PQfnumber(res, "refwdbemcontroller"),
			PQfnumber(res, "refwdbemimbuf"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefwdbekvendor"),
			PQfnumber(res, "srefrule"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->hkNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->supRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->tplRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refWdbeMController = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWdbeMImbuf = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->srefWdbeKVendor.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Srefrule.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMModule::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMModule& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMModule* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "hknum"),
			PQfnumber(res, "suprefwdbemmodule"),
			PQfnumber(res, "tplrefwdbemmodule"),
			PQfnumber(res, "refwdbemcontroller"),
			PQfnumber(res, "refwdbemimbuf"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "srefwdbekvendor"),
			PQfnumber(res, "srefrule"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMModule();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->hkNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->supRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->tplRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refWdbeMController = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWdbeMImbuf = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->srefWdbeKVendor.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Srefrule.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMModule::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMModule** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMModule::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMModule::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMModule& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMModule::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMModule::loadRecBySQL(
			const string& sqlstr
			, WdbeMModule** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMModule::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMModule::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMModule& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMModule::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMModule::insertRec(
			WdbeMModule* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	uint _hkNum = htonl(rec->hkNum);
	ubigint _supRefWdbeMModule = htonl64(rec->supRefWdbeMModule);
	ubigint _tplRefWdbeMModule = htonl64(rec->tplRefWdbeMModule);
	ubigint _refWdbeMController = htonl64(rec->refWdbeMController);
	ubigint _refWdbeMImbuf = htonl64(rec->refWdbeMImbuf);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_hkNum,
		(char*) &_supRefWdbeMModule,
		(char*) &_tplRefWdbeMModule,
		(char*) &_refWdbeMController,
		(char*) &_refWdbeMImbuf,
		rec->sref.c_str(),
		rec->srefWdbeKVendor.c_str(),
		rec->Srefrule.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMModule_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMModule::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMModule::insertRst(
			ListWdbeMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMModule::updateRec(
			WdbeMModule* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	uint _hkNum = htonl(rec->hkNum);
	ubigint _supRefWdbeMModule = htonl64(rec->supRefWdbeMModule);
	ubigint _tplRefWdbeMModule = htonl64(rec->tplRefWdbeMModule);
	ubigint _refWdbeMController = htonl64(rec->refWdbeMController);
	ubigint _refWdbeMImbuf = htonl64(rec->refWdbeMImbuf);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_hkNum,
		(char*) &_supRefWdbeMModule,
		(char*) &_tplRefWdbeMModule,
		(char*) &_refWdbeMController,
		(char*) &_refWdbeMImbuf,
		rec->sref.c_str(),
		rec->srefWdbeKVendor.c_str(),
		rec->Srefrule.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMModule_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMModule::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMModule::updateRst(
			ListWdbeMModule& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMModule::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMModule_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMModule::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMModule::loadRecByRef(
			ubigint ref
			, WdbeMModule** rec
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

	return loadRecByStmt("TblWdbeMModule_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMModule::confirmByRef(
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

	return loadRefByStmt("TblWdbeMModule_confirmByRef", 1, vals, l, f, _ref);
};

bool PgTblWdbeMModule::loadRecByCtr(
			ubigint refWdbeMController
			, WdbeMModule** rec
		) {
	ubigint _refWdbeMController = htonl64(refWdbeMController);

	const char* vals[] = {
		(char*) &_refWdbeMController
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMModule_loadRecByCtr", 1, vals, l, f, rec);
};

bool PgTblWdbeMModule::loadRecByImb(
			ubigint refWdbeMImbuf
			, WdbeMModule** rec
		) {
	ubigint _refWdbeMImbuf = htonl64(refWdbeMImbuf);

	const char* vals[] = {
		(char*) &_refWdbeMImbuf
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMModule_loadRecByImb", 1, vals, l, f, rec);
};

bool PgTblWdbeMModule::loadRefBySupSrf(
			ubigint supRefWdbeMModule
			, string sref
			, ubigint& ref
		) {
	ubigint _supRefWdbeMModule = htonl64(supRefWdbeMModule);

	const char* vals[] = {
		(char*) &_supRefWdbeMModule,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRefByStmt("TblWdbeMModule_loadRefBySupSrf", 2, vals, l, f, ref);
};

ubigint PgTblWdbeMModule::loadRefsByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblWdbeMModule_loadRefsByHktHku", 2, vals, l, f, append, refs);
};

ubigint PgTblWdbeMModule::loadRefsBySup(
			ubigint supRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefWdbeMModule = htonl64(supRefWdbeMModule);

	const char* vals[] = {
		(char*) &_supRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMModule_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMModule::loadRstByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, const bool append
			, ListWdbeMModule& rst
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWdbeMModule_loadRstByHktHku", 2, vals, l, f, append, rst);
};

ubigint PgTblWdbeMModule::loadRstBySup(
			ubigint supRefWdbeMModule
			, const bool append
			, ListWdbeMModule& rst
		) {
	ubigint _supRefWdbeMModule = htonl64(supRefWdbeMModule);

	const char* vals[] = {
		(char*) &_supRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMModule_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMModule::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMModule_loadSrfByRef", 1, vals, l, f, sref);
};

bool PgTblWdbeMModule::loadSupByRef(
			ubigint ref
			, ubigint& supRefWdbeMModule
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWdbeMModule_loadSupByRef", 1, vals, l, f, supRefWdbeMModule);
};

#endif
