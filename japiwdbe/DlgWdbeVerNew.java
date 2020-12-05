/**
  * \file DlgWdbeVerNew.java
  * Java API code for job DlgWdbeVerNew
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWdbeVerNew {
	/**
		* VecVDo (full: VecVDlgWdbeVerNewDo)
		*/
	public static class VecVDo {

		public static final int BUTCNCCLICK = 1;
		public static final int BUTCRECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butcncclick")) return BUTCNCCLICK;
			if (s.equals("butcreclick")) return BUTCRECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTCNCCLICK) return("ButCncClick");
			if (ix == BUTCRECLICK) return("ButCreClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWdbeVerNewSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int CREATE = 2;
		public static final int DONE = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("create")) return CREATE;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == CREATE) return("create");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
		* VecVVni (full: VecVDlgWdbeVerNewVni)
		*/
	public static class VecVVni {

		public static final int MAJ = 1;
		public static final int MIN = 2;
		public static final int SUB = 3;
		public static final int VOID = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("maj")) return MAJ;
			if (s.equals("min")) return MIN;
			if (s.equals("sub")) return SUB;
			if (s.equals("void")) return VOID;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == MAJ) return("maj");
			if (ix == MIN) return("min");
			if (ix == SUB) return("sub");
			if (ix == VOID) return("void");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWdbeVerNew)
	  */
	public class ContIac extends Block {

		public static final int NUMFDETPUPPRJ = 1;
		public static final int NUMFDETPUPBVR = 2;
		public static final int NUMFDETRBUVNI = 3;
		public static final int DETTXFCMT = 4;

		public ContIac(
					int numFDetPupPrj
					, int numFDetPupBvr
					, int numFDetRbuVni
					, String DetTxfCmt
				) {
			this.numFDetPupPrj = numFDetPupPrj;
			this.numFDetPupBvr = numFDetPupBvr;
			this.numFDetRbuVni = numFDetRbuVni;
			this.DetTxfCmt = DetTxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFDETPUPPRJ, NUMFDETPUPBVR, NUMFDETRBUVNI, DETTXFCMT));
		};

		public int numFDetPupPrj;
		public int numFDetPupBvr;
		public int numFDetRbuVni;
		public String DetTxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWdbeVerNew");

			String itemtag = "ContitemIacDlgWdbeVerNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFDetPupPrj = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetPupPrj", mask, NUMFDETPUPPRJ);
				numFDetPupBvr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetPupBvr", mask, NUMFDETPUPBVR);
				numFDetRbuVni = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetRbuVni", mask, NUMFDETRBUVNI);
				DetTxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxfCmt", mask, DETTXFCMT);

				return true;
			};

			return false;
		};

		public void writeXML(
					Document doc
					, Element sup
					, String difftag
					, boolean shorttags
				) {
			if (difftag.isEmpty()) difftag = "ContIacDlgWdbeVerNew";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWdbeVerNew";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetPupPrj", numFDetPupPrj);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetPupBvr", numFDetPupBvr);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetRbuVni", numFDetRbuVni);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "DetTxfCmt", DetTxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFDetPupPrj == comp.numFDetPupPrj) items.add(NUMFDETPUPPRJ);
			if (numFDetPupBvr == comp.numFDetPupBvr) items.add(NUMFDETPUPBVR);
			if (numFDetRbuVni == comp.numFDetRbuVni) items.add(NUMFDETRBUVNI);
			if (DetTxfCmt.equals(comp.DetTxfCmt)) items.add(DETTXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFDETPUPPRJ, NUMFDETPUPBVR, NUMFDETRBUVNI, DETTXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWdbeVerNew)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;

		public ContInf(
					int numFSge
				) {
			this.numFSge = numFSge;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE));
		};

		public int numFSge;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeVerNew");

			String itemtag = "ContitemInfDlgWdbeVerNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWdbeVerNew)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWdbeVerNew");

			String itemtag = "StatitemAppDlgWdbeVerNew";

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
	  * StatShr (full: StatShrDlgWdbeVerNew)
	  */
	public class StatShr extends Block {

		public static final int BUTCREACTIVE = 1;

		public StatShr(
					boolean ButCreActive
				) {
			this.ButCreActive = ButCreActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTCREACTIVE));
		};

		public boolean ButCreActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeVerNew");

			String itemtag = "StatitemShrDlgWdbeVerNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButCreActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCreActive", mask, BUTCREACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButCreActive == comp.ButCreActive) items.add(BUTCREACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTCREACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWdbeVerNew)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int DETCPTPRJ = 2;
		public static final int DETCPTBVR = 3;
		public static final int DETCPTVNI = 4;
		public static final int DETCPTCMT = 5;
		public static final int BUTCNC = 6;
		public static final int BUTCRE = 7;

		public Tag(
					String Cpt
					, String DetCptPrj
					, String DetCptBvr
					, String DetCptVni
					, String DetCptCmt
					, String ButCnc
					, String ButCre
				) {
			this.Cpt = Cpt;
			this.DetCptPrj = DetCptPrj;
			this.DetCptBvr = DetCptBvr;
			this.DetCptVni = DetCptVni;
			this.DetCptCmt = DetCptCmt;
			this.ButCnc = ButCnc;
			this.ButCre = ButCre;

			mask = new HashSet<Integer>(Arrays.asList(CPT, DETCPTPRJ, DETCPTBVR, DETCPTVNI, DETCPTCMT, BUTCNC, BUTCRE));
		};

		public String Cpt;
		public String DetCptPrj;
		public String DetCptBvr;
		public String DetCptVni;
		public String DetCptCmt;
		public String ButCnc;
		public String ButCre;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeVerNew");

			String itemtag = "TagitemDlgWdbeVerNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				DetCptPrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptPrj", mask, DETCPTPRJ);
				DetCptBvr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptBvr", mask, DETCPTBVR);
				DetCptVni = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptVni", mask, DETCPTVNI);
				DetCptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptCmt", mask, DETCPTCMT);
				ButCnc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButCnc", mask, BUTCNC);
				ButCre = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButCre", mask, BUTCRE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (DetCptPrj.equals(comp.DetCptPrj)) items.add(DETCPTPRJ);
			if (DetCptBvr.equals(comp.DetCptBvr)) items.add(DETCPTBVR);
			if (DetCptVni.equals(comp.DetCptVni)) items.add(DETCPTVNI);
			if (DetCptCmt.equals(comp.DetCptCmt)) items.add(DETCPTCMT);
			if (ButCnc.equals(comp.ButCnc)) items.add(BUTCNC);
			if (ButCre.equals(comp.ButCre)) items.add(BUTCRE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, DETCPTPRJ, DETCPTBVR, DETCPTVNI, DETCPTCMT, BUTCNC, BUTCRE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeVerNewData)
		*/
	public class DpchAppData extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int ALL = 3;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPDLGWDBEVERNEWDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
		};

		public ContIac contiac;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWdbeVerNewData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeVerNewDo)
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
			super(VecWdbeVDpch.DPCHAPPDLGWDBEVERNEWDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWdbeVerNewDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeVerNewData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFDETPUPBVR = 4;
		public static final int FEEDFDETPUPPRJ = 5;
		public static final int FEEDFDETRBUVNI = 6;
		public static final int FEEDFSGE = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGDLGWDBEVERNEWDATA);

			contiac = new ContIac(0, 0, 0, "");
			continf = new ContInf(0);
			feedFDetPupBvr = new Feed("FeedFDetPupBvr");
			feedFDetPupPrj = new Feed("FeedFDetPupPrj");
			feedFDetRbuVni = new Feed("FeedFDetRbuVni");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp("");
			statshr = new StatShr(false);
			tag = new Tag("", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFDetPupBvr;
		public Feed feedFDetPupPrj;
		public Feed feedFDetRbuVni;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFDETPUPBVR)) ss.add("feedFDetPupBvr");
			if (has(FEEDFDETPUPPRJ)) ss.add("feedFDetPupPrj");
			if (has(FEEDFDETRBUVNI)) ss.add("feedFDetRbuVni");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWdbeVerNewData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFDetPupBvr.readXML(doc, basexpath, true)) add(FEEDFDETPUPBVR);
				if (feedFDetPupPrj.readXML(doc, basexpath, true)) add(FEEDFDETPUPPRJ);
				if (feedFDetRbuVni.readXML(doc, basexpath, true)) add(FEEDFDETRBUVNI);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, "");
				continf = new ContInf(0);
				feedFDetPupBvr = new Feed("FeedFDetPupBvr");
				feedFDetPupPrj = new Feed("FeedFDetPupPrj");
				feedFDetRbuVni = new Feed("FeedFDetRbuVni");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp("");
				statshr = new StatShr(false);
				tag = new Tag("", "", "", "", "", "", "");
			};
		};

	};

};

