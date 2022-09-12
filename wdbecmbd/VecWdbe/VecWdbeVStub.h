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
	const Sbecore::uint STUBWDBEBNKSREF = 1;
	const Sbecore::uint STUBWDBEBNKSTD = 2;
	const Sbecore::uint STUBWDBECMDSTD = 3;
	const Sbecore::uint STUBWDBECTRLONG = 4;
	const Sbecore::uint STUBWDBECTRSREF = 5;
	const Sbecore::uint STUBWDBECTRSTD = 6;
	const Sbecore::uint STUBWDBECPRSTD = 7;
	const Sbecore::uint STUBWDBECVRNO = 8;
	const Sbecore::uint STUBWDBECVRSTD = 9;
	const Sbecore::uint STUBWDBEERRSTD = 10;
	const Sbecore::uint STUBWDBEFAMSTD = 11;
	const Sbecore::uint STUBWDBEFILSTD = 12;
	const Sbecore::uint STUBWDBEFSMSTD = 13;
	const Sbecore::uint STUBWDBEFSTSTD = 14;
	const Sbecore::uint STUBWDBEGENSTD = 15;
	const Sbecore::uint STUBWDBEIMBSTD = 16;
	const Sbecore::uint STUBWDBEINTSTD = 17;
	const Sbecore::uint STUBWDBELIBSREF = 18;
	const Sbecore::uint STUBWDBELIBSTD = 19;
	const Sbecore::uint STUBWDBEMCHSREF = 20;
	const Sbecore::uint STUBWDBEMCHSTD = 21;
	const Sbecore::uint STUBWDBEMDLHSREF = 22;
	const Sbecore::uint STUBWDBEMDLSREF = 23;
	const Sbecore::uint STUBWDBEMDLSTD = 24;
	const Sbecore::uint STUBWDBEMODSTD = 25;
	const Sbecore::uint STUBWDBEMTPSTD = 26;
	const Sbecore::uint STUBWDBEPPHSTD = 27;
	const Sbecore::uint STUBWDBEPRSSTD = 28;
	const Sbecore::uint STUBWDBEPINSTD = 29;
	const Sbecore::uint STUBWDBEPPLSTD = 30;
	const Sbecore::uint STUBWDBEPRTSREF = 31;
	const Sbecore::uint STUBWDBEPRTSTD = 32;
	const Sbecore::uint STUBWDBEPRCSTD = 33;
	const Sbecore::uint STUBWDBEPRJSHORT = 34;
	const Sbecore::uint STUBWDBEPRJSTD = 35;
	const Sbecore::uint STUBWDBERLSLONG = 36;
	const Sbecore::uint STUBWDBERLSSTD = 37;
	const Sbecore::uint STUBWDBESEGHSREF = 38;
	const Sbecore::uint STUBWDBESEGSREF = 39;
	const Sbecore::uint STUBWDBESEGSTD = 40;
	const Sbecore::uint STUBWDBESNSSTD = 41;
	const Sbecore::uint STUBWDBESESMENU = 42;
	const Sbecore::uint STUBWDBESESSTD = 43;
	const Sbecore::uint STUBWDBESIGSREF = 44;
	const Sbecore::uint STUBWDBESIGSTD = 45;
	const Sbecore::uint STUBWDBESYSSTD = 46;
	const Sbecore::uint STUBWDBETRGSREF = 47;
	const Sbecore::uint STUBWDBETRGSTD = 48;
	const Sbecore::uint STUBWDBESILSTD = 49;
	const Sbecore::uint STUBWDBEUNISTD = 50;
	const Sbecore::uint STUBWDBEUNTSREF = 51;
	const Sbecore::uint STUBWDBEUNTSTD = 52;
	const Sbecore::uint STUBWDBEOWNER = 53;
	const Sbecore::uint STUBWDBEUSRPRS = 54;
	const Sbecore::uint STUBWDBEUSRSTD = 55;
	const Sbecore::uint STUBWDBEGROUP = 56;
	const Sbecore::uint STUBWDBEUSGSTD = 57;
	const Sbecore::uint STUBWDBEVARSTD = 58;
	const Sbecore::uint STUBWDBEVECSTD = 59;
	const Sbecore::uint STUBWDBEVITSTD = 60;
	const Sbecore::uint STUBWDBEVERNO = 61;
	const Sbecore::uint STUBWDBEVERSHORT = 62;
	const Sbecore::uint STUBWDBEVERSTD = 63;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
