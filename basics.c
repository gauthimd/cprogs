/*This is a program intended to show all the basics of a C program
 To compile this program, run the following command:
 gcc basics.c -lm
 This will produce a file called a.out which can be run at the command prompt by ./a.out
 Otherwise the program may be compiled to a different filename called myprog:
 gcc basics.c -o myprog -lm
 and the file may be run at the prompt using ./myprog
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159

int square()
{
	int x;
	printf("What needs squarin? ");
	scanf("%d", &x);
	printf("The square of %d is %d\n", x, x*x);
	return 0;
}

//Every C program has a main()
int main()
{
	//Basic printf and scanf and arithmetic and function usage
	int a,b,c;
	printf("Enter 2 integers separated by a space: ");
	scanf("%d %d", &a, &b);
	printf("a = %d  b = %d\n", a, b);
	printf("a + b = %d\n", a+b);
	printf("a / b = %.2f\n",(float)a/b);
	square();

	//The main data types in C
	int d=1;
	float e=2.3;
	double f=4.3;
	char g='z';
	printf("int %d\nfloat %.1f\ndouble %lf\nchar %c\n\a", d, e, f, g);
	
	//A basic if else statement
	if (a > b) 
		printf("a is greater than b\n");
	else 
		printf("a is less than or equal to b\n");
	
	//Celsius to Farenheit program
	float C,F;
	printf("\nEnter temperature in Celsius: ");
	scanf("%f",&C);
	printf("%.1f Celsius is %.1f Farenheit\n", C,F=(9.0/5.0)*C + 32); 

	//A basic for loop
	int i,j;
	printf("Enter max number: ");
	scanf("%d", &j);
	for(i=0;i<j;i++)
		printf("%d\n",i);

	//A basic while loop

	return 0;
}
