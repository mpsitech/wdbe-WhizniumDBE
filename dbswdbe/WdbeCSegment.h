/**
	* \file WdbeCSegment.h
	* Dbs and XML wrapper for table TblWdbeCSegment (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifndef WDBECSEGMENT_H
#define WDBECSEGMENT_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWdbeCSegment: C++ wrapper for table TblWdbeCSegment
	*/
class TblWdbeCSegment {

public:
	TblWdbeCSegment();
	virtual ~TblWdbeCSegment();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWdbeCSegment: C++ wrapper for table TblWdbeCSegment (MySQL database)
	*/
class MyTblWdbeCSegment : public TblWdbeCSegment, public Sbecore::MyTable {

public:
	MyTblWdbeCSegment();
	~MyTblWdbeCSegment();

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
	* PgTblWdbeCSegment: C++ wrapper for table TblWdbeCSegment (PgSQL database)
	*/
class PgTblWdbeCSegment : public TblWdbeCSegment, public Sbecore::PgTable {

public:
	PgTblWdbeCSegment();
	~PgTblWdbeCSegment();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif
