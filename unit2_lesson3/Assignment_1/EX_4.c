/*
 *
 *
Created on: Mar 20, 2023
 *      Author: ahmed
 *
 *      EX_4
 */

#include<stdio.h>

int main(void)
{
	float x,y;

	printf("Please enter two numbers to multiply .. ");

	printf("\nthe first number is : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&x);

	printf("\nthe second number is : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&y);

	printf("\nThe sum is :%f\n",x*y);
}
