/**
  * \file CrdWdbeRls.java
  * Java API code for job CrdWdbeRls
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdWdbeRls {
	/**
		* VecVDo (full: VecVWdbeRlsDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;
		public static final int MITCRDNEWCLICK = 3;
		public static final int MITCRDSRTCLICK = 4;
		public static final int MITCRDCRTCLICK = 5;
		public static final int MITCRDFRTCLICK = 6;
		public static final int MITCRDWCOCLICK = 7;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;
			if (s.equals("mitcrdnewclick")) return MITCRDNEWCLICK;
			if (s.equals("mitcrdsrtclick")) return MITCRDSRTCLICK;
			if (s.equals("mitcrdcrtclick")) return MITCRDCRTCLICK;
			if (s.equals("mitcrdfrtclick")) return MITCRDFRTCLICK;
			if (s.equals("mitcrdwcoclick")) return MITCRDWCOCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
			if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
			if (ix == MITCRDSRTCLICK) return("MitCrdSrtClick");
			if (ix == MITCRDCRTCLICK) return("MitCrdCrtClick");
			if (ix == MITCRDFRTCLICK) return("MitCrdFrtClick");
			if (ix == MITCRDWCOCLICK) return("MitCrdWcoClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVWdbeRlsSge)
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
	  * ContInf (full: ContInfWdbeRls)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MTXCRDRLS = 3;

		public ContInf(
					int numFSge
					, String MrlAppHlp
					, String MtxCrdRls
				) {
			this.numFSge = numFSge;
			this.MrlAppHlp = MrlAppHlp;
			this.MtxCrdRls = MtxCrdRls;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXCRDRLS));
		};

		public int numFSge;
		public String MrlAppHlp;
		public String MtxCrdRls;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeRls");

			String itemtag = "ContitemInfWdbeRls";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MtxCrdRls = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxCrdRls", mask, MTXCRDRLS);

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
			if (MtxCrdRls.equals(comp.MtxCrdRls)) items.add(MTXCRDRLS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXCRDRLS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeRls)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeRls");

			String itemtag = "StatitemAppWdbeRls";

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
	  * StatShr (full: StatShrWdbeRls)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFDLGFINREPTR = 1;
		public static final int SCRJREFDLGNEW = 2;
		public static final int SCRJREFDLGSTAREPTR = 3;
		public static final int SCRJREFDLGWRITE = 4;
		public static final int SCRJREFHEADBAR = 5;
		public static final int SCRJREFLIST = 6;
		public static final int SCRJREFREC = 7;
		public static final int MSPCRD1AVAIL = 8;
		public static final int MITCRDNEWAVAIL = 9;
		public static final int MITCRDSRTAVAIL = 10;
		public static final int MITCRDSRTACTIVE = 11;
		public static final int MITCRDCRTAVAIL = 12;
		public static final int MITCRDCRTACTIVE = 13;
		public static final int MITCRDFRTAVAIL = 14;
		public static final int MITCRDFRTACTIVE = 15;
		public static final int MITCRDWCOAVAIL = 16;
		public static final int MITCRDWCOACTIVE = 17;

		public StatShr(
					String scrJrefDlgfinreptr
					, String scrJrefDlgnew
					, String scrJrefDlgstareptr
					, String scrJrefDlgwrite
					, String scrJrefHeadbar
					, String scrJrefList
					, String scrJrefRec
					, boolean MspCrd1Avail
					, boolean MitCrdNewAvail
					, boolean MitCrdSrtAvail
					, boolean MitCrdSrtActive
					, boolean MitCrdCrtAvail
					, boolean MitCrdCrtActive
					, boolean MitCrdFrtAvail
					, boolean MitCrdFrtActive
					, boolean MitCrdWcoAvail
					, boolean MitCrdWcoActive
				) {
			this.scrJrefDlgfinreptr = scrJrefDlgfinreptr;
			this.scrJrefDlgnew = scrJrefDlgnew;
			this.scrJrefDlgstareptr = scrJrefDlgstareptr;
			this.scrJrefDlgwrite = scrJrefDlgwrite;
			this.scrJrefHeadbar = scrJrefHeadbar;
			this.scrJrefList = scrJrefList;
			this.scrJrefRec = scrJrefRec;
			this.MspCrd1Avail = MspCrd1Avail;
			this.MitCrdNewAvail = MitCrdNewAvail;
			this.MitCrdSrtAvail = MitCrdSrtAvail;
			this.MitCrdSrtActive = MitCrdSrtActive;
			this.MitCrdCrtAvail = MitCrdCrtAvail;
			this.MitCrdCrtActive = MitCrdCrtActive;
			this.MitCrdFrtAvail = MitCrdFrtAvail;
			this.MitCrdFrtActive = MitCrdFrtActive;
			this.MitCrdWcoAvail = MitCrdWcoAvail;
			this.MitCrdWcoActive = MitCrdWcoActive;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFDLGFINREPTR, SCRJREFDLGNEW, SCRJREFDLGSTAREPTR, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDSRTAVAIL, MITCRDSRTACTIVE, MITCRDCRTAVAIL, MITCRDCRTACTIVE, MITCRDFRTAVAIL, MITCRDFRTACTIVE, MITCRDWCOAVAIL, MITCRDWCOACTIVE));
		};

		public String scrJrefDlgfinreptr;
		public String scrJrefDlgnew;
		public String scrJrefDlgstareptr;
		public String scrJrefDlgwrite;
		public String scrJrefHeadbar;
		public String scrJrefList;
		public String scrJrefRec;
		public boolean MspCrd1Avail;
		public boolean MitCrdNewAvail;
		public boolean MitCrdSrtAvail;
		public boolean MitCrdSrtActive;
		public boolean MitCrdCrtAvail;
		public boolean MitCrdCrtActive;
		public boolean MitCrdFrtAvail;
		public boolean MitCrdFrtActive;
		public boolean MitCrdWcoAvail;
		public boolean MitCrdWcoActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeRls");

			String itemtag = "StatitemShrWdbeRls";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefDlgfinreptr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgfinreptr", mask, SCRJREFDLGFINREPTR);
				scrJrefDlgnew = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", mask, SCRJREFDLGNEW);
				scrJrefDlgstareptr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgstareptr", mask, SCRJREFDLGSTAREPTR);
				scrJrefDlgwrite = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgwrite", mask, SCRJREFDLGWRITE);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);
				scrJrefList = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefList", mask, SCRJREFLIST);
				scrJrefRec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRec", mask, SCRJREFREC);
				MspCrd1Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", mask, MSPCRD1AVAIL);
				MitCrdNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", mask, MITCRDNEWAVAIL);
				MitCrdSrtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSrtAvail", mask, MITCRDSRTAVAIL);
				MitCrdSrtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSrtActive", mask, MITCRDSRTACTIVE);
				MitCrdCrtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCrtAvail", mask, MITCRDCRTAVAIL);
				MitCrdCrtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCrtActive", mask, MITCRDCRTACTIVE);
				MitCrdFrtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdFrtAvail", mask, MITCRDFRTAVAIL);
				MitCrdFrtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdFrtActive", mask, MITCRDFRTACTIVE);
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

			if (scrJrefDlgfinreptr.equals(comp.scrJrefDlgfinreptr)) items.add(SCRJREFDLGFINREPTR);
			if (scrJrefDlgnew.equals(comp.scrJrefDlgnew)) items.add(SCRJREFDLGNEW);
			if (scrJrefDlgstareptr.equals(comp.scrJrefDlgstareptr)) items.add(SCRJREFDLGSTAREPTR);
			if (scrJrefDlgwrite.equals(comp.scrJrefDlgwrite)) items.add(SCRJREFDLGWRITE);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);
			if (scrJrefList.equals(comp.scrJrefList)) items.add(SCRJREFLIST);
			if (scrJrefRec.equals(comp.scrJrefRec)) items.add(SCRJREFREC);
			if (MspCrd1Avail == comp.MspCrd1Avail) items.add(MSPCRD1AVAIL);
			if (MitCrdNewAvail == comp.MitCrdNewAvail) items.add(MITCRDNEWAVAIL);
			if (MitCrdSrtAvail == comp.MitCrdSrtAvail) items.add(MITCRDSRTAVAIL);
			if (MitCrdSrtActive == comp.MitCrdSrtActive) items.add(MITCRDSRTACTIVE);
			if (MitCrdCrtAvail == comp.MitCrdCrtAvail) items.add(MITCRDCRTAVAIL);
			if (MitCrdCrtActive == comp.MitCrdCrtActive) items.add(MITCRDCRTACTIVE);
			if (MitCrdFrtAvail == comp.MitCrdFrtAvail) items.add(MITCRDFRTAVAIL);
			if (MitCrdFrtActive == comp.MitCrdFrtActive) items.add(MITCRDFRTACTIVE);
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

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFDLGFINREPTR, SCRJREFDLGNEW, SCRJREFDLGSTAREPTR, SCRJREFDLGWRITE, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDSRTAVAIL, MITCRDSRTACTIVE, MITCRDCRTAVAIL, MITCRDCRTACTIVE, MITCRDFRTAVAIL, MITCRDFRTACTIVE, MITCRDWCOAVAIL, MITCRDWCOACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeRls)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MITCRDNEW = 3;
		public static final int MITCRDSRT = 4;
		public static final int MITCRDCRT = 5;
		public static final int MITCRDFRT = 6;
		public static final int MITCRDWCO = 7;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
					, String MitCrdNew
					, String MitCrdSrt
					, String MitCrdCrt
					, String MitCrdFrt
					, String MitCrdWco
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;
			this.MitCrdNew = MitCrdNew;
			this.MitCrdSrt = MitCrdSrt;
			this.MitCrdCrt = MitCrdCrt;
			this.MitCrdFrt = MitCrdFrt;
			this.MitCrdWco = MitCrdWco;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDSRT, MITCRDCRT, MITCRDFRT, MITCRDWCO));
		};

		public String MitAppAbt;
		public String MrlAppHlp;
		public String MitCrdNew;
		public String MitCrdSrt;
		public String MitCrdCrt;
		public String MitCrdFrt;
		public String MitCrdWco;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeRls");

			String itemtag = "TagitemWdbeRls";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MitCrdNew = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdNew", mask, MITCRDNEW);
				MitCrdSrt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdSrt", mask, MITCRDSRT);
				MitCrdCrt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCrt", mask, MITCRDCRT);
				MitCrdFrt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdFrt", mask, MITCRDFRT);
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
			if (MitCrdSrt.equals(comp.MitCrdSrt)) items.add(MITCRDSRT);
			if (MitCrdCrt.equals(comp.MitCrdCrt)) items.add(MITCRDCRT);
			if (MitCrdFrt.equals(comp.MitCrdFrt)) items.add(MITCRDFRT);
			if (MitCrdWco.equals(comp.MitCrdWco)) items.add(MITCRDWCO);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDSRT, MITCRDCRT, MITCRDFRT, MITCRDWCO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeRlsDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBERLSDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeRlsDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeRlsData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBERLSDATA);

			continf = new ContInf(0, "", "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false, false, false);
			statshr = new StatShr("", "", "", "", "", "", "", false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeRlsData");

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
				statshr = new StatShr("", "", "", "", "", "", "", false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "");
			};
		};

	};

};

