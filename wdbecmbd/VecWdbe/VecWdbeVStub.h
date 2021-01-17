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
	const Sbecore::uint STUBWDBELIBSREF = 17;
	const Sbecore::uint STUBWDBELIBSTD = 18;
	const Sbecore::uint STUBWDBEMCHSREF = 19;
	const Sbecore::uint STUBWDBEMCHSTD = 20;
	const Sbecore::uint STUBWDBEMDLHSREF = 21;
	const Sbecore::uint STUBWDBEMDLSREF = 22;
	const Sbecore::uint STUBWDBEMDLSTD = 23;
	const Sbecore::uint STUBWDBEMODSTD = 24;
	const Sbecore::uint STUBWDBEMTPSTD = 25;
	const Sbecore::uint STUBWDBEPPHSTD = 26;
	const Sbecore::uint STUBWDBEPRSSTD = 27;
	const Sbecore::uint STUBWDBEPINSTD = 28;
	const Sbecore::uint STUBWDBEPRTSREF = 29;
	const Sbecore::uint STUBWDBEPRTSTD = 30;
	const Sbecore::uint STUBWDBEPRCSTD = 31;
	const Sbecore::uint STUBWDBEPRJSHORT = 32;
	const Sbecore::uint STUBWDBEPRJSTD = 33;
	const Sbecore::uint STUBWDBERLSLONG = 34;
	const Sbecore::uint STUBWDBERLSSTD = 35;
	const Sbecore::uint STUBWDBESESMENU = 36;
	const Sbecore::uint STUBWDBESESSTD = 37;
	const Sbecore::uint STUBWDBESIGSREF = 38;
	const Sbecore::uint STUBWDBESIGSTD = 39;
	const Sbecore::uint STUBWDBESYSSTD = 40;
	const Sbecore::uint STUBWDBETRGSREF = 41;
	const Sbecore::uint STUBWDBETRGSTD = 42;
	const Sbecore::uint STUBWDBESILSTD = 43;
	const Sbecore::uint STUBWDBEUNISTD = 44;
	const Sbecore::uint STUBWDBEUNTSREF = 45;
	const Sbecore::uint STUBWDBEUNTSTD = 46;
	const Sbecore::uint STUBWDBEOWNER = 47;
	const Sbecore::uint STUBWDBEUSRPRS = 48;
	const Sbecore::uint STUBWDBEUSRSTD = 49;
	const Sbecore::uint STUBWDBEGROUP = 50;
	const Sbecore::uint STUBWDBEUSGSTD = 51;
	const Sbecore::uint STUBWDBEVARSTD = 52;
	const Sbecore::uint STUBWDBEVECSTD = 53;
	const Sbecore::uint STUBWDBEVITSTD = 54;
	const Sbecore::uint STUBWDBEVERNO = 55;
	const Sbecore::uint STUBWDBEVERSHORT = 56;
	const Sbecore::uint STUBWDBEVERSTD = 57;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif
