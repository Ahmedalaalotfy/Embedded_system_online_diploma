/*
 *
 *
Create
 on: Mar 20, 2023
 *      Author: ahmed
 *
 *      EX_4
 */

#include<stdio.h>

int main(void)
{
	float x, i;

	for (i =0 ; i <=2 ; i++)
	{
		printf("\nplease enter a number to check : ");
		fflush(stdin); fflush(stdout);
		scanf("%f",&x);

		if (x ==0 )
			printf("the number %0.2f is zero ",x);

		else if (x > 0)
			printf("the number %0.2f is positive ",x);

		else
			printf("the number %0.2f is negative ",x);
	}
}
