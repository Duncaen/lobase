#	$OpenBSD: Makefile,v 1.9 2016/05/26 21:24:16 millert Exp $

.TOPDIR?=../..

PROG=	which
MAN=	which.1 whereis.1
LINKS=	${BINDIR}/which ${BINDIR}/whereis

# XXX: put the updated man page in the objdir?
check_path_in_man:
	@echo "Checking path expansion in whereis.1"; \
	stdpath=`printf '#include <paths.h>\n_PATH_STDPATH\n' | \
	${CC} -E -P ${CPPFLAGS} - | \
	sed -n 's/^[    ]*"\(.*\)".*/.D1 \1/p'` ; \
	fgrep -xq "$$stdpath" ${.CURDIR}/whereis.1 && { touch $@; exit 0; }; \
	echo "Update the expansion of _PATH_STDPATH in ${.CURDIR}/whereis.1"; \
	exit 0

all: check_path_in_man
CLEANFILES = check_path_in_man

include ${.TOPDIR}/mk/bsd.prog.mk
