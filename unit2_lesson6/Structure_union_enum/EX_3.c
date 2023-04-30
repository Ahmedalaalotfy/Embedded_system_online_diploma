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

struct comlpex_numbers
{
	float real;
	float imaginary;
} number_1 , number_2 , sum;

void add_complex(struct comlpex_numbers x,struct comlpex_numbers y);

int main()
{
	printf("Enter information for the first complex number : ");

	printf("\nEnter real : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&number_1.real);

	printf("\nEnter imaginary : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&number_1.imaginary);

	printf("Enter information for the second complex number : ");

	printf("\nEnter real : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&number_2.real);

	printf("\nEnter imaginary : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&number_2.imaginary);

	add_complex(number_1,number_2);

	return 0 ;
}

void add_complex(struct comlpex_numbers x,struct comlpex_numbers y)
{
	sum.real = x.real + y.real ;
	sum.imaginary = x.imaginary + y.imaginary;

	printf("\nsum = %0.1f+%0.1fi",sum.real,sum.imaginary);
}



