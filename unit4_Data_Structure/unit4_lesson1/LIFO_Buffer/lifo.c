/*
 * lifo.c
 *
 *  Created on: Jul 4, 2023
 *      Author: ahmed
 */
#include "lifo.h"

//APIs
LIFO_status LIFO_Add_item(LIFO_Buf_t* LIFO_buf , unsigned int item)
{

	//check lifo is valid
	if (!LIFO_buf->base || !LIFO_buf->head )
		return LIFO_Null ;
	//check lifo is full
	if (LIFO_buf->count == LIFO_buf->length )
		return LIFO_full ;
	//add value
     *(LIFO_buf->head) = item ;
     LIFO_buf->head++ ;
	 LIFO_buf->count++;
	 return LIFO_no_error ;
}
LIFO_status LIFO_get_item(LIFO_Buf_t* LIFO_buf , unsigned int* item)
{
   //check lifo is empty
	if (LIFO_buf->count == 0)
		return LIFO_empty ;

	//get item
	LIFO_buf->head-- ;
	*item= *(LIFO_buf->head);
	LIFO_buf->count--;
	return LIFO_no_error ;
}
LIFO_status LIFO_init(LIFO_Buf_t* LIFO_buf , unsigned int* buf,unsigned int length)
{
	if (buf == NULL )
		return LIFO_full ;

	LIFO_buf->base = buf;
	LIFO_buf->head = buf;
	LIFO_buf->length = length;
	LIFO_buf->count = 0;
	return LIFO_no_error ;
}
