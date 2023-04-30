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
#define PI 3.14
#define c_area(x) PI*x*x
int main()
{
	int y;
	printf("Enter the radius : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);

	printf("Area = %f",c_area(y));

	return 0 ;
}



