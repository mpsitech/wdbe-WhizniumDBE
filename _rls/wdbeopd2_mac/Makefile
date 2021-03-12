# file Makefile
# make file for Wdbe operation daemon, release wdbeopd2_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 12 Mar 2021
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbswdbe -I$(BUILDROOT)/wdbeopd2/VecWdbe -I$(BUILDROOT)/wdbeopd2/IexWdbe -I$(BUILDROOT)/wdbeopd2
INCPATH += -I$(BUILDROOT)/wdbeopd2/WdbeMtpWrmcu -I$(BUILDROOT)/wdbeopd2/WdbeMtpWrfpga -I$(BUILDROOT)/wdbeopd2/WdbeMtpModdet -I$(BUILDROOT)/wdbeopd2/WdbeMtpModbsctd -I$(BUILDROOT)/wdbeopd2/WdbeMtpModbscbu -I$(BUILDROOT)/wdbeopd2/WdbeMtpPlhmcu -I$(BUILDROOT)/wdbeopd2/WdbeMtpPlhfpga
INCPATH += -I${WHIZSDKROOT}/build -I/usr/local/include -I/usr/local/include/curl -I/usr/local/include/libxml2 -I/usr/local/mysql/include

PCHS = Wdbeopd.h.gch

OBJS = Wdbe.o WdbeopdEngsrv.o WdbeopdOpprc.o Wdbeopd.o
OBJS += Wdbeopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wdbeopd2
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/local/lib -L/usr/local/mysql/lib

LIBS = -lwdbemtpwrmcu -lwdbemtpwrfpga -lwdbemtpmoddet -lwdbemtpmodbsctd -lwdbemtpmodbscbu -lwdbemtpplhmcu -lwdbemtpplhfpga
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
	rm -f *.o

pch:	$(PCHS)

install:
	mv $(EXE) $(BINROOT)/wdbeopd2/

clean:
	rm -f *.gch
	rm -f *.o
