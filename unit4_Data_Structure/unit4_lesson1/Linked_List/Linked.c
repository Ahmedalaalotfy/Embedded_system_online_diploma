/*
 * Linked.c
 *
 *  Created on: Jul 5, 2023
 *      Author: ahmed
 */

#include "Linked.h"

struct SStudent* gpFirstStudent=NULL ;


void AddStudent()
{
	struct SStudent* pNewStudent ;
	struct SStudent* pLastStudent ;
	char temp_text[40];

	//check list is empty
	if(gpFirstStudent==NULL)
	{
		//create new record
		pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));

		//assign it to gpfirst
		gpFirstStudent = pNewStudent ;
	}
	else
	{
		//navigate untill reach to the last record
		pLastStudent = gpFirstStudent ;

		while(pLastStudent->PNextStudent)
		{
			pLastStudent = pLastStudent->PNextStudent;
		}

		//create new record
		pNewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
		pLastStudent->PNextStudent = pNewStudent ;
	}

	//fill new record
	printf("\n Enter the ID:");
	gets(temp_text);
	pNewStudent->student.ID = atoi(temp_text);

	printf("\n Enter the name:");
	gets(pNewStudent->student.name);

	printf("\n Enter the Hight:");
	gets(temp_text);
	pNewStudent->student.hight = atof(temp_text);

	//set the next pointer (new student) to null

	pNewStudent->PNextStudent= NULL ;
}

int delete_student ()
{
	char temp_text[40];
	unsigned int selected_id;

	//get the sekected id
	printf("\n Enter the student ID to be deleted:");
	gets(temp_text);
	selected_id = atoi(temp_text);

	//list is not empty
	if(gpFirstStudent)
	{
		struct SStudent* pSelectedStudent = gpFirstStudent ;
		struct SStudent* pPreviousStudent = NULL ;

		//Loop on all records
		while(pSelectedStudent)
		{
			//compare each node with the selected id
			if (pSelectedStudent->student.ID == selected_id)
			{
				if (pPreviousStudent) //the first is not the selected one
				{
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent ;
				}
				else //the first is the selected one
				{
					gpFirstStudent = pSelectedStudent->PNextStudent;
				}
				free(pSelectedStudent);
				return 1 ;
			}
			pPreviousStudent = pSelectedStudent ;
			pSelectedStudent = pSelectedStudent->PNextStudent ;
		}

	}

	printf("cannot fined the student ID ");
	return 0;
}


void view_students()
{
	struct SStudent* pCurrentStudent = gpFirstStudent ;
	unsigned int count = 0 ;

	if (gpFirstStudent == NULL)
	{
		printf("\nThis list is empty");
	}

	while (pCurrentStudent)
	{
		printf("\nRecord number %d",count+1);

		printf("\n \t ID : %d",pCurrentStudent->student.ID);
		printf("\n \t Name : %s",pCurrentStudent->student.name);
		printf("\n \t Height : %f",pCurrentStudent->student.hight);

		pCurrentStudent = pCurrentStudent->PNextStudent ;
		count++;
	}

}

void Delete_All()
{
	struct SStudent* pCurrentStudent = gpFirstStudent ;
	if (gpFirstStudent == NULL)
	{
		printf("\nThis list is empty");
	}

	while ( pCurrentStudent)
	{
		struct SStudent* pTempStudent =  pCurrentStudent ;
		pCurrentStudent =  pCurrentStudent->PNextStudent ;
		free(pTempStudent);
	}
	gpFirstStudent = NULL ;


	printf("\nAll student deleted ===== ");

}

void Linked_length()
{
	struct SStudent* pCurrentStudent = gpFirstStudent ;
	unsigned int count = 0 ;

	if (gpFirstStudent == NULL)
	{
		printf("\nThis list is empty");
	}

	else {
		while (pCurrentStudent)
		{
			pCurrentStudent = pCurrentStudent->PNextStudent ;
			count++;
		}

		printf("\nLinked Length : %d",count);

	}

}


void Linked_nth()
{
	struct SStudent* pCurrentStudent = gpFirstStudent ;
	unsigned int count = 0 ,n;

	if (gpFirstStudent == NULL)
	{
		printf("\nThis list is empty");
	}

	else {
		printf("\nChoose the nth : \n");
		scanf("%d",&n);

		while (pCurrentStudent)
		{

			if (n == count+1)
			{
				printf("\n \t ID : %d",pCurrentStudent->student.ID);
				printf("\n \t Name : %s",pCurrentStudent->student.name);
				printf("\n \t Height : %f",pCurrentStudent->student.hight);

			}

				count++;
				pCurrentStudent = pCurrentStudent->PNextStudent ;

		}

	}

}

void Reverse_Linked()
{
	struct SStudent* pCurrentStudent = gpFirstStudent ;
	struct SStudent* pNextStudent = NULL ;
	struct SStudent* pPreviousStudent = NULL ;

		unsigned int count = 0 ;

		if (gpFirstStudent == NULL)
		{
			printf("\nThis list is empty");
		}

		else {
			while (pCurrentStudent)
			{
				pNextStudent = pCurrentStudent->PNextStudent ;
				pCurrentStudent->PNextStudent = pPreviousStudent;
				pPreviousStudent = pCurrentStudent ;
				pCurrentStudent = pNextStudent ;

			}

			gpFirstStudent = pPreviousStudent ;

			printf("\nReversed !");

		}



}


