/**
  * \file DpchAppWdbeInit.java
  * Wdbe Java API package init app dispatch block
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

public class DpchAppWdbeInit extends DpchAppWdbe {

	public DpchAppWdbeInit(
				String scrJref
			) {
		super(VecWdbeVDpch.DPCHAPPWDBEINIT, scrJref);
	};
};

