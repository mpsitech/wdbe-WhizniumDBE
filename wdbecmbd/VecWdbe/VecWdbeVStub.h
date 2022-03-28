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
	const Sbecore::uint STUBWDBEVERNO = 1;
	const Sbecore::uint STUBWDBEVERSHORT = 2;
	const Sbecore::uint STUBWDBEVERSTD = 3;
	const Sbecore::uint STUBWDBEVITSTD = 4;
	const Sbecore::uint STUBWDBEVECSTD = 5;
	const Sbecore::uint STUBWDBEVARSTD = 6;
	const Sbecore::uint STUBWDBEGROUP = 7;
	const Sbecore::uint STUBWDBEUSGSTD = 8;
	const Sbecore::uint STUBWDBEOWNER = 9;
	const Sbecore::uint STUBWDBEUSRPRS = 10;
	const Sbecore::uint STUBWDBEUSRSTD = 11;
	const Sbecore::uint STUBWDBESILSTD = 12;
	const Sbecore::uint STUBWDBEUNISTD = 13;
	const Sbecore::uint STUBWDBEUNTSREF = 14;
	const Sbecore::uint STUBWDBEUNTSTD = 15;
	const Sbecore::uint STUBWDBETRGSREF = 16;
	const Sbecore::uint STUBWDBETRGSTD = 17;
	const Sbecore::uint STUBWDBESYSSTD = 18;
	const Sbecore::uint STUBWDBESIGSREF = 19;
	const Sbecore::uint STUBWDBESIGSTD = 20;
	const Sbecore::uint STUBWDBESESMENU = 21;
	const Sbecore::uint STUBWDBESESSTD = 22;
	const Sbecore::uint STUBWDBESNSSTD = 23;
	const Sbecore::uint STUBWDBESEGHSREF = 24;
	const Sbecore::uint STUBWDBESEGSREF = 25;
	const Sbecore::uint STUBWDBESEGSTD = 26;
	const Sbecore::uint STUBWDBEPRJSHORT = 27;
	const Sbecore::uint STUBWDBEPRJSTD = 28;
	const Sbecore::uint STUBWDBERLSLONG = 29;
	const Sbecore::uint STUBWDBERLSSTD = 30;
	const Sbecore::uint STUBWDBEPRCSTD = 31;
	const Sbecore::uint STUBWDBEPRTSREF = 32;
	const Sbecore::uint STUBWDBEPRTSTD = 33;
	const Sbecore::uint STUBWDBEPPLSTD = 34;
	const Sbecore::uint STUBWDBEPINSTD = 35;
	const Sbecore::uint STUBWDBEPRSSTD = 36;
	const Sbecore::uint STUBWDBEPPHSTD = 37;
	const Sbecore::uint STUBWDBEMDLHSREF = 38;
	const Sbecore::uint STUBWDBEMDLSREF = 39;
	const Sbecore::uint STUBWDBEMDLSTD = 40;
	const Sbecore::uint STUBWDBEMODSTD = 41;
	const Sbecore::uint STUBWDBEMTPSTD = 42;
	const Sbecore::uint STUBWDBEMCHSREF = 43;
	const Sbecore::uint STUBWDBEMCHSTD = 44;
	const Sbecore::uint STUBWDBELIBSREF = 45;
	const Sbecore::uint STUBWDBELIBSTD = 46;
	const Sbecore::uint STUBWDBEGENSTD = 47;
	const Sbecore::uint STUBWDBEIMBSTD = 48;
	const Sbecore::uint STUBWDBEINTSTD = 49;
	const Sbecore::uint STUBWDBEFAMSTD = 50;
	const Sbecore::uint STUBWDBEFILSTD = 51;
	const Sbecore::uint STUBWDBEFSMSTD = 52;
	const Sbecore::uint STUBWDBEFSTSTD = 53;
	const Sbecore::uint STUBWDBEERRSTD = 54;
	const Sbecore::uint STUBWDBECVRNO = 55;
	const Sbecore::uint STUBWDBECVRSTD = 56;
	const Sbecore::uint STUBWDBEBNKSREF = 57;
	const Sbecore::uint STUBWDBEBNKSTD = 58;
	const Sbecore::uint STUBWDBECMDSTD = 59;
	const Sbecore::uint STUBWDBECTRLONG = 60;
	const Sbecore::uint STUBWDBECTRSREF = 61;
	const Sbecore::uint STUBWDBECTRSTD = 62;
	const Sbecore::uint STUBWDBECPRSTD = 63;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
