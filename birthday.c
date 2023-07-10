#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int main()
{
	int a[N];
	int i,j;
	int count=0;
	float prob = 0.0;
	srand(time(NULL));
	for (i=0;i<N;i++) a[i]=rand() % 365 + 1;
	for (i=0;i<N;i++)
	{
		for (j=i+1;j<=N;j++) 
		{if (a[i]==a[j]) 
			{
				count++;
				goto ExitLoop;
			}
		}
	ExitLoop:;
	}
	prob=(float)count/N;
	printf("\nCounter: %d\nN: %d\nProbability: %f\n", count, N, prob);
	return 0;
}

