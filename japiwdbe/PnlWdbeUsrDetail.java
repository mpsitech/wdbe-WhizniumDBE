/**
  * \file PnlWdbeUsrDetail.java
  * Java API code for job PnlWdbeUsrDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeUsrDetail {
	/**
		* VecVDo (full: VecVWdbeUsrDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTPRSVIEWCLICK = 2;
		public static final int BUTUSGVIEWCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butprsviewclick")) return BUTPRSVIEWCLICK;
			if (s.equals("butusgviewclick")) return BUTUSGVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
			if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeUsrDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPSTE = 1;
		public static final int NUMFPUPLCL = 2;
		public static final int NUMFPUPULV = 3;
		public static final int TXFPWD = 4;
		public static final int TXFFKY = 5;
		public static final int TXFCMT = 6;

		public ContIac(
					int numFPupSte
					, int numFPupLcl
					, int numFPupUlv
					, String TxfPwd
					, String TxfFky
					, String TxfCmt
				) {
			this.numFPupSte = numFPupSte;
			this.numFPupLcl = numFPupLcl;
			this.numFPupUlv = numFPupUlv;
			this.TxfPwd = TxfPwd;
			this.TxfFky = TxfFky;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPSTE, NUMFPUPLCL, NUMFPUPULV, TXFPWD, TXFFKY, TXFCMT));
		};

		public int numFPupSte;
		public int numFPupLcl;
		public int numFPupUlv;
		public String TxfPwd;
		public String TxfFky;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeUsrDetail");

			String itemtag = "ContitemIacWdbeUsrDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupSte = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupSte", mask, NUMFPUPSTE);
				numFPupLcl = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupLcl", mask, NUMFPUPLCL);
				numFPupUlv = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupUlv", mask, NUMFPUPULV);
				TxfPwd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfPwd", mask, TXFPWD);
				TxfFky = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfFky", mask, TXFFKY);
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
			if (difftag.isEmpty()) difftag = "ContIacWdbeUsrDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeUsrDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupSte", numFPupSte);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupLcl", numFPupLcl);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupUlv", numFPupUlv);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfPwd", TxfPwd);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFky", TxfFky);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupSte == comp.numFPupSte) items.add(NUMFPUPSTE);
			if (numFPupLcl == comp.numFPupLcl) items.add(NUMFPUPLCL);
			if (numFPupUlv == comp.numFPupUlv) items.add(NUMFPUPULV);
			if (TxfPwd.equals(comp.TxfPwd)) items.add(TXFPWD);
			if (TxfFky.equals(comp.TxfFky)) items.add(TXFFKY);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPSTE, NUMFPUPLCL, NUMFPUPULV, TXFPWD, TXFFKY, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeUsrDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTPRS = 1;
		public static final int TXTSRF = 2;
		public static final int TXTUSG = 3;

		public ContInf(
					String TxtPrs
					, String TxtSrf
					, String TxtUsg
				) {
			this.TxtPrs = TxtPrs;
			this.TxtSrf = TxtSrf;
			this.TxtUsg = TxtUsg;

			mask = new HashSet<Integer>(Arrays.asList(TXTPRS, TXTSRF, TXTUSG));
		};

		public String TxtPrs;
		public String TxtSrf;
		public String TxtUsg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeUsrDetail");

			String itemtag = "ContitemInfWdbeUsrDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrs", mask, TXTPRS);
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtUsg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtUsg", mask, TXTUSG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrs.equals(comp.TxtPrs)) items.add(TXTPRS);
			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtUsg.equals(comp.TxtUsg)) items.add(TXTUSG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTPRS, TXTSRF, TXTUSG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeUsrDetail)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeUsrDetail");

			String itemtag = "StatitemAppWdbeUsrDetail";

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
	  * StatShr (full: StatShrWdbeUsrDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTPRSACTIVE = 3;
		public static final int BUTPRSVIEWAVAIL = 4;
		public static final int BUTPRSVIEWACTIVE = 5;
		public static final int TXTSRFACTIVE = 6;
		public static final int TXTUSGACTIVE = 7;
		public static final int BUTUSGVIEWAVAIL = 8;
		public static final int BUTUSGVIEWACTIVE = 9;
		public static final int PUPSTEACTIVE = 10;
		public static final int PUPLCLACTIVE = 11;
		public static final int PUPULVACTIVE = 12;
		public static final int TXFPWDACTIVE = 13;
		public static final int TXFFKYACTIVE = 14;
		public static final int TXFCMTACTIVE = 15;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtPrsActive
					, boolean ButPrsViewAvail
					, boolean ButPrsViewActive
					, boolean TxtSrfActive
					, boolean TxtUsgActive
					, boolean ButUsgViewAvail
					, boolean ButUsgViewActive
					, boolean PupSteActive
					, boolean PupLclActive
					, boolean PupUlvActive
					, boolean TxfPwdActive
					, boolean TxfFkyActive
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtPrsActive = TxtPrsActive;
			this.ButPrsViewAvail = ButPrsViewAvail;
			this.ButPrsViewActive = ButPrsViewActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxtUsgActive = TxtUsgActive;
			this.ButUsgViewAvail = ButUsgViewAvail;
			this.ButUsgViewActive = ButUsgViewActive;
			this.PupSteActive = PupSteActive;
			this.PupLclActive = PupLclActive;
			this.PupUlvActive = PupUlvActive;
			this.TxfPwdActive = TxfPwdActive;
			this.TxfFkyActive = TxfFkyActive;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRSACTIVE, BUTPRSVIEWAVAIL, BUTPRSVIEWACTIVE, TXTSRFACTIVE, TXTUSGACTIVE, BUTUSGVIEWAVAIL, BUTUSGVIEWACTIVE, PUPSTEACTIVE, PUPLCLACTIVE, PUPULVACTIVE, TXFPWDACTIVE, TXFFKYACTIVE, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtPrsActive;
		public boolean ButPrsViewAvail;
		public boolean ButPrsViewActive;
		public boolean TxtSrfActive;
		public boolean TxtUsgActive;
		public boolean ButUsgViewAvail;
		public boolean ButUsgViewActive;
		public boolean PupSteActive;
		public boolean PupLclActive;
		public boolean PupUlvActive;
		public boolean TxfPwdActive;
		public boolean TxfFkyActive;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeUsrDetail");

			String itemtag = "StatitemShrWdbeUsrDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtPrsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPrsActive", mask, TXTPRSACTIVE);
				ButPrsViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrsViewAvail", mask, BUTPRSVIEWAVAIL);
				ButPrsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrsViewActive", mask, BUTPRSVIEWACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxtUsgActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtUsgActive", mask, TXTUSGACTIVE);
				ButUsgViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUsgViewAvail", mask, BUTUSGVIEWAVAIL);
				ButUsgViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUsgViewActive", mask, BUTUSGVIEWACTIVE);
				PupSteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupSteActive", mask, PUPSTEACTIVE);
				PupLclActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupLclActive", mask, PUPLCLACTIVE);
				PupUlvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupUlvActive", mask, PUPULVACTIVE);
				TxfPwdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfPwdActive", mask, TXFPWDACTIVE);
				TxfFkyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfFkyActive", mask, TXFFKYACTIVE);
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
			if (TxtPrsActive == comp.TxtPrsActive) items.add(TXTPRSACTIVE);
			if (ButPrsViewAvail == comp.ButPrsViewAvail) items.add(BUTPRSVIEWAVAIL);
			if (ButPrsViewActive == comp.ButPrsViewActive) items.add(BUTPRSVIEWACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxtUsgActive == comp.TxtUsgActive) items.add(TXTUSGACTIVE);
			if (ButUsgViewAvail == comp.ButUsgViewAvail) items.add(BUTUSGVIEWAVAIL);
			if (ButUsgViewActive == comp.ButUsgViewActive) items.add(BUTUSGVIEWACTIVE);
			if (PupSteActive == comp.PupSteActive) items.add(PUPSTEACTIVE);
			if (PupLclActive == comp.PupLclActive) items.add(PUPLCLACTIVE);
			if (PupUlvActive == comp.PupUlvActive) items.add(PUPULVACTIVE);
			if (TxfPwdActive == comp.TxfPwdActive) items.add(TXFPWDACTIVE);
			if (TxfFkyActive == comp.TxfFkyActive) items.add(TXFFKYACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTPRSACTIVE, BUTPRSVIEWAVAIL, BUTPRSVIEWACTIVE, TXTSRFACTIVE, TXTUSGACTIVE, BUTUSGVIEWAVAIL, BUTUSGVIEWACTIVE, PUPSTEACTIVE, PUPLCLACTIVE, PUPULVACTIVE, TXFPWDACTIVE, TXFFKYACTIVE, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeUsrDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTPRS = 2;
		public static final int CPTSRF = 3;
		public static final int CPTUSG = 4;
		public static final int CPTSTE = 5;
		public static final int CPTLCL = 6;
		public static final int CPTULV = 7;
		public static final int CPTPWD = 8;
		public static final int CPTFKY = 9;
		public static final int CPTCMT = 10;

		public Tag(
					String Cpt
					, String CptPrs
					, String CptSrf
					, String CptUsg
					, String CptSte
					, String CptLcl
					, String CptUlv
					, String CptPwd
					, String CptFky
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptPrs = CptPrs;
			this.CptSrf = CptSrf;
			this.CptUsg = CptUsg;
			this.CptSte = CptSte;
			this.CptLcl = CptLcl;
			this.CptUlv = CptUlv;
			this.CptPwd = CptPwd;
			this.CptFky = CptFky;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTPRS, CPTSRF, CPTUSG, CPTSTE, CPTLCL, CPTULV, CPTPWD, CPTFKY, CPTCMT));
		};

		public String Cpt;
		public String CptPrs;
		public String CptSrf;
		public String CptUsg;
		public String CptSte;
		public String CptLcl;
		public String CptUlv;
		public String CptPwd;
		public String CptFky;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeUsrDetail");

			String itemtag = "TagitemWdbeUsrDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptPrs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrs", mask, CPTPRS);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptUsg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUsg", mask, CPTUSG);
				CptSte = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSte", mask, CPTSTE);
				CptLcl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLcl", mask, CPTLCL);
				CptUlv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUlv", mask, CPTULV);
				CptPwd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPwd", mask, CPTPWD);
				CptFky = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFky", mask, CPTFKY);
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
			if (CptPrs.equals(comp.CptPrs)) items.add(CPTPRS);
			if (CptSrf.equals(comp.CptSrf)) items.add(CPTSRF);
			if (CptUsg.equals(comp.CptUsg)) items.add(CPTUSG);
			if (CptSte.equals(comp.CptSte)) items.add(CPTSTE);
			if (CptLcl.equals(comp.CptLcl)) items.add(CPTLCL);
			if (CptUlv.equals(comp.CptUlv)) items.add(CPTULV);
			if (CptPwd.equals(comp.CptPwd)) items.add(CPTPWD);
			if (CptFky.equals(comp.CptFky)) items.add(CPTFKY);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTPRS, CPTSRF, CPTUSG, CPTSTE, CPTLCL, CPTULV, CPTPWD, CPTFKY, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeUsrDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEUSRDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeUsrDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeUsrDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEUSRDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeUsrDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeUsrDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPLCL = 4;
		public static final int FEEDFPUPSTE = 5;
		public static final int FEEDFPUPULV = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEUSRDETAILDATA);

			contiac = new ContIac(0, 0, 0, "", "", "");
			continf = new ContInf("", "", "");
			feedFPupLcl = new Feed("FeedFPupLcl");
			feedFPupSte = new Feed("FeedFPupSte");
			feedFPupUlv = new Feed("FeedFPupUlv");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupLcl;
		public Feed feedFPupSte;
		public Feed feedFPupUlv;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPLCL)) ss.add("feedFPupLcl");
			if (has(FEEDFPUPSTE)) ss.add("feedFPupSte");
			if (has(FEEDFPUPULV)) ss.add("feedFPupUlv");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeUsrDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupLcl.readXML(doc, basexpath, true)) add(FEEDFPUPLCL);
				if (feedFPupSte.readXML(doc, basexpath, true)) add(FEEDFPUPSTE);
				if (feedFPupUlv.readXML(doc, basexpath, true)) add(FEEDFPUPULV);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, "", "", "");
				continf = new ContInf("", "", "");
				feedFPupLcl = new Feed("FeedFPupLcl");
				feedFPupSte = new Feed("FeedFPupSte");
				feedFPupUlv = new Feed("FeedFPupUlv");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

