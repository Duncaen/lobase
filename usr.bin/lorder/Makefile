#	$OpenBSD: Makefile,v 1.9 2011/11/08 10:37:10 guenther Exp $

.TOPDIR?=../..

MAN=	lorder.1

SCRIPT=	lorder.sh

realinstall:
	${INSTALL} ${INSTALL_COPY} -S -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
	    ${.CURDIR}/${SCRIPT} ${DESTDIR}${BINDIR}/lorder

include ${.TOPDIR}/mk/bsd.prog.mk
