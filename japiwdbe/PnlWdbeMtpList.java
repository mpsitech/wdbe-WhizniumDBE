/**
  * \file PnlWdbeMtpList.java
  * Java API code for job PnlWdbeMtpList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeMtpList {
	/**
		* VecVDo (full: VecVWdbeMtpListDo)
		*/
	public static class VecVDo {

		public static final int BUTMINIMIZECLICK = 1;
		public static final int BUTREGULARIZECLICK = 2;
		public static final int BUTNEWCLICK = 3;
		public static final int BUTDELETECLICK = 4;
		public static final int BUTFILTERCLICK = 5;
		public static final int BUTREFRESHCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butnewclick")) return BUTNEWCLICK;
			if (s.equals("butdeleteclick")) return BUTDELETECLICK;
			if (s.equals("butfilterclick")) return BUTFILTERCLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTNEWCLICK) return("ButNewClick");
			if (ix == BUTDELETECLICK) return("ButDeleteClick");
			if (ix == BUTFILTERCLICK) return("ButFilterClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeMtpList)
	  */
	public class ContIac extends Block {

		public static final int NUMFTOS = 1;

		public ContIac(
					int numFTos
				) {
			this.numFTos = numFTos;

			mask = new HashSet<Integer>(Arrays.asList(NUMFTOS));
		};

		public int numFTos;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeMtpList");

			String itemtag = "ContitemIacWdbeMtpList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFTos = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFTos", mask, NUMFTOS);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeMtpList";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeMtpList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFTos", numFTos);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFTos == comp.numFTos) items.add(NUMFTOS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFTOS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeMtpList)
	  */
	public class ContInf extends Block {

		public static final int BUTFILTERON = 1;
		public static final int NUMFCSIQST = 2;

		public ContInf(
					boolean ButFilterOn
					, int numFCsiQst
				) {
			this.ButFilterOn = ButFilterOn;
			this.numFCsiQst = numFCsiQst;

			mask = new HashSet<Integer>(Arrays.asList(BUTFILTERON, NUMFCSIQST));
		};

		public boolean ButFilterOn;
		public int numFCsiQst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeMtpList");

			String itemtag = "ContitemInfWdbeMtpList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButFilterOn = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ButFilterOn", mask, BUTFILTERON);
				numFCsiQst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFCsiQst", mask, NUMFCSIQST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButFilterOn == comp.ButFilterOn) items.add(BUTFILTERON);
			if (numFCsiQst == comp.numFCsiQst) items.add(NUMFCSIQST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTFILTERON, NUMFCSIQST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeMtpList)
	  */
	public class StatShr extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int BUTDELETEACTIVE = 2;

		public StatShr(
					int ixWdbeVExpstate
					, boolean ButDeleteActive
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.ButDeleteActive = ButDeleteActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, BUTDELETEACTIVE));
		};

		public int ixWdbeVExpstate;
		public boolean ButDeleteActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeMtpList");

			String itemtag = "StatitemShrWdbeMtpList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				ButDeleteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDeleteActive", mask, BUTDELETEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (ButDeleteActive == comp.ButDeleteActive) items.add(BUTDELETEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, BUTDELETEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacWdbeMtpList)
	  */
	public class StgIac extends Block {

		public static final int TCOSRFWIDTH = 1;
		public static final int TCOVNDWIDTH = 2;
		public static final int TCOTYPWIDTH = 3;
		public static final int TCOSRRWIDTH = 4;

		public StgIac(
					int TcoSrfWidth
					, int TcoVndWidth
					, int TcoTypWidth
					, int TcoSrrWidth
				) {
			this.TcoSrfWidth = TcoSrfWidth;
			this.TcoVndWidth = TcoVndWidth;
			this.TcoTypWidth = TcoTypWidth;
			this.TcoSrrWidth = TcoSrrWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOSRFWIDTH, TCOVNDWIDTH, TCOTYPWIDTH, TCOSRRWIDTH));
		};

		public int TcoSrfWidth;
		public int TcoVndWidth;
		public int TcoTypWidth;
		public int TcoSrrWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWdbeMtpList");

			String itemtag = "StgitemIacWdbeMtpList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoSrfWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", mask, TCOSRFWIDTH);
				TcoVndWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoVndWidth", mask, TCOVNDWIDTH);
				TcoTypWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTypWidth", mask, TCOTYPWIDTH);
				TcoSrrWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSrrWidth", mask, TCOSRRWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWdbeMtpList";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWdbeMtpList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoVndWidth", TcoVndWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTypWidth", TcoTypWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSrrWidth", TcoSrrWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoSrfWidth == comp.TcoSrfWidth) items.add(TCOSRFWIDTH);
			if (TcoVndWidth == comp.TcoVndWidth) items.add(TCOVNDWIDTH);
			if (TcoTypWidth == comp.TcoTypWidth) items.add(TCOTYPWIDTH);
			if (TcoSrrWidth == comp.TcoSrrWidth) items.add(TCOSRRWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOSRFWIDTH, TCOVNDWIDTH, TCOTYPWIDTH, TCOSRRWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeMtpList)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOSRF = 7;
		public static final int TCOVND = 8;
		public static final int TCOTYP = 9;
		public static final int TCOSRR = 10;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoSrf
					, String TcoVnd
					, String TcoTyp
					, String TcoSrr
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoSrf = TcoSrf;
			this.TcoVnd = TcoVnd;
			this.TcoTyp = TcoTyp;
			this.TcoSrr = TcoSrr;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOVND, TCOTYP, TCOSRR));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoSrf;
		public String TcoVnd;
		public String TcoTyp;
		public String TcoSrr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeMtpList");

			String itemtag = "TagitemWdbeMtpList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSrf", mask, TCOSRF);
				TcoVnd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoVnd", mask, TCOVND);
				TcoTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTyp", mask, TCOTYP);
				TcoSrr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSrr", mask, TCOSRR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (TxtRecord1.equals(comp.TxtRecord1)) items.add(TXTRECORD1);
			if (TxtRecord2.equals(comp.TxtRecord2)) items.add(TXTRECORD2);
			if (Trs.equals(comp.Trs)) items.add(TRS);
			if (TxtShowing1.equals(comp.TxtShowing1)) items.add(TXTSHOWING1);
			if (TxtShowing2.equals(comp.TxtShowing2)) items.add(TXTSHOWING2);
			if (TcoSrf.equals(comp.TcoSrf)) items.add(TCOSRF);
			if (TcoVnd.equals(comp.TcoVnd)) items.add(TCOVND);
			if (TcoTyp.equals(comp.TcoTyp)) items.add(TCOTYP);
			if (TcoSrr.equals(comp.TcoSrr)) items.add(TCOSRR);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOVND, TCOTYP, TCOSRR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeMtpListData)
		*/
	public class DpchAppData extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int STGIAC = 3;
		public static final int STGIACQRY = 4;
		public static final int ALL = 5;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, StgIac stgiac
					, QryWdbeMtpList.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPWDBEMTPLISTDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC, STGIAC, STGIACQRY));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
			if (has(STGIAC)) this.stgiac = stgiac;
			if (has(STGIACQRY)) this.stgiacqry = stgiacqry;
		};

		public ContIac contiac;
		public StgIac stgiac;
		public QryWdbeMtpList.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWdbeMtpListData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeMtpListDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEMTPLISTDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeMtpListDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeMtpListData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFCSIQST = 4;
		public static final int FEEDFTOS = 5;
		public static final int STATSHR = 6;
		public static final int STGIAC = 7;
		public static final int TAG = 8;
		public static final int RST = 9;
		public static final int STATAPPQRY = 10;
		public static final int STATSHRQRY = 11;
		public static final int STGIACQRY = 12;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEMTPLISTDATA);

			contiac = new ContIac(0);
			continf = new ContInf(false, 0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			feedFTos = new Feed("FeedFTos");
			statshr = new StatShr(0, false);
			stgiac = new StgIac(0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "");
			rst = new ListWdbeQMtpList();
			statappqry = (new QryWdbeMtpList()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWdbeMtpList()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWdbeMtpList()).new StgIac(0, 0, 0);
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFCsiQst;
		public Feed feedFTos;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWdbeQMtpList rst;
		public QryWdbeMtpList.StatApp statappqry;
		public QryWdbeMtpList.StatShr statshrqry;
		public QryWdbeMtpList.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFCSIQST)) ss.add("feedFCsiQst");
			if (has(FEEDFTOS)) ss.add("feedFTos");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(TAG)) ss.add("tag");
			if (has(RST)) ss.add("rst");
			if (has(STATAPPQRY)) ss.add("statappqry");
			if (has(STATSHRQRY)) ss.add("statshrqry");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeMtpListData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFCsiQst.readXML(doc, basexpath, true)) add(FEEDFCSIQST);
				if (feedFTos.readXML(doc, basexpath, true)) add(FEEDFTOS);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (stgiac.readXML(doc, basexpath, true)) add(STGIAC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (rst.readXML(doc, basexpath, true)) add(RST);
				if (statappqry.readXML(doc, basexpath, true)) add(STATAPPQRY);
				if (statshrqry.readXML(doc, basexpath, true)) add(STATSHRQRY);
				if (stgiacqry.readXML(doc, basexpath, true)) add(STGIACQRY);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				continf = new ContInf(false, 0);
				feedFCsiQst = new Feed("FeedFCsiQst");
				feedFTos = new Feed("FeedFTos");
				statshr = new StatShr(0, false);
				stgiac = new StgIac(0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWdbeMtpList()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWdbeMtpList()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWdbeMtpList()).new StgIac(0, 0, 0);
			};
		};

	};

};
