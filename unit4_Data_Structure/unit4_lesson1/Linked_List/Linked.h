/*
 * Linked.h
 *
 *  Created on: Jul 5, 2023
 *      Author: ahmed
 */

#ifndef LINKED_H_
#define LINKED_H_


#define NULL (void *)0
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"


//Data
struct Sdata
{
	int ID ;
	char name[40] ;
	float hight ;
};

struct SStudent
{
	struct Sdata student;
	struct Student* PNextStudent;
};



void AddStudent();
int delete_student ();
void view_students();
void Delete_All();


#endif /* LINKED_H_ */
