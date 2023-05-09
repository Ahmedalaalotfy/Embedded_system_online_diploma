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
	int x,i, factorial=1, z ;

	for (z=0 ; z<3; z++)
	{
		printf("\nplease enter a number to get the factorial : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);

		if (x == 0 )
			printf("the factorial is 1");
		else if (x<0)
			printf("negative number doesn't have a factorial ");

		else
		{
			for (i=0 ; i<x ; i++)
			{
				factorial *= (i+1);
			}

			printf("\nthe factorial is : %d ",factorial);
		}
	}
}
