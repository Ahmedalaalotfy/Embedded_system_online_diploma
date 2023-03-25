/*
 *
 *
Create
 on: Mar 20, 2023
 *      Author: ahmed
 *
 *      EX_1
 */

#include<stdio.h>

int main(void)
{
	int x,y,i;

	for (i=0; i <= 1 ; i++)
	{
		printf("please enter number to check : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);
		y = x%2 ;

		if (y == 0)
			printf("\nthe number %d is even\n" ,x );
		else
			printf("\nthe number %d is odd\n" ,x );
	}
}
