MAKEOBJDIR?=	obj

.TOPDIR?=	..
.OBJDIR?=	${MAKEOBJDIR}
.SRCDIR?=	.
.CURDIR?=	.
.RELDIR:=	$(.SRCDIR:.%=$(.TOPDIR)/../%)

SUBDIR_MFLAGS=	--no-print-directory \
		-I$(.NEXTTOP)/mk \
		-C ${.OBJDIR}/$$nextdir \
		-f ${.RELDIR}/$$nextdir/Makefile \
		.OBJDIR=. \
		.TOPDIR=${.TOPDIR}/.. \
		.CURDIR=${.RELDIR}/$$nextdir \
		.SRCDIR=${.SRCDIR}/$$nextdir \
		MAKEOBJDIR=${.TOPDIR}/${MAKEOBJDIR} \
		_THISDIR_=$$nextdir
		


SUBDIR_TARGETS = all install clean cleandir includes depend regress obj tags manlint

$(SUBDIR_TARGETS): _SUBDIRUSE

define __SUBDIRUSE
for nextdir in $(SUBDIR); do                                                   \
	b=; for s in $(SKIPDIR); do                                            \
		[ "$$s" = "$$nextdir" ] && b=1 && break;                       \
	done;                                                                  \
	[ -n "$$b" ] && echo "($$nextdir skipped)" && continue;                \
	echo "===> $${_THISDIR_:+$${_THISDIR_}/}$$nextdir";                    \
	mkdir -p "${.OBJDIR}/$$nextdir"                                        \
	&& $(MAKE) $(SUBDIR_MFLAGS) $(MAKECMDGOALS) || exit 1;                 \
done
endef

_SUBDIRUSE:
ifneq ($(SUBDIR),)
	+@$(__SUBDIRUSE)

$(SUBDIR):
	+@nextdir="$@"; \
	echo "===> $$nextdir"; \
	mkdir -p "${.OBJDIR}/$$nextdir" \
	&& $(MAKE) $(SUBDIR_MFLAGS) all || exit 1
endif

.PHONY: _SUBDIRUSE $(SUBDIR_TARGETS) $(SUBDIR)
