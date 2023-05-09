/*
 * ex_1.c

 *
 *  Created on: Mar 26, 2023
 *      Author: Ahmedalaalotfy
 *
 *      EX_1
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float a[2][2] , b[2][2] , sum[2][2];
	int i , j;

	printf("Please enter the elements of matrix A  ... ");

	for (i=0 ; i<2 ; i++ )
	{
		for(j=0 ; j<2 ; j++)
		{
			printf("\nElement A[%d][%d] :",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}

	printf("\nPlease enter the elements of matrix B  ... ");

	for (i=0 ; i<2 ; i++ )
	{
		for(j=0 ; j<2 ; j++)
		{
			printf("\nElement B[%d][%d] :",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&b[i][j]);

			sum[i][j]= a[i][j] + b[i][j];
		}
	}

	printf("\nthe sum of the two matrices is :\n");

	for (i=0 ; i<2 ; i++ )
	{
		for(j=0 ; j<2 ; j++)
		{
			printf("%.2f ",sum[i][j]);

		}
		printf("\n");
	}

}


