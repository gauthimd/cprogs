#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159
#define N 100

int main()
{
	srand(time(NULL));
	int i;
	int sum = 0;
	int roll[N];
	float avg, var, sd;
	for (i=0;i<N;i++) 
	{
		roll[i]=rand() % 6 + 1;
		sum = sum + roll[i];
		printf("%d\n", roll[i]);
	}
	avg = (float)sum/N;
	for (i=0;i<N;i++) 
	{
		var = var + pow(roll[i]-avg,2);
	}
	sd = sqrt(var/(N-1));
	printf("Rolls: %d\nAverage: %.2f\nStd. Dev: %.2f\n", N, avg, sd);
	return 0;
}

