/**
  * \file DpchWdbe.java
  * Wdbe Java API package dispatch block
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import sbecore.*;

public class DpchWdbe extends Block {

	public DpchWdbe(
				int ixWdbeVDpch
			) {
		this.ixWdbeVDpch = ixWdbeVDpch;
	};

	public int ixWdbeVDpch;
};

