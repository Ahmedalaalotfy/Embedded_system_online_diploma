/*
 ============================================================================
 Name        :
 assignments.c
 Author      : Ahmedalaalotfy
 Version     :
 Copyright   : Your copyright notice
 Description : EX_4
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x , y , i , j;

	printf("Please enter the number of elements : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	int a[x];

	for (i=0 ; i<x ; i++ )
	{
		a[i]= i+1;
		printf("%d ",a[i]);
	}

	printf("\nEnter the element to be inserted : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);

	printf("\nEnter the location : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&j);


	printf("\n");

	for (i=0 ; i<x ; i++ )
		{
			if (i == (j-1))
			{
				a[i]= y;
			}
			printf("%d ",a[i]);
		}


}


