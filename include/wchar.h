#include_next <wchar.h>

#ifndef _COMPAT_WCHAR_H_
#define _COMPAT_WCHAR_H_

#include_next <wchar.h>

wchar_t *fgetwln(FILE *__restrict, size_t *__restrict);

int wcwidth(wchar_t);

#endif /* !_COMPAT_WCHAR_H_ */
