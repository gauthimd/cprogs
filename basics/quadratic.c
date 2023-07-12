#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main(int argc, char *argv[])
{
	float a, b, c, x1, x2;
	if (argc > 1)
	{
		a=atoi(argv[1]);
		b=atoi(argv[2]);
		c=atoi(argv[3]);
		printf("%.1f %.1f %.1f\n",a,b,c);
	}
	else
	{
        printf("Enter a,b, and c separated by spaces: ");
	scanf("%f %f %f", &a, &b, &c);
	}
	if (pow(b,2)-4*a*c < 0) printf("\nThe roots are imaginary\n");
	else
	{
	x1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
	x2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
	printf("The roots are:\n");
	printf("x1 = %.3f\n", x1);
	printf("x2 = %.3f\n", x2);
	}
	return 0;
}

