/*
 *
 *
Create
 on: Mar 20, 2023
 *      Author: ahmed
 *
 *      EX_8
 */

#include<stdio.h>

int main(void)
{
	float x,y ;
	char z , i;

	for (i=0 ; i<4 ; i++)
	{
		printf("\nplease enter specific operation + or - or * or /  : ");
		fflush(stdin); fflush(stdout);
		scanf("%c",&z);


		printf("\nplease enter two numbers ... ");


		printf("\nplease enter the first number : ");
		fflush(stdin); fflush(stdout);
		scanf("%f",&x);

		printf("\nplease enter the second number : ");
		fflush(stdin); fflush(stdout);
		scanf("%f",&y);

		switch (z)
		{
		case '+' :
			printf("the sum of the two numbers is : %0.3f",x+y);
			break;

		case '-' :
			printf("the difference between the two numbers is : %0.3f",x-y);
			break;


		case '*' :
			printf("the multiply of the two numbers is : %0.3f",x*y);
			break;


		case '/' :
			printf("the divide of the two numbers is : %0.3f",x/y);
			break;

		default :
			printf("you didn't choose any operation");

		}
	}

}
