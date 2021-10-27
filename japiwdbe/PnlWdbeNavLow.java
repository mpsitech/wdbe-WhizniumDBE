/**
  * \file PnlWdbeNavLow.java
  * Java API code for job PnlWdbeNavLow
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeNavLow {
	/**
		* VecVDo (full: VecVWdbeNavLowDo)
		*/
	public static class VecVDo {

		public static final int BUTBNKVIEWCLICK = 1;
		public static final int BUTBNKNEWCRDCLICK = 2;
		public static final int BUTPINVIEWCLICK = 3;
		public static final int BUTPINNEWCRDCLICK = 4;
		public static final int BUTINTVIEWCLICK = 5;
		public static final int BUTINTNEWCRDCLICK = 6;
		public static final int BUTSNSVIEWCLICK = 7;
		public static final int BUTVARVIEWCLICK = 8;
		public static final int BUTGENVIEWCLICK = 9;
		public static final int BUTPRTVIEWCLICK = 10;
		public static final int BUTSIGVIEWCLICK = 11;
		public static final int BUTSIGNEWCRDCLICK = 12;
		public static final int BUTPRCVIEWCLICK = 13;
		public static final int BUTFSTVIEWCLICK = 14;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butbnkviewclick")) return BUTBNKVIEWCLICK;
			if (s.equals("butbnknewcrdclick")) return BUTBNKNEWCRDCLICK;
			if (s.equals("butpinviewclick")) return BUTPINVIEWCLICK;
			if (s.equals("butpinnewcrdclick")) return BUTPINNEWCRDCLICK;
			if (s.equals("butintviewclick")) return BUTINTVIEWCLICK;
			if (s.equals("butintnewcrdclick")) return BUTINTNEWCRDCLICK;
			if (s.equals("butsnsviewclick")) return BUTSNSVIEWCLICK;
			if (s.equals("butvarviewclick")) return BUTVARVIEWCLICK;
			if (s.equals("butgenviewclick")) return BUTGENVIEWCLICK;
			if (s.equals("butprtviewclick")) return BUTPRTVIEWCLICK;
			if (s.equals("butsigviewclick")) return BUTSIGVIEWCLICK;
			if (s.equals("butsignewcrdclick")) return BUTSIGNEWCRDCLICK;
			if (s.equals("butprcviewclick")) return BUTPRCVIEWCLICK;
			if (s.equals("butfstviewclick")) return BUTFSTVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTBNKVIEWCLICK) return("ButBnkViewClick");
			if (ix == BUTBNKNEWCRDCLICK) return("ButBnkNewcrdClick");
			if (ix == BUTPINVIEWCLICK) return("ButPinViewClick");
			if (ix == BUTPINNEWCRDCLICK) return("ButPinNewcrdClick");
			if (ix == BUTINTVIEWCLICK) return("ButIntViewClick");
			if (ix == BUTINTNEWCRDCLICK) return("ButIntNewcrdClick");
			if (ix == BUTSNSVIEWCLICK) return("ButSnsViewClick");
			if (ix == BUTVARVIEWCLICK) return("ButVarViewClick");
			if (ix == BUTGENVIEWCLICK) return("ButGenViewClick");
			if (ix == BUTPRTVIEWCLICK) return("ButPrtViewClick");
			if (ix == BUTSIGVIEWCLICK) return("ButSigViewClick");
			if (ix == BUTSIGNEWCRDCLICK) return("ButSigNewcrdClick");
			if (ix == BUTPRCVIEWCLICK) return("ButPrcViewClick");
			if (ix == BUTFSTVIEWCLICK) return("ButFstViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeNavLow)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTBNK = 1;
		public static final int NUMFLSTPIN = 2;
		public static final int NUMFLSTINT = 3;
		public static final int NUMFLSTSNS = 4;
		public static final int NUMFLSTVAR = 5;
		public static final int NUMFLSTGEN = 6;
		public static final int NUMFLSTPRT = 7;
		public static final int NUMFLSTSIG = 8;
		public static final int NUMFLSTPRC = 9;
		public static final int NUMFLSTFST = 10;

		public ContIac(
					int numFLstBnk
					, int numFLstPin
					, int numFLstInt
					, int numFLstSns
					, int numFLstVar
					, int numFLstGen
					, int numFLstPrt
					, int numFLstSig
					, int numFLstPrc
					, int numFLstFst
				) {
			this.numFLstBnk = numFLstBnk;
			this.numFLstPin = numFLstPin;
			this.numFLstInt = numFLstInt;
			this.numFLstSns = numFLstSns;
			this.numFLstVar = numFLstVar;
			this.numFLstGen = numFLstGen;
			this.numFLstPrt = numFLstPrt;
			this.numFLstSig = numFLstSig;
			this.numFLstPrc = numFLstPrc;
			this.numFLstFst = numFLstFst;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTBNK, NUMFLSTPIN, NUMFLSTINT, NUMFLSTSNS, NUMFLSTVAR, NUMFLSTGEN, NUMFLSTPRT, NUMFLSTSIG, NUMFLSTPRC, NUMFLSTFST));
		};

		public int numFLstBnk;
		public int numFLstPin;
		public int numFLstInt;
		public int numFLstSns;
		public int numFLstVar;
		public int numFLstGen;
		public int numFLstPrt;
		public int numFLstSig;
		public int numFLstPrc;
		public int numFLstFst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeNavLow");

			String itemtag = "ContitemIacWdbeNavLow";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstBnk = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstBnk", mask, NUMFLSTBNK);
				numFLstPin = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPin", mask, NUMFLSTPIN);
				numFLstInt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstInt", mask, NUMFLSTINT);
				numFLstSns = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSns", mask, NUMFLSTSNS);
				numFLstVar = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVar", mask, NUMFLSTVAR);
				numFLstGen = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstGen", mask, NUMFLSTGEN);
				numFLstPrt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPrt", mask, NUMFLSTPRT);
				numFLstSig = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSig", mask, NUMFLSTSIG);
				numFLstPrc = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPrc", mask, NUMFLSTPRC);
				numFLstFst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstFst", mask, NUMFLSTFST);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeNavLow";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeNavLow";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstBnk", numFLstBnk);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPin", numFLstPin);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstInt", numFLstInt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSns", numFLstSns);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVar", numFLstVar);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstGen", numFLstGen);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPrt", numFLstPrt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSig", numFLstSig);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPrc", numFLstPrc);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstFst", numFLstFst);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstBnk == comp.numFLstBnk) items.add(NUMFLSTBNK);
			if (numFLstPin == comp.numFLstPin) items.add(NUMFLSTPIN);
			if (numFLstInt == comp.numFLstInt) items.add(NUMFLSTINT);
			if (numFLstSns == comp.numFLstSns) items.add(NUMFLSTSNS);
			if (numFLstVar == comp.numFLstVar) items.add(NUMFLSTVAR);
			if (numFLstGen == comp.numFLstGen) items.add(NUMFLSTGEN);
			if (numFLstPrt == comp.numFLstPrt) items.add(NUMFLSTPRT);
			if (numFLstSig == comp.numFLstSig) items.add(NUMFLSTSIG);
			if (numFLstPrc == comp.numFLstPrc) items.add(NUMFLSTPRC);
			if (numFLstFst == comp.numFLstFst) items.add(NUMFLSTFST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTBNK, NUMFLSTPIN, NUMFLSTINT, NUMFLSTSNS, NUMFLSTVAR, NUMFLSTGEN, NUMFLSTPRT, NUMFLSTSIG, NUMFLSTPRC, NUMFLSTFST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeNavLow)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTBNKALT = 2;
		public static final int LSTPINALT = 3;
		public static final int LSTINTALT = 4;
		public static final int LSTSNSALT = 5;
		public static final int LSTVARALT = 6;
		public static final int LSTGENALT = 7;
		public static final int LSTPRTALT = 8;
		public static final int LSTSIGALT = 9;
		public static final int LSTPRCALT = 10;
		public static final int LSTFSTALT = 11;
		public static final int LSTBNKNUMFIRSTDISP = 12;
		public static final int LSTPINNUMFIRSTDISP = 13;
		public static final int LSTINTNUMFIRSTDISP = 14;
		public static final int LSTSNSNUMFIRSTDISP = 15;
		public static final int LSTVARNUMFIRSTDISP = 16;
		public static final int LSTGENNUMFIRSTDISP = 17;
		public static final int LSTPRTNUMFIRSTDISP = 18;
		public static final int LSTSIGNUMFIRSTDISP = 19;
		public static final int LSTPRCNUMFIRSTDISP = 20;
		public static final int LSTFSTNUMFIRSTDISP = 21;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstBnkAlt
					, boolean LstPinAlt
					, boolean LstIntAlt
					, boolean LstSnsAlt
					, boolean LstVarAlt
					, boolean LstGenAlt
					, boolean LstPrtAlt
					, boolean LstSigAlt
					, boolean LstPrcAlt
					, boolean LstFstAlt
					, int LstBnkNumFirstdisp
					, int LstPinNumFirstdisp
					, int LstIntNumFirstdisp
					, int LstSnsNumFirstdisp
					, int LstVarNumFirstdisp
					, int LstGenNumFirstdisp
					, int LstPrtNumFirstdisp
					, int LstSigNumFirstdisp
					, int LstPrcNumFirstdisp
					, int LstFstNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstBnkAlt = LstBnkAlt;
			this.LstPinAlt = LstPinAlt;
			this.LstIntAlt = LstIntAlt;
			this.LstSnsAlt = LstSnsAlt;
			this.LstVarAlt = LstVarAlt;
			this.LstGenAlt = LstGenAlt;
			this.LstPrtAlt = LstPrtAlt;
			this.LstSigAlt = LstSigAlt;
			this.LstPrcAlt = LstPrcAlt;
			this.LstFstAlt = LstFstAlt;
			this.LstBnkNumFirstdisp = LstBnkNumFirstdisp;
			this.LstPinNumFirstdisp = LstPinNumFirstdisp;
			this.LstIntNumFirstdisp = LstIntNumFirstdisp;
			this.LstSnsNumFirstdisp = LstSnsNumFirstdisp;
			this.LstVarNumFirstdisp = LstVarNumFirstdisp;
			this.LstGenNumFirstdisp = LstGenNumFirstdisp;
			this.LstPrtNumFirstdisp = LstPrtNumFirstdisp;
			this.LstSigNumFirstdisp = LstSigNumFirstdisp;
			this.LstPrcNumFirstdisp = LstPrcNumFirstdisp;
			this.LstFstNumFirstdisp = LstFstNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTBNKALT, LSTPINALT, LSTINTALT, LSTSNSALT, LSTVARALT, LSTGENALT, LSTPRTALT, LSTSIGALT, LSTPRCALT, LSTFSTALT, LSTBNKNUMFIRSTDISP, LSTPINNUMFIRSTDISP, LSTINTNUMFIRSTDISP, LSTSNSNUMFIRSTDISP, LSTVARNUMFIRSTDISP, LSTGENNUMFIRSTDISP, LSTPRTNUMFIRSTDISP, LSTSIGNUMFIRSTDISP, LSTPRCNUMFIRSTDISP, LSTFSTNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstBnkAlt;
		public boolean LstPinAlt;
		public boolean LstIntAlt;
		public boolean LstSnsAlt;
		public boolean LstVarAlt;
		public boolean LstGenAlt;
		public boolean LstPrtAlt;
		public boolean LstSigAlt;
		public boolean LstPrcAlt;
		public boolean LstFstAlt;
		public int LstBnkNumFirstdisp;
		public int LstPinNumFirstdisp;
		public int LstIntNumFirstdisp;
		public int LstSnsNumFirstdisp;
		public int LstVarNumFirstdisp;
		public int LstGenNumFirstdisp;
		public int LstPrtNumFirstdisp;
		public int LstSigNumFirstdisp;
		public int LstPrcNumFirstdisp;
		public int LstFstNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeNavLow");

			String itemtag = "StatitemAppWdbeNavLow";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstBnkAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBnkAlt", mask, LSTBNKALT);
				LstPinAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPinAlt", mask, LSTPINALT);
				LstIntAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIntAlt", mask, LSTINTALT);
				LstSnsAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSnsAlt", mask, LSTSNSALT);
				LstVarAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVarAlt", mask, LSTVARALT);
				LstGenAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstGenAlt", mask, LSTGENALT);
				LstPrtAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrtAlt", mask, LSTPRTALT);
				LstSigAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSigAlt", mask, LSTSIGALT);
				LstPrcAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrcAlt", mask, LSTPRCALT);
				LstFstAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFstAlt", mask, LSTFSTALT);
				LstBnkNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBnkNumFirstdisp", mask, LSTBNKNUMFIRSTDISP);
				LstPinNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPinNumFirstdisp", mask, LSTPINNUMFIRSTDISP);
				LstIntNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIntNumFirstdisp", mask, LSTINTNUMFIRSTDISP);
				LstSnsNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSnsNumFirstdisp", mask, LSTSNSNUMFIRSTDISP);
				LstVarNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVarNumFirstdisp", mask, LSTVARNUMFIRSTDISP);
				LstGenNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstGenNumFirstdisp", mask, LSTGENNUMFIRSTDISP);
				LstPrtNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrtNumFirstdisp", mask, LSTPRTNUMFIRSTDISP);
				LstSigNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSigNumFirstdisp", mask, LSTSIGNUMFIRSTDISP);
				LstPrcNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrcNumFirstdisp", mask, LSTPRCNUMFIRSTDISP);
				LstFstNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFstNumFirstdisp", mask, LSTFSTNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstBnkAlt == comp.LstBnkAlt) items.add(LSTBNKALT);
			if (LstPinAlt == comp.LstPinAlt) items.add(LSTPINALT);
			if (LstIntAlt == comp.LstIntAlt) items.add(LSTINTALT);
			if (LstSnsAlt == comp.LstSnsAlt) items.add(LSTSNSALT);
			if (LstVarAlt == comp.LstVarAlt) items.add(LSTVARALT);
			if (LstGenAlt == comp.LstGenAlt) items.add(LSTGENALT);
			if (LstPrtAlt == comp.LstPrtAlt) items.add(LSTPRTALT);
			if (LstSigAlt == comp.LstSigAlt) items.add(LSTSIGALT);
			if (LstPrcAlt == comp.LstPrcAlt) items.add(LSTPRCALT);
			if (LstFstAlt == comp.LstFstAlt) items.add(LSTFSTALT);
			if (LstBnkNumFirstdisp == comp.LstBnkNumFirstdisp) items.add(LSTBNKNUMFIRSTDISP);
			if (LstPinNumFirstdisp == comp.LstPinNumFirstdisp) items.add(LSTPINNUMFIRSTDISP);
			if (LstIntNumFirstdisp == comp.LstIntNumFirstdisp) items.add(LSTINTNUMFIRSTDISP);
			if (LstSnsNumFirstdisp == comp.LstSnsNumFirstdisp) items.add(LSTSNSNUMFIRSTDISP);
			if (LstVarNumFirstdisp == comp.LstVarNumFirstdisp) items.add(LSTVARNUMFIRSTDISP);
			if (LstGenNumFirstdisp == comp.LstGenNumFirstdisp) items.add(LSTGENNUMFIRSTDISP);
			if (LstPrtNumFirstdisp == comp.LstPrtNumFirstdisp) items.add(LSTPRTNUMFIRSTDISP);
			if (LstSigNumFirstdisp == comp.LstSigNumFirstdisp) items.add(LSTSIGNUMFIRSTDISP);
			if (LstPrcNumFirstdisp == comp.LstPrcNumFirstdisp) items.add(LSTPRCNUMFIRSTDISP);
			if (LstFstNumFirstdisp == comp.LstFstNumFirstdisp) items.add(LSTFSTNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTBNKALT, LSTPINALT, LSTINTALT, LSTSNSALT, LSTVARALT, LSTGENALT, LSTPRTALT, LSTSIGALT, LSTPRCALT, LSTFSTALT, LSTBNKNUMFIRSTDISP, LSTPINNUMFIRSTDISP, LSTINTNUMFIRSTDISP, LSTSNSNUMFIRSTDISP, LSTVARNUMFIRSTDISP, LSTGENNUMFIRSTDISP, LSTPRTNUMFIRSTDISP, LSTSIGNUMFIRSTDISP, LSTPRCNUMFIRSTDISP, LSTFSTNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeNavLow)
	  */
	public class StatShr extends Block {

		public static final int LSTBNKAVAIL = 1;
		public static final int BUTBNKVIEWACTIVE = 2;
		public static final int BUTBNKNEWCRDACTIVE = 3;
		public static final int LSTPINAVAIL = 4;
		public static final int BUTPINVIEWACTIVE = 5;
		public static final int BUTPINNEWCRDACTIVE = 6;
		public static final int LSTINTAVAIL = 7;
		public static final int BUTINTVIEWACTIVE = 8;
		public static final int BUTINTNEWCRDACTIVE = 9;
		public static final int LSTSNSAVAIL = 10;
		public static final int BUTSNSVIEWACTIVE = 11;
		public static final int LSTVARAVAIL = 12;
		public static final int BUTVARVIEWACTIVE = 13;
		public static final int LSTGENAVAIL = 14;
		public static final int BUTGENVIEWACTIVE = 15;
		public static final int LSTPRTAVAIL = 16;
		public static final int BUTPRTVIEWACTIVE = 17;
		public static final int LSTSIGAVAIL = 18;
		public static final int BUTSIGVIEWACTIVE = 19;
		public static final int BUTSIGNEWCRDACTIVE = 20;
		public static final int LSTPRCAVAIL = 21;
		public static final int BUTPRCVIEWACTIVE = 22;
		public static final int LSTFSTAVAIL = 23;
		public static final int BUTFSTVIEWACTIVE = 24;

		public StatShr(
					boolean LstBnkAvail
					, boolean ButBnkViewActive
					, boolean ButBnkNewcrdActive
					, boolean LstPinAvail
					, boolean ButPinViewActive
					, boolean ButPinNewcrdActive
					, boolean LstIntAvail
					, boolean ButIntViewActive
					, boolean ButIntNewcrdActive
					, boolean LstSnsAvail
					, boolean ButSnsViewActive
					, boolean LstVarAvail
					, boolean ButVarViewActive
					, boolean LstGenAvail
					, boolean ButGenViewActive
					, boolean LstPrtAvail
					, boolean ButPrtViewActive
					, boolean LstSigAvail
					, boolean ButSigViewActive
					, boolean ButSigNewcrdActive
					, boolean LstPrcAvail
					, boolean ButPrcViewActive
					, boolean LstFstAvail
					, boolean ButFstViewActive
				) {
			this.LstBnkAvail = LstBnkAvail;
			this.ButBnkViewActive = ButBnkViewActive;
			this.ButBnkNewcrdActive = ButBnkNewcrdActive;
			this.LstPinAvail = LstPinAvail;
			this.ButPinViewActive = ButPinViewActive;
			this.ButPinNewcrdActive = ButPinNewcrdActive;
			this.LstIntAvail = LstIntAvail;
			this.ButIntViewActive = ButIntViewActive;
			this.ButIntNewcrdActive = ButIntNewcrdActive;
			this.LstSnsAvail = LstSnsAvail;
			this.ButSnsViewActive = ButSnsViewActive;
			this.LstVarAvail = LstVarAvail;
			this.ButVarViewActive = ButVarViewActive;
			this.LstGenAvail = LstGenAvail;
			this.ButGenViewActive = ButGenViewActive;
			this.LstPrtAvail = LstPrtAvail;
			this.ButPrtViewActive = ButPrtViewActive;
			this.LstSigAvail = LstSigAvail;
			this.ButSigViewActive = ButSigViewActive;
			this.ButSigNewcrdActive = ButSigNewcrdActive;
			this.LstPrcAvail = LstPrcAvail;
			this.ButPrcViewActive = ButPrcViewActive;
			this.LstFstAvail = LstFstAvail;
			this.ButFstViewActive = ButFstViewActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTBNKAVAIL, BUTBNKVIEWACTIVE, BUTBNKNEWCRDACTIVE, LSTPINAVAIL, BUTPINVIEWACTIVE, BUTPINNEWCRDACTIVE, LSTINTAVAIL, BUTINTVIEWACTIVE, BUTINTNEWCRDACTIVE, LSTSNSAVAIL, BUTSNSVIEWACTIVE, LSTVARAVAIL, BUTVARVIEWACTIVE, LSTGENAVAIL, BUTGENVIEWACTIVE, LSTPRTAVAIL, BUTPRTVIEWACTIVE, LSTSIGAVAIL, BUTSIGVIEWACTIVE, BUTSIGNEWCRDACTIVE, LSTPRCAVAIL, BUTPRCVIEWACTIVE, LSTFSTAVAIL, BUTFSTVIEWACTIVE));
		};

		public boolean LstBnkAvail;
		public boolean ButBnkViewActive;
		public boolean ButBnkNewcrdActive;
		public boolean LstPinAvail;
		public boolean ButPinViewActive;
		public boolean ButPinNewcrdActive;
		public boolean LstIntAvail;
		public boolean ButIntViewActive;
		public boolean ButIntNewcrdActive;
		public boolean LstSnsAvail;
		public boolean ButSnsViewActive;
		public boolean LstVarAvail;
		public boolean ButVarViewActive;
		public boolean LstGenAvail;
		public boolean ButGenViewActive;
		public boolean LstPrtAvail;
		public boolean ButPrtViewActive;
		public boolean LstSigAvail;
		public boolean ButSigViewActive;
		public boolean ButSigNewcrdActive;
		public boolean LstPrcAvail;
		public boolean ButPrcViewActive;
		public boolean LstFstAvail;
		public boolean ButFstViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNavLow");

			String itemtag = "StatitemShrWdbeNavLow";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstBnkAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstBnkAvail", mask, LSTBNKAVAIL);
				ButBnkViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBnkViewActive", mask, BUTBNKVIEWACTIVE);
				ButBnkNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButBnkNewcrdActive", mask, BUTBNKNEWCRDACTIVE);
				LstPinAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPinAvail", mask, LSTPINAVAIL);
				ButPinViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPinViewActive", mask, BUTPINVIEWACTIVE);
				ButPinNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPinNewcrdActive", mask, BUTPINNEWCRDACTIVE);
				LstIntAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstIntAvail", mask, LSTINTAVAIL);
				ButIntViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButIntViewActive", mask, BUTINTVIEWACTIVE);
				ButIntNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButIntNewcrdActive", mask, BUTINTNEWCRDACTIVE);
				LstSnsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSnsAvail", mask, LSTSNSAVAIL);
				ButSnsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSnsViewActive", mask, BUTSNSVIEWACTIVE);
				LstVarAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVarAvail", mask, LSTVARAVAIL);
				ButVarViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVarViewActive", mask, BUTVARVIEWACTIVE);
				LstGenAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstGenAvail", mask, LSTGENAVAIL);
				ButGenViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButGenViewActive", mask, BUTGENVIEWACTIVE);
				LstPrtAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrtAvail", mask, LSTPRTAVAIL);
				ButPrtViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrtViewActive", mask, BUTPRTVIEWACTIVE);
				LstSigAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSigAvail", mask, LSTSIGAVAIL);
				ButSigViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSigViewActive", mask, BUTSIGVIEWACTIVE);
				ButSigNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSigNewcrdActive", mask, BUTSIGNEWCRDACTIVE);
				LstPrcAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrcAvail", mask, LSTPRCAVAIL);
				ButPrcViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrcViewActive", mask, BUTPRCVIEWACTIVE);
				LstFstAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFstAvail", mask, LSTFSTAVAIL);
				ButFstViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFstViewActive", mask, BUTFSTVIEWACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstBnkAvail == comp.LstBnkAvail) items.add(LSTBNKAVAIL);
			if (ButBnkViewActive == comp.ButBnkViewActive) items.add(BUTBNKVIEWACTIVE);
			if (ButBnkNewcrdActive == comp.ButBnkNewcrdActive) items.add(BUTBNKNEWCRDACTIVE);
			if (LstPinAvail == comp.LstPinAvail) items.add(LSTPINAVAIL);
			if (ButPinViewActive == comp.ButPinViewActive) items.add(BUTPINVIEWACTIVE);
			if (ButPinNewcrdActive == comp.ButPinNewcrdActive) items.add(BUTPINNEWCRDACTIVE);
			if (LstIntAvail == comp.LstIntAvail) items.add(LSTINTAVAIL);
			if (ButIntViewActive == comp.ButIntViewActive) items.add(BUTINTVIEWACTIVE);
			if (ButIntNewcrdActive == comp.ButIntNewcrdActive) items.add(BUTINTNEWCRDACTIVE);
			if (LstSnsAvail == comp.LstSnsAvail) items.add(LSTSNSAVAIL);
			if (ButSnsViewActive == comp.ButSnsViewActive) items.add(BUTSNSVIEWACTIVE);
			if (LstVarAvail == comp.LstVarAvail) items.add(LSTVARAVAIL);
			if (ButVarViewActive == comp.ButVarViewActive) items.add(BUTVARVIEWACTIVE);
			if (LstGenAvail == comp.LstGenAvail) items.add(LSTGENAVAIL);
			if (ButGenViewActive == comp.ButGenViewActive) items.add(BUTGENVIEWACTIVE);
			if (LstPrtAvail == comp.LstPrtAvail) items.add(LSTPRTAVAIL);
			if (ButPrtViewActive == comp.ButPrtViewActive) items.add(BUTPRTVIEWACTIVE);
			if (LstSigAvail == comp.LstSigAvail) items.add(LSTSIGAVAIL);
			if (ButSigViewActive == comp.ButSigViewActive) items.add(BUTSIGVIEWACTIVE);
			if (ButSigNewcrdActive == comp.ButSigNewcrdActive) items.add(BUTSIGNEWCRDACTIVE);
			if (LstPrcAvail == comp.LstPrcAvail) items.add(LSTPRCAVAIL);
			if (ButPrcViewActive == comp.ButPrcViewActive) items.add(BUTPRCVIEWACTIVE);
			if (LstFstAvail == comp.LstFstAvail) items.add(LSTFSTAVAIL);
			if (ButFstViewActive == comp.ButFstViewActive) items.add(BUTFSTVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTBNKAVAIL, BUTBNKVIEWACTIVE, BUTBNKNEWCRDACTIVE, LSTPINAVAIL, BUTPINVIEWACTIVE, BUTPINNEWCRDACTIVE, LSTINTAVAIL, BUTINTVIEWACTIVE, BUTINTNEWCRDACTIVE, LSTSNSAVAIL, BUTSNSVIEWACTIVE, LSTVARAVAIL, BUTVARVIEWACTIVE, LSTGENAVAIL, BUTGENVIEWACTIVE, LSTPRTAVAIL, BUTPRTVIEWACTIVE, LSTSIGAVAIL, BUTSIGVIEWACTIVE, BUTSIGNEWCRDACTIVE, LSTPRCAVAIL, BUTPRCVIEWACTIVE, LSTFSTAVAIL, BUTFSTVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNavLow)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTBNK = 2;
		public static final int CPTPIN = 3;
		public static final int CPTINT = 4;
		public static final int CPTSNS = 5;
		public static final int CPTVAR = 6;
		public static final int CPTGEN = 7;
		public static final int CPTPRT = 8;
		public static final int CPTSIG = 9;
		public static final int CPTPRC = 10;
		public static final int CPTFST = 11;

		public Tag(
					String Cpt
					, String CptBnk
					, String CptPin
					, String CptInt
					, String CptSns
					, String CptVar
					, String CptGen
					, String CptPrt
					, String CptSig
					, String CptPrc
					, String CptFst
				) {
			this.Cpt = Cpt;
			this.CptBnk = CptBnk;
			this.CptPin = CptPin;
			this.CptInt = CptInt;
			this.CptSns = CptSns;
			this.CptVar = CptVar;
			this.CptGen = CptGen;
			this.CptPrt = CptPrt;
			this.CptSig = CptSig;
			this.CptPrc = CptPrc;
			this.CptFst = CptFst;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTBNK, CPTPIN, CPTINT, CPTSNS, CPTVAR, CPTGEN, CPTPRT, CPTSIG, CPTPRC, CPTFST));
		};

		public String Cpt;
		public String CptBnk;
		public String CptPin;
		public String CptInt;
		public String CptSns;
		public String CptVar;
		public String CptGen;
		public String CptPrt;
		public String CptSig;
		public String CptPrc;
		public String CptFst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNavLow");

			String itemtag = "TagitemWdbeNavLow";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptBnk = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptBnk", mask, CPTBNK);
				CptPin = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPin", mask, CPTPIN);
				CptInt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptInt", mask, CPTINT);
				CptSns = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSns", mask, CPTSNS);
				CptVar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVar", mask, CPTVAR);
				CptGen = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptGen", mask, CPTGEN);
				CptPrt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrt", mask, CPTPRT);
				CptSig = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSig", mask, CPTSIG);
				CptPrc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrc", mask, CPTPRC);
				CptFst = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFst", mask, CPTFST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptBnk.equals(comp.CptBnk)) items.add(CPTBNK);
			if (CptPin.equals(comp.CptPin)) items.add(CPTPIN);
			if (CptInt.equals(comp.CptInt)) items.add(CPTINT);
			if (CptSns.equals(comp.CptSns)) items.add(CPTSNS);
			if (CptVar.equals(comp.CptVar)) items.add(CPTVAR);
			if (CptGen.equals(comp.CptGen)) items.add(CPTGEN);
			if (CptPrt.equals(comp.CptPrt)) items.add(CPTPRT);
			if (CptSig.equals(comp.CptSig)) items.add(CPTSIG);
			if (CptPrc.equals(comp.CptPrc)) items.add(CPTPRC);
			if (CptFst.equals(comp.CptFst)) items.add(CPTFST);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTBNK, CPTPIN, CPTINT, CPTSNS, CPTVAR, CPTGEN, CPTPRT, CPTSIG, CPTPRC, CPTFST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeNavLowData)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVLOWDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavLowData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavLowDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVLOWDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavLowDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavLowData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTBNK = 3;
		public static final int FEEDFLSTFST = 4;
		public static final int FEEDFLSTGEN = 5;
		public static final int FEEDFLSTINT = 6;
		public static final int FEEDFLSTPIN = 7;
		public static final int FEEDFLSTPRC = 8;
		public static final int FEEDFLSTPRT = 9;
		public static final int FEEDFLSTSIG = 10;
		public static final int FEEDFLSTSNS = 11;
		public static final int FEEDFLSTVAR = 12;
		public static final int STATAPP = 13;
		public static final int STATSHR = 14;
		public static final int TAG = 15;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVLOWDATA);

			contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			feedFLstBnk = new Feed("FeedFLstBnk");
			feedFLstFst = new Feed("FeedFLstFst");
			feedFLstGen = new Feed("FeedFLstGen");
			feedFLstInt = new Feed("FeedFLstInt");
			feedFLstPin = new Feed("FeedFLstPin");
			feedFLstPrc = new Feed("FeedFLstPrc");
			feedFLstPrt = new Feed("FeedFLstPrt");
			feedFLstSig = new Feed("FeedFLstSig");
			feedFLstSns = new Feed("FeedFLstSns");
			feedFLstVar = new Feed("FeedFLstVar");
			statapp = new StatApp(0, false, false, false, false, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstBnk;
		public Feed feedFLstFst;
		public Feed feedFLstGen;
		public Feed feedFLstInt;
		public Feed feedFLstPin;
		public Feed feedFLstPrc;
		public Feed feedFLstPrt;
		public Feed feedFLstSig;
		public Feed feedFLstSns;
		public Feed feedFLstVar;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTBNK)) ss.add("feedFLstBnk");
			if (has(FEEDFLSTFST)) ss.add("feedFLstFst");
			if (has(FEEDFLSTGEN)) ss.add("feedFLstGen");
			if (has(FEEDFLSTINT)) ss.add("feedFLstInt");
			if (has(FEEDFLSTPIN)) ss.add("feedFLstPin");
			if (has(FEEDFLSTPRC)) ss.add("feedFLstPrc");
			if (has(FEEDFLSTPRT)) ss.add("feedFLstPrt");
			if (has(FEEDFLSTSIG)) ss.add("feedFLstSig");
			if (has(FEEDFLSTSNS)) ss.add("feedFLstSns");
			if (has(FEEDFLSTVAR)) ss.add("feedFLstVar");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavLowData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstBnk.readXML(doc, basexpath, true)) add(FEEDFLSTBNK);
				if (feedFLstFst.readXML(doc, basexpath, true)) add(FEEDFLSTFST);
				if (feedFLstGen.readXML(doc, basexpath, true)) add(FEEDFLSTGEN);
				if (feedFLstInt.readXML(doc, basexpath, true)) add(FEEDFLSTINT);
				if (feedFLstPin.readXML(doc, basexpath, true)) add(FEEDFLSTPIN);
				if (feedFLstPrc.readXML(doc, basexpath, true)) add(FEEDFLSTPRC);
				if (feedFLstPrt.readXML(doc, basexpath, true)) add(FEEDFLSTPRT);
				if (feedFLstSig.readXML(doc, basexpath, true)) add(FEEDFLSTSIG);
				if (feedFLstSns.readXML(doc, basexpath, true)) add(FEEDFLSTSNS);
				if (feedFLstVar.readXML(doc, basexpath, true)) add(FEEDFLSTVAR);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				feedFLstBnk = new Feed("FeedFLstBnk");
				feedFLstFst = new Feed("FeedFLstFst");
				feedFLstGen = new Feed("FeedFLstGen");
				feedFLstInt = new Feed("FeedFLstInt");
				feedFLstPin = new Feed("FeedFLstPin");
				feedFLstPrc = new Feed("FeedFLstPrc");
				feedFLstPrt = new Feed("FeedFLstPrt");
				feedFLstSig = new Feed("FeedFLstSig");
				feedFLstSns = new Feed("FeedFLstSns");
				feedFLstVar = new Feed("FeedFLstVar");
				statapp = new StatApp(0, false, false, false, false, false, false, false, false, false, false, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
