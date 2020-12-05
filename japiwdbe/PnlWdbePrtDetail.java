/**
  * \file PnlWdbePrtDetail.java
  * Java API code for job PnlWdbePrtDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbePrtDetail {
	/**
		* VecVDo (full: VecVWdbePrtDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTCLUVIEWCLICK = 2;
		public static final int BUTCLUCLUSTERCLICK = 3;
		public static final int BUTCLUUNCLUSTERCLICK = 4;
		public static final int BUTMDLVIEWCLICK = 5;
		public static final int BUTHTYEDITCLICK = 6;
		public static final int BUTCPIVIEWCLICK = 7;
		public static final int BUTCPRVIEWCLICK = 8;
		public static final int BUTCSIVIEWCLICK = 9;

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
			if (s.equals("butcpiviewclick")) return BUTCPIVIEWCLICK;
			if (s.equals("butcprviewclick")) return BUTCPRVIEWCLICK;
			if (s.equals("butcsiviewclick")) return BUTCSIVIEWCLICK;

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
			if (ix == BUTCPIVIEWCLICK) return("ButCpiViewClick");
			if (ix == BUTCPRVIEWCLICK) return("ButCprViewClick");
			if (ix == BUTCSIVIEWCLICK) return("ButCsiViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbePrtDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTCLU = 1;
		public static final int NUMFPUPDIR = 2;
		public static final int NUMFPUPHTY = 3;
		public static final int TXFHTY = 4;
		public static final int TXFWID = 5;
		public static final int TXFMMX = 6;
		public static final int TXFDFV = 7;
		public static final int TXFCPI = 8;
		public static final int TXFCPR = 9;
		public static final int TXFCSI = 10;
		public static final int TXFCMT = 11;

		public ContIac(
					int numFLstClu
					, int numFPupDir
					, int numFPupHty
					, String TxfHty
					, String TxfWid
					, String TxfMmx
					, String TxfDfv
					, String TxfCpi
					, String TxfCpr
					, String TxfCsi
					, String TxfCmt
				) {
			this.numFLstClu = numFLstClu;
			this.numFPupDir = numFPupDir;
			this.numFPupHty = numFPupHty;
			this.TxfHty = TxfHty;
			this.TxfWid = TxfWid;
			this.TxfMmx = TxfMmx;
			this.TxfDfv = TxfDfv;
			this.TxfCpi = TxfCpi;
			this.TxfCpr = TxfCpr;
			this.TxfCsi = TxfCsi;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTCLU, NUMFPUPDIR, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFDFV, TXFCPI, TXFCPR, TXFCSI, TXFCMT));
		};

		public int numFLstClu;
		public int numFPupDir;
		public int numFPupHty;
		public String TxfHty;
		public String TxfWid;
		public String TxfMmx;
		public String TxfDfv;
		public String TxfCpi;
		public String TxfCpr;
		public String TxfCsi;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbePrtDetail");

			String itemtag = "ContitemIacWdbePrtDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstClu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstClu", mask, NUMFLSTCLU);
				numFPupDir = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupDir", mask, NUMFPUPDIR);
				numFPupHty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupHty", mask, NUMFPUPHTY);
				TxfHty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfHty", mask, TXFHTY);
				TxfWid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfWid", mask, TXFWID);
				TxfMmx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMmx", mask, TXFMMX);
				TxfDfv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfDfv", mask, TXFDFV);
				TxfCpi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCpi", mask, TXFCPI);
				TxfCpr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCpr", mask, TXFCPR);
				TxfCsi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCsi", mask, TXFCSI);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbePrtDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbePrtDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstClu", numFLstClu);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupDir", numFPupDir);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupHty", numFPupHty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfHty", TxfHty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfWid", TxfWid);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMmx", TxfMmx);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfDfv", TxfDfv);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCpi", TxfCpi);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCpr", TxfCpr);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCsi", TxfCsi);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstClu == comp.numFLstClu) items.add(NUMFLSTCLU);
			if (numFPupDir == comp.numFPupDir) items.add(NUMFPUPDIR);
			if (numFPupHty == comp.numFPupHty) items.add(NUMFPUPHTY);
			if (TxfHty.equals(comp.TxfHty)) items.add(TXFHTY);
			if (TxfWid.equals(comp.TxfWid)) items.add(TXFWID);
			if (TxfMmx.equals(comp.TxfMmx)) items.add(TXFMMX);
			if (TxfDfv.equals(comp.TxfDfv)) items.add(TXFDFV);
			if (TxfCpi.equals(comp.TxfCpi)) items.add(TXFCPI);
			if (TxfCpr.equals(comp.TxfCpr)) items.add(TXFCPR);
			if (TxfCsi.equals(comp.TxfCsi)) items.add(TXFCSI);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTCLU, NUMFPUPDIR, NUMFPUPHTY, TXFHTY, TXFWID, TXFMMX, TXFDFV, TXFCPI, TXFCPR, TXFCSI, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbePrtDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTCLU = 2;
		public static final int TXTMDL = 3;
		public static final int TXTCPI = 4;
		public static final int TXTCPR = 5;
		public static final int TXTCSI = 6;

		public ContInf(
					String TxtSrf
					, String TxtClu
					, String TxtMdl
					, String TxtCpi
					, String TxtCpr
					, String TxtCsi
				) {
			this.TxtSrf = TxtSrf;
			this.TxtClu = TxtClu;
			this.TxtMdl = TxtMdl;
			this.TxtCpi = TxtCpi;
			this.TxtCpr = TxtCpr;
			this.TxtCsi = TxtCsi;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCLU, TXTMDL, TXTCPI, TXTCPR, TXTCSI));
		};

		public String TxtSrf;
		public String TxtClu;
		public String TxtMdl;
		public String TxtCpi;
		public String TxtCpr;
		public String TxtCsi;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbePrtDetail");

			String itemtag = "ContitemInfWdbePrtDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtClu", mask, TXTCLU);
				TxtMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMdl", mask, TXTMDL);
				TxtCpi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCpi", mask, TXTCPI);
				TxtCpr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCpr", mask, TXTCPR);
				TxtCsi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCsi", mask, TXTCSI);

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
			if (TxtCpi.equals(comp.TxtCpi)) items.add(TXTCPI);
			if (TxtCpr.equals(comp.TxtCpr)) items.add(TXTCPR);
			if (TxtCsi.equals(comp.TxtCsi)) items.add(TXTCSI);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCLU, TXTMDL, TXTCPI, TXTCPR, TXTCSI));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbePrtDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTCLUALT = 2;
		public static final int PUPHTYALT = 3;
		public static final int TXTCPIALT = 4;
		public static final int TXTCPRALT = 5;
		public static final int TXTCSIALT = 6;
		public static final int LSTCLUNUMFIRSTDISP = 7;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstCluAlt
					, boolean PupHtyAlt
					, boolean TxtCpiAlt
					, boolean TxtCprAlt
					, boolean TxtCsiAlt
					, int LstCluNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstCluAlt = LstCluAlt;
			this.PupHtyAlt = PupHtyAlt;
			this.TxtCpiAlt = TxtCpiAlt;
			this.TxtCprAlt = TxtCprAlt;
			this.TxtCsiAlt = TxtCsiAlt;
			this.LstCluNumFirstdisp = LstCluNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, TXTCPIALT, TXTCPRALT, TXTCSIALT, LSTCLUNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstCluAlt;
		public boolean PupHtyAlt;
		public boolean TxtCpiAlt;
		public boolean TxtCprAlt;
		public boolean TxtCsiAlt;
		public int LstCluNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbePrtDetail");

			String itemtag = "StatitemAppWdbePrtDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstCluAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluAlt", mask, LSTCLUALT);
				PupHtyAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupHtyAlt", mask, PUPHTYALT);
				TxtCpiAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCpiAlt", mask, TXTCPIALT);
				TxtCprAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCprAlt", mask, TXTCPRALT);
				TxtCsiAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCsiAlt", mask, TXTCSIALT);
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
			if (TxtCpiAlt == comp.TxtCpiAlt) items.add(TXTCPIALT);
			if (TxtCprAlt == comp.TxtCprAlt) items.add(TXTCPRALT);
			if (TxtCsiAlt == comp.TxtCsiAlt) items.add(TXTCSIALT);
			if (LstCluNumFirstdisp == comp.LstCluNumFirstdisp) items.add(LSTCLUNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCLUALT, PUPHTYALT, TXTCPIALT, TXTCPRALT, TXTCSIALT, LSTCLUNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbePrtDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFHTYVALID = 1;
		public static final int TXFCPIVALID = 2;
		public static final int TXFCPRVALID = 3;
		public static final int TXFCSIVALID = 4;
		public static final int BUTSAVEAVAIL = 5;
		public static final int BUTSAVEACTIVE = 6;
		public static final int TXTSRFACTIVE = 7;
		public static final int LSTCLUACTIVE = 8;
		public static final int BUTCLUVIEWACTIVE = 9;
		public static final int BUTCLUCLUSTERAVAIL = 10;
		public static final int BUTCLUUNCLUSTERAVAIL = 11;
		public static final int TXTMDLACTIVE = 12;
		public static final int BUTMDLVIEWAVAIL = 13;
		public static final int BUTMDLVIEWACTIVE = 14;
		public static final int PUPDIRACTIVE = 15;
		public static final int PUPHTYACTIVE = 16;
		public static final int BUTHTYEDITAVAIL = 17;
		public static final int TXFWIDACTIVE = 18;
		public static final int TXFMMXACTIVE = 19;
		public static final int TXFDFVACTIVE = 20;
		public static final int TXTCPIACTIVE = 21;
		public static final int BUTCPIVIEWAVAIL = 22;
		public static final int TXTCPRACTIVE = 23;
		public static final int BUTCPRVIEWAVAIL = 24;
		public static final int TXTCSIACTIVE = 25;
		public static final int BUTCSIVIEWAVAIL = 26;
		public static final int TXFCMTACTIVE = 27;

		public StatShr(
					boolean TxfHtyValid
					, boolean TxfCpiValid
					, boolean TxfCprValid
					, boolean TxfCsiValid
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
					, boolean PupDirActive
					, boolean PupHtyActive
					, boolean ButHtyEditAvail
					, boolean TxfWidActive
					, boolean TxfMmxActive
					, boolean TxfDfvActive
					, boolean TxtCpiActive
					, boolean ButCpiViewAvail
					, boolean TxtCprActive
					, boolean ButCprViewAvail
					, boolean TxtCsiActive
					, boolean ButCsiViewAvail
					, boolean TxfCmtActive
				) {
			this.TxfHtyValid = TxfHtyValid;
			this.TxfCpiValid = TxfCpiValid;
			this.TxfCprValid = TxfCprValid;
			this.TxfCsiValid = TxfCsiValid;
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
			this.PupDirActive = PupDirActive;
			this.PupHtyActive = PupHtyActive;
			this.ButHtyEditAvail = ButHtyEditAvail;
			this.TxfWidActive = TxfWidActive;
			this.TxfMmxActive = TxfMmxActive;
			this.TxfDfvActive = TxfDfvActive;
			this.TxtCpiActive = TxtCpiActive;
			this.ButCpiViewAvail = ButCpiViewAvail;
			this.TxtCprActive = TxtCprActive;
			this.ButCprViewAvail = ButCprViewAvail;
			this.TxtCsiActive = TxtCsiActive;
			this.ButCsiViewAvail = ButCsiViewAvail;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFHTYVALID, TXFCPIVALID, TXFCPRVALID, TXFCSIVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPDIRACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFDFVACTIVE, TXTCPIACTIVE, BUTCPIVIEWAVAIL, TXTCPRACTIVE, BUTCPRVIEWAVAIL, TXTCSIACTIVE, BUTCSIVIEWAVAIL, TXFCMTACTIVE));
		};

		public boolean TxfHtyValid;
		public boolean TxfCpiValid;
		public boolean TxfCprValid;
		public boolean TxfCsiValid;
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
		public boolean PupDirActive;
		public boolean PupHtyActive;
		public boolean ButHtyEditAvail;
		public boolean TxfWidActive;
		public boolean TxfMmxActive;
		public boolean TxfDfvActive;
		public boolean TxtCpiActive;
		public boolean ButCpiViewAvail;
		public boolean TxtCprActive;
		public boolean ButCprViewAvail;
		public boolean TxtCsiActive;
		public boolean ButCsiViewAvail;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbePrtDetail");

			String itemtag = "StatitemShrWdbePrtDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfHtyValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfHtyValid", mask, TXFHTYVALID);
				TxfCpiValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCpiValid", mask, TXFCPIVALID);
				TxfCprValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCprValid", mask, TXFCPRVALID);
				TxfCsiValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCsiValid", mask, TXFCSIVALID);
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
				PupDirActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupDirActive", mask, PUPDIRACTIVE);
				PupHtyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupHtyActive", mask, PUPHTYACTIVE);
				ButHtyEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHtyEditAvail", mask, BUTHTYEDITAVAIL);
				TxfWidActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfWidActive", mask, TXFWIDACTIVE);
				TxfMmxActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMmxActive", mask, TXFMMXACTIVE);
				TxfDfvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfDfvActive", mask, TXFDFVACTIVE);
				TxtCpiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCpiActive", mask, TXTCPIACTIVE);
				ButCpiViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCpiViewAvail", mask, BUTCPIVIEWAVAIL);
				TxtCprActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCprActive", mask, TXTCPRACTIVE);
				ButCprViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCprViewAvail", mask, BUTCPRVIEWAVAIL);
				TxtCsiActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCsiActive", mask, TXTCSIACTIVE);
				ButCsiViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCsiViewAvail", mask, BUTCSIVIEWAVAIL);
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
			if (TxfCpiValid == comp.TxfCpiValid) items.add(TXFCPIVALID);
			if (TxfCprValid == comp.TxfCprValid) items.add(TXFCPRVALID);
			if (TxfCsiValid == comp.TxfCsiValid) items.add(TXFCSIVALID);
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
			if (PupDirActive == comp.PupDirActive) items.add(PUPDIRACTIVE);
			if (PupHtyActive == comp.PupHtyActive) items.add(PUPHTYACTIVE);
			if (ButHtyEditAvail == comp.ButHtyEditAvail) items.add(BUTHTYEDITAVAIL);
			if (TxfWidActive == comp.TxfWidActive) items.add(TXFWIDACTIVE);
			if (TxfMmxActive == comp.TxfMmxActive) items.add(TXFMMXACTIVE);
			if (TxfDfvActive == comp.TxfDfvActive) items.add(TXFDFVACTIVE);
			if (TxtCpiActive == comp.TxtCpiActive) items.add(TXTCPIACTIVE);
			if (ButCpiViewAvail == comp.ButCpiViewAvail) items.add(BUTCPIVIEWAVAIL);
			if (TxtCprActive == comp.TxtCprActive) items.add(TXTCPRACTIVE);
			if (ButCprViewAvail == comp.ButCprViewAvail) items.add(BUTCPRVIEWAVAIL);
			if (TxtCsiActive == comp.TxtCsiActive) items.add(TXTCSIACTIVE);
			if (ButCsiViewAvail == comp.ButCsiViewAvail) items.add(BUTCSIVIEWAVAIL);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFHTYVALID, TXFCPIVALID, TXFCPRVALID, TXFCSIVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPDIRACTIVE, PUPHTYACTIVE, BUTHTYEDITAVAIL, TXFWIDACTIVE, TXFMMXACTIVE, TXFDFVACTIVE, TXTCPIACTIVE, BUTCPIVIEWAVAIL, TXTCPRACTIVE, BUTCPRVIEWAVAIL, TXTCSIACTIVE, BUTCSIVIEWAVAIL, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbePrtDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTCLU = 3;
		public static final int CPTMDL = 4;
		public static final int CPTDIR = 5;
		public static final int CPTHTY = 6;
		public static final int CPTWID = 7;
		public static final int CPTMMX = 8;
		public static final int CPTDFV = 9;
		public static final int CPTCPI = 10;
		public static final int CPTCPR = 11;
		public static final int CPTCSI = 12;
		public static final int CPTCMT = 13;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptClu
					, String CptMdl
					, String CptDir
					, String CptHty
					, String CptWid
					, String CptMmx
					, String CptDfv
					, String CptCpi
					, String CptCpr
					, String CptCsi
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptClu = CptClu;
			this.CptMdl = CptMdl;
			this.CptDir = CptDir;
			this.CptHty = CptHty;
			this.CptWid = CptWid;
			this.CptMmx = CptMmx;
			this.CptDfv = CptDfv;
			this.CptCpi = CptCpi;
			this.CptCpr = CptCpr;
			this.CptCsi = CptCsi;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCLU, CPTMDL, CPTDIR, CPTHTY, CPTWID, CPTMMX, CPTDFV, CPTCPI, CPTCPR, CPTCSI, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptClu;
		public String CptMdl;
		public String CptDir;
		public String CptHty;
		public String CptWid;
		public String CptMmx;
		public String CptDfv;
		public String CptCpi;
		public String CptCpr;
		public String CptCsi;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbePrtDetail");

			String itemtag = "TagitemWdbePrtDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptClu", mask, CPTCLU);
				CptMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMdl", mask, CPTMDL);
				CptDir = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDir", mask, CPTDIR);
				CptHty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptHty", mask, CPTHTY);
				CptWid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptWid", mask, CPTWID);
				CptMmx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMmx", mask, CPTMMX);
				CptDfv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptDfv", mask, CPTDFV);
				CptCpi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCpi", mask, CPTCPI);
				CptCpr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCpr", mask, CPTCPR);
				CptCsi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCsi", mask, CPTCSI);
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
			if (CptDir.equals(comp.CptDir)) items.add(CPTDIR);
			if (CptHty.equals(comp.CptHty)) items.add(CPTHTY);
			if (CptWid.equals(comp.CptWid)) items.add(CPTWID);
			if (CptMmx.equals(comp.CptMmx)) items.add(CPTMMX);
			if (CptDfv.equals(comp.CptDfv)) items.add(CPTDFV);
			if (CptCpi.equals(comp.CptCpi)) items.add(CPTCPI);
			if (CptCpr.equals(comp.CptCpr)) items.add(CPTCPR);
			if (CptCsi.equals(comp.CptCsi)) items.add(CPTCSI);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCLU, CPTMDL, CPTDIR, CPTHTY, CPTWID, CPTMMX, CPTDFV, CPTCPI, CPTCPR, CPTCSI, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbePrtDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPRTDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePrtDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbePrtDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPRTDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePrtDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbePrtDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTCLU = 4;
		public static final int FEEDFPUPDIR = 5;
		public static final int FEEDFPUPHTY = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEPRTDETAILDATA);

			contiac = new ContIac(0, 0, 0, "", "", "", "", "", "", "", "");
			continf = new ContInf("", "", "", "", "", "");
			feedFLstClu = new Feed("FeedFLstClu");
			feedFPupDir = new Feed("FeedFPupDir");
			feedFPupHty = new Feed("FeedFPupHty");
			statapp = new StatApp(0, false, false, false, false, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstClu;
		public Feed feedFPupDir;
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
			if (has(FEEDFPUPDIR)) ss.add("feedFPupDir");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbePrtDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstClu.readXML(doc, basexpath, true)) add(FEEDFLSTCLU);
				if (feedFPupDir.readXML(doc, basexpath, true)) add(FEEDFPUPDIR);
				if (feedFPupHty.readXML(doc, basexpath, true)) add(FEEDFPUPHTY);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, "", "", "", "", "", "", "", "");
				continf = new ContInf("", "", "", "", "", "");
				feedFLstClu = new Feed("FeedFLstClu");
				feedFPupDir = new Feed("FeedFPupDir");
				feedFPupHty = new Feed("FeedFPupHty");
				statapp = new StatApp(0, false, false, false, false, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

