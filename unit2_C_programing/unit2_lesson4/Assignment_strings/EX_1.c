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

	int  i , frequency=0 ;
	char string[100], y;

	printf("Please enter the string to check the length : ");
	fflush(stdin); fflush(stdout);
	gets(string);

	printf("Please enter the character to check the frequency : ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&y);

	for (i=0 ; i<sizeof(string) ; i++ )
	{
		if(string[i]==y)
		{
			frequency++;
		}
	}

	printf("\nThe frequency is : %d",frequency);

}


