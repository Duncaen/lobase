#	$OpenBSD: Makefile,v 1.7 2017/07/09 21:23:19 espie Exp $

.TOPDIR?=../..

PROG =	tsort

CDIAGFLAGS = -Wall -Wno-char-subscripts -Wstrict-prototypes -pedantic -W
DPADD += ${LIBUTIL}
LDADD += -loutil

include ${.TOPDIR}/mk/bsd.prog.mk
