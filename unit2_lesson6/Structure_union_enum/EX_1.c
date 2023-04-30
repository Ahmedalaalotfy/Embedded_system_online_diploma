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


struct student
{
	char name[50];
	int roll;
	float mark ;
} student_1;

int main()
{
	printf("Enter information of students: ");

	printf("\nEnter name: ");
	fflush(stdin); fflush(stdout);
	scanf("%s",&student_1.name);

	printf("\nEnter roll number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&student_1.roll);

	printf("\nEnter mark: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&student_1.mark);

	printf("\nDisplay data: ");
	printf("\nname: %s",student_1.name);
	printf("\nroll: %d",student_1.roll);
	printf("\nmark: %0.2f",student_1.mark);

	return 0 ;
}



