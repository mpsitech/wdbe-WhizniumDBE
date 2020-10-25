/**
	* \file VecWdbeVStub.h
	* vector VecWdbeVStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

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
	const Sbecore::uint STUBWDBEMCHSTD = 19;
	const Sbecore::uint STUBWDBEMDLHSREF = 20;
	const Sbecore::uint STUBWDBEMDLSREF = 21;
	const Sbecore::uint STUBWDBEMDLSTD = 22;
	const Sbecore::uint STUBWDBEMODSTD = 23;
	const Sbecore::uint STUBWDBEMTPSTD = 24;
	const Sbecore::uint STUBWDBEPPHSTD = 25;
	const Sbecore::uint STUBWDBEPRSSTD = 26;
	const Sbecore::uint STUBWDBEPINSTD = 27;
	const Sbecore::uint STUBWDBEPRTSREF = 28;
	const Sbecore::uint STUBWDBEPRTSTD = 29;
	const Sbecore::uint STUBWDBEPRCSTD = 30;
	const Sbecore::uint STUBWDBEPRJSHORT = 31;
	const Sbecore::uint STUBWDBEPRJSTD = 32;
	const Sbecore::uint STUBWDBERLSLONG = 33;
	const Sbecore::uint STUBWDBERLSSTD = 34;
	const Sbecore::uint STUBWDBESESMENU = 35;
	const Sbecore::uint STUBWDBESESSTD = 36;
	const Sbecore::uint STUBWDBESIGSREF = 37;
	const Sbecore::uint STUBWDBESIGSTD = 38;
	const Sbecore::uint STUBWDBESYSSTD = 39;
	const Sbecore::uint STUBWDBETRGSREF = 40;
	const Sbecore::uint STUBWDBETRGSTD = 41;
	const Sbecore::uint STUBWDBESILSTD = 42;
	const Sbecore::uint STUBWDBEUNISTD = 43;
	const Sbecore::uint STUBWDBEUNTSREF = 44;
	const Sbecore::uint STUBWDBEUNTSTD = 45;
	const Sbecore::uint STUBWDBEOWNER = 46;
	const Sbecore::uint STUBWDBEUSRPRS = 47;
	const Sbecore::uint STUBWDBEUSRSTD = 48;
	const Sbecore::uint STUBWDBEGROUP = 49;
	const Sbecore::uint STUBWDBEUSGSTD = 50;
	const Sbecore::uint STUBWDBEVARSTD = 51;
	const Sbecore::uint STUBWDBEVECSTD = 52;
	const Sbecore::uint STUBWDBEVITSTD = 53;
	const Sbecore::uint STUBWDBEVERNO = 54;
	const Sbecore::uint STUBWDBEVERSHORT = 55;
	const Sbecore::uint STUBWDBEVERSTD = 56;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

