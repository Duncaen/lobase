# $OpenBSD: Makefile,v 1.3 2012/07/10 11:42:02 nicm Exp $

.TOPDIR?=../..

PROG=	cu
SRCS=	cu.c command.c error.c input.c xmodem.c

CDIAGFLAGS+= -Wall -W -Wno-unused-parameter

LDADD=  -levent
DPADD=  ${LIBEVENT}

include ${.TOPDIR}/mk/bsd.prog.mk
