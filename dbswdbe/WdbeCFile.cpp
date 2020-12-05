/**
	* \file WdbeCFile.cpp
	* Dbs and XML wrapper for table TblWdbeCFile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeCFile.h"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class TblWdbeCFile
 ******************************************************************************/

TblWdbeCFile::TblWdbeCFile() {
};

TblWdbeCFile::~TblWdbeCFile() {
};

ubigint TblWdbeCFile::getNewRef() {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeCFile
 ******************************************************************************/

MyTblWdbeCFile::MyTblWdbeCFile() :
			TblWdbeCFile()
			, MyTable()
		{
	stmtGetNewRef = NULL;
};

MyTblWdbeCFile::~MyTblWdbeCFile() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblWdbeCFile::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblWdbeCFile () VALUES ()", false);
};

ubigint MyTblWdbeCFile::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) {
		string dbms = "MyTblWdbeCFile::getNewRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtGetNewRef)) {
		string dbms = "MyTblWdbeCFile::getNewRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	return mysql_stmt_insert_id(stmtGetNewRef);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeCFile
 ******************************************************************************/

PgTblWdbeCFile::PgTblWdbeCFile() :
			TblWdbeCFile()
			, PgTable()
		{
};

PgTblWdbeCFile::~PgTblWdbeCFile() {
};

void PgTblWdbeCFile::initStatements() {
	createStatement("TblWdbeCFile_getNewRef", "SELECT nextval('TblWdbeCFile')", 0);
};

ubigint PgTblWdbeCFile::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblWdbeCFile_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeCFile::getNewRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
#endif

