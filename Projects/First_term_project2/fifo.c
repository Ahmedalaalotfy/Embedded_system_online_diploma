/*
 * fifo.c
 *
 *  Created on: Jul 22, 2023
 *  Author: Ahmedalaalotfy
 */

#include "fifo.h"

FILE *Student_Data ;

static Students_t* search_by_roll (FIFO_Buf_t *FIFO_UART, int roll_num);

//FIFO APIs
FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo ,Students_t* buf,uint32_t length)
{
	if (buf == NULL )
		return FIFO_Null ;

	fifo->base = buf ;
	fifo->head = fifo->base ;
	fifo->tail = fifo->base ;
	fifo->length = length ;
	fifo->count = 0 ;
	return FIFO_no_error ;
}
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t* fifo ,Students_t item)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null ;

	//fifo is full
	if (FIFO_IS_FULL(fifo) == FIFO_full )
		return FIFO_full;


	*(fifo->head) = item ;
	fifo->count++;

	//circular fifo
	if (fifo->head == (fifo->base + (sizeof(element_type)*fifo->length)))
		fifo->head = fifo->base ;
	else
		fifo->head++;

	return FIFO_no_error ;

}
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t* fifo ,Students_t* item)
{
	if (!fifo->base ||!fifo->head || !fifo->tail)
		return FIFO_Null ;

	//check empty
	if (fifo->count == 0)
		return FIFO_empty ;

	*item = *(fifo->tail);
	fifo->count--;

	//circular fifo
	if (fifo->tail == (fifo->tail + (sizeof(element_type)*fifo->length)))
		fifo->tail = fifo->base ;
	else
		fifo->tail++;
	return FIFO_no_error ;

}
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t* fifo)
{
	if (!fifo->base ||!fifo->head || !fifo->tail)
		return FIFO_Null ;

	//fifo is full
	if (fifo->count >= fifo->length)
	{
		printf("FIFO is full");
		return FIFO_full;
	}
	return FIFO_no_error ;
}
/* void FIFO_print (FIFO_Buf_t* fifo)
{
	element_type* temp ;
	int i ;
	if (fifo->count == 0)
	{
		printf("fifo is empty \n");
	}

	else
	{
		temp = fifo->tail ;
		printf("\n======== fifo print =========\n");
		for (i=0 ; i<fifo->count ; i++)
		{
			printf("\t %X \n",*temp);
			temp++;
		}
		printf("\n========\n");
	}
} */


void Add_Student_Manually(FIFO_Buf_t *FIFO_UART)
{
	Students_t New_Student ;
	int i ;

	printf("\n=====================\n");
	printf("Add student details\n");
	printf("\n=====================\n");

	printf("Enter Roll Number : \n");
	scanf("%d",&New_Student.Roll_Num);

	if(search_by_roll (FIFO_UART, New_Student.Roll_Num)!=NULL)
	{
		printf("The Roll number %d is already exist \n",New_Student.Roll_Num);
		return;
	}

	printf("Enter First name : \n");
	scanf("%s",New_Student.First_Name);

	printf("Enter Last name : \n");
	scanf("%s",New_Student.Last_Name);

	printf("Enter GPA : \n");
	scanf("%f",&New_Student.GPA);


	for (i=0 ; i<Courses_num ; i++)
	{
		printf("Enter Course ID number %d : \n",i+1);
		scanf("%d",&New_Student.Courses[i]);
	}


	if (FIFO_enqueue(FIFO_UART ,New_Student)== FIFO_no_error)
	{
		printf("Added successfully \n");
	}
	else
	{
		printf("Failed \n");
	}

}


