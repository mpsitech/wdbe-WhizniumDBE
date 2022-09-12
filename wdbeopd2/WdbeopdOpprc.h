/**
	* \file WdbeopdOpprc.h
	* operation processor for Wdbe operation daemon wdbeopd2 (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEOPDOPPRC_H
#define WDBEOPDOPPRC_H

#include "WdbeMtpWrmcuUarthostif_Easy_v1_1_Mcu.h"
#include "WdbeMtpWrmcuUsbhostif_Easy_v1_0_Mcu.h"
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
#include "WdbeMtpGenfstPmmu_v1_0.h"
#include "WdbeMtpGenfstSpifwd_v1_0.h"
#include "WdbeMtpGenfstTkclksrc_v1_0.h"
#include "WdbeMtpGenfstUarthostif_Easy_v1_1_Mcu.h"
#include "WdbeMtpGenfstUsbhostif_Easy_v1_0_Mcu.h"
#include "WdbeMtpCplmsttdCmdinv_v1_0.h"
#include "WdbeMtpCplmsttdCmdret_v1_0.h"
#include "WdbeMtpCplmsttdDpbram_v1_0.h"
#include "WdbeMtpCplmsttdGpio_Easy_v1_0.h"
#include "WdbeMtpCplmsttdI2c_Easy_v1_0.h"
#include "WdbeMtpCplmsttdPmmu_v1_0.h"
#include "WdbeMtpCplmsttdSpbram_v1_0.h"
#include "WdbeMtpCplmsttdTop_lttc_v1_0.h"
#include "WdbeMtpCplmsttdTop_mchp_v1_0.h"
#include "WdbeMtpCplmsttdTop_xlnx_v1_0.h"
#include "WdbeMtpCplmstbuAdd_xlnx_v12_0.h"
#include "WdbeMtpCplmstbuAxihostif_Easy_v1_0.h"
#include "WdbeMtpCplmstbuAxihostif_Easy_v2_0.h"
#include "WdbeMtpCplmstbuAxihostif_v1_0.h"
#include "WdbeMtpCplmstbuCmdinv_v1_0.h"
#include "WdbeMtpCplmstbuCmdret_v1_0.h"
#include "WdbeMtpCplmstbuDft_xlnx_v4_0.h"
#include "WdbeMtpCplmstbuDiv_xlnx_v3_0.h"
#include "WdbeMtpCplmstbuDiv_xlnx_v5_1.h"
#include "WdbeMtpCplmstbuDotmx2x16_v1_0.h"
#include "WdbeMtpCplmstbuDpbram_v1_0.h"
#include "WdbeMtpCplmstbuDpbram_xlnx_v8_4.h"
#include "WdbeMtpCplmstbuDpsram_mchp_v1_0.h"
#include "WdbeMtpCplmstbuDsp48_xlnx_v3_0_aMultB.h"
#include "WdbeMtpCplmstbuDsp48_xlnx_v3_0_aPlusDPlusC.h"
#include "WdbeMtpCplmstbuGpio_Easy_v1_0.h"
#include "WdbeMtpCplmstbuIod_mchp_v1_0_mipirx.h"
#include "WdbeMtpCplmstbuMipidec_mchp_v1_0.h"
#include "WdbeMtpCplmstbuMpfs_ip_AXI_v1_0.h"
#include "WdbeMtpCplmstbuMult_xlnx_v12_0.h"
#include "WdbeMtpCplmstbuOled128x32_v1_0.h"
#include "WdbeMtpCplmstbuPmmu_v1_0.h"
#include "WdbeMtpCplmstbuSelectio_xlnx_v5_1_mipirx.h"
#include "WdbeMtpCplmstbuSpbram_v1_0.h"
#include "WdbeMtpCplmstbuSpifwd_v1_0.h"
#include "WdbeMtpCplmstbuSpihostif_Easy_v1_0.h"
#include "WdbeMtpCplmstbuSpihostif_v1_0.h"
#include "WdbeMtpCplmstbuSub_xlnx_v12_0.h"
#include "WdbeMtpCplmstbuTop_lttc_v1_0.h"
#include "WdbeMtpCplmstbuTop_mchp_v1_0.h"
#include "WdbeMtpCplmstbuTop_xlnx_v1_0.h"
#include "WdbeMtpCplmstbuTpsram_mchp_v1_0.h"
#include "WdbeMtpCplmstbuUart_Easy_v1_0.h"
#include "WdbeMtpCplmstbuUarthostif_Easy_v1_0.h"
#include "WdbeMtpCplmstbuUarthostif_v1_0.h"
#include "WdbeMtpCplmstbuUartrx_v1_0_Mcu.h"
#include "WdbeMtpCplmstbuUarttx_v1_0_Mcu.h"
#include "WdbeMtpCplmstbuUsbrxtx_slbs_v1_0_Mcu.h"
#include "WdbeMtpCplmstbuXadc_xlnx_v3_3.h"
#include "WdbeMtpCplmstbuZynq_ip_AXI_v1_0.h"
#include "WdbeMtpCplmstbuZynq_ip_AXI_v2_0.h"
#include "WdbeMtpPlhmcuUsbhostif_Easy_v1_0_Mcu.h"
#include "WdbeMtpPlhfpgaPmmu_v1_0.h"

/**
	* WdbeopdOpprc
	*/
namespace WdbeopdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif
