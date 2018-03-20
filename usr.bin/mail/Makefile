#	$OpenBSD: Makefile,v 1.11 2016/03/30 06:38:46 jmc Exp $

.TOPDIR?=../..

PROG=	mail
SRCS=	version.c aux.c cmd1.c cmd2.c cmd3.c cmdtab.c collect.c \
	edit.c fio.c getname.c head.c v7.local.c lex.c list.c main.c names.c \
	popen.c quit.c send.c strings.c temp.c tty.c vars.c
SFILES=	mail.help mail.tildehelp
EFILES=	mail.rc
LINKS=	${BINDIR}/mail ${BINDIR}/Mail ${BINDIR}/mail ${BINDIR}/mailx
CPPFLAGS+=	-D'_PATH_HELP="${SHAREDIR}/misc/mail.help"'
CPPFLAGS+=	-D'_PATH_TILDE="${SHAREDIR}/misc/mail.tildehelp"'

afterinstall: distribution

distribution:
	# cd ${.CURDIR}/misc; ${INSTALL} ${INSTALL_COPY} -o root -g wheel \
	#     -m 644 ${EFILES} ${DESTDIR}/etc
	${INSTALL} -d ${DESTDIR}${SHAREDIR}/misc
	cd ${.CURDIR}/misc; ${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} \
	    -m 444 ${SFILES} ${DESTDIR}${SHAREDIR}/misc

include ${.TOPDIR}/mk/bsd.prog.mk
