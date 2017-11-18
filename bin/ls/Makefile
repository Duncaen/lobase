#	$OpenBSD: Makefile,v 1.8 2015/12/01 18:36:13 schwarze Exp $

.TOPDIR?=../..

PROG=	ls
SRCS=	cmp.c ls.c main.c print.c util.c utf8.c
DPADD=	${LIBUTIL}
LDADD=	-loutil -lrt

include ${.TOPDIR}/mk/bsd.prog.mk
