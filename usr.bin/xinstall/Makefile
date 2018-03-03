#	$OpenBSD: Makefile,v 1.8 2017/07/09 21:23:19 espie Exp $

.TOPDIR?=../..

PROG=	xinstall
MAN=	install.1

include ${.TOPDIR}/mk/bsd.prog.mk

realinstall:
	test -d "$(DESTDIR)$(BINDIR)" || \
		$(INSTALL) -d -m 755 $(DESTDIR)$(BINDIR)
	$(INSTALL) $(PROG) $(DESTDIR)$(BINDIR)/install
