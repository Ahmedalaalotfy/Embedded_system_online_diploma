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
#define NUM 10
struct student
{
	char name[50];
	float mark ;
} student[NUM];

int main()
{
	int i ;
	printf("Enter information of students: ");

	for (i=0 ; i<NUM ; i++)
	{
		printf("\nFor roll number %d",i+1);
		printf("\nEnter name: ");
		fflush(stdin); fflush(stdout);
		scanf("%s",&student[i].name);

		printf("\nEnter mark: ");
		fflush(stdin); fflush(stdout);
		scanf("%f",&student[i].mark);
	}

	printf("Displaying the information: ");

	for (i=0 ; i<NUM ; i++)
	{
		printf("\nInformation for roll number %d",i+1);
		printf("\nname: %s",student[i].name);
		printf("\nmark: %0.2f",student[i].mark);
	}

	return 0 ;
}



