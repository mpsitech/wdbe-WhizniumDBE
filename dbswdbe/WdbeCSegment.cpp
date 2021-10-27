/**
	* \file WdbeCSegment.cpp
	* Dbs and XML wrapper for table TblWdbeCSegment (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#include "WdbeCSegment.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWdbeCSegment
 ******************************************************************************/

TblWdbeCSegment::TblWdbeCSegment() {
};

TblWdbeCSegment::~TblWdbeCSegment() {
};

ubigint TblWdbeCSegment::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeCSegment
 ******************************************************************************/

MyTblWdbeCSegment::MyTblWdbeCSegment() :
			TblWdbeCSegment()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWdbeCSegment::~MyTblWdbeCSegment() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWdbeCSegment::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWdbeCSegment () VALUES ()", false);
};

ubigint MyTblWdbeCSegment::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWdbeCSegment::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWdbeCSegment::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeCSegment
 ******************************************************************************/

PgTblWdbeCSegment::PgTblWdbeCSegment() :
			TblWdbeCSegment()
			, PgTable()
		{
};

PgTblWdbeCSegment::~PgTblWdbeCSegment() {
};

void PgTblWdbeCSegment::initStatements() {
	createStatement("TblWdbeCSegment_getNewRef", "SELECT nextval('TblWdbeCSegment')", 0);
};

ubigint PgTblWdbeCSegment::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWdbeCSegment_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeCSegment::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif
