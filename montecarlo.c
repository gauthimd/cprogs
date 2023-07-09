#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159

int main()
{
	printf("This program will use the Monte Carlo method to solve the integral 1/(1+x^2) from 0 to 1\n");
	int i,n;
	float x,y,z, count;
	printf("\nHow many iterations? ");
	scanf("%d", &n);
	count = 0;
	srand(time(NULL));
	for (i=0;i<n;i++)
	{
		x = 1.0*rand()/RAND_MAX;
		//printf("x = %f\n",x);
		y = 1.0*rand()/RAND_MAX;
		//printf("y = %f\n",y);
		if (y <= 1/(1+pow(x,2))) count = count + 1.0;
		//printf("count = %f\n",count);
	}
	printf("\nIterations = %d\ncount = %.f\n", n, count);
	printf("The result of the integral is %.6f which is an approximation of Pi/4\n", (float)count/n);
	printf("The resulting approximation of Pi is: %.6f\n", 4*count/n);
	printf("\nThis next simulation calculates the volume of a sphere of radius 1, an estimation of (4/3)*pi\n");
	count = 0;
	for (i=0;i<n;i++)
	{
		x = 1.0*rand()/RAND_MAX;
		//printf("x = %f\n",x);
		y = 1.0*rand()/RAND_MAX;
		//printf("y = %f\n",y);
		z = 1.0*rand()/RAND_MAX;
		//printf("z = %f\n",z);
		if ((x*x + y*y + z*z) <= 1.0) count = count + 1.0;
		//printf("x*x + y*y + z*z = %f\n", x*x+y*y+z*z);
		//printf("count = %f\n",count);
		//printf("iteration = %d\n",i);
	}
	printf("The result of the simulation is: %f\n", 8*count/n); //The 8 is from the total volume integrated over for a unit sphere
	printf("The actual volume of the sphere is: %.6f\n",(4.0/3.0)*PI);
	return 0;
}

