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

int main(void) {

	int  i ;
	char string[100] ;

	printf("Please enter the string to check the length : ");
	fflush(stdin); fflush(stdout);
	gets(string);

	for (i=0 ; string[i]!='\0'; i++ );


	printf("\nThe length is : %d",i);

}


