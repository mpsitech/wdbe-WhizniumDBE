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

#include "WdbeCplmstCtrEctrHostifEhostif.h"
#include "WdbeCplmstImbuf.h"
#include "WdbeCplmstTplcpy.h"
#include "WdbeCplmstUnt.h"
#include "WdbeGenAux.h"
#include "WdbeGenStdvec.h"
#include "WdbeGenWiring.h"
#include "WdbeGenfstCmdbus.h"
#include "WdbeGenfstCtr.h"
#include "WdbeGenfstEctr.h"
#include "WdbeGenfstEhostif.h"
#include "WdbeGenfstHostif.h"
#include "WdbeGenfstImbuf.h"
#include "WdbeGenfstPpl.h"
#include "WdbeGenfstTop.h"
#include "WdbePlhfpgaCmdinv.h"
#include "WdbePlhfpgaCmdret.h"
#include "WdbePlhfpgaCtr.h"
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
#include "WdbeWrdevUnt.h"
#include "WdbeWrfpgaAux.h"
#include "WdbeWrfpgaBase.h"
#include "WdbeWrfpgaCtr.h"
#include "WdbeWrfpgaDeploy.h"
#include "WdbeWrfpgaMdlfine.h"
#include "WdbeWrfpgaMdlraw.h"
#include "WdbeWrfpgaTop.h"
#include "WdbeWrmcuBase.h"
#include "WdbeWrmcuCtr.h"
#include "WdbeWrmcuDeploy.h"
#include "WdbeWrmcuMdlfine.h"
#include "WdbeWrmcuMdlraw.h"
#include "WdbeWrtermDeploy.h"
#include "WdbeWrtermMain.h"

/**
	* WdbeopdOpprc
	*/
namespace WdbeopdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif
