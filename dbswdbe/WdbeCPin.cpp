/**
	* \file WdbeCPin.cpp
	* Dbs and XML wrapper for table TblWdbeCPin (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeCPin.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWdbeCPin
 ******************************************************************************/

TblWdbeCPin::TblWdbeCPin() {
};

TblWdbeCPin::~TblWdbeCPin() {
};

ubigint TblWdbeCPin::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeCPin
 ******************************************************************************/

MyTblWdbeCPin::MyTblWdbeCPin() :
			TblWdbeCPin()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWdbeCPin::~MyTblWdbeCPin() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWdbeCPin::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWdbeCPin () VALUES ()", false);
};

ubigint MyTblWdbeCPin::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWdbeCPin::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWdbeCPin::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeCPin
 ******************************************************************************/

PgTblWdbeCPin::PgTblWdbeCPin() :
			TblWdbeCPin()
			, PgTable()
		{
};

PgTblWdbeCPin::~PgTblWdbeCPin() {
};

void PgTblWdbeCPin::initStatements() {
	createStatement("TblWdbeCPin_getNewRef", "SELECT nextval('TblWdbeCPin')", 0);
};

ubigint PgTblWdbeCPin::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWdbeCPin_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeCPin::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

