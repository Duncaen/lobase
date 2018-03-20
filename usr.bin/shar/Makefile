#	$OpenBSD: Makefile,v 1.5 1997/09/21 11:50:44 deraadt Exp $

.TOPDIR?=../..

MAN=	shar.1

beforeinstall:
	${INSTALL} -d -m 755 ${DESTDIR}${BINDIR}
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
	    ${.CURDIR}/shar.sh ${DESTDIR}${BINDIR}/shar

include ${.TOPDIR}/mk/bsd.prog.mk
