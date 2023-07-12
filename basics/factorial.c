#include <stdio.h>
#include <math.h>
#define PI 3.14159

int factorial(int n)
{
	if (n==0) return 1;
	return n * factorial(n-1);
}

int main()
{
	int x,i;
	float sum;
	printf("This program will return the factorial of n.\n");
	printf("Enter n:  ");
	scanf("%d", &x);
	printf("The factorial of %d is: %d\n", x, factorial(x));
	for (i=0;i<=x;i++) sum = sum + 1.0/factorial(i);
	printf("The sequence 1/0! + 1/1! + 1/2! + ... + 1/n! = %.30f\n", sum);
	return 0;
}

