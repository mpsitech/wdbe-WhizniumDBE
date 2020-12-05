/**
  * \file QryWdbeGenList.java
  * Java API code for job QryWdbeGenList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class QryWdbeGenList {
	/**
		* VecVOrd (full: VecVQryWdbeGenListOrd)
		*/
	public static class VecVOrd {

		public static final int MDL = 1;
		public static final int SRF = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("mdl")) return MDL;
			if (s.equals("srf")) return SRF;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == MDL) return("mdl");
			if (ix == SRF) return("srf");

			return "";
		};

	};

	/**
	  * StatApp (full: StatAppQryWdbeGenList)
	  */
	public class StatApp extends Block {

		public static final int FIRSTCOL = 1;
		public static final int JNUMFIRSTDISP = 2;
		public static final int NCOL = 3;
		public static final int NDISP = 4;

		public StatApp(
					int firstcol
					, int jnumFirstdisp
					, int ncol
					, int ndisp
				) {
			this.firstcol = firstcol;
			this.jnumFirstdisp = jnumFirstdisp;
			this.ncol = ncol;
			this.ndisp = ndisp;

			mask = new HashSet<Integer>(Arrays.asList(FIRSTCOL, JNUMFIRSTDISP, NCOL, NDISP));
		};

		public int firstcol;
		public int jnumFirstdisp;
		public int ncol;
		public int ndisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppQryWdbeGenList");

			String itemtag = "StatitemAppQryWdbeGenList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				firstcol = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "firstcol", mask, FIRSTCOL);
				jnumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "jnumFirstdisp", mask, JNUMFIRSTDISP);
				ncol = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ncol", mask, NCOL);
				ndisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ndisp", mask, NDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (firstcol == comp.firstcol) items.add(FIRSTCOL);
			if (jnumFirstdisp == comp.jnumFirstdisp) items.add(JNUMFIRSTDISP);
			if (ncol == comp.ncol) items.add(NCOL);
			if (ndisp == comp.ndisp) items.add(NDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(FIRSTCOL, JNUMFIRSTDISP, NCOL, NDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrQryWdbeGenList)
	  */
	public class StatShr extends Block {

		public static final int NTOT = 1;
		public static final int JNUMFIRSTLOAD = 2;
		public static final int NLOAD = 3;

		public StatShr(
					int ntot
					, int jnumFirstload
					, int nload
				) {
			this.ntot = ntot;
			this.jnumFirstload = jnumFirstload;
			this.nload = nload;

			mask = new HashSet<Integer>(Arrays.asList(NTOT, JNUMFIRSTLOAD, NLOAD));
		};

		public int ntot;
		public int jnumFirstload;
		public int nload;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrQryWdbeGenList");

			String itemtag = "StatitemShrQryWdbeGenList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ntot = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ntot", mask, NTOT);
				jnumFirstload = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "jnumFirstload", mask, JNUMFIRSTLOAD);
				nload = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "nload", mask, NLOAD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ntot == comp.ntot) items.add(NTOT);
			if (jnumFirstload == comp.jnumFirstload) items.add(JNUMFIRSTLOAD);
			if (nload == comp.nload) items.add(NLOAD);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NTOT, JNUMFIRSTLOAD, NLOAD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacQryWdbeGenList)
	  */
	public class StgIac extends Block {

		public static final int JNUM = 1;
		public static final int JNUMFIRSTLOAD = 2;
		public static final int NLOAD = 3;

		public StgIac(
					int jnum
					, int jnumFirstload
					, int nload
				) {
			this.jnum = jnum;
			this.jnumFirstload = jnumFirstload;
			this.nload = nload;

			mask = new HashSet<Integer>(Arrays.asList(JNUM, JNUMFIRSTLOAD, NLOAD));
		};

		public int jnum;
		public int jnumFirstload;
		public int nload;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacQryWdbeGenList");

			String itemtag = "StgitemIacQryWdbeGenList";

			if (Xmlio.checkXPath(doc, basexpath)) {
				jnum = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "jnum", mask, JNUM);
				jnumFirstload = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "jnumFirstload", mask, JNUMFIRSTLOAD);
				nload = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "nload", mask, NLOAD);

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
			if (difftag.isEmpty()) difftag = "StgIacQryWdbeGenList";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacQryWdbeGenList";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "jnum", jnum);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "jnumFirstload", jnumFirstload);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "nload", nload);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (jnum == comp.jnum) items.add(JNUM);
			if (jnumFirstload == comp.jnumFirstload) items.add(JNUMFIRSTLOAD);
			if (nload == comp.nload) items.add(NLOAD);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(JNUM, JNUMFIRSTLOAD, NLOAD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

};

