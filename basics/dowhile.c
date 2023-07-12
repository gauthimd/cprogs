#include <stdio.h>
#include <math.h>

int main()
{
	int x;
	do
	{
	printf("Enter 1 or 0: ");
	scanf("%d", &x);
	} while (x != 0 && x != 1);
	return 0;
}
