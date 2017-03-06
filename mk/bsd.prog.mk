include config.mk

.CURDIR = .
CLEANFILES += $(PROG) *.o

CPPFLAGS += -I$(TOPDIR)/lib/libopenbsd -include openbsd.h -I$(TOPDIR) -include config.h

LIBC ?= $(TOPDIR)/lib/libopenbsd/libopenbsd.a
LIBUTIL ?= $(TOPDIR)/lib/libutil/libutil.a

ifeq (-lutil,$(filter -lutil,$(LDADD)))
	LDFLAGS+= -L$(TOPDIR)/lib/libutil
endif
LDFLAGS += -L$(TOPDIR)/lib/libopenbsd $(LDADD) -lopenbsd

CFILES = $(filter %.c,$(SRCS))
YFILES = $(filter %.y,$(SRCS))
LFILES = $(filter %.l,$(SRCS))

OBJS = $(YFILES:.y=.o) $(LFILES:.l=.o) $(CFILES:.c=.o)

ifneq (,$(findstring $(.DEFAULT_GOAL),install beforeinstall afterinstall))
	.DEFAULT_GOAL :=
endif

.DEFAULT_GOAL :=

all: $(PROG)

ifdef SRCS
$(PROG) : $(OBJS)
else
$(PROG) : % : %.o
endif

y.tab.h y.tab.c:
	$(YACC) -d $(YFILES)

%.o: %.y y.tab.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c y.tab.c -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

$(PROG):
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(CLEANFILES) y.tab.h y.tab.c

install: proginstall install_links

proginstall:
ifneq (,$(PROG))
	test -d "$(DESTDIR)$(BINDIR)" || \
		$(INSTALL) -d -m 755 $(DESTDIR)$(BINDIR)
	$(INSTALL) $(PROG) $(DESTDIR)$(BINDIR)/$(PROG_NAME)
endif

install_links:
ifneq (,$(LINKS))
	@set -- $(LINKS); \
	while test $$# -ge 2; do \
		l=$(DESTDIR)$$1; shift; \
		t=$(DESTDIR)$$1; shift; \
		echo "$$t -> $$l"; \
		mkdir -p $$(dirname $$t); \
		rm -f $$t; \
		ln -s $$l $$t; \
	done

endif

.PHONY: all clean install proginstall
