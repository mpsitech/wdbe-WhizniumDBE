# file Makefile
# make file for Wdbe operation daemon, release wdbeopd1_jack
# author Alexander Wirthmueller
# date created: 23 Aug 2020
# modified: 23 Aug 2020

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbswdbe -I$(SRCROOT)/wdbeopd1/VecWdbe -I$(SRCROOT)/wdbeopd1/IexWdbe -I$(SRCROOT)/wdbeopd1
INCPATH += -I$(SRCROOT)/wdbeopd1/WdbeModbsc -I$(SRCROOT)/wdbeopd1/WdbeModdet -I$(SRCROOT)/wdbeopd1/WdbePlhfpga -I$(SRCROOT)/wdbeopd1/WdbePlhmcu -I$(SRCROOT)/wdbeopd1/WdbePrcfile -I$(SRCROOT)/wdbeopd1/WdbePrctree -I$(SRCROOT)/wdbeopd1/WdbeWrdev -I$(SRCROOT)/wdbeopd1/WdbeWrfpga -I$(SRCROOT)/wdbeopd1/WdbeWrmcu
INCPATH += -I/usr/include -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql -I/usr/local/include

PCHS = Wdbeopd.h.gch

OBJS = Wdbe.o WdbeopdEngsrv.o WdbeopdOpprc.o Wdbeopd.o
OBJS += Wdbeopd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wdbeopd1
LIBPATH += -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lwdbemodbsc -lwdbemoddet -lwdbeplhfpga -lwdbeplhmcu -lwdbeprcfile -lwdbeprctree -lwdbewrdev -lwdbewrfpga -lwdbewrmcu
LIBS += -liexwdbe -lvecwdbe -ldbswdbe
LIBS += -lcurl -lmicrohttpd -lsbecore_my -lsbecore_pg
LIBS += -lmysqlclient -lpq -lsbecore_plus
LIBS += -lsbecore
LIBS += -lxml2
LIBS += -lz
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

