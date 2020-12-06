/**
  * \file PnlWdbeCvrDetail.java
  * Java API code for job PnlWdbeCvrDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeCvrDetail {
	/**
		* VecVDo (full: VecVWdbeCvrDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTCPRVIEWCLICK = 2;
		public static final int BUTBCVVIEWCLICK = 3;
		public static final int BUTJSTEDITCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butcprviewclick")) return BUTCPRVIEWCLICK;
			if (s.equals("butbcvviewclick")) return BUTBCVVIEWCLICK;
			if (s.equals("butjsteditclick")) return BUTJSTEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTCPRVIEWCLICK) return("ButCprViewClick");
			if (ix == BUTBCVVIEWCLICK) return("ButBcvViewClick");
			if (ix == BUTJSTEDITCLICK) return("ButJstEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeCvrDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFMAJ = 1;
		public static final int TXFMIN = 2;
		public static final int TXFSUB = 3;
		public static final int NUMFPUPJST = 4;
		public static final int NUMFPUPSTE = 5;
		public static final int NUMSFLSTSTY = 6;

		public ContIac(
					String TxfMaj
					, String TxfMin
					, String TxfSub
					, int numFPupJst
					, int numFPupSte
					, ArrayList<Integer> numsFLstSty
				) {
			this.TxfMaj = TxfMaj;
			this.TxfMin = TxfMin;
			this.TxfSub = TxfSub;
			this.numFPupJst = numFPupJst;
			this.numFPupSte = numFPupSte;
			this.numsFLstSty = numsFLstSty;

			mask = new HashSet<Integer>(Arrays.asList(TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, NUMSFLSTSTY));
		};

		public String TxfMaj;
		public String TxfMin;
		public String TxfSub;
		public int numFPupJst;
		public int numFPupSte;
		public ArrayList<Integer> numsFLstSty;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeCvrDetail");

			String itemtag = "ContitemIacWdbeCvrDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfMaj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMaj", mask, TXFMAJ);
				TxfMin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMin", mask, TXFMIN);
				TxfSub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSub", mask, TXFSUB);
				numFPupJst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupJst", mask, NUMFPUPJST);
				numFPupSte = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSte", mask, NUMFPUPSTE);
				numsFLstSty = Xmlio.extractUintvecAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numsFLstSty", mask, NUMSFLSTSTY);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeCvrDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeCvrDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMaj", TxfMaj);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMin", TxfMin);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSub", TxfSub);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupJst", numFPupJst);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSte", numFPupSte);
			Xmlio.writeUintvecAttr(doc, el, itemtag, "sref", "numsFLstSty", numsFLstSty);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfMaj.equals(comp.TxfMaj)) items.add(TXFMAJ);
			if (TxfMin.equals(comp.TxfMin)) items.add(TXFMIN);
			if (TxfSub.equals(comp.TxfSub)) items.add(TXFSUB);
			if (numFPupJst == comp.numFPupJst) items.add(NUMFPUPJST);
			if (numFPupSte == comp.numFPupSte) items.add(NUMFPUPSTE);
			if (Xmlio.compareIntegervec(numsFLstSty, comp.numsFLstSty)) items.add(NUMSFLSTSTY);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, NUMSFLSTSTY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeCvrDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTCPR = 1;
		public static final int TXTBCV = 2;
		public static final int TXTSTY = 3;

		public ContInf(
					String TxtCpr
					, String TxtBcv
					, String TxtSty
				) {
			this.TxtCpr = TxtCpr;
			this.TxtBcv = TxtBcv;
			this.TxtSty = TxtSty;

			mask = new HashSet<Integer>(Arrays.asList(TXTCPR, TXTBCV, TXTSTY));
		};

		public String TxtCpr;
		public String TxtBcv;
		public String TxtSty;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeCvrDetail");

			String itemtag = "ContitemInfWdbeCvrDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtCpr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCpr", mask, TXTCPR);
				TxtBcv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtBcv", mask, TXTBCV);
				TxtSty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSty", mask, TXTSTY);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtCpr.equals(comp.TxtCpr)) items.add(TXTCPR);
			if (TxtBcv.equals(comp.TxtBcv)) items.add(TXTBCV);
			if (TxtSty.equals(comp.TxtSty)) items.add(TXTSTY);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTCPR, TXTBCV, TXTSTY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeCvrDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTSTYALT = 2;
		public static final int LSTSTYNUMFIRSTDISP = 3;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstStyAlt
					, int LstStyNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstStyAlt = LstStyAlt;
			this.LstStyNumFirstdisp = LstStyNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTSTYALT, LSTSTYNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstStyAlt;
		public int LstStyNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeCvrDetail");

			String itemtag = "StatitemAppWdbeCvrDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstStyAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstStyAlt", mask, LSTSTYALT);
				LstStyNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstStyNumFirstdisp", mask, LSTSTYNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstStyAlt == comp.LstStyAlt) items.add(LSTSTYALT);
			if (LstStyNumFirstdisp == comp.LstStyNumFirstdisp) items.add(LSTSTYNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTSTYALT, LSTSTYNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeCvrDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTCPRACTIVE = 3;
		public static final int BUTCPRVIEWAVAIL = 4;
		public static final int BUTCPRVIEWACTIVE = 5;
		public static final int TXFMAJACTIVE = 6;
		public static final int TXFMINACTIVE = 7;
		public static final int TXFSUBACTIVE = 8;
		public static final int TXTBCVACTIVE = 9;
		public static final int BUTBCVVIEWAVAIL = 10;
		public static final int BUTBCVVIEWACTIVE = 11;
		public static final int PUPJSTACTIVE = 12;
		public static final int BUTJSTEDITAVAIL = 13;
		public static final int PUPSTEACTIVE = 14;
		public static final int LSTSTYACTIVE = 15;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtCprActive
					, boolean ButCprViewAvail
					, boolean ButCprViewActive
					, boolean TxfMajActive
					, boolean TxfMinActive
					, boolean TxfSubActive
					, boolean TxtBcvActive
					, boolean ButBcvViewAvail
					, boolean ButBcvViewActive
					, boolean PupJstActive
					, boolean ButJstEditAvail
					, boolean PupSteActive
					, boolean LstStyActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtCprActive = TxtCprActive;
			this.ButCprViewAvail = ButCprViewAvail;
			this.ButCprViewActive = ButCprViewActive;
			this.TxfMajActive = TxfMajActive;
			this.TxfMinActive = TxfMinActive;
			this.TxfSubActive = TxfSubActive;
			this.TxtBcvActive = TxtBcvActive;
			this.ButBcvViewAvail = ButBcvViewAvail;
			this.ButBcvViewActive = ButBcvViewActive;
			this.PupJstActive = PupJstActive;
			this.ButJstEditAvail = ButJstEditAvail;
			this.PupSteActive = PupSteActive;
			this.LstStyActive = LstStyActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTCPRACTIVE, BUTCPRVIEWAVAIL, BUTCPRVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBCVACTIVE, BUTBCVVIEWAVAIL, BUTBCVVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, LSTSTYACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtCprActive;
		public boolean ButCprViewAvail;
		public boolean ButCprViewActive;
		public boolean TxfMajActive;
		public boolean TxfMinActive;
		public boolean TxfSubActive;
		public boolean TxtBcvActive;
		public boolean ButBcvViewAvail;
		public boolean ButBcvViewActive;
		public boolean PupJstActive;
		public boolean ButJstEditAvail;
		public boolean PupSteActive;
		public boolean LstStyActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeCvrDetail");

			String itemtag = "StatitemShrWdbeCvrDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtCprActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCprActive", mask, TXTCPRACTIVE);
				ButCprViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCprViewAvail", mask, BUTCPRVIEWAVAIL);
				ButCprViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCprViewActive", mask, BUTCPRVIEWACTIVE);
				TxfMajActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMajActive", mask, TXFMAJACTIVE);
				TxfMinActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMinActive", mask, TXFMINACTIVE);
				TxfSubActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSubActive", mask, TXFSUBACTIVE);
				TxtBcvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtBcvActive", mask, TXTBCVACTIVE);
				ButBcvViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBcvViewAvail", mask, BUTBCVVIEWAVAIL);
				ButBcvViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBcvViewActive", mask, BUTBCVVIEWACTIVE);
				PupJstActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupJstActive", mask, PUPJSTACTIVE);
				ButJstEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJstEditAvail", mask, BUTJSTEDITAVAIL);
				PupSteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupSteActive", mask, PUPSTEACTIVE);
				LstStyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstStyActive", mask, LSTSTYACTIVE);

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
			if (TxtCprActive == comp.TxtCprActive) items.add(TXTCPRACTIVE);
			if (ButCprViewAvail == comp.ButCprViewAvail) items.add(BUTCPRVIEWAVAIL);
			if (ButCprViewActive == comp.ButCprViewActive) items.add(BUTCPRVIEWACTIVE);
			if (TxfMajActive == comp.TxfMajActive) items.add(TXFMAJACTIVE);
			if (TxfMinActive == comp.TxfMinActive) items.add(TXFMINACTIVE);
			if (TxfSubActive == comp.TxfSubActive) items.add(TXFSUBACTIVE);
			if (TxtBcvActive == comp.TxtBcvActive) items.add(TXTBCVACTIVE);
			if (ButBcvViewAvail == comp.ButBcvViewAvail) items.add(BUTBCVVIEWAVAIL);
			if (ButBcvViewActive == comp.ButBcvViewActive) items.add(BUTBCVVIEWACTIVE);
			if (PupJstActive == comp.PupJstActive) items.add(PUPJSTACTIVE);
			if (ButJstEditAvail == comp.ButJstEditAvail) items.add(BUTJSTEDITAVAIL);
			if (PupSteActive == comp.PupSteActive) items.add(PUPSTEACTIVE);
			if (LstStyActive == comp.LstStyActive) items.add(LSTSTYACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTCPRACTIVE, BUTCPRVIEWAVAIL, BUTCPRVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBCVACTIVE, BUTBCVVIEWAVAIL, BUTBCVVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, LSTSTYACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeCvrDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTCPR = 2;
		public static final int CPTMAJ = 3;
		public static final int CPTMIN = 4;
		public static final int CPTSUB = 5;
		public static final int CPTBCV = 6;
		public static final int CPTSTE = 7;
		public static final int CPTSTY = 8;

		public Tag(
					String Cpt
					, String CptCpr
					, String CptMaj
					, String CptMin
					, String CptSub
					, String CptBcv
					, String CptSte
					, String CptSty
				) {
			this.Cpt = Cpt;
			this.CptCpr = CptCpr;
			this.CptMaj = CptMaj;
			this.CptMin = CptMin;
			this.CptSub = CptSub;
			this.CptBcv = CptBcv;
			this.CptSte = CptSte;
			this.CptSty = CptSty;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTCPR, CPTMAJ, CPTMIN, CPTSUB, CPTBCV, CPTSTE, CPTSTY));
		};

		public String Cpt;
		public String CptCpr;
		public String CptMaj;
		public String CptMin;
		public String CptSub;
		public String CptBcv;
		public String CptSte;
		public String CptSty;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeCvrDetail");

			String itemtag = "TagitemWdbeCvrDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptCpr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCpr", mask, CPTCPR);
				CptMaj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMaj", mask, CPTMAJ);
				CptMin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMin", mask, CPTMIN);
				CptSub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSub", mask, CPTSUB);
				CptBcv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptBcv", mask, CPTBCV);
				CptSte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSte", mask, CPTSTE);
				CptSty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSty", mask, CPTSTY);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptCpr.equals(comp.CptCpr)) items.add(CPTCPR);
			if (CptMaj.equals(comp.CptMaj)) items.add(CPTMAJ);
			if (CptMin.equals(comp.CptMin)) items.add(CPTMIN);
			if (CptSub.equals(comp.CptSub)) items.add(CPTSUB);
			if (CptBcv.equals(comp.CptBcv)) items.add(CPTBCV);
			if (CptSte.equals(comp.CptSte)) items.add(CPTSTE);
			if (CptSty.equals(comp.CptSty)) items.add(CPTSTY);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTCPR, CPTMAJ, CPTMIN, CPTSUB, CPTBCV, CPTSTE, CPTSTY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeCvrDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBECVRDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeCvrDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeCvrDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBECVRDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeCvrDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeCvrDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTSTY = 4;
		public static final int FEEDFPUPJST = 5;
		public static final int FEEDFPUPSTE = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBECVRDETAILDATA);

			contiac = new ContIac("", "", "", 0, 0, new ArrayList<Integer>());
			continf = new ContInf("", "", "");
			feedFLstSty = new Feed("FeedFLstSty");
			feedFPupJst = new Feed("FeedFPupJst");
			feedFPupSte = new Feed("FeedFPupSte");
			statapp = new StatApp(0, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstSty;
		public Feed feedFPupJst;
		public Feed feedFPupSte;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTSTY)) ss.add("feedFLstSty");
			if (has(FEEDFPUPJST)) ss.add("feedFPupJst");
			if (has(FEEDFPUPSTE)) ss.add("feedFPupSte");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeCvrDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstSty.readXML(doc, basexpath, true)) add(FEEDFLSTSTY);
				if (feedFPupJst.readXML(doc, basexpath, true)) add(FEEDFPUPJST);
				if (feedFPupSte.readXML(doc, basexpath, true)) add(FEEDFPUPSTE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", "", 0, 0, new ArrayList<Integer>());
				continf = new ContInf("", "", "");
				feedFLstSty = new Feed("FeedFLstSty");
				feedFPupJst = new Feed("FeedFPupJst");
				feedFPupSte = new Feed("FeedFPupSte");
				statapp = new StatApp(0, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "");
			};
		};

	};

};
