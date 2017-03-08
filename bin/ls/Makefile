#	$OpenBSD: Makefile,v 1.8 2015/12/01 18:36:13 schwarze Exp $

.TOPDIR?=../..

PROG=	ls
SRCS=	cmp.c ls.c main.c print.c util.c utf8.c
DPADD= ${LIBUTIL}
LDADD= -lutil
CPPFLAGS+=-D_GNU_SOURCE

include ${.TOPDIR}/mk/bsd.prog.mk
