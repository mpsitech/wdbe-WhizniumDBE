/**
  * \file DlgWdbeRlsFinreptr.java
  * Java API code for job DlgWdbeRlsFinreptr
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWdbeRlsFinreptr {
	/**
		* VecVDit (full: VecVDlgWdbeRlsFinreptrDit)
		*/
	public static class VecVDit {

		public static final int FIN = 1;
		public static final int RES = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("fin")) return FIN;
			if (s.equals("res")) return RES;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == FIN) return("Fin");
			if (ix == RES) return("Res");

			return "";
		};

	};

	/**
		* VecVDo (full: VecVDlgWdbeRlsFinreptrDo)
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
		* VecVDoFin (full: VecVDlgWdbeRlsFinreptrDoFin)
		*/
	public static class VecVDoFin {

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
		* VecVDoRes (full: VecVDlgWdbeRlsFinreptrDoRes)
		*/
	public static class VecVDoRes {

		public static final int BUTPSGCLICK = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butpsgclick")) return BUTPSGCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTPSGCLICK) return("ButPsgClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWdbeRlsFinreptrSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int ALRGNF = 2;
		public static final int ALRGAD = 3;
		public static final int FINIDLE = 4;
		public static final int PACK = 5;
		public static final int COMMIT = 6;
		public static final int FINDONE = 7;
		public static final int PSGIDLE = 8;
		public static final int PUSHGIT = 9;
		public static final int DONE = 10;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("alrgnf")) return ALRGNF;
			if (s.equals("alrgad")) return ALRGAD;
			if (s.equals("finidle")) return FINIDLE;
			if (s.equals("pack")) return PACK;
			if (s.equals("commit")) return COMMIT;
			if (s.equals("findone")) return FINDONE;
			if (s.equals("psgidle")) return PSGIDLE;
			if (s.equals("pushgit")) return PUSHGIT;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == ALRGNF) return("alrgnf");
			if (ix == ALRGAD) return("alrgad");
			if (ix == FINIDLE) return("finidle");
			if (ix == PACK) return("pack");
			if (ix == COMMIT) return("commit");
			if (ix == FINDONE) return("findone");
			if (ix == PSGIDLE) return("psgidle");
			if (ix == PUSHGIT) return("pushgit");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWdbeRlsFinreptr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWdbeRlsFinreptr");

			String itemtag = "ContitemIacDlgWdbeRlsFinreptr";

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWdbeRlsFinreptr";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWdbeRlsFinreptr";

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
	  * ContInf (full: ContInfDlgWdbeRlsFinreptr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeRlsFinreptr");

			String itemtag = "ContitemInfDlgWdbeRlsFinreptr";

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
	  * ContInfFin (full: ContInfDlgWdbeRlsFinreptrFin)
	  */
	public class ContInfFin extends Block {

		public static final int TXTPRG = 1;

		public ContInfFin(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeRlsFinreptrFin");

			String itemtag = "ContitemInfDlgWdbeRlsFinreptrFin";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrg", mask, TXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfFin comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrg.equals(comp.TxtPrg)) items.add(TXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfFin comp
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
	  * ContInfRes (full: ContInfDlgWdbeRlsFinreptrRes)
	  */
	public class ContInfRes extends Block {

		public static final int DLD = 1;
		public static final int TXTPRG = 2;

		public ContInfRes(
					String Dld
					, String TxtPrg
				) {
			this.Dld = Dld;
			this.TxtPrg = TxtPrg;

			mask = new HashSet<Integer>(Arrays.asList(DLD, TXTPRG));
		};

		public String Dld;
		public String TxtPrg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeRlsFinreptrRes");

			String itemtag = "ContitemInfDlgWdbeRlsFinreptrRes";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Dld", mask, DLD);
				TxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrg", mask, TXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfRes comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);
			if (TxtPrg.equals(comp.TxtPrg)) items.add(TXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfRes comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLD, TXTPRG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWdbeRlsFinreptr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWdbeRlsFinreptr");

			String itemtag = "StatitemAppDlgWdbeRlsFinreptr";

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
	  * StatShr (full: StatShrDlgWdbeRlsFinreptr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsFinreptr");

			String itemtag = "StatitemShrDlgWdbeRlsFinreptr";

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
	  * StatShrFin (full: StatShrDlgWdbeRlsFinreptrFin)
	  */
	public class StatShrFin extends Block {

		public static final int BUTRUNACTIVE = 1;
		public static final int BUTSTOACTIVE = 2;

		public StatShrFin(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsFinreptrFin");

			String itemtag = "StatitemShrDlgWdbeRlsFinreptrFin";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRunActive", mask, BUTRUNACTIVE);
				ButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStoActive", mask, BUTSTOACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrFin comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButRunActive == comp.ButRunActive) items.add(BUTRUNACTIVE);
			if (ButStoActive == comp.ButStoActive) items.add(BUTSTOACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrFin comp
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
	  * StatShrRes (full: StatShrDlgWdbeRlsFinreptrRes)
	  */
	public class StatShrRes extends Block {

		public static final int DLDAVAIL = 1;
		public static final int DLDACTIVE = 2;
		public static final int TXTPRGAVAIL = 3;
		public static final int SEP1AVAIL = 4;
		public static final int BUTPSGAVAIL = 5;
		public static final int BUTPSGACTIVE = 6;

		public StatShrRes(
					boolean DldAvail
					, boolean DldActive
					, boolean TxtPrgAvail
					, boolean Sep1Avail
					, boolean ButPsgAvail
					, boolean ButPsgActive
				) {
			this.DldAvail = DldAvail;
			this.DldActive = DldActive;
			this.TxtPrgAvail = TxtPrgAvail;
			this.Sep1Avail = Sep1Avail;
			this.ButPsgAvail = ButPsgAvail;
			this.ButPsgActive = ButPsgActive;

			mask = new HashSet<Integer>(Arrays.asList(DLDAVAIL, DLDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTPSGAVAIL, BUTPSGACTIVE));
		};

		public boolean DldAvail;
		public boolean DldActive;
		public boolean TxtPrgAvail;
		public boolean Sep1Avail;
		public boolean ButPsgAvail;
		public boolean ButPsgActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeRlsFinreptrRes");

			String itemtag = "StatitemShrDlgWdbeRlsFinreptrRes";

			if (Xmlio.checkXPath(doc, basexpath)) {
				DldAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DldAvail", mask, DLDAVAIL);
				DldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DldActive", mask, DLDACTIVE);
				TxtPrgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtPrgAvail", mask, TXTPRGAVAIL);
				Sep1Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Sep1Avail", mask, SEP1AVAIL);
				ButPsgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPsgAvail", mask, BUTPSGAVAIL);
				ButPsgActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPsgActive", mask, BUTPSGACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrRes comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (DldAvail == comp.DldAvail) items.add(DLDAVAIL);
			if (DldActive == comp.DldActive) items.add(DLDACTIVE);
			if (TxtPrgAvail == comp.TxtPrgAvail) items.add(TXTPRGAVAIL);
			if (Sep1Avail == comp.Sep1Avail) items.add(SEP1AVAIL);
			if (ButPsgAvail == comp.ButPsgAvail) items.add(BUTPSGAVAIL);
			if (ButPsgActive == comp.ButPsgActive) items.add(BUTPSGACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrRes comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLDAVAIL, DLDACTIVE, TXTPRGAVAIL, SEP1AVAIL, BUTPSGAVAIL, BUTPSGACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWdbeRlsFinreptr)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsFinreptr");

			String itemtag = "TagitemDlgWdbeRlsFinreptr";

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
	  * TagFin (full: TagDlgWdbeRlsFinreptrFin)
	  */
	public class TagFin extends Block {

		public static final int CPTPRG = 1;
		public static final int BUTRUN = 2;
		public static final int BUTSTO = 3;

		public TagFin(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsFinreptrFin");

			String itemtag = "TagitemDlgWdbeRlsFinreptrFin";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrg", mask, CPTPRG);
				ButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButRun", mask, BUTRUN);
				ButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButSto", mask, BUTSTO);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagFin comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptPrg.equals(comp.CptPrg)) items.add(CPTPRG);
			if (ButRun.equals(comp.ButRun)) items.add(BUTRUN);
			if (ButSto.equals(comp.ButSto)) items.add(BUTSTO);

			return(items);
		};

		public HashSet<Integer> diff(
					TagFin comp
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
	  * TagRes (full: TagDlgWdbeRlsFinreptrRes)
	  */
	public class TagRes extends Block {

		public static final int DLD = 1;
		public static final int CPTPRG = 2;
		public static final int BUTPSG = 3;

		public TagRes(
					String Dld
					, String CptPrg
					, String ButPsg
				) {
			this.Dld = Dld;
			this.CptPrg = CptPrg;
			this.ButPsg = ButPsg;

			mask = new HashSet<Integer>(Arrays.asList(DLD, CPTPRG, BUTPSG));
		};

		public String Dld;
		public String CptPrg;
		public String ButPsg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeRlsFinreptrRes");

			String itemtag = "TagitemDlgWdbeRlsFinreptrRes";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Dld", mask, DLD);
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrg", mask, CPTPRG);
				ButPsg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButPsg", mask, BUTPSG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagRes comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);
			if (CptPrg.equals(comp.CptPrg)) items.add(CPTPRG);
			if (ButPsg.equals(comp.ButPsg)) items.add(BUTPSG);

			return(items);
		};

		public HashSet<Integer> diff(
					TagRes comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLD, CPTPRG, BUTPSG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeRlsFinreptrData)
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
			super(VecWdbeVDpch.DPCHAPPDLGWDBERLSFINREPTRDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWdbeRlsFinreptrData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeRlsFinreptrDo)
		*/
	public class DpchAppDo extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int IXVDOFIN = 3;
		public static final int IXVDORES = 4;
		public static final int ALL = 5;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, int ixVDoFin
					, int ixVDoRes
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPDLGWDBERLSFINREPTRDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO, IXVDOFIN, IXVDORES));
					break;
				};

			this.ixVDo = ixVDo;
			this.ixVDoFin = ixVDoFin;
			this.ixVDoRes = ixVDoRes;
		};

		public int ixVDo;
		public int ixVDoFin;
		public int ixVDoRes;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");
			if (has(IXVDOFIN)) ss.add("ixVDoFin");
			if (has(IXVDORES)) ss.add("ixVDoRes");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWdbeRlsFinreptrDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
			if (has(IXVDOFIN)) Xmlio.writeString(doc, el, "srefIxVDoFin", VecVDoFin.getSref(ixVDoFin));
			if (has(IXVDORES)) Xmlio.writeString(doc, el, "srefIxVDoRes", VecVDoRes.getSref(ixVDoRes));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeRlsFinreptrData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int CONTINFFIN = 4;
		public static final int CONTINFRES = 5;
		public static final int FEEDFDSE = 6;
		public static final int FEEDFSGE = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int STATSHRFIN = 10;
		public static final int STATSHRRES = 11;
		public static final int TAG = 12;
		public static final int TAGFIN = 13;
		public static final int TAGRES = 14;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGDLGWDBERLSFINREPTRDATA);

			contiac = new ContIac(0);
			continf = new ContInf(0);
			continffin = new ContInfFin("");
			continfres = new ContInfRes("", "");
			feedFDse = new Feed("FeedFDse");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(false, "");
			statshr = new StatShr(false);
			statshrfin = new StatShrFin(false, false);
			statshrres = new StatShrRes(false, false, false, false, false, false);
			tag = new Tag("", "");
			tagfin = new TagFin("", "", "");
			tagres = new TagRes("", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public ContInfFin continffin;
		public ContInfRes continfres;
		public Feed feedFDse;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public StatShrFin statshrfin;
		public StatShrRes statshrres;
		public Tag tag;
		public TagFin tagfin;
		public TagRes tagres;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(CONTINFFIN)) ss.add("continffin");
			if (has(CONTINFRES)) ss.add("continfres");
			if (has(FEEDFDSE)) ss.add("feedFDse");
			if (has(FEEDFSGE)) ss.add("feedFSge");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STATSHRFIN)) ss.add("statshrfin");
			if (has(STATSHRRES)) ss.add("statshrres");
			if (has(TAG)) ss.add("tag");
			if (has(TAGFIN)) ss.add("tagfin");
			if (has(TAGRES)) ss.add("tagres");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWdbeRlsFinreptrData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (continffin.readXML(doc, basexpath, true)) add(CONTINFFIN);
				if (continfres.readXML(doc, basexpath, true)) add(CONTINFRES);
				if (feedFDse.readXML(doc, basexpath, true)) add(FEEDFDSE);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (statshrfin.readXML(doc, basexpath, true)) add(STATSHRFIN);
				if (statshrres.readXML(doc, basexpath, true)) add(STATSHRRES);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (tagfin.readXML(doc, basexpath, true)) add(TAGFIN);
				if (tagres.readXML(doc, basexpath, true)) add(TAGRES);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				continf = new ContInf(0);
				continffin = new ContInfFin("");
				continfres = new ContInfRes("", "");
				feedFDse = new Feed("FeedFDse");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(false, "");
				statshr = new StatShr(false);
				statshrfin = new StatShrFin(false, false);
				statshrres = new StatShrRes(false, false, false, false, false, false);
				tag = new Tag("", "");
				tagfin = new TagFin("", "", "");
				tagres = new TagRes("", "", "");
			};
		};

	};

};

