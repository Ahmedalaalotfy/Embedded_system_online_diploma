/*
 *
 *
Create
 on: Mar 20, 2023
 *      Author: ahmed
 *
 *      EX_6
 */

#include<stdio.h>

int main(void)
{
	int x,i, sum=0 ;

	printf("\nplease enter a number to get the sum : ");
			fflush(stdin); fflush(stdout);
			scanf("%d",&x);

	for (i =0 ; i< x ; i++)
	{
            sum += (i+1);
	}

	printf("\nthe sum is : %d ",sum);
}
