/*
 ============================================================================
 Name        :
 assignments.c
 Author      : Ahmedalaalotfy
 Version     :
 Copyright   : Your copyright notice
 Description : EX_5
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x , y , i ;

	printf("Please enter the number of elements : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	int a[x];

	for (i=0 ; i<x ; i++ )
	{
		a[i]= (i+1)*11 ;
		printf("%d ",a[i]);
	}

	printf("\nEnter the element to be searched : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);

	printf("\n");

	for (i=0 ; i<x ; i++ )
		{
			if (a[i] == y )
			{
				printf("found in location : %d ",i+1);
				break;
			}
		}

}


