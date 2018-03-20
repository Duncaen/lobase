#	$OpenBSD: Makefile,v 1.11 2016/09/11 06:40:57 natano Exp $

.TOPDIR?=../..

PROG=	calendar
SRCS=   calendar.c io.c day.c pesach.c ostern.c paskha.c
INTER=	de_DE.UTF-8 hr_HR.UTF-8 ru_RU.UTF-8 fr_FR.UTF-8
CPPFLAGS+=	-D'_PATH_CPP="${libexecdir}/tradcpp"'
CPPFLAGS+=	-D'_PATH_INCLUDE="-I${SHAREDIR}/calendar"'

beforeinstall:
	${INSTALL} -d ${SHAREDIR}/calendar
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m 444 \
	    ${.CURDIR}/calendars/calendar.* ${DESTDIR}${SHAREDIR}/calendar
	for lang in ${INTER}; do \
		mkdir -p ${DESTDIR}${SHAREDIR}/calendar/$${lang}; \
		${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m 444 \
			${.CURDIR}/calendars/$${lang}/calendar.* \
			${DESTDIR}${SHAREDIR}/calendar/$${lang}; \
	done

include ${.TOPDIR}/mk/bsd.prog.mk
