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

int Power(int x , int y);

int main()
{

	int x , y ;

	printf("please enter the base number : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	printf("please enter the power : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y);

	printf("the result is : %d",Power(x,y))  ;
	return 0 ;
}

int Power(int x , int y)
{
	int p = 1 ;
	if (y > 0)
	{
		p *= x*Power(x,y-1);
	}

	return p ;
}
