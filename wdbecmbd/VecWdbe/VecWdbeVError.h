/**
	* \file VecWdbeVError.h
	* vector VecWdbeVError (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef VECWDBEVERROR_H
#define VECWDBEVERROR_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVError
	*/
namespace VecWdbeVError {
	const Sbecore::uint DBS_CONN = 1;
	const Sbecore::uint DBS_QUERY = 2;
	const Sbecore::uint DBS_STMTEXEC = 3;
	const Sbecore::uint DBS_STMTPREP = 4;
	const Sbecore::uint ENGCONN = 5;
	const Sbecore::uint IEX_FILETYPE = 6;
	const Sbecore::uint IEX_FTM = 7;
	const Sbecore::uint IEX_IARG = 8;
	const Sbecore::uint IEX_IDIREF = 9;
	const Sbecore::uint IEX_IOP = 10;
	const Sbecore::uint IEX_IREF = 11;
	const Sbecore::uint IEX_RETR = 12;
	const Sbecore::uint IEX_THINT = 13;
	const Sbecore::uint IEX_THSREF = 14;
	const Sbecore::uint IEX_TSREF = 15;
	const Sbecore::uint IEX_VERSION = 16;
	const Sbecore::uint IEX_VSREF = 17;
	const Sbecore::uint PATHNF = 18;
	const Sbecore::uint TXTRD_CONTENT = 19;
	const Sbecore::uint TXTRD_ENDTKN = 20;
	const Sbecore::uint TXTRD_TKNMISPL = 21;
	const Sbecore::uint TXTRD_TKNUNID = 22;
	const Sbecore::uint XMLIO_BUFPARSE = 23;
	const Sbecore::uint XMLIO_FILEPARSE = 24;
	const Sbecore::uint LIC_AUTH = 25;
	const Sbecore::uint LIC_CTWARN = 26;
	const Sbecore::uint LIC_CTLOST = 27;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);

	std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWdbeVLocale);

	void fillFeed(const Sbecore::uint ixWdbeVLocale, Sbecore::Xmlio::Feed& feed);
};

#endif

