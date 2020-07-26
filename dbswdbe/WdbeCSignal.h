/**
	* \file WdbeCSignal.h
	* Dbs and XML wrapper for table TblWdbeCSignal (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

