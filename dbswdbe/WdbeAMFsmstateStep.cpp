/**
	* \file WdbeAMFsmstateStep.cpp
	* database access for table TblWdbeAMFsmstateStep (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeAMFsmstateStep.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAMFsmstateStep
 ******************************************************************************/

WdbeAMFsmstateStep::WdbeAMFsmstateStep(
			const ubigint ref
			, const ubigint fstRefWdbeMFsmstate
			, const uint fstNum
			, const ubigint fnxRefWdbeMFsmstate
			, const string Cond1
			, const string Ip1
			, const string Cond2
			, const string Ip2
			, const string Cond3
			, const string Ip3
			, const string Cond4
			, const string Ip4
		) {

	this->ref = ref;
	this->fstRefWdbeMFsmstate = fstRefWdbeMFsmstate;
	this->fstNum = fstNum;
	this->fnxRefWdbeMFsmstate = fnxRefWdbeMFsmstate;
	this->Cond1 = Cond1;
	this->Ip1 = Ip1;
	this->Cond2 = Cond2;
	this->Ip2 = Ip2;
	this->Cond3 = Cond3;
	this->Ip3 = Ip3;
	this->Cond4 = Cond4;
	this->Ip4 = Ip4;
};

bool WdbeAMFsmstateStep::operator==(
			const WdbeAMFsmstateStep& comp
		) {
	return false;
};

