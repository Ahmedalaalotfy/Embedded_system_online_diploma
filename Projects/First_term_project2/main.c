/*
 * main.c
 *
 *  Created on: Jul 22, 2023
 *      Author: Ahmedalaalotfy
 */

#include "fifo.h"
#define student_NUM 50
void main ()
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	FIFO_Buf_t FIFO_UART ;
	Students_t student[student_NUM] ;

	int Choice;

	FIFO_init(&FIFO_UART,student, student_NUM);
	printf("Welcome to the Student Management System\n");

	while(1)
	{
		printf(" =============================\n");
		printf("\n Choose the task you want to perform \n");
		printf(" 1- Add Student  Details Manually\n");
		printf(" 2- Add Student Details From Text File\n");
		printf(" 3- Find Student Details by Roll Number\n");
		printf(" 4- Find Student Details by First Name\n");
		printf(" 5- Find Student Details by Course ID\n");
		printf(" 6- Find The Total Students Number\n");
		printf(" 7- Delete Student Details by Roll Number\n");
		printf(" 8- Update Student Details by Roll Number\n");
		printf(" 9- Show All Information\n");
		printf(" 10-Exit\n");
		printf("\n\n Enter Your Choice : ");

		scanf("%d",&Choice);

		printf(" ============================= \n");

		switch(Choice)
		{
		case 1:
			Add_Student_Manually(&FIFO_UART);
			break;

		case 2:
			Add_Student_From_File(&FIFO_UART);
			break;

		case 3:
			Find_Student_By_Roll(&FIFO_UART);
			break;

		case 4:
			Find_Student_By_First(&FIFO_UART);
			break;

		case 5:
			Find_Student_By_Course(&FIFO_UART);
			break;

		case 6:
			Total_Student_Number(&FIFO_UART);
			break;

		case 7:
			Delete_Student_By_Roll(&FIFO_UART);
			break;

		case 8:
			Update_Student_By_Roll(&FIFO_UART);
			break;

		case 9:
			Show_All_Students(&FIFO_UART);
			break;

			case 10:
				printf("Thanks !");
				exit(0);
				break;

		default:
			printf("\n Wrong Option: Try Again \n\n");
			break;
		}
	}

	return;

}
