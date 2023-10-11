#include "aic205.h"
#include <stdlib.h>
#include <time.h>

internal int RandInitialized = 0;

static void initRand(int seed_arg, int should_seed)
{
	if (RandInitialized == 1) return;
	if (should_seed == 1)
		srand(seed_arg);
	else
		srand(time(NULL));
	RandInitialized = 1;
}

void randomForceSeed(int seed)
{
	RandInitialized = 0;
	initRand(seed, 1);
}

int randomInt(void)
{
	if (!RandInitialized)
		initRand(0, 0);
	return(rand());
}

int randomIntFromTo(int from, int to)
{
	int diff = to - from;
	if (diff <= 0) return(0);
	if (!RandInitialized)
		initRand(0, 0);
	return((rand() % (diff + 1)) + from);
}