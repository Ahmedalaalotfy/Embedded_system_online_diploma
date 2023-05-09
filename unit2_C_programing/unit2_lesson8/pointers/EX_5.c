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

struct employee
{
	char *name ;
	int id ;
} ;

int main()
{
	struct employee employee_1={"ahmed",1000}, employee_2={"mohamed",1001} , employee_3={"alex",1002} ;
	struct employee (*arr[])={&employee_1,&employee_2,&employee_3} ;
	struct employee (*(*ptr)[]) = &arr ;

	printf("Name : %s , ID : %d",(**(*ptr+2)).name,(**(*ptr+2)).id);


	return 0 ;
}



