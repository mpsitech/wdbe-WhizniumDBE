/**
	* \file VecWdbeVCall.h
	* vector VecWdbeVCall (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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
	const Sbecore::uint CALLWDBECLAIMCHG = 7;
	const Sbecore::uint CALLWDBECMD_RETEQ = 8;
	const Sbecore::uint CALLWDBECMD_REU_INSBS = 9;
	const Sbecore::uint CALLWDBECMD_REU_MDL_INSBS = 10;
	const Sbecore::uint CALLWDBECMD_REUEQ = 11;
	const Sbecore::uint CALLWDBECMDAIPAMOD_CMDEQ = 12;
	const Sbecore::uint CALLWDBECMDARPAMOD_CMDEQ = 13;
	const Sbecore::uint CALLWDBECMDMOD = 14;
	const Sbecore::uint CALLWDBECMDMOD_RETREUEQ = 15;
	const Sbecore::uint CALLWDBECMDRCTRMOD_CMDEQ = 16;
	const Sbecore::uint CALLWDBECMDRCTRMOD_CTREQ = 17;
	const Sbecore::uint CALLWDBECMDUPD_REFEQ = 18;
	const Sbecore::uint CALLWDBECPR_CVREQ = 19;
	const Sbecore::uint CALLWDBECPRMOD = 20;
	const Sbecore::uint CALLWDBECPRRPRSMOD_CPREQ = 21;
	const Sbecore::uint CALLWDBECPRRPRSMOD_PRSEQ = 22;
	const Sbecore::uint CALLWDBECPRUPD_REFEQ = 23;
	const Sbecore::uint CALLWDBECRDACTIVE = 24;
	const Sbecore::uint CALLWDBECRDCLOSE = 25;
	const Sbecore::uint CALLWDBECRDOPEN = 26;
	const Sbecore::uint CALLWDBECTLAPARMOD_USREQ = 27;
	const Sbecore::uint CALLWDBECTR_CLREQ = 28;
	const Sbecore::uint CALLWDBECTR_FWD_INSBS = 29;
	const Sbecore::uint CALLWDBECTR_FWDEQ = 30;
	const Sbecore::uint CALLWDBECTR_MDL_INSBS = 31;
	const Sbecore::uint CALLWDBECTRMOD = 32;
	const Sbecore::uint CALLWDBECTRMOD_FWDEQ = 33;
	const Sbecore::uint CALLWDBECTRUPD_REFEQ = 34;
	const Sbecore::uint CALLWDBECVR_BCVEQ = 35;
	const Sbecore::uint CALLWDBECVR_CPREQ = 36;
	const Sbecore::uint CALLWDBECVRAIPXMOD_CVREQ = 37;
	const Sbecore::uint CALLWDBECVRAPLHMOD_CVREQ = 38;
	const Sbecore::uint CALLWDBECVRJSTEMOD_CVREQ = 39;
	const Sbecore::uint CALLWDBECVRMOD = 40;
	const Sbecore::uint CALLWDBECVRMOD_BCVEQ = 41;
	const Sbecore::uint CALLWDBECVRMOD_CPREQ = 42;
	const Sbecore::uint CALLWDBECVRUPD_REFEQ = 43;
	const Sbecore::uint CALLWDBEDATCHG = 44;
	const Sbecore::uint CALLWDBEDBLVALPRESET = 45;
	const Sbecore::uint CALLWDBEDLGCLOSE = 46;
	const Sbecore::uint CALLWDBEERR_RETEQ = 47;
	const Sbecore::uint CALLWDBEERR_REU_INSBS = 48;
	const Sbecore::uint CALLWDBEERR_REU_MDL_INSBS = 49;
	const Sbecore::uint CALLWDBEERR_REUEQ = 50;
	const Sbecore::uint CALLWDBEERRAPARMOD_ERREQ = 51;
	const Sbecore::uint CALLWDBEERRMOD = 52;
	const Sbecore::uint CALLWDBEERRMOD_RETREUEQ = 53;
	const Sbecore::uint CALLWDBEERRUPD_REFEQ = 54;
	const Sbecore::uint CALLWDBEFAMMOD = 55;
	const Sbecore::uint CALLWDBEFAMUPD_REFEQ = 56;
	const Sbecore::uint CALLWDBEFIL_CLUEQ = 57;
	const Sbecore::uint CALLWDBEFIL_RETEQ = 58;
	const Sbecore::uint CALLWDBEFIL_REUEQ = 59;
	const Sbecore::uint CALLWDBEFILMOD = 60;
	const Sbecore::uint CALLWDBEFILMOD_CLUEQ = 61;
	const Sbecore::uint CALLWDBEFILMOD_RETREUEQ = 62;
	const Sbecore::uint CALLWDBEFILUPD_REFEQ = 63;
	const Sbecore::uint CALLWDBEFSMMOD = 64;
	const Sbecore::uint CALLWDBEFSMUPD_REFEQ = 65;
	const Sbecore::uint CALLWDBEFST_CLUEQ = 66;
	const Sbecore::uint CALLWDBEFST_FSMEQ = 67;
	const Sbecore::uint CALLWDBEFSTASTPMOD_FSTEQ = 68;
	const Sbecore::uint CALLWDBEFSTMOD = 69;
	const Sbecore::uint CALLWDBEFSTMOD_CLUEQ = 70;
	const Sbecore::uint CALLWDBEFSTMOD_FSMEQ = 71;
	const Sbecore::uint CALLWDBEFSTUPD_REFEQ = 72;
	const Sbecore::uint CALLWDBEGEN_CLUEQ = 73;
	const Sbecore::uint CALLWDBEGEN_MDL_INSBS = 74;
	const Sbecore::uint CALLWDBEGEN_MDLEQ = 75;
	const Sbecore::uint CALLWDBEGENMOD = 76;
	const Sbecore::uint CALLWDBEGENMOD_CLUEQ = 77;
	const Sbecore::uint CALLWDBEGENMOD_MDLEQ = 78;
	const Sbecore::uint CALLWDBEGENUPD_REFEQ = 79;
	const Sbecore::uint CALLWDBEHUSRRUNVMOD_CRDUSREQ = 80;
	const Sbecore::uint CALLWDBEIMB_COREQ = 81;
	const Sbecore::uint CALLWDBEIMB_MDL_INSBS = 82;
	const Sbecore::uint CALLWDBEIMBMOD = 83;
	const Sbecore::uint CALLWDBEIMBMOD_COREQ = 84;
	const Sbecore::uint CALLWDBEIMBUPD_REFEQ = 85;
	const Sbecore::uint CALLWDBEINTVALPRESET = 86;
	const Sbecore::uint CALLWDBEIXPRESET = 87;
	const Sbecore::uint CALLWDBEKAKJKEYMOD_KLSAKEYEQ = 88;
	const Sbecore::uint CALLWDBEKLSAKEYMOD_KLSEQ = 89;
	const Sbecore::uint CALLWDBEKLSAKEYMOD_KLSMTBURFEQ = 90;
	const Sbecore::uint CALLWDBELIBAMKFMOD_LIBEQ = 91;
	const Sbecore::uint CALLWDBELIBAMKFMOD_MCHEQ = 92;
	const Sbecore::uint CALLWDBELIBMOD = 93;
	const Sbecore::uint CALLWDBELIBRVERMOD_LIBEQ = 94;
	const Sbecore::uint CALLWDBELIBRVERMOD_VEREQ = 95;
	const Sbecore::uint CALLWDBELIBUPD_REFEQ = 96;
	const Sbecore::uint CALLWDBELOG = 97;
	const Sbecore::uint CALLWDBELOGOUT = 98;
	const Sbecore::uint CALLWDBEMCH_CCHEQ = 99;
	const Sbecore::uint CALLWDBEMCHAMKFMOD_MCHEQ = 100;
	const Sbecore::uint CALLWDBEMCHAPARMOD_MCHEQ = 101;
	const Sbecore::uint CALLWDBEMCHMOD = 102;
	const Sbecore::uint CALLWDBEMCHUPD_REFEQ = 103;
	const Sbecore::uint CALLWDBEMDL_CTREQ = 104;
	const Sbecore::uint CALLWDBEMDL_HKTEQ = 105;
	const Sbecore::uint CALLWDBEMDL_HKU_INSBS = 106;
	const Sbecore::uint CALLWDBEMDL_HKUEQ = 107;
	const Sbecore::uint CALLWDBEMDL_IMBEQ = 108;
	const Sbecore::uint CALLWDBEMDL_INSBS = 109;
	const Sbecore::uint CALLWDBEMDL_SUP_INSBS = 110;
	const Sbecore::uint CALLWDBEMDL_SUPEQ = 111;
	const Sbecore::uint CALLWDBEMDL_TPLEQ = 112;
	const Sbecore::uint CALLWDBEMDL_TYPEQ = 113;
	const Sbecore::uint CALLWDBEMDLAPARMOD_MDLEQ = 114;
	const Sbecore::uint CALLWDBEMDLMOD = 115;
	const Sbecore::uint CALLWDBEMDLMOD_HKTHKUEQ = 116;
	const Sbecore::uint CALLWDBEMDLMOD_SUPEQ = 117;
	const Sbecore::uint CALLWDBEMDLMOD_TPLEQ = 118;
	const Sbecore::uint CALLWDBEMDLUPD_REFEQ = 119;
	const Sbecore::uint CALLWDBEMONSTATCHG = 120;
	const Sbecore::uint CALLWDBENODECHG = 121;
	const Sbecore::uint CALLWDBEPIN_BNKEQ = 122;
	const Sbecore::uint CALLWDBEPIN_CLUEQ = 123;
	const Sbecore::uint CALLWDBEPINAPARMOD_PINEQ = 124;
	const Sbecore::uint CALLWDBEPINJSRFMOD_PINEQ = 125;
	const Sbecore::uint CALLWDBEPINJSRFMOD_PPHEQ = 126;
	const Sbecore::uint CALLWDBEPINMOD = 127;
	const Sbecore::uint CALLWDBEPINMOD_BNKEQ = 128;
	const Sbecore::uint CALLWDBEPINMOD_CLUEQ = 129;
	const Sbecore::uint CALLWDBEPINUPD_REFEQ = 130;
	const Sbecore::uint CALLWDBEPPH_MDLEQ = 131;
	const Sbecore::uint CALLWDBEPPH_UNT_INSBS = 132;
	const Sbecore::uint CALLWDBEPPH_UNTEQ = 133;
	const Sbecore::uint CALLWDBEPPHAPARMOD_PPHEQ = 134;
	const Sbecore::uint CALLWDBEPPHMOD = 135;
	const Sbecore::uint CALLWDBEPPHMOD_MDLEQ = 136;
	const Sbecore::uint CALLWDBEPPHMOD_UNTEQ = 137;
	const Sbecore::uint CALLWDBEPPHUPD_REFEQ = 138;
	const Sbecore::uint CALLWDBEPRC_FSMEQ = 139;
	const Sbecore::uint CALLWDBEPRC_MDLEQ = 140;
	const Sbecore::uint CALLWDBEPRCMOD = 141;
	const Sbecore::uint CALLWDBEPRCMOD_MDLEQ = 142;
	const Sbecore::uint CALLWDBEPRCUPD_REFEQ = 143;
	const Sbecore::uint CALLWDBEPRJ_VEREQ = 144;
	const Sbecore::uint CALLWDBEPRJMOD = 145;
	const Sbecore::uint CALLWDBEPRJUPD_REFEQ = 146;
	const Sbecore::uint CALLWDBEPRSADETMOD_PRSEQ = 147;
	const Sbecore::uint CALLWDBEPRSJLNMMOD_PRSEQ = 148;
	const Sbecore::uint CALLWDBEPRSMOD = 149;
	const Sbecore::uint CALLWDBEPRSRPRJMOD_PRJEQ = 150;
	const Sbecore::uint CALLWDBEPRSRPRJMOD_PRSEQ = 151;
	const Sbecore::uint CALLWDBEPRSUPD_REFEQ = 152;
	const Sbecore::uint CALLWDBEPRT_CLUEQ = 153;
	const Sbecore::uint CALLWDBEPRT_MDL_INSBS = 154;
	const Sbecore::uint CALLWDBEPRT_MDLEQ = 155;
	const Sbecore::uint CALLWDBEPRTMOD = 156;
	const Sbecore::uint CALLWDBEPRTMOD_CLUEQ = 157;
	const Sbecore::uint CALLWDBEPRTMOD_MDLEQ = 158;
	const Sbecore::uint CALLWDBEPRTUPD_REFEQ = 159;
	const Sbecore::uint CALLWDBERECACCESS = 160;
	const Sbecore::uint CALLWDBEREFPRESET = 161;
	const Sbecore::uint CALLWDBEREFSPRESET = 162;
	const Sbecore::uint CALLWDBEREPTRSTART = 163;
	const Sbecore::uint CALLWDBEREPTRSTOP = 164;
	const Sbecore::uint CALLWDBERLS_MCHEQ = 165;
	const Sbecore::uint CALLWDBERLS_VEREQ = 166;
	const Sbecore::uint CALLWDBERLSMOD = 167;
	const Sbecore::uint CALLWDBERLSMOD_MCHEQ = 168;
	const Sbecore::uint CALLWDBERLSMOD_VEREQ = 169;
	const Sbecore::uint CALLWDBERLSUPD_REFEQ = 170;
	const Sbecore::uint CALLWDBESESMOD = 171;
	const Sbecore::uint CALLWDBESESMOD_USREQ = 172;
	const Sbecore::uint CALLWDBESESUPD_REFEQ = 173;
	const Sbecore::uint CALLWDBESGECHG = 174;
	const Sbecore::uint CALLWDBESHRDATCHG = 175;
	const Sbecore::uint CALLWDBESIG_CLUEQ = 176;
	const Sbecore::uint CALLWDBESIG_DRVEQ = 177;
	const Sbecore::uint CALLWDBESIG_MDLEQ = 178;
	const Sbecore::uint CALLWDBESIG_MGTEQ = 179;
	const Sbecore::uint CALLWDBESIG_MGU_INSBS = 180;
	const Sbecore::uint CALLWDBESIG_MGUEQ = 181;
	const Sbecore::uint CALLWDBESIG_VECEQ = 182;
	const Sbecore::uint CALLWDBESIGMOD = 183;
	const Sbecore::uint CALLWDBESIGMOD_CLUEQ = 184;
	const Sbecore::uint CALLWDBESIGMOD_MDLEQ = 185;
	const Sbecore::uint CALLWDBESIGMOD_MGTMGUEQ = 186;
	const Sbecore::uint CALLWDBESIGUPD_REFEQ = 187;
	const Sbecore::uint CALLWDBESREFPRESET = 188;
	const Sbecore::uint CALLWDBESTATCHG = 189;
	const Sbecore::uint CALLWDBESTGCHG = 190;
	const Sbecore::uint CALLWDBESTUBCHG = 191;
	const Sbecore::uint CALLWDBESUSPSESS = 192;
	const Sbecore::uint CALLWDBESYS_UNT_INSBS = 193;
	const Sbecore::uint CALLWDBESYS_UNTEQ = 194;
	const Sbecore::uint CALLWDBESYS_VEREQ = 195;
	const Sbecore::uint CALLWDBESYSMOD = 196;
	const Sbecore::uint CALLWDBESYSMOD_VEREQ = 197;
	const Sbecore::uint CALLWDBESYSUPD_REFEQ = 198;
	const Sbecore::uint CALLWDBETRG_SYSEQ = 199;
	const Sbecore::uint CALLWDBETRG_UNT_INSBS = 200;
	const Sbecore::uint CALLWDBETRG_UNTEQ = 201;
	const Sbecore::uint CALLWDBETRGMOD = 202;
	const Sbecore::uint CALLWDBETRGMOD_SYSEQ = 203;
	const Sbecore::uint CALLWDBETRGMOD_UNTEQ = 204;
	const Sbecore::uint CALLWDBETRGUPD_REFEQ = 205;
	const Sbecore::uint CALLWDBETXTVALPRESET = 206;
	const Sbecore::uint CALLWDBEUNT_INSBS = 207;
	const Sbecore::uint CALLWDBEUNT_MDLEQ = 208;
	const Sbecore::uint CALLWDBEUNT_RETEQ = 209;
	const Sbecore::uint CALLWDBEUNT_REUEQ = 210;
	const Sbecore::uint CALLWDBEUNT_SILEQ = 211;
	const Sbecore::uint CALLWDBEUNT_SYSEQ = 212;
	const Sbecore::uint CALLWDBEUNTMOD = 213;
	const Sbecore::uint CALLWDBEUNTMOD_RETREUEQ = 214;
	const Sbecore::uint CALLWDBEUNTMOD_SILEQ = 215;
	const Sbecore::uint CALLWDBEUNTUPD_REFEQ = 216;
	const Sbecore::uint CALLWDBEUSGAACCMOD_USGEQ = 217;
	const Sbecore::uint CALLWDBEUSGMOD = 218;
	const Sbecore::uint CALLWDBEUSGUPD_REFEQ = 219;
	const Sbecore::uint CALLWDBEUSR_PRSEQ = 220;
	const Sbecore::uint CALLWDBEUSR_USGEQ = 221;
	const Sbecore::uint CALLWDBEUSRAACCMOD_USREQ = 222;
	const Sbecore::uint CALLWDBEUSRJSTEMOD_USREQ = 223;
	const Sbecore::uint CALLWDBEUSRMOD = 224;
	const Sbecore::uint CALLWDBEUSRRUSGMOD_USGEQ = 225;
	const Sbecore::uint CALLWDBEUSRRUSGMOD_USREQ = 226;
	const Sbecore::uint CALLWDBEUSRUPD_REFEQ = 227;
	const Sbecore::uint CALLWDBEVAR_CLUEQ = 228;
	const Sbecore::uint CALLWDBEVARMOD = 229;
	const Sbecore::uint CALLWDBEVARMOD_CLUEQ = 230;
	const Sbecore::uint CALLWDBEVARMOD_PRCEQ = 231;
	const Sbecore::uint CALLWDBEVARUPD_REFEQ = 232;
	const Sbecore::uint CALLWDBEVEC_HKTEQ = 233;
	const Sbecore::uint CALLWDBEVEC_HKU_INSBS = 234;
	const Sbecore::uint CALLWDBEVEC_HKU_MDL_INSBS = 235;
	const Sbecore::uint CALLWDBEVEC_HKUEQ = 236;
	const Sbecore::uint CALLWDBEVECMOD = 237;
	const Sbecore::uint CALLWDBEVECMOD_HKTHKUEQ = 238;
	const Sbecore::uint CALLWDBEVECUPD_REFEQ = 239;
	const Sbecore::uint CALLWDBEVER_BVREQ = 240;
	const Sbecore::uint CALLWDBEVER_PRJEQ = 241;
	const Sbecore::uint CALLWDBEVER_STEEQ = 242;
	const Sbecore::uint CALLWDBEVERJSTEMOD_VEREQ = 243;
	const Sbecore::uint CALLWDBEVERMOD = 244;
	const Sbecore::uint CALLWDBEVERMOD_BVREQ = 245;
	const Sbecore::uint CALLWDBEVERMOD_PRJEQ = 246;
	const Sbecore::uint CALLWDBEVERUPD_REFEQ = 247;
	const Sbecore::uint CALLWDBEVIT_VECEQ = 248;
	const Sbecore::uint CALLWDBEVITMOD = 249;
	const Sbecore::uint CALLWDBEVITMOD_VECEQ = 250;
	const Sbecore::uint CALLWDBEVITUPD_REFEQ = 251;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

