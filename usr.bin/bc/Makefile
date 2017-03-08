#	$OpenBSD: Makefile,v 1.8 2015/10/10 19:28:54 deraadt Exp $

.TOPDIR?=../..

PROG=		bc
SRCS=		bc.y scan.l tty.c dc.c bcode.c inout.c mem.c stack.c
CPPFLAGS+=	-I. -I${.CURDIR}
CFLAGS+=	-Wall -Wno-unused
YFLAGS+=
LDADD+=		-ledit -lcurses -lcrypto
DPADD+=		${LIBEDIT} ${LIBCURSES} ${LIBCRYPTO}

# XXX: include add %/obj by default?
VPATH+=		${.CURDIR}/../dc

beforeinstall:
	install -c -o ${BINOWN} -g ${BINGRP} -m 444 ${.CURDIR}/bc.library \
	    ${DESTDIR}/usr/share/misc

# XXX: replace with make depends
scan.o : y.tab.h

include ${.TOPDIR}/mk/bsd.prog.mk
