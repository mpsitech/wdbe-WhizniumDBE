/**
	* \file VecWdbeVError.cpp
	* vector VecWdbeVError (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "VecWdbeVError.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWdbeVError
 ******************************************************************************/

uint VecWdbeVError::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dbs.conn") return DBS_CONN;
	if (s == "dbs.query") return DBS_QUERY;
	if (s == "dbs.stmtexec") return DBS_STMTEXEC;
	if (s == "dbs.stmtprep") return DBS_STMTPREP;
	if (s == "engconn") return ENGCONN;
	if (s == "iex.filetype") return IEX_FILETYPE;
	if (s == "iex.ftm") return IEX_FTM;
	if (s == "iex.iarg") return IEX_IARG;
	if (s == "iex.idiref") return IEX_IDIREF;
	if (s == "iex.iop") return IEX_IOP;
	if (s == "iex.iref") return IEX_IREF;
	if (s == "iex.retr") return IEX_RETR;
	if (s == "iex.thint") return IEX_THINT;
	if (s == "iex.thsref") return IEX_THSREF;
	if (s == "iex.tsref") return IEX_TSREF;
	if (s == "iex.version") return IEX_VERSION;
	if (s == "iex.vsref") return IEX_VSREF;
	if (s == "pathnf") return PATHNF;
	if (s == "txtrd.content") return TXTRD_CONTENT;
	if (s == "txtrd.endtkn") return TXTRD_ENDTKN;
	if (s == "txtrd.tknmispl") return TXTRD_TKNMISPL;
	if (s == "txtrd.tknunid") return TXTRD_TKNUNID;
	if (s == "xmlio.bufparse") return XMLIO_BUFPARSE;
	if (s == "xmlio.fileparse") return XMLIO_FILEPARSE;
	if (s == "lic.auth") return LIC_AUTH;
	if (s == "lic.ctwarn") return LIC_CTWARN;
	if (s == "lic.ctlost") return LIC_CTLOST;

	return(0);
};

string VecWdbeVError::getSref(
			const uint ix
		) {
	if (ix == DBS_CONN) return("dbs.conn");
	if (ix == DBS_QUERY) return("dbs.query");
	if (ix == DBS_STMTEXEC) return("dbs.stmtexec");
	if (ix == DBS_STMTPREP) return("dbs.stmtprep");
	if (ix == ENGCONN) return("engconn");
	if (ix == IEX_FILETYPE) return("iex.filetype");
	if (ix == IEX_FTM) return("iex.ftm");
	if (ix == IEX_IARG) return("iex.iarg");
	if (ix == IEX_IDIREF) return("iex.idiref");
	if (ix == IEX_IOP) return("iex.iop");
	if (ix == IEX_IREF) return("iex.iref");
	if (ix == IEX_RETR) return("iex.retr");
	if (ix == IEX_THINT) return("iex.thint");
	if (ix == IEX_THSREF) return("iex.thsref");
	if (ix == IEX_TSREF) return("iex.tsref");
	if (ix == IEX_VERSION) return("iex.version");
	if (ix == IEX_VSREF) return("iex.vsref");
	if (ix == PATHNF) return("pathnf");
	if (ix == TXTRD_CONTENT) return("txtrd.content");
	if (ix == TXTRD_ENDTKN) return("txtrd.endtkn");
	if (ix == TXTRD_TKNMISPL) return("txtrd.tknmispl");
	if (ix == TXTRD_TKNUNID) return("txtrd.tknunid");
	if (ix == XMLIO_BUFPARSE) return("xmlio.bufparse");
	if (ix == XMLIO_FILEPARSE) return("xmlio.fileparse");
	if (ix == LIC_AUTH) return("lic.auth");
	if (ix == LIC_CTWARN) return("lic.ctwarn");
	if (ix == LIC_CTLOST) return("lic.ctlost");

	return("");
};

string VecWdbeVError::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == DBS_CONN) return("database connection failure: &dbms;");
		if (ix == DBS_QUERY) return("error executing SQL query '&sql;': &dbms;");
		if (ix == DBS_STMTEXEC) return("error executing statement: &dbms;");
		if (ix == DBS_STMTPREP) return("error preparing SQL statement '&sql;': &dbms;");
		if (ix == ENGCONN) return("error connecting to engine");
		if (ix == IEX_FILETYPE) return("not a &iexsref; file");
		if (ix == IEX_FTM) return("time stamp/date/time format '&ftm;' invalid for import column &iel; in line &lineno;");
		if (ix == IEX_IARG) return("argument '&iarg;' for custom import invalid for import column &iel; in line &lineno;");
		if (ix == IEX_IDIREF) return("duplicate identifying integer reference &idiref; for import &ime; in line &lineno;");
		if (ix == IEX_IOP) return("invalid import operation &iop; for import &ime; in line &lineno;");
		if (ix == IEX_IREF) return("integer reference &iref; not resolved for import column &iel; in line &lineno;");
		if (ix == IEX_RETR) return("record can't be retrieved for import &ime; based on information in line &lineno;");
		if (ix == IEX_THINT) return("textual hint '&thint;' for table reference not resolved for import column &iel; in line &lineno;");
		if (ix == IEX_THSREF) return("hierarchical string reference '&thsref;' to table not resolved for import column &iel; in line &lineno;");
		if (ix == IEX_TSREF) return("string reference '&tsref;' to table not resolved for import column &iel; in line &lineno;");
		if (ix == IEX_VERSION) return("version &version; incompatible, minimum is &minversion;");
		if (ix == IEX_VSREF) return("string reference '&vsref;' to vector item not resolved for import column &iel; in line &lineno;");
		if (ix == PATHNF) return("path '&path;' not found");
		if (ix == TXTRD_CONTENT) return("misplaced content in line &lineno;");
		if (ix == TXTRD_ENDTKN) return("missing &ime;.end token in line &lineno;");
		if (ix == TXTRD_TKNMISPL) return("misplaced token '&tkn;' in line &lineno;");
		if (ix == TXTRD_TKNUNID) return("unidentified token '&tkn;' in line &lineno;");
		if (ix == XMLIO_BUFPARSE) return("error parsing XML buffer");
		if (ix == XMLIO_FILEPARSE) return("error parsing XML file");
		if (ix == LIC_AUTH) return("&srvmsg;");
		if (ix == LIC_CTWARN) return("Last contact with licensing server was on &lastAttempt;. WhizniumDBE will cease to function unless contact is re-established by &finalAttempt;.");
		if (ix == LIC_CTLOST) return("Last contact with licensing server was on &lastAttempt;. Please contact support at support@mpsitech.com.");
		return(getSref(ix));
	};

	return("");
};

void VecWdbeVError::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 27; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

