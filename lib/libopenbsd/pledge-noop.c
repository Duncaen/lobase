#include "openbsd.h"

int
pledge(__UNUSED const char *promises, __UNUSED const char *paths[])
{
	return 0;
}
