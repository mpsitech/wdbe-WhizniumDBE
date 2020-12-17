/**
	* \file PnlWdbeModRec_blks.cpp
	* job handler for job PnlWdbeModRec (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWdbeModRec::VecVDo
 ******************************************************************************/

uint PnlWdbeModRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWdbeModRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWdbeModRec::ContInf
 ******************************************************************************/

PnlWdbeModRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

void PnlWdbeModRec::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeModRec";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfWdbeModRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtRef", TxtRef);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeModRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWdbeModRec::ContInf::diff(
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
 class PnlWdbeModRec::StatApp
 ******************************************************************************/

void PnlWdbeModRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneKHdltype
			, const bool initdoneAPar
			, const bool initdone1NPeripheral
			, const bool initdoneMdl1NSignal
			, const bool initdone1NProcess
			, const bool initdoneMdl1NPort
			, const bool initdoneCor1NImbuf
			, const bool initdoneMdl1NGeneric
			, const bool initdoneSup1NModule
			, const bool initdoneMge1NSignal
			, const bool initdoneCtrRef1NError
			, const bool initdoneCtrHk1NVector
			, const bool initdoneCtrRef1NCommand
			, const bool initdoneCtrMNCommand
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeModRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppWdbeModRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "initdoneDetail", initdoneDetail);
		writeBoolAttr(wr, itemtag, "sref", "initdoneKHdltype", initdoneKHdltype);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAPar", initdoneAPar);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NPeripheral", initdone1NPeripheral);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMdl1NSignal", initdoneMdl1NSignal);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NProcess", initdone1NProcess);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMdl1NPort", initdoneMdl1NPort);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCor1NImbuf", initdoneCor1NImbuf);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMdl1NGeneric", initdoneMdl1NGeneric);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NModule", initdoneSup1NModule);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMge1NSignal", initdoneMge1NSignal);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCtrRef1NError", initdoneCtrRef1NError);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCtrHk1NVector", initdoneCtrHk1NVector);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCtrRef1NCommand", initdoneCtrRef1NCommand);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCtrMNCommand", initdoneCtrMNCommand);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeModRec::StatShr
 ******************************************************************************/

PnlWdbeModRec::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const ubigint jrefDetail
			, const ubigint jrefKHdltype
			, const ubigint jrefAPar
			, const ubigint jref1NPeripheral
			, const ubigint jrefMdl1NSignal
			, const ubigint jref1NProcess
			, const ubigint jrefMdl1NPort
			, const ubigint jrefCor1NImbuf
			, const ubigint jrefMdl1NGeneric
			, const ubigint jrefSup1NModule
			, const ubigint jrefMge1NSignal
			, const ubigint jrefCtrRef1NError
			, const bool pnlctrref1nerrorAvail
			, const ubigint jrefCtrHk1NVector
			, const bool pnlctrhk1nvectorAvail
			, const ubigint jrefCtrRef1NCommand
			, const bool pnlctrref1ncommandAvail
			, const ubigint jrefCtrMNCommand
			, const bool pnlctrmncommandAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->jrefDetail = jrefDetail;
	this->jrefKHdltype = jrefKHdltype;
	this->jrefAPar = jrefAPar;
	this->jref1NPeripheral = jref1NPeripheral;
	this->jrefMdl1NSignal = jrefMdl1NSignal;
	this->jref1NProcess = jref1NProcess;
	this->jrefMdl1NPort = jrefMdl1NPort;
	this->jrefCor1NImbuf = jrefCor1NImbuf;
	this->jrefMdl1NGeneric = jrefMdl1NGeneric;
	this->jrefSup1NModule = jrefSup1NModule;
	this->jrefMge1NSignal = jrefMge1NSignal;
	this->jrefCtrRef1NError = jrefCtrRef1NError;
	this->pnlctrref1nerrorAvail = pnlctrref1nerrorAvail;
	this->jrefCtrHk1NVector = jrefCtrHk1NVector;
	this->pnlctrhk1nvectorAvail = pnlctrhk1nvectorAvail;
	this->jrefCtrRef1NCommand = jrefCtrRef1NCommand;
	this->pnlctrref1ncommandAvail = pnlctrref1ncommandAvail;
	this->jrefCtrMNCommand = jrefCtrMNCommand;
	this->pnlctrmncommandAvail = pnlctrmncommandAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWDBEVEXPSTATE, JREFDETAIL, JREFKHDLTYPE, JREFAPAR, JREF1NPERIPHERAL, JREFMDL1NSIGNAL, JREF1NPROCESS, JREFMDL1NPORT, JREFCOR1NIMBUF, JREFMDL1NGENERIC, JREFSUP1NMODULE, JREFMGE1NSIGNAL, JREFCTRREF1NERROR, PNLCTRREF1NERRORAVAIL, JREFCTRHK1NVECTOR, PNLCTRHK1NVECTORAVAIL, JREFCTRREF1NCOMMAND, PNLCTRREF1NCOMMANDAVAIL, JREFCTRMNCOMMAND, PNLCTRMNCOMMANDAVAIL, BUTREGULARIZEACTIVE};
};

