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

struct units
{
	float feet;
	float inch;
} distance_1 , distance_2 , sum;

int main()
{
	float x,i;
	int y ,z ,m;

	printf("Enter information for the first distance : ");

	printf("\nEnter feet : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&distance_1.feet);

	printf("\nEnter inch : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&distance_1.inch);

	printf("Enter information for the second distance : ");

	printf("\nEnter feet : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&distance_2.feet);

	printf("\nEnter inch : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&distance_2.inch);

	x = distance_1.feet + distance_2.feet + ((distance_1.inch)/12) + ((distance_2.inch)/12) ;
	sum.feet = x;

	for(i=0 ; i<4 ; i++)
	{
		x*=10;
		m = x;
		y = m%10 ;
		if (i == 0)
		{
			z = y ;
		}
		else
			z = (z*10) +y ;
	}
	sum.inch = (z*12);

	printf("\nsum of distance : %d'%0.4f''",(int)sum.feet,(sum.inch)/10000);

	return 0 ;
}



