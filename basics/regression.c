#include <stdio.h>

#define N 10

int main()
{
	float x[N]={1,2,3,4,5,6,7,8,9,10},
	      y[N]={-3,2.9,0.5,3.0,2.6,5.2,4.9,4.5,6.1,7.2};
	float xysum = 0.0, xsum = 0.0, ysum = 0.0, x2sum = 0.0;
	float a, b, det;
	a=b=det=0;
	int i;
	for (i=0;i<N;i++) 
	{
		xsum = xsum = x[i];
		ysum = ysum = y[i];
		xysum = xysum + x[i]*y[i];
		x2sum = x2sum + x[i]*x[i];
	}
	det = x2sum*N-xsum*xsum;
	a = (xysum*N-xsum*ysum)/det;
	b = (x2sum*ysum-xysum*xsum)/det;
	printf("The regression line is: %f x + %f.\n", a, b);
	return 0;
}

