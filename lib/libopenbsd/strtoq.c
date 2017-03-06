#include <stdlib.h>


long long __attribute__((weak))
strtoll(const char *, char **, int);

long long
strtoll(const char *nptr, char **endptr, int base)  {
	return 0;
}
 __weak_alias(strtoq, strtoll);
