/**
  * \file PnlWdbeSegDetail.java
  * Java API code for job PnlWdbeSegDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeSegDetail {
	/**
		* VecVDo (full: VecVWdbeSegDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTCLUVIEWCLICK = 2;
		public static final int BUTCLUCLUSTERCLICK = 3;
		public static final int BUTCLUUNCLUSTERCLICK = 4;
		public static final int BUTPPLVIEWCLICK = 5;
		public static final int BUTSUPVIEWCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butcluviewclick")) return BUTCLUVIEWCLICK;
			if (s.equals("butcluclusterclick")) return BUTCLUCLUSTERCLICK;
			if (s.equals("butcluunclusterclick")) return BUTCLUUNCLUSTERCLICK;
			if (s.equals("butpplviewclick")) return BUTPPLVIEWCLICK;
			if (s.equals("butsupviewclick")) return BUTSUPVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTCLUVIEWCLICK) return("ButCluViewClick");
			if (ix == BUTCLUCLUSTERCLICK) return("ButCluClusterClick");
			if (ix == BUTCLUUNCLUSTERCLICK) return("ButCluUnclusterClick");
			if (ix == BUTPPLVIEWCLICK) return("ButPplViewClick");
			if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeSegDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTCLU = 1;
		public static final int TXFIFM = 2;
		public static final int TXFOFM = 3;
		public static final int TXFLCY = 4;
		public static final int TXFCMT = 5;

		public ContIac(
					int numFLstClu
					, String TxfIfm
					, String TxfOfm
					, String TxfLcy
					, String TxfCmt
				) {
			this.numFLstClu = numFLstClu;
			this.TxfIfm = TxfIfm;
			this.TxfOfm = TxfOfm;
			this.TxfLcy = TxfLcy;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTCLU, TXFIFM, TXFOFM, TXFLCY, TXFCMT));
		};

		public int numFLstClu;
		public String TxfIfm;
		public String TxfOfm;
		public String TxfLcy;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeSegDetail");

			String itemtag = "ContitemIacWdbeSegDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstClu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstClu", mask, NUMFLSTCLU);
				TxfIfm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfIfm", mask, TXFIFM);
				TxfOfm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfOfm", mask, TXFOFM);
				TxfLcy = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfLcy", mask, TXFLCY);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbeSegDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeSegDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstClu", numFLstClu);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfIfm", TxfIfm);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfOfm", TxfOfm);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfLcy", TxfLcy);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstClu == comp.numFLstClu) items.add(NUMFLSTCLU);
			if (TxfIfm.equals(comp.TxfIfm)) items.add(TXFIFM);
			if (TxfOfm.equals(comp.TxfOfm)) items.add(TXFOFM);
			if (TxfLcy.equals(comp.TxfLcy)) items.add(TXFLCY);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTCLU, TXFIFM, TXFOFM, TXFLCY, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeSegDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTCLU = 2;
		public static final int TXTPPL = 3;
		public static final int TXTSUP = 4;

		public ContInf(
					String TxtSrf
					, String TxtClu
					, String TxtPpl
					, String TxtSup
				) {
			this.TxtSrf = TxtSrf;
			this.TxtClu = TxtClu;
			this.TxtPpl = TxtPpl;
			this.TxtSup = TxtSup;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCLU, TXTPPL, TXTSUP));
		};

		public String TxtSrf;
		public String TxtClu;
		public String TxtPpl;
		public String TxtSup;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeSegDetail");

			String itemtag = "ContitemInfWdbeSegDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtClu", mask, TXTCLU);
				TxtPpl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPpl", mask, TXTPPL);
				TxtSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSup", mask, TXTSUP);

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
			if (TxtPpl.equals(comp.TxtPpl)) items.add(TXTPPL);
			if (TxtSup.equals(comp.TxtSup)) items.add(TXTSUP);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTCLU, TXTPPL, TXTSUP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeSegDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTCLUALT = 2;
		public static final int LSTCLUNUMFIRSTDISP = 3;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstCluAlt
					, int LstCluNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstCluAlt = LstCluAlt;
			this.LstCluNumFirstdisp = LstCluNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCLUALT, LSTCLUNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstCluAlt;
		public int LstCluNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeSegDetail");

			String itemtag = "StatitemAppWdbeSegDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstCluAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluAlt", mask, LSTCLUALT);
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
			if (LstCluNumFirstdisp == comp.LstCluNumFirstdisp) items.add(LSTCLUNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCLUALT, LSTCLUNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeSegDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int LSTCLUACTIVE = 4;
		public static final int BUTCLUVIEWACTIVE = 5;
		public static final int BUTCLUCLUSTERAVAIL = 6;
		public static final int BUTCLUUNCLUSTERAVAIL = 7;
		public static final int TXTPPLACTIVE = 8;
		public static final int BUTPPLVIEWAVAIL = 9;
		public static final int BUTPPLVIEWACTIVE = 10;
		public static final int TXTSUPACTIVE = 11;
		public static final int BUTSUPVIEWAVAIL = 12;
		public static final int BUTSUPVIEWACTIVE = 13;
		public static final int TXFIFMACTIVE = 14;
		public static final int TXFOFMACTIVE = 15;
		public static final int TXFLCYACTIVE = 16;
		public static final int TXFCMTACTIVE = 17;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean LstCluActive
					, boolean ButCluViewActive
					, boolean ButCluClusterAvail
					, boolean ButCluUnclusterAvail
					, boolean TxtPplActive
					, boolean ButPplViewAvail
					, boolean ButPplViewActive
					, boolean TxtSupActive
					, boolean ButSupViewAvail
					, boolean ButSupViewActive
					, boolean TxfIfmActive
					, boolean TxfOfmActive
					, boolean TxfLcyActive
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.LstCluActive = LstCluActive;
			this.ButCluViewActive = ButCluViewActive;
			this.ButCluClusterAvail = ButCluClusterAvail;
			this.ButCluUnclusterAvail = ButCluUnclusterAvail;
			this.TxtPplActive = TxtPplActive;
			this.ButPplViewAvail = ButPplViewAvail;
			this.ButPplViewActive = ButPplViewActive;
			this.TxtSupActive = TxtSupActive;
			this.ButSupViewAvail = ButSupViewAvail;
			this.ButSupViewActive = ButSupViewActive;
			this.TxfIfmActive = TxfIfmActive;
			this.TxfOfmActive = TxfOfmActive;
			this.TxfLcyActive = TxfLcyActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTPPLACTIVE, BUTPPLVIEWAVAIL, BUTPPLVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXFIFMACTIVE, TXFOFMACTIVE, TXFLCYACTIVE, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean LstCluActive;
		public boolean ButCluViewActive;
		public boolean ButCluClusterAvail;
		public boolean ButCluUnclusterAvail;
		public boolean TxtPplActive;
		public boolean ButPplViewAvail;
		public boolean ButPplViewActive;
		public boolean TxtSupActive;
		public boolean ButSupViewAvail;
		public boolean ButSupViewActive;
		public boolean TxfIfmActive;
		public boolean TxfOfmActive;
		public boolean TxfLcyActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeSegDetail");

			String itemtag = "StatitemShrWdbeSegDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				LstCluActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluActive", mask, LSTCLUACTIVE);
				ButCluViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluViewActive", mask, BUTCLUVIEWACTIVE);
				ButCluClusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", mask, BUTCLUCLUSTERAVAIL);
				ButCluUnclusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", mask, BUTCLUUNCLUSTERAVAIL);
				TxtPplActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPplActive", mask, TXTPPLACTIVE);
				ButPplViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPplViewAvail", mask, BUTPPLVIEWAVAIL);
				ButPplViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPplViewActive", mask, BUTPPLVIEWACTIVE);
				TxtSupActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSupActive", mask, TXTSUPACTIVE);
				ButSupViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", mask, BUTSUPVIEWAVAIL);
				ButSupViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewActive", mask, BUTSUPVIEWACTIVE);
				TxfIfmActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfIfmActive", mask, TXFIFMACTIVE);
				TxfOfmActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfOfmActive", mask, TXFOFMACTIVE);
				TxfLcyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfLcyActive", mask, TXFLCYACTIVE);
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
			if (TxtPplActive == comp.TxtPplActive) items.add(TXTPPLACTIVE);
			if (ButPplViewAvail == comp.ButPplViewAvail) items.add(BUTPPLVIEWAVAIL);
			if (ButPplViewActive == comp.ButPplViewActive) items.add(BUTPPLVIEWACTIVE);
			if (TxtSupActive == comp.TxtSupActive) items.add(TXTSUPACTIVE);
			if (ButSupViewAvail == comp.ButSupViewAvail) items.add(BUTSUPVIEWAVAIL);
			if (ButSupViewActive == comp.ButSupViewActive) items.add(BUTSUPVIEWACTIVE);
			if (TxfIfmActive == comp.TxfIfmActive) items.add(TXFIFMACTIVE);
			if (TxfOfmActive == comp.TxfOfmActive) items.add(TXFOFMACTIVE);
			if (TxfLcyActive == comp.TxfLcyActive) items.add(TXFLCYACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTPPLACTIVE, BUTPPLVIEWAVAIL, BUTPPLVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXFIFMACTIVE, TXFOFMACTIVE, TXFLCYACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeSegDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTCLU = 3;
		public static final int CPTPPL = 4;
		public static final int CPTSUP = 5;
		public static final int CPTIFM = 6;
		public static final int CPTOFM = 7;
		public static final int CPTLCY = 8;
		public static final int CPTCMT = 9;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptClu
					, String CptPpl
					, String CptSup
					, String CptIfm
					, String CptOfm
					, String CptLcy
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptClu = CptClu;
			this.CptPpl = CptPpl;
			this.CptSup = CptSup;
			this.CptIfm = CptIfm;
			this.CptOfm = CptOfm;
			this.CptLcy = CptLcy;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCLU, CPTPPL, CPTSUP, CPTIFM, CPTOFM, CPTLCY, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptClu;
		public String CptPpl;
		public String CptSup;
		public String CptIfm;
		public String CptOfm;
		public String CptLcy;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeSegDetail");

			String itemtag = "TagitemWdbeSegDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptClu", mask, CPTCLU);
				CptPpl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPpl", mask, CPTPPL);
				CptSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSup", mask, CPTSUP);
				CptIfm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIfm", mask, CPTIFM);
				CptOfm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptOfm", mask, CPTOFM);
				CptLcy = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLcy", mask, CPTLCY);
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
			if (CptPpl.equals(comp.CptPpl)) items.add(CPTPPL);
			if (CptSup.equals(comp.CptSup)) items.add(CPTSUP);
			if (CptIfm.equals(comp.CptIfm)) items.add(CPTIFM);
			if (CptOfm.equals(comp.CptOfm)) items.add(CPTOFM);
			if (CptLcy.equals(comp.CptLcy)) items.add(CPTLCY);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTCLU, CPTPPL, CPTSUP, CPTIFM, CPTOFM, CPTLCY, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeSegDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBESEGDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeSegDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeSegDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBESEGDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeSegDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeSegDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTCLU = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBESEGDETAILDATA);

			contiac = new ContIac(0, "", "", "", "");
			continf = new ContInf("", "", "", "");
			feedFLstClu = new Feed("FeedFLstClu");
			statapp = new StatApp(0, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstClu;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFLSTCLU)) ss.add("feedFLstClu");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeSegDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstClu.readXML(doc, basexpath, true)) add(FEEDFLSTCLU);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", "", "", "");
				continf = new ContInf("", "", "", "");
				feedFLstClu = new Feed("FeedFLstClu");
				statapp = new StatApp(0, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "");
			};
		};

	};

};
