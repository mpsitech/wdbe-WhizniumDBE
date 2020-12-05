/**
  * \file CrdWdbeCvr.java
  * Java API code for job CrdWdbeCvr
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdWdbeCvr {
	/**
		* VecVDo (full: VecVWdbeCvrDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;
		public static final int MITCRDNEWCLICK = 3;
		public static final int MITCRDIBSCLICK = 4;
		public static final int MITCRDIDSCLICK = 5;
		public static final int MITCRDWCOCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;
			if (s.equals("mitcrdnewclick")) return MITCRDNEWCLICK;
			if (s.equals("mitcrdibsclick")) return MITCRDIBSCLICK;
			if (s.equals("mitcrdidsclick")) return MITCRDIDSCLICK;
			if (s.equals("mitcrdwcoclick")) return MITCRDWCOCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
			if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
			if (ix == MITCRDIBSCLICK) return("MitCrdIbsClick");
			if (ix == MITCRDIDSCLICK) return("MitCrdIdsClick");
			if (ix == MITCRDWCOCLICK) return("MitCrdWcoClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVWdbeCvrSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRWDBEABT = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrwdbeabt")) return ALRWDBEABT;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRWDBEABT) return("alrwdbeabt");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWdbeCvr)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MTXCRDCVR = 3;

		public ContInf(
					int numFSge
					, String MrlAppHlp
					, String MtxCrdCvr
				) {
			this.numFSge = numFSge;
			this.MrlAppHlp = MrlAppHlp;
			this.MtxCrdCvr = MtxCrdCvr;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXCRDCVR));
		};

		public int numFSge;
		public String MrlAppHlp;
		public String MtxCrdCvr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeCvr");

			String itemtag = "ContitemInfWdbeCvr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MtxCrdCvr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxCrdCvr", mask, MTXCRDCVR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (MrlAppHlp.equals(comp.MrlAppHlp)) items.add(MRLAPPHLP);
			if (MtxCrdCvr.equals(comp.MtxCrdCvr)) items.add(MTXCRDCVR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXCRDCVR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeCvr)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONEHEADBAR = 5;
		public static final int INITDONELIST = 6;
		public static final int INITDONEREC = 7;

		public StatApp(
					int ixWdbeVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneHeadbar
					, boolean initdoneList
					, boolean initdoneRec
				) {
			this.ixWdbeVReqitmode = ixWdbeVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneHeadbar = initdoneHeadbar;
			this.initdoneList = initdoneList;
			this.initdoneRec = initdoneRec;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC));
		};

		public int ixWdbeVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneHeadbar;
		public boolean initdoneList;
		public boolean initdoneRec;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeCvr");

			String itemtag = "StatitemAppWdbeCvr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVReqitmode", mask, IXWDBEVREQITMODE);
				ixWdbeVReqitmode = VecWdbeVReqitmode.getIx(srefIxWdbeVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneHeadbar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", mask, INITDONEHEADBAR);
				initdoneList = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneList", mask, INITDONELIST);
				initdoneRec = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRec", mask, INITDONEREC);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVReqitmode == comp.ixWdbeVReqitmode) items.add(IXWDBEVREQITMODE);
			if (latency == comp.latency) items.add(LATENCY);
			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);
			if (widthMenu == comp.widthMenu) items.add(WIDTHMENU);
			if (initdoneHeadbar == comp.initdoneHeadbar) items.add(INITDONEHEADBAR);
			if (initdoneList == comp.initdoneList) items.add(INITDONELIST);
			if (initdoneRec == comp.initdoneRec) items.add(INITDONEREC);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeCvr)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFDLGBSCCD = 1;
		public static final int SCRJREFDLGDETCD = 2;
		public static final int SCRJREFDLGNEW = 3;
		public static final int SCRJREFDLGWRITE = 4;
		public static final int SCRJREFHEADBAR = 5;
		public static final int SCRJREFLIST = 6;
		public static final int SCRJREFREC = 7;
		public static final int MSPCRD1AVAIL = 8;
		public static final int MITCRDNEWAVAIL = 9;
		public static final int MITCRDIBSAVAIL = 10;
		public static final int MITCRDIBSACTIVE = 11;
		public static final int MITCRDIDSAVAIL = 12;
		public static final int MITCRDIDSACTIVE = 13;
		public static final int MSPCRD2AVAIL = 14;
		public static final int MITCRDWCOAVAIL = 15;
		public static final int MITCRDWCOACTIVE = 16;

		public StatShr(
					String scrJrefDlgbsccd
					, String scrJrefDlgdetcd
					, String scrJrefDlgnew
					, String scrJrefDlgwrite
					, String scrJrefHeadbar
					, String scrJrefList
					, String scrJrefRec
					, boolean MspCrd1Avail
					, boolean MitCrdNewAvail
					, boolean MitCrdIbsAvail
					, boolean MitCrdIbsActive
					, boolean MitCrdIdsAvail
					, boolean MitCrdIdsActive
					, boolean MspCrd2Avail
					, boolean MitCrdWcoAvail
					, boolean MitCrdWcoActive
				) {
			this.scrJrefDlgbsccd = scrJrefDlgbsccd;
			this.scrJrefDlgdetcd = scrJrefDlgdetcd;
			this.scrJrefDlgnew = scrJrefDlgnew;
			this.scrJrefDlgwrite = scrJrefDlgwrite;
			this.scrJrefHeadbar = scrJrefHeadbar;
			this.scrJrefList = scrJrefList;
			this.scrJrefRec = scrJrefRec;
			this.MspCrd1Avail = MspCrd1Avail;
			this.MitCrdNewAvail = MitCrdNewAvail;
			this.MitCrdIbsAvail = MitCrdIbsAvail;
			this.MitCrdIbsActive = MitCrdIbsActive;
			this.MitCrdIdsAvail = MitCrdIdsAvail;
			this.MitCrdIdsActive = MitCrdIdsActive;
			this.MspCrd2Avail = MspCrd2Avail;
			this.MitCrdWcoAvail = MitCrdWcoAvail;
			this.MitCrdWcoActive = MitCrdWcoActive;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFDLGBSCCD, SCRJREFDLGDETCD, SCRJREFDLGNEW, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDIBSAVAIL, MITCRDIBSACTIVE, MITCRDIDSAVAIL, MITCRDIDSACTIVE, MSPCRD2AVAIL, MITCRDWCOAVAIL, MITCRDWCOACTIVE));
		};

		public String scrJrefDlgbsccd;
		public String scrJrefDlgdetcd;
		public String scrJrefDlgnew;
		public String scrJrefDlgwrite;
		public String scrJrefHeadbar;
		public String scrJrefList;
		public String scrJrefRec;
		public boolean MspCrd1Avail;
		public boolean MitCrdNewAvail;
		public boolean MitCrdIbsAvail;
		public boolean MitCrdIbsActive;
		public boolean MitCrdIdsAvail;
		public boolean MitCrdIdsActive;
		public boolean MspCrd2Avail;
		public boolean MitCrdWcoAvail;
		public boolean MitCrdWcoActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeCvr");

			String itemtag = "StatitemShrWdbeCvr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefDlgbsccd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgbsccd", mask, SCRJREFDLGBSCCD);
				scrJrefDlgdetcd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgdetcd", mask, SCRJREFDLGDETCD);
				scrJrefDlgnew = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", mask, SCRJREFDLGNEW);
				scrJrefDlgwrite = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgwrite", mask, SCRJREFDLGWRITE);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);
				scrJrefList = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefList", mask, SCRJREFLIST);
				scrJrefRec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRec", mask, SCRJREFREC);
				MspCrd1Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", mask, MSPCRD1AVAIL);
				MitCrdNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", mask, MITCRDNEWAVAIL);
				MitCrdIbsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIbsAvail", mask, MITCRDIBSAVAIL);
				MitCrdIbsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIbsActive", mask, MITCRDIBSACTIVE);
				MitCrdIdsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIdsAvail", mask, MITCRDIDSAVAIL);
				MitCrdIdsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIdsActive", mask, MITCRDIDSACTIVE);
				MspCrd2Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", mask, MSPCRD2AVAIL);
				MitCrdWcoAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdWcoAvail", mask, MITCRDWCOAVAIL);
				MitCrdWcoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdWcoActive", mask, MITCRDWCOACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefDlgbsccd.equals(comp.scrJrefDlgbsccd)) items.add(SCRJREFDLGBSCCD);
			if (scrJrefDlgdetcd.equals(comp.scrJrefDlgdetcd)) items.add(SCRJREFDLGDETCD);
			if (scrJrefDlgnew.equals(comp.scrJrefDlgnew)) items.add(SCRJREFDLGNEW);
			if (scrJrefDlgwrite.equals(comp.scrJrefDlgwrite)) items.add(SCRJREFDLGWRITE);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);
			if (scrJrefList.equals(comp.scrJrefList)) items.add(SCRJREFLIST);
			if (scrJrefRec.equals(comp.scrJrefRec)) items.add(SCRJREFREC);
			if (MspCrd1Avail == comp.MspCrd1Avail) items.add(MSPCRD1AVAIL);
			if (MitCrdNewAvail == comp.MitCrdNewAvail) items.add(MITCRDNEWAVAIL);
			if (MitCrdIbsAvail == comp.MitCrdIbsAvail) items.add(MITCRDIBSAVAIL);
			if (MitCrdIbsActive == comp.MitCrdIbsActive) items.add(MITCRDIBSACTIVE);
			if (MitCrdIdsAvail == comp.MitCrdIdsAvail) items.add(MITCRDIDSAVAIL);
			if (MitCrdIdsActive == comp.MitCrdIdsActive) items.add(MITCRDIDSACTIVE);
			if (MspCrd2Avail == comp.MspCrd2Avail) items.add(MSPCRD2AVAIL);
			if (MitCrdWcoAvail == comp.MitCrdWcoAvail) items.add(MITCRDWCOAVAIL);
			if (MitCrdWcoActive == comp.MitCrdWcoActive) items.add(MITCRDWCOACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFDLGBSCCD, SCRJREFDLGDETCD, SCRJREFDLGNEW, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDIBSAVAIL, MITCRDIBSACTIVE, MITCRDIDSAVAIL, MITCRDIDSACTIVE, MSPCRD2AVAIL, MITCRDWCOAVAIL, MITCRDWCOACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeCvr)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MITCRDNEW = 3;
		public static final int MITCRDIBS = 4;
		public static final int MITCRDIDS = 5;
		public static final int MITCRDWCO = 6;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
					, String MitCrdNew
					, String MitCrdIbs
					, String MitCrdIds
					, String MitCrdWco
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;
			this.MitCrdNew = MitCrdNew;
			this.MitCrdIbs = MitCrdIbs;
			this.MitCrdIds = MitCrdIds;
			this.MitCrdWco = MitCrdWco;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDIBS, MITCRDIDS, MITCRDWCO));
		};

		public String MitAppAbt;
		public String MrlAppHlp;
		public String MitCrdNew;
		public String MitCrdIbs;
		public String MitCrdIds;
		public String MitCrdWco;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeCvr");

			String itemtag = "TagitemWdbeCvr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MitCrdNew = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdNew", mask, MITCRDNEW);
				MitCrdIbs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIbs", mask, MITCRDIBS);
				MitCrdIds = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIds", mask, MITCRDIDS);
				MitCrdWco = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdWco", mask, MITCRDWCO);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (MitAppAbt.equals(comp.MitAppAbt)) items.add(MITAPPABT);
			if (MrlAppHlp.equals(comp.MrlAppHlp)) items.add(MRLAPPHLP);
			if (MitCrdNew.equals(comp.MitCrdNew)) items.add(MITCRDNEW);
			if (MitCrdIbs.equals(comp.MitCrdIbs)) items.add(MITCRDIBS);
			if (MitCrdIds.equals(comp.MitCrdIds)) items.add(MITCRDIDS);
			if (MitCrdWco.equals(comp.MitCrdWco)) items.add(MITCRDWCO);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDIBS, MITCRDIDS, MITCRDWCO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeCvrDo)
		*/
	public class DpchAppDo extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int ALL = 3;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPWDBECVRDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO));
					break;
				};

			this.ixVDo = ixVDo;
		};

		public int ixVDo;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWdbeCvrDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeCvrData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBECVRDATA);

			continf = new ContInf(0, "", "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false, false, false);
			statshr = new StatShr("", "", "", "", "", "", "", false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContInf continf;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFSGE)) ss.add("feedFSge");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(TAG)) ss.add("tag");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeCvrData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(0, "", "");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(0, 0, "", 0, false, false, false);
				statshr = new StatShr("", "", "", "", "", "", "", false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};

