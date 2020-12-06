# file Makefile
# make file for Wdbe operation daemon, release wdbeopd1_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 6 Dec 2020
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbswdbe -I$(BUILDROOT)/wdbeopd1/VecWdbe -I$(BUILDROOT)/wdbeopd1/IexWdbe -I$(BUILDROOT)/wdbeopd1
INCPATH += -I$(BUILDROOT)/wdbeopd1/WdbeWrmcu -I$(BUILDROOT)/wdbeopd1/WdbeWrfpga -I$(BUILDROOT)/wdbeopd1/WdbeWrdev -I$(BUILDROOT)/wdbeopd1/WdbePrctree -I$(BUILDROOT)/wdbeopd1/WdbePrcfile -I$(BUILDROOT)/wdbeopd1/WdbePlhmcu -I$(BUILDROOT)/wdbeopd1/WdbePlhfpga -I$(BUILDROOT)/wdbeopd1/WdbeModdet -I$(BUILDROOT)/wdbeopd1/WdbeModbsc
INCPATH += -I${WHIZSDKROOT}/build -I/usr/include -I/usr/include/libxml2 -I/usr/include/mariadb

PCHS = Wdbeopd.h.gch

OBJS = Wdbe.o WdbeopdEngsrv.o WdbeopdOpprc.o Wdbeopd.o
OBJS += Wdbeopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wdbeopd1
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/lib/x86_64-linux-gnu
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lwdbewrmcu -lwdbewrfpga -lwdbewrdev -lwdbeprctree -lwdbeprcfile -lwdbeplhmcu -lwdbeplhfpga -lwdbemoddet -lwdbemodbsc
LIBS += -liexwdbe -lvecwdbe -ldbswdbe
LIBS += -lcurl -lmicrohttpd -lsbecore_mar
LIBS += -lmariadbclient -lsbecore_plus
LIBS += -lsbecore
LIBS += -lxml2
LIBS += -lpthread

EXE = Wdbeopd1

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
	mv $(EXE) $(BINROOT)/wdbeopd1/

clean:
	rm -f *.gch
	rm -f *.o
