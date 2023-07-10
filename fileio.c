#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159

int main()
{
	FILE *fp1, *fp2;
	float a,b,c;
	fp1=fopen("data1.dat","r");
	fscanf(fp1, "%f %f %f", &a, &b, &c);
	printf("%f %f %f", a,b,c);
	fclose(fp1);
	fp2=fopen("data2.dat","w");
	fprintf(fp2, "Hello, World!\n");
	fclose(fp2);
	return 0;
}

