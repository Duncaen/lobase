#ifndef _COMPAT_RESOLV_H_
#define _COMPAT_RESOLV_H_

int b64_ntop(unsigned char const *, size_t, char *, size_t);
int b64_pton(char const *, unsigned char *, size_t);

#endif /* _COMPAT_RESOLV_H_ */

#include_next <resolv.h>
