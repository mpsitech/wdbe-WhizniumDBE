/**
	* \file WdbeCPin.h
	* Dbs and XML wrapper for table TblWdbeCPin (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBECPIN_H
#define WDBECPIN_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWdbeCPin: C++ wrapper for table TblWdbeCPin
	*/
class TblWdbeCPin {

public:
	TblWdbeCPin();
	virtual ~TblWdbeCPin();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWdbeCPin: C++ wrapper for table TblWdbeCPin (MySQL database)
	*/
class MyTblWdbeCPin : public TblWdbeCPin, public Sbecore::MyTable {

public:
	MyTblWdbeCPin();
	~MyTblWdbeCPin();

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
	* PgTblWdbeCPin: C++ wrapper for table TblWdbeCPin (PgSQL database)
	*/
class PgTblWdbeCPin : public TblWdbeCPin, public Sbecore::PgTable {

public:
	PgTblWdbeCPin();
	~PgTblWdbeCPin();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

