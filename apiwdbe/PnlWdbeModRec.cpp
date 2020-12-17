/**
	* \file PnlWdbeModRec.cpp
	* API code for job PnlWdbeModRec (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWdbeModRec.h"

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

bool PnlWdbeModRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWdbeModRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWdbeModRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
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

PnlWdbeModRec::StatApp::StatApp(
			const bool initdoneDetail
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
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneKHdltype = initdoneKHdltype;
	this->initdoneAPar = initdoneAPar;
	this->initdone1NPeripheral = initdone1NPeripheral;
	this->initdoneMdl1NSignal = initdoneMdl1NSignal;
	this->initdone1NProcess = initdone1NProcess;
	this->initdoneMdl1NPort = initdoneMdl1NPort;
	this->initdoneCor1NImbuf = initdoneCor1NImbuf;
	this->initdoneMdl1NGeneric = initdoneMdl1NGeneric;
	this->initdoneSup1NModule = initdoneSup1NModule;
	this->initdoneMge1NSignal = initdoneMge1NSignal;
	this->initdoneCtrRef1NError = initdoneCtrRef1NError;
	this->initdoneCtrHk1NVector = initdoneCtrHk1NVector;
	this->initdoneCtrRef1NCommand = initdoneCtrRef1NCommand;
	this->initdoneCtrMNCommand = initdoneCtrMNCommand;

	mask = {INITDONEDETAIL, INITDONEKHDLTYPE, INITDONEAPAR, INITDONE1NPERIPHERAL, INITDONEMDL1NSIGNAL, INITDONE1NPROCESS, INITDONEMDL1NPORT, INITDONECOR1NIMBUF, INITDONEMDL1NGENERIC, INITDONESUP1NMODULE, INITDONEMGE1NSIGNAL, INITDONECTRREF1NERROR, INITDONECTRHK1NVECTOR, INITDONECTRREF1NCOMMAND, INITDONECTRMNCOMMAND};
};

bool PnlWdbeModRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWdbeModRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWdbeModRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneKHdltype", initdoneKHdltype)) add(INITDONEKHDLTYPE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAPar", initdoneAPar)) add(INITDONEAPAR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NPeripheral", initdone1NPeripheral)) add(INITDONE1NPERIPHERAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMdl1NSignal", initdoneMdl1NSignal)) add(INITDONEMDL1NSIGNAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NProcess", initdone1NProcess)) add(INITDONE1NPROCESS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMdl1NPort", initdoneMdl1NPort)) add(INITDONEMDL1NPORT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneCor1NImbuf", initdoneCor1NImbuf)) add(INITDONECOR1NIMBUF);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMdl1NGeneric", initdoneMdl1NGeneric)) add(INITDONEMDL1NGENERIC);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneSup1NModule", initdoneSup1NModule)) add(INITDONESUP1NMODULE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMge1NSignal", initdoneMge1NSignal)) add(INITDONEMGE1NSIGNAL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneCtrRef1NError", initdoneCtrRef1NError)) add(INITDONECTRREF1NERROR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneCtrHk1NVector", initdoneCtrHk1NVector)) add(INITDONECTRHK1NVECTOR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneCtrRef1NCommand", initdoneCtrRef1NCommand)) add(INITDONECTRREF1NCOMMAND);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneCtrMNCommand", initdoneCtrMNCommand)) add(INITDONECTRMNCOMMAND);
	};

	return basefound;
};

set<uint> PnlWdbeModRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneKHdltype == comp->initdoneKHdltype) insert(items, INITDONEKHDLTYPE);
	if (initdoneAPar == comp->initdoneAPar) insert(items, INITDONEAPAR);
	if (initdone1NPeripheral == comp->initdone1NPeripheral) insert(items, INITDONE1NPERIPHERAL);
	if (initdoneMdl1NSignal == comp->initdoneMdl1NSignal) insert(items, INITDONEMDL1NSIGNAL);
	if (initdone1NProcess == comp->initdone1NProcess) insert(items, INITDONE1NPROCESS);
	if (initdoneMdl1NPort == comp->initdoneMdl1NPort) insert(items, INITDONEMDL1NPORT);
	if (initdoneCor1NImbuf == comp->initdoneCor1NImbuf) insert(items, INITDONECOR1NIMBUF);
	if (initdoneMdl1NGeneric == comp->initdoneMdl1NGeneric) insert(items, INITDONEMDL1NGENERIC);
	if (initdoneSup1NModule == comp->initdoneSup1NModule) insert(items, INITDONESUP1NMODULE);
	if (initdoneMge1NSignal == comp->initdoneMge1NSignal) insert(items, INITDONEMGE1NSIGNAL);
	if (initdoneCtrRef1NError == comp->initdoneCtrRef1NError) insert(items, INITDONECTRREF1NERROR);
	if (initdoneCtrHk1NVector == comp->initdoneCtrHk1NVector) insert(items, INITDONECTRHK1NVECTOR);
	if (initdoneCtrRef1NCommand == comp->initdoneCtrRef1NCommand) insert(items, INITDONECTRREF1NCOMMAND);
	if (initdoneCtrMNCommand == comp->initdoneCtrMNCommand) insert(items, INITDONECTRMNCOMMAND);

	return(items);
};

set<uint> PnlWdbeModRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEKHDLTYPE, INITDONEAPAR, INITDONE1NPERIPHERAL, INITDONEMDL1NSIGNAL, INITDONE1NPROCESS, INITDONEMDL1NPORT, INITDONECOR1NIMBUF, INITDONEMDL1NGENERIC, INITDONESUP1NMODULE, INITDONEMGE1NSIGNAL, INITDONECTRREF1NERROR, INITDONECTRHK1NVECTOR, INITDONECTRREF1NCOMMAND, INITDONECTRMNCOMMAND};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModRec::StatShr
 ******************************************************************************/

