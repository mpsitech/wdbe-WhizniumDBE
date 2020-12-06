/**
	* \file WdbeCGeneric.h
	* Dbs and XML wrapper for table TblWdbeCGeneric (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

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
