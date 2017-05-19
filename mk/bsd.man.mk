
install: maninstall

VPATH+=${.CURDIR}

maninstall: _maninstall

_maninstall: ${MAN}
	for f in $^; do \
		s=$${f##*.}; \
		test -d "${DESTDIR}${MANDIR}$$s" || \
			$(INSTALL) -d -m 755 "${DESTDIR}${MANDIR}$$s"; \
		${INSTALL} -m ${MANMODE} "$$f" "${DESTDIR}${MANDIR}$$s/$${f##*/}"; \
	done


manlint:

.PHONY: install maninstall _maninstall manlint