void PnlWdbeModRec::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeModRec";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrWdbeModRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxWdbeVExpstate", VecWdbeVExpstate::getSref(ixWdbeVExpstate));
		writeStringAttr(wr, itemtag, "sref", "scrJrefDetail", Scr::scramble(jrefDetail));
		writeStringAttr(wr, itemtag, "sref", "scrJrefKHdltype", Scr::scramble(jrefKHdltype));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAPar", Scr::scramble(jrefAPar));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NPeripheral", Scr::scramble(jref1NPeripheral));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMdl1NSignal", Scr::scramble(jrefMdl1NSignal));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NProcess", Scr::scramble(jref1NProcess));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMdl1NPort", Scr::scramble(jrefMdl1NPort));
		writeStringAttr(wr, itemtag, "sref", "scrJrefCor1NImbuf", Scr::scramble(jrefCor1NImbuf));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMdl1NGeneric", Scr::scramble(jrefMdl1NGeneric));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NModule", Scr::scramble(jrefSup1NModule));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMge1NSignal", Scr::scramble(jrefMge1NSignal));
		writeStringAttr(wr, itemtag, "sref", "scrJrefCtrRef1NError", Scr::scramble(jrefCtrRef1NError));
		writeBoolAttr(wr, itemtag, "sref", "pnlctrref1nerrorAvail", pnlctrref1nerrorAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefCtrHk1NVector", Scr::scramble(jrefCtrHk1NVector));
		writeBoolAttr(wr, itemtag, "sref", "pnlctrhk1nvectorAvail", pnlctrhk1nvectorAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefCtrRef1NCommand", Scr::scramble(jrefCtrRef1NCommand));
		writeBoolAttr(wr, itemtag, "sref", "pnlctrref1ncommandAvail", pnlctrref1ncommandAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefCtrMNCommand", Scr::scramble(jrefCtrMNCommand));
		writeBoolAttr(wr, itemtag, "sref", "pnlctrmncommandAvail", pnlctrmncommandAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButRegularizeActive", ButRegularizeActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlWdbeModRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (jrefDetail == comp->jrefDetail) insert(items, JREFDETAIL);
	if (jrefKHdltype == comp->jrefKHdltype) insert(items, JREFKHDLTYPE);
	if (jrefAPar == comp->jrefAPar) insert(items, JREFAPAR);
	if (jref1NPeripheral == comp->jref1NPeripheral) insert(items, JREF1NPERIPHERAL);
	if (jrefMdl1NSignal == comp->jrefMdl1NSignal) insert(items, JREFMDL1NSIGNAL);
	if (jref1NProcess == comp->jref1NProcess) insert(items, JREF1NPROCESS);
	if (jrefMdl1NPort == comp->jrefMdl1NPort) insert(items, JREFMDL1NPORT);
	if (jrefCor1NImbuf == comp->jrefCor1NImbuf) insert(items, JREFCOR1NIMBUF);
	if (jrefMdl1NGeneric == comp->jrefMdl1NGeneric) insert(items, JREFMDL1NGENERIC);
	if (jrefSup1NModule == comp->jrefSup1NModule) insert(items, JREFSUP1NMODULE);
	if (jrefMge1NSignal == comp->jrefMge1NSignal) insert(items, JREFMGE1NSIGNAL);
	if (jrefCtrRef1NError == comp->jrefCtrRef1NError) insert(items, JREFCTRREF1NERROR);
	if (pnlctrref1nerrorAvail == comp->pnlctrref1nerrorAvail) insert(items, PNLCTRREF1NERRORAVAIL);
	if (jrefCtrHk1NVector == comp->jrefCtrHk1NVector) insert(items, JREFCTRHK1NVECTOR);
	if (pnlctrhk1nvectorAvail == comp->pnlctrhk1nvectorAvail) insert(items, PNLCTRHK1NVECTORAVAIL);
	if (jrefCtrRef1NCommand == comp->jrefCtrRef1NCommand) insert(items, JREFCTRREF1NCOMMAND);
	if (pnlctrref1ncommandAvail == comp->pnlctrref1ncommandAvail) insert(items, PNLCTRREF1NCOMMANDAVAIL);
	if (jrefCtrMNCommand == comp->jrefCtrMNCommand) insert(items, JREFCTRMNCOMMAND);
	if (pnlctrmncommandAvail == comp->pnlctrmncommandAvail) insert(items, PNLCTRMNCOMMANDAVAIL);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWdbeModRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWDBEVEXPSTATE, JREFDETAIL, JREFKHDLTYPE, JREFAPAR, JREF1NPERIPHERAL, JREFMDL1NSIGNAL, JREF1NPROCESS, JREFMDL1NPORT, JREFCOR1NIMBUF, JREFMDL1NGENERIC, JREFSUP1NMODULE, JREFMGE1NSIGNAL, JREFCTRREF1NERROR, PNLCTRREF1NERRORAVAIL, JREFCTRHK1NVECTOR, PNLCTRHK1NVECTORAVAIL, JREFCTRREF1NCOMMAND, PNLCTRREF1NCOMMANDAVAIL, JREFCTRMNCOMMAND, PNLCTRMNCOMMANDAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModRec::Tag
 ******************************************************************************/

void PnlWdbeModRec::Tag::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagWdbeModRec";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemWdbeModRec";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "Cpt", "Module");
		};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeModRec::DpchAppDo
 ******************************************************************************/

PnlWdbeModRec::DpchAppDo::DpchAppDo() :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEMODRECDO)
		{
	ixVDo = 0;
};

string PnlWdbeModRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeModRec::DpchAppDo::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppWdbeModRecDo");
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
 class PnlWdbeModRec::DpchEngData
 ******************************************************************************/

PnlWdbeModRec::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, StatShr* statshr
			, const set<uint>& mask
		) :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEMODRECDATA, jref)
		{
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlWdbeModRec::DpchEngData::getSrefsMask() {
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

void PnlWdbeModRec::DpchEngData::merge(
			DpchEngWdbe* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlWdbeModRec::DpchEngData::writeXML(
			const uint ixWdbeVLocale
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngWdbeModRecData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixWdbeVLocale, wr);
	xmlTextWriterEndElement(wr);
};
