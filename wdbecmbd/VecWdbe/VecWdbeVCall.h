/**
	* \file VecWdbeVCall.h
	* vector VecWdbeVCall (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef VECWDBEVCALL_H
#define VECWDBEVCALL_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVCall
	*/
namespace VecWdbeVCall {
	const Sbecore::uint CALLWDBEBNK_UNT_INSBS = 1;
	const Sbecore::uint CALLWDBEBNK_UNTEQ = 2;
	const Sbecore::uint CALLWDBEBNKMOD = 3;
	const Sbecore::uint CALLWDBEBNKMOD_UNTEQ = 4;
	const Sbecore::uint CALLWDBEBNKUPD_REFEQ = 5;
	const Sbecore::uint CALLWDBEBOOLVALPRESET = 6;
	const Sbecore::uint CALLWDBECDC_MDLEQ = 7;
	const Sbecore::uint CALLWDBECDCMOD = 8;
	const Sbecore::uint CALLWDBECDCMOD_MDLEQ = 9;
	const Sbecore::uint CALLWDBECDCRSIGMOD_CDCEQ = 10;
	const Sbecore::uint CALLWDBECDCRSIGMOD_SIGEQ = 11;
	const Sbecore::uint CALLWDBECDCUPD_REFEQ = 12;
	const Sbecore::uint CALLWDBECLAIMCHG = 13;
	const Sbecore::uint CALLWDBECMD_IVREQ = 14;
	const Sbecore::uint CALLWDBECMD_REREQ = 15;
	const Sbecore::uint CALLWDBECMD_RETEQ = 16;
	const Sbecore::uint CALLWDBECMD_REU_INSBS = 17;
	const Sbecore::uint CALLWDBECMD_REU_MDL_INSBS = 18;
	const Sbecore::uint CALLWDBECMD_REUEQ = 19;
	const Sbecore::uint CALLWDBECMD_RVREQ = 20;
	const Sbecore::uint CALLWDBECMDAIPAMOD_CMDEQ = 21;
	const Sbecore::uint CALLWDBECMDARPAMOD_CMDEQ = 22;
	const Sbecore::uint CALLWDBECMDMOD = 23;
	const Sbecore::uint CALLWDBECMDMOD_RETREUEQ = 24;
	const Sbecore::uint CALLWDBECMDRCTRMOD_CMDEQ = 25;
	const Sbecore::uint CALLWDBECMDRCTRMOD_CTREQ = 26;
	const Sbecore::uint CALLWDBECMDUPD_REFEQ = 27;
	const Sbecore::uint CALLWDBECMP_VEREQ = 28;
	const Sbecore::uint CALLWDBECMPMOD = 29;
	const Sbecore::uint CALLWDBECMPMOD_VEREQ = 30;
	const Sbecore::uint CALLWDBECMPRLIBMOD_CMPEQ = 31;
	const Sbecore::uint CALLWDBECMPRLIBMOD_LIBEQ = 32;
	const Sbecore::uint CALLWDBECMPUPD_REFEQ = 33;
	const Sbecore::uint CALLWDBECPR_CVREQ = 34;
	const Sbecore::uint CALLWDBECPRMOD = 35;
	const Sbecore::uint CALLWDBECPRRPRSMOD_CPREQ = 36;
	const Sbecore::uint CALLWDBECPRRPRSMOD_PRSEQ = 37;
	const Sbecore::uint CALLWDBECPRUPD_REFEQ = 38;
	const Sbecore::uint CALLWDBECRDACTIVE = 39;
	const Sbecore::uint CALLWDBECRDCLOSE = 40;
	const Sbecore::uint CALLWDBECRDOPEN = 41;
	const Sbecore::uint CALLWDBECTLAPARMOD_USREQ = 42;
	const Sbecore::uint CALLWDBECTR_CLREQ = 43;
	const Sbecore::uint CALLWDBECTR_MDL_INSBS = 44;
	const Sbecore::uint CALLWDBECTRMOD = 45;
	const Sbecore::uint CALLWDBECTRUPD_REFEQ = 46;
	const Sbecore::uint CALLWDBECVR_BCVEQ = 47;
	const Sbecore::uint CALLWDBECVR_CPREQ = 48;
	const Sbecore::uint CALLWDBECVRAIPXMOD_CVREQ = 49;
	const Sbecore::uint CALLWDBECVRAPLHMOD_CVREQ = 50;
	const Sbecore::uint CALLWDBECVRJSTEMOD_CVREQ = 51;
	const Sbecore::uint CALLWDBECVRMOD = 52;
	const Sbecore::uint CALLWDBECVRMOD_BCVEQ = 53;
	const Sbecore::uint CALLWDBECVRMOD_CPREQ = 54;
	const Sbecore::uint CALLWDBECVRUPD_REFEQ = 55;
	const Sbecore::uint CALLWDBEDATCHG = 56;
	const Sbecore::uint CALLWDBEDBLVALPRESET = 57;
	const Sbecore::uint CALLWDBEDLGCLOSE = 58;
	const Sbecore::uint CALLWDBEERR_RETEQ = 59;
	const Sbecore::uint CALLWDBEERR_REU_INSBS = 60;
	const Sbecore::uint CALLWDBEERR_REU_MDL_INSBS = 61;
	const Sbecore::uint CALLWDBEERR_REUEQ = 62;
	const Sbecore::uint CALLWDBEERR_TRAEQ = 63;
	const Sbecore::uint CALLWDBEERRAPARMOD_ERREQ = 64;
	const Sbecore::uint CALLWDBEERRMOD = 65;
	const Sbecore::uint CALLWDBEERRMOD_RETREUEQ = 66;
	const Sbecore::uint CALLWDBEERRUPD_REFEQ = 67;
	const Sbecore::uint CALLWDBEFAMMOD = 68;
	const Sbecore::uint CALLWDBEFAMUPD_REFEQ = 69;
	const Sbecore::uint CALLWDBEFIL_CLUEQ = 70;
	const Sbecore::uint CALLWDBEFIL_RETEQ = 71;
	const Sbecore::uint CALLWDBEFIL_REUEQ = 72;
	const Sbecore::uint CALLWDBEFILMOD = 73;
	const Sbecore::uint CALLWDBEFILMOD_CLUEQ = 74;
	const Sbecore::uint CALLWDBEFILMOD_RETREUEQ = 75;
	const Sbecore::uint CALLWDBEFILUPD_REFEQ = 76;
	const Sbecore::uint CALLWDBEFSMMOD = 77;
	const Sbecore::uint CALLWDBEFSMUPD_REFEQ = 78;
	const Sbecore::uint CALLWDBEFST_CLUEQ = 79;
	const Sbecore::uint CALLWDBEFST_FSMEQ = 80;
	const Sbecore::uint CALLWDBEFSTASTPMOD_FSTEQ = 81;
	const Sbecore::uint CALLWDBEFSTMOD = 82;
	const Sbecore::uint CALLWDBEFSTMOD_CLUEQ = 83;
	const Sbecore::uint CALLWDBEFSTMOD_FSMEQ = 84;
	const Sbecore::uint CALLWDBEFSTUPD_REFEQ = 85;
	const Sbecore::uint CALLWDBEGEN_CLUEQ = 86;
	const Sbecore::uint CALLWDBEGEN_MDL_INSBS = 87;
	const Sbecore::uint CALLWDBEGEN_MDLEQ = 88;
	const Sbecore::uint CALLWDBEGENMOD = 89;
	const Sbecore::uint CALLWDBEGENMOD_CLUEQ = 90;
	const Sbecore::uint CALLWDBEGENMOD_MDLEQ = 91;
	const Sbecore::uint CALLWDBEGENUPD_REFEQ = 92;
	const Sbecore::uint CALLWDBEHUSRRUNVMOD_CRDUSREQ = 93;
	const Sbecore::uint CALLWDBEIMBMOD = 94;
	const Sbecore::uint CALLWDBEIMBUPD_REFEQ = 95;
	const Sbecore::uint CALLWDBEINT_UNT_INSBS = 96;
	const Sbecore::uint CALLWDBEINT_UNTEQ = 97;
	const Sbecore::uint CALLWDBEINTMOD = 98;
	const Sbecore::uint CALLWDBEINTMOD_UNTEQ = 99;
	const Sbecore::uint CALLWDBEINTUPD_REFEQ = 100;
	const Sbecore::uint CALLWDBEINTVALPRESET = 101;
	const Sbecore::uint CALLWDBEIXPRESET = 102;
	const Sbecore::uint CALLWDBEKAKJKEYMOD_KLSAKEYEQ = 103;
	const Sbecore::uint CALLWDBEKLSAKEYMOD_KLSEQ = 104;
	const Sbecore::uint CALLWDBEKLSAKEYMOD_KLSMTBURFEQ = 105;
	const Sbecore::uint CALLWDBELIBAMKFMOD_LIBEQ = 106;
	const Sbecore::uint CALLWDBELIBAMKFMOD_MCHEQ = 107;
	const Sbecore::uint CALLWDBELIBMOD = 108;
	const Sbecore::uint CALLWDBELIBUPD_REFEQ = 109;
	const Sbecore::uint CALLWDBELOG = 110;
	const Sbecore::uint CALLWDBELOGOUT = 111;
	const Sbecore::uint CALLWDBEMCH_CCHEQ = 112;
	const Sbecore::uint CALLWDBEMCH_SUPEQ = 113;
	const Sbecore::uint CALLWDBEMCHAMKFMOD_MCHEQ = 114;
	const Sbecore::uint CALLWDBEMCHAPARMOD_MCHEQ = 115;
	const Sbecore::uint CALLWDBEMCHMOD = 116;
	const Sbecore::uint CALLWDBEMCHMOD_SUPEQ = 117;
	const Sbecore::uint CALLWDBEMCHUPD_REFEQ = 118;
	const Sbecore::uint CALLWDBEMDL_CTREQ = 119;
	const Sbecore::uint CALLWDBEMDL_HKTEQ = 120;
	const Sbecore::uint CALLWDBEMDL_HKU_INSBS = 121;
	const Sbecore::uint CALLWDBEMDL_HKUEQ = 122;
	const Sbecore::uint CALLWDBEMDL_IMBEQ = 123;
	const Sbecore::uint CALLWDBEMDL_INSBS = 124;
	const Sbecore::uint CALLWDBEMDL_SUP_INSBS = 125;
	const Sbecore::uint CALLWDBEMDL_SUPEQ = 126;
	const Sbecore::uint CALLWDBEMDL_TPLEQ = 127;
	const Sbecore::uint CALLWDBEMDL_TYPEQ = 128;
	const Sbecore::uint CALLWDBEMDLAPARMOD_MDLEQ = 129;
	const Sbecore::uint CALLWDBEMDLMOD = 130;
	const Sbecore::uint CALLWDBEMDLMOD_HKTHKUEQ = 131;
	const Sbecore::uint CALLWDBEMDLMOD_SUPEQ = 132;
	const Sbecore::uint CALLWDBEMDLMOD_TPLEQ = 133;
	const Sbecore::uint CALLWDBEMDLRMDLMOD_COREQ = 134;
	const Sbecore::uint CALLWDBEMDLRMDLMOD_CTDEQ = 135;
	const Sbecore::uint CALLWDBEMDLRPPHMOD_MDLEQ = 136;
	const Sbecore::uint CALLWDBEMDLRPPHMOD_PPHEQ = 137;
	const Sbecore::uint CALLWDBEMDLUPD_REFEQ = 138;
	const Sbecore::uint CALLWDBEMONSTATCHG = 139;
	const Sbecore::uint CALLWDBENODECHG = 140;
	const Sbecore::uint CALLWDBEPIN_BNKEQ = 141;
	const Sbecore::uint CALLWDBEPIN_CLUEQ = 142;
	const Sbecore::uint CALLWDBEPINAPARMOD_PINEQ = 143;
	const Sbecore::uint CALLWDBEPINJSRFMOD_PINEQ = 144;
	const Sbecore::uint CALLWDBEPINJSRFMOD_PPHEQ = 145;
	const Sbecore::uint CALLWDBEPINMOD = 146;
	const Sbecore::uint CALLWDBEPINMOD_BNKEQ = 147;
	const Sbecore::uint CALLWDBEPINMOD_CLUEQ = 148;
	const Sbecore::uint CALLWDBEPINUPD_REFEQ = 149;
	const Sbecore::uint CALLWDBEPPH_UNT_INSBS = 150;
	const Sbecore::uint CALLWDBEPPH_UNTEQ = 151;
	const Sbecore::uint CALLWDBEPPHAPARMOD_PPHEQ = 152;
	const Sbecore::uint CALLWDBEPPHMOD = 153;
	const Sbecore::uint CALLWDBEPPHMOD_UNTEQ = 154;
	const Sbecore::uint CALLWDBEPPHUPD_REFEQ = 155;
	const Sbecore::uint CALLWDBEPPL_HSM_INSBS = 156;
	const Sbecore::uint CALLWDBEPPL_HSMEQ = 157;
	const Sbecore::uint CALLWDBEPPLMOD = 158;
	const Sbecore::uint CALLWDBEPPLMOD_HSMEQ = 159;
	const Sbecore::uint CALLWDBEPPLUPD_REFEQ = 160;
	const Sbecore::uint CALLWDBEPRC_FSMEQ = 161;
	const Sbecore::uint CALLWDBEPRC_MDLEQ = 162;
	const Sbecore::uint CALLWDBEPRCMOD = 163;
	const Sbecore::uint CALLWDBEPRCMOD_MDLEQ = 164;
	const Sbecore::uint CALLWDBEPRCUPD_REFEQ = 165;
	const Sbecore::uint CALLWDBEPRJ_VEREQ = 166;
	const Sbecore::uint CALLWDBEPRJMOD = 167;
	const Sbecore::uint CALLWDBEPRJUPD_REFEQ = 168;
	const Sbecore::uint CALLWDBEPRSADETMOD_PRSEQ = 169;
	const Sbecore::uint CALLWDBEPRSJLNMMOD_PRSEQ = 170;
	const Sbecore::uint CALLWDBEPRSMOD = 171;
	const Sbecore::uint CALLWDBEPRSRPRJMOD_PRJEQ = 172;
	const Sbecore::uint CALLWDBEPRSRPRJMOD_PRSEQ = 173;
	const Sbecore::uint CALLWDBEPRSUPD_REFEQ = 174;
	const Sbecore::uint CALLWDBEPRT_CLUEQ = 175;
	const Sbecore::uint CALLWDBEPRT_MDL_INSBS = 176;
	const Sbecore::uint CALLWDBEPRT_MDLEQ = 177;
	const Sbecore::uint CALLWDBEPRTMOD = 178;
	const Sbecore::uint CALLWDBEPRTMOD_CLUEQ = 179;
	const Sbecore::uint CALLWDBEPRTMOD_MDLEQ = 180;
	const Sbecore::uint CALLWDBEPRTUPD_REFEQ = 181;
	const Sbecore::uint CALLWDBERECACCESS = 182;
	const Sbecore::uint CALLWDBEREFPRESET = 183;
	const Sbecore::uint CALLWDBEREFSPRESET = 184;
	const Sbecore::uint CALLWDBEREPTRSTART = 185;
	const Sbecore::uint CALLWDBEREPTRSTOP = 186;
	const Sbecore::uint CALLWDBERLS_CMPEQ = 187;
	const Sbecore::uint CALLWDBERLS_MCHEQ = 188;
	const Sbecore::uint CALLWDBERLSMOD = 189;
	const Sbecore::uint CALLWDBERLSMOD_CMPEQ = 190;
	const Sbecore::uint CALLWDBERLSMOD_MCHEQ = 191;
	const Sbecore::uint CALLWDBERLSUPD_REFEQ = 192;
	const Sbecore::uint CALLWDBESEG_CLUEQ = 193;
	const Sbecore::uint CALLWDBESEG_PPLEQ = 194;
	const Sbecore::uint CALLWDBESEG_SUPEQ = 195;
	const Sbecore::uint CALLWDBESEGMOD = 196;
	const Sbecore::uint CALLWDBESEGMOD_CLUEQ = 197;
	const Sbecore::uint CALLWDBESEGMOD_PPLEQ = 198;
	const Sbecore::uint CALLWDBESEGMOD_SUPEQ = 199;
	const Sbecore::uint CALLWDBESEGUPD_REFEQ = 200;
	const Sbecore::uint CALLWDBESESMOD = 201;
	const Sbecore::uint CALLWDBESESMOD_USREQ = 202;
	const Sbecore::uint CALLWDBESESUPD_REFEQ = 203;
	const Sbecore::uint CALLWDBESGECHG = 204;
	const Sbecore::uint CALLWDBESHRDATCHG = 205;
	const Sbecore::uint CALLWDBESIG_CLUEQ = 206;
	const Sbecore::uint CALLWDBESIG_DRVEQ = 207;
	const Sbecore::uint CALLWDBESIG_MGTEQ = 208;
	const Sbecore::uint CALLWDBESIG_MGU_INSBS = 209;
	const Sbecore::uint CALLWDBESIG_MGUEQ = 210;
	const Sbecore::uint CALLWDBESIG_RETEQ = 211;
	const Sbecore::uint CALLWDBESIG_REU_INSBS = 212;
	const Sbecore::uint CALLWDBESIG_REUEQ = 213;
	const Sbecore::uint CALLWDBESIG_VECEQ = 214;
	const Sbecore::uint CALLWDBESIGMOD = 215;
	const Sbecore::uint CALLWDBESIGMOD_CLUEQ = 216;
	const Sbecore::uint CALLWDBESIGMOD_MGTMGUEQ = 217;
	const Sbecore::uint CALLWDBESIGMOD_RETREUEQ = 218;
	const Sbecore::uint CALLWDBESIGUPD_REFEQ = 219;
	const Sbecore::uint CALLWDBESNS_RETEQ = 220;
	const Sbecore::uint CALLWDBESNS_REU_INSBS = 221;
	const Sbecore::uint CALLWDBESNS_REUEQ = 222;
	const Sbecore::uint CALLWDBESNS_SRTEQ = 223;
	const Sbecore::uint CALLWDBESNS_SRUEQ = 224;
	const Sbecore::uint CALLWDBESNSMOD = 225;
	const Sbecore::uint CALLWDBESNSMOD_RETREUEQ = 226;
	const Sbecore::uint CALLWDBESNSMOD_SRTSRUEQ = 227;
	const Sbecore::uint CALLWDBESNSUPD_REFEQ = 228;
	const Sbecore::uint CALLWDBESREFPRESET = 229;
	const Sbecore::uint CALLWDBESTATCHG = 230;
	const Sbecore::uint CALLWDBESTGCHG = 231;
	const Sbecore::uint CALLWDBESTUBCHG = 232;
	const Sbecore::uint CALLWDBESUSPSESS = 233;
	const Sbecore::uint CALLWDBETXTVALPRESET = 234;
	const Sbecore::uint CALLWDBEUNT_INSBS = 235;
	const Sbecore::uint CALLWDBEUNT_MDLEQ = 236;
	const Sbecore::uint CALLWDBEUNT_RETEQ = 237;
	const Sbecore::uint CALLWDBEUNT_REUEQ = 238;
	const Sbecore::uint CALLWDBEUNT_SILEQ = 239;
	const Sbecore::uint CALLWDBEUNTMOD = 240;
	const Sbecore::uint CALLWDBEUNTMOD_RETREUEQ = 241;
	const Sbecore::uint CALLWDBEUNTMOD_SILEQ = 242;
	const Sbecore::uint CALLWDBEUNTUPD_REFEQ = 243;
	const Sbecore::uint CALLWDBEUSGAACCMOD_USGEQ = 244;
	const Sbecore::uint CALLWDBEUSGMOD = 245;
	const Sbecore::uint CALLWDBEUSGUPD_REFEQ = 246;
	const Sbecore::uint CALLWDBEUSR_PRSEQ = 247;
	const Sbecore::uint CALLWDBEUSR_USGEQ = 248;
	const Sbecore::uint CALLWDBEUSRAACCMOD_USREQ = 249;
	const Sbecore::uint CALLWDBEUSRJSTEMOD_USREQ = 250;
	const Sbecore::uint CALLWDBEUSRMOD = 251;
	const Sbecore::uint CALLWDBEUSRRUSGMOD_USGEQ = 252;
	const Sbecore::uint CALLWDBEUSRRUSGMOD_USREQ = 253;
	const Sbecore::uint CALLWDBEUSRUPD_REFEQ = 254;
	const Sbecore::uint CALLWDBEVAR_CLUEQ = 255;
	const Sbecore::uint CALLWDBEVAR_RETEQ = 256;
	const Sbecore::uint CALLWDBEVAR_REU_INSBS = 257;
	const Sbecore::uint CALLWDBEVAR_REUEQ = 258;
	const Sbecore::uint CALLWDBEVARMOD = 259;
	const Sbecore::uint CALLWDBEVARMOD_CLUEQ = 260;
	const Sbecore::uint CALLWDBEVARUPD_REFEQ = 261;
	const Sbecore::uint CALLWDBEVEC_HKTEQ = 262;
	const Sbecore::uint CALLWDBEVEC_HKU_INSBS = 263;
	const Sbecore::uint CALLWDBEVEC_HKU_MDL_INSBS = 264;
	const Sbecore::uint CALLWDBEVEC_HKUEQ = 265;
	const Sbecore::uint CALLWDBEVECMOD = 266;
	const Sbecore::uint CALLWDBEVECMOD_HKTHKUEQ = 267;
	const Sbecore::uint CALLWDBEVECUPD_REFEQ = 268;
	const Sbecore::uint CALLWDBEVER_BVREQ = 269;
	const Sbecore::uint CALLWDBEVER_PRJEQ = 270;
	const Sbecore::uint CALLWDBEVER_STEEQ = 271;
	const Sbecore::uint CALLWDBEVERJSTEMOD_VEREQ = 272;
	const Sbecore::uint CALLWDBEVERMOD = 273;
	const Sbecore::uint CALLWDBEVERMOD_BVREQ = 274;
	const Sbecore::uint CALLWDBEVERMOD_PRJEQ = 275;
	const Sbecore::uint CALLWDBEVERUPD_REFEQ = 276;
	const Sbecore::uint CALLWDBEVIT_VECEQ = 277;
	const Sbecore::uint CALLWDBEVITMOD = 278;
	const Sbecore::uint CALLWDBEVITMOD_VECEQ = 279;
	const Sbecore::uint CALLWDBEVITUPD_REFEQ = 280;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
