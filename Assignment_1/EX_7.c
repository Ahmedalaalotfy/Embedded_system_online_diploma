/*
 *
 *
Created on: Mar 20, 2023
 *      Author: ahmed
 *
 *      EX_7
 */

#include<stdio.h>

int main(void)
{
	float x,y ;

	printf("Please enter two numbers to swap ... ");

	printf("\n the first number is : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&x);

	printf("\n the second number is : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&y);

	x = x+y ;
	y = x+y ;
	x = y-x ;
 	y = y-2*x ;


	printf("\nafter swap , value of first number is : %.1f ",x );
	printf("\nafter swap , value of second number is : %.1f ",y  );

}
