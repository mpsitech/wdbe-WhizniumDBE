/**
  * \file PnlWdbeGenDetail.java
  * Java API code for job PnlWdbeGenDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeGenDetail {
	/**
		* VecVDo (full: VecVWdbeGenDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTCLUVIEWCLICK = 2;
		public static final int BUTCLUCLUSTERCLICK = 3;
		public static final int BUTCLUUNCLUSTERCLICK = 4;
		public static final int BUTMDLVIEWCLICK = 5;
		public static final int BUTHTYEDITCLICK = 6;
		public static final int BUTSRCVIEWCLICK = 7;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butcluviewclick")) return BUTCLUVIEWCLICK;
			if (s.equals("butcluclusterclick")) return BUTCLUCLUSTERCLICK;
			if (s.equals("butcluunclusterclick")) return BUTCLUUNCLUSTERCLICK;
			if (s.equals("butmdlviewclick")) return BUTMDLVIEWCLICK;
			if (s.equals("buthtyeditclick")) return BUTHTYEDITCLICK;
			if (s.equals("butsrcviewclick")) return BUTSRCVIEWCLICK;

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
			if (ix == BUTHTYEDITCLICK) return("ButHtyEditClick");
			if (ix == BUTSRCVIEWCLICK) return("ButSrcViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeGenDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTCLU = 1;
		public static final int NUMFPUPHTY = 2;
		public static final int TXFHTY = 3;
		public static final int TXFWID = 4;
		public static final int TXFMMX = 5;
		public static final int TXFDFV = 6;
		public static final int TXFSRC = 7;
		public static final int TXFCMT = 8;

		public ContIac(
					int numFLstClu
					, int numFPupHty
					, String TxfHty
					, String TxfWid
					, String TxfMmx
					, String TxfDfv
					, String TxfSrc
					, String TxfCmt
				) {
			this.numFLstClu = numFLstClu;
			this.numFPupHty = numFPupHty;
			this.TxfHty = TxfHty;
			this.TxfWid = TxfWid;
			this.TxfMmx = TxfMmx;
			this.TxfDfv = TxfDfv;
			this.TxfSrc = TxfSrc;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTCLU, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFDFV, TXFSRC, TXFCMT));
		};

		public int numFLstClu;
		public int numFPupHty;
		public String TxfHty;
		public String TxfWid;
		public String TxfMmx;
		public String TxfDfv;
		public String TxfSrc;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeGenDetail");

			String itemtag = "ContitemIacWdbeGenDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstClu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstClu", mask, NUMFLSTCLU);
				numFPupHty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupHty", mask, NUMFPUPHTY);
				TxfHty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfHty", mask, TXFHTY);
				TxfWid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfWid", mask, TXFWID);
				TxfMmx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMmx", mask, TXFMMX);
				TxfDfv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfDfv", mask, TXFDFV);
				TxfSrc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSrc", mask, TXFSRC);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbeGenDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeGenDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstClu", numFLstClu);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupHty", numFPupHty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfHty", TxfHty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfWid", TxfWid);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMmx", TxfMmx);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfDfv", TxfDfv);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSrc", TxfSrc);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstClu == comp.numFLstClu) items.add(NUMFLSTCLU);
			if (numFPupHty == comp.numFPupHty) items.add(NUMFPUPHTY);
			if (TxfHty.equals(comp.TxfHty)) items.add(TXFHTY);
			if (TxfWid.equals(comp.TxfWid)) items.add(TXFWID);
			if (TxfMmx.equals(comp.TxfMmx)) items.add(TXFMMX);
			if (TxfDfv.equals(comp.TxfDfv)) items.add(TXFDFV);
			if (TxfSrc.equals(comp.TxfSrc)) items.add(TXFSRC);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTCLU, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFDFV, TXFSRC, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeGenDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTCLU = 2;
		public static final int TXTMDL = 3;
		public static final int TXTSRC = 4;

		public ContInf(
					String TxtSrf
					, String TxtClu
					, String TxtMdl
					, String TxtSrc
				) {
			this.TxtSrf = TxtSrf;
			this.TxtClu = TxtClu;
			this.TxtMdl = TxtMdl;
			this.TxtSrc = TxtSrc;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCLU, TXTMDL, TXTSRC));
		};

		public String TxtSrf;
		public String TxtClu;
		public String TxtMdl;
		public String TxtSrc;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeGenDetail");

			String itemtag = "ContitemInfWdbeGenDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtClu", mask, TXTCLU);
				TxtMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMdl", mask, TXTMDL);
				TxtSrc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrc", mask, TXTSRC);

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
			if (TxtSrc.equals(comp.TxtSrc)) items.add(TXTSRC);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCLU, TXTMDL, TXTSRC));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeGenDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTCLUALT = 2;
		public static final int PUPHTYALT = 3;
		public static final int TXTSRCALT = 4;
		public static final int LSTCLUNUMFIRSTDISP = 5;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstCluAlt
					, boolean PupHtyAlt
					, boolean TxtSrcAlt
					, int LstCluNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstCluAlt = LstCluAlt;
			this.PupHtyAlt = PupHtyAlt;
			this.TxtSrcAlt = TxtSrcAlt;
			this.LstCluNumFirstdisp = LstCluNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, TXTSRCALT, LSTCLUNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstCluAlt;
		public boolean PupHtyAlt;
		public boolean TxtSrcAlt;
		public int LstCluNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeGenDetail");

			String itemtag = "StatitemAppWdbeGenDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstCluAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluAlt", mask, LSTCLUALT);
				PupHtyAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupHtyAlt", mask, PUPHTYALT);
				TxtSrcAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrcAlt", mask, TXTSRCALT);
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
			if (TxtSrcAlt == comp.TxtSrcAlt) items.add(TXTSRCALT);
			if (LstCluNumFirstdisp == comp.LstCluNumFirstdisp) items.add(LSTCLUNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, TXTSRCALT, LSTCLUNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeGenDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFHTYVALID = 1;
		public static final int TXFSRCVALID = 2;
		public static final int BUTSAVEAVAIL = 3;
		public static final int BUTSAVEACTIVE = 4;
		public static final int TXTSRFACTIVE = 5;
		public static final int LSTCLUACTIVE = 6;
		public static final int BUTCLUVIEWACTIVE = 7;
		public static final int BUTCLUCLUSTERAVAIL = 8;
		public static final int BUTCLUUNCLUSTERAVAIL = 9;
		public static final int TXTMDLACTIVE = 10;
		public static final int BUTMDLVIEWAVAIL = 11;
		public static final int BUTMDLVIEWACTIVE = 12;
		public static final int PUPHTYACTIVE = 13;
		public static final int BUTHTYEDITAVAIL = 14;
		public static final int TXFWIDACTIVE = 15;
		public static final int TXFMMXACTIVE = 16;
		public static final int TXFDFVACTIVE = 17;
		public static final int TXTSRCACTIVE = 18;
		public static final int BUTSRCVIEWAVAIL = 19;
		public static final int TXFCMTACTIVE = 20;

		public StatShr(
					boolean TxfHtyValid
					, boolean TxfSrcValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean LstCluActive
					, boolean ButCluViewActive
					, boolean ButCluClusterAvail
					, boolean ButCluUnclusterAvail
					, boolean TxtMdlActive
					, boolean ButMdlViewAvail
					, boolean ButMdlViewActive
					, boolean PupHtyActive
					, boolean ButHtyEditAvail
					, boolean TxfWidActive
					, boolean TxfMmxActive
					, boolean TxfDfvActive
					, boolean TxtSrcActive
					, boolean ButSrcViewAvail
					, boolean TxfCmtActive
				) {
			this.TxfHtyValid = TxfHtyValid;
			this.TxfSrcValid = TxfSrcValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.LstCluActive = LstCluActive;
			this.ButCluViewActive = ButCluViewActive;
			this.ButCluClusterAvail = ButCluClusterAvail;
			this.ButCluUnclusterAvail = ButCluUnclusterAvail;
			this.TxtMdlActive = TxtMdlActive;
			this.ButMdlViewAvail = ButMdlViewAvail;
			this.ButMdlViewActive = ButMdlViewActive;
			this.PupHtyActive = PupHtyActive;
			this.ButHtyEditAvail = ButHtyEditAvail;
			this.TxfWidActive = TxfWidActive;
			this.TxfMmxActive = TxfMmxActive;
			this.TxfDfvActive = TxfDfvActive;
			this.TxtSrcActive = TxtSrcActive;
			this.ButSrcViewAvail = ButSrcViewAvail;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFHTYVALID, TXFSRCVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFDFVACTIVE, TXTSRCACTIVE, BUTSRCVIEWAVAIL, TXFCMTACTIVE));
		};

		public boolean TxfHtyValid;
		public boolean TxfSrcValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean LstCluActive;
		public boolean ButCluViewActive;
		public boolean ButCluClusterAvail;
		public boolean ButCluUnclusterAvail;
		public boolean TxtMdlActive;
		public boolean ButMdlViewAvail;
		public boolean ButMdlViewActive;
		public boolean PupHtyActive;
		public boolean ButHtyEditAvail;
		public boolean TxfWidActive;
		public boolean TxfMmxActive;
		public boolean TxfDfvActive;
		public boolean TxtSrcActive;
		public boolean ButSrcViewAvail;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeGenDetail");

			String itemtag = "StatitemShrWdbeGenDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfHtyValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfHtyValid", mask, TXFHTYVALID);
				TxfSrcValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSrcValid", mask, TXFSRCVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				LstCluActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluActive", mask, LSTCLUACTIVE);
				ButCluViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluViewActive", mask, BUTCLUVIEWACTIVE);
				ButCluClusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", mask, BUTCLUCLUSTERAVAIL);
				ButCluUnclusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", mask, BUTCLUUNCLUSTERAVAIL);
				TxtMdlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtMdlActive", mask, TXTMDLACTIVE);
				ButMdlViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewAvail", mask, BUTMDLVIEWAVAIL);
				ButMdlViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", mask, BUTMDLVIEWACTIVE);
				PupHtyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupHtyActive", mask, PUPHTYACTIVE);
				ButHtyEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHtyEditAvail", mask, BUTHTYEDITAVAIL);
				TxfWidActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfWidActive", mask, TXFWIDACTIVE);
				TxfMmxActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMmxActive", mask, TXFMMXACTIVE);
				TxfDfvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfDfvActive", mask, TXFDFVACTIVE);
				TxtSrcActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrcActive", mask, TXTSRCACTIVE);
				ButSrcViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSrcViewAvail", mask, BUTSRCVIEWAVAIL);
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
			if (TxfSrcValid == comp.TxfSrcValid) items.add(TXFSRCVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (LstCluActive == comp.LstCluActive) items.add(LSTCLUACTIVE);
			if (ButCluViewActive == comp.ButCluViewActive) items.add(BUTCLUVIEWACTIVE);
			if (ButCluClusterAvail == comp.ButCluClusterAvail) items.add(BUTCLUCLUSTERAVAIL);
			if (ButCluUnclusterAvail == comp.ButCluUnclusterAvail) items.add(BUTCLUUNCLUSTERAVAIL);
			if (TxtMdlActive == comp.TxtMdlActive) items.add(TXTMDLACTIVE);
			if (ButMdlViewAvail == comp.ButMdlViewAvail) items.add(BUTMDLVIEWAVAIL);
			if (ButMdlViewActive == comp.ButMdlViewActive) items.add(BUTMDLVIEWACTIVE);
			if (PupHtyActive == comp.PupHtyActive) items.add(PUPHTYACTIVE);
			if (ButHtyEditAvail == comp.ButHtyEditAvail) items.add(BUTHTYEDITAVAIL);
			if (TxfWidActive == comp.TxfWidActive) items.add(TXFWIDACTIVE);
			if (TxfMmxActive == comp.TxfMmxActive) items.add(TXFMMXACTIVE);
			if (TxfDfvActive == comp.TxfDfvActive) items.add(TXFDFVACTIVE);
			if (TxtSrcActive == comp.TxtSrcActive) items.add(TXTSRCACTIVE);
			if (ButSrcViewAvail == comp.ButSrcViewAvail) items.add(BUTSRCVIEWAVAIL);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFHTYVALID, TXFSRCVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFDFVACTIVE, TXTSRCACTIVE, BUTSRCVIEWAVAIL, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeGenDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTCLU = 3;
		public static final int CPTMDL = 4;
		public static final int CPTHTY = 5;
		public static final int CPTWID = 6;
		public static final int CPTMMX = 7;
		public static final int CPTDFV = 8;
		public static final int CPTSRC = 9;
		public static final int CPTCMT = 10;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptClu
					, String CptMdl
					, String CptHty
					, String CptWid
					, String CptMmx
					, String CptDfv
					, String CptSrc
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptClu = CptClu;
			this.CptMdl = CptMdl;
			this.CptHty = CptHty;
			this.CptWid = CptWid;
			this.CptMmx = CptMmx;
			this.CptDfv = CptDfv;
			this.CptSrc = CptSrc;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCLU, CPTMDL, CPTHTY, CPTWID, CPTMMX, CPTDFV, CPTSRC, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptClu;
		public String CptMdl;
		public String CptHty;
		public String CptWid;
		public String CptMmx;
		public String CptDfv;
		public String CptSrc;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeGenDetail");

			String itemtag = "TagitemWdbeGenDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptClu", mask, CPTCLU);
				CptMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMdl", mask, CPTMDL);
				CptHty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptHty", mask, CPTHTY);
				CptWid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptWid", mask, CPTWID);
				CptMmx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMmx", mask, CPTMMX);
				CptDfv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDfv", mask, CPTDFV);
				CptSrc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrc", mask, CPTSRC);
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
			if (CptMdl.equals(comp.CptMdl)) items.add(CPTMDL);
			if (CptHty.equals(comp.CptHty)) items.add(CPTHTY);
			if (CptWid.equals(comp.CptWid)) items.add(CPTWID);
			if (CptMmx.equals(comp.CptMmx)) items.add(CPTMMX);
			if (CptDfv.equals(comp.CptDfv)) items.add(CPTDFV);
			if (CptSrc.equals(comp.CptSrc)) items.add(CPTSRC);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCLU, CPTMDL, CPTHTY, CPTWID, CPTMMX, CPTDFV, CPTSRC, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeGenDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEGENDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeGenDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeGenDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEGENDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeGenDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeGenDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTCLU = 4;
		public static final int FEEDFPUPHTY = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEGENDETAILDATA);

			contiac = new ContIac(0, 0, "", "", "", "", "", "");
			continf = new ContInf("", "", "", "");
			feedFLstClu = new Feed("FeedFLstClu");
			feedFPupHty = new Feed("FeedFPupHty");
			statapp = new StatApp(0, false, false, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstClu;
		public Feed feedFPupHty;
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeGenDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstClu.readXML(doc, basexpath, true)) add(FEEDFLSTCLU);
				if (feedFPupHty.readXML(doc, basexpath, true)) add(FEEDFPUPHTY);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, "", "", "", "", "", "");
				continf = new ContInf("", "", "", "");
				feedFLstClu = new Feed("FeedFLstClu");
				feedFPupHty = new Feed("FeedFPupHty");
				statapp = new StatApp(0, false, false, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

