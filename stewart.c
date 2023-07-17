#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.14159

/*This function will get the normal vector of the surface created by three individual points
 *First points A,B,and C will be used to find 2 vectors, AB and AC
 *The cross-product AB x AC gives the vector normal to the surface created by these 2 vectors*/
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
	printf("%lf %lf %lf %lf",vector[0],vector[1],vector[2],len);
	for (i=0; i<3; i++)
	{
		if (i==2) angles[i] = acos(vector[i]/len);
		else angles[i] = acos((vector[i])/len); //-pi/2;
	}
	printf("\nx=%lf y=%lf z=%lf\n", angles[0], angles[1], angles[2]);
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
	//		printf("%lf ", h[i][j]);
			g[i][j] = h[i][j];
		}
	//	printf("\n");
	}
}

void getlegvectors(double dist[6][3], double len[6], double trans[3], double rot[3][3], double plat[6][3], double base[6][3])
{
	int i, j, k;
	double prod[6][3] = {0};
	for (i=0; i<6; i++)
	{
		for (j=0; j<3; j++)
		{
			for (k=0; k<3; k++)
			{
				prod[i][j] += rot[j][k]*plat[i][k];
				//printf("i=%d  j=%d  k=%d  prod[i][j]=%lf\n",i,j,k,prod[i][j]);
			}
			dist[i][j] = trans[j] + prod[i][j] - base[i][j];
			//printf("dist[i][j]= %lf\n",dist[i][j]);
		}
			//printf("\nprod[0]=%lf prod[1]=%lf prod[2]=%lf\n\n",prod[i][0],prod[i][1],prod[i][2]);
		len[i] = sqrt(pow(dist[i][0],2) + pow(dist[i][1],2) + pow(dist[i][2],2));
	}
}

int main()
{
	int i, j;
	float x, y, z;					//Temp variables to calculate normal vector
	double normalvector[3]; 			//This is the normal vector calculated from 3 individual points
	double newangles[3]; 				//This is the x,y,z angles calculated for a given normal vector
	double T[3] = {0, 0, 10.0};			//This is the translation vector, will be gathered from inputs tbd 
	double mat[3][3] = {0};  		   	//This is the rotational matrix for given x,y,z angles
	double T0[3] = {0, 0, 10.0};		   	//This is the home position translation vector
	double P[6][3] = { {3.464,  -2, 0},     	//These are the platform coordinates of the anchor points
		           {-3.464,  2, 0},
			   {0.00,  -4.00, 0},
			   {0.00,   4.00, 0},
			   {-3.464, -2, 0},
			   {3.464,   2, 0} };
	double B[6][3] = { {4.33,  -2.5, 0},          	//These are the base coordinates of the anchor points
		           {-4.33,  2.5, 0},
			   {0,  -5.0, 0},
			   {0,   5.0, 0},
			   {-4.33, -2.5, 0},
			   {4.33,   2.5, 0} };
	double d[6][3] = {0};				//These are the vectors for each leg, used to calculate length
	double dlen[6];					//These are the 6 lengths for each leg, calculated from the leg vectors
	//normalvector[0] = 0;
	//normalvector[1] = 0;
	//normalvector[2] = 1;
	do{
	printf("\nPress Ctrl+C to exit\nEnter the coordinates for the normal vector in x y z format: ");
	scanf("%lf %lf %lf", &normalvector[0], &normalvector[1], &normalvector[2]);
	getangles(normalvector, newangles);			//This line calls the function to get the angles from the normal vector
	printf("\nNew angles: %.3lfx %.3lfy %.3lfz\n", newangles[0]*180/pi, newangles[1]*180/pi, newangles[2]*180/pi);
	ProtB(mat, newangles[0], newangles[1], newangles[2]);   //This line calls the function to obtain the rotational matrix for the 
	printf("\nRotation matrix for given normal vector:\n");
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++) printf(" %.3lf ",mat[i][j]);
		printf("\n");
	}
	getlegvectors(d, dlen, T, mat, P, B);
	printf("\nLeg vectors:\n");
	i=0;
	for (i=0; i<6; i++)
	{
		printf("%d    %.3lfx %.3lfy %.3lfz\n", i+1, d[i][0], d[i][1], d[i][2]);
	}
	printf("\nLeg lengths:\n");
	i=0;
	for (i=0; i<6; i++)
	{
		printf("%d    %.3lf\n", i+1, dlen[i]);
	}
	}while(1);
	return 0;
}
