#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159
#define row 2
#define col 5

int array()
{
	int firstarray[]={1,2,3,4,5,6,7,8,9,10};
	printf("This is element 7 of the array: %d\n",firstarray[6]);
	return 0;
}

int matrix()
{
	int i,j;
	float mat[row][col]={{1.0,2.0,3.0,4.0,5.0},{6.0,7.0,8.0,9.0,10.0}};
	printf("\nThis is a 2x5 matrix:\n");
	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++) printf("%f ",mat[i][j]);
		printf("\n");
	}
	return 0;
}

int main()
{
	//array();
	matrix();
	return 0;
}

