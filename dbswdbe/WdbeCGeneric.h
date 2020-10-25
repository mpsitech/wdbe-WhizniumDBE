/**
	* \file WdbeCGeneric.h
	* Dbs and XML wrapper for table TblWdbeCGeneric (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBECGENERIC_H
#define WDBECGENERIC_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWdbeCGeneric: C++ wrapper for table TblWdbeCGeneric
	*/
class TblWdbeCGeneric {

public:
	TblWdbeCGeneric();
	virtual ~TblWdbeCGeneric();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWdbeCGeneric: C++ wrapper for table TblWdbeCGeneric (MySQL database)
	*/
class MyTblWdbeCGeneric : public TblWdbeCGeneric, public Sbecore::MyTable {

public:
	MyTblWdbeCGeneric();
	~MyTblWdbeCGeneric();

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
	* PgTblWdbeCGeneric: C++ wrapper for table TblWdbeCGeneric (PgSQL database)
	*/
class PgTblWdbeCGeneric : public TblWdbeCGeneric, public Sbecore::PgTable {

public:
	PgTblWdbeCGeneric();
	~PgTblWdbeCGeneric();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

