#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main()
{
	int i,n;
	float sum = 0.0;
	float approxpi;
	printf("Enter number of iterations: ");
	scanf("%d",&n);
	for (i=1;i<=n;i++) sum = sum + pow(-1,i+1)/(2*i-1); 
	approxpi = 4*sum;
	printf("The approximate value of pi is: %f\n", approxpi);
	return 0;
}

