#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159

typedef struct {float Re; float Im} Complex;

Complex complexdiv(Complex z1, Complex z2)
{
	Complex z;
	z.Re = z2.Re/z1.Re;
	z.Im = z2.Im/z1.Im;
	return z;
}

int main(int argc, char *argv[])
{
	Complex z1,z2,z;
	z1.Re = 3;
	z1.Im = 2;
	z2.Re = 6;
	z2.Im = -2;
	z=complexdiv(z1,z2);
	printf("%.2f + %.2fi", z.Re, z.Im);
	return 0;
}

