/**
  * \file VecWdbeVBasereptype.java
  * vector VecWdbeVBasereptype
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

public class VecWdbeVBasereptype {
	public static final int VOID = 1;
	public static final int PRJGIT = 2;
	public static final int CUSTGIT = 3;
	public static final int ULD = 4;

	public static int getIx(
				String sref
			) {
		String s = sref.toLowerCase();

		if (s.equals("void")) return VOID;
		if (s.equals("prjgit")) return PRJGIT;
		if (s.equals("custgit")) return CUSTGIT;
		if (s.equals("uld")) return ULD;

		return 0;
	};

	public static String getSref(
				int ix
			) {
		if (ix == VOID) return("void");
		if (ix == PRJGIT) return("prjgit");
		if (ix == CUSTGIT) return("custgit");
		if (ix == ULD) return("uld");

		return "";
	};

};

