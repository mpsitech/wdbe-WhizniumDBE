/**
	* \file PnlWdbeSilRec_blks.cpp
	* job handler for job PnlWdbeSilRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeSilRec::VecVDo
 ******************************************************************************/

uint PnlWdbeSilRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWdbeSilRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWdbeSilRec::ContInf
 ******************************************************************************/

PnlWdbeSilRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlWdbeSilRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeSilRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeSilRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeSilRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWdbeSilRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSilRec::StatApp
 ******************************************************************************/

void PnlWdbeSilRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdone1NBank
			, const bool initdoneFwd1NController
			, const bool initdone1NTarget
			, const bool initdone1NPeripheral
			, const bool initdoneSil1NUnit
			, const bool initdoneRef1NCommand
			, const bool initdoneHk1NModule
			, const bool initdoneHk1NVector
			, const bool initdoneRef1NError
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeSilRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeSilRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NBank", initdone1NBank);
		writeBoolAttr(wr, itemtag, "sref", "initdoneFwd1NController", initdoneFwd1NController);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NTarget", initdone1NTarget);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NPeripheral", initdone1NPeripheral);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSil1NUnit", initdoneSil1NUnit);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NCommand", initdoneRef1NCommand);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NModule", initdoneHk1NModule);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHk1NVector", initdoneHk1NVector);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NError", initdoneRef1NError);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSilRec::StatShr
 ******************************************************************************/

PnlWdbeSilRec::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const ubigint jrefDetail
			, const ubigint jref1NBank
			, const ubigint jrefFwd1NController
			, const ubigint jref1NTarget
			, const ubigint jref1NPeripheral
			, const ubigint jrefSil1NUnit
			, const ubigint jrefRef1NCommand
			, const ubigint jrefHk1NModule
			, const ubigint jrefHk1NVector
			, const ubigint jrefRef1NError
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->jrefDetail = jrefDetail;
	this->jref1NBank = jref1NBank;
	this->jrefFwd1NController = jrefFwd1NController;
	this->jref1NTarget = jref1NTarget;
	this->jref1NPeripheral = jref1NPeripheral;
	this->jrefSil1NUnit = jrefSil1NUnit;
	this->jrefRef1NCommand = jrefRef1NCommand;
	this->jrefHk1NModule = jrefHk1NModule;
	this->jrefHk1NVector = jrefHk1NVector;
	this->jrefRef1NError = jrefRef1NError;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWDBEVEXPSTATE, JREFDETAIL, JREF1NBANK, JREFFWD1NCONTROLLER, JREF1NTARGET, JREF1NPERIPHERAL, JREFSIL1NUNIT, JREFREF1NCOMMAND, JREFHK1NMODULE, JREFHK1NVECTOR, JREFREF1NERROR, BUTREGULARIZEACTIVE};
};

void PnlWdbeSilRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeSilRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeSilRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NBank", Scr::scramble(jref1NBank));
		writeStringAttr(wr, itemtag, "sref", "scrJrefFwd1NController", Scr::scramble(jrefFwd1NController));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NTarget", Scr::scramble(jref1NTarget));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NPeripheral", Scr::scramble(jref1NPeripheral));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSil1NUnit", Scr::scramble(jrefSil1NUnit));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NCommand", Scr::scramble(jrefRef1NCommand));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NModule", Scr::scramble(jrefHk1NModule));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHk1NVector", Scr::scramble(jrefHk1NVector));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NError", Scr::scramble(jrefRef1NError));
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeSilRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jref1NBank == comp->jref1NBank) insert(items, JREF1NBANK);
	if (jrefFwd1NController == comp->jrefFwd1NController) insert(items, JREFFWD1NCONTROLLER);
	if (jref1NTarget == comp->jref1NTarget) insert(items, JREF1NTARGET);
	if (jref1NPeripheral == comp->jref1NPeripheral) insert(items, JREF1NPERIPHERAL);
	if (jrefSil1NUnit == comp->jrefSil1NUnit) insert(items, JREFSIL1NUNIT);
	if (jrefRef1NCommand == comp->jrefRef1NCommand) insert(items, JREFREF1NCOMMAND);
	if (jrefHk1NModule == comp->jrefHk1NModule) insert(items, JREFHK1NMODULE);
	if (jrefHk1NVector == comp->jrefHk1NVector) insert(items, JREFHK1NVECTOR);
	if (jrefRef1NError == comp->jrefRef1NError) insert(items, JREFREF1NERROR);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWdbeSilRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, JREFDETAIL, JREF1NBANK, JREFFWD1NCONTROLLER, JREF1NTARGET, JREF1NPERIPHERAL, JREFSIL1NUNIT, JREFREF1NCOMMAND, JREFHK1NMODULE, JREFHK1NVECTOR, JREFREF1NERROR, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeSilRec::Tag
 ******************************************************************************/

void PnlWdbeSilRec::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeSilRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeSilRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Silicon device");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeSilRec::DpchAppDo
 ******************************************************************************/

PnlWdbeSilRec::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBESILRECDO)
		{
	ixVDo = 0;
};

string PnlWdbeSilRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSilRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeSilRecDo");
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
 class PnlWdbeSilRec::DpchEngData
 ******************************************************************************/

PnlWdbeSilRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBESILRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeSilRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeSilRec::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeSilRec::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeSilRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};



