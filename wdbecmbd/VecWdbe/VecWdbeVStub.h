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
	const Sbecore::uint STUBWDBEOWNER = 5;
	const Sbecore::uint STUBWDBEUSRPRS = 6;
	const Sbecore::uint STUBWDBEUSRSTD = 7;
	const Sbecore::uint STUBWDBESIGSREF = 8;
	const Sbecore::uint STUBWDBESIGSTD = 9;
	const Sbecore::uint STUBWDBESESMENU = 10;
	const Sbecore::uint STUBWDBESESSTD = 11;
	const Sbecore::uint STUBWDBESNSSTD = 12;
	const Sbecore::uint STUBWDBESEGHSREF = 13;
	const Sbecore::uint STUBWDBESEGSREF = 14;
	const Sbecore::uint STUBWDBESEGSTD = 15;
	const Sbecore::uint STUBWDBERLSSTD = 16;
	const Sbecore::uint STUBWDBEPRJSHORT = 17;
	const Sbecore::uint STUBWDBEPRJSTD = 18;
	const Sbecore::uint STUBWDBEPRCSTD = 19;
	const Sbecore::uint STUBWDBEPRTSREF = 20;
	const Sbecore::uint STUBWDBEPRTSTD = 21;
	const Sbecore::uint STUBWDBEPPLSTD = 22;
	const Sbecore::uint STUBWDBEPINSTD = 23;
	const Sbecore::uint STUBWDBEMCHSREF = 24;
	const Sbecore::uint STUBWDBEMCHSTD = 25;
	const Sbecore::uint STUBWDBEPRSSTD = 26;
	const Sbecore::uint STUBWDBEPPHSTD = 27;
	const Sbecore::uint STUBWDBEMDLHSREF = 28;
	const Sbecore::uint STUBWDBEMDLSREF = 29;
	const Sbecore::uint STUBWDBEMDLSTD = 30;
	const Sbecore::uint STUBWDBEMODSTD = 31;
	const Sbecore::uint STUBWDBEMTPSTD = 32;
	const Sbecore::uint STUBWDBEVECSTD = 33;
	const Sbecore::uint STUBWDBEVARSTD = 34;
	const Sbecore::uint STUBWDBEGROUP = 35;
	const Sbecore::uint STUBWDBEUSGSTD = 36;
	const Sbecore::uint STUBWDBESILSTD = 37;
	const Sbecore::uint STUBWDBEUNISTD = 38;
	const Sbecore::uint STUBWDBEUNTSREF = 39;
	const Sbecore::uint STUBWDBEUNTSTD = 40;
	const Sbecore::uint STUBWDBELIBSREF = 41;
	const Sbecore::uint STUBWDBELIBSTD = 42;
	const Sbecore::uint STUBWDBEINTSTD = 43;
	const Sbecore::uint STUBWDBEIMBSTD = 44;
	const Sbecore::uint STUBWDBEGENSTD = 45;
	const Sbecore::uint STUBWDBEFSTSTD = 46;
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
