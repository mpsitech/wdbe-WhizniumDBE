/**
  * \file PnlWdbeVarDetail.java
  * Java API code for job PnlWdbeVarDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeVarDetail {
	/**
		* VecVDo (full: VecVWdbeVarDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTCLUVIEWCLICK = 2;
		public static final int BUTCLUCLUSTERCLICK = 3;
		public static final int BUTCLUUNCLUSTERCLICK = 4;
		public static final int BUTREUVIEWCLICK = 5;
		public static final int BUTHTYEDITCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butcluviewclick")) return BUTCLUVIEWCLICK;
			if (s.equals("butcluclusterclick")) return BUTCLUCLUSTERCLICK;
			if (s.equals("butcluunclusterclick")) return BUTCLUUNCLUSTERCLICK;
			if (s.equals("butreuviewclick")) return BUTREUVIEWCLICK;
			if (s.equals("buthtyeditclick")) return BUTHTYEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
			if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
			if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
			if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
			if (ix == BUTHTYEDITCLICK) return("ButHtyEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeVarDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTCLU = 1;
		public static final int NUMFPUPRET = 2;
		public static final int CHKCON = 3;
		public static final int CHKFAL = 4;
		public static final int NUMFPUPHTY = 5;
		public static final int TXFHTY = 6;
		public static final int TXFWID = 7;
		public static final int TXFMMX = 8;
		public static final int TXFONV = 9;
		public static final int TXFOFV = 10;
		public static final int CHKDFO = 11;
		public static final int TXFCMT = 12;

		public ContIac(
					int numFLstClu
					, int numFPupRet
					, boolean ChkCon
					, boolean ChkFal
					, int numFPupHty
					, String TxfHty
					, String TxfWid
					, String TxfMmx
					, String TxfOnv
					, String TxfOfv
					, boolean ChkDfo
					, String TxfCmt
				) {
			this.numFLstClu = numFLstClu;
			this.numFPupRet = numFPupRet;
			this.ChkCon = ChkCon;
			this.ChkFal = ChkFal;
			this.numFPupHty = numFPupHty;
			this.TxfHty = TxfHty;
			this.TxfWid = TxfWid;
			this.TxfMmx = TxfMmx;
			this.TxfOnv = TxfOnv;
			this.TxfOfv = TxfOfv;
			this.ChkDfo = ChkDfo;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTCLU, NUMFPUPRET, CHKCON, CHKFAL, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFONV, TXFOFV, CHKDFO, TXFCMT));
		};

		public int numFLstClu;
		public int numFPupRet;
		public boolean ChkCon;
		public boolean ChkFal;
		public int numFPupHty;
		public String TxfHty;
		public String TxfWid;
		public String TxfMmx;
		public String TxfOnv;
		public String TxfOfv;
		public boolean ChkDfo;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeVarDetail");

			String itemtag = "ContitemIacWdbeVarDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstClu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstClu", mask, NUMFLSTCLU);
				numFPupRet = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRet", mask, NUMFPUPRET);
				ChkCon = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkCon", mask, CHKCON);
				ChkFal = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkFal", mask, CHKFAL);
				numFPupHty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupHty", mask, NUMFPUPHTY);
				TxfHty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfHty", mask, TXFHTY);
				TxfWid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfWid", mask, TXFWID);
				TxfMmx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMmx", mask, TXFMMX);
				TxfOnv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfOnv", mask, TXFONV);
				TxfOfv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfOfv", mask, TXFOFV);
				ChkDfo = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkDfo", mask, CHKDFO);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbeVarDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeVarDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstClu", numFLstClu);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkCon", ChkCon);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkFal", ChkFal);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupHty", numFPupHty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfHty", TxfHty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfWid", TxfWid);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMmx", TxfMmx);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfOnv", TxfOnv);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfOfv", TxfOfv);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkDfo", ChkDfo);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstClu == comp.numFLstClu) items.add(NUMFLSTCLU);
			if (numFPupRet == comp.numFPupRet) items.add(NUMFPUPRET);
			if (ChkCon == comp.ChkCon) items.add(CHKCON);
			if (ChkFal == comp.ChkFal) items.add(CHKFAL);
			if (numFPupHty == comp.numFPupHty) items.add(NUMFPUPHTY);
			if (TxfHty.equals(comp.TxfHty)) items.add(TXFHTY);
			if (TxfWid.equals(comp.TxfWid)) items.add(TXFWID);
			if (TxfMmx.equals(comp.TxfMmx)) items.add(TXFMMX);
			if (TxfOnv.equals(comp.TxfOnv)) items.add(TXFONV);
			if (TxfOfv.equals(comp.TxfOfv)) items.add(TXFOFV);
			if (ChkDfo == comp.ChkDfo) items.add(CHKDFO);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTCLU, NUMFPUPRET, CHKCON, CHKFAL, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFONV, TXFOFV, CHKDFO, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeVarDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTCLU = 2;
		public static final int TXTREU = 3;

		public ContInf(
					String TxtSrf
					, String TxtClu
					, String TxtReu
				) {
			this.TxtSrf = TxtSrf;
			this.TxtClu = TxtClu;
			this.TxtReu = TxtReu;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCLU, TXTREU));
		};

		public String TxtSrf;
		public String TxtClu;
		public String TxtReu;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeVarDetail");

			String itemtag = "ContitemInfWdbeVarDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtClu", mask, TXTCLU);
				TxtReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtReu", mask, TXTREU);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtClu.equals(comp.TxtClu)) items.add(TXTCLU);
			if (TxtReu.equals(comp.TxtReu)) items.add(TXTREU);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCLU, TXTREU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeVarDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTCLUALT = 2;
		public static final int PUPHTYALT = 3;
		public static final int LSTCLUNUMFIRSTDISP = 4;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstCluAlt
					, boolean PupHtyAlt
					, int LstCluNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstCluAlt = LstCluAlt;
			this.PupHtyAlt = PupHtyAlt;
			this.LstCluNumFirstdisp = LstCluNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, LSTCLUNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstCluAlt;
		public boolean PupHtyAlt;
		public int LstCluNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeVarDetail");

			String itemtag = "StatitemAppWdbeVarDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstCluAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluAlt", mask, LSTCLUALT);
				PupHtyAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupHtyAlt", mask, PUPHTYALT);
				LstCluNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluNumFirstdisp", mask, LSTCLUNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstCluAlt == comp.LstCluAlt) items.add(LSTCLUALT);
			if (PupHtyAlt == comp.PupHtyAlt) items.add(PUPHTYALT);
			if (LstCluNumFirstdisp == comp.LstCluNumFirstdisp) items.add(LSTCLUNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, LSTCLUNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeVarDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int LSTCLUACTIVE = 4;
		public static final int BUTCLUVIEWACTIVE = 5;
		public static final int BUTCLUCLUSTERAVAIL = 6;
		public static final int BUTCLUUNCLUSTERAVAIL = 7;
		public static final int TXTREUACTIVE = 8;
		public static final int BUTREUVIEWAVAIL = 9;
		public static final int BUTREUVIEWACTIVE = 10;
		public static final int CHKCONACTIVE = 11;
		public static final int CHKFALACTIVE = 12;
		public static final int PUPHTYACTIVE = 13;
		public static final int TXFHTYVALID = 14;
		public static final int BUTHTYEDITAVAIL = 15;
		public static final int TXFWIDACTIVE = 16;
		public static final int TXFMMXACTIVE = 17;
		public static final int TXFONVACTIVE = 18;
		public static final int TXFOFVACTIVE = 19;
		public static final int CHKDFOACTIVE = 20;
		public static final int TXFCMTACTIVE = 21;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean LstCluActive
					, boolean ButCluViewActive
					, boolean ButCluClusterAvail
					, boolean ButCluUnclusterAvail
					, boolean TxtReuActive
					, boolean ButReuViewAvail
					, boolean ButReuViewActive
					, boolean ChkConActive
					, boolean ChkFalActive
					, boolean PupHtyActive
					, boolean TxfHtyValid
					, boolean ButHtyEditAvail
					, boolean TxfWidActive
					, boolean TxfMmxActive
					, boolean TxfOnvActive
					, boolean TxfOfvActive
					, boolean ChkDfoActive
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.LstCluActive = LstCluActive;
			this.ButCluViewActive = ButCluViewActive;
			this.ButCluClusterAvail = ButCluClusterAvail;
			this.ButCluUnclusterAvail = ButCluUnclusterAvail;
			this.TxtReuActive = TxtReuActive;
			this.ButReuViewAvail = ButReuViewAvail;
			this.ButReuViewActive = ButReuViewActive;
			this.ChkConActive = ChkConActive;
			this.ChkFalActive = ChkFalActive;
			this.PupHtyActive = PupHtyActive;
			this.TxfHtyValid = TxfHtyValid;
			this.ButHtyEditAvail = ButHtyEditAvail;
			this.TxfWidActive = TxfWidActive;
			this.TxfMmxActive = TxfMmxActive;
			this.TxfOnvActive = TxfOnvActive;
			this.TxfOfvActive = TxfOfvActive;
			this.ChkDfoActive = ChkDfoActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, CHKCONACTIVE, CHKFALACTIVE, PUPHTYACTIVE, TXFHTYVALID, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFONVACTIVE, TXFOFVACTIVE, CHKDFOACTIVE, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean LstCluActive;
		public boolean ButCluViewActive;
		public boolean ButCluClusterAvail;
		public boolean ButCluUnclusterAvail;
		public boolean TxtReuActive;
		public boolean ButReuViewAvail;
		public boolean ButReuViewActive;
		public boolean ChkConActive;
		public boolean ChkFalActive;
		public boolean PupHtyActive;
		public boolean TxfHtyValid;
		public boolean ButHtyEditAvail;
		public boolean TxfWidActive;
		public boolean TxfMmxActive;
		public boolean TxfOnvActive;
		public boolean TxfOfvActive;
		public boolean ChkDfoActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeVarDetail");

			String itemtag = "StatitemShrWdbeVarDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				LstCluActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluActive", mask, LSTCLUACTIVE);
				ButCluViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluViewActive", mask, BUTCLUVIEWACTIVE);
				ButCluClusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", mask, BUTCLUCLUSTERAVAIL);
				ButCluUnclusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", mask, BUTCLUUNCLUSTERAVAIL);
				TxtReuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtReuActive", mask, TXTREUACTIVE);
				ButReuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", mask, BUTREUVIEWAVAIL);
				ButReuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewActive", mask, BUTREUVIEWACTIVE);
				ChkConActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkConActive", mask, CHKCONACTIVE);
				ChkFalActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkFalActive", mask, CHKFALACTIVE);
				PupHtyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupHtyActive", mask, PUPHTYACTIVE);
				TxfHtyValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfHtyValid", mask, TXFHTYVALID);
				ButHtyEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHtyEditAvail", mask, BUTHTYEDITAVAIL);
				TxfWidActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfWidActive", mask, TXFWIDACTIVE);
				TxfMmxActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMmxActive", mask, TXFMMXACTIVE);
				TxfOnvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfOnvActive", mask, TXFONVACTIVE);
				TxfOfvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfOfvActive", mask, TXFOFVACTIVE);
				ChkDfoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkDfoActive", mask, CHKDFOACTIVE);
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
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (LstCluActive == comp.LstCluActive) items.add(LSTCLUACTIVE);
			if (ButCluViewActive == comp.ButCluViewActive) items.add(BUTCLUVIEWACTIVE);
			if (ButCluClusterAvail == comp.ButCluClusterAvail) items.add(BUTCLUCLUSTERAVAIL);
			if (ButCluUnclusterAvail == comp.ButCluUnclusterAvail) items.add(BUTCLUUNCLUSTERAVAIL);
			if (TxtReuActive == comp.TxtReuActive) items.add(TXTREUACTIVE);
			if (ButReuViewAvail == comp.ButReuViewAvail) items.add(BUTREUVIEWAVAIL);
			if (ButReuViewActive == comp.ButReuViewActive) items.add(BUTREUVIEWACTIVE);
			if (ChkConActive == comp.ChkConActive) items.add(CHKCONACTIVE);
			if (ChkFalActive == comp.ChkFalActive) items.add(CHKFALACTIVE);
			if (PupHtyActive == comp.PupHtyActive) items.add(PUPHTYACTIVE);
			if (TxfHtyValid == comp.TxfHtyValid) items.add(TXFHTYVALID);
			if (ButHtyEditAvail == comp.ButHtyEditAvail) items.add(BUTHTYEDITAVAIL);
			if (TxfWidActive == comp.TxfWidActive) items.add(TXFWIDACTIVE);
			if (TxfMmxActive == comp.TxfMmxActive) items.add(TXFMMXACTIVE);
			if (TxfOnvActive == comp.TxfOnvActive) items.add(TXFONVACTIVE);
			if (TxfOfvActive == comp.TxfOfvActive) items.add(TXFOFVACTIVE);
			if (ChkDfoActive == comp.ChkDfoActive) items.add(CHKDFOACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, CHKCONACTIVE, CHKFALACTIVE, PUPHTYACTIVE, TXFHTYVALID, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFONVACTIVE, TXFOFVACTIVE, CHKDFOACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeVarDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTCLU = 3;
		public static final int CPTREU = 4;
		public static final int CPTCON = 5;
		public static final int CPTFAL = 6;
		public static final int CPTHTY = 7;
		public static final int CPTWID = 8;
		public static final int CPTMMX = 9;
		public static final int CPTONV = 10;
		public static final int CPTOFV = 11;
		public static final int CPTDFO = 12;
		public static final int CPTCMT = 13;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptClu
					, String CptReu
					, String CptCon
					, String CptFal
					, String CptHty
					, String CptWid
					, String CptMmx
					, String CptOnv
					, String CptOfv
					, String CptDfo
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptClu = CptClu;
			this.CptReu = CptReu;
			this.CptCon = CptCon;
			this.CptFal = CptFal;
			this.CptHty = CptHty;
			this.CptWid = CptWid;
			this.CptMmx = CptMmx;
			this.CptOnv = CptOnv;
			this.CptOfv = CptOfv;
			this.CptDfo = CptDfo;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCLU, CPTREU, CPTCON, CPTFAL, CPTHTY, CPTWID, CPTMMX, CPTONV, CPTOFV, CPTDFO, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptClu;
		public String CptReu;
		public String CptCon;
		public String CptFal;
		public String CptHty;
		public String CptWid;
		public String CptMmx;
		public String CptOnv;
		public String CptOfv;
		public String CptDfo;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeVarDetail");

			String itemtag = "TagitemWdbeVarDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptClu", mask, CPTCLU);
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptReu", mask, CPTREU);
				CptCon = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCon", mask, CPTCON);
				CptFal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFal", mask, CPTFAL);
				CptHty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptHty", mask, CPTHTY);
				CptWid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptWid", mask, CPTWID);
				CptMmx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMmx", mask, CPTMMX);
				CptOnv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOnv", mask, CPTONV);
				CptOfv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOfv", mask, CPTOFV);
				CptDfo = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDfo", mask, CPTDFO);
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
			if (CptClu.equals(comp.CptClu)) items.add(CPTCLU);
			if (CptReu.equals(comp.CptReu)) items.add(CPTREU);
			if (CptCon.equals(comp.CptCon)) items.add(CPTCON);
			if (CptFal.equals(comp.CptFal)) items.add(CPTFAL);
			if (CptHty.equals(comp.CptHty)) items.add(CPTHTY);
			if (CptWid.equals(comp.CptWid)) items.add(CPTWID);
			if (CptMmx.equals(comp.CptMmx)) items.add(CPTMMX);
			if (CptOnv.equals(comp.CptOnv)) items.add(CPTONV);
			if (CptOfv.equals(comp.CptOfv)) items.add(CPTOFV);
			if (CptDfo.equals(comp.CptDfo)) items.add(CPTDFO);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCLU, CPTREU, CPTCON, CPTFAL, CPTHTY, CPTWID, CPTMMX, CPTONV, CPTOFV, CPTDFO, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeVarDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEVARDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeVarDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeVarDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEVARDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeVarDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeVarDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTCLU = 4;
		public static final int FEEDFPUPHTY = 5;
		public static final int FEEDFPUPRET = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEVARDETAILDATA);

			contiac = new ContIac(0, 0, false, false, 0, "", "", "", "", "", false, "");
			continf = new ContInf("", "", "");
			feedFLstClu = new Feed("FeedFLstClu");
			feedFPupHty = new Feed("FeedFPupHty");
			feedFPupRet = new Feed("FeedFPupRet");
			statapp = new StatApp(0, false, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstClu;
		public Feed feedFPupHty;
		public Feed feedFPupRet;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTCLU)) ss.add("feedFLstClu");
			if (has(FEEDFPUPHTY)) ss.add("feedFPupHty");
			if (has(FEEDFPUPRET)) ss.add("feedFPupRet");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeVarDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstClu.readXML(doc, basexpath, true)) add(FEEDFLSTCLU);
				if (feedFPupHty.readXML(doc, basexpath, true)) add(FEEDFPUPHTY);
				if (feedFPupRet.readXML(doc, basexpath, true)) add(FEEDFPUPRET);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, false, false, 0, "", "", "", "", "", false, "");
				continf = new ContInf("", "", "");
				feedFLstClu = new Feed("FeedFLstClu");
				feedFPupHty = new Feed("FeedFPupHty");
				feedFPupRet = new Feed("FeedFPupRet");
				statapp = new StatApp(0, false, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
