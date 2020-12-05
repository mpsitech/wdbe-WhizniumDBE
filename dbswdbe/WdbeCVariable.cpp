/**
	* \file WdbeCVariable.cpp
	* Dbs and XML wrapper for table TblWdbeCVariable (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeCVariable.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWdbeCVariable
 ******************************************************************************/

TblWdbeCVariable::TblWdbeCVariable() {
};

TblWdbeCVariable::~TblWdbeCVariable() {
};

ubigint TblWdbeCVariable::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeCVariable
 ******************************************************************************/

MyTblWdbeCVariable::MyTblWdbeCVariable() :
			TblWdbeCVariable()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWdbeCVariable::~MyTblWdbeCVariable() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWdbeCVariable::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWdbeCVariable () VALUES ()", false);
};

ubigint MyTblWdbeCVariable::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWdbeCVariable::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWdbeCVariable::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeCVariable
 ******************************************************************************/

PgTblWdbeCVariable::PgTblWdbeCVariable() :
			TblWdbeCVariable()
			, PgTable()
		{
};

PgTblWdbeCVariable::~PgTblWdbeCVariable() {
};

void PgTblWdbeCVariable::initStatements() {
	createStatement("TblWdbeCVariable_getNewRef", "SELECT nextval('TblWdbeCVariable')", 0);
};

ubigint PgTblWdbeCVariable::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWdbeCVariable_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeCVariable::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

