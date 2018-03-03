#include_next <limits.h>

#ifndef _COMPAT_LIMITS_H_
#define _COMPAT_LIMITS_H_

#ifndef ARG_MAX
# if defined(__linux__) && defined(_SC_ARG_MAX)
#  define ARG_MAX sysconf(_SC_ARG_MAX)
# endif
#endif

#endif
