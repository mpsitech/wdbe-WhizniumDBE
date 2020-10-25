/**
	* \file WdbeopdOpprc.h
	* operation processor for Wdbe operation daemon wdbeopd1 (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBEOPDOPPRC_H
#define WDBEOPDOPPRC_H

#include "WdbeModbscCtrtd.h"
#include "WdbeModbscFwdctrtd.h"
#include "WdbeModbscImbuftd.h"
#include "WdbeModbscSys.h"
#include "WdbeModbscTplcpy.h"
#include "WdbeModbscUnt.h"
#include "WdbeModdetCmdbus.h"
#include "WdbeModdetCtrFwdctr.h"
#include "WdbeModdetEctr.h"
#include "WdbeModdetEhostif.h"
#include "WdbeModdetImbuf.h"
#include "WdbeModdetUnt.h"
#include "WdbeModdetWiring.h"
#include "WdbePlhfpgaCmdinv.h"
#include "WdbePlhfpgaCmdret.h"
#include "WdbePlhfpgaEhostif.h"
#include "WdbePlhfpgaFwdctr.h"
#include "WdbePlhmcuEhostif.h"
#include "WdbePrcfileConcat.h"
#include "WdbePrcfileIexconv.h"
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
#include "WdbeWrmcuBase.h"
#include "WdbeWrmcuCtrFwdctr.h"
#include "WdbeWrmcuDeploy.h"
#include "WdbeWrmcuEhostif.h"
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

