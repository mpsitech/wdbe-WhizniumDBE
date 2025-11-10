# file Makefile
# make file for Wdbe operation daemon, release wdbeopd2_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 5 Nov 2025
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbswdbe -I$(BUILDROOT)/wdbeopd2/VecWdbe -I$(BUILDROOT)/wdbeopd2/IexWdbe -I$(BUILDROOT)/wdbeopd2
INCPATH += -I$(BUILDROOT)/wdbeopd2/WdbeMtpPlhfpga -I$(BUILDROOT)/wdbeopd2/WdbeMtpPlhmcu -I$(BUILDROOT)/wdbeopd2/WdbeMtpCplmstbu -I$(BUILDROOT)/wdbeopd2/WdbeMtpCplmsttd -I$(BUILDROOT)/wdbeopd2/WdbeMtpGenfst -I$(BUILDROOT)/wdbeopd2/WdbeMtpWrfpga -I$(BUILDROOT)/wdbeopd2/WdbeMtpWrmcu
INCPATH += -I${WHIZSDKROOT}/build -I/opt/homebrew/include -I/opt/homebrew/opt/curl/include -I/opt/homebrew/opt/libmicrohttpd/include -I/opt/homebrew/opt/libxml2/include -I/usr/local/mysql/include

PCHS = Wdbeopd.h.gch

OBJS = Wdbe.o WdbeopdEngsrv.o WdbeopdOpprc.o Wdbeopd.o
OBJS += Wdbeopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wdbeopd2
LIBPATH += -L${WHIZSDKROOT}/lib -L/opt/homebrew/lib -L/opt/homebrew/opt/curl/lib -L/opt/homebrew/opt/libmicrohttpd/lib -L/opt/homebrew/opt/libxml2/include -L/usr/local/mysql/lib

LIBS = -lwdbemtpplhfpga -lwdbemtpplhmcu -lwdbemtpcplmstbu -lwdbemtpcplmsttd -lwdbemtpgenfst -lwdbemtpwrfpga -lwdbemtpwrmcu
LIBS += -liexwdbe -lvecwdbe -ldbswdbe
LIBS += -lcurl -lmicrohttpd -lsbecore_my
LIBS += -lmysqlclient -lsbecore_plus
LIBS += -lsbecore
LIBS += -ljsoncpp -lxml2

EXE = Wdbeopd2

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(PCHS) $(EXE)

$(EXE):	$(OBJS)
	$(LINK) $(LINKFLAGS) $(OBJS) $(LIBPATH) $(LIBS) -o $(EXE)

pch:	$(PCHS)

install:
	mv $(EXE) $(BINROOT)/wdbeopd2/

clean:
	rm -f *.gch
	rm -f *.o
