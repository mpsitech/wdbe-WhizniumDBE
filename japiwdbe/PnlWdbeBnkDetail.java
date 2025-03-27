/**
  * \file PnlWdbeBnkDetail.java
  * Java API code for job PnlWdbeBnkDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeBnkDetail {
	/**
		* VecVDo (full: VecVWdbeBnkDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTUNTVIEWCLICK = 2;
		public static final int BUTVSTEDITCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butuntviewclick")) return BUTUNTVIEWCLICK;
			if (s.equals("butvsteditclick")) return BUTVSTEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTUNTVIEWCLICK) return("ButUntViewClick");
			if (ix == BUTVSTEDITCLICK) return("ButVstEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeBnkDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPVST = 1;
		public static final int TXFVST = 2;

		public ContIac(
					int numFPupVst
					, String TxfVst
				) {
			this.numFPupVst = numFPupVst;
			this.TxfVst = TxfVst;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPVST, TXFVST));
		};

		public int numFPupVst;
		public String TxfVst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeBnkDetail");

			String itemtag = "ContitemIacWdbeBnkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupVst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupVst", mask, NUMFPUPVST);
				TxfVst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfVst", mask, TXFVST);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeBnkDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeBnkDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupVst", numFPupVst);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfVst", TxfVst);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupVst == comp.numFPupVst) items.add(NUMFPUPVST);
			if (TxfVst.equals(comp.TxfVst)) items.add(TXFVST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPVST, TXFVST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeBnkDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTUNT = 2;

		public ContInf(
					String TxtSrf
					, String TxtUnt
				) {
			this.TxtSrf = TxtSrf;
			this.TxtUnt = TxtUnt;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTUNT));
		};

		public String TxtSrf;
		public String TxtUnt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeBnkDetail");

			String itemtag = "ContitemInfWdbeBnkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtUnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtUnt", mask, TXTUNT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtUnt.equals(comp.TxtUnt)) items.add(TXTUNT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTUNT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeBnkDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int PUPVSTALT = 2;

		public StatApp(
					int ixWdbeVExpstate
					, boolean PupVstAlt
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.PupVstAlt = PupVstAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, PUPVSTALT));
		};

		public int ixWdbeVExpstate;
		public boolean PupVstAlt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeBnkDetail");

			String itemtag = "StatitemAppWdbeBnkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				PupVstAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupVstAlt", mask, PUPVSTALT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (PupVstAlt == comp.PupVstAlt) items.add(PUPVSTALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, PUPVSTALT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeBnkDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int TXTUNTACTIVE = 4;
		public static final int BUTUNTVIEWAVAIL = 5;
		public static final int BUTUNTVIEWACTIVE = 6;
		public static final int PUPVSTACTIVE = 7;
		public static final int TXFVSTVALID = 8;
		public static final int BUTVSTEDITAVAIL = 9;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxtUntActive
					, boolean ButUntViewAvail
					, boolean ButUntViewActive
					, boolean PupVstActive
					, boolean TxfVstValid
					, boolean ButVstEditAvail
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxtUntActive = TxtUntActive;
			this.ButUntViewAvail = ButUntViewAvail;
			this.ButUntViewActive = ButUntViewActive;
			this.PupVstActive = PupVstActive;
			this.TxfVstValid = TxfVstValid;
			this.ButVstEditAvail = ButVstEditAvail;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTUNTACTIVE, BUTUNTVIEWAVAIL, BUTUNTVIEWACTIVE, PUPVSTACTIVE, TXFVSTVALID, BUTVSTEDITAVAIL));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxtUntActive;
		public boolean ButUntViewAvail;
		public boolean ButUntViewActive;
		public boolean PupVstActive;
		public boolean TxfVstValid;
		public boolean ButVstEditAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeBnkDetail");

			String itemtag = "StatitemShrWdbeBnkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxtUntActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtUntActive", mask, TXTUNTACTIVE);
				ButUntViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUntViewAvail", mask, BUTUNTVIEWAVAIL);
				ButUntViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUntViewActive", mask, BUTUNTVIEWACTIVE);
				PupVstActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupVstActive", mask, PUPVSTACTIVE);
				TxfVstValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfVstValid", mask, TXFVSTVALID);
				ButVstEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVstEditAvail", mask, BUTVSTEDITAVAIL);

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
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxtUntActive == comp.TxtUntActive) items.add(TXTUNTACTIVE);
			if (ButUntViewAvail == comp.ButUntViewAvail) items.add(BUTUNTVIEWAVAIL);
			if (ButUntViewActive == comp.ButUntViewActive) items.add(BUTUNTVIEWACTIVE);
			if (PupVstActive == comp.PupVstActive) items.add(PUPVSTACTIVE);
			if (TxfVstValid == comp.TxfVstValid) items.add(TXFVSTVALID);
			if (ButVstEditAvail == comp.ButVstEditAvail) items.add(BUTVSTEDITAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTUNTACTIVE, BUTUNTVIEWAVAIL, BUTUNTVIEWACTIVE, PUPVSTACTIVE, TXFVSTVALID, BUTVSTEDITAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeBnkDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTUNT = 3;
		public static final int CPTVST = 4;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptUnt
					, String CptVst
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptUnt = CptUnt;
			this.CptVst = CptVst;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTUNT, CPTVST));
		};

		public String Cpt;
		public String CptSrf;
		public String CptUnt;
		public String CptVst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeBnkDetail");

			String itemtag = "TagitemWdbeBnkDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptUnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUnt", mask, CPTUNT);
				CptVst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVst", mask, CPTVST);

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
			if (CptUnt.equals(comp.CptUnt)) items.add(CPTUNT);
			if (CptVst.equals(comp.CptVst)) items.add(CPTVST);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTUNT, CPTVST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeBnkDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEBNKDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeBnkDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeBnkDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEBNKDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeBnkDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeBnkDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPVST = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEBNKDETAILDATA);

			contiac = new ContIac(0, "");
			continf = new ContInf("", "");
			feedFPupVst = new Feed("FeedFPupVst");
			statapp = new StatApp(0, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupVst;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPVST)) ss.add("feedFPupVst");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeBnkDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupVst.readXML(doc, basexpath, true)) add(FEEDFPUPVST);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "");
				continf = new ContInf("", "");
				feedFPupVst = new Feed("FeedFPupVst");
				statapp = new StatApp(0, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "");
			};
		};

	};

};
