/**
  * \file PnlWdbeFilDetail.java
  * Java API code for job PnlWdbeFilDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeFilDetail {
	/**
		* VecVDo (full: VecVWdbeFilDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTCLUVIEWCLICK = 2;
		public static final int BUTCLUCLUSTERCLICK = 3;
		public static final int BUTCLUUNCLUSTERCLICK = 4;
		public static final int BUTREUVIEWCLICK = 5;
		public static final int BUTCNTEDITCLICK = 6;
		public static final int BUTMIMEDITCLICK = 7;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butcluviewclick")) return BUTCLUVIEWCLICK;
			if (s.equals("butcluclusterclick")) return BUTCLUCLUSTERCLICK;
			if (s.equals("butcluunclusterclick")) return BUTCLUUNCLUSTERCLICK;
			if (s.equals("butreuviewclick")) return BUTREUVIEWCLICK;
			if (s.equals("butcnteditclick")) return BUTCNTEDITCLICK;
			if (s.equals("butmimeditclick")) return BUTMIMEDITCLICK;

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
			if (ix == BUTCNTEDITCLICK) return("ButCntEditClick");
			if (ix == BUTMIMEDITCLICK) return("ButMimEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeFilDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFFNM = 1;
		public static final int NUMFLSTCLU = 2;
		public static final int NUMFPUPRET = 3;
		public static final int NUMFPUPCNT = 4;
		public static final int TXFCNT = 5;
		public static final int TXFACV = 6;
		public static final int TXFANM = 7;
		public static final int NUMFPUPMIM = 8;
		public static final int TXFMIM = 9;
		public static final int TXFSIZ = 10;
		public static final int TXFCMT = 11;

		public ContIac(
					String TxfFnm
					, int numFLstClu
					, int numFPupRet
					, int numFPupCnt
					, String TxfCnt
					, String TxfAcv
					, String TxfAnm
					, int numFPupMim
					, String TxfMim
					, String TxfSiz
					, String TxfCmt
				) {
			this.TxfFnm = TxfFnm;
			this.numFLstClu = numFLstClu;
			this.numFPupRet = numFPupRet;
			this.numFPupCnt = numFPupCnt;
			this.TxfCnt = TxfCnt;
			this.TxfAcv = TxfAcv;
			this.TxfAnm = TxfAnm;
			this.numFPupMim = numFPupMim;
			this.TxfMim = TxfMim;
			this.TxfSiz = TxfSiz;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(TXFFNM, NUMFLSTCLU, NUMFPUPRET, NUMFPUPCNT, TXFCNT, TXFACV, TXFANM, NUMFPUPMIM, TXFMIM, TXFSIZ, TXFCMT));
		};

		public String TxfFnm;
		public int numFLstClu;
		public int numFPupRet;
		public int numFPupCnt;
		public String TxfCnt;
		public String TxfAcv;
		public String TxfAnm;
		public int numFPupMim;
		public String TxfMim;
		public String TxfSiz;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeFilDetail");

			String itemtag = "ContitemIacWdbeFilDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfFnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfFnm", mask, TXFFNM);
				numFLstClu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstClu", mask, NUMFLSTCLU);
				numFPupRet = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRet", mask, NUMFPUPRET);
				numFPupCnt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupCnt", mask, NUMFPUPCNT);
				TxfCnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCnt", mask, TXFCNT);
				TxfAcv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfAcv", mask, TXFACV);
				TxfAnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfAnm", mask, TXFANM);
				numFPupMim = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupMim", mask, NUMFPUPMIM);
				TxfMim = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfMim", mask, TXFMIM);
				TxfSiz = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSiz", mask, TXFSIZ);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbeFilDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeFilDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFnm", TxfFnm);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstClu", numFLstClu);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupCnt", numFPupCnt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCnt", TxfCnt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAcv", TxfAcv);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfAnm", TxfAnm);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupMim", numFPupMim);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfMim", TxfMim);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSiz", TxfSiz);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfFnm.equals(comp.TxfFnm)) items.add(TXFFNM);
			if (numFLstClu == comp.numFLstClu) items.add(NUMFLSTCLU);
			if (numFPupRet == comp.numFPupRet) items.add(NUMFPUPRET);
			if (numFPupCnt == comp.numFPupCnt) items.add(NUMFPUPCNT);
			if (TxfCnt.equals(comp.TxfCnt)) items.add(TXFCNT);
			if (TxfAcv.equals(comp.TxfAcv)) items.add(TXFACV);
			if (TxfAnm.equals(comp.TxfAnm)) items.add(TXFANM);
			if (numFPupMim == comp.numFPupMim) items.add(NUMFPUPMIM);
			if (TxfMim.equals(comp.TxfMim)) items.add(TXFMIM);
			if (TxfSiz.equals(comp.TxfSiz)) items.add(TXFSIZ);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFFNM, NUMFLSTCLU, NUMFPUPRET, NUMFPUPCNT, TXFCNT, TXFACV, TXFANM, NUMFPUPMIM, TXFMIM, TXFSIZ, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeFilDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTCLU = 1;
		public static final int TXTREU = 2;

		public ContInf(
					String TxtClu
					, String TxtReu
				) {
			this.TxtClu = TxtClu;
			this.TxtReu = TxtReu;

			mask = new HashSet<Integer>(Arrays.asList(TXTCLU, TXTREU));
		};

		public String TxtClu;
		public String TxtReu;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeFilDetail");

			String itemtag = "ContitemInfWdbeFilDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
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

			diffitems = new HashSet<Integer>(Arrays.asList(TXTCLU, TXTREU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeFilDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTCLUALT = 2;
		public static final int PUPCNTALT = 3;
		public static final int PUPMIMALT = 4;
		public static final int LSTCLUNUMFIRSTDISP = 5;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstCluAlt
					, boolean PupCntAlt
					, boolean PupMimAlt
					, int LstCluNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstCluAlt = LstCluAlt;
			this.PupCntAlt = PupCntAlt;
			this.PupMimAlt = PupMimAlt;
			this.LstCluNumFirstdisp = LstCluNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCLUALT, PUPCNTALT, PUPMIMALT, LSTCLUNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstCluAlt;
		public boolean PupCntAlt;
		public boolean PupMimAlt;
		public int LstCluNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeFilDetail");

			String itemtag = "StatitemAppWdbeFilDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstCluAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluAlt", mask, LSTCLUALT);
				PupCntAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupCntAlt", mask, PUPCNTALT);
				PupMimAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupMimAlt", mask, PUPMIMALT);
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
			if (PupCntAlt == comp.PupCntAlt) items.add(PUPCNTALT);
			if (PupMimAlt == comp.PupMimAlt) items.add(PUPMIMALT);
			if (LstCluNumFirstdisp == comp.LstCluNumFirstdisp) items.add(LSTCLUNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCLUALT, PUPCNTALT, PUPMIMALT, LSTCLUNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeFilDetail)
	  */
	public class StatShr extends Block {

		public static final int TXFCNTVALID = 1;
		public static final int TXFMIMVALID = 2;
		public static final int BUTSAVEAVAIL = 3;
		public static final int BUTSAVEACTIVE = 4;
		public static final int TXFFNMACTIVE = 5;
		public static final int LSTCLUACTIVE = 6;
		public static final int BUTCLUVIEWACTIVE = 7;
		public static final int BUTCLUCLUSTERAVAIL = 8;
		public static final int BUTCLUUNCLUSTERAVAIL = 9;
		public static final int TXTREUACTIVE = 10;
		public static final int BUTREUVIEWAVAIL = 11;
		public static final int BUTREUVIEWACTIVE = 12;
		public static final int PUPCNTACTIVE = 13;
		public static final int BUTCNTEDITAVAIL = 14;
		public static final int TXFACVACTIVE = 15;
		public static final int TXFANMACTIVE = 16;
		public static final int PUPMIMACTIVE = 17;
		public static final int BUTMIMEDITAVAIL = 18;
		public static final int TXFSIZACTIVE = 19;
		public static final int TXFCMTACTIVE = 20;

		public StatShr(
					boolean TxfCntValid
					, boolean TxfMimValid
					, boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxfFnmActive
					, boolean LstCluActive
					, boolean ButCluViewActive
					, boolean ButCluClusterAvail
					, boolean ButCluUnclusterAvail
					, boolean TxtReuActive
					, boolean ButReuViewAvail
					, boolean ButReuViewActive
					, boolean PupCntActive
					, boolean ButCntEditAvail
					, boolean TxfAcvActive
					, boolean TxfAnmActive
					, boolean PupMimActive
					, boolean ButMimEditAvail
					, boolean TxfSizActive
					, boolean TxfCmtActive
				) {
			this.TxfCntValid = TxfCntValid;
			this.TxfMimValid = TxfMimValid;
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxfFnmActive = TxfFnmActive;
			this.LstCluActive = LstCluActive;
			this.ButCluViewActive = ButCluViewActive;
			this.ButCluClusterAvail = ButCluClusterAvail;
			this.ButCluUnclusterAvail = ButCluUnclusterAvail;
			this.TxtReuActive = TxtReuActive;
			this.ButReuViewAvail = ButReuViewAvail;
			this.ButReuViewActive = ButReuViewActive;
			this.PupCntActive = PupCntActive;
			this.ButCntEditAvail = ButCntEditAvail;
			this.TxfAcvActive = TxfAcvActive;
			this.TxfAnmActive = TxfAnmActive;
			this.PupMimActive = PupMimActive;
			this.ButMimEditAvail = ButMimEditAvail;
			this.TxfSizActive = TxfSizActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFCNTVALID, TXFMIMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXFFNMACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, PUPCNTACTIVE, BUTCNTEDITAVAIL, TXFACVACTIVE, TXFANMACTIVE, PUPMIMACTIVE, BUTMIMEDITAVAIL, TXFSIZACTIVE, TXFCMTACTIVE));
		};

		public boolean TxfCntValid;
		public boolean TxfMimValid;
		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxfFnmActive;
		public boolean LstCluActive;
		public boolean ButCluViewActive;
		public boolean ButCluClusterAvail;
		public boolean ButCluUnclusterAvail;
		public boolean TxtReuActive;
		public boolean ButReuViewAvail;
		public boolean ButReuViewActive;
		public boolean PupCntActive;
		public boolean ButCntEditAvail;
		public boolean TxfAcvActive;
		public boolean TxfAnmActive;
		public boolean PupMimActive;
		public boolean ButMimEditAvail;
		public boolean TxfSizActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeFilDetail");

			String itemtag = "StatitemShrWdbeFilDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfCntValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCntValid", mask, TXFCNTVALID);
				TxfMimValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfMimValid", mask, TXFMIMVALID);
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxfFnmActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfFnmActive", mask, TXFFNMACTIVE);
				LstCluActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCluActive", mask, LSTCLUACTIVE);
				ButCluViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluViewActive", mask, BUTCLUVIEWACTIVE);
				ButCluClusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluClusterAvail", mask, BUTCLUCLUSTERAVAIL);
				ButCluUnclusterAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCluUnclusterAvail", mask, BUTCLUUNCLUSTERAVAIL);
				TxtReuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtReuActive", mask, TXTREUACTIVE);
				ButReuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", mask, BUTREUVIEWAVAIL);
				ButReuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewActive", mask, BUTREUVIEWACTIVE);
				PupCntActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupCntActive", mask, PUPCNTACTIVE);
				ButCntEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCntEditAvail", mask, BUTCNTEDITAVAIL);
				TxfAcvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfAcvActive", mask, TXFACVACTIVE);
				TxfAnmActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfAnmActive", mask, TXFANMACTIVE);
				PupMimActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupMimActive", mask, PUPMIMACTIVE);
				ButMimEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMimEditAvail", mask, BUTMIMEDITAVAIL);
				TxfSizActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSizActive", mask, TXFSIZACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfCntValid == comp.TxfCntValid) items.add(TXFCNTVALID);
			if (TxfMimValid == comp.TxfMimValid) items.add(TXFMIMVALID);
			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxfFnmActive == comp.TxfFnmActive) items.add(TXFFNMACTIVE);
			if (LstCluActive == comp.LstCluActive) items.add(LSTCLUACTIVE);
			if (ButCluViewActive == comp.ButCluViewActive) items.add(BUTCLUVIEWACTIVE);
			if (ButCluClusterAvail == comp.ButCluClusterAvail) items.add(BUTCLUCLUSTERAVAIL);
			if (ButCluUnclusterAvail == comp.ButCluUnclusterAvail) items.add(BUTCLUUNCLUSTERAVAIL);
			if (TxtReuActive == comp.TxtReuActive) items.add(TXTREUACTIVE);
			if (ButReuViewAvail == comp.ButReuViewAvail) items.add(BUTREUVIEWAVAIL);
			if (ButReuViewActive == comp.ButReuViewActive) items.add(BUTREUVIEWACTIVE);
			if (PupCntActive == comp.PupCntActive) items.add(PUPCNTACTIVE);
			if (ButCntEditAvail == comp.ButCntEditAvail) items.add(BUTCNTEDITAVAIL);
			if (TxfAcvActive == comp.TxfAcvActive) items.add(TXFACVACTIVE);
			if (TxfAnmActive == comp.TxfAnmActive) items.add(TXFANMACTIVE);
			if (PupMimActive == comp.PupMimActive) items.add(PUPMIMACTIVE);
			if (ButMimEditAvail == comp.ButMimEditAvail) items.add(BUTMIMEDITAVAIL);
			if (TxfSizActive == comp.TxfSizActive) items.add(TXFSIZACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFCNTVALID, TXFMIMVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXFFNMACTIVE, LSTCLUACTIVE, BUTCLUVIEWACTIVE, BUTCLUCLUSTERAVAIL, BUTCLUUNCLUSTERAVAIL, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, PUPCNTACTIVE, BUTCNTEDITAVAIL, TXFACVACTIVE, TXFANMACTIVE, PUPMIMACTIVE, BUTMIMEDITAVAIL, TXFSIZACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeFilDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTFNM = 2;
		public static final int CPTCLU = 3;
		public static final int CPTREU = 4;
		public static final int CPTCNT = 5;
		public static final int CPTACV = 6;
		public static final int CPTANM = 7;
		public static final int CPTMIM = 8;
		public static final int CPTSIZ = 9;
		public static final int CPTCMT = 10;

		public Tag(
					String Cpt
					, String CptFnm
					, String CptClu
					, String CptReu
					, String CptCnt
					, String CptAcv
					, String CptAnm
					, String CptMim
					, String CptSiz
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptFnm = CptFnm;
			this.CptClu = CptClu;
			this.CptReu = CptReu;
			this.CptCnt = CptCnt;
			this.CptAcv = CptAcv;
			this.CptAnm = CptAnm;
			this.CptMim = CptMim;
			this.CptSiz = CptSiz;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTFNM, CPTCLU, CPTREU, CPTCNT, CPTACV, CPTANM, CPTMIM, CPTSIZ, CPTCMT));
		};

		public String Cpt;
		public String CptFnm;
		public String CptClu;
		public String CptReu;
		public String CptCnt;
		public String CptAcv;
		public String CptAnm;
		public String CptMim;
		public String CptSiz;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeFilDetail");

			String itemtag = "TagitemWdbeFilDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptFnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFnm", mask, CPTFNM);
				CptClu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptClu", mask, CPTCLU);
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptReu", mask, CPTREU);
				CptCnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCnt", mask, CPTCNT);
				CptAcv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAcv", mask, CPTACV);
				CptAnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptAnm", mask, CPTANM);
				CptMim = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMim", mask, CPTMIM);
				CptSiz = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSiz", mask, CPTSIZ);
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
			if (CptFnm.equals(comp.CptFnm)) items.add(CPTFNM);
			if (CptClu.equals(comp.CptClu)) items.add(CPTCLU);
			if (CptReu.equals(comp.CptReu)) items.add(CPTREU);
			if (CptCnt.equals(comp.CptCnt)) items.add(CPTCNT);
			if (CptAcv.equals(comp.CptAcv)) items.add(CPTACV);
			if (CptAnm.equals(comp.CptAnm)) items.add(CPTANM);
			if (CptMim.equals(comp.CptMim)) items.add(CPTMIM);
			if (CptSiz.equals(comp.CptSiz)) items.add(CPTSIZ);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTFNM, CPTCLU, CPTREU, CPTCNT, CPTACV, CPTANM, CPTMIM, CPTSIZ, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeFilDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEFILDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeFilDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeFilDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEFILDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeFilDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeFilDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFLSTCLU = 4;
		public static final int FEEDFPUPCNT = 5;
		public static final int FEEDFPUPMIM = 6;
		public static final int FEEDFPUPRET = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEFILDETAILDATA);

			contiac = new ContIac("", 0, 0, 0, "", "", "", 0, "", "", "");
			continf = new ContInf("", "");
			feedFLstClu = new Feed("FeedFLstClu");
			feedFPupCnt = new Feed("FeedFPupCnt");
			feedFPupMim = new Feed("FeedFPupMim");
			feedFPupRet = new Feed("FeedFPupRet");
			statapp = new StatApp(0, false, false, false, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFLstClu;
		public Feed feedFPupCnt;
		public Feed feedFPupMim;
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
			if (has(FEEDFPUPCNT)) ss.add("feedFPupCnt");
			if (has(FEEDFPUPMIM)) ss.add("feedFPupMim");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeFilDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFLstClu.readXML(doc, basexpath, true)) add(FEEDFLSTCLU);
				if (feedFPupCnt.readXML(doc, basexpath, true)) add(FEEDFPUPCNT);
				if (feedFPupMim.readXML(doc, basexpath, true)) add(FEEDFPUPMIM);
				if (feedFPupRet.readXML(doc, basexpath, true)) add(FEEDFPUPRET);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", 0, 0, 0, "", "", "", 0, "", "", "");
				continf = new ContInf("", "");
				feedFLstClu = new Feed("FeedFLstClu");
				feedFPupCnt = new Feed("FeedFPupCnt");
				feedFPupMim = new Feed("FeedFPupMim");
				feedFPupRet = new Feed("FeedFPupRet");
				statapp = new StatApp(0, false, false, false, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

