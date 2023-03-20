/*
 *
 *
Create
 on: Mar 20, 2023
 *      Author: ahmed
 *
 *      EX_3
 */

#include<stdio.h>

int main(void)
{
	char x,i ;

	for (i=0 ; i <= 1 ; i++)
	{
		printf("please enter character to check : ");
		fflush(stdin); fflush(stdout);
		scanf("%c",&x);

		if (x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' ||x == 'u' || x == 'U')
			printf("\nthe character %c is vowel\n" ,x );
		else
			printf("\nthe character %c is consonant\n" ,x );
	}
}
