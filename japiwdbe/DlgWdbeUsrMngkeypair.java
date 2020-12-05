/**
  * \file DlgWdbeUsrMngkeypair.java
  * Java API code for job DlgWdbeUsrMngkeypair
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWdbeUsrMngkeypair {
	/**
		* VecVDo (full: VecVDlgWdbeUsrMngkeypairDo)
		*/
	public static class VecVDo {

		public static final int DETBUTDELCLICK = 1;
		public static final int DETBUTGENCLICK = 2;
		public static final int BUTDNECLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("detbutdelclick")) return DETBUTDELCLICK;
			if (s.equals("detbutgenclick")) return DETBUTGENCLICK;
			if (s.equals("butdneclick")) return BUTDNECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == DETBUTDELCLICK) return("DetButDelClick");
			if (ix == DETBUTGENCLICK) return("DetButGenClick");
			if (ix == BUTDNECLICK) return("ButDneClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWdbeUsrMngkeypairSge)
		*/
	public static class VecVSge {

		public static final int NF = 1;
		public static final int FOUND = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("nf")) return NF;
			if (s.equals("found")) return FOUND;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == NF) return("nf");
			if (ix == FOUND) return("found");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfDlgWdbeUsrMngkeypair)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int DETTXTSTE = 2;
		public static final int DETDLD = 3;

		public ContInf(
					int numFSge
					, String DetTxtSte
					, String DetDld
				) {
			this.numFSge = numFSge;
			this.DetTxtSte = DetTxtSte;
			this.DetDld = DetDld;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, DETTXTSTE, DETDLD));
		};

		public int numFSge;
		public String DetTxtSte;
		public String DetDld;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeUsrMngkeypair");

			String itemtag = "ContitemInfDlgWdbeUsrMngkeypair";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				DetTxtSte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxtSte", mask, DETTXTSTE);
				DetDld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetDld", mask, DETDLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (DetTxtSte.equals(comp.DetTxtSte)) items.add(DETTXTSTE);
			if (DetDld.equals(comp.DetDld)) items.add(DETDLD);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, DETTXTSTE, DETDLD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWdbeUsrMngkeypair)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWdbeUsrMngkeypair");

			String itemtag = "StatitemAppDlgWdbeUsrMngkeypair";

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
	  * StatShr (full: StatShrDlgWdbeUsrMngkeypair)
	  */
	public class StatShr extends Block {

		public static final int DETBUTDELAVAIL = 1;
		public static final int DETBUTGENAVAIL = 2;
		public static final int DETDLDACTIVE = 3;

		public StatShr(
					boolean DetButDelAvail
					, boolean DetButGenAvail
					, boolean DetDldActive
				) {
			this.DetButDelAvail = DetButDelAvail;
			this.DetButGenAvail = DetButGenAvail;
			this.DetDldActive = DetDldActive;

			mask = new HashSet<Integer>(Arrays.asList(DETBUTDELAVAIL, DETBUTGENAVAIL, DETDLDACTIVE));
		};

		public boolean DetButDelAvail;
		public boolean DetButGenAvail;
		public boolean DetDldActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeUsrMngkeypair");

			String itemtag = "StatitemShrDlgWdbeUsrMngkeypair";

			if (Xmlio.checkXPath(doc, basexpath)) {
				DetButDelAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DetButDelAvail", mask, DETBUTDELAVAIL);
				DetButGenAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DetButGenAvail", mask, DETBUTGENAVAIL);
				DetDldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DetDldActive", mask, DETDLDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (DetButDelAvail == comp.DetButDelAvail) items.add(DETBUTDELAVAIL);
			if (DetButGenAvail == comp.DetButGenAvail) items.add(DETBUTGENAVAIL);
			if (DetDldActive == comp.DetDldActive) items.add(DETDLDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DETBUTDELAVAIL, DETBUTGENAVAIL, DETDLDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWdbeUsrMngkeypair)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int DETCPTSTE = 2;
		public static final int DETBUTDEL = 3;
		public static final int DETBUTGEN = 4;
		public static final int DETDLD = 5;
		public static final int BUTDNE = 6;

		public Tag(
					String Cpt
					, String DetCptSte
					, String DetButDel
					, String DetButGen
					, String DetDld
					, String ButDne
				) {
			this.Cpt = Cpt;
			this.DetCptSte = DetCptSte;
			this.DetButDel = DetButDel;
			this.DetButGen = DetButGen;
			this.DetDld = DetDld;
			this.ButDne = ButDne;

			mask = new HashSet<Integer>(Arrays.asList(CPT, DETCPTSTE, DETBUTDEL, DETBUTGEN, DETDLD, BUTDNE));
		};

		public String Cpt;
		public String DetCptSte;
		public String DetButDel;
		public String DetButGen;
		public String DetDld;
		public String ButDne;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeUsrMngkeypair");

			String itemtag = "TagitemDlgWdbeUsrMngkeypair";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				DetCptSte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptSte", mask, DETCPTSTE);
				DetButDel = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetButDel", mask, DETBUTDEL);
				DetButGen = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetButGen", mask, DETBUTGEN);
				DetDld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetDld", mask, DETDLD);
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
			if (DetCptSte.equals(comp.DetCptSte)) items.add(DETCPTSTE);
			if (DetButDel.equals(comp.DetButDel)) items.add(DETBUTDEL);
			if (DetButGen.equals(comp.DetButGen)) items.add(DETBUTGEN);
			if (DetDld.equals(comp.DetDld)) items.add(DETDLD);
			if (ButDne.equals(comp.ButDne)) items.add(BUTDNE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, DETCPTSTE, DETBUTDEL, DETBUTGEN, DETDLD, BUTDNE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeUsrMngkeypairDo)
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
			super(VecWdbeVDpch.DPCHAPPDLGWDBEUSRMNGKEYPAIRDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWdbeUsrMngkeypairDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeUsrMngkeypairData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGDLGWDBEUSRMNGKEYPAIRDATA);

			continf = new ContInf(0, "", "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp("");
			statshr = new StatShr(false, false, false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWdbeUsrMngkeypairData");

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
				statapp = new StatApp("");
				statshr = new StatShr(false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};

