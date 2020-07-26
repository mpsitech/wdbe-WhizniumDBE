/**
	* \file WdbeCGeneric.cpp
	* Dbs and XML wrapper for table TblWdbeCGeneric (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "WdbeCGeneric.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWdbeCGeneric
 ******************************************************************************/

TblWdbeCGeneric::TblWdbeCGeneric() {
};

TblWdbeCGeneric::~TblWdbeCGeneric() {
};

ubigint TblWdbeCGeneric::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeCGeneric
 ******************************************************************************/

MyTblWdbeCGeneric::MyTblWdbeCGeneric() :
			TblWdbeCGeneric()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWdbeCGeneric::~MyTblWdbeCGeneric() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWdbeCGeneric::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWdbeCGeneric () VALUES ()", false);
};

ubigint MyTblWdbeCGeneric::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWdbeCGeneric::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWdbeCGeneric::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeCGeneric
 ******************************************************************************/

PgTblWdbeCGeneric::PgTblWdbeCGeneric() :
			TblWdbeCGeneric()
			, PgTable()
		{
};

PgTblWdbeCGeneric::~PgTblWdbeCGeneric() {
};

void PgTblWdbeCGeneric::initStatements() {
	createStatement("TblWdbeCGeneric_getNewRef", "SELECT nextval('TblWdbeCGeneric')", 0);
};

ubigint PgTblWdbeCGeneric::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWdbeCGeneric_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeCGeneric::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

