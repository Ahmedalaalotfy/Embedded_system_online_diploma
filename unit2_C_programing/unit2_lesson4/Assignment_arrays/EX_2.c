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

int main(void) {

	int x , i;
	float sum=0 ;

	printf("Please enter the number of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	float a[x];

	for (i=0 ; i<x ; i++ )
	{
			printf("\n%d. Enter number : ",i+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&a[i]);

			sum+= a[i];
	}


	printf("the average is : %f",sum/x);

}


