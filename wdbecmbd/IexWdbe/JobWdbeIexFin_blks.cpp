/**
	* \file JobWdbeIexFin_blks.cpp
	* job handler for job JobWdbeIexFin (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWdbeIexFin::VecVSge
 ******************************************************************************/

uint JobWdbeIexFin::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "parse") return PARSE;
	if (s == "prserr") return PRSERR;
	if (s == "prsdone") return PRSDONE;
	if (s == "import") return IMPORT;
	if (s == "imperr") return IMPERR;
	if (s == "reverse") return REVERSE;
	if (s == "collect") return COLLECT;
	if (s == "cltdone") return CLTDONE;
	if (s == "export") return EXPORT;
	if (s == "done") return DONE;

	return(0);
};

string JobWdbeIexFin::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == PARSE) return("parse");
	if (ix == PRSERR) return("prserr");
	if (ix == PRSDONE) return("prsdone");
	if (ix == IMPORT) return("import");
	if (ix == IMPERR) return("imperr");
	if (ix == REVERSE) return("reverse");
	if (ix == COLLECT) return("collect");
	if (ix == CLTDONE) return("cltdone");
	if (ix == EXPORT) return("export");
	if (ix == DONE) return("done");

	return("");
};

void JobWdbeIexFin::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 11; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};
