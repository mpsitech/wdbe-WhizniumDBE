/**
  * \file PnlWdbeSilList.java
  * Java API code for job PnlWdbeSilList
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeSilList {
	/**
		* VecVDo (full: VecVWdbeSilListDo)
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
	  * ContIac (full: ContIacWdbeSilList)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeSilList");

			String itemtag = "ContitemIacWdbeSilList";

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeSilList";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeSilList";

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
	  * ContInf (full: ContInfWdbeSilList)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeSilList");

			String itemtag = "ContitemInfWdbeSilList";

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
	  * StatShr (full: StatShrWdbeSilList)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeSilList");

			String itemtag = "StatitemShrWdbeSilList";

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
	  * StgIac (full: StgIacWdbeSilList)
	  */
	public class StgIac extends Block {

		public static final int TCOSRFWIDTH = 1;
		public static final int TCOTITWIDTH = 2;
		public static final int TCOFSRWIDTH = 3;
		public static final int TCOTYPWIDTH = 4;
		public static final int TCORETWIDTH = 5;
		public static final int TCOREUWIDTH = 6;
		public static final int TCOSYSWIDTH = 7;
		public static final int TCOMDLWIDTH = 8;
		public static final int TCOPKGWIDTH = 9;
		public static final int TCOESYWIDTH = 10;
		public static final int TCOTCHWIDTH = 11;

		public StgIac(
					int TcoSrfWidth
					, int TcoTitWidth
					, int TcoFsrWidth
					, int TcoTypWidth
					, int TcoRetWidth
					, int TcoReuWidth
					, int TcoSysWidth
					, int TcoMdlWidth
					, int TcoPkgWidth
					, int TcoEsyWidth
					, int TcoTchWidth
				) {
			this.TcoSrfWidth = TcoSrfWidth;
			this.TcoTitWidth = TcoTitWidth;
			this.TcoFsrWidth = TcoFsrWidth;
			this.TcoTypWidth = TcoTypWidth;
			this.TcoRetWidth = TcoRetWidth;
			this.TcoReuWidth = TcoReuWidth;
			this.TcoSysWidth = TcoSysWidth;
			this.TcoMdlWidth = TcoMdlWidth;
			this.TcoPkgWidth = TcoPkgWidth;
			this.TcoEsyWidth = TcoEsyWidth;
			this.TcoTchWidth = TcoTchWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOSRFWIDTH, TCOTITWIDTH, TCOFSRWIDTH, TCOTYPWIDTH, TCORETWIDTH, TCOREUWIDTH, TCOSYSWIDTH, TCOMDLWIDTH, TCOPKGWIDTH, TCOESYWIDTH, TCOTCHWIDTH));
		};

		public int TcoSrfWidth;
		public int TcoTitWidth;
		public int TcoFsrWidth;
		public int TcoTypWidth;
		public int TcoRetWidth;
		public int TcoReuWidth;
		public int TcoSysWidth;
		public int TcoMdlWidth;
		public int TcoPkgWidth;
		public int TcoEsyWidth;
		public int TcoTchWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWdbeSilList");

			String itemtag = "StgitemIacWdbeSilList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoSrfWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", mask, TCOSRFWIDTH);
				TcoTitWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTitWidth", mask, TCOTITWIDTH);
				TcoFsrWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoFsrWidth", mask, TCOFSRWIDTH);
				TcoTypWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTypWidth", mask, TCOTYPWIDTH);
				TcoRetWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoRetWidth", mask, TCORETWIDTH);
				TcoReuWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoReuWidth", mask, TCOREUWIDTH);
				TcoSysWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSysWidth", mask, TCOSYSWIDTH);
				TcoMdlWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoMdlWidth", mask, TCOMDLWIDTH);
				TcoPkgWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoPkgWidth", mask, TCOPKGWIDTH);
				TcoEsyWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoEsyWidth", mask, TCOESYWIDTH);
				TcoTchWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoTchWidth", mask, TCOTCHWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWdbeSilList";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWdbeSilList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTitWidth", TcoTitWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoFsrWidth", TcoFsrWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTypWidth", TcoTypWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoRetWidth", TcoRetWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoReuWidth", TcoReuWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSysWidth", TcoSysWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoMdlWidth", TcoMdlWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoPkgWidth", TcoPkgWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoEsyWidth", TcoEsyWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoTchWidth", TcoTchWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoSrfWidth == comp.TcoSrfWidth) items.add(TCOSRFWIDTH);
			if (TcoTitWidth == comp.TcoTitWidth) items.add(TCOTITWIDTH);
			if (TcoFsrWidth == comp.TcoFsrWidth) items.add(TCOFSRWIDTH);
			if (TcoTypWidth == comp.TcoTypWidth) items.add(TCOTYPWIDTH);
			if (TcoRetWidth == comp.TcoRetWidth) items.add(TCORETWIDTH);
			if (TcoReuWidth == comp.TcoReuWidth) items.add(TCOREUWIDTH);
			if (TcoSysWidth == comp.TcoSysWidth) items.add(TCOSYSWIDTH);
			if (TcoMdlWidth == comp.TcoMdlWidth) items.add(TCOMDLWIDTH);
			if (TcoPkgWidth == comp.TcoPkgWidth) items.add(TCOPKGWIDTH);
			if (TcoEsyWidth == comp.TcoEsyWidth) items.add(TCOESYWIDTH);
			if (TcoTchWidth == comp.TcoTchWidth) items.add(TCOTCHWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOSRFWIDTH, TCOTITWIDTH, TCOFSRWIDTH, TCOTYPWIDTH, TCORETWIDTH, TCOREUWIDTH, TCOSYSWIDTH, TCOMDLWIDTH, TCOPKGWIDTH, TCOESYWIDTH, TCOTCHWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeSilList)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOSRF = 7;
		public static final int TCOTIT = 8;
		public static final int TCOFSR = 9;
		public static final int TCOTYP = 10;
		public static final int TCORET = 11;
		public static final int TCOREU = 12;
		public static final int TCOSYS = 13;
		public static final int TCOMDL = 14;
		public static final int TCOPKG = 15;
		public static final int TCOESY = 16;
		public static final int TCOTCH = 17;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoSrf
					, String TcoTit
					, String TcoFsr
					, String TcoTyp
					, String TcoRet
					, String TcoReu
					, String TcoSys
					, String TcoMdl
					, String TcoPkg
					, String TcoEsy
					, String TcoTch
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoSrf = TcoSrf;
			this.TcoTit = TcoTit;
			this.TcoFsr = TcoFsr;
			this.TcoTyp = TcoTyp;
			this.TcoRet = TcoRet;
			this.TcoReu = TcoReu;
			this.TcoSys = TcoSys;
			this.TcoMdl = TcoMdl;
			this.TcoPkg = TcoPkg;
			this.TcoEsy = TcoEsy;
			this.TcoTch = TcoTch;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOTIT, TCOFSR, TCOTYP, TCORET, TCOREU, TCOSYS, TCOMDL, TCOPKG, TCOESY, TCOTCH));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoSrf;
		public String TcoTit;
		public String TcoFsr;
		public String TcoTyp;
		public String TcoRet;
		public String TcoReu;
		public String TcoSys;
		public String TcoMdl;
		public String TcoPkg;
		public String TcoEsy;
		public String TcoTch;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeSilList");

			String itemtag = "TagitemWdbeSilList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSrf", mask, TCOSRF);
				TcoTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTit", mask, TCOTIT);
				TcoFsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoFsr", mask, TCOFSR);
				TcoTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTyp", mask, TCOTYP);
				TcoRet = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoRet", mask, TCORET);
				TcoReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoReu", mask, TCOREU);
				TcoSys = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSys", mask, TCOSYS);
				TcoMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoMdl", mask, TCOMDL);
				TcoPkg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoPkg", mask, TCOPKG);
				TcoEsy = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoEsy", mask, TCOESY);
				TcoTch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoTch", mask, TCOTCH);

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
			if (TcoTit.equals(comp.TcoTit)) items.add(TCOTIT);
			if (TcoFsr.equals(comp.TcoFsr)) items.add(TCOFSR);
			if (TcoTyp.equals(comp.TcoTyp)) items.add(TCOTYP);
			if (TcoRet.equals(comp.TcoRet)) items.add(TCORET);
			if (TcoReu.equals(comp.TcoReu)) items.add(TCOREU);
			if (TcoSys.equals(comp.TcoSys)) items.add(TCOSYS);
			if (TcoMdl.equals(comp.TcoMdl)) items.add(TCOMDL);
			if (TcoPkg.equals(comp.TcoPkg)) items.add(TCOPKG);
			if (TcoEsy.equals(comp.TcoEsy)) items.add(TCOESY);
			if (TcoTch.equals(comp.TcoTch)) items.add(TCOTCH);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOTIT, TCOFSR, TCOTYP, TCORET, TCOREU, TCOSYS, TCOMDL, TCOPKG, TCOESY, TCOTCH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeSilListData)
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
					, QryWdbeSilList.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPWDBESILLISTDATA, scrJref);

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
		public QryWdbeSilList.StgIac stgiacqry;

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
			Element el = doc.createElement("DpchAppWdbeSilListData");

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
		* DpchAppDo (full: DpchAppWdbeSilListDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBESILLISTDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeSilListDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeSilListData)
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
			super(VecWdbeVDpch.DPCHENGWDBESILLISTDATA);

			contiac = new ContIac(0);
			continf = new ContInf(false, 0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			feedFTos = new Feed("FeedFTos");
			statshr = new StatShr(0, false);
			stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			rst = new ListWdbeQSilList();
			statappqry = (new QryWdbeSilList()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWdbeSilList()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWdbeSilList()).new StgIac(0, 0, 0);
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFCsiQst;
		public Feed feedFTos;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWdbeQSilList rst;
		public QryWdbeSilList.StatApp statappqry;
		public QryWdbeSilList.StatShr statshrqry;
		public QryWdbeSilList.StgIac stgiacqry;

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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeSilListData");

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
				stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWdbeSilList()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWdbeSilList()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWdbeSilList()).new StgIac(0, 0, 0);
			};
		};

	};

};

