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

void Reverse_sentence();

int main()
{

	printf("please enter sentence to be reversed : ");
	fflush(stdin); fflush(stdout);
	Reverse_sentence();
	return 0 ;
}

void Reverse_sentence()
{
	char x;

	scanf("%c",&x);
	if (x != '\n')
	{
		Reverse_sentence();
		printf("%c",x);
	}

}
