/**
  * \file PnlWdbePrfDaemon.java
  * Java API code for job PnlWdbePrfDaemon
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 8 Jan 2025
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbePrfDaemon {
	/**
		* VecVDo (full: VecVWdbePrfDaemonDo)
		*/
	public static class VecVDo {

		public static final int BUTREGULARIZECLICK = 1;
		public static final int BUTMINIMIZECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;
			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbePrfDaemon)
	  */
	public class ContIac extends Block {

		public static final int TXF2 = 1;
		public static final int CHK3 = 2;
		public static final int TXF4 = 3;
		public static final int TXF5 = 4;
		public static final int TXF6 = 5;
		public static final int TXF102 = 6;
		public static final int CHK103 = 7;
		public static final int TXF104 = 8;
		public static final int TXF202 = 9;
		public static final int TXF203 = 10;
		public static final int CHK204 = 11;
		public static final int TXF302 = 12;
		public static final int TXF303 = 13;
		public static final int CHK304 = 14;
		public static final int NUMFPUP402 = 15;
		public static final int TXF403 = 16;
		public static final int TXF404 = 17;
		public static final int TXF405 = 18;
		public static final int TXF406 = 19;
		public static final int TXF407 = 20;
		public static final int TXF408 = 21;
		public static final int TXF502 = 22;
		public static final int TXF503 = 23;
		public static final int TXF504 = 24;
		public static final int TXF505 = 25;
		public static final int TXF506 = 26;
		public static final int TXF507 = 27;
		public static final int TXF602 = 28;
		public static final int TXF603 = 29;
		public static final int TXF702 = 30;
		public static final int TXF703 = 31;
		public static final int TXF704 = 32;
		public static final int TXF705 = 33;
		public static final int NUMFPUP706 = 34;
		public static final int TXF707 = 35;
		public static final int TXF708 = 36;
		public static final int TXF709 = 37;
		public static final int TXF710 = 38;

		public ContIac(
					String Txf2
					, boolean Chk3
					, String Txf4
					, String Txf5
					, String Txf6
					, String Txf102
					, boolean Chk103
					, String Txf104
					, String Txf202
					, String Txf203
					, boolean Chk204
					, String Txf302
					, String Txf303
					, boolean Chk304
					, int numFPup402
					, String Txf403
					, String Txf404
					, String Txf405
					, String Txf406
					, String Txf407
					, String Txf408
					, String Txf502
					, String Txf503
					, String Txf504
					, String Txf505
					, String Txf506
					, String Txf507
					, String Txf602
					, String Txf603
					, String Txf702
					, String Txf703
					, String Txf704
					, String Txf705
					, int numFPup706
					, String Txf707
					, String Txf708
					, String Txf709
					, String Txf710
				) {
			this.Txf2 = Txf2;
			this.Chk3 = Chk3;
			this.Txf4 = Txf4;
			this.Txf5 = Txf5;
			this.Txf6 = Txf6;
			this.Txf102 = Txf102;
			this.Chk103 = Chk103;
			this.Txf104 = Txf104;
			this.Txf202 = Txf202;
			this.Txf203 = Txf203;
			this.Chk204 = Chk204;
			this.Txf302 = Txf302;
			this.Txf303 = Txf303;
			this.Chk304 = Chk304;
			this.numFPup402 = numFPup402;
			this.Txf403 = Txf403;
			this.Txf404 = Txf404;
			this.Txf405 = Txf405;
			this.Txf406 = Txf406;
			this.Txf407 = Txf407;
			this.Txf408 = Txf408;
			this.Txf502 = Txf502;
			this.Txf503 = Txf503;
			this.Txf504 = Txf504;
			this.Txf505 = Txf505;
			this.Txf506 = Txf506;
			this.Txf507 = Txf507;
			this.Txf602 = Txf602;
			this.Txf603 = Txf603;
			this.Txf702 = Txf702;
			this.Txf703 = Txf703;
			this.Txf704 = Txf704;
			this.Txf705 = Txf705;
			this.numFPup706 = numFPup706;
			this.Txf707 = Txf707;
			this.Txf708 = Txf708;
			this.Txf709 = Txf709;
			this.Txf710 = Txf710;

			mask = new HashSet<Integer>(Arrays.asList(TXF2, CHK3, TXF4, TXF5, TXF6, TXF102, CHK103, TXF104, TXF202, TXF203, CHK204, TXF302, TXF303, CHK304, NUMFPUP402, TXF403, TXF404, TXF405, TXF406, TXF407, TXF408, TXF502, TXF503, TXF504, TXF505, TXF506, TXF507, TXF602, TXF603, TXF702, TXF703, TXF704, TXF705, NUMFPUP706, TXF707, TXF708, TXF709, TXF710));
		};

		public String Txf2;
		public boolean Chk3;
		public String Txf4;
		public String Txf5;
		public String Txf6;
		public String Txf102;
		public boolean Chk103;
		public String Txf104;
		public String Txf202;
		public String Txf203;
		public boolean Chk204;
		public String Txf302;
		public String Txf303;
		public boolean Chk304;
		public int numFPup402;
		public String Txf403;
		public String Txf404;
		public String Txf405;
		public String Txf406;
		public String Txf407;
		public String Txf408;
		public String Txf502;
		public String Txf503;
		public String Txf504;
		public String Txf505;
		public String Txf506;
		public String Txf507;
		public String Txf602;
		public String Txf603;
		public String Txf702;
		public String Txf703;
		public String Txf704;
		public String Txf705;
		public int numFPup706;
		public String Txf707;
		public String Txf708;
		public String Txf709;
		public String Txf710;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbePrfDaemon");

			String itemtag = "ContitemIacWdbePrfDaemon";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Txf2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf2", mask, TXF2);
				Chk3 = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Chk3", mask, CHK3);
				Txf4 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf4", mask, TXF4);
				Txf5 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf5", mask, TXF5);
				Txf6 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf6", mask, TXF6);
				Txf102 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf102", mask, TXF102);
				Chk103 = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Chk103", mask, CHK103);
				Txf104 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf104", mask, TXF104);
				Txf202 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf202", mask, TXF202);
				Txf203 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf203", mask, TXF203);
				Chk204 = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Chk204", mask, CHK204);
				Txf302 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf302", mask, TXF302);
				Txf303 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf303", mask, TXF303);
				Chk304 = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Chk304", mask, CHK304);
				numFPup402 = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPup402", mask, NUMFPUP402);
				Txf403 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf403", mask, TXF403);
				Txf404 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf404", mask, TXF404);
				Txf405 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf405", mask, TXF405);
				Txf406 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf406", mask, TXF406);
				Txf407 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf407", mask, TXF407);
				Txf408 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf408", mask, TXF408);
				Txf502 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf502", mask, TXF502);
				Txf503 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf503", mask, TXF503);
				Txf504 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf504", mask, TXF504);
				Txf505 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf505", mask, TXF505);
				Txf506 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf506", mask, TXF506);
				Txf507 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf507", mask, TXF507);
				Txf602 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf602", mask, TXF602);
				Txf603 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf603", mask, TXF603);
				Txf702 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf702", mask, TXF702);
				Txf703 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf703", mask, TXF703);
				Txf704 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf704", mask, TXF704);
				Txf705 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf705", mask, TXF705);
				numFPup706 = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPup706", mask, NUMFPUP706);
				Txf707 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf707", mask, TXF707);
				Txf708 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf708", mask, TXF708);
				Txf709 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf709", mask, TXF709);
				Txf710 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Txf710", mask, TXF710);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbePrfDaemon";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbePrfDaemon";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf2", Txf2);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "Chk3", Chk3);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf4", Txf4);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf5", Txf5);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf6", Txf6);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf102", Txf102);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "Chk103", Chk103);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf104", Txf104);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf202", Txf202);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf203", Txf203);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "Chk204", Chk204);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf302", Txf302);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf303", Txf303);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "Chk304", Chk304);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPup402", numFPup402);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf403", Txf403);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf404", Txf404);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf405", Txf405);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf406", Txf406);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf407", Txf407);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf408", Txf408);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf502", Txf502);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf503", Txf503);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf504", Txf504);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf505", Txf505);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf506", Txf506);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf507", Txf507);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf602", Txf602);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf603", Txf603);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf702", Txf702);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf703", Txf703);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf704", Txf704);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf705", Txf705);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPup706", numFPup706);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf707", Txf707);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf708", Txf708);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf709", Txf709);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "Txf710", Txf710);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Txf2.equals(comp.Txf2)) items.add(TXF2);
			if (Chk3 == comp.Chk3) items.add(CHK3);
			if (Txf4.equals(comp.Txf4)) items.add(TXF4);
			if (Txf5.equals(comp.Txf5)) items.add(TXF5);
			if (Txf6.equals(comp.Txf6)) items.add(TXF6);
			if (Txf102.equals(comp.Txf102)) items.add(TXF102);
			if (Chk103 == comp.Chk103) items.add(CHK103);
			if (Txf104.equals(comp.Txf104)) items.add(TXF104);
			if (Txf202.equals(comp.Txf202)) items.add(TXF202);
			if (Txf203.equals(comp.Txf203)) items.add(TXF203);
			if (Chk204 == comp.Chk204) items.add(CHK204);
			if (Txf302.equals(comp.Txf302)) items.add(TXF302);
			if (Txf303.equals(comp.Txf303)) items.add(TXF303);
			if (Chk304 == comp.Chk304) items.add(CHK304);
			if (numFPup402 == comp.numFPup402) items.add(NUMFPUP402);
			if (Txf403.equals(comp.Txf403)) items.add(TXF403);
			if (Txf404.equals(comp.Txf404)) items.add(TXF404);
			if (Txf405.equals(comp.Txf405)) items.add(TXF405);
			if (Txf406.equals(comp.Txf406)) items.add(TXF406);
			if (Txf407.equals(comp.Txf407)) items.add(TXF407);
			if (Txf408.equals(comp.Txf408)) items.add(TXF408);
			if (Txf502.equals(comp.Txf502)) items.add(TXF502);
			if (Txf503.equals(comp.Txf503)) items.add(TXF503);
			if (Txf504.equals(comp.Txf504)) items.add(TXF504);
			if (Txf505.equals(comp.Txf505)) items.add(TXF505);
			if (Txf506.equals(comp.Txf506)) items.add(TXF506);
			if (Txf507.equals(comp.Txf507)) items.add(TXF507);
			if (Txf602.equals(comp.Txf602)) items.add(TXF602);
			if (Txf603.equals(comp.Txf603)) items.add(TXF603);
			if (Txf702.equals(comp.Txf702)) items.add(TXF702);
			if (Txf703.equals(comp.Txf703)) items.add(TXF703);
			if (Txf704.equals(comp.Txf704)) items.add(TXF704);
			if (Txf705.equals(comp.Txf705)) items.add(TXF705);
			if (numFPup706 == comp.numFPup706) items.add(NUMFPUP706);
			if (Txf707.equals(comp.Txf707)) items.add(TXF707);
			if (Txf708.equals(comp.Txf708)) items.add(TXF708);
			if (Txf709.equals(comp.Txf709)) items.add(TXF709);
			if (Txf710.equals(comp.Txf710)) items.add(TXF710);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXF2, CHK3, TXF4, TXF5, TXF6, TXF102, CHK103, TXF104, TXF202, TXF203, CHK204, TXF302, TXF303, CHK304, NUMFPUP402, TXF403, TXF404, TXF405, TXF406, TXF407, TXF408, TXF502, TXF503, TXF504, TXF505, TXF506, TXF507, TXF602, TXF603, TXF702, TXF703, TXF704, TXF705, NUMFPUP706, TXF707, TXF708, TXF709, TXF710));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbePrfDaemon)
	  */
	public class StatShr extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int TXF2CLEAN = 2;
		public static final int CHK3CLEAN = 3;
		public static final int TXF4CLEAN = 4;
		public static final int TXF5CLEAN = 5;
		public static final int TXF6CLEAN = 6;
		public static final int TXF102CLEAN = 7;
		public static final int CHK103CLEAN = 8;
		public static final int TXF104CLEAN = 9;
		public static final int SEP2AVAIL = 10;
		public static final int HDG201AVAIL = 11;
		public static final int TXF202AVAIL = 12;
		public static final int TXF202CLEAN = 13;
		public static final int TXF203AVAIL = 14;
		public static final int TXF203CLEAN = 15;
		public static final int CHK204AVAIL = 16;
		public static final int CHK204CLEAN = 17;
		public static final int SEP3AVAIL = 18;
		public static final int HDG301AVAIL = 19;
		public static final int TXF302AVAIL = 20;
		public static final int TXF302CLEAN = 21;
		public static final int TXF303AVAIL = 22;
		public static final int TXF303CLEAN = 23;
		public static final int CHK304AVAIL = 24;
		public static final int CHK304CLEAN = 25;
		public static final int PUP402CLEAN = 26;
		public static final int TXF403CLEAN = 27;
		public static final int TXF404CLEAN = 28;
		public static final int TXF405CLEAN = 29;
		public static final int TXF406CLEAN = 30;
		public static final int TXF407CLEAN = 31;
		public static final int TXF408CLEAN = 32;
		public static final int TXF502CLEAN = 33;
		public static final int TXF503CLEAN = 34;
		public static final int TXF504CLEAN = 35;
		public static final int TXF505CLEAN = 36;
		public static final int TXF506CLEAN = 37;
		public static final int TXF507CLEAN = 38;
		public static final int TXF602CLEAN = 39;
		public static final int TXF603CLEAN = 40;
		public static final int TXF702CLEAN = 41;
		public static final int TXF703CLEAN = 42;
		public static final int TXF704CLEAN = 43;
		public static final int TXF705CLEAN = 44;
		public static final int PUP706CLEAN = 45;
		public static final int TXF707CLEAN = 46;
		public static final int TXF708CLEAN = 47;
		public static final int TXF709CLEAN = 48;
		public static final int TXF710CLEAN = 49;

		public StatShr(
					int ixWdbeVExpstate
					, boolean Txf2Clean
					, boolean Chk3Clean
					, boolean Txf4Clean
					, boolean Txf5Clean
					, boolean Txf6Clean
					, boolean Txf102Clean
					, boolean Chk103Clean
					, boolean Txf104Clean
					, boolean Sep2Avail
					, boolean Hdg201Avail
					, boolean Txf202Avail
					, boolean Txf202Clean
					, boolean Txf203Avail
					, boolean Txf203Clean
					, boolean Chk204Avail
					, boolean Chk204Clean
					, boolean Sep3Avail
					, boolean Hdg301Avail
					, boolean Txf302Avail
					, boolean Txf302Clean
					, boolean Txf303Avail
					, boolean Txf303Clean
					, boolean Chk304Avail
					, boolean Chk304Clean
					, boolean Pup402Clean
					, boolean Txf403Clean
					, boolean Txf404Clean
					, boolean Txf405Clean
					, boolean Txf406Clean
					, boolean Txf407Clean
					, boolean Txf408Clean
					, boolean Txf502Clean
					, boolean Txf503Clean
					, boolean Txf504Clean
					, boolean Txf505Clean
					, boolean Txf506Clean
					, boolean Txf507Clean
					, boolean Txf602Clean
					, boolean Txf603Clean
					, boolean Txf702Clean
					, boolean Txf703Clean
					, boolean Txf704Clean
					, boolean Txf705Clean
					, boolean Pup706Clean
					, boolean Txf707Clean
					, boolean Txf708Clean
					, boolean Txf709Clean
					, boolean Txf710Clean
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.Txf2Clean = Txf2Clean;
			this.Chk3Clean = Chk3Clean;
			this.Txf4Clean = Txf4Clean;
			this.Txf5Clean = Txf5Clean;
			this.Txf6Clean = Txf6Clean;
			this.Txf102Clean = Txf102Clean;
			this.Chk103Clean = Chk103Clean;
			this.Txf104Clean = Txf104Clean;
			this.Sep2Avail = Sep2Avail;
			this.Hdg201Avail = Hdg201Avail;
			this.Txf202Avail = Txf202Avail;
			this.Txf202Clean = Txf202Clean;
			this.Txf203Avail = Txf203Avail;
			this.Txf203Clean = Txf203Clean;
			this.Chk204Avail = Chk204Avail;
			this.Chk204Clean = Chk204Clean;
			this.Sep3Avail = Sep3Avail;
			this.Hdg301Avail = Hdg301Avail;
			this.Txf302Avail = Txf302Avail;
			this.Txf302Clean = Txf302Clean;
			this.Txf303Avail = Txf303Avail;
			this.Txf303Clean = Txf303Clean;
			this.Chk304Avail = Chk304Avail;
			this.Chk304Clean = Chk304Clean;
			this.Pup402Clean = Pup402Clean;
			this.Txf403Clean = Txf403Clean;
			this.Txf404Clean = Txf404Clean;
			this.Txf405Clean = Txf405Clean;
			this.Txf406Clean = Txf406Clean;
			this.Txf407Clean = Txf407Clean;
			this.Txf408Clean = Txf408Clean;
			this.Txf502Clean = Txf502Clean;
			this.Txf503Clean = Txf503Clean;
			this.Txf504Clean = Txf504Clean;
			this.Txf505Clean = Txf505Clean;
			this.Txf506Clean = Txf506Clean;
			this.Txf507Clean = Txf507Clean;
			this.Txf602Clean = Txf602Clean;
			this.Txf603Clean = Txf603Clean;
			this.Txf702Clean = Txf702Clean;
			this.Txf703Clean = Txf703Clean;
			this.Txf704Clean = Txf704Clean;
			this.Txf705Clean = Txf705Clean;
			this.Pup706Clean = Pup706Clean;
			this.Txf707Clean = Txf707Clean;
			this.Txf708Clean = Txf708Clean;
			this.Txf709Clean = Txf709Clean;
			this.Txf710Clean = Txf710Clean;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, TXF2CLEAN, CHK3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, TXF102CLEAN, CHK103CLEAN, TXF104CLEAN, SEP2AVAIL, HDG201AVAIL, TXF202AVAIL, TXF202CLEAN, TXF203AVAIL, TXF203CLEAN, CHK204AVAIL, CHK204CLEAN, SEP3AVAIL, HDG301AVAIL, TXF302AVAIL, TXF302CLEAN, TXF303AVAIL, TXF303CLEAN, CHK304AVAIL, CHK304CLEAN, PUP402CLEAN, TXF403CLEAN, TXF404CLEAN, TXF405CLEAN, TXF406CLEAN, TXF407CLEAN, TXF408CLEAN, TXF502CLEAN, TXF503CLEAN, TXF504CLEAN, TXF505CLEAN, TXF506CLEAN, TXF507CLEAN, TXF602CLEAN, TXF603CLEAN, TXF702CLEAN, TXF703CLEAN, TXF704CLEAN, TXF705CLEAN, PUP706CLEAN, TXF707CLEAN, TXF708CLEAN, TXF709CLEAN, TXF710CLEAN));
		};

		public int ixWdbeVExpstate;
		public boolean Txf2Clean;
		public boolean Chk3Clean;
		public boolean Txf4Clean;
		public boolean Txf5Clean;
		public boolean Txf6Clean;
		public boolean Txf102Clean;
		public boolean Chk103Clean;
		public boolean Txf104Clean;
		public boolean Sep2Avail;
		public boolean Hdg201Avail;
		public boolean Txf202Avail;
		public boolean Txf202Clean;
		public boolean Txf203Avail;
		public boolean Txf203Clean;
		public boolean Chk204Avail;
		public boolean Chk204Clean;
		public boolean Sep3Avail;
		public boolean Hdg301Avail;
		public boolean Txf302Avail;
		public boolean Txf302Clean;
		public boolean Txf303Avail;
		public boolean Txf303Clean;
		public boolean Chk304Avail;
		public boolean Chk304Clean;
		public boolean Pup402Clean;
		public boolean Txf403Clean;
		public boolean Txf404Clean;
		public boolean Txf405Clean;
		public boolean Txf406Clean;
		public boolean Txf407Clean;
		public boolean Txf408Clean;
		public boolean Txf502Clean;
		public boolean Txf503Clean;
		public boolean Txf504Clean;
		public boolean Txf505Clean;
		public boolean Txf506Clean;
		public boolean Txf507Clean;
		public boolean Txf602Clean;
		public boolean Txf603Clean;
		public boolean Txf702Clean;
		public boolean Txf703Clean;
		public boolean Txf704Clean;
		public boolean Txf705Clean;
		public boolean Pup706Clean;
		public boolean Txf707Clean;
		public boolean Txf708Clean;
		public boolean Txf709Clean;
		public boolean Txf710Clean;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbePrfDaemon");

			String itemtag = "StatitemShrWdbePrfDaemon";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				Txf2Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf2Clean", mask, TXF2CLEAN);
				Chk3Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Chk3Clean", mask, CHK3CLEAN);
				Txf4Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf4Clean", mask, TXF4CLEAN);
				Txf5Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf5Clean", mask, TXF5CLEAN);
				Txf6Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf6Clean", mask, TXF6CLEAN);
				Txf102Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf102Clean", mask, TXF102CLEAN);
				Chk103Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Chk103Clean", mask, CHK103CLEAN);
				Txf104Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf104Clean", mask, TXF104CLEAN);
				Sep2Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Sep2Avail", mask, SEP2AVAIL);
				Hdg201Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Hdg201Avail", mask, HDG201AVAIL);
				Txf202Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf202Avail", mask, TXF202AVAIL);
				Txf202Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf202Clean", mask, TXF202CLEAN);
				Txf203Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf203Avail", mask, TXF203AVAIL);
				Txf203Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf203Clean", mask, TXF203CLEAN);
				Chk204Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Chk204Avail", mask, CHK204AVAIL);
				Chk204Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Chk204Clean", mask, CHK204CLEAN);
				Sep3Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Sep3Avail", mask, SEP3AVAIL);
				Hdg301Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Hdg301Avail", mask, HDG301AVAIL);
				Txf302Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf302Avail", mask, TXF302AVAIL);
				Txf302Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf302Clean", mask, TXF302CLEAN);
				Txf303Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf303Avail", mask, TXF303AVAIL);
				Txf303Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf303Clean", mask, TXF303CLEAN);
				Chk304Avail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Chk304Avail", mask, CHK304AVAIL);
				Chk304Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Chk304Clean", mask, CHK304CLEAN);
				Pup402Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Pup402Clean", mask, PUP402CLEAN);
				Txf403Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf403Clean", mask, TXF403CLEAN);
				Txf404Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf404Clean", mask, TXF404CLEAN);
				Txf405Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf405Clean", mask, TXF405CLEAN);
				Txf406Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf406Clean", mask, TXF406CLEAN);
				Txf407Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf407Clean", mask, TXF407CLEAN);
				Txf408Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf408Clean", mask, TXF408CLEAN);
				Txf502Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf502Clean", mask, TXF502CLEAN);
				Txf503Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf503Clean", mask, TXF503CLEAN);
				Txf504Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf504Clean", mask, TXF504CLEAN);
				Txf505Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf505Clean", mask, TXF505CLEAN);
				Txf506Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf506Clean", mask, TXF506CLEAN);
				Txf507Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf507Clean", mask, TXF507CLEAN);
				Txf602Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf602Clean", mask, TXF602CLEAN);
				Txf603Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf603Clean", mask, TXF603CLEAN);
				Txf702Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf702Clean", mask, TXF702CLEAN);
				Txf703Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf703Clean", mask, TXF703CLEAN);
				Txf704Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf704Clean", mask, TXF704CLEAN);
				Txf705Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf705Clean", mask, TXF705CLEAN);
				Pup706Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Pup706Clean", mask, PUP706CLEAN);
				Txf707Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf707Clean", mask, TXF707CLEAN);
				Txf708Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf708Clean", mask, TXF708CLEAN);
				Txf709Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf709Clean", mask, TXF709CLEAN);
				Txf710Clean = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "Txf710Clean", mask, TXF710CLEAN);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (Txf2Clean == comp.Txf2Clean) items.add(TXF2CLEAN);
			if (Chk3Clean == comp.Chk3Clean) items.add(CHK3CLEAN);
			if (Txf4Clean == comp.Txf4Clean) items.add(TXF4CLEAN);
			if (Txf5Clean == comp.Txf5Clean) items.add(TXF5CLEAN);
			if (Txf6Clean == comp.Txf6Clean) items.add(TXF6CLEAN);
			if (Txf102Clean == comp.Txf102Clean) items.add(TXF102CLEAN);
			if (Chk103Clean == comp.Chk103Clean) items.add(CHK103CLEAN);
			if (Txf104Clean == comp.Txf104Clean) items.add(TXF104CLEAN);
			if (Sep2Avail == comp.Sep2Avail) items.add(SEP2AVAIL);
			if (Hdg201Avail == comp.Hdg201Avail) items.add(HDG201AVAIL);
			if (Txf202Avail == comp.Txf202Avail) items.add(TXF202AVAIL);
			if (Txf202Clean == comp.Txf202Clean) items.add(TXF202CLEAN);
			if (Txf203Avail == comp.Txf203Avail) items.add(TXF203AVAIL);
			if (Txf203Clean == comp.Txf203Clean) items.add(TXF203CLEAN);
			if (Chk204Avail == comp.Chk204Avail) items.add(CHK204AVAIL);
			if (Chk204Clean == comp.Chk204Clean) items.add(CHK204CLEAN);
			if (Sep3Avail == comp.Sep3Avail) items.add(SEP3AVAIL);
			if (Hdg301Avail == comp.Hdg301Avail) items.add(HDG301AVAIL);
			if (Txf302Avail == comp.Txf302Avail) items.add(TXF302AVAIL);
			if (Txf302Clean == comp.Txf302Clean) items.add(TXF302CLEAN);
			if (Txf303Avail == comp.Txf303Avail) items.add(TXF303AVAIL);
			if (Txf303Clean == comp.Txf303Clean) items.add(TXF303CLEAN);
			if (Chk304Avail == comp.Chk304Avail) items.add(CHK304AVAIL);
			if (Chk304Clean == comp.Chk304Clean) items.add(CHK304CLEAN);
			if (Pup402Clean == comp.Pup402Clean) items.add(PUP402CLEAN);
			if (Txf403Clean == comp.Txf403Clean) items.add(TXF403CLEAN);
			if (Txf404Clean == comp.Txf404Clean) items.add(TXF404CLEAN);
			if (Txf405Clean == comp.Txf405Clean) items.add(TXF405CLEAN);
			if (Txf406Clean == comp.Txf406Clean) items.add(TXF406CLEAN);
			if (Txf407Clean == comp.Txf407Clean) items.add(TXF407CLEAN);
			if (Txf408Clean == comp.Txf408Clean) items.add(TXF408CLEAN);
			if (Txf502Clean == comp.Txf502Clean) items.add(TXF502CLEAN);
			if (Txf503Clean == comp.Txf503Clean) items.add(TXF503CLEAN);
			if (Txf504Clean == comp.Txf504Clean) items.add(TXF504CLEAN);
			if (Txf505Clean == comp.Txf505Clean) items.add(TXF505CLEAN);
			if (Txf506Clean == comp.Txf506Clean) items.add(TXF506CLEAN);
			if (Txf507Clean == comp.Txf507Clean) items.add(TXF507CLEAN);
			if (Txf602Clean == comp.Txf602Clean) items.add(TXF602CLEAN);
			if (Txf603Clean == comp.Txf603Clean) items.add(TXF603CLEAN);
			if (Txf702Clean == comp.Txf702Clean) items.add(TXF702CLEAN);
			if (Txf703Clean == comp.Txf703Clean) items.add(TXF703CLEAN);
			if (Txf704Clean == comp.Txf704Clean) items.add(TXF704CLEAN);
			if (Txf705Clean == comp.Txf705Clean) items.add(TXF705CLEAN);
			if (Pup706Clean == comp.Pup706Clean) items.add(PUP706CLEAN);
			if (Txf707Clean == comp.Txf707Clean) items.add(TXF707CLEAN);
			if (Txf708Clean == comp.Txf708Clean) items.add(TXF708CLEAN);
			if (Txf709Clean == comp.Txf709Clean) items.add(TXF709CLEAN);
			if (Txf710Clean == comp.Txf710Clean) items.add(TXF710CLEAN);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, TXF2CLEAN, CHK3CLEAN, TXF4CLEAN, TXF5CLEAN, TXF6CLEAN, TXF102CLEAN, CHK103CLEAN, TXF104CLEAN, SEP2AVAIL, HDG201AVAIL, TXF202AVAIL, TXF202CLEAN, TXF203AVAIL, TXF203CLEAN, CHK204AVAIL, CHK204CLEAN, SEP3AVAIL, HDG301AVAIL, TXF302AVAIL, TXF302CLEAN, TXF303AVAIL, TXF303CLEAN, CHK304AVAIL, CHK304CLEAN, PUP402CLEAN, TXF403CLEAN, TXF404CLEAN, TXF405CLEAN, TXF406CLEAN, TXF407CLEAN, TXF408CLEAN, TXF502CLEAN, TXF503CLEAN, TXF504CLEAN, TXF505CLEAN, TXF506CLEAN, TXF507CLEAN, TXF602CLEAN, TXF603CLEAN, TXF702CLEAN, TXF703CLEAN, TXF704CLEAN, TXF705CLEAN, PUP706CLEAN, TXF707CLEAN, TXF708CLEAN, TXF709CLEAN, TXF710CLEAN));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbePrfDaemon)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int HDG1 = 2;
		public static final int CPT2 = 3;
		public static final int CPT3 = 4;
		public static final int CPT4 = 5;
		public static final int CPT5 = 6;
		public static final int CPT6 = 7;
		public static final int HDG101 = 8;
		public static final int CPT102 = 9;
		public static final int CPT103 = 10;
		public static final int CPT104 = 11;
		public static final int HDG201 = 12;
		public static final int CPT202 = 13;
		public static final int CPT203 = 14;
		public static final int CPT204 = 15;
		public static final int HDG301 = 16;
		public static final int CPT302 = 17;
		public static final int CPT303 = 18;
		public static final int CPT304 = 19;
		public static final int HDG401 = 20;
		public static final int CPT402 = 21;
		public static final int CPT403 = 22;
		public static final int CPT404 = 23;
		public static final int CPT405 = 24;
		public static final int CPT406 = 25;
		public static final int CPT407 = 26;
		public static final int CPT408 = 27;
		public static final int HDG501 = 28;
		public static final int CPT502 = 29;
		public static final int CPT503 = 30;
		public static final int CPT504 = 31;
		public static final int CPT505 = 32;
		public static final int CPT506 = 33;
		public static final int CPT507 = 34;
		public static final int HDG601 = 35;
		public static final int CPT602 = 36;
		public static final int CPT603 = 37;
		public static final int HDG701 = 38;
		public static final int CPT702 = 39;
		public static final int CPT703 = 40;
		public static final int CPT704 = 41;
		public static final int CPT705 = 42;
		public static final int CPT706 = 43;
		public static final int CPT707 = 44;
		public static final int CPT708 = 45;
		public static final int CPT709 = 46;
		public static final int CPT710 = 47;

		public Tag(
					String Cpt
					, String Hdg1
					, String Cpt2
					, String Cpt3
					, String Cpt4
					, String Cpt5
					, String Cpt6
					, String Hdg101
					, String Cpt102
					, String Cpt103
					, String Cpt104
					, String Hdg201
					, String Cpt202
					, String Cpt203
					, String Cpt204
					, String Hdg301
					, String Cpt302
					, String Cpt303
					, String Cpt304
					, String Hdg401
					, String Cpt402
					, String Cpt403
					, String Cpt404
					, String Cpt405
					, String Cpt406
					, String Cpt407
					, String Cpt408
					, String Hdg501
					, String Cpt502
					, String Cpt503
					, String Cpt504
					, String Cpt505
					, String Cpt506
					, String Cpt507
					, String Hdg601
					, String Cpt602
					, String Cpt603
					, String Hdg701
					, String Cpt702
					, String Cpt703
					, String Cpt704
					, String Cpt705
					, String Cpt706
					, String Cpt707
					, String Cpt708
					, String Cpt709
					, String Cpt710
				) {
			this.Cpt = Cpt;
			this.Hdg1 = Hdg1;
			this.Cpt2 = Cpt2;
			this.Cpt3 = Cpt3;
			this.Cpt4 = Cpt4;
			this.Cpt5 = Cpt5;
			this.Cpt6 = Cpt6;
			this.Hdg101 = Hdg101;
			this.Cpt102 = Cpt102;
			this.Cpt103 = Cpt103;
			this.Cpt104 = Cpt104;
			this.Hdg201 = Hdg201;
			this.Cpt202 = Cpt202;
			this.Cpt203 = Cpt203;
			this.Cpt204 = Cpt204;
			this.Hdg301 = Hdg301;
			this.Cpt302 = Cpt302;
			this.Cpt303 = Cpt303;
			this.Cpt304 = Cpt304;
			this.Hdg401 = Hdg401;
			this.Cpt402 = Cpt402;
			this.Cpt403 = Cpt403;
			this.Cpt404 = Cpt404;
			this.Cpt405 = Cpt405;
			this.Cpt406 = Cpt406;
			this.Cpt407 = Cpt407;
			this.Cpt408 = Cpt408;
			this.Hdg501 = Hdg501;
			this.Cpt502 = Cpt502;
			this.Cpt503 = Cpt503;
			this.Cpt504 = Cpt504;
			this.Cpt505 = Cpt505;
			this.Cpt506 = Cpt506;
			this.Cpt507 = Cpt507;
			this.Hdg601 = Hdg601;
			this.Cpt602 = Cpt602;
			this.Cpt603 = Cpt603;
			this.Hdg701 = Hdg701;
			this.Cpt702 = Cpt702;
			this.Cpt703 = Cpt703;
			this.Cpt704 = Cpt704;
			this.Cpt705 = Cpt705;
			this.Cpt706 = Cpt706;
			this.Cpt707 = Cpt707;
			this.Cpt708 = Cpt708;
			this.Cpt709 = Cpt709;
			this.Cpt710 = Cpt710;

			mask = new HashSet<Integer>(Arrays.asList(CPT, HDG1, CPT2, CPT3, CPT4, CPT5, CPT6, HDG101, CPT102, CPT103, CPT104, HDG201, CPT202, CPT203, CPT204, HDG301, CPT302, CPT303, CPT304, HDG401, CPT402, CPT403, CPT404, CPT405, CPT406, CPT407, CPT408, HDG501, CPT502, CPT503, CPT504, CPT505, CPT506, CPT507, HDG601, CPT602, CPT603, HDG701, CPT702, CPT703, CPT704, CPT705, CPT706, CPT707, CPT708, CPT709, CPT710));
		};

		public String Cpt;
		public String Hdg1;
		public String Cpt2;
		public String Cpt3;
		public String Cpt4;
		public String Cpt5;
		public String Cpt6;
		public String Hdg101;
		public String Cpt102;
		public String Cpt103;
		public String Cpt104;
		public String Hdg201;
		public String Cpt202;
		public String Cpt203;
		public String Cpt204;
		public String Hdg301;
		public String Cpt302;
		public String Cpt303;
		public String Cpt304;
		public String Hdg401;
		public String Cpt402;
		public String Cpt403;
		public String Cpt404;
		public String Cpt405;
		public String Cpt406;
		public String Cpt407;
		public String Cpt408;
		public String Hdg501;
		public String Cpt502;
		public String Cpt503;
		public String Cpt504;
		public String Cpt505;
		public String Cpt506;
		public String Cpt507;
		public String Hdg601;
		public String Cpt602;
		public String Cpt603;
		public String Hdg701;
		public String Cpt702;
		public String Cpt703;
		public String Cpt704;
		public String Cpt705;
		public String Cpt706;
		public String Cpt707;
		public String Cpt708;
		public String Cpt709;
		public String Cpt710;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbePrfDaemon");

			String itemtag = "TagitemWdbePrfDaemon";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				Hdg1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Hdg1", mask, HDG1);
				Cpt2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt2", mask, CPT2);
				Cpt3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt3", mask, CPT3);
				Cpt4 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt4", mask, CPT4);
				Cpt5 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt5", mask, CPT5);
				Cpt6 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt6", mask, CPT6);
				Hdg101 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Hdg101", mask, HDG101);
				Cpt102 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt102", mask, CPT102);
				Cpt103 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt103", mask, CPT103);
				Cpt104 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt104", mask, CPT104);
				Hdg201 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Hdg201", mask, HDG201);
				Cpt202 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt202", mask, CPT202);
				Cpt203 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt203", mask, CPT203);
				Cpt204 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt204", mask, CPT204);
				Hdg301 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Hdg301", mask, HDG301);
				Cpt302 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt302", mask, CPT302);
				Cpt303 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt303", mask, CPT303);
				Cpt304 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt304", mask, CPT304);
				Hdg401 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Hdg401", mask, HDG401);
				Cpt402 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt402", mask, CPT402);
				Cpt403 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt403", mask, CPT403);
				Cpt404 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt404", mask, CPT404);
				Cpt405 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt405", mask, CPT405);
				Cpt406 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt406", mask, CPT406);
				Cpt407 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt407", mask, CPT407);
				Cpt408 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt408", mask, CPT408);
				Hdg501 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Hdg501", mask, HDG501);
				Cpt502 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt502", mask, CPT502);
				Cpt503 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt503", mask, CPT503);
				Cpt504 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt504", mask, CPT504);
				Cpt505 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt505", mask, CPT505);
				Cpt506 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt506", mask, CPT506);
				Cpt507 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt507", mask, CPT507);
				Hdg601 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Hdg601", mask, HDG601);
				Cpt602 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt602", mask, CPT602);
				Cpt603 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt603", mask, CPT603);
				Hdg701 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Hdg701", mask, HDG701);
				Cpt702 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt702", mask, CPT702);
				Cpt703 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt703", mask, CPT703);
				Cpt704 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt704", mask, CPT704);
				Cpt705 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt705", mask, CPT705);
				Cpt706 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt706", mask, CPT706);
				Cpt707 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt707", mask, CPT707);
				Cpt708 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt708", mask, CPT708);
				Cpt709 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt709", mask, CPT709);
				Cpt710 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt710", mask, CPT710);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (Hdg1.equals(comp.Hdg1)) items.add(HDG1);
			if (Cpt2.equals(comp.Cpt2)) items.add(CPT2);
			if (Cpt3.equals(comp.Cpt3)) items.add(CPT3);
			if (Cpt4.equals(comp.Cpt4)) items.add(CPT4);
			if (Cpt5.equals(comp.Cpt5)) items.add(CPT5);
			if (Cpt6.equals(comp.Cpt6)) items.add(CPT6);
			if (Hdg101.equals(comp.Hdg101)) items.add(HDG101);
			if (Cpt102.equals(comp.Cpt102)) items.add(CPT102);
			if (Cpt103.equals(comp.Cpt103)) items.add(CPT103);
			if (Cpt104.equals(comp.Cpt104)) items.add(CPT104);
			if (Hdg201.equals(comp.Hdg201)) items.add(HDG201);
			if (Cpt202.equals(comp.Cpt202)) items.add(CPT202);
			if (Cpt203.equals(comp.Cpt203)) items.add(CPT203);
			if (Cpt204.equals(comp.Cpt204)) items.add(CPT204);
			if (Hdg301.equals(comp.Hdg301)) items.add(HDG301);
			if (Cpt302.equals(comp.Cpt302)) items.add(CPT302);
			if (Cpt303.equals(comp.Cpt303)) items.add(CPT303);
			if (Cpt304.equals(comp.Cpt304)) items.add(CPT304);
			if (Hdg401.equals(comp.Hdg401)) items.add(HDG401);
			if (Cpt402.equals(comp.Cpt402)) items.add(CPT402);
			if (Cpt403.equals(comp.Cpt403)) items.add(CPT403);
			if (Cpt404.equals(comp.Cpt404)) items.add(CPT404);
			if (Cpt405.equals(comp.Cpt405)) items.add(CPT405);
			if (Cpt406.equals(comp.Cpt406)) items.add(CPT406);
			if (Cpt407.equals(comp.Cpt407)) items.add(CPT407);
			if (Cpt408.equals(comp.Cpt408)) items.add(CPT408);
			if (Hdg501.equals(comp.Hdg501)) items.add(HDG501);
			if (Cpt502.equals(comp.Cpt502)) items.add(CPT502);
			if (Cpt503.equals(comp.Cpt503)) items.add(CPT503);
			if (Cpt504.equals(comp.Cpt504)) items.add(CPT504);
			if (Cpt505.equals(comp.Cpt505)) items.add(CPT505);
			if (Cpt506.equals(comp.Cpt506)) items.add(CPT506);
			if (Cpt507.equals(comp.Cpt507)) items.add(CPT507);
			if (Hdg601.equals(comp.Hdg601)) items.add(HDG601);
			if (Cpt602.equals(comp.Cpt602)) items.add(CPT602);
			if (Cpt603.equals(comp.Cpt603)) items.add(CPT603);
			if (Hdg701.equals(comp.Hdg701)) items.add(HDG701);
			if (Cpt702.equals(comp.Cpt702)) items.add(CPT702);
			if (Cpt703.equals(comp.Cpt703)) items.add(CPT703);
			if (Cpt704.equals(comp.Cpt704)) items.add(CPT704);
			if (Cpt705.equals(comp.Cpt705)) items.add(CPT705);
			if (Cpt706.equals(comp.Cpt706)) items.add(CPT706);
			if (Cpt707.equals(comp.Cpt707)) items.add(CPT707);
			if (Cpt708.equals(comp.Cpt708)) items.add(CPT708);
			if (Cpt709.equals(comp.Cpt709)) items.add(CPT709);
			if (Cpt710.equals(comp.Cpt710)) items.add(CPT710);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, HDG1, CPT2, CPT3, CPT4, CPT5, CPT6, HDG101, CPT102, CPT103, CPT104, HDG201, CPT202, CPT203, CPT204, HDG301, CPT302, CPT303, CPT304, HDG401, CPT402, CPT403, CPT404, CPT405, CPT406, CPT407, CPT408, HDG501, CPT502, CPT503, CPT504, CPT505, CPT506, CPT507, HDG601, CPT602, CPT603, HDG701, CPT702, CPT703, CPT704, CPT705, CPT706, CPT707, CPT708, CPT709, CPT710));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbePrfDaemonData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPRFDAEMONDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePrfDaemonData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbePrfDaemonDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPRFDAEMONDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePrfDaemonDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbePrfDaemonData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFPUP402 = 3;
		public static final int FEEDFPUP706 = 4;
		public static final int STATSHR = 5;
		public static final int TAG = 6;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEPRFDAEMONDATA);

			contiac = new ContIac("", false, "", "", "", "", false, "", "", "", false, "", "", false, 0, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 0, "", "", "", "");
			feedFPup402 = new Feed("FeedFPup402");
			feedFPup706 = new Feed("FeedFPup706");
			statshr = new StatShr(0, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFPup402;
		public Feed feedFPup706;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFPUP402)) ss.add("feedFPup402");
			if (has(FEEDFPUP706)) ss.add("feedFPup706");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbePrfDaemonData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFPup402.readXML(doc, basexpath, true)) add(FEEDFPUP402);
				if (feedFPup706.readXML(doc, basexpath, true)) add(FEEDFPUP706);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", false, "", "", "", "", false, "", "", "", false, "", "", false, 0, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 0, "", "", "", "");
				feedFPup402 = new Feed("FeedFPup402");
				feedFPup706 = new Feed("FeedFPup706");
				statshr = new StatShr(0, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
