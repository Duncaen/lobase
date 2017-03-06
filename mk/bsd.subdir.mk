SUBDIR_TARGETS = all clean install depend regress

$(SUBDIR_TARGETS): $(SUBDIR)

$(SUBDIR):
	@cd $@ && $(MAKE) -I$(TOPDIR) -I$(TOPDIR)/mk \
		$(filter-out $@,$(MAKECMDGOALS))

$(BROKEN):
	@echo "skipping $@"

.PHONY: all clean install $(SUBDIR)
