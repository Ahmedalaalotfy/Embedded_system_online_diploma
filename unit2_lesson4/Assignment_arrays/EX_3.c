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

int main(void) {

	int x , y , i , j;

	printf("Please enter the number of rows : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	printf("Please enter the number of columns : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&y);

	float a[x][y];

	for (i=0 ; i<x ; i++ )
	{
		for (j=0 ; j<y ; j++ )
		{
			printf("\nEnter element A[%d][%d] : ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}

	printf("\nThe entered matrix : \n");

	for (i=0 ; i<x ; i++ )
		{
			for (j=0 ; j<y ; j++ )
			{
				printf("%.2f ",a[i][j]);
			}
			printf("\n");
		}

	printf("\nTranspose of matrix : \n");

	for (i=0 ; i<y ; i++ )
			{
				for (j=0 ; j<x ; j++ )
				{
					printf("%.2f ",a[j][i]);
				}
				printf("\n");
			}
}


