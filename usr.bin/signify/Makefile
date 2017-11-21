#	$OpenBSD: Makefile,v 1.12 2017/05/28 21:59:56 tedu Exp $

.TOPDIR?=../..

SRCS=	signify.c
SRCS+=	zsig.c
SRCS+=	fe25519.c sc25519.c
SRCS+=	mod_ed25519.c mod_ge25519.c
SRCS+=	crypto_api.c

PROG=	signify

LDADD=  -loutil
DPADD=  ${LIBUTIL}

COPTS+=	-Wall

include ${.TOPDIR}/mk/bsd.prog.mk
