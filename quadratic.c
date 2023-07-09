#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main()
{
	float a, b, c, x1, x2;
        printf("Enter a,b, and c separated by spaces: ");
	scanf("%f %f %f", &a, &b, &c);
	if (pow(b,2)-4*a*c < 0) printf("The roots are imaginary\n");
	else
	{
	x1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
	x2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
	printf("x1 = %f\n", x1);
	printf("x2 = %f\n", x2);
	}
	return 0;
}

