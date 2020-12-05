/**
	* \file VecWdbeVStub.cpp
	* vector VecWdbeVStub (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "VecWdbeVStub.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWdbeVStub
 ******************************************************************************/

uint VecWdbeVStub::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "stubwdbeverno") return STUBWDBEVERNO;
	if (s == "stubwdbevershort") return STUBWDBEVERSHORT;
	if (s == "stubwdbeverstd") return STUBWDBEVERSTD;
	if (s == "stubwdbevitstd") return STUBWDBEVITSTD;
	if (s == "stubwdbevecstd") return STUBWDBEVECSTD;
	if (s == "stubwdbevarstd") return STUBWDBEVARSTD;
	if (s == "stubwdbegroup") return STUBWDBEGROUP;
	if (s == "stubwdbeusgstd") return STUBWDBEUSGSTD;
	if (s == "stubwdbeowner") return STUBWDBEOWNER;
	if (s == "stubwdbeusrprs") return STUBWDBEUSRPRS;
	if (s == "stubwdbeusrstd") return STUBWDBEUSRSTD;
	if (s == "stubwdbesilstd") return STUBWDBESILSTD;
	if (s == "stubwdbeunistd") return STUBWDBEUNISTD;
	if (s == "stubwdbeuntsref") return STUBWDBEUNTSREF;
	if (s == "stubwdbeuntstd") return STUBWDBEUNTSTD;
	if (s == "stubwdbetrgsref") return STUBWDBETRGSREF;
	if (s == "stubwdbetrgstd") return STUBWDBETRGSTD;
	if (s == "stubwdbesysstd") return STUBWDBESYSSTD;
	if (s == "stubwdbesigsref") return STUBWDBESIGSREF;
	if (s == "stubwdbesigstd") return STUBWDBESIGSTD;
	if (s == "stubwdbesesmenu") return STUBWDBESESMENU;
	if (s == "stubwdbesesstd") return STUBWDBESESSTD;
	if (s == "stubwdberlslong") return STUBWDBERLSLONG;
	if (s == "stubwdberlsstd") return STUBWDBERLSSTD;
	if (s == "stubwdbeprjshort") return STUBWDBEPRJSHORT;
	if (s == "stubwdbeprjstd") return STUBWDBEPRJSTD;
	if (s == "stubwdbeprcstd") return STUBWDBEPRCSTD;
	if (s == "stubwdbeprtsref") return STUBWDBEPRTSREF;
	if (s == "stubwdbeprtstd") return STUBWDBEPRTSTD;
	if (s == "stubwdbepinstd") return STUBWDBEPINSTD;
	if (s == "stubwdbeprsstd") return STUBWDBEPRSSTD;
	if (s == "stubwdbepphstd") return STUBWDBEPPHSTD;
	if (s == "stubwdbemdlhsref") return STUBWDBEMDLHSREF;
	if (s == "stubwdbemdlsref") return STUBWDBEMDLSREF;
	if (s == "stubwdbemdlstd") return STUBWDBEMDLSTD;
	if (s == "stubwdbemodstd") return STUBWDBEMODSTD;
	if (s == "stubwdbemtpstd") return STUBWDBEMTPSTD;
	if (s == "stubwdbemchsref") return STUBWDBEMCHSREF;
	if (s == "stubwdbemchstd") return STUBWDBEMCHSTD;
	if (s == "stubwdbelibsref") return STUBWDBELIBSREF;
	if (s == "stubwdbelibstd") return STUBWDBELIBSTD;
	if (s == "stubwdbeimbstd") return STUBWDBEIMBSTD;
	if (s == "stubwdbegenstd") return STUBWDBEGENSTD;
	if (s == "stubwdbefststd") return STUBWDBEFSTSTD;
	if (s == "stubwdbefsmstd") return STUBWDBEFSMSTD;
	if (s == "stubwdbefilstd") return STUBWDBEFILSTD;
	if (s == "stubwdbefamstd") return STUBWDBEFAMSTD;
	if (s == "stubwdbeerrstd") return STUBWDBEERRSTD;
	if (s == "stubwdbecvrno") return STUBWDBECVRNO;
	if (s == "stubwdbecvrstd") return STUBWDBECVRSTD;
	if (s == "stubwdbecprstd") return STUBWDBECPRSTD;
	if (s == "stubwdbectrlong") return STUBWDBECTRLONG;
	if (s == "stubwdbectrsref") return STUBWDBECTRSREF;
	if (s == "stubwdbectrstd") return STUBWDBECTRSTD;
	if (s == "stubwdbecmdstd") return STUBWDBECMDSTD;
	if (s == "stubwdbebnksref") return STUBWDBEBNKSREF;
	if (s == "stubwdbebnkstd") return STUBWDBEBNKSTD;

	return(0);
};

