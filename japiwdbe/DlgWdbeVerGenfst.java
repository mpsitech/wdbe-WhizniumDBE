/**
  * \file DlgWdbeVerGenfst.java
  * Java API code for job DlgWdbeVerGenfst
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWdbeVerGenfst {
	/**
		* VecVDo (full: VecVDlgWdbeVerGenfstDo)
		*/
	public static class VecVDo {

		public static final int GFSBUTRUNCLICK = 1;
		public static final int GFSBUTSTOCLICK = 2;
		public static final int BUTDNECLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("gfsbutrunclick")) return GFSBUTRUNCLICK;
			if (s.equals("gfsbutstoclick")) return GFSBUTSTOCLICK;
			if (s.equals("butdneclick")) return BUTDNECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == GFSBUTRUNCLICK) return("GfsButRunClick");
			if (ix == GFSBUTSTOCLICK) return("GfsButStoClick");
			if (ix == BUTDNECLICK) return("ButDneClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWdbeVerGenfstSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int GENFST = 2;
		public static final int GENMTP = 3;
		public static final int DONE = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("genfst")) return GENFST;
			if (s.equals("genmtp")) return GENMTP;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == GENFST) return("genfst");
			if (ix == GENMTP) return("genmtp");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfDlgWdbeVerGenfst)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int GFSTXTPRG = 2;

		public ContInf(
					int numFSge
					, String GfsTxtPrg
				) {
			this.numFSge = numFSge;
			this.GfsTxtPrg = GfsTxtPrg;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, GFSTXTPRG));
		};

		public int numFSge;
		public String GfsTxtPrg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeVerGenfst");

			String itemtag = "ContitemInfDlgWdbeVerGenfst";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				GfsTxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "GfsTxtPrg", mask, GFSTXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (GfsTxtPrg.equals(comp.GfsTxtPrg)) items.add(GFSTXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, GFSTXTPRG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWdbeVerGenfst)
	  */
	public class StatApp extends Block {

		public static final int SHORTMENU = 1;

		public StatApp(
					String shortMenu
				) {
			this.shortMenu = shortMenu;

			mask = new HashSet<Integer>(Arrays.asList(SHORTMENU));
		};

		public String shortMenu;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWdbeVerGenfst");

			String itemtag = "StatitemAppDlgWdbeVerGenfst";

			if (Xmlio.checkXPath(doc, basexpath)) {
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SHORTMENU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrDlgWdbeVerGenfst)
	  */
	public class StatShr extends Block {

		public static final int GFSBUTRUNACTIVE = 1;
		public static final int GFSBUTSTOACTIVE = 2;
		public static final int BUTDNEACTIVE = 3;

		public StatShr(
					boolean GfsButRunActive
					, boolean GfsButStoActive
					, boolean ButDneActive
				) {
			this.GfsButRunActive = GfsButRunActive;
			this.GfsButStoActive = GfsButStoActive;
			this.ButDneActive = ButDneActive;

			mask = new HashSet<Integer>(Arrays.asList(GFSBUTRUNACTIVE, GFSBUTSTOACTIVE, BUTDNEACTIVE));
		};

		public boolean GfsButRunActive;
		public boolean GfsButStoActive;
		public boolean ButDneActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeVerGenfst");

			String itemtag = "StatitemShrDlgWdbeVerGenfst";

			if (Xmlio.checkXPath(doc, basexpath)) {
				GfsButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "GfsButRunActive", mask, GFSBUTRUNACTIVE);
				GfsButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "GfsButStoActive", mask, GFSBUTSTOACTIVE);
				ButDneActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDneActive", mask, BUTDNEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (GfsButRunActive == comp.GfsButRunActive) items.add(GFSBUTRUNACTIVE);
			if (GfsButStoActive == comp.GfsButStoActive) items.add(GFSBUTSTOACTIVE);
			if (ButDneActive == comp.ButDneActive) items.add(BUTDNEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(GFSBUTRUNACTIVE, GFSBUTSTOACTIVE, BUTDNEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWdbeVerGenfst)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int GFSCPTPRG = 2;
		public static final int GFSBUTRUN = 3;
		public static final int GFSBUTSTO = 4;
		public static final int BUTDNE = 5;

		public Tag(
					String Cpt
					, String GfsCptPrg
					, String GfsButRun
					, String GfsButSto
					, String ButDne
				) {
			this.Cpt = Cpt;
			this.GfsCptPrg = GfsCptPrg;
			this.GfsButRun = GfsButRun;
			this.GfsButSto = GfsButSto;
			this.ButDne = ButDne;

			mask = new HashSet<Integer>(Arrays.asList(CPT, GFSCPTPRG, GFSBUTRUN, GFSBUTSTO, BUTDNE));
		};

		public String Cpt;
		public String GfsCptPrg;
		public String GfsButRun;
		public String GfsButSto;
		public String ButDne;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeVerGenfst");

			String itemtag = "TagitemDlgWdbeVerGenfst";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				GfsCptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "GfsCptPrg", mask, GFSCPTPRG);
				GfsButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "GfsButRun", mask, GFSBUTRUN);
				GfsButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "GfsButSto", mask, GFSBUTSTO);
				ButDne = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButDne", mask, BUTDNE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (GfsCptPrg.equals(comp.GfsCptPrg)) items.add(GFSCPTPRG);
			if (GfsButRun.equals(comp.GfsButRun)) items.add(GFSBUTRUN);
			if (GfsButSto.equals(comp.GfsButSto)) items.add(GFSBUTSTO);
			if (ButDne.equals(comp.ButDne)) items.add(BUTDNE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, GFSCPTPRG, GFSBUTRUN, GFSBUTSTO, BUTDNE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeVerGenfstDo)
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
			super(VecWdbeVDpch.DPCHAPPDLGWDBEVERGENFSTDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWdbeVerGenfstDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeVerGenfstData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGDLGWDBEVERGENFSTDATA);

			continf = new ContInf(0, "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp("");
			statshr = new StatShr(false, false, false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWdbeVerGenfstData");

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
				statapp = new StatApp("");
				statshr = new StatShr(false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};