bool WdbeAMFsmstateStep::operator!=(
			const WdbeAMFsmstateStep& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAMFsmstateStep
 ******************************************************************************/

ListWdbeAMFsmstateStep::ListWdbeAMFsmstateStep() {
};

ListWdbeAMFsmstateStep::ListWdbeAMFsmstateStep(
			const ListWdbeAMFsmstateStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAMFsmstateStep(*(src.nodes[i]));
};

ListWdbeAMFsmstateStep::~ListWdbeAMFsmstateStep() {
	clear();
};

void ListWdbeAMFsmstateStep::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAMFsmstateStep::size() const {
	return(nodes.size());
};

void ListWdbeAMFsmstateStep::append(
			WdbeAMFsmstateStep* rec
		) {
	nodes.push_back(rec);
};

WdbeAMFsmstateStep* ListWdbeAMFsmstateStep::operator[](
			const uint ix
		) {
	WdbeAMFsmstateStep* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAMFsmstateStep& ListWdbeAMFsmstateStep::operator=(
			const ListWdbeAMFsmstateStep& src
		) {
	WdbeAMFsmstateStep* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAMFsmstateStep(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAMFsmstateStep::operator==(
			const ListWdbeAMFsmstateStep& comp
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

bool ListWdbeAMFsmstateStep::operator!=(
			const ListWdbeAMFsmstateStep& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAMFsmstateStep
 ******************************************************************************/

TblWdbeAMFsmstateStep::TblWdbeAMFsmstateStep() {
};

TblWdbeAMFsmstateStep::~TblWdbeAMFsmstateStep() {
};

bool TblWdbeAMFsmstateStep::loadRecBySQL(
			const string& sqlstr
			, WdbeAMFsmstateStep** rec
		) {
	return false;
};

ubigint TblWdbeAMFsmstateStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMFsmstateStep& rst
		) {
	return 0;
};

ubigint TblWdbeAMFsmstateStep::insertRec(
			WdbeAMFsmstateStep* rec
		) {
	return 0;
};

ubigint TblWdbeAMFsmstateStep::insertNewRec(
			WdbeAMFsmstateStep** rec
			, const ubigint fstRefWdbeMFsmstate
			, const uint fstNum
			, const ubigint fnxRefWdbeMFsmstate
			, const string Cond1
			, const string Ip1
			, const string Cond2
			, const string Ip2
			, const string Cond3
			, const string Ip3
			, const string Cond4
			, const string Ip4
		) {
	ubigint retval = 0;
	WdbeAMFsmstateStep* _rec = NULL;

	_rec = new WdbeAMFsmstateStep(0, fstRefWdbeMFsmstate, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAMFsmstateStep::appendNewRecToRst(
			ListWdbeAMFsmstateStep& rst
			, WdbeAMFsmstateStep** rec
			, const ubigint fstRefWdbeMFsmstate
			, const uint fstNum
			, const ubigint fnxRefWdbeMFsmstate
			, const string Cond1
			, const string Ip1
			, const string Cond2
			, const string Ip2
			, const string Cond3
			, const string Ip3
			, const string Cond4
			, const string Ip4
		) {
	ubigint retval = 0;
	WdbeAMFsmstateStep* _rec = NULL;

	retval = insertNewRec(&_rec, fstRefWdbeMFsmstate, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAMFsmstateStep::insertRst(
			ListWdbeAMFsmstateStep& rst
			, bool transact
		) {
};

void TblWdbeAMFsmstateStep::updateRec(
			WdbeAMFsmstateStep* rec
		) {
};

void TblWdbeAMFsmstateStep::updateRst(
			ListWdbeAMFsmstateStep& rst
			, bool transact
		) {
};

void TblWdbeAMFsmstateStep::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAMFsmstateStep::loadRecByRef(
			ubigint ref
			, WdbeAMFsmstateStep** rec
		) {
	return false;
};

ubigint TblWdbeAMFsmstateStep::loadRefsByFst(
			ubigint fstRefWdbeMFsmstate
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeAMFsmstateStep::loadRstByFst(
			ubigint fstRefWdbeMFsmstate
			, const bool append
			, ListWdbeAMFsmstateStep& rst
		) {
	return 0;
};

ubigint TblWdbeAMFsmstateStep::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAMFsmstateStep& rst
		) {
	ubigint numload = 0;
	WdbeAMFsmstateStep* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAMFsmstateStep
 ******************************************************************************/

MyTblWdbeAMFsmstateStep::MyTblWdbeAMFsmstateStep() :
			TblWdbeAMFsmstateStep()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAMFsmstateStep::~MyTblWdbeAMFsmstateStep() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAMFsmstateStep::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAMFsmstateStep (fstRefWdbeMFsmstate, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAMFsmstateStep SET fstRefWdbeMFsmstate = ?, fstNum = ?, fnxRefWdbeMFsmstate = ?, Cond1 = ?, Ip1 = ?, Cond2 = ?, Ip2 = ?, Cond3 = ?, Ip3 = ?, Cond4 = ?, Ip4 = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAMFsmstateStep WHERE ref = ?", false);
};

bool MyTblWdbeAMFsmstateStep::loadRecBySQL(
			const string& sqlstr
			, WdbeAMFsmstateStep** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAMFsmstateStep* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMFsmstateStep::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMFsmstateStep::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAMFsmstateStep();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->fstRefWdbeMFsmstate = atoll((char*) dbrow[1]); else _rec->fstRefWdbeMFsmstate = 0;
		if (dbrow[2]) _rec->fstNum = atol((char*) dbrow[2]); else _rec->fstNum = 0;
		if (dbrow[3]) _rec->fnxRefWdbeMFsmstate = atoll((char*) dbrow[3]); else _rec->fnxRefWdbeMFsmstate = 0;
		if (dbrow[4]) _rec->Cond1.assign(dbrow[4], dblengths[4]); else _rec->Cond1 = "";
		if (dbrow[5]) _rec->Ip1.assign(dbrow[5], dblengths[5]); else _rec->Ip1 = "";
		if (dbrow[6]) _rec->Cond2.assign(dbrow[6], dblengths[6]); else _rec->Cond2 = "";
		if (dbrow[7]) _rec->Ip2.assign(dbrow[7], dblengths[7]); else _rec->Ip2 = "";
		if (dbrow[8]) _rec->Cond3.assign(dbrow[8], dblengths[8]); else _rec->Cond3 = "";
		if (dbrow[9]) _rec->Ip3.assign(dbrow[9], dblengths[9]); else _rec->Ip3 = "";
		if (dbrow[10]) _rec->Cond4.assign(dbrow[10], dblengths[10]); else _rec->Cond4 = "";
		if (dbrow[11]) _rec->Ip4.assign(dbrow[11], dblengths[11]); else _rec->Ip4 = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAMFsmstateStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMFsmstateStep& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAMFsmstateStep* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAMFsmstateStep::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAMFsmstateStep::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAMFsmstateStep();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->fstRefWdbeMFsmstate = atoll((char*) dbrow[1]); else rec->fstRefWdbeMFsmstate = 0;
			if (dbrow[2]) rec->fstNum = atol((char*) dbrow[2]); else rec->fstNum = 0;
			if (dbrow[3]) rec->fnxRefWdbeMFsmstate = atoll((char*) dbrow[3]); else rec->fnxRefWdbeMFsmstate = 0;
			if (dbrow[4]) rec->Cond1.assign(dbrow[4], dblengths[4]); else rec->Cond1 = "";
			if (dbrow[5]) rec->Ip1.assign(dbrow[5], dblengths[5]); else rec->Ip1 = "";
			if (dbrow[6]) rec->Cond2.assign(dbrow[6], dblengths[6]); else rec->Cond2 = "";
			if (dbrow[7]) rec->Ip2.assign(dbrow[7], dblengths[7]); else rec->Ip2 = "";
			if (dbrow[8]) rec->Cond3.assign(dbrow[8], dblengths[8]); else rec->Cond3 = "";
			if (dbrow[9]) rec->Ip3.assign(dbrow[9], dblengths[9]); else rec->Ip3 = "";
			if (dbrow[10]) rec->Cond4.assign(dbrow[10], dblengths[10]); else rec->Cond4 = "";
			if (dbrow[11]) rec->Ip4.assign(dbrow[11], dblengths[11]); else rec->Ip4 = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAMFsmstateStep::insertRec(
			WdbeAMFsmstateStep* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[3] = rec->Cond1.length();
	l[4] = rec->Ip1.length();
	l[5] = rec->Cond2.length();
	l[6] = rec->Ip2.length();
	l[7] = rec->Cond3.length();
	l[8] = rec->Ip3.length();
	l[9] = rec->Cond4.length();
	l[10] = rec->Ip4.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->fstRefWdbeMFsmstate,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->fstNum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->fnxRefWdbeMFsmstate,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Cond1.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Ip1.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Cond2.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Ip2.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Cond3.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Ip3.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Cond4.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Ip4.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAMFsmstateStep::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAMFsmstateStep::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAMFsmstateStep::insertRst(
			ListWdbeAMFsmstateStep& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAMFsmstateStep::updateRec(
			WdbeAMFsmstateStep* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[3] = rec->Cond1.length();
	l[4] = rec->Ip1.length();
	l[5] = rec->Cond2.length();
	l[6] = rec->Ip2.length();
	l[7] = rec->Cond3.length();
	l[8] = rec->Ip3.length();
	l[9] = rec->Cond4.length();
	l[10] = rec->Ip4.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->fstRefWdbeMFsmstate,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->fstNum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->fnxRefWdbeMFsmstate,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Cond1.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Ip1.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Cond2.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Ip2.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Cond3.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Ip3.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Cond4.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Ip4.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAMFsmstateStep::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAMFsmstateStep::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAMFsmstateStep::updateRst(
			ListWdbeAMFsmstateStep& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAMFsmstateStep::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAMFsmstateStep::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAMFsmstateStep::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAMFsmstateStep::loadRecByRef(
			ubigint ref
			, WdbeAMFsmstateStep** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAMFsmstateStep WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblWdbeAMFsmstateStep::loadRefsByFst(
			ubigint fstRefWdbeMFsmstate
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeAMFsmstateStep WHERE fstRefWdbeMFsmstate = " + to_string(fstRefWdbeMFsmstate) + "", append, refs);
};

ubigint MyTblWdbeAMFsmstateStep::loadRstByFst(
			ubigint fstRefWdbeMFsmstate
			, const bool append
			, ListWdbeAMFsmstateStep& rst
		) {
	return loadRstBySQL("SELECT ref, fstRefWdbeMFsmstate, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4 FROM TblWdbeAMFsmstateStep WHERE fstRefWdbeMFsmstate = " + to_string(fstRefWdbeMFsmstate) + " ORDER BY fstNum ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAMFsmstateStep
 ******************************************************************************/

PgTblWdbeAMFsmstateStep::PgTblWdbeAMFsmstateStep() :
			TblWdbeAMFsmstateStep()
			, PgTable()
		{
};

PgTblWdbeAMFsmstateStep::~PgTblWdbeAMFsmstateStep() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAMFsmstateStep::initStatements() {
	createStatement("TblWdbeAMFsmstateStep_insertRec", "INSERT INTO TblWdbeAMFsmstateStep (fstRefWdbeMFsmstate, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11);
	createStatement("TblWdbeAMFsmstateStep_updateRec", "UPDATE TblWdbeAMFsmstateStep SET fstRefWdbeMFsmstate = $1, fstNum = $2, fnxRefWdbeMFsmstate = $3, Cond1 = $4, Ip1 = $5, Cond2 = $6, Ip2 = $7, Cond3 = $8, Ip3 = $9, Cond4 = $10, Ip4 = $11 WHERE ref = $12", 12);
	createStatement("TblWdbeAMFsmstateStep_removeRecByRef", "DELETE FROM TblWdbeAMFsmstateStep WHERE ref = $1", 1);

	createStatement("TblWdbeAMFsmstateStep_loadRecByRef", "SELECT ref, fstRefWdbeMFsmstate, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4 FROM TblWdbeAMFsmstateStep WHERE ref = $1", 1);
	createStatement("TblWdbeAMFsmstateStep_loadRefsByFst", "SELECT ref FROM TblWdbeAMFsmstateStep WHERE fstRefWdbeMFsmstate = $1", 1);
	createStatement("TblWdbeAMFsmstateStep_loadRstByFst", "SELECT ref, fstRefWdbeMFsmstate, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4 FROM TblWdbeAMFsmstateStep WHERE fstRefWdbeMFsmstate = $1 ORDER BY fstNum ASC", 1);
};

bool PgTblWdbeAMFsmstateStep::loadRec(
			PGresult* res
			, WdbeAMFsmstateStep** rec
		) {
	char* ptr;

	WdbeAMFsmstateStep* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAMFsmstateStep();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "fstrefwdbemfsmstate"),
			PQfnumber(res, "fstnum"),
			PQfnumber(res, "fnxrefwdbemfsmstate"),
			PQfnumber(res, "cond1"),
			PQfnumber(res, "ip1"),
			PQfnumber(res, "cond2"),
			PQfnumber(res, "ip2"),
			PQfnumber(res, "cond3"),
			PQfnumber(res, "ip3"),
			PQfnumber(res, "cond4"),
			PQfnumber(res, "ip4")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->fstRefWdbeMFsmstate = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->fstNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->fnxRefWdbeMFsmstate = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Cond1.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Ip1.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Cond2.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Ip2.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Cond3.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Ip3.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Cond4.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Ip4.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAMFsmstateStep::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAMFsmstateStep& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAMFsmstateStep* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "fstrefwdbemfsmstate"),
			PQfnumber(res, "fstnum"),
			PQfnumber(res, "fnxrefwdbemfsmstate"),
			PQfnumber(res, "cond1"),
			PQfnumber(res, "ip1"),
			PQfnumber(res, "cond2"),
			PQfnumber(res, "ip2"),
			PQfnumber(res, "cond3"),
			PQfnumber(res, "ip3"),
			PQfnumber(res, "cond4"),
			PQfnumber(res, "ip4")
		};

		while (numread < numrow) {
			rec = new WdbeAMFsmstateStep();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->fstRefWdbeMFsmstate = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->fstNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->fnxRefWdbeMFsmstate = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Cond1.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Ip1.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Cond2.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Ip2.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Cond3.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Ip3.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Cond4.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Ip4.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAMFsmstateStep::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAMFsmstateStep** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMFsmstateStep::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMFsmstateStep::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeAMFsmstateStep& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMFsmstateStep::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeAMFsmstateStep::loadRecBySQL(
			const string& sqlstr
			, WdbeAMFsmstateStep** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMFsmstateStep::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAMFsmstateStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAMFsmstateStep& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMFsmstateStep::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAMFsmstateStep::insertRec(
			WdbeAMFsmstateStep* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _fstRefWdbeMFsmstate = htonl64(rec->fstRefWdbeMFsmstate);
	uint _fstNum = htonl(rec->fstNum);
	ubigint _fnxRefWdbeMFsmstate = htonl64(rec->fnxRefWdbeMFsmstate);

	const char* vals[] = {
		(char*) &_fstRefWdbeMFsmstate,
		(char*) &_fstNum,
		(char*) &_fnxRefWdbeMFsmstate,
		rec->Cond1.c_str(),
		rec->Ip1.c_str(),
		rec->Cond2.c_str(),
		rec->Ip2.c_str(),
		rec->Cond3.c_str(),
		rec->Ip3.c_str(),
		rec->Cond4.c_str(),
		rec->Ip4.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeAMFsmstateStep_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAMFsmstateStep::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAMFsmstateStep::insertRst(
			ListWdbeAMFsmstateStep& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAMFsmstateStep::updateRec(
			WdbeAMFsmstateStep* rec
		) {
	PGresult* res;

	ubigint _fstRefWdbeMFsmstate = htonl64(rec->fstRefWdbeMFsmstate);
	uint _fstNum = htonl(rec->fstNum);
	ubigint _fnxRefWdbeMFsmstate = htonl64(rec->fnxRefWdbeMFsmstate);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_fstRefWdbeMFsmstate,
		(char*) &_fstNum,
		(char*) &_fnxRefWdbeMFsmstate,
		rec->Cond1.c_str(),
		rec->Ip1.c_str(),
		rec->Cond2.c_str(),
		rec->Ip2.c_str(),
		rec->Cond3.c_str(),
		rec->Ip3.c_str(),
		rec->Cond4.c_str(),
		rec->Ip4.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAMFsmstateStep_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMFsmstateStep::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAMFsmstateStep::updateRst(
			ListWdbeAMFsmstateStep& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAMFsmstateStep::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAMFsmstateStep_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAMFsmstateStep::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAMFsmstateStep::loadRecByRef(
			ubigint ref
			, WdbeAMFsmstateStep** rec
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

	return loadRecByStmt("TblWdbeAMFsmstateStep_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblWdbeAMFsmstateStep::loadRefsByFst(
			ubigint fstRefWdbeMFsmstate
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _fstRefWdbeMFsmstate = htonl64(fstRefWdbeMFsmstate);

	const char* vals[] = {
		(char*) &_fstRefWdbeMFsmstate
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeAMFsmstateStep_loadRefsByFst", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeAMFsmstateStep::loadRstByFst(
			ubigint fstRefWdbeMFsmstate
			, const bool append
			, ListWdbeAMFsmstateStep& rst
		) {
	ubigint _fstRefWdbeMFsmstate = htonl64(fstRefWdbeMFsmstate);

	const char* vals[] = {
		(char*) &_fstRefWdbeMFsmstate
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeAMFsmstateStep_loadRstByFst", 1, vals, l, f, append, rst);
};

#endif

