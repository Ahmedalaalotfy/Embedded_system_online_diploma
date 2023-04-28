#include <stdio.h>

double sqr_root(double num);

int main() {

	int x ;

	printf("Please enter number to get the square root : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);


	printf("\n the square root is = %f",sqr_root(x));


	return 0;
}

double sqr_root(double num)
{
	int i ;
	double j = num/2;
	for ( i = 0; i < 10; i++ )
	{
		j = (j+num/j)/2;
	}
	return j;
}
