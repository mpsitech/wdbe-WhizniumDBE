/**
	* \file PnlWdbePrfDaemon.cpp
	* API code for job PnlWdbePrfDaemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

#include "PnlWdbePrfDaemon.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbePrfDaemon::VecVDo
 ******************************************************************************/

uint PnlWdbePrfDaemon::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butregularizeclick") return BUTREGULARIZECLICK;
	if (s == "butminimizeclick") return BUTMINIMIZECLICK;

	return(0);
};

string PnlWdbePrfDaemon::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

	return("");
};

/******************************************************************************
 class PnlWdbePrfDaemon::ContIac
 ******************************************************************************/

PnlWdbePrfDaemon::ContIac::ContIac(
			const string& Txf2
			, const bool Chk3
			, const string& Txf4
			, const string& Txf5
			, const string& Txf6
			, const string& Txf102
			, const bool Chk103
			, const string& Txf104
			, const string& Txf202
			, const string& Txf203
			, const bool Chk204
			, const string& Txf302
			, const string& Txf303
			, const bool Chk304
			, const uint numFPup402
			, const string& Txf403
			, const string& Txf404
			, const string& Txf405
			, const string& Txf406
			, const string& Txf407
			, const string& Txf408
			, const string& Txf502
			, const string& Txf503
			, const string& Txf504
			, const string& Txf505
			, const string& Txf506
			, const string& Txf507
			, const string& Txf602
			, const string& Txf603
			, const string& Txf702
			, const string& Txf703
			, const string& Txf704
			, const string& Txf705
			, const uint numFPup706
			, const string& Txf707
			, const string& Txf708
			, const string& Txf709
			, const string& Txf710
		) :
			Block()
			, Txf2(Txf2)
			, Chk3(Chk3)
			, Txf4(Txf4)
			, Txf5(Txf5)
			, Txf6(Txf6)
			, Txf102(Txf102)
			, Chk103(Chk103)
			, Txf104(Txf104)
			, Txf202(Txf202)
			, Txf203(Txf203)
			, Chk204(Chk204)
			, Txf302(Txf302)
			, Txf303(Txf303)
			, Chk304(Chk304)
			, numFPup402(numFPup402)
			, Txf403(Txf403)
			, Txf404(Txf404)
			, Txf405(Txf405)
			, Txf406(Txf406)
			, Txf407(Txf407)
			, Txf408(Txf408)
			, Txf502(Txf502)
			, Txf503(Txf503)
			, Txf504(Txf504)
			, Txf505(Txf505)
			, Txf506(Txf506)
			, Txf507(Txf507)
			, Txf602(Txf602)
			, Txf603(Txf603)
			, Txf702(Txf702)
			, Txf703(Txf703)
			, Txf704(Txf704)
			, Txf705(Txf705)
			, numFPup706(numFPup706)
			, Txf707(Txf707)
			, Txf708(Txf708)
			, Txf709(Txf709)
			, Txf710(Txf710)
		{
	mask = {TXF2, CHK3, TXF4, TXF5, TXF6, TXF102, CHK103, TXF104, TXF202, TXF203, CHK204, TXF302, TXF303, CHK304, NUMFPUP402, TXF403, TXF404, TXF405, TXF406, TXF407, TXF408, TXF502, TXF503, TXF504, TXF505, TXF506, TXF507, TXF602, TXF603, TXF702, TXF703, TXF704, TXF705, NUMFPUP706, TXF707, TXF708, TXF709, TXF710};
};

