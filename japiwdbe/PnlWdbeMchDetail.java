/**
  * \file PnlWdbeMchDetail.java
  * Java API code for job PnlWdbeMchDetail
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeMchDetail {
	/**
		* VecVDo (full: VecVWdbeMchDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTPLAEDITCLICK = 2;
		public static final int BUTCCHVIEWCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butplaeditclick")) return BUTPLAEDITCLICK;
			if (s.equals("butcchviewclick")) return BUTCCHVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTPLAEDITCLICK) return("ButPlaEditClick");
			if (ix == BUTCCHVIEWCLICK) return("ButCchViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeMchDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPPLA = 1;
		public static final int TXFPLA = 2;
		public static final int TXFCMT = 3;

		public ContIac(
					int numFPupPla
					, String TxfPla
					, String TxfCmt
				) {
			this.numFPupPla = numFPupPla;
			this.TxfPla = TxfPla;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPPLA, TXFPLA, TXFCMT));
		};

		public int numFPupPla;
		public String TxfPla;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeMchDetail");

			String itemtag = "ContitemIacWdbeMchDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupPla = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupPla", mask, NUMFPUPPLA);
				TxfPla = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfPla", mask, TXFPLA);
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeMchDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeMchDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupPla", numFPupPla);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfPla", TxfPla);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupPla == comp.numFPupPla) items.add(NUMFPUPPLA);
			if (TxfPla.equals(comp.TxfPla)) items.add(TXFPLA);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPPLA, TXFPLA, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeMchDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTCCH = 2;

		public ContInf(
					String TxtSrf
					, String TxtCch
				) {
			this.TxtSrf = TxtSrf;
			this.TxtCch = TxtCch;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCCH));
		};

		public String TxtSrf;
		public String TxtCch;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeMchDetail");

			String itemtag = "ContitemInfWdbeMchDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtCch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCch", mask, TXTCCH);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtCch.equals(comp.TxtCch)) items.add(TXTCCH);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCCH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeMchDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int PUPPLAALT = 2;

		public StatApp(
					int ixWdbeVExpstate
					, boolean PupPlaAlt
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.PupPlaAlt = PupPlaAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, PUPPLAALT));
		};

		public int ixWdbeVExpstate;
		public boolean PupPlaAlt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeMchDetail");

			String itemtag = "StatitemAppWdbeMchDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				PupPlaAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPlaAlt", mask, PUPPLAALT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (PupPlaAlt == comp.PupPlaAlt) items.add(PUPPLAALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, PUPPLAALT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeMchDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFPLAVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int TXTSRFACTIVE = 4;
		public static final int PUPPLAACTIVE = 5;
		public static final int BUTPLAEDITAVAIL = 6;
		public static final int TXTCCHACTIVE = 7;
		public static final int BUTCCHVIEWAVAIL = 8;
		public static final int BUTCCHVIEWACTIVE = 9;
		public static final int TXFCMTACTIVE = 10;

		public StatShr(
					boolean TxfPlaValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupPlaActive
					, boolean ButPlaEditAvail
					, boolean TxtCchActive
					, boolean ButCchViewAvail
					, boolean ButCchViewActive
					, boolean TxfCmtActive
				) {
			this.TxfPlaValid = TxfPlaValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupPlaActive = PupPlaActive;
			this.ButPlaEditAvail = ButPlaEditAvail;
			this.TxtCchActive = TxtCchActive;
			this.ButCchViewAvail = ButCchViewAvail;
			this.ButCchViewActive = ButCchViewActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFPLAVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPPLAACTIVE, BUTPLAEDITAVAIL, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, TXFCMTACTIVE));
		};

		public boolean TxfPlaValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupPlaActive;
		public boolean ButPlaEditAvail;
		public boolean TxtCchActive;
		public boolean ButCchViewAvail;
		public boolean ButCchViewActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeMchDetail");

			String itemtag = "StatitemShrWdbeMchDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfPlaValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfPlaValid", mask, TXFPLAVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupPlaActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPlaActive", mask, PUPPLAACTIVE);
				ButPlaEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPlaEditAvail", mask, BUTPLAEDITAVAIL);
				TxtCchActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCchActive", mask, TXTCCHACTIVE);
				ButCchViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCchViewAvail", mask, BUTCCHVIEWAVAIL);
				ButCchViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCchViewActive", mask, BUTCCHVIEWACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfPlaValid == comp.TxfPlaValid) items.add(TXFPLAVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (PupPlaActive == comp.PupPlaActive) items.add(PUPPLAACTIVE);
			if (ButPlaEditAvail == comp.ButPlaEditAvail) items.add(BUTPLAEDITAVAIL);
			if (TxtCchActive == comp.TxtCchActive) items.add(TXTCCHACTIVE);
			if (ButCchViewAvail == comp.ButCchViewAvail) items.add(BUTCCHVIEWAVAIL);
			if (ButCchViewActive == comp.ButCchViewActive) items.add(BUTCCHVIEWACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFPLAVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPPLAACTIVE, BUTPLAEDITAVAIL, TXTCCHACTIVE, BUTCCHVIEWAVAIL, BUTCCHVIEWACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeMchDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTPLA = 3;
		public static final int CPTCCH = 4;
		public static final int CPTCMT = 5;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptPla
					, String CptCch
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptPla = CptPla;
			this.CptCch = CptCch;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTPLA, CPTCCH, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptPla;
		public String CptCch;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeMchDetail");

			String itemtag = "TagitemWdbeMchDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptPla = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPla", mask, CPTPLA);
				CptCch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCch", mask, CPTCCH);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptSrf.equals(comp.CptSrf)) items.add(CPTSRF);
			if (CptPla.equals(comp.CptPla)) items.add(CPTPLA);
			if (CptCch.equals(comp.CptCch)) items.add(CPTCCH);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTPLA, CPTCCH, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeMchDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEMCHDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeMchDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeMchDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEMCHDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeMchDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeMchDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPPLA = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEMCHDETAILDATA);

			contiac = new ContIac(0, "", "");
			continf = new ContInf("", "");
			feedFPupPla = new Feed("FeedFPupPla");
			statapp = new StatApp(0, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupPla;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPPLA)) ss.add("feedFPupPla");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeMchDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupPla.readXML(doc, basexpath, true)) add(FEEDFPUPPLA);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", "");
				continf = new ContInf("", "");
				feedFPupPla = new Feed("FeedFPupPla");
				statapp = new StatApp(0, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};

