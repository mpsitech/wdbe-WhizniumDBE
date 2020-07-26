/**
	* \file WdbeMPort.cpp
	* database access for table TblWdbeMPort (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeMPort.h"

#include "WdbeMPort_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMPort
 ******************************************************************************/

WdbeMPort::WdbeMPort(
			const ubigint ref
			, const ubigint refWdbeCPort
			, const ubigint mdlRefWdbeMModule
			, const uint mdlNum
			, const uint mdlIxVCat
			, const string sref
			, const uint ixVDir
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Defval
			, const string cpiSrefWdbeMPin
			, const string cprSrefWdbeMPort
			, const string csiSrefWdbeMSignal
			, const string Comment
		) {

	this->ref = ref;
	this->refWdbeCPort = refWdbeCPort;
	this->mdlRefWdbeMModule = mdlRefWdbeMModule;
	this->mdlNum = mdlNum;
	this->mdlIxVCat = mdlIxVCat;
	this->sref = sref;
	this->ixVDir = ixVDir;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Defval = Defval;
	this->cpiSrefWdbeMPin = cpiSrefWdbeMPin;
	this->cprSrefWdbeMPort = cprSrefWdbeMPort;
	this->csiSrefWdbeMSignal = csiSrefWdbeMSignal;
	this->Comment = Comment;
};

bool WdbeMPort::operator==(
			const WdbeMPort& comp
		) {
	return false;
};

bool WdbeMPort::operator!=(
			const WdbeMPort& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMPort
 ******************************************************************************/

ListWdbeMPort::ListWdbeMPort() {
};

ListWdbeMPort::ListWdbeMPort(
			const ListWdbeMPort& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMPort(*(src.nodes[i]));
};

ListWdbeMPort::~ListWdbeMPort() {
	clear();
};

void ListWdbeMPort::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMPort::size() const {
	return(nodes.size());
};

void ListWdbeMPort::append(
			WdbeMPort* rec
		) {
	nodes.push_back(rec);
};

WdbeMPort* ListWdbeMPort::operator[](
			const uint ix
		) {
	WdbeMPort* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMPort& ListWdbeMPort::operator=(
			const ListWdbeMPort& src
		) {
	WdbeMPort* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMPort(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMPort::operator==(
			const ListWdbeMPort& comp
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

bool ListWdbeMPort::operator!=(
			const ListWdbeMPort& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMPort
 ******************************************************************************/

TblWdbeMPort::TblWdbeMPort() {
};

TblWdbeMPort::~TblWdbeMPort() {
};

bool TblWdbeMPort::loadRecBySQL(
			const string& sqlstr
			, WdbeMPort** rec
		) {
	return false;
};

ubigint TblWdbeMPort::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPort& rst
		) {
	return 0;
};

ubigint TblWdbeMPort::insertRec(
			WdbeMPort* rec
		) {
	return 0;
};

ubigint TblWdbeMPort::insertNewRec(
			WdbeMPort** rec
			, const ubigint refWdbeCPort
			, const ubigint mdlRefWdbeMModule
			, const uint mdlNum
			, const uint mdlIxVCat
			, const string sref
			, const uint ixVDir
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Defval
			, const string cpiSrefWdbeMPin
			, const string cprSrefWdbeMPort
			, const string csiSrefWdbeMSignal
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMPort* _rec = NULL;

	_rec = new WdbeMPort(0, refWdbeCPort, mdlRefWdbeMModule, mdlNum, mdlIxVCat, sref, ixVDir, srefWdbeKHdltype, Width, Minmax, Defval, cpiSrefWdbeMPin, cprSrefWdbeMPort, csiSrefWdbeMSignal, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMPort::appendNewRecToRst(
			ListWdbeMPort& rst
			, WdbeMPort** rec
			, const ubigint refWdbeCPort
			, const ubigint mdlRefWdbeMModule
			, const uint mdlNum
			, const uint mdlIxVCat
			, const string sref
			, const uint ixVDir
			, const string srefWdbeKHdltype
			, const usmallint Width
			, const string Minmax
			, const string Defval
			, const string cpiSrefWdbeMPin
			, const string cprSrefWdbeMPort
			, const string csiSrefWdbeMSignal
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMPort* _rec = NULL;

	retval = insertNewRec(&_rec, refWdbeCPort, mdlRefWdbeMModule, mdlNum, mdlIxVCat, sref, ixVDir, srefWdbeKHdltype, Width, Minmax, Defval, cpiSrefWdbeMPin, cprSrefWdbeMPort, csiSrefWdbeMSignal, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMPort::insertRst(
			ListWdbeMPort& rst
			, bool transact
		) {
};

void TblWdbeMPort::updateRec(
			WdbeMPort* rec
		) {
};

void TblWdbeMPort::updateRst(
			ListWdbeMPort& rst
			, bool transact
		) {
};

void TblWdbeMPort::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMPort::loadRecByRef(
			ubigint ref
			, WdbeMPort** rec
		) {
	return false;
};

ubigint TblWdbeMPort::loadRefsByClu(
			ubigint refWdbeCPort
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMPort::loadRefsByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMPort::loadRstByClu(
			ubigint refWdbeCPort
			, const bool append
			, ListWdbeMPort& rst
		) {
	return 0;
};

ubigint TblWdbeMPort::loadRstByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, ListWdbeMPort& rst
		) {
	return 0;
};

bool TblWdbeMPort::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblWdbeMPort::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMPort& rst
		) {
	ubigint numload = 0;
	WdbeMPort* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMPort
 ******************************************************************************/

MyTblWdbeMPort::MyTblWdbeMPort() :
			TblWdbeMPort()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMPort::~MyTblWdbeMPort() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMPort::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMPort (refWdbeCPort, mdlRefWdbeMModule, mdlNum, mdlIxVCat, sref, ixVDir, srefWdbeKHdltype, Width, Minmax, Defval, cpiSrefWdbeMPin, cprSrefWdbeMPort, csiSrefWdbeMSignal, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMPort SET refWdbeCPort = ?, mdlRefWdbeMModule = ?, mdlNum = ?, mdlIxVCat = ?, sref = ?, ixVDir = ?, srefWdbeKHdltype = ?, Width = ?, Minmax = ?, Defval = ?, cpiSrefWdbeMPin = ?, cprSrefWdbeMPort = ?, csiSrefWdbeMSignal = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMPort WHERE ref = ?", false);
};

bool MyTblWdbeMPort::loadRecBySQL(
			const string& sqlstr
			, WdbeMPort** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMPort* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMPort::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMPort::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMPort();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refWdbeCPort = atoll((char*) dbrow[1]); else _rec->refWdbeCPort = 0;
		if (dbrow[2]) _rec->mdlRefWdbeMModule = atoll((char*) dbrow[2]); else _rec->mdlRefWdbeMModule = 0;
		if (dbrow[3]) _rec->mdlNum = atol((char*) dbrow[3]); else _rec->mdlNum = 0;
		if (dbrow[4]) _rec->mdlIxVCat = atol((char*) dbrow[4]); else _rec->mdlIxVCat = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->ixVDir = atol((char*) dbrow[6]); else _rec->ixVDir = 0;
		if (dbrow[7]) _rec->srefWdbeKHdltype.assign(dbrow[7], dblengths[7]); else _rec->srefWdbeKHdltype = "";
		if (dbrow[8]) _rec->Width = atoi((char*) dbrow[8]); else _rec->Width = 0;
		if (dbrow[9]) _rec->Minmax.assign(dbrow[9], dblengths[9]); else _rec->Minmax = "";
		if (dbrow[10]) _rec->Defval.assign(dbrow[10], dblengths[10]); else _rec->Defval = "";
		if (dbrow[11]) _rec->cpiSrefWdbeMPin.assign(dbrow[11], dblengths[11]); else _rec->cpiSrefWdbeMPin = "";
		if (dbrow[12]) _rec->cprSrefWdbeMPort.assign(dbrow[12], dblengths[12]); else _rec->cprSrefWdbeMPort = "";
		if (dbrow[13]) _rec->csiSrefWdbeMSignal.assign(dbrow[13], dblengths[13]); else _rec->csiSrefWdbeMSignal = "";
		if (dbrow[14]) _rec->Comment.assign(dbrow[14], dblengths[14]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMPort::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPort& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMPort* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMPort::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMPort::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMPort();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refWdbeCPort = atoll((char*) dbrow[1]); else rec->refWdbeCPort = 0;
			if (dbrow[2]) rec->mdlRefWdbeMModule = atoll((char*) dbrow[2]); else rec->mdlRefWdbeMModule = 0;
			if (dbrow[3]) rec->mdlNum = atol((char*) dbrow[3]); else rec->mdlNum = 0;
			if (dbrow[4]) rec->mdlIxVCat = atol((char*) dbrow[4]); else rec->mdlIxVCat = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->ixVDir = atol((char*) dbrow[6]); else rec->ixVDir = 0;
			if (dbrow[7]) rec->srefWdbeKHdltype.assign(dbrow[7], dblengths[7]); else rec->srefWdbeKHdltype = "";
			if (dbrow[8]) rec->Width = atoi((char*) dbrow[8]); else rec->Width = 0;
			if (dbrow[9]) rec->Minmax.assign(dbrow[9], dblengths[9]); else rec->Minmax = "";
			if (dbrow[10]) rec->Defval.assign(dbrow[10], dblengths[10]); else rec->Defval = "";
			if (dbrow[11]) rec->cpiSrefWdbeMPin.assign(dbrow[11], dblengths[11]); else rec->cpiSrefWdbeMPin = "";
			if (dbrow[12]) rec->cprSrefWdbeMPort.assign(dbrow[12], dblengths[12]); else rec->cprSrefWdbeMPort = "";
			if (dbrow[13]) rec->csiSrefWdbeMSignal.assign(dbrow[13], dblengths[13]); else rec->csiSrefWdbeMSignal = "";
			if (dbrow[14]) rec->Comment.assign(dbrow[14], dblengths[14]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMPort::insertRec(
			WdbeMPort* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[4] = rec->sref.length();
	l[6] = rec->srefWdbeKHdltype.length();
	l[8] = rec->Minmax.length();
	l[9] = rec->Defval.length();
	l[10] = rec->cpiSrefWdbeMPin.length();
	l[11] = rec->cprSrefWdbeMPort.length();
	l[12] = rec->csiSrefWdbeMSignal.length();
	l[13] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCPort,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->mdlNum,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->mdlIxVCat,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVDir,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Width,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->cpiSrefWdbeMPin.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->cprSrefWdbeMPort.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->csiSrefWdbeMSignal.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMPort::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMPort::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMPort::insertRst(
			ListWdbeMPort& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMPort::updateRec(
			WdbeMPort* rec
		) {
	unsigned long l[15]; my_bool n[15]; my_bool e[15];

	l[4] = rec->sref.length();
	l[6] = rec->srefWdbeKHdltype.length();
	l[8] = rec->Minmax.length();
	l[9] = rec->Defval.length();
	l[10] = rec->cpiSrefWdbeMPin.length();
	l[11] = rec->cprSrefWdbeMPort.length();
	l[12] = rec->csiSrefWdbeMSignal.length();
	l[13] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refWdbeCPort,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->mdlRefWdbeMModule,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->mdlNum,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->mdlIxVCat,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVDir,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->srefWdbeKHdltype.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->Width,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Minmax.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Defval.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->cpiSrefWdbeMPin.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->cprSrefWdbeMPort.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->csiSrefWdbeMSignal.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[13]),&(n[13]),&(e[13])),
		bindUbigint(&rec->ref,&(l[14]),&(n[14]),&(e[14]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMPort::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMPort::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMPort::updateRst(
			ListWdbeMPort& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMPort::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMPort::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMPort::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMPort::loadRecByRef(
			ubigint ref
			, WdbeMPort** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMPort WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeMPort::loadRefsByClu(
			ubigint refWdbeCPort
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refWdbeCPort) + "", append, refs);
};

ubigint MyTblWdbeMPort::loadRefsByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdlRefWdbeMModule) + "", append, refs);
};

ubigint MyTblWdbeMPort::loadRstByClu(
			ubigint refWdbeCPort
			, const bool append
			, ListWdbeMPort& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCPort, mdlRefWdbeMModule, mdlNum, mdlIxVCat, sref, ixVDir, srefWdbeKHdltype, Width, Minmax, Defval, cpiSrefWdbeMPin, cprSrefWdbeMPort, csiSrefWdbeMSignal, Comment FROM TblWdbeMPort WHERE refWdbeCPort = " + to_string(refWdbeCPort) + "", append, rst);
};

ubigint MyTblWdbeMPort::loadRstByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, ListWdbeMPort& rst
		) {
	return loadRstBySQL("SELECT ref, refWdbeCPort, mdlRefWdbeMModule, mdlNum, mdlIxVCat, sref, ixVDir, srefWdbeKHdltype, Width, Minmax, Defval, cpiSrefWdbeMPin, cprSrefWdbeMPort, csiSrefWdbeMSignal, Comment FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(mdlRefWdbeMModule) + " ORDER BY mdlNum ASC", append, rst);
};

bool MyTblWdbeMPort::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblWdbeMPort WHERE ref = " + to_string(ref) + "", sref);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMPort
 ******************************************************************************/

PgTblWdbeMPort::PgTblWdbeMPort() :
			TblWdbeMPort()
			, PgTable()
		{
};

PgTblWdbeMPort::~PgTblWdbeMPort() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMPort::initStatements() {
	createStatement("TblWdbeMPort_insertRec", "INSERT INTO TblWdbeMPort (refWdbeCPort, mdlRefWdbeMModule, mdlNum, mdlIxVCat, sref, ixVDir, srefWdbeKHdltype, Width, Minmax, Defval, cpiSrefWdbeMPin, cprSrefWdbeMPort, csiSrefWdbeMSignal, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14) RETURNING ref", 14);
	createStatement("TblWdbeMPort_updateRec", "UPDATE TblWdbeMPort SET refWdbeCPort = $1, mdlRefWdbeMModule = $2, mdlNum = $3, mdlIxVCat = $4, sref = $5, ixVDir = $6, srefWdbeKHdltype = $7, Width = $8, Minmax = $9, Defval = $10, cpiSrefWdbeMPin = $11, cprSrefWdbeMPort = $12, csiSrefWdbeMSignal = $13, Comment = $14 WHERE ref = $15", 15);
	createStatement("TblWdbeMPort_removeRecByRef", "DELETE FROM TblWdbeMPort WHERE ref = $1", 1);

	createStatement("TblWdbeMPort_loadRecByRef", "SELECT ref, refWdbeCPort, mdlRefWdbeMModule, mdlNum, mdlIxVCat, sref, ixVDir, srefWdbeKHdltype, Width, Minmax, Defval, cpiSrefWdbeMPin, cprSrefWdbeMPort, csiSrefWdbeMSignal, Comment FROM TblWdbeMPort WHERE ref = $1", 1);
	createStatement("TblWdbeMPort_loadRefsByClu", "SELECT ref FROM TblWdbeMPort WHERE refWdbeCPort = $1", 1);
	createStatement("TblWdbeMPort_loadRefsByMdl", "SELECT ref FROM TblWdbeMPort WHERE mdlRefWdbeMModule = $1", 1);
	createStatement("TblWdbeMPort_loadRstByClu", "SELECT ref, refWdbeCPort, mdlRefWdbeMModule, mdlNum, mdlIxVCat, sref, ixVDir, srefWdbeKHdltype, Width, Minmax, Defval, cpiSrefWdbeMPin, cprSrefWdbeMPort, csiSrefWdbeMSignal, Comment FROM TblWdbeMPort WHERE refWdbeCPort = $1", 1);
	createStatement("TblWdbeMPort_loadRstByMdl", "SELECT ref, refWdbeCPort, mdlRefWdbeMModule, mdlNum, mdlIxVCat, sref, ixVDir, srefWdbeKHdltype, Width, Minmax, Defval, cpiSrefWdbeMPin, cprSrefWdbeMPort, csiSrefWdbeMSignal, Comment FROM TblWdbeMPort WHERE mdlRefWdbeMModule = $1 ORDER BY mdlNum ASC", 1);
	createStatement("TblWdbeMPort_loadSrfByRef", "SELECT sref FROM TblWdbeMPort WHERE ref = $1", 1);
};

bool PgTblWdbeMPort::loadRec(
			PGresult* res
			, WdbeMPort** rec
		) {
	char* ptr;

	WdbeMPort* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMPort();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecport"),
			PQfnumber(res, "mdlrefwdbemmodule"),
			PQfnumber(res, "mdlnum"),
			PQfnumber(res, "mdlixvcat"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "cpisrefwdbempin"),
			PQfnumber(res, "cprsrefwdbemport"),
			PQfnumber(res, "csisrefwdbemsignal"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refWdbeCPort = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->mdlRefWdbeMModule = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mdlNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->mdlIxVCat = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVDir = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Width = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Minmax.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Defval.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->cpiSrefWdbeMPin.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->cprSrefWdbeMPort.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->csiSrefWdbeMSignal.assign(ptr, PQgetlength(res, 0, fnum[13]));
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[14]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMPort::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMPort& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMPort* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refwdbecport"),
			PQfnumber(res, "mdlrefwdbemmodule"),
			PQfnumber(res, "mdlnum"),
			PQfnumber(res, "mdlixvcat"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "srefwdbekhdltype"),
			PQfnumber(res, "width"),
			PQfnumber(res, "minmax"),
			PQfnumber(res, "defval"),
			PQfnumber(res, "cpisrefwdbempin"),
			PQfnumber(res, "cprsrefwdbemport"),
			PQfnumber(res, "csisrefwdbemsignal"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMPort();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refWdbeCPort = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->mdlRefWdbeMModule = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mdlNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->mdlIxVCat = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVDir = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->srefWdbeKHdltype.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Width = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Minmax.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Defval.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->cpiSrefWdbeMPin.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->cprSrefWdbeMPort.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->csiSrefWdbeMSignal.assign(ptr, PQgetlength(res, numread, fnum[13]));
			ptr = PQgetvalue(res, numread, fnum[14]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[14]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMPort::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMPort** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPort::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMPort::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMPort& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPort::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMPort::loadRecBySQL(
			const string& sqlstr
			, WdbeMPort** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPort::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMPort::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMPort& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPort::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMPort::insertRec(
			WdbeMPort* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refWdbeCPort = htonl64(rec->refWdbeCPort);
	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	uint _mdlNum = htonl(rec->mdlNum);
	uint _mdlIxVCat = htonl(rec->mdlIxVCat);
	uint _ixVDir = htonl(rec->ixVDir);
	usmallint _Width = htons(rec->Width);

	const char* vals[] = {
		(char*) &_refWdbeCPort,
		(char*) &_mdlRefWdbeMModule,
		(char*) &_mdlNum,
		(char*) &_mdlIxVCat,
		rec->sref.c_str(),
		(char*) &_ixVDir,
		rec->srefWdbeKHdltype.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str(),
		rec->Defval.c_str(),
		rec->cpiSrefWdbeMPin.c_str(),
		rec->cprSrefWdbeMPort.c_str(),
		rec->csiSrefWdbeMSignal.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(uint),
		0,
		sizeof(usmallint),
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeMPort_insertRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMPort::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMPort::insertRst(
			ListWdbeMPort& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMPort::updateRec(
			WdbeMPort* rec
		) {
	PGresult* res;

	ubigint _refWdbeCPort = htonl64(rec->refWdbeCPort);
	ubigint _mdlRefWdbeMModule = htonl64(rec->mdlRefWdbeMModule);
	uint _mdlNum = htonl(rec->mdlNum);
	uint _mdlIxVCat = htonl(rec->mdlIxVCat);
	uint _ixVDir = htonl(rec->ixVDir);
	usmallint _Width = htons(rec->Width);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refWdbeCPort,
		(char*) &_mdlRefWdbeMModule,
		(char*) &_mdlNum,
		(char*) &_mdlIxVCat,
		rec->sref.c_str(),
		(char*) &_ixVDir,
		rec->srefWdbeKHdltype.c_str(),
		(char*) &_Width,
		rec->Minmax.c_str(),
		rec->Defval.c_str(),
		rec->cpiSrefWdbeMPin.c_str(),
		rec->cprSrefWdbeMPort.c_str(),
		rec->csiSrefWdbeMSignal.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(uint),
		0,
		sizeof(usmallint),
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMPort_updateRec", 15, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMPort::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMPort::updateRst(
			ListWdbeMPort& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMPort::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeMPort_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMPort::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMPort::loadRecByRef(
			ubigint ref
			, WdbeMPort** rec
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

	return loadRecByStmt("TblWdbeMPort_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeMPort::loadRefsByClu(
			ubigint refWdbeCPort
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeCPort = htonl64(refWdbeCPort);

	const char* vals[] = {
		(char*) &_refWdbeCPort
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMPort_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMPort::loadRefsByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _mdlRefWdbeMModule = htonl64(mdlRefWdbeMModule);

	const char* vals[] = {
		(char*) &_mdlRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMPort_loadRefsByMdl", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMPort::loadRstByClu(
			ubigint refWdbeCPort
			, const bool append
			, ListWdbeMPort& rst
		) {
	ubigint _refWdbeCPort = htonl64(refWdbeCPort);

	const char* vals[] = {
		(char*) &_refWdbeCPort
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMPort_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeMPort::loadRstByMdl(
			ubigint mdlRefWdbeMModule
			, const bool append
			, ListWdbeMPort& rst
		) {
	ubigint _mdlRefWdbeMModule = htonl64(mdlRefWdbeMModule);

	const char* vals[] = {
		(char*) &_mdlRefWdbeMModule
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMPort_loadRstByMdl", 1, vals, l, f, append, rst);
};

bool PgTblWdbeMPort::loadSrfByRef(
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

	return loadStringByStmt("TblWdbeMPort_loadSrfByRef", 1, vals, l, f, sref);
};

#endif

