/**
  * \file CrdWdbeVer.java
  * Java API code for job CrdWdbeVer
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdWdbeVer {
	/**
		* VecVDo (full: VecVWdbeVerDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;
		public static final int MITCRDNEWCLICK = 3;
		public static final int MITCRDPCVCLICK = 4;
		public static final int MITCRDIMDCLICK = 5;
		public static final int MITCRDICSCLICK = 6;
		public static final int MITCRDIDACLICK = 7;
		public static final int MITCRDGFSCLICK = 8;
		public static final int MITCRDIFSCLICK = 9;
		public static final int MITCRDFNMCLICK = 10;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;
			if (s.equals("mitcrdnewclick")) return MITCRDNEWCLICK;
			if (s.equals("mitcrdpcvclick")) return MITCRDPCVCLICK;
			if (s.equals("mitcrdimdclick")) return MITCRDIMDCLICK;
			if (s.equals("mitcrdicsclick")) return MITCRDICSCLICK;
			if (s.equals("mitcrdidaclick")) return MITCRDIDACLICK;
			if (s.equals("mitcrdgfsclick")) return MITCRDGFSCLICK;
			if (s.equals("mitcrdifsclick")) return MITCRDIFSCLICK;
			if (s.equals("mitcrdfnmclick")) return MITCRDFNMCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
			if (ix == MITCRDNEWCLICK) return("MitCrdNewClick");
			if (ix == MITCRDPCVCLICK) return("MitCrdPcvClick");
			if (ix == MITCRDIMDCLICK) return("MitCrdImdClick");
			if (ix == MITCRDICSCLICK) return("MitCrdIcsClick");
			if (ix == MITCRDIDACLICK) return("MitCrdIdaClick");
			if (ix == MITCRDGFSCLICK) return("MitCrdGfsClick");
			if (ix == MITCRDIFSCLICK) return("MitCrdIfsClick");
			if (ix == MITCRDFNMCLICK) return("MitCrdFnmClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVWdbeVerSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRWDBEABT = 2;
		public static final int ALRCVW = 3;
		public static final int SETPRJCVR = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrwdbeabt")) return ALRWDBEABT;
			if (s.equals("alrcvw")) return ALRCVW;
			if (s.equals("setprjcvr")) return SETPRJCVR;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRWDBEABT) return("alrwdbeabt");
			if (ix == ALRCVW) return("alrcvw");
			if (ix == SETPRJCVR) return("setprjcvr");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWdbeVer)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MTXCRDVER = 3;

		public ContInf(
					int numFSge
					, String MrlAppHlp
					, String MtxCrdVer
				) {
			this.numFSge = numFSge;
			this.MrlAppHlp = MrlAppHlp;
			this.MtxCrdVer = MtxCrdVer;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXCRDVER));
		};

		public int numFSge;
		public String MrlAppHlp;
		public String MtxCrdVer;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeVer");

			String itemtag = "ContitemInfWdbeVer";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MtxCrdVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxCrdVer", mask, MTXCRDVER);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);
			if (MrlAppHlp.equals(comp.MrlAppHlp)) items.add(MRLAPPHLP);
			if (MtxCrdVer.equals(comp.MtxCrdVer)) items.add(MTXCRDVER);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXCRDVER));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeVer)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONEHEADBAR = 5;
		public static final int INITDONELIST = 6;
		public static final int INITDONEREC = 7;

		public StatApp(
					int ixWdbeVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneHeadbar
					, boolean initdoneList
					, boolean initdoneRec
				) {
			this.ixWdbeVReqitmode = ixWdbeVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneHeadbar = initdoneHeadbar;
			this.initdoneList = initdoneList;
			this.initdoneRec = initdoneRec;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC));
		};

		public int ixWdbeVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneHeadbar;
		public boolean initdoneList;
		public boolean initdoneRec;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeVer");

			String itemtag = "StatitemAppWdbeVer";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVReqitmode", mask, IXWDBEVREQITMODE);
				ixWdbeVReqitmode = VecWdbeVReqitmode.getIx(srefIxWdbeVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneHeadbar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", mask, INITDONEHEADBAR);
				initdoneList = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneList", mask, INITDONELIST);
				initdoneRec = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRec", mask, INITDONEREC);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVReqitmode == comp.ixWdbeVReqitmode) items.add(IXWDBEVREQITMODE);
			if (latency == comp.latency) items.add(LATENCY);
			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);
			if (widthMenu == comp.widthMenu) items.add(WIDTHMENU);
			if (initdoneHeadbar == comp.initdoneHeadbar) items.add(INITDONEHEADBAR);
			if (initdoneList == comp.initdoneList) items.add(INITDONELIST);
			if (initdoneRec == comp.initdoneRec) items.add(INITDONEREC);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONELIST, INITDONEREC));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeVer)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFDLGCMDSET = 1;
		public static final int SCRJREFDLGCUSTFST = 2;
		public static final int SCRJREFDLGDFLALG = 3;
		public static final int SCRJREFDLGFINMOD = 4;
		public static final int SCRJREFDLGGENFST = 5;
		public static final int SCRJREFDLGMDLSTR = 6;
		public static final int SCRJREFDLGNEW = 7;
		public static final int SCRJREFHEADBAR = 8;
		public static final int SCRJREFLIST = 9;
		public static final int SCRJREFREC = 10;
		public static final int MSPCRD1AVAIL = 11;
		public static final int MITCRDNEWAVAIL = 12;
		public static final int MITCRDPCVAVAIL = 13;
		public static final int MITCRDPCVACTIVE = 14;
		public static final int MSPCRD3AVAIL = 15;
		public static final int MSPCRD3ACTIVE = 16;
		public static final int MITCRDIMDAVAIL = 17;
		public static final int MITCRDIMDACTIVE = 18;
		public static final int MITCRDICSAVAIL = 19;
		public static final int MITCRDICSACTIVE = 20;
		public static final int MITCRDIDAAVAIL = 21;
		public static final int MITCRDIDAACTIVE = 22;
		public static final int MSPCRD4AVAIL = 23;
		public static final int MSPCRD4ACTIVE = 24;
		public static final int MITCRDGFSAVAIL = 25;
		public static final int MITCRDGFSACTIVE = 26;
		public static final int MITCRDIFSAVAIL = 27;
		public static final int MITCRDIFSACTIVE = 28;
		public static final int MSPCRD5AVAIL = 29;
		public static final int MSPCRD5ACTIVE = 30;
		public static final int MITCRDFNMAVAIL = 31;
		public static final int MITCRDFNMACTIVE = 32;

		public StatShr(
					String scrJrefDlgcmdset
					, String scrJrefDlgcustfst
					, String scrJrefDlgdflalg
					, String scrJrefDlgfinmod
					, String scrJrefDlggenfst
					, String scrJrefDlgmdlstr
					, String scrJrefDlgnew
					, String scrJrefHeadbar
					, String scrJrefList
					, String scrJrefRec
					, boolean MspCrd1Avail
					, boolean MitCrdNewAvail
					, boolean MitCrdPcvAvail
					, boolean MitCrdPcvActive
					, boolean MspCrd3Avail
					, boolean MspCrd3Active
					, boolean MitCrdImdAvail
					, boolean MitCrdImdActive
					, boolean MitCrdIcsAvail
					, boolean MitCrdIcsActive
					, boolean MitCrdIdaAvail
					, boolean MitCrdIdaActive
					, boolean MspCrd4Avail
					, boolean MspCrd4Active
					, boolean MitCrdGfsAvail
					, boolean MitCrdGfsActive
					, boolean MitCrdIfsAvail
					, boolean MitCrdIfsActive
					, boolean MspCrd5Avail
					, boolean MspCrd5Active
					, boolean MitCrdFnmAvail
					, boolean MitCrdFnmActive
				) {
			this.scrJrefDlgcmdset = scrJrefDlgcmdset;
			this.scrJrefDlgcustfst = scrJrefDlgcustfst;
			this.scrJrefDlgdflalg = scrJrefDlgdflalg;
			this.scrJrefDlgfinmod = scrJrefDlgfinmod;
			this.scrJrefDlggenfst = scrJrefDlggenfst;
			this.scrJrefDlgmdlstr = scrJrefDlgmdlstr;
			this.scrJrefDlgnew = scrJrefDlgnew;
			this.scrJrefHeadbar = scrJrefHeadbar;
			this.scrJrefList = scrJrefList;
			this.scrJrefRec = scrJrefRec;
			this.MspCrd1Avail = MspCrd1Avail;
			this.MitCrdNewAvail = MitCrdNewAvail;
			this.MitCrdPcvAvail = MitCrdPcvAvail;
			this.MitCrdPcvActive = MitCrdPcvActive;
			this.MspCrd3Avail = MspCrd3Avail;
			this.MspCrd3Active = MspCrd3Active;
			this.MitCrdImdAvail = MitCrdImdAvail;
			this.MitCrdImdActive = MitCrdImdActive;
			this.MitCrdIcsAvail = MitCrdIcsAvail;
			this.MitCrdIcsActive = MitCrdIcsActive;
			this.MitCrdIdaAvail = MitCrdIdaAvail;
			this.MitCrdIdaActive = MitCrdIdaActive;
			this.MspCrd4Avail = MspCrd4Avail;
			this.MspCrd4Active = MspCrd4Active;
			this.MitCrdGfsAvail = MitCrdGfsAvail;
			this.MitCrdGfsActive = MitCrdGfsActive;
			this.MitCrdIfsAvail = MitCrdIfsAvail;
			this.MitCrdIfsActive = MitCrdIfsActive;
			this.MspCrd5Avail = MspCrd5Avail;
			this.MspCrd5Active = MspCrd5Active;
			this.MitCrdFnmAvail = MitCrdFnmAvail;
			this.MitCrdFnmActive = MitCrdFnmActive;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFDLGCMDSET, SCRJREFDLGCUSTFST, SCRJREFDLGDFLALG, SCRJREFDLGFINMOD, SCRJREFDLGGENFST, SCRJREFDLGMDLSTR, SCRJREFDLGNEW, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MSPCRD3ACTIVE, MITCRDIMDAVAIL, MITCRDIMDACTIVE, MITCRDICSAVAIL, MITCRDICSACTIVE, MITCRDIDAAVAIL, MITCRDIDAACTIVE, MSPCRD4AVAIL, MSPCRD4ACTIVE, MITCRDGFSAVAIL, MITCRDGFSACTIVE, MITCRDIFSAVAIL, MITCRDIFSACTIVE, MSPCRD5AVAIL, MSPCRD5ACTIVE, MITCRDFNMAVAIL, MITCRDFNMACTIVE));
		};

		public String scrJrefDlgcmdset;
		public String scrJrefDlgcustfst;
		public String scrJrefDlgdflalg;
		public String scrJrefDlgfinmod;
		public String scrJrefDlggenfst;
		public String scrJrefDlgmdlstr;
		public String scrJrefDlgnew;
		public String scrJrefHeadbar;
		public String scrJrefList;
		public String scrJrefRec;
		public boolean MspCrd1Avail;
		public boolean MitCrdNewAvail;
		public boolean MitCrdPcvAvail;
		public boolean MitCrdPcvActive;
		public boolean MspCrd3Avail;
		public boolean MspCrd3Active;
		public boolean MitCrdImdAvail;
		public boolean MitCrdImdActive;
		public boolean MitCrdIcsAvail;
		public boolean MitCrdIcsActive;
		public boolean MitCrdIdaAvail;
		public boolean MitCrdIdaActive;
		public boolean MspCrd4Avail;
		public boolean MspCrd4Active;
		public boolean MitCrdGfsAvail;
		public boolean MitCrdGfsActive;
		public boolean MitCrdIfsAvail;
		public boolean MitCrdIfsActive;
		public boolean MspCrd5Avail;
		public boolean MspCrd5Active;
		public boolean MitCrdFnmAvail;
		public boolean MitCrdFnmActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeVer");

			String itemtag = "StatitemShrWdbeVer";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefDlgcmdset = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgcmdset", mask, SCRJREFDLGCMDSET);
				scrJrefDlgcustfst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgcustfst", mask, SCRJREFDLGCUSTFST);
				scrJrefDlgdflalg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgdflalg", mask, SCRJREFDLGDFLALG);
				scrJrefDlgfinmod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgfinmod", mask, SCRJREFDLGFINMOD);
				scrJrefDlggenfst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlggenfst", mask, SCRJREFDLGGENFST);
				scrJrefDlgmdlstr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgmdlstr", mask, SCRJREFDLGMDLSTR);
				scrJrefDlgnew = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgnew", mask, SCRJREFDLGNEW);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);
				scrJrefList = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefList", mask, SCRJREFLIST);
				scrJrefRec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRec", mask, SCRJREFREC);
				MspCrd1Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", mask, MSPCRD1AVAIL);
				MitCrdNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdNewAvail", mask, MITCRDNEWAVAIL);
				MitCrdPcvAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPcvAvail", mask, MITCRDPCVAVAIL);
				MitCrdPcvActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPcvActive", mask, MITCRDPCVACTIVE);
				MspCrd3Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd3Avail", mask, MSPCRD3AVAIL);
				MspCrd3Active = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd3Active", mask, MSPCRD3ACTIVE);
				MitCrdImdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdImdAvail", mask, MITCRDIMDAVAIL);
				MitCrdImdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdImdActive", mask, MITCRDIMDACTIVE);
				MitCrdIcsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIcsAvail", mask, MITCRDICSAVAIL);
				MitCrdIcsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIcsActive", mask, MITCRDICSACTIVE);
				MitCrdIdaAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIdaAvail", mask, MITCRDIDAAVAIL);
				MitCrdIdaActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIdaActive", mask, MITCRDIDAACTIVE);
				MspCrd4Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd4Avail", mask, MSPCRD4AVAIL);
				MspCrd4Active = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd4Active", mask, MSPCRD4ACTIVE);
				MitCrdGfsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdGfsAvail", mask, MITCRDGFSAVAIL);
				MitCrdGfsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdGfsActive", mask, MITCRDGFSACTIVE);
				MitCrdIfsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIfsAvail", mask, MITCRDIFSAVAIL);
				MitCrdIfsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIfsActive", mask, MITCRDIFSACTIVE);
				MspCrd5Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd5Avail", mask, MSPCRD5AVAIL);
				MspCrd5Active = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd5Active", mask, MSPCRD5ACTIVE);
				MitCrdFnmAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdFnmAvail", mask, MITCRDFNMAVAIL);
				MitCrdFnmActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdFnmActive", mask, MITCRDFNMACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefDlgcmdset.equals(comp.scrJrefDlgcmdset)) items.add(SCRJREFDLGCMDSET);
			if (scrJrefDlgcustfst.equals(comp.scrJrefDlgcustfst)) items.add(SCRJREFDLGCUSTFST);
			if (scrJrefDlgdflalg.equals(comp.scrJrefDlgdflalg)) items.add(SCRJREFDLGDFLALG);
			if (scrJrefDlgfinmod.equals(comp.scrJrefDlgfinmod)) items.add(SCRJREFDLGFINMOD);
			if (scrJrefDlggenfst.equals(comp.scrJrefDlggenfst)) items.add(SCRJREFDLGGENFST);
			if (scrJrefDlgmdlstr.equals(comp.scrJrefDlgmdlstr)) items.add(SCRJREFDLGMDLSTR);
			if (scrJrefDlgnew.equals(comp.scrJrefDlgnew)) items.add(SCRJREFDLGNEW);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);
			if (scrJrefList.equals(comp.scrJrefList)) items.add(SCRJREFLIST);
			if (scrJrefRec.equals(comp.scrJrefRec)) items.add(SCRJREFREC);
			if (MspCrd1Avail == comp.MspCrd1Avail) items.add(MSPCRD1AVAIL);
			if (MitCrdNewAvail == comp.MitCrdNewAvail) items.add(MITCRDNEWAVAIL);
			if (MitCrdPcvAvail == comp.MitCrdPcvAvail) items.add(MITCRDPCVAVAIL);
			if (MitCrdPcvActive == comp.MitCrdPcvActive) items.add(MITCRDPCVACTIVE);
			if (MspCrd3Avail == comp.MspCrd3Avail) items.add(MSPCRD3AVAIL);
			if (MspCrd3Active == comp.MspCrd3Active) items.add(MSPCRD3ACTIVE);
			if (MitCrdImdAvail == comp.MitCrdImdAvail) items.add(MITCRDIMDAVAIL);
			if (MitCrdImdActive == comp.MitCrdImdActive) items.add(MITCRDIMDACTIVE);
			if (MitCrdIcsAvail == comp.MitCrdIcsAvail) items.add(MITCRDICSAVAIL);
			if (MitCrdIcsActive == comp.MitCrdIcsActive) items.add(MITCRDICSACTIVE);
			if (MitCrdIdaAvail == comp.MitCrdIdaAvail) items.add(MITCRDIDAAVAIL);
			if (MitCrdIdaActive == comp.MitCrdIdaActive) items.add(MITCRDIDAACTIVE);
			if (MspCrd4Avail == comp.MspCrd4Avail) items.add(MSPCRD4AVAIL);
			if (MspCrd4Active == comp.MspCrd4Active) items.add(MSPCRD4ACTIVE);
			if (MitCrdGfsAvail == comp.MitCrdGfsAvail) items.add(MITCRDGFSAVAIL);
			if (MitCrdGfsActive == comp.MitCrdGfsActive) items.add(MITCRDGFSACTIVE);
			if (MitCrdIfsAvail == comp.MitCrdIfsAvail) items.add(MITCRDIFSAVAIL);
			if (MitCrdIfsActive == comp.MitCrdIfsActive) items.add(MITCRDIFSACTIVE);
			if (MspCrd5Avail == comp.MspCrd5Avail) items.add(MSPCRD5AVAIL);
			if (MspCrd5Active == comp.MspCrd5Active) items.add(MSPCRD5ACTIVE);
			if (MitCrdFnmAvail == comp.MitCrdFnmAvail) items.add(MITCRDFNMAVAIL);
			if (MitCrdFnmActive == comp.MitCrdFnmActive) items.add(MITCRDFNMACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFDLGCMDSET, SCRJREFDLGCUSTFST, SCRJREFDLGDFLALG, SCRJREFDLGFINMOD, SCRJREFDLGGENFST, SCRJREFDLGMDLSTR, SCRJREFDLGNEW, SCRJREFHEADBAR, SCRJREFLIST, SCRJREFREC, MSPCRD1AVAIL, MITCRDNEWAVAIL, MITCRDPCVAVAIL, MITCRDPCVACTIVE, MSPCRD3AVAIL, MSPCRD3ACTIVE, MITCRDIMDAVAIL, MITCRDIMDACTIVE, MITCRDICSAVAIL, MITCRDICSACTIVE, MITCRDIDAAVAIL, MITCRDIDAACTIVE, MSPCRD4AVAIL, MSPCRD4ACTIVE, MITCRDGFSAVAIL, MITCRDGFSACTIVE, MITCRDIFSAVAIL, MITCRDIFSACTIVE, MSPCRD5AVAIL, MSPCRD5ACTIVE, MITCRDFNMAVAIL, MITCRDFNMACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeVer)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MITCRDNEW = 3;
		public static final int MITCRDPCV = 4;
		public static final int MITCRDIMD = 5;
		public static final int MITCRDICS = 6;
		public static final int MITCRDIDA = 7;
		public static final int MITCRDGFS = 8;
		public static final int MITCRDIFS = 9;
		public static final int MITCRDFNM = 10;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
					, String MitCrdNew
					, String MitCrdPcv
					, String MitCrdImd
					, String MitCrdIcs
					, String MitCrdIda
					, String MitCrdGfs
					, String MitCrdIfs
					, String MitCrdFnm
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;
			this.MitCrdNew = MitCrdNew;
			this.MitCrdPcv = MitCrdPcv;
			this.MitCrdImd = MitCrdImd;
			this.MitCrdIcs = MitCrdIcs;
			this.MitCrdIda = MitCrdIda;
			this.MitCrdGfs = MitCrdGfs;
			this.MitCrdIfs = MitCrdIfs;
			this.MitCrdFnm = MitCrdFnm;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDPCV, MITCRDIMD, MITCRDICS, MITCRDIDA, MITCRDGFS, MITCRDIFS, MITCRDFNM));
		};

		public String MitAppAbt;
		public String MrlAppHlp;
		public String MitCrdNew;
		public String MitCrdPcv;
		public String MitCrdImd;
		public String MitCrdIcs;
		public String MitCrdIda;
		public String MitCrdGfs;
		public String MitCrdIfs;
		public String MitCrdFnm;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeVer");

			String itemtag = "TagitemWdbeVer";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MitCrdNew = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdNew", mask, MITCRDNEW);
				MitCrdPcv = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPcv", mask, MITCRDPCV);
				MitCrdImd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdImd", mask, MITCRDIMD);
				MitCrdIcs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIcs", mask, MITCRDICS);
				MitCrdIda = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIda", mask, MITCRDIDA);
				MitCrdGfs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdGfs", mask, MITCRDGFS);
				MitCrdIfs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdIfs", mask, MITCRDIFS);
				MitCrdFnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdFnm", mask, MITCRDFNM);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (MitAppAbt.equals(comp.MitAppAbt)) items.add(MITAPPABT);
			if (MrlAppHlp.equals(comp.MrlAppHlp)) items.add(MRLAPPHLP);
			if (MitCrdNew.equals(comp.MitCrdNew)) items.add(MITCRDNEW);
			if (MitCrdPcv.equals(comp.MitCrdPcv)) items.add(MITCRDPCV);
			if (MitCrdImd.equals(comp.MitCrdImd)) items.add(MITCRDIMD);
			if (MitCrdIcs.equals(comp.MitCrdIcs)) items.add(MITCRDICS);
			if (MitCrdIda.equals(comp.MitCrdIda)) items.add(MITCRDIDA);
			if (MitCrdGfs.equals(comp.MitCrdGfs)) items.add(MITCRDGFS);
			if (MitCrdIfs.equals(comp.MitCrdIfs)) items.add(MITCRDIFS);
			if (MitCrdFnm.equals(comp.MitCrdFnm)) items.add(MITCRDFNM);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITCRDNEW, MITCRDPCV, MITCRDIMD, MITCRDICS, MITCRDIDA, MITCRDGFS, MITCRDIFS, MITCRDFNM));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeVerDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEVERDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeVerDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeVerData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEVERDATA);

			continf = new ContInf(0, "", "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false, false, false);
			statshr = new StatShr("", "", "", "", "", "", "", "", "", "", false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "");
		};

		public ContInf continf;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFSGE)) ss.add("feedFSge");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeVerData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(0, "", "");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(0, 0, "", 0, false, false, false);
				statshr = new StatShr("", "", "", "", "", "", "", "", "", "", false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
