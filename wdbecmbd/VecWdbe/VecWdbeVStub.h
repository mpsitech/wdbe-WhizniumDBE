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
	const Sbecore::uint STUBWDBEFSTSTD = 1;
	const Sbecore::uint STUBWDBEGENSTD = 2;
	const Sbecore::uint STUBWDBEIMBSTD = 3;
	const Sbecore::uint STUBWDBEINTSTD = 4;
	const Sbecore::uint STUBWDBELIBSREF = 5;
	const Sbecore::uint STUBWDBELIBSTD = 6;
	const Sbecore::uint STUBWDBEMCHSREF = 7;
	const Sbecore::uint STUBWDBEMCHSTD = 8;
	const Sbecore::uint STUBWDBEMDLHSREF = 9;
	const Sbecore::uint STUBWDBEMDLSREF = 10;
	const Sbecore::uint STUBWDBEMDLSTD = 11;
	const Sbecore::uint STUBWDBEMODSTD = 12;
	const Sbecore::uint STUBWDBEMTPSTD = 13;
	const Sbecore::uint STUBWDBEPPHSTD = 14;
	const Sbecore::uint STUBWDBEPRSSTD = 15;
	const Sbecore::uint STUBWDBEPINSTD = 16;
	const Sbecore::uint STUBWDBEPPLSTD = 17;
	const Sbecore::uint STUBWDBEPRTSREF = 18;
	const Sbecore::uint STUBWDBEPRTSTD = 19;
	const Sbecore::uint STUBWDBEPRCSTD = 20;
	const Sbecore::uint STUBWDBEPRJSHORT = 21;
	const Sbecore::uint STUBWDBEPRJSTD = 22;
	const Sbecore::uint STUBWDBERLSSTD = 23;
	const Sbecore::uint STUBWDBESEGHSREF = 24;
	const Sbecore::uint STUBWDBESEGSREF = 25;
	const Sbecore::uint STUBWDBESEGSTD = 26;
	const Sbecore::uint STUBWDBESNSSTD = 27;
	const Sbecore::uint STUBWDBESESMENU = 28;
	const Sbecore::uint STUBWDBESESSTD = 29;
	const Sbecore::uint STUBWDBESIGSREF = 30;
	const Sbecore::uint STUBWDBESIGSTD = 31;
	const Sbecore::uint STUBWDBESILSTD = 32;
	const Sbecore::uint STUBWDBEUNISTD = 33;
	const Sbecore::uint STUBWDBEUNTSREF = 34;
	const Sbecore::uint STUBWDBEUNTSTD = 35;
	const Sbecore::uint STUBWDBEOWNER = 36;
	const Sbecore::uint STUBWDBEUSRPRS = 37;
	const Sbecore::uint STUBWDBEUSRSTD = 38;
	const Sbecore::uint STUBWDBEGROUP = 39;
	const Sbecore::uint STUBWDBEUSGSTD = 40;
	const Sbecore::uint STUBWDBEVARSTD = 41;
	const Sbecore::uint STUBWDBEVECSTD = 42;
	const Sbecore::uint STUBWDBEVITSTD = 43;
	const Sbecore::uint STUBWDBEVERNO = 44;
	const Sbecore::uint STUBWDBEVERSHORT = 45;
	const Sbecore::uint STUBWDBEVERSTD = 46;
	const Sbecore::uint STUBWDBEFSMSTD = 47;
	const Sbecore::uint STUBWDBEFILSTD = 48;
	const Sbecore::uint STUBWDBEFAMSTD = 49;
	const Sbecore::uint STUBWDBEERRSTD = 50;
	const Sbecore::uint STUBWDBECVRNO = 51;
	const Sbecore::uint STUBWDBECVRSTD = 52;
	const Sbecore::uint STUBWDBECPRSTD = 53;
	const Sbecore::uint STUBWDBECTRLONG = 54;
	const Sbecore::uint STUBWDBECTRSREF = 55;
	const Sbecore::uint STUBWDBECTRSTD = 56;
	const Sbecore::uint STUBWDBECMPSTD = 57;
	const Sbecore::uint STUBWDBECMDSTD = 58;
	const Sbecore::uint STUBWDBECDCDSTD = 59;
	const Sbecore::uint STUBWDBEBNKSREF = 60;
	const Sbecore::uint STUBWDBEBNKSTD = 61;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
