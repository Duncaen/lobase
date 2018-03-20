#	$OpenBSD: Makefile,v 1.2 2002/03/02 16:20:33 millert Exp $

.TOPDIR?=../..

PROG=	spellprog
MAN=	spell.1
SRCS=	spellprog.c look.c
BINDIR=	${libexec}

all: spell

spell: spell.ksh
	sed \
		-e "s;/bin/ksh;${bindir}/ksh;g" \
		-e "s;/usr/libexec;${libexecdir};g" \
		-e "s;/usr/share;${datadir};g" \
		$< >$@

afterinstall:
	${INSTALL} -d ${DESTDIR}${datadir}/dict/special
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		spell ${DESTDIR}${bindir}/spell
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m ${NONBINMODE} \
		${.CURDIR}/stop ${DESTDIR}${datadir}/dict
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m ${NONBINMODE} \
		${.CURDIR}/american ${DESTDIR}${datadir}/dict
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m ${NONBINMODE} \
		${.CURDIR}/british ${DESTDIR}${datadir}/dict
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m ${NONBINMODE} \
		${.CURDIR}/special.4bsd  ${DESTDIR}${datadir}/dict/special/4bsd
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m ${NONBINMODE} \
		${.CURDIR}/special.math ${DESTDIR}${datadir}/dict/special/math

include ${.TOPDIR}/mk/bsd.prog.mk
