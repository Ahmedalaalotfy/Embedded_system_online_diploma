/*
 *
 *
Create
 on: Mar 20, 2023
 *      Author: ahmed
 *
 *      EX_5
 */

#include<stdio.h>

int main(void)
{
	char x;
	int i ;

	for (i =0 ; i <=3 ; i++)
	{
		printf("\nplease enter a character to check : ");
		fflush(stdin); fflush(stdout);
		scanf("%c",&x);

		if ((x >= 65 && x <=90) || (x >= 97 && x <=122)  )
			printf("\n%c is an alphabet",x);

		else
			printf("\n%c is not an alphabet",x);
	}
}
