#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159

void swap(float *pa, float *pb)
{
	float tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}


int main()
{
	float a,b;
	a = 30.0; b = 120.0;
	printf("Old a = %.1f\nOld b = %.1f\n", a,b);
	swap(&a,&b);
	printf("\nNew a = %.1f\nNew b = %.1f\n", a,b);
	return 0;
}

