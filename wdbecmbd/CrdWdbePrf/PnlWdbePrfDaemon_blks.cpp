/**
	* \file PnlWdbePrfDaemon_blks.cpp
	* job handler for job PnlWdbePrfDaemon (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

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

bool PnlWdbePrfDaemon::ContIac::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["ContIacWdbePrfDaemon"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("Txf2")) {Txf2 = me["Txf2"].asString(); add(TXF2);};
		if (me.isMember("Chk3")) {Chk3 = me["Chk3"].asBool(); add(CHK3);};
		if (me.isMember("Txf4")) {Txf4 = me["Txf4"].asString(); add(TXF4);};
		if (me.isMember("Txf5")) {Txf5 = me["Txf5"].asString(); add(TXF5);};
		if (me.isMember("Txf6")) {Txf6 = me["Txf6"].asString(); add(TXF6);};
		if (me.isMember("Txf102")) {Txf102 = me["Txf102"].asString(); add(TXF102);};
		if (me.isMember("Chk103")) {Chk103 = me["Chk103"].asBool(); add(CHK103);};
		if (me.isMember("Txf104")) {Txf104 = me["Txf104"].asString(); add(TXF104);};
		if (me.isMember("Txf202")) {Txf202 = me["Txf202"].asString(); add(TXF202);};
		if (me.isMember("Txf203")) {Txf203 = me["Txf203"].asString(); add(TXF203);};
		if (me.isMember("Chk204")) {Chk204 = me["Chk204"].asBool(); add(CHK204);};
		if (me.isMember("Txf302")) {Txf302 = me["Txf302"].asString(); add(TXF302);};
		if (me.isMember("Txf303")) {Txf303 = me["Txf303"].asString(); add(TXF303);};
		if (me.isMember("Chk304")) {Chk304 = me["Chk304"].asBool(); add(CHK304);};
		if (me.isMember("numFPup402")) {numFPup402 = me["numFPup402"].asUInt(); add(NUMFPUP402);};
		if (me.isMember("Txf403")) {Txf403 = me["Txf403"].asString(); add(TXF403);};
		if (me.isMember("Txf404")) {Txf404 = me["Txf404"].asString(); add(TXF404);};
		if (me.isMember("Txf405")) {Txf405 = me["Txf405"].asString(); add(TXF405);};
		if (me.isMember("Txf406")) {Txf406 = me["Txf406"].asString(); add(TXF406);};
		if (me.isMember("Txf407")) {Txf407 = me["Txf407"].asString(); add(TXF407);};
		if (me.isMember("Txf408")) {Txf408 = me["Txf408"].asString(); add(TXF408);};
		if (me.isMember("Txf502")) {Txf502 = me["Txf502"].asString(); add(TXF502);};
		if (me.isMember("Txf503")) {Txf503 = me["Txf503"].asString(); add(TXF503);};
		if (me.isMember("Txf504")) {Txf504 = me["Txf504"].asString(); add(TXF504);};
		if (me.isMember("Txf505")) {Txf505 = me["Txf505"].asString(); add(TXF505);};
		if (me.isMember("Txf506")) {Txf506 = me["Txf506"].asString(); add(TXF506);};
		if (me.isMember("Txf507")) {Txf507 = me["Txf507"].asString(); add(TXF507);};
		if (me.isMember("Txf602")) {Txf602 = me["Txf602"].asString(); add(TXF602);};
		if (me.isMember("Txf603")) {Txf603 = me["Txf603"].asString(); add(TXF603);};
		if (me.isMember("Txf702")) {Txf702 = me["Txf702"].asString(); add(TXF702);};
		if (me.isMember("Txf703")) {Txf703 = me["Txf703"].asString(); add(TXF703);};
		if (me.isMember("Txf704")) {Txf704 = me["Txf704"].asString(); add(TXF704);};
		if (me.isMember("Txf705")) {Txf705 = me["Txf705"].asString(); add(TXF705);};
		if (me.isMember("numFPup706")) {numFPup706 = me["numFPup706"].asUInt(); add(NUMFPUP706);};
		if (me.isMember("Txf707")) {Txf707 = me["Txf707"].asString(); add(TXF707);};
		if (me.isMember("Txf708")) {Txf708 = me["Txf708"].asString(); add(TXF708);};
		if (me.isMember("Txf709")) {Txf709 = me["Txf709"].asString(); add(TXF709);};
		if (me.isMember("Txf710")) {Txf710 = me["Txf710"].asString(); add(TXF710);};
	};

	return basefound;
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

void PnlWdbePrfDaemon::ContIac::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContIacWdbePrfDaemon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["Txf2"] = Txf2;
	me["Chk3"] = Chk3;
	me["Txf4"] = Txf4;
	me["Txf5"] = Txf5;
	me["Txf6"] = Txf6;
	me["Txf102"] = Txf102;
	me["Chk103"] = Chk103;
	me["Txf104"] = Txf104;
	me["Txf202"] = Txf202;
	me["Txf203"] = Txf203;
	me["Chk204"] = Chk204;
	me["Txf302"] = Txf302;
	me["Txf303"] = Txf303;
	me["Chk304"] = Chk304;
	me["numFPup402"] = (Json::Value::UInt) numFPup402;
	me["Txf403"] = Txf403;
	me["Txf404"] = Txf404;
	me["Txf405"] = Txf405;
	me["Txf406"] = Txf406;
	me["Txf407"] = Txf407;
	me["Txf408"] = Txf408;
	me["Txf502"] = Txf502;
	me["Txf503"] = Txf503;
	me["Txf504"] = Txf504;
	me["Txf505"] = Txf505;
	me["Txf506"] = Txf506;
	me["Txf507"] = Txf507;
	me["Txf602"] = Txf602;
	me["Txf603"] = Txf603;
	me["Txf702"] = Txf702;
	me["Txf703"] = Txf703;
	me["Txf704"] = Txf704;
	me["Txf705"] = Txf705;
	me["numFPup706"] = (Json::Value::UInt) numFPup706;
	me["Txf707"] = Txf707;
	me["Txf708"] = Txf708;
	me["Txf709"] = Txf709;
	me["Txf710"] = Txf710;
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

void PnlWdbePrfDaemon::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePrfDaemon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["Txf2Clean"] = Txf2Clean;
	me["Chk3Clean"] = Chk3Clean;
	me["Txf4Clean"] = Txf4Clean;
	me["Txf5Clean"] = Txf5Clean;
	me["Txf6Clean"] = Txf6Clean;
	me["Txf102Clean"] = Txf102Clean;
	me["Chk103Clean"] = Chk103Clean;
	me["Txf104Clean"] = Txf104Clean;
	me["Sep2Avail"] = Sep2Avail;
	me["Hdg201Avail"] = Hdg201Avail;
	me["Txf202Avail"] = Txf202Avail;
	me["Txf202Clean"] = Txf202Clean;
	me["Txf203Avail"] = Txf203Avail;
	me["Txf203Clean"] = Txf203Clean;
	me["Chk204Avail"] = Chk204Avail;
	me["Chk204Clean"] = Chk204Clean;
	me["Sep3Avail"] = Sep3Avail;
	me["Hdg301Avail"] = Hdg301Avail;
	me["Txf302Avail"] = Txf302Avail;
	me["Txf302Clean"] = Txf302Clean;
	me["Txf303Avail"] = Txf303Avail;
	me["Txf303Clean"] = Txf303Clean;
	me["Chk304Avail"] = Chk304Avail;
	me["Chk304Clean"] = Chk304Clean;
	me["Pup402Clean"] = Pup402Clean;
	me["Txf403Clean"] = Txf403Clean;
	me["Txf404Clean"] = Txf404Clean;
	me["Txf405Clean"] = Txf405Clean;
	me["Txf406Clean"] = Txf406Clean;
	me["Txf407Clean"] = Txf407Clean;
	me["Txf408Clean"] = Txf408Clean;
	me["Txf502Clean"] = Txf502Clean;
	me["Txf503Clean"] = Txf503Clean;
	me["Txf504Clean"] = Txf504Clean;
	me["Txf505Clean"] = Txf505Clean;
	me["Txf506Clean"] = Txf506Clean;
	me["Txf507Clean"] = Txf507Clean;
	me["Txf602Clean"] = Txf602Clean;
	me["Txf603Clean"] = Txf603Clean;
	me["Txf702Clean"] = Txf702Clean;
	me["Txf703Clean"] = Txf703Clean;
	me["Txf704Clean"] = Txf704Clean;
	me["Txf705Clean"] = Txf705Clean;
	me["Pup706Clean"] = Pup706Clean;
	me["Txf707Clean"] = Txf707Clean;
	me["Txf708Clean"] = Txf708Clean;
	me["Txf709Clean"] = Txf709Clean;
	me["Txf710Clean"] = Txf710Clean;
};

void PnlWdbePrfDaemon::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbePrfDaemon";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbePrfDaemon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "Txf2Clean", Txf2Clean);
		writeBoolAttr(wr, itemtag, "sref", "Chk3Clean", Chk3Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf4Clean", Txf4Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf5Clean", Txf5Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf6Clean", Txf6Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf102Clean", Txf102Clean);
		writeBoolAttr(wr, itemtag, "sref", "Chk103Clean", Chk103Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf104Clean", Txf104Clean);
		writeBoolAttr(wr, itemtag, "sref", "Sep2Avail", Sep2Avail);
		writeBoolAttr(wr, itemtag, "sref", "Hdg201Avail", Hdg201Avail);
		writeBoolAttr(wr, itemtag, "sref", "Txf202Avail", Txf202Avail);
		writeBoolAttr(wr, itemtag, "sref", "Txf202Clean", Txf202Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf203Avail", Txf203Avail);
		writeBoolAttr(wr, itemtag, "sref", "Txf203Clean", Txf203Clean);
		writeBoolAttr(wr, itemtag, "sref", "Chk204Avail", Chk204Avail);
		writeBoolAttr(wr, itemtag, "sref", "Chk204Clean", Chk204Clean);
		writeBoolAttr(wr, itemtag, "sref", "Sep3Avail", Sep3Avail);
		writeBoolAttr(wr, itemtag, "sref", "Hdg301Avail", Hdg301Avail);
		writeBoolAttr(wr, itemtag, "sref", "Txf302Avail", Txf302Avail);
		writeBoolAttr(wr, itemtag, "sref", "Txf302Clean", Txf302Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf303Avail", Txf303Avail);
		writeBoolAttr(wr, itemtag, "sref", "Txf303Clean", Txf303Clean);
		writeBoolAttr(wr, itemtag, "sref", "Chk304Avail", Chk304Avail);
		writeBoolAttr(wr, itemtag, "sref", "Chk304Clean", Chk304Clean);
		writeBoolAttr(wr, itemtag, "sref", "Pup402Clean", Pup402Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf403Clean", Txf403Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf404Clean", Txf404Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf405Clean", Txf405Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf406Clean", Txf406Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf407Clean", Txf407Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf408Clean", Txf408Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf502Clean", Txf502Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf503Clean", Txf503Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf504Clean", Txf504Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf505Clean", Txf505Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf506Clean", Txf506Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf507Clean", Txf507Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf602Clean", Txf602Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf603Clean", Txf603Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf702Clean", Txf702Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf703Clean", Txf703Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf704Clean", Txf704Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf705Clean", Txf705Clean);
		writeBoolAttr(wr, itemtag, "sref", "Pup706Clean", Pup706Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf707Clean", Txf707Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf708Clean", Txf708Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf709Clean", Txf709Clean);
		writeBoolAttr(wr, itemtag, "sref", "Txf710Clean", Txf710Clean);
	xmlTextWriterEndElement(wr);
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

void PnlWdbePrfDaemon::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbePrfDaemon";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Daemon settings";
		me["Hdg1"] = "Behavior";
		me["Cpt2"] = "histlength";
		me["Cpt3"] = "suspsess";
		me["Cpt4"] = "sesstterm";
		me["Cpt5"] = "sesstwarn";
		me["Cpt6"] = "roottterm";
		me["Hdg101"] = "Application server";
		me["Cpt102"] = "port";
		me["Cpt103"] = "https";
		me["Cpt104"] = "cors";
		me["Hdg201"] = "Daemon";
		me["Cpt202"] = "jobprcn";
		me["Cpt203"] = "opengsrvport";
		me["Cpt204"] = "appsrv";
		me["Hdg301"] = "Combined daemon";
		me["Cpt302"] = "jobprcn";
		me["Cpt303"] = "opprcn";
		me["Cpt304"] = "appsrv";
		me["Hdg401"] = "Database";
		me["Cpt402"] = "ixDbsVDbstype";
		me["Cpt403"] = "dbspath";
		me["Cpt404"] = "dbsname";
		me["Cpt405"] = "username";
		me["Cpt406"] = "password";
		me["Cpt407"] = "ip";
		me["Cpt408"] = "port";
		me["Hdg501"] = "Paths";
		me["Cpt502"] = "acvpath";
		me["Cpt503"] = "keypath";
		me["Cpt504"] = "monpath";
		me["Cpt505"] = "tmppath";
		me["Cpt506"] = "webpath";
		me["Cpt507"] = "helpurl";
		me["Hdg601"] = "Tenant";
		me["Cpt602"] = "orgname";
		me["Cpt603"] = "orgweb";
		me["Hdg701"] = "Monitoring";
		me["Cpt702"] = "username";
		me["Cpt703"] = "password";
		me["Cpt704"] = "ip";
		me["Cpt705"] = "port";
		me["Cpt706"] = "ixDbsVDbstype";
		me["Cpt707"] = "dbspath";
		me["Cpt708"] = "dbsname";
		me["Cpt709"] = "dbsusername";
		me["Cpt710"] = "dbspassword";
	};
};

void PnlWdbePrfDaemon::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbePrfDaemon";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbePrfDaemon";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Daemon settings");
			writeStringAttr(wr, itemtag, "sref", "Hdg1", "Behavior");
			writeStringAttr(wr, itemtag, "sref", "Cpt2", "histlength");
			writeStringAttr(wr, itemtag, "sref", "Cpt3", "suspsess");
			writeStringAttr(wr, itemtag, "sref", "Cpt4", "sesstterm");
			writeStringAttr(wr, itemtag, "sref", "Cpt5", "sesstwarn");
			writeStringAttr(wr, itemtag, "sref", "Cpt6", "roottterm");
			writeStringAttr(wr, itemtag, "sref", "Hdg101", "Application server");
			writeStringAttr(wr, itemtag, "sref", "Cpt102", "port");
			writeStringAttr(wr, itemtag, "sref", "Cpt103", "https");
			writeStringAttr(wr, itemtag, "sref", "Cpt104", "cors");
			writeStringAttr(wr, itemtag, "sref", "Hdg201", "Daemon");
			writeStringAttr(wr, itemtag, "sref", "Cpt202", "jobprcn");
			writeStringAttr(wr, itemtag, "sref", "Cpt203", "opengsrvport");
			writeStringAttr(wr, itemtag, "sref", "Cpt204", "appsrv");
			writeStringAttr(wr, itemtag, "sref", "Hdg301", "Combined daemon");
			writeStringAttr(wr, itemtag, "sref", "Cpt302", "jobprcn");
			writeStringAttr(wr, itemtag, "sref", "Cpt303", "opprcn");
			writeStringAttr(wr, itemtag, "sref", "Cpt304", "appsrv");
			writeStringAttr(wr, itemtag, "sref", "Hdg401", "Database");
			writeStringAttr(wr, itemtag, "sref", "Cpt402", "ixDbsVDbstype");
			writeStringAttr(wr, itemtag, "sref", "Cpt403", "dbspath");
			writeStringAttr(wr, itemtag, "sref", "Cpt404", "dbsname");
			writeStringAttr(wr, itemtag, "sref", "Cpt405", "username");
			writeStringAttr(wr, itemtag, "sref", "Cpt406", "password");
			writeStringAttr(wr, itemtag, "sref", "Cpt407", "ip");
			writeStringAttr(wr, itemtag, "sref", "Cpt408", "port");
			writeStringAttr(wr, itemtag, "sref", "Hdg501", "Paths");
			writeStringAttr(wr, itemtag, "sref", "Cpt502", "acvpath");
			writeStringAttr(wr, itemtag, "sref", "Cpt503", "keypath");
			writeStringAttr(wr, itemtag, "sref", "Cpt504", "monpath");
			writeStringAttr(wr, itemtag, "sref", "Cpt505", "tmppath");
			writeStringAttr(wr, itemtag, "sref", "Cpt506", "webpath");
			writeStringAttr(wr, itemtag, "sref", "Cpt507", "helpurl");
			writeStringAttr(wr, itemtag, "sref", "Hdg601", "Tenant");
			writeStringAttr(wr, itemtag, "sref", "Cpt602", "orgname");
			writeStringAttr(wr, itemtag, "sref", "Cpt603", "orgweb");
			writeStringAttr(wr, itemtag, "sref", "Hdg701", "Monitoring");
			writeStringAttr(wr, itemtag, "sref", "Cpt702", "username");
			writeStringAttr(wr, itemtag, "sref", "Cpt703", "password");
			writeStringAttr(wr, itemtag, "sref", "Cpt704", "ip");
			writeStringAttr(wr, itemtag, "sref", "Cpt705", "port");
			writeStringAttr(wr, itemtag, "sref", "Cpt706", "ixDbsVDbstype");
			writeStringAttr(wr, itemtag, "sref", "Cpt707", "dbspath");
			writeStringAttr(wr, itemtag, "sref", "Cpt708", "dbsname");
			writeStringAttr(wr, itemtag, "sref", "Cpt709", "dbsusername");
			writeStringAttr(wr, itemtag, "sref", "Cpt710", "dbspassword");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbePrfDaemon::DpchAppData
 ******************************************************************************/

