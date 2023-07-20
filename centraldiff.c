#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159
#define N 11

int main(int argc, char *argv[])
{
	double y[N]={370,9170,23835,45624,62065,87368,97355,103422,127892,149626,160095};
	double central[N], h=20;
	int i;
	for (i=2;i<N-1;i++) central[i]=(y[i+1]-y[i-1])/(2*h);
	central[10] = (3*y[10]-4*y[9] + y[8])/(2*h);
	central[1] = (4*y[2]-y[3]-3*y[1])/(2*h);
	for (i=1; i<N; i++)
	{
	printf("%.1lf %.1lf\n", i*h, central[i]);
	}
	return 0;
}