bool PnlWdbePrfDaemon::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacWdbePrfDaemon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacWdbePrfDaemon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf2", Txf2)) add(TXF2);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Chk3", Chk3)) add(CHK3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf4", Txf4)) add(TXF4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf5", Txf5)) add(TXF5);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf6", Txf6)) add(TXF6);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf102", Txf102)) add(TXF102);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Chk103", Chk103)) add(CHK103);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf104", Txf104)) add(TXF104);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf202", Txf202)) add(TXF202);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf203", Txf203)) add(TXF203);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Chk204", Chk204)) add(CHK204);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf302", Txf302)) add(TXF302);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf303", Txf303)) add(TXF303);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Chk304", Chk304)) add(CHK304);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPup402", numFPup402)) add(NUMFPUP402);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf403", Txf403)) add(TXF403);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf404", Txf404)) add(TXF404);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf405", Txf405)) add(TXF405);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf406", Txf406)) add(TXF406);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf407", Txf407)) add(TXF407);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf408", Txf408)) add(TXF408);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf502", Txf502)) add(TXF502);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf503", Txf503)) add(TXF503);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf504", Txf504)) add(TXF504);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf505", Txf505)) add(TXF505);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf506", Txf506)) add(TXF506);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf507", Txf507)) add(TXF507);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf602", Txf602)) add(TXF602);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf603", Txf603)) add(TXF603);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf702", Txf702)) add(TXF702);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf703", Txf703)) add(TXF703);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf704", Txf704)) add(TXF704);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf705", Txf705)) add(TXF705);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPup706", numFPup706)) add(NUMFPUP706);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf707", Txf707)) add(TXF707);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf708", Txf708)) add(TXF708);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf709", Txf709)) add(TXF709);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "Txf710", Txf710)) add(TXF710);
	};

	return basefound;
};

void PnlWdbePrfDaemon::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePrfDaemon";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacWdbePrfDaemon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "Txf2", Txf2);
		writeBoolAttr(wr, itemtag, "sref", "Chk3", Chk3);
		writeStringAttr(wr, itemtag, "sref", "Txf4", Txf4);
		writeStringAttr(wr, itemtag, "sref", "Txf5", Txf5);
		writeStringAttr(wr, itemtag, "sref", "Txf6", Txf6);
		writeStringAttr(wr, itemtag, "sref", "Txf102", Txf102);
		writeBoolAttr(wr, itemtag, "sref", "Chk103", Chk103);
		writeStringAttr(wr, itemtag, "sref", "Txf104", Txf104);
		writeStringAttr(wr, itemtag, "sref", "Txf202", Txf202);
		writeStringAttr(wr, itemtag, "sref", "Txf203", Txf203);
		writeBoolAttr(wr, itemtag, "sref", "Chk204", Chk204);
		writeStringAttr(wr, itemtag, "sref", "Txf302", Txf302);
		writeStringAttr(wr, itemtag, "sref", "Txf303", Txf303);
		writeBoolAttr(wr, itemtag, "sref", "Chk304", Chk304);
		writeUintAttr(wr, itemtag, "sref", "numFPup402", numFPup402);
		writeStringAttr(wr, itemtag, "sref", "Txf403", Txf403);
		writeStringAttr(wr, itemtag, "sref", "Txf404", Txf404);
		writeStringAttr(wr, itemtag, "sref", "Txf405", Txf405);
		writeStringAttr(wr, itemtag, "sref", "Txf406", Txf406);
		writeStringAttr(wr, itemtag, "sref", "Txf407", Txf407);
		writeStringAttr(wr, itemtag, "sref", "Txf408", Txf408);
		writeStringAttr(wr, itemtag, "sref", "Txf502", Txf502);
		writeStringAttr(wr, itemtag, "sref", "Txf503", Txf503);
		writeStringAttr(wr, itemtag, "sref", "Txf504", Txf504);
		writeStringAttr(wr, itemtag, "sref", "Txf505", Txf505);
		writeStringAttr(wr, itemtag, "sref", "Txf506", Txf506);
		writeStringAttr(wr, itemtag, "sref", "Txf507", Txf507);
		writeStringAttr(wr, itemtag, "sref", "Txf602", Txf602);
		writeStringAttr(wr, itemtag, "sref", "Txf603", Txf603);
		writeStringAttr(wr, itemtag, "sref", "Txf702", Txf702);
		writeStringAttr(wr, itemtag, "sref", "Txf703", Txf703);
		writeStringAttr(wr, itemtag, "sref", "Txf704", Txf704);
		writeStringAttr(wr, itemtag, "sref", "Txf705", Txf705);
		writeUintAttr(wr, itemtag, "sref", "numFPup706", numFPup706);
		writeStringAttr(wr, itemtag, "sref", "Txf707", Txf707);
		writeStringAttr(wr, itemtag, "sref", "Txf708", Txf708);
		writeStringAttr(wr, itemtag, "sref", "Txf709", Txf709);
		writeStringAttr(wr, itemtag, "sref", "Txf710", Txf710);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbePrfDaemon::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (Txf2 == comp->Txf2) insert(items, TXF2);
	if (Chk3 == comp->Chk3) insert(items, CHK3);
	if (Txf4 == comp->Txf4) insert(items, TXF4);
	if (Txf5 == comp->Txf5) insert(items, TXF5);
	if (Txf6 == comp->Txf6) insert(items, TXF6);
	if (Txf102 == comp->Txf102) insert(items, TXF102);
	if (Chk103 == comp->Chk103) insert(items, CHK103);
	if (Txf104 == comp->Txf104) insert(items, TXF104);
	if (Txf202 == comp->Txf202) insert(items, TXF202);
	if (Txf203 == comp->Txf203) insert(items, TXF203);
	if (Chk204 == comp->Chk204) insert(items, CHK204);
	if (Txf302 == comp->Txf302) insert(items, TXF302);
	if (Txf303 == comp->Txf303) insert(items, TXF303);
	if (Chk304 == comp->Chk304) insert(items, CHK304);
	if (numFPup402 == comp->numFPup402) insert(items, NUMFPUP402);
	if (Txf403 == comp->Txf403) insert(items, TXF403);
	if (Txf404 == comp->Txf404) insert(items, TXF404);
	if (Txf405 == comp->Txf405) insert(items, TXF405);
	if (Txf406 == comp->Txf406) insert(items, TXF406);
	if (Txf407 == comp->Txf407) insert(items, TXF407);
	if (Txf408 == comp->Txf408) insert(items, TXF408);
	if (Txf502 == comp->Txf502) insert(items, TXF502);
	if (Txf503 == comp->Txf503) insert(items, TXF503);
	if (Txf504 == comp->Txf504) insert(items, TXF504);
	if (Txf505 == comp->Txf505) insert(items, TXF505);
	if (Txf506 == comp->Txf506) insert(items, TXF506);
	if (Txf507 == comp->Txf507) insert(items, TXF507);
	if (Txf602 == comp->Txf602) insert(items, TXF602);
	if (Txf603 == comp->Txf603) insert(items, TXF603);
	if (Txf702 == comp->Txf702) insert(items, TXF702);
	if (Txf703 == comp->Txf703) insert(items, TXF703);
	if (Txf704 == comp->Txf704) insert(items, TXF704);
	if (Txf705 == comp->Txf705) insert(items, TXF705);
	if (numFPup706 == comp->numFPup706) insert(items, NUMFPUP706);
	if (Txf707 == comp->Txf707) insert(items, TXF707);
	if (Txf708 == comp->Txf708) insert(items, TXF708);
	if (Txf709 == comp->Txf709) insert(items, TXF709);
	if (Txf710 == comp->Txf710) insert(items, TXF710);

	return(items);
};

