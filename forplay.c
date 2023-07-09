#include <stdio.h>
#include <math.h>

int main()
{
	int i, n;
	float sum = 0.0;
	printf("Enter number of iterations: ");
	scanf("%d", &n);
	for (i=1;i<=n;i++) sum=sum + pow(-1,i+1)/i;
	printf("The approximate value of ln(2) = %f\n", sum);
	printf("The exact value of ln(2) = %f\n", log(2));
	
	float x=1.0;
	float y;
	for (i=1;i<=n;i++) x = 1/(1+x*x);
	printf("\nSolve roots of x^3 + x - 1\n");
        printf("x = %f\n", x);
        printf("f(x) = %f\n", x*x*x + x - 1);
	return 0;
}
