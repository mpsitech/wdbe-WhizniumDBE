/**
	* \file WdbeCFile.h
	* Dbs and XML wrapper for table TblWdbeCFile (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBECFILE_H
#define WDBECFILE_H

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

/**
	* TblWdbeCFile: C++ wrapper for table TblWdbeCFile
	*/
class TblWdbeCFile {

public:
	TblWdbeCFile();
	virtual ~TblWdbeCFile();

public:
	virtual Sbecore::ubigint getNewRef();
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/**
	* MyTblWdbeCFile: C++ wrapper for table TblWdbeCFile (MySQL database)
	*/
class MyTblWdbeCFile : public TblWdbeCFile, public Sbecore::MyTable {

public:
	MyTblWdbeCFile();
	~MyTblWdbeCFile();

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
	* PgTblWdbeCFile: C++ wrapper for table TblWdbeCFile (PgSQL database)
	*/
class PgTblWdbeCFile : public TblWdbeCFile, public Sbecore::PgTable {

public:
	PgTblWdbeCFile();
	~PgTblWdbeCFile();

public:
	void initStatements();

public:
	Sbecore::ubigint getNewRef();
};
#endif

#endif

