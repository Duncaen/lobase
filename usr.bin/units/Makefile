#	$OpenBSD: Makefile,v 1.4 1997/04/27 20:56:56 millert Exp $

.TOPDIR?=../..

PROG=	units
CPPFLAGS+=	-D'UNITSFILE="${SHAREDIR}/misc/units.lib"'

beforeinstall:
	${INSTALL} -d -m 755 ${DESTDIR}${SHAREDIR}
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m 444 \
	    ${.CURDIR}/units.lib ${DESTDIR}${SHAREDIR}/misc

include ${.TOPDIR}/mk/bsd.prog.mk
