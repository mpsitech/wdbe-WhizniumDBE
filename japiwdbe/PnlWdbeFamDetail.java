/**
  * \file PnlWdbeFamDetail.java
  * Java API code for job PnlWdbeFamDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeFamDetail {
	/**
		* VecVDo (full: VecVWdbeFamDetailDo)
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
	  * ContIac (full: ContIacWdbeFamDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPVND = 1;
		public static final int TXFVND = 2;
		public static final int TXFTIT = 3;
		public static final int TXFCMT = 4;

		public ContIac(
					int numFPupVnd
					, String TxfVnd
					, String TxfTit
					, String TxfCmt
				) {
			this.numFPupVnd = numFPupVnd;
			this.TxfVnd = TxfVnd;
			this.TxfTit = TxfTit;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPVND, TXFVND, TXFTIT, TXFCMT));
		};

		public int numFPupVnd;
		public String TxfVnd;
		public String TxfTit;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeFamDetail");

			String itemtag = "ContitemIacWdbeFamDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupVnd = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupVnd", mask, NUMFPUPVND);
				TxfVnd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfVnd", mask, TXFVND);
				TxfTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfTit", mask, TXFTIT);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbeFamDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeFamDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupVnd", numFPupVnd);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfVnd", TxfVnd);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTit", TxfTit);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupVnd == comp.numFPupVnd) items.add(NUMFPUPVND);
			if (TxfVnd.equals(comp.TxfVnd)) items.add(TXFVND);
			if (TxfTit.equals(comp.TxfTit)) items.add(TXFTIT);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPVND, TXFVND, TXFTIT, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeFamDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeFamDetail");

			String itemtag = "StatitemAppWdbeFamDetail";

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
	  * StatShr (full: StatShrWdbeFamDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFVNDVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int PUPVNDACTIVE = 4;
		public static final int BUTVNDEDITAVAIL = 5;
		public static final int TXFTITACTIVE = 6;
		public static final int TXFCMTACTIVE = 7;

		public StatShr(
					boolean TxfVndValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean PupVndActive
					, boolean ButVndEditAvail
					, boolean TxfTitActive
					, boolean TxfCmtActive
				) {
			this.TxfVndValid = TxfVndValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.PupVndActive = PupVndActive;
			this.ButVndEditAvail = ButVndEditAvail;
			this.TxfTitActive = TxfTitActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFVNDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, PUPVNDACTIVE, BUTVNDEDITAVAIL, TXFTITACTIVE, TXFCMTACTIVE));
		};

		public boolean TxfVndValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean PupVndActive;
		public boolean ButVndEditAvail;
		public boolean TxfTitActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeFamDetail");

			String itemtag = "StatitemShrWdbeFamDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfVndValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfVndValid", mask, TXFVNDVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				PupVndActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupVndActive", mask, PUPVNDACTIVE);
				ButVndEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVndEditAvail", mask, BUTVNDEDITAVAIL);
				TxfTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfTitActive", mask, TXFTITACTIVE);
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
			if (PupVndActive == comp.PupVndActive) items.add(PUPVNDACTIVE);
			if (ButVndEditAvail == comp.ButVndEditAvail) items.add(BUTVNDEDITAVAIL);
			if (TxfTitActive == comp.TxfTitActive) items.add(TXFTITACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFVNDVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, PUPVNDACTIVE, BUTVNDEDITAVAIL, TXFTITACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeFamDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTVND = 2;
		public static final int CPTTIT = 3;
		public static final int CPTCMT = 4;

		public Tag(
					String Cpt
					, String CptVnd
					, String CptTit
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptVnd = CptVnd;
			this.CptTit = CptTit;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTVND, CPTTIT, CPTCMT));
		};

		public String Cpt;
		public String CptVnd;
		public String CptTit;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeFamDetail");

			String itemtag = "TagitemWdbeFamDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptVnd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVnd", mask, CPTVND);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
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
			if (CptVnd.equals(comp.CptVnd)) items.add(CPTVND);
			if (CptTit.equals(comp.CptTit)) items.add(CPTTIT);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTVND, CPTTIT, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeFamDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEFAMDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeFamDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeFamDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEFAMDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeFamDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeFamDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFPUPVND = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEFAMDETAILDATA);

			contiac = new ContIac(0, "", "", "");
			feedFPupVnd = new Feed("FeedFPupVnd");
			statapp = new StatApp(0, false);
			statshr = new StatShr(false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFPupVnd;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeFamDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFPupVnd.readXML(doc, basexpath, true)) add(FEEDFPUPVND);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", "", "");
				feedFPupVnd = new Feed("FeedFPupVnd");
				statapp = new StatApp(0, false);
				statshr = new StatShr(false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "");
			};
		};

	};

};