set<uint> PnlWdbePrfDaemon::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXF2, CHK3, TXF4, TXF5, TXF6, TXF102, CHK103, TXF104, TXF202, TXF203, CHK204, TXF302, TXF303, CHK304, NUMFPUP402, TXF403, TXF404, TXF405, TXF406, TXF407, TXF408, TXF502, TXF503, TXF504, TXF505, TXF506, TXF507, TXF602, TXF603, TXF702, TXF703, TXF704, TXF705, NUMFPUP706, TXF707, TXF708, TXF709, TXF710};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrfDaemon::StatShr
 ******************************************************************************/

PnlWdbePrfDaemon::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const bool Txf2Clean
			, const bool Chk3Clean
			, const bool Txf4Clean
			, const bool Txf5Clean
			, const bool Txf6Clean
			, const bool Txf102Clean
			, const bool Chk103Clean
			, const bool Txf104Clean
			, const bool Sep2Avail
			, const bool Hdg201Avail
			, const bool Txf202Avail
			, const bool Txf202Clean
			, const bool Txf203Avail
			, const bool Txf203Clean
			, const bool Chk204Avail
			, const bool Chk204Clean
			, const bool Sep3Avail
			, const bool Hdg301Avail
			, const bool Txf302Avail
			, const bool Txf302Clean
			, const bool Txf303Avail
			, const bool Txf303Clean
			, const bool Chk304Avail
			, const bool Chk304Clean
			, const bool Pup402Clean
			, const bool Txf403Clean
			, const bool Txf404Clean
			, const bool Txf405Clean
			, const bool Txf406Clean
			, const bool Txf407Clean
			, const bool Txf408Clean
			, const bool Txf502Clean
			, const bool Txf503Clean
			, const bool Txf504Clean
			, const bool Txf505Clean
			, const bool Txf506Clean
			, const bool Txf507Clean
			, const bool Txf602Clean
			, const bool Txf603Clean
			, const bool Txf702Clean
			, const bool Txf703Clean
			, const bool Txf704Clean
			, const bool Txf705Clean
			, const bool Pup706Clean
			, const bool Txf707Clean
			, const bool Txf708Clean
			, const bool Txf709Clean
			, const bool Txf710Clean
		) :
			Block()
			, ixWdbeVExpstate(ixWdbeVExpstate)
			, Txf2Clean(Txf2Clean)
			, Chk3Clean(Chk3Clean)
			, Txf4Clean(Txf4Clean)
			, Txf5Clean(Txf5Clean)
			, Txf6Clean(Txf6Clean)
			, Txf102Clean(Txf102Clean)
			, Chk103Clean(Chk103Clean)
			, Txf104Clean(Txf104Clean)
			, Sep2Avail(Sep2Avail)
			, Hdg201Avail(Hdg201Avail)
			, Txf202Avail(Txf202Avail)
			, Txf202Clean(Txf202Clean)
			, Txf203Avail(Txf203Avail)
			, Txf203Clean(Txf203Clean)
			, Chk204Avail(Chk204Avail)
			, Chk204Clean(Chk204Clean)
			, Sep3Avail(Sep3Avail)
			, Hdg301Avail(Hdg301Avail)
			, Txf302Avail(Txf302Avail)
			, Txf302Clean(Txf302Clean)
			, Txf303Avail(Txf303Avail)
			, Txf303Clean(Txf303Clean)
			, Chk304Avail(Chk304Avail)
			, Chk304Clean(Chk304Clean)
			, Pup402Clean(Pup402Clean)
			, Txf403Clean(Txf403Clean)
			, Txf404Clean(Txf404Clean)
			, Txf405Clean(Txf405Clean)
			, Txf406Clean(Txf406Clean)
			, Txf407Clean(Txf407Clean)
			, Txf408Clean(Txf408Clean)
			, Txf502Clean(Txf502Clean)
			, Txf503Clean(Txf503Clean)
			, Txf504Clean(Txf504Clean)
			, Txf505Clean(Txf505Clean)
			, Txf506Clean(Txf506Clean)
			, Txf507Clean(Txf507Clean)
			, Txf602Clean(Txf602Clean)
			, Txf603Clean(Txf603Clean)
			, Txf702Clean(Txf702Clean)
			, Txf703Clean(Txf703Clean)
			, Txf704Clean(Txf704Clean)
			, Txf705Clean(Txf705Clean)
			, Pup706Clean(Pup706Clean)
			, Txf707Clean(Txf707Clean)
			, Txf708Clean(Txf708Clean)
			, Txf709Clean(Txf709Clean)
			, Txf710Clean(Txf710Clean)
		{
	mask = {IXWDBEVEXPSTATE, TXF2CLEAN, CHK3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, TXF102CLEAN, CHK103CLEAN, TXF104CLEAN, SEP2AVAIL, HDG201AVAIL, TXF202AVAIL, TXF202CLEAN, TXF203AVAIL, TXF203CLEAN, CHK204AVAIL, CHK204CLEAN, SEP3AVAIL, HDG301AVAIL, TXF302AVAIL, TXF302CLEAN, TXF303AVAIL, TXF303CLEAN, CHK304AVAIL, CHK304CLEAN, PUP402CLEAN, TXF403CLEAN, TXF404CLEAN, TXF405CLEAN, TXF406CLEAN, TXF407CLEAN, TXF408CLEAN, TXF502CLEAN, TXF503CLEAN, TXF504CLEAN, TXF505CLEAN, TXF506CLEAN, TXF507CLEAN, TXF602CLEAN, TXF603CLEAN, TXF702CLEAN, TXF703CLEAN, TXF704CLEAN, TXF705CLEAN, PUP706CLEAN, TXF707CLEAN, TXF708CLEAN, TXF709CLEAN, TXF710CLEAN};
};

