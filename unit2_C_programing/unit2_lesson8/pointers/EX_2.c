/*
 ============================================================================
 Name        :
 assignments.c
 Author      : Ahmedalaalotfy
 Version     :
 Copyright   : Your copyright notice
 Description : EX_2
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{

	char x[26] ;
	char *ptr = x ;
	int i ;
	for (i = 0 ; i<26 ; i++)
	{
		*ptr= 65+i ;
		ptr++;
	}

	ptr = x ;

	for (i = 0 ; i<26 ; i++)
		{
			printf("%c ",*ptr);
			ptr++;
		}

	return 0 ;
}



