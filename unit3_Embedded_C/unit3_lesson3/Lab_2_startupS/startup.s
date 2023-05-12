/* startup_cortexM3.s */ 
/* Eng : Ahmedalaalotfy */

/* SRAM start from 0x20000000 */ 

.section .vectors

.word 0x20001000        /* stack top address */
.word  _reset				/* 1  reset section */
.word  _Vector_handler		/* 2  NMI (non maskable interrupt) */
.word  _Vector_handler 		/* 3  Hard Fault */
.word  _Vector_handler 		/* 4  MM Fault (Memory Management) */
.word  _Vector_handler 		/* 5  Bus Fault */
.word  _Vector_handler 		/* 6  Usage Fault */
.word  _Vector_handler 		/* 7  RESERVED */
.word  _Vector_handler 		/* 8  RESERVED */
.word  _Vector_handler 		/* 9  RESERVED */
.word  _Vector_handler 		/* 10 RESERVED */
.word  _Vector_handler 		/* 11 SV call */
.word  _Vector_handler 		/* 12 Debug reserved */
.word  _Vector_handler 		/* 13 RESERVED */
.word  _Vector_handler 		/* 14 PendSV */
.word  _Vector_handler 		/* 15 SysTick */
.word  _Vector_handler 		/* 16 IRQ0 */
.word  _Vector_handler 		/* 17 IRQ1 */
.word  _Vector_handler 		/* 18 IRQ2 */
.word  _Vector_handler		/* 19 ... */

.section .text 

_reset: 
	bl main 
	b . 

.thumb_func
_Vector_handler:
	b _reset