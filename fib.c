#include <stdio.h>
#include <math.h>
#define PI 3.14159

int fibo(int n)
{
	if (n==1) return 1;
	if (n==2) return 1;
	return fibo(n-1) + fibo(n-2);
}

int main()
{
	int i;
	printf("Enter n = "); scanf("%d",&i);
	printf("%d\n", fibo(i));

	return 0;
}

