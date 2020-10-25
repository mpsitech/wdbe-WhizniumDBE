/**
  * \file PnlWdbePrcKHdltype.java
  * Java API code for job PnlWdbePrcKHdltype
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbePrcKHdltype {
	/**
		* VecVDo (full: VecVWdbePrcKHdltypeDo)
		*/
	public static class VecVDo {

		public static final int BUTUPCLICK = 1;
		public static final int BUTDOWNCLICK = 2;
		public static final int BUTNEWCLICK = 3;
		public static final int BUTDUPLICATECLICK = 4;
		public static final int BUTDELETECLICK = 5;
		public static final int BUTREFRESHCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butupclick")) return BUTUPCLICK;
			if (s.equals("butdownclick")) return BUTDOWNCLICK;
			if (s.equals("butnewclick")) return BUTNEWCLICK;
			if (s.equals("butduplicateclick")) return BUTDUPLICATECLICK;
			if (s.equals("butdeleteclick")) return BUTDELETECLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTUPCLICK) return("ButUpClick");
			if (ix == BUTDOWNCLICK) return("ButDownClick");
			if (ix == BUTNEWCLICK) return("ButNewClick");
			if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
			if (ix == BUTDELETECLICK) return("ButDeleteClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWdbePrcKHdltype)
	  */
	public class ContInf extends Block {

		public static final int NUMFCSIQST = 1;

		public ContInf(
					int numFCsiQst
				) {
			this.numFCsiQst = numFCsiQst;

			mask = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
		};

		public int numFCsiQst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbePrcKHdltype");

			String itemtag = "ContitemInfWdbePrcKHdltype";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFCsiQst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFCsiQst", mask, NUMFCSIQST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFCsiQst == comp.numFCsiQst) items.add(NUMFCSIQST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbePrcKHdltype)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbePrcKHdltype");

			String itemtag = "StatitemAppWdbePrcKHdltype";

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
	  * StatShr (full: StatShrWdbePrcKHdltype)
	  */
	public class StatShr extends Block {

		public static final int BUTUPACTIVE = 1;
		public static final int BUTDOWNACTIVE = 2;
		public static final int BUTDUPLICATEACTIVE = 3;
		public static final int BUTDELETEACTIVE = 4;

		public StatShr(
					boolean ButUpActive
					, boolean ButDownActive
					, boolean ButDuplicateActive
					, boolean ButDeleteActive
				) {
			this.ButUpActive = ButUpActive;
			this.ButDownActive = ButDownActive;
			this.ButDuplicateActive = ButDuplicateActive;
			this.ButDeleteActive = ButDeleteActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTUPACTIVE, BUTDOWNACTIVE, BUTDUPLICATEACTIVE, BUTDELETEACTIVE));
		};

		public boolean ButUpActive;
		public boolean ButDownActive;
		public boolean ButDuplicateActive;
		public boolean ButDeleteActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbePrcKHdltype");

			String itemtag = "StatitemShrWdbePrcKHdltype";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButUpActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUpActive", mask, BUTUPACTIVE);
				ButDownActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDownActive", mask, BUTDOWNACTIVE);
				ButDuplicateActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", mask, BUTDUPLICATEACTIVE);
				ButDeleteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDeleteActive", mask, BUTDELETEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButUpActive == comp.ButUpActive) items.add(BUTUPACTIVE);
			if (ButDownActive == comp.ButDownActive) items.add(BUTDOWNACTIVE);
			if (ButDuplicateActive == comp.ButDuplicateActive) items.add(BUTDUPLICATEACTIVE);
			if (ButDeleteActive == comp.ButDeleteActive) items.add(BUTDELETEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTUPACTIVE, BUTDOWNACTIVE, BUTDUPLICATEACTIVE, BUTDELETEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacWdbePrcKHdltype)
	  */
	public class StgIac extends Block {

		public static final int TCOFIXWIDTH = 1;
		public static final int TCOSRFWIDTH = 2;
		public static final int TCOAVLWIDTH = 3;
		public static final int TCOIMPWIDTH = 4;
		public static final int TCOTITWIDTH = 5;
		public static final int TCOCMTWIDTH = 6;

		public StgIac(
					int TcoFixWidth
					, int TcoSrfWidth
					, int TcoAvlWidth
					, int TcoImpWidth
					, int TcoTitWidth
					, int TcoCmtWidth
				) {
			this.TcoFixWidth = TcoFixWidth;
			this.TcoSrfWidth = TcoSrfWidth;
			this.TcoAvlWidth = TcoAvlWidth;
			this.TcoImpWidth = TcoImpWidth;
			this.TcoTitWidth = TcoTitWidth;
			this.TcoCmtWidth = TcoCmtWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOFIXWIDTH, TCOSRFWIDTH, TCOAVLWIDTH, TCOIMPWIDTH, TCOTITWIDTH, TCOCMTWIDTH));
		};

		public int TcoFixWidth;
		public int TcoSrfWidth;
		public int TcoAvlWidth;
		public int TcoImpWidth;
		public int TcoTitWidth;
		public int TcoCmtWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWdbePrcKHdltype");

			String itemtag = "StgitemIacWdbePrcKHdltype";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoFixWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoFixWidth", mask, TCOFIXWIDTH);
				TcoSrfWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", mask, TCOSRFWIDTH);
				TcoAvlWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoAvlWidth", mask, TCOAVLWIDTH);
				TcoImpWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoImpWidth", mask, TCOIMPWIDTH);
				TcoTitWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTitWidth", mask, TCOTITWIDTH);
				TcoCmtWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoCmtWidth", mask, TCOCMTWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWdbePrcKHdltype";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWdbePrcKHdltype";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoFixWidth", TcoFixWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoAvlWidth", TcoAvlWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoImpWidth", TcoImpWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTitWidth", TcoTitWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoCmtWidth", TcoCmtWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoFixWidth == comp.TcoFixWidth) items.add(TCOFIXWIDTH);
			if (TcoSrfWidth == comp.TcoSrfWidth) items.add(TCOSRFWIDTH);
			if (TcoAvlWidth == comp.TcoAvlWidth) items.add(TCOAVLWIDTH);
			if (TcoImpWidth == comp.TcoImpWidth) items.add(TCOIMPWIDTH);
			if (TcoTitWidth == comp.TcoTitWidth) items.add(TCOTITWIDTH);
			if (TcoCmtWidth == comp.TcoCmtWidth) items.add(TCOCMTWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOFIXWIDTH, TCOSRFWIDTH, TCOAVLWIDTH, TCOIMPWIDTH, TCOTITWIDTH, TCOCMTWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbePrcKHdltype)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOFIX = 7;
		public static final int TCOSRF = 8;
		public static final int TCOAVL = 9;
		public static final int TCOIMP = 10;
		public static final int TCOTIT = 11;
		public static final int TCOCMT = 12;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoFix
					, String TcoSrf
					, String TcoAvl
					, String TcoImp
					, String TcoTit
					, String TcoCmt
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoFix = TcoFix;
			this.TcoSrf = TcoSrf;
			this.TcoAvl = TcoAvl;
			this.TcoImp = TcoImp;
			this.TcoTit = TcoTit;
			this.TcoCmt = TcoCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOFIX, TCOSRF, TCOAVL, TCOIMP, TCOTIT, TCOCMT));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoFix;
		public String TcoSrf;
		public String TcoAvl;
		public String TcoImp;
		public String TcoTit;
		public String TcoCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbePrcKHdltype");

			String itemtag = "TagitemWdbePrcKHdltype";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoFix = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoFix", mask, TCOFIX);
				TcoSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSrf", mask, TCOSRF);
				TcoAvl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoAvl", mask, TCOAVL);
				TcoImp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoImp", mask, TCOIMP);
				TcoTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTit", mask, TCOTIT);
				TcoCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoCmt", mask, TCOCMT);

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
			if (TcoFix.equals(comp.TcoFix)) items.add(TCOFIX);
			if (TcoSrf.equals(comp.TcoSrf)) items.add(TCOSRF);
			if (TcoAvl.equals(comp.TcoAvl)) items.add(TCOAVL);
			if (TcoImp.equals(comp.TcoImp)) items.add(TCOIMP);
			if (TcoTit.equals(comp.TcoTit)) items.add(TCOTIT);
			if (TcoCmt.equals(comp.TcoCmt)) items.add(TCOCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOFIX, TCOSRF, TCOAVL, TCOIMP, TCOTIT, TCOCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbePrcKHdltypeData)
		*/
	public class DpchAppData extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int STGIAC = 2;
		public static final int STGIACQRY = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, StgIac stgiac
					, QryWdbePrcKHdltype.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPWDBEPRCKHDLTYPEDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, STGIAC, STGIACQRY));
					break;
				};

			if (has(STGIAC)) this.stgiac = stgiac;
			if (has(STGIACQRY)) this.stgiacqry = stgiacqry;
		};

		public StgIac stgiac;
		public QryWdbePrcKHdltype.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWdbePrcKHdltypeData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbePrcKHdltypeDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPRCKHDLTYPEDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePrcKHdltypeDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbePrcKHdltypeData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFCSIQST = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int STGIAC = 6;
		public static final int TAG = 7;
		public static final int RST = 8;
		public static final int STATAPPQRY = 9;
		public static final int STATSHRQRY = 10;
		public static final int STGIACQRY = 11;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEPRCKHDLTYPEDATA);

			continf = new ContInf(0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false);
			stgiac = new StgIac(0, 0, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "");
			rst = new ListWdbeQPrcKHdltype();
			statappqry = (new QryWdbePrcKHdltype()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWdbePrcKHdltype()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWdbePrcKHdltype()).new StgIac(0, 0, 0);
		};

		public ContInf continf;
		public Feed feedFCsiQst;
		public StatApp statapp;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWdbeQPrcKHdltype rst;
		public QryWdbePrcKHdltype.StatApp statappqry;
		public QryWdbePrcKHdltype.StatShr statshrqry;
		public QryWdbePrcKHdltype.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFCSIQST)) ss.add("feedFCsiQst");
			if (has(STATAPP)) ss.add("statapp");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbePrcKHdltypeData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFCsiQst.readXML(doc, basexpath, true)) add(FEEDFCSIQST);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (stgiac.readXML(doc, basexpath, true)) add(STGIAC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (rst.readXML(doc, basexpath, true)) add(RST);
				if (statappqry.readXML(doc, basexpath, true)) add(STATAPPQRY);
				if (statshrqry.readXML(doc, basexpath, true)) add(STATSHRQRY);
				if (stgiacqry.readXML(doc, basexpath, true)) add(STGIACQRY);
			} else {
				scrJref = "";
				continf = new ContInf(0);
				feedFCsiQst = new Feed("FeedFCsiQst");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false);
				stgiac = new StgIac(0, 0, 0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWdbePrcKHdltype()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWdbePrcKHdltype()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWdbePrcKHdltype()).new StgIac(0, 0, 0);
			};
		};

	};

};

