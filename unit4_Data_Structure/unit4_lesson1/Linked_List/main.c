/*
 * main.c
 *
 *  Created on: Jul 5, 2023
 *      Author: ahmed
 */

#include "Linked.h"


void main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char temp_text[40];

	while (1)
	{
		printf("\n======================");
		printf("\n\t Choose of the following Options \n");
		printf("\n 1: Add Student");
		printf("\n 2: Delete Student");
		printf("\n 3: view Students");
		printf("\n 4: Delete All Students");
		printf("\n 5: Linked Length");
		printf("\n 6: Get Nth");
		printf("\n 7: Reverse\n");

		gets(temp_text);
		printf("\n======================");

		switch (atoi(temp_text))
		{
		case 1:
			AddStudent();
			break;

		case 2:
			delete_student(); 
			break; 	

		case 3:
			view_students(); 
			break; 	

		case 4:
			Delete_All(); 
			break;		

		case 5:
			Linked_length();
			break;

		case 6:
			Linked_nth();
			break;

		case 7:
			Reverse_Linked();
			break;

		default:
			printf("Wrong choice");
			break ;
		}

	}

}