PnlWdbePrfDaemon::DpchAppData::DpchAppData() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRFDAEMONDATA)
		{
};

string PnlWdbePrfDaemon::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfDaemon::DpchAppData::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbePrfDaemonData"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (contiac.readJSON(me, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

void PnlWdbePrfDaemon::DpchAppData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePrfDaemonData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlWdbePrfDaemon::DpchAppDo
 ******************************************************************************/

PnlWdbePrfDaemon::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEPRFDAEMONDO)
		{
	ixVDo = 0;
};

string PnlWdbePrfDaemon::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfDaemon::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbePrfDaemonDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
};

void PnlWdbePrfDaemon::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbePrfDaemonDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class PnlWdbePrfDaemon::DpchEngData
 ******************************************************************************/

PnlWdbePrfDaemon::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, Feed* feedFPup402
			, Feed* feedFPup706
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEPRFDAEMONDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, FEEDFPUP402, FEEDFPUP706, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, FEEDFPUP402) && feedFPup402) this->feedFPup402 = *feedFPup402;
	if (find(this->mask, FEEDFPUP706) && feedFPup706) this->feedFPup706 = *feedFPup706;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbePrfDaemon::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(FEEDFPUP402)) ss.push_back("feedFPup402");
	if (has(FEEDFPUP706)) ss.push_back("feedFPup706");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbePrfDaemon::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(FEEDFPUP402)) {feedFPup402 = src->feedFPup402; add(FEEDFPUP402);};
	if (src->has(FEEDFPUP706)) {feedFPup706 = src->feedFPup706; add(FEEDFPUP706);};
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbePrfDaemon::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbePrfDaemonData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTIAC)) contiac.writeJSON(me);
	if (has(FEEDFPUP402)) feedFPup402.writeJSON(me);
	if (has(FEEDFPUP706)) feedFPup706.writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
};

void PnlWdbePrfDaemon::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbePrfDaemonData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(FEEDFPUP402)) feedFPup402.writeXML(wr);
		if (has(FEEDFPUP706)) feedFPup706.writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