string VecWdbeVStub::getSref(
			const uint ix
		) {
	if (ix == STUBWDBEVERNO) return("StubWdbeVerNo");
	if (ix == STUBWDBEVERSHORT) return("StubWdbeVerShort");
	if (ix == STUBWDBEVERSTD) return("StubWdbeVerStd");
	if (ix == STUBWDBEVITSTD) return("StubWdbeVitStd");
	if (ix == STUBWDBEVECSTD) return("StubWdbeVecStd");
	if (ix == STUBWDBEVARSTD) return("StubWdbeVarStd");
	if (ix == STUBWDBEGROUP) return("StubWdbeGroup");
	if (ix == STUBWDBEUSGSTD) return("StubWdbeUsgStd");
	if (ix == STUBWDBEOWNER) return("StubWdbeOwner");
	if (ix == STUBWDBEUSRPRS) return("StubWdbeUsrPrs");
	if (ix == STUBWDBEUSRSTD) return("StubWdbeUsrStd");
	if (ix == STUBWDBESILSTD) return("StubWdbeSilStd");
	if (ix == STUBWDBEUNISTD) return("StubWdbeUniStd");
	if (ix == STUBWDBEUNTSREF) return("StubWdbeUntSref");
	if (ix == STUBWDBEUNTSTD) return("StubWdbeUntStd");
	if (ix == STUBWDBETRGSREF) return("StubWdbeTrgSref");
	if (ix == STUBWDBETRGSTD) return("StubWdbeTrgStd");
	if (ix == STUBWDBESYSSTD) return("StubWdbeSysStd");
	if (ix == STUBWDBESIGSREF) return("StubWdbeSigSref");
	if (ix == STUBWDBESIGSTD) return("StubWdbeSigStd");
	if (ix == STUBWDBESESMENU) return("StubWdbeSesMenu");
	if (ix == STUBWDBESESSTD) return("StubWdbeSesStd");
	if (ix == STUBWDBERLSLONG) return("StubWdbeRlsLong");
	if (ix == STUBWDBERLSSTD) return("StubWdbeRlsStd");
	if (ix == STUBWDBEPRJSHORT) return("StubWdbePrjShort");
	if (ix == STUBWDBEPRJSTD) return("StubWdbePrjStd");
	if (ix == STUBWDBEPRCSTD) return("StubWdbePrcStd");
	if (ix == STUBWDBEPRTSREF) return("StubWdbePrtSref");
	if (ix == STUBWDBEPRTSTD) return("StubWdbePrtStd");
	if (ix == STUBWDBEPINSTD) return("StubWdbePinStd");
	if (ix == STUBWDBEPRSSTD) return("StubWdbePrsStd");
	if (ix == STUBWDBEPPHSTD) return("StubWdbePphStd");
	if (ix == STUBWDBEMDLHSREF) return("StubWdbeMdlHsref");
	if (ix == STUBWDBEMDLSREF) return("StubWdbeMdlSref");
	if (ix == STUBWDBEMDLSTD) return("StubWdbeMdlStd");
	if (ix == STUBWDBEMODSTD) return("StubWdbeModStd");
	if (ix == STUBWDBEMTPSTD) return("StubWdbeMtpStd");
	if (ix == STUBWDBEMCHSREF) return("StubWdbeMchSref");
	if (ix == STUBWDBEMCHSTD) return("StubWdbeMchStd");
	if (ix == STUBWDBELIBSREF) return("StubWdbeLibSref");
	if (ix == STUBWDBELIBSTD) return("StubWdbeLibStd");
	if (ix == STUBWDBEIMBSTD) return("StubWdbeImbStd");
	if (ix == STUBWDBEGENSTD) return("StubWdbeGenStd");
	if (ix == STUBWDBEFSTSTD) return("StubWdbeFstStd");
	if (ix == STUBWDBEFSMSTD) return("StubWdbeFsmStd");
	if (ix == STUBWDBEFILSTD) return("StubWdbeFilStd");
	if (ix == STUBWDBEFAMSTD) return("StubWdbeFamStd");
	if (ix == STUBWDBEERRSTD) return("StubWdbeErrStd");
	if (ix == STUBWDBECVRNO) return("StubWdbeCvrNo");
	if (ix == STUBWDBECVRSTD) return("StubWdbeCvrStd");
	if (ix == STUBWDBECPRSTD) return("StubWdbeCprStd");
	if (ix == STUBWDBECTRLONG) return("StubWdbeCtrLong");
	if (ix == STUBWDBECTRSREF) return("StubWdbeCtrSref");
	if (ix == STUBWDBECTRSTD) return("StubWdbeCtrStd");
	if (ix == STUBWDBECMDSTD) return("StubWdbeCmdStd");
	if (ix == STUBWDBEBNKSREF) return("StubWdbeBnkSref");
	if (ix == STUBWDBEBNKSTD) return("StubWdbeBnkStd");

	return("");
};



