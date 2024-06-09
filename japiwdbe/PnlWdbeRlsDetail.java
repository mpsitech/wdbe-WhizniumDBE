/**
  * \file PnlWdbeRlsDetail.java
  * Java API code for job PnlWdbeRlsDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeRlsDetail {
	/**
		* VecVDo (full: VecVWdbeRlsDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTCMPVIEWCLICK = 2;
		public static final int BUTMCHVIEWCLICK = 3;
		public static final int BUTOPTEDITCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butcmpviewclick")) return BUTCMPVIEWCLICK;
			if (s.equals("butmchviewclick")) return BUTMCHVIEWCLICK;
			if (s.equals("butopteditclick")) return BUTOPTEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTCMPVIEWCLICK) return("ButCmpViewClick");
			if (ix == BUTMCHVIEWCLICK) return("ButMchViewClick");
			if (ix == BUTOPTEDITCLICK) return("ButOptEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeRlsDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMSFLSTOPT = 1;
		public static final int TXFOPT = 2;
		public static final int TXFCMT = 3;

		public ContIac(
					ArrayList<Integer> numsFLstOpt
					, String TxfOpt
					, String TxfCmt
				) {
			this.numsFLstOpt = numsFLstOpt;
			this.TxfOpt = TxfOpt;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMSFLSTOPT, TXFOPT, TXFCMT));
		};

		public ArrayList<Integer> numsFLstOpt;
		public String TxfOpt;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeRlsDetail");

			String itemtag = "ContitemIacWdbeRlsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numsFLstOpt = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstOpt", mask, NUMSFLSTOPT);
				TxfOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfOpt", mask, TXFOPT);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbeRlsDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeRlsDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstOpt", numsFLstOpt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfOpt", TxfOpt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Xmlio.compareIntegervec(numsFLstOpt, comp.numsFLstOpt)) items.add(NUMSFLSTOPT);
			if (TxfOpt.equals(comp.TxfOpt)) items.add(TXFOPT);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMSFLSTOPT, TXFOPT, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeRlsDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTCMP = 2;
		public static final int TXTMCH = 3;

		public ContInf(
					String TxtSrf
					, String TxtCmp
					, String TxtMch
				) {
			this.TxtSrf = TxtSrf;
			this.TxtCmp = TxtCmp;
			this.TxtMch = TxtMch;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCMP, TXTMCH));
		};

		public String TxtSrf;
		public String TxtCmp;
		public String TxtMch;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeRlsDetail");

			String itemtag = "ContitemInfWdbeRlsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtCmp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCmp", mask, TXTCMP);
				TxtMch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMch", mask, TXTMCH);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtCmp.equals(comp.TxtCmp)) items.add(TXTCMP);
			if (TxtMch.equals(comp.TxtMch)) items.add(TXTMCH);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCMP, TXTMCH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeRlsDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTOPTALT = 2;
		public static final int LSTOPTNUMFIRSTDISP = 3;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstOptAlt
					, int LstOptNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstOptAlt = LstOptAlt;
			this.LstOptNumFirstdisp = LstOptNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTOPTALT, LSTOPTNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstOptAlt;
		public int LstOptNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeRlsDetail");

			String itemtag = "StatitemAppWdbeRlsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstOptAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptAlt", mask, LSTOPTALT);
				LstOptNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptNumFirstdisp", mask, LSTOPTNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstOptAlt == comp.LstOptAlt) items.add(LSTOPTALT);
			if (LstOptNumFirstdisp == comp.LstOptNumFirstdisp) items.add(LSTOPTNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTOPTALT, LSTOPTNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeRlsDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFOPTVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int TXTSRFACTIVE = 4;
		public static final int TXTCMPACTIVE = 5;
		public static final int BUTCMPVIEWAVAIL = 6;
		public static final int BUTCMPVIEWACTIVE = 7;
		public static final int TXTMCHACTIVE = 8;
		public static final int BUTMCHVIEWAVAIL = 9;
		public static final int BUTMCHVIEWACTIVE = 10;
		public static final int LSTOPTACTIVE = 11;
		public static final int BUTOPTEDITAVAIL = 12;
		public static final int TXFCMTACTIVE = 13;

		public StatShr(
					boolean TxfOptValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxtCmpActive
					, boolean ButCmpViewAvail
					, boolean ButCmpViewActive
					, boolean TxtMchActive
					, boolean ButMchViewAvail
					, boolean ButMchViewActive
					, boolean LstOptActive
					, boolean ButOptEditAvail
					, boolean TxfCmtActive
				) {
			this.TxfOptValid = TxfOptValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxtCmpActive = TxtCmpActive;
			this.ButCmpViewAvail = ButCmpViewAvail;
			this.ButCmpViewActive = ButCmpViewActive;
			this.TxtMchActive = TxtMchActive;
			this.ButMchViewAvail = ButMchViewAvail;
			this.ButMchViewActive = ButMchViewActive;
			this.LstOptActive = LstOptActive;
			this.ButOptEditAvail = ButOptEditAvail;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTCMPACTIVE, BUTCMPVIEWAVAIL, BUTCMPVIEWACTIVE, TXTMCHACTIVE, BUTMCHVIEWAVAIL, BUTMCHVIEWACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, TXFCMTACTIVE));
		};

		public boolean TxfOptValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxtCmpActive;
		public boolean ButCmpViewAvail;
		public boolean ButCmpViewActive;
		public boolean TxtMchActive;
		public boolean ButMchViewAvail;
		public boolean ButMchViewActive;
		public boolean LstOptActive;
		public boolean ButOptEditAvail;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeRlsDetail");

			String itemtag = "StatitemShrWdbeRlsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfOptValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfOptValid", mask, TXFOPTVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxtCmpActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCmpActive", mask, TXTCMPACTIVE);
				ButCmpViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCmpViewAvail", mask, BUTCMPVIEWAVAIL);
				ButCmpViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCmpViewActive", mask, BUTCMPVIEWACTIVE);
				TxtMchActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtMchActive", mask, TXTMCHACTIVE);
				ButMchViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMchViewAvail", mask, BUTMCHVIEWAVAIL);
				ButMchViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMchViewActive", mask, BUTMCHVIEWACTIVE);
				LstOptActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstOptActive", mask, LSTOPTACTIVE);
				ButOptEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButOptEditAvail", mask, BUTOPTEDITAVAIL);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfOptValid == comp.TxfOptValid) items.add(TXFOPTVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxtCmpActive == comp.TxtCmpActive) items.add(TXTCMPACTIVE);
			if (ButCmpViewAvail == comp.ButCmpViewAvail) items.add(BUTCMPVIEWAVAIL);
			if (ButCmpViewActive == comp.ButCmpViewActive) items.add(BUTCMPVIEWACTIVE);
			if (TxtMchActive == comp.TxtMchActive) items.add(TXTMCHACTIVE);
			if (ButMchViewAvail == comp.ButMchViewAvail) items.add(BUTMCHVIEWAVAIL);
			if (ButMchViewActive == comp.ButMchViewActive) items.add(BUTMCHVIEWACTIVE);
			if (LstOptActive == comp.LstOptActive) items.add(LSTOPTACTIVE);
			if (ButOptEditAvail == comp.ButOptEditAvail) items.add(BUTOPTEDITAVAIL);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFOPTVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTCMPACTIVE, BUTCMPVIEWAVAIL, BUTCMPVIEWACTIVE, TXTMCHACTIVE, BUTMCHVIEWAVAIL, BUTMCHVIEWACTIVE, LSTOPTACTIVE, BUTOPTEDITAVAIL, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeRlsDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTCMP = 3;
		public static final int CPTMCH = 4;
		public static final int CPTOPT = 5;
		public static final int CPTCMT = 6;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptCmp
					, String CptMch
					, String CptOpt
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptCmp = CptCmp;
			this.CptMch = CptMch;
			this.CptOpt = CptOpt;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCMP, CPTMCH, CPTOPT, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptCmp;
		public String CptMch;
		public String CptOpt;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeRlsDetail");

			String itemtag = "TagitemWdbeRlsDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptCmp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmp", mask, CPTCMP);
				CptMch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMch", mask, CPTMCH);
				CptOpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOpt", mask, CPTOPT);
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
			if (CptCmp.equals(comp.CptCmp)) items.add(CPTCMP);
			if (CptMch.equals(comp.CptMch)) items.add(CPTMCH);
			if (CptOpt.equals(comp.CptOpt)) items.add(CPTOPT);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCMP, CPTMCH, CPTOPT, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeRlsDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBERLSDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeRlsDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeRlsDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBERLSDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeRlsDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeRlsDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTOPT = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBERLSDETAILDATA);

			contiac = new ContIac(new ArrayList<Integer>(), "", "");
			continf = new ContInf("", "", "");
			feedFLstOpt = new Feed("FeedFLstOpt");
			statapp = new StatApp(0, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstOpt;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTOPT)) ss.add("feedFLstOpt");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeRlsDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstOpt.readXML(doc, basexpath, true)) add(FEEDFLSTOPT);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(new ArrayList<Integer>(), "", "");
				continf = new ContInf("", "", "");
				feedFLstOpt = new Feed("FeedFLstOpt");
				statapp = new StatApp(0, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};
