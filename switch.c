#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main()
{
	int x;
	printf("Enter a number between 1 and 5\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1: printf("You entered 1\n");break;
		case 2: printf("You entered 2\n");break;
		case 3: printf("You entered 3\n");break;
		case 4: printf("You entered 4\n");break;
		case 5: printf("You entered 5\n");break;
		default: printf("You are a dick\n");break;
	}
	return 0;
}

