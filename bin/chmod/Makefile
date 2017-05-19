#	$OpenBSD: Makefile,v 1.7 2001/09/06 18:52:55 mickey Exp $

.TOPDIR?=../..

PROG=	chmod
CFLAGS+=-DSUPPORT_DOT
MAN=	chmod.1 chgrp.1 chown.8 chflags.1
LINKS=	${BINDIR}/chmod ${BINDIR}/chgrp \
	${BINDIR}/chmod ${BINDIR}/chown

# XXX compatibility
#afterinstall:
#	(cd ${DESTDIR}/usr/sbin; \
#	    ln -sf ../../sbin/chown .; \
#	    ln -sf ../../bin/chgrp .)
#	(cd ${DESTDIR}/usr/bin; \
#	    ln -sf ../../bin/chmod chflags)


include ${.TOPDIR}/mk/bsd.prog.mk
