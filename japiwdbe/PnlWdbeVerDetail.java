/**
  * \file PnlWdbeVerDetail.java
  * Java API code for job PnlWdbeVerDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeVerDetail {
	/**
		* VecVDo (full: VecVWdbeVerDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTPRJVIEWCLICK = 2;
		public static final int BUTBVRVIEWCLICK = 3;
		public static final int BUTJSTEDITCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butprjviewclick")) return BUTPRJVIEWCLICK;
			if (s.equals("butbvrviewclick")) return BUTBVRVIEWCLICK;
			if (s.equals("butjsteditclick")) return BUTJSTEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
			if (ix == BUTBVRVIEWCLICK) return("ButBvrViewClick");
			if (ix == BUTJSTEDITCLICK) return("ButJstEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeVerDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFMAJ = 1;
		public static final int TXFMIN = 2;
		public static final int TXFSUB = 3;
		public static final int NUMFPUPJST = 4;
		public static final int NUMFPUPSTE = 5;
		public static final int TXFABT = 6;
		public static final int TXFCMT = 7;

		public ContIac(
					String TxfMaj
					, String TxfMin
					, String TxfSub
					, int numFPupJst
					, int numFPupSte
					, String TxfAbt
					, String TxfCmt
				) {
			this.TxfMaj = TxfMaj;
			this.TxfMin = TxfMin;
			this.TxfSub = TxfSub;
			this.numFPupJst = numFPupJst;
			this.numFPupSte = numFPupSte;
			this.TxfAbt = TxfAbt;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, TXFABT, TXFCMT));
		};

		public String TxfMaj;
		public String TxfMin;
		public String TxfSub;
		public int numFPupJst;
		public int numFPupSte;
		public String TxfAbt;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeVerDetail");

			String itemtag = "ContitemIacWdbeVerDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfMaj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMaj", mask, TXFMAJ);
				TxfMin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMin", mask, TXFMIN);
				TxfSub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSub", mask, TXFSUB);
				numFPupJst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupJst", mask, NUMFPUPJST);
				numFPupSte = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSte", mask, NUMFPUPSTE);
				TxfAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfAbt", mask, TXFABT);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbeVerDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeVerDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMaj", TxfMaj);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMin", TxfMin);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSub", TxfSub);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupJst", numFPupJst);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSte", numFPupSte);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAbt", TxfAbt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
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
			if (TxfAbt.equals(comp.TxfAbt)) items.add(TXFABT);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFMAJ, TXFMIN, TXFSUB, NUMFPUPJST, NUMFPUPSTE, TXFABT, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeVerDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTPRJ = 1;
		public static final int TXTBVR = 2;

		public ContInf(
					String TxtPrj
					, String TxtBvr
				) {
			this.TxtPrj = TxtPrj;
			this.TxtBvr = TxtBvr;

			mask = new HashSet<Integer>(Arrays.asList(TXTPRJ, TXTBVR));
		};

		public String TxtPrj;
		public String TxtBvr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeVerDetail");

			String itemtag = "ContitemInfWdbeVerDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrj", mask, TXTPRJ);
				TxtBvr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtBvr", mask, TXTBVR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrj.equals(comp.TxtPrj)) items.add(TXTPRJ);
			if (TxtBvr.equals(comp.TxtBvr)) items.add(TXTBVR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTPRJ, TXTBVR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeVerDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeVerDetail");

			String itemtag = "StatitemAppWdbeVerDetail";

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
	  * StatShr (full: StatShrWdbeVerDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTPRJACTIVE = 3;
		public static final int BUTPRJVIEWAVAIL = 4;
		public static final int BUTPRJVIEWACTIVE = 5;
		public static final int TXFMAJACTIVE = 6;
		public static final int TXFMINACTIVE = 7;
		public static final int TXFSUBACTIVE = 8;
		public static final int TXTBVRACTIVE = 9;
		public static final int BUTBVRVIEWAVAIL = 10;
		public static final int BUTBVRVIEWACTIVE = 11;
		public static final int PUPJSTACTIVE = 12;
		public static final int BUTJSTEDITAVAIL = 13;
		public static final int PUPSTEACTIVE = 14;
		public static final int TXFABTACTIVE = 15;
		public static final int TXFCMTACTIVE = 16;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtPrjActive
					, boolean ButPrjViewAvail
					, boolean ButPrjViewActive
					, boolean TxfMajActive
					, boolean TxfMinActive
					, boolean TxfSubActive
					, boolean TxtBvrActive
					, boolean ButBvrViewAvail
					, boolean ButBvrViewActive
					, boolean PupJstActive
					, boolean ButJstEditAvail
					, boolean PupSteActive
					, boolean TxfAbtActive
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtPrjActive = TxtPrjActive;
			this.ButPrjViewAvail = ButPrjViewAvail;
			this.ButPrjViewActive = ButPrjViewActive;
			this.TxfMajActive = TxfMajActive;
			this.TxfMinActive = TxfMinActive;
			this.TxfSubActive = TxfSubActive;
			this.TxtBvrActive = TxtBvrActive;
			this.ButBvrViewAvail = ButBvrViewAvail;
			this.ButBvrViewActive = ButBvrViewActive;
			this.PupJstActive = PupJstActive;
			this.ButJstEditAvail = ButJstEditAvail;
			this.PupSteActive = PupSteActive;
			this.TxfAbtActive = TxfAbtActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRJACTIVE, BUTPRJVIEWAVAIL, BUTPRJVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBVRACTIVE, BUTBVRVIEWAVAIL, BUTBVRVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, TXFABTACTIVE, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtPrjActive;
		public boolean ButPrjViewAvail;
		public boolean ButPrjViewActive;
		public boolean TxfMajActive;
		public boolean TxfMinActive;
		public boolean TxfSubActive;
		public boolean TxtBvrActive;
		public boolean ButBvrViewAvail;
		public boolean ButBvrViewActive;
		public boolean PupJstActive;
		public boolean ButJstEditAvail;
		public boolean PupSteActive;
		public boolean TxfAbtActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeVerDetail");

			String itemtag = "StatitemShrWdbeVerDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtPrjActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPrjActive", mask, TXTPRJACTIVE);
				ButPrjViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrjViewAvail", mask, BUTPRJVIEWAVAIL);
				ButPrjViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrjViewActive", mask, BUTPRJVIEWACTIVE);
				TxfMajActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMajActive", mask, TXFMAJACTIVE);
				TxfMinActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMinActive", mask, TXFMINACTIVE);
				TxfSubActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSubActive", mask, TXFSUBACTIVE);
				TxtBvrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtBvrActive", mask, TXTBVRACTIVE);
				ButBvrViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBvrViewAvail", mask, BUTBVRVIEWAVAIL);
				ButBvrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBvrViewActive", mask, BUTBVRVIEWACTIVE);
				PupJstActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupJstActive", mask, PUPJSTACTIVE);
				ButJstEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButJstEditAvail", mask, BUTJSTEDITAVAIL);
				PupSteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupSteActive", mask, PUPSTEACTIVE);
				TxfAbtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfAbtActive", mask, TXFABTACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

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
			if (TxtPrjActive == comp.TxtPrjActive) items.add(TXTPRJACTIVE);
			if (ButPrjViewAvail == comp.ButPrjViewAvail) items.add(BUTPRJVIEWAVAIL);
			if (ButPrjViewActive == comp.ButPrjViewActive) items.add(BUTPRJVIEWACTIVE);
			if (TxfMajActive == comp.TxfMajActive) items.add(TXFMAJACTIVE);
			if (TxfMinActive == comp.TxfMinActive) items.add(TXFMINACTIVE);
			if (TxfSubActive == comp.TxfSubActive) items.add(TXFSUBACTIVE);
			if (TxtBvrActive == comp.TxtBvrActive) items.add(TXTBVRACTIVE);
			if (ButBvrViewAvail == comp.ButBvrViewAvail) items.add(BUTBVRVIEWAVAIL);
			if (ButBvrViewActive == comp.ButBvrViewActive) items.add(BUTBVRVIEWACTIVE);
			if (PupJstActive == comp.PupJstActive) items.add(PUPJSTACTIVE);
			if (ButJstEditAvail == comp.ButJstEditAvail) items.add(BUTJSTEDITAVAIL);
			if (PupSteActive == comp.PupSteActive) items.add(PUPSTEACTIVE);
			if (TxfAbtActive == comp.TxfAbtActive) items.add(TXFABTACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRJACTIVE, BUTPRJVIEWAVAIL, BUTPRJVIEWACTIVE, TXFMAJACTIVE, TXFMINACTIVE, TXFSUBACTIVE, TXTBVRACTIVE, BUTBVRVIEWAVAIL, BUTBVRVIEWACTIVE, PUPJSTACTIVE, BUTJSTEDITAVAIL, PUPSTEACTIVE, TXFABTACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeVerDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTPRJ = 2;
		public static final int CPTMAJ = 3;
		public static final int CPTMIN = 4;
		public static final int CPTSUB = 5;
		public static final int CPTBVR = 6;
		public static final int CPTSTE = 7;
		public static final int CPTABT = 8;
		public static final int CPTCMT = 9;

		public Tag(
					String Cpt
					, String CptPrj
					, String CptMaj
					, String CptMin
					, String CptSub
					, String CptBvr
					, String CptSte
					, String CptAbt
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptPrj = CptPrj;
			this.CptMaj = CptMaj;
			this.CptMin = CptMin;
			this.CptSub = CptSub;
			this.CptBvr = CptBvr;
			this.CptSte = CptSte;
			this.CptAbt = CptAbt;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTPRJ, CPTMAJ, CPTMIN, CPTSUB, CPTBVR, CPTSTE, CPTABT, CPTCMT));
		};

		public String Cpt;
		public String CptPrj;
		public String CptMaj;
		public String CptMin;
		public String CptSub;
		public String CptBvr;
		public String CptSte;
		public String CptAbt;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeVerDetail");

			String itemtag = "TagitemWdbeVerDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptPrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrj", mask, CPTPRJ);
				CptMaj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMaj", mask, CPTMAJ);
				CptMin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMin", mask, CPTMIN);
				CptSub = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSub", mask, CPTSUB);
				CptBvr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptBvr", mask, CPTBVR);
				CptSte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSte", mask, CPTSTE);
				CptAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAbt", mask, CPTABT);
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
			if (CptPrj.equals(comp.CptPrj)) items.add(CPTPRJ);
			if (CptMaj.equals(comp.CptMaj)) items.add(CPTMAJ);
			if (CptMin.equals(comp.CptMin)) items.add(CPTMIN);
			if (CptSub.equals(comp.CptSub)) items.add(CPTSUB);
			if (CptBvr.equals(comp.CptBvr)) items.add(CPTBVR);
			if (CptSte.equals(comp.CptSte)) items.add(CPTSTE);
			if (CptAbt.equals(comp.CptAbt)) items.add(CPTABT);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTPRJ, CPTMAJ, CPTMIN, CPTSUB, CPTBVR, CPTSTE, CPTABT, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeVerDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEVERDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeVerDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeVerDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEVERDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeVerDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeVerDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPJST = 4;
		public static final int FEEDFPUPSTE = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEVERDETAILDATA);

			contiac = new ContIac("", "", "", 0, 0, "", "");
			continf = new ContInf("", "");
			feedFPupJst = new Feed("FeedFPupJst");
			feedFPupSte = new Feed("FeedFPupSte");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeVerDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupJst.readXML(doc, basexpath, true)) add(FEEDFPUPJST);
				if (feedFPupSte.readXML(doc, basexpath, true)) add(FEEDFPUPSTE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", "", 0, 0, "", "");
				continf = new ContInf("", "");
				feedFPupJst = new Feed("FeedFPupJst");
				feedFPupSte = new Feed("FeedFPupSte");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "");
			};
		};

	};

};

