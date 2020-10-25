/**
  * \file PnlWdbeTrgDetail.java
  * Java API code for job PnlWdbeTrgDetail
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeTrgDetail {
	/**
		* VecVDo (full: VecVWdbeTrgDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTSYSVIEWCLICK = 2;
		public static final int BUTUNTVIEWCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butsysviewclick")) return BUTSYSVIEWCLICK;
			if (s.equals("butuntviewclick")) return BUTUNTVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTSYSVIEWCLICK) return("ButSysViewClick");
			if (ix == BUTUNTVIEWCLICK) return("ButUntViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeTrgDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTRTE = 1;
		public static final int TXFRTE = 2;
		public static final int TXFCMT = 3;

		public ContIac(
					int numFLstRte
					, String TxfRte
					, String TxfCmt
				) {
			this.numFLstRte = numFLstRte;
			this.TxfRte = TxfRte;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTRTE, TXFRTE, TXFCMT));
		};

		public int numFLstRte;
		public String TxfRte;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeTrgDetail");

			String itemtag = "ContitemIacWdbeTrgDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstRte = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstRte", mask, NUMFLSTRTE);
				TxfRte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfRte", mask, TXFRTE);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbeTrgDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeTrgDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstRte", numFLstRte);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfRte", TxfRte);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstRte == comp.numFLstRte) items.add(NUMFLSTRTE);
			if (TxfRte.equals(comp.TxfRte)) items.add(TXFRTE);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTRTE, TXFRTE, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeTrgDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTSYS = 2;
		public static final int TXTUNT = 3;

		public ContInf(
					String TxtSrf
					, String TxtSys
					, String TxtUnt
				) {
			this.TxtSrf = TxtSrf;
			this.TxtSys = TxtSys;
			this.TxtUnt = TxtUnt;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTSYS, TXTUNT));
		};

		public String TxtSrf;
		public String TxtSys;
		public String TxtUnt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeTrgDetail");

			String itemtag = "ContitemInfWdbeTrgDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtSys = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSys", mask, TXTSYS);
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
			if (TxtSys.equals(comp.TxtSys)) items.add(TXTSYS);
			if (TxtUnt.equals(comp.TxtUnt)) items.add(TXTUNT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTSYS, TXTUNT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeTrgDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTRTEALT = 2;
		public static final int LSTRTENUMFIRSTDISP = 3;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstRteAlt
					, int LstRteNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstRteAlt = LstRteAlt;
			this.LstRteNumFirstdisp = LstRteNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTRTEALT, LSTRTENUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstRteAlt;
		public int LstRteNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeTrgDetail");

			String itemtag = "StatitemAppWdbeTrgDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstRteAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRteAlt", mask, LSTRTEALT);
				LstRteNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRteNumFirstdisp", mask, LSTRTENUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstRteAlt == comp.LstRteAlt) items.add(LSTRTEALT);
			if (LstRteNumFirstdisp == comp.LstRteNumFirstdisp) items.add(LSTRTENUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTRTEALT, LSTRTENUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeTrgDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFRTEVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int TXTSRFACTIVE = 4;
		public static final int TXTSYSACTIVE = 5;
		public static final int BUTSYSVIEWAVAIL = 6;
		public static final int BUTSYSVIEWACTIVE = 7;
		public static final int TXTUNTACTIVE = 8;
		public static final int BUTUNTVIEWAVAIL = 9;
		public static final int BUTUNTVIEWACTIVE = 10;
		public static final int LSTRTEACTIVE = 11;
		public static final int TXFCMTACTIVE = 12;

		public StatShr(
					boolean TxfRteValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxtSysActive
					, boolean ButSysViewAvail
					, boolean ButSysViewActive
					, boolean TxtUntActive
					, boolean ButUntViewAvail
					, boolean ButUntViewActive
					, boolean LstRteActive
					, boolean TxfCmtActive
				) {
			this.TxfRteValid = TxfRteValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxtSysActive = TxtSysActive;
			this.ButSysViewAvail = ButSysViewAvail;
			this.ButSysViewActive = ButSysViewActive;
			this.TxtUntActive = TxtUntActive;
			this.ButUntViewAvail = ButUntViewAvail;
			this.ButUntViewActive = ButUntViewActive;
			this.LstRteActive = LstRteActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFRTEVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSYSACTIVE, BUTSYSVIEWAVAIL, BUTSYSVIEWACTIVE, TXTUNTACTIVE, BUTUNTVIEWAVAIL, BUTUNTVIEWACTIVE, LSTRTEACTIVE, TXFCMTACTIVE));
		};

		public boolean TxfRteValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxtSysActive;
		public boolean ButSysViewAvail;
		public boolean ButSysViewActive;
		public boolean TxtUntActive;
		public boolean ButUntViewAvail;
		public boolean ButUntViewActive;
		public boolean LstRteActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeTrgDetail");

			String itemtag = "StatitemShrWdbeTrgDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfRteValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfRteValid", mask, TXFRTEVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxtSysActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSysActive", mask, TXTSYSACTIVE);
				ButSysViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSysViewAvail", mask, BUTSYSVIEWAVAIL);
				ButSysViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSysViewActive", mask, BUTSYSVIEWACTIVE);
				TxtUntActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtUntActive", mask, TXTUNTACTIVE);
				ButUntViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUntViewAvail", mask, BUTUNTVIEWAVAIL);
				ButUntViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUntViewActive", mask, BUTUNTVIEWACTIVE);
				LstRteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRteActive", mask, LSTRTEACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfRteValid == comp.TxfRteValid) items.add(TXFRTEVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxtSysActive == comp.TxtSysActive) items.add(TXTSYSACTIVE);
			if (ButSysViewAvail == comp.ButSysViewAvail) items.add(BUTSYSVIEWAVAIL);
			if (ButSysViewActive == comp.ButSysViewActive) items.add(BUTSYSVIEWACTIVE);
			if (TxtUntActive == comp.TxtUntActive) items.add(TXTUNTACTIVE);
			if (ButUntViewAvail == comp.ButUntViewAvail) items.add(BUTUNTVIEWAVAIL);
			if (ButUntViewActive == comp.ButUntViewActive) items.add(BUTUNTVIEWACTIVE);
			if (LstRteActive == comp.LstRteActive) items.add(LSTRTEACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFRTEVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTSYSACTIVE, BUTSYSVIEWAVAIL, BUTSYSVIEWACTIVE, TXTUNTACTIVE, BUTUNTVIEWAVAIL, BUTUNTVIEWACTIVE, LSTRTEACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeTrgDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTSYS = 3;
		public static final int CPTUNT = 4;
		public static final int CPTRTE = 5;
		public static final int CPTCMT = 6;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptSys
					, String CptUnt
					, String CptRte
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptSys = CptSys;
			this.CptUnt = CptUnt;
			this.CptRte = CptRte;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSYS, CPTUNT, CPTRTE, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptSys;
		public String CptUnt;
		public String CptRte;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeTrgDetail");

			String itemtag = "TagitemWdbeTrgDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptSys = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSys", mask, CPTSYS);
				CptUnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUnt", mask, CPTUNT);
				CptRte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRte", mask, CPTRTE);
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
			if (CptSys.equals(comp.CptSys)) items.add(CPTSYS);
			if (CptUnt.equals(comp.CptUnt)) items.add(CPTUNT);
			if (CptRte.equals(comp.CptRte)) items.add(CPTRTE);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTSYS, CPTUNT, CPTRTE, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeTrgDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBETRGDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeTrgDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeTrgDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBETRGDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeTrgDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeTrgDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTRTE = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBETRGDETAILDATA);

			contiac = new ContIac(0, "", "");
			continf = new ContInf("", "", "");
			feedFLstRte = new Feed("FeedFLstRte");
			statapp = new StatApp(0, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstRte;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTRTE)) ss.add("feedFLstRte");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeTrgDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstRte.readXML(doc, basexpath, true)) add(FEEDFLSTRTE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", "");
				continf = new ContInf("", "", "");
				feedFLstRte = new Feed("FeedFLstRte");
				statapp = new StatApp(0, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};

