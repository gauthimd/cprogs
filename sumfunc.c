#include <stdio.h>
#include <math.h>
#define PI 3.14159

int sumofints(int n)
{
	if (n==0) return 0;
	return n + sumofints(n-1);
}

int main()
{
	int x;
	printf("This program will sum all integers from 0 to n.\n");
	printf("Enter n:  ");
	scanf("%d", &x);
	printf("The sum from zero to %d is: %d\n", x, sumofints(x));
	return 0;
}

