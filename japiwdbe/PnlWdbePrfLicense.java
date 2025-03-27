/**
  * \file PnlWdbePrfLicense.java
  * Java API code for job PnlWdbePrfLicense
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbePrfLicense {
	/**
		* VecVDo (full: VecVWdbePrfLicenseDo)
		*/
	public static class VecVDo {

		public static final int BUTREGULARIZECLICK = 1;
		public static final int BUTMINIMIZECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbePrfLicense)
	  */
	public class ContIac extends Block {

		public static final int TXF1 = 1;
		public static final int TXF2 = 2;
		public static final int TXF3 = 3;
		public static final int TXF4 = 4;
		public static final int TXF5 = 5;
		public static final int TXF6 = 6;
		public static final int TXF7 = 7;
		public static final int TXF8 = 8;
		public static final int TXF9 = 9;
		public static final int TXF10 = 10;

		public ContIac(
					String Txf1
					, String Txf2
					, String Txf3
					, String Txf4
					, String Txf5
					, String Txf6
					, String Txf7
					, String Txf8
					, String Txf9
					, String Txf10
				) {
			this.Txf1 = Txf1;
			this.Txf2 = Txf2;
			this.Txf3 = Txf3;
			this.Txf4 = Txf4;
			this.Txf5 = Txf5;
			this.Txf6 = Txf6;
			this.Txf7 = Txf7;
			this.Txf8 = Txf8;
			this.Txf9 = Txf9;
			this.Txf10 = Txf10;

			mask = new HashSet<Integer>(Arrays.asList(TXF1, TXF2, TXF3, TXF4, TXF5, TXF6, TXF7, TXF8, TXF9, TXF10));
		};

		public String Txf1;
		public String Txf2;
		public String Txf3;
		public String Txf4;
		public String Txf5;
		public String Txf6;
		public String Txf7;
		public String Txf8;
		public String Txf9;
		public String Txf10;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbePrfLicense");

			String itemtag = "ContitemIacWdbePrfLicense";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Txf1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf1", mask, TXF1);
				Txf2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf2", mask, TXF2);
				Txf3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf3", mask, TXF3);
				Txf4 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf4", mask, TXF4);
				Txf5 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf5", mask, TXF5);
				Txf6 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf6", mask, TXF6);
				Txf7 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf7", mask, TXF7);
				Txf8 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf8", mask, TXF8);
				Txf9 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf9", mask, TXF9);
				Txf10 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf10", mask, TXF10);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbePrfLicense";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbePrfLicense";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf1", Txf1);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf2", Txf2);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf3", Txf3);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf4", Txf4);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf5", Txf5);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf6", Txf6);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf7", Txf7);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf8", Txf8);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf9", Txf9);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf10", Txf10);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Txf1.equals(comp.Txf1)) items.add(TXF1);
			if (Txf2.equals(comp.Txf2)) items.add(TXF2);
			if (Txf3.equals(comp.Txf3)) items.add(TXF3);
			if (Txf4.equals(comp.Txf4)) items.add(TXF4);
			if (Txf5.equals(comp.Txf5)) items.add(TXF5);
			if (Txf6.equals(comp.Txf6)) items.add(TXF6);
			if (Txf7.equals(comp.Txf7)) items.add(TXF7);
			if (Txf8.equals(comp.Txf8)) items.add(TXF8);
			if (Txf9.equals(comp.Txf9)) items.add(TXF9);
			if (Txf10.equals(comp.Txf10)) items.add(TXF10);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXF1, TXF2, TXF3, TXF4, TXF5, TXF6, TXF7, TXF8, TXF9, TXF10));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbePrfLicense)
	  */
	public class StatShr extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int TXF1CLEAN = 2;
		public static final int TXF2CLEAN = 3;
		public static final int TXF3CLEAN = 4;
		public static final int TXF4CLEAN = 5;
		public static final int TXF5CLEAN = 6;
		public static final int TXF6CLEAN = 7;
		public static final int TXF7CLEAN = 8;
		public static final int TXF8CLEAN = 9;
		public static final int TXF9CLEAN = 10;
		public static final int TXF10CLEAN = 11;

		public StatShr(
					int ixWdbeVExpstate
					, boolean Txf1Clean
					, boolean Txf2Clean
					, boolean Txf3Clean
					, boolean Txf4Clean
					, boolean Txf5Clean
					, boolean Txf6Clean
					, boolean Txf7Clean
					, boolean Txf8Clean
					, boolean Txf9Clean
					, boolean Txf10Clean
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.Txf1Clean = Txf1Clean;
			this.Txf2Clean = Txf2Clean;
			this.Txf3Clean = Txf3Clean;
			this.Txf4Clean = Txf4Clean;
			this.Txf5Clean = Txf5Clean;
			this.Txf6Clean = Txf6Clean;
			this.Txf7Clean = Txf7Clean;
			this.Txf8Clean = Txf8Clean;
			this.Txf9Clean = Txf9Clean;
			this.Txf10Clean = Txf10Clean;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, TXF1CLEAN, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, TXF7CLEAN, TXF8CLEAN, TXF9CLEAN, TXF10CLEAN));
		};

		public int ixWdbeVExpstate;
		public boolean Txf1Clean;
		public boolean Txf2Clean;
		public boolean Txf3Clean;
		public boolean Txf4Clean;
		public boolean Txf5Clean;
		public boolean Txf6Clean;
		public boolean Txf7Clean;
		public boolean Txf8Clean;
		public boolean Txf9Clean;
		public boolean Txf10Clean;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbePrfLicense");

			String itemtag = "StatitemShrWdbePrfLicense";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				Txf1Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf1Clean", mask, TXF1CLEAN);
				Txf2Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf2Clean", mask, TXF2CLEAN);
				Txf3Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf3Clean", mask, TXF3CLEAN);
				Txf4Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf4Clean", mask, TXF4CLEAN);
				Txf5Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf5Clean", mask, TXF5CLEAN);
				Txf6Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf6Clean", mask, TXF6CLEAN);
				Txf7Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf7Clean", mask, TXF7CLEAN);
				Txf8Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf8Clean", mask, TXF8CLEAN);
				Txf9Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf9Clean", mask, TXF9CLEAN);
				Txf10Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf10Clean", mask, TXF10CLEAN);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (Txf1Clean == comp.Txf1Clean) items.add(TXF1CLEAN);
			if (Txf2Clean == comp.Txf2Clean) items.add(TXF2CLEAN);
			if (Txf3Clean == comp.Txf3Clean) items.add(TXF3CLEAN);
			if (Txf4Clean == comp.Txf4Clean) items.add(TXF4CLEAN);
			if (Txf5Clean == comp.Txf5Clean) items.add(TXF5CLEAN);
			if (Txf6Clean == comp.Txf6Clean) items.add(TXF6CLEAN);
			if (Txf7Clean == comp.Txf7Clean) items.add(TXF7CLEAN);
			if (Txf8Clean == comp.Txf8Clean) items.add(TXF8CLEAN);
			if (Txf9Clean == comp.Txf9Clean) items.add(TXF9CLEAN);
			if (Txf10Clean == comp.Txf10Clean) items.add(TXF10CLEAN);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, TXF1CLEAN, TXF2CLEAN, TXF3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, TXF7CLEAN, TXF8CLEAN, TXF9CLEAN, TXF10CLEAN));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbePrfLicense)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPT1 = 2;
		public static final int CPT2 = 3;
		public static final int CPT3 = 4;
		public static final int CPT4 = 5;
		public static final int CPT5 = 6;
		public static final int CPT6 = 7;
		public static final int CPT7 = 8;
		public static final int CPT8 = 9;
		public static final int CPT9 = 10;
		public static final int CPT10 = 11;

		public Tag(
					String Cpt
					, String Cpt1
					, String Cpt2
					, String Cpt3
					, String Cpt4
					, String Cpt5
					, String Cpt6
					, String Cpt7
					, String Cpt8
					, String Cpt9
					, String Cpt10
				) {
			this.Cpt = Cpt;
			this.Cpt1 = Cpt1;
			this.Cpt2 = Cpt2;
			this.Cpt3 = Cpt3;
			this.Cpt4 = Cpt4;
			this.Cpt5 = Cpt5;
			this.Cpt6 = Cpt6;
			this.Cpt7 = Cpt7;
			this.Cpt8 = Cpt8;
			this.Cpt9 = Cpt9;
			this.Cpt10 = Cpt10;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPT1, CPT2, CPT3, CPT4, CPT5, CPT6, CPT7, CPT8, CPT9, CPT10));
		};

		public String Cpt;
		public String Cpt1;
		public String Cpt2;
		public String Cpt3;
		public String Cpt4;
		public String Cpt5;
		public String Cpt6;
		public String Cpt7;
		public String Cpt8;
		public String Cpt9;
		public String Cpt10;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbePrfLicense");

			String itemtag = "TagitemWdbePrfLicense";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				Cpt1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt1", mask, CPT1);
				Cpt2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt2", mask, CPT2);
				Cpt3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt3", mask, CPT3);
				Cpt4 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt4", mask, CPT4);
				Cpt5 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt5", mask, CPT5);
				Cpt6 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt6", mask, CPT6);
				Cpt7 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt7", mask, CPT7);
				Cpt8 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt8", mask, CPT8);
				Cpt9 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt9", mask, CPT9);
				Cpt10 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt10", mask, CPT10);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (Cpt1.equals(comp.Cpt1)) items.add(CPT1);
			if (Cpt2.equals(comp.Cpt2)) items.add(CPT2);
			if (Cpt3.equals(comp.Cpt3)) items.add(CPT3);
			if (Cpt4.equals(comp.Cpt4)) items.add(CPT4);
			if (Cpt5.equals(comp.Cpt5)) items.add(CPT5);
			if (Cpt6.equals(comp.Cpt6)) items.add(CPT6);
			if (Cpt7.equals(comp.Cpt7)) items.add(CPT7);
			if (Cpt8.equals(comp.Cpt8)) items.add(CPT8);
			if (Cpt9.equals(comp.Cpt9)) items.add(CPT9);
			if (Cpt10.equals(comp.Cpt10)) items.add(CPT10);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPT1, CPT2, CPT3, CPT4, CPT5, CPT6, CPT7, CPT8, CPT9, CPT10));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbePrfLicenseData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPRFLICENSEDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePrfLicenseData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbePrfLicenseDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPRFLICENSEDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePrfLicenseDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbePrfLicenseData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int STATSHR = 3;
		public static final int TAG = 4;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEPRFLICENSEDATA);

			contiac = new ContIac("", "", "", "", "", "", "", "", "", "");
			statshr = new StatShr(0, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbePrfLicenseData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", "", "", "", "", "", "", "", "");
				statshr = new StatShr(0, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
