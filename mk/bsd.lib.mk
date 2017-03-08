include ${.TOPDIR}/mk/bsd.own.mk

STATICLIB = lib$(LIB).a

#.CURDIR = .
#_objdir = ${.CURDIR}/obj
#VPATH+=	$(__objdir)

CPPFLAGS+=	-I$(.TOPDIR)/include -include compat.h \
		-I$(.TOPDIR) -include config.h

LDFLAGS += $(LDADD)

CFILES = $(filter %.c,$(SRCS))
YFILES = $(filter %.y,$(SRCS))
LFILES = $(filter %.l,$(SRCS))

OBJS += $(YFILES:.y=.o)
OBJS += $(LFILES:.l=.o)
OBJS += $(CFILES:.c=.o)

.DEFAULT_GOAL :=

all: $(STATICLIB)

ifdef SRCS
$(STATICLIB) : $(OBJS)
else
$(STATICLIB) : % : %.o
endif

y.tab.h y.tab.c: $(YFILES)
	@echo $(YACC) -d $(^F)
	@$(YACC) -d $^

$(YFILES:.y=.c): y.tab.c
	@cp -f y.tab.c $@

%.c: %.l
	@echo "$(LEX) -t $(LFLAGS) $(<F) > $(@F)"
	@$(LEX) -t $(LFLAGS) $< > $@

%.o: %.c
	@echo $(CC) -c $(CFLAGS) $(<F)
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $<

$(STATICLIB):
	@rm -f $@
	@echo $(AR) $@ $(^F)
	@$(AR) rc $@ $(^F)
	@echo $(RANLIB) $@
	@$(RANLIB) $@

clean: _SUBDIRUSE
	rm -f $(STATICLIB) $(OBJS)
ifdef CLEANFILES
	rm -f $(CLEANFILES)
endif

cleandir: _SUBDIRUSE clean

beforeinstall:

realinstall:
	test -d "$(DESTDIR)$(LIBDIR)" || \
		$(INSTALL) -d -m 755 $(DESTDIR)$(LIBDIR)
	$(INSTALL) -m 600 $(STATICLIB) \
		$(DESTDIR)$(LIBDIR)

install: maninstall _SUBDIRUSE
maninstall: afterinstall
afterinstall: realinstall
realinstall: beforeinstall


.PHONY: all clean cleandir install libinstall

ifndef NOMAN
include ${.TOPDIR}/mk/bsd.man.mk
endif

include ${.TOPDIR}/mk/bsd.subdir.mk
