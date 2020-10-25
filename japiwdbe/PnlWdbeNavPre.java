/**
  * \file PnlWdbeNavPre.java
  * Java API code for job PnlWdbeNavPre
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeNavPre {
	/**
		* VecVDo (full: VecVWdbeNavPreDo)
		*/
	public static class VecVDo {

		public static final int BUTCVRREMOVECLICK = 1;
		public static final int BUTUNTREMOVECLICK = 2;
		public static final int BUTVERREMOVECLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butcvrremoveclick")) return BUTCVRREMOVECLICK;
			if (s.equals("butuntremoveclick")) return BUTUNTREMOVECLICK;
			if (s.equals("butverremoveclick")) return BUTVERREMOVECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTCVRREMOVECLICK) return("ButCvrRemoveClick");
			if (ix == BUTUNTREMOVECLICK) return("ButUntRemoveClick");
			if (ix == BUTVERREMOVECLICK) return("ButVerRemoveClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWdbeNavPre)
	  */
	public class ContInf extends Block {

		public static final int TXTCVR = 1;
		public static final int TXTUNT = 2;
		public static final int TXTVER = 3;

		public ContInf(
					String TxtCvr
					, String TxtUnt
					, String TxtVer
				) {
			this.TxtCvr = TxtCvr;
			this.TxtUnt = TxtUnt;
			this.TxtVer = TxtVer;

			mask = new HashSet<Integer>(Arrays.asList(TXTCVR, TXTUNT, TXTVER));
		};

		public String TxtCvr;
		public String TxtUnt;
		public String TxtVer;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeNavPre");

			String itemtag = "ContitemInfWdbeNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtCvr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCvr", mask, TXTCVR);
				TxtUnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtUnt", mask, TXTUNT);
				TxtVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtVer", mask, TXTVER);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtCvr.equals(comp.TxtCvr)) items.add(TXTCVR);
			if (TxtUnt.equals(comp.TxtUnt)) items.add(TXTUNT);
			if (TxtVer.equals(comp.TxtVer)) items.add(TXTVER);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTCVR, TXTUNT, TXTVER));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeNavPre)
	  */
	public class StatShr extends Block {

		public static final int TXTCVRAVAIL = 1;
		public static final int TXTUNTAVAIL = 2;
		public static final int TXTVERAVAIL = 3;

		public StatShr(
					boolean TxtCvrAvail
					, boolean TxtUntAvail
					, boolean TxtVerAvail
				) {
			this.TxtCvrAvail = TxtCvrAvail;
			this.TxtUntAvail = TxtUntAvail;
			this.TxtVerAvail = TxtVerAvail;

			mask = new HashSet<Integer>(Arrays.asList(TXTCVRAVAIL, TXTUNTAVAIL, TXTVERAVAIL));
		};

		public boolean TxtCvrAvail;
		public boolean TxtUntAvail;
		public boolean TxtVerAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNavPre");

			String itemtag = "StatitemShrWdbeNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtCvrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCvrAvail", mask, TXTCVRAVAIL);
				TxtUntAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtUntAvail", mask, TXTUNTAVAIL);
				TxtVerAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtVerAvail", mask, TXTVERAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtCvrAvail == comp.TxtCvrAvail) items.add(TXTCVRAVAIL);
			if (TxtUntAvail == comp.TxtUntAvail) items.add(TXTUNTAVAIL);
			if (TxtVerAvail == comp.TxtVerAvail) items.add(TXTVERAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTCVRAVAIL, TXTUNTAVAIL, TXTVERAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNavPre)
	  */
	public class Tag extends Block {

		public static final int CPTCVR = 1;
		public static final int CPTUNT = 2;
		public static final int CPTVER = 3;

		public Tag(
					String CptCvr
					, String CptUnt
					, String CptVer
				) {
			this.CptCvr = CptCvr;
			this.CptUnt = CptUnt;
			this.CptVer = CptVer;

			mask = new HashSet<Integer>(Arrays.asList(CPTCVR, CPTUNT, CPTVER));
		};

		public String CptCvr;
		public String CptUnt;
		public String CptVer;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNavPre");

			String itemtag = "TagitemWdbeNavPre";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptCvr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCvr", mask, CPTCVR);
				CptUnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUnt", mask, CPTUNT);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptCvr.equals(comp.CptCvr)) items.add(CPTCVR);
			if (CptUnt.equals(comp.CptUnt)) items.add(CPTUNT);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTCVR, CPTUNT, CPTVER));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavPreDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVPREDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavPreDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavPreData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATSHR = 3;
		public static final int TAG = 4;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVPREDATA);

			continf = new ContInf("", "", "");
			statshr = new StatShr(false, false, false);
			tag = new Tag("", "", "");
		};

		public ContInf continf;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavPreData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("", "", "");
				statshr = new StatShr(false, false, false);
				tag = new Tag("", "", "");
			};
		};

	};

};

