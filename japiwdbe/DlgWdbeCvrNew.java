/**
  * \file DlgWdbeCvrNew.java
  * Java API code for job DlgWdbeCvrNew
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWdbeCvrNew {
	/**
		* VecVDo (full: VecVDlgWdbeCvrNewDo)
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
		* VecVSge (full: VecVDlgWdbeCvrNewSge)
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
		* VecVVni (full: VecVDlgWdbeCvrNewVni)
		*/
	public static class VecVVni {

		public static final int MAJ = 1;
		public static final int MIN = 2;
		public static final int SUB = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("maj")) return MAJ;
			if (s.equals("min")) return MIN;
			if (s.equals("sub")) return SUB;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == MAJ) return("maj");
			if (ix == MIN) return("min");
			if (ix == SUB) return("sub");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWdbeCvrNew)
	  */
	public class ContIac extends Block {

		public static final int NUMFDETPUPCPR = 1;
		public static final int NUMFDETPUPBCV = 2;
		public static final int NUMFDETRBUVNI = 3;

		public ContIac(
					int numFDetPupCpr
					, int numFDetPupBcv
					, int numFDetRbuVni
				) {
			this.numFDetPupCpr = numFDetPupCpr;
			this.numFDetPupBcv = numFDetPupBcv;
			this.numFDetRbuVni = numFDetRbuVni;

			mask = new HashSet<Integer>(Arrays.asList(NUMFDETPUPCPR, NUMFDETPUPBCV, NUMFDETRBUVNI));
		};

		public int numFDetPupCpr;
		public int numFDetPupBcv;
		public int numFDetRbuVni;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWdbeCvrNew");

			String itemtag = "ContitemIacDlgWdbeCvrNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFDetPupCpr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetPupCpr", mask, NUMFDETPUPCPR);
				numFDetPupBcv = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetPupBcv", mask, NUMFDETPUPBCV);
				numFDetRbuVni = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetRbuVni", mask, NUMFDETRBUVNI);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWdbeCvrNew";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWdbeCvrNew";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetPupCpr", numFDetPupCpr);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetPupBcv", numFDetPupBcv);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetRbuVni", numFDetRbuVni);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFDetPupCpr == comp.numFDetPupCpr) items.add(NUMFDETPUPCPR);
			if (numFDetPupBcv == comp.numFDetPupBcv) items.add(NUMFDETPUPBCV);
			if (numFDetRbuVni == comp.numFDetRbuVni) items.add(NUMFDETRBUVNI);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFDETPUPCPR, NUMFDETPUPBCV, NUMFDETRBUVNI));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWdbeCvrNew)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeCvrNew");

			String itemtag = "ContitemInfDlgWdbeCvrNew";

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
	  * StatApp (full: StatAppDlgWdbeCvrNew)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWdbeCvrNew");

			String itemtag = "StatitemAppDlgWdbeCvrNew";

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
	  * StatShr (full: StatShrDlgWdbeCvrNew)
	  */
	public class StatShr extends Block {

		public static final int BUTCNCACTIVE = 1;
		public static final int BUTCREACTIVE = 2;

		public StatShr(
					boolean ButCncActive
					, boolean ButCreActive
				) {
			this.ButCncActive = ButCncActive;
			this.ButCreActive = ButCreActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTCNCACTIVE, BUTCREACTIVE));
		};

		public boolean ButCncActive;
		public boolean ButCreActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeCvrNew");

			String itemtag = "StatitemShrDlgWdbeCvrNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButCncActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCncActive", mask, BUTCNCACTIVE);
				ButCreActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCreActive", mask, BUTCREACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButCncActive == comp.ButCncActive) items.add(BUTCNCACTIVE);
			if (ButCreActive == comp.ButCreActive) items.add(BUTCREACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTCNCACTIVE, BUTCREACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWdbeCvrNew)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int DETCPTCPR = 2;
		public static final int DETCPTBCV = 3;
		public static final int DETCPTVNI = 4;
		public static final int BUTCNC = 5;
		public static final int BUTCRE = 6;

		public Tag(
					String Cpt
					, String DetCptCpr
					, String DetCptBcv
					, String DetCptVni
					, String ButCnc
					, String ButCre
				) {
			this.Cpt = Cpt;
			this.DetCptCpr = DetCptCpr;
			this.DetCptBcv = DetCptBcv;
			this.DetCptVni = DetCptVni;
			this.ButCnc = ButCnc;
			this.ButCre = ButCre;

			mask = new HashSet<Integer>(Arrays.asList(CPT, DETCPTCPR, DETCPTBCV, DETCPTVNI, BUTCNC, BUTCRE));
		};

		public String Cpt;
		public String DetCptCpr;
		public String DetCptBcv;
		public String DetCptVni;
		public String ButCnc;
		public String ButCre;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeCvrNew");

			String itemtag = "TagitemDlgWdbeCvrNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				DetCptCpr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptCpr", mask, DETCPTCPR);
				DetCptBcv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptBcv", mask, DETCPTBCV);
				DetCptVni = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptVni", mask, DETCPTVNI);
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
			if (DetCptCpr.equals(comp.DetCptCpr)) items.add(DETCPTCPR);
			if (DetCptBcv.equals(comp.DetCptBcv)) items.add(DETCPTBCV);
			if (DetCptVni.equals(comp.DetCptVni)) items.add(DETCPTVNI);
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

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, DETCPTCPR, DETCPTBCV, DETCPTVNI, BUTCNC, BUTCRE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeCvrNewData)
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
			super(VecWdbeVDpch.DPCHAPPDLGWDBECVRNEWDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWdbeCvrNewData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeCvrNewDo)
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
			super(VecWdbeVDpch.DPCHAPPDLGWDBECVRNEWDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWdbeCvrNewDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeCvrNewData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFDETPUPBCV = 4;
		public static final int FEEDFDETPUPCPR = 5;
		public static final int FEEDFDETRBUVNI = 6;
		public static final int FEEDFSGE = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGDLGWDBECVRNEWDATA);

			contiac = new ContIac(0, 0, 0);
			continf = new ContInf(0);
			feedFDetPupBcv = new Feed("FeedFDetPupBcv");
			feedFDetPupCpr = new Feed("FeedFDetPupCpr");
			feedFDetRbuVni = new Feed("FeedFDetRbuVni");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp("");
			statshr = new StatShr(false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFDetPupBcv;
		public Feed feedFDetPupCpr;
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
			if (has(FEEDFDETPUPBCV)) ss.add("feedFDetPupBcv");
			if (has(FEEDFDETPUPCPR)) ss.add("feedFDetPupCpr");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWdbeCvrNewData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFDetPupBcv.readXML(doc, basexpath, true)) add(FEEDFDETPUPBCV);
				if (feedFDetPupCpr.readXML(doc, basexpath, true)) add(FEEDFDETPUPCPR);
				if (feedFDetRbuVni.readXML(doc, basexpath, true)) add(FEEDFDETRBUVNI);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0);
				continf = new ContInf(0);
				feedFDetPupBcv = new Feed("FeedFDetPupBcv");
				feedFDetPupCpr = new Feed("FeedFDetPupCpr");
				feedFDetRbuVni = new Feed("FeedFDetRbuVni");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp("");
				statshr = new StatShr(false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};

