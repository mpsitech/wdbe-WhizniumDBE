/**
  * \file DlgWdbeNavMnglic.java
  * Java API code for job DlgWdbeNavMnglic
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWdbeNavMnglic {
	/**
		* VecVDo (full: VecVDlgWdbeNavMnglicDo)
		*/
	public static class VecVDo {

		public static final int DETBUTSCNCLICK = 1;
		public static final int DETBUTSDCCLICK = 2;
		public static final int DETBUTACTCLICK = 3;
		public static final int BUTDNECLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("detbutscnclick")) return DETBUTSCNCLICK;
			if (s.equals("detbutsdcclick")) return DETBUTSDCCLICK;
			if (s.equals("detbutactclick")) return DETBUTACTCLICK;
			if (s.equals("butdneclick")) return BUTDNECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == DETBUTSCNCLICK) return("DetButScnClick");
			if (ix == DETBUTSDCCLICK) return("DetButSdcClick");
			if (ix == DETBUTACTCLICK) return("DetButActClick");
			if (ix == BUTDNECLICK) return("ButDneClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWdbeNavMnglicSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int READY = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("ready")) return READY;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == READY) return("ready");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWdbeNavMnglic)
	  */
	public class ContIac extends Block {

		public static final int NUMFDETPUPFIS = 1;
		public static final int DETCHKFIS = 2;
		public static final int NUMFDETLSTLCS = 3;

		public ContIac(
					int numFDetPupFis
					, boolean DetChkFis
					, int numFDetLstLcs
				) {
			this.numFDetPupFis = numFDetPupFis;
			this.DetChkFis = DetChkFis;
			this.numFDetLstLcs = numFDetLstLcs;

			mask = new HashSet<Integer>(Arrays.asList(NUMFDETPUPFIS, DETCHKFIS, NUMFDETLSTLCS));
		};

		public int numFDetPupFis;
		public boolean DetChkFis;
		public int numFDetLstLcs;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWdbeNavMnglic");

			String itemtag = "ContitemIacDlgWdbeNavMnglic";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFDetPupFis = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetPupFis", mask, NUMFDETPUPFIS);
				DetChkFis = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetChkFis", mask, DETCHKFIS);
				numFDetLstLcs = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDetLstLcs", mask, NUMFDETLSTLCS);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWdbeNavMnglic";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWdbeNavMnglic";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetPupFis", numFDetPupFis);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "DetChkFis", DetChkFis);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDetLstLcs", numFDetLstLcs);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFDetPupFis == comp.numFDetPupFis) items.add(NUMFDETPUPFIS);
			if (DetChkFis == comp.DetChkFis) items.add(DETCHKFIS);
			if (numFDetLstLcs == comp.numFDetLstLcs) items.add(NUMFDETLSTLCS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFDETPUPFIS, DETCHKFIS, NUMFDETLSTLCS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWdbeNavMnglic)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int DETTXTSIP = 2;
		public static final int DETTXTSCP = 3;
		public static final int DETTXTLSR = 4;
		public static final int DETTXTLAR = 5;
		public static final int DETTXTLST = 6;
		public static final int DETTXTLEX = 7;

		public ContInf(
					int numFSge
					, String DetTxtSip
					, String DetTxtScp
					, String DetTxtLsr
					, String DetTxtLar
					, String DetTxtLst
					, String DetTxtLex
				) {
			this.numFSge = numFSge;
			this.DetTxtSip = DetTxtSip;
			this.DetTxtScp = DetTxtScp;
			this.DetTxtLsr = DetTxtLsr;
			this.DetTxtLar = DetTxtLar;
			this.DetTxtLst = DetTxtLst;
			this.DetTxtLex = DetTxtLex;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, DETTXTSIP, DETTXTSCP, DETTXTLSR, DETTXTLAR, DETTXTLST, DETTXTLEX));
		};

		public int numFSge;
		public String DetTxtSip;
		public String DetTxtScp;
		public String DetTxtLsr;
		public String DetTxtLar;
		public String DetTxtLst;
		public String DetTxtLex;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeNavMnglic");

			String itemtag = "ContitemInfDlgWdbeNavMnglic";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				DetTxtSip = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxtSip", mask, DETTXTSIP);
				DetTxtScp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxtScp", mask, DETTXTSCP);
				DetTxtLsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxtLsr", mask, DETTXTLSR);
				DetTxtLar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxtLar", mask, DETTXTLAR);
				DetTxtLst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxtLst", mask, DETTXTLST);
				DetTxtLex = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "DetTxtLex", mask, DETTXTLEX);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (DetTxtSip.equals(comp.DetTxtSip)) items.add(DETTXTSIP);
			if (DetTxtScp.equals(comp.DetTxtScp)) items.add(DETTXTSCP);
			if (DetTxtLsr.equals(comp.DetTxtLsr)) items.add(DETTXTLSR);
			if (DetTxtLar.equals(comp.DetTxtLar)) items.add(DETTXTLAR);
			if (DetTxtLst.equals(comp.DetTxtLst)) items.add(DETTXTLST);
			if (DetTxtLex.equals(comp.DetTxtLex)) items.add(DETTXTLEX);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, DETTXTSIP, DETTXTSCP, DETTXTLSR, DETTXTLAR, DETTXTLST, DETTXTLEX));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWdbeNavMnglic)
	  */
	public class StatApp extends Block {

		public static final int SHORTMENU = 1;
		public static final int DETLSTLCSNUMFIRSTDISP = 2;

		public StatApp(
					String shortMenu
					, int DetLstLcsNumFirstdisp
				) {
			this.shortMenu = shortMenu;
			this.DetLstLcsNumFirstdisp = DetLstLcsNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(SHORTMENU, DETLSTLCSNUMFIRSTDISP));
		};

		public String shortMenu;
		public int DetLstLcsNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWdbeNavMnglic");

			String itemtag = "StatitemAppDlgWdbeNavMnglic";

			if (Xmlio.checkXPath(doc, basexpath)) {
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				DetLstLcsNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DetLstLcsNumFirstdisp", mask, DETLSTLCSNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);
			if (DetLstLcsNumFirstdisp == comp.DetLstLcsNumFirstdisp) items.add(DETLSTLCSNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SHORTMENU, DETLSTLCSNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrDlgWdbeNavMnglic)
	  */
	public class StatShr extends Block {

		public static final int DETBUTACTACTIVE = 1;

		public StatShr(
					boolean DetButActActive
				) {
			this.DetButActActive = DetButActActive;

			mask = new HashSet<Integer>(Arrays.asList(DETBUTACTACTIVE));
		};

		public boolean DetButActActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeNavMnglic");

			String itemtag = "StatitemShrDlgWdbeNavMnglic";

			if (Xmlio.checkXPath(doc, basexpath)) {
				DetButActActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DetButActActive", mask, DETBUTACTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (DetButActActive == comp.DetButActActive) items.add(DETBUTACTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DETBUTACTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWdbeNavMnglic)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int DETHDGSRV = 2;
		public static final int DETCPTSIP = 3;
		public static final int DETCPTSCP = 4;
		public static final int DETBUTSCN = 5;
		public static final int DETBUTSDC = 6;
		public static final int DETCPTFIS = 7;
		public static final int DETCPTLCS = 8;
		public static final int DETBUTACT = 9;
		public static final int DETHDGLIC = 10;
		public static final int DETCPTLSR = 11;
		public static final int DETCPTLAR = 12;
		public static final int DETCPTLST = 13;
		public static final int DETCPTLEX = 14;
		public static final int BUTDNE = 15;

		public Tag(
					String Cpt
					, String DetHdgSrv
					, String DetCptSip
					, String DetCptScp
					, String DetButScn
					, String DetButSdc
					, String DetCptFis
					, String DetCptLcs
					, String DetButAct
					, String DetHdgLic
					, String DetCptLsr
					, String DetCptLar
					, String DetCptLst
					, String DetCptLex
					, String ButDne
				) {
			this.Cpt = Cpt;
			this.DetHdgSrv = DetHdgSrv;
			this.DetCptSip = DetCptSip;
			this.DetCptScp = DetCptScp;
			this.DetButScn = DetButScn;
			this.DetButSdc = DetButSdc;
			this.DetCptFis = DetCptFis;
			this.DetCptLcs = DetCptLcs;
			this.DetButAct = DetButAct;
			this.DetHdgLic = DetHdgLic;
			this.DetCptLsr = DetCptLsr;
			this.DetCptLar = DetCptLar;
			this.DetCptLst = DetCptLst;
			this.DetCptLex = DetCptLex;
			this.ButDne = ButDne;

			mask = new HashSet<Integer>(Arrays.asList(CPT, DETHDGSRV, DETCPTSIP, DETCPTSCP, DETBUTSCN, DETBUTSDC, DETCPTFIS, DETCPTLCS, DETBUTACT, DETHDGLIC, DETCPTLSR, DETCPTLAR, DETCPTLST, DETCPTLEX, BUTDNE));
		};

		public String Cpt;
		public String DetHdgSrv;
		public String DetCptSip;
		public String DetCptScp;
		public String DetButScn;
		public String DetButSdc;
		public String DetCptFis;
		public String DetCptLcs;
		public String DetButAct;
		public String DetHdgLic;
		public String DetCptLsr;
		public String DetCptLar;
		public String DetCptLst;
		public String DetCptLex;
		public String ButDne;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeNavMnglic");

			String itemtag = "TagitemDlgWdbeNavMnglic";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				DetHdgSrv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetHdgSrv", mask, DETHDGSRV);
				DetCptSip = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptSip", mask, DETCPTSIP);
				DetCptScp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptScp", mask, DETCPTSCP);
				DetButScn = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetButScn", mask, DETBUTSCN);
				DetButSdc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetButSdc", mask, DETBUTSDC);
				DetCptFis = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptFis", mask, DETCPTFIS);
				DetCptLcs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptLcs", mask, DETCPTLCS);
				DetButAct = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetButAct", mask, DETBUTACT);
				DetHdgLic = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetHdgLic", mask, DETHDGLIC);
				DetCptLsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptLsr", mask, DETCPTLSR);
				DetCptLar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptLar", mask, DETCPTLAR);
				DetCptLst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptLst", mask, DETCPTLST);
				DetCptLex = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "DetCptLex", mask, DETCPTLEX);
				ButDne = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButDne", mask, BUTDNE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (DetHdgSrv.equals(comp.DetHdgSrv)) items.add(DETHDGSRV);
			if (DetCptSip.equals(comp.DetCptSip)) items.add(DETCPTSIP);
			if (DetCptScp.equals(comp.DetCptScp)) items.add(DETCPTSCP);
			if (DetButScn.equals(comp.DetButScn)) items.add(DETBUTSCN);
			if (DetButSdc.equals(comp.DetButSdc)) items.add(DETBUTSDC);
			if (DetCptFis.equals(comp.DetCptFis)) items.add(DETCPTFIS);
			if (DetCptLcs.equals(comp.DetCptLcs)) items.add(DETCPTLCS);
			if (DetButAct.equals(comp.DetButAct)) items.add(DETBUTACT);
			if (DetHdgLic.equals(comp.DetHdgLic)) items.add(DETHDGLIC);
			if (DetCptLsr.equals(comp.DetCptLsr)) items.add(DETCPTLSR);
			if (DetCptLar.equals(comp.DetCptLar)) items.add(DETCPTLAR);
			if (DetCptLst.equals(comp.DetCptLst)) items.add(DETCPTLST);
			if (DetCptLex.equals(comp.DetCptLex)) items.add(DETCPTLEX);
			if (ButDne.equals(comp.ButDne)) items.add(BUTDNE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, DETHDGSRV, DETCPTSIP, DETCPTSCP, DETBUTSCN, DETBUTSDC, DETCPTFIS, DETCPTLCS, DETBUTACT, DETHDGLIC, DETCPTLSR, DETCPTLAR, DETCPTLST, DETCPTLEX, BUTDNE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeNavMnglicData)
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
			super(VecWdbeVDpch.DPCHAPPDLGWDBENAVMNGLICDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWdbeNavMnglicData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeNavMnglicDo)
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
			super(VecWdbeVDpch.DPCHAPPDLGWDBENAVMNGLICDO, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWdbeNavMnglicDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeNavMnglicData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFDETLSTLCS = 4;
		public static final int FEEDFDETPUPFIS = 5;
		public static final int FEEDFSGE = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGDLGWDBENAVMNGLICDATA);

			contiac = new ContIac(0, false, 0);
			continf = new ContInf(0, "", "", "", "", "", "");
			feedFDetLstLcs = new Feed("FeedFDetLstLcs");
			feedFDetPupFis = new Feed("FeedFDetPupFis");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp("", 0);
			statshr = new StatShr(false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFDetLstLcs;
		public Feed feedFDetPupFis;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFDETLSTLCS)) ss.add("feedFDetLstLcs");
			if (has(FEEDFDETPUPFIS)) ss.add("feedFDetPupFis");
			if (has(FEEDFSGE)) ss.add("feedFSge");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWdbeNavMnglicData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFDetLstLcs.readXML(doc, basexpath, true)) add(FEEDFDETLSTLCS);
				if (feedFDetPupFis.readXML(doc, basexpath, true)) add(FEEDFDETPUPFIS);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, false, 0);
				continf = new ContInf(0, "", "", "", "", "", "");
				feedFDetLstLcs = new Feed("FeedFDetLstLcs");
				feedFDetPupFis = new Feed("FeedFDetPupFis");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp("", 0);
				statshr = new StatShr(false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
