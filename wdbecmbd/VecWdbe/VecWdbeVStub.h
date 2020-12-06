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
	const Sbecore::uint STUBWDBEFSMSTD = 1;
	const Sbecore::uint STUBWDBEFSTSTD = 2;
	const Sbecore::uint STUBWDBEGENSTD = 3;
	const Sbecore::uint STUBWDBEIMBSTD = 4;
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
	const Sbecore::uint STUBWDBEPRTSREF = 17;
	const Sbecore::uint STUBWDBEPRTSTD = 18;
	const Sbecore::uint STUBWDBEPRCSTD = 19;
	const Sbecore::uint STUBWDBEPRJSHORT = 20;
	const Sbecore::uint STUBWDBEPRJSTD = 21;
	const Sbecore::uint STUBWDBERLSLONG = 22;
	const Sbecore::uint STUBWDBERLSSTD = 23;
	const Sbecore::uint STUBWDBESESMENU = 24;
	const Sbecore::uint STUBWDBESESSTD = 25;
	const Sbecore::uint STUBWDBESIGSREF = 26;
	const Sbecore::uint STUBWDBESIGSTD = 27;
	const Sbecore::uint STUBWDBESYSSTD = 28;
	const Sbecore::uint STUBWDBETRGSREF = 29;
	const Sbecore::uint STUBWDBETRGSTD = 30;
	const Sbecore::uint STUBWDBESILSTD = 31;
	const Sbecore::uint STUBWDBEUNISTD = 32;
	const Sbecore::uint STUBWDBEUNTSREF = 33;
	const Sbecore::uint STUBWDBEUNTSTD = 34;
	const Sbecore::uint STUBWDBEOWNER = 35;
	const Sbecore::uint STUBWDBEUSRPRS = 36;
	const Sbecore::uint STUBWDBEUSRSTD = 37;
	const Sbecore::uint STUBWDBEGROUP = 38;
	const Sbecore::uint STUBWDBEUSGSTD = 39;
	const Sbecore::uint STUBWDBEVARSTD = 40;
	const Sbecore::uint STUBWDBEVECSTD = 41;
	const Sbecore::uint STUBWDBEVITSTD = 42;
	const Sbecore::uint STUBWDBEVERNO = 43;
	const Sbecore::uint STUBWDBEVERSHORT = 44;
	const Sbecore::uint STUBWDBEVERSTD = 45;
	const Sbecore::uint STUBWDBEFILSTD = 46;
	const Sbecore::uint STUBWDBEFAMSTD = 47;
	const Sbecore::uint STUBWDBEERRSTD = 48;
	const Sbecore::uint STUBWDBECVRNO = 49;
	const Sbecore::uint STUBWDBECVRSTD = 50;
	const Sbecore::uint STUBWDBECPRSTD = 51;
	const Sbecore::uint STUBWDBECTRLONG = 52;
	const Sbecore::uint STUBWDBECTRSREF = 53;
	const Sbecore::uint STUBWDBECTRSTD = 54;
	const Sbecore::uint STUBWDBECMDSTD = 55;
	const Sbecore::uint STUBWDBEBNKSREF = 56;
	const Sbecore::uint STUBWDBEBNKSTD = 57;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
