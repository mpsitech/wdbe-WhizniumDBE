/**
  * \file PnlWdbePrcDetail.java
  * Java API code for job PnlWdbePrcDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbePrcDetail {
	/**
		* VecVDo (full: VecVWdbePrcDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTMDLVIEWCLICK = 2;
		public static final int BUTCLKVIEWCLICK = 3;
		public static final int BUTASRVIEWCLICK = 4;
		public static final int BUTFSMNEWCLICK = 5;
		public static final int BUTFSMDELETECLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butmdlviewclick")) return BUTMDLVIEWCLICK;
			if (s.equals("butclkviewclick")) return BUTCLKVIEWCLICK;
			if (s.equals("butasrviewclick")) return BUTASRVIEWCLICK;
			if (s.equals("butfsmnewclick")) return BUTFSMNEWCLICK;
			if (s.equals("butfsmdeleteclick")) return BUTFSMDELETECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
			if (ix == BUTCLKVIEWCLICK) return("ButClkViewClick");
			if (ix == BUTASRVIEWCLICK) return("ButAsrViewClick");
			if (ix == BUTFSMNEWCLICK) return("ButFsmNewClick");
			if (ix == BUTFSMDELETECLICK) return("ButFsmDeleteClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbePrcDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFCLK = 1;
		public static final int TXFASR = 2;
		public static final int CHKFAL = 3;
		public static final int TXFSNR = 4;
		public static final int CHKEIP = 5;
		public static final int TXFCMT = 6;

		public ContIac(
					String TxfClk
					, String TxfAsr
					, boolean ChkFal
					, String TxfSnr
					, boolean ChkEip
					, String TxfCmt
				) {
			this.TxfClk = TxfClk;
			this.TxfAsr = TxfAsr;
			this.ChkFal = ChkFal;
			this.TxfSnr = TxfSnr;
			this.ChkEip = ChkEip;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(TXFCLK, TXFASR, CHKFAL, TXFSNR, CHKEIP, TXFCMT));
		};

		public String TxfClk;
		public String TxfAsr;
		public boolean ChkFal;
		public String TxfSnr;
		public boolean ChkEip;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbePrcDetail");

			String itemtag = "ContitemIacWdbePrcDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfClk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfClk", mask, TXFCLK);
				TxfAsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfAsr", mask, TXFASR);
				ChkFal = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkFal", mask, CHKFAL);
				TxfSnr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSnr", mask, TXFSNR);
				ChkEip = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkEip", mask, CHKEIP);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbePrcDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbePrcDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfClk", TxfClk);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAsr", TxfAsr);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkFal", ChkFal);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSnr", TxfSnr);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkEip", ChkEip);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfClk.equals(comp.TxfClk)) items.add(TXFCLK);
			if (TxfAsr.equals(comp.TxfAsr)) items.add(TXFASR);
			if (ChkFal == comp.ChkFal) items.add(CHKFAL);
			if (TxfSnr.equals(comp.TxfSnr)) items.add(TXFSNR);
			if (ChkEip == comp.ChkEip) items.add(CHKEIP);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFCLK, TXFASR, CHKFAL, TXFSNR, CHKEIP, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbePrcDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTMDL = 2;
		public static final int TXTCLK = 3;
		public static final int TXTASR = 4;

		public ContInf(
					String TxtSrf
					, String TxtMdl
					, String TxtClk
					, String TxtAsr
				) {
			this.TxtSrf = TxtSrf;
			this.TxtMdl = TxtMdl;
			this.TxtClk = TxtClk;
			this.TxtAsr = TxtAsr;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTMDL, TXTCLK, TXTASR));
		};

		public String TxtSrf;
		public String TxtMdl;
		public String TxtClk;
		public String TxtAsr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbePrcDetail");

			String itemtag = "ContitemInfWdbePrcDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMdl", mask, TXTMDL);
				TxtClk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtClk", mask, TXTCLK);
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
			if (TxtMdl.equals(comp.TxtMdl)) items.add(TXTMDL);
			if (TxtClk.equals(comp.TxtClk)) items.add(TXTCLK);
			if (TxtAsr.equals(comp.TxtAsr)) items.add(TXTASR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTMDL, TXTCLK, TXTASR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbePrcDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int TXTCLKALT = 2;
		public static final int TXTASRALT = 3;

		public StatApp(
					int ixWdbeVExpstate
					, boolean TxtClkAlt
					, boolean TxtAsrAlt
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.TxtClkAlt = TxtClkAlt;
			this.TxtAsrAlt = TxtAsrAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, TXTCLKALT, TXTASRALT));
		};

		public int ixWdbeVExpstate;
		public boolean TxtClkAlt;
		public boolean TxtAsrAlt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbePrcDetail");

			String itemtag = "StatitemAppWdbePrcDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				TxtClkAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtClkAlt", mask, TXTCLKALT);
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
			if (TxtAsrAlt == comp.TxtAsrAlt) items.add(TXTASRALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, TXTCLKALT, TXTASRALT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbePrcDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFCLKVALID = 1;
		public static final int TXFASRVALID = 2;
		public static final int BUTSAVEAVAIL = 3;
		public static final int BUTSAVEACTIVE = 4;
		public static final int TXTSRFACTIVE = 5;
		public static final int TXTMDLACTIVE = 6;
		public static final int BUTMDLVIEWAVAIL = 7;
		public static final int BUTMDLVIEWACTIVE = 8;
		public static final int TXTCLKACTIVE = 9;
		public static final int BUTCLKVIEWAVAIL = 10;
		public static final int TXTASRACTIVE = 11;
		public static final int BUTASRVIEWAVAIL = 12;
		public static final int CHKFALACTIVE = 13;
		public static final int TXFSNRACTIVE = 14;
		public static final int CHKEIPACTIVE = 15;
		public static final int TXFCMTACTIVE = 16;
		public static final int BUTFSMNEWAVAIL = 17;
		public static final int BUTFSMDELETEAVAIL = 18;

		public StatShr(
					boolean TxfClkValid
					, boolean TxfAsrValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxtMdlActive
					, boolean ButMdlViewAvail
					, boolean ButMdlViewActive
					, boolean TxtClkActive
					, boolean ButClkViewAvail
					, boolean TxtAsrActive
					, boolean ButAsrViewAvail
					, boolean ChkFalActive
					, boolean TxfSnrActive
					, boolean ChkEipActive
					, boolean TxfCmtActive
					, boolean ButFsmNewAvail
					, boolean ButFsmDeleteAvail
				) {
			this.TxfClkValid = TxfClkValid;
			this.TxfAsrValid = TxfAsrValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxtMdlActive = TxtMdlActive;
			this.ButMdlViewAvail = ButMdlViewAvail;
			this.ButMdlViewActive = ButMdlViewActive;
			this.TxtClkActive = TxtClkActive;
			this.ButClkViewAvail = ButClkViewAvail;
			this.TxtAsrActive = TxtAsrActive;
			this.ButAsrViewAvail = ButAsrViewAvail;
			this.ChkFalActive = ChkFalActive;
			this.TxfSnrActive = TxfSnrActive;
			this.ChkEipActive = ChkEipActive;
			this.TxfCmtActive = TxfCmtActive;
			this.ButFsmNewAvail = ButFsmNewAvail;
			this.ButFsmDeleteAvail = ButFsmDeleteAvail;

			mask = new HashSet<Integer>(Arrays.asList(TXFCLKVALID, TXFASRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTCLKACTIVE, BUTCLKVIEWAVAIL, TXTASRACTIVE, BUTASRVIEWAVAIL, CHKFALACTIVE, TXFSNRACTIVE, CHKEIPACTIVE, TXFCMTACTIVE, BUTFSMNEWAVAIL, BUTFSMDELETEAVAIL));
		};

		public boolean TxfClkValid;
		public boolean TxfAsrValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxtMdlActive;
		public boolean ButMdlViewAvail;
		public boolean ButMdlViewActive;
		public boolean TxtClkActive;
		public boolean ButClkViewAvail;
		public boolean TxtAsrActive;
		public boolean ButAsrViewAvail;
		public boolean ChkFalActive;
		public boolean TxfSnrActive;
		public boolean ChkEipActive;
		public boolean TxfCmtActive;
		public boolean ButFsmNewAvail;
		public boolean ButFsmDeleteAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbePrcDetail");

			String itemtag = "StatitemShrWdbePrcDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfClkValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfClkValid", mask, TXFCLKVALID);
				TxfAsrValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfAsrValid", mask, TXFASRVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxtMdlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtMdlActive", mask, TXTMDLACTIVE);
				ButMdlViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewAvail", mask, BUTMDLVIEWAVAIL);
				ButMdlViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", mask, BUTMDLVIEWACTIVE);
				TxtClkActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtClkActive", mask, TXTCLKACTIVE);
				ButClkViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButClkViewAvail", mask, BUTCLKVIEWAVAIL);
				TxtAsrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtAsrActive", mask, TXTASRACTIVE);
				ButAsrViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButAsrViewAvail", mask, BUTASRVIEWAVAIL);
				ChkFalActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkFalActive", mask, CHKFALACTIVE);
				TxfSnrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSnrActive", mask, TXFSNRACTIVE);
				ChkEipActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkEipActive", mask, CHKEIPACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);
				ButFsmNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFsmNewAvail", mask, BUTFSMNEWAVAIL);
				ButFsmDeleteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFsmDeleteAvail", mask, BUTFSMDELETEAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfClkValid == comp.TxfClkValid) items.add(TXFCLKVALID);
			if (TxfAsrValid == comp.TxfAsrValid) items.add(TXFASRVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxtMdlActive == comp.TxtMdlActive) items.add(TXTMDLACTIVE);
			if (ButMdlViewAvail == comp.ButMdlViewAvail) items.add(BUTMDLVIEWAVAIL);
			if (ButMdlViewActive == comp.ButMdlViewActive) items.add(BUTMDLVIEWACTIVE);
			if (TxtClkActive == comp.TxtClkActive) items.add(TXTCLKACTIVE);
			if (ButClkViewAvail == comp.ButClkViewAvail) items.add(BUTCLKVIEWAVAIL);
			if (TxtAsrActive == comp.TxtAsrActive) items.add(TXTASRACTIVE);
			if (ButAsrViewAvail == comp.ButAsrViewAvail) items.add(BUTASRVIEWAVAIL);
			if (ChkFalActive == comp.ChkFalActive) items.add(CHKFALACTIVE);
			if (TxfSnrActive == comp.TxfSnrActive) items.add(TXFSNRACTIVE);
			if (ChkEipActive == comp.ChkEipActive) items.add(CHKEIPACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);
			if (ButFsmNewAvail == comp.ButFsmNewAvail) items.add(BUTFSMNEWAVAIL);
			if (ButFsmDeleteAvail == comp.ButFsmDeleteAvail) items.add(BUTFSMDELETEAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFCLKVALID, TXFASRVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTCLKACTIVE, BUTCLKVIEWAVAIL, TXTASRACTIVE, BUTASRVIEWAVAIL, CHKFALACTIVE, TXFSNRACTIVE, CHKEIPACTIVE, TXFCMTACTIVE, BUTFSMNEWAVAIL, BUTFSMDELETEAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbePrcDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTMDL = 3;
		public static final int CPTCLK = 4;
		public static final int CPTASR = 5;
		public static final int CPTFAL = 6;
		public static final int CPTSNR = 7;
		public static final int CPTEIP = 8;
		public static final int CPTCMT = 9;
		public static final int HDGFSM = 10;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptMdl
					, String CptClk
					, String CptAsr
					, String CptFal
					, String CptSnr
					, String CptEip
					, String CptCmt
					, String HdgFsm
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptMdl = CptMdl;
			this.CptClk = CptClk;
			this.CptAsr = CptAsr;
			this.CptFal = CptFal;
			this.CptSnr = CptSnr;
			this.CptEip = CptEip;
			this.CptCmt = CptCmt;
			this.HdgFsm = HdgFsm;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTMDL, CPTCLK, CPTASR, CPTFAL, CPTSNR, CPTEIP, CPTCMT, HDGFSM));
		};

		public String Cpt;
		public String CptSrf;
		public String CptMdl;
		public String CptClk;
		public String CptAsr;
		public String CptFal;
		public String CptSnr;
		public String CptEip;
		public String CptCmt;
		public String HdgFsm;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbePrcDetail");

			String itemtag = "TagitemWdbePrcDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMdl", mask, CPTMDL);
				CptClk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptClk", mask, CPTCLK);
				CptAsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAsr", mask, CPTASR);
				CptFal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFal", mask, CPTFAL);
				CptSnr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSnr", mask, CPTSNR);
				CptEip = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptEip", mask, CPTEIP);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);
				HdgFsm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgFsm", mask, HDGFSM);

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
			if (CptMdl.equals(comp.CptMdl)) items.add(CPTMDL);
			if (CptClk.equals(comp.CptClk)) items.add(CPTCLK);
			if (CptAsr.equals(comp.CptAsr)) items.add(CPTASR);
			if (CptFal.equals(comp.CptFal)) items.add(CPTFAL);
			if (CptSnr.equals(comp.CptSnr)) items.add(CPTSNR);
			if (CptEip.equals(comp.CptEip)) items.add(CPTEIP);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);
			if (HdgFsm.equals(comp.HdgFsm)) items.add(HDGFSM);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTMDL, CPTCLK, CPTASR, CPTFAL, CPTSNR, CPTEIP, CPTCMT, HDGFSM));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbePrcDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPRCDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePrcDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbePrcDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPRCDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePrcDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbePrcDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEPRCDETAILDATA);

			contiac = new ContIac("", "", false, "", false, "");
			continf = new ContInf("", "", "", "");
			statapp = new StatApp(0, false, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbePrcDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", false, "", false, "");
				continf = new ContInf("", "", "", "");
				statapp = new StatApp(0, false, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

