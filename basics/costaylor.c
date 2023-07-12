#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159

int factorial(int n)
{
	if (n == 0) return 1;
	return n*factorial(n-1);
}

float taylorcos(float x)
{
	int i;
	float cosx=0;
	for (i=0;i<10;i++) cosx = cosx + (pow(-1,i)*pow(x,2*i)/factorial(2*i));
	return cosx;
}

int main()
{
	int i;
	float x;
	printf("This program prints a column of x, and a column of cos(x) generated from the\n");
	printf("sum of the first 10 terms of the Taylor series expansion for cos(x)\n");
	printf("The 3rd column is generated from the cos(x) from math.h\n\n");
	printf("x\t\ttaylorcos(x)\t\tcos(x)\n");
	printf("__________________________________________________\n");
	for (i=1;i<=10;i++) printf("%.1f\t\t%.8f\t\t%.8f\n", x=i/10.0, taylorcos(x), cos(x));
	return 0;
}

