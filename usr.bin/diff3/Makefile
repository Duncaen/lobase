#	$OpenBSD: Makefile,v 1.2 2003/07/22 00:11:30 millert Exp $

.TOPDIR?=../..

PROG=	diff3prog
MAN=	diff3.1
BINDIR=	${libexecdir}

all: diff3

diff3: diff3.ksh
	sed \
		-e "s;/bin/ksh;${bindir}/ksh;g" \
		-e "s;/usr/libexec;${libexecdir};g" \
		$< >$@

beforeinstall:
	test -d "$(DESTDIR)$(bindir)" || \
		$(INSTALL) -d -m 755 $(DESTDIR)$(bindir)/
	$(INSTALL) diff3 $(DESTDIR)$(bindir)/diff3

include ${.TOPDIR}/mk/bsd.prog.mk
