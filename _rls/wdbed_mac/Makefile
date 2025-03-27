# file Makefile
# make file for Wdbe daemon, release wdbed_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 3 Mar 2025
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWDBED

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbswdbe -I$(BUILDROOT)/wdbed/VecWdbe -I$(BUILDROOT)/wdbed/IexWdbe -I$(BUILDROOT)/wdbed
INCPATH += -I$(BUILDROOT)/wdbed/CrdWdbeUsg -I$(BUILDROOT)/wdbed/CrdWdbeUsr -I$(BUILDROOT)/wdbed/CrdWdbePrs -I$(BUILDROOT)/wdbed/CrdWdbeFil -I$(BUILDROOT)/wdbed/CrdWdbePrf -I$(BUILDROOT)/wdbed/CrdWdbeNav -I$(BUILDROOT)/wdbed/CrdWdbeMch -I$(BUILDROOT)/wdbed/CrdWdbeLib -I$(BUILDROOT)/wdbed/CrdWdbeFam -I$(BUILDROOT)/wdbed/CrdWdbeSil -I$(BUILDROOT)/wdbed/CrdWdbeMtp -I$(BUILDROOT)/wdbed/CrdWdbePrj -I$(BUILDROOT)/wdbed/CrdWdbeVer -I$(BUILDROOT)/wdbed/CrdWdbeUnt -I$(BUILDROOT)/wdbed/CrdWdbeCpr -I$(BUILDROOT)/wdbed/CrdWdbeCvr -I$(BUILDROOT)/wdbed/CrdWdbePph -I$(BUILDROOT)/wdbed/CrdWdbeMod -I$(BUILDROOT)/wdbed/CrdWdbeVec -I$(BUILDROOT)/wdbed/CrdWdbeVit -I$(BUILDROOT)/wdbed/CrdWdbeCmd -I$(BUILDROOT)/wdbed/CrdWdbeErr -I$(BUILDROOT)/wdbed/CrdWdbePpl -I$(BUILDROOT)/wdbed/CrdWdbeSeg -I$(BUILDROOT)/wdbed/CrdWdbeBnk -I$(BUILDROOT)/wdbed/CrdWdbePin -I$(BUILDROOT)/wdbed/CrdWdbeInt -I$(BUILDROOT)/wdbed/CrdWdbeSns -I$(BUILDROOT)/wdbed/CrdWdbeVar -I$(BUILDROOT)/wdbed/CrdWdbeGen -I$(BUILDROOT)/wdbed/CrdWdbePrt -I$(BUILDROOT)/wdbed/CrdWdbeSig -I$(BUILDROOT)/wdbed/CrdWdbeCdc -I$(BUILDROOT)/wdbed/CrdWdbePrc -I$(BUILDROOT)/wdbed/CrdWdbeFst -I$(BUILDROOT)/wdbed/CrdWdbeCmp -I$(BUILDROOT)/wdbed/CrdWdbeRls -I$(BUILDROOT)/wdbed/CrdWdbeUtl
INCPATH += -I${WHIZSDKROOT}/build -I${WHIZSDKROOT}/build/apiwzlm -I/opt/homebrew/include -I/opt/homebrew/opt/curl/include -I/opt/homebrew/opt/libgit2/include -I/opt/homebrew/opt/libmicrohttpd/include -I/opt/homebrew/opt/libxml2/include -I/opt/homebrew/opt/openssl@3/include -I/opt/homebrew/opt/sqlite3/include -I/usr/local/mysql/include

PCHS = Wdbed.h.gch

OBJS = Wdbe.o WdbedAppsrv.o WdbedJobprc.o WdbedOpprc.o WdbedOpengcli.o WdbedOpengsrv.o Wdbed.o
OBJS += RootWdbe.o SessWdbe.o JobWdbeLicense.o
OBJS += WdbeWrdev_blks.o SqkWdbeWrdev.o WdbePrctree_blks.o SqkWdbePrctree.o WdbePrcfile_blks.o SqkWdbePrcfile.o WdbePlhmcu_blks.o SqkWdbePlhmcu.o WdbePlhfpga_blks.o SqkWdbePlhfpga.o WdbeMtpWrmcu_blks.o SqkWdbeMtpWrmcu.o WdbeMtpWrfpga_blks.o SqkWdbeMtpWrfpga.o WdbeMtpGenfst_blks.o SqkWdbeMtpGenfst.o WdbeMtpCplmsttd_blks.o SqkWdbeMtpCplmsttd.o WdbeMtpCplmstbu_blks.o SqkWdbeMtpCplmstbu.o WdbeMtpPlhmcu_blks.o SqkWdbeMtpPlhmcu.o WdbeMtpPlhfpga_blks.o SqkWdbeMtpPlhfpga.o WdbeGenfst_blks.o SqkWdbeGenfst.o WdbeGen_blks.o SqkWdbeGen.o WdbeCplmst_blks.o SqkWdbeCplmst.o WdbeWrfpga_blks.o SqkWdbeWrfpga.o WdbeWrmcu_blks.o SqkWdbeWrmcu.o WdbeWrterm_blks.o SqkWdbeWrterm.o
OBJS += Wdbed_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wdbed
LIBPATH += -L${WHIZSDKROOT}/lib -L/opt/homebrew/lib -L/opt/homebrew/opt/curl/lib -L/opt/homebrew/opt/libgit2/lib -L/opt/homebrew/opt/libmicrohttpd/lib -L/opt/homebrew/opt/libxml2/include -L/opt/homebrew/opt/openssl@3/lib -L/opt/homebrew/opt/sqlite3/lib -L/usr/local/mysql/lib

LIBS = -lcrdwdbeusg -lcrdwdbeusr -lcrdwdbeprs -lcrdwdbefil -lcrdwdbeprf -lcrdwdbenav -lcrdwdbemch -lcrdwdbelib -lcrdwdbefam -lcrdwdbesil -lcrdwdbemtp -lcrdwdbeprj -lcrdwdbever -lcrdwdbeunt -lcrdwdbecpr -lcrdwdbecvr -lcrdwdbepph -lcrdwdbemod -lcrdwdbevec -lcrdwdbevit -lcrdwdbecmd -lcrdwdbeerr -lcrdwdbeppl -lcrdwdbeseg -lcrdwdbebnk -lcrdwdbepin -lcrdwdbeint -lcrdwdbesns -lcrdwdbevar -lcrdwdbegen -lcrdwdbeprt -lcrdwdbesig -lcrdwdbecdc -lcrdwdbeprc -lcrdwdbefst -lcrdwdbecmp -lcrdwdberls -lcrdwdbeutl
LIBS += -liexwdbe -lvecwdbe -ldbswdbe
LIBS += -lapiwzlm -lcurl -lgit2 -lmicrohttpd -lsbecore_dbsmon -lsbecore_mon
LIBS += -ldbswzem
LIBS += -lsbecore_lite -lsbecore_my
LIBS += -lmysqlclient -lsbecore_plus -lsqlite3 -lssl
LIBS += -lcrypto -lsbecore
LIBS += -ljsoncpp -lxml2

EXE = Wdbed

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
	mv $(EXE) $(BINROOT)/wdbed/

clean:
	rm -f *.gch
	rm -f *.o
