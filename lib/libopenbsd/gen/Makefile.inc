#	$OpenBSD: Makefile.inc,v 1.29 2016/03/30 06:38:41 jmc Exp $

# stdio sources
VPATH+=	${LIBCSRCDIR}/gen

SRCS+=	basename.c dirname.c errc.c fts.c getmntinfo.c glob.c setmode.c unvis.c\
	verrc.c vis.c vwarnc.c warnc.c


MAN+=	basename.3 dirname.3 fts.3 getmntinfo.3 glob.3 setmode.3 unvis.3 vis.3
