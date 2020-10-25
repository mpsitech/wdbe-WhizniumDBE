/**
  * \file CrdWdbeUtl.java
  * Java API code for job CrdWdbeUtl
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdWdbeUtl {
	/**
		* VecVDo (full: VecVWdbeUtlDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;
		public static final int MITCRDCIFCLICK = 3;
		public static final int MITCRDXIPCLICK = 4;
		public static final int MITCRDMIPCLICK = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;
			if (s.equals("mitcrdcifclick")) return MITCRDCIFCLICK;
			if (s.equals("mitcrdxipclick")) return MITCRDXIPCLICK;
			if (s.equals("mitcrdmipclick")) return MITCRDMIPCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
			if (ix == MITCRDCIFCLICK) return("MitCrdCifClick");
			if (ix == MITCRDXIPCLICK) return("MitCrdXipClick");
			if (ix == MITCRDMIPCLICK) return("MitCrdMipClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVWdbeUtlSge)
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
	  * ContInf (full: ContInfWdbeUtl)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int MRLAPPHLP = 2;

		public ContInf(
					int numFSge
					, String MrlAppHlp
				) {
			this.numFSge = numFSge;
			this.MrlAppHlp = MrlAppHlp;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP));
		};

		public int numFSge;
		public String MrlAppHlp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeUtl");

			String itemtag = "ContitemInfWdbeUtl";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", mask, MRLAPPHLP);

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

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeUtl)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONEHEADBAR = 5;

		public StatApp(
					int ixWdbeVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneHeadbar
				) {
			this.ixWdbeVReqitmode = ixWdbeVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneHeadbar = initdoneHeadbar;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR));
		};

		public int ixWdbeVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneHeadbar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeUtl");

			String itemtag = "StatitemAppWdbeUtl";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVReqitmode", mask, IXWDBEVREQITMODE);
				ixWdbeVReqitmode = VecWdbeVReqitmode.getIx(srefIxWdbeVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneHeadbar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", mask, INITDONEHEADBAR);

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

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeUtl)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFDLGEXTRIP = 1;
		public static final int SCRJREFDLGIEXCONV = 2;
		public static final int SCRJREFDLGMRGIP = 3;
		public static final int SCRJREFHEADBAR = 4;

		public StatShr(
					String scrJrefDlgextrip
					, String scrJrefDlgiexconv
					, String scrJrefDlgmrgip
					, String scrJrefHeadbar
				) {
			this.scrJrefDlgextrip = scrJrefDlgextrip;
			this.scrJrefDlgiexconv = scrJrefDlgiexconv;
			this.scrJrefDlgmrgip = scrJrefDlgmrgip;
			this.scrJrefHeadbar = scrJrefHeadbar;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFDLGEXTRIP, SCRJREFDLGIEXCONV, SCRJREFDLGMRGIP, SCRJREFHEADBAR));
		};

		public String scrJrefDlgextrip;
		public String scrJrefDlgiexconv;
		public String scrJrefDlgmrgip;
		public String scrJrefHeadbar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeUtl");

			String itemtag = "StatitemShrWdbeUtl";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefDlgextrip = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgextrip", mask, SCRJREFDLGEXTRIP);
				scrJrefDlgiexconv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgiexconv", mask, SCRJREFDLGIEXCONV);
				scrJrefDlgmrgip = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgmrgip", mask, SCRJREFDLGMRGIP);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefDlgextrip.equals(comp.scrJrefDlgextrip)) items.add(SCRJREFDLGEXTRIP);
			if (scrJrefDlgiexconv.equals(comp.scrJrefDlgiexconv)) items.add(SCRJREFDLGIEXCONV);
			if (scrJrefDlgmrgip.equals(comp.scrJrefDlgmrgip)) items.add(SCRJREFDLGMRGIP);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFDLGEXTRIP, SCRJREFDLGIEXCONV, SCRJREFDLGMRGIP, SCRJREFHEADBAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeUtl)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MITCRDCIF = 3;
		public static final int MITCRDXIP = 4;
		public static final int MITCRDMIP = 5;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
					, String MitCrdCif
					, String MitCrdXip
					, String MitCrdMip
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;
			this.MitCrdCif = MitCrdCif;
			this.MitCrdXip = MitCrdXip;
			this.MitCrdMip = MitCrdMip;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDCIF, MITCRDXIP, MITCRDMIP));
		};

		public String MitAppAbt;
		public String MrlAppHlp;
		public String MitCrdCif;
		public String MitCrdXip;
		public String MitCrdMip;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeUtl");

			String itemtag = "TagitemWdbeUtl";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MitCrdCif = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCif", mask, MITCRDCIF);
				MitCrdXip = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdXip", mask, MITCRDXIP);
				MitCrdMip = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdMip", mask, MITCRDMIP);

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
			if (MitCrdCif.equals(comp.MitCrdCif)) items.add(MITCRDCIF);
			if (MitCrdXip.equals(comp.MitCrdXip)) items.add(MITCRDXIP);
			if (MitCrdMip.equals(comp.MitCrdMip)) items.add(MITCRDMIP);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDCIF, MITCRDXIP, MITCRDMIP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeUtlDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEUTLDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeUtlDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeUtlData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEUTLDATA);

			continf = new ContInf(0, "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false);
			statshr = new StatShr("", "", "", "");
			tag = new Tag("", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeUtlData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(0, "");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(0, 0, "", 0, false);
				statshr = new StatShr("", "", "", "");
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};

