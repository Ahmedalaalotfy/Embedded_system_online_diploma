/*
 *
 *
Created on: Mar 20, 2023
 *      Author: ahmed
 *
 *      EX_5
 */

#include<stdio.h>

int main(void)
{
	char x ;

	printf("Please enter a character to find the ASCI code : ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);

	printf("\nthe ASCI code of (%c) is : %d",x,x);

}
