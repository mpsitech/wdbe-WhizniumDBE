/**
  * \file CrdWdbeNav.java
  * Java API code for job CrdWdbeNav
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class CrdWdbeNav {
	/**
		* VecVDo (full: VecVWdbeNavDo)
		*/
	public static class VecVDo {

		public static final int CLOSE = 1;
		public static final int MITAPPABTCLICK = 2;
		public static final int MITSESSPSCLICK = 3;
		public static final int MITSESTRMCLICK = 4;
		public static final int MITCRDUSGCLICK = 5;
		public static final int MITCRDUSRCLICK = 6;
		public static final int MITCRDPRSCLICK = 7;
		public static final int MITCRDFILCLICK = 8;
		public static final int MITCRDMCHCLICK = 9;
		public static final int MITCRDLIBCLICK = 10;
		public static final int MITCRDFAMCLICK = 11;
		public static final int MITCRDSILCLICK = 12;
		public static final int MITCRDMTPCLICK = 13;
		public static final int MITCRDPRJCLICK = 14;
		public static final int MITCRDVERCLICK = 15;
		public static final int MITCRDUNTCLICK = 16;
		public static final int MITCRDCPRCLICK = 17;
		public static final int MITCRDCVRCLICK = 18;
		public static final int MITCRDPPHCLICK = 19;
		public static final int MITCRDMODCLICK = 20;
		public static final int MITCRDVECCLICK = 21;
		public static final int MITCRDCMDCLICK = 22;
		public static final int MITCRDERRCLICK = 23;
		public static final int MITCRDPPLCLICK = 24;
		public static final int MITCRDSEGCLICK = 25;
		public static final int MITCRDBNKCLICK = 26;
		public static final int MITCRDPINCLICK = 27;
		public static final int MITCRDINTCLICK = 28;
		public static final int MITCRDSIGCLICK = 29;
		public static final int MITCRDCMPCLICK = 30;
		public static final int MITCRDRLSCLICK = 31;
		public static final int MITCRDUTLCLICK = 32;
		public static final int MITAPPMLCCLICK = 33;
		public static final int MITAPPLOICLICK = 34;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("close")) return CLOSE;
			if (s.equals("mitappabtclick")) return MITAPPABTCLICK;
			if (s.equals("mitsesspsclick")) return MITSESSPSCLICK;
			if (s.equals("mitsestrmclick")) return MITSESTRMCLICK;
			if (s.equals("mitcrdusgclick")) return MITCRDUSGCLICK;
			if (s.equals("mitcrdusrclick")) return MITCRDUSRCLICK;
			if (s.equals("mitcrdprsclick")) return MITCRDPRSCLICK;
			if (s.equals("mitcrdfilclick")) return MITCRDFILCLICK;
			if (s.equals("mitcrdmchclick")) return MITCRDMCHCLICK;
			if (s.equals("mitcrdlibclick")) return MITCRDLIBCLICK;
			if (s.equals("mitcrdfamclick")) return MITCRDFAMCLICK;
			if (s.equals("mitcrdsilclick")) return MITCRDSILCLICK;
			if (s.equals("mitcrdmtpclick")) return MITCRDMTPCLICK;
			if (s.equals("mitcrdprjclick")) return MITCRDPRJCLICK;
			if (s.equals("mitcrdverclick")) return MITCRDVERCLICK;
			if (s.equals("mitcrduntclick")) return MITCRDUNTCLICK;
			if (s.equals("mitcrdcprclick")) return MITCRDCPRCLICK;
			if (s.equals("mitcrdcvrclick")) return MITCRDCVRCLICK;
			if (s.equals("mitcrdpphclick")) return MITCRDPPHCLICK;
			if (s.equals("mitcrdmodclick")) return MITCRDMODCLICK;
			if (s.equals("mitcrdvecclick")) return MITCRDVECCLICK;
			if (s.equals("mitcrdcmdclick")) return MITCRDCMDCLICK;
			if (s.equals("mitcrderrclick")) return MITCRDERRCLICK;
			if (s.equals("mitcrdpplclick")) return MITCRDPPLCLICK;
			if (s.equals("mitcrdsegclick")) return MITCRDSEGCLICK;
			if (s.equals("mitcrdbnkclick")) return MITCRDBNKCLICK;
			if (s.equals("mitcrdpinclick")) return MITCRDPINCLICK;
			if (s.equals("mitcrdintclick")) return MITCRDINTCLICK;
			if (s.equals("mitcrdsigclick")) return MITCRDSIGCLICK;
			if (s.equals("mitcrdcmpclick")) return MITCRDCMPCLICK;
			if (s.equals("mitcrdrlsclick")) return MITCRDRLSCLICK;
			if (s.equals("mitcrdutlclick")) return MITCRDUTLCLICK;
			if (s.equals("mitappmlcclick")) return MITAPPMLCCLICK;
			if (s.equals("mitapploiclick")) return MITAPPLOICLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == CLOSE) return("close");
			if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
			if (ix == MITSESSPSCLICK) return("MitSesSpsClick");
			if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
			if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
			if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
			if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
			if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
			if (ix == MITCRDMCHCLICK) return("MitCrdMchClick");
			if (ix == MITCRDLIBCLICK) return("MitCrdLibClick");
			if (ix == MITCRDFAMCLICK) return("MitCrdFamClick");
			if (ix == MITCRDSILCLICK) return("MitCrdSilClick");
			if (ix == MITCRDMTPCLICK) return("MitCrdMtpClick");
			if (ix == MITCRDPRJCLICK) return("MitCrdPrjClick");
			if (ix == MITCRDVERCLICK) return("MitCrdVerClick");
			if (ix == MITCRDUNTCLICK) return("MitCrdUntClick");
			if (ix == MITCRDCPRCLICK) return("MitCrdCprClick");
			if (ix == MITCRDCVRCLICK) return("MitCrdCvrClick");
			if (ix == MITCRDPPHCLICK) return("MitCrdPphClick");
			if (ix == MITCRDMODCLICK) return("MitCrdModClick");
			if (ix == MITCRDVECCLICK) return("MitCrdVecClick");
			if (ix == MITCRDCMDCLICK) return("MitCrdCmdClick");
			if (ix == MITCRDERRCLICK) return("MitCrdErrClick");
			if (ix == MITCRDPPLCLICK) return("MitCrdPplClick");
			if (ix == MITCRDSEGCLICK) return("MitCrdSegClick");
			if (ix == MITCRDBNKCLICK) return("MitCrdBnkClick");
			if (ix == MITCRDPINCLICK) return("MitCrdPinClick");
			if (ix == MITCRDINTCLICK) return("MitCrdIntClick");
			if (ix == MITCRDSIGCLICK) return("MitCrdSigClick");
			if (ix == MITCRDCMPCLICK) return("MitCrdCmpClick");
			if (ix == MITCRDRLSCLICK) return("MitCrdRlsClick");
			if (ix == MITCRDUTLCLICK) return("MitCrdUtlClick");
			if (ix == MITAPPMLCCLICK) return("MitAppMlcClick");
			if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVWdbeNavSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRWDBEABT = 2;
		public static final int ALRWDBETRM = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrwdbeabt")) return ALRWDBEABT;
			if (s.equals("alrwdbetrm")) return ALRWDBETRM;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRWDBEABT) return("alrwdbeabt");
			if (ix == ALRWDBETRM) return("alrwdbetrm");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWdbeNav)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MTXSESSES1 = 3;
		public static final int MTXSESSES2 = 4;
		public static final int MTXSESSES3 = 5;

		public ContInf(
					int numFSge
					, String MrlAppHlp
					, String MtxSesSes1
					, String MtxSesSes2
					, String MtxSesSes3
				) {
			this.numFSge = numFSge;
			this.MrlAppHlp = MrlAppHlp;
			this.MtxSesSes1 = MtxSesSes1;
			this.MtxSesSes2 = MtxSesSes2;
			this.MtxSesSes3 = MtxSesSes3;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3));
		};

		public int numFSge;
		public String MrlAppHlp;
		public String MtxSesSes1;
		public String MtxSesSes2;
		public String MtxSesSes3;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeNav");

			String itemtag = "ContitemInfWdbeNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MtxSesSes1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxSesSes1", mask, MTXSESSES1);
				MtxSesSes2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxSesSes2", mask, MTXSESSES2);
				MtxSesSes3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "MtxSesSes3", mask, MTXSESSES3);

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
			if (MtxSesSes1.equals(comp.MtxSesSes1)) items.add(MTXSESSES1);
			if (MtxSesSes2.equals(comp.MtxSesSes2)) items.add(MTXSESSES2);
			if (MtxSesSes3.equals(comp.MtxSesSes3)) items.add(MTXSESSES3);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeNav)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVREQITMODE = 1;
		public static final int LATENCY = 2;
		public static final int SHORTMENU = 3;
		public static final int WIDTHMENU = 4;
		public static final int INITDONEHEADBAR = 5;
		public static final int INITDONEPRE = 6;
		public static final int INITDONEADMIN = 7;
		public static final int INITDONEGLOBAL = 8;
		public static final int INITDONEDEVDEV = 9;
		public static final int INITDONECOREDEV = 10;
		public static final int INITDONEHIGH = 11;
		public static final int INITDONELOW = 12;
		public static final int INITDONEDEPLOY = 13;
		public static final int INITDONEAUXFCT = 14;

		public StatApp(
					int ixWdbeVReqitmode
					, int latency
					, String shortMenu
					, int widthMenu
					, boolean initdoneHeadbar
					, boolean initdonePre
					, boolean initdoneAdmin
					, boolean initdoneGlobal
					, boolean initdoneDevdev
					, boolean initdoneCoredev
					, boolean initdoneHigh
					, boolean initdoneLow
					, boolean initdoneDeploy
					, boolean initdoneAuxfct
				) {
			this.ixWdbeVReqitmode = ixWdbeVReqitmode;
			this.latency = latency;
			this.shortMenu = shortMenu;
			this.widthMenu = widthMenu;
			this.initdoneHeadbar = initdoneHeadbar;
			this.initdonePre = initdonePre;
			this.initdoneAdmin = initdoneAdmin;
			this.initdoneGlobal = initdoneGlobal;
			this.initdoneDevdev = initdoneDevdev;
			this.initdoneCoredev = initdoneCoredev;
			this.initdoneHigh = initdoneHigh;
			this.initdoneLow = initdoneLow;
			this.initdoneDeploy = initdoneDeploy;
			this.initdoneAuxfct = initdoneAuxfct;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEGLOBAL, INITDONEDEVDEV, INITDONECOREDEV, INITDONEHIGH, INITDONELOW, INITDONEDEPLOY, INITDONEAUXFCT));
		};

		public int ixWdbeVReqitmode;
		public int latency;
		public String shortMenu;
		public int widthMenu;
		public boolean initdoneHeadbar;
		public boolean initdonePre;
		public boolean initdoneAdmin;
		public boolean initdoneGlobal;
		public boolean initdoneDevdev;
		public boolean initdoneCoredev;
		public boolean initdoneHigh;
		public boolean initdoneLow;
		public boolean initdoneDeploy;
		public boolean initdoneAuxfct;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVReqitmode;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeNav");

			String itemtag = "StatitemAppWdbeNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVReqitmode = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVReqitmode", mask, IXWDBEVREQITMODE);
				ixWdbeVReqitmode = VecWdbeVReqitmode.getIx(srefIxWdbeVReqitmode);
				latency = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "latency", mask, LATENCY);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);
				widthMenu = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "widthMenu", mask, WIDTHMENU);
				initdoneHeadbar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHeadbar", mask, INITDONEHEADBAR);
				initdonePre = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdonePre", mask, INITDONEPRE);
				initdoneAdmin = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAdmin", mask, INITDONEADMIN);
				initdoneGlobal = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneGlobal", mask, INITDONEGLOBAL);
				initdoneDevdev = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDevdev", mask, INITDONEDEVDEV);
				initdoneCoredev = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCoredev", mask, INITDONECOREDEV);
				initdoneHigh = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHigh", mask, INITDONEHIGH);
				initdoneLow = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneLow", mask, INITDONELOW);
				initdoneDeploy = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDeploy", mask, INITDONEDEPLOY);
				initdoneAuxfct = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAuxfct", mask, INITDONEAUXFCT);

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
			if (initdonePre == comp.initdonePre) items.add(INITDONEPRE);
			if (initdoneAdmin == comp.initdoneAdmin) items.add(INITDONEADMIN);
			if (initdoneGlobal == comp.initdoneGlobal) items.add(INITDONEGLOBAL);
			if (initdoneDevdev == comp.initdoneDevdev) items.add(INITDONEDEVDEV);
			if (initdoneCoredev == comp.initdoneCoredev) items.add(INITDONECOREDEV);
			if (initdoneHigh == comp.initdoneHigh) items.add(INITDONEHIGH);
			if (initdoneLow == comp.initdoneLow) items.add(INITDONELOW);
			if (initdoneDeploy == comp.initdoneDeploy) items.add(INITDONEDEPLOY);
			if (initdoneAuxfct == comp.initdoneAuxfct) items.add(INITDONEAUXFCT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVREQITMODE, LATENCY, SHORTMENU, WIDTHMENU, INITDONEHEADBAR, INITDONEPRE, INITDONEADMIN, INITDONEGLOBAL, INITDONEDEVDEV, INITDONECOREDEV, INITDONEHIGH, INITDONELOW, INITDONEDEPLOY, INITDONEAUXFCT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeNav)
	  */
	public class StatShr extends Block {

		public static final int SCRJREFDLGLOAINI = 1;
		public static final int SCRJREFDLGMNGLIC = 2;
		public static final int SCRJREFHEADBAR = 3;
		public static final int SCRJREFPRE = 4;
		public static final int PNLPREAVAIL = 5;
		public static final int SCRJREFADMIN = 6;
		public static final int PNLADMINAVAIL = 7;
		public static final int SCRJREFGLOBAL = 8;
		public static final int PNLGLOBALAVAIL = 9;
		public static final int SCRJREFDEVDEV = 10;
		public static final int PNLDEVDEVAVAIL = 11;
		public static final int SCRJREFCOREDEV = 12;
		public static final int PNLCOREDEVAVAIL = 13;
		public static final int SCRJREFHIGH = 14;
		public static final int PNLHIGHAVAIL = 15;
		public static final int SCRJREFLOW = 16;
		public static final int PNLLOWAVAIL = 17;
		public static final int SCRJREFDEPLOY = 18;
		public static final int PNLDEPLOYAVAIL = 19;
		public static final int SCRJREFAUXFCT = 20;
		public static final int PNLAUXFCTAVAIL = 21;
		public static final int MITSESSPSAVAIL = 22;
		public static final int MSPCRD1AVAIL = 23;
		public static final int MITCRDUSGAVAIL = 24;
		public static final int MITCRDUSRAVAIL = 25;
		public static final int MITCRDPRSAVAIL = 26;
		public static final int MITCRDFILAVAIL = 27;
		public static final int MSPCRD2AVAIL = 28;
		public static final int MITCRDMCHAVAIL = 29;
		public static final int MITCRDLIBAVAIL = 30;
		public static final int MITCRDFAMAVAIL = 31;
		public static final int MITCRDSILAVAIL = 32;
		public static final int MITCRDMTPAVAIL = 33;
		public static final int MSPCRD3AVAIL = 34;
		public static final int MITCRDPRJAVAIL = 35;
		public static final int MITCRDVERAVAIL = 36;
		public static final int MITCRDUNTAVAIL = 37;
		public static final int MITCRDUNTACTIVE = 38;
		public static final int MSPCRD4AVAIL = 39;
		public static final int MITCRDCPRAVAIL = 40;
		public static final int MITCRDCVRAVAIL = 41;
		public static final int MSPCRD5AVAIL = 42;
		public static final int MITCRDPPHAVAIL = 43;
		public static final int MITCRDPPHACTIVE = 44;
		public static final int MITCRDMODAVAIL = 45;
		public static final int MITCRDMODACTIVE = 46;
		public static final int MITCRDVECAVAIL = 47;
		public static final int MITCRDVECACTIVE = 48;
		public static final int MITCRDCMDAVAIL = 49;
		public static final int MITCRDCMDACTIVE = 50;
		public static final int MITCRDERRAVAIL = 51;
		public static final int MITCRDERRACTIVE = 52;
		public static final int MITCRDPPLAVAIL = 53;
		public static final int MITCRDPPLACTIVE = 54;
		public static final int MITCRDSEGAVAIL = 55;
		public static final int MITCRDSEGACTIVE = 56;
		public static final int MSPCRD6AVAIL = 57;
		public static final int MITCRDBNKAVAIL = 58;
		public static final int MITCRDBNKACTIVE = 59;
		public static final int MITCRDPINAVAIL = 60;
		public static final int MITCRDPINACTIVE = 61;
		public static final int MITCRDINTAVAIL = 62;
		public static final int MITCRDINTACTIVE = 63;
		public static final int MITCRDSIGAVAIL = 64;
		public static final int MITCRDSIGACTIVE = 65;
		public static final int MSPCRD7AVAIL = 66;
		public static final int MITCRDCMPAVAIL = 67;
		public static final int MITCRDRLSAVAIL = 68;
		public static final int MITCRDRLSACTIVE = 69;
		public static final int MSPCRD8AVAIL = 70;
		public static final int MITCRDUTLAVAIL = 71;
		public static final int MSPAPP2AVAIL = 72;
		public static final int MITAPPMLCAVAIL = 73;
		public static final int MITAPPLOIAVAIL = 74;

		public StatShr(
					String scrJrefDlgloaini
					, String scrJrefDlgmnglic
					, String scrJrefHeadbar
					, String scrJrefPre
					, boolean pnlpreAvail
					, String scrJrefAdmin
					, boolean pnladminAvail
					, String scrJrefGlobal
					, boolean pnlglobalAvail
					, String scrJrefDevdev
					, boolean pnldevdevAvail
					, String scrJrefCoredev
					, boolean pnlcoredevAvail
					, String scrJrefHigh
					, boolean pnlhighAvail
					, String scrJrefLow
					, boolean pnllowAvail
					, String scrJrefDeploy
					, boolean pnldeployAvail
					, String scrJrefAuxfct
					, boolean pnlauxfctAvail
					, boolean MitSesSpsAvail
					, boolean MspCrd1Avail
					, boolean MitCrdUsgAvail
					, boolean MitCrdUsrAvail
					, boolean MitCrdPrsAvail
					, boolean MitCrdFilAvail
					, boolean MspCrd2Avail
					, boolean MitCrdMchAvail
					, boolean MitCrdLibAvail
					, boolean MitCrdFamAvail
					, boolean MitCrdSilAvail
					, boolean MitCrdMtpAvail
					, boolean MspCrd3Avail
					, boolean MitCrdPrjAvail
					, boolean MitCrdVerAvail
					, boolean MitCrdUntAvail
					, boolean MitCrdUntActive
					, boolean MspCrd4Avail
					, boolean MitCrdCprAvail
					, boolean MitCrdCvrAvail
					, boolean MspCrd5Avail
					, boolean MitCrdPphAvail
					, boolean MitCrdPphActive
					, boolean MitCrdModAvail
					, boolean MitCrdModActive
					, boolean MitCrdVecAvail
					, boolean MitCrdVecActive
					, boolean MitCrdCmdAvail
					, boolean MitCrdCmdActive
					, boolean MitCrdErrAvail
					, boolean MitCrdErrActive
					, boolean MitCrdPplAvail
					, boolean MitCrdPplActive
					, boolean MitCrdSegAvail
					, boolean MitCrdSegActive
					, boolean MspCrd6Avail
					, boolean MitCrdBnkAvail
					, boolean MitCrdBnkActive
					, boolean MitCrdPinAvail
					, boolean MitCrdPinActive
					, boolean MitCrdIntAvail
					, boolean MitCrdIntActive
					, boolean MitCrdSigAvail
					, boolean MitCrdSigActive
					, boolean MspCrd7Avail
					, boolean MitCrdCmpAvail
					, boolean MitCrdRlsAvail
					, boolean MitCrdRlsActive
					, boolean MspCrd8Avail
					, boolean MitCrdUtlAvail
					, boolean MspApp2Avail
					, boolean MitAppMlcAvail
					, boolean MitAppLoiAvail
				) {
			this.scrJrefDlgloaini = scrJrefDlgloaini;
			this.scrJrefDlgmnglic = scrJrefDlgmnglic;
			this.scrJrefHeadbar = scrJrefHeadbar;
			this.scrJrefPre = scrJrefPre;
			this.pnlpreAvail = pnlpreAvail;
			this.scrJrefAdmin = scrJrefAdmin;
			this.pnladminAvail = pnladminAvail;
			this.scrJrefGlobal = scrJrefGlobal;
			this.pnlglobalAvail = pnlglobalAvail;
			this.scrJrefDevdev = scrJrefDevdev;
			this.pnldevdevAvail = pnldevdevAvail;
			this.scrJrefCoredev = scrJrefCoredev;
			this.pnlcoredevAvail = pnlcoredevAvail;
			this.scrJrefHigh = scrJrefHigh;
			this.pnlhighAvail = pnlhighAvail;
			this.scrJrefLow = scrJrefLow;
			this.pnllowAvail = pnllowAvail;
			this.scrJrefDeploy = scrJrefDeploy;
			this.pnldeployAvail = pnldeployAvail;
			this.scrJrefAuxfct = scrJrefAuxfct;
			this.pnlauxfctAvail = pnlauxfctAvail;
			this.MitSesSpsAvail = MitSesSpsAvail;
			this.MspCrd1Avail = MspCrd1Avail;
			this.MitCrdUsgAvail = MitCrdUsgAvail;
			this.MitCrdUsrAvail = MitCrdUsrAvail;
			this.MitCrdPrsAvail = MitCrdPrsAvail;
			this.MitCrdFilAvail = MitCrdFilAvail;
			this.MspCrd2Avail = MspCrd2Avail;
			this.MitCrdMchAvail = MitCrdMchAvail;
			this.MitCrdLibAvail = MitCrdLibAvail;
			this.MitCrdFamAvail = MitCrdFamAvail;
			this.MitCrdSilAvail = MitCrdSilAvail;
			this.MitCrdMtpAvail = MitCrdMtpAvail;
			this.MspCrd3Avail = MspCrd3Avail;
			this.MitCrdPrjAvail = MitCrdPrjAvail;
			this.MitCrdVerAvail = MitCrdVerAvail;
			this.MitCrdUntAvail = MitCrdUntAvail;
			this.MitCrdUntActive = MitCrdUntActive;
			this.MspCrd4Avail = MspCrd4Avail;
			this.MitCrdCprAvail = MitCrdCprAvail;
			this.MitCrdCvrAvail = MitCrdCvrAvail;
			this.MspCrd5Avail = MspCrd5Avail;
			this.MitCrdPphAvail = MitCrdPphAvail;
			this.MitCrdPphActive = MitCrdPphActive;
			this.MitCrdModAvail = MitCrdModAvail;
			this.MitCrdModActive = MitCrdModActive;
			this.MitCrdVecAvail = MitCrdVecAvail;
			this.MitCrdVecActive = MitCrdVecActive;
			this.MitCrdCmdAvail = MitCrdCmdAvail;
			this.MitCrdCmdActive = MitCrdCmdActive;
			this.MitCrdErrAvail = MitCrdErrAvail;
			this.MitCrdErrActive = MitCrdErrActive;
			this.MitCrdPplAvail = MitCrdPplAvail;
			this.MitCrdPplActive = MitCrdPplActive;
			this.MitCrdSegAvail = MitCrdSegAvail;
			this.MitCrdSegActive = MitCrdSegActive;
			this.MspCrd6Avail = MspCrd6Avail;
			this.MitCrdBnkAvail = MitCrdBnkAvail;
			this.MitCrdBnkActive = MitCrdBnkActive;
			this.MitCrdPinAvail = MitCrdPinAvail;
			this.MitCrdPinActive = MitCrdPinActive;
			this.MitCrdIntAvail = MitCrdIntAvail;
			this.MitCrdIntActive = MitCrdIntActive;
			this.MitCrdSigAvail = MitCrdSigAvail;
			this.MitCrdSigActive = MitCrdSigActive;
			this.MspCrd7Avail = MspCrd7Avail;
			this.MitCrdCmpAvail = MitCrdCmpAvail;
			this.MitCrdRlsAvail = MitCrdRlsAvail;
			this.MitCrdRlsActive = MitCrdRlsActive;
			this.MspCrd8Avail = MspCrd8Avail;
			this.MitCrdUtlAvail = MitCrdUtlAvail;
			this.MspApp2Avail = MspApp2Avail;
			this.MitAppMlcAvail = MitAppMlcAvail;
			this.MitAppLoiAvail = MitAppLoiAvail;

			mask = new HashSet<Integer>(Arrays.asList(SCRJREFDLGLOAINI, SCRJREFDLGMNGLIC, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFGLOBAL, PNLGLOBALAVAIL, SCRJREFDEVDEV, PNLDEVDEVAVAIL, SCRJREFCOREDEV, PNLCOREDEVAVAIL, SCRJREFHIGH, PNLHIGHAVAIL, SCRJREFLOW, PNLLOWAVAIL, SCRJREFDEPLOY, PNLDEPLOYAVAIL, SCRJREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MITCRDFAMAVAIL, MITCRDSILAVAIL, MITCRDMTPAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDUNTAVAIL, MITCRDUNTACTIVE, MSPCRD4AVAIL, MITCRDCPRAVAIL, MITCRDCVRAVAIL, MSPCRD5AVAIL, MITCRDPPHAVAIL, MITCRDPPHACTIVE, MITCRDMODAVAIL, MITCRDMODACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDCMDAVAIL, MITCRDCMDACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MITCRDPPLAVAIL, MITCRDPPLACTIVE, MITCRDSEGAVAIL, MITCRDSEGACTIVE, MSPCRD6AVAIL, MITCRDBNKAVAIL, MITCRDBNKACTIVE, MITCRDPINAVAIL, MITCRDPINACTIVE, MITCRDINTAVAIL, MITCRDINTACTIVE, MITCRDSIGAVAIL, MITCRDSIGACTIVE, MSPCRD7AVAIL, MITCRDCMPAVAIL, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD8AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL));
		};

		public String scrJrefDlgloaini;
		public String scrJrefDlgmnglic;
		public String scrJrefHeadbar;
		public String scrJrefPre;
		public boolean pnlpreAvail;
		public String scrJrefAdmin;
		public boolean pnladminAvail;
		public String scrJrefGlobal;
		public boolean pnlglobalAvail;
		public String scrJrefDevdev;
		public boolean pnldevdevAvail;
		public String scrJrefCoredev;
		public boolean pnlcoredevAvail;
		public String scrJrefHigh;
		public boolean pnlhighAvail;
		public String scrJrefLow;
		public boolean pnllowAvail;
		public String scrJrefDeploy;
		public boolean pnldeployAvail;
		public String scrJrefAuxfct;
		public boolean pnlauxfctAvail;
		public boolean MitSesSpsAvail;
		public boolean MspCrd1Avail;
		public boolean MitCrdUsgAvail;
		public boolean MitCrdUsrAvail;
		public boolean MitCrdPrsAvail;
		public boolean MitCrdFilAvail;
		public boolean MspCrd2Avail;
		public boolean MitCrdMchAvail;
		public boolean MitCrdLibAvail;
		public boolean MitCrdFamAvail;
		public boolean MitCrdSilAvail;
		public boolean MitCrdMtpAvail;
		public boolean MspCrd3Avail;
		public boolean MitCrdPrjAvail;
		public boolean MitCrdVerAvail;
		public boolean MitCrdUntAvail;
		public boolean MitCrdUntActive;
		public boolean MspCrd4Avail;
		public boolean MitCrdCprAvail;
		public boolean MitCrdCvrAvail;
		public boolean MspCrd5Avail;
		public boolean MitCrdPphAvail;
		public boolean MitCrdPphActive;
		public boolean MitCrdModAvail;
		public boolean MitCrdModActive;
		public boolean MitCrdVecAvail;
		public boolean MitCrdVecActive;
		public boolean MitCrdCmdAvail;
		public boolean MitCrdCmdActive;
		public boolean MitCrdErrAvail;
		public boolean MitCrdErrActive;
		public boolean MitCrdPplAvail;
		public boolean MitCrdPplActive;
		public boolean MitCrdSegAvail;
		public boolean MitCrdSegActive;
		public boolean MspCrd6Avail;
		public boolean MitCrdBnkAvail;
		public boolean MitCrdBnkActive;
		public boolean MitCrdPinAvail;
		public boolean MitCrdPinActive;
		public boolean MitCrdIntAvail;
		public boolean MitCrdIntActive;
		public boolean MitCrdSigAvail;
		public boolean MitCrdSigActive;
		public boolean MspCrd7Avail;
		public boolean MitCrdCmpAvail;
		public boolean MitCrdRlsAvail;
		public boolean MitCrdRlsActive;
		public boolean MspCrd8Avail;
		public boolean MitCrdUtlAvail;
		public boolean MspApp2Avail;
		public boolean MitAppMlcAvail;
		public boolean MitAppLoiAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNav");

			String itemtag = "StatitemShrWdbeNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJrefDlgloaini = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgloaini", mask, SCRJREFDLGLOAINI);
				scrJrefDlgmnglic = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDlgmnglic", mask, SCRJREFDLGMNGLIC);
				scrJrefHeadbar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHeadbar", mask, SCRJREFHEADBAR);
				scrJrefPre = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefPre", mask, SCRJREFPRE);
				pnlpreAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlpreAvail", mask, PNLPREAVAIL);
				scrJrefAdmin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAdmin", mask, SCRJREFADMIN);
				pnladminAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnladminAvail", mask, PNLADMINAVAIL);
				scrJrefGlobal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefGlobal", mask, SCRJREFGLOBAL);
				pnlglobalAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlglobalAvail", mask, PNLGLOBALAVAIL);
				scrJrefDevdev = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDevdev", mask, SCRJREFDEVDEV);
				pnldevdevAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnldevdevAvail", mask, PNLDEVDEVAVAIL);
				scrJrefCoredev = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCoredev", mask, SCRJREFCOREDEV);
				pnlcoredevAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlcoredevAvail", mask, PNLCOREDEVAVAIL);
				scrJrefHigh = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHigh", mask, SCRJREFHIGH);
				pnlhighAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlhighAvail", mask, PNLHIGHAVAIL);
				scrJrefLow = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefLow", mask, SCRJREFLOW);
				pnllowAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnllowAvail", mask, PNLLOWAVAIL);
				scrJrefDeploy = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDeploy", mask, SCRJREFDEPLOY);
				pnldeployAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnldeployAvail", mask, PNLDEPLOYAVAIL);
				scrJrefAuxfct = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAuxfct", mask, SCRJREFAUXFCT);
				pnlauxfctAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlauxfctAvail", mask, PNLAUXFCTAVAIL);
				MitSesSpsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitSesSpsAvail", mask, MITSESSPSAVAIL);
				MspCrd1Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd1Avail", mask, MSPCRD1AVAIL);
				MitCrdUsgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdUsgAvail", mask, MITCRDUSGAVAIL);
				MitCrdUsrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdUsrAvail", mask, MITCRDUSRAVAIL);
				MitCrdPrsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPrsAvail", mask, MITCRDPRSAVAIL);
				MitCrdFilAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdFilAvail", mask, MITCRDFILAVAIL);
				MspCrd2Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd2Avail", mask, MSPCRD2AVAIL);
				MitCrdMchAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdMchAvail", mask, MITCRDMCHAVAIL);
				MitCrdLibAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdLibAvail", mask, MITCRDLIBAVAIL);
				MitCrdFamAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdFamAvail", mask, MITCRDFAMAVAIL);
				MitCrdSilAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSilAvail", mask, MITCRDSILAVAIL);
				MitCrdMtpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdMtpAvail", mask, MITCRDMTPAVAIL);
				MspCrd3Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd3Avail", mask, MSPCRD3AVAIL);
				MitCrdPrjAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPrjAvail", mask, MITCRDPRJAVAIL);
				MitCrdVerAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdVerAvail", mask, MITCRDVERAVAIL);
				MitCrdUntAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdUntAvail", mask, MITCRDUNTAVAIL);
				MitCrdUntActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdUntActive", mask, MITCRDUNTACTIVE);
				MspCrd4Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd4Avail", mask, MSPCRD4AVAIL);
				MitCrdCprAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCprAvail", mask, MITCRDCPRAVAIL);
				MitCrdCvrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCvrAvail", mask, MITCRDCVRAVAIL);
				MspCrd5Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd5Avail", mask, MSPCRD5AVAIL);
				MitCrdPphAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPphAvail", mask, MITCRDPPHAVAIL);
				MitCrdPphActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPphActive", mask, MITCRDPPHACTIVE);
				MitCrdModAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdModAvail", mask, MITCRDMODAVAIL);
				MitCrdModActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdModActive", mask, MITCRDMODACTIVE);
				MitCrdVecAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdVecAvail", mask, MITCRDVECAVAIL);
				MitCrdVecActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdVecActive", mask, MITCRDVECACTIVE);
				MitCrdCmdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCmdAvail", mask, MITCRDCMDAVAIL);
				MitCrdCmdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCmdActive", mask, MITCRDCMDACTIVE);
				MitCrdErrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdErrAvail", mask, MITCRDERRAVAIL);
				MitCrdErrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdErrActive", mask, MITCRDERRACTIVE);
				MitCrdPplAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPplAvail", mask, MITCRDPPLAVAIL);
				MitCrdPplActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPplActive", mask, MITCRDPPLACTIVE);
				MitCrdSegAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSegAvail", mask, MITCRDSEGAVAIL);
				MitCrdSegActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSegActive", mask, MITCRDSEGACTIVE);
				MspCrd6Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd6Avail", mask, MSPCRD6AVAIL);
				MitCrdBnkAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdBnkAvail", mask, MITCRDBNKAVAIL);
				MitCrdBnkActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdBnkActive", mask, MITCRDBNKACTIVE);
				MitCrdPinAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPinAvail", mask, MITCRDPINAVAIL);
				MitCrdPinActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdPinActive", mask, MITCRDPINACTIVE);
				MitCrdIntAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIntAvail", mask, MITCRDINTAVAIL);
				MitCrdIntActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdIntActive", mask, MITCRDINTACTIVE);
				MitCrdSigAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSigAvail", mask, MITCRDSIGAVAIL);
				MitCrdSigActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdSigActive", mask, MITCRDSIGACTIVE);
				MspCrd7Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd7Avail", mask, MSPCRD7AVAIL);
				MitCrdCmpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdCmpAvail", mask, MITCRDCMPAVAIL);
				MitCrdRlsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdRlsAvail", mask, MITCRDRLSAVAIL);
				MitCrdRlsActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdRlsActive", mask, MITCRDRLSACTIVE);
				MspCrd8Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspCrd8Avail", mask, MSPCRD8AVAIL);
				MitCrdUtlAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitCrdUtlAvail", mask, MITCRDUTLAVAIL);
				MspApp2Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MspApp2Avail", mask, MSPAPP2AVAIL);
				MitAppMlcAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitAppMlcAvail", mask, MITAPPMLCAVAIL);
				MitAppLoiAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "MitAppLoiAvail", mask, MITAPPLOIAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (scrJrefDlgloaini.equals(comp.scrJrefDlgloaini)) items.add(SCRJREFDLGLOAINI);
			if (scrJrefDlgmnglic.equals(comp.scrJrefDlgmnglic)) items.add(SCRJREFDLGMNGLIC);
			if (scrJrefHeadbar.equals(comp.scrJrefHeadbar)) items.add(SCRJREFHEADBAR);
			if (scrJrefPre.equals(comp.scrJrefPre)) items.add(SCRJREFPRE);
			if (pnlpreAvail == comp.pnlpreAvail) items.add(PNLPREAVAIL);
			if (scrJrefAdmin.equals(comp.scrJrefAdmin)) items.add(SCRJREFADMIN);
			if (pnladminAvail == comp.pnladminAvail) items.add(PNLADMINAVAIL);
			if (scrJrefGlobal.equals(comp.scrJrefGlobal)) items.add(SCRJREFGLOBAL);
			if (pnlglobalAvail == comp.pnlglobalAvail) items.add(PNLGLOBALAVAIL);
			if (scrJrefDevdev.equals(comp.scrJrefDevdev)) items.add(SCRJREFDEVDEV);
			if (pnldevdevAvail == comp.pnldevdevAvail) items.add(PNLDEVDEVAVAIL);
			if (scrJrefCoredev.equals(comp.scrJrefCoredev)) items.add(SCRJREFCOREDEV);
			if (pnlcoredevAvail == comp.pnlcoredevAvail) items.add(PNLCOREDEVAVAIL);
			if (scrJrefHigh.equals(comp.scrJrefHigh)) items.add(SCRJREFHIGH);
			if (pnlhighAvail == comp.pnlhighAvail) items.add(PNLHIGHAVAIL);
			if (scrJrefLow.equals(comp.scrJrefLow)) items.add(SCRJREFLOW);
			if (pnllowAvail == comp.pnllowAvail) items.add(PNLLOWAVAIL);
			if (scrJrefDeploy.equals(comp.scrJrefDeploy)) items.add(SCRJREFDEPLOY);
			if (pnldeployAvail == comp.pnldeployAvail) items.add(PNLDEPLOYAVAIL);
			if (scrJrefAuxfct.equals(comp.scrJrefAuxfct)) items.add(SCRJREFAUXFCT);
			if (pnlauxfctAvail == comp.pnlauxfctAvail) items.add(PNLAUXFCTAVAIL);
			if (MitSesSpsAvail == comp.MitSesSpsAvail) items.add(MITSESSPSAVAIL);
			if (MspCrd1Avail == comp.MspCrd1Avail) items.add(MSPCRD1AVAIL);
			if (MitCrdUsgAvail == comp.MitCrdUsgAvail) items.add(MITCRDUSGAVAIL);
			if (MitCrdUsrAvail == comp.MitCrdUsrAvail) items.add(MITCRDUSRAVAIL);
			if (MitCrdPrsAvail == comp.MitCrdPrsAvail) items.add(MITCRDPRSAVAIL);
			if (MitCrdFilAvail == comp.MitCrdFilAvail) items.add(MITCRDFILAVAIL);
			if (MspCrd2Avail == comp.MspCrd2Avail) items.add(MSPCRD2AVAIL);
			if (MitCrdMchAvail == comp.MitCrdMchAvail) items.add(MITCRDMCHAVAIL);
			if (MitCrdLibAvail == comp.MitCrdLibAvail) items.add(MITCRDLIBAVAIL);
			if (MitCrdFamAvail == comp.MitCrdFamAvail) items.add(MITCRDFAMAVAIL);
			if (MitCrdSilAvail == comp.MitCrdSilAvail) items.add(MITCRDSILAVAIL);
			if (MitCrdMtpAvail == comp.MitCrdMtpAvail) items.add(MITCRDMTPAVAIL);
			if (MspCrd3Avail == comp.MspCrd3Avail) items.add(MSPCRD3AVAIL);
			if (MitCrdPrjAvail == comp.MitCrdPrjAvail) items.add(MITCRDPRJAVAIL);
			if (MitCrdVerAvail == comp.MitCrdVerAvail) items.add(MITCRDVERAVAIL);
			if (MitCrdUntAvail == comp.MitCrdUntAvail) items.add(MITCRDUNTAVAIL);
			if (MitCrdUntActive == comp.MitCrdUntActive) items.add(MITCRDUNTACTIVE);
			if (MspCrd4Avail == comp.MspCrd4Avail) items.add(MSPCRD4AVAIL);
			if (MitCrdCprAvail == comp.MitCrdCprAvail) items.add(MITCRDCPRAVAIL);
			if (MitCrdCvrAvail == comp.MitCrdCvrAvail) items.add(MITCRDCVRAVAIL);
			if (MspCrd5Avail == comp.MspCrd5Avail) items.add(MSPCRD5AVAIL);
			if (MitCrdPphAvail == comp.MitCrdPphAvail) items.add(MITCRDPPHAVAIL);
			if (MitCrdPphActive == comp.MitCrdPphActive) items.add(MITCRDPPHACTIVE);
			if (MitCrdModAvail == comp.MitCrdModAvail) items.add(MITCRDMODAVAIL);
			if (MitCrdModActive == comp.MitCrdModActive) items.add(MITCRDMODACTIVE);
			if (MitCrdVecAvail == comp.MitCrdVecAvail) items.add(MITCRDVECAVAIL);
			if (MitCrdVecActive == comp.MitCrdVecActive) items.add(MITCRDVECACTIVE);
			if (MitCrdCmdAvail == comp.MitCrdCmdAvail) items.add(MITCRDCMDAVAIL);
			if (MitCrdCmdActive == comp.MitCrdCmdActive) items.add(MITCRDCMDACTIVE);
			if (MitCrdErrAvail == comp.MitCrdErrAvail) items.add(MITCRDERRAVAIL);
			if (MitCrdErrActive == comp.MitCrdErrActive) items.add(MITCRDERRACTIVE);
			if (MitCrdPplAvail == comp.MitCrdPplAvail) items.add(MITCRDPPLAVAIL);
			if (MitCrdPplActive == comp.MitCrdPplActive) items.add(MITCRDPPLACTIVE);
			if (MitCrdSegAvail == comp.MitCrdSegAvail) items.add(MITCRDSEGAVAIL);
			if (MitCrdSegActive == comp.MitCrdSegActive) items.add(MITCRDSEGACTIVE);
			if (MspCrd6Avail == comp.MspCrd6Avail) items.add(MSPCRD6AVAIL);
			if (MitCrdBnkAvail == comp.MitCrdBnkAvail) items.add(MITCRDBNKAVAIL);
			if (MitCrdBnkActive == comp.MitCrdBnkActive) items.add(MITCRDBNKACTIVE);
			if (MitCrdPinAvail == comp.MitCrdPinAvail) items.add(MITCRDPINAVAIL);
			if (MitCrdPinActive == comp.MitCrdPinActive) items.add(MITCRDPINACTIVE);
			if (MitCrdIntAvail == comp.MitCrdIntAvail) items.add(MITCRDINTAVAIL);
			if (MitCrdIntActive == comp.MitCrdIntActive) items.add(MITCRDINTACTIVE);
			if (MitCrdSigAvail == comp.MitCrdSigAvail) items.add(MITCRDSIGAVAIL);
			if (MitCrdSigActive == comp.MitCrdSigActive) items.add(MITCRDSIGACTIVE);
			if (MspCrd7Avail == comp.MspCrd7Avail) items.add(MSPCRD7AVAIL);
			if (MitCrdCmpAvail == comp.MitCrdCmpAvail) items.add(MITCRDCMPAVAIL);
			if (MitCrdRlsAvail == comp.MitCrdRlsAvail) items.add(MITCRDRLSAVAIL);
			if (MitCrdRlsActive == comp.MitCrdRlsActive) items.add(MITCRDRLSACTIVE);
			if (MspCrd8Avail == comp.MspCrd8Avail) items.add(MSPCRD8AVAIL);
			if (MitCrdUtlAvail == comp.MitCrdUtlAvail) items.add(MITCRDUTLAVAIL);
			if (MspApp2Avail == comp.MspApp2Avail) items.add(MSPAPP2AVAIL);
			if (MitAppMlcAvail == comp.MitAppMlcAvail) items.add(MITAPPMLCAVAIL);
			if (MitAppLoiAvail == comp.MitAppLoiAvail) items.add(MITAPPLOIAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(SCRJREFDLGLOAINI, SCRJREFDLGMNGLIC, SCRJREFHEADBAR, SCRJREFPRE, PNLPREAVAIL, SCRJREFADMIN, PNLADMINAVAIL, SCRJREFGLOBAL, PNLGLOBALAVAIL, SCRJREFDEVDEV, PNLDEVDEVAVAIL, SCRJREFCOREDEV, PNLCOREDEVAVAIL, SCRJREFHIGH, PNLHIGHAVAIL, SCRJREFLOW, PNLLOWAVAIL, SCRJREFDEPLOY, PNLDEPLOYAVAIL, SCRJREFAUXFCT, PNLAUXFCTAVAIL, MITSESSPSAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MSPCRD2AVAIL, MITCRDMCHAVAIL, MITCRDLIBAVAIL, MITCRDFAMAVAIL, MITCRDSILAVAIL, MITCRDMTPAVAIL, MSPCRD3AVAIL, MITCRDPRJAVAIL, MITCRDVERAVAIL, MITCRDUNTAVAIL, MITCRDUNTACTIVE, MSPCRD4AVAIL, MITCRDCPRAVAIL, MITCRDCVRAVAIL, MSPCRD5AVAIL, MITCRDPPHAVAIL, MITCRDPPHACTIVE, MITCRDMODAVAIL, MITCRDMODACTIVE, MITCRDVECAVAIL, MITCRDVECACTIVE, MITCRDCMDAVAIL, MITCRDCMDACTIVE, MITCRDERRAVAIL, MITCRDERRACTIVE, MITCRDPPLAVAIL, MITCRDPPLACTIVE, MITCRDSEGAVAIL, MITCRDSEGACTIVE, MSPCRD6AVAIL, MITCRDBNKAVAIL, MITCRDBNKACTIVE, MITCRDPINAVAIL, MITCRDPINACTIVE, MITCRDINTAVAIL, MITCRDINTACTIVE, MITCRDSIGAVAIL, MITCRDSIGACTIVE, MSPCRD7AVAIL, MITCRDCMPAVAIL, MITCRDRLSAVAIL, MITCRDRLSACTIVE, MSPCRD8AVAIL, MITCRDUTLAVAIL, MSPAPP2AVAIL, MITAPPMLCAVAIL, MITAPPLOIAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNav)
	  */
	public class Tag extends Block {

		public static final int MITAPPABT = 1;
		public static final int MRLAPPHLP = 2;
		public static final int MITSESSPS = 3;
		public static final int MITSESTRM = 4;
		public static final int MITCRDUSG = 5;
		public static final int MITCRDUSR = 6;
		public static final int MITCRDPRS = 7;
		public static final int MITCRDFIL = 8;
		public static final int MITCRDMCH = 9;
		public static final int MITCRDLIB = 10;
		public static final int MITCRDFAM = 11;
		public static final int MITCRDSIL = 12;
		public static final int MITCRDMTP = 13;
		public static final int MITCRDPRJ = 14;
		public static final int MITCRDVER = 15;
		public static final int MITCRDUNT = 16;
		public static final int MITCRDCPR = 17;
		public static final int MITCRDCVR = 18;
		public static final int MITCRDPPH = 19;
		public static final int MITCRDMOD = 20;
		public static final int MITCRDVEC = 21;
		public static final int MITCRDCMD = 22;
		public static final int MITCRDERR = 23;
		public static final int MITCRDPPL = 24;
		public static final int MITCRDSEG = 25;
		public static final int MITCRDBNK = 26;
		public static final int MITCRDPIN = 27;
		public static final int MITCRDINT = 28;
		public static final int MITCRDSIG = 29;
		public static final int MITCRDCMP = 30;
		public static final int MITCRDRLS = 31;
		public static final int MITCRDUTL = 32;
		public static final int MITAPPMLC = 33;
		public static final int MITAPPLOI = 34;

		public Tag(
					String MitAppAbt
					, String MrlAppHlp
					, String MitSesSps
					, String MitSesTrm
					, String MitCrdUsg
					, String MitCrdUsr
					, String MitCrdPrs
					, String MitCrdFil
					, String MitCrdMch
					, String MitCrdLib
					, String MitCrdFam
					, String MitCrdSil
					, String MitCrdMtp
					, String MitCrdPrj
					, String MitCrdVer
					, String MitCrdUnt
					, String MitCrdCpr
					, String MitCrdCvr
					, String MitCrdPph
					, String MitCrdMod
					, String MitCrdVec
					, String MitCrdCmd
					, String MitCrdErr
					, String MitCrdPpl
					, String MitCrdSeg
					, String MitCrdBnk
					, String MitCrdPin
					, String MitCrdInt
					, String MitCrdSig
					, String MitCrdCmp
					, String MitCrdRls
					, String MitCrdUtl
					, String MitAppMlc
					, String MitAppLoi
				) {
			this.MitAppAbt = MitAppAbt;
			this.MrlAppHlp = MrlAppHlp;
			this.MitSesSps = MitSesSps;
			this.MitSesTrm = MitSesTrm;
			this.MitCrdUsg = MitCrdUsg;
			this.MitCrdUsr = MitCrdUsr;
			this.MitCrdPrs = MitCrdPrs;
			this.MitCrdFil = MitCrdFil;
			this.MitCrdMch = MitCrdMch;
			this.MitCrdLib = MitCrdLib;
			this.MitCrdFam = MitCrdFam;
			this.MitCrdSil = MitCrdSil;
			this.MitCrdMtp = MitCrdMtp;
			this.MitCrdPrj = MitCrdPrj;
			this.MitCrdVer = MitCrdVer;
			this.MitCrdUnt = MitCrdUnt;
			this.MitCrdCpr = MitCrdCpr;
			this.MitCrdCvr = MitCrdCvr;
			this.MitCrdPph = MitCrdPph;
			this.MitCrdMod = MitCrdMod;
			this.MitCrdVec = MitCrdVec;
			this.MitCrdCmd = MitCrdCmd;
			this.MitCrdErr = MitCrdErr;
			this.MitCrdPpl = MitCrdPpl;
			this.MitCrdSeg = MitCrdSeg;
			this.MitCrdBnk = MitCrdBnk;
			this.MitCrdPin = MitCrdPin;
			this.MitCrdInt = MitCrdInt;
			this.MitCrdSig = MitCrdSig;
			this.MitCrdCmp = MitCrdCmp;
			this.MitCrdRls = MitCrdRls;
			this.MitCrdUtl = MitCrdUtl;
			this.MitAppMlc = MitAppMlc;
			this.MitAppLoi = MitAppLoi;

			mask = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITSESSPS, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDFIL, MITCRDMCH, MITCRDLIB, MITCRDFAM, MITCRDSIL, MITCRDMTP, MITCRDPRJ, MITCRDVER, MITCRDUNT, MITCRDCPR, MITCRDCVR, MITCRDPPH, MITCRDMOD, MITCRDVEC, MITCRDCMD, MITCRDERR, MITCRDPPL, MITCRDSEG, MITCRDBNK, MITCRDPIN, MITCRDINT, MITCRDSIG, MITCRDCMP, MITCRDRLS, MITCRDUTL, MITAPPMLC, MITAPPLOI));
		};

		public String MitAppAbt;
		public String MrlAppHlp;
		public String MitSesSps;
		public String MitSesTrm;
		public String MitCrdUsg;
		public String MitCrdUsr;
		public String MitCrdPrs;
		public String MitCrdFil;
		public String MitCrdMch;
		public String MitCrdLib;
		public String MitCrdFam;
		public String MitCrdSil;
		public String MitCrdMtp;
		public String MitCrdPrj;
		public String MitCrdVer;
		public String MitCrdUnt;
		public String MitCrdCpr;
		public String MitCrdCvr;
		public String MitCrdPph;
		public String MitCrdMod;
		public String MitCrdVec;
		public String MitCrdCmd;
		public String MitCrdErr;
		public String MitCrdPpl;
		public String MitCrdSeg;
		public String MitCrdBnk;
		public String MitCrdPin;
		public String MitCrdInt;
		public String MitCrdSig;
		public String MitCrdCmp;
		public String MitCrdRls;
		public String MitCrdUtl;
		public String MitAppMlc;
		public String MitAppLoi;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNav");

			String itemtag = "TagitemWdbeNav";

			if (Xmlio.checkXPath(doc, basexpath)) {
				MitAppAbt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppAbt", mask, MITAPPABT);
				MrlAppHlp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MrlAppHlp", mask, MRLAPPHLP);
				MitSesSps = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitSesSps", mask, MITSESSPS);
				MitSesTrm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitSesTrm", mask, MITSESTRM);
				MitCrdUsg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdUsg", mask, MITCRDUSG);
				MitCrdUsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdUsr", mask, MITCRDUSR);
				MitCrdPrs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPrs", mask, MITCRDPRS);
				MitCrdFil = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdFil", mask, MITCRDFIL);
				MitCrdMch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdMch", mask, MITCRDMCH);
				MitCrdLib = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdLib", mask, MITCRDLIB);
				MitCrdFam = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdFam", mask, MITCRDFAM);
				MitCrdSil = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdSil", mask, MITCRDSIL);
				MitCrdMtp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdMtp", mask, MITCRDMTP);
				MitCrdPrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPrj", mask, MITCRDPRJ);
				MitCrdVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdVer", mask, MITCRDVER);
				MitCrdUnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdUnt", mask, MITCRDUNT);
				MitCrdCpr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCpr", mask, MITCRDCPR);
				MitCrdCvr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCvr", mask, MITCRDCVR);
				MitCrdPph = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPph", mask, MITCRDPPH);
				MitCrdMod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdMod", mask, MITCRDMOD);
				MitCrdVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdVec", mask, MITCRDVEC);
				MitCrdCmd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCmd", mask, MITCRDCMD);
				MitCrdErr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdErr", mask, MITCRDERR);
				MitCrdPpl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPpl", mask, MITCRDPPL);
				MitCrdSeg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdSeg", mask, MITCRDSEG);
				MitCrdBnk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdBnk", mask, MITCRDBNK);
				MitCrdPin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdPin", mask, MITCRDPIN);
				MitCrdInt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdInt", mask, MITCRDINT);
				MitCrdSig = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdSig", mask, MITCRDSIG);
				MitCrdCmp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdCmp", mask, MITCRDCMP);
				MitCrdRls = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdRls", mask, MITCRDRLS);
				MitCrdUtl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitCrdUtl", mask, MITCRDUTL);
				MitAppMlc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppMlc", mask, MITAPPMLC);
				MitAppLoi = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "MitAppLoi", mask, MITAPPLOI);

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
			if (MitSesSps.equals(comp.MitSesSps)) items.add(MITSESSPS);
			if (MitSesTrm.equals(comp.MitSesTrm)) items.add(MITSESTRM);
			if (MitCrdUsg.equals(comp.MitCrdUsg)) items.add(MITCRDUSG);
			if (MitCrdUsr.equals(comp.MitCrdUsr)) items.add(MITCRDUSR);
			if (MitCrdPrs.equals(comp.MitCrdPrs)) items.add(MITCRDPRS);
			if (MitCrdFil.equals(comp.MitCrdFil)) items.add(MITCRDFIL);
			if (MitCrdMch.equals(comp.MitCrdMch)) items.add(MITCRDMCH);
			if (MitCrdLib.equals(comp.MitCrdLib)) items.add(MITCRDLIB);
			if (MitCrdFam.equals(comp.MitCrdFam)) items.add(MITCRDFAM);
			if (MitCrdSil.equals(comp.MitCrdSil)) items.add(MITCRDSIL);
			if (MitCrdMtp.equals(comp.MitCrdMtp)) items.add(MITCRDMTP);
			if (MitCrdPrj.equals(comp.MitCrdPrj)) items.add(MITCRDPRJ);
			if (MitCrdVer.equals(comp.MitCrdVer)) items.add(MITCRDVER);
			if (MitCrdUnt.equals(comp.MitCrdUnt)) items.add(MITCRDUNT);
			if (MitCrdCpr.equals(comp.MitCrdCpr)) items.add(MITCRDCPR);
			if (MitCrdCvr.equals(comp.MitCrdCvr)) items.add(MITCRDCVR);
			if (MitCrdPph.equals(comp.MitCrdPph)) items.add(MITCRDPPH);
			if (MitCrdMod.equals(comp.MitCrdMod)) items.add(MITCRDMOD);
			if (MitCrdVec.equals(comp.MitCrdVec)) items.add(MITCRDVEC);
			if (MitCrdCmd.equals(comp.MitCrdCmd)) items.add(MITCRDCMD);
			if (MitCrdErr.equals(comp.MitCrdErr)) items.add(MITCRDERR);
			if (MitCrdPpl.equals(comp.MitCrdPpl)) items.add(MITCRDPPL);
			if (MitCrdSeg.equals(comp.MitCrdSeg)) items.add(MITCRDSEG);
			if (MitCrdBnk.equals(comp.MitCrdBnk)) items.add(MITCRDBNK);
			if (MitCrdPin.equals(comp.MitCrdPin)) items.add(MITCRDPIN);
			if (MitCrdInt.equals(comp.MitCrdInt)) items.add(MITCRDINT);
			if (MitCrdSig.equals(comp.MitCrdSig)) items.add(MITCRDSIG);
			if (MitCrdCmp.equals(comp.MitCrdCmp)) items.add(MITCRDCMP);
			if (MitCrdRls.equals(comp.MitCrdRls)) items.add(MITCRDRLS);
			if (MitCrdUtl.equals(comp.MitCrdUtl)) items.add(MITCRDUTL);
			if (MitAppMlc.equals(comp.MitAppMlc)) items.add(MITAPPMLC);
			if (MitAppLoi.equals(comp.MitAppLoi)) items.add(MITAPPLOI);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(MITAPPABT, MRLAPPHLP, MITSESSPS, MITSESTRM, MITCRDUSG, MITCRDUSR, MITCRDPRS, MITCRDFIL, MITCRDMCH, MITCRDLIB, MITCRDFAM, MITCRDSIL, MITCRDMTP, MITCRDPRJ, MITCRDVER, MITCRDUNT, MITCRDCPR, MITCRDCVR, MITCRDPPH, MITCRDMOD, MITCRDVEC, MITCRDCMD, MITCRDERR, MITCRDPPL, MITCRDSEG, MITCRDBNK, MITCRDPIN, MITCRDINT, MITCRDSIG, MITCRDCMP, MITCRDRLS, MITCRDUTL, MITAPPMLC, MITAPPLOI));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFSGE = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVDATA);

			continf = new ContInf(0, "", "", "", "");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(0, 0, "", 0, false, false, false, false, false, false, false, false, false, false);
			statshr = new StatShr("", "", "", "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf(0, "", "", "", "");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(0, 0, "", 0, false, false, false, false, false, false, false, false, false, false);
				statshr = new StatShr("", "", "", "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, "", false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
