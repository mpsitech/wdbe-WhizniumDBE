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
			, TxtRef(TxtRef)
		{
	mask = {TXTREF};
};

void PnlWdbeModRec::ContInf::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeModRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtRef"] = TxtRef;
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

void PnlWdbeModRec::StatApp::writeJSON(
			Json::Value& sup
			, string difftag
			, const bool initdoneDetail
			, const bool initdoneKHdltype
			, const bool initdoneAPar
			, const bool initdoneMdl1NGeneric
			, const bool initdoneMdl1NPort
			, const bool initdone1NProcess
			, const bool initdoneHsm1NPipeline
			, const bool initdone1NCdc
			, const bool initdoneSup1NModule
			, const bool initdoneMge1NSignal
			, const bool initdoneRef1NVariable
			, const bool initdoneRef1NSensitivity
			, const bool initdoneRef1NSignal
			, const bool initdoneCtrRef1NCommand
			, const bool initdoneCtrHk1NVector
			, const bool initdoneCtrRef1NError
			, const bool initdoneCtdMNModule
			, const bool initdoneMNPeripheral
			, const bool initdoneCorMNModule
			, const bool initdoneCtrMNCommand
		) {
	if (difftag.length() == 0) difftag = "StatAppWdbeModRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["initdoneDetail"] = initdoneDetail;
	me["initdoneKHdltype"] = initdoneKHdltype;
	me["initdoneAPar"] = initdoneAPar;
	me["initdoneMdl1NGeneric"] = initdoneMdl1NGeneric;
	me["initdoneMdl1NPort"] = initdoneMdl1NPort;
	me["initdone1NProcess"] = initdone1NProcess;
	me["initdoneHsm1NPipeline"] = initdoneHsm1NPipeline;
	me["initdone1NCdc"] = initdone1NCdc;
	me["initdoneSup1NModule"] = initdoneSup1NModule;
	me["initdoneMge1NSignal"] = initdoneMge1NSignal;
	me["initdoneRef1NVariable"] = initdoneRef1NVariable;
	me["initdoneRef1NSensitivity"] = initdoneRef1NSensitivity;
	me["initdoneRef1NSignal"] = initdoneRef1NSignal;
	me["initdoneCtrRef1NCommand"] = initdoneCtrRef1NCommand;
	me["initdoneCtrHk1NVector"] = initdoneCtrHk1NVector;
	me["initdoneCtrRef1NError"] = initdoneCtrRef1NError;
	me["initdoneCtdMNModule"] = initdoneCtdMNModule;
	me["initdoneMNPeripheral"] = initdoneMNPeripheral;
	me["initdoneCorMNModule"] = initdoneCorMNModule;
	me["initdoneCtrMNCommand"] = initdoneCtrMNCommand;
};

