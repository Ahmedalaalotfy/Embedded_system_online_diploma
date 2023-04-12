/*
 ============================================================================
 Name        :
 assignments.c
 Author      : Ahmedalaalotfy
 Version     :
 Copyright   : Your copyright notice
 Description : EX_2
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int Factorial( int x);

int main()
{
	int x;

	printf("please enter two numbers get the factorial : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);


	printf("the factorial of %d is : %d",x,Factorial(x));

	printf("\nplease enter two numbers get the factorial : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);


		printf("the factorial of %d is : %d",x,Factorial(x));


	return 0 ;

}

int Factorial( int x)
{
	int fac = 1 ;
	if (x>1)
	{
		fac *= (x*Factorial(x-1));
	}

	else if (x == 0)
	{
		fac = 1 ;
	}

	return fac ;
}
