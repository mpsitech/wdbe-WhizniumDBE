/**
  * \file DlgWdbeRlsStareptr.java
  * Java API code for job DlgWdbeRlsStareptr
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWdbeRlsStareptr {
	/**
		* VecVDit (full: VecVDlgWdbeRlsStareptrDit)
		*/
	public static class VecVDit {

		public static final int DET = 1;
		public static final int INI = 2;
		public static final int EXT = 3;
		public static final int LFI = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("det")) return DET;
			if (s.equals("ini")) return INI;
			if (s.equals("ext")) return EXT;
			if (s.equals("lfi")) return LFI;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == DET) return("Det");
			if (ix == INI) return("Ini");
			if (ix == EXT) return("Ext");
			if (ix == LFI) return("Lfi");

			return "";
		};

	};

	/**
		* VecVDo (full: VecVDlgWdbeRlsStareptrDo)
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
		* VecVDoDet (full: VecVDlgWdbeRlsStareptrDoDet)
		*/
	public static class VecVDoDet {

		public static final int BUTSTACLICK = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butstaclick")) return BUTSTACLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSTACLICK) return("ButStaClick");

			return "";
		};

	};

	/**
		* VecVDoExt (full: VecVDlgWdbeRlsStareptrDoExt)
		*/
	public static class VecVDoExt {

		public static final int BUTRUNCLICK = 1;
		public static final int BUTSTOCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butrunclick")) return BUTRUNCLICK;
			if (s.equals("butstoclick")) return BUTSTOCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTRUNCLICK) return("ButRunClick");
			if (ix == BUTSTOCLICK) return("ButStoClick");

			return "";
		};

	};

	/**
		* VecVDoIni (full: VecVDlgWdbeRlsStareptrDoIni)
		*/
	public static class VecVDoIni {

		public static final int BUTCLGCLICK = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butclgclick")) return BUTCLGCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTCLGCLICK) return("ButClgClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWdbeRlsStareptrSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRGNF = 2;
		public static final int ALRGAD = 3;
		public static final int ALRGVE = 4;
		public static final int ALRXER = 5;
		public static final int STADONE = 6;
		public static final int UPKIDLE = 7;
		public static final int UNPACK = 8;
		public static final int UPKDONE = 9;
		public static final int CLGIDLE = 10;
		public static final int CLONEGIT = 11;
		public static final int CLGDONE = 12;
		public static final int EXTRACT = 13;
		public static final int PACK = 14;
		public static final int FAIL = 15;
		public static final int DONE = 16;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrgnf")) return ALRGNF;
			if (s.equals("alrgad")) return ALRGAD;
			if (s.equals("alrgve")) return ALRGVE;
			if (s.equals("alrxer")) return ALRXER;
			if (s.equals("stadone")) return STADONE;
			if (s.equals("upkidle")) return UPKIDLE;
			if (s.equals("unpack")) return UNPACK;
			if (s.equals("upkdone")) return UPKDONE;
			if (s.equals("clgidle")) return CLGIDLE;
			if (s.equals("clonegit")) return CLONEGIT;
			if (s.equals("clgdone")) return CLGDONE;
			if (s.equals("extract")) return EXTRACT;
			if (s.equals("pack")) return PACK;
			if (s.equals("fail")) return FAIL;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRGNF) return("alrgnf");
			if (ix == ALRGAD) return("alrgad");
			if (ix == ALRGVE) return("alrgve");
			if (ix == ALRXER) return("alrxer");
			if (ix == STADONE) return("stadone");
			if (ix == UPKIDLE) return("upkidle");
			if (ix == UNPACK) return("unpack");
			if (ix == UPKDONE) return("upkdone");
			if (ix == CLGIDLE) return("clgidle");
			if (ix == CLONEGIT) return("clonegit");
			if (ix == CLGDONE) return("clgdone");
			if (ix == EXTRACT) return("extract");
			if (ix == PACK) return("pack");
			if (ix == FAIL) return("fail");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWdbeRlsStareptr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWdbeRlsStareptr");

			String itemtag = "ContitemIacDlgWdbeRlsStareptr";

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWdbeRlsStareptr";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWdbeRlsStareptr";

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
	  * ContIacDet (full: ContIacDlgWdbeRlsStareptrDet)
	  */
	public class ContIacDet extends Block {

		public static final int NUMFRBUBRT = 1;
		public static final int TXFGRL = 2;

		public ContIacDet(
					int numFRbuBrt
					, String TxfGrl
				) {
			this.numFRbuBrt = numFRbuBrt;
			this.TxfGrl = TxfGrl;

			mask = new HashSet<Integer>(Arrays.asList(NUMFRBUBRT, TXFGRL));
		};

		public int numFRbuBrt;
		public String TxfGrl;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWdbeRlsStareptrDet");

			String itemtag = "ContitemIacDlgWdbeRlsStareptrDet";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFRbuBrt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFRbuBrt", mask, NUMFRBUBRT);
				TxfGrl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfGrl", mask, TXFGRL);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWdbeRlsStareptrDet";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWdbeRlsStareptrDet";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFRbuBrt", numFRbuBrt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfGrl", TxfGrl);
		};

		public HashSet<Integer> comm(
					ContIacDet comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFRbuBrt == comp.numFRbuBrt) items.add(NUMFRBUBRT);
			if (TxfGrl.equals(comp.TxfGrl)) items.add(TXFGRL);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIacDet comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFRBUBRT, TXFGRL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWdbeRlsStareptr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeRlsStareptr");

			String itemtag = "ContitemInfDlgWdbeRlsStareptr";

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
	  * ContInfExt (full: ContInfDlgWdbeRlsStareptrExt)
	  */
	public class ContInfExt extends Block {

		public static final int TXTPRG = 1;

		public ContInfExt(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeRlsStareptrExt");

			String itemtag = "ContitemInfDlgWdbeRlsStareptrExt";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrg", mask, TXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfExt comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrg.equals(comp.TxtPrg)) items.add(TXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfExt comp
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
	  * ContInfIni (full: ContInfDlgWdbeRlsStareptrIni)
	  */
	public class ContInfIni extends Block {

		public static final int TXTPRG = 1;

		public ContInfIni(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeRlsStareptrIni");

			String itemtag = "ContitemInfDlgWdbeRlsStareptrIni";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrg", mask, TXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfIni comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrg.equals(comp.TxtPrg)) items.add(TXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfIni comp
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
	  * ContInfLfi (full: ContInfDlgWdbeRlsStareptrLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeRlsStareptrLfi");

			String itemtag = "ContitemInfDlgWdbeRlsStareptrLfi";

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
	  * StatApp (full: StatAppDlgWdbeRlsStareptr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWdbeRlsStareptr");

			String itemtag = "StatitemAppDlgWdbeRlsStareptr";

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
	  * StatShr (full: StatShrDlgWdbeRlsStareptr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsStareptr");

			String itemtag = "StatitemShrDlgWdbeRlsStareptr";

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
	  * StatShrDet (full: StatShrDlgWdbeRlsStareptrDet)
	  */
	public class StatShrDet extends Block {

		public static final int TXFGRLAVAIL = 1;
		public static final int BUTSTAACTIVE = 2;

		public StatShrDet(
					boolean TxfGrlAvail
					, boolean ButStaActive
				) {
			this.TxfGrlAvail = TxfGrlAvail;
			this.ButStaActive = ButStaActive;

			mask = new HashSet<Integer>(Arrays.asList(TXFGRLAVAIL, BUTSTAACTIVE));
		};

		public boolean TxfGrlAvail;
		public boolean ButStaActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsStareptrDet");

			String itemtag = "StatitemShrDlgWdbeRlsStareptrDet";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfGrlAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfGrlAvail", mask, TXFGRLAVAIL);
				ButStaActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStaActive", mask, BUTSTAACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrDet comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfGrlAvail == comp.TxfGrlAvail) items.add(TXFGRLAVAIL);
			if (ButStaActive == comp.ButStaActive) items.add(BUTSTAACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrDet comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFGRLAVAIL, BUTSTAACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrExt (full: StatShrDlgWdbeRlsStareptrExt)
	  */
	public class StatShrExt extends Block {

		public static final int BUTRUNACTIVE = 1;
		public static final int BUTSTOACTIVE = 2;

		public StatShrExt(
					boolean ButRunActive
					, boolean ButStoActive
				) {
			this.ButRunActive = ButRunActive;
			this.ButStoActive = ButStoActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTRUNACTIVE, BUTSTOACTIVE));
		};

		public boolean ButRunActive;
		public boolean ButStoActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsStareptrExt");

			String itemtag = "StatitemShrDlgWdbeRlsStareptrExt";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRunActive", mask, BUTRUNACTIVE);
				ButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStoActive", mask, BUTSTOACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrExt comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButRunActive == comp.ButRunActive) items.add(BUTRUNACTIVE);
			if (ButStoActive == comp.ButStoActive) items.add(BUTSTOACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrExt comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTRUNACTIVE, BUTSTOACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrIni (full: StatShrDlgWdbeRlsStareptrIni)
	  */
	public class StatShrIni extends Block {

		public static final int ULDAVAIL = 1;
		public static final int ULDACTIVE = 2;
		public static final int TXTPRGAVAIL = 3;
		public static final int SEP1AVAIL = 4;
		public static final int BUTCLGAVAIL = 5;
		public static final int BUTCLGACTIVE = 6;

		public StatShrIni(
					boolean UldAvail
					, boolean UldActive
					, boolean TxtPrgAvail
					, boolean Sep1Avail
					, boolean ButClgAvail
					, boolean ButClgActive
				) {
			this.UldAvail = UldAvail;
			this.UldActive = UldActive;
			this.TxtPrgAvail = TxtPrgAvail;
			this.Sep1Avail = Sep1Avail;
			this.ButClgAvail = ButClgAvail;
			this.ButClgActive = ButClgActive;

			mask = new HashSet<Integer>(Arrays.asList(ULDAVAIL, ULDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTCLGAVAIL, BUTCLGACTIVE));
		};

		public boolean UldAvail;
		public boolean UldActive;
		public boolean TxtPrgAvail;
		public boolean Sep1Avail;
		public boolean ButClgAvail;
		public boolean ButClgActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsStareptrIni");

			String itemtag = "StatitemShrDlgWdbeRlsStareptrIni";

			if (Xmlio.checkXPath(doc, basexpath)) {
				UldAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UldAvail", mask, ULDAVAIL);
				UldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UldActive", mask, ULDACTIVE);
				TxtPrgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPrgAvail", mask, TXTPRGAVAIL);
				Sep1Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Sep1Avail", mask, SEP1AVAIL);
				ButClgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButClgAvail", mask, BUTCLGAVAIL);
				ButClgActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButClgActive", mask, BUTCLGACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrIni comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (UldAvail == comp.UldAvail) items.add(ULDAVAIL);
			if (UldActive == comp.UldActive) items.add(ULDACTIVE);
			if (TxtPrgAvail == comp.TxtPrgAvail) items.add(TXTPRGAVAIL);
			if (Sep1Avail == comp.Sep1Avail) items.add(SEP1AVAIL);
			if (ButClgAvail == comp.ButClgAvail) items.add(BUTCLGAVAIL);
			if (ButClgActive == comp.ButClgActive) items.add(BUTCLGACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrIni comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(ULDAVAIL, ULDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTCLGAVAIL, BUTCLGACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrLfi (full: StatShrDlgWdbeRlsStareptrLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsStareptrLfi");

			String itemtag = "StatitemShrDlgWdbeRlsStareptrLfi";

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
	  * Tag (full: TagDlgWdbeRlsStareptr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsStareptr");

			String itemtag = "TagitemDlgWdbeRlsStareptr";

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
	  * TagDet (full: TagDlgWdbeRlsStareptrDet)
	  */
	public class TagDet extends Block {

		public static final int CPTBRT = 1;
		public static final int CPTGRL = 2;
		public static final int BUTSTA = 3;

		public TagDet(
					String CptBrt
					, String CptGrl
					, String ButSta
				) {
			this.CptBrt = CptBrt;
			this.CptGrl = CptGrl;
			this.ButSta = ButSta;

			mask = new HashSet<Integer>(Arrays.asList(CPTBRT, CPTGRL, BUTSTA));
		};

		public String CptBrt;
		public String CptGrl;
		public String ButSta;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsStareptrDet");

			String itemtag = "TagitemDlgWdbeRlsStareptrDet";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptBrt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptBrt", mask, CPTBRT);
				CptGrl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptGrl", mask, CPTGRL);
				ButSta = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButSta", mask, BUTSTA);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagDet comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptBrt.equals(comp.CptBrt)) items.add(CPTBRT);
			if (CptGrl.equals(comp.CptGrl)) items.add(CPTGRL);
			if (ButSta.equals(comp.ButSta)) items.add(BUTSTA);

			return(items);
		};

		public HashSet<Integer> diff(
					TagDet comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTBRT, CPTGRL, BUTSTA));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagExt (full: TagDlgWdbeRlsStareptrExt)
	  */
	public class TagExt extends Block {

		public static final int CPTPRG = 1;
		public static final int BUTRUN = 2;
		public static final int BUTSTO = 3;

		public TagExt(
					String CptPrg
					, String ButRun
					, String ButSto
				) {
			this.CptPrg = CptPrg;
			this.ButRun = ButRun;
			this.ButSto = ButSto;

			mask = new HashSet<Integer>(Arrays.asList(CPTPRG, BUTRUN, BUTSTO));
		};

		public String CptPrg;
		public String ButRun;
		public String ButSto;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsStareptrExt");

			String itemtag = "TagitemDlgWdbeRlsStareptrExt";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrg", mask, CPTPRG);
				ButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButRun", mask, BUTRUN);
				ButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButSto", mask, BUTSTO);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagExt comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptPrg.equals(comp.CptPrg)) items.add(CPTPRG);
			if (ButRun.equals(comp.ButRun)) items.add(BUTRUN);
			if (ButSto.equals(comp.ButSto)) items.add(BUTSTO);

			return(items);
		};

		public HashSet<Integer> diff(
					TagExt comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTPRG, BUTRUN, BUTSTO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagIni (full: TagDlgWdbeRlsStareptrIni)
	  */
	public class TagIni extends Block {

		public static final int ULD = 1;
		public static final int CPT = 2;
		public static final int CPTPRG = 3;
		public static final int BUTCLG = 4;

		public TagIni(
					String Uld
					, String Cpt
					, String CptPrg
					, String ButClg
				) {
			this.Uld = Uld;
			this.Cpt = Cpt;
			this.CptPrg = CptPrg;
			this.ButClg = ButClg;

			mask = new HashSet<Integer>(Arrays.asList(ULD, CPT, CPTPRG, BUTCLG));
		};

		public String Uld;
		public String Cpt;
		public String CptPrg;
		public String ButClg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsStareptrIni");

			String itemtag = "TagitemDlgWdbeRlsStareptrIni";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Uld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Uld", mask, ULD);
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrg", mask, CPTPRG);
				ButClg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButClg", mask, BUTCLG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagIni comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Uld.equals(comp.Uld)) items.add(ULD);
			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptPrg.equals(comp.CptPrg)) items.add(CPTPRG);
			if (ButClg.equals(comp.ButClg)) items.add(BUTCLG);

			return(items);
		};

		public HashSet<Integer> diff(
					TagIni comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(ULD, CPT, CPTPRG, BUTCLG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagLfi (full: TagDlgWdbeRlsStareptrLfi)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsStareptrLfi");

			String itemtag = "TagitemDlgWdbeRlsStareptrLfi";

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
		* DpchAppData (full: DpchAppDlgWdbeRlsStareptrData)
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
			super(VecWdbeVDpch.DPCHAPPDLGWDBERLSSTAREPTRDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWdbeRlsStareptrData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
			if (has(CONTIACDET)) contiacdet.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeRlsStareptrDo)
		*/
	public class DpchAppDo extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int IXVDODET = 3;
		public static final int IXVDOEXT = 4;
		public static final int IXVDOINI = 5;
		public static final int ALL = 6;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, int ixVDoDet
					, int ixVDoExt
					, int ixVDoIni
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPDLGWDBERLSSTAREPTRDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO, IXVDODET, IXVDOEXT, IXVDOINI));
					break;
				};

			this.ixVDo = ixVDo;
			this.ixVDoDet = ixVDoDet;
			this.ixVDoExt = ixVDoExt;
			this.ixVDoIni = ixVDoIni;
		};

		public int ixVDo;
		public int ixVDoDet;
		public int ixVDoExt;
		public int ixVDoIni;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");
			if (has(IXVDODET)) ss.add("ixVDoDet");
			if (has(IXVDOEXT)) ss.add("ixVDoExt");
			if (has(IXVDOINI)) ss.add("ixVDoIni");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWdbeRlsStareptrDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
			if (has(IXVDODET)) Xmlio.writeString(doc, el, "srefIxVDoDet", VecVDoDet.getSref(ixVDoDet));
			if (has(IXVDOEXT)) Xmlio.writeString(doc, el, "srefIxVDoExt", VecVDoExt.getSref(ixVDoExt));
			if (has(IXVDOINI)) Xmlio.writeString(doc, el, "srefIxVDoIni", VecVDoIni.getSref(ixVDoIni));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeRlsStareptrData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTIACDET = 3;
		public static final int CONTINF = 4;
		public static final int CONTINFEXT = 5;
		public static final int CONTINFINI = 6;
		public static final int CONTINFLFI = 7;
		public static final int FEEDFDETRBUBRT = 8;
		public static final int FEEDFDSE = 9;
		public static final int FEEDFSGE = 10;
		public static final int STATAPP = 11;
		public static final int STATSHR = 12;
		public static final int STATSHRDET = 13;
		public static final int STATSHREXT = 14;
		public static final int STATSHRINI = 15;
		public static final int STATSHRLFI = 16;
		public static final int TAG = 17;
		public static final int TAGDET = 18;
		public static final int TAGEXT = 19;
		public static final int TAGINI = 20;
		public static final int TAGLFI = 21;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGDLGWDBERLSSTAREPTRDATA);

			contiac = new ContIac(0);
			contiacdet = new ContIacDet(0, "");
			continf = new ContInf(0);
			continfext = new ContInfExt("");
			continfini = new ContInfIni("");
			continflfi = new ContInfLfi("");
			feedFDetRbuBrt = new Feed("FeedFDetRbuBrt");
			feedFDse = new Feed("FeedFDse");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(false, "");
			statshr = new StatShr(false);
			statshrdet = new StatShrDet(false, false);
			statshrext = new StatShrExt(false, false);
			statshrini = new StatShrIni(false, false, false, false, false, false);
			statshrlfi = new StatShrLfi(false);
			tag = new Tag("", "");
			tagdet = new TagDet("", "", "");
			tagext = new TagExt("", "", "");
			tagini = new TagIni("", "", "", "");
			taglfi = new TagLfi("");
		};

		public ContIac contiac;
		public ContIacDet contiacdet;
		public ContInf continf;
		public ContInfExt continfext;
		public ContInfIni continfini;
		public ContInfLfi continflfi;
		public Feed feedFDetRbuBrt;
		public Feed feedFDse;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public StatShrDet statshrdet;
		public StatShrExt statshrext;
		public StatShrIni statshrini;
		public StatShrLfi statshrlfi;
		public Tag tag;
		public TagDet tagdet;
		public TagExt tagext;
		public TagIni tagini;
		public TagLfi taglfi;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTIACDET)) ss.add("contiacdet");
			if (has(CONTINF)) ss.add("continf");
			if (has(CONTINFEXT)) ss.add("continfext");
			if (has(CONTINFINI)) ss.add("continfini");
			if (has(CONTINFLFI)) ss.add("continflfi");
			if (has(FEEDFDETRBUBRT)) ss.add("feedFDetRbuBrt");
			if (has(FEEDFDSE)) ss.add("feedFDse");
			if (has(FEEDFSGE)) ss.add("feedFSge");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STATSHRDET)) ss.add("statshrdet");
			if (has(STATSHREXT)) ss.add("statshrext");
			if (has(STATSHRINI)) ss.add("statshrini");
			if (has(STATSHRLFI)) ss.add("statshrlfi");
			if (has(TAG)) ss.add("tag");
			if (has(TAGDET)) ss.add("tagdet");
			if (has(TAGEXT)) ss.add("tagext");
			if (has(TAGINI)) ss.add("tagini");
			if (has(TAGLFI)) ss.add("taglfi");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWdbeRlsStareptrData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (contiacdet.readXML(doc, basexpath, true)) add(CONTIACDET);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (continfext.readXML(doc, basexpath, true)) add(CONTINFEXT);
				if (continfini.readXML(doc, basexpath, true)) add(CONTINFINI);
				if (continflfi.readXML(doc, basexpath, true)) add(CONTINFLFI);
				if (feedFDetRbuBrt.readXML(doc, basexpath, true)) add(FEEDFDETRBUBRT);
				if (feedFDse.readXML(doc, basexpath, true)) add(FEEDFDSE);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (statshrdet.readXML(doc, basexpath, true)) add(STATSHRDET);
				if (statshrext.readXML(doc, basexpath, true)) add(STATSHREXT);
				if (statshrini.readXML(doc, basexpath, true)) add(STATSHRINI);
				if (statshrlfi.readXML(doc, basexpath, true)) add(STATSHRLFI);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (tagdet.readXML(doc, basexpath, true)) add(TAGDET);
				if (tagext.readXML(doc, basexpath, true)) add(TAGEXT);
				if (tagini.readXML(doc, basexpath, true)) add(TAGINI);
				if (taglfi.readXML(doc, basexpath, true)) add(TAGLFI);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				contiacdet = new ContIacDet(0, "");
				continf = new ContInf(0);
				continfext = new ContInfExt("");
				continfini = new ContInfIni("");
				continflfi = new ContInfLfi("");
				feedFDetRbuBrt = new Feed("FeedFDetRbuBrt");
				feedFDse = new Feed("FeedFDse");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(false, "");
				statshr = new StatShr(false);
				statshrdet = new StatShrDet(false, false);
				statshrext = new StatShrExt(false, false);
				statshrini = new StatShrIni(false, false, false, false, false, false);
				statshrlfi = new StatShrLfi(false);
				tag = new Tag("", "");
				tagdet = new TagDet("", "", "");
				tagext = new TagExt("", "", "");
				tagini = new TagIni("", "", "", "");
				taglfi = new TagLfi("");
			};
		};

	};

};

