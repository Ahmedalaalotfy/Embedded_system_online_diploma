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

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);

	int x[15] ;
	int *ptr = x;
	int i , y;

	printf("Enter the number of elements (max15): ");
	scanf("%d",&y);

	printf("\nthe the element of the array: ");

	for (i = 0 ; i<y ; i++)
		{
			printf("\nelement %d : ",i+1);
			scanf("%d",&x[i]);
		}
	ptr = &x[y-1];
	printf("\nthe reversed array : ");

	for (i = (y-1) ; i>=0 ; i--)
	{
		printf("\nelement %d : %d",i+1,*ptr);
		ptr--;
	}
	return 0 ;
}



