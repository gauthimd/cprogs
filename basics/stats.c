#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159
#define N 10

int main()
{
	float a[N]={.92348,.58724,.14852,.52439,.98724,
		.25489,.19433,.29435,.10982,.29483};
	int i;
	float sum = 0;
	float average = 0;
	float var = 0;
	float sd = 0;
	for (i=0;i<N;i++) sum = sum + a[i];
	average = sum/N;
	for (i=0;i<N;i++) var = var + pow(a[i]-average,2);
	sd = sqrt(var/(N-1.0));
	printf("Average: %.5f\n",average);
	printf("Std. Dev: %.5f\n",sd);
	return 0;
}

