/*
 *
 *
Create
 on: Mar 20, 2023
 *      Author: ahmed
 *
 *      EX_3
 */

#include<stdio.h>

int main(void)
{
	float x,y,z ;


	printf("please enter three numbers to get the largest ... ");

	printf("\nplease enter the first number : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&x);

	printf("\nplease enter the second number : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&y);

	printf("\nplease enter the third number : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&z);

	if (x > y )
	{
		if (x > z)
			printf("\nthe largest number is : %f",x);
		else
			printf("\nthe largest number is : %f",z);

	}

	else if (y > x )
	{
		if (y > z)
			printf("\nthe largest number is : %f",y);
		else
			printf("\nthe largest number is : %f",z);

	}

}
