#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159

/*This function will get the normal vector of the surface created by three individual points
-First points A,B,and C will be used to find 2 vectors, AB and AC
-The cross-product AB x AC gives the vector normal to the surface created by these 2 vectors*/
void getnormal()
{
}

/*This function takes a vector (assumed to be a vector normal to a surface we wish the platform to match)
and calculates the 3 angles the vector makes with the x, y, and z axis using the dot-product.
These angles are then sent to the rotation matrix function to calculate the new rotational matrix
of the platform frame with respect to the base frame*/
void getangles(double vector[3], double angles[3])
{
	int i;
	double len;
	len = sqrt(pow(vector[0],2) + pow(vector[1],2) + pow(vector[2],2));
	for (i=0; i<3; i++)
	{
		angles[i] = acos(vector[i]/len);
	}
}

/*This is the rotational matrix of the platform frame with respect to the base frame. This matrix
 * is dotted with the P[i] vectors (the vectors from the platform origin to the platform anchor points)
 * and added to the translation vector T from which the base vectors to the anchor points 
 */
void ProtB(double g[3][3], double x, double y, double z)
{
	int i, j;
	double h[3][3] =
	     {{cos(z)*cos(y),-sin(z)*cos(x)+cos(z)*sin(y)*sin(x),sin(z)*sin(x)+cos(z)*sin(y)*cos(x)},
	     {sin(z)*cos(y),cos(z)*cos(x)+sin(z)*sin(y)*sin(x),-cos(z)*sin(x)+sin(z)*sin(y)*cos(x)},
	     {-sin(y),cos(y)*sin(x),cos(y)*cos(x)}};
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++) 
		{
			if (h[i][j] < .0001) h[i][j] = 0;
			printf("%lf ", h[i][j]);
			g[i][j] = h[i][j];
		}
		printf("\n");
	}
}

int main()
{
	int i, j;
	double normalvector[3], newangles[3], T[3];
	double mat[3][3] = {0};  
	double T0[3] = {0, 0, 10.0};
	double P[6][3] = {{3.75,  -1.33, 10},     //These are the platform coordinates of the anchor points
		          {-3.75,  1.33, 10},
			  {0.00,  -4.00, 10},
			  {0.00,   4.00, 10},
			  {-3.75, -1.33, 10},
			  {3.75,   1.33, 10}};
	double B[6][3] = {{4,  -2.5, 0},          //These are the base coordinates of the anchor points
		          {-4,  2.5, 0},
			  {0,  -5.0, 0},
			  {0,   5.0, 0},
			  {-4, -2.5, 0},
			  {4,   2.5, 0}};
	normalvector[0] = .3;
	normalvector[1] = 2;
	normalvector[2] = -.1;
	getangles(normalvector, newangles);			//This line calls the function to get the angles from the normal vector
	printf("\nNew angles: %.3lfx %.3lfy %.3lfz\n\n", newangles[0]*180/pi, newangles[1]*180/pi, newangles[2]*180/pi);
	ProtB(mat, newangles[0], newangles[1], newangles[2]);   //This line calls the function to obtain the rotational matrix for the 
	printf("\n");						//new normal vector
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++) printf("%lf ",mat[i][j]);
		printf("\n");
	}
	return 0;
}