void Add_Student_From_File(FIFO_Buf_t *FIFO_UART)
{

	int i;
	Students_t New_Student;

	Student_Data = fopen("Student_Data.txt","r");

	if(Student_Data == NULL)
	{
		printf("Adding Data from file failed. \n");
		return;
	}

	while(!feof(Student_Data))
	{
		fscanf(Student_Data, "%d", &New_Student.Roll_Num);


		if(search_by_roll (FIFO_UART, New_Student.Roll_Num)!=NULL)
		{
			printf("The Roll number %d is already exist \n",New_Student.Roll_Num);

			fscanf(Student_Data, "%*[^\n]");
			continue;
		}

		fscanf(Student_Data, "%s", New_Student.First_Name);
		fscanf(Student_Data, "%s", New_Student.Last_Name);
		fscanf(Student_Data, "%f", &New_Student.GPA);


		for (i = 0; i < Courses_num; ++i)
		{
			fscanf(Student_Data, "%d", &New_Student.Courses[i]);
		}

		if((FIFO_enqueue(FIFO_UART, New_Student))== FIFO_no_error)
		{
			printf("Added successfully\n");
		}
		else
		{
			printf("Failed\n");
			return;
		}
	}

	fclose(Student_Data);
}

void Find_Student_By_Roll(FIFO_Buf_t *FIFO_UART)
{

	if (FIFO_UART->count == 0)
	{
		printf("List is empty \n");
		return;
	}

	Students_t *Student_Temp ;
	int Roll_Temp , j;

	printf("\nEnter the Roll number You want to search about : ");
	scanf("%d",&Roll_Temp);

	Student_Temp = search_by_roll (FIFO_UART,Roll_Temp);

	if (Student_Temp == NULL)
	{
		printf("The student with roll number %d is not found \n",Roll_Temp);
		return;
	}

	else
	{
		printf("The student with roll number %d is found :\n",Roll_Temp);
		printf("First Name: %s\n",Student_Temp->First_Name);
		printf("Last Name: %s\n",Student_Temp->Last_Name);
		printf("GPA: %0.2f\n",Student_Temp->GPA);
		for (j=0 ; j<Courses_num ; j++)
		{
			printf("Course ID number %d : %d\n",j+1,Student_Temp->Courses[j]);
		}

	}

}

void Find_Student_By_First(FIFO_Buf_t *FIFO_UART)
{
	if (FIFO_UART->count == 0)
	{
		printf("List is empty \n");
		return;
	}

	int i ,j ,x, flag=0;
	char Temp_Name[First_Name_Length] ;
	Students_t *student = FIFO_UART->tail;

	printf("Enter the name you want to search about : \n");
	scanf("%s",Temp_Name);

	for (i = 0; i< FIFO_UART->count; i++)
	{
		x= strcmp(Temp_Name,student->First_Name);
		if (x == 0)
		{
			printf("Roll Number: %d\n",student->Roll_Num);
			printf("First Name: %s\n",student->First_Name);
			printf("Last Name: %s\n",student->Last_Name);
			printf("GPA: %0.2f\n",student->GPA);
			for (j=0 ; j<Courses_num ; j++)
			{
				printf("Course ID number %d : %d\n",j+1,student->Courses[j]);
			}
		}

		else
		{
			flag++;
		}


		if((student + 1) == (FIFO_UART->base + FIFO_UART->length))
		{
			student = FIFO_UART->base;

		}
		else
		{
			student++;
		}
	}

	if (flag == FIFO_UART->count )
	{
		printf("the name is not found \n");
	}
}

void Find_Student_By_Course(FIFO_Buf_t *FIFO_UART)
{
	if (FIFO_UART->count == 0)
	{
		printf("List is empty \n");
		return;
	}

	int i ,k, flag=0;
	int Temp_Course ;
	Students_t *student = FIFO_UART->tail;

	printf("Enter the Course ID you want to search about : \n");
	scanf("%d",&Temp_Course);

	for (i = 0; i< FIFO_UART->count; i++)
	{
		for(k = 0; k< Courses_num; k++)
		{
			if (Temp_Course == student->Courses[k])
			{
				printf("Roll Number: %d\n",student->Roll_Num);
				printf("First Name: %s\n",student->First_Name);
				printf("Last Name: %s\n",student->Last_Name);
				printf("GPA: %0.2f\n",student->GPA);

			}

			else
			{
				flag++;
			}
		}


		if((student + 1) == (FIFO_UART->base + FIFO_UART->length))
		{
			student = FIFO_UART->base;

		}
		else
		{
			student++;
		}
	}

	if (flag == FIFO_UART->count * Courses_num  )
	{
		printf("There is no student in this course \n");
	}
}

