#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159

double f(double x)
{
	return pow(x,2)-2;
}

double fp(double x)
{
	return 2*x;
}

double newton(double x)
{
	return x-f(x)/fp(x);
}

int main(int argc, char *argv[])
{
	double eps = 1.0e-10;
	double x1, x2;
	int i;

	do
	{
		printf("Enter initial guess: ");
		scanf("%lf", &x1);
	}
	while (fp(x1) == 0);

	for (i=0;i<100;i++)
	{
		x2 = newton(x1);
		if (fabs(x1-x2) < eps) break;
		x1=x2;
	}

	printf("\nIteration number: %d\nRoot: %.10lf\n", i, x2);

	return 0;
}

