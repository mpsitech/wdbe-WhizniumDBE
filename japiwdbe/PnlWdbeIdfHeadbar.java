/**
  * \file PnlWdbeIdfHeadbar.java
  * Java API code for job PnlWdbeIdfHeadbar
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 22 Aug 2025
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeIdfHeadbar {
	/**
	  * StgInf (full: StgInfWdbeIdfHeadbar)
	  */
	public class StgInf extends Block {

		public static final int MENAPPCPTWIDTH = 1;
		public static final int MENAPPWIDTH = 2;

		public StgInf(
					int MenAppCptwidth
					, int MenAppWidth
				) {
			this.MenAppCptwidth = MenAppCptwidth;
			this.MenAppWidth = MenAppWidth;

			mask = new HashSet<Integer>(Arrays.asList(MENAPPCPTWIDTH, MENAPPWIDTH));
		};

		public int MenAppCptwidth;
		public int MenAppWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgInfWdbeIdfHeadbar");

			String itemtag = "StgitemInfWdbeIdfHeadbar";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MenAppCptwidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MenAppCptwidth", mask, MENAPPCPTWIDTH);
				MenAppWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MenAppWidth", mask, MENAPPWIDTH);

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

			return(items);
		};

		public HashSet<Integer> diff(
					StgInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MENAPPCPTWIDTH, MENAPPWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeIdfHeadbar)
	  */
	public class Tag extends Block {

		public static final int MENAPP = 1;

		public Tag(
					String MenApp
				) {
			this.MenApp = MenApp;

			mask = new HashSet<Integer>(Arrays.asList(MENAPP));
		};

		public String MenApp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeIdfHeadbar");

			String itemtag = "TagitemWdbeIdfHeadbar";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MenApp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MenApp", mask, MENAPP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (MenApp.equals(comp.MenApp)) items.add(MENAPP);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MENAPP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeIdfHeadbarData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int STGINF = 2;
		public static final int TAG = 3;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEIDFHEADBARDATA);

			stginf = new StgInf(0, 0);
			tag = new Tag("");
		};

		public StgInf stginf;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeIdfHeadbarData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (stginf.readXML(doc, basexpath, true)) add(STGINF);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				stginf = new StgInf(0, 0);
				tag = new Tag("");
			};
		};

	};

};
