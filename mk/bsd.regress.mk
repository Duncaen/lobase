include ../../../config.mk

.CURDIR = .
.OBJDIR = $(shell pwd)
.DEFAULT_GOAL :=

all: depend regress
depend:

regress:
ifneq (,$(REGRESS_TARGETS))
	for t in $(REGRESS_TARGETS); do \
		$(MAKE) $$t; \
	done
endif

clean:
ifneq (,$(CLEANFILES))
	rm -f $(CLEANFILES)
endif

.PHONY: all clean regress depend
