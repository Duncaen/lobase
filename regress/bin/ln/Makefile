#	$OpenBSD: Makefile,v 1.1 2013/03/12 06:00:05 guenther Exp $

regress: recursive links/source
	@$(SHELL) ${.CURDIR}/test_ln.sh && touch $@

clean:
	rm -rf links regress

links:
	@mkdir -p ${.OBJDIR}/links

recursive: links
#	@ln -s ${.OBJDIR}/links links/links

links/source: links
	@echo "Hello, world!" > ${.OBJDIR}/links/source

include ${.TOPDIR}/mk/bsd.regress.mk