bool PnlWdbePrfDaemon::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbePrfDaemon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbePrfDaemon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf2Clean", Txf2Clean)) add(TXF2CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk3Clean", Chk3Clean)) add(CHK3CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf4Clean", Txf4Clean)) add(TXF4CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf5Clean", Txf5Clean)) add(TXF5CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf6Clean", Txf6Clean)) add(TXF6CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf102Clean", Txf102Clean)) add(TXF102CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk103Clean", Chk103Clean)) add(CHK103CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf104Clean", Txf104Clean)) add(TXF104CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Sep2Avail", Sep2Avail)) add(SEP2AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Hdg201Avail", Hdg201Avail)) add(HDG201AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf202Avail", Txf202Avail)) add(TXF202AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf202Clean", Txf202Clean)) add(TXF202CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf203Avail", Txf203Avail)) add(TXF203AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf203Clean", Txf203Clean)) add(TXF203CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk204Avail", Chk204Avail)) add(CHK204AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk204Clean", Chk204Clean)) add(CHK204CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Sep3Avail", Sep3Avail)) add(SEP3AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Hdg301Avail", Hdg301Avail)) add(HDG301AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf302Avail", Txf302Avail)) add(TXF302AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf302Clean", Txf302Clean)) add(TXF302CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf303Avail", Txf303Avail)) add(TXF303AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf303Clean", Txf303Clean)) add(TXF303CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk304Avail", Chk304Avail)) add(CHK304AVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Chk304Clean", Chk304Clean)) add(CHK304CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Pup402Clean", Pup402Clean)) add(PUP402CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf403Clean", Txf403Clean)) add(TXF403CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf404Clean", Txf404Clean)) add(TXF404CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf405Clean", Txf405Clean)) add(TXF405CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf406Clean", Txf406Clean)) add(TXF406CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf407Clean", Txf407Clean)) add(TXF407CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf408Clean", Txf408Clean)) add(TXF408CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf502Clean", Txf502Clean)) add(TXF502CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf503Clean", Txf503Clean)) add(TXF503CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf504Clean", Txf504Clean)) add(TXF504CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf505Clean", Txf505Clean)) add(TXF505CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf506Clean", Txf506Clean)) add(TXF506CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf507Clean", Txf507Clean)) add(TXF507CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf602Clean", Txf602Clean)) add(TXF602CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf603Clean", Txf603Clean)) add(TXF603CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf702Clean", Txf702Clean)) add(TXF702CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf703Clean", Txf703Clean)) add(TXF703CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf704Clean", Txf704Clean)) add(TXF704CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf705Clean", Txf705Clean)) add(TXF705CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Pup706Clean", Pup706Clean)) add(PUP706CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf707Clean", Txf707Clean)) add(TXF707CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf708Clean", Txf708Clean)) add(TXF708CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf709Clean", Txf709Clean)) add(TXF709CLEAN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "Txf710Clean", Txf710Clean)) add(TXF710CLEAN);
	};

	return basefound;
};

