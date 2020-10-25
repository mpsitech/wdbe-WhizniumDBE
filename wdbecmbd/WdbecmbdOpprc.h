/**
	* \file WdbecmbdOpprc.h
	* operation processor for Wdbe combined daemon (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#ifndef WDBECMBDOPPRC_H
#define WDBECMBDOPPRC_H

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
#include "WdbeMtpModbscbuAdd_v12_0.h"
#include "WdbeMtpModbscbuAxihostif_Easy_v1_0.h"
#include "WdbeMtpModbscbuAxihostif_Easy_v2_0.h"
#include "WdbeMtpModbscbuAxihostif_v1_0.h"
#include "WdbeMtpModbscbuCmdinv_v1_0.h"
#include "WdbeMtpModbscbuCmdret_v1_0.h"
#include "WdbeMtpModbscbuDft_v4_0.h"
#include "WdbeMtpModbscbuDiv_v3_0.h"
#include "WdbeMtpModbscbuDiv_v5_1.h"
#include "WdbeMtpModbscbuDotmx2x16_v1_0.h"
#include "WdbeMtpModbscbuDpbram_v1_0.h"
#include "WdbeMtpModbscbuDpbram_v8_4.h"
#include "WdbeMtpModbscbuDsp48_v3_0_aMultB.h"
#include "WdbeMtpModbscbuDsp48_v3_0_aPlusDPlusC.h"
#include "WdbeMtpModbscbuMult_v12_0.h"
#include "WdbeMtpModbscbuOled128x32_v1_0.h"
#include "WdbeMtpModbscbuPmmu_v1_0.h"
#include "WdbeMtpModbscbuSpbram_v1_0.h"
#include "WdbeMtpModbscbuSpifwd_v1_0.h"
#include "WdbeMtpModbscbuSpihostif_Easy_v1_0.h"
#include "WdbeMtpModbscbuSpihostif_v1_0.h"
#include "WdbeMtpModbscbuSub_v12_0.h"
#include "WdbeMtpModbscbuUarthostif_Easy_v1_0.h"
#include "WdbeMtpModbscbuUarthostif_v1_0.h"
#include "WdbeMtpModbscbuXadc_v3_3.h"
#include "WdbeMtpModbscbuZynq_ip_AXI_v1_0.h"
#include "WdbeMtpModbscbuZynq_ip_AXI_v2_0.h"
#include "WdbeMtpModbscbuZynq_ip_v1_0.h"
#include "WdbeMtpModbsctdCmdinv_v1_0.h"
#include "WdbeMtpModbsctdCmdret_v1_0.h"
#include "WdbeMtpModbsctdDpbram_v1_0.h"
#include "WdbeMtpModbsctdPmmu_v1_0.h"
#include "WdbeMtpModbsctdSpbram_v1_0.h"
#include "WdbeMtpModdetPmmu_v1_0.h"
#include "WdbeMtpModdetSpifwd_v1_0.h"
#include "WdbeMtpModdetTkclksrc_v1_0.h"
#include "WdbeMtpModdetTop_v1_0.h"
#include "WdbeMtpPlhfpgaPmmu_v1_0.h"
#include "WdbeMtpWrfpgaCmdbus_v1_0.h"
#include "WdbeMtpWrfpgaCmdinv_v1_0.h"
#include "WdbeMtpWrfpgaCmdret_v1_0.h"
#include "WdbeMtpWrfpgaCrcspec_32_v1_0.h"
#include "WdbeMtpWrfpgaCrcspec_v1_0.h"
#include "WdbeMtpWrfpgaDpbram_v1_0.h"
#include "WdbeMtpWrfpgaPmmu_v1_0.h"
#include "WdbeMtpWrfpgaSpbram_v1_0.h"
#include "WdbeMtpWrfpgaSpifwd_v1_0.h"
#include "WdbeMtpWrfpgaTkclksrc_v1_0.h"
#include "WdbeMtpWrfpgaTop_v1_0.h"
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
	* WdbecmbdOpprc
	*/
namespace WdbecmbdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif

