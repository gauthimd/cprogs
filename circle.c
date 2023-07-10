#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159

void circle(float radius, float *ar, float *per)
{
	*ar = pi*pow(radius,2);
	printf("%f",pi*pow(radius,2));
	*per = 2*pi*radius;
}

int main()
{
	float rad, area, perimeter;
	printf("\nPlease enter a radius: ");
	scanf("%f",&rad);
	circle(rad, &area, &perimeter);
	printf("\nA circle of radius %.2f has a perimeter of %.2f and an area of %.2f\n", rad, perimeter, area);
	return 0;
}

