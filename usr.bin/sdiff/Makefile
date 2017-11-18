#	$OpenBSD: Makefile,v 1.5 2017/09/05 06:27:38 otto Exp $

.TOPDIR?=../..

PROG=sdiff
SRCS=common.c edit.c sdiff.c
COPTS+=-Wall -Wextra -Wno-sign-compare

LDADD+=	-loutil
DPADD+=	${LIBUTIL}

include ${.TOPDIR}/mk/bsd.prog.mk
