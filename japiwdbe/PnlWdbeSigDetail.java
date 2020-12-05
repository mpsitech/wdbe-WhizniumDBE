/**
  * \file PnlWdbeSigDetail.java
  * Java API code for job PnlWdbeSigDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeSigDetail {
	/**
		* VecVDo (full: VecVWdbeSigDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTCLUVIEWCLICK = 2;
		public static final int BUTCLUCLUSTERCLICK = 3;
		public static final int BUTCLUUNCLUSTERCLICK = 4;
		public static final int BUTMDLVIEWCLICK = 5;
		public static final int BUTMGUVIEWCLICK = 6;
		public static final int BUTVECVIEWCLICK = 7;
		public static final int BUTHTYEDITCLICK = 8;
		public static final int BUTDRVVIEWCLICK = 9;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butcluviewclick")) return BUTCLUVIEWCLICK;
			if (s.equals("butcluclusterclick")) return BUTCLUCLUSTERCLICK;
			if (s.equals("butcluunclusterclick")) return BUTCLUUNCLUSTERCLICK;
			if (s.equals("butmdlviewclick")) return BUTMDLVIEWCLICK;
			if (s.equals("butmguviewclick")) return BUTMGUVIEWCLICK;
			if (s.equals("butvecviewclick")) return BUTVECVIEWCLICK;
			if (s.equals("buthtyeditclick")) return BUTHTYEDITCLICK;
			if (s.equals("butdrvviewclick")) return BUTDRVVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
			if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
			if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
			if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
			if (ix == BUTMGUVIEWCLICK) return("ButMguViewClick");
			if (ix == BUTVECVIEWCLICK) return("ButVecViewClick");
			if (ix == BUTHTYEDITCLICK) return("ButHtyEditClick");
			if (ix == BUTDRVVIEWCLICK) return("ButDrvViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeSigDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPTYP = 1;
		public static final int NUMFLSTCLU = 2;
		public static final int NUMFPUPMGT = 3;
		public static final int CHKCON = 4;
		public static final int NUMFPUPHTY = 5;
		public static final int TXFHTY = 6;
		public static final int TXFWID = 7;
		public static final int TXFMMX = 8;
		public static final int TXFCMB = 9;
		public static final int TXFONV = 10;
		public static final int TXFOFV = 11;
		public static final int CHKDFO = 12;
		public static final int TXFCMT = 13;

		public ContIac(
					int numFPupTyp
					, int numFLstClu
					, int numFPupMgt
					, boolean ChkCon
					, int numFPupHty
					, String TxfHty
					, String TxfWid
					, String TxfMmx
					, String TxfCmb
					, String TxfOnv
					, String TxfOfv
					, boolean ChkDfo
					, String TxfCmt
				) {
			this.numFPupTyp = numFPupTyp;
			this.numFLstClu = numFLstClu;
			this.numFPupMgt = numFPupMgt;
			this.ChkCon = ChkCon;
			this.numFPupHty = numFPupHty;
			this.TxfHty = TxfHty;
			this.TxfWid = TxfWid;
			this.TxfMmx = TxfMmx;
			this.TxfCmb = TxfCmb;
			this.TxfOnv = TxfOnv;
			this.TxfOfv = TxfOfv;
			this.ChkDfo = ChkDfo;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFLSTCLU, NUMFPUPMGT, CHKCON, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFCMB, TXFONV, TXFOFV, CHKDFO, TXFCMT));
		};

		public int numFPupTyp;
		public int numFLstClu;
		public int numFPupMgt;
		public boolean ChkCon;
		public int numFPupHty;
		public String TxfHty;
		public String TxfWid;
		public String TxfMmx;
		public String TxfCmb;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeSigDetail");

			String itemtag = "ContitemIacWdbeSigDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numFLstClu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstClu", mask, NUMFLSTCLU);
				numFPupMgt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupMgt", mask, NUMFPUPMGT);
				ChkCon = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkCon", mask, CHKCON);
				numFPupHty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupHty", mask, NUMFPUPHTY);
				TxfHty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfHty", mask, TXFHTY);
				TxfWid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfWid", mask, TXFWID);
				TxfMmx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMmx", mask, TXFMMX);
				TxfCmb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmb", mask, TXFCMB);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbeSigDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeSigDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstClu", numFLstClu);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupMgt", numFPupMgt);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkCon", ChkCon);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupHty", numFPupHty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfHty", TxfHty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfWid", TxfWid);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMmx", TxfMmx);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmb", TxfCmb);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfOnv", TxfOnv);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfOfv", TxfOfv);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkDfo", ChkDfo);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (numFLstClu == comp.numFLstClu) items.add(NUMFLSTCLU);
			if (numFPupMgt == comp.numFPupMgt) items.add(NUMFPUPMGT);
			if (ChkCon == comp.ChkCon) items.add(CHKCON);
			if (numFPupHty == comp.numFPupHty) items.add(NUMFPUPHTY);
			if (TxfHty.equals(comp.TxfHty)) items.add(TXFHTY);
			if (TxfWid.equals(comp.TxfWid)) items.add(TXFWID);
			if (TxfMmx.equals(comp.TxfMmx)) items.add(TXFMMX);
			if (TxfCmb.equals(comp.TxfCmb)) items.add(TXFCMB);
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

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFLSTCLU, NUMFPUPMGT, CHKCON, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFCMB, TXFONV, TXFOFV, CHKDFO, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeSigDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTCLU = 2;
		public static final int TXTMDL = 3;
		public static final int TXTMGU = 4;
		public static final int TXTVEC = 5;
		public static final int TXTDRV = 6;

		public ContInf(
					String TxtSrf
					, String TxtClu
					, String TxtMdl
					, String TxtMgu
					, String TxtVec
					, String TxtDrv
				) {
			this.TxtSrf = TxtSrf;
			this.TxtClu = TxtClu;
			this.TxtMdl = TxtMdl;
			this.TxtMgu = TxtMgu;
			this.TxtVec = TxtVec;
			this.TxtDrv = TxtDrv;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCLU, TXTMDL, TXTMGU, TXTVEC, TXTDRV));
		};

		public String TxtSrf;
		public String TxtClu;
		public String TxtMdl;
		public String TxtMgu;
		public String TxtVec;
		public String TxtDrv;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeSigDetail");

			String itemtag = "ContitemInfWdbeSigDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtClu", mask, TXTCLU);
				TxtMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMdl", mask, TXTMDL);
				TxtMgu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMgu", mask, TXTMGU);
				TxtVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVec", mask, TXTVEC);
				TxtDrv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtDrv", mask, TXTDRV);

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
			if (TxtMdl.equals(comp.TxtMdl)) items.add(TXTMDL);
			if (TxtMgu.equals(comp.TxtMgu)) items.add(TXTMGU);
			if (TxtVec.equals(comp.TxtVec)) items.add(TXTVEC);
			if (TxtDrv.equals(comp.TxtDrv)) items.add(TXTDRV);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCLU, TXTMDL, TXTMGU, TXTVEC, TXTDRV));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeSigDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeSigDetail");

			String itemtag = "StatitemAppWdbeSigDetail";

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
	  * StatShr (full: StatShrWdbeSigDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFHTYVALID = 1;
		public static final int BUTSAVEAVAIL = 2;
		public static final int BUTSAVEACTIVE = 3;
		public static final int TXTSRFACTIVE = 4;
		public static final int PUPTYPACTIVE = 5;
		public static final int LSTCLUACTIVE = 6;
		public static final int BUTCLUVIEWACTIVE = 7;
		public static final int BUTCLUCLUSTERAVAIL = 8;
		public static final int BUTCLUUNCLUSTERAVAIL = 9;
		public static final int TXTMDLACTIVE = 10;
		public static final int BUTMDLVIEWAVAIL = 11;
		public static final int BUTMDLVIEWACTIVE = 12;
		public static final int TXTMGUACTIVE = 13;
		public static final int BUTMGUVIEWAVAIL = 14;
		public static final int BUTMGUVIEWACTIVE = 15;
		public static final int TXTVECACTIVE = 16;
		public static final int BUTVECVIEWAVAIL = 17;
		public static final int BUTVECVIEWACTIVE = 18;
		public static final int CHKCONACTIVE = 19;
		public static final int PUPHTYACTIVE = 20;
		public static final int BUTHTYEDITAVAIL = 21;
		public static final int TXFWIDACTIVE = 22;
		public static final int TXFMMXACTIVE = 23;
		public static final int TXFCMBACTIVE = 24;
		public static final int TXFONVACTIVE = 25;
		public static final int TXFOFVACTIVE = 26;
		public static final int CHKDFOACTIVE = 27;
		public static final int TXTDRVACTIVE = 28;
		public static final int BUTDRVVIEWAVAIL = 29;
		public static final int BUTDRVVIEWACTIVE = 30;
		public static final int TXFCMTACTIVE = 31;

		public StatShr(
					boolean TxfHtyValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupTypActive
					, boolean LstCluActive
					, boolean ButCluViewActive
					, boolean ButCluClusterAvail
					, boolean ButCluUnclusterAvail
					, boolean TxtMdlActive
					, boolean ButMdlViewAvail
					, boolean ButMdlViewActive
					, boolean TxtMguActive
					, boolean ButMguViewAvail
					, boolean ButMguViewActive
					, boolean TxtVecActive
					, boolean ButVecViewAvail
					, boolean ButVecViewActive
					, boolean ChkConActive
					, boolean PupHtyActive
					, boolean ButHtyEditAvail
					, boolean TxfWidActive
					, boolean TxfMmxActive
					, boolean TxfCmbActive
					, boolean TxfOnvActive
					, boolean TxfOfvActive
					, boolean ChkDfoActive
					, boolean TxtDrvActive
					, boolean ButDrvViewAvail
					, boolean ButDrvViewActive
					, boolean TxfCmtActive
				) {
			this.TxfHtyValid = TxfHtyValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupTypActive = PupTypActive;
			this.LstCluActive = LstCluActive;
			this.ButCluViewActive = ButCluViewActive;
			this.ButCluClusterAvail = ButCluClusterAvail;
			this.ButCluUnclusterAvail = ButCluUnclusterAvail;
			this.TxtMdlActive = TxtMdlActive;
			this.ButMdlViewAvail = ButMdlViewAvail;
			this.ButMdlViewActive = ButMdlViewActive;
			this.TxtMguActive = TxtMguActive;
			this.ButMguViewAvail = ButMguViewAvail;
			this.ButMguViewActive = ButMguViewActive;
			this.TxtVecActive = TxtVecActive;
			this.ButVecViewAvail = ButVecViewAvail;
			this.ButVecViewActive = ButVecViewActive;
			this.ChkConActive = ChkConActive;
			this.PupHtyActive = PupHtyActive;
			this.ButHtyEditAvail = ButHtyEditAvail;
			this.TxfWidActive = TxfWidActive;
			this.TxfMmxActive = TxfMmxActive;
			this.TxfCmbActive = TxfCmbActive;
			this.TxfOnvActive = TxfOnvActive;
			this.TxfOfvActive = TxfOfvActive;
			this.ChkDfoActive = ChkDfoActive;
			this.TxtDrvActive = TxtDrvActive;
			this.ButDrvViewAvail = ButDrvViewAvail;
			this.ButDrvViewActive = ButDrvViewActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFHTYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTMGUACTIVE, BUTMGUVIEWAVAIL, BUTMGUVIEWACTIVE, TXTVECACTIVE, BUTVECVIEWAVAIL, BUTVECVIEWACTIVE, CHKCONACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFCMBACTIVE, TXFONVACTIVE, TXFOFVACTIVE, CHKDFOACTIVE, TXTDRVACTIVE, BUTDRVVIEWAVAIL, BUTDRVVIEWACTIVE, TXFCMTACTIVE));
		};

		public boolean TxfHtyValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupTypActive;
		public boolean LstCluActive;
		public boolean ButCluViewActive;
		public boolean ButCluClusterAvail;
		public boolean ButCluUnclusterAvail;
		public boolean TxtMdlActive;
		public boolean ButMdlViewAvail;
		public boolean ButMdlViewActive;
		public boolean TxtMguActive;
		public boolean ButMguViewAvail;
		public boolean ButMguViewActive;
		public boolean TxtVecActive;
		public boolean ButVecViewAvail;
		public boolean ButVecViewActive;
		public boolean ChkConActive;
		public boolean PupHtyActive;
		public boolean ButHtyEditAvail;
		public boolean TxfWidActive;
		public boolean TxfMmxActive;
		public boolean TxfCmbActive;
		public boolean TxfOnvActive;
		public boolean TxfOfvActive;
		public boolean ChkDfoActive;
		public boolean TxtDrvActive;
		public boolean ButDrvViewAvail;
		public boolean ButDrvViewActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeSigDetail");

			String itemtag = "StatitemShrWdbeSigDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfHtyValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfHtyValid", mask, TXFHTYVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				LstCluActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluActive", mask, LSTCLUACTIVE);
				ButCluViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluViewActive", mask, BUTCLUVIEWACTIVE);
				ButCluClusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", mask, BUTCLUCLUSTERAVAIL);
				ButCluUnclusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", mask, BUTCLUUNCLUSTERAVAIL);
				TxtMdlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtMdlActive", mask, TXTMDLACTIVE);
				ButMdlViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewAvail", mask, BUTMDLVIEWAVAIL);
				ButMdlViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", mask, BUTMDLVIEWACTIVE);
				TxtMguActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtMguActive", mask, TXTMGUACTIVE);
				ButMguViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMguViewAvail", mask, BUTMGUVIEWAVAIL);
				ButMguViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMguViewActive", mask, BUTMGUVIEWACTIVE);
				TxtVecActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVecActive", mask, TXTVECACTIVE);
				ButVecViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVecViewAvail", mask, BUTVECVIEWAVAIL);
				ButVecViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVecViewActive", mask, BUTVECVIEWACTIVE);
				ChkConActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkConActive", mask, CHKCONACTIVE);
				PupHtyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupHtyActive", mask, PUPHTYACTIVE);
				ButHtyEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHtyEditAvail", mask, BUTHTYEDITAVAIL);
				TxfWidActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfWidActive", mask, TXFWIDACTIVE);
				TxfMmxActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMmxActive", mask, TXFMMXACTIVE);
				TxfCmbActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmbActive", mask, TXFCMBACTIVE);
				TxfOnvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfOnvActive", mask, TXFONVACTIVE);
				TxfOfvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfOfvActive", mask, TXFOFVACTIVE);
				ChkDfoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkDfoActive", mask, CHKDFOACTIVE);
				TxtDrvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtDrvActive", mask, TXTDRVACTIVE);
				ButDrvViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDrvViewAvail", mask, BUTDRVVIEWAVAIL);
				ButDrvViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDrvViewActive", mask, BUTDRVVIEWACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfHtyValid == comp.TxfHtyValid) items.add(TXFHTYVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (LstCluActive == comp.LstCluActive) items.add(LSTCLUACTIVE);
			if (ButCluViewActive == comp.ButCluViewActive) items.add(BUTCLUVIEWACTIVE);
			if (ButCluClusterAvail == comp.ButCluClusterAvail) items.add(BUTCLUCLUSTERAVAIL);
			if (ButCluUnclusterAvail == comp.ButCluUnclusterAvail) items.add(BUTCLUUNCLUSTERAVAIL);
			if (TxtMdlActive == comp.TxtMdlActive) items.add(TXTMDLACTIVE);
			if (ButMdlViewAvail == comp.ButMdlViewAvail) items.add(BUTMDLVIEWAVAIL);
			if (ButMdlViewActive == comp.ButMdlViewActive) items.add(BUTMDLVIEWACTIVE);
			if (TxtMguActive == comp.TxtMguActive) items.add(TXTMGUACTIVE);
			if (ButMguViewAvail == comp.ButMguViewAvail) items.add(BUTMGUVIEWAVAIL);
			if (ButMguViewActive == comp.ButMguViewActive) items.add(BUTMGUVIEWACTIVE);
			if (TxtVecActive == comp.TxtVecActive) items.add(TXTVECACTIVE);
			if (ButVecViewAvail == comp.ButVecViewAvail) items.add(BUTVECVIEWAVAIL);
			if (ButVecViewActive == comp.ButVecViewActive) items.add(BUTVECVIEWACTIVE);
			if (ChkConActive == comp.ChkConActive) items.add(CHKCONACTIVE);
			if (PupHtyActive == comp.PupHtyActive) items.add(PUPHTYACTIVE);
			if (ButHtyEditAvail == comp.ButHtyEditAvail) items.add(BUTHTYEDITAVAIL);
			if (TxfWidActive == comp.TxfWidActive) items.add(TXFWIDACTIVE);
			if (TxfMmxActive == comp.TxfMmxActive) items.add(TXFMMXACTIVE);
			if (TxfCmbActive == comp.TxfCmbActive) items.add(TXFCMBACTIVE);
			if (TxfOnvActive == comp.TxfOnvActive) items.add(TXFONVACTIVE);
			if (TxfOfvActive == comp.TxfOfvActive) items.add(TXFOFVACTIVE);
			if (ChkDfoActive == comp.ChkDfoActive) items.add(CHKDFOACTIVE);
			if (TxtDrvActive == comp.TxtDrvActive) items.add(TXTDRVACTIVE);
			if (ButDrvViewAvail == comp.ButDrvViewAvail) items.add(BUTDRVVIEWAVAIL);
			if (ButDrvViewActive == comp.ButDrvViewActive) items.add(BUTDRVVIEWACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFHTYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTMGUACTIVE, BUTMGUVIEWAVAIL, BUTMGUVIEWACTIVE, TXTVECACTIVE, BUTVECVIEWAVAIL, BUTVECVIEWACTIVE, CHKCONACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFCMBACTIVE, TXFONVACTIVE, TXFOFVACTIVE, CHKDFOACTIVE, TXTDRVACTIVE, BUTDRVVIEWAVAIL, BUTDRVVIEWACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeSigDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTYP = 3;
		public static final int CPTCLU = 4;
		public static final int CPTMDL = 5;
		public static final int CPTMGU = 6;
		public static final int CPTVEC = 7;
		public static final int CPTCON = 8;
		public static final int CPTHTY = 9;
		public static final int CPTWID = 10;
		public static final int CPTMMX = 11;
		public static final int CPTCMB = 12;
		public static final int CPTONV = 13;
		public static final int CPTOFV = 14;
		public static final int CPTDFO = 15;
		public static final int CPTDRV = 16;
		public static final int CPTCMT = 17;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTyp
					, String CptClu
					, String CptMdl
					, String CptMgu
					, String CptVec
					, String CptCon
					, String CptHty
					, String CptWid
					, String CptMmx
					, String CptCmb
					, String CptOnv
					, String CptOfv
					, String CptDfo
					, String CptDrv
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTyp = CptTyp;
			this.CptClu = CptClu;
			this.CptMdl = CptMdl;
			this.CptMgu = CptMgu;
			this.CptVec = CptVec;
			this.CptCon = CptCon;
			this.CptHty = CptHty;
			this.CptWid = CptWid;
			this.CptMmx = CptMmx;
			this.CptCmb = CptCmb;
			this.CptOnv = CptOnv;
			this.CptOfv = CptOfv;
			this.CptDfo = CptDfo;
			this.CptDrv = CptDrv;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTCLU, CPTMDL, CPTMGU, CPTVEC, CPTCON, CPTHTY, CPTWID, CPTMMX, CPTCMB, CPTONV, CPTOFV, CPTDFO, CPTDRV, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTyp;
		public String CptClu;
		public String CptMdl;
		public String CptMgu;
		public String CptVec;
		public String CptCon;
		public String CptHty;
		public String CptWid;
		public String CptMmx;
		public String CptCmb;
		public String CptOnv;
		public String CptOfv;
		public String CptDfo;
		public String CptDrv;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeSigDetail");

			String itemtag = "TagitemWdbeSigDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptClu", mask, CPTCLU);
				CptMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMdl", mask, CPTMDL);
				CptMgu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMgu", mask, CPTMGU);
				CptVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVec", mask, CPTVEC);
				CptCon = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCon", mask, CPTCON);
				CptHty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptHty", mask, CPTHTY);
				CptWid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptWid", mask, CPTWID);
				CptMmx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMmx", mask, CPTMMX);
				CptCmb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmb", mask, CPTCMB);
				CptOnv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOnv", mask, CPTONV);
				CptOfv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOfv", mask, CPTOFV);
				CptDfo = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDfo", mask, CPTDFO);
				CptDrv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDrv", mask, CPTDRV);
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
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptClu.equals(comp.CptClu)) items.add(CPTCLU);
			if (CptMdl.equals(comp.CptMdl)) items.add(CPTMDL);
			if (CptMgu.equals(comp.CptMgu)) items.add(CPTMGU);
			if (CptVec.equals(comp.CptVec)) items.add(CPTVEC);
			if (CptCon.equals(comp.CptCon)) items.add(CPTCON);
			if (CptHty.equals(comp.CptHty)) items.add(CPTHTY);
			if (CptWid.equals(comp.CptWid)) items.add(CPTWID);
			if (CptMmx.equals(comp.CptMmx)) items.add(CPTMMX);
			if (CptCmb.equals(comp.CptCmb)) items.add(CPTCMB);
			if (CptOnv.equals(comp.CptOnv)) items.add(CPTONV);
			if (CptOfv.equals(comp.CptOfv)) items.add(CPTOFV);
			if (CptDfo.equals(comp.CptDfo)) items.add(CPTDFO);
			if (CptDrv.equals(comp.CptDrv)) items.add(CPTDRV);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTCLU, CPTMDL, CPTMGU, CPTVEC, CPTCON, CPTHTY, CPTWID, CPTMMX, CPTCMB, CPTONV, CPTOFV, CPTDFO, CPTDRV, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeSigDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBESIGDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeSigDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeSigDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBESIGDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeSigDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeSigDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTCLU = 4;
		public static final int FEEDFPUPHTY = 5;
		public static final int FEEDFPUPMGT = 6;
		public static final int FEEDFPUPTYP = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBESIGDETAILDATA);

			contiac = new ContIac(0, 0, 0, false, 0, "", "", "", "", "", "", false, "");
			continf = new ContInf("", "", "", "", "", "");
			feedFLstClu = new Feed("FeedFLstClu");
			feedFPupHty = new Feed("FeedFPupHty");
			feedFPupMgt = new Feed("FeedFPupMgt");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstClu;
		public Feed feedFPupHty;
		public Feed feedFPupMgt;
		public Feed feedFPupTyp;
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
			if (has(FEEDFPUPMGT)) ss.add("feedFPupMgt");
			if (has(FEEDFPUPTYP)) ss.add("feedFPupTyp");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeSigDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstClu.readXML(doc, basexpath, true)) add(FEEDFLSTCLU);
				if (feedFPupHty.readXML(doc, basexpath, true)) add(FEEDFPUPHTY);
				if (feedFPupMgt.readXML(doc, basexpath, true)) add(FEEDFPUPMGT);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, false, 0, "", "", "", "", "", "", false, "");
				continf = new ContInf("", "", "", "", "", "");
				feedFLstClu = new Feed("FeedFLstClu");
				feedFPupHty = new Feed("FeedFPupHty");
				feedFPupMgt = new Feed("FeedFPupMgt");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

