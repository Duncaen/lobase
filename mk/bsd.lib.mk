include config.mk

STATICLIB = lib$(LIB).a

.CURDIR = .
CLEANFILES += $(STATICLIB) *.o

CPPFLAGS += -I$(TOPDIR)/libopenbsd -include openbsd.h -I$(TOPDIR) -include config.h
LDFLAGS += $(LDADD)

#find_src = $(wildcard $(src) $(.PATH:%=%/$(src)))
#SRCS := $(foreach src,$(SRCS),$(find_src))
ifneq (,$(.PATH))
	VPATH := $(.PATH)
endif

CFILES = $(filter %.c,$(SRCS))
YFILES = $(filter %.y,$(SRCS))
LFILES = $(filter %.l,$(SRCS))

OBJS = $(YFILES:.y=.o) $(LFILES:.l=.o) $(CFILES:.c=.o)

ifneq (,$(findstring $(.DEFAULT_GOAL),install beforeinstall afterinstall))
	.DEFAULT_GOAL :=
endif

.DEFAULT_GOAL :=

all: $(STATICLIB)

ifdef SRCS
$(STATICLIB) : $(OBJS)
else
$(STATICLIB) : % : %.o
endif

$(STATICLIB) : ../../libopenbsd/libopenbsd.a

../../libopenbsd/libopenbsd.a:
	$(MAKE) -C ../../libopenbsd libopenbsd.a

y.tab.h y.tab.c:
	$(YACC) -d $<

%.o: %.y y.tab.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c y.tab.c -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

$(STATICLIB):
	$(AR) rc $@ $^

clean:
	rm -f $(CLEANFILES)

install: libinstall

libinstall:
	test -d "$(DESTDIR)$(LIBDIR)" || \
		$(INSTALL) -d -m 755 $(DESTDIR)$(LIBDIR)
	$(INSTALL) $(STATICLIB) $(DESTDIR)$(LIBDIR)/$(STATICLIB)

.PHONY: all clean install libinstall
