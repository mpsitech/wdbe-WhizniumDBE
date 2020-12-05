/**
  * \file DlgWdbeRlsWrite.java
  * Java API code for job DlgWdbeRlsWrite
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWdbeRlsWrite {
	/**
		* VecVDit (full: VecVDlgWdbeRlsWriteDit)
		*/
	public static class VecVDit {

		public static final int DET = 1;
		public static final int CUC = 2;
		public static final int WRC = 3;
		public static final int LFI = 4;
		public static final int FIA = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("det")) return DET;
			if (s.equals("cuc")) return CUC;
			if (s.equals("wrc")) return WRC;
			if (s.equals("lfi")) return LFI;
			if (s.equals("fia")) return FIA;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == DET) return("Det");
			if (ix == CUC) return("Cuc");
			if (ix == WRC) return("Wrc");
			if (ix == LFI) return("Lfi");
			if (ix == FIA) return("Fia");

			return "";
		};

	};

	/**
		* VecVDo (full: VecVDlgWdbeRlsWriteDo)
		*/
	public static class VecVDo {

		public static final int BUTDNECLICK = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butdneclick")) return BUTDNECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTDNECLICK) return("ButDneClick");

			return "";
		};

	};

	/**
		* VecVDoWrc (full: VecVDlgWdbeRlsWriteDoWrc)
		*/
	public static class VecVDoWrc {

		public static final int BUTAUTCLICK = 1;
		public static final int BUTRUNCLICK = 2;
		public static final int BUTSTOCLICK = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butautclick")) return BUTAUTCLICK;
			if (s.equals("butrunclick")) return BUTRUNCLICK;
			if (s.equals("butstoclick")) return BUTSTOCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTAUTCLICK) return("ButAutClick");
			if (ix == BUTRUNCLICK) return("ButRunClick");
			if (ix == BUTSTOCLICK) return("ButStoClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWdbeRlsWriteSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRAER = 2;
		public static final int ALRMER = 3;
		public static final int UPKIDLE = 4;
		public static final int UNPACK = 5;
		public static final int UPKDONE = 6;
		public static final int AUTH = 7;
		public static final int AUTDONE = 8;
		public static final int FILLPLH = 9;
		public static final int CREATE = 10;
		public static final int WRITE = 11;
		public static final int MRG = 12;
		public static final int MRGFINE = 13;
		public static final int MRGTYPSPEC = 14;
		public static final int MRGTPLSPEC = 15;
		public static final int CLRSPEC = 16;
		public static final int MRGCUST = 17;
		public static final int PACK = 18;
		public static final int FAIL = 19;
		public static final int DONE = 20;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alraer")) return ALRAER;
			if (s.equals("alrmer")) return ALRMER;
			if (s.equals("upkidle")) return UPKIDLE;
			if (s.equals("unpack")) return UNPACK;
			if (s.equals("upkdone")) return UPKDONE;
			if (s.equals("auth")) return AUTH;
			if (s.equals("autdone")) return AUTDONE;
			if (s.equals("fillplh")) return FILLPLH;
			if (s.equals("create")) return CREATE;
			if (s.equals("write")) return WRITE;
			if (s.equals("mrg")) return MRG;
			if (s.equals("mrgfine")) return MRGFINE;
			if (s.equals("mrgtypspec")) return MRGTYPSPEC;
			if (s.equals("mrgtplspec")) return MRGTPLSPEC;
			if (s.equals("clrspec")) return CLRSPEC;
			if (s.equals("mrgcust")) return MRGCUST;
			if (s.equals("pack")) return PACK;
			if (s.equals("fail")) return FAIL;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRAER) return("alraer");
			if (ix == ALRMER) return("alrmer");
			if (ix == UPKIDLE) return("upkidle");
			if (ix == UNPACK) return("unpack");
			if (ix == UPKDONE) return("upkdone");
			if (ix == AUTH) return("auth");
			if (ix == AUTDONE) return("autdone");
			if (ix == FILLPLH) return("fillplh");
			if (ix == CREATE) return("create");
			if (ix == WRITE) return("write");
			if (ix == MRG) return("mrg");
			if (ix == MRGFINE) return("mrgfine");
			if (ix == MRGTYPSPEC) return("mrgtypspec");
			if (ix == MRGTPLSPEC) return("mrgtplspec");
			if (ix == CLRSPEC) return("clrspec");
			if (ix == MRGCUST) return("mrgcust");
			if (ix == PACK) return("pack");
			if (ix == FAIL) return("fail");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWdbeRlsWrite)
	  */
	public class ContIac extends Block {

		public static final int NUMFDSE = 1;

		public ContIac(
					int numFDse
				) {
			this.numFDse = numFDse;

			mask = new HashSet<Integer>(Arrays.asList(NUMFDSE));
		};

		public int numFDse;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWdbeRlsWrite");

			String itemtag = "ContitemIacDlgWdbeRlsWrite";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFDse = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDse", mask, NUMFDSE);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWdbeRlsWrite";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWdbeRlsWrite";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDse", numFDse);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFDse == comp.numFDse) items.add(NUMFDSE);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFDSE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContIacDet (full: ContIacDlgWdbeRlsWriteDet)
	  */
	public class ContIacDet extends Block {

		public static final int CHKBSO = 1;

		public ContIacDet(
					boolean ChkBso
				) {
			this.ChkBso = ChkBso;

			mask = new HashSet<Integer>(Arrays.asList(CHKBSO));
		};

		public boolean ChkBso;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWdbeRlsWriteDet");

			String itemtag = "ContitemIacDlgWdbeRlsWriteDet";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ChkBso = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkBso", mask, CHKBSO);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWdbeRlsWriteDet";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWdbeRlsWriteDet";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkBso", ChkBso);
		};

		public HashSet<Integer> comm(
					ContIacDet comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ChkBso == comp.ChkBso) items.add(CHKBSO);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIacDet comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CHKBSO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWdbeRlsWrite)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;

		public ContInf(
					int numFSge
				) {
			this.numFSge = numFSge;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE));
		};

		public int numFSge;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeRlsWrite");

			String itemtag = "ContitemInfDlgWdbeRlsWrite";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInfFia (full: ContInfDlgWdbeRlsWriteFia)
	  */
	public class ContInfFia extends Block {

		public static final int DLD = 1;

		public ContInfFia(
					String Dld
				) {
			this.Dld = Dld;

			mask = new HashSet<Integer>(Arrays.asList(DLD));
		};

		public String Dld;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeRlsWriteFia");

			String itemtag = "ContitemInfDlgWdbeRlsWriteFia";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfFia comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfFia comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInfLfi (full: ContInfDlgWdbeRlsWriteLfi)
	  */
	public class ContInfLfi extends Block {

		public static final int DLD = 1;

		public ContInfLfi(
					String Dld
				) {
			this.Dld = Dld;

			mask = new HashSet<Integer>(Arrays.asList(DLD));
		};

		public String Dld;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeRlsWriteLfi");

			String itemtag = "ContitemInfDlgWdbeRlsWriteLfi";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfLfi comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfLfi comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInfWrc (full: ContInfDlgWdbeRlsWriteWrc)
	  */
	public class ContInfWrc extends Block {

		public static final int TXTPRG = 1;

		public ContInfWrc(
					String TxtPrg
				) {
			this.TxtPrg = TxtPrg;

			mask = new HashSet<Integer>(Arrays.asList(TXTPRG));
		};

		public String TxtPrg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeRlsWriteWrc");

			String itemtag = "ContitemInfDlgWdbeRlsWriteWrc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrg", mask, TXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfWrc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrg.equals(comp.TxtPrg)) items.add(TXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfWrc comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTPRG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWdbeRlsWrite)
	  */
	public class StatApp extends Block {

		public static final int INITDONE = 1;
		public static final int SHORTMENU = 2;

		public StatApp(
					boolean initdone
					, String shortMenu
				) {
			this.initdone = initdone;
			this.shortMenu = shortMenu;

			mask = new HashSet<Integer>(Arrays.asList(INITDONE, SHORTMENU));
		};

		public boolean initdone;
		public String shortMenu;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWdbeRlsWrite");

			String itemtag = "StatitemAppDlgWdbeRlsWrite";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdone = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone", mask, INITDONE);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdone == comp.initdone) items.add(INITDONE);
			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONE, SHORTMENU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrDlgWdbeRlsWrite)
	  */
	public class StatShr extends Block {

		public static final int BUTDNEACTIVE = 1;

		public StatShr(
					boolean ButDneActive
				) {
			this.ButDneActive = ButDneActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTDNEACTIVE));
		};

		public boolean ButDneActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsWrite");

			String itemtag = "StatitemShrDlgWdbeRlsWrite";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButDneActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDneActive", mask, BUTDNEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButDneActive == comp.ButDneActive) items.add(BUTDNEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTDNEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrCuc (full: StatShrDlgWdbeRlsWriteCuc)
	  */
	public class StatShrCuc extends Block {

		public static final int ULDAVAIL = 1;
		public static final int ULDACTIVE = 2;

		public StatShrCuc(
					boolean UldAvail
					, boolean UldActive
				) {
			this.UldAvail = UldAvail;
			this.UldActive = UldActive;

			mask = new HashSet<Integer>(Arrays.asList(ULDAVAIL, ULDACTIVE));
		};

		public boolean UldAvail;
		public boolean UldActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsWriteCuc");

			String itemtag = "StatitemShrDlgWdbeRlsWriteCuc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				UldAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UldAvail", mask, ULDAVAIL);
				UldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UldActive", mask, ULDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrCuc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (UldAvail == comp.UldAvail) items.add(ULDAVAIL);
			if (UldActive == comp.UldActive) items.add(ULDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrCuc comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(ULDAVAIL, ULDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrFia (full: StatShrDlgWdbeRlsWriteFia)
	  */
	public class StatShrFia extends Block {

		public static final int DLDAVAIL = 1;
		public static final int DLDACTIVE = 2;

		public StatShrFia(
					boolean DldAvail
					, boolean DldActive
				) {
			this.DldAvail = DldAvail;
			this.DldActive = DldActive;

			mask = new HashSet<Integer>(Arrays.asList(DLDAVAIL, DLDACTIVE));
		};

		public boolean DldAvail;
		public boolean DldActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsWriteFia");

			String itemtag = "StatitemShrDlgWdbeRlsWriteFia";

			if (Xmlio.checkXPath(doc, basexpath)) {
				DldAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DldAvail", mask, DLDAVAIL);
				DldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DldActive", mask, DLDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrFia comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (DldAvail == comp.DldAvail) items.add(DLDAVAIL);
			if (DldActive == comp.DldActive) items.add(DLDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrFia comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLDAVAIL, DLDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrLfi (full: StatShrDlgWdbeRlsWriteLfi)
	  */
	public class StatShrLfi extends Block {

		public static final int DLDACTIVE = 1;

		public StatShrLfi(
					boolean DldActive
				) {
			this.DldActive = DldActive;

			mask = new HashSet<Integer>(Arrays.asList(DLDACTIVE));
		};

		public boolean DldActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsWriteLfi");

			String itemtag = "StatitemShrDlgWdbeRlsWriteLfi";

			if (Xmlio.checkXPath(doc, basexpath)) {
				DldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DldActive", mask, DLDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrLfi comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (DldActive == comp.DldActive) items.add(DLDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrLfi comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrWrc (full: StatShrDlgWdbeRlsWriteWrc)
	  */
	public class StatShrWrc extends Block {

		public static final int BUTAUTACTIVE = 1;
		public static final int BUTRUNACTIVE = 2;
		public static final int BUTSTOACTIVE = 3;

		public StatShrWrc(
					boolean ButAutActive
					, boolean ButRunActive
					, boolean ButStoActive
				) {
			this.ButAutActive = ButAutActive;
			this.ButRunActive = ButRunActive;
			this.ButStoActive = ButStoActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTAUTACTIVE, BUTRUNACTIVE, BUTSTOACTIVE));
		};

		public boolean ButAutActive;
		public boolean ButRunActive;
		public boolean ButStoActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsWriteWrc");

			String itemtag = "StatitemShrDlgWdbeRlsWriteWrc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButAutActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButAutActive", mask, BUTAUTACTIVE);
				ButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRunActive", mask, BUTRUNACTIVE);
				ButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStoActive", mask, BUTSTOACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrWrc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButAutActive == comp.ButAutActive) items.add(BUTAUTACTIVE);
			if (ButRunActive == comp.ButRunActive) items.add(BUTRUNACTIVE);
			if (ButStoActive == comp.ButStoActive) items.add(BUTSTOACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrWrc comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTAUTACTIVE, BUTRUNACTIVE, BUTSTOACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWdbeRlsWrite)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int BUTDNE = 2;

		public Tag(
					String Cpt
					, String ButDne
				) {
			this.Cpt = Cpt;
			this.ButDne = ButDne;

			mask = new HashSet<Integer>(Arrays.asList(CPT, BUTDNE));
		};

		public String Cpt;
		public String ButDne;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsWrite");

			String itemtag = "TagitemDlgWdbeRlsWrite";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				ButDne = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButDne", mask, BUTDNE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (ButDne.equals(comp.ButDne)) items.add(BUTDNE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, BUTDNE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagCuc (full: TagDlgWdbeRlsWriteCuc)
	  */
	public class TagCuc extends Block {

		public static final int ULD = 1;
		public static final int CPT = 2;

		public TagCuc(
					String Uld
					, String Cpt
				) {
			this.Uld = Uld;
			this.Cpt = Cpt;

			mask = new HashSet<Integer>(Arrays.asList(ULD, CPT));
		};

		public String Uld;
		public String Cpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsWriteCuc");

			String itemtag = "TagitemDlgWdbeRlsWriteCuc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Uld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Uld", mask, ULD);
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagCuc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Uld.equals(comp.Uld)) items.add(ULD);
			if (Cpt.equals(comp.Cpt)) items.add(CPT);

			return(items);
		};

		public HashSet<Integer> diff(
					TagCuc comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(ULD, CPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagDet (full: TagDlgWdbeRlsWriteDet)
	  */
	public class TagDet extends Block {

		public static final int CPTBSO = 1;

		public TagDet(
					String CptBso
				) {
			this.CptBso = CptBso;

			mask = new HashSet<Integer>(Arrays.asList(CPTBSO));
		};

		public String CptBso;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsWriteDet");

			String itemtag = "TagitemDlgWdbeRlsWriteDet";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptBso = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptBso", mask, CPTBSO);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagDet comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptBso.equals(comp.CptBso)) items.add(CPTBSO);

			return(items);
		};

		public HashSet<Integer> diff(
					TagDet comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTBSO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagFia (full: TagDlgWdbeRlsWriteFia)
	  */
	public class TagFia extends Block {

		public static final int DLD = 1;

		public TagFia(
					String Dld
				) {
			this.Dld = Dld;

			mask = new HashSet<Integer>(Arrays.asList(DLD));
		};

		public String Dld;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsWriteFia");

			String itemtag = "TagitemDlgWdbeRlsWriteFia";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagFia comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					TagFia comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagLfi (full: TagDlgWdbeRlsWriteLfi)
	  */
	public class TagLfi extends Block {

		public static final int DLD = 1;

		public TagLfi(
					String Dld
				) {
			this.Dld = Dld;

			mask = new HashSet<Integer>(Arrays.asList(DLD));
		};

		public String Dld;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsWriteLfi");

			String itemtag = "TagitemDlgWdbeRlsWriteLfi";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagLfi comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					TagLfi comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagWrc (full: TagDlgWdbeRlsWriteWrc)
	  */
	public class TagWrc extends Block {

		public static final int CPTPRG = 1;
		public static final int BUTAUT = 2;
		public static final int BUTRUN = 3;
		public static final int BUTSTO = 4;

		public TagWrc(
					String CptPrg
					, String ButAut
					, String ButRun
					, String ButSto
				) {
			this.CptPrg = CptPrg;
			this.ButAut = ButAut;
			this.ButRun = ButRun;
			this.ButSto = ButSto;

			mask = new HashSet<Integer>(Arrays.asList(CPTPRG, BUTAUT, BUTRUN, BUTSTO));
		};

		public String CptPrg;
		public String ButAut;
		public String ButRun;
		public String ButSto;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsWriteWrc");

			String itemtag = "TagitemDlgWdbeRlsWriteWrc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrg", mask, CPTPRG);
				ButAut = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButAut", mask, BUTAUT);
				ButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButRun", mask, BUTRUN);
				ButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButSto", mask, BUTSTO);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagWrc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptPrg.equals(comp.CptPrg)) items.add(CPTPRG);
			if (ButAut.equals(comp.ButAut)) items.add(BUTAUT);
			if (ButRun.equals(comp.ButRun)) items.add(BUTRUN);
			if (ButSto.equals(comp.ButSto)) items.add(BUTSTO);

			return(items);
		};

		public HashSet<Integer> diff(
					TagWrc comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTPRG, BUTAUT, BUTRUN, BUTSTO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeRlsWriteData)
		*/
	public class DpchAppData extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTIACDET = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, ContIacDet contiacdet
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPDLGWDBERLSWRITEDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC, CONTIACDET));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
			if (has(CONTIACDET)) this.contiacdet = contiacdet;
		};

		public ContIac contiac;
		public ContIacDet contiacdet;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTIACDET)) ss.add("contiacdet");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWdbeRlsWriteData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
			if (has(CONTIACDET)) contiacdet.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeRlsWriteDo)
		*/
	public class DpchAppDo extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int IXVDOWRC = 3;
		public static final int ALL = 4;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, int ixVDoWrc
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPDLGWDBERLSWRITEDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO, IXVDOWRC));
					break;
				};

			this.ixVDo = ixVDo;
			this.ixVDoWrc = ixVDoWrc;
		};

		public int ixVDo;
		public int ixVDoWrc;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");
			if (has(IXVDOWRC)) ss.add("ixVDoWrc");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWdbeRlsWriteDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
			if (has(IXVDOWRC)) Xmlio.writeString(doc, el, "srefIxVDoWrc", VecVDoWrc.getSref(ixVDoWrc));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeRlsWriteData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTIACDET = 3;
		public static final int CONTINF = 4;
		public static final int CONTINFFIA = 5;
		public static final int CONTINFLFI = 6;
		public static final int CONTINFWRC = 7;
		public static final int FEEDFDSE = 8;
		public static final int FEEDFSGE = 9;
		public static final int STATAPP = 10;
		public static final int STATSHR = 11;
		public static final int STATSHRCUC = 12;
		public static final int STATSHRFIA = 13;
		public static final int STATSHRLFI = 14;
		public static final int STATSHRWRC = 15;
		public static final int TAG = 16;
		public static final int TAGCUC = 17;
		public static final int TAGDET = 18;
		public static final int TAGFIA = 19;
		public static final int TAGLFI = 20;
		public static final int TAGWRC = 21;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGDLGWDBERLSWRITEDATA);

			contiac = new ContIac(0);
			contiacdet = new ContIacDet(false);
			continf = new ContInf(0);
			continffia = new ContInfFia("");
			continflfi = new ContInfLfi("");
			continfwrc = new ContInfWrc("");
			feedFDse = new Feed("FeedFDse");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(false, "");
			statshr = new StatShr(false);
			statshrcuc = new StatShrCuc(false, false);
			statshrfia = new StatShrFia(false, false);
			statshrlfi = new StatShrLfi(false);
			statshrwrc = new StatShrWrc(false, false, false);
			tag = new Tag("", "");
			tagcuc = new TagCuc("", "");
			tagdet = new TagDet("");
			tagfia = new TagFia("");
			taglfi = new TagLfi("");
			tagwrc = new TagWrc("", "", "", "");
		};

		public ContIac contiac;
		public ContIacDet contiacdet;
		public ContInf continf;
		public ContInfFia continffia;
		public ContInfLfi continflfi;
		public ContInfWrc continfwrc;
		public Feed feedFDse;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public StatShrCuc statshrcuc;
		public StatShrFia statshrfia;
		public StatShrLfi statshrlfi;
		public StatShrWrc statshrwrc;
		public Tag tag;
		public TagCuc tagcuc;
		public TagDet tagdet;
		public TagFia tagfia;
		public TagLfi taglfi;
		public TagWrc tagwrc;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTIACDET)) ss.add("contiacdet");
			if (has(CONTINF)) ss.add("continf");
			if (has(CONTINFFIA)) ss.add("continffia");
			if (has(CONTINFLFI)) ss.add("continflfi");
			if (has(CONTINFWRC)) ss.add("continfwrc");
			if (has(FEEDFDSE)) ss.add("feedFDse");
			if (has(FEEDFSGE)) ss.add("feedFSge");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STATSHRCUC)) ss.add("statshrcuc");
			if (has(STATSHRFIA)) ss.add("statshrfia");
			if (has(STATSHRLFI)) ss.add("statshrlfi");
			if (has(STATSHRWRC)) ss.add("statshrwrc");
			if (has(TAG)) ss.add("tag");
			if (has(TAGCUC)) ss.add("tagcuc");
			if (has(TAGDET)) ss.add("tagdet");
			if (has(TAGFIA)) ss.add("tagfia");
			if (has(TAGLFI)) ss.add("taglfi");
			if (has(TAGWRC)) ss.add("tagwrc");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWdbeRlsWriteData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (contiacdet.readXML(doc, basexpath, true)) add(CONTIACDET);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (continffia.readXML(doc, basexpath, true)) add(CONTINFFIA);
				if (continflfi.readXML(doc, basexpath, true)) add(CONTINFLFI);
				if (continfwrc.readXML(doc, basexpath, true)) add(CONTINFWRC);
				if (feedFDse.readXML(doc, basexpath, true)) add(FEEDFDSE);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (statshrcuc.readXML(doc, basexpath, true)) add(STATSHRCUC);
				if (statshrfia.readXML(doc, basexpath, true)) add(STATSHRFIA);
				if (statshrlfi.readXML(doc, basexpath, true)) add(STATSHRLFI);
				if (statshrwrc.readXML(doc, basexpath, true)) add(STATSHRWRC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (tagcuc.readXML(doc, basexpath, true)) add(TAGCUC);
				if (tagdet.readXML(doc, basexpath, true)) add(TAGDET);
				if (tagfia.readXML(doc, basexpath, true)) add(TAGFIA);
				if (taglfi.readXML(doc, basexpath, true)) add(TAGLFI);
				if (tagwrc.readXML(doc, basexpath, true)) add(TAGWRC);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				contiacdet = new ContIacDet(false);
				continf = new ContInf(0);
				continffia = new ContInfFia("");
				continflfi = new ContInfLfi("");
				continfwrc = new ContInfWrc("");
				feedFDse = new Feed("FeedFDse");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(false, "");
				statshr = new StatShr(false);
				statshrcuc = new StatShrCuc(false, false);
				statshrfia = new StatShrFia(false, false);
				statshrlfi = new StatShrLfi(false);
				statshrwrc = new StatShrWrc(false, false, false);
				tag = new Tag("", "");
				tagcuc = new TagCuc("", "");
				tagdet = new TagDet("");
				tagfia = new TagFia("");
				taglfi = new TagLfi("");
				tagwrc = new TagWrc("", "", "", "");
			};
		};

	};

};