void PnlWdbeModRec::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const bool initdoneDetail
			, const bool initdoneKHdltype
			, const bool initdoneAPar
			, const bool initdoneMdl1NGeneric
			, const bool initdoneMdl1NPort
			, const bool initdone1NProcess
			, const bool initdoneHsm1NPipeline
			, const bool initdone1NCdc
			, const bool initdoneSup1NModule
			, const bool initdoneMge1NSignal
			, const bool initdoneRef1NVariable
			, const bool initdoneRef1NSensitivity
			, const bool initdoneRef1NSignal
			, const bool initdoneCtrRef1NCommand
			, const bool initdoneCtrHk1NVector
			, const bool initdoneCtrRef1NError
			, const bool initdoneCtdMNModule
			, const bool initdoneMNPeripheral
			, const bool initdoneCorMNModule
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
		writeBoolAttr(wr, itemtag, "sref", "initdoneMdl1NGeneric", initdoneMdl1NGeneric);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMdl1NPort", initdoneMdl1NPort);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NProcess", initdone1NProcess);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHsm1NPipeline", initdoneHsm1NPipeline);
		writeBoolAttr(wr, itemtag, "sref", "initdone1NCdc", initdone1NCdc);
		writeBoolAttr(wr, itemtag, "sref", "initdoneSup1NModule", initdoneSup1NModule);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMge1NSignal", initdoneMge1NSignal);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NVariable", initdoneRef1NVariable);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NSensitivity", initdoneRef1NSensitivity);
		writeBoolAttr(wr, itemtag, "sref", "initdoneRef1NSignal", initdoneRef1NSignal);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCtrRef1NCommand", initdoneCtrRef1NCommand);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCtrHk1NVector", initdoneCtrHk1NVector);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCtrRef1NError", initdoneCtrRef1NError);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCtdMNModule", initdoneCtdMNModule);
		writeBoolAttr(wr, itemtag, "sref", "initdoneMNPeripheral", initdoneMNPeripheral);
		writeBoolAttr(wr, itemtag, "sref", "initdoneCorMNModule", initdoneCorMNModule);
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
			, const ubigint jrefMdl1NGeneric
			, const ubigint jrefMdl1NPort
			, const ubigint jref1NProcess
			, const ubigint jrefHsm1NPipeline
			, const ubigint jref1NCdc
			, const ubigint jrefSup1NModule
			, const ubigint jrefMge1NSignal
			, const ubigint jrefRef1NVariable
			, const ubigint jrefRef1NSensitivity
			, const ubigint jrefRef1NSignal
			, const ubigint jrefCtrRef1NCommand
			, const bool pnlctrref1ncommandAvail
			, const ubigint jrefCtrHk1NVector
			, const bool pnlctrhk1nvectorAvail
			, const ubigint jrefCtrRef1NError
			, const bool pnlctrref1nerrorAvail
			, const ubigint jrefCtdMNModule
			, const ubigint jrefMNPeripheral
			, const ubigint jrefCorMNModule
			, const ubigint jrefCtrMNCommand
			, const bool pnlctrmncommandAvail
			, const bool ButRegularizeActive
		) :
			Block()
			, ixWdbeVExpstate(ixWdbeVExpstate)
			, jrefDetail(jrefDetail)
			, jrefKHdltype(jrefKHdltype)
			, jrefAPar(jrefAPar)
			, jrefMdl1NGeneric(jrefMdl1NGeneric)
			, jrefMdl1NPort(jrefMdl1NPort)
			, jref1NProcess(jref1NProcess)
			, jrefHsm1NPipeline(jrefHsm1NPipeline)
			, jref1NCdc(jref1NCdc)
			, jrefSup1NModule(jrefSup1NModule)
			, jrefMge1NSignal(jrefMge1NSignal)
			, jrefRef1NVariable(jrefRef1NVariable)
			, jrefRef1NSensitivity(jrefRef1NSensitivity)
			, jrefRef1NSignal(jrefRef1NSignal)
			, jrefCtrRef1NCommand(jrefCtrRef1NCommand)
			, pnlctrref1ncommandAvail(pnlctrref1ncommandAvail)
			, jrefCtrHk1NVector(jrefCtrHk1NVector)
			, pnlctrhk1nvectorAvail(pnlctrhk1nvectorAvail)
			, jrefCtrRef1NError(jrefCtrRef1NError)
			, pnlctrref1nerrorAvail(pnlctrref1nerrorAvail)
			, jrefCtdMNModule(jrefCtdMNModule)
			, jrefMNPeripheral(jrefMNPeripheral)
			, jrefCorMNModule(jrefCorMNModule)
			, jrefCtrMNCommand(jrefCtrMNCommand)
			, pnlctrmncommandAvail(pnlctrmncommandAvail)
			, ButRegularizeActive(ButRegularizeActive)
		{
	mask = {IXWDBEVEXPSTATE, JREFDETAIL, JREFKHDLTYPE, JREFAPAR, JREFMDL1NGENERIC, JREFMDL1NPORT, JREF1NPROCESS, JREFHSM1NPIPELINE, JREF1NCDC, JREFSUP1NMODULE, JREFMGE1NSIGNAL, JREFREF1NVARIABLE, JREFREF1NSENSITIVITY, JREFREF1NSIGNAL, JREFCTRREF1NCOMMAND, PNLCTRREF1NCOMMANDAVAIL, JREFCTRHK1NVECTOR, PNLCTRHK1NVECTORAVAIL, JREFCTRREF1NERROR, PNLCTRREF1NERRORAVAIL, JREFCTDMNMODULE, JREFMNPERIPHERAL, JREFCORMNMODULE, JREFCTRMNCOMMAND, PNLCTRMNCOMMANDAVAIL, BUTREGULARIZEACTIVE};
};

