/**
	* \file VecWdbeVStub.h
	* vector VecWdbeVStub (declarations)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifndef VECWDBEVSTUB_H
#define VECWDBEVSTUB_H

#include <sbecore/Xmlio.h>

/**
	* VecWdbeVStub
	*/
namespace VecWdbeVStub {
	const Sbecore::uint STUBWDBEVERNO = 1;
	const Sbecore::uint STUBWDBEVERSTD = 2;
	const Sbecore::uint STUBWDBEVECSTD = 3;
	const Sbecore::uint STUBWDBEVITSTD = 4;
	const Sbecore::uint STUBWDBEVARSTD = 5;
	const Sbecore::uint STUBWDBEGROUP = 6;
	const Sbecore::uint STUBWDBEUSGSTD = 7;
	const Sbecore::uint STUBWDBEOWNER = 8;
	const Sbecore::uint STUBWDBEUSRPRS = 9;
	const Sbecore::uint STUBWDBEUSRSTD = 10;
	const Sbecore::uint STUBWDBESILSTD = 11;
	const Sbecore::uint STUBWDBEUNISTD = 12;
	const Sbecore::uint STUBWDBEUNTSREF = 13;
	const Sbecore::uint STUBWDBEUNTSTD = 14;
	const Sbecore::uint STUBWDBETRGSREF = 15;
	const Sbecore::uint STUBWDBETRGSTD = 16;
	const Sbecore::uint STUBWDBESYSSTD = 17;
	const Sbecore::uint STUBWDBESIGSREF = 18;
	const Sbecore::uint STUBWDBESIGSTD = 19;
	const Sbecore::uint STUBWDBESESMENU = 20;
	const Sbecore::uint STUBWDBESESSTD = 21;
	const Sbecore::uint STUBWDBERLSLONG = 22;
	const Sbecore::uint STUBWDBERLSSTD = 23;
	const Sbecore::uint STUBWDBEPRJSTD = 24;
	const Sbecore::uint STUBWDBEPRCSTD = 25;
	const Sbecore::uint STUBWDBEPRTSREF = 26;
	const Sbecore::uint STUBWDBEPRTSTD = 27;
	const Sbecore::uint STUBWDBEPINSTD = 28;
	const Sbecore::uint STUBWDBEPRSSTD = 29;
	const Sbecore::uint STUBWDBEPPHSTD = 30;
	const Sbecore::uint STUBWDBEMDLHSREF = 31;
	const Sbecore::uint STUBWDBEMDLSREF = 32;
	const Sbecore::uint STUBWDBEMDLSTD = 33;
	const Sbecore::uint STUBWDBEMODSTD = 34;
	const Sbecore::uint STUBWDBEMTPSTD = 35;
	const Sbecore::uint STUBWDBEMCHSTD = 36;
	const Sbecore::uint STUBWDBELIBSREF = 37;
	const Sbecore::uint STUBWDBELIBSTD = 38;
	const Sbecore::uint STUBWDBEIMBSTD = 39;
	const Sbecore::uint STUBWDBEGENSTD = 40;
	const Sbecore::uint STUBWDBEFSTSTD = 41;
	const Sbecore::uint STUBWDBEFSMSTD = 42;
	const Sbecore::uint STUBWDBEFILSTD = 43;
	const Sbecore::uint STUBWDBEFAMSTD = 44;
	const Sbecore::uint STUBWDBEERRSTD = 45;
	const Sbecore::uint STUBWDBECVRNO = 46;
	const Sbecore::uint STUBWDBECVRSTD = 47;
	const Sbecore::uint STUBWDBECPRSTD = 48;
	const Sbecore::uint STUBWDBECTRLONG = 49;
	const Sbecore::uint STUBWDBECTRSREF = 50;
	const Sbecore::uint STUBWDBECTRSTD = 51;
	const Sbecore::uint STUBWDBECMDSTD = 52;
	const Sbecore::uint STUBWDBEBNKSREF = 53;
	const Sbecore::uint STUBWDBEBNKSTD = 54;

	Sbecore::uint getIx(const std::string& sref);
	std::string getSref(const Sbecore::uint ix);
};

#endif

