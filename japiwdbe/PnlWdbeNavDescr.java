/**
  * \file PnlWdbeNavDescr.java
  * Java API code for job PnlWdbeNavDescr
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeNavDescr {
	/**
		* VecVDo (full: VecVWdbeNavDescrDo)
		*/
	public static class VecVDo {

		public static final int BUTMODVIEWCLICK = 1;
		public static final int BUTMODNEWCRDCLICK = 2;
		public static final int BUTVECVIEWCLICK = 3;
		public static final int BUTVECNEWCRDCLICK = 4;
		public static final int BUTVITVIEWCLICK = 5;
		public static final int BUTCMDVIEWCLICK = 6;
		public static final int BUTCMDNEWCRDCLICK = 7;
		public static final int BUTERRVIEWCLICK = 8;
		public static final int BUTERRNEWCRDCLICK = 9;
		public static final int BUTPPHVIEWCLICK = 10;
		public static final int BUTPPHNEWCRDCLICK = 11;
		public static final int BUTBNKVIEWCLICK = 12;
		public static final int BUTBNKNEWCRDCLICK = 13;
		public static final int BUTPINVIEWCLICK = 14;
		public static final int BUTPINNEWCRDCLICK = 15;
		public static final int BUTGENVIEWCLICK = 16;
		public static final int BUTPRTVIEWCLICK = 17;
		public static final int BUTSIGVIEWCLICK = 18;
		public static final int BUTPRCVIEWCLICK = 19;
		public static final int BUTFSTVIEWCLICK = 20;
		public static final int BUTVARVIEWCLICK = 21;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butmodviewclick")) return BUTMODVIEWCLICK;
			if (s.equals("butmodnewcrdclick")) return BUTMODNEWCRDCLICK;
			if (s.equals("butvecviewclick")) return BUTVECVIEWCLICK;
			if (s.equals("butvecnewcrdclick")) return BUTVECNEWCRDCLICK;
			if (s.equals("butvitviewclick")) return BUTVITVIEWCLICK;
			if (s.equals("butcmdviewclick")) return BUTCMDVIEWCLICK;
			if (s.equals("butcmdnewcrdclick")) return BUTCMDNEWCRDCLICK;
			if (s.equals("buterrviewclick")) return BUTERRVIEWCLICK;
			if (s.equals("buterrnewcrdclick")) return BUTERRNEWCRDCLICK;
			if (s.equals("butpphviewclick")) return BUTPPHVIEWCLICK;
			if (s.equals("butpphnewcrdclick")) return BUTPPHNEWCRDCLICK;
			if (s.equals("butbnkviewclick")) return BUTBNKVIEWCLICK;
			if (s.equals("butbnknewcrdclick")) return BUTBNKNEWCRDCLICK;
			if (s.equals("butpinviewclick")) return BUTPINVIEWCLICK;
			if (s.equals("butpinnewcrdclick")) return BUTPINNEWCRDCLICK;
			if (s.equals("butgenviewclick")) return BUTGENVIEWCLICK;
			if (s.equals("butprtviewclick")) return BUTPRTVIEWCLICK;
			if (s.equals("butsigviewclick")) return BUTSIGVIEWCLICK;
			if (s.equals("butprcviewclick")) return BUTPRCVIEWCLICK;
			if (s.equals("butfstviewclick")) return BUTFSTVIEWCLICK;
			if (s.equals("butvarviewclick")) return BUTVARVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMODVIEWCLICK) return("ButModViewClick");
			if (ix == BUTMODNEWCRDCLICK) return("ButModNewcrdClick");
			if (ix == BUTVECVIEWCLICK) return("ButVecViewClick");
			if (ix == BUTVECNEWCRDCLICK) return("ButVecNewcrdClick");
			if (ix == BUTVITVIEWCLICK) return("ButVitViewClick");
			if (ix == BUTCMDVIEWCLICK) return("ButCmdViewClick");
			if (ix == BUTCMDNEWCRDCLICK) return("ButCmdNewcrdClick");
			if (ix == BUTERRVIEWCLICK) return("ButErrViewClick");
			if (ix == BUTERRNEWCRDCLICK) return("ButErrNewcrdClick");
			if (ix == BUTPPHVIEWCLICK) return("ButPphViewClick");
			if (ix == BUTPPHNEWCRDCLICK) return("ButPphNewcrdClick");
			if (ix == BUTBNKVIEWCLICK) return("ButBnkViewClick");
			if (ix == BUTBNKNEWCRDCLICK) return("ButBnkNewcrdClick");
			if (ix == BUTPINVIEWCLICK) return("ButPinViewClick");
			if (ix == BUTPINNEWCRDCLICK) return("ButPinNewcrdClick");
			if (ix == BUTGENVIEWCLICK) return("ButGenViewClick");
			if (ix == BUTPRTVIEWCLICK) return("ButPrtViewClick");
			if (ix == BUTSIGVIEWCLICK) return("ButSigViewClick");
			if (ix == BUTPRCVIEWCLICK) return("ButPrcViewClick");
			if (ix == BUTFSTVIEWCLICK) return("ButFstViewClick");
			if (ix == BUTVARVIEWCLICK) return("ButVarViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeNavDescr)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTMOD = 1;
		public static final int NUMFLSTVEC = 2;
		public static final int NUMFLSTVIT = 3;
		public static final int NUMFLSTCMD = 4;
		public static final int NUMFLSTERR = 5;
		public static final int NUMFLSTPPH = 6;
		public static final int NUMFLSTBNK = 7;
		public static final int NUMFLSTPIN = 8;
		public static final int NUMFLSTGEN = 9;
		public static final int NUMFLSTPRT = 10;
		public static final int NUMFLSTSIG = 11;
		public static final int NUMFLSTPRC = 12;
		public static final int NUMFLSTFST = 13;
		public static final int NUMFLSTVAR = 14;

		public ContIac(
					int numFLstMod
					, int numFLstVec
					, int numFLstVit
					, int numFLstCmd
					, int numFLstErr
					, int numFLstPph
					, int numFLstBnk
					, int numFLstPin
					, int numFLstGen
					, int numFLstPrt
					, int numFLstSig
					, int numFLstPrc
					, int numFLstFst
					, int numFLstVar
				) {
			this.numFLstMod = numFLstMod;
			this.numFLstVec = numFLstVec;
			this.numFLstVit = numFLstVit;
			this.numFLstCmd = numFLstCmd;
			this.numFLstErr = numFLstErr;
			this.numFLstPph = numFLstPph;
			this.numFLstBnk = numFLstBnk;
			this.numFLstPin = numFLstPin;
			this.numFLstGen = numFLstGen;
			this.numFLstPrt = numFLstPrt;
			this.numFLstSig = numFLstSig;
			this.numFLstPrc = numFLstPrc;
			this.numFLstFst = numFLstFst;
			this.numFLstVar = numFLstVar;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTMOD, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCMD, NUMFLSTERR, NUMFLSTPPH, NUMFLSTBNK, NUMFLSTPIN, NUMFLSTGEN, NUMFLSTPRT, NUMFLSTSIG, NUMFLSTPRC, NUMFLSTFST, NUMFLSTVAR));
		};

		public int numFLstMod;
		public int numFLstVec;
		public int numFLstVit;
		public int numFLstCmd;
		public int numFLstErr;
		public int numFLstPph;
		public int numFLstBnk;
		public int numFLstPin;
		public int numFLstGen;
		public int numFLstPrt;
		public int numFLstSig;
		public int numFLstPrc;
		public int numFLstFst;
		public int numFLstVar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeNavDescr");

			String itemtag = "ContitemIacWdbeNavDescr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstMod = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstMod", mask, NUMFLSTMOD);
				numFLstVec = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVec", mask, NUMFLSTVEC);
				numFLstVit = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVit", mask, NUMFLSTVIT);
				numFLstCmd = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstCmd", mask, NUMFLSTCMD);
				numFLstErr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstErr", mask, NUMFLSTERR);
				numFLstPph = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPph", mask, NUMFLSTPPH);
				numFLstBnk = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstBnk", mask, NUMFLSTBNK);
				numFLstPin = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPin", mask, NUMFLSTPIN);
				numFLstGen = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstGen", mask, NUMFLSTGEN);
				numFLstPrt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPrt", mask, NUMFLSTPRT);
				numFLstSig = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSig", mask, NUMFLSTSIG);
				numFLstPrc = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPrc", mask, NUMFLSTPRC);
				numFLstFst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstFst", mask, NUMFLSTFST);
				numFLstVar = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVar", mask, NUMFLSTVAR);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeNavDescr";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeNavDescr";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstMod", numFLstMod);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVec", numFLstVec);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVit", numFLstVit);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstCmd", numFLstCmd);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstErr", numFLstErr);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPph", numFLstPph);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstBnk", numFLstBnk);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPin", numFLstPin);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstGen", numFLstGen);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPrt", numFLstPrt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSig", numFLstSig);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPrc", numFLstPrc);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstFst", numFLstFst);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVar", numFLstVar);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstMod == comp.numFLstMod) items.add(NUMFLSTMOD);
			if (numFLstVec == comp.numFLstVec) items.add(NUMFLSTVEC);
			if (numFLstVit == comp.numFLstVit) items.add(NUMFLSTVIT);
			if (numFLstCmd == comp.numFLstCmd) items.add(NUMFLSTCMD);
			if (numFLstErr == comp.numFLstErr) items.add(NUMFLSTERR);
			if (numFLstPph == comp.numFLstPph) items.add(NUMFLSTPPH);
			if (numFLstBnk == comp.numFLstBnk) items.add(NUMFLSTBNK);
			if (numFLstPin == comp.numFLstPin) items.add(NUMFLSTPIN);
			if (numFLstGen == comp.numFLstGen) items.add(NUMFLSTGEN);
			if (numFLstPrt == comp.numFLstPrt) items.add(NUMFLSTPRT);
			if (numFLstSig == comp.numFLstSig) items.add(NUMFLSTSIG);
			if (numFLstPrc == comp.numFLstPrc) items.add(NUMFLSTPRC);
			if (numFLstFst == comp.numFLstFst) items.add(NUMFLSTFST);
			if (numFLstVar == comp.numFLstVar) items.add(NUMFLSTVAR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTMOD, NUMFLSTVEC, NUMFLSTVIT, NUMFLSTCMD, NUMFLSTERR, NUMFLSTPPH, NUMFLSTBNK, NUMFLSTPIN, NUMFLSTGEN, NUMFLSTPRT, NUMFLSTSIG, NUMFLSTPRC, NUMFLSTFST, NUMFLSTVAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeNavDescr)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTMODALT = 2;
		public static final int LSTVECALT = 3;
		public static final int LSTVITALT = 4;
		public static final int LSTCMDALT = 5;
		public static final int LSTERRALT = 6;
		public static final int LSTPPHALT = 7;
		public static final int LSTBNKALT = 8;
		public static final int LSTPINALT = 9;
		public static final int LSTGENALT = 10;
		public static final int LSTPRTALT = 11;
		public static final int LSTSIGALT = 12;
		public static final int LSTPRCALT = 13;
		public static final int LSTFSTALT = 14;
		public static final int LSTVARALT = 15;
		public static final int LSTMODNUMFIRSTDISP = 16;
		public static final int LSTVECNUMFIRSTDISP = 17;
		public static final int LSTVITNUMFIRSTDISP = 18;
		public static final int LSTCMDNUMFIRSTDISP = 19;
		public static final int LSTERRNUMFIRSTDISP = 20;
		public static final int LSTPPHNUMFIRSTDISP = 21;
		public static final int LSTBNKNUMFIRSTDISP = 22;
		public static final int LSTPINNUMFIRSTDISP = 23;
		public static final int LSTGENNUMFIRSTDISP = 24;
		public static final int LSTPRTNUMFIRSTDISP = 25;
		public static final int LSTSIGNUMFIRSTDISP = 26;
		public static final int LSTPRCNUMFIRSTDISP = 27;
		public static final int LSTFSTNUMFIRSTDISP = 28;
		public static final int LSTVARNUMFIRSTDISP = 29;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstModAlt
					, boolean LstVecAlt
					, boolean LstVitAlt
					, boolean LstCmdAlt
					, boolean LstErrAlt
					, boolean LstPphAlt
					, boolean LstBnkAlt
					, boolean LstPinAlt
					, boolean LstGenAlt
					, boolean LstPrtAlt
					, boolean LstSigAlt
					, boolean LstPrcAlt
					, boolean LstFstAlt
					, boolean LstVarAlt
					, int LstModNumFirstdisp
					, int LstVecNumFirstdisp
					, int LstVitNumFirstdisp
					, int LstCmdNumFirstdisp
					, int LstErrNumFirstdisp
					, int LstPphNumFirstdisp
					, int LstBnkNumFirstdisp
					, int LstPinNumFirstdisp
					, int LstGenNumFirstdisp
					, int LstPrtNumFirstdisp
					, int LstSigNumFirstdisp
					, int LstPrcNumFirstdisp
					, int LstFstNumFirstdisp
					, int LstVarNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstModAlt = LstModAlt;
			this.LstVecAlt = LstVecAlt;
			this.LstVitAlt = LstVitAlt;
			this.LstCmdAlt = LstCmdAlt;
			this.LstErrAlt = LstErrAlt;
			this.LstPphAlt = LstPphAlt;
			this.LstBnkAlt = LstBnkAlt;
			this.LstPinAlt = LstPinAlt;
			this.LstGenAlt = LstGenAlt;
			this.LstPrtAlt = LstPrtAlt;
			this.LstSigAlt = LstSigAlt;
			this.LstPrcAlt = LstPrcAlt;
			this.LstFstAlt = LstFstAlt;
			this.LstVarAlt = LstVarAlt;
			this.LstModNumFirstdisp = LstModNumFirstdisp;
			this.LstVecNumFirstdisp = LstVecNumFirstdisp;
			this.LstVitNumFirstdisp = LstVitNumFirstdisp;
			this.LstCmdNumFirstdisp = LstCmdNumFirstdisp;
			this.LstErrNumFirstdisp = LstErrNumFirstdisp;
			this.LstPphNumFirstdisp = LstPphNumFirstdisp;
			this.LstBnkNumFirstdisp = LstBnkNumFirstdisp;
			this.LstPinNumFirstdisp = LstPinNumFirstdisp;
			this.LstGenNumFirstdisp = LstGenNumFirstdisp;
			this.LstPrtNumFirstdisp = LstPrtNumFirstdisp;
			this.LstSigNumFirstdisp = LstSigNumFirstdisp;
			this.LstPrcNumFirstdisp = LstPrcNumFirstdisp;
			this.LstFstNumFirstdisp = LstFstNumFirstdisp;
			this.LstVarNumFirstdisp = LstVarNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTMODALT, LSTVECALT, LSTVITALT, LSTCMDALT, LSTERRALT, LSTPPHALT, LSTBNKALT, LSTPINALT, LSTGENALT, LSTPRTALT, LSTSIGALT, LSTPRCALT, LSTFSTALT, LSTVARALT, LSTMODNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCMDNUMFIRSTDISP, LSTERRNUMFIRSTDISP, LSTPPHNUMFIRSTDISP, LSTBNKNUMFIRSTDISP, LSTPINNUMFIRSTDISP, LSTGENNUMFIRSTDISP, LSTPRTNUMFIRSTDISP, LSTSIGNUMFIRSTDISP, LSTPRCNUMFIRSTDISP, LSTFSTNUMFIRSTDISP, LSTVARNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstModAlt;
		public boolean LstVecAlt;
		public boolean LstVitAlt;
		public boolean LstCmdAlt;
		public boolean LstErrAlt;
		public boolean LstPphAlt;
		public boolean LstBnkAlt;
		public boolean LstPinAlt;
		public boolean LstGenAlt;
		public boolean LstPrtAlt;
		public boolean LstSigAlt;
		public boolean LstPrcAlt;
		public boolean LstFstAlt;
		public boolean LstVarAlt;
		public int LstModNumFirstdisp;
		public int LstVecNumFirstdisp;
		public int LstVitNumFirstdisp;
		public int LstCmdNumFirstdisp;
		public int LstErrNumFirstdisp;
		public int LstPphNumFirstdisp;
		public int LstBnkNumFirstdisp;
		public int LstPinNumFirstdisp;
		public int LstGenNumFirstdisp;
		public int LstPrtNumFirstdisp;
		public int LstSigNumFirstdisp;
		public int LstPrcNumFirstdisp;
		public int LstFstNumFirstdisp;
		public int LstVarNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeNavDescr");

			String itemtag = "StatitemAppWdbeNavDescr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstModAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstModAlt", mask, LSTMODALT);
				LstVecAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVecAlt", mask, LSTVECALT);
				LstVitAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVitAlt", mask, LSTVITALT);
				LstCmdAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCmdAlt", mask, LSTCMDALT);
				LstErrAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstErrAlt", mask, LSTERRALT);
				LstPphAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPphAlt", mask, LSTPPHALT);
				LstBnkAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBnkAlt", mask, LSTBNKALT);
				LstPinAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPinAlt", mask, LSTPINALT);
				LstGenAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstGenAlt", mask, LSTGENALT);
				LstPrtAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrtAlt", mask, LSTPRTALT);
				LstSigAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSigAlt", mask, LSTSIGALT);
				LstPrcAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrcAlt", mask, LSTPRCALT);
				LstFstAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFstAlt", mask, LSTFSTALT);
				LstVarAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVarAlt", mask, LSTVARALT);
				LstModNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstModNumFirstdisp", mask, LSTMODNUMFIRSTDISP);
				LstVecNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVecNumFirstdisp", mask, LSTVECNUMFIRSTDISP);
				LstVitNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVitNumFirstdisp", mask, LSTVITNUMFIRSTDISP);
				LstCmdNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCmdNumFirstdisp", mask, LSTCMDNUMFIRSTDISP);
				LstErrNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstErrNumFirstdisp", mask, LSTERRNUMFIRSTDISP);
				LstPphNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPphNumFirstdisp", mask, LSTPPHNUMFIRSTDISP);
				LstBnkNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBnkNumFirstdisp", mask, LSTBNKNUMFIRSTDISP);
				LstPinNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPinNumFirstdisp", mask, LSTPINNUMFIRSTDISP);
				LstGenNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstGenNumFirstdisp", mask, LSTGENNUMFIRSTDISP);
				LstPrtNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrtNumFirstdisp", mask, LSTPRTNUMFIRSTDISP);
				LstSigNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSigNumFirstdisp", mask, LSTSIGNUMFIRSTDISP);
				LstPrcNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrcNumFirstdisp", mask, LSTPRCNUMFIRSTDISP);
				LstFstNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFstNumFirstdisp", mask, LSTFSTNUMFIRSTDISP);
				LstVarNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVarNumFirstdisp", mask, LSTVARNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstModAlt == comp.LstModAlt) items.add(LSTMODALT);
			if (LstVecAlt == comp.LstVecAlt) items.add(LSTVECALT);
			if (LstVitAlt == comp.LstVitAlt) items.add(LSTVITALT);
			if (LstCmdAlt == comp.LstCmdAlt) items.add(LSTCMDALT);
			if (LstErrAlt == comp.LstErrAlt) items.add(LSTERRALT);
			if (LstPphAlt == comp.LstPphAlt) items.add(LSTPPHALT);
			if (LstBnkAlt == comp.LstBnkAlt) items.add(LSTBNKALT);
			if (LstPinAlt == comp.LstPinAlt) items.add(LSTPINALT);
			if (LstGenAlt == comp.LstGenAlt) items.add(LSTGENALT);
			if (LstPrtAlt == comp.LstPrtAlt) items.add(LSTPRTALT);
			if (LstSigAlt == comp.LstSigAlt) items.add(LSTSIGALT);
			if (LstPrcAlt == comp.LstPrcAlt) items.add(LSTPRCALT);
			if (LstFstAlt == comp.LstFstAlt) items.add(LSTFSTALT);
			if (LstVarAlt == comp.LstVarAlt) items.add(LSTVARALT);
			if (LstModNumFirstdisp == comp.LstModNumFirstdisp) items.add(LSTMODNUMFIRSTDISP);
			if (LstVecNumFirstdisp == comp.LstVecNumFirstdisp) items.add(LSTVECNUMFIRSTDISP);
			if (LstVitNumFirstdisp == comp.LstVitNumFirstdisp) items.add(LSTVITNUMFIRSTDISP);
			if (LstCmdNumFirstdisp == comp.LstCmdNumFirstdisp) items.add(LSTCMDNUMFIRSTDISP);
			if (LstErrNumFirstdisp == comp.LstErrNumFirstdisp) items.add(LSTERRNUMFIRSTDISP);
			if (LstPphNumFirstdisp == comp.LstPphNumFirstdisp) items.add(LSTPPHNUMFIRSTDISP);
			if (LstBnkNumFirstdisp == comp.LstBnkNumFirstdisp) items.add(LSTBNKNUMFIRSTDISP);
			if (LstPinNumFirstdisp == comp.LstPinNumFirstdisp) items.add(LSTPINNUMFIRSTDISP);
			if (LstGenNumFirstdisp == comp.LstGenNumFirstdisp) items.add(LSTGENNUMFIRSTDISP);
			if (LstPrtNumFirstdisp == comp.LstPrtNumFirstdisp) items.add(LSTPRTNUMFIRSTDISP);
			if (LstSigNumFirstdisp == comp.LstSigNumFirstdisp) items.add(LSTSIGNUMFIRSTDISP);
			if (LstPrcNumFirstdisp == comp.LstPrcNumFirstdisp) items.add(LSTPRCNUMFIRSTDISP);
			if (LstFstNumFirstdisp == comp.LstFstNumFirstdisp) items.add(LSTFSTNUMFIRSTDISP);
			if (LstVarNumFirstdisp == comp.LstVarNumFirstdisp) items.add(LSTVARNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTMODALT, LSTVECALT, LSTVITALT, LSTCMDALT, LSTERRALT, LSTPPHALT, LSTBNKALT, LSTPINALT, LSTGENALT, LSTPRTALT, LSTSIGALT, LSTPRCALT, LSTFSTALT, LSTVARALT, LSTMODNUMFIRSTDISP, LSTVECNUMFIRSTDISP, LSTVITNUMFIRSTDISP, LSTCMDNUMFIRSTDISP, LSTERRNUMFIRSTDISP, LSTPPHNUMFIRSTDISP, LSTBNKNUMFIRSTDISP, LSTPINNUMFIRSTDISP, LSTGENNUMFIRSTDISP, LSTPRTNUMFIRSTDISP, LSTSIGNUMFIRSTDISP, LSTPRCNUMFIRSTDISP, LSTFSTNUMFIRSTDISP, LSTVARNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeNavDescr)
	  */
	public class StatShr extends Block {

		public static final int LSTMODAVAIL = 1;
		public static final int BUTMODVIEWACTIVE = 2;
		public static final int BUTMODNEWCRDACTIVE = 3;
		public static final int LSTVECAVAIL = 4;
		public static final int BUTVECVIEWACTIVE = 5;
		public static final int BUTVECNEWCRDACTIVE = 6;
		public static final int LSTVITAVAIL = 7;
		public static final int BUTVITVIEWACTIVE = 8;
		public static final int LSTCMDAVAIL = 9;
		public static final int BUTCMDVIEWACTIVE = 10;
		public static final int BUTCMDNEWCRDACTIVE = 11;
		public static final int LSTERRAVAIL = 12;
		public static final int BUTERRVIEWACTIVE = 13;
		public static final int BUTERRNEWCRDACTIVE = 14;
		public static final int LSTPPHAVAIL = 15;
		public static final int BUTPPHVIEWACTIVE = 16;
		public static final int BUTPPHNEWCRDACTIVE = 17;
		public static final int LSTBNKAVAIL = 18;
		public static final int BUTBNKVIEWACTIVE = 19;
		public static final int BUTBNKNEWCRDACTIVE = 20;
		public static final int LSTPINAVAIL = 21;
		public static final int BUTPINVIEWACTIVE = 22;
		public static final int BUTPINNEWCRDACTIVE = 23;
		public static final int LSTGENAVAIL = 24;
		public static final int BUTGENVIEWACTIVE = 25;
		public static final int LSTPRTAVAIL = 26;
		public static final int BUTPRTVIEWACTIVE = 27;
		public static final int LSTSIGAVAIL = 28;
		public static final int BUTSIGVIEWACTIVE = 29;
		public static final int LSTPRCAVAIL = 30;
		public static final int BUTPRCVIEWACTIVE = 31;
		public static final int LSTFSTAVAIL = 32;
		public static final int BUTFSTVIEWACTIVE = 33;
		public static final int LSTVARAVAIL = 34;
		public static final int BUTVARVIEWACTIVE = 35;

		public StatShr(
					boolean LstModAvail
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
					, boolean LstPphAvail
					, boolean ButPphViewActive
					, boolean ButPphNewcrdActive
					, boolean LstBnkAvail
					, boolean ButBnkViewActive
					, boolean ButBnkNewcrdActive
					, boolean LstPinAvail
					, boolean ButPinViewActive
					, boolean ButPinNewcrdActive
					, boolean LstGenAvail
					, boolean ButGenViewActive
					, boolean LstPrtAvail
					, boolean ButPrtViewActive
					, boolean LstSigAvail
					, boolean ButSigViewActive
					, boolean LstPrcAvail
					, boolean ButPrcViewActive
					, boolean LstFstAvail
					, boolean ButFstViewActive
					, boolean LstVarAvail
					, boolean ButVarViewActive
				) {
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
			this.LstPphAvail = LstPphAvail;
			this.ButPphViewActive = ButPphViewActive;
			this.ButPphNewcrdActive = ButPphNewcrdActive;
			this.LstBnkAvail = LstBnkAvail;
			this.ButBnkViewActive = ButBnkViewActive;
			this.ButBnkNewcrdActive = ButBnkNewcrdActive;
			this.LstPinAvail = LstPinAvail;
			this.ButPinViewActive = ButPinViewActive;
			this.ButPinNewcrdActive = ButPinNewcrdActive;
			this.LstGenAvail = LstGenAvail;
			this.ButGenViewActive = ButGenViewActive;
			this.LstPrtAvail = LstPrtAvail;
			this.ButPrtViewActive = ButPrtViewActive;
			this.LstSigAvail = LstSigAvail;
			this.ButSigViewActive = ButSigViewActive;
			this.LstPrcAvail = LstPrcAvail;
			this.ButPrcViewActive = ButPrcViewActive;
			this.LstFstAvail = LstFstAvail;
			this.ButFstViewActive = ButFstViewActive;
			this.LstVarAvail = LstVarAvail;
			this.ButVarViewActive = ButVarViewActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTMODAVAIL, BUTMODVIEWACTIVE, BUTMODNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, LSTCMDAVAIL, BUTCMDVIEWACTIVE, BUTCMDNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE, LSTPPHAVAIL, BUTPPHVIEWACTIVE, BUTPPHNEWCRDACTIVE, LSTBNKAVAIL, BUTBNKVIEWACTIVE, BUTBNKNEWCRDACTIVE, LSTPINAVAIL, BUTPINVIEWACTIVE, BUTPINNEWCRDACTIVE, LSTGENAVAIL, BUTGENVIEWACTIVE, LSTPRTAVAIL, BUTPRTVIEWACTIVE, LSTSIGAVAIL, BUTSIGVIEWACTIVE, LSTPRCAVAIL, BUTPRCVIEWACTIVE, LSTFSTAVAIL, BUTFSTVIEWACTIVE, LSTVARAVAIL, BUTVARVIEWACTIVE));
		};

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
		public boolean LstPphAvail;
		public boolean ButPphViewActive;
		public boolean ButPphNewcrdActive;
		public boolean LstBnkAvail;
		public boolean ButBnkViewActive;
		public boolean ButBnkNewcrdActive;
		public boolean LstPinAvail;
		public boolean ButPinViewActive;
		public boolean ButPinNewcrdActive;
		public boolean LstGenAvail;
		public boolean ButGenViewActive;
		public boolean LstPrtAvail;
		public boolean ButPrtViewActive;
		public boolean LstSigAvail;
		public boolean ButSigViewActive;
		public boolean LstPrcAvail;
		public boolean ButPrcViewActive;
		public boolean LstFstAvail;
		public boolean ButFstViewActive;
		public boolean LstVarAvail;
		public boolean ButVarViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNavDescr");

			String itemtag = "StatitemShrWdbeNavDescr";

			if (Xmlio.checkXPath(doc, basexpath)) {
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
				LstPphAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPphAvail", mask, LSTPPHAVAIL);
				ButPphViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPphViewActive", mask, BUTPPHVIEWACTIVE);
				ButPphNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPphNewcrdActive", mask, BUTPPHNEWCRDACTIVE);
				LstBnkAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBnkAvail", mask, LSTBNKAVAIL);
				ButBnkViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBnkViewActive", mask, BUTBNKVIEWACTIVE);
				ButBnkNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBnkNewcrdActive", mask, BUTBNKNEWCRDACTIVE);
				LstPinAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPinAvail", mask, LSTPINAVAIL);
				ButPinViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPinViewActive", mask, BUTPINVIEWACTIVE);
				ButPinNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPinNewcrdActive", mask, BUTPINNEWCRDACTIVE);
				LstGenAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstGenAvail", mask, LSTGENAVAIL);
				ButGenViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButGenViewActive", mask, BUTGENVIEWACTIVE);
				LstPrtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrtAvail", mask, LSTPRTAVAIL);
				ButPrtViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrtViewActive", mask, BUTPRTVIEWACTIVE);
				LstSigAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSigAvail", mask, LSTSIGAVAIL);
				ButSigViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSigViewActive", mask, BUTSIGVIEWACTIVE);
				LstPrcAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrcAvail", mask, LSTPRCAVAIL);
				ButPrcViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrcViewActive", mask, BUTPRCVIEWACTIVE);
				LstFstAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFstAvail", mask, LSTFSTAVAIL);
				ButFstViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFstViewActive", mask, BUTFSTVIEWACTIVE);
				LstVarAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVarAvail", mask, LSTVARAVAIL);
				ButVarViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVarViewActive", mask, BUTVARVIEWACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

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
			if (LstPphAvail == comp.LstPphAvail) items.add(LSTPPHAVAIL);
			if (ButPphViewActive == comp.ButPphViewActive) items.add(BUTPPHVIEWACTIVE);
			if (ButPphNewcrdActive == comp.ButPphNewcrdActive) items.add(BUTPPHNEWCRDACTIVE);
			if (LstBnkAvail == comp.LstBnkAvail) items.add(LSTBNKAVAIL);
			if (ButBnkViewActive == comp.ButBnkViewActive) items.add(BUTBNKVIEWACTIVE);
			if (ButBnkNewcrdActive == comp.ButBnkNewcrdActive) items.add(BUTBNKNEWCRDACTIVE);
			if (LstPinAvail == comp.LstPinAvail) items.add(LSTPINAVAIL);
			if (ButPinViewActive == comp.ButPinViewActive) items.add(BUTPINVIEWACTIVE);
			if (ButPinNewcrdActive == comp.ButPinNewcrdActive) items.add(BUTPINNEWCRDACTIVE);
			if (LstGenAvail == comp.LstGenAvail) items.add(LSTGENAVAIL);
			if (ButGenViewActive == comp.ButGenViewActive) items.add(BUTGENVIEWACTIVE);
			if (LstPrtAvail == comp.LstPrtAvail) items.add(LSTPRTAVAIL);
			if (ButPrtViewActive == comp.ButPrtViewActive) items.add(BUTPRTVIEWACTIVE);
			if (LstSigAvail == comp.LstSigAvail) items.add(LSTSIGAVAIL);
			if (ButSigViewActive == comp.ButSigViewActive) items.add(BUTSIGVIEWACTIVE);
			if (LstPrcAvail == comp.LstPrcAvail) items.add(LSTPRCAVAIL);
			if (ButPrcViewActive == comp.ButPrcViewActive) items.add(BUTPRCVIEWACTIVE);
			if (LstFstAvail == comp.LstFstAvail) items.add(LSTFSTAVAIL);
			if (ButFstViewActive == comp.ButFstViewActive) items.add(BUTFSTVIEWACTIVE);
			if (LstVarAvail == comp.LstVarAvail) items.add(LSTVARAVAIL);
			if (ButVarViewActive == comp.ButVarViewActive) items.add(BUTVARVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTMODAVAIL, BUTMODVIEWACTIVE, BUTMODNEWCRDACTIVE, LSTVECAVAIL, BUTVECVIEWACTIVE, BUTVECNEWCRDACTIVE, LSTVITAVAIL, BUTVITVIEWACTIVE, LSTCMDAVAIL, BUTCMDVIEWACTIVE, BUTCMDNEWCRDACTIVE, LSTERRAVAIL, BUTERRVIEWACTIVE, BUTERRNEWCRDACTIVE, LSTPPHAVAIL, BUTPPHVIEWACTIVE, BUTPPHNEWCRDACTIVE, LSTBNKAVAIL, BUTBNKVIEWACTIVE, BUTBNKNEWCRDACTIVE, LSTPINAVAIL, BUTPINVIEWACTIVE, BUTPINNEWCRDACTIVE, LSTGENAVAIL, BUTGENVIEWACTIVE, LSTPRTAVAIL, BUTPRTVIEWACTIVE, LSTSIGAVAIL, BUTSIGVIEWACTIVE, LSTPRCAVAIL, BUTPRCVIEWACTIVE, LSTFSTAVAIL, BUTFSTVIEWACTIVE, LSTVARAVAIL, BUTVARVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNavDescr)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTMOD = 2;
		public static final int CPTVEC = 3;
		public static final int CPTVIT = 4;
		public static final int CPTCMD = 5;
		public static final int CPTERR = 6;
		public static final int CPTPPH = 7;
		public static final int CPTBNK = 8;
		public static final int CPTPIN = 9;
		public static final int CPTGEN = 10;
		public static final int CPTPRT = 11;
		public static final int CPTSIG = 12;
		public static final int CPTPRC = 13;
		public static final int CPTFST = 14;
		public static final int CPTVAR = 15;

		public Tag(
					String Cpt
					, String CptMod
					, String CptVec
					, String CptVit
					, String CptCmd
					, String CptErr
					, String CptPph
					, String CptBnk
					, String CptPin
					, String CptGen
					, String CptPrt
					, String CptSig
					, String CptPrc
					, String CptFst
					, String CptVar
				) {
			this.Cpt = Cpt;
			this.CptMod = CptMod;
			this.CptVec = CptVec;
			this.CptVit = CptVit;
			this.CptCmd = CptCmd;
			this.CptErr = CptErr;
			this.CptPph = CptPph;
			this.CptBnk = CptBnk;
			this.CptPin = CptPin;
			this.CptGen = CptGen;
			this.CptPrt = CptPrt;
			this.CptSig = CptSig;
			this.CptPrc = CptPrc;
			this.CptFst = CptFst;
			this.CptVar = CptVar;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTMOD, CPTVEC, CPTVIT, CPTCMD, CPTERR, CPTPPH, CPTBNK, CPTPIN, CPTGEN, CPTPRT, CPTSIG, CPTPRC, CPTFST, CPTVAR));
		};

		public String Cpt;
		public String CptMod;
		public String CptVec;
		public String CptVit;
		public String CptCmd;
		public String CptErr;
		public String CptPph;
		public String CptBnk;
		public String CptPin;
		public String CptGen;
		public String CptPrt;
		public String CptSig;
		public String CptPrc;
		public String CptFst;
		public String CptVar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNavDescr");

			String itemtag = "TagitemWdbeNavDescr";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptMod = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMod", mask, CPTMOD);
				CptVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVec", mask, CPTVEC);
				CptVit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVit", mask, CPTVIT);
				CptCmd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmd", mask, CPTCMD);
				CptErr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptErr", mask, CPTERR);
				CptPph = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPph", mask, CPTPPH);
				CptBnk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptBnk", mask, CPTBNK);
				CptPin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPin", mask, CPTPIN);
				CptGen = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptGen", mask, CPTGEN);
				CptPrt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrt", mask, CPTPRT);
				CptSig = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSig", mask, CPTSIG);
				CptPrc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrc", mask, CPTPRC);
				CptFst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFst", mask, CPTFST);
				CptVar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVar", mask, CPTVAR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptMod.equals(comp.CptMod)) items.add(CPTMOD);
			if (CptVec.equals(comp.CptVec)) items.add(CPTVEC);
			if (CptVit.equals(comp.CptVit)) items.add(CPTVIT);
			if (CptCmd.equals(comp.CptCmd)) items.add(CPTCMD);
			if (CptErr.equals(comp.CptErr)) items.add(CPTERR);
			if (CptPph.equals(comp.CptPph)) items.add(CPTPPH);
			if (CptBnk.equals(comp.CptBnk)) items.add(CPTBNK);
			if (CptPin.equals(comp.CptPin)) items.add(CPTPIN);
			if (CptGen.equals(comp.CptGen)) items.add(CPTGEN);
			if (CptPrt.equals(comp.CptPrt)) items.add(CPTPRT);
			if (CptSig.equals(comp.CptSig)) items.add(CPTSIG);
			if (CptPrc.equals(comp.CptPrc)) items.add(CPTPRC);
			if (CptFst.equals(comp.CptFst)) items.add(CPTFST);
			if (CptVar.equals(comp.CptVar)) items.add(CPTVAR);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTMOD, CPTVEC, CPTVIT, CPTCMD, CPTERR, CPTPPH, CPTBNK, CPTPIN, CPTGEN, CPTPRT, CPTSIG, CPTPRC, CPTFST, CPTVAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeNavDescrData)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVDESCRDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavDescrData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavDescrDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVDESCRDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavDescrDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavDescrData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTBNK = 3;
		public static final int FEEDFLSTCMD = 4;
		public static final int FEEDFLSTERR = 5;
		public static final int FEEDFLSTFST = 6;
		public static final int FEEDFLSTGEN = 7;
		public static final int FEEDFLSTMOD = 8;
		public static final int FEEDFLSTPIN = 9;
		public static final int FEEDFLSTPPH = 10;
		public static final int FEEDFLSTPRC = 11;
		public static final int FEEDFLSTPRT = 12;
		public static final int FEEDFLSTSIG = 13;
		public static final int FEEDFLSTVAR = 14;
		public static final int FEEDFLSTVEC = 15;
		public static final int FEEDFLSTVIT = 16;
		public static final int STATAPP = 17;
		public static final int STATSHR = 18;
		public static final int TAG = 19;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVDESCRDATA);

			contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			feedFLstBnk = new Feed("FeedFLstBnk");
			feedFLstCmd = new Feed("FeedFLstCmd");
			feedFLstErr = new Feed("FeedFLstErr");
			feedFLstFst = new Feed("FeedFLstFst");
			feedFLstGen = new Feed("FeedFLstGen");
			feedFLstMod = new Feed("FeedFLstMod");
			feedFLstPin = new Feed("FeedFLstPin");
			feedFLstPph = new Feed("FeedFLstPph");
			feedFLstPrc = new Feed("FeedFLstPrc");
			feedFLstPrt = new Feed("FeedFLstPrt");
			feedFLstSig = new Feed("FeedFLstSig");
			feedFLstVar = new Feed("FeedFLstVar");
			feedFLstVec = new Feed("FeedFLstVec");
			feedFLstVit = new Feed("FeedFLstVit");
			statapp = new StatApp(0, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstBnk;
		public Feed feedFLstCmd;
		public Feed feedFLstErr;
		public Feed feedFLstFst;
		public Feed feedFLstGen;
		public Feed feedFLstMod;
		public Feed feedFLstPin;
		public Feed feedFLstPph;
		public Feed feedFLstPrc;
		public Feed feedFLstPrt;
		public Feed feedFLstSig;
		public Feed feedFLstVar;
		public Feed feedFLstVec;
		public Feed feedFLstVit;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTBNK)) ss.add("feedFLstBnk");
			if (has(FEEDFLSTCMD)) ss.add("feedFLstCmd");
			if (has(FEEDFLSTERR)) ss.add("feedFLstErr");
			if (has(FEEDFLSTFST)) ss.add("feedFLstFst");
			if (has(FEEDFLSTGEN)) ss.add("feedFLstGen");
			if (has(FEEDFLSTMOD)) ss.add("feedFLstMod");
			if (has(FEEDFLSTPIN)) ss.add("feedFLstPin");
			if (has(FEEDFLSTPPH)) ss.add("feedFLstPph");
			if (has(FEEDFLSTPRC)) ss.add("feedFLstPrc");
			if (has(FEEDFLSTPRT)) ss.add("feedFLstPrt");
			if (has(FEEDFLSTSIG)) ss.add("feedFLstSig");
			if (has(FEEDFLSTVAR)) ss.add("feedFLstVar");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavDescrData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstBnk.readXML(doc, basexpath, true)) add(FEEDFLSTBNK);
				if (feedFLstCmd.readXML(doc, basexpath, true)) add(FEEDFLSTCMD);
				if (feedFLstErr.readXML(doc, basexpath, true)) add(FEEDFLSTERR);
				if (feedFLstFst.readXML(doc, basexpath, true)) add(FEEDFLSTFST);
				if (feedFLstGen.readXML(doc, basexpath, true)) add(FEEDFLSTGEN);
				if (feedFLstMod.readXML(doc, basexpath, true)) add(FEEDFLSTMOD);
				if (feedFLstPin.readXML(doc, basexpath, true)) add(FEEDFLSTPIN);
				if (feedFLstPph.readXML(doc, basexpath, true)) add(FEEDFLSTPPH);
				if (feedFLstPrc.readXML(doc, basexpath, true)) add(FEEDFLSTPRC);
				if (feedFLstPrt.readXML(doc, basexpath, true)) add(FEEDFLSTPRT);
				if (feedFLstSig.readXML(doc, basexpath, true)) add(FEEDFLSTSIG);
				if (feedFLstVar.readXML(doc, basexpath, true)) add(FEEDFLSTVAR);
				if (feedFLstVec.readXML(doc, basexpath, true)) add(FEEDFLSTVEC);
				if (feedFLstVit.readXML(doc, basexpath, true)) add(FEEDFLSTVIT);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				feedFLstBnk = new Feed("FeedFLstBnk");
				feedFLstCmd = new Feed("FeedFLstCmd");
				feedFLstErr = new Feed("FeedFLstErr");
				feedFLstFst = new Feed("FeedFLstFst");
				feedFLstGen = new Feed("FeedFLstGen");
				feedFLstMod = new Feed("FeedFLstMod");
				feedFLstPin = new Feed("FeedFLstPin");
				feedFLstPph = new Feed("FeedFLstPph");
				feedFLstPrc = new Feed("FeedFLstPrc");
				feedFLstPrt = new Feed("FeedFLstPrt");
				feedFLstSig = new Feed("FeedFLstSig");
				feedFLstVar = new Feed("FeedFLstVar");
				feedFLstVec = new Feed("FeedFLstVec");
				feedFLstVit = new Feed("FeedFLstVit");
				statapp = new StatApp(0, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
