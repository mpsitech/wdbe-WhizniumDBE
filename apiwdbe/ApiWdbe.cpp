/**
	* \file ApiWdbe.cpp
	* Wdbe API library global functionality (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "ApiWdbe.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class StgWdbeapi
 ******************************************************************************/

StgWdbeapi::StgWdbeapi(
			const string engip
			, const uint engport
			, const string username
			, const string password
		) :
			Block()
			, engip(engip)
			, engport(engport)
			, username(username)
			, password(password)
		{
	mask = {ENGIP, ENGPORT, USERNAME, PASSWORD};
};

bool StgWdbeapi::all(
			const set<uint>& items
		) {
	if (!find(items, ENGIP)) return false;
	if (!find(items, ENGPORT)) return false;
	if (!find(items, USERNAME)) return false;
	if (!find(items, PASSWORD)) return false;

	return true;
};

bool StgWdbeapi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWdbeapi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWdbeapi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engip", engip)) add(ENGIP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engport", engport)) add(ENGPORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
	};

	return basefound;
};

void StgWdbeapi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWdbeapi";

	string itemtag;
	if (shorttags)
		itemtag = "Si";
	else
		itemtag = "StgitemWdbeapi";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "engip", engip);
		writeUintAttr(wr, itemtag, "sref", "engport", engport);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWdbeapi::compare(
			const StgWdbeapi* comp
		) {
	set<uint> items;

	if (engip == comp->engip) insert(items, ENGIP);
	if (engport == comp->engport) insert(items, ENGPORT);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);

	return items;
};

/******************************************************************************
 namespace ApiWdbe
 ******************************************************************************/

