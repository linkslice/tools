#define _BSD_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>


void hearts(int);

int main()
{

	int count = 0;
	while (count != 1) {
		printf("%d\n", makeRandom());
		sleep(1);
	}
	
}

int makeRandom()
{

	int p;
	p = getpid();
	srand(time(NULL)+p);
	int y;
	y = 60 + (int) (1000.0 * (rand() / (RAND_MAX + 1.0)));

	return y;
}
