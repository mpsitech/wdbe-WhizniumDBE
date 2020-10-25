# file Makefile
# make file for Wdbe operation daemon, release wdbeopd2_jack
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbswdbe -I$(SRCROOT)/wdbeopd2/VecWdbe -I$(SRCROOT)/wdbeopd2/IexWdbe -I$(SRCROOT)/wdbeopd2
INCPATH += -I$(SRCROOT)/wdbeopd2/WdbeMtpPlhfpga -I$(SRCROOT)/wdbeopd2/WdbeMtpPlhmcu -I$(SRCROOT)/wdbeopd2/WdbeMtpModbscbu -I$(SRCROOT)/wdbeopd2/WdbeMtpModbsctd -I$(SRCROOT)/wdbeopd2/WdbeMtpModdet -I$(SRCROOT)/wdbeopd2/WdbeMtpWrfpga -I$(SRCROOT)/wdbeopd2/WdbeMtpWrmcu
INCPATH += -I/usr/include -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql -I/usr/local/include

PCHS = Wdbeopd.h.gch

OBJS = Wdbe.o WdbeopdEngsrv.o WdbeopdOpprc.o Wdbeopd.o
OBJS += Wdbeopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wdbeopd2
LIBPATH += -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lwdbemtpplhfpga -lwdbemtpplhmcu -lwdbemtpmodbscbu -lwdbemtpmodbsctd -lwdbemtpmoddet -lwdbemtpwrfpga -lwdbemtpwrmcu
LIBS += -liexwdbe -lvecwdbe -ldbswdbe
LIBS += -lcurl -lmicrohttpd -lsbecore_my -lsbecore_pg
LIBS += -lmysqlclient -lpq -lsbecore_plus
LIBS += -lsbecore
LIBS += -lxml2
LIBS += -lz
LIBS += -lpthread

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

