/**
	* \file WdbeMUser.cpp
	* database access for table TblWdbeMUser (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMUser.h"

#include "WdbeMUser_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMUser
 ******************************************************************************/

WdbeMUser::WdbeMUser(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWdbeMUsergroup
			, const ubigint refWdbeMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWdbeVLocale
			, const uint ixWdbeVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refRUsergroup = refRUsergroup;
	this->refWdbeMUsergroup = refWdbeMUsergroup;
	this->refWdbeMPerson = refWdbeMPerson;
	this->sref = sref;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->ixWdbeVLocale = ixWdbeVLocale;
	this->ixWdbeVUserlevel = ixWdbeVUserlevel;
	this->Password = Password;
	this->Fullkey = Fullkey;
	this->Comment = Comment;
};

bool WdbeMUser::operator==(
			const WdbeMUser& comp
		) {
	return false;
};

bool WdbeMUser::operator!=(
			const WdbeMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMUser
 ******************************************************************************/

ListWdbeMUser::ListWdbeMUser() {
};

ListWdbeMUser::ListWdbeMUser(
			const ListWdbeMUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMUser(*(src.nodes[i]));
};

ListWdbeMUser::~ListWdbeMUser() {
	clear();
};

void ListWdbeMUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMUser::size() const {
	return(nodes.size());
};

void ListWdbeMUser::append(
			WdbeMUser* rec
		) {
	nodes.push_back(rec);
};

WdbeMUser* ListWdbeMUser::operator[](
			const uint ix
		) {
	WdbeMUser* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMUser& ListWdbeMUser::operator=(
			const ListWdbeMUser& src
		) {
	WdbeMUser* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMUser(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMUser::operator==(
			const ListWdbeMUser& comp
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

bool ListWdbeMUser::operator!=(
			const ListWdbeMUser& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMUser
 ******************************************************************************/

TblWdbeMUser::TblWdbeMUser() {
};

TblWdbeMUser::~TblWdbeMUser() {
};

bool TblWdbeMUser::loadRecBySQL(
			const string& sqlstr
			, WdbeMUser** rec
		) {
	return false;
};

ubigint TblWdbeMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMUser& rst
		) {
	return 0;
};

ubigint TblWdbeMUser::insertRec(
			WdbeMUser* rec
		) {
	return 0;
};

ubigint TblWdbeMUser::insertNewRec(
			WdbeMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWdbeMUsergroup
			, const ubigint refWdbeMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWdbeVLocale
			, const uint ixWdbeVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMUser* _rec = NULL;

	_rec = new WdbeMUser(0, grp, own, refRUsergroup, refWdbeMUsergroup, refWdbeMPerson, sref, refJState, ixVState, ixWdbeVLocale, ixWdbeVUserlevel, Password, Fullkey, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMUser::appendNewRecToRst(
			ListWdbeMUser& rst
			, WdbeMUser** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refRUsergroup
			, const ubigint refWdbeMUsergroup
			, const ubigint refWdbeMPerson
			, const string sref
			, const ubigint refJState
			, const uint ixVState
			, const uint ixWdbeVLocale
			, const uint ixWdbeVUserlevel
			, const string Password
			, const string Fullkey
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMUser* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refRUsergroup, refWdbeMUsergroup, refWdbeMPerson, sref, refJState, ixVState, ixWdbeVLocale, ixWdbeVUserlevel, Password, Fullkey, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMUser::insertRst(
			ListWdbeMUser& rst
			, bool transact
		) {
};

void TblWdbeMUser::updateRec(
			WdbeMUser* rec
		) {
};

void TblWdbeMUser::updateRst(
			ListWdbeMUser& rst
			, bool transact
		) {
};

void TblWdbeMUser::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMUser::loadRecByRef(
			ubigint ref
			, WdbeMUser** rec
		) {
	return false;
};

bool TblWdbeMUser::loadRecByPrs(
			ubigint refWdbeMPerson
			, WdbeMUser** rec
		) {
	return false;
};

bool TblWdbeMUser::loadRecBySrf(
			string sref
			, WdbeMUser** rec
		) {
	return false;
};

bool TblWdbeMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WdbeMUser** rec
		) {
	return false;
};

bool TblWdbeMUser::loadRefByPrs(
			ubigint refWdbeMPerson
			, ubigint& ref
		) {
	return false;
};

bool TblWdbeMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWdbeMUser::loadRefsByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

bool TblWdbeMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMUser::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMUser& rst
		) {
	ubigint numload = 0;
	WdbeMUser* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMUser
 ******************************************************************************/

MyTblWdbeMUser::MyTblWdbeMUser() :
			TblWdbeMUser()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMUser::~MyTblWdbeMUser() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMUser::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMUser (grp, own, refRUsergroup, refWdbeMUsergroup, refWdbeMPerson, sref, refJState, ixVState, ixWdbeVLocale, ixWdbeVUserlevel, Password, Fullkey, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMUser SET grp = ?, own = ?, refRUsergroup = ?, refWdbeMUsergroup = ?, refWdbeMPerson = ?, sref = ?, refJState = ?, ixVState = ?, ixWdbeVLocale = ?, ixWdbeVUserlevel = ?, Password = ?, Fullkey = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMUser WHERE ref = ?", false);
};

bool MyTblWdbeMUser::loadRecBySQL(
			const string& sqlstr
			, WdbeMUser** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMUser* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMUser::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMUser::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMUser();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refRUsergroup = atoll((char*) dbrow[3]); else _rec->refRUsergroup = 0;
		if (dbrow[4]) _rec->refWdbeMUsergroup = atoll((char*) dbrow[4]); else _rec->refWdbeMUsergroup = 0;
		if (dbrow[5]) _rec->refWdbeMPerson = atoll((char*) dbrow[5]); else _rec->refWdbeMPerson = 0;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->refJState = atoll((char*) dbrow[7]); else _rec->refJState = 0;
		if (dbrow[8]) _rec->ixVState = atol((char*) dbrow[8]); else _rec->ixVState = 0;
		if (dbrow[9]) _rec->ixWdbeVLocale = atol((char*) dbrow[9]); else _rec->ixWdbeVLocale = 0;
		if (dbrow[10]) _rec->ixWdbeVUserlevel = atol((char*) dbrow[10]); else _rec->ixWdbeVUserlevel = 0;
		if (dbrow[11]) _rec->Password.assign(dbrow[11], dblengths[11]); else _rec->Password = "";
		if (dbrow[12]) _rec->Fullkey.assign(dbrow[12], dblengths[12]); else _rec->Fullkey = "";
		if (dbrow[13]) _rec->Comment.assign(dbrow[13], dblengths[13]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMUser& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMUser* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMUser::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMUser::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMUser();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refRUsergroup = atoll((char*) dbrow[3]); else rec->refRUsergroup = 0;
			if (dbrow[4]) rec->refWdbeMUsergroup = atoll((char*) dbrow[4]); else rec->refWdbeMUsergroup = 0;
			if (dbrow[5]) rec->refWdbeMPerson = atoll((char*) dbrow[5]); else rec->refWdbeMPerson = 0;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->refJState = atoll((char*) dbrow[7]); else rec->refJState = 0;
			if (dbrow[8]) rec->ixVState = atol((char*) dbrow[8]); else rec->ixVState = 0;
			if (dbrow[9]) rec->ixWdbeVLocale = atol((char*) dbrow[9]); else rec->ixWdbeVLocale = 0;
			if (dbrow[10]) rec->ixWdbeVUserlevel = atol((char*) dbrow[10]); else rec->ixWdbeVUserlevel = 0;
			if (dbrow[11]) rec->Password.assign(dbrow[11], dblengths[11]); else rec->Password = "";
			if (dbrow[12]) rec->Fullkey.assign(dbrow[12], dblengths[12]); else rec->Fullkey = "";
			if (dbrow[13]) rec->Comment.assign(dbrow[13], dblengths[13]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMUser::insertRec(
			WdbeMUser* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();
	l[11] = rec->Fullkey.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWdbeMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixWdbeVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWdbeVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Fullkey.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMUser::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMUser::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMUser::insertRst(
			ListWdbeMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMUser::updateRec(
			WdbeMUser* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[5] = rec->sref.length();
	l[10] = rec->Password.length();
	l[11] = rec->Fullkey.length();
	l[12] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refRUsergroup,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refWdbeMUsergroup,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refWdbeMPerson,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refJState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixVState,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixWdbeVLocale,&(l[8]),&(n[8]),&(e[8])),
		bindUint(&rec->ixWdbeVUserlevel,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Password.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Fullkey.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMUser::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMUser::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMUser::updateRst(
			ListWdbeMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMUser::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMUser::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMUser::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMUser::loadRecByRef(
			ubigint ref
			, WdbeMUser** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMUser WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMUser::loadRecByPrs(
			ubigint refWdbeMPerson
			, WdbeMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refWdbeMUsergroup, refWdbeMPerson, sref, refJState, ixVState, ixWdbeVLocale, ixWdbeVUserlevel, Password, Fullkey, Comment FROM TblWdbeMUser WHERE refWdbeMPerson = " + to_string(refWdbeMPerson) + "", rec);
};

bool MyTblWdbeMUser::loadRecBySrf(
			string sref
			, WdbeMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refWdbeMUsergroup, refWdbeMPerson, sref, refJState, ixVState, ixWdbeVLocale, ixWdbeVUserlevel, Password, Fullkey, Comment FROM TblWdbeMUser WHERE sref = '" + sref + "'", rec);
};

bool MyTblWdbeMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WdbeMUser** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, refRUsergroup, refWdbeMUsergroup, refWdbeMPerson, sref, refJState, ixVState, ixWdbeVLocale, ixWdbeVUserlevel, Password, Fullkey, Comment FROM TblWdbeMUser WHERE sref = '" + sref + "' AND Password = '" + Password + "'", rec);
};

bool MyTblWdbeMUser::loadRefByPrs(
			ubigint refWdbeMPerson
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWdbeMUser WHERE refWdbeMPerson = " + to_string(refWdbeMPerson) + "", ref);
};

bool MyTblWdbeMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWdbeMUser WHERE sref = '" + sref + "'", ref);
};

ubigint MyTblWdbeMUser::loadRefsByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMUser WHERE refWdbeMUsergroup = " + to_string(refWdbeMUsergroup) + "", append, refs);
};

bool MyTblWdbeMUser::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMUser WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMUser
 ******************************************************************************/

PgTblWdbeMUser::PgTblWdbeMUser() :
			TblWdbeMUser()
			, PgTable()
		{
};

PgTblWdbeMUser::~PgTblWdbeMUser() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMUser::initStatements() {
	createStatement("TblWdbeMUser_insertRec", "INSERT INTO TblWdbeMUser (grp, own, refRUsergroup, refWdbeMUsergroup, refWdbeMPerson, sref, refJState, ixVState, ixWdbeVLocale, ixWdbeVUserlevel, Password, Fullkey, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13);
	createStatement("TblWdbeMUser_updateRec", "UPDATE TblWdbeMUser SET grp = $1, own = $2, refRUsergroup = $3, refWdbeMUsergroup = $4, refWdbeMPerson = $5, sref = $6, refJState = $7, ixVState = $8, ixWdbeVLocale = $9, ixWdbeVUserlevel = $10, Password = $11, Fullkey = $12, Comment = $13 WHERE ref = $14", 14);
	createStatement("TblWdbeMUser_removeRecByRef", "DELETE FROM TblWdbeMUser WHERE ref = $1", 1);

	createStatement("TblWdbeMUser_loadRecByRef", "SELECT ref, grp, own, refRUsergroup, refWdbeMUsergroup, refWdbeMPerson, sref, refJState, ixVState, ixWdbeVLocale, ixWdbeVUserlevel, Password, Fullkey, Comment FROM TblWdbeMUser WHERE ref = $1", 1);
	createStatement("TblWdbeMUser_loadRecByPrs", "SELECT ref, grp, own, refRUsergroup, refWdbeMUsergroup, refWdbeMPerson, sref, refJState, ixVState, ixWdbeVLocale, ixWdbeVUserlevel, Password, Fullkey, Comment FROM TblWdbeMUser WHERE refWdbeMPerson = $1", 1);
	createStatement("TblWdbeMUser_loadRecBySrf", "SELECT ref, grp, own, refRUsergroup, refWdbeMUsergroup, refWdbeMPerson, sref, refJState, ixVState, ixWdbeVLocale, ixWdbeVUserlevel, Password, Fullkey, Comment FROM TblWdbeMUser WHERE sref = $1", 1);
	createStatement("TblWdbeMUser_loadRecBySrfPwd", "SELECT ref, grp, own, refRUsergroup, refWdbeMUsergroup, refWdbeMPerson, sref, refJState, ixVState, ixWdbeVLocale, ixWdbeVUserlevel, Password, Fullkey, Comment FROM TblWdbeMUser WHERE sref = $1 AND Password = $2", 2);
	createStatement("TblWdbeMUser_loadRefByPrs", "SELECT ref FROM TblWdbeMUser WHERE refWdbeMPerson = $1", 1);
	createStatement("TblWdbeMUser_loadRefBySrf", "SELECT ref FROM TblWdbeMUser WHERE sref = $1", 1);
	createStatement("TblWdbeMUser_loadRefsByUsg", "SELECT ref FROM TblWdbeMUser WHERE refWdbeMUsergroup = $1", 1);
	createStatement("TblWdbeMUser_loadSrfByRef", "SELECT sref FROM TblWdbeMUser WHERE ref = $1", 1);
};

bool PgTblWdbeMUser::loadRec(
			PGresult* res
			, WdbeMUser** rec
		) {
	char* ptr;

	WdbeMUser* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMUser();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "refwdbemusergroup"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwdbevlocale"),
			PQfnumber(res, "ixwdbevuserlevel"),
			PQfnumber(res, "password"),
			PQfnumber(res, "fullkey"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refRUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refWdbeMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refWdbeMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixWdbeVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->ixWdbeVUserlevel = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Password.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Fullkey.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMUser::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMUser& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMUser* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refrusergroup"),
			PQfnumber(res, "refwdbemusergroup"),
			PQfnumber(res, "refwdbemperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixwdbevlocale"),
			PQfnumber(res, "ixwdbevuserlevel"),
			PQfnumber(res, "password"),
			PQfnumber(res, "fullkey"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMUser();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refRUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refWdbeMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refWdbeMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixWdbeVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->ixWdbeVUserlevel = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Password.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Fullkey.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMUser::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMUser** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMUser::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeMUser::loadRecBySQL(
			const string& sqlstr
			, WdbeMUser** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMUser::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMUser::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMUser& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMUser::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMUser::insertRec(
			WdbeMUser* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refWdbeMUsergroup = htonl64(rec->refWdbeMUsergroup);
	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWdbeVLocale = htonl(rec->ixWdbeVLocale);
	uint _ixWdbeVUserlevel = htonl(rec->ixWdbeVUserlevel);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refWdbeMUsergroup,
		(char*) &_refWdbeMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixWdbeVLocale,
		(char*) &_ixWdbeVUserlevel,
		rec->Password.c_str(),
		rec->Fullkey.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMUser_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMUser::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMUser::insertRst(
			ListWdbeMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMUser::updateRec(
			WdbeMUser* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refRUsergroup = htonl64(rec->refRUsergroup);
	ubigint _refWdbeMUsergroup = htonl64(rec->refWdbeMUsergroup);
	ubigint _refWdbeMPerson = htonl64(rec->refWdbeMPerson);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixWdbeVLocale = htonl(rec->ixWdbeVLocale);
	uint _ixWdbeVUserlevel = htonl(rec->ixWdbeVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refRUsergroup,
		(char*) &_refWdbeMUsergroup,
		(char*) &_refWdbeMPerson,
		rec->sref.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		(char*) &_ixWdbeVLocale,
		(char*) &_ixWdbeVUserlevel,
		rec->Password.c_str(),
		rec->Fullkey.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMUser_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMUser::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMUser::updateRst(
			ListWdbeMUser& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMUser::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMUser_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMUser::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMUser::loadRecByRef(
			ubigint ref
			, WdbeMUser** rec
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

	return loadRecByStmt("TblWdbeMUser_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMUser::loadRecByPrs(
			ubigint refWdbeMPerson
			, WdbeMUser** rec
		) {
	ubigint _refWdbeMPerson = htonl64(refWdbeMPerson);

	const char* vals[] = {
		(char*) &_refWdbeMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMUser_loadRecByPrs", 1, vals, l, f, rec);
};

bool PgTblWdbeMUser::loadRecBySrf(
			string sref
			, WdbeMUser** rec
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRecByStmt("TblWdbeMUser_loadRecBySrf", 1, vals, l, f, rec);
};

bool PgTblWdbeMUser::loadRecBySrfPwd(
			string sref
			, string Password
			, WdbeMUser** rec
		) {

	const char* vals[] = {
		sref.c_str(),
		Password.c_str()
	};
	const int l[] = {
		0,
		0
	};
	const int f[] = {0,0};

	return loadRecByStmt("TblWdbeMUser_loadRecBySrfPwd", 2, vals, l, f, rec);
};

bool PgTblWdbeMUser::loadRefByPrs(
			ubigint refWdbeMPerson
			, ubigint& ref
		) {
	ubigint _refWdbeMPerson = htonl64(refWdbeMPerson);

	const char* vals[] = {
		(char*) &_refWdbeMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblWdbeMUser_loadRefByPrs", 1, vals, l, f, ref);
};

bool PgTblWdbeMUser::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRefByStmt("TblWdbeMUser_loadRefBySrf", 1, vals, l, f, ref);
};

ubigint PgTblWdbeMUser::loadRefsByUsg(
			ubigint refWdbeMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeMUsergroup = htonl64(refWdbeMUsergroup);

	const char* vals[] = {
		(char*) &_refWdbeMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMUser_loadRefsByUsg", 1, vals, l, f, append, refs);
};

bool PgTblWdbeMUser::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMUser_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

