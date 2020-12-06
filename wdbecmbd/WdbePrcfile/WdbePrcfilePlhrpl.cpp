/**
	* \file WdbePrcfilePlhrpl.cpp
	* Wdbe operation processor - replace placeholders in template file and write into output file (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbePrcfilePlhrpl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePrcfile;

/******************************************************************************
 namespace WdbePrcfilePlhrpl
 ******************************************************************************/

DpchRetWdbe* WdbePrcfilePlhrpl::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePrcfilePlhrpl* dpchinv
		) {
	ubigint inRefWdbeMFile = dpchinv->inRefWdbeMFile;
	string infile = dpchinv->infile;
	string outfile = dpchinv->outfile;
	vector<string> keys = dpchinv->keys;
	vector<string> vals = dpchinv->vals;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string key;

	char* buf = new char[1048576];
	string s;
	size_t keylen;
	size_t ptr1, ptr2;

	unsigned int newlinecnt;

	ifstream infi;
	fstream outfi;

	mode_t mode;

	if (inRefWdbeMFile != 0) s = xchg->acvpath + "/" + Acv::getfile(dbswdbe, inRefWdbeMFile);
	else s = xchg->tmppath + "/" + infile;

	// determine input file permissions
	if (access(s.c_str(), X_OK) == 0) mode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH; // 644
	else mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // 755

	// open input file
	infi.open(s.c_str());

	// open output file
	s = xchg->tmppath + "/" + outfile;
	outfi.open(s.c_str(), ios::out | ios::trunc);

	newlinecnt = 0;

	while (infi.good() && (!infi.eof())) {
		// read single line
		s = StrMod::readLine(infi, buf, 1048576);

		if (s.length() == 0) newlinecnt++;
		else {
			for (unsigned int i = 0; i < newlinecnt; i++) outfi << endl;
			newlinecnt = 0;

			// look for srefsKey, one after the other
			for (unsigned int i = 0; i < keys.size(); i++) {
				key = "&" + keys[i] + ";";
				keylen = key.length();

				ptr1 = 0;
				ptr2 = s.find(key, ptr1);
				while ((ptr2 >= ptr1) && (ptr2 != string::npos)) {
					// replace by value
					s = s.substr(0, ptr2) + vals[i] + s.substr(ptr2+keylen);

					ptr1 = ptr2+1;
					ptr2 = s.find(key, ptr1);
				};
			};

			outfi << s << endl;
		};
	};

	delete[] buf;

	// close input file
	infi.close();

	// close output file and adapt permissions
	outfi.close();

	s = xchg->tmppath + "/" + outfile;
	chmod(s.c_str(), mode);
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
