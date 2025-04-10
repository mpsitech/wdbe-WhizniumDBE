/**
	* \file ApiWdbe.java
	* Wdbe Java API package global functionality
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import java.io.*;

import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;

import org.w3c.dom.*;
import org.xml.sax.*;

import sbecore.*;

public class ApiWdbe {

	public static final String WDBE_VERSION = "1.1.41";
	public static final int WDBE_VERSION_MAJOR = 1;
	public static final int WDBE_VERSION_MINOR = 1;
	public static final int WDBE_VERSION_SUB = 41;

	public static DpchEngWdbe readDpchEng(
				String s
			) {
		DpchEngWdbe dpcheng = null;

		try {
			InputSource is = new InputSource();
			is.setCharacterStream(new StringReader(s));

			Document doc = DocumentBuilderFactory.newInstance().newDocumentBuilder().parse(is);

			int ixWdbeVDpch = VecWdbeVDpch.getIx(Xmlio.extractRoot(doc));
			
			if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBECPRNEWDATA) dpcheng = (new DlgWdbeCprNew()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBECVRBSCCDDATA) dpcheng = (new DlgWdbeCvrBsccd()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBECVRDETCDDATA) dpcheng = (new DlgWdbeCvrDetcd()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBECVRNEWDATA) dpcheng = (new DlgWdbeCvrNew()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBECVRWRITEDATA) dpcheng = (new DlgWdbeCvrWrite()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEFILDOWNLOADDATA) dpcheng = (new DlgWdbeFilDownload()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEFILNEWDATA) dpcheng = (new DlgWdbeFilNew()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBENAVLOAINIDATA) dpcheng = (new DlgWdbeNavLoaini()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBENAVMNGLICDATA) dpcheng = (new DlgWdbeNavMnglic()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEPRJIMPEXDATA) dpcheng = (new DlgWdbePrjImpex()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEPRJNEWDATA) dpcheng = (new DlgWdbePrjNew()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBERLSFINREPTRDATA) dpcheng = (new DlgWdbeRlsFinreptr()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBERLSSTAREPTRDATA) dpcheng = (new DlgWdbeRlsStareptr()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBERLSWRITEDATA) dpcheng = (new DlgWdbeRlsWrite()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEUSRMNGKEYPAIRDATA) dpcheng = (new DlgWdbeUsrMngkeypair()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEUTLEXTRIPDATA) dpcheng = (new DlgWdbeUtlExtrip()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEUTLMRGIPDATA) dpcheng = (new DlgWdbeUtlMrgip()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEVERCMDSETDATA) dpcheng = (new DlgWdbeVerCmdset()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEVERCUSTFSTDATA) dpcheng = (new DlgWdbeVerCustfst()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEVERDEPLOYDATA) dpcheng = (new DlgWdbeVerDeploy()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEVERDFLALGDATA) dpcheng = (new DlgWdbeVerDflalg()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEVERFINMODDATA) dpcheng = (new DlgWdbeVerFinmod()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEVERGENFSTDATA) dpcheng = (new DlgWdbeVerGenfst()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEVERMDLSTRDATA) dpcheng = (new DlgWdbeVerMdlstr()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGDLGWDBEVERNEWDATA) dpcheng = (new DlgWdbeVerNew()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGROOTWDBEDATA) dpcheng = (new RootWdbe()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGSESSWDBEDATA) dpcheng = (new SessWdbe()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEACK) dpcheng = new DpchEngWdbeAck();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEALERT) dpcheng = new DpchEngWdbeAlert();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEBNK1NPINDATA) dpcheng = (new PnlWdbeBnk1NPin()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEBNKDATA) dpcheng = (new CrdWdbeBnk()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEBNKDETAILDATA) dpcheng = (new PnlWdbeBnkDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEBNKHEADBARDATA) dpcheng = (new PnlWdbeBnkHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEBNKLISTDATA) dpcheng = (new PnlWdbeBnkList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEBNKRECDATA) dpcheng = (new PnlWdbeBnkRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECDCDATA) dpcheng = (new CrdWdbeCdc()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECDCDETAILDATA) dpcheng = (new PnlWdbeCdcDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECDCHEADBARDATA) dpcheng = (new PnlWdbeCdcHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECDCLISTDATA) dpcheng = (new PnlWdbeCdcList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECDCMNSIGNALDATA) dpcheng = (new PnlWdbeCdcMNSignal()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECDCRECDATA) dpcheng = (new PnlWdbeCdcRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMDAINVPARDATA) dpcheng = (new PnlWdbeCmdAInvpar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMDARETPARDATA) dpcheng = (new PnlWdbeCmdARetpar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMDDATA) dpcheng = (new CrdWdbeCmd()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMDDETAILDATA) dpcheng = (new PnlWdbeCmdDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMDHEADBARDATA) dpcheng = (new PnlWdbeCmdHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMDLISTDATA) dpcheng = (new PnlWdbeCmdList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMDMNCONTROLLERDATA) dpcheng = (new PnlWdbeCmdMNController()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMDRECDATA) dpcheng = (new PnlWdbeCmdRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMP1NRELEASEDATA) dpcheng = (new PnlWdbeCmp1NRelease()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMPDATA) dpcheng = (new CrdWdbeCmp()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMPDETAILDATA) dpcheng = (new PnlWdbeCmpDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMPHEADBARDATA) dpcheng = (new PnlWdbeCmpHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMPLISTDATA) dpcheng = (new PnlWdbeCmpList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMPMNLIBRARYDATA) dpcheng = (new PnlWdbeCmpMNLibrary()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECMPRECDATA) dpcheng = (new PnlWdbeCmpRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECONFIRM) dpcheng = new DpchEngWdbeConfirm();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECPR1NCOREVERSIONDATA) dpcheng = (new PnlWdbeCpr1NCoreversion()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECPRDATA) dpcheng = (new CrdWdbeCpr()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECPRDETAILDATA) dpcheng = (new PnlWdbeCprDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECPRHEADBARDATA) dpcheng = (new PnlWdbeCprHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECPRLISTDATA) dpcheng = (new PnlWdbeCprList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECPRMNPERSONDATA) dpcheng = (new PnlWdbeCprMNPerson()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECPRRECDATA) dpcheng = (new PnlWdbeCprRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECVRAIPDATA) dpcheng = (new PnlWdbeCvrAIp()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECVRAPLHDATA) dpcheng = (new PnlWdbeCvrAPlh()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECVRBCV1NCOREVERSIONDATA) dpcheng = (new PnlWdbeCvrBcv1NCoreversion()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECVRDATA) dpcheng = (new CrdWdbeCvr()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECVRDETAILDATA) dpcheng = (new PnlWdbeCvrDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECVRHEADBARDATA) dpcheng = (new PnlWdbeCvrHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECVRHK1NMODULEDATA) dpcheng = (new PnlWdbeCvrHk1NModule()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECVRLISTDATA) dpcheng = (new PnlWdbeCvrList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBECVRRECDATA) dpcheng = (new PnlWdbeCvrRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEERRAPARDATA) dpcheng = (new PnlWdbeErrAPar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEERRDATA) dpcheng = (new CrdWdbeErr()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEERRDETAILDATA) dpcheng = (new PnlWdbeErrDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEERRHEADBARDATA) dpcheng = (new PnlWdbeErrHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEERRLISTDATA) dpcheng = (new PnlWdbeErrList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEERRRECDATA) dpcheng = (new PnlWdbeErrRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFAM1NUNITDATA) dpcheng = (new PnlWdbeFam1NUnit()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFAMDATA) dpcheng = (new CrdWdbeFam()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFAMDETAILDATA) dpcheng = (new PnlWdbeFamDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFAMHEADBARDATA) dpcheng = (new PnlWdbeFamHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFAMLISTDATA) dpcheng = (new PnlWdbeFamList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFAMRECDATA) dpcheng = (new PnlWdbeFamRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFILDATA) dpcheng = (new CrdWdbeFil()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFILDETAILDATA) dpcheng = (new PnlWdbeFilDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFILHEADBARDATA) dpcheng = (new PnlWdbeFilHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFILLISTDATA) dpcheng = (new PnlWdbeFilList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFILRECDATA) dpcheng = (new PnlWdbeFilRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFSTASTEPDATA) dpcheng = (new PnlWdbeFstAStep()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFSTDATA) dpcheng = (new CrdWdbeFst()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFSTDETAILDATA) dpcheng = (new PnlWdbeFstDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFSTHEADBARDATA) dpcheng = (new PnlWdbeFstHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFSTLISTDATA) dpcheng = (new PnlWdbeFstList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEFSTRECDATA) dpcheng = (new PnlWdbeFstRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEGENDATA) dpcheng = (new CrdWdbeGen()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEGENDETAILDATA) dpcheng = (new PnlWdbeGenDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEGENHEADBARDATA) dpcheng = (new PnlWdbeGenHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEGENLISTDATA) dpcheng = (new PnlWdbeGenList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEGENRECDATA) dpcheng = (new PnlWdbeGenRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEINTDATA) dpcheng = (new CrdWdbeInt()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEINTDETAILDATA) dpcheng = (new PnlWdbeIntDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEINTHEADBARDATA) dpcheng = (new PnlWdbeIntHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEINTLISTDATA) dpcheng = (new PnlWdbeIntList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEINTRECDATA) dpcheng = (new PnlWdbeIntRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEINTSRC1NSENSITIVITYDATA) dpcheng = (new PnlWdbeIntSrc1NSensitivity()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBELIBAMAKEFILEDATA) dpcheng = (new PnlWdbeLibAMakefile()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBELIBDATA) dpcheng = (new CrdWdbeLib()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBELIBDETAILDATA) dpcheng = (new PnlWdbeLibDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBELIBHEADBARDATA) dpcheng = (new PnlWdbeLibHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBELIBLISTDATA) dpcheng = (new PnlWdbeLibList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBELIBMNCOMPONENTDATA) dpcheng = (new PnlWdbeLibMNComponent()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBELIBRECDATA) dpcheng = (new PnlWdbeLibRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMCH1NRELEASEDATA) dpcheng = (new PnlWdbeMch1NRelease()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMCHAMAKEFILEDATA) dpcheng = (new PnlWdbeMchAMakefile()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMCHAPARDATA) dpcheng = (new PnlWdbeMchAPar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMCHDATA) dpcheng = (new CrdWdbeMch()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMCHDETAILDATA) dpcheng = (new PnlWdbeMchDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMCHHEADBARDATA) dpcheng = (new PnlWdbeMchHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMCHLISTDATA) dpcheng = (new PnlWdbeMchList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMCHRECDATA) dpcheng = (new PnlWdbeMchRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMCHSUP1NMACHINEDATA) dpcheng = (new PnlWdbeMchSup1NMachine()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMOD1NCDCDATA) dpcheng = (new PnlWdbeMod1NCdc()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMOD1NPROCESSDATA) dpcheng = (new PnlWdbeMod1NProcess()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODAPARDATA) dpcheng = (new PnlWdbeModAPar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODCORMNMODULEDATA) dpcheng = (new PnlWdbeModCorMNModule()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODCTDMNMODULEDATA) dpcheng = (new PnlWdbeModCtdMNModule()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODCTRHK1NVECTORDATA) dpcheng = (new PnlWdbeModCtrHk1NVector()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODCTRMNCOMMANDDATA) dpcheng = (new PnlWdbeModCtrMNCommand()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODCTRREF1NCOMMANDDATA) dpcheng = (new PnlWdbeModCtrRef1NCommand()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODCTRREF1NERRORDATA) dpcheng = (new PnlWdbeModCtrRef1NError()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODDATA) dpcheng = (new CrdWdbeMod()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODDETAILDATA) dpcheng = (new PnlWdbeModDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODHEADBARDATA) dpcheng = (new PnlWdbeModHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODHSM1NPIPELINEDATA) dpcheng = (new PnlWdbeModHsm1NPipeline()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODKHDLTYPEDATA) dpcheng = (new PnlWdbeModKHdltype()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODLISTDATA) dpcheng = (new PnlWdbeModList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODMDL1NGENERICDATA) dpcheng = (new PnlWdbeModMdl1NGeneric()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODMDL1NPORTDATA) dpcheng = (new PnlWdbeModMdl1NPort()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODMGE1NSIGNALDATA) dpcheng = (new PnlWdbeModMge1NSignal()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODMNPERIPHERALDATA) dpcheng = (new PnlWdbeModMNPeripheral()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODRECDATA) dpcheng = (new PnlWdbeModRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODREF1NSENSITIVITYDATA) dpcheng = (new PnlWdbeModRef1NSensitivity()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODREF1NSIGNALDATA) dpcheng = (new PnlWdbeModRef1NSignal()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODREF1NVARIABLEDATA) dpcheng = (new PnlWdbeModRef1NVariable()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMODSUP1NMODULEDATA) dpcheng = (new PnlWdbeModSup1NModule()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPAPARDATA) dpcheng = (new PnlWdbeMtpAPar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPDATA) dpcheng = (new CrdWdbeMtp()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPDETAILDATA) dpcheng = (new PnlWdbeMtpDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPHEADBARDATA) dpcheng = (new PnlWdbeMtpHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPHSM1NPIPELINEDATA) dpcheng = (new PnlWdbeMtpHsm1NPipeline()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPKHDLTYPEDATA) dpcheng = (new PnlWdbeMtpKHdltype()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPKPARKEYDATA) dpcheng = (new PnlWdbeMtpKParKey()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPLISTDATA) dpcheng = (new PnlWdbeMtpList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPMDL1NGENERICDATA) dpcheng = (new PnlWdbeMtpMdl1NGeneric()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPMDL1NPORTDATA) dpcheng = (new PnlWdbeMtpMdl1NPort()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPMGE1NSIGNALDATA) dpcheng = (new PnlWdbeMtpMge1NSignal()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPRECDATA) dpcheng = (new PnlWdbeMtpRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPREF1NFILEDATA) dpcheng = (new PnlWdbeMtpRef1NFile()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPREF1NSENSITIVITYDATA) dpcheng = (new PnlWdbeMtpRef1NSensitivity()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPREF1NVARIABLEDATA) dpcheng = (new PnlWdbeMtpRef1NVariable()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPSUP1NMODULEDATA) dpcheng = (new PnlWdbeMtpSup1NModule()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEMTPTPL1NMODULEDATA) dpcheng = (new PnlWdbeMtpTpl1NModule()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBENAVADMINDATA) dpcheng = (new PnlWdbeNavAdmin()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBENAVAUXFCTDATA) dpcheng = (new PnlWdbeNavAuxfct()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBENAVCOREDEVDATA) dpcheng = (new PnlWdbeNavCoredev()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBENAVDATA) dpcheng = (new CrdWdbeNav()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBENAVDEPLOYDATA) dpcheng = (new PnlWdbeNavDeploy()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBENAVDEVDEVDATA) dpcheng = (new PnlWdbeNavDevdev()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBENAVGLOBALDATA) dpcheng = (new PnlWdbeNavGlobal()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBENAVHEADBARDATA) dpcheng = (new PnlWdbeNavHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBENAVHIGHDATA) dpcheng = (new PnlWdbeNavHigh()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBENAVLOWDATA) dpcheng = (new PnlWdbeNavLow()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBENAVPREDATA) dpcheng = (new PnlWdbeNavPre()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPINAPARDATA) dpcheng = (new PnlWdbePinAPar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPINDATA) dpcheng = (new CrdWdbePin()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPINDETAILDATA) dpcheng = (new PnlWdbePinDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPINHEADBARDATA) dpcheng = (new PnlWdbePinHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPINLISTDATA) dpcheng = (new PnlWdbePinList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPINRECDATA) dpcheng = (new PnlWdbePinRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPHAPARDATA) dpcheng = (new PnlWdbePphAPar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPHDATA) dpcheng = (new CrdWdbePph()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPHDETAILDATA) dpcheng = (new PnlWdbePphDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPHHEADBARDATA) dpcheng = (new PnlWdbePphHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPHLISTDATA) dpcheng = (new PnlWdbePphList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPHMNMODULEDATA) dpcheng = (new PnlWdbePphMNModule()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPHRECDATA) dpcheng = (new PnlWdbePphRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPLDATA) dpcheng = (new CrdWdbePpl()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPLDETAILDATA) dpcheng = (new PnlWdbePplDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPLHEADBARDATA) dpcheng = (new PnlWdbePplHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPLLISTDATA) dpcheng = (new PnlWdbePplList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPLPPL1NSEGMENTDATA) dpcheng = (new PnlWdbePplPpl1NSegment()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPPLRECDATA) dpcheng = (new PnlWdbePplRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRCDATA) dpcheng = (new CrdWdbePrc()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRCDETAILDATA) dpcheng = (new PnlWdbePrcDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRCFSMFSM1NFSMSTATEDATA) dpcheng = (new PnlWdbePrcFsmFsm1NFsmstate()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRCFSMHK1NVECTORDATA) dpcheng = (new PnlWdbePrcFsmHk1NVector()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRCHEADBARDATA) dpcheng = (new PnlWdbePrcHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRCKHDLTYPEDATA) dpcheng = (new PnlWdbePrcKHdltype()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRCLISTDATA) dpcheng = (new PnlWdbePrcList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRCMGE1NSIGNALDATA) dpcheng = (new PnlWdbePrcMge1NSignal()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRCRECDATA) dpcheng = (new PnlWdbePrcRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRCREF1NSENSITIVITYDATA) dpcheng = (new PnlWdbePrcRef1NSensitivity()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRCREF1NVARIABLEDATA) dpcheng = (new PnlWdbePrcRef1NVariable()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRJDATA) dpcheng = (new CrdWdbePrj()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRJDETAILDATA) dpcheng = (new PnlWdbePrjDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRJHEADBARDATA) dpcheng = (new PnlWdbePrjHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRJLISTDATA) dpcheng = (new PnlWdbePrjList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRJMNPERSONDATA) dpcheng = (new PnlWdbePrjMNPerson()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRJPRJ1NVERSIONDATA) dpcheng = (new PnlWdbePrjPrj1NVersion()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRJRECDATA) dpcheng = (new PnlWdbePrjRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRSADETAILDATA) dpcheng = (new PnlWdbePrsADetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRSDATA) dpcheng = (new CrdWdbePrs()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRSDETAILDATA) dpcheng = (new PnlWdbePrsDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRSHEADBARDATA) dpcheng = (new PnlWdbePrsHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRSLISTDATA) dpcheng = (new PnlWdbePrsList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRSMNCOREPROJECTDATA) dpcheng = (new PnlWdbePrsMNCoreproject()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRSMNPROJECTDATA) dpcheng = (new PnlWdbePrsMNProject()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRSRECDATA) dpcheng = (new PnlWdbePrsRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRTDATA) dpcheng = (new CrdWdbePrt()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRTDETAILDATA) dpcheng = (new PnlWdbePrtDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRTHEADBARDATA) dpcheng = (new PnlWdbePrtHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRTLISTDATA) dpcheng = (new PnlWdbePrtList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRTRECDATA) dpcheng = (new PnlWdbePrtRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEPRTSRC1NSENSITIVITYDATA) dpcheng = (new PnlWdbePrtSrc1NSensitivity()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBERLSDATA) dpcheng = (new CrdWdbeRls()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBERLSDETAILDATA) dpcheng = (new PnlWdbeRlsDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBERLSHEADBARDATA) dpcheng = (new PnlWdbeRlsHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBERLSLISTDATA) dpcheng = (new PnlWdbeRlsList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBERLSRECDATA) dpcheng = (new PnlWdbeRlsRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESEGDATA) dpcheng = (new CrdWdbeSeg()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESEGDETAILDATA) dpcheng = (new PnlWdbeSegDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESEGHEADBARDATA) dpcheng = (new PnlWdbeSegHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESEGLISTDATA) dpcheng = (new PnlWdbeSegList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESEGRECDATA) dpcheng = (new PnlWdbeSegRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESEGSUP1NSEGMENTDATA) dpcheng = (new PnlWdbeSegSup1NSegment()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESIGDATA) dpcheng = (new CrdWdbeSig()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESIGDETAILDATA) dpcheng = (new PnlWdbeSigDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESIGHEADBARDATA) dpcheng = (new PnlWdbeSigHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESIGLISTDATA) dpcheng = (new PnlWdbeSigList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESIGMNCDCDATA) dpcheng = (new PnlWdbeSigMNCdc()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESIGRECDATA) dpcheng = (new PnlWdbeSigRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESIGSRC1NSENSITIVITYDATA) dpcheng = (new PnlWdbeSigSrc1NSensitivity()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESIL1NBANKDATA) dpcheng = (new PnlWdbeSil1NBank()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESIL1NINTERRUPTDATA) dpcheng = (new PnlWdbeSil1NInterrupt()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESIL1NPERIPHERALDATA) dpcheng = (new PnlWdbeSil1NPeripheral()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESILDATA) dpcheng = (new CrdWdbeSil()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESILDETAILDATA) dpcheng = (new PnlWdbeSilDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESILHEADBARDATA) dpcheng = (new PnlWdbeSilHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESILHK1NMODULEDATA) dpcheng = (new PnlWdbeSilHk1NModule()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESILHK1NVECTORDATA) dpcheng = (new PnlWdbeSilHk1NVector()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESILLISTDATA) dpcheng = (new PnlWdbeSilList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESILRECDATA) dpcheng = (new PnlWdbeSilRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESILREF1NCOMMANDDATA) dpcheng = (new PnlWdbeSilRef1NCommand()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESILREF1NERRORDATA) dpcheng = (new PnlWdbeSilRef1NError()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESILREF1NSIGNALDATA) dpcheng = (new PnlWdbeSilRef1NSignal()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESILSIL1NUNITDATA) dpcheng = (new PnlWdbeSilSil1NUnit()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESNSDATA) dpcheng = (new CrdWdbeSns()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESNSDETAILDATA) dpcheng = (new PnlWdbeSnsDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESNSHEADBARDATA) dpcheng = (new PnlWdbeSnsHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESNSLISTDATA) dpcheng = (new PnlWdbeSnsList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESNSRECDATA) dpcheng = (new PnlWdbeSnsRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBESUSPEND) dpcheng = new DpchEngWdbeSuspend();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNT1NBANKDATA) dpcheng = (new PnlWdbeUnt1NBank()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNT1NINTERRUPTDATA) dpcheng = (new PnlWdbeUnt1NInterrupt()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNT1NPERIPHERALDATA) dpcheng = (new PnlWdbeUnt1NPeripheral()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNTDATA) dpcheng = (new CrdWdbeUnt()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNTDETAILDATA) dpcheng = (new PnlWdbeUntDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNTHEADBARDATA) dpcheng = (new PnlWdbeUntHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNTHK1NMODULEDATA) dpcheng = (new PnlWdbeUntHk1NModule()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNTHK1NVECTORDATA) dpcheng = (new PnlWdbeUntHk1NVector()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNTLISTDATA) dpcheng = (new PnlWdbeUntList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNTRECDATA) dpcheng = (new PnlWdbeUntRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNTREF1NCOMMANDDATA) dpcheng = (new PnlWdbeUntRef1NCommand()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNTREF1NERRORDATA) dpcheng = (new PnlWdbeUntRef1NError()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNTREF1NSIGNALDATA) dpcheng = (new PnlWdbeUntRef1NSignal()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUNTSIL1NUNITDATA) dpcheng = (new PnlWdbeUntSil1NUnit()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSGAACCESSDATA) dpcheng = (new PnlWdbeUsgAAccess()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSGDATA) dpcheng = (new CrdWdbeUsg()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSGDETAILDATA) dpcheng = (new PnlWdbeUsgDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSGHEADBARDATA) dpcheng = (new PnlWdbeUsgHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSGLISTDATA) dpcheng = (new PnlWdbeUsgList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSGMNUSERDATA) dpcheng = (new PnlWdbeUsgMNUser()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSGRECDATA) dpcheng = (new PnlWdbeUsgRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSR1NSESSIONDATA) dpcheng = (new PnlWdbeUsr1NSession()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSRAACCESSDATA) dpcheng = (new PnlWdbeUsrAAccess()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSRDATA) dpcheng = (new CrdWdbeUsr()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSRDETAILDATA) dpcheng = (new PnlWdbeUsrDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSRHEADBARDATA) dpcheng = (new PnlWdbeUsrHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSRLISTDATA) dpcheng = (new PnlWdbeUsrList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSRMNUSERGROUPDATA) dpcheng = (new PnlWdbeUsrMNUsergroup()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUSRRECDATA) dpcheng = (new PnlWdbeUsrRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUTLDATA) dpcheng = (new CrdWdbeUtl()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEUTLHEADBARDATA) dpcheng = (new PnlWdbeUtlHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVARDATA) dpcheng = (new CrdWdbeVar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVARDETAILDATA) dpcheng = (new PnlWdbeVarDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVARHEADBARDATA) dpcheng = (new PnlWdbeVarHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVARLISTDATA) dpcheng = (new PnlWdbeVarList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVARRECDATA) dpcheng = (new PnlWdbeVarRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVECDATA) dpcheng = (new CrdWdbeVec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVECDETAILDATA) dpcheng = (new PnlWdbeVecDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVECHEADBARDATA) dpcheng = (new PnlWdbeVecHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVECLISTDATA) dpcheng = (new PnlWdbeVecList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVECRECDATA) dpcheng = (new PnlWdbeVecRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVECVEC1NVECTORITEMDATA) dpcheng = (new PnlWdbeVecVec1NVectoritem()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVER1NCOMPONENTDATA) dpcheng = (new PnlWdbeVer1NComponent()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVER1NUNITDATA) dpcheng = (new PnlWdbeVer1NUnit()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVERBVR1NVERSIONDATA) dpcheng = (new PnlWdbeVerBvr1NVersion()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVERDATA) dpcheng = (new CrdWdbeVer()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVERDETAILDATA) dpcheng = (new PnlWdbeVerDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVERHEADBARDATA) dpcheng = (new PnlWdbeVerHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVERLISTDATA) dpcheng = (new PnlWdbeVerList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVERRECDATA) dpcheng = (new PnlWdbeVerRec()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVERREF1NFILEDATA) dpcheng = (new PnlWdbeVerRef1NFile()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVITDATA) dpcheng = (new CrdWdbeVit()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVITDETAILDATA) dpcheng = (new PnlWdbeVitDetail()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVITHEADBARDATA) dpcheng = (new PnlWdbeVitHeadbar()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVITLISTDATA) dpcheng = (new PnlWdbeVitList()).new DpchEngData();
			else if (ixWdbeVDpch == VecWdbeVDpch.DPCHENGWDBEVITRECDATA) dpcheng = (new PnlWdbeVitRec()).new DpchEngData();

			if (dpcheng != null) dpcheng.readXML(doc,  "",  true);

		} catch (IOException e) {
			System.out.println(e.toString());
		} catch (ParserConfigurationException e) {
			System.out.println(e.toString());
		} catch (SAXException e) {
			System.out.println(e.toString());
		};

		return dpcheng;
	};

	public static String writeDpchApp(
				DpchAppWdbe dpchapp
			) {
		Document doc;
		StringWriter str = new StringWriter();

		try {
			doc = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
	
			dpchapp.writeXML(doc, null);
	
			Transformer tr = TransformerFactory.newInstance().newTransformer();
	
			tr.transform(new DOMSource(doc), new StreamResult(str));
	
			return(str.toString());

		} catch (ParserConfigurationException e) {
			System.out.println(e.toString());
		} catch (TransformerConfigurationException e) {
			System.out.println(e.toString());
		} catch (TransformerException e) {
			System.out.println(e.toString());
		};
		
		return "";
	};
};
