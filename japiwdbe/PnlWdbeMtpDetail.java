/**
  * \file PnlWdbeMtpDetail.java
  * Java API code for job PnlWdbeMtpDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeMtpDetail {
	/**
		* VecVDo (full: VecVWdbeMtpDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTVNDEDITCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butvndeditclick")) return BUTVNDEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTVNDEDITCLICK) return("ButVndEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeMtpDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPVND = 1;
		public static final int TXFVND = 2;
		public static final int NUMFPUPTYP = 3;
		public static final int TXFSRR = 4;
		public static final int TXFCMT = 5;

		public ContIac(
					int numFPupVnd
					, String TxfVnd
					, int numFPupTyp
					, String TxfSrr
					, String TxfCmt
				) {
			this.numFPupVnd = numFPupVnd;
			this.TxfVnd = TxfVnd;
			this.numFPupTyp = numFPupTyp;
			this.TxfSrr = TxfSrr;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPVND, TXFVND, NUMFPUPTYP, TXFSRR, TXFCMT));
		};

		public int numFPupVnd;
		public String TxfVnd;
		public int numFPupTyp;
		public String TxfSrr;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeMtpDetail");

			String itemtag = "ContitemIacWdbeMtpDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupVnd = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupVnd", mask, NUMFPUPVND);
				TxfVnd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfVnd", mask, TXFVND);
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				TxfSrr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSrr", mask, TXFSRR);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbeMtpDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeMtpDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupVnd", numFPupVnd);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfVnd", TxfVnd);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSrr", TxfSrr);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupVnd == comp.numFPupVnd) items.add(NUMFPUPVND);
			if (TxfVnd.equals(comp.TxfVnd)) items.add(TXFVND);
			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (TxfSrr.equals(comp.TxfSrr)) items.add(TXFSRR);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPVND, TXFVND, NUMFPUPTYP, TXFSRR, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeMtpDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;

		public ContInf(
					String TxtSrf
				) {
			this.TxtSrf = TxtSrf;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF));
		};

		public String TxtSrf;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeMtpDetail");

			String itemtag = "ContitemInfWdbeMtpDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeMtpDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int PUPVNDALT = 2;

		public StatApp(
					int ixWdbeVExpstate
					, boolean PupVndAlt
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.PupVndAlt = PupVndAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, PUPVNDALT));
		};

		public int ixWdbeVExpstate;
		public boolean PupVndAlt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeMtpDetail");

			String itemtag = "StatitemAppWdbeMtpDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				PupVndAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupVndAlt", mask, PUPVNDALT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (PupVndAlt == comp.PupVndAlt) items.add(PUPVNDALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, PUPVNDALT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeMtpDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFVNDVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int TXTSRFACTIVE = 4;
		public static final int PUPVNDACTIVE = 5;
		public static final int BUTVNDEDITAVAIL = 6;
		public static final int PUPTYPACTIVE = 7;
		public static final int TXFSRRACTIVE = 8;
		public static final int TXFCMTACTIVE = 9;

		public StatShr(
					boolean TxfVndValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupVndActive
					, boolean ButVndEditAvail
					, boolean PupTypActive
					, boolean TxfSrrActive
					, boolean TxfCmtActive
				) {
			this.TxfVndValid = TxfVndValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupVndActive = PupVndActive;
			this.ButVndEditAvail = ButVndEditAvail;
			this.PupTypActive = PupTypActive;
			this.TxfSrrActive = TxfSrrActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFVNDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPVNDACTIVE, BUTVNDEDITAVAIL, PUPTYPACTIVE, TXFSRRACTIVE, TXFCMTACTIVE));
		};

		public boolean TxfVndValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupVndActive;
		public boolean ButVndEditAvail;
		public boolean PupTypActive;
		public boolean TxfSrrActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeMtpDetail");

			String itemtag = "StatitemShrWdbeMtpDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfVndValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfVndValid", mask, TXFVNDVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupVndActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupVndActive", mask, PUPVNDACTIVE);
				ButVndEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVndEditAvail", mask, BUTVNDEDITAVAIL);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				TxfSrrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSrrActive", mask, TXFSRRACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfVndValid == comp.TxfVndValid) items.add(TXFVNDVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (PupVndActive == comp.PupVndActive) items.add(PUPVNDACTIVE);
			if (ButVndEditAvail == comp.ButVndEditAvail) items.add(BUTVNDEDITAVAIL);
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (TxfSrrActive == comp.TxfSrrActive) items.add(TXFSRRACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFVNDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPVNDACTIVE, BUTVNDEDITAVAIL, PUPTYPACTIVE, TXFSRRACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeMtpDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTVND = 3;
		public static final int CPTTYP = 4;
		public static final int CPTSRR = 5;
		public static final int CPTCMT = 6;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptVnd
					, String CptTyp
					, String CptSrr
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptVnd = CptVnd;
			this.CptTyp = CptTyp;
			this.CptSrr = CptSrr;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTVND, CPTTYP, CPTSRR, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptVnd;
		public String CptTyp;
		public String CptSrr;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeMtpDetail");

			String itemtag = "TagitemWdbeMtpDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptVnd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVnd", mask, CPTVND);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptSrr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrr", mask, CPTSRR);
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
			if (CptVnd.equals(comp.CptVnd)) items.add(CPTVND);
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptSrr.equals(comp.CptSrr)) items.add(CPTSRR);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTVND, CPTTYP, CPTSRR, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeMtpDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEMTPDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeMtpDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeMtpDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEMTPDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeMtpDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeMtpDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPTYP = 4;
		public static final int FEEDFPUPVND = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEMTPDETAILDATA);

			contiac = new ContIac(0, "", 0, "", "");
			continf = new ContInf("");
			feedFPupTyp = new Feed("FeedFPupTyp");
			feedFPupVnd = new Feed("FeedFPupVnd");
			statapp = new StatApp(0, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupTyp;
		public Feed feedFPupVnd;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPTYP)) ss.add("feedFPupTyp");
			if (has(FEEDFPUPVND)) ss.add("feedFPupVnd");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeMtpDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (feedFPupVnd.readXML(doc, basexpath, true)) add(FEEDFPUPVND);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", 0, "", "");
				continf = new ContInf("");
				feedFPupTyp = new Feed("FeedFPupTyp");
				feedFPupVnd = new Feed("FeedFPupVnd");
				statapp = new StatApp(0, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};
