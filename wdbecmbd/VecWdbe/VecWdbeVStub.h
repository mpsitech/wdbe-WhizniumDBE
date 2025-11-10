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
	const Sbecore::uint STUBWDBECDCDSTD = 3;
	const Sbecore::uint STUBWDBECMDSTD = 4;
	const Sbecore::uint STUBWDBECMPSTD = 5;
	const Sbecore::uint STUBWDBECTRLONG = 6;
	const Sbecore::uint STUBWDBECTRSREF = 7;
	const Sbecore::uint STUBWDBECTRSTD = 8;
	const Sbecore::uint STUBWDBECPRSTD = 9;
	const Sbecore::uint STUBWDBECVRNO = 10;
	const Sbecore::uint STUBWDBECVRSTD = 11;
	const Sbecore::uint STUBWDBEERRSTD = 12;
	const Sbecore::uint STUBWDBEFAMSTD = 13;
	const Sbecore::uint STUBWDBEFILSTD = 14;
	const Sbecore::uint STUBWDBEFSMSTD = 15;
	const Sbecore::uint STUBWDBEFSTSTD = 16;
	const Sbecore::uint STUBWDBEGENSTD = 17;
	const Sbecore::uint STUBWDBEIMBSTD = 18;
	const Sbecore::uint STUBWDBEINTSTD = 19;
	const Sbecore::uint STUBWDBELIBSREF = 20;
	const Sbecore::uint STUBWDBELIBSTD = 21;
	const Sbecore::uint STUBWDBEMCHSREF = 22;
	const Sbecore::uint STUBWDBEMCHSTD = 23;
	const Sbecore::uint STUBWDBEMDLHSREF = 24;
	const Sbecore::uint STUBWDBEMDLSREF = 25;
	const Sbecore::uint STUBWDBEMDLSTD = 26;
	const Sbecore::uint STUBWDBEMODSTD = 27;
	const Sbecore::uint STUBWDBEMTPSTD = 28;
	const Sbecore::uint STUBWDBEPPHSTD = 29;
	const Sbecore::uint STUBWDBEPRSSTD = 30;
	const Sbecore::uint STUBWDBEPINSTD = 31;
	const Sbecore::uint STUBWDBEPPLSTD = 32;
	const Sbecore::uint STUBWDBEPRTSREF = 33;
	const Sbecore::uint STUBWDBEPRTSTD = 34;
	const Sbecore::uint STUBWDBEPRCSTD = 35;
	const Sbecore::uint STUBWDBEPRJSHORT = 36;
	const Sbecore::uint STUBWDBEPRJSTD = 37;
	const Sbecore::uint STUBWDBERLSSTD = 38;
	const Sbecore::uint STUBWDBESEGHSREF = 39;
	const Sbecore::uint STUBWDBESEGSREF = 40;
	const Sbecore::uint STUBWDBESEGSTD = 41;
	const Sbecore::uint STUBWDBESNSSTD = 42;
	const Sbecore::uint STUBWDBESESMENU = 43;
	const Sbecore::uint STUBWDBESESSTD = 44;
	const Sbecore::uint STUBWDBESIGSREF = 45;
	const Sbecore::uint STUBWDBESIGSTD = 46;
	const Sbecore::uint STUBWDBESILSTD = 47;
	const Sbecore::uint STUBWDBEUNISTD = 48;
	const Sbecore::uint STUBWDBEUNTSREF = 49;
	const Sbecore::uint STUBWDBEUNTSTD = 50;
	const Sbecore::uint STUBWDBEOWNER = 51;
	const Sbecore::uint STUBWDBEUSRPRS = 52;
	const Sbecore::uint STUBWDBEUSRSTD = 53;
	const Sbecore::uint STUBWDBEGROUP = 54;
	const Sbecore::uint STUBWDBEUSGSTD = 55;
	const Sbecore::uint STUBWDBEVARSTD = 56;
	const Sbecore::uint STUBWDBEVECSTD = 57;
	const Sbecore::uint STUBWDBEVITSTD = 58;
	const Sbecore::uint STUBWDBEVERNO = 59;
	const Sbecore::uint STUBWDBEVERSHORT = 60;
	const Sbecore::uint STUBWDBEVERSTD = 61;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
