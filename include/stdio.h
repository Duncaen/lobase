#include_next <stdio.h>

#ifndef	_COMPAT_STDIO_H_
#define	_COMPAT_STDIO_H_

#include <sys/types.h>

char	*fgetln(FILE *, size_t *);

int asprintf(char **, const char *, ...);
int vasprintf(char **, const char *, va_list);

#endif /* _COMPAT STDIO_H_ */
