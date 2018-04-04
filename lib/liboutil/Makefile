#	$OpenBSD: Makefile,v 1.40 2017/12/14 09:27:44 kettenis Exp $
#	$NetBSD: Makefile,v 1.8 1996/05/16 07:03:28 thorpej Exp $

.TOPDIR?=../..
.CURDIR?=.

LIB=	outil

VERSION_SCRIPT=	${.CURDIR}/Symbols.map

HDRS=	util.h imsg.h
SRCS=	bcrypt_pbkdf.c \
	logwtmp.c \
	uucplock.c fparseln.c pidfile.c \
	fmt_scaled.c imsg.c imsg-buffer.c pkcs5_pbkdf2.c

MAN=	bcrypt_pbkdf.3 \
	uucplock.3 \
	fparseln.3 pidfile.3 fmt_scaled.3 imsg_init.3 \
	pkcs5_pbkdf2.3

SRCS+=	ohash.c
HDRS += ohash.h

MAN +=	ohash_init.3 ohash_interval.3

includes:
	@cd ${.CURDIR}; for i in $(HDRS); do \
	    j="cmp -s $$i ${DESTDIR}/usr/include/$$i || \
		${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} \
		-m 444 $$i ${DESTDIR}/usr/include"; \
	    echo $$j; \
	    eval "$$j"; \
	done

include ${.TOPDIR}/mk/bsd.lib.mk