PnlWdbeModRec::StatShr::StatShr(
			const uint ixWdbeVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefKHdltype
			, const string& scrJrefAPar
			, const string& scrJref1NPeripheral
			, const string& scrJrefMdl1NSignal
			, const string& scrJref1NProcess
			, const string& scrJrefMdl1NPort
			, const string& scrJrefCor1NImbuf
			, const string& scrJrefMdl1NGeneric
			, const string& scrJrefSup1NModule
			, const string& scrJrefMge1NSignal
			, const string& scrJrefCtrRef1NError
			, const bool pnlctrref1nerrorAvail
			, const string& scrJrefCtrHk1NVector
			, const bool pnlctrhk1nvectorAvail
			, const string& scrJrefCtrRef1NCommand
			, const bool pnlctrref1ncommandAvail
			, const string& scrJrefCtrMNCommand
			, const bool pnlctrmncommandAvail
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWdbeVExpstate = ixWdbeVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefKHdltype = scrJrefKHdltype;
	this->scrJrefAPar = scrJrefAPar;
	this->scrJref1NPeripheral = scrJref1NPeripheral;
	this->scrJrefMdl1NSignal = scrJrefMdl1NSignal;
	this->scrJref1NProcess = scrJref1NProcess;
	this->scrJrefMdl1NPort = scrJrefMdl1NPort;
	this->scrJrefCor1NImbuf = scrJrefCor1NImbuf;
	this->scrJrefMdl1NGeneric = scrJrefMdl1NGeneric;
	this->scrJrefSup1NModule = scrJrefSup1NModule;
	this->scrJrefMge1NSignal = scrJrefMge1NSignal;
	this->scrJrefCtrRef1NError = scrJrefCtrRef1NError;
	this->pnlctrref1nerrorAvail = pnlctrref1nerrorAvail;
	this->scrJrefCtrHk1NVector = scrJrefCtrHk1NVector;
	this->pnlctrhk1nvectorAvail = pnlctrhk1nvectorAvail;
	this->scrJrefCtrRef1NCommand = scrJrefCtrRef1NCommand;
	this->pnlctrref1ncommandAvail = pnlctrref1ncommandAvail;
	this->scrJrefCtrMNCommand = scrJrefCtrMNCommand;
	this->pnlctrmncommandAvail = pnlctrmncommandAvail;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKHDLTYPE, SCRJREFAPAR, SCRJREF1NPERIPHERAL, SCRJREFMDL1NSIGNAL, SCRJREF1NPROCESS, SCRJREFMDL1NPORT, SCRJREFCOR1NIMBUF, SCRJREFMDL1NGENERIC, SCRJREFSUP1NMODULE, SCRJREFMGE1NSIGNAL, SCRJREFCTRREF1NERROR, PNLCTRREF1NERRORAVAIL, SCRJREFCTRHK1NVECTOR, PNLCTRHK1NVECTORAVAIL, SCRJREFCTRREF1NCOMMAND, PNLCTRREF1NCOMMANDAVAIL, SCRJREFCTRMNCOMMAND, PNLCTRMNCOMMANDAVAIL, BUTREGULARIZEACTIVE};
};