void Total_Student_Number(FIFO_Buf_t *FIFO_UART)
{
	if (FIFO_UART->count == 0)
	{
		printf("List is empty \n");
		return;
	}

	printf("The total number of students is : %d\n",FIFO_UART->count);
}

void Delete_Student_By_Roll(FIFO_Buf_t *FIFO_UART)
{
	Students_t *Temp_Student ;
	int  Temp_Roll;

	printf("\n=====================\n");
	printf("Delete student details\n");
	printf("\n=====================\n");

	printf("Enter Roll Number : \n");
	scanf("%d",&Temp_Roll);

	Temp_Student = search_by_roll (FIFO_UART,Temp_Roll) ;

	if(Temp_Student==NULL)
	{
		printf("The Roll number %d is not exist \n",Temp_Roll);
		return;
	}


	if (FIFO_dequeue(FIFO_UART ,Temp_Student)== FIFO_no_error)
	{
		printf("Deleted successfully \n");
	}
	else
	{
		printf("Failed \n");
	}
}

void Update_Student_By_Roll(FIFO_Buf_t *FIFO_UART)
{
	if (FIFO_UART->count == 0)
	{
		printf("List is empty \n");
		return;
	}

	Students_t *Student_Temp ;
	int Roll_Temp , i , choice;

	printf("\nEnter the Roll number You want to Update : ");
	scanf("%d",&Roll_Temp);

	Student_Temp = search_by_roll (FIFO_UART,Roll_Temp);

	if (Student_Temp == NULL)
	{
		printf("The student with roll number %d is not found \n",Roll_Temp);
		return;
	}

	printf("Choose the Data number You want to Update : \n");
	printf("\t1- First Name\n");
	printf("\t2- Last Name\n");
	printf("\t3- GPA\n");
	printf("\t4- Courses IDs\n");
	scanf("%d",&choice);

	switch(choice)
	{
	case 1:
		printf("Enter The new First Name : \n");
		scanf("%s",Student_Temp->First_Name);
		printf("Updated .. \n");
		break;

	case 2:
		printf("Enter The new Last Name : \n");
		scanf("%s",Student_Temp->Last_Name);
		printf("Updated .. \n");
		break;

	case 3:
		printf("Enter The new GPA : \n");
		scanf("%f",&Student_Temp->GPA);
		printf("Updated .. \n");
		break;

	case 4:
		printf("Enter The new Course IDs : \n");
		for (i = 0 ; i<Courses_num ; i++)
		{
			printf("Enter Course ID number %d : \n",i+1);
			scanf("%d",&Student_Temp->Courses[i]);
		}

		printf("Updated .. \n");
		break;

	default:
		printf("Wrong Choice\n");
		break;

	}
}


void Show_All_Students(FIFO_Buf_t *FIFO_UART)
{
	int i ,j ;


	if (FIFO_UART->count == 0)
	{
		printf("List is empty \n");
		return;
	}



	Students_t *student = FIFO_UART->tail;

	for (i = 0; i< FIFO_UART->count; i++)
	{
		printf("Roll Number: %d\n",student->Roll_Num);
		printf("First Name: %s\n",student->First_Name);
		printf("Last Name: %s\n",student->Last_Name);
		printf("GPA: %0.2f\n",student->GPA);
		for (j=0 ; j<Courses_num ; j++)
		{
			printf("Course ID number %d : %d\n",j+1,student->Courses[j]);
		}

		if((student + 1) == (FIFO_UART->base + FIFO_UART->length))
		{
			student = FIFO_UART->base;
		}
		else
		{
			student++;
		}
	}

}


static Students_t* search_by_roll (FIFO_Buf_t *FIFO_UART, int roll_num)
{
	int i ;

	Students_t *student = FIFO_UART->tail;

	for (i = 0; i< FIFO_UART->count; i++)
	{
		if (student->Roll_Num == roll_num)
		{
			break;
		}

		if((student + 1) == (FIFO_UART->base + FIFO_UART->length))
		{
			student = FIFO_UART->base;
		}
		else
		{
			student++;
		}
	}

	if(i == FIFO_UART->count)
	{
		student = NULL;
	}

	return student;
}

