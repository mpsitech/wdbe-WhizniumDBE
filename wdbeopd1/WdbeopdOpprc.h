/**
	* \file WdbeopdOpprc.h
	* operation processor for Wdbe operation daemon wdbeopd1 (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEOPDOPPRC_H
#define WDBEOPDOPPRC_H

#include "WdbeCplmstCtrEctr.h"
#include "WdbeCplmstFwdctr.h"
#include "WdbeCplmstImbuf.h"
#include "WdbeCplmstSys.h"
#include "WdbeCplmstTplcpy.h"
#include "WdbeCplmstUnt.h"
#include "WdbeGenStdvec.h"
#include "WdbeGenTest.h"
#include "WdbeGenWiring.h"
#include "WdbeGenfstCmdbus.h"
#include "WdbeGenfstCtrFwdctr.h"
#include "WdbeGenfstEctr.h"
#include "WdbeGenfstEhostif.h"
#include "WdbeGenfstHostif.h"
#include "WdbeGenfstImbuf.h"
#include "WdbeGenfstPpl.h"
#include "WdbeGenfstTop.h"
#include "WdbePlhfpgaCmdinv.h"
#include "WdbePlhfpgaCmdret.h"
#include "WdbePlhfpgaEhostif.h"
#include "WdbePlhfpgaFwdctr.h"
#include "WdbePlhmcuEctr.h"
#include "WdbePlhmcuEhostif.h"
#include "WdbePrcfileConcat.h"
#include "WdbePrcfilePlhrpl.h"
#include "WdbePrctreeExtract.h"
#include "WdbePrctreeMerge.h"
#include "WdbePrctreeValidate.h"
#include "WdbeWrdevBase.h"
#include "WdbeWrdevCtr.h"
#include "WdbeWrdevDeploy.h"
#include "WdbeWrdevSys.h"
#include "WdbeWrdevUnt.h"
#include "WdbeWrfpgaBase.h"
#include "WdbeWrfpgaCtrFwdctr.h"
#include "WdbeWrfpgaDeploy.h"
#include "WdbeWrfpgaEhostif.h"
#include "WdbeWrfpgaHostif.h"
#include "WdbeWrfpgaIpclr.h"
#include "WdbeWrfpgaMdlfine.h"
#include "WdbeWrfpgaMdlraw.h"
#include "WdbeWrfpgaTop.h"
#include "WdbeWrmcuBase.h"
#include "WdbeWrmcuCtrFwdctr.h"
#include "WdbeWrmcuDeploy.h"
#include "WdbeWrmcuMdlfine.h"
#include "WdbeWrmcuMdlraw.h"

/**
	* WdbeopdOpprc
	*/
namespace WdbeopdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif
