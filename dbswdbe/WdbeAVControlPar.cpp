/**
	* \file WdbeAVControlPar.cpp
	* database access for table TblWdbeAVControlPar (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeAVControlPar.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeAVControlPar
 ******************************************************************************/

WdbeAVControlPar::WdbeAVControlPar(
			const ubigint ref
			, const uint ixWdbeVControl
			, const ubigint x1RefWdbeMUser
			, const uint x2IxWdbeVLocale
			, const string Par
			, const string Val
		) {

	this->ref = ref;
	this->ixWdbeVControl = ixWdbeVControl;
	this->x1RefWdbeMUser = x1RefWdbeMUser;
	this->x2IxWdbeVLocale = x2IxWdbeVLocale;
	this->Par = Par;
	this->Val = Val;
};

bool WdbeAVControlPar::operator==(
			const WdbeAVControlPar& comp
		) {
	return false;
};

bool WdbeAVControlPar::operator!=(
			const WdbeAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeAVControlPar
 ******************************************************************************/

ListWdbeAVControlPar::ListWdbeAVControlPar() {
};

ListWdbeAVControlPar::ListWdbeAVControlPar(
			const ListWdbeAVControlPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeAVControlPar(*(src.nodes[i]));
};

ListWdbeAVControlPar::~ListWdbeAVControlPar() {
	clear();
};

void ListWdbeAVControlPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeAVControlPar::size() const {
	return(nodes.size());
};

void ListWdbeAVControlPar::append(
			WdbeAVControlPar* rec
		) {
	nodes.push_back(rec);
};

WdbeAVControlPar* ListWdbeAVControlPar::operator[](
			const uint ix
		) {
	WdbeAVControlPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeAVControlPar& ListWdbeAVControlPar::operator=(
			const ListWdbeAVControlPar& src
		) {
	WdbeAVControlPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeAVControlPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeAVControlPar::operator==(
			const ListWdbeAVControlPar& comp
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

bool ListWdbeAVControlPar::operator!=(
			const ListWdbeAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeAVControlPar
 ******************************************************************************/

TblWdbeAVControlPar::TblWdbeAVControlPar() {
};

TblWdbeAVControlPar::~TblWdbeAVControlPar() {
};

bool TblWdbeAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAVControlPar** rec
		) {
	return false;
};

ubigint TblWdbeAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAVControlPar& rst
		) {
	return 0;
};

ubigint TblWdbeAVControlPar::insertRec(
			WdbeAVControlPar* rec
		) {
	return 0;
};

ubigint TblWdbeAVControlPar::insertNewRec(
			WdbeAVControlPar** rec
			, const uint ixWdbeVControl
			, const ubigint x1RefWdbeMUser
			, const uint x2IxWdbeVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAVControlPar* _rec = NULL;

	_rec = new WdbeAVControlPar(0, ixWdbeVControl, x1RefWdbeMUser, x2IxWdbeVLocale, Par, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeAVControlPar::appendNewRecToRst(
			ListWdbeAVControlPar& rst
			, WdbeAVControlPar** rec
			, const uint ixWdbeVControl
			, const ubigint x1RefWdbeMUser
			, const uint x2IxWdbeVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	WdbeAVControlPar* _rec = NULL;

	retval = insertNewRec(&_rec, ixWdbeVControl, x1RefWdbeMUser, x2IxWdbeVLocale, Par, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeAVControlPar::insertRst(
			ListWdbeAVControlPar& rst
			, bool transact
		) {
};

void TblWdbeAVControlPar::updateRec(
			WdbeAVControlPar* rec
		) {
};

void TblWdbeAVControlPar::updateRst(
			ListWdbeAVControlPar& rst
			, bool transact
		) {
};

void TblWdbeAVControlPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeAVControlPar::loadRecByRef(
			ubigint ref
			, WdbeAVControlPar** rec
		) {
	return false;
};

bool TblWdbeAVControlPar::loadRefByCtlUsrPar(
			uint ixWdbeVControl
			, ubigint x1RefWdbeMUser
			, string Par
			, ubigint& ref
		) {
	return false;
};

bool TblWdbeAVControlPar::loadValByCtlUsrPar(
			uint ixWdbeVControl
			, ubigint x1RefWdbeMUser
			, string Par
			, string& Val
		) {
	return false;
};

ubigint TblWdbeAVControlPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeAVControlPar& rst
		) {
	ubigint numload = 0;
	WdbeAVControlPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeAVControlPar
 ******************************************************************************/

MyTblWdbeAVControlPar::MyTblWdbeAVControlPar() :
			TblWdbeAVControlPar()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeAVControlPar::~MyTblWdbeAVControlPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeAVControlPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeAVControlPar (ixWdbeVControl, x1RefWdbeMUser, x2IxWdbeVLocale, Par, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeAVControlPar SET ixWdbeVControl = ?, x1RefWdbeMUser = ?, x2IxWdbeVLocale = ?, Par = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeAVControlPar WHERE ref = ?", false);
};

bool MyTblWdbeAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAVControlPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeAVControlPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAVControlPar::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAVControlPar::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeAVControlPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixWdbeVControl = atol((char*) dbrow[1]); else _rec->ixWdbeVControl = 0;
		if (dbrow[2]) _rec->x1RefWdbeMUser = atoll((char*) dbrow[2]); else _rec->x1RefWdbeMUser = 0;
		if (dbrow[3]) _rec->x2IxWdbeVLocale = atol((char*) dbrow[3]); else _rec->x2IxWdbeVLocale = 0;
		if (dbrow[4]) _rec->Par.assign(dbrow[4], dblengths[4]); else _rec->Par = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAVControlPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeAVControlPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeAVControlPar::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeAVControlPar::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeAVControlPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixWdbeVControl = atol((char*) dbrow[1]); else rec->ixWdbeVControl = 0;
			if (dbrow[2]) rec->x1RefWdbeMUser = atoll((char*) dbrow[2]); else rec->x1RefWdbeMUser = 0;
			if (dbrow[3]) rec->x2IxWdbeVLocale = atol((char*) dbrow[3]); else rec->x2IxWdbeVLocale = 0;
			if (dbrow[4]) rec->Par.assign(dbrow[4], dblengths[4]); else rec->Par = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeAVControlPar::insertRec(
			WdbeAVControlPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixWdbeVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWdbeMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxWdbeVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeAVControlPar::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeAVControlPar::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeAVControlPar::insertRst(
			ListWdbeAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeAVControlPar::updateRec(
			WdbeAVControlPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixWdbeVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefWdbeMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxWdbeVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeAVControlPar::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeAVControlPar::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeAVControlPar::updateRst(
			ListWdbeAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeAVControlPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeAVControlPar::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeAVControlPar::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeAVControlPar::loadRecByRef(
			ubigint ref
			, WdbeAVControlPar** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeAVControlPar WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeAVControlPar::loadRefByCtlUsrPar(
			uint ixWdbeVControl
			, ubigint x1RefWdbeMUser
			, string Par
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblWdbeAVControlPar WHERE ixWdbeVControl = " + to_string(ixWdbeVControl) + " AND x1RefWdbeMUser = " + to_string(x1RefWdbeMUser) + " AND Par = '" + Par + "'", ref);
};

bool MyTblWdbeAVControlPar::loadValByCtlUsrPar(
			uint ixWdbeVControl
			, ubigint x1RefWdbeMUser
			, string Par
			, string& Val
		) {
	return loadStringBySQL("SELECT Val FROM TblWdbeAVControlPar WHERE ixWdbeVControl = " + to_string(ixWdbeVControl) + " AND x1RefWdbeMUser = " + to_string(x1RefWdbeMUser) + " AND Par = '" + Par + "'", Val);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeAVControlPar
 ******************************************************************************/

PgTblWdbeAVControlPar::PgTblWdbeAVControlPar() :
			TblWdbeAVControlPar()
			, PgTable()
		{
};

PgTblWdbeAVControlPar::~PgTblWdbeAVControlPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeAVControlPar::initStatements() {
	createStatement("TblWdbeAVControlPar_insertRec", "INSERT INTO TblWdbeAVControlPar (ixWdbeVControl, x1RefWdbeMUser, x2IxWdbeVLocale, Par, Val) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5);
	createStatement("TblWdbeAVControlPar_updateRec", "UPDATE TblWdbeAVControlPar SET ixWdbeVControl = $1, x1RefWdbeMUser = $2, x2IxWdbeVLocale = $3, Par = $4, Val = $5 WHERE ref = $6", 6);
	createStatement("TblWdbeAVControlPar_removeRecByRef", "DELETE FROM TblWdbeAVControlPar WHERE ref = $1", 1);

	createStatement("TblWdbeAVControlPar_loadRecByRef", "SELECT ref, ixWdbeVControl, x1RefWdbeMUser, x2IxWdbeVLocale, Par, Val FROM TblWdbeAVControlPar WHERE ref = $1", 1);
	createStatement("TblWdbeAVControlPar_loadRefByCtlUsrPar", "SELECT ref FROM TblWdbeAVControlPar WHERE ixWdbeVControl = $1 AND x1RefWdbeMUser = $2 AND Par = $3", 3);
	createStatement("TblWdbeAVControlPar_loadValByCtlUsrPar", "SELECT Val FROM TblWdbeAVControlPar WHERE ixWdbeVControl = $1 AND x1RefWdbeMUser = $2 AND Par = $3", 3);
};

bool PgTblWdbeAVControlPar::loadRec(
			PGresult* res
			, WdbeAVControlPar** rec
		) {
	char* ptr;

	WdbeAVControlPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeAVControlPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixwdbevcontrol"),
			PQfnumber(res, "x1refwdbemuser"),
			PQfnumber(res, "x2ixwdbevlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixWdbeVControl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefWdbeMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2IxWdbeVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Par.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeAVControlPar::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeAVControlPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeAVControlPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixwdbevcontrol"),
			PQfnumber(res, "x1refwdbemuser"),
			PQfnumber(res, "x2ixwdbevlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new WdbeAVControlPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixWdbeVControl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefWdbeMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2IxWdbeVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Par.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeAVControlPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeAVControlPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVControlPar::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

bool PgTblWdbeAVControlPar::loadRecBySQL(
			const string& sqlstr
			, WdbeAVControlPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVControlPar::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeAVControlPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVControlPar::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeAVControlPar::insertRec(
			WdbeAVControlPar* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixWdbeVControl = htonl(rec->ixWdbeVControl);
	ubigint _x1RefWdbeMUser = htonl64(rec->x1RefWdbeMUser);
	uint _x2IxWdbeVLocale = htonl(rec->x2IxWdbeVLocale);

	const char* vals[] = {
		(char*) &_ixWdbeVControl,
		(char*) &_x1RefWdbeMUser,
		(char*) &_x2IxWdbeVLocale,
		rec->Par.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeAVControlPar_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeAVControlPar::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeAVControlPar::insertRst(
			ListWdbeAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeAVControlPar::updateRec(
			WdbeAVControlPar* rec
		) {
	PGresult* res;

	uint _ixWdbeVControl = htonl(rec->ixWdbeVControl);
	ubigint _x1RefWdbeMUser = htonl64(rec->x1RefWdbeMUser);
	uint _x2IxWdbeVLocale = htonl(rec->x2IxWdbeVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixWdbeVControl,
		(char*) &_x1RefWdbeMUser,
		(char*) &_x2IxWdbeVLocale,
		rec->Par.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeAVControlPar_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAVControlPar::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeAVControlPar::updateRst(
			ListWdbeAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeAVControlPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblWdbeAVControlPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeAVControlPar::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeAVControlPar::loadRecByRef(
			ubigint ref
			, WdbeAVControlPar** rec
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

	return loadRecByStmt("TblWdbeAVControlPar_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeAVControlPar::loadRefByCtlUsrPar(
			uint ixWdbeVControl
			, ubigint x1RefWdbeMUser
			, string Par
			, ubigint& ref
		) {
	uint _ixWdbeVControl = htonl(ixWdbeVControl);
	ubigint _x1RefWdbeMUser = htonl64(x1RefWdbeMUser);

	const char* vals[] = {
		(char*) &_ixWdbeVControl,
		(char*) &_x1RefWdbeMUser,
		Par.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadRefByStmt("TblWdbeAVControlPar_loadRefByCtlUsrPar", 3, vals, l, f, ref);
};

bool PgTblWdbeAVControlPar::loadValByCtlUsrPar(
			uint ixWdbeVControl
			, ubigint x1RefWdbeMUser
			, string Par
			, string& Val
		) {
	uint _ixWdbeVControl = htonl(ixWdbeVControl);
	ubigint _x1RefWdbeMUser = htonl64(x1RefWdbeMUser);

	const char* vals[] = {
		(char*) &_ixWdbeVControl,
		(char*) &_x1RefWdbeMUser,
		Par.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadStringByStmt("TblWdbeAVControlPar_loadValByCtlUsrPar", 3, vals, l, f, Val);
};

#endif