set<uint> PnlWdbePrfDaemon::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (Txf2Clean == comp->Txf2Clean) insert(items, TXF2CLEAN);
	if (Chk3Clean == comp->Chk3Clean) insert(items, CHK3CLEAN);
	if (Txf4Clean == comp->Txf4Clean) insert(items, TXF4CLEAN);
	if (Txf5Clean == comp->Txf5Clean) insert(items, TXF5CLEAN);
	if (Txf6Clean == comp->Txf6Clean) insert(items, TXF6CLEAN);
	if (Txf102Clean == comp->Txf102Clean) insert(items, TXF102CLEAN);
	if (Chk103Clean == comp->Chk103Clean) insert(items, CHK103CLEAN);
	if (Txf104Clean == comp->Txf104Clean) insert(items, TXF104CLEAN);
	if (Sep2Avail == comp->Sep2Avail) insert(items, SEP2AVAIL);
	if (Hdg201Avail == comp->Hdg201Avail) insert(items, HDG201AVAIL);
	if (Txf202Avail == comp->Txf202Avail) insert(items, TXF202AVAIL);
	if (Txf202Clean == comp->Txf202Clean) insert(items, TXF202CLEAN);
	if (Txf203Avail == comp->Txf203Avail) insert(items, TXF203AVAIL);
	if (Txf203Clean == comp->Txf203Clean) insert(items, TXF203CLEAN);
	if (Chk204Avail == comp->Chk204Avail) insert(items, CHK204AVAIL);
	if (Chk204Clean == comp->Chk204Clean) insert(items, CHK204CLEAN);
	if (Sep3Avail == comp->Sep3Avail) insert(items, SEP3AVAIL);
	if (Hdg301Avail == comp->Hdg301Avail) insert(items, HDG301AVAIL);
	if (Txf302Avail == comp->Txf302Avail) insert(items, TXF302AVAIL);
	if (Txf302Clean == comp->Txf302Clean) insert(items, TXF302CLEAN);
	if (Txf303Avail == comp->Txf303Avail) insert(items, TXF303AVAIL);
	if (Txf303Clean == comp->Txf303Clean) insert(items, TXF303CLEAN);
	if (Chk304Avail == comp->Chk304Avail) insert(items, CHK304AVAIL);
	if (Chk304Clean == comp->Chk304Clean) insert(items, CHK304CLEAN);
	if (Pup402Clean == comp->Pup402Clean) insert(items, PUP402CLEAN);
	if (Txf403Clean == comp->Txf403Clean) insert(items, TXF403CLEAN);
	if (Txf404Clean == comp->Txf404Clean) insert(items, TXF404CLEAN);
	if (Txf405Clean == comp->Txf405Clean) insert(items, TXF405CLEAN);
	if (Txf406Clean == comp->Txf406Clean) insert(items, TXF406CLEAN);
	if (Txf407Clean == comp->Txf407Clean) insert(items, TXF407CLEAN);
	if (Txf408Clean == comp->Txf408Clean) insert(items, TXF408CLEAN);
	if (Txf502Clean == comp->Txf502Clean) insert(items, TXF502CLEAN);
	if (Txf503Clean == comp->Txf503Clean) insert(items, TXF503CLEAN);
	if (Txf504Clean == comp->Txf504Clean) insert(items, TXF504CLEAN);
	if (Txf505Clean == comp->Txf505Clean) insert(items, TXF505CLEAN);
	if (Txf506Clean == comp->Txf506Clean) insert(items, TXF506CLEAN);
	if (Txf507Clean == comp->Txf507Clean) insert(items, TXF507CLEAN);
	if (Txf602Clean == comp->Txf602Clean) insert(items, TXF602CLEAN);
	if (Txf603Clean == comp->Txf603Clean) insert(items, TXF603CLEAN);
	if (Txf702Clean == comp->Txf702Clean) insert(items, TXF702CLEAN);
	if (Txf703Clean == comp->Txf703Clean) insert(items, TXF703CLEAN);
	if (Txf704Clean == comp->Txf704Clean) insert(items, TXF704CLEAN);
	if (Txf705Clean == comp->Txf705Clean) insert(items, TXF705CLEAN);
	if (Pup706Clean == comp->Pup706Clean) insert(items, PUP706CLEAN);
	if (Txf707Clean == comp->Txf707Clean) insert(items, TXF707CLEAN);
	if (Txf708Clean == comp->Txf708Clean) insert(items, TXF708CLEAN);
	if (Txf709Clean == comp->Txf709Clean) insert(items, TXF709CLEAN);
	if (Txf710Clean == comp->Txf710Clean) insert(items, TXF710CLEAN);

	return(items);
};

