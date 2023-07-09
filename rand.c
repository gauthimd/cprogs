#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159

int main()
{
	int i;
	srand(time(NULL));
	printf("Seed random number generator with UNIX NULL time: %d\n",time(NULL));
	printf("This gives 10 random numbers between 0 and 1.0:\n");
	for (i=0;i<10;i++) printf("%1.1f\n", 1.0*rand()/RAND_MAX);
	printf("This gives 10 random numbers between 0 and 5.0:\n");
	for (i=0;i<10;i++) printf("%1.1f\n", 5.0*rand()/RAND_MAX);
	printf("This gives 10 random numbers between -5.0 and 5.0:\n");
	for (i=0;i<10;i++) printf("%1.1f\n", 10.0*rand()/RAND_MAX-5);
	/*printf("This gives 0,1,2,3,4,5, or 6:\n");
	for (i=0;i<10;i++) printf("%1.1f\n", rand()%7);
	printf("This gives 10,11,12,13,14,15, or 16:\n");
	for (i=0;i<10;i++) printf("%1.1f\n", rand()%7+10);*/
	printf("MAX = %d\n", RAND_MAX);
	return 0;
}
