/**
  * \file PnlWdbeNavHeadbar.java
  * Java API code for job PnlWdbeNavHeadbar
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeNavHeadbar {
	/**
	  * StatShr (full: StatShrWdbeNavHeadbar)
	  */
	public class StatShr extends Block {

		public static final int MENCRDAVAIL = 1;

		public StatShr(
					boolean MenCrdAvail
				) {
			this.MenCrdAvail = MenCrdAvail;

			mask = new HashSet<Integer>(Arrays.asList(MENCRDAVAIL));
		};

		public boolean MenCrdAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNavHeadbar");

			String itemtag = "StatitemShrWdbeNavHeadbar";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MenCrdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MenCrdAvail", mask, MENCRDAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (MenCrdAvail == comp.MenCrdAvail) items.add(MENCRDAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MENCRDAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgInf (full: StgInfWdbeNavHeadbar)
	  */
	public class StgInf extends Block {

		public static final int MENAPPCPTWIDTH = 1;
		public static final int MENAPPWIDTH = 2;
		public static final int MENSESCPTWIDTH = 3;
		public static final int MENSESWIDTH = 4;
		public static final int MENCRDCPTWIDTH = 5;
		public static final int MENCRDWIDTH = 6;

		public StgInf(
					int MenAppCptwidth
					, int MenAppWidth
					, int MenSesCptwidth
					, int MenSesWidth
					, int MenCrdCptwidth
					, int MenCrdWidth
				) {
			this.MenAppCptwidth = MenAppCptwidth;
			this.MenAppWidth = MenAppWidth;
			this.MenSesCptwidth = MenSesCptwidth;
			this.MenSesWidth = MenSesWidth;
			this.MenCrdCptwidth = MenCrdCptwidth;
			this.MenCrdWidth = MenCrdWidth;

			mask = new HashSet<Integer>(Arrays.asList(MENAPPCPTWIDTH, MENAPPWIDTH, MENSESCPTWIDTH, MENSESWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH));
		};

		public int MenAppCptwidth;
		public int MenAppWidth;
		public int MenSesCptwidth;
		public int MenSesWidth;
		public int MenCrdCptwidth;
		public int MenCrdWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgInfWdbeNavHeadbar");

			String itemtag = "StgitemInfWdbeNavHeadbar";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MenAppCptwidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MenAppCptwidth", mask, MENAPPCPTWIDTH);
				MenAppWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MenAppWidth", mask, MENAPPWIDTH);
				MenSesCptwidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MenSesCptwidth", mask, MENSESCPTWIDTH);
				MenSesWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MenSesWidth", mask, MENSESWIDTH);
				MenCrdCptwidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MenCrdCptwidth", mask, MENCRDCPTWIDTH);
				MenCrdWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MenCrdWidth", mask, MENCRDWIDTH);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StgInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (MenAppCptwidth == comp.MenAppCptwidth) items.add(MENAPPCPTWIDTH);
			if (MenAppWidth == comp.MenAppWidth) items.add(MENAPPWIDTH);
			if (MenSesCptwidth == comp.MenSesCptwidth) items.add(MENSESCPTWIDTH);
			if (MenSesWidth == comp.MenSesWidth) items.add(MENSESWIDTH);
			if (MenCrdCptwidth == comp.MenCrdCptwidth) items.add(MENCRDCPTWIDTH);
			if (MenCrdWidth == comp.MenCrdWidth) items.add(MENCRDWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MENAPPCPTWIDTH, MENAPPWIDTH, MENSESCPTWIDTH, MENSESWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNavHeadbar)
	  */
	public class Tag extends Block {

		public static final int MENAPP = 1;
		public static final int MENSES = 2;
		public static final int MENCRD = 3;

		public Tag(
					String MenApp
					, String MenSes
					, String MenCrd
				) {
			this.MenApp = MenApp;
			this.MenSes = MenSes;
			this.MenCrd = MenCrd;

			mask = new HashSet<Integer>(Arrays.asList(MENAPP, MENSES, MENCRD));
		};

		public String MenApp;
		public String MenSes;
		public String MenCrd;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNavHeadbar");

			String itemtag = "TagitemWdbeNavHeadbar";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MenApp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MenApp", mask, MENAPP);
				MenSes = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MenSes", mask, MENSES);
				MenCrd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MenCrd", mask, MENCRD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (MenApp.equals(comp.MenApp)) items.add(MENAPP);
			if (MenSes.equals(comp.MenSes)) items.add(MENSES);
			if (MenCrd.equals(comp.MenCrd)) items.add(MENCRD);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MENAPP, MENSES, MENCRD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavHeadbarData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int STATSHR = 2;
		public static final int STGINF = 3;
		public static final int TAG = 4;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVHEADBARDATA);

			statshr = new StatShr(false);
			stginf = new StgInf(0, 0, 0, 0, 0, 0);
			tag = new Tag("", "", "");
		};

		public StatShr statshr;
		public StgInf stginf;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STGINF)) ss.add("stginf");
			if (has(TAG)) ss.add("tag");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavHeadbarData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (stginf.readXML(doc, basexpath, true)) add(STGINF);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				statshr = new StatShr(false);
				stginf = new StgInf(0, 0, 0, 0, 0, 0);
				tag = new Tag("", "", "");
			};
		};

	};

};