bool PnlWdbeModRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWdbeVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWdbeModRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWdbeModRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", srefIxWdbeVExpstate)) {
			ixWdbeVExpstate = VecWdbeVExpstate::getIx(srefIxWdbeVExpstate);
			add(IXWDBEVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefKHdltype", scrJrefKHdltype)) add(SCRJREFKHDLTYPE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAPar", scrJrefAPar)) add(SCRJREFAPAR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NPeripheral", scrJref1NPeripheral)) add(SCRJREF1NPERIPHERAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMdl1NSignal", scrJrefMdl1NSignal)) add(SCRJREFMDL1NSIGNAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NProcess", scrJref1NProcess)) add(SCRJREF1NPROCESS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMdl1NPort", scrJrefMdl1NPort)) add(SCRJREFMDL1NPORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCor1NImbuf", scrJrefCor1NImbuf)) add(SCRJREFCOR1NIMBUF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMdl1NGeneric", scrJrefMdl1NGeneric)) add(SCRJREFMDL1NGENERIC);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSup1NModule", scrJrefSup1NModule)) add(SCRJREFSUP1NMODULE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMge1NSignal", scrJrefMge1NSignal)) add(SCRJREFMGE1NSIGNAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCtrRef1NError", scrJrefCtrRef1NError)) add(SCRJREFCTRREF1NERROR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlctrref1nerrorAvail", pnlctrref1nerrorAvail)) add(PNLCTRREF1NERRORAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCtrHk1NVector", scrJrefCtrHk1NVector)) add(SCRJREFCTRHK1NVECTOR);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlctrhk1nvectorAvail", pnlctrhk1nvectorAvail)) add(PNLCTRHK1NVECTORAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCtrRef1NCommand", scrJrefCtrRef1NCommand)) add(SCRJREFCTRREF1NCOMMAND);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlctrref1ncommandAvail", pnlctrref1ncommandAvail)) add(PNLCTRREF1NCOMMANDAVAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCtrMNCommand", scrJrefCtrMNCommand)) add(SCRJREFCTRMNCOMMAND);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pnlctrmncommandAvail", pnlctrmncommandAvail)) add(PNLCTRMNCOMMANDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWdbeModRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWdbeVExpstate == comp->ixWdbeVExpstate) insert(items, IXWDBEVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefKHdltype == comp->scrJrefKHdltype) insert(items, SCRJREFKHDLTYPE);
	if (scrJrefAPar == comp->scrJrefAPar) insert(items, SCRJREFAPAR);
	if (scrJref1NPeripheral == comp->scrJref1NPeripheral) insert(items, SCRJREF1NPERIPHERAL);
	if (scrJrefMdl1NSignal == comp->scrJrefMdl1NSignal) insert(items, SCRJREFMDL1NSIGNAL);
	if (scrJref1NProcess == comp->scrJref1NProcess) insert(items, SCRJREF1NPROCESS);
	if (scrJrefMdl1NPort == comp->scrJrefMdl1NPort) insert(items, SCRJREFMDL1NPORT);
	if (scrJrefCor1NImbuf == comp->scrJrefCor1NImbuf) insert(items, SCRJREFCOR1NIMBUF);
	if (scrJrefMdl1NGeneric == comp->scrJrefMdl1NGeneric) insert(items, SCRJREFMDL1NGENERIC);
	if (scrJrefSup1NModule == comp->scrJrefSup1NModule) insert(items, SCRJREFSUP1NMODULE);
	if (scrJrefMge1NSignal == comp->scrJrefMge1NSignal) insert(items, SCRJREFMGE1NSIGNAL);
	if (scrJrefCtrRef1NError == comp->scrJrefCtrRef1NError) insert(items, SCRJREFCTRREF1NERROR);
	if (pnlctrref1nerrorAvail == comp->pnlctrref1nerrorAvail) insert(items, PNLCTRREF1NERRORAVAIL);
	if (scrJrefCtrHk1NVector == comp->scrJrefCtrHk1NVector) insert(items, SCRJREFCTRHK1NVECTOR);
	if (pnlctrhk1nvectorAvail == comp->pnlctrhk1nvectorAvail) insert(items, PNLCTRHK1NVECTORAVAIL);
	if (scrJrefCtrRef1NCommand == comp->scrJrefCtrRef1NCommand) insert(items, SCRJREFCTRREF1NCOMMAND);
	if (pnlctrref1ncommandAvail == comp->pnlctrref1ncommandAvail) insert(items, PNLCTRREF1NCOMMANDAVAIL);
	if (scrJrefCtrMNCommand == comp->scrJrefCtrMNCommand) insert(items, SCRJREFCTRMNCOMMAND);
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

	diffitems = {IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKHDLTYPE, SCRJREFAPAR, SCRJREF1NPERIPHERAL, SCRJREFMDL1NSIGNAL, SCRJREF1NPROCESS, SCRJREFMDL1NPORT, SCRJREFCOR1NIMBUF, SCRJREFMDL1NGENERIC, SCRJREFSUP1NMODULE, SCRJREFMGE1NSIGNAL, SCRJREFCTRREF1NERROR, PNLCTRREF1NERRORAVAIL, SCRJREFCTRHK1NVECTOR, PNLCTRHK1NVECTORAVAIL, SCRJREFCTRREF1NCOMMAND, PNLCTRREF1NCOMMANDAVAIL, SCRJREFCTRMNCOMMAND, PNLCTRMNCOMMANDAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModRec::Tag
 ******************************************************************************/

PnlWdbeModRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWdbeModRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWdbeModRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWdbeModRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWdbeModRec::DpchAppDo
 ******************************************************************************/

PnlWdbeModRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWdbe(VecWdbeVDpch::DPCHAPPWDBEMODRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWdbeModRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeModRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWdbeModRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWdbeModRec::DpchEngData
 ******************************************************************************/

PnlWdbeModRec::DpchEngData::DpchEngData() :
			DpchEngWdbe(VecWdbeVDpch::DPCHENGWDBEMODRECDATA)
		{
};

string PnlWdbeModRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWdbeModRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWdbeModRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};
