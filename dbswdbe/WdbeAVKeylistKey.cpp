/**
	* \file WdbeAVKeylistKey.cpp
	* database access for table TblWdbeAVKeylistKey (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeAVKeylistKey.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAVKeylistKey
 ******************************************************************************/

WdbeAVKeylistKey::WdbeAVKeylistKey(
			const ubigint ref
			, const uint klsIxWdbeVKeylist
			, const uint klsNum
			, const uint x1IxWdbeVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->klsIxWdbeVKeylist = klsIxWdbeVKeylist;
	this->klsNum = klsNum;
	this->x1IxWdbeVMaintable = x1IxWdbeVMaintable;
	this->x1Uref = x1Uref;
	this->Fixed = Fixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

bool WdbeAVKeylistKey::operator==(
			const WdbeAVKeylistKey& comp
		) {
	return false;
};

bool WdbeAVKeylistKey::operator!=(
			const WdbeAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAVKeylistKey
 ******************************************************************************/

ListWdbeAVKeylistKey::ListWdbeAVKeylistKey() {
};

ListWdbeAVKeylistKey::ListWdbeAVKeylistKey(
			const ListWdbeAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAVKeylistKey(*(src.nodes[i]));
};

ListWdbeAVKeylistKey::~ListWdbeAVKeylistKey() {
	clear();
};

void ListWdbeAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAVKeylistKey::size() const {
	return(nodes.size());
};

void ListWdbeAVKeylistKey::append(
			WdbeAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

WdbeAVKeylistKey* ListWdbeAVKeylistKey::operator[](
			const uint ix
		) {
	WdbeAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAVKeylistKey& ListWdbeAVKeylistKey::operator=(
			const ListWdbeAVKeylistKey& src
		) {
	WdbeAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAVKeylistKey::operator==(
			const ListWdbeAVKeylistKey& comp
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

bool ListWdbeAVKeylistKey::operator!=(
			const ListWdbeAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAVKeylistKey
 ******************************************************************************/

TblWdbeAVKeylistKey::TblWdbeAVKeylistKey() {
};

TblWdbeAVKeylistKey::~TblWdbeAVKeylistKey() {
};

bool TblWdbeAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WdbeAVKeylistKey** rec
		) {
	return false;
};

ubigint TblWdbeAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWdbeAVKeylistKey::insertRec(
			WdbeAVKeylistKey* rec
		) {
	return 0;
};

ubigint TblWdbeAVKeylistKey::insertNewRec(
			WdbeAVKeylistKey** rec
			, const uint klsIxWdbeVKeylist
			, const uint klsNum
			, const uint x1IxWdbeVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAVKeylistKey* _rec = NULL;

	_rec = new WdbeAVKeylistKey(0, klsIxWdbeVKeylist, klsNum, x1IxWdbeVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAVKeylistKey::appendNewRecToRst(
			ListWdbeAVKeylistKey& rst
			, WdbeAVKeylistKey** rec
			, const uint klsIxWdbeVKeylist
			, const uint klsNum
			, const uint x1IxWdbeVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, klsIxWdbeVKeylist, klsNum, x1IxWdbeVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAVKeylistKey::insertRst(
			ListWdbeAVKeylistKey& rst
			, bool transact
		) {
};

void TblWdbeAVKeylistKey::updateRec(
			WdbeAVKeylistKey* rec
		) {
};

void TblWdbeAVKeylistKey::updateRst(
			ListWdbeAVKeylistKey& rst
			, bool transact
		) {
};

void TblWdbeAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAVKeylistKey::loadRecByRef(
			ubigint ref
			, WdbeAVKeylistKey** rec
		) {
	return false;
};

bool TblWdbeAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWdbeVKeylist
			, uint x1IxWdbeVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return false;
};

bool TblWdbeAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWdbeVKeylist
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblWdbeAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxWdbeVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAVKeylistKey::loadRstByKls(
			uint klsIxWdbeVKeylist
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblWdbeAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWdbeVKeylist
			, uint x1IxWdbeVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	return 0;
};

bool TblWdbeAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblWdbeAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	ubigint numload = 0;
	WdbeAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAVKeylistKey
 ******************************************************************************/

MyTblWdbeAVKeylistKey::MyTblWdbeAVKeylistKey() :
			TblWdbeAVKeylistKey()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAVKeylistKey::~MyTblWdbeAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAVKeylistKey (klsIxWdbeVKeylist, klsNum, x1IxWdbeVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAVKeylistKey SET klsIxWdbeVKeylist = ?, klsNum = ?, x1IxWdbeVMaintable = ?, x1Uref = ?, Fixed = ?, sref = ?, Avail = ?, Implied = ?, refJ = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAVKeylistKey WHERE ref = ?", false);
};

bool MyTblWdbeAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WdbeAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAVKeylistKey::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAVKeylistKey::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->klsIxWdbeVKeylist = atol((char*) dbrow[1]); else _rec->klsIxWdbeVKeylist = 0;
		if (dbrow[2]) _rec->klsNum = atol((char*) dbrow[2]); else _rec->klsNum = 0;
		if (dbrow[3]) _rec->x1IxWdbeVMaintable = atol((char*) dbrow[3]); else _rec->x1IxWdbeVMaintable = 0;
		if (dbrow[4]) _rec->x1Uref = atoll((char*) dbrow[4]); else _rec->x1Uref = 0;
		if (dbrow[5]) _rec->Fixed = (atoi((char*) dbrow[5]) != 0); else _rec->Fixed = false;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Avail.assign(dbrow[7], dblengths[7]); else _rec->Avail = "";
		if (dbrow[8]) _rec->Implied.assign(dbrow[8], dblengths[8]); else _rec->Implied = "";
		if (dbrow[9]) _rec->refJ = atoll((char*) dbrow[9]); else _rec->refJ = 0;
		if (dbrow[10]) _rec->Title.assign(dbrow[10], dblengths[10]); else _rec->Title = "";
		if (dbrow[11]) _rec->Comment.assign(dbrow[11], dblengths[11]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAVKeylistKey::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAVKeylistKey::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->klsIxWdbeVKeylist = atol((char*) dbrow[1]); else rec->klsIxWdbeVKeylist = 0;
			if (dbrow[2]) rec->klsNum = atol((char*) dbrow[2]); else rec->klsNum = 0;
			if (dbrow[3]) rec->x1IxWdbeVMaintable = atol((char*) dbrow[3]); else rec->x1IxWdbeVMaintable = 0;
			if (dbrow[4]) rec->x1Uref = atoll((char*) dbrow[4]); else rec->x1Uref = 0;
			if (dbrow[5]) rec->Fixed = (atoi((char*) dbrow[5]) != 0); else rec->Fixed = false;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Avail.assign(dbrow[7], dblengths[7]); else rec->Avail = "";
			if (dbrow[8]) rec->Implied.assign(dbrow[8], dblengths[8]); else rec->Implied = "";
			if (dbrow[9]) rec->refJ = atoll((char*) dbrow[9]); else rec->refJ = 0;
			if (dbrow[10]) rec->Title.assign(dbrow[10], dblengths[10]); else rec->Title = "";
			if (dbrow[11]) rec->Comment.assign(dbrow[11], dblengths[11]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAVKeylistKey::insertRec(
			WdbeAVKeylistKey* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxWdbeVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWdbeVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAVKeylistKey::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAVKeylistKey::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAVKeylistKey::insertRst(
			ListWdbeAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAVKeylistKey::updateRec(
			WdbeAVKeylistKey* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxWdbeVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxWdbeVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAVKeylistKey::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAVKeylistKey::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAVKeylistKey::updateRst(
			ListWdbeAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAVKeylistKey::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAVKeylistKey::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAVKeylistKey::loadRecByRef(
			ubigint ref
			, WdbeAVKeylistKey** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWdbeVKeylist
			, uint x1IxWdbeVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWdbeAVKeylistKey WHERE klsIxWdbeVKeylist = " + to_string(klsIxWdbeVKeylist) + " AND x1IxWdbeVMaintable = " + to_string(x1IxWdbeVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " AND sref = '" + sref + "'", ref);
};

bool MyTblWdbeAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWdbeVKeylist
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWdbeAVKeylistKey WHERE klsIxWdbeVKeylist = " + to_string(klsIxWdbeVKeylist) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblWdbeAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxWdbeVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAVKeylistKey WHERE x1IxWdbeVMaintable = " + to_string(x1IxWdbeVMaintable) + " AND x1Uref = " + to_string(x1Uref) + "", append, refs);
};

ubigint MyTblWdbeAVKeylistKey::loadRstByKls(
			uint klsIxWdbeVKeylist
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxWdbeVKeylist, klsNum, x1IxWdbeVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWdbeAVKeylistKey WHERE klsIxWdbeVKeylist = " + to_string(klsIxWdbeVKeylist) + " ORDER BY klsNum ASC", append, rst);
};

ubigint MyTblWdbeAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWdbeVKeylist
			, uint x1IxWdbeVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxWdbeVKeylist, klsNum, x1IxWdbeVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWdbeAVKeylistKey WHERE klsIxWdbeVKeylist = " + to_string(klsIxWdbeVKeylist) + " AND x1IxWdbeVMaintable = " + to_string(x1IxWdbeVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " ORDER BY klsNum ASC", append, rst);
};

bool MyTblWdbeAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblWdbeAVKeylistKey WHERE ref = " + to_string(ref) + "", Title);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAVKeylistKey
 ******************************************************************************/

PgTblWdbeAVKeylistKey::PgTblWdbeAVKeylistKey() :
			TblWdbeAVKeylistKey()
			, PgTable()
		{
};

PgTblWdbeAVKeylistKey::~PgTblWdbeAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAVKeylistKey::initStatements() {
	createStatement("TblWdbeAVKeylistKey_insertRec", "INSERT INTO TblWdbeAVKeylistKey (klsIxWdbeVKeylist, klsNum, x1IxWdbeVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11);
	createStatement("TblWdbeAVKeylistKey_updateRec", "UPDATE TblWdbeAVKeylistKey SET klsIxWdbeVKeylist = $1, klsNum = $2, x1IxWdbeVMaintable = $3, x1Uref = $4, Fixed = $5, sref = $6, Avail = $7, Implied = $8, refJ = $9, Title = $10, Comment = $11 WHERE ref = $12", 12);
	createStatement("TblWdbeAVKeylistKey_removeRecByRef", "DELETE FROM TblWdbeAVKeylistKey WHERE ref = $1", 1);

	createStatement("TblWdbeAVKeylistKey_loadRecByRef", "SELECT ref, klsIxWdbeVKeylist, klsNum, x1IxWdbeVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWdbeAVKeylistKey WHERE ref = $1", 1);
	createStatement("TblWdbeAVKeylistKey_loadRefByKlsMtbUrfSrf", "SELECT ref FROM TblWdbeAVKeylistKey WHERE klsIxWdbeVKeylist = $1 AND x1IxWdbeVMaintable = $2 AND x1Uref = $3 AND sref = $4", 4);
	createStatement("TblWdbeAVKeylistKey_loadRefByKlsSrf", "SELECT ref FROM TblWdbeAVKeylistKey WHERE klsIxWdbeVKeylist = $1 AND sref = $2", 2);
	createStatement("TblWdbeAVKeylistKey_loadRefsByMtbUrf", "SELECT ref FROM TblWdbeAVKeylistKey WHERE x1IxWdbeVMaintable = $1 AND x1Uref = $2", 2);
	createStatement("TblWdbeAVKeylistKey_loadRstByKls", "SELECT ref, klsIxWdbeVKeylist, klsNum, x1IxWdbeVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWdbeAVKeylistKey WHERE klsIxWdbeVKeylist = $1 ORDER BY klsNum ASC", 1);
	createStatement("TblWdbeAVKeylistKey_loadRstByKlsMtbUrf", "SELECT ref, klsIxWdbeVKeylist, klsNum, x1IxWdbeVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblWdbeAVKeylistKey WHERE klsIxWdbeVKeylist = $1 AND x1IxWdbeVMaintable = $2 AND x1Uref = $3 ORDER BY klsNum ASC", 3);
	createStatement("TblWdbeAVKeylistKey_loadTitByRef", "SELECT Title FROM TblWdbeAVKeylistKey WHERE ref = $1", 1);
};

bool PgTblWdbeAVKeylistKey::loadRec(
			PGresult* res
			, WdbeAVKeylistKey** rec
		) {
	char* ptr;

	WdbeAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixwdbevkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixwdbevmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->klsIxWdbeVKeylist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->klsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxWdbeVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1Uref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fixed = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Implied.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixwdbevkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixwdbevmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->klsIxWdbeVKeylist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->klsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxWdbeVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1Uref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fixed = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Implied.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVKeylistKey::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVKeylistKey::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, WdbeAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVKeylistKey::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVKeylistKey::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAVKeylistKey::insertRec(
			WdbeAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	uint _klsIxWdbeVKeylist = htonl(rec->klsIxWdbeVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxWdbeVMaintable = htonl(rec->x1IxWdbeVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_klsIxWdbeVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxWdbeVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeAVKeylistKey_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVKeylistKey::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAVKeylistKey::insertRst(
			ListWdbeAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAVKeylistKey::updateRec(
			WdbeAVKeylistKey* rec
		) {
	PGresult* res;

	uint _klsIxWdbeVKeylist = htonl(rec->klsIxWdbeVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxWdbeVMaintable = htonl(rec->x1IxWdbeVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_klsIxWdbeVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxWdbeVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAVKeylistKey_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAVKeylistKey::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAVKeylistKey::updateRst(
			ListWdbeAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAVKeylistKey::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAVKeylistKey::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAVKeylistKey::loadRecByRef(
			ubigint ref
			, WdbeAVKeylistKey** rec
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

	return loadRecByStmt("TblWdbeAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxWdbeVKeylist
			, uint x1IxWdbeVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	uint _klsIxWdbeVKeylist = htonl(klsIxWdbeVKeylist);
	uint _x1IxWdbeVMaintable = htonl(x1IxWdbeVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxWdbeVKeylist,
		(char*) &_x1IxWdbeVMaintable,
		(char*) &_x1Uref,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,1,0};

	return loadRefByStmt("TblWdbeAVKeylistKey_loadRefByKlsMtbUrfSrf", 4, vals, l, f, ref);
};

bool PgTblWdbeAVKeylistKey::loadRefByKlsSrf(
			uint klsIxWdbeVKeylist
			, string sref
			, ubigint& ref
		) {
	uint _klsIxWdbeVKeylist = htonl(klsIxWdbeVKeylist);

	const char* vals[] = {
		(char*) &_klsIxWdbeVKeylist,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		0
	};
	const int f[] = {1,0};

	return loadRefByStmt("TblWdbeAVKeylistKey_loadRefByKlsSrf", 2, vals, l, f, ref);
};

ubigint PgTblWdbeAVKeylistKey::loadRefsByMtbUrf(
			uint x1IxWdbeVMaintable
			, ubigint x1Uref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _x1IxWdbeVMaintable = htonl(x1IxWdbeVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_x1IxWdbeVMaintable,
		(char*) &_x1Uref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblWdbeAVKeylistKey_loadRefsByMtbUrf", 2, vals, l, f, append, refs);
};

ubigint PgTblWdbeAVKeylistKey::loadRstByKls(
			uint klsIxWdbeVKeylist
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	uint _klsIxWdbeVKeylist = htonl(klsIxWdbeVKeylist);

	const char* vals[] = {
		(char*) &_klsIxWdbeVKeylist
	};
	const int l[] = {
		sizeof(uint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAVKeylistKey_loadRstByKls", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxWdbeVKeylist
			, uint x1IxWdbeVMaintable
			, ubigint x1Uref
			, const bool append
			, ListWdbeAVKeylistKey& rst
		) {
	uint _klsIxWdbeVKeylist = htonl(klsIxWdbeVKeylist);
	uint _x1IxWdbeVMaintable = htonl(x1IxWdbeVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxWdbeVKeylist,
		(char*) &_x1IxWdbeVMaintable,
		(char*) &_x1Uref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRstByStmt("TblWdbeAVKeylistKey_loadRstByKlsMtbUrf", 3, vals, l, f, append, rst);
};

bool PgTblWdbeAVKeylistKey::loadTitByRef(
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

	return loadStringByStmt("TblWdbeAVKeylistKey_loadTitByRef", 1, vals, l, f, Title);
};

#endif

