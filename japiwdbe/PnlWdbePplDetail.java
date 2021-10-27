/**
  * \file PnlWdbePplDetail.java
  * Java API code for job PnlWdbePplDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbePplDetail {
	/**
		* VecVDo (full: VecVWdbePplDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTHSMVIEWCLICK = 2;
		public static final int BUTCLKVIEWCLICK = 3;
		public static final int BUTCLGVIEWCLICK = 4;
		public static final int BUTASRVIEWCLICK = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("buthsmviewclick")) return BUTHSMVIEWCLICK;
			if (s.equals("butclkviewclick")) return BUTCLKVIEWCLICK;
			if (s.equals("butclgviewclick")) return BUTCLGVIEWCLICK;
			if (s.equals("butasrviewclick")) return BUTASRVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTHSMVIEWCLICK) return("ButHsmViewClick");
			if (ix == BUTCLKVIEWCLICK) return("ButClkViewClick");
			if (ix == BUTCLGVIEWCLICK) return("ButClgViewClick");
			if (ix == BUTASRVIEWCLICK) return("ButAsrViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbePplDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFCLK = 1;
		public static final int TXFCLG = 2;
		public static final int TXFASR = 3;
		public static final int TXFDPT = 4;
		public static final int TXFCMT = 5;

		public ContIac(
					String TxfClk
					, String TxfClg
					, String TxfAsr
					, String TxfDpt
					, String TxfCmt
				) {
			this.TxfClk = TxfClk;
			this.TxfClg = TxfClg;
			this.TxfAsr = TxfAsr;
			this.TxfDpt = TxfDpt;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(TXFCLK, TXFCLG, TXFASR, TXFDPT, TXFCMT));
		};

		public String TxfClk;
		public String TxfClg;
		public String TxfAsr;
		public String TxfDpt;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbePplDetail");

			String itemtag = "ContitemIacWdbePplDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfClk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfClk", mask, TXFCLK);
				TxfClg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfClg", mask, TXFCLG);
				TxfAsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfAsr", mask, TXFASR);
				TxfDpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfDpt", mask, TXFDPT);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbePplDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbePplDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfClk", TxfClk);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfClg", TxfClg);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAsr", TxfAsr);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfDpt", TxfDpt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfClk.equals(comp.TxfClk)) items.add(TXFCLK);
			if (TxfClg.equals(comp.TxfClg)) items.add(TXFCLG);
			if (TxfAsr.equals(comp.TxfAsr)) items.add(TXFASR);
			if (TxfDpt.equals(comp.TxfDpt)) items.add(TXFDPT);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFCLK, TXFCLG, TXFASR, TXFDPT, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbePplDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTHSM = 2;
		public static final int TXTCLK = 3;
		public static final int TXTCLG = 4;
		public static final int TXTASR = 5;

		public ContInf(
					String TxtSrf
					, String TxtHsm
					, String TxtClk
					, String TxtClg
					, String TxtAsr
				) {
			this.TxtSrf = TxtSrf;
			this.TxtHsm = TxtHsm;
			this.TxtClk = TxtClk;
			this.TxtClg = TxtClg;
			this.TxtAsr = TxtAsr;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTHSM, TXTCLK, TXTCLG, TXTASR));
		};

		public String TxtSrf;
		public String TxtHsm;
		public String TxtClk;
		public String TxtClg;
		public String TxtAsr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbePplDetail");

			String itemtag = "ContitemInfWdbePplDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtHsm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtHsm", mask, TXTHSM);
				TxtClk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtClk", mask, TXTCLK);
				TxtClg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtClg", mask, TXTCLG);
				TxtAsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtAsr", mask, TXTASR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtHsm.equals(comp.TxtHsm)) items.add(TXTHSM);
			if (TxtClk.equals(comp.TxtClk)) items.add(TXTCLK);
			if (TxtClg.equals(comp.TxtClg)) items.add(TXTCLG);
			if (TxtAsr.equals(comp.TxtAsr)) items.add(TXTASR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTHSM, TXTCLK, TXTCLG, TXTASR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbePplDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int TXTCLKALT = 2;
		public static final int TXTCLGALT = 3;
		public static final int TXTASRALT = 4;

		public StatApp(
					int ixWdbeVExpstate
					, boolean TxtClkAlt
					, boolean TxtClgAlt
					, boolean TxtAsrAlt
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.TxtClkAlt = TxtClkAlt;
			this.TxtClgAlt = TxtClgAlt;
			this.TxtAsrAlt = TxtAsrAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, TXTCLKALT, TXTCLGALT, TXTASRALT));
		};

		public int ixWdbeVExpstate;
		public boolean TxtClkAlt;
		public boolean TxtClgAlt;
		public boolean TxtAsrAlt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbePplDetail");

			String itemtag = "StatitemAppWdbePplDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				TxtClkAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtClkAlt", mask, TXTCLKALT);
				TxtClgAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtClgAlt", mask, TXTCLGALT);
				TxtAsrAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtAsrAlt", mask, TXTASRALT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (TxtClkAlt == comp.TxtClkAlt) items.add(TXTCLKALT);
			if (TxtClgAlt == comp.TxtClgAlt) items.add(TXTCLGALT);
			if (TxtAsrAlt == comp.TxtAsrAlt) items.add(TXTASRALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, TXTCLKALT, TXTCLGALT, TXTASRALT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbePplDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFCLKVALID = 1;
		public static final int TXFCLGVALID = 2;
		public static final int TXFASRVALID = 3;
		public static final int BUTSAVEAVAIL = 4;
		public static final int BUTSAVEACTIVE = 5;
		public static final int TXTSRFACTIVE = 6;
		public static final int TXTHSMACTIVE = 7;
		public static final int BUTHSMVIEWAVAIL = 8;
		public static final int BUTHSMVIEWACTIVE = 9;
		public static final int TXTCLKACTIVE = 10;
		public static final int BUTCLKVIEWAVAIL = 11;
		public static final int TXTCLGACTIVE = 12;
		public static final int BUTCLGVIEWAVAIL = 13;
		public static final int TXTASRACTIVE = 14;
		public static final int BUTASRVIEWAVAIL = 15;
		public static final int TXFDPTACTIVE = 16;
		public static final int TXFCMTACTIVE = 17;

		public StatShr(
					boolean TxfClkValid
					, boolean TxfClgValid
					, boolean TxfAsrValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxtHsmActive
					, boolean ButHsmViewAvail
					, boolean ButHsmViewActive
					, boolean TxtClkActive
					, boolean ButClkViewAvail
					, boolean TxtClgActive
					, boolean ButClgViewAvail
					, boolean TxtAsrActive
					, boolean ButAsrViewAvail
					, boolean TxfDptActive
					, boolean TxfCmtActive
				) {
			this.TxfClkValid = TxfClkValid;
			this.TxfClgValid = TxfClgValid;
			this.TxfAsrValid = TxfAsrValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxtHsmActive = TxtHsmActive;
			this.ButHsmViewAvail = ButHsmViewAvail;
			this.ButHsmViewActive = ButHsmViewActive;
			this.TxtClkActive = TxtClkActive;
			this.ButClkViewAvail = ButClkViewAvail;
			this.TxtClgActive = TxtClgActive;
			this.ButClgViewAvail = ButClgViewAvail;
			this.TxtAsrActive = TxtAsrActive;
			this.ButAsrViewAvail = ButAsrViewAvail;
			this.TxfDptActive = TxfDptActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFCLKVALID, TXFCLGVALID, TXFASRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTHSMACTIVE, BUTHSMVIEWAVAIL, BUTHSMVIEWACTIVE, TXTCLKACTIVE, BUTCLKVIEWAVAIL, TXTCLGACTIVE, BUTCLGVIEWAVAIL, TXTASRACTIVE, BUTASRVIEWAVAIL, TXFDPTACTIVE, TXFCMTACTIVE));
		};

		public boolean TxfClkValid;
		public boolean TxfClgValid;
		public boolean TxfAsrValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxtHsmActive;
		public boolean ButHsmViewAvail;
		public boolean ButHsmViewActive;
		public boolean TxtClkActive;
		public boolean ButClkViewAvail;
		public boolean TxtClgActive;
		public boolean ButClgViewAvail;
		public boolean TxtAsrActive;
		public boolean ButAsrViewAvail;
		public boolean TxfDptActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbePplDetail");

			String itemtag = "StatitemShrWdbePplDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfClkValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfClkValid", mask, TXFCLKVALID);
				TxfClgValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfClgValid", mask, TXFCLGVALID);
				TxfAsrValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfAsrValid", mask, TXFASRVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxtHsmActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtHsmActive", mask, TXTHSMACTIVE);
				ButHsmViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHsmViewAvail", mask, BUTHSMVIEWAVAIL);
				ButHsmViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHsmViewActive", mask, BUTHSMVIEWACTIVE);
				TxtClkActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtClkActive", mask, TXTCLKACTIVE);
				ButClkViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButClkViewAvail", mask, BUTCLKVIEWAVAIL);
				TxtClgActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtClgActive", mask, TXTCLGACTIVE);
				ButClgViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButClgViewAvail", mask, BUTCLGVIEWAVAIL);
				TxtAsrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtAsrActive", mask, TXTASRACTIVE);
				ButAsrViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButAsrViewAvail", mask, BUTASRVIEWAVAIL);
				TxfDptActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfDptActive", mask, TXFDPTACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfClkValid == comp.TxfClkValid) items.add(TXFCLKVALID);
			if (TxfClgValid == comp.TxfClgValid) items.add(TXFCLGVALID);
			if (TxfAsrValid == comp.TxfAsrValid) items.add(TXFASRVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxtHsmActive == comp.TxtHsmActive) items.add(TXTHSMACTIVE);
			if (ButHsmViewAvail == comp.ButHsmViewAvail) items.add(BUTHSMVIEWAVAIL);
			if (ButHsmViewActive == comp.ButHsmViewActive) items.add(BUTHSMVIEWACTIVE);
			if (TxtClkActive == comp.TxtClkActive) items.add(TXTCLKACTIVE);
			if (ButClkViewAvail == comp.ButClkViewAvail) items.add(BUTCLKVIEWAVAIL);
			if (TxtClgActive == comp.TxtClgActive) items.add(TXTCLGACTIVE);
			if (ButClgViewAvail == comp.ButClgViewAvail) items.add(BUTCLGVIEWAVAIL);
			if (TxtAsrActive == comp.TxtAsrActive) items.add(TXTASRACTIVE);
			if (ButAsrViewAvail == comp.ButAsrViewAvail) items.add(BUTASRVIEWAVAIL);
			if (TxfDptActive == comp.TxfDptActive) items.add(TXFDPTACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFCLKVALID, TXFCLGVALID, TXFASRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTHSMACTIVE, BUTHSMVIEWAVAIL, BUTHSMVIEWACTIVE, TXTCLKACTIVE, BUTCLKVIEWAVAIL, TXTCLGACTIVE, BUTCLGVIEWAVAIL, TXTASRACTIVE, BUTASRVIEWAVAIL, TXFDPTACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbePplDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTHSM = 3;
		public static final int CPTCLK = 4;
		public static final int CPTCLG = 5;
		public static final int CPTASR = 6;
		public static final int CPTDPT = 7;
		public static final int CPTCMT = 8;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptHsm
					, String CptClk
					, String CptClg
					, String CptAsr
					, String CptDpt
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptHsm = CptHsm;
			this.CptClk = CptClk;
			this.CptClg = CptClg;
			this.CptAsr = CptAsr;
			this.CptDpt = CptDpt;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTHSM, CPTCLK, CPTCLG, CPTASR, CPTDPT, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptHsm;
		public String CptClk;
		public String CptClg;
		public String CptAsr;
		public String CptDpt;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbePplDetail");

			String itemtag = "TagitemWdbePplDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptHsm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptHsm", mask, CPTHSM);
				CptClk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptClk", mask, CPTCLK);
				CptClg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptClg", mask, CPTCLG);
				CptAsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAsr", mask, CPTASR);
				CptDpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDpt", mask, CPTDPT);
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
			if (CptHsm.equals(comp.CptHsm)) items.add(CPTHSM);
			if (CptClk.equals(comp.CptClk)) items.add(CPTCLK);
			if (CptClg.equals(comp.CptClg)) items.add(CPTCLG);
			if (CptAsr.equals(comp.CptAsr)) items.add(CPTASR);
			if (CptDpt.equals(comp.CptDpt)) items.add(CPTDPT);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTHSM, CPTCLK, CPTCLG, CPTASR, CPTDPT, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbePplDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPPLDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePplDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbePplDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPPLDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePplDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbePplDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEPPLDETAILDATA);

			contiac = new ContIac("", "", "", "", "");
			continf = new ContInf("", "", "", "", "");
			statapp = new StatApp(0, false, false, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbePplDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", "", "", "");
				continf = new ContInf("", "", "", "", "");
				statapp = new StatApp(0, false, false, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "");
			};
		};

	};

};
