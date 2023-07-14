#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159

double f(double x)
{
	return exp(x)-3*x;
}

int main(int argc, char *argv[])
{
	double x1, x2, x3;
	double eps = 1.0e-10;
	//Get 2 real numbers as an initial guess for the interval of the root
	do
	{
		if (argc == 3 && f(atol(argv[1]))*f(atol(argv[2])) < 0)
		{
			x1 = atol(argv[1]); x2 = atol(argv[2]);
		}	
		else
		{
		printf("Enter 2 real numbers separated by a space as the guess of the interval: ");
		scanf("%lf %lf", &x1, &x2);
		}
	}
        while (f(x1)*f(x2) > 0);
	//When an interval is found in which f(x1)*f(x2) < 0 begin the bisection iterations
	while (fabs(x1-x2) > eps)
	{
	x3 = (x1 + x2)/2;
	if (f(x1)*f(x3) < 0) x2 = x3;
        else x1 = x3;
	}
	printf("The root is: %.10lf\n", x1);
	return 0;
}
