#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159

void reorder(float *pa, float *pb)
{
	float tmp;
	if (*pa > *pb) 
	{
		tmp = *pa;
		*pa = *pb;
		*pb = tmp;
	}
}

int main()
{
	float a=15, b = -6;
	printf("a=%.f b=%.f\n",a,b);
	reorder(&a,&b);
	printf("a=%.f b=%.f\n",a,b);
	return 0;
}

