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

int main(void) {

	int  i =0, x ;
	char string[100],ch;

	printf("Please enter the string to be reverse : ");
	fflush(stdin); fflush(stdout);
	gets(string);

	x = strlen(string);

	while (i<(x-1))
	{
		ch=string[i];
		string[i]=string[x-1];
		string[x-1]= ch;

		i++;
		x--;
	}

	printf("\nThe reversed word is : %s",string);

}