void PnlWdbeModRec::StatShr::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "StatShrWdbeModRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["srefIxWdbeVExpstate"] = VecWdbeVExpstate::getSref(ixWdbeVExpstate);
	me["scrJrefDetail"] = Scr::scramble(jrefDetail);
	me["scrJrefKHdltype"] = Scr::scramble(jrefKHdltype);
	me["scrJrefAPar"] = Scr::scramble(jrefAPar);
	me["scrJrefMdl1NGeneric"] = Scr::scramble(jrefMdl1NGeneric);
	me["scrJrefMdl1NPort"] = Scr::scramble(jrefMdl1NPort);
	me["scrJref1NProcess"] = Scr::scramble(jref1NProcess);
	me["scrJrefHsm1NPipeline"] = Scr::scramble(jrefHsm1NPipeline);
	me["scrJref1NCdc"] = Scr::scramble(jref1NCdc);
	me["scrJrefSup1NModule"] = Scr::scramble(jrefSup1NModule);
	me["scrJrefMge1NSignal"] = Scr::scramble(jrefMge1NSignal);
	me["scrJrefRef1NVariable"] = Scr::scramble(jrefRef1NVariable);
	me["scrJrefRef1NSensitivity"] = Scr::scramble(jrefRef1NSensitivity);
	me["scrJrefRef1NSignal"] = Scr::scramble(jrefRef1NSignal);
	me["scrJrefCtrRef1NCommand"] = Scr::scramble(jrefCtrRef1NCommand);
	me["pnlctrref1ncommandAvail"] = pnlctrref1ncommandAvail;
	me["scrJrefCtrHk1NVector"] = Scr::scramble(jrefCtrHk1NVector);
	me["pnlctrhk1nvectorAvail"] = pnlctrhk1nvectorAvail;
	me["scrJrefCtrRef1NError"] = Scr::scramble(jrefCtrRef1NError);
	me["pnlctrref1nerrorAvail"] = pnlctrref1nerrorAvail;
	me["scrJrefCtdMNModule"] = Scr::scramble(jrefCtdMNModule);
	me["scrJrefMNPeripheral"] = Scr::scramble(jrefMNPeripheral);
	me["scrJrefCorMNModule"] = Scr::scramble(jrefCorMNModule);
	me["scrJrefCtrMNCommand"] = Scr::scramble(jrefCtrMNCommand);
	me["pnlctrmncommandAvail"] = pnlctrmncommandAvail;
	me["ButRegularizeActive"] = ButRegularizeActive;
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
		writeStringAttr(wr, itemtag, "sref", "scrJrefMdl1NGeneric", Scr::scramble(jrefMdl1NGeneric));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMdl1NPort", Scr::scramble(jrefMdl1NPort));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NProcess", Scr::scramble(jref1NProcess));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHsm1NPipeline", Scr::scramble(jrefHsm1NPipeline));
		writeStringAttr(wr, itemtag, "sref", "scrJref1NCdc", Scr::scramble(jref1NCdc));
		writeStringAttr(wr, itemtag, "sref", "scrJrefSup1NModule", Scr::scramble(jrefSup1NModule));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMge1NSignal", Scr::scramble(jrefMge1NSignal));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NVariable", Scr::scramble(jrefRef1NVariable));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NSensitivity", Scr::scramble(jrefRef1NSensitivity));
		writeStringAttr(wr, itemtag, "sref", "scrJrefRef1NSignal", Scr::scramble(jrefRef1NSignal));
		writeStringAttr(wr, itemtag, "sref", "scrJrefCtrRef1NCommand", Scr::scramble(jrefCtrRef1NCommand));
		writeBoolAttr(wr, itemtag, "sref", "pnlctrref1ncommandAvail", pnlctrref1ncommandAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefCtrHk1NVector", Scr::scramble(jrefCtrHk1NVector));
		writeBoolAttr(wr, itemtag, "sref", "pnlctrhk1nvectorAvail", pnlctrhk1nvectorAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefCtrRef1NError", Scr::scramble(jrefCtrRef1NError));
		writeBoolAttr(wr, itemtag, "sref", "pnlctrref1nerrorAvail", pnlctrref1nerrorAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefCtdMNModule", Scr::scramble(jrefCtdMNModule));
		writeStringAttr(wr, itemtag, "sref", "scrJrefMNPeripheral", Scr::scramble(jrefMNPeripheral));
		writeStringAttr(wr, itemtag, "sref", "scrJrefCorMNModule", Scr::scramble(jrefCorMNModule));
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
	if (jrefMdl1NGeneric == comp->jrefMdl1NGeneric) insert(items, JREFMDL1NGENERIC);
	if (jrefMdl1NPort == comp->jrefMdl1NPort) insert(items, JREFMDL1NPORT);
	if (jref1NProcess == comp->jref1NProcess) insert(items, JREF1NPROCESS);
	if (jrefHsm1NPipeline == comp->jrefHsm1NPipeline) insert(items, JREFHSM1NPIPELINE);
	if (jref1NCdc == comp->jref1NCdc) insert(items, JREF1NCDC);
	if (jrefSup1NModule == comp->jrefSup1NModule) insert(items, JREFSUP1NMODULE);
	if (jrefMge1NSignal == comp->jrefMge1NSignal) insert(items, JREFMGE1NSIGNAL);
	if (jrefRef1NVariable == comp->jrefRef1NVariable) insert(items, JREFREF1NVARIABLE);
	if (jrefRef1NSensitivity == comp->jrefRef1NSensitivity) insert(items, JREFREF1NSENSITIVITY);
	if (jrefRef1NSignal == comp->jrefRef1NSignal) insert(items, JREFREF1NSIGNAL);
	if (jrefCtrRef1NCommand == comp->jrefCtrRef1NCommand) insert(items, JREFCTRREF1NCOMMAND);
	if (pnlctrref1ncommandAvail == comp->pnlctrref1ncommandAvail) insert(items, PNLCTRREF1NCOMMANDAVAIL);
	if (jrefCtrHk1NVector == comp->jrefCtrHk1NVector) insert(items, JREFCTRHK1NVECTOR);
	if (pnlctrhk1nvectorAvail == comp->pnlctrhk1nvectorAvail) insert(items, PNLCTRHK1NVECTORAVAIL);
	if (jrefCtrRef1NError == comp->jrefCtrRef1NError) insert(items, JREFCTRREF1NERROR);
	if (pnlctrref1nerrorAvail == comp->pnlctrref1nerrorAvail) insert(items, PNLCTRREF1NERRORAVAIL);
	if (jrefCtdMNModule == comp->jrefCtdMNModule) insert(items, JREFCTDMNMODULE);
	if (jrefMNPeripheral == comp->jrefMNPeripheral) insert(items, JREFMNPERIPHERAL);
	if (jrefCorMNModule == comp->jrefCorMNModule) insert(items, JREFCORMNMODULE);
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

	diffitems = {IXWDBEVEXPSTATE, JREFDETAIL, JREFKHDLTYPE, JREFAPAR, JREFMDL1NGENERIC, JREFMDL1NPORT, JREF1NPROCESS, JREFHSM1NPIPELINE, JREF1NCDC, JREFSUP1NMODULE, JREFMGE1NSIGNAL, JREFREF1NVARIABLE, JREFREF1NSENSITIVITY, JREFREF1NSIGNAL, JREFCTRREF1NCOMMAND, PNLCTRREF1NCOMMANDAVAIL, JREFCTRHK1NVECTOR, PNLCTRHK1NVECTORAVAIL, JREFCTRREF1NERROR, PNLCTRREF1NERRORAVAIL, JREFCTDMNMODULE, JREFMNPERIPHERAL, JREFCORMNMODULE, JREFCTRMNCOMMAND, PNLCTRMNCOMMANDAVAIL, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWdbeModRec::Tag
 ******************************************************************************/

void PnlWdbeModRec::Tag::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
			, string difftag
		) {
	if (difftag.length() == 0) difftag = "TagWdbeModRec";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	if (ixWdbeVLocale == VecWdbeVLocale::ENUS) {
		me["Cpt"] = "Module";
	};
};

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

void PnlWdbeModRec::DpchAppDo::readJSON(
			const Json::Value& sup
			, bool addbasetag
		) {
	clear();

	bool basefound;

	const Json::Value& me = [&]{if (!addbasetag) return sup; return sup["DpchAppWdbeModRecDo"];}();

	basefound = (me != Json::nullValue);

	if (basefound) {
		if (me.isMember("scrJref")) {jref = Scr::descramble(me["scrJref"].asString()); add(JREF);};
		if (me.isMember("srefIxVDo")) {ixVDo = VecVDo::getIx(me["srefIxVDo"].asString()); add(IXVDO);};
	} else {
	};
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

void PnlWdbeModRec::DpchEngData::writeJSON(
			const uint ixWdbeVLocale
			, Json::Value& sup
		) {
	Json::Value& me = sup["DpchEngWdbeModRecData"] = Json::Value(Json::objectValue);

	if (has(JREF)) me["scrJref"] = Scr::scramble(jref);
	if (has(CONTINF)) continf.writeJSON(me);
	if (has(STATAPP)) StatApp::writeJSON(me);
	if (has(STATSHR)) statshr.writeJSON(me);
	if (has(TAG)) Tag::writeJSON(ixWdbeVLocale, me);
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
