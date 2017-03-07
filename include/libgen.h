#include_next <libgen.h>

#ifndef _COMPAT_LIBGEN_H_
#define _COMPAT_LIBGEN_H_

#undef	basename
#define	basename	openbsd_basename
#undef	dirname
#define	dirname		openbsd_dirname

char	*basename(const char *);
char	*dirname(const char *);

#endif /* _COMPAT_LIBGEN_H_ */
