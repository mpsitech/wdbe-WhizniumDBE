/**
	* \file WdbeCFsmstate.h
	* Dbs and XML wrapper for table TblWdbeCFsmstate (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBECFSMSTATE_H
#define WDBECFSMSTATE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWdbeCFsmstate: C++ wrapper for table TblWdbeCFsmstate
	*/
class TblWdbeCFsmstate {

public:
	TblWdbeCFsmstate();
	virtual ~TblWdbeCFsmstate();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWdbeCFsmstate: C++ wrapper for table TblWdbeCFsmstate (MySQL database)
	*/
class MyTblWdbeCFsmstate : public TblWdbeCFsmstate, public Sbecore::MyTable {

public:
	MyTblWdbeCFsmstate();
	~MyTblWdbeCFsmstate();

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
	* PgTblWdbeCFsmstate: C++ wrapper for table TblWdbeCFsmstate (PgSQL database)
	*/
class PgTblWdbeCFsmstate : public TblWdbeCFsmstate, public Sbecore::PgTable {

public:
	PgTblWdbeCFsmstate();
	~PgTblWdbeCFsmstate();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif
