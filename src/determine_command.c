#include "bob.h"

int determine_command(char *arg)
{
	if (equal_strings(arg, "init")) return 1;
	if (equal_strings(arg, "set")) return 2;
	if (equal_strings(arg, "build")) return 3;
	if (equal_strings(arg, "run")) return 4;
	return 0;
}
