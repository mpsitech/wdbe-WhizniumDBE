/**
	* \file WdbeCVariable.h
	* Dbs and XML wrapper for table TblWdbeCVariable (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBECVARIABLE_H
#define WDBECVARIABLE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWdbeCVariable: C++ wrapper for table TblWdbeCVariable
	*/
class TblWdbeCVariable {

public:
	TblWdbeCVariable();
	virtual ~TblWdbeCVariable();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWdbeCVariable: C++ wrapper for table TblWdbeCVariable (MySQL database)
	*/
class MyTblWdbeCVariable : public TblWdbeCVariable, public Sbecore::MyTable {

public:
	MyTblWdbeCVariable();
	~MyTblWdbeCVariable();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtGetNewRef;

public:
	Sbecore::ubigint getNewRef();
};
#endif

#if defined(SBECORE_PG)
/**
	* PgTblWdbeCVariable: C++ wrapper for table TblWdbeCVariable (PgSQL database)
	*/
class PgTblWdbeCVariable : public TblWdbeCVariable, public Sbecore::PgTable {

public:
	PgTblWdbeCVariable();
	~PgTblWdbeCVariable();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

