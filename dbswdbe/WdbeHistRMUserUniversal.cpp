/**
	* \file WdbeHistRMUserUniversal.cpp
	* database access for table TblWdbeHistRMUserUniversal (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeHistRMUserUniversal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeHistRMUserUniversal
 ******************************************************************************/

WdbeHistRMUserUniversal::WdbeHistRMUserUniversal(
			const ubigint ref
			, const ubigint refWdbeMUser
			, const uint unvIxWdbeVMaintable
			, const ubigint unvUref
			, const uint ixWdbeVCard
			, const uint ixWdbeVPreset
			, const uint preIxWdbeVMaintable
			, const ubigint preUref
			, const uint start
		) {

	this->ref = ref;
	this->refWdbeMUser = refWdbeMUser;
	this->unvIxWdbeVMaintable = unvIxWdbeVMaintable;
	this->unvUref = unvUref;
	this->ixWdbeVCard = ixWdbeVCard;
	this->ixWdbeVPreset = ixWdbeVPreset;
	this->preIxWdbeVMaintable = preIxWdbeVMaintable;
	this->preUref = preUref;
	this->start = start;
};

bool WdbeHistRMUserUniversal::operator==(
			const WdbeHistRMUserUniversal& comp
		) {
	return false;
};

bool WdbeHistRMUserUniversal::operator!=(
			const WdbeHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeHistRMUserUniversal
 ******************************************************************************/

ListWdbeHistRMUserUniversal::ListWdbeHistRMUserUniversal() {
};

ListWdbeHistRMUserUniversal::ListWdbeHistRMUserUniversal(
			const ListWdbeHistRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeHistRMUserUniversal(*(src.nodes[i]));
};

ListWdbeHistRMUserUniversal::~ListWdbeHistRMUserUniversal() {
	clear();
};

void ListWdbeHistRMUserUniversal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeHistRMUserUniversal::size() const {
	return(nodes.size());
};

void ListWdbeHistRMUserUniversal::append(
			WdbeHistRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

WdbeHistRMUserUniversal* ListWdbeHistRMUserUniversal::operator[](
			const uint ix
		) {
	WdbeHistRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeHistRMUserUniversal& ListWdbeHistRMUserUniversal::operator=(
			const ListWdbeHistRMUserUniversal& src
		) {
	WdbeHistRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeHistRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeHistRMUserUniversal::operator==(
			const ListWdbeHistRMUserUniversal& comp
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

bool ListWdbeHistRMUserUniversal::operator!=(
			const ListWdbeHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeHistRMUserUniversal
 ******************************************************************************/

TblWdbeHistRMUserUniversal::TblWdbeHistRMUserUniversal() {
};

TblWdbeHistRMUserUniversal::~TblWdbeHistRMUserUniversal() {
};

bool TblWdbeHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WdbeHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWdbeHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeHistRMUserUniversal& rst
		) {
	return 0;
};

ubigint TblWdbeHistRMUserUniversal::insertRec(
			WdbeHistRMUserUniversal* rec
		) {
	return 0;
};

ubigint TblWdbeHistRMUserUniversal::insertNewRec(
			WdbeHistRMUserUniversal** rec
			, const ubigint refWdbeMUser
			, const uint unvIxWdbeVMaintable
			, const ubigint unvUref
			, const uint ixWdbeVCard
			, const uint ixWdbeVPreset
			, const uint preIxWdbeVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	WdbeHistRMUserUniversal* _rec = NULL;

	_rec = new WdbeHistRMUserUniversal(0, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVCard, ixWdbeVPreset, preIxWdbeVMaintable, preUref, start);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeHistRMUserUniversal::appendNewRecToRst(
			ListWdbeHistRMUserUniversal& rst
			, WdbeHistRMUserUniversal** rec
			, const ubigint refWdbeMUser
			, const uint unvIxWdbeVMaintable
			, const ubigint unvUref
			, const uint ixWdbeVCard
			, const uint ixWdbeVPreset
			, const uint preIxWdbeVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	WdbeHistRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVCard, ixWdbeVPreset, preIxWdbeVMaintable, preUref, start);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeHistRMUserUniversal::insertRst(
			ListWdbeHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblWdbeHistRMUserUniversal::updateRec(
			WdbeHistRMUserUniversal* rec
		) {
};

void TblWdbeHistRMUserUniversal::updateRst(
			ListWdbeHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblWdbeHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WdbeHistRMUserUniversal** rec
		) {
	return false;
};

bool TblWdbeHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWdbeMUser
			, uint unvIxWdbeVMaintable
			, ubigint unvUref
			, uint ixWdbeVCard
			, WdbeHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblWdbeHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWdbeMUser
			, uint unvIxWdbeVMaintable
			, uint ixWdbeVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	return 0;
};

ubigint TblWdbeHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWdbeMUser
			, uint ixWdbeVCard
			, const bool append
			, ListWdbeHistRMUserUniversal& rst
		) {
	return 0;
};

bool TblWdbeHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	return false;
};

ubigint TblWdbeHistRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeHistRMUserUniversal& rst
		) {
	ubigint numload = 0;
	WdbeHistRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeHistRMUserUniversal
 ******************************************************************************/

MyTblWdbeHistRMUserUniversal::MyTblWdbeHistRMUserUniversal() :
			TblWdbeHistRMUserUniversal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeHistRMUserUniversal::~MyTblWdbeHistRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeHistRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeHistRMUserUniversal (refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVCard, ixWdbeVPreset, preIxWdbeVMaintable, preUref, start) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeHistRMUserUniversal SET refWdbeMUser = ?, unvIxWdbeVMaintable = ?, unvUref = ?, ixWdbeVCard = ?, ixWdbeVPreset = ?, preIxWdbeVMaintable = ?, preUref = ?, start = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeHistRMUserUniversal WHERE ref = ?", false);
};

bool MyTblWdbeHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WdbeHistRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeHistRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeHistRMUserUniversal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeHistRMUserUniversal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new WdbeHistRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeMUser = atoll((char*) dbrow[1]); else _rec->refWdbeMUser = 0;
		if (dbrow[2]) _rec->unvIxWdbeVMaintable = atol((char*) dbrow[2]); else _rec->unvIxWdbeVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixWdbeVCard = atol((char*) dbrow[4]); else _rec->ixWdbeVCard = 0;
		if (dbrow[5]) _rec->ixWdbeVPreset = atol((char*) dbrow[5]); else _rec->ixWdbeVPreset = 0;
		if (dbrow[6]) _rec->preIxWdbeVMaintable = atol((char*) dbrow[6]); else _rec->preIxWdbeVMaintable = 0;
		if (dbrow[7]) _rec->preUref = atoll((char*) dbrow[7]); else _rec->preUref = 0;
		if (dbrow[8]) _rec->start = atol((char*) dbrow[8]); else _rec->start = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeHistRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeHistRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeHistRMUserUniversal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeHistRMUserUniversal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new WdbeHistRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeMUser = atoll((char*) dbrow[1]); else rec->refWdbeMUser = 0;
			if (dbrow[2]) rec->unvIxWdbeVMaintable = atol((char*) dbrow[2]); else rec->unvIxWdbeVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixWdbeVCard = atol((char*) dbrow[4]); else rec->ixWdbeVCard = 0;
			if (dbrow[5]) rec->ixWdbeVPreset = atol((char*) dbrow[5]); else rec->ixWdbeVPreset = 0;
			if (dbrow[6]) rec->preIxWdbeVMaintable = atol((char*) dbrow[6]); else rec->preIxWdbeVMaintable = 0;
			if (dbrow[7]) rec->preUref = atoll((char*) dbrow[7]); else rec->preUref = 0;
			if (dbrow[8]) rec->start = atol((char*) dbrow[8]); else rec->start = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeHistRMUserUniversal::insertRec(
			WdbeHistRMUserUniversal* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWdbeVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWdbeVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxWdbeVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeHistRMUserUniversal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeHistRMUserUniversal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeHistRMUserUniversal::insertRst(
			ListWdbeHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeHistRMUserUniversal::updateRec(
			WdbeHistRMUserUniversal* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxWdbeVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixWdbeVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixWdbeVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxWdbeVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeHistRMUserUniversal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeHistRMUserUniversal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeHistRMUserUniversal::updateRst(
			ListWdbeHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeHistRMUserUniversal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeHistRMUserUniversal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WdbeHistRMUserUniversal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeHistRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWdbeMUser
			, uint unvIxWdbeVMaintable
			, ubigint unvUref
			, uint ixWdbeVCard
			, WdbeHistRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVCard, ixWdbeVPreset, preIxWdbeVMaintable, preUref, start FROM TblWdbeHistRMUserUniversal WHERE refWdbeMUser = " + to_string(refWdbeMUser) + " AND unvIxWdbeVMaintable = " + to_string(unvIxWdbeVMaintable) + " AND unvUref = " + to_string(unvUref) + " AND ixWdbeVCard = " + to_string(ixWdbeVCard) + "", rec);
};

ubigint MyTblWdbeHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWdbeMUser
			, uint unvIxWdbeVMaintable
			, uint ixWdbeVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	if ((limit == 0) && (offset == 0)) limit--;

	return loadRefsBySQL("SELECT ref FROM TblWdbeHistRMUserUniversal WHERE refWdbeMUser = " + to_string(refWdbeMUser) + " AND unvIxWdbeVMaintable = " + to_string(unvIxWdbeVMaintable) + " AND ixWdbeVCard = " + to_string(ixWdbeVCard) + " ORDER BY start DESC LIMIT " + to_string(offset) + "," + to_string(limit) + "", append, refs);
};

ubigint MyTblWdbeHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWdbeMUser
			, uint ixWdbeVCard
			, const bool append
			, ListWdbeHistRMUserUniversal& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVCard, ixWdbeVPreset, preIxWdbeVMaintable, preUref, start FROM TblWdbeHistRMUserUniversal WHERE refWdbeMUser = " + to_string(refWdbeMUser) + " AND ixWdbeVCard = " + to_string(ixWdbeVCard) + " ORDER BY start DESC", append, rst);
};

bool MyTblWdbeHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	return loadRefBySQL("SELECT unvUref FROM TblWdbeHistRMUserUniversal WHERE ref = " + to_string(ref) + "", unvUref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeHistRMUserUniversal
 ******************************************************************************/

PgTblWdbeHistRMUserUniversal::PgTblWdbeHistRMUserUniversal() :
			TblWdbeHistRMUserUniversal()
			, PgTable()
		{
};

PgTblWdbeHistRMUserUniversal::~PgTblWdbeHistRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeHistRMUserUniversal::initStatements() {
	createStatement("TblWdbeHistRMUserUniversal_insertRec", "INSERT INTO TblWdbeHistRMUserUniversal (refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVCard, ixWdbeVPreset, preIxWdbeVMaintable, preUref, start) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8);
	createStatement("TblWdbeHistRMUserUniversal_updateRec", "UPDATE TblWdbeHistRMUserUniversal SET refWdbeMUser = $1, unvIxWdbeVMaintable = $2, unvUref = $3, ixWdbeVCard = $4, ixWdbeVPreset = $5, preIxWdbeVMaintable = $6, preUref = $7, start = $8 WHERE ref = $9", 9);
	createStatement("TblWdbeHistRMUserUniversal_removeRecByRef", "DELETE FROM TblWdbeHistRMUserUniversal WHERE ref = $1", 1);

	createStatement("TblWdbeHistRMUserUniversal_loadRecByRef", "SELECT ref, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVCard, ixWdbeVPreset, preIxWdbeVMaintable, preUref, start FROM TblWdbeHistRMUserUniversal WHERE ref = $1", 1);
	createStatement("TblWdbeHistRMUserUniversal_loadRecByUsrMtbUnvCrd", "SELECT ref, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVCard, ixWdbeVPreset, preIxWdbeVMaintable, preUref, start FROM TblWdbeHistRMUserUniversal WHERE refWdbeMUser = $1 AND unvIxWdbeVMaintable = $2 AND unvUref = $3 AND ixWdbeVCard = $4", 4);
	createStatement("TblWdbeHistRMUserUniversal_loadRefsByUsrMtbCrd", "SELECT ref FROM TblWdbeHistRMUserUniversal WHERE refWdbeMUser = $1 AND unvIxWdbeVMaintable = $2 AND ixWdbeVCard = $3 ORDER BY start DESC OFFSET $4 LIMIT $5", 5);
	createStatement("TblWdbeHistRMUserUniversal_loadRstByUsrCrd", "SELECT ref, refWdbeMUser, unvIxWdbeVMaintable, unvUref, ixWdbeVCard, ixWdbeVPreset, preIxWdbeVMaintable, preUref, start FROM TblWdbeHistRMUserUniversal WHERE refWdbeMUser = $1 AND ixWdbeVCard = $2 ORDER BY start DESC", 2);
	createStatement("TblWdbeHistRMUserUniversal_loadUnuByRef", "SELECT unvUref FROM TblWdbeHistRMUserUniversal WHERE ref = $1", 1);
};

bool PgTblWdbeHistRMUserUniversal::loadRec(
			PGresult* res
			, WdbeHistRMUserUniversal** rec
		) {
	char* ptr;

	WdbeHistRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeHistRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "unvixwdbevmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwdbevcard"),
			PQfnumber(res, "ixwdbevpreset"),
			PQfnumber(res, "preixwdbevmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxWdbeVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixWdbeVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixWdbeVPreset = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->preIxWdbeVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->preUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->start = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeHistRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeHistRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeHistRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbemuser"),
			PQfnumber(res, "unvixwdbevmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixwdbevcard"),
			PQfnumber(res, "ixwdbevpreset"),
			PQfnumber(res, "preixwdbevmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		while (numread < numrow) {
			rec = new WdbeHistRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxWdbeVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixWdbeVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixWdbeVPreset = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->preIxWdbeVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->preUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->start = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeHistRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeHistRMUserUniversal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeHistRMUserUniversal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeHistRMUserUniversal::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, WdbeHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeHistRMUserUniversal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeHistRMUserUniversal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeHistRMUserUniversal::insertRec(
			WdbeHistRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	uint _unvIxWdbeVMaintable = htonl(rec->unvIxWdbeVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWdbeVCard = htonl(rec->ixWdbeVCard);
	uint _ixWdbeVPreset = htonl(rec->ixWdbeVPreset);
	uint _preIxWdbeVMaintable = htonl(rec->preIxWdbeVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_unvIxWdbeVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWdbeVCard,
		(char*) &_ixWdbeVPreset,
		(char*) &_preIxWdbeVMaintable,
		(char*) &_preUref,
		(char*) &_start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeHistRMUserUniversal_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeHistRMUserUniversal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeHistRMUserUniversal::insertRst(
			ListWdbeHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeHistRMUserUniversal::updateRec(
			WdbeHistRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refWdbeMUser = htonl64(rec->refWdbeMUser);
	uint _unvIxWdbeVMaintable = htonl(rec->unvIxWdbeVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixWdbeVCard = htonl(rec->ixWdbeVCard);
	uint _ixWdbeVPreset = htonl(rec->ixWdbeVPreset);
	uint _preIxWdbeVMaintable = htonl(rec->preIxWdbeVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_unvIxWdbeVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWdbeVCard,
		(char*) &_ixWdbeVPreset,
		(char*) &_preIxWdbeVMaintable,
		(char*) &_preUref,
		(char*) &_start,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblWdbeHistRMUserUniversal_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeHistRMUserUniversal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeHistRMUserUniversal::updateRst(
			ListWdbeHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeHistRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeHistRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeHistRMUserUniversal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, WdbeHistRMUserUniversal** rec
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

	return loadRecByStmt("TblWdbeHistRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeHistRMUserUniversal::loadRecByUsrMtbUnvCrd(
			ubigint refWdbeMUser
			, uint unvIxWdbeVMaintable
			, ubigint unvUref
			, uint ixWdbeVCard
			, WdbeHistRMUserUniversal** rec
		) {
	ubigint _refWdbeMUser = htonl64(refWdbeMUser);
	uint _unvIxWdbeVMaintable = htonl(unvIxWdbeVMaintable);
	ubigint _unvUref = htonl64(unvUref);
	uint _ixWdbeVCard = htonl(ixWdbeVCard);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_unvIxWdbeVMaintable,
		(char*) &_unvUref,
		(char*) &_ixWdbeVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1,1,1};

	return loadRecByStmt("TblWdbeHistRMUserUniversal_loadRecByUsrMtbUnvCrd", 4, vals, l, f, rec);
};

ubigint PgTblWdbeHistRMUserUniversal::loadRefsByUsrMtbCrd(
			ubigint refWdbeMUser
			, uint unvIxWdbeVMaintable
			, uint ixWdbeVCard
			, const bool append
			, vector<ubigint>& refs
			, ubigint limit
			, ubigint offset
		) {
	ubigint _refWdbeMUser = htonl64(refWdbeMUser);
	uint _unvIxWdbeVMaintable = htonl(unvIxWdbeVMaintable);
	uint _ixWdbeVCard = htonl(ixWdbeVCard);
	ubigint _offset = htonl64(offset);

	ubigint _limit = htonl64(limit);
	char* _limitptr = NULL;
	int _limitl = 0;

	if (limit != 0) {
		_limitptr = (char*) &_limit;
		_limitl = sizeof(ubigint);
	};

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_unvIxWdbeVMaintable,
		(char*) &_ixWdbeVCard,
		(char*) &_offset,
		_limitptr
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		_limitl
	};
	const int f[] = {1,1,1,1,1};

	return loadRefsByStmt("TblWdbeHistRMUserUniversal_loadRefsByUsrMtbCrd", 3, vals, l, f, append, refs);
};

ubigint PgTblWdbeHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refWdbeMUser
			, uint ixWdbeVCard
			, const bool append
			, ListWdbeHistRMUserUniversal& rst
		) {
	ubigint _refWdbeMUser = htonl64(refWdbeMUser);
	uint _ixWdbeVCard = htonl(ixWdbeVCard);

	const char* vals[] = {
		(char*) &_refWdbeMUser,
		(char*) &_ixWdbeVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWdbeHistRMUserUniversal_loadRstByUsrCrd", 2, vals, l, f, append, rst);
};

bool PgTblWdbeHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWdbeHistRMUserUniversal_loadUnuByRef", 1, vals, l, f, unvUref);
};

#endif

