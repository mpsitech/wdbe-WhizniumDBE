/**
  * \file PnlWdbeNavDevdev.java
  * Java API code for job PnlWdbeNavDevdev
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeNavDevdev {
	/**
		* VecVDo (full: VecVWdbeNavDevdevDo)
		*/
	public static class VecVDo {

		public static final int BUTPRJVIEWCLICK = 1;
		public static final int BUTPRJNEWCRDCLICK = 2;
		public static final int BUTVERVIEWCLICK = 3;
		public static final int BUTVERNEWCRDCLICK = 4;
		public static final int BUTSYSVIEWCLICK = 5;
		public static final int BUTSYSNEWCRDCLICK = 6;
		public static final int BUTTRGVIEWCLICK = 7;
		public static final int BUTTRGNEWCRDCLICK = 8;
		public static final int BUTUNTVIEWCLICK = 9;
		public static final int BUTUNTNEWCRDCLICK = 10;
		public static final int BUTRLSVIEWCLICK = 11;
		public static final int BUTRLSNEWCRDCLICK = 12;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butprjviewclick")) return BUTPRJVIEWCLICK;
			if (s.equals("butprjnewcrdclick")) return BUTPRJNEWCRDCLICK;
			if (s.equals("butverviewclick")) return BUTVERVIEWCLICK;
			if (s.equals("butvernewcrdclick")) return BUTVERNEWCRDCLICK;
			if (s.equals("butsysviewclick")) return BUTSYSVIEWCLICK;
			if (s.equals("butsysnewcrdclick")) return BUTSYSNEWCRDCLICK;
			if (s.equals("buttrgviewclick")) return BUTTRGVIEWCLICK;
			if (s.equals("buttrgnewcrdclick")) return BUTTRGNEWCRDCLICK;
			if (s.equals("butuntviewclick")) return BUTUNTVIEWCLICK;
			if (s.equals("butuntnewcrdclick")) return BUTUNTNEWCRDCLICK;
			if (s.equals("butrlsviewclick")) return BUTRLSVIEWCLICK;
			if (s.equals("butrlsnewcrdclick")) return BUTRLSNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
			if (ix == BUTPRJNEWCRDCLICK) return("ButPrjNewcrdClick");
			if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
			if (ix == BUTVERNEWCRDCLICK) return("ButVerNewcrdClick");
			if (ix == BUTSYSVIEWCLICK) return("ButSysViewClick");
			if (ix == BUTSYSNEWCRDCLICK) return("ButSysNewcrdClick");
			if (ix == BUTTRGVIEWCLICK) return("ButTrgViewClick");
			if (ix == BUTTRGNEWCRDCLICK) return("ButTrgNewcrdClick");
			if (ix == BUTUNTVIEWCLICK) return("ButUntViewClick");
			if (ix == BUTUNTNEWCRDCLICK) return("ButUntNewcrdClick");
			if (ix == BUTRLSVIEWCLICK) return("ButRlsViewClick");
			if (ix == BUTRLSNEWCRDCLICK) return("ButRlsNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeNavDevdev)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTPRJ = 1;
		public static final int NUMFLSTVER = 2;
		public static final int NUMFLSTSYS = 3;
		public static final int NUMFLSTTRG = 4;
		public static final int NUMFLSTUNT = 5;
		public static final int NUMFLSTRLS = 6;

		public ContIac(
					int numFLstPrj
					, int numFLstVer
					, int numFLstSys
					, int numFLstTrg
					, int numFLstUnt
					, int numFLstRls
				) {
			this.numFLstPrj = numFLstPrj;
			this.numFLstVer = numFLstVer;
			this.numFLstSys = numFLstSys;
			this.numFLstTrg = numFLstTrg;
			this.numFLstUnt = numFLstUnt;
			this.numFLstRls = numFLstRls;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTPRJ, NUMFLSTVER, NUMFLSTSYS, NUMFLSTTRG, NUMFLSTUNT, NUMFLSTRLS));
		};

		public int numFLstPrj;
		public int numFLstVer;
		public int numFLstSys;
		public int numFLstTrg;
		public int numFLstUnt;
		public int numFLstRls;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeNavDevdev");

			String itemtag = "ContitemIacWdbeNavDevdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstPrj = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPrj", mask, NUMFLSTPRJ);
				numFLstVer = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVer", mask, NUMFLSTVER);
				numFLstSys = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSys", mask, NUMFLSTSYS);
				numFLstTrg = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstTrg", mask, NUMFLSTTRG);
				numFLstUnt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstUnt", mask, NUMFLSTUNT);
				numFLstRls = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstRls", mask, NUMFLSTRLS);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeNavDevdev";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeNavDevdev";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPrj", numFLstPrj);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVer", numFLstVer);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSys", numFLstSys);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstTrg", numFLstTrg);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstUnt", numFLstUnt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstRls", numFLstRls);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstPrj == comp.numFLstPrj) items.add(NUMFLSTPRJ);
			if (numFLstVer == comp.numFLstVer) items.add(NUMFLSTVER);
			if (numFLstSys == comp.numFLstSys) items.add(NUMFLSTSYS);
			if (numFLstTrg == comp.numFLstTrg) items.add(NUMFLSTTRG);
			if (numFLstUnt == comp.numFLstUnt) items.add(NUMFLSTUNT);
			if (numFLstRls == comp.numFLstRls) items.add(NUMFLSTRLS);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTPRJ, NUMFLSTVER, NUMFLSTSYS, NUMFLSTTRG, NUMFLSTUNT, NUMFLSTRLS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeNavDevdev)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTPRJALT = 2;
		public static final int LSTVERALT = 3;
		public static final int LSTSYSALT = 4;
		public static final int LSTTRGALT = 5;
		public static final int LSTUNTALT = 6;
		public static final int LSTRLSALT = 7;
		public static final int LSTPRJNUMFIRSTDISP = 8;
		public static final int LSTVERNUMFIRSTDISP = 9;
		public static final int LSTSYSNUMFIRSTDISP = 10;
		public static final int LSTTRGNUMFIRSTDISP = 11;
		public static final int LSTUNTNUMFIRSTDISP = 12;
		public static final int LSTRLSNUMFIRSTDISP = 13;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstPrjAlt
					, boolean LstVerAlt
					, boolean LstSysAlt
					, boolean LstTrgAlt
					, boolean LstUntAlt
					, boolean LstRlsAlt
					, int LstPrjNumFirstdisp
					, int LstVerNumFirstdisp
					, int LstSysNumFirstdisp
					, int LstTrgNumFirstdisp
					, int LstUntNumFirstdisp
					, int LstRlsNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstPrjAlt = LstPrjAlt;
			this.LstVerAlt = LstVerAlt;
			this.LstSysAlt = LstSysAlt;
			this.LstTrgAlt = LstTrgAlt;
			this.LstUntAlt = LstUntAlt;
			this.LstRlsAlt = LstRlsAlt;
			this.LstPrjNumFirstdisp = LstPrjNumFirstdisp;
			this.LstVerNumFirstdisp = LstVerNumFirstdisp;
			this.LstSysNumFirstdisp = LstSysNumFirstdisp;
			this.LstTrgNumFirstdisp = LstTrgNumFirstdisp;
			this.LstUntNumFirstdisp = LstUntNumFirstdisp;
			this.LstRlsNumFirstdisp = LstRlsNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTPRJALT, LSTVERALT, LSTSYSALT, LSTTRGALT, LSTUNTALT, LSTRLSALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTSYSNUMFIRSTDISP, LSTTRGNUMFIRSTDISP, LSTUNTNUMFIRSTDISP, LSTRLSNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstPrjAlt;
		public boolean LstVerAlt;
		public boolean LstSysAlt;
		public boolean LstTrgAlt;
		public boolean LstUntAlt;
		public boolean LstRlsAlt;
		public int LstPrjNumFirstdisp;
		public int LstVerNumFirstdisp;
		public int LstSysNumFirstdisp;
		public int LstTrgNumFirstdisp;
		public int LstUntNumFirstdisp;
		public int LstRlsNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeNavDevdev");

			String itemtag = "StatitemAppWdbeNavDevdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstPrjAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrjAlt", mask, LSTPRJALT);
				LstVerAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVerAlt", mask, LSTVERALT);
				LstSysAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSysAlt", mask, LSTSYSALT);
				LstTrgAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTrgAlt", mask, LSTTRGALT);
				LstUntAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUntAlt", mask, LSTUNTALT);
				LstRlsAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRlsAlt", mask, LSTRLSALT);
				LstPrjNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrjNumFirstdisp", mask, LSTPRJNUMFIRSTDISP);
				LstVerNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVerNumFirstdisp", mask, LSTVERNUMFIRSTDISP);
				LstSysNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSysNumFirstdisp", mask, LSTSYSNUMFIRSTDISP);
				LstTrgNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTrgNumFirstdisp", mask, LSTTRGNUMFIRSTDISP);
				LstUntNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUntNumFirstdisp", mask, LSTUNTNUMFIRSTDISP);
				LstRlsNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRlsNumFirstdisp", mask, LSTRLSNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstPrjAlt == comp.LstPrjAlt) items.add(LSTPRJALT);
			if (LstVerAlt == comp.LstVerAlt) items.add(LSTVERALT);
			if (LstSysAlt == comp.LstSysAlt) items.add(LSTSYSALT);
			if (LstTrgAlt == comp.LstTrgAlt) items.add(LSTTRGALT);
			if (LstUntAlt == comp.LstUntAlt) items.add(LSTUNTALT);
			if (LstRlsAlt == comp.LstRlsAlt) items.add(LSTRLSALT);
			if (LstPrjNumFirstdisp == comp.LstPrjNumFirstdisp) items.add(LSTPRJNUMFIRSTDISP);
			if (LstVerNumFirstdisp == comp.LstVerNumFirstdisp) items.add(LSTVERNUMFIRSTDISP);
			if (LstSysNumFirstdisp == comp.LstSysNumFirstdisp) items.add(LSTSYSNUMFIRSTDISP);
			if (LstTrgNumFirstdisp == comp.LstTrgNumFirstdisp) items.add(LSTTRGNUMFIRSTDISP);
			if (LstUntNumFirstdisp == comp.LstUntNumFirstdisp) items.add(LSTUNTNUMFIRSTDISP);
			if (LstRlsNumFirstdisp == comp.LstRlsNumFirstdisp) items.add(LSTRLSNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTPRJALT, LSTVERALT, LSTSYSALT, LSTTRGALT, LSTUNTALT, LSTRLSALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTSYSNUMFIRSTDISP, LSTTRGNUMFIRSTDISP, LSTUNTNUMFIRSTDISP, LSTRLSNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeNavDevdev)
	  */
	public class StatShr extends Block {

		public static final int LSTPRJAVAIL = 1;
		public static final int BUTPRJVIEWACTIVE = 2;
		public static final int LSTVERAVAIL = 3;
		public static final int BUTVERVIEWACTIVE = 4;
		public static final int LSTSYSAVAIL = 5;
		public static final int BUTSYSVIEWACTIVE = 6;
		public static final int BUTSYSNEWCRDACTIVE = 7;
		public static final int LSTTRGAVAIL = 8;
		public static final int BUTTRGVIEWACTIVE = 9;
		public static final int BUTTRGNEWCRDACTIVE = 10;
		public static final int LSTUNTAVAIL = 11;
		public static final int BUTUNTVIEWACTIVE = 12;
		public static final int BUTUNTNEWCRDACTIVE = 13;
		public static final int LSTRLSAVAIL = 14;
		public static final int BUTRLSVIEWACTIVE = 15;
		public static final int BUTRLSNEWCRDACTIVE = 16;

		public StatShr(
					boolean LstPrjAvail
					, boolean ButPrjViewActive
					, boolean LstVerAvail
					, boolean ButVerViewActive
					, boolean LstSysAvail
					, boolean ButSysViewActive
					, boolean ButSysNewcrdActive
					, boolean LstTrgAvail
					, boolean ButTrgViewActive
					, boolean ButTrgNewcrdActive
					, boolean LstUntAvail
					, boolean ButUntViewActive
					, boolean ButUntNewcrdActive
					, boolean LstRlsAvail
					, boolean ButRlsViewActive
					, boolean ButRlsNewcrdActive
				) {
			this.LstPrjAvail = LstPrjAvail;
			this.ButPrjViewActive = ButPrjViewActive;
			this.LstVerAvail = LstVerAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.LstSysAvail = LstSysAvail;
			this.ButSysViewActive = ButSysViewActive;
			this.ButSysNewcrdActive = ButSysNewcrdActive;
			this.LstTrgAvail = LstTrgAvail;
			this.ButTrgViewActive = ButTrgViewActive;
			this.ButTrgNewcrdActive = ButTrgNewcrdActive;
			this.LstUntAvail = LstUntAvail;
			this.ButUntViewActive = ButUntViewActive;
			this.ButUntNewcrdActive = ButUntNewcrdActive;
			this.LstRlsAvail = LstRlsAvail;
			this.ButRlsViewActive = ButRlsViewActive;
			this.ButRlsNewcrdActive = ButRlsNewcrdActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTSYSAVAIL, BUTSYSVIEWACTIVE, BUTSYSNEWCRDACTIVE, LSTTRGAVAIL, BUTTRGVIEWACTIVE, BUTTRGNEWCRDACTIVE, LSTUNTAVAIL, BUTUNTVIEWACTIVE, BUTUNTNEWCRDACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE));
		};

		public boolean LstPrjAvail;
		public boolean ButPrjViewActive;
		public boolean LstVerAvail;
		public boolean ButVerViewActive;
		public boolean LstSysAvail;
		public boolean ButSysViewActive;
		public boolean ButSysNewcrdActive;
		public boolean LstTrgAvail;
		public boolean ButTrgViewActive;
		public boolean ButTrgNewcrdActive;
		public boolean LstUntAvail;
		public boolean ButUntViewActive;
		public boolean ButUntNewcrdActive;
		public boolean LstRlsAvail;
		public boolean ButRlsViewActive;
		public boolean ButRlsNewcrdActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNavDevdev");

			String itemtag = "StatitemShrWdbeNavDevdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstPrjAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrjAvail", mask, LSTPRJAVAIL);
				ButPrjViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrjViewActive", mask, BUTPRJVIEWACTIVE);
				LstVerAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVerAvail", mask, LSTVERAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
				LstSysAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSysAvail", mask, LSTSYSAVAIL);
				ButSysViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSysViewActive", mask, BUTSYSVIEWACTIVE);
				ButSysNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSysNewcrdActive", mask, BUTSYSNEWCRDACTIVE);
				LstTrgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstTrgAvail", mask, LSTTRGAVAIL);
				ButTrgViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTrgViewActive", mask, BUTTRGVIEWACTIVE);
				ButTrgNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTrgNewcrdActive", mask, BUTTRGNEWCRDACTIVE);
				LstUntAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUntAvail", mask, LSTUNTAVAIL);
				ButUntViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUntViewActive", mask, BUTUNTVIEWACTIVE);
				ButUntNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUntNewcrdActive", mask, BUTUNTNEWCRDACTIVE);
				LstRlsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstRlsAvail", mask, LSTRLSAVAIL);
				ButRlsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRlsViewActive", mask, BUTRLSVIEWACTIVE);
				ButRlsNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRlsNewcrdActive", mask, BUTRLSNEWCRDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstPrjAvail == comp.LstPrjAvail) items.add(LSTPRJAVAIL);
			if (ButPrjViewActive == comp.ButPrjViewActive) items.add(BUTPRJVIEWACTIVE);
			if (LstVerAvail == comp.LstVerAvail) items.add(LSTVERAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (LstSysAvail == comp.LstSysAvail) items.add(LSTSYSAVAIL);
			if (ButSysViewActive == comp.ButSysViewActive) items.add(BUTSYSVIEWACTIVE);
			if (ButSysNewcrdActive == comp.ButSysNewcrdActive) items.add(BUTSYSNEWCRDACTIVE);
			if (LstTrgAvail == comp.LstTrgAvail) items.add(LSTTRGAVAIL);
			if (ButTrgViewActive == comp.ButTrgViewActive) items.add(BUTTRGVIEWACTIVE);
			if (ButTrgNewcrdActive == comp.ButTrgNewcrdActive) items.add(BUTTRGNEWCRDACTIVE);
			if (LstUntAvail == comp.LstUntAvail) items.add(LSTUNTAVAIL);
			if (ButUntViewActive == comp.ButUntViewActive) items.add(BUTUNTVIEWACTIVE);
			if (ButUntNewcrdActive == comp.ButUntNewcrdActive) items.add(BUTUNTNEWCRDACTIVE);
			if (LstRlsAvail == comp.LstRlsAvail) items.add(LSTRLSAVAIL);
			if (ButRlsViewActive == comp.ButRlsViewActive) items.add(BUTRLSVIEWACTIVE);
			if (ButRlsNewcrdActive == comp.ButRlsNewcrdActive) items.add(BUTRLSNEWCRDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTSYSAVAIL, BUTSYSVIEWACTIVE, BUTSYSNEWCRDACTIVE, LSTTRGAVAIL, BUTTRGVIEWACTIVE, BUTTRGNEWCRDACTIVE, LSTUNTAVAIL, BUTUNTVIEWACTIVE, BUTUNTNEWCRDACTIVE, LSTRLSAVAIL, BUTRLSVIEWACTIVE, BUTRLSNEWCRDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNavDevdev)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTPRJ = 2;
		public static final int CPTVER = 3;
		public static final int CPTSYS = 4;
		public static final int CPTTRG = 5;
		public static final int CPTUNT = 6;
		public static final int CPTRLS = 7;

		public Tag(
					String Cpt
					, String CptPrj
					, String CptVer
					, String CptSys
					, String CptTrg
					, String CptUnt
					, String CptRls
				) {
			this.Cpt = Cpt;
			this.CptPrj = CptPrj;
			this.CptVer = CptVer;
			this.CptSys = CptSys;
			this.CptTrg = CptTrg;
			this.CptUnt = CptUnt;
			this.CptRls = CptRls;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTPRJ, CPTVER, CPTSYS, CPTTRG, CPTUNT, CPTRLS));
		};

		public String Cpt;
		public String CptPrj;
		public String CptVer;
		public String CptSys;
		public String CptTrg;
		public String CptUnt;
		public String CptRls;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNavDevdev");

			String itemtag = "TagitemWdbeNavDevdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptPrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrj", mask, CPTPRJ);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptSys = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSys", mask, CPTSYS);
				CptTrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTrg", mask, CPTTRG);
				CptUnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUnt", mask, CPTUNT);
				CptRls = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRls", mask, CPTRLS);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptPrj.equals(comp.CptPrj)) items.add(CPTPRJ);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptSys.equals(comp.CptSys)) items.add(CPTSYS);
			if (CptTrg.equals(comp.CptTrg)) items.add(CPTTRG);
			if (CptUnt.equals(comp.CptUnt)) items.add(CPTUNT);
			if (CptRls.equals(comp.CptRls)) items.add(CPTRLS);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTPRJ, CPTVER, CPTSYS, CPTTRG, CPTUNT, CPTRLS));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeNavDevdevData)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVDEVDEVDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavDevdevData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavDevdevDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVDEVDEVDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavDevdevDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavDevdevData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTPRJ = 3;
		public static final int FEEDFLSTRLS = 4;
		public static final int FEEDFLSTSYS = 5;
		public static final int FEEDFLSTTRG = 6;
		public static final int FEEDFLSTUNT = 7;
		public static final int FEEDFLSTVER = 8;
		public static final int STATAPP = 9;
		public static final int STATSHR = 10;
		public static final int TAG = 11;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVDEVDEVDATA);

			contiac = new ContIac(0, 0, 0, 0, 0, 0);
			feedFLstPrj = new Feed("FeedFLstPrj");
			feedFLstRls = new Feed("FeedFLstRls");
			feedFLstSys = new Feed("FeedFLstSys");
			feedFLstTrg = new Feed("FeedFLstTrg");
			feedFLstUnt = new Feed("FeedFLstUnt");
			feedFLstVer = new Feed("FeedFLstVer");
			statapp = new StatApp(0, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstPrj;
		public Feed feedFLstRls;
		public Feed feedFLstSys;
		public Feed feedFLstTrg;
		public Feed feedFLstUnt;
		public Feed feedFLstVer;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTPRJ)) ss.add("feedFLstPrj");
			if (has(FEEDFLSTRLS)) ss.add("feedFLstRls");
			if (has(FEEDFLSTSYS)) ss.add("feedFLstSys");
			if (has(FEEDFLSTTRG)) ss.add("feedFLstTrg");
			if (has(FEEDFLSTUNT)) ss.add("feedFLstUnt");
			if (has(FEEDFLSTVER)) ss.add("feedFLstVer");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavDevdevData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstPrj.readXML(doc, basexpath, true)) add(FEEDFLSTPRJ);
				if (feedFLstRls.readXML(doc, basexpath, true)) add(FEEDFLSTRLS);
				if (feedFLstSys.readXML(doc, basexpath, true)) add(FEEDFLSTSYS);
				if (feedFLstTrg.readXML(doc, basexpath, true)) add(FEEDFLSTTRG);
				if (feedFLstUnt.readXML(doc, basexpath, true)) add(FEEDFLSTUNT);
				if (feedFLstVer.readXML(doc, basexpath, true)) add(FEEDFLSTVER);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0, 0);
				feedFLstPrj = new Feed("FeedFLstPrj");
				feedFLstRls = new Feed("FeedFLstRls");
				feedFLstSys = new Feed("FeedFLstSys");
				feedFLstTrg = new Feed("FeedFLstTrg");
				feedFLstUnt = new Feed("FeedFLstUnt");
				feedFLstVer = new Feed("FeedFLstVer");
				statapp = new StatApp(0, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "");
			};
		};

	};

};

