SUBDIR_MFLAGS = -I$(TOPDIR) -I$(TOPDIR)/mk
SUBDIR_TARGETS = all clean cleandir includes depend obj tags manlint
SKIPDIR ?=

$(SUBDIR_TARGETS): _SUBDIRUSE

_SUBDIRUSE:
ifneq (,$(SUBDIR))
	@for d in $(SUBDIR); do \
		skip=; for s in $(SKIPDIR); do \
			[ "$$s" = "$$d" ] && skip=1; \
		done; \
		[ "$$skip" ] && echo "($$d skipped)" && continue; \
		echo "===> $$d"; \
		$(MAKE) $(SUBDIR_MFLAGS) -C $$d $(MAKECMDGOALS) || exit 1; \
	done

$(SUBDIR):
	@echo "===> $@"; \
	$(MAKE) $(SUBDIR_MFLAGS) -C $@ all || exit 1
endif

.PHONY: _SUBDIRUSE $(SUBDIR_TARGETS) $(SUBDIR)
