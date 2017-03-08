#	$OpenBSD: Makefile,v 1.5 2016/01/10 01:15:52 tb Exp $

.TOPDIR?=../..

PROG=	jot
CFLAGS+= -Wall
LDADD+=	-lm
DPADD+=	${LIBM}

include ${.TOPDIR}/mk/bsd.prog.mk
