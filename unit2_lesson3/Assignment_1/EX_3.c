/*
 *
 *
 Created on: Mar 20, 2023
 *      Author: ahmed
 *
 *      EX_3
 */

#include<stdio.h>

int main(void)
{
	int x,y;

	printf("Please enter two numbers to add .. ");

	printf("\nthe first number is : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	printf("\nthe second number is : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);

	printf("\nThe sum is :%d\n",x+y);
}
