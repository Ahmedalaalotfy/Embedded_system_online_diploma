/*
 ============================================================================
 Name        :
 assignments.c
 Author      : Ahmedalaalotfy
 Version     :
 Copyright   : Your copyright notice
 Description : EX_1
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{

	int m=29 ,*ab;

	printf("\nAddress of m: %x",(unsigned int)&m);
	printf("\nValue of m: %d",m);

	ab=&m;

	printf("\nAddress of m: %x",(unsigned int)ab);
	printf("\nValue of m: %d",*ab);

	m = 34;

	printf("\nAddress of m: %x",(unsigned int)ab);
	printf("\nValue of m: %d",*ab);

	*ab=7;

	printf("\nAddress of m: %x",(unsigned int)&m);
	printf("\nValue of m: %d",m);
	return 0 ;
}



