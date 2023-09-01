<<<<<<< HEAD
/*
name : Ahmedalaalotfy
date : 1/9/2002
version : 1.0
swc : BIT MATH 
describtion :

*/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM) REG|=(1<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM) REG&=(~(1<<BIT_NUM)) 
#define TOG_BIT(REG,BIT_NUM) REG^=(1<<BIT_NUM) 
#define GET_BIT(REG,BIT_NUM) ((REG>>BIT_NUM)&1)

=======
/*
name : Ahmedalaalotfy
date : 1/9/2002
version : 1.0
swc : BIT MATH 
describtion :

*/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NUM) REG|=(1<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM) REG&=(~(1<<BIT_NUM)) 
#define TOG_BIT(REG,BIT_NUM) REG^=(1<<BIT_NUM) 
#define GET_BIT(REG,BIT_NUM) ((REG>>BIT_NUM)&1)

>>>>>>> bd560d5b990063eaea5362409ab455504410aa69
#endif 