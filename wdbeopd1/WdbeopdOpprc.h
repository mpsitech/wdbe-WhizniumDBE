/**
	* \file WdbeopdOpprc.h
	* operation processor for Wdbe operation daemon wdbeopd1 (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef WDBEOPDOPPRC_H
#define WDBEOPDOPPRC_H

#include "WdbeWrmcuBase.h"
#include "WdbeWrmcuCtrFwdctr.h"
#include "WdbeWrmcuDeploy.h"
#include "WdbeWrmcuEhostif.h"
#include "WdbeWrmcuMdlfine.h"
#include "WdbeWrmcuMdlraw.h"
#include "WdbeWrfpgaBase.h"
#include "WdbeWrfpgaCtrFwdctr.h"
#include "WdbeWrfpgaDeploy.h"
#include "WdbeWrfpgaEhostif.h"
#include "WdbeWrfpgaHostif.h"
#include "WdbeWrfpgaIpclr.h"
#include "WdbeWrfpgaMdlfine.h"
#include "WdbeWrfpgaMdlraw.h"
#include "WdbeWrdevBase.h"
#include "WdbeWrdevCtr.h"
#include "WdbeWrdevDeploy.h"
#include "WdbeWrdevSys.h"
#include "WdbeWrdevUnt.h"
#include "WdbePrctreeExtract.h"
#include "WdbePrctreeMerge.h"
#include "WdbePrctreeValidate.h"
#include "WdbePrcfileConcat.h"
#include "WdbePrcfileIexconv.h"
#include "WdbePrcfilePlhrpl.h"
#include "WdbePlhmcuEhostif.h"
#include "WdbePlhfpgaCmdinv.h"
#include "WdbePlhfpgaCmdret.h"
#include "WdbePlhfpgaEhostif.h"
#include "WdbePlhfpgaFwdctr.h"
#include "WdbeModdetCmdbus.h"
#include "WdbeModdetCtrFwdctr.h"
#include "WdbeModdetEctr.h"
#include "WdbeModdetEhostif.h"
#include "WdbeModdetImbuf.h"
#include "WdbeModdetUnt.h"
#include "WdbeModdetWiring.h"
#include "WdbeModbscCtrtd.h"
#include "WdbeModbscFwdctrtd.h"
#include "WdbeModbscImbuftd.h"
#include "WdbeModbscSys.h"
#include "WdbeModbscTplcpy.h"
#include "WdbeModbscUnt.h"

/**
	* WdbeopdOpprc
	*/
namespace WdbeopdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif

