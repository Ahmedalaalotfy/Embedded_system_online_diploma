/*
 * fifo.h
 *
 *  Created on: Jul 22, 2023
 *  Author: Ahmedalaalotfy
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include <string.h>

//USER Configuration

/*select element type(uint8_t , uint16_t , uint32_t , .... )*/
#define element_type Students_t
#define First_Name_Length  50
#define Last_Name_Length   50
#define Courses_num  5
//create buffer1
//#define width1 5
//element_type uart_buff[width1];


typedef struct {
	char First_Name[First_Name_Length];
	char Last_Name[Last_Name_Length];
    int  Roll_Num;
    float GPA ;
    int Courses[Courses_num];

}Students_t;

//FIFO data type
typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

typedef enum{
FIFO_no_error,
FIFO_full,
FIFO_empty,
FIFO_Null
}FIFO_Buf_Status;

//FIFO APIs
FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo ,Students_t* buf,uint32_t length);
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t* fifo ,Students_t item);
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t* fifo ,Students_t* item);
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t* fifo);
// void FIFO_print (FIFO_Buf_t* fifo);

void Add_Student_Manually(FIFO_Buf_t *FIFO_UART);
void Add_Student_From_File(FIFO_Buf_t *FIFO_UART);
void Find_Student_By_Roll(FIFO_Buf_t *FIFO_UART);
void Find_Student_By_First(FIFO_Buf_t *FIFO_UART);
void Find_Student_By_Course(FIFO_Buf_t *FIFO_UART);
void Total_Student_Number(FIFO_Buf_t *FIFO_UART);
void Delete_Student_By_Roll(FIFO_Buf_t *FIFO_UART);
void Update_Student_By_Roll(FIFO_Buf_t *FIFO_UART);
void Show_All_Students(FIFO_Buf_t *FIFO_UART);


#endif /* FIFO_H_ */
