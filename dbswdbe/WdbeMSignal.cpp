/**
	* \file WdbeMSignal.cpp
	* database access for table TblWdbeMSignal (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMSignal.h"

#include "WdbeMSignal_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMSignal
 ******************************************************************************/

WdbeMSignal::WdbeMSignal(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refWdbeCSignal
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const uint mgeIxVTbl
			, const ubigint mgeUref
			, const ubigint refWdbeMVector
			, const string sref
			, const bool Const
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Comb
			, const string Onval
			, const string Offval
			, const bool Defon
			, const ubigint drvRefWdbeMPort
			, const string Comment
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refWdbeCSignal = refWdbeCSignal;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->refNum = refNum;
	this->mgeIxVTbl = mgeIxVTbl;
	this->mgeUref = mgeUref;
	this->refWdbeMVector = refWdbeMVector;
	this->sref = sref;
	this->Const = Const;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Comb = Comb;
	this->Onval = Onval;
	this->Offval = Offval;
	this->Defon = Defon;
	this->drvRefWdbeMPort = drvRefWdbeMPort;
	this->Comment = Comment;
};

bool WdbeMSignal::operator==(
			const WdbeMSignal& comp
		) {
	return false;
};

bool WdbeMSignal::operator!=(
			const WdbeMSignal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMSignal
 ******************************************************************************/

ListWdbeMSignal::ListWdbeMSignal() {
};

ListWdbeMSignal::ListWdbeMSignal(
			const ListWdbeMSignal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMSignal(*(src.nodes[i]));
};

ListWdbeMSignal::~ListWdbeMSignal() {
	clear();
};

void ListWdbeMSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMSignal::size() const {
	return(nodes.size());
};

void ListWdbeMSignal::append(
			WdbeMSignal* rec
		) {
	nodes.push_back(rec);
};

WdbeMSignal* ListWdbeMSignal::operator[](
			const uint ix
		) {
	WdbeMSignal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMSignal& ListWdbeMSignal::operator=(
			const ListWdbeMSignal& src
		) {
	WdbeMSignal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMSignal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMSignal::operator==(
			const ListWdbeMSignal& comp
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

bool ListWdbeMSignal::operator!=(
			const ListWdbeMSignal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMSignal
 ******************************************************************************/

TblWdbeMSignal::TblWdbeMSignal() {
};

TblWdbeMSignal::~TblWdbeMSignal() {
};

bool TblWdbeMSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeMSignal** rec
		) {
	return false;
};

ubigint TblWdbeMSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSignal& rst
		) {
	return 0;
};

ubigint TblWdbeMSignal::insertRec(
			WdbeMSignal* rec
		) {
	return 0;
};

ubigint TblWdbeMSignal::insertNewRec(
			WdbeMSignal** rec
			, const uint ixVBasetype
			, const ubigint refWdbeCSignal
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const uint mgeIxVTbl
			, const ubigint mgeUref
			, const ubigint refWdbeMVector
			, const string sref
			, const bool Const
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Comb
			, const string Onval
			, const string Offval
			, const bool Defon
			, const ubigint drvRefWdbeMPort
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMSignal* _rec = NULL;

	_rec = new WdbeMSignal(0, ixVBasetype, refWdbeCSignal, refIxVTbl, refUref, refNum, mgeIxVTbl, mgeUref, refWdbeMVector, sref, Const, srefWdbeKHdltype, Width, Minmax, Comb, Onval, Offval, Defon, drvRefWdbeMPort, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMSignal::appendNewRecToRst(
			ListWdbeMSignal& rst
			, WdbeMSignal** rec
			, const uint ixVBasetype
			, const ubigint refWdbeCSignal
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const uint mgeIxVTbl
			, const ubigint mgeUref
			, const ubigint refWdbeMVector
			, const string sref
			, const bool Const
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Comb
			, const string Onval
			, const string Offval
			, const bool Defon
			, const ubigint drvRefWdbeMPort
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMSignal* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refWdbeCSignal, refIxVTbl, refUref, refNum, mgeIxVTbl, mgeUref, refWdbeMVector, sref, Const, srefWdbeKHdltype, Width, Minmax, Comb, Onval, Offval, Defon, drvRefWdbeMPort, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMSignal::insertRst(
			ListWdbeMSignal& rst
			, bool transact
		) {
};

void TblWdbeMSignal::updateRec(
			WdbeMSignal* rec
		) {
};

void TblWdbeMSignal::updateRst(
			ListWdbeMSignal& rst
			, bool transact
		) {
};

void TblWdbeMSignal::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMSignal::loadRecByRef(
			ubigint ref
			, WdbeMSignal** rec
		) {
	return false;
};

bool TblWdbeMSignal::loadRecByVec(
			ubigint refWdbeMVector
			, WdbeMSignal** rec
		) {
	return false;
};

ubigint TblWdbeMSignal::loadRefsByClu(
			ubigint refWdbeCSignal
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMSignal::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMSignal::loadRstByClu(
			ubigint refWdbeCSignal
			, const bool append
			, ListWdbeMSignal& rst
		) {
	return 0;
};

ubigint TblWdbeMSignal::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMSignal& rst
		) {
	return 0;
};

bool TblWdbeMSignal::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMSignal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMSignal& rst
		) {
	ubigint numload = 0;
	WdbeMSignal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMSignal
 ******************************************************************************/

MyTblWdbeMSignal::MyTblWdbeMSignal() :
			TblWdbeMSignal()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMSignal::~MyTblWdbeMSignal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMSignal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMSignal (ixVBasetype, refWdbeCSignal, refIxVTbl, refUref, refNum, mgeIxVTbl, mgeUref, refWdbeMVector, sref, Const, srefWdbeKHdltype, Width, Minmax, Comb, Onval, Offval, Defon, drvRefWdbeMPort, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMSignal SET ixVBasetype = ?, refWdbeCSignal = ?, refIxVTbl = ?, refUref = ?, refNum = ?, mgeIxVTbl = ?, mgeUref = ?, refWdbeMVector = ?, sref = ?, Const = ?, srefWdbeKHdltype = ?, Width = ?, Minmax = ?, Comb = ?, Onval = ?, Offval = ?, Defon = ?, drvRefWdbeMPort = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMSignal WHERE ref = ?", false);
};

bool MyTblWdbeMSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeMSignal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMSignal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMSignal::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMSignal::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMSignal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refWdbeCSignal = atoll((char*) dbrow[2]); else _rec->refWdbeCSignal = 0;
		if (dbrow[3]) _rec->refIxVTbl = atol((char*) dbrow[3]); else _rec->refIxVTbl = 0;
		if (dbrow[4]) _rec->refUref = atoll((char*) dbrow[4]); else _rec->refUref = 0;
		if (dbrow[5]) _rec->refNum = atol((char*) dbrow[5]); else _rec->refNum = 0;
		if (dbrow[6]) _rec->mgeIxVTbl = atol((char*) dbrow[6]); else _rec->mgeIxVTbl = 0;
		if (dbrow[7]) _rec->mgeUref = atoll((char*) dbrow[7]); else _rec->mgeUref = 0;
		if (dbrow[8]) _rec->refWdbeMVector = atoll((char*) dbrow[8]); else _rec->refWdbeMVector = 0;
		if (dbrow[9]) _rec->sref.assign(dbrow[9], dblengths[9]); else _rec->sref = "";
		if (dbrow[10]) _rec->Const = (atoi((char*) dbrow[10]) != 0); else _rec->Const = false;
		if (dbrow[11]) _rec->srefWdbeKHdltype.assign(dbrow[11], dblengths[11]); else _rec->srefWdbeKHdltype = "";
		if (dbrow[12]) _rec->Width = atoi((char*) dbrow[12]); else _rec->Width = 0;
		if (dbrow[13]) _rec->Minmax.assign(dbrow[13], dblengths[13]); else _rec->Minmax = "";
		if (dbrow[14]) _rec->Comb.assign(dbrow[14], dblengths[14]); else _rec->Comb = "";
		if (dbrow[15]) _rec->Onval.assign(dbrow[15], dblengths[15]); else _rec->Onval = "";
		if (dbrow[16]) _rec->Offval.assign(dbrow[16], dblengths[16]); else _rec->Offval = "";
		if (dbrow[17]) _rec->Defon = (atoi((char*) dbrow[17]) != 0); else _rec->Defon = false;
		if (dbrow[18]) _rec->drvRefWdbeMPort = atoll((char*) dbrow[18]); else _rec->drvRefWdbeMPort = 0;
		if (dbrow[19]) _rec->Comment.assign(dbrow[19], dblengths[19]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSignal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMSignal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMSignal::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMSignal::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMSignal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refWdbeCSignal = atoll((char*) dbrow[2]); else rec->refWdbeCSignal = 0;
			if (dbrow[3]) rec->refIxVTbl = atol((char*) dbrow[3]); else rec->refIxVTbl = 0;
			if (dbrow[4]) rec->refUref = atoll((char*) dbrow[4]); else rec->refUref = 0;
			if (dbrow[5]) rec->refNum = atol((char*) dbrow[5]); else rec->refNum = 0;
			if (dbrow[6]) rec->mgeIxVTbl = atol((char*) dbrow[6]); else rec->mgeIxVTbl = 0;
			if (dbrow[7]) rec->mgeUref = atoll((char*) dbrow[7]); else rec->mgeUref = 0;
			if (dbrow[8]) rec->refWdbeMVector = atoll((char*) dbrow[8]); else rec->refWdbeMVector = 0;
			if (dbrow[9]) rec->sref.assign(dbrow[9], dblengths[9]); else rec->sref = "";
			if (dbrow[10]) rec->Const = (atoi((char*) dbrow[10]) != 0); else rec->Const = false;
			if (dbrow[11]) rec->srefWdbeKHdltype.assign(dbrow[11], dblengths[11]); else rec->srefWdbeKHdltype = "";
			if (dbrow[12]) rec->Width = atoi((char*) dbrow[12]); else rec->Width = 0;
			if (dbrow[13]) rec->Minmax.assign(dbrow[13], dblengths[13]); else rec->Minmax = "";
			if (dbrow[14]) rec->Comb.assign(dbrow[14], dblengths[14]); else rec->Comb = "";
			if (dbrow[15]) rec->Onval.assign(dbrow[15], dblengths[15]); else rec->Onval = "";
			if (dbrow[16]) rec->Offval.assign(dbrow[16], dblengths[16]); else rec->Offval = "";
			if (dbrow[17]) rec->Defon = (atoi((char*) dbrow[17]) != 0); else rec->Defon = false;
			if (dbrow[18]) rec->drvRefWdbeMPort = atoll((char*) dbrow[18]); else rec->drvRefWdbeMPort = 0;
			if (dbrow[19]) rec->Comment.assign(dbrow[19], dblengths[19]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMSignal::insertRec(
			WdbeMSignal* rec
		) {
	unsigned long l[19]; my_bool n[19]; my_bool e[19];

	l[8] = rec->sref.length();
	tinyint Const = rec->Const;
	l[10] = rec->srefWdbeKHdltype.length();
	l[12] = rec->Minmax.length();
	l[13] = rec->Comb.length();
	l[14] = rec->Onval.length();
	l[15] = rec->Offval.length();
	tinyint Defon = rec->Defon;
	l[18] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeCSignal,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->refNum,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->mgeIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->mgeUref,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWdbeMVector,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->sref.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Const,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUsmallint(&rec->Width,&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->Comb.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->Onval.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->Offval.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindTinyint(&Defon,&(l[16]),&(n[16]),&(e[16])),
		bindUbigint(&rec->drvRefWdbeMPort,&(l[17]),&(n[17]),&(e[17])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[18]),&(n[18]),&(e[18]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMSignal::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMSignal::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMSignal::insertRst(
			ListWdbeMSignal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMSignal::updateRec(
			WdbeMSignal* rec
		) {
	unsigned long l[20]; my_bool n[20]; my_bool e[20];

	l[8] = rec->sref.length();
	tinyint Const = rec->Const;
	l[10] = rec->srefWdbeKHdltype.length();
	l[12] = rec->Minmax.length();
	l[13] = rec->Comb.length();
	l[14] = rec->Onval.length();
	l[15] = rec->Offval.length();
	tinyint Defon = rec->Defon;
	l[18] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refWdbeCSignal,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refIxVTbl,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refUref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->refNum,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->mgeIxVTbl,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->mgeUref,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refWdbeMVector,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->sref.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Const,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUsmallint(&rec->Width,&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->Comb.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->Onval.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->Offval.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindTinyint(&Defon,&(l[16]),&(n[16]),&(e[16])),
		bindUbigint(&rec->drvRefWdbeMPort,&(l[17]),&(n[17]),&(e[17])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[18]),&(n[18]),&(e[18])),
		bindUbigint(&rec->ref,&(l[19]),&(n[19]),&(e[19]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMSignal::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMSignal::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMSignal::updateRst(
			ListWdbeMSignal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMSignal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMSignal::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMSignal::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMSignal::loadRecByRef(
			ubigint ref
			, WdbeMSignal** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMSignal WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMSignal::loadRecByVec(
			ubigint refWdbeMVector
			, WdbeMSignal** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refWdbeCSignal, refIxVTbl, refUref, refNum, mgeIxVTbl, mgeUref, refWdbeMVector, sref, Const, srefWdbeKHdltype, Width, Minmax, Comb, Onval, Offval, Defon, drvRefWdbeMPort, Comment FROM TblWdbeMSignal WHERE refWdbeMVector = " + to_string(refWdbeMVector) + "", rec);
};

ubigint MyTblWdbeMSignal::loadRefsByClu(
			ubigint refWdbeCSignal
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMSignal WHERE refWdbeCSignal = " + to_string(refWdbeCSignal) + "", append, refs);
};

ubigint MyTblWdbeMSignal::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", append, refs);
};

ubigint MyTblWdbeMSignal::loadRstByClu(
			ubigint refWdbeCSignal
			, const bool append
			, ListWdbeMSignal& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWdbeCSignal, refIxVTbl, refUref, refNum, mgeIxVTbl, mgeUref, refWdbeMVector, sref, Const, srefWdbeKHdltype, Width, Minmax, Comb, Onval, Offval, Defon, drvRefWdbeMPort, Comment FROM TblWdbeMSignal WHERE refWdbeCSignal = " + to_string(refWdbeCSignal) + "", append, rst);
};

ubigint MyTblWdbeMSignal::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMSignal& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refWdbeCSignal, refIxVTbl, refUref, refNum, mgeIxVTbl, mgeUref, refWdbeMVector, sref, Const, srefWdbeKHdltype, Width, Minmax, Comb, Onval, Offval, Defon, drvRefWdbeMPort, Comment FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " ORDER BY Const DESC, refNum ASC", append, rst);
};

bool MyTblWdbeMSignal::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMSignal WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMSignal
 ******************************************************************************/

PgTblWdbeMSignal::PgTblWdbeMSignal() :
			TblWdbeMSignal()
			, PgTable()
		{
};

PgTblWdbeMSignal::~PgTblWdbeMSignal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMSignal::initStatements() {
	createStatement("TblWdbeMSignal_insertRec", "INSERT INTO TblWdbeMSignal (ixVBasetype, refWdbeCSignal, refIxVTbl, refUref, refNum, mgeIxVTbl, mgeUref, refWdbeMVector, sref, Const, srefWdbeKHdltype, Width, Minmax, Comb, Onval, Offval, Defon, drvRefWdbeMPort, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17,$18,$19) RETURNING ref", 19);
	createStatement("TblWdbeMSignal_updateRec", "UPDATE TblWdbeMSignal SET ixVBasetype = $1, refWdbeCSignal = $2, refIxVTbl = $3, refUref = $4, refNum = $5, mgeIxVTbl = $6, mgeUref = $7, refWdbeMVector = $8, sref = $9, Const = $10, srefWdbeKHdltype = $11, Width = $12, Minmax = $13, Comb = $14, Onval = $15, Offval = $16, Defon = $17, drvRefWdbeMPort = $18, Comment = $19 WHERE ref = $20", 20);
	createStatement("TblWdbeMSignal_removeRecByRef", "DELETE FROM TblWdbeMSignal WHERE ref = $1", 1);

	createStatement("TblWdbeMSignal_loadRecByRef", "SELECT ref, ixVBasetype, refWdbeCSignal, refIxVTbl, refUref, refNum, mgeIxVTbl, mgeUref, refWdbeMVector, sref, Const, srefWdbeKHdltype, Width, Minmax, Comb, Onval, Offval, Defon, drvRefWdbeMPort, Comment FROM TblWdbeMSignal WHERE ref = $1", 1);
	createStatement("TblWdbeMSignal_loadRecByVec", "SELECT ref, ixVBasetype, refWdbeCSignal, refIxVTbl, refUref, refNum, mgeIxVTbl, mgeUref, refWdbeMVector, sref, Const, srefWdbeKHdltype, Width, Minmax, Comb, Onval, Offval, Defon, drvRefWdbeMPort, Comment FROM TblWdbeMSignal WHERE refWdbeMVector = $1", 1);
	createStatement("TblWdbeMSignal_loadRefsByClu", "SELECT ref FROM TblWdbeMSignal WHERE refWdbeCSignal = $1", 1);
	createStatement("TblWdbeMSignal_loadRefsByRetReu", "SELECT ref FROM TblWdbeMSignal WHERE refIxVTbl = $1 AND refUref = $2", 2);
	createStatement("TblWdbeMSignal_loadRstByClu", "SELECT ref, ixVBasetype, refWdbeCSignal, refIxVTbl, refUref, refNum, mgeIxVTbl, mgeUref, refWdbeMVector, sref, Const, srefWdbeKHdltype, Width, Minmax, Comb, Onval, Offval, Defon, drvRefWdbeMPort, Comment FROM TblWdbeMSignal WHERE refWdbeCSignal = $1", 1);
	createStatement("TblWdbeMSignal_loadRstByRetReu", "SELECT ref, ixVBasetype, refWdbeCSignal, refIxVTbl, refUref, refNum, mgeIxVTbl, mgeUref, refWdbeMVector, sref, Const, srefWdbeKHdltype, Width, Minmax, Comb, Onval, Offval, Defon, drvRefWdbeMPort, Comment FROM TblWdbeMSignal WHERE refIxVTbl = $1 AND refUref = $2 ORDER BY Const DESC, refNum ASC", 2);
	createStatement("TblWdbeMSignal_loadSrfByRef", "SELECT sref FROM TblWdbeMSignal WHERE ref = $1", 1);
};

bool PgTblWdbeMSignal::loadRec(
			PGresult* res
			, WdbeMSignal** rec
		) {
	char* ptr;

	WdbeMSignal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMSignal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwdbecsignal"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refnum"),
			PQfnumber(res, "mgeixvtbl"),
			PQfnumber(res, "mgeuref"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "const"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax"),
			PQfnumber(res, "comb"),
			PQfnumber(res, "onval"),
			PQfnumber(res, "offval"),
			PQfnumber(res, "defon"),
			PQfnumber(res, "drvrefwdbemport"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refWdbeCSignal = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->mgeIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->mgeUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refWdbeMVector = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Const = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Width = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Minmax.assign(ptr, PQgetlength(res, 0, fnum[13]));
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->Comb.assign(ptr, PQgetlength(res, 0, fnum[14]));
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->Onval.assign(ptr, PQgetlength(res, 0, fnum[15]));
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->Offval.assign(ptr, PQgetlength(res, 0, fnum[16]));
		ptr = PQgetvalue(res, 0, fnum[17]); _rec->Defon = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[18]); _rec->drvRefWdbeMPort = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[19]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[19]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMSignal::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMSignal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMSignal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refwdbecsignal"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refnum"),
			PQfnumber(res, "mgeixvtbl"),
			PQfnumber(res, "mgeuref"),
			PQfnumber(res, "refwdbemvector"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "const"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax"),
			PQfnumber(res, "comb"),
			PQfnumber(res, "onval"),
			PQfnumber(res, "offval"),
			PQfnumber(res, "defon"),
			PQfnumber(res, "drvrefwdbemport"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMSignal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refWdbeCSignal = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->mgeIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->mgeUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refWdbeMVector = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Const = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Width = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Minmax.assign(ptr, PQgetlength(res, numread, fnum[13]));
			ptr = PQgetvalue(res, numread, fnum[14]); rec->Comb.assign(ptr, PQgetlength(res, numread, fnum[14]));
			ptr = PQgetvalue(res, numread, fnum[15]); rec->Onval.assign(ptr, PQgetlength(res, numread, fnum[15]));
			ptr = PQgetvalue(res, numread, fnum[16]); rec->Offval.assign(ptr, PQgetlength(res, numread, fnum[16]));
			ptr = PQgetvalue(res, numread, fnum[17]); rec->Defon = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[18]); rec->drvRefWdbeMPort = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[19]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[19]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMSignal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMSignal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSignal::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMSignal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMSignal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSignal::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMSignal::loadRecBySQL(
			const string& sqlstr
			, WdbeMSignal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSignal::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMSignal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMSignal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSignal::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMSignal::insertRec(
			WdbeMSignal* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWdbeCSignal = htonl64(rec->refWdbeCSignal);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _refNum = htonl(rec->refNum);
	uint _mgeIxVTbl = htonl(rec->mgeIxVTbl);
	ubigint _mgeUref = htonl64(rec->mgeUref);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	smallint _Const = htons((smallint) rec->Const);
	usmallint _Width = htons(rec->Width);
	smallint _Defon = htons((smallint) rec->Defon);
	ubigint _drvRefWdbeMPort = htonl64(rec->drvRefWdbeMPort);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWdbeCSignal,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refNum,
		(char*) &_mgeIxVTbl,
		(char*) &_mgeUref,
		(char*) &_refWdbeMVector,
		rec->sref.c_str(),
		(char*) &_Const,
		rec->srefWdbeKHdltype.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str(),
		rec->Comb.c_str(),
		rec->Onval.c_str(),
		rec->Offval.c_str(),
		(char*) &_Defon,
		(char*) &_drvRefWdbeMPort,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		0,
		sizeof(usmallint),
		0,
		0,
		0,
		0,
		sizeof(smallint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeMSignal_insertRec", 19, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMSignal::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMSignal::insertRst(
			ListWdbeMSignal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMSignal::updateRec(
			WdbeMSignal* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refWdbeCSignal = htonl64(rec->refWdbeCSignal);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _refNum = htonl(rec->refNum);
	uint _mgeIxVTbl = htonl(rec->mgeIxVTbl);
	ubigint _mgeUref = htonl64(rec->mgeUref);
	ubigint _refWdbeMVector = htonl64(rec->refWdbeMVector);
	smallint _Const = htons((smallint) rec->Const);
	usmallint _Width = htons(rec->Width);
	smallint _Defon = htons((smallint) rec->Defon);
	ubigint _drvRefWdbeMPort = htonl64(rec->drvRefWdbeMPort);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refWdbeCSignal,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refNum,
		(char*) &_mgeIxVTbl,
		(char*) &_mgeUref,
		(char*) &_refWdbeMVector,
		rec->sref.c_str(),
		(char*) &_Const,
		rec->srefWdbeKHdltype.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str(),
		rec->Comb.c_str(),
		rec->Onval.c_str(),
		rec->Offval.c_str(),
		(char*) &_Defon,
		(char*) &_drvRefWdbeMPort,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		0,
		sizeof(usmallint),
		0,
		0,
		0,
		0,
		sizeof(smallint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMSignal_updateRec", 20, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMSignal::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMSignal::updateRst(
			ListWdbeMSignal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMSignal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMSignal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMSignal::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMSignal::loadRecByRef(
			ubigint ref
			, WdbeMSignal** rec
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

	return loadRecByStmt("TblWdbeMSignal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMSignal::loadRecByVec(
			ubigint refWdbeMVector
			, WdbeMSignal** rec
		) {
	ubigint _refWdbeMVector = htonl64(refWdbeMVector);

	const char* vals[] = {
		(char*) &_refWdbeMVector
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMSignal_loadRecByVec", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMSignal::loadRefsByClu(
			ubigint refWdbeCSignal
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeCSignal = htonl64(refWdbeCSignal);

	const char* vals[] = {
		(char*) &_refWdbeCSignal
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMSignal_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMSignal::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
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

	return loadRefsByStmt("TblWdbeMSignal_loadRefsByRetReu", 2, vals, l, f, append, refs);
};

ubigint PgTblWdbeMSignal::loadRstByClu(
			ubigint refWdbeCSignal
			, const bool append
			, ListWdbeMSignal& rst
		) {
	ubigint _refWdbeCSignal = htonl64(refWdbeCSignal);

	const char* vals[] = {
		(char*) &_refWdbeCSignal
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMSignal_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeMSignal::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMSignal& rst
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

	return loadRstByStmt("TblWdbeMSignal_loadRstByRetReu", 2, vals, l, f, append, rst);
};

bool PgTblWdbeMSignal::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMSignal_loadSrfByRef", 1, vals, l, f, sref);
};

#endif
