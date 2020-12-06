/**
	* \file WdbeMUnit.cpp
	* database access for table TblWdbeMUnit (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMUnit.h"

#include "WdbeMUnit_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMUnit
 ******************************************************************************/

WdbeMUnit::WdbeMUnit(
			const ubigint ref
			, const uint ixVBasetype
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint silRefWdbeMUnit
			, const ubigint refWdbeMSystem
			, const ubigint refWdbeMModule
			, const string sref
			, const string Title
			, const string Fullsref
			, const string srefKPackage
			, const bool Easy
			, const string srefKToolch
			, const string Comment
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->silRefWdbeMUnit = silRefWdbeMUnit;
	this->refWdbeMSystem = refWdbeMSystem;
	this->refWdbeMModule = refWdbeMModule;
	this->sref = sref;
	this->Title = Title;
	this->Fullsref = Fullsref;
	this->srefKPackage = srefKPackage;
	this->Easy = Easy;
	this->srefKToolch = srefKToolch;
	this->Comment = Comment;
};

bool WdbeMUnit::operator==(
			const WdbeMUnit& comp
		) {
	return false;
};

bool WdbeMUnit::operator!=(
			const WdbeMUnit& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMUnit
 ******************************************************************************/

ListWdbeMUnit::ListWdbeMUnit() {
};

ListWdbeMUnit::ListWdbeMUnit(
			const ListWdbeMUnit& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMUnit(*(src.nodes[i]));
};

ListWdbeMUnit::~ListWdbeMUnit() {
	clear();
};

void ListWdbeMUnit::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMUnit::size() const {
	return(nodes.size());
};

void ListWdbeMUnit::append(
			WdbeMUnit* rec
		) {
	nodes.push_back(rec);
};

WdbeMUnit* ListWdbeMUnit::operator[](
			const uint ix
		) {
	WdbeMUnit* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMUnit& ListWdbeMUnit::operator=(
			const ListWdbeMUnit& src
		) {
	WdbeMUnit* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMUnit(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMUnit::operator==(
			const ListWdbeMUnit& comp
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

bool ListWdbeMUnit::operator!=(
			const ListWdbeMUnit& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMUnit
 ******************************************************************************/

TblWdbeMUnit::TblWdbeMUnit() {
};

TblWdbeMUnit::~TblWdbeMUnit() {
};

bool TblWdbeMUnit::loadRecBySQL(
			const string& sqlstr
			, WdbeMUnit** rec
		) {
	return false;
};

ubigint TblWdbeMUnit::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMUnit& rst
		) {
	return 0;
};

ubigint TblWdbeMUnit::insertRec(
			WdbeMUnit* rec
		) {
	return 0;
};

ubigint TblWdbeMUnit::insertNewRec(
			WdbeMUnit** rec
			, const uint ixVBasetype
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint silRefWdbeMUnit
			, const ubigint refWdbeMSystem
			, const ubigint refWdbeMModule
			, const string sref
			, const string Title
			, const string Fullsref
			, const string srefKPackage
			, const bool Easy
			, const string srefKToolch
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMUnit* _rec = NULL;

	_rec = new WdbeMUnit(0, ixVBasetype, refIxVTbl, refUref, silRefWdbeMUnit, refWdbeMSystem, refWdbeMModule, sref, Title, Fullsref, srefKPackage, Easy, srefKToolch, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMUnit::appendNewRecToRst(
			ListWdbeMUnit& rst
			, WdbeMUnit** rec
			, const uint ixVBasetype
			, const uint refIxVTbl
			, const ubigint refUref
			, const ubigint silRefWdbeMUnit
			, const ubigint refWdbeMSystem
			, const ubigint refWdbeMModule
			, const string sref
			, const string Title
			, const string Fullsref
			, const string srefKPackage
			, const bool Easy
			, const string srefKToolch
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMUnit* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refIxVTbl, refUref, silRefWdbeMUnit, refWdbeMSystem, refWdbeMModule, sref, Title, Fullsref, srefKPackage, Easy, srefKToolch, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMUnit::insertRst(
			ListWdbeMUnit& rst
			, bool transact
		) {
};

void TblWdbeMUnit::updateRec(
			WdbeMUnit* rec
		) {
};

void TblWdbeMUnit::updateRst(
			ListWdbeMUnit& rst
			, bool transact
		) {
};

void TblWdbeMUnit::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMUnit::loadRecByRef(
			ubigint ref
			, WdbeMUnit** rec
		) {
	return false;
};

bool TblWdbeMUnit::loadFsrByRef(
			ubigint ref
			, string& Fullsref
		) {
	return false;
};

bool TblWdbeMUnit::loadRecBySys(
			ubigint refWdbeMSystem
			, WdbeMUnit** rec
		) {
	return false;
};

ubigint TblWdbeMUnit::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMUnit& rst
		) {
	return 0;
};

bool TblWdbeMUnit::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

bool TblWdbeMUnit::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblWdbeMUnit::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMUnit& rst
		) {
	ubigint numload = 0;
	WdbeMUnit* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMUnit
 ******************************************************************************/

MyTblWdbeMUnit::MyTblWdbeMUnit() :
			TblWdbeMUnit()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMUnit::~MyTblWdbeMUnit() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMUnit::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMUnit (ixVBasetype, refIxVTbl, refUref, silRefWdbeMUnit, refWdbeMSystem, refWdbeMModule, sref, Title, Fullsref, srefKPackage, Easy, srefKToolch, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMUnit SET ixVBasetype = ?, refIxVTbl = ?, refUref = ?, silRefWdbeMUnit = ?, refWdbeMSystem = ?, refWdbeMModule = ?, sref = ?, Title = ?, Fullsref = ?, srefKPackage = ?, Easy = ?, srefKToolch = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMUnit WHERE ref = ?", false);
};

bool MyTblWdbeMUnit::loadRecBySQL(
			const string& sqlstr
			, WdbeMUnit** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMUnit* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMUnit::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMUnit::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMUnit();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refIxVTbl = atol((char*) dbrow[2]); else _rec->refIxVTbl = 0;
		if (dbrow[3]) _rec->refUref = atoll((char*) dbrow[3]); else _rec->refUref = 0;
		if (dbrow[4]) _rec->silRefWdbeMUnit = atoll((char*) dbrow[4]); else _rec->silRefWdbeMUnit = 0;
		if (dbrow[5]) _rec->refWdbeMSystem = atoll((char*) dbrow[5]); else _rec->refWdbeMSystem = 0;
		if (dbrow[6]) _rec->refWdbeMModule = atoll((char*) dbrow[6]); else _rec->refWdbeMModule = 0;
		if (dbrow[7]) _rec->sref.assign(dbrow[7], dblengths[7]); else _rec->sref = "";
		if (dbrow[8]) _rec->Title.assign(dbrow[8], dblengths[8]); else _rec->Title = "";
		if (dbrow[9]) _rec->Fullsref.assign(dbrow[9], dblengths[9]); else _rec->Fullsref = "";
		if (dbrow[10]) _rec->srefKPackage.assign(dbrow[10], dblengths[10]); else _rec->srefKPackage = "";
		if (dbrow[11]) _rec->Easy = (atoi((char*) dbrow[11]) != 0); else _rec->Easy = false;
		if (dbrow[12]) _rec->srefKToolch.assign(dbrow[12], dblengths[12]); else _rec->srefKToolch = "";
		if (dbrow[13]) _rec->Comment.assign(dbrow[13], dblengths[13]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMUnit::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMUnit& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMUnit* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMUnit::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMUnit::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMUnit();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refIxVTbl = atol((char*) dbrow[2]); else rec->refIxVTbl = 0;
			if (dbrow[3]) rec->refUref = atoll((char*) dbrow[3]); else rec->refUref = 0;
			if (dbrow[4]) rec->silRefWdbeMUnit = atoll((char*) dbrow[4]); else rec->silRefWdbeMUnit = 0;
			if (dbrow[5]) rec->refWdbeMSystem = atoll((char*) dbrow[5]); else rec->refWdbeMSystem = 0;
			if (dbrow[6]) rec->refWdbeMModule = atoll((char*) dbrow[6]); else rec->refWdbeMModule = 0;
			if (dbrow[7]) rec->sref.assign(dbrow[7], dblengths[7]); else rec->sref = "";
			if (dbrow[8]) rec->Title.assign(dbrow[8], dblengths[8]); else rec->Title = "";
			if (dbrow[9]) rec->Fullsref.assign(dbrow[9], dblengths[9]); else rec->Fullsref = "";
			if (dbrow[10]) rec->srefKPackage.assign(dbrow[10], dblengths[10]); else rec->srefKPackage = "";
			if (dbrow[11]) rec->Easy = (atoi((char*) dbrow[11]) != 0); else rec->Easy = false;
			if (dbrow[12]) rec->srefKToolch.assign(dbrow[12], dblengths[12]); else rec->srefKToolch = "";
			if (dbrow[13]) rec->Comment.assign(dbrow[13], dblengths[13]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMUnit::insertRec(
			WdbeMUnit* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[6] = rec->sref.length();
	l[7] = rec->Title.length();
	l[8] = rec->Fullsref.length();
	l[9] = rec->srefKPackage.length();
	tinyint Easy = rec->Easy;
	l[11] = rec->srefKToolch.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->refIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refUref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->silRefWdbeMUnit,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMSystem,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWdbeMModule,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKPackage.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindTinyint(&Easy,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->srefKToolch.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMUnit::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMUnit::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMUnit::insertRst(
			ListWdbeMUnit& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMUnit::updateRec(
			WdbeMUnit* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[6] = rec->sref.length();
	l[7] = rec->Title.length();
	l[8] = rec->Fullsref.length();
	l[9] = rec->srefKPackage.length();
	tinyint Easy = rec->Easy;
	l[11] = rec->srefKToolch.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->refIxVTbl,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refUref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->silRefWdbeMUnit,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMSystem,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refWdbeMModule,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->sref.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Title.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Fullsref.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKPackage.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindTinyint(&Easy,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->srefKToolch.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMUnit::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMUnit::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMUnit::updateRst(
			ListWdbeMUnit& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMUnit::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMUnit::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMUnit::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMUnit::loadRecByRef(
			ubigint ref
			, WdbeMUnit** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMUnit WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMUnit::loadFsrByRef(
			ubigint ref
			, string& Fullsref
		) {
	return loadStringBySQL("SELECT Fullsref FROM TblWdbeMUnit WHERE ref = " + to_string(ref) + "", Fullsref);
};

bool MyTblWdbeMUnit::loadRecBySys(
			ubigint refWdbeMSystem
			, WdbeMUnit** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refIxVTbl, refUref, silRefWdbeMUnit, refWdbeMSystem, refWdbeMModule, sref, Title, Fullsref, srefKPackage, Easy, srefKToolch, Comment FROM TblWdbeMUnit WHERE refWdbeMSystem = " + to_string(refWdbeMSystem) + "", rec);
};

ubigint MyTblWdbeMUnit::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMUnit& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refIxVTbl, refUref, silRefWdbeMUnit, refWdbeMSystem, refWdbeMModule, sref, Title, Fullsref, srefKPackage, Easy, srefKToolch, Comment FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " ORDER BY sref ASC", append, rst);
};

bool MyTblWdbeMUnit::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMUnit WHERE ref = " + to_string(ref) + "", sref);
};

bool MyTblWdbeMUnit::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWdbeMUnit WHERE ref = " + to_string(ref) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMUnit
 ******************************************************************************/

PgTblWdbeMUnit::PgTblWdbeMUnit() :
			TblWdbeMUnit()
			, PgTable()
		{
};

PgTblWdbeMUnit::~PgTblWdbeMUnit() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMUnit::initStatements() {
	createStatement("TblWdbeMUnit_insertRec", "INSERT INTO TblWdbeMUnit (ixVBasetype, refIxVTbl, refUref, silRefWdbeMUnit, refWdbeMSystem, refWdbeMModule, sref, Title, Fullsref, srefKPackage, Easy, srefKToolch, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13);
	createStatement("TblWdbeMUnit_updateRec", "UPDATE TblWdbeMUnit SET ixVBasetype = $1, refIxVTbl = $2, refUref = $3, silRefWdbeMUnit = $4, refWdbeMSystem = $5, refWdbeMModule = $6, sref = $7, Title = $8, Fullsref = $9, srefKPackage = $10, Easy = $11, srefKToolch = $12, Comment = $13 WHERE ref = $14", 14);
	createStatement("TblWdbeMUnit_removeRecByRef", "DELETE FROM TblWdbeMUnit WHERE ref = $1", 1);

	createStatement("TblWdbeMUnit_loadRecByRef", "SELECT ref, ixVBasetype, refIxVTbl, refUref, silRefWdbeMUnit, refWdbeMSystem, refWdbeMModule, sref, Title, Fullsref, srefKPackage, Easy, srefKToolch, Comment FROM TblWdbeMUnit WHERE ref = $1", 1);
	createStatement("TblWdbeMUnit_loadFsrByRef", "SELECT Fullsref FROM TblWdbeMUnit WHERE ref = $1", 1);
	createStatement("TblWdbeMUnit_loadRecBySys", "SELECT ref, ixVBasetype, refIxVTbl, refUref, silRefWdbeMUnit, refWdbeMSystem, refWdbeMModule, sref, Title, Fullsref, srefKPackage, Easy, srefKToolch, Comment FROM TblWdbeMUnit WHERE refWdbeMSystem = $1", 1);
	createStatement("TblWdbeMUnit_loadRstByRetReu", "SELECT ref, ixVBasetype, refIxVTbl, refUref, silRefWdbeMUnit, refWdbeMSystem, refWdbeMModule, sref, Title, Fullsref, srefKPackage, Easy, srefKToolch, Comment FROM TblWdbeMUnit WHERE refIxVTbl = $1 AND refUref = $2 ORDER BY sref ASC", 2);
	createStatement("TblWdbeMUnit_loadSrfByRef", "SELECT sref FROM TblWdbeMUnit WHERE ref = $1", 1);
	createStatement("TblWdbeMUnit_loadTitByRef", "SELECT Title FROM TblWdbeMUnit WHERE ref = $1", 1);
};

bool PgTblWdbeMUnit::loadRec(
			PGresult* res
			, WdbeMUnit** rec
		) {
	char* ptr;

	WdbeMUnit* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMUnit();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "silrefwdbemunit"),
			PQfnumber(res, "refwdbemsystem"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "srefkpackage"),
			PQfnumber(res, "easy"),
			PQfnumber(res, "srefktoolch"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->silRefWdbeMUnit = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWdbeMSystem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Fullsref.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->srefKPackage.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Easy = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->srefKToolch.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMUnit::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMUnit& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMUnit* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "silrefwdbemunit"),
			PQfnumber(res, "refwdbemsystem"),
			PQfnumber(res, "refwdbemmodule"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "fullsref"),
			PQfnumber(res, "srefkpackage"),
			PQfnumber(res, "easy"),
			PQfnumber(res, "srefktoolch"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMUnit();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->silRefWdbeMUnit = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWdbeMSystem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Fullsref.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->srefKPackage.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Easy = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->srefKToolch.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMUnit::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMUnit** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMUnit::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMUnit::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMUnit& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMUnit::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMUnit::loadRecBySQL(
			const string& sqlstr
			, WdbeMUnit** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMUnit::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMUnit::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMUnit& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMUnit::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMUnit::insertRec(
			WdbeMUnit* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _silRefWdbeMUnit = htonl64(rec->silRefWdbeMUnit);
	ubigint _refWdbeMSystem = htonl64(rec->refWdbeMSystem);
	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	smallint _Easy = htons((smallint) rec->Easy);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_silRefWdbeMUnit,
		(char*) &_refWdbeMSystem,
		(char*) &_refWdbeMModule,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Fullsref.c_str(),
		rec->srefKPackage.c_str(),
		(char*) &_Easy,
		rec->srefKToolch.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(smallint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMUnit_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMUnit::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMUnit::insertRst(
			ListWdbeMUnit& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMUnit::updateRec(
			WdbeMUnit* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	ubigint _silRefWdbeMUnit = htonl64(rec->silRefWdbeMUnit);
	ubigint _refWdbeMSystem = htonl64(rec->refWdbeMSystem);
	ubigint _refWdbeMModule = htonl64(rec->refWdbeMModule);
	smallint _Easy = htons((smallint) rec->Easy);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_silRefWdbeMUnit,
		(char*) &_refWdbeMSystem,
		(char*) &_refWdbeMModule,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->Fullsref.c_str(),
		rec->srefKPackage.c_str(),
		(char*) &_Easy,
		rec->srefKToolch.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(smallint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMUnit_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMUnit::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMUnit::updateRst(
			ListWdbeMUnit& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMUnit::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMUnit_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMUnit::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMUnit::loadRecByRef(
			ubigint ref
			, WdbeMUnit** rec
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

	return loadRecByStmt("TblWdbeMUnit_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMUnit::loadFsrByRef(
			ubigint ref
			, string& Fullsref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMUnit_loadFsrByRef", 1, vals, l, f, Fullsref);
};

bool PgTblWdbeMUnit::loadRecBySys(
			ubigint refWdbeMSystem
			, WdbeMUnit** rec
		) {
	ubigint _refWdbeMSystem = htonl64(refWdbeMSystem);

	const char* vals[] = {
		(char*) &_refWdbeMSystem
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMUnit_loadRecBySys", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMUnit::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMUnit& rst
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWdbeMUnit_loadRstByRetReu", 2, vals, l, f, append, rst);
};

bool PgTblWdbeMUnit::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMUnit_loadSrfByRef", 1, vals, l, f, sref);
};

bool PgTblWdbeMUnit::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMUnit_loadTitByRef", 1, vals, l, f, Title);
};

#endif
