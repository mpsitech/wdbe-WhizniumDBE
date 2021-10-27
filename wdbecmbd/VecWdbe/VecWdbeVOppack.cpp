/**
	* \file VecWdbeVOppack.cpp
	* vector VecWdbeVOppack (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "VecWdbeVOppack.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWdbeVOppack
 ******************************************************************************/

uint VecWdbeVOppack::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "wdbecplmst") return WDBECPLMST;
	if (s == "wdbegen") return WDBEGEN;
	if (s == "wdbegenfst") return WDBEGENFST;
	if (s == "wdbemtpcplmstbu") return WDBEMTPCPLMSTBU;
	if (s == "wdbemtpcplmsttd") return WDBEMTPCPLMSTTD;
	if (s == "wdbemtpgenfst") return WDBEMTPGENFST;
	if (s == "wdbemtpplhfpga") return WDBEMTPPLHFPGA;
	if (s == "wdbemtpplhmcu") return WDBEMTPPLHMCU;
	if (s == "wdbemtpwrfpga") return WDBEMTPWRFPGA;
	if (s == "wdbemtpwrmcu") return WDBEMTPWRMCU;
	if (s == "wdbeplhfpga") return WDBEPLHFPGA;
	if (s == "wdbeplhmcu") return WDBEPLHMCU;
	if (s == "wdbeprcfile") return WDBEPRCFILE;
	if (s == "wdbeprctree") return WDBEPRCTREE;
	if (s == "wdbewrdev") return WDBEWRDEV;
	if (s == "wdbewrfpga") return WDBEWRFPGA;
	if (s == "wdbewrmcu") return WDBEWRMCU;

	return(0);
};

string VecWdbeVOppack::getSref(
			const uint ix
		) {
	if (ix == WDBECPLMST) return("WdbeCplmst");
	if (ix == WDBEGEN) return("WdbeGen");
	if (ix == WDBEGENFST) return("WdbeGenfst");
	if (ix == WDBEMTPCPLMSTBU) return("WdbeMtpCplmstbu");
	if (ix == WDBEMTPCPLMSTTD) return("WdbeMtpCplmsttd");
	if (ix == WDBEMTPGENFST) return("WdbeMtpGenfst");
	if (ix == WDBEMTPPLHFPGA) return("WdbeMtpPlhfpga");
	if (ix == WDBEMTPPLHMCU) return("WdbeMtpPlhmcu");
	if (ix == WDBEMTPWRFPGA) return("WdbeMtpWrfpga");
	if (ix == WDBEMTPWRMCU) return("WdbeMtpWrmcu");
	if (ix == WDBEPLHFPGA) return("WdbePlhfpga");
	if (ix == WDBEPLHMCU) return("WdbePlhmcu");
	if (ix == WDBEPRCFILE) return("WdbePrcfile");
	if (ix == WDBEPRCTREE) return("WdbePrctree");
	if (ix == WDBEWRDEV) return("WdbeWrdev");
	if (ix == WDBEWRFPGA) return("WdbeWrfpga");
	if (ix == WDBEWRMCU) return("WdbeWrmcu");

	return("");
};

string VecWdbeVOppack::getTitle(
			const uint ix
		) {
	if (ix == WDBECPLMST) return("complement modular structure");
	if (ix == WDBEGEN) return("generate");
	if (ix == WDBEGENFST) return("generate fine structure");
	if (ix == WDBEMTPCPLMSTBU) return("complement module template-specific modular structure bottom-up");
	if (ix == WDBEMTPCPLMSTTD) return("complement module template-specific modular structure top-down");
	if (ix == WDBEMTPGENFST) return("generate module template-specific fine structure");
	if (ix == WDBEMTPPLHFPGA) return("fill module template-specific FPGA code placeholders");
	if (ix == WDBEMTPPLHMCU) return("fill module template-specific MCU code placeholders");
	if (ix == WDBEMTPWRFPGA) return("write module template-specific FPGA code");
	if (ix == WDBEMTPWRMCU) return("write module template-specific MCU code");
	if (ix == WDBEPLHFPGA) return("fill FPGA code placeholders");
	if (ix == WDBEPLHMCU) return("fill MCU code placeholders");
	if (ix == WDBEPRCFILE) return("process file");
	if (ix == WDBEPRCTREE) return("process file tree");
	if (ix == WDBEWRDEV) return("write device access library code");
	if (ix == WDBEWRFPGA) return("write FPGA code");
	if (ix == WDBEWRMCU) return("write MCU code");
	return(getSref(ix));

	return("");
};

string VecWdbeVOppack::getComment(
			const uint ix
		) {

	return("");
};

void VecWdbeVOppack::appendToFeed(
			const uint ix
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix));
};

void VecWdbeVOppack::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 17; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};
