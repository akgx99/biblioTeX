#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hello.h"

int main(void)
{
	int system(const char *command);
    chdir("script/");
    system("./stats.sh");

	return 0;
}

