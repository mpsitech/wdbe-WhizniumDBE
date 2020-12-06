/**
	* \file WdbeCPort.cpp
	* Dbs and XML wrapper for table TblWdbeCPort (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeCPort.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWdbeCPort
 ******************************************************************************/

TblWdbeCPort::TblWdbeCPort() {
};

TblWdbeCPort::~TblWdbeCPort() {
};

ubigint TblWdbeCPort::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeCPort
 ******************************************************************************/

MyTblWdbeCPort::MyTblWdbeCPort() :
			TblWdbeCPort()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWdbeCPort::~MyTblWdbeCPort() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWdbeCPort::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWdbeCPort () VALUES ()", false);
};

ubigint MyTblWdbeCPort::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWdbeCPort::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWdbeCPort::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeCPort
 ******************************************************************************/

PgTblWdbeCPort::PgTblWdbeCPort() :
			TblWdbeCPort()
			, PgTable()
		{
};

PgTblWdbeCPort::~PgTblWdbeCPort() {
};

void PgTblWdbeCPort::initStatements() {
	createStatement("TblWdbeCPort_getNewRef", "SELECT nextval('TblWdbeCPort')", 0);
};

ubigint PgTblWdbeCPort::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWdbeCPort_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeCPort::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif
