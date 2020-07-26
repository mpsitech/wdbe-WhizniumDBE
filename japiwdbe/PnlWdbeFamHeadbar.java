/**
  * \file PnlWdbeFamHeadbar.java
  * Java API code for job PnlWdbeFamHeadbar
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeFamHeadbar {
	/**
	  * StgInf (full: StgInfWdbeFamHeadbar)
	  */
	public class StgInf extends Block {

		public static final int MENAPPCPTWIDTH = 1;
		public static final int MENAPPWIDTH = 2;
		public static final int MENCRDCPTWIDTH = 3;
		public static final int MENCRDWIDTH = 4;

		public StgInf(
					int MenAppCptwidth
					, int MenAppWidth
					, int MenCrdCptwidth
					, int MenCrdWidth
				) {
			this.MenAppCptwidth = MenAppCptwidth;
			this.MenAppWidth = MenAppWidth;
			this.MenCrdCptwidth = MenCrdCptwidth;
			this.MenCrdWidth = MenCrdWidth;

			mask = new HashSet<Integer>(Arrays.asList(MENAPPCPTWIDTH, MENAPPWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH));
		};

		public int MenAppCptwidth;
		public int MenAppWidth;
		public int MenCrdCptwidth;
		public int MenCrdWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgInfWdbeFamHeadbar");

			String itemtag = "StgitemInfWdbeFamHeadbar";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MenAppCptwidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MenAppCptwidth", mask, MENAPPCPTWIDTH);
				MenAppWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MenAppWidth", mask, MENAPPWIDTH);
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

			diffitems = new HashSet<Integer>(Arrays.asList(MENAPPCPTWIDTH, MENAPPWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeFamHeadbar)
	  */
	public class Tag extends Block {

		public static final int MENAPP = 1;
		public static final int MENCRD = 2;

		public Tag(
					String MenApp
					, String MenCrd
				) {
			this.MenApp = MenApp;
			this.MenCrd = MenCrd;

			mask = new HashSet<Integer>(Arrays.asList(MENAPP, MENCRD));
		};

		public String MenApp;
		public String MenCrd;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeFamHeadbar");

			String itemtag = "TagitemWdbeFamHeadbar";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MenApp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MenApp", mask, MENAPP);
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
			if (MenCrd.equals(comp.MenCrd)) items.add(MENCRD);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MENAPP, MENCRD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeFamHeadbarData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int STGINF = 2;
		public static final int TAG = 3;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEFAMHEADBARDATA);

			stginf = new StgInf(0, 0, 0, 0);
			tag = new Tag("", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeFamHeadbarData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (stginf.readXML(doc, basexpath, true)) add(STGINF);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				stginf = new StgInf(0, 0, 0, 0);
				tag = new Tag("", "");
			};
		};

	};

};

