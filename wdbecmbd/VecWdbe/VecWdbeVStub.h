/**
	* \file VecWdbeVStub.h
	* vector VecWdbeVStub (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef VECWDBEVSTUB_H
#define VECWDBEVSTUB_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVStub
	*/
namespace VecWdbeVStub {
	const Sbecore::uint STUBWDBEFAMSTD = 1;
	const Sbecore::uint STUBWDBEFILSTD = 2;
	const Sbecore::uint STUBWDBEFSMSTD = 3;
	const Sbecore::uint STUBWDBEFSTSTD = 4;
	const Sbecore::uint STUBWDBEGENSTD = 5;
	const Sbecore::uint STUBWDBEIMBSTD = 6;
	const Sbecore::uint STUBWDBEINTSTD = 7;
	const Sbecore::uint STUBWDBELIBSREF = 8;
	const Sbecore::uint STUBWDBELIBSTD = 9;
	const Sbecore::uint STUBWDBEMCHSREF = 10;
	const Sbecore::uint STUBWDBEMCHSTD = 11;
	const Sbecore::uint STUBWDBEMDLHSREF = 12;
	const Sbecore::uint STUBWDBEMDLSREF = 13;
	const Sbecore::uint STUBWDBEMDLSTD = 14;
	const Sbecore::uint STUBWDBEMODSTD = 15;
	const Sbecore::uint STUBWDBEMTPSTD = 16;
	const Sbecore::uint STUBWDBEPPHSTD = 17;
	const Sbecore::uint STUBWDBEPRSSTD = 18;
	const Sbecore::uint STUBWDBEPINSTD = 19;
	const Sbecore::uint STUBWDBEPPLSTD = 20;
	const Sbecore::uint STUBWDBEPRTSREF = 21;
	const Sbecore::uint STUBWDBEPRTSTD = 22;
	const Sbecore::uint STUBWDBEPRCSTD = 23;
	const Sbecore::uint STUBWDBEPRJSHORT = 24;
	const Sbecore::uint STUBWDBEPRJSTD = 25;
	const Sbecore::uint STUBWDBERLSLONG = 26;
	const Sbecore::uint STUBWDBERLSSTD = 27;
	const Sbecore::uint STUBWDBESEGHSREF = 28;
	const Sbecore::uint STUBWDBESEGSREF = 29;
	const Sbecore::uint STUBWDBESEGSTD = 30;
	const Sbecore::uint STUBWDBESNSSTD = 31;
	const Sbecore::uint STUBWDBESESMENU = 32;
	const Sbecore::uint STUBWDBESESSTD = 33;
	const Sbecore::uint STUBWDBESIGSREF = 34;
	const Sbecore::uint STUBWDBESIGSTD = 35;
	const Sbecore::uint STUBWDBESYSSTD = 36;
	const Sbecore::uint STUBWDBETRGSREF = 37;
	const Sbecore::uint STUBWDBETRGSTD = 38;
	const Sbecore::uint STUBWDBESILSTD = 39;
	const Sbecore::uint STUBWDBEUNISTD = 40;
	const Sbecore::uint STUBWDBEUNTSREF = 41;
	const Sbecore::uint STUBWDBEUNTSTD = 42;
	const Sbecore::uint STUBWDBEOWNER = 43;
	const Sbecore::uint STUBWDBEUSRPRS = 44;
	const Sbecore::uint STUBWDBEUSRSTD = 45;
	const Sbecore::uint STUBWDBEGROUP = 46;
	const Sbecore::uint STUBWDBEUSGSTD = 47;
	const Sbecore::uint STUBWDBEVARSTD = 48;
	const Sbecore::uint STUBWDBEVECSTD = 49;
	const Sbecore::uint STUBWDBEVITSTD = 50;
	const Sbecore::uint STUBWDBEVERNO = 51;
	const Sbecore::uint STUBWDBEVERSHORT = 52;
	const Sbecore::uint STUBWDBEVERSTD = 53;
	const Sbecore::uint STUBWDBEERRSTD = 54;
	const Sbecore::uint STUBWDBECVRNO = 55;
	const Sbecore::uint STUBWDBECVRSTD = 56;
	const Sbecore::uint STUBWDBECPRSTD = 57;
	const Sbecore::uint STUBWDBECTRLONG = 58;
	const Sbecore::uint STUBWDBECTRSREF = 59;
	const Sbecore::uint STUBWDBECTRSTD = 60;
	const Sbecore::uint STUBWDBECMDSTD = 61;
	const Sbecore::uint STUBWDBEBNKSREF = 62;
	const Sbecore::uint STUBWDBEBNKSTD = 63;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
