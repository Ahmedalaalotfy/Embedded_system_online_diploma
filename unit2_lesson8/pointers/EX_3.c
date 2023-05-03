/*
 ============================================================================
 Name        :
 assignments.c
 Author      : Ahmedalaalotfy
 Version     :
 Copyright   : Your copyright notice
 Description : EX_3
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char x[50] ;
	char *ptr = x ;
	int i , y;

	printf("\nEnter the string: ");
	fflush(stdin); fflush(stdout);
	gets(x);

	y = strlen(x);

	printf("\nthe entered string : %s",x);

	ptr = x + y ;

	printf("\nthe reversed string : ");

	for (i = y ; i>=0 ; i--)
	{
		printf("%c",*ptr);
		ptr--;
	}

	return 0 ;
}