set<uint> PnlWdbePrfDaemon::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, TXF2CLEAN, CHK3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, TXF102CLEAN, CHK103CLEAN, TXF104CLEAN, SEP2AVAIL, HDG201AVAIL, TXF202AVAIL, TXF202CLEAN, TXF203AVAIL, TXF203CLEAN, CHK204AVAIL, CHK204CLEAN, SEP3AVAIL, HDG301AVAIL, TXF302AVAIL, TXF302CLEAN, TXF303AVAIL, TXF303CLEAN, CHK304AVAIL, CHK304CLEAN, PUP402CLEAN, TXF403CLEAN, TXF404CLEAN, TXF405CLEAN, TXF406CLEAN, TXF407CLEAN, TXF408CLEAN, TXF502CLEAN, TXF503CLEAN, TXF504CLEAN, TXF505CLEAN, TXF506CLEAN, TXF507CLEAN, TXF602CLEAN, TXF603CLEAN, TXF702CLEAN, TXF703CLEAN, TXF704CLEAN, TXF705CLEAN, PUP706CLEAN, TXF707CLEAN, TXF708CLEAN, TXF709CLEAN, TXF710CLEAN};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbePrfDaemon::Tag
 ******************************************************************************/

PnlWdbePrfDaemon::Tag::Tag(
			const string& Cpt
			, const string& Hdg1
			, const string& Cpt2
			, const string& Cpt3
			, const string& Cpt4
			, const string& Cpt5
			, const string& Cpt6
			, const string& Hdg101
			, const string& Cpt102
			, const string& Cpt103
			, const string& Cpt104
			, const string& Hdg201
			, const string& Cpt202
			, const string& Cpt203
			, const string& Cpt204
			, const string& Hdg301
			, const string& Cpt302
			, const string& Cpt303
			, const string& Cpt304
			, const string& Hdg401
			, const string& Cpt402
			, const string& Cpt403
			, const string& Cpt404
			, const string& Cpt405
			, const string& Cpt406
			, const string& Cpt407
			, const string& Cpt408
			, const string& Hdg501
			, const string& Cpt502
			, const string& Cpt503
			, const string& Cpt504
			, const string& Cpt505
			, const string& Cpt506
			, const string& Cpt507
			, const string& Hdg601
			, const string& Cpt602
			, const string& Cpt603
			, const string& Hdg701
			, const string& Cpt702
			, const string& Cpt703
			, const string& Cpt704
			, const string& Cpt705
			, const string& Cpt706
			, const string& Cpt707
			, const string& Cpt708
			, const string& Cpt709
			, const string& Cpt710
		) :
			Block()
			, Cpt(Cpt)
			, Hdg1(Hdg1)
			, Cpt2(Cpt2)
			, Cpt3(Cpt3)
			, Cpt4(Cpt4)
			, Cpt5(Cpt5)
			, Cpt6(Cpt6)
			, Hdg101(Hdg101)
			, Cpt102(Cpt102)
			, Cpt103(Cpt103)
			, Cpt104(Cpt104)
			, Hdg201(Hdg201)
			, Cpt202(Cpt202)
			, Cpt203(Cpt203)
			, Cpt204(Cpt204)
			, Hdg301(Hdg301)
			, Cpt302(Cpt302)
			, Cpt303(Cpt303)
			, Cpt304(Cpt304)
			, Hdg401(Hdg401)
			, Cpt402(Cpt402)
			, Cpt403(Cpt403)
			, Cpt404(Cpt404)
			, Cpt405(Cpt405)
			, Cpt406(Cpt406)
			, Cpt407(Cpt407)
			, Cpt408(Cpt408)
			, Hdg501(Hdg501)
			, Cpt502(Cpt502)
			, Cpt503(Cpt503)
			, Cpt504(Cpt504)
			, Cpt505(Cpt505)
			, Cpt506(Cpt506)
			, Cpt507(Cpt507)
			, Hdg601(Hdg601)
			, Cpt602(Cpt602)
			, Cpt603(Cpt603)
			, Hdg701(Hdg701)
			, Cpt702(Cpt702)
			, Cpt703(Cpt703)
			, Cpt704(Cpt704)
			, Cpt705(Cpt705)
			, Cpt706(Cpt706)
			, Cpt707(Cpt707)
			, Cpt708(Cpt708)
			, Cpt709(Cpt709)
			, Cpt710(Cpt710)
		{
	mask = {CPT, HDG1, CPT2, CPT3, CPT4, CPT5, CPT6, HDG101, CPT102, CPT103, CPT104, HDG201, CPT202, CPT203, CPT204, HDG301, CPT302, CPT303, CPT304, HDG401, CPT402, CPT403, CPT404, CPT405, CPT406, CPT407, CPT408, HDG501, CPT502, CPT503, CPT504, CPT505, CPT506, CPT507, HDG601, CPT602, CPT603, HDG701, CPT702, CPT703, CPT704, CPT705, CPT706, CPT707, CPT708, CPT709, CPT710};
};

