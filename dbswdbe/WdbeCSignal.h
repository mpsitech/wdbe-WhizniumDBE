/**
	* \file WdbeCSignal.h
	* Dbs and XML wrapper for table TblWdbeCSignal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBECSIGNAL_H
#define WDBECSIGNAL_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWdbeCSignal: C++ wrapper for table TblWdbeCSignal
	*/
class TblWdbeCSignal {

public:
	TblWdbeCSignal();
	virtual ~TblWdbeCSignal();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWdbeCSignal: C++ wrapper for table TblWdbeCSignal (MySQL database)
	*/
class MyTblWdbeCSignal : public TblWdbeCSignal, public Sbecore::MyTable {

public:
	MyTblWdbeCSignal();
	~MyTblWdbeCSignal();

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
	* PgTblWdbeCSignal: C++ wrapper for table TblWdbeCSignal (PgSQL database)
	*/
class PgTblWdbeCSignal : public TblWdbeCSignal, public Sbecore::PgTable {

public:
	PgTblWdbeCSignal();
	~PgTblWdbeCSignal();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif
