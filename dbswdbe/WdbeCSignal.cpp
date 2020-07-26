/**
	* \file WdbeCSignal.cpp
	* Dbs and XML wrapper for table TblWdbeCSignal (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeCSignal.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWdbeCSignal
 ******************************************************************************/

TblWdbeCSignal::TblWdbeCSignal() {
};

TblWdbeCSignal::~TblWdbeCSignal() {
};

ubigint TblWdbeCSignal::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeCSignal
 ******************************************************************************/

MyTblWdbeCSignal::MyTblWdbeCSignal() :
			TblWdbeCSignal()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWdbeCSignal::~MyTblWdbeCSignal() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWdbeCSignal::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWdbeCSignal () VALUES ()", false);
};

ubigint MyTblWdbeCSignal::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWdbeCSignal::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWdbeCSignal::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeCSignal
 ******************************************************************************/

PgTblWdbeCSignal::PgTblWdbeCSignal() :
			TblWdbeCSignal()
			, PgTable()
		{
};

PgTblWdbeCSignal::~PgTblWdbeCSignal() {
};

void PgTblWdbeCSignal::initStatements() {
	createStatement("TblWdbeCSignal_getNewRef", "SELECT nextval('TblWdbeCSignal')", 0);
};

ubigint PgTblWdbeCSignal::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWdbeCSignal_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeCSignal::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