bool PnlWdbePrfDaemon::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbePrfDaemon");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbePrfDaemon";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg1", Hdg1)) add(HDG1);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt2", Cpt2)) add(CPT2);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt3", Cpt3)) add(CPT3);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt4", Cpt4)) add(CPT4);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt5", Cpt5)) add(CPT5);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt6", Cpt6)) add(CPT6);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg101", Hdg101)) add(HDG101);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt102", Cpt102)) add(CPT102);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt103", Cpt103)) add(CPT103);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt104", Cpt104)) add(CPT104);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg201", Hdg201)) add(HDG201);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt202", Cpt202)) add(CPT202);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt203", Cpt203)) add(CPT203);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt204", Cpt204)) add(CPT204);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg301", Hdg301)) add(HDG301);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt302", Cpt302)) add(CPT302);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt303", Cpt303)) add(CPT303);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt304", Cpt304)) add(CPT304);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg401", Hdg401)) add(HDG401);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt402", Cpt402)) add(CPT402);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt403", Cpt403)) add(CPT403);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt404", Cpt404)) add(CPT404);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt405", Cpt405)) add(CPT405);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt406", Cpt406)) add(CPT406);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt407", Cpt407)) add(CPT407);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt408", Cpt408)) add(CPT408);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg501", Hdg501)) add(HDG501);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt502", Cpt502)) add(CPT502);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt503", Cpt503)) add(CPT503);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt504", Cpt504)) add(CPT504);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt505", Cpt505)) add(CPT505);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt506", Cpt506)) add(CPT506);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt507", Cpt507)) add(CPT507);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg601", Hdg601)) add(HDG601);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt602", Cpt602)) add(CPT602);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt603", Cpt603)) add(CPT603);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Hdg701", Hdg701)) add(HDG701);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt702", Cpt702)) add(CPT702);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt703", Cpt703)) add(CPT703);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt704", Cpt704)) add(CPT704);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt705", Cpt705)) add(CPT705);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt706", Cpt706)) add(CPT706);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt707", Cpt707)) add(CPT707);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt708", Cpt708)) add(CPT708);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt709", Cpt709)) add(CPT709);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt710", Cpt710)) add(CPT710);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbePrfDaemon::DpchAppData
 ******************************************************************************/

PnlWdbePrfDaemon::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRFDAEMONDATA, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlWdbePrfDaemon::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfDaemon::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePrfDaemonData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrfDaemon::DpchAppDo
 ******************************************************************************/

PnlWdbePrfDaemon::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRFDAEMONDO, scrJref)
			, ixVDo(ixVDo)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

};

string PnlWdbePrfDaemon::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfDaemon::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbePrfDaemonDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrfDaemon::DpchEngData
 ******************************************************************************/

PnlWdbePrfDaemon::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRFDAEMONDATA)
		{
	feedFPup402.tag = "FeedFPup402";
	feedFPup706.tag = "FeedFPup706";
};

string PnlWdbePrfDaemon::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFPUP402)) ss.push_back("feedFPup402");
	if (has(FEEDFPUP706)) ss.push_back("feedFPup706");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfDaemon::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbePrfDaemonData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (feedFPup402.readXML(docctx, basexpath, true)) add(FEEDFPUP402);
		if (feedFPup706.readXML(docctx, basexpath, true)) add(FEEDFPUP706);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		feedFPup402.clear();
		feedFPup706.clear();
		statshr = StatShr();
		tag = Tag();
	};
};
