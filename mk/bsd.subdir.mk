SUBDIR_TARGETS = all clean install depend regress
SRCDIR = $(shell pwd)

$(SUBDIR_TARGETS): $(SUBDIR)

$(SUBDIR):
	cd $@ && $(MAKE) $(filter-out $@,$(MAKECMDGOALS))

$(BROKEN):
	@echo "skipping $@"

.PHONY: all clean install $(SUBDIR)
