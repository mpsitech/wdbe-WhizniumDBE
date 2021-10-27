/**
  * \file PnlWdbeSnsDetail.java
  * Java API code for job PnlWdbeSnsDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeSnsDetail {
	/**
		* VecVDo (full: VecVWdbeSnsDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTREUVIEWCLICK = 2;
		public static final int BUTSRUVIEWCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butreuviewclick")) return BUTREUVIEWCLICK;
			if (s.equals("butsruviewclick")) return BUTSRUVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
			if (ix == BUTSRUVIEWCLICK) return("ButSruViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeSnsDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPRET = 1;
		public static final int NUMFPUPSRT = 2;

		public ContIac(
					int numFPupRet
					, int numFPupSrt
				) {
			this.numFPupRet = numFPupRet;
			this.numFPupSrt = numFPupSrt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPRET, NUMFPUPSRT));
		};

		public int numFPupRet;
		public int numFPupSrt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeSnsDetail");

			String itemtag = "ContitemIacWdbeSnsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupRet = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRet", mask, NUMFPUPRET);
				numFPupSrt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSrt", mask, NUMFPUPSRT);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeSnsDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeSnsDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSrt", numFPupSrt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupRet == comp.numFPupRet) items.add(NUMFPUPRET);
			if (numFPupSrt == comp.numFPupSrt) items.add(NUMFPUPSRT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPRET, NUMFPUPSRT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeSnsDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTREU = 1;
		public static final int TXTSRU = 2;

		public ContInf(
					String TxtReu
					, String TxtSru
				) {
			this.TxtReu = TxtReu;
			this.TxtSru = TxtSru;

			mask = new HashSet<Integer>(Arrays.asList(TXTREU, TXTSRU));
		};

		public String TxtReu;
		public String TxtSru;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeSnsDetail");

			String itemtag = "ContitemInfWdbeSnsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtReu", mask, TXTREU);
				TxtSru = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSru", mask, TXTSRU);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtReu.equals(comp.TxtReu)) items.add(TXTREU);
			if (TxtSru.equals(comp.TxtSru)) items.add(TXTSRU);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTREU, TXTSRU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeSnsDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;

		public StatApp(
					int ixWdbeVExpstate
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE));
		};

		public int ixWdbeVExpstate;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeSnsDetail");

			String itemtag = "StatitemAppWdbeSnsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeSnsDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTREUACTIVE = 3;
		public static final int BUTREUVIEWAVAIL = 4;
		public static final int BUTREUVIEWACTIVE = 5;
		public static final int TXTSRUACTIVE = 6;
		public static final int BUTSRUVIEWAVAIL = 7;
		public static final int BUTSRUVIEWACTIVE = 8;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtReuActive
					, boolean ButReuViewAvail
					, boolean ButReuViewActive
					, boolean TxtSruActive
					, boolean ButSruViewAvail
					, boolean ButSruViewActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtReuActive = TxtReuActive;
			this.ButReuViewAvail = ButReuViewAvail;
			this.ButReuViewActive = ButReuViewActive;
			this.TxtSruActive = TxtSruActive;
			this.ButSruViewAvail = ButSruViewAvail;
			this.ButSruViewActive = ButSruViewActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTSRUACTIVE, BUTSRUVIEWAVAIL, BUTSRUVIEWACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtReuActive;
		public boolean ButReuViewAvail;
		public boolean ButReuViewActive;
		public boolean TxtSruActive;
		public boolean ButSruViewAvail;
		public boolean ButSruViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeSnsDetail");

			String itemtag = "StatitemShrWdbeSnsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtReuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtReuActive", mask, TXTREUACTIVE);
				ButReuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", mask, BUTREUVIEWAVAIL);
				ButReuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewActive", mask, BUTREUVIEWACTIVE);
				TxtSruActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSruActive", mask, TXTSRUACTIVE);
				ButSruViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSruViewAvail", mask, BUTSRUVIEWAVAIL);
				ButSruViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSruViewActive", mask, BUTSRUVIEWACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtReuActive == comp.TxtReuActive) items.add(TXTREUACTIVE);
			if (ButReuViewAvail == comp.ButReuViewAvail) items.add(BUTREUVIEWAVAIL);
			if (ButReuViewActive == comp.ButReuViewActive) items.add(BUTREUVIEWACTIVE);
			if (TxtSruActive == comp.TxtSruActive) items.add(TXTSRUACTIVE);
			if (ButSruViewAvail == comp.ButSruViewAvail) items.add(BUTSRUVIEWAVAIL);
			if (ButSruViewActive == comp.ButSruViewActive) items.add(BUTSRUVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTSRUACTIVE, BUTSRUVIEWAVAIL, BUTSRUVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeSnsDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTREU = 2;
		public static final int CPTSRU = 3;

		public Tag(
					String Cpt
					, String CptReu
					, String CptSru
				) {
			this.Cpt = Cpt;
			this.CptReu = CptReu;
			this.CptSru = CptSru;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTREU, CPTSRU));
		};

		public String Cpt;
		public String CptReu;
		public String CptSru;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeSnsDetail");

			String itemtag = "TagitemWdbeSnsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptReu", mask, CPTREU);
				CptSru = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSru", mask, CPTSRU);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptReu.equals(comp.CptReu)) items.add(CPTREU);
			if (CptSru.equals(comp.CptSru)) items.add(CPTSRU);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTREU, CPTSRU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeSnsDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBESNSDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeSnsDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeSnsDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBESNSDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeSnsDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeSnsDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPRET = 4;
		public static final int FEEDFPUPSRT = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBESNSDETAILDATA);

			contiac = new ContIac(0, 0);
			continf = new ContInf("", "");
			feedFPupRet = new Feed("FeedFPupRet");
			feedFPupSrt = new Feed("FeedFPupSrt");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupRet;
		public Feed feedFPupSrt;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPRET)) ss.add("feedFPupRet");
			if (has(FEEDFPUPSRT)) ss.add("feedFPupSrt");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeSnsDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupRet.readXML(doc, basexpath, true)) add(FEEDFPUPRET);
				if (feedFPupSrt.readXML(doc, basexpath, true)) add(FEEDFPUPSRT);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0);
				continf = new ContInf("", "");
				feedFPupRet = new Feed("FeedFPupRet");
				feedFPupSrt = new Feed("FeedFPupSrt");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "");
			};
		};

	};

};
