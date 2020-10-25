/**
  * \file DpchAppWdbeResume.java
  * Wdbe Java API package resume app dispatch block
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

public class DpchAppWdbeResume extends DpchAppWdbe {

	public DpchAppWdbeResume(
				String scrJref
			) {
		super(VecWdbeVDpch.DPCHAPPWDBERESUME, scrJref);
	};
};

