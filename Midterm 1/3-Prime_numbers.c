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

void Prime_numbers( int x , int y);

int main()
{
	int x, y;

	printf("please enter two numbers to check prime numbers between them : ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&x ,&y);


	Prime_numbers(x,y);

	return 0 ;

}

void Prime_numbers( int x , int y)
{
	int i , j , flag= 0;

	printf("\nthe prime numbers between %d %d is/are : ",x,y);

	for(i=x+1 ;i<y ; i++ )
	{
		for (j=2 ; j<=i/2 ; j++ , flag=0 )
		{
			if (i%j == 0)
			{
				flag = 1 ;
				break;
			}
		}
		if (flag == 0)
		{
			printf("%d ",i);
		}
	}

}


