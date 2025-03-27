/**
  * \file PnlWdbeCdcDetail.java
  * Java API code for job PnlWdbeCdcDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeCdcDetail {
	/**
		* VecVDo (full: VecVWdbeCdcDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTFCKVIEWCLICK = 2;
		public static final int BUTSCKVIEWCLICK = 3;
		public static final int BUTMDLVIEWCLICK = 4;
		public static final int BUTFARVIEWCLICK = 5;
		public static final int BUTSARVIEWCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butfckviewclick")) return BUTFCKVIEWCLICK;
			if (s.equals("butsckviewclick")) return BUTSCKVIEWCLICK;
			if (s.equals("butmdlviewclick")) return BUTMDLVIEWCLICK;
			if (s.equals("butfarviewclick")) return BUTFARVIEWCLICK;
			if (s.equals("butsarviewclick")) return BUTSARVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTFCKVIEWCLICK) return("ButFckViewClick");
			if (ix == BUTSCKVIEWCLICK) return("ButSckViewClick");
			if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
			if (ix == BUTFARVIEWCLICK) return("ButFarViewClick");
			if (ix == BUTSARVIEWCLICK) return("ButSarViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeCdcDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFFCK = 1;
		public static final int TXFSCK = 2;
		public static final int TXFFAR = 3;
		public static final int TXFSAR = 4;
		public static final int TXFRAT = 5;

		public ContIac(
					String TxfFck
					, String TxfSck
					, String TxfFar
					, String TxfSar
					, String TxfRat
				) {
			this.TxfFck = TxfFck;
			this.TxfSck = TxfSck;
			this.TxfFar = TxfFar;
			this.TxfSar = TxfSar;
			this.TxfRat = TxfRat;

			mask = new HashSet<Integer>(Arrays.asList(TXFFCK, TXFSCK, TXFFAR, TXFSAR, TXFRAT));
		};

		public String TxfFck;
		public String TxfSck;
		public String TxfFar;
		public String TxfSar;
		public String TxfRat;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeCdcDetail");

			String itemtag = "ContitemIacWdbeCdcDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfFck = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfFck", mask, TXFFCK);
				TxfSck = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSck", mask, TXFSCK);
				TxfFar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfFar", mask, TXFFAR);
				TxfSar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSar", mask, TXFSAR);
				TxfRat = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfRat", mask, TXFRAT);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeCdcDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeCdcDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFck", TxfFck);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSck", TxfSck);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFar", TxfFar);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSar", TxfSar);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfRat", TxfRat);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfFck.equals(comp.TxfFck)) items.add(TXFFCK);
			if (TxfSck.equals(comp.TxfSck)) items.add(TXFSCK);
			if (TxfFar.equals(comp.TxfFar)) items.add(TXFFAR);
			if (TxfSar.equals(comp.TxfSar)) items.add(TXFSAR);
			if (TxfRat.equals(comp.TxfRat)) items.add(TXFRAT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFFCK, TXFSCK, TXFFAR, TXFSAR, TXFRAT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeCdcDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTFCK = 1;
		public static final int TXTSCK = 2;
		public static final int TXTMDL = 3;
		public static final int TXTFAR = 4;
		public static final int TXTSAR = 5;

		public ContInf(
					String TxtFck
					, String TxtSck
					, String TxtMdl
					, String TxtFar
					, String TxtSar
				) {
			this.TxtFck = TxtFck;
			this.TxtSck = TxtSck;
			this.TxtMdl = TxtMdl;
			this.TxtFar = TxtFar;
			this.TxtSar = TxtSar;

			mask = new HashSet<Integer>(Arrays.asList(TXTFCK, TXTSCK, TXTMDL, TXTFAR, TXTSAR));
		};

		public String TxtFck;
		public String TxtSck;
		public String TxtMdl;
		public String TxtFar;
		public String TxtSar;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeCdcDetail");

			String itemtag = "ContitemInfWdbeCdcDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtFck = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtFck", mask, TXTFCK);
				TxtSck = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSck", mask, TXTSCK);
				TxtMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMdl", mask, TXTMDL);
				TxtFar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtFar", mask, TXTFAR);
				TxtSar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSar", mask, TXTSAR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtFck.equals(comp.TxtFck)) items.add(TXTFCK);
			if (TxtSck.equals(comp.TxtSck)) items.add(TXTSCK);
			if (TxtMdl.equals(comp.TxtMdl)) items.add(TXTMDL);
			if (TxtFar.equals(comp.TxtFar)) items.add(TXTFAR);
			if (TxtSar.equals(comp.TxtSar)) items.add(TXTSAR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTFCK, TXTSCK, TXTMDL, TXTFAR, TXTSAR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeCdcDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int TXTFCKALT = 2;
		public static final int TXTSCKALT = 3;
		public static final int TXTFARALT = 4;
		public static final int TXTSARALT = 5;

		public StatApp(
					int ixWdbeVExpstate
					, boolean TxtFckAlt
					, boolean TxtSckAlt
					, boolean TxtFarAlt
					, boolean TxtSarAlt
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.TxtFckAlt = TxtFckAlt;
			this.TxtSckAlt = TxtSckAlt;
			this.TxtFarAlt = TxtFarAlt;
			this.TxtSarAlt = TxtSarAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, TXTFCKALT, TXTSCKALT, TXTFARALT, TXTSARALT));
		};

		public int ixWdbeVExpstate;
		public boolean TxtFckAlt;
		public boolean TxtSckAlt;
		public boolean TxtFarAlt;
		public boolean TxtSarAlt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeCdcDetail");

			String itemtag = "StatitemAppWdbeCdcDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				TxtFckAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFckAlt", mask, TXTFCKALT);
				TxtSckAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSckAlt", mask, TXTSCKALT);
				TxtFarAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFarAlt", mask, TXTFARALT);
				TxtSarAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSarAlt", mask, TXTSARALT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (TxtFckAlt == comp.TxtFckAlt) items.add(TXTFCKALT);
			if (TxtSckAlt == comp.TxtSckAlt) items.add(TXTSCKALT);
			if (TxtFarAlt == comp.TxtFarAlt) items.add(TXTFARALT);
			if (TxtSarAlt == comp.TxtSarAlt) items.add(TXTSARALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, TXTFCKALT, TXTSCKALT, TXTFARALT, TXTSARALT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeCdcDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTFCKACTIVE = 3;
		public static final int TXFFCKVALID = 4;
		public static final int BUTFCKVIEWAVAIL = 5;
		public static final int TXTSCKACTIVE = 6;
		public static final int TXFSCKVALID = 7;
		public static final int BUTSCKVIEWAVAIL = 8;
		public static final int TXTMDLACTIVE = 9;
		public static final int BUTMDLVIEWAVAIL = 10;
		public static final int BUTMDLVIEWACTIVE = 11;
		public static final int TXTFARACTIVE = 12;
		public static final int TXFFARVALID = 13;
		public static final int BUTFARVIEWAVAIL = 14;
		public static final int TXTSARACTIVE = 15;
		public static final int TXFSARVALID = 16;
		public static final int BUTSARVIEWAVAIL = 17;
		public static final int TXFRATACTIVE = 18;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtFckActive
					, boolean TxfFckValid
					, boolean ButFckViewAvail
					, boolean TxtSckActive
					, boolean TxfSckValid
					, boolean ButSckViewAvail
					, boolean TxtMdlActive
					, boolean ButMdlViewAvail
					, boolean ButMdlViewActive
					, boolean TxtFarActive
					, boolean TxfFarValid
					, boolean ButFarViewAvail
					, boolean TxtSarActive
					, boolean TxfSarValid
					, boolean ButSarViewAvail
					, boolean TxfRatActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtFckActive = TxtFckActive;
			this.TxfFckValid = TxfFckValid;
			this.ButFckViewAvail = ButFckViewAvail;
			this.TxtSckActive = TxtSckActive;
			this.TxfSckValid = TxfSckValid;
			this.ButSckViewAvail = ButSckViewAvail;
			this.TxtMdlActive = TxtMdlActive;
			this.ButMdlViewAvail = ButMdlViewAvail;
			this.ButMdlViewActive = ButMdlViewActive;
			this.TxtFarActive = TxtFarActive;
			this.TxfFarValid = TxfFarValid;
			this.ButFarViewAvail = ButFarViewAvail;
			this.TxtSarActive = TxtSarActive;
			this.TxfSarValid = TxfSarValid;
			this.ButSarViewAvail = ButSarViewAvail;
			this.TxfRatActive = TxfRatActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFCKACTIVE, TXFFCKVALID, BUTFCKVIEWAVAIL, TXTSCKACTIVE, TXFSCKVALID, BUTSCKVIEWAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTFARACTIVE, TXFFARVALID, BUTFARVIEWAVAIL, TXTSARACTIVE, TXFSARVALID, BUTSARVIEWAVAIL, TXFRATACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtFckActive;
		public boolean TxfFckValid;
		public boolean ButFckViewAvail;
		public boolean TxtSckActive;
		public boolean TxfSckValid;
		public boolean ButSckViewAvail;
		public boolean TxtMdlActive;
		public boolean ButMdlViewAvail;
		public boolean ButMdlViewActive;
		public boolean TxtFarActive;
		public boolean TxfFarValid;
		public boolean ButFarViewAvail;
		public boolean TxtSarActive;
		public boolean TxfSarValid;
		public boolean ButSarViewAvail;
		public boolean TxfRatActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeCdcDetail");

			String itemtag = "StatitemShrWdbeCdcDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtFckActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFckActive", mask, TXTFCKACTIVE);
				TxfFckValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfFckValid", mask, TXFFCKVALID);
				ButFckViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFckViewAvail", mask, BUTFCKVIEWAVAIL);
				TxtSckActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSckActive", mask, TXTSCKACTIVE);
				TxfSckValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSckValid", mask, TXFSCKVALID);
				ButSckViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSckViewAvail", mask, BUTSCKVIEWAVAIL);
				TxtMdlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtMdlActive", mask, TXTMDLACTIVE);
				ButMdlViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewAvail", mask, BUTMDLVIEWAVAIL);
				ButMdlViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", mask, BUTMDLVIEWACTIVE);
				TxtFarActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtFarActive", mask, TXTFARACTIVE);
				TxfFarValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfFarValid", mask, TXFFARVALID);
				ButFarViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFarViewAvail", mask, BUTFARVIEWAVAIL);
				TxtSarActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSarActive", mask, TXTSARACTIVE);
				TxfSarValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSarValid", mask, TXFSARVALID);
				ButSarViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSarViewAvail", mask, BUTSARVIEWAVAIL);
				TxfRatActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfRatActive", mask, TXFRATACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtFckActive == comp.TxtFckActive) items.add(TXTFCKACTIVE);
			if (TxfFckValid == comp.TxfFckValid) items.add(TXFFCKVALID);
			if (ButFckViewAvail == comp.ButFckViewAvail) items.add(BUTFCKVIEWAVAIL);
			if (TxtSckActive == comp.TxtSckActive) items.add(TXTSCKACTIVE);
			if (TxfSckValid == comp.TxfSckValid) items.add(TXFSCKVALID);
			if (ButSckViewAvail == comp.ButSckViewAvail) items.add(BUTSCKVIEWAVAIL);
			if (TxtMdlActive == comp.TxtMdlActive) items.add(TXTMDLACTIVE);
			if (ButMdlViewAvail == comp.ButMdlViewAvail) items.add(BUTMDLVIEWAVAIL);
			if (ButMdlViewActive == comp.ButMdlViewActive) items.add(BUTMDLVIEWACTIVE);
			if (TxtFarActive == comp.TxtFarActive) items.add(TXTFARACTIVE);
			if (TxfFarValid == comp.TxfFarValid) items.add(TXFFARVALID);
			if (ButFarViewAvail == comp.ButFarViewAvail) items.add(BUTFARVIEWAVAIL);
			if (TxtSarActive == comp.TxtSarActive) items.add(TXTSARACTIVE);
			if (TxfSarValid == comp.TxfSarValid) items.add(TXFSARVALID);
			if (ButSarViewAvail == comp.ButSarViewAvail) items.add(BUTSARVIEWAVAIL);
			if (TxfRatActive == comp.TxfRatActive) items.add(TXFRATACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTFCKACTIVE, TXFFCKVALID, BUTFCKVIEWAVAIL, TXTSCKACTIVE, TXFSCKVALID, BUTSCKVIEWAVAIL, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, TXTFARACTIVE, TXFFARVALID, BUTFARVIEWAVAIL, TXTSARACTIVE, TXFSARVALID, BUTSARVIEWAVAIL, TXFRATACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeCdcDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTFCK = 2;
		public static final int CPTSCK = 3;
		public static final int CPTMDL = 4;
		public static final int CPTFAR = 5;
		public static final int CPTSAR = 6;
		public static final int CPTRAT = 7;

		public Tag(
					String Cpt
					, String CptFck
					, String CptSck
					, String CptMdl
					, String CptFar
					, String CptSar
					, String CptRat
				) {
			this.Cpt = Cpt;
			this.CptFck = CptFck;
			this.CptSck = CptSck;
			this.CptMdl = CptMdl;
			this.CptFar = CptFar;
			this.CptSar = CptSar;
			this.CptRat = CptRat;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTFCK, CPTSCK, CPTMDL, CPTFAR, CPTSAR, CPTRAT));
		};

		public String Cpt;
		public String CptFck;
		public String CptSck;
		public String CptMdl;
		public String CptFar;
		public String CptSar;
		public String CptRat;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeCdcDetail");

			String itemtag = "TagitemWdbeCdcDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptFck = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFck", mask, CPTFCK);
				CptSck = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSck", mask, CPTSCK);
				CptMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMdl", mask, CPTMDL);
				CptFar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFar", mask, CPTFAR);
				CptSar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSar", mask, CPTSAR);
				CptRat = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRat", mask, CPTRAT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptFck.equals(comp.CptFck)) items.add(CPTFCK);
			if (CptSck.equals(comp.CptSck)) items.add(CPTSCK);
			if (CptMdl.equals(comp.CptMdl)) items.add(CPTMDL);
			if (CptFar.equals(comp.CptFar)) items.add(CPTFAR);
			if (CptSar.equals(comp.CptSar)) items.add(CPTSAR);
			if (CptRat.equals(comp.CptRat)) items.add(CPTRAT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTFCK, CPTSCK, CPTMDL, CPTFAR, CPTSAR, CPTRAT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeCdcDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBECDCDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeCdcDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeCdcDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBECDCDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeCdcDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeCdcDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBECDCDETAILDATA);

			contiac = new ContIac("", "", "", "", "");
			continf = new ContInf("", "", "", "", "");
			statapp = new StatApp(0, false, false, false, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeCdcDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", "", "", "");
				continf = new ContInf("", "", "", "", "");
				statapp = new StatApp(0, false, false, false, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "");
			};
		};

	};

};
