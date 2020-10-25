/**
	* \file VecWdbeVOppack.cpp
	* vector VecWdbeVOppack (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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

	if (s == "wdbemodbsc") return WDBEMODBSC;
	if (s == "wdbemoddet") return WDBEMODDET;
	if (s == "wdbemtpmodbscbu") return WDBEMTPMODBSCBU;
	if (s == "wdbemtpmodbsctd") return WDBEMTPMODBSCTD;
	if (s == "wdbemtpmoddet") return WDBEMTPMODDET;
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
	if (ix == WDBEMODBSC) return("WdbeModbsc");
	if (ix == WDBEMODDET) return("WdbeModdet");
	if (ix == WDBEMTPMODBSCBU) return("WdbeMtpModbscbu");
	if (ix == WDBEMTPMODBSCTD) return("WdbeMtpModbsctd");
	if (ix == WDBEMTPMODDET) return("WdbeMtpModdet");
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
	if (ix == WDBEMODBSC) return("modify basic device/core description");
	if (ix == WDBEMODDET) return("modify detailed device/core description");
	if (ix == WDBEMTPMODBSCBU) return("modify module template-specific basic device description bottom-up");
	if (ix == WDBEMTPMODBSCTD) return("modify module template-specific basic device description top-down");
	if (ix == WDBEMTPMODDET) return("modify module template-specific detailed device description");
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

	for (unsigned int i = 1; i <= 16; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};