uint ApiWdbe::readDpchEng(
			char* buf
			, unsigned long buflen
			, DpchEngWdbe** dpcheng
		) {
	uint ixWdbeVDpch = 0;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	try {
		parseBuffer(buf, buflen, &doc, &docctx);

		ixWdbeVDpch = VecWdbeVDpch::getIx(extractRoot(doc));

		if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBECPRNEWDATA) {
			*dpcheng = new DlgWdbeCprNew::DpchEngData();
			((DlgWdbeCprNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBECVRBSCCDDATA) {
			*dpcheng = new DlgWdbeCvrBsccd::DpchEngData();
			((DlgWdbeCvrBsccd::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBECVRDETCDDATA) {
			*dpcheng = new DlgWdbeCvrDetcd::DpchEngData();
			((DlgWdbeCvrDetcd::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBECVRNEWDATA) {
			*dpcheng = new DlgWdbeCvrNew::DpchEngData();
			((DlgWdbeCvrNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBECVRWRITEDATA) {
			*dpcheng = new DlgWdbeCvrWrite::DpchEngData();
			((DlgWdbeCvrWrite::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEFILDOWNLOADDATA) {
			*dpcheng = new DlgWdbeFilDownload::DpchEngData();
			((DlgWdbeFilDownload::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEFILNEWDATA) {
			*dpcheng = new DlgWdbeFilNew::DpchEngData();
			((DlgWdbeFilNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBENAVLOAINIDATA) {
			*dpcheng = new DlgWdbeNavLoaini::DpchEngData();
			((DlgWdbeNavLoaini::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBENAVMNGLICDATA) {
			*dpcheng = new DlgWdbeNavMnglic::DpchEngData();
			((DlgWdbeNavMnglic::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEPRJIMPEXDATA) {
			*dpcheng = new DlgWdbePrjImpex::DpchEngData();
			((DlgWdbePrjImpex::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEPRJNEWDATA) {
			*dpcheng = new DlgWdbePrjNew::DpchEngData();
			((DlgWdbePrjNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBERLSFINREPTRDATA) {
			*dpcheng = new DlgWdbeRlsFinreptr::DpchEngData();
			((DlgWdbeRlsFinreptr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBERLSSTAREPTRDATA) {
			*dpcheng = new DlgWdbeRlsStareptr::DpchEngData();
			((DlgWdbeRlsStareptr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBERLSWRITEDATA) {
			*dpcheng = new DlgWdbeRlsWrite::DpchEngData();
			((DlgWdbeRlsWrite::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEUSRMNGKEYPAIRDATA) {
			*dpcheng = new DlgWdbeUsrMngkeypair::DpchEngData();
			((DlgWdbeUsrMngkeypair::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEUTLEXTRIPDATA) {
			*dpcheng = new DlgWdbeUtlExtrip::DpchEngData();
			((DlgWdbeUtlExtrip::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEUTLMRGIPDATA) {
			*dpcheng = new DlgWdbeUtlMrgip::DpchEngData();
			((DlgWdbeUtlMrgip::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEVERCMDSETDATA) {
			*dpcheng = new DlgWdbeVerCmdset::DpchEngData();
			((DlgWdbeVerCmdset::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEVERCUSTFSTDATA) {
			*dpcheng = new DlgWdbeVerCustfst::DpchEngData();
			((DlgWdbeVerCustfst::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEVERDEPLOYDATA) {
			*dpcheng = new DlgWdbeVerDeploy::DpchEngData();
			((DlgWdbeVerDeploy::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEVERDFLALGDATA) {
			*dpcheng = new DlgWdbeVerDflalg::DpchEngData();
			((DlgWdbeVerDflalg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEVERFINMODDATA) {
			*dpcheng = new DlgWdbeVerFinmod::DpchEngData();
			((DlgWdbeVerFinmod::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEVERGENFSTDATA) {
			*dpcheng = new DlgWdbeVerGenfst::DpchEngData();
			((DlgWdbeVerGenfst::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEVERMDLSTRDATA) {
			*dpcheng = new DlgWdbeVerMdlstr::DpchEngData();
			((DlgWdbeVerMdlstr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGDLGWDBEVERNEWDATA) {
			*dpcheng = new DlgWdbeVerNew::DpchEngData();
			((DlgWdbeVerNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGROOTWDBEDATA) {
			*dpcheng = new RootWdbe::DpchEngData();
			((RootWdbe::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGSESSWDBEDATA) {
			*dpcheng = new SessWdbe::DpchEngData();
			((SessWdbe::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEACK) {
			*dpcheng = new DpchEngWdbeAck();
			((DpchEngWdbeAck*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEALERT) {
			*dpcheng = new DpchEngWdbeAlert();
			((DpchEngWdbeAlert*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEBNK1NPINDATA) {
			*dpcheng = new PnlWdbeBnk1NPin::DpchEngData();
			((PnlWdbeBnk1NPin::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEBNKDATA) {
			*dpcheng = new CrdWdbeBnk::DpchEngData();
			((CrdWdbeBnk::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEBNKDETAILDATA) {
			*dpcheng = new PnlWdbeBnkDetail::DpchEngData();
			((PnlWdbeBnkDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEBNKHEADBARDATA) {
			*dpcheng = new PnlWdbeBnkHeadbar::DpchEngData();
			((PnlWdbeBnkHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEBNKLISTDATA) {
			*dpcheng = new PnlWdbeBnkList::DpchEngData();
			((PnlWdbeBnkList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEBNKRECDATA) {
			*dpcheng = new PnlWdbeBnkRec::DpchEngData();
			((PnlWdbeBnkRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECDCDATA) {
			*dpcheng = new CrdWdbeCdc::DpchEngData();
			((CrdWdbeCdc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECDCDETAILDATA) {
			*dpcheng = new PnlWdbeCdcDetail::DpchEngData();
			((PnlWdbeCdcDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECDCHEADBARDATA) {
			*dpcheng = new PnlWdbeCdcHeadbar::DpchEngData();
			((PnlWdbeCdcHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECDCLISTDATA) {
			*dpcheng = new PnlWdbeCdcList::DpchEngData();
			((PnlWdbeCdcList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECDCMNSIGNALDATA) {
			*dpcheng = new PnlWdbeCdcMNSignal::DpchEngData();
			((PnlWdbeCdcMNSignal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECDCRECDATA) {
			*dpcheng = new PnlWdbeCdcRec::DpchEngData();
			((PnlWdbeCdcRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMDAINVPARDATA) {
			*dpcheng = new PnlWdbeCmdAInvpar::DpchEngData();
			((PnlWdbeCmdAInvpar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMDARETPARDATA) {
			*dpcheng = new PnlWdbeCmdARetpar::DpchEngData();
			((PnlWdbeCmdARetpar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMDDATA) {
			*dpcheng = new CrdWdbeCmd::DpchEngData();
			((CrdWdbeCmd::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMDDETAILDATA) {
			*dpcheng = new PnlWdbeCmdDetail::DpchEngData();
			((PnlWdbeCmdDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMDHEADBARDATA) {
			*dpcheng = new PnlWdbeCmdHeadbar::DpchEngData();
			((PnlWdbeCmdHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMDHK1NVECTORDATA) {
			*dpcheng = new PnlWdbeCmdHk1NVector::DpchEngData();
			((PnlWdbeCmdHk1NVector::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMDLISTDATA) {
			*dpcheng = new PnlWdbeCmdList::DpchEngData();
			((PnlWdbeCmdList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMDMNCONTROLLERDATA) {
			*dpcheng = new PnlWdbeCmdMNController::DpchEngData();
			((PnlWdbeCmdMNController::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMDRECDATA) {
			*dpcheng = new PnlWdbeCmdRec::DpchEngData();
			((PnlWdbeCmdRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMP1NRELEASEDATA) {
			*dpcheng = new PnlWdbeCmp1NRelease::DpchEngData();
			((PnlWdbeCmp1NRelease::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMPDATA) {
			*dpcheng = new CrdWdbeCmp::DpchEngData();
			((CrdWdbeCmp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMPDETAILDATA) {
			*dpcheng = new PnlWdbeCmpDetail::DpchEngData();
			((PnlWdbeCmpDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMPHEADBARDATA) {
			*dpcheng = new PnlWdbeCmpHeadbar::DpchEngData();
			((PnlWdbeCmpHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMPLISTDATA) {
			*dpcheng = new PnlWdbeCmpList::DpchEngData();
			((PnlWdbeCmpList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMPMNLIBRARYDATA) {
			*dpcheng = new PnlWdbeCmpMNLibrary::DpchEngData();
			((PnlWdbeCmpMNLibrary::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECMPRECDATA) {
			*dpcheng = new PnlWdbeCmpRec::DpchEngData();
			((PnlWdbeCmpRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECONFIRM) {
			*dpcheng = new DpchEngWdbeConfirm();
			((DpchEngWdbeConfirm*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECPR1NCOREVERSIONDATA) {
			*dpcheng = new PnlWdbeCpr1NCoreversion::DpchEngData();
			((PnlWdbeCpr1NCoreversion::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECPRDATA) {
			*dpcheng = new CrdWdbeCpr::DpchEngData();
			((CrdWdbeCpr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECPRDETAILDATA) {
			*dpcheng = new PnlWdbeCprDetail::DpchEngData();
			((PnlWdbeCprDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECPRHEADBARDATA) {
			*dpcheng = new PnlWdbeCprHeadbar::DpchEngData();
			((PnlWdbeCprHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECPRLISTDATA) {
			*dpcheng = new PnlWdbeCprList::DpchEngData();
			((PnlWdbeCprList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECPRMNPERSONDATA) {
			*dpcheng = new PnlWdbeCprMNPerson::DpchEngData();
			((PnlWdbeCprMNPerson::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECPRRECDATA) {
			*dpcheng = new PnlWdbeCprRec::DpchEngData();
			((PnlWdbeCprRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECVRAIPDATA) {
			*dpcheng = new PnlWdbeCvrAIp::DpchEngData();
			((PnlWdbeCvrAIp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECVRAPLHDATA) {
			*dpcheng = new PnlWdbeCvrAPlh::DpchEngData();
			((PnlWdbeCvrAPlh::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECVRBCV1NCOREVERSIONDATA) {
			*dpcheng = new PnlWdbeCvrBcv1NCoreversion::DpchEngData();
			((PnlWdbeCvrBcv1NCoreversion::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECVRDATA) {
			*dpcheng = new CrdWdbeCvr::DpchEngData();
			((CrdWdbeCvr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECVRDETAILDATA) {
			*dpcheng = new PnlWdbeCvrDetail::DpchEngData();
			((PnlWdbeCvrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECVRHEADBARDATA) {
			*dpcheng = new PnlWdbeCvrHeadbar::DpchEngData();
			((PnlWdbeCvrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECVRHK1NMODULEDATA) {
			*dpcheng = new PnlWdbeCvrHk1NModule::DpchEngData();
			((PnlWdbeCvrHk1NModule::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECVRLISTDATA) {
			*dpcheng = new PnlWdbeCvrList::DpchEngData();
			((PnlWdbeCvrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBECVRRECDATA) {
			*dpcheng = new PnlWdbeCvrRec::DpchEngData();
			((PnlWdbeCvrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEERRAPARDATA) {
			*dpcheng = new PnlWdbeErrAPar::DpchEngData();
			((PnlWdbeErrAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEERRDATA) {
			*dpcheng = new CrdWdbeErr::DpchEngData();
			((CrdWdbeErr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEERRDETAILDATA) {
			*dpcheng = new PnlWdbeErrDetail::DpchEngData();
			((PnlWdbeErrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEERRHEADBARDATA) {
			*dpcheng = new PnlWdbeErrHeadbar::DpchEngData();
			((PnlWdbeErrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEERRLISTDATA) {
			*dpcheng = new PnlWdbeErrList::DpchEngData();
			((PnlWdbeErrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEERRRECDATA) {
			*dpcheng = new PnlWdbeErrRec::DpchEngData();
			((PnlWdbeErrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFAM1NUNITDATA) {
			*dpcheng = new PnlWdbeFam1NUnit::DpchEngData();
			((PnlWdbeFam1NUnit::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFAMDATA) {
			*dpcheng = new CrdWdbeFam::DpchEngData();
			((CrdWdbeFam::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFAMDETAILDATA) {
			*dpcheng = new PnlWdbeFamDetail::DpchEngData();
			((PnlWdbeFamDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFAMHEADBARDATA) {
			*dpcheng = new PnlWdbeFamHeadbar::DpchEngData();
			((PnlWdbeFamHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFAMLISTDATA) {
			*dpcheng = new PnlWdbeFamList::DpchEngData();
			((PnlWdbeFamList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFAMRECDATA) {
			*dpcheng = new PnlWdbeFamRec::DpchEngData();
			((PnlWdbeFamRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFILDATA) {
			*dpcheng = new CrdWdbeFil::DpchEngData();
			((CrdWdbeFil::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFILDETAILDATA) {
			*dpcheng = new PnlWdbeFilDetail::DpchEngData();
			((PnlWdbeFilDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFILHEADBARDATA) {
			*dpcheng = new PnlWdbeFilHeadbar::DpchEngData();
			((PnlWdbeFilHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFILLISTDATA) {
			*dpcheng = new PnlWdbeFilList::DpchEngData();
			((PnlWdbeFilList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFILRECDATA) {
			*dpcheng = new PnlWdbeFilRec::DpchEngData();
			((PnlWdbeFilRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFSTASTEPDATA) {
			*dpcheng = new PnlWdbeFstAStep::DpchEngData();
			((PnlWdbeFstAStep::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFSTDATA) {
			*dpcheng = new CrdWdbeFst::DpchEngData();
			((CrdWdbeFst::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFSTDETAILDATA) {
			*dpcheng = new PnlWdbeFstDetail::DpchEngData();
			((PnlWdbeFstDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFSTHEADBARDATA) {
			*dpcheng = new PnlWdbeFstHeadbar::DpchEngData();
			((PnlWdbeFstHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFSTLISTDATA) {
			*dpcheng = new PnlWdbeFstList::DpchEngData();
			((PnlWdbeFstList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEFSTRECDATA) {
			*dpcheng = new PnlWdbeFstRec::DpchEngData();
			((PnlWdbeFstRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEGENDATA) {
			*dpcheng = new CrdWdbeGen::DpchEngData();
			((CrdWdbeGen::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEGENDETAILDATA) {
			*dpcheng = new PnlWdbeGenDetail::DpchEngData();
			((PnlWdbeGenDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEGENHEADBARDATA) {
			*dpcheng = new PnlWdbeGenHeadbar::DpchEngData();
			((PnlWdbeGenHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEGENLISTDATA) {
			*dpcheng = new PnlWdbeGenList::DpchEngData();
			((PnlWdbeGenList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEGENRECDATA) {
			*dpcheng = new PnlWdbeGenRec::DpchEngData();
			((PnlWdbeGenRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEINTDATA) {
			*dpcheng = new CrdWdbeInt::DpchEngData();
			((CrdWdbeInt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEINTDETAILDATA) {
			*dpcheng = new PnlWdbeIntDetail::DpchEngData();
			((PnlWdbeIntDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEINTHEADBARDATA) {
			*dpcheng = new PnlWdbeIntHeadbar::DpchEngData();
			((PnlWdbeIntHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEINTLISTDATA) {
			*dpcheng = new PnlWdbeIntList::DpchEngData();
			((PnlWdbeIntList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEINTRECDATA) {
			*dpcheng = new PnlWdbeIntRec::DpchEngData();
			((PnlWdbeIntRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEINTSRC1NSENSITIVITYDATA) {
			*dpcheng = new PnlWdbeIntSrc1NSensitivity::DpchEngData();
			((PnlWdbeIntSrc1NSensitivity::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBELIBAMAKEFILEDATA) {
			*dpcheng = new PnlWdbeLibAMakefile::DpchEngData();
			((PnlWdbeLibAMakefile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBELIBDATA) {
			*dpcheng = new CrdWdbeLib::DpchEngData();
			((CrdWdbeLib::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBELIBDETAILDATA) {
			*dpcheng = new PnlWdbeLibDetail::DpchEngData();
			((PnlWdbeLibDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBELIBHEADBARDATA) {
			*dpcheng = new PnlWdbeLibHeadbar::DpchEngData();
			((PnlWdbeLibHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBELIBLISTDATA) {
			*dpcheng = new PnlWdbeLibList::DpchEngData();
			((PnlWdbeLibList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBELIBMNCOMPONENTDATA) {
			*dpcheng = new PnlWdbeLibMNComponent::DpchEngData();
			((PnlWdbeLibMNComponent::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBELIBRECDATA) {
			*dpcheng = new PnlWdbeLibRec::DpchEngData();
			((PnlWdbeLibRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMCH1NRELEASEDATA) {
			*dpcheng = new PnlWdbeMch1NRelease::DpchEngData();
			((PnlWdbeMch1NRelease::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMCHAMAKEFILEDATA) {
			*dpcheng = new PnlWdbeMchAMakefile::DpchEngData();
			((PnlWdbeMchAMakefile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMCHAPARDATA) {
			*dpcheng = new PnlWdbeMchAPar::DpchEngData();
			((PnlWdbeMchAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMCHDATA) {
			*dpcheng = new CrdWdbeMch::DpchEngData();
			((CrdWdbeMch::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMCHDETAILDATA) {
			*dpcheng = new PnlWdbeMchDetail::DpchEngData();
			((PnlWdbeMchDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMCHHEADBARDATA) {
			*dpcheng = new PnlWdbeMchHeadbar::DpchEngData();
			((PnlWdbeMchHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMCHLISTDATA) {
			*dpcheng = new PnlWdbeMchList::DpchEngData();
			((PnlWdbeMchList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMCHRECDATA) {
			*dpcheng = new PnlWdbeMchRec::DpchEngData();
			((PnlWdbeMchRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMCHSUP1NMACHINEDATA) {
			*dpcheng = new PnlWdbeMchSup1NMachine::DpchEngData();
			((PnlWdbeMchSup1NMachine::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMOD1NCDCDATA) {
			*dpcheng = new PnlWdbeMod1NCdc::DpchEngData();
			((PnlWdbeMod1NCdc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMOD1NPROCESSDATA) {
			*dpcheng = new PnlWdbeMod1NProcess::DpchEngData();
			((PnlWdbeMod1NProcess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODAPARDATA) {
			*dpcheng = new PnlWdbeModAPar::DpchEngData();
			((PnlWdbeModAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODCORMNMODULEDATA) {
			*dpcheng = new PnlWdbeModCorMNModule::DpchEngData();
			((PnlWdbeModCorMNModule::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODCTDMNMODULEDATA) {
			*dpcheng = new PnlWdbeModCtdMNModule::DpchEngData();
			((PnlWdbeModCtdMNModule::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODCTRHK1NVECTORDATA) {
			*dpcheng = new PnlWdbeModCtrHk1NVector::DpchEngData();
			((PnlWdbeModCtrHk1NVector::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODCTRMNCOMMANDDATA) {
			*dpcheng = new PnlWdbeModCtrMNCommand::DpchEngData();
			((PnlWdbeModCtrMNCommand::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODCTRREF1NCOMMANDDATA) {
			*dpcheng = new PnlWdbeModCtrRef1NCommand::DpchEngData();
			((PnlWdbeModCtrRef1NCommand::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODCTRREF1NERRORDATA) {
			*dpcheng = new PnlWdbeModCtrRef1NError::DpchEngData();
			((PnlWdbeModCtrRef1NError::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODDATA) {
			*dpcheng = new CrdWdbeMod::DpchEngData();
			((CrdWdbeMod::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODDETAILDATA) {
			*dpcheng = new PnlWdbeModDetail::DpchEngData();
			((PnlWdbeModDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODHEADBARDATA) {
			*dpcheng = new PnlWdbeModHeadbar::DpchEngData();
			((PnlWdbeModHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODHSM1NPIPELINEDATA) {
			*dpcheng = new PnlWdbeModHsm1NPipeline::DpchEngData();
			((PnlWdbeModHsm1NPipeline::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODKHDLTYPEDATA) {
			*dpcheng = new PnlWdbeModKHdltype::DpchEngData();
			((PnlWdbeModKHdltype::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODLISTDATA) {
			*dpcheng = new PnlWdbeModList::DpchEngData();
			((PnlWdbeModList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODMDL1NGENERICDATA) {
			*dpcheng = new PnlWdbeModMdl1NGeneric::DpchEngData();
			((PnlWdbeModMdl1NGeneric::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODMDL1NPORTDATA) {
			*dpcheng = new PnlWdbeModMdl1NPort::DpchEngData();
			((PnlWdbeModMdl1NPort::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODMGE1NSIGNALDATA) {
			*dpcheng = new PnlWdbeModMge1NSignal::DpchEngData();
			((PnlWdbeModMge1NSignal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODMNPERIPHERALDATA) {
			*dpcheng = new PnlWdbeModMNPeripheral::DpchEngData();
			((PnlWdbeModMNPeripheral::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODRECDATA) {
			*dpcheng = new PnlWdbeModRec::DpchEngData();
			((PnlWdbeModRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODREF1NSENSITIVITYDATA) {
			*dpcheng = new PnlWdbeModRef1NSensitivity::DpchEngData();
			((PnlWdbeModRef1NSensitivity::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODREF1NSIGNALDATA) {
			*dpcheng = new PnlWdbeModRef1NSignal::DpchEngData();
			((PnlWdbeModRef1NSignal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODREF1NVARIABLEDATA) {
			*dpcheng = new PnlWdbeModRef1NVariable::DpchEngData();
			((PnlWdbeModRef1NVariable::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMODSUP1NMODULEDATA) {
			*dpcheng = new PnlWdbeModSup1NModule::DpchEngData();
			((PnlWdbeModSup1NModule::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPAPARDATA) {
			*dpcheng = new PnlWdbeMtpAPar::DpchEngData();
			((PnlWdbeMtpAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPDATA) {
			*dpcheng = new CrdWdbeMtp::DpchEngData();
			((CrdWdbeMtp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPDETAILDATA) {
			*dpcheng = new PnlWdbeMtpDetail::DpchEngData();
			((PnlWdbeMtpDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPHEADBARDATA) {
			*dpcheng = new PnlWdbeMtpHeadbar::DpchEngData();
			((PnlWdbeMtpHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPHSM1NPIPELINEDATA) {
			*dpcheng = new PnlWdbeMtpHsm1NPipeline::DpchEngData();
			((PnlWdbeMtpHsm1NPipeline::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPKHDLTYPEDATA) {
			*dpcheng = new PnlWdbeMtpKHdltype::DpchEngData();
			((PnlWdbeMtpKHdltype::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPKPARKEYDATA) {
			*dpcheng = new PnlWdbeMtpKParKey::DpchEngData();
			((PnlWdbeMtpKParKey::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPLISTDATA) {
			*dpcheng = new PnlWdbeMtpList::DpchEngData();
			((PnlWdbeMtpList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPMDL1NGENERICDATA) {
			*dpcheng = new PnlWdbeMtpMdl1NGeneric::DpchEngData();
			((PnlWdbeMtpMdl1NGeneric::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPMDL1NPORTDATA) {
			*dpcheng = new PnlWdbeMtpMdl1NPort::DpchEngData();
			((PnlWdbeMtpMdl1NPort::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPMGE1NSIGNALDATA) {
			*dpcheng = new PnlWdbeMtpMge1NSignal::DpchEngData();
			((PnlWdbeMtpMge1NSignal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPRECDATA) {
			*dpcheng = new PnlWdbeMtpRec::DpchEngData();
			((PnlWdbeMtpRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPREF1NFILEDATA) {
			*dpcheng = new PnlWdbeMtpRef1NFile::DpchEngData();
			((PnlWdbeMtpRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPREF1NSENSITIVITYDATA) {
			*dpcheng = new PnlWdbeMtpRef1NSensitivity::DpchEngData();
			((PnlWdbeMtpRef1NSensitivity::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPREF1NVARIABLEDATA) {
			*dpcheng = new PnlWdbeMtpRef1NVariable::DpchEngData();
			((PnlWdbeMtpRef1NVariable::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPSUP1NMODULEDATA) {
			*dpcheng = new PnlWdbeMtpSup1NModule::DpchEngData();
			((PnlWdbeMtpSup1NModule::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEMTPTPL1NMODULEDATA) {
			*dpcheng = new PnlWdbeMtpTpl1NModule::DpchEngData();
			((PnlWdbeMtpTpl1NModule::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBENAVADMINDATA) {
			*dpcheng = new PnlWdbeNavAdmin::DpchEngData();
			((PnlWdbeNavAdmin::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBENAVAUXFCTDATA) {
			*dpcheng = new PnlWdbeNavAuxfct::DpchEngData();
			((PnlWdbeNavAuxfct::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBENAVCOREDEVDATA) {
			*dpcheng = new PnlWdbeNavCoredev::DpchEngData();
			((PnlWdbeNavCoredev::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBENAVDATA) {
			*dpcheng = new CrdWdbeNav::DpchEngData();
			((CrdWdbeNav::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBENAVDEPLOYDATA) {
			*dpcheng = new PnlWdbeNavDeploy::DpchEngData();
			((PnlWdbeNavDeploy::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBENAVDEVDEVDATA) {
			*dpcheng = new PnlWdbeNavDevdev::DpchEngData();
			((PnlWdbeNavDevdev::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBENAVGLOBALDATA) {
			*dpcheng = new PnlWdbeNavGlobal::DpchEngData();
			((PnlWdbeNavGlobal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBENAVHEADBARDATA) {
			*dpcheng = new PnlWdbeNavHeadbar::DpchEngData();
			((PnlWdbeNavHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBENAVHIGHDATA) {
			*dpcheng = new PnlWdbeNavHigh::DpchEngData();
			((PnlWdbeNavHigh::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBENAVLOWDATA) {
			*dpcheng = new PnlWdbeNavLow::DpchEngData();
			((PnlWdbeNavLow::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBENAVPREDATA) {
			*dpcheng = new PnlWdbeNavPre::DpchEngData();
			((PnlWdbeNavPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPINAPARDATA) {
			*dpcheng = new PnlWdbePinAPar::DpchEngData();
			((PnlWdbePinAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPINDATA) {
			*dpcheng = new CrdWdbePin::DpchEngData();
			((CrdWdbePin::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPINDETAILDATA) {
			*dpcheng = new PnlWdbePinDetail::DpchEngData();
			((PnlWdbePinDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPINHEADBARDATA) {
			*dpcheng = new PnlWdbePinHeadbar::DpchEngData();
			((PnlWdbePinHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPINLISTDATA) {
			*dpcheng = new PnlWdbePinList::DpchEngData();
			((PnlWdbePinList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPINRECDATA) {
			*dpcheng = new PnlWdbePinRec::DpchEngData();
			((PnlWdbePinRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPHAPARDATA) {
			*dpcheng = new PnlWdbePphAPar::DpchEngData();
			((PnlWdbePphAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPHDATA) {
			*dpcheng = new CrdWdbePph::DpchEngData();
			((CrdWdbePph::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPHDETAILDATA) {
			*dpcheng = new PnlWdbePphDetail::DpchEngData();
			((PnlWdbePphDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPHHEADBARDATA) {
			*dpcheng = new PnlWdbePphHeadbar::DpchEngData();
			((PnlWdbePphHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPHLISTDATA) {
			*dpcheng = new PnlWdbePphList::DpchEngData();
			((PnlWdbePphList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPHMNMODULEDATA) {
			*dpcheng = new PnlWdbePphMNModule::DpchEngData();
			((PnlWdbePphMNModule::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPHRECDATA) {
			*dpcheng = new PnlWdbePphRec::DpchEngData();
			((PnlWdbePphRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPLDATA) {
			*dpcheng = new CrdWdbePpl::DpchEngData();
			((CrdWdbePpl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPLDETAILDATA) {
			*dpcheng = new PnlWdbePplDetail::DpchEngData();
			((PnlWdbePplDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPLHEADBARDATA) {
			*dpcheng = new PnlWdbePplHeadbar::DpchEngData();
			((PnlWdbePplHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPLLISTDATA) {
			*dpcheng = new PnlWdbePplList::DpchEngData();
			((PnlWdbePplList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPLPPL1NSEGMENTDATA) {
			*dpcheng = new PnlWdbePplPpl1NSegment::DpchEngData();
			((PnlWdbePplPpl1NSegment::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPPLRECDATA) {
			*dpcheng = new PnlWdbePplRec::DpchEngData();
			((PnlWdbePplRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRCDATA) {
			*dpcheng = new CrdWdbePrc::DpchEngData();
			((CrdWdbePrc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRCDETAILDATA) {
			*dpcheng = new PnlWdbePrcDetail::DpchEngData();
			((PnlWdbePrcDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRCFSMFSM1NFSMSTATEDATA) {
			*dpcheng = new PnlWdbePrcFsmFsm1NFsmstate::DpchEngData();
			((PnlWdbePrcFsmFsm1NFsmstate::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRCFSMHK1NVECTORDATA) {
			*dpcheng = new PnlWdbePrcFsmHk1NVector::DpchEngData();
			((PnlWdbePrcFsmHk1NVector::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRCHEADBARDATA) {
			*dpcheng = new PnlWdbePrcHeadbar::DpchEngData();
			((PnlWdbePrcHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRCKHDLTYPEDATA) {
			*dpcheng = new PnlWdbePrcKHdltype::DpchEngData();
			((PnlWdbePrcKHdltype::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRCLISTDATA) {
			*dpcheng = new PnlWdbePrcList::DpchEngData();
			((PnlWdbePrcList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRCMGE1NSIGNALDATA) {
			*dpcheng = new PnlWdbePrcMge1NSignal::DpchEngData();
			((PnlWdbePrcMge1NSignal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRCRECDATA) {
			*dpcheng = new PnlWdbePrcRec::DpchEngData();
			((PnlWdbePrcRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRCREF1NSENSITIVITYDATA) {
			*dpcheng = new PnlWdbePrcRef1NSensitivity::DpchEngData();
			((PnlWdbePrcRef1NSensitivity::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRCREF1NVARIABLEDATA) {
			*dpcheng = new PnlWdbePrcRef1NVariable::DpchEngData();
			((PnlWdbePrcRef1NVariable::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRFDAEMONDATA) {
			*dpcheng = new PnlWdbePrfDaemon::DpchEngData();
			((PnlWdbePrfDaemon::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRFDATA) {
			*dpcheng = new CrdWdbePrf::DpchEngData();
			((CrdWdbePrf::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRFHEADBARDATA) {
			*dpcheng = new PnlWdbePrfHeadbar::DpchEngData();
			((PnlWdbePrfHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRFLICENSEDATA) {
			*dpcheng = new PnlWdbePrfLicense::DpchEngData();
			((PnlWdbePrfLicense::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRJDATA) {
			*dpcheng = new CrdWdbePrj::DpchEngData();
			((CrdWdbePrj::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRJDETAILDATA) {
			*dpcheng = new PnlWdbePrjDetail::DpchEngData();
			((PnlWdbePrjDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRJHEADBARDATA) {
			*dpcheng = new PnlWdbePrjHeadbar::DpchEngData();
			((PnlWdbePrjHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRJLISTDATA) {
			*dpcheng = new PnlWdbePrjList::DpchEngData();
			((PnlWdbePrjList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRJMNPERSONDATA) {
			*dpcheng = new PnlWdbePrjMNPerson::DpchEngData();
			((PnlWdbePrjMNPerson::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRJPRJ1NVERSIONDATA) {
			*dpcheng = new PnlWdbePrjPrj1NVersion::DpchEngData();
			((PnlWdbePrjPrj1NVersion::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRJRECDATA) {
			*dpcheng = new PnlWdbePrjRec::DpchEngData();
			((PnlWdbePrjRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRSADETAILDATA) {
			*dpcheng = new PnlWdbePrsADetail::DpchEngData();
			((PnlWdbePrsADetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRSDATA) {
			*dpcheng = new CrdWdbePrs::DpchEngData();
			((CrdWdbePrs::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRSDETAILDATA) {
			*dpcheng = new PnlWdbePrsDetail::DpchEngData();
			((PnlWdbePrsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRSHEADBARDATA) {
			*dpcheng = new PnlWdbePrsHeadbar::DpchEngData();
			((PnlWdbePrsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRSLISTDATA) {
			*dpcheng = new PnlWdbePrsList::DpchEngData();
			((PnlWdbePrsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRSMNCOREPROJECTDATA) {
			*dpcheng = new PnlWdbePrsMNCoreproject::DpchEngData();
			((PnlWdbePrsMNCoreproject::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRSMNPROJECTDATA) {
			*dpcheng = new PnlWdbePrsMNProject::DpchEngData();
			((PnlWdbePrsMNProject::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRSRECDATA) {
			*dpcheng = new PnlWdbePrsRec::DpchEngData();
			((PnlWdbePrsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRTDATA) {
			*dpcheng = new CrdWdbePrt::DpchEngData();
			((CrdWdbePrt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRTDETAILDATA) {
			*dpcheng = new PnlWdbePrtDetail::DpchEngData();
			((PnlWdbePrtDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRTHEADBARDATA) {
			*dpcheng = new PnlWdbePrtHeadbar::DpchEngData();
			((PnlWdbePrtHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRTLISTDATA) {
			*dpcheng = new PnlWdbePrtList::DpchEngData();
			((PnlWdbePrtList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRTRECDATA) {
			*dpcheng = new PnlWdbePrtRec::DpchEngData();
			((PnlWdbePrtRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEPRTSRC1NSENSITIVITYDATA) {
			*dpcheng = new PnlWdbePrtSrc1NSensitivity::DpchEngData();
			((PnlWdbePrtSrc1NSensitivity::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBERLSDATA) {
			*dpcheng = new CrdWdbeRls::DpchEngData();
			((CrdWdbeRls::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBERLSDETAILDATA) {
			*dpcheng = new PnlWdbeRlsDetail::DpchEngData();
			((PnlWdbeRlsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBERLSHEADBARDATA) {
			*dpcheng = new PnlWdbeRlsHeadbar::DpchEngData();
			((PnlWdbeRlsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBERLSLISTDATA) {
			*dpcheng = new PnlWdbeRlsList::DpchEngData();
			((PnlWdbeRlsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBERLSRECDATA) {
			*dpcheng = new PnlWdbeRlsRec::DpchEngData();
			((PnlWdbeRlsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESEGDATA) {
			*dpcheng = new CrdWdbeSeg::DpchEngData();
			((CrdWdbeSeg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESEGDETAILDATA) {
			*dpcheng = new PnlWdbeSegDetail::DpchEngData();
			((PnlWdbeSegDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESEGHEADBARDATA) {
			*dpcheng = new PnlWdbeSegHeadbar::DpchEngData();
			((PnlWdbeSegHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESEGLISTDATA) {
			*dpcheng = new PnlWdbeSegList::DpchEngData();
			((PnlWdbeSegList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESEGRECDATA) {
			*dpcheng = new PnlWdbeSegRec::DpchEngData();
			((PnlWdbeSegRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESEGSUP1NSEGMENTDATA) {
			*dpcheng = new PnlWdbeSegSup1NSegment::DpchEngData();
			((PnlWdbeSegSup1NSegment::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESIGDATA) {
			*dpcheng = new CrdWdbeSig::DpchEngData();
			((CrdWdbeSig::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESIGDETAILDATA) {
			*dpcheng = new PnlWdbeSigDetail::DpchEngData();
			((PnlWdbeSigDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESIGHEADBARDATA) {
			*dpcheng = new PnlWdbeSigHeadbar::DpchEngData();
			((PnlWdbeSigHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESIGLISTDATA) {
			*dpcheng = new PnlWdbeSigList::DpchEngData();
			((PnlWdbeSigList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESIGMNCDCDATA) {
			*dpcheng = new PnlWdbeSigMNCdc::DpchEngData();
			((PnlWdbeSigMNCdc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESIGRECDATA) {
			*dpcheng = new PnlWdbeSigRec::DpchEngData();
			((PnlWdbeSigRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESIGSRC1NSENSITIVITYDATA) {
			*dpcheng = new PnlWdbeSigSrc1NSensitivity::DpchEngData();
			((PnlWdbeSigSrc1NSensitivity::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESIL1NBANKDATA) {
			*dpcheng = new PnlWdbeSil1NBank::DpchEngData();
			((PnlWdbeSil1NBank::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESIL1NINTERRUPTDATA) {
			*dpcheng = new PnlWdbeSil1NInterrupt::DpchEngData();
			((PnlWdbeSil1NInterrupt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESIL1NPERIPHERALDATA) {
			*dpcheng = new PnlWdbeSil1NPeripheral::DpchEngData();
			((PnlWdbeSil1NPeripheral::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESILDATA) {
			*dpcheng = new CrdWdbeSil::DpchEngData();
			((CrdWdbeSil::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESILDETAILDATA) {
			*dpcheng = new PnlWdbeSilDetail::DpchEngData();
			((PnlWdbeSilDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESILHEADBARDATA) {
			*dpcheng = new PnlWdbeSilHeadbar::DpchEngData();
			((PnlWdbeSilHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESILHK1NMODULEDATA) {
			*dpcheng = new PnlWdbeSilHk1NModule::DpchEngData();
			((PnlWdbeSilHk1NModule::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESILHK1NVECTORDATA) {
			*dpcheng = new PnlWdbeSilHk1NVector::DpchEngData();
			((PnlWdbeSilHk1NVector::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESILLISTDATA) {
			*dpcheng = new PnlWdbeSilList::DpchEngData();
			((PnlWdbeSilList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESILRECDATA) {
			*dpcheng = new PnlWdbeSilRec::DpchEngData();
			((PnlWdbeSilRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESILREF1NCOMMANDDATA) {
			*dpcheng = new PnlWdbeSilRef1NCommand::DpchEngData();
			((PnlWdbeSilRef1NCommand::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESILREF1NERRORDATA) {
			*dpcheng = new PnlWdbeSilRef1NError::DpchEngData();
			((PnlWdbeSilRef1NError::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESILREF1NSIGNALDATA) {
			*dpcheng = new PnlWdbeSilRef1NSignal::DpchEngData();
			((PnlWdbeSilRef1NSignal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESILSIL1NUNITDATA) {
			*dpcheng = new PnlWdbeSilSil1NUnit::DpchEngData();
			((PnlWdbeSilSil1NUnit::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESNSDATA) {
			*dpcheng = new CrdWdbeSns::DpchEngData();
			((CrdWdbeSns::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESNSDETAILDATA) {
			*dpcheng = new PnlWdbeSnsDetail::DpchEngData();
			((PnlWdbeSnsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESNSHEADBARDATA) {
			*dpcheng = new PnlWdbeSnsHeadbar::DpchEngData();
			((PnlWdbeSnsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESNSLISTDATA) {
			*dpcheng = new PnlWdbeSnsList::DpchEngData();
			((PnlWdbeSnsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESNSRECDATA) {
			*dpcheng = new PnlWdbeSnsRec::DpchEngData();
			((PnlWdbeSnsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBESUSPEND) {
			*dpcheng = new DpchEngWdbeSuspend();
			((DpchEngWdbeSuspend*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNT1NBANKDATA) {
			*dpcheng = new PnlWdbeUnt1NBank::DpchEngData();
			((PnlWdbeUnt1NBank::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNT1NINTERRUPTDATA) {
			*dpcheng = new PnlWdbeUnt1NInterrupt::DpchEngData();
			((PnlWdbeUnt1NInterrupt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNT1NPERIPHERALDATA) {
			*dpcheng = new PnlWdbeUnt1NPeripheral::DpchEngData();
			((PnlWdbeUnt1NPeripheral::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNTDATA) {
			*dpcheng = new CrdWdbeUnt::DpchEngData();
			((CrdWdbeUnt::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNTDETAILDATA) {
			*dpcheng = new PnlWdbeUntDetail::DpchEngData();
			((PnlWdbeUntDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNTHEADBARDATA) {
			*dpcheng = new PnlWdbeUntHeadbar::DpchEngData();
			((PnlWdbeUntHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNTHK1NMODULEDATA) {
			*dpcheng = new PnlWdbeUntHk1NModule::DpchEngData();
			((PnlWdbeUntHk1NModule::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNTHK1NVECTORDATA) {
			*dpcheng = new PnlWdbeUntHk1NVector::DpchEngData();
			((PnlWdbeUntHk1NVector::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNTLISTDATA) {
			*dpcheng = new PnlWdbeUntList::DpchEngData();
			((PnlWdbeUntList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNTRECDATA) {
			*dpcheng = new PnlWdbeUntRec::DpchEngData();
			((PnlWdbeUntRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNTREF1NCOMMANDDATA) {
			*dpcheng = new PnlWdbeUntRef1NCommand::DpchEngData();
			((PnlWdbeUntRef1NCommand::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNTREF1NERRORDATA) {
			*dpcheng = new PnlWdbeUntRef1NError::DpchEngData();
			((PnlWdbeUntRef1NError::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNTREF1NSIGNALDATA) {
			*dpcheng = new PnlWdbeUntRef1NSignal::DpchEngData();
			((PnlWdbeUntRef1NSignal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUNTSIL1NUNITDATA) {
			*dpcheng = new PnlWdbeUntSil1NUnit::DpchEngData();
			((PnlWdbeUntSil1NUnit::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSGAACCESSDATA) {
			*dpcheng = new PnlWdbeUsgAAccess::DpchEngData();
			((PnlWdbeUsgAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSGDATA) {
			*dpcheng = new CrdWdbeUsg::DpchEngData();
			((CrdWdbeUsg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSGDETAILDATA) {
			*dpcheng = new PnlWdbeUsgDetail::DpchEngData();
			((PnlWdbeUsgDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSGHEADBARDATA) {
			*dpcheng = new PnlWdbeUsgHeadbar::DpchEngData();
			((PnlWdbeUsgHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSGLISTDATA) {
			*dpcheng = new PnlWdbeUsgList::DpchEngData();
			((PnlWdbeUsgList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSGMNUSERDATA) {
			*dpcheng = new PnlWdbeUsgMNUser::DpchEngData();
			((PnlWdbeUsgMNUser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSGRECDATA) {
			*dpcheng = new PnlWdbeUsgRec::DpchEngData();
			((PnlWdbeUsgRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSR1NSESSIONDATA) {
			*dpcheng = new PnlWdbeUsr1NSession::DpchEngData();
			((PnlWdbeUsr1NSession::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSRAACCESSDATA) {
			*dpcheng = new PnlWdbeUsrAAccess::DpchEngData();
			((PnlWdbeUsrAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSRDATA) {
			*dpcheng = new CrdWdbeUsr::DpchEngData();
			((CrdWdbeUsr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSRDETAILDATA) {
			*dpcheng = new PnlWdbeUsrDetail::DpchEngData();
			((PnlWdbeUsrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSRHEADBARDATA) {
			*dpcheng = new PnlWdbeUsrHeadbar::DpchEngData();
			((PnlWdbeUsrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSRLISTDATA) {
			*dpcheng = new PnlWdbeUsrList::DpchEngData();
			((PnlWdbeUsrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSRMNUSERGROUPDATA) {
			*dpcheng = new PnlWdbeUsrMNUsergroup::DpchEngData();
			((PnlWdbeUsrMNUsergroup::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUSRRECDATA) {
			*dpcheng = new PnlWdbeUsrRec::DpchEngData();
			((PnlWdbeUsrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUTLDATA) {
			*dpcheng = new CrdWdbeUtl::DpchEngData();
			((CrdWdbeUtl::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEUTLHEADBARDATA) {
			*dpcheng = new PnlWdbeUtlHeadbar::DpchEngData();
			((PnlWdbeUtlHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVARDATA) {
			*dpcheng = new CrdWdbeVar::DpchEngData();
			((CrdWdbeVar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVARDETAILDATA) {
			*dpcheng = new PnlWdbeVarDetail::DpchEngData();
			((PnlWdbeVarDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVARHEADBARDATA) {
			*dpcheng = new PnlWdbeVarHeadbar::DpchEngData();
			((PnlWdbeVarHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVARLISTDATA) {
			*dpcheng = new PnlWdbeVarList::DpchEngData();
			((PnlWdbeVarList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVARRECDATA) {
			*dpcheng = new PnlWdbeVarRec::DpchEngData();
			((PnlWdbeVarRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVECDATA) {
			*dpcheng = new CrdWdbeVec::DpchEngData();
			((CrdWdbeVec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVECDETAILDATA) {
			*dpcheng = new PnlWdbeVecDetail::DpchEngData();
			((PnlWdbeVecDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVECHEADBARDATA) {
			*dpcheng = new PnlWdbeVecHeadbar::DpchEngData();
			((PnlWdbeVecHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVECLISTDATA) {
			*dpcheng = new PnlWdbeVecList::DpchEngData();
			((PnlWdbeVecList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVECRECDATA) {
			*dpcheng = new PnlWdbeVecRec::DpchEngData();
			((PnlWdbeVecRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVECVEC1NVECTORITEMDATA) {
			*dpcheng = new PnlWdbeVecVec1NVectoritem::DpchEngData();
			((PnlWdbeVecVec1NVectoritem::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVER1NCOMPONENTDATA) {
			*dpcheng = new PnlWdbeVer1NComponent::DpchEngData();
			((PnlWdbeVer1NComponent::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVER1NUNITDATA) {
			*dpcheng = new PnlWdbeVer1NUnit::DpchEngData();
			((PnlWdbeVer1NUnit::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVERBVR1NVERSIONDATA) {
			*dpcheng = new PnlWdbeVerBvr1NVersion::DpchEngData();
			((PnlWdbeVerBvr1NVersion::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVERDATA) {
			*dpcheng = new CrdWdbeVer::DpchEngData();
			((CrdWdbeVer::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVERDETAILDATA) {
			*dpcheng = new PnlWdbeVerDetail::DpchEngData();
			((PnlWdbeVerDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVERHEADBARDATA) {
			*dpcheng = new PnlWdbeVerHeadbar::DpchEngData();
			((PnlWdbeVerHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVERLISTDATA) {
			*dpcheng = new PnlWdbeVerList::DpchEngData();
			((PnlWdbeVerList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVERRECDATA) {
			*dpcheng = new PnlWdbeVerRec::DpchEngData();
			((PnlWdbeVerRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVERREF1NFILEDATA) {
			*dpcheng = new PnlWdbeVerRef1NFile::DpchEngData();
			((PnlWdbeVerRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVITDATA) {
			*dpcheng = new CrdWdbeVit::DpchEngData();
			((CrdWdbeVit::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVITDETAILDATA) {
			*dpcheng = new PnlWdbeVitDetail::DpchEngData();
			((PnlWdbeVitDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVITHEADBARDATA) {
			*dpcheng = new PnlWdbeVitHeadbar::DpchEngData();
			((PnlWdbeVitHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVITLISTDATA) {
			*dpcheng = new PnlWdbeVitList::DpchEngData();
			((PnlWdbeVitList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWdbeVDpch == VecWdbeVDpch::DPCHENGWDBEVITRECDATA) {
			*dpcheng = new PnlWdbeVitRec::DpchEngData();
			((PnlWdbeVitRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		};
	} catch (SbeException& e) {
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixWdbeVDpch;
};

void ApiWdbe::writeDpchApp(
			DpchAppWdbe* dpchapp
			, char** buf
			, unsigned long& buflen
			, unsigned long ofs
		) {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &xbuf);
		dpchapp->writeXML(wr);
	closewriteBuffer(wr);

	buflen = xbuf->use + ofs;
	*buf = new char[buflen];
	memcpy(&((*buf)[ofs]), xbuf->content, buflen-ofs);

	xmlBufferFree(xbuf);
};
