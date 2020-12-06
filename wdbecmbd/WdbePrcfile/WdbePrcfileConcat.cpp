/**
	* \file WdbePrcfileConcat.cpp
	* Wdbe operation processor - concatenate text from multiple input files into output file (implementation)
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

#include "WdbePrcfileConcat.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePrcfile;

/******************************************************************************
 namespace WdbePrcfileConcat
 ******************************************************************************/

DpchRetWdbe* WdbePrcfileConcat::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePrcfileConcat* dpchinv
		) {
	vector<string> infiles = dpchinv->infiles;
	vector<string> headers = dpchinv->headers;
	string outfile = dpchinv->outfile;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	char* buf = new char[1048576];
	string s;

	ifstream infi;
	fstream outfi;

	mode_t mode;

	if (infiles.size() > 0) {
		// determine permissions of first input file
		s = xchg->tmppath + "/" + infiles[0];
		if (access(s.c_str(), X_OK) == 0) mode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH; // 644
		else mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // 755

		// open output file
		s = xchg->tmppath + "/" + outfile;
		outfi.open(s.c_str(), ios::out | ios::app);

		// concatenate input file contents
		for (unsigned int i = 0; i < infiles.size(); i++) {
			s = xchg->tmppath + "/" + infiles[i];
			infi.open(s.c_str());

			if (headers[i] != "") {
				outfi << headers[i] << endl;
				outfi << endl;
			};

			// copy line by line
			while (infi.good() && (!infi.eof())) {
				s = StrMod::readLine(infi, buf, 1048576);
				if (s.length() > 0) outfi << s << endl;
			};

			if (headers[i] != "") outfi << endl << endl;

			infi.close();
		};

		// close output file and adapt permissions
		outfi.close();

		s = xchg->tmppath + "/" + outfile;
		chmod(s.c_str(), mode);
	};

	delete[] buf;
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- INSERT
