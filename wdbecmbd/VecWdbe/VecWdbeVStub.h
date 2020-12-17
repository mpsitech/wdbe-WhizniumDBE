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
	const Sbecore::uint STUBWDBESILSTD = 1;
	const Sbecore::uint STUBWDBEUNISTD = 2;
	const Sbecore::uint STUBWDBEUNTSREF = 3;
	const Sbecore::uint STUBWDBEUNTSTD = 4;
	const Sbecore::uint STUBWDBEOWNER = 5;
	const Sbecore::uint STUBWDBEUSRPRS = 6;
	const Sbecore::uint STUBWDBEUSRSTD = 7;
	const Sbecore::uint STUBWDBEGROUP = 8;
	const Sbecore::uint STUBWDBEUSGSTD = 9;
	const Sbecore::uint STUBWDBEVARSTD = 10;
	const Sbecore::uint STUBWDBEVECSTD = 11;
	const Sbecore::uint STUBWDBEVITSTD = 12;
	const Sbecore::uint STUBWDBEVERNO = 13;
	const Sbecore::uint STUBWDBEVERSHORT = 14;
	const Sbecore::uint STUBWDBEVERSTD = 15;
	const Sbecore::uint STUBWDBETRGSREF = 16;
	const Sbecore::uint STUBWDBETRGSTD = 17;
	const Sbecore::uint STUBWDBEFSMSTD = 18;
	const Sbecore::uint STUBWDBEFSTSTD = 19;
	const Sbecore::uint STUBWDBEGENSTD = 20;
	const Sbecore::uint STUBWDBEIMBSTD = 21;
	const Sbecore::uint STUBWDBELIBSREF = 22;
	const Sbecore::uint STUBWDBELIBSTD = 23;
	const Sbecore::uint STUBWDBEMCHSREF = 24;
	const Sbecore::uint STUBWDBEMCHSTD = 25;
	const Sbecore::uint STUBWDBEMDLHSREF = 26;
	const Sbecore::uint STUBWDBEMDLSREF = 27;
	const Sbecore::uint STUBWDBEMDLSTD = 28;
	const Sbecore::uint STUBWDBEMODSTD = 29;
	const Sbecore::uint STUBWDBEMTPSTD = 30;
	const Sbecore::uint STUBWDBEPPHSTD = 31;
	const Sbecore::uint STUBWDBEPRSSTD = 32;
	const Sbecore::uint STUBWDBEPINSTD = 33;
	const Sbecore::uint STUBWDBEPRTSREF = 34;
	const Sbecore::uint STUBWDBEPRTSTD = 35;
	const Sbecore::uint STUBWDBEPRCSTD = 36;
	const Sbecore::uint STUBWDBEPRJSHORT = 37;
	const Sbecore::uint STUBWDBEPRJSTD = 38;
	const Sbecore::uint STUBWDBERLSLONG = 39;
	const Sbecore::uint STUBWDBERLSSTD = 40;
	const Sbecore::uint STUBWDBESESMENU = 41;
	const Sbecore::uint STUBWDBESESSTD = 42;
	const Sbecore::uint STUBWDBESIGSREF = 43;
	const Sbecore::uint STUBWDBESIGSTD = 44;
	const Sbecore::uint STUBWDBESYSSTD = 45;
	const Sbecore::uint STUBWDBEFAMSTD = 46;
	const Sbecore::uint STUBWDBEFILSTD = 47;
	const Sbecore::uint STUBWDBEERRSTD = 48;
	const Sbecore::uint STUBWDBECVRNO = 49;
	const Sbecore::uint STUBWDBECVRSTD = 50;
	const Sbecore::uint STUBWDBECPRSTD = 51;
	const Sbecore::uint STUBWDBEBNKSREF = 52;
	const Sbecore::uint STUBWDBEBNKSTD = 53;
	const Sbecore::uint STUBWDBECMDSTD = 54;
	const Sbecore::uint STUBWDBECTRLONG = 55;
	const Sbecore::uint STUBWDBECTRSREF = 56;
	const Sbecore::uint STUBWDBECTRSTD = 57;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
