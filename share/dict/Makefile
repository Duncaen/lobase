#	$OpenBSD: Makefile,v 1.3 2017/06/12 18:49:34 espie Exp $
#	from: @(#)Makefile	5.1.1.1 (Berkeley) 5/7/91

# Missing: connectives, words

FILES=	README propernames web2 web2a
NOOBJ=	noobj
LINKS=	${BINDIR}/dict/web2 ${BINDIR}/dict/words

all clean cleandir depend tags:

realinstall:
	${INSTALL} -d ${DESTDIR}${BINDIR}/dict
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m 444 \
		$(addprefix ${.CURDIR}/,$(FILES)) ${DESTDIR}${BINDIR}/dict

include ${.TOPDIR}/mk/bsd.prog.mk
