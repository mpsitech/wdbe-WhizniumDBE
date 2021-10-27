/**
  * \file PnlWdbeNavHigh.java
  * Java API code for job PnlWdbeNavHigh
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeNavHigh {
	/**
		* VecVDo (full: VecVWdbeNavHighDo)
		*/
	public static class VecVDo {

		public static final int BUTPPHVIEWCLICK = 1;
		public static final int BUTPPHNEWCRDCLICK = 2;
		public static final int BUTMODVIEWCLICK = 3;
		public static final int BUTMODNEWCRDCLICK = 4;
		public static final int BUTVECVIEWCLICK = 5;
		public static final int BUTVECNEWCRDCLICK = 6;
		public static final int BUTVITVIEWCLICK = 7;
		public static final int BUTCMDVIEWCLICK = 8;
		public static final int BUTCMDNEWCRDCLICK = 9;
		public static final int BUTERRVIEWCLICK = 10;
		public static final int BUTERRNEWCRDCLICK = 11;
		public static final int BUTPPLVIEWCLICK = 12;
		public static final int BUTPPLNEWCRDCLICK = 13;
		public static final int BUTSEGVIEWCLICK = 14;
		public static final int BUTSEGNEWCRDCLICK = 15;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butpphviewclick")) return BUTPPHVIEWCLICK;
			if (s.equals("butpphnewcrdclick")) return BUTPPHNEWCRDCLICK;
			if (s.equals("butmodviewclick")) return BUTMODVIEWCLICK;
			if (s.equals("butmodnewcrdclick")) return BUTMODNEWCRDCLICK;
			if (s.equals("butvecviewclick")) return BUTVECVIEWCLICK;
			if (s.equals("butvecnewcrdclick")) return BUTVECNEWCRDCLICK;
			if (s.equals("butvitviewclick")) return BUTVITVIEWCLICK;
			if (s.equals("butcmdviewclick")) return BUTCMDVIEWCLICK;
			if (s.equals("butcmdnewcrdclick")) return BUTCMDNEWCRDCLICK;
			if (s.equals("buterrviewclick")) return BUTERRVIEWCLICK;
			if (s.equals("buterrnewcrdclick")) return BUTERRNEWCRDCLICK;
			if (s.equals("butpplviewclick")) return BUTPPLVIEWCLICK;
			if (s.equals("butpplnewcrdclick")) return BUTPPLNEWCRDCLICK;
			if (s.equals("butsegviewclick")) return BUTSEGVIEWCLICK;
			if (s.equals("butsegnewcrdclick")) return BUTSEGNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTPPHVIEWCLICK) return("ButPphViewClick");
			if (ix == BUTPPHNEWCRDCLICK) return("ButPphNewcrdClick");
			if (ix == BUTMODVIEWCLICK) return("ButModViewClick");
			if (ix == BUTMODNEWCRDCLICK) return("ButModNewcrdClick");
			if (ix == BUTVECVIEWCLICK) return("ButVecViewClick");
			if (ix == BUTVECNEWCRDCLICK) return("ButVecNewcrdClick");
			if (ix == BUTVITVIEWCLICK) return("ButVitViewClick");
			if (ix == BUTCMDVIEWCLICK) return("ButCmdViewClick");
			if (ix == BUTCMDNEWCRDCLICK) return("ButCmdNewcrdClick");
			if (ix == BUTERRVIEWCLICK) return("ButErrViewClick");
			if (ix == BUTERRNEWCRDCLICK) return("ButErrNewcrdClick");
			if (ix == BUTPPLVIEWCLICK) return("ButPplViewClick");
			if (ix == BUTPPLNEWCRDCLICK) return("ButPplNewcrdClick");
			if (ix == BUTSEGVIEWCLICK) return("ButSegViewClick");
			if (ix == BUTSEGNEWCRDCLICK) return("ButSegNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeNavHigh)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTPPH = 1;
		public static final int NUMFLSTMOD = 2;
		public static final int NUMFLSTVEC = 3;
		public static final int NUMFLSTVIT = 4;
		public static final int NUMFLSTCMD = 5;
		public static final int NUMFLSTERR = 6;
		public static final int NUMFLSTPPL = 7;
		public static final int NUMFLSTSEG = 8;

		public ContIac(
					int numFLstPph
					, int numFLstMod
					, int numFLstVec
					, int numFLstVit
					, int numFLstCmd
					, int numFLstErr
					, int numFLstPpl
					, int numFLstSeg
				) {
			this.numFLstPph = numFLstPph;
			this.numFLstMod = numFLstMod;
			this.numFLstVec = numFLstVec;
			this.numFLstVit = numFLstVit;
			this.numFLstCmd = numFLstCmd;
			this.numFLstErr = numFLstErr;
			this.numFLstPpl = numFLstPpl;
			this.numFLstSeg = numFLstSeg;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTPPH, NUMFLSTMOD, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCMD, NUMFLSTERR, NUMFLSTPPL, NUMFLSTSEG));
		};

		public int numFLstPph;
		public int numFLstMod;
		public int numFLstVec;
		public int numFLstVit;
		public int numFLstCmd;
		public int numFLstErr;
		public int numFLstPpl;
		public int numFLstSeg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeNavHigh");

			String itemtag = "ContitemIacWdbeNavHigh";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstPph = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPph", mask, NUMFLSTPPH);
				numFLstMod = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstMod", mask, NUMFLSTMOD);
				numFLstVec = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVec", mask, NUMFLSTVEC);
				numFLstVit = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVit", mask, NUMFLSTVIT);
				numFLstCmd = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstCmd", mask, NUMFLSTCMD);
				numFLstErr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstErr", mask, NUMFLSTERR);
				numFLstPpl = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPpl", mask, NUMFLSTPPL);
				numFLstSeg = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSeg", mask, NUMFLSTSEG);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeNavHigh";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeNavHigh";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPph", numFLstPph);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstMod", numFLstMod);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVec", numFLstVec);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVit", numFLstVit);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstCmd", numFLstCmd);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstErr", numFLstErr);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPpl", numFLstPpl);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSeg", numFLstSeg);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstPph == comp.numFLstPph) items.add(NUMFLSTPPH);
			if (numFLstMod == comp.numFLstMod) items.add(NUMFLSTMOD);
			if (numFLstVec == comp.numFLstVec) items.add(NUMFLSTVEC);
			if (numFLstVit == comp.numFLstVit) items.add(NUMFLSTVIT);
			if (numFLstCmd == comp.numFLstCmd) items.add(NUMFLSTCMD);
			if (numFLstErr == comp.numFLstErr) items.add(NUMFLSTERR);
			if (numFLstPpl == comp.numFLstPpl) items.add(NUMFLSTPPL);
			if (numFLstSeg == comp.numFLstSeg) items.add(NUMFLSTSEG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTPPH, NUMFLSTMOD, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCMD, NUMFLSTERR, NUMFLSTPPL, NUMFLSTSEG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeNavHigh)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTPPHALT = 2;
		public static final int LSTMODALT = 3;
		public static final int LSTVECALT = 4;
		public static final int LSTVITALT = 5;
		public static final int LSTCMDALT = 6;
		public static final int LSTERRALT = 7;
		public static final int LSTPPLALT = 8;
		public static final int LSTSEGALT = 9;
		public static final int LSTPPHNUMFIRSTDISP = 10;
		public static final int LSTMODNUMFIRSTDISP = 11;
		public static final int LSTVECNUMFIRSTDISP = 12;
		public static final int LSTVITNUMFIRSTDISP = 13;
		public static final int LSTCMDNUMFIRSTDISP = 14;
		public static final int LSTERRNUMFIRSTDISP = 15;
		public static final int LSTPPLNUMFIRSTDISP = 16;
		public static final int LSTSEGNUMFIRSTDISP = 17;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstPphAlt
					, boolean LstModAlt
					, boolean LstVecAlt
					, boolean LstVitAlt
					, boolean LstCmdAlt
					, boolean LstErrAlt
					, boolean LstPplAlt
					, boolean LstSegAlt
					, int LstPphNumFirstdisp
					, int LstModNumFirstdisp
					, int LstVecNumFirstdisp
					, int LstVitNumFirstdisp
					, int LstCmdNumFirstdisp
					, int LstErrNumFirstdisp
					, int LstPplNumFirstdisp
					, int LstSegNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstPphAlt = LstPphAlt;
			this.LstModAlt = LstModAlt;
			this.LstVecAlt = LstVecAlt;
			this.LstVitAlt = LstVitAlt;
			this.LstCmdAlt = LstCmdAlt;
			this.LstErrAlt = LstErrAlt;
			this.LstPplAlt = LstPplAlt;
			this.LstSegAlt = LstSegAlt;
			this.LstPphNumFirstdisp = LstPphNumFirstdisp;
			this.LstModNumFirstdisp = LstModNumFirstdisp;
			this.LstVecNumFirstdisp = LstVecNumFirstdisp;
			this.LstVitNumFirstdisp = LstVitNumFirstdisp;
			this.LstCmdNumFirstdisp = LstCmdNumFirstdisp;
			this.LstErrNumFirstdisp = LstErrNumFirstdisp;
			this.LstPplNumFirstdisp = LstPplNumFirstdisp;
			this.LstSegNumFirstdisp = LstSegNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTPPHALT, LSTMODALT, LSTVECALT, LSTVITALT, LSTCMDALT, LSTERRALT, LSTPPLALT, LSTSEGALT, LSTPPHNUMFIRSTDISP, LSTMODNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCMDNUMFIRSTDISP, LSTERRNUMFIRSTDISP, LSTPPLNUMFIRSTDISP, LSTSEGNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstPphAlt;
		public boolean LstModAlt;
		public boolean LstVecAlt;
		public boolean LstVitAlt;
		public boolean LstCmdAlt;
		public boolean LstErrAlt;
		public boolean LstPplAlt;
		public boolean LstSegAlt;
		public int LstPphNumFirstdisp;
		public int LstModNumFirstdisp;
		public int LstVecNumFirstdisp;
		public int LstVitNumFirstdisp;
		public int LstCmdNumFirstdisp;
		public int LstErrNumFirstdisp;
		public int LstPplNumFirstdisp;
		public int LstSegNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeNavHigh");

			String itemtag = "StatitemAppWdbeNavHigh";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstPphAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPphAlt", mask, LSTPPHALT);
				LstModAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstModAlt", mask, LSTMODALT);
				LstVecAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVecAlt", mask, LSTVECALT);
				LstVitAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVitAlt", mask, LSTVITALT);
				LstCmdAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCmdAlt", mask, LSTCMDALT);
				LstErrAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstErrAlt", mask, LSTERRALT);
				LstPplAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPplAlt", mask, LSTPPLALT);
				LstSegAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSegAlt", mask, LSTSEGALT);
				LstPphNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPphNumFirstdisp", mask, LSTPPHNUMFIRSTDISP);
				LstModNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstModNumFirstdisp", mask, LSTMODNUMFIRSTDISP);
				LstVecNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVecNumFirstdisp", mask, LSTVECNUMFIRSTDISP);
				LstVitNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVitNumFirstdisp", mask, LSTVITNUMFIRSTDISP);
				LstCmdNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCmdNumFirstdisp", mask, LSTCMDNUMFIRSTDISP);
				LstErrNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstErrNumFirstdisp", mask, LSTERRNUMFIRSTDISP);
				LstPplNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPplNumFirstdisp", mask, LSTPPLNUMFIRSTDISP);
				LstSegNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSegNumFirstdisp", mask, LSTSEGNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstPphAlt == comp.LstPphAlt) items.add(LSTPPHALT);
			if (LstModAlt == comp.LstModAlt) items.add(LSTMODALT);
			if (LstVecAlt == comp.LstVecAlt) items.add(LSTVECALT);
			if (LstVitAlt == comp.LstVitAlt) items.add(LSTVITALT);
			if (LstCmdAlt == comp.LstCmdAlt) items.add(LSTCMDALT);
			if (LstErrAlt == comp.LstErrAlt) items.add(LSTERRALT);
			if (LstPplAlt == comp.LstPplAlt) items.add(LSTPPLALT);
			if (LstSegAlt == comp.LstSegAlt) items.add(LSTSEGALT);
			if (LstPphNumFirstdisp == comp.LstPphNumFirstdisp) items.add(LSTPPHNUMFIRSTDISP);
			if (LstModNumFirstdisp == comp.LstModNumFirstdisp) items.add(LSTMODNUMFIRSTDISP);
			if (LstVecNumFirstdisp == comp.LstVecNumFirstdisp) items.add(LSTVECNUMFIRSTDISP);
			if (LstVitNumFirstdisp == comp.LstVitNumFirstdisp) items.add(LSTVITNUMFIRSTDISP);
			if (LstCmdNumFirstdisp == comp.LstCmdNumFirstdisp) items.add(LSTCMDNUMFIRSTDISP);
			if (LstErrNumFirstdisp == comp.LstErrNumFirstdisp) items.add(LSTERRNUMFIRSTDISP);
			if (LstPplNumFirstdisp == comp.LstPplNumFirstdisp) items.add(LSTPPLNUMFIRSTDISP);
			if (LstSegNumFirstdisp == comp.LstSegNumFirstdisp) items.add(LSTSEGNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTPPHALT, LSTMODALT, LSTVECALT, LSTVITALT, LSTCMDALT, LSTERRALT, LSTPPLALT, LSTSEGALT, LSTPPHNUMFIRSTDISP, LSTMODNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCMDNUMFIRSTDISP, LSTERRNUMFIRSTDISP, LSTPPLNUMFIRSTDISP, LSTSEGNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeNavHigh)
	  */
	public class StatShr extends Block {

		public static final int LSTPPHAVAIL = 1;
		public static final int BUTPPHVIEWACTIVE = 2;
		public static final int BUTPPHNEWCRDACTIVE = 3;
		public static final int LSTMODAVAIL = 4;
		public static final int BUTMODVIEWACTIVE = 5;
		public static final int BUTMODNEWCRDACTIVE = 6;
		public static final int LSTVECAVAIL = 7;
		public static final int BUTVECVIEWACTIVE = 8;
		public static final int BUTVECNEWCRDACTIVE = 9;
		public static final int LSTVITAVAIL = 10;
		public static final int BUTVITVIEWACTIVE = 11;
		public static final int LSTCMDAVAIL = 12;
		public static final int BUTCMDVIEWACTIVE = 13;
		public static final int BUTCMDNEWCRDACTIVE = 14;
		public static final int LSTERRAVAIL = 15;
		public static final int BUTERRVIEWACTIVE = 16;
		public static final int BUTERRNEWCRDACTIVE = 17;
		public static final int LSTPPLAVAIL = 18;
		public static final int BUTPPLVIEWACTIVE = 19;
		public static final int BUTPPLNEWCRDACTIVE = 20;
		public static final int LSTSEGAVAIL = 21;
		public static final int BUTSEGVIEWACTIVE = 22;
		public static final int BUTSEGNEWCRDACTIVE = 23;

		public StatShr(
					boolean LstPphAvail
					, boolean ButPphViewActive
					, boolean ButPphNewcrdActive
					, boolean LstModAvail
					, boolean ButModViewActive
					, boolean ButModNewcrdActive
					, boolean LstVecAvail
					, boolean ButVecViewActive
					, boolean ButVecNewcrdActive
					, boolean LstVitAvail
					, boolean ButVitViewActive
					, boolean LstCmdAvail
					, boolean ButCmdViewActive
					, boolean ButCmdNewcrdActive
					, boolean LstErrAvail
					, boolean ButErrViewActive
					, boolean ButErrNewcrdActive
					, boolean LstPplAvail
					, boolean ButPplViewActive
					, boolean ButPplNewcrdActive
					, boolean LstSegAvail
					, boolean ButSegViewActive
					, boolean ButSegNewcrdActive
				) {
			this.LstPphAvail = LstPphAvail;
			this.ButPphViewActive = ButPphViewActive;
			this.ButPphNewcrdActive = ButPphNewcrdActive;
			this.LstModAvail = LstModAvail;
			this.ButModViewActive = ButModViewActive;
			this.ButModNewcrdActive = ButModNewcrdActive;
			this.LstVecAvail = LstVecAvail;
			this.ButVecViewActive = ButVecViewActive;
			this.ButVecNewcrdActive = ButVecNewcrdActive;
			this.LstVitAvail = LstVitAvail;
			this.ButVitViewActive = ButVitViewActive;
			this.LstCmdAvail = LstCmdAvail;
			this.ButCmdViewActive = ButCmdViewActive;
			this.ButCmdNewcrdActive = ButCmdNewcrdActive;
			this.LstErrAvail = LstErrAvail;
			this.ButErrViewActive = ButErrViewActive;
			this.ButErrNewcrdActive = ButErrNewcrdActive;
			this.LstPplAvail = LstPplAvail;
			this.ButPplViewActive = ButPplViewActive;
			this.ButPplNewcrdActive = ButPplNewcrdActive;
			this.LstSegAvail = LstSegAvail;
			this.ButSegViewActive = ButSegViewActive;
			this.ButSegNewcrdActive = ButSegNewcrdActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTPPHAVAIL, BUTPPHVIEWACTIVE, BUTPPHNEWCRDACTIVE, LSTMODAVAIL, BUTMODVIEWACTIVE, BUTMODNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, LSTCMDAVAIL, BUTCMDVIEWACTIVE, BUTCMDNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE, LSTPPLAVAIL, BUTPPLVIEWACTIVE, BUTPPLNEWCRDACTIVE, LSTSEGAVAIL, BUTSEGVIEWACTIVE, BUTSEGNEWCRDACTIVE));
		};

		public boolean LstPphAvail;
		public boolean ButPphViewActive;
		public boolean ButPphNewcrdActive;
		public boolean LstModAvail;
		public boolean ButModViewActive;
		public boolean ButModNewcrdActive;
		public boolean LstVecAvail;
		public boolean ButVecViewActive;
		public boolean ButVecNewcrdActive;
		public boolean LstVitAvail;
		public boolean ButVitViewActive;
		public boolean LstCmdAvail;
		public boolean ButCmdViewActive;
		public boolean ButCmdNewcrdActive;
		public boolean LstErrAvail;
		public boolean ButErrViewActive;
		public boolean ButErrNewcrdActive;
		public boolean LstPplAvail;
		public boolean ButPplViewActive;
		public boolean ButPplNewcrdActive;
		public boolean LstSegAvail;
		public boolean ButSegViewActive;
		public boolean ButSegNewcrdActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNavHigh");

			String itemtag = "StatitemShrWdbeNavHigh";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstPphAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPphAvail", mask, LSTPPHAVAIL);
				ButPphViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPphViewActive", mask, BUTPPHVIEWACTIVE);
				ButPphNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPphNewcrdActive", mask, BUTPPHNEWCRDACTIVE);
				LstModAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstModAvail", mask, LSTMODAVAIL);
				ButModViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButModViewActive", mask, BUTMODVIEWACTIVE);
				ButModNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButModNewcrdActive", mask, BUTMODNEWCRDACTIVE);
				LstVecAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVecAvail", mask, LSTVECAVAIL);
				ButVecViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVecViewActive", mask, BUTVECVIEWACTIVE);
				ButVecNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVecNewcrdActive", mask, BUTVECNEWCRDACTIVE);
				LstVitAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVitAvail", mask, LSTVITAVAIL);
				ButVitViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVitViewActive", mask, BUTVITVIEWACTIVE);
				LstCmdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCmdAvail", mask, LSTCMDAVAIL);
				ButCmdViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCmdViewActive", mask, BUTCMDVIEWACTIVE);
				ButCmdNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCmdNewcrdActive", mask, BUTCMDNEWCRDACTIVE);
				LstErrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstErrAvail", mask, LSTERRAVAIL);
				ButErrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButErrViewActive", mask, BUTERRVIEWACTIVE);
				ButErrNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButErrNewcrdActive", mask, BUTERRNEWCRDACTIVE);
				LstPplAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPplAvail", mask, LSTPPLAVAIL);
				ButPplViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPplViewActive", mask, BUTPPLVIEWACTIVE);
				ButPplNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPplNewcrdActive", mask, BUTPPLNEWCRDACTIVE);
				LstSegAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSegAvail", mask, LSTSEGAVAIL);
				ButSegViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSegViewActive", mask, BUTSEGVIEWACTIVE);
				ButSegNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSegNewcrdActive", mask, BUTSEGNEWCRDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstPphAvail == comp.LstPphAvail) items.add(LSTPPHAVAIL);
			if (ButPphViewActive == comp.ButPphViewActive) items.add(BUTPPHVIEWACTIVE);
			if (ButPphNewcrdActive == comp.ButPphNewcrdActive) items.add(BUTPPHNEWCRDACTIVE);
			if (LstModAvail == comp.LstModAvail) items.add(LSTMODAVAIL);
			if (ButModViewActive == comp.ButModViewActive) items.add(BUTMODVIEWACTIVE);
			if (ButModNewcrdActive == comp.ButModNewcrdActive) items.add(BUTMODNEWCRDACTIVE);
			if (LstVecAvail == comp.LstVecAvail) items.add(LSTVECAVAIL);
			if (ButVecViewActive == comp.ButVecViewActive) items.add(BUTVECVIEWACTIVE);
			if (ButVecNewcrdActive == comp.ButVecNewcrdActive) items.add(BUTVECNEWCRDACTIVE);
			if (LstVitAvail == comp.LstVitAvail) items.add(LSTVITAVAIL);
			if (ButVitViewActive == comp.ButVitViewActive) items.add(BUTVITVIEWACTIVE);
			if (LstCmdAvail == comp.LstCmdAvail) items.add(LSTCMDAVAIL);
			if (ButCmdViewActive == comp.ButCmdViewActive) items.add(BUTCMDVIEWACTIVE);
			if (ButCmdNewcrdActive == comp.ButCmdNewcrdActive) items.add(BUTCMDNEWCRDACTIVE);
			if (LstErrAvail == comp.LstErrAvail) items.add(LSTERRAVAIL);
			if (ButErrViewActive == comp.ButErrViewActive) items.add(BUTERRVIEWACTIVE);
			if (ButErrNewcrdActive == comp.ButErrNewcrdActive) items.add(BUTERRNEWCRDACTIVE);
			if (LstPplAvail == comp.LstPplAvail) items.add(LSTPPLAVAIL);
			if (ButPplViewActive == comp.ButPplViewActive) items.add(BUTPPLVIEWACTIVE);
			if (ButPplNewcrdActive == comp.ButPplNewcrdActive) items.add(BUTPPLNEWCRDACTIVE);
			if (LstSegAvail == comp.LstSegAvail) items.add(LSTSEGAVAIL);
			if (ButSegViewActive == comp.ButSegViewActive) items.add(BUTSEGVIEWACTIVE);
			if (ButSegNewcrdActive == comp.ButSegNewcrdActive) items.add(BUTSEGNEWCRDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTPPHAVAIL, BUTPPHVIEWACTIVE, BUTPPHNEWCRDACTIVE, LSTMODAVAIL, BUTMODVIEWACTIVE, BUTMODNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, LSTCMDAVAIL, BUTCMDVIEWACTIVE, BUTCMDNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE, LSTPPLAVAIL, BUTPPLVIEWACTIVE, BUTPPLNEWCRDACTIVE, LSTSEGAVAIL, BUTSEGVIEWACTIVE, BUTSEGNEWCRDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNavHigh)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTPPH = 2;
		public static final int CPTMOD = 3;
		public static final int CPTVEC = 4;
		public static final int CPTVIT = 5;
		public static final int CPTCMD = 6;
		public static final int CPTERR = 7;
		public static final int CPTPPL = 8;
		public static final int CPTSEG = 9;

		public Tag(
					String Cpt
					, String CptPph
					, String CptMod
					, String CptVec
					, String CptVit
					, String CptCmd
					, String CptErr
					, String CptPpl
					, String CptSeg
				) {
			this.Cpt = Cpt;
			this.CptPph = CptPph;
			this.CptMod = CptMod;
			this.CptVec = CptVec;
			this.CptVit = CptVit;
			this.CptCmd = CptCmd;
			this.CptErr = CptErr;
			this.CptPpl = CptPpl;
			this.CptSeg = CptSeg;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTPPH, CPTMOD, CPTVEC, CPTVIT, CPTCMD, CPTERR, CPTPPL, CPTSEG));
		};

		public String Cpt;
		public String CptPph;
		public String CptMod;
		public String CptVec;
		public String CptVit;
		public String CptCmd;
		public String CptErr;
		public String CptPpl;
		public String CptSeg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNavHigh");

			String itemtag = "TagitemWdbeNavHigh";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptPph = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPph", mask, CPTPPH);
				CptMod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMod", mask, CPTMOD);
				CptVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVec", mask, CPTVEC);
				CptVit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVit", mask, CPTVIT);
				CptCmd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmd", mask, CPTCMD);
				CptErr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptErr", mask, CPTERR);
				CptPpl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPpl", mask, CPTPPL);
				CptSeg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSeg", mask, CPTSEG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptPph.equals(comp.CptPph)) items.add(CPTPPH);
			if (CptMod.equals(comp.CptMod)) items.add(CPTMOD);
			if (CptVec.equals(comp.CptVec)) items.add(CPTVEC);
			if (CptVit.equals(comp.CptVit)) items.add(CPTVIT);
			if (CptCmd.equals(comp.CptCmd)) items.add(CPTCMD);
			if (CptErr.equals(comp.CptErr)) items.add(CPTERR);
			if (CptPpl.equals(comp.CptPpl)) items.add(CPTPPL);
			if (CptSeg.equals(comp.CptSeg)) items.add(CPTSEG);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTPPH, CPTMOD, CPTVEC, CPTVIT, CPTCMD, CPTERR, CPTPPL, CPTSEG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeNavHighData)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVHIGHDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavHighData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavHighDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVHIGHDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavHighDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavHighData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTCMD = 3;
		public static final int FEEDFLSTERR = 4;
		public static final int FEEDFLSTMOD = 5;
		public static final int FEEDFLSTPPH = 6;
		public static final int FEEDFLSTPPL = 7;
		public static final int FEEDFLSTSEG = 8;
		public static final int FEEDFLSTVEC = 9;
		public static final int FEEDFLSTVIT = 10;
		public static final int STATAPP = 11;
		public static final int STATSHR = 12;
		public static final int TAG = 13;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVHIGHDATA);

			contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0);
			feedFLstCmd = new Feed("FeedFLstCmd");
			feedFLstErr = new Feed("FeedFLstErr");
			feedFLstMod = new Feed("FeedFLstMod");
			feedFLstPph = new Feed("FeedFLstPph");
			feedFLstPpl = new Feed("FeedFLstPpl");
			feedFLstSeg = new Feed("FeedFLstSeg");
			feedFLstVec = new Feed("FeedFLstVec");
			feedFLstVit = new Feed("FeedFLstVit");
			statapp = new StatApp(0, false, false, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstCmd;
		public Feed feedFLstErr;
		public Feed feedFLstMod;
		public Feed feedFLstPph;
		public Feed feedFLstPpl;
		public Feed feedFLstSeg;
		public Feed feedFLstVec;
		public Feed feedFLstVit;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTCMD)) ss.add("feedFLstCmd");
			if (has(FEEDFLSTERR)) ss.add("feedFLstErr");
			if (has(FEEDFLSTMOD)) ss.add("feedFLstMod");
			if (has(FEEDFLSTPPH)) ss.add("feedFLstPph");
			if (has(FEEDFLSTPPL)) ss.add("feedFLstPpl");
			if (has(FEEDFLSTSEG)) ss.add("feedFLstSeg");
			if (has(FEEDFLSTVEC)) ss.add("feedFLstVec");
			if (has(FEEDFLSTVIT)) ss.add("feedFLstVit");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavHighData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstCmd.readXML(doc, basexpath, true)) add(FEEDFLSTCMD);
				if (feedFLstErr.readXML(doc, basexpath, true)) add(FEEDFLSTERR);
				if (feedFLstMod.readXML(doc, basexpath, true)) add(FEEDFLSTMOD);
				if (feedFLstPph.readXML(doc, basexpath, true)) add(FEEDFLSTPPH);
				if (feedFLstPpl.readXML(doc, basexpath, true)) add(FEEDFLSTPPL);
				if (feedFLstSeg.readXML(doc, basexpath, true)) add(FEEDFLSTSEG);
				if (feedFLstVec.readXML(doc, basexpath, true)) add(FEEDFLSTVEC);
				if (feedFLstVit.readXML(doc, basexpath, true)) add(FEEDFLSTVIT);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0);
				feedFLstCmd = new Feed("FeedFLstCmd");
				feedFLstErr = new Feed("FeedFLstErr");
				feedFLstMod = new Feed("FeedFLstMod");
				feedFLstPph = new Feed("FeedFLstPph");
				feedFLstPpl = new Feed("FeedFLstPpl");
				feedFLstSeg = new Feed("FeedFLstSeg");
				feedFLstVec = new Feed("FeedFLstVec");
				feedFLstVit = new Feed("FeedFLstVit");
				statapp = new StatApp(0, false, false, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "");
			};
		};

	};

};
