#include <stdio.h>
#include <stdlib.h>
#include "loadFunctions.h"
#include "poll.h"


int main(int argc, char **argv)
{
	char *file = argv[1];

	int something;
	something = load(file);

	poll();

	printf("\n\n\n\n");


return 0;


}
