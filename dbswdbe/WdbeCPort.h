/**
	* \file WdbeCPort.h
	* Dbs and XML wrapper for table TblWdbeCPort (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WDBECPORT_H
#define WDBECPORT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWdbeCPort: C++ wrapper for table TblWdbeCPort
	*/
class TblWdbeCPort {

public:
	TblWdbeCPort();
	virtual ~TblWdbeCPort();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWdbeCPort: C++ wrapper for table TblWdbeCPort (MySQL database)
	*/
class MyTblWdbeCPort : public TblWdbeCPort, public Sbecore::MyTable {

public:
	MyTblWdbeCPort();
	~MyTblWdbeCPort();

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
	* PgTblWdbeCPort: C++ wrapper for table TblWdbeCPort (PgSQL database)
	*/
class PgTblWdbeCPort : public TblWdbeCPort, public Sbecore::PgTable {

public:
	PgTblWdbeCPort();
	~PgTblWdbeCPort();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif
