#include <stdio.h>
#include <math.h>
#define PI 3.14159

int fibo(int n)
{
	if (n==0) return 0;
	if (n==1) return 1;
	if (n==2) return 1;
	return fibo(n-1) + fibo(n-2);
}

int seq1(int m)
{
	int result;
	if (m==0) return 2;
	if (m==1) return -1;
	return -2*seq1(m-1) + 3*seq1(m-2);	
}

int main()
{
	int i;
	printf("Enter n = "); scanf("%d",&i);
	printf("Fibonacci: %d\n", fibo(i));
	printf("Sequence 1: %d\n", seq1(i));

	return 0;
}

