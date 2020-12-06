/**
	* \file WdbeCFsmstate.cpp
	* Dbs and XML wrapper for table TblWdbeCFsmstate (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeCFsmstate.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWdbeCFsmstate
 ******************************************************************************/

TblWdbeCFsmstate::TblWdbeCFsmstate() {
};

TblWdbeCFsmstate::~TblWdbeCFsmstate() {
};

ubigint TblWdbeCFsmstate::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeCFsmstate
 ******************************************************************************/

MyTblWdbeCFsmstate::MyTblWdbeCFsmstate() :
			TblWdbeCFsmstate()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWdbeCFsmstate::~MyTblWdbeCFsmstate() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWdbeCFsmstate::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWdbeCFsmstate () VALUES ()", false);
};

ubigint MyTblWdbeCFsmstate::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWdbeCFsmstate::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWdbeCFsmstate::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeCFsmstate
 ******************************************************************************/

PgTblWdbeCFsmstate::PgTblWdbeCFsmstate() :
			TblWdbeCFsmstate()
			, PgTable()
		{
};

PgTblWdbeCFsmstate::~PgTblWdbeCFsmstate() {
};

void PgTblWdbeCFsmstate::initStatements() {
	createStatement("TblWdbeCFsmstate_getNewRef", "SELECT nextval('TblWdbeCFsmstate')", 0);
};

ubigint PgTblWdbeCFsmstate::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWdbeCFsmstate_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeCFsmstate::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif
