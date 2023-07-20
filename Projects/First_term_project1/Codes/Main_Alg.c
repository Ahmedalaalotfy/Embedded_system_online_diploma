/*
 * Main_Alg.c
 *
 *  Created on: Jul 17, 2023
 *      Author: Ahmedalaalotfy
 */

#include "Main_Alg.h"

 //STATE pointer to function 
void (*Main_Alg_state)();

// variables 
int Main_Alg_Pval = 0 ;
int Main_Alg_Threshold = 20 ;

void Set_Pressure_Val(int Pval)
{ 
  if (Pval > Main_Alg_Threshold )
   {
    Main_Alg_state = STATE(Main_Alg_High_Pressure_Detect);
   }
   else 
   {
    Main_Alg_state = STATE(Main_Alg_High_Pressure_Not_Detect);
   }
}




STATE_define(Main_Alg_High_Pressure_Detect) 
{
   //STATE_name
   Main_Alg_state_id = Main_Alg_High_Pressure_Detect ; 


   //STATE_action 
   High_Pressure_Detected();

   //Get pressure value 
    Main_Alg_Pval = getPressureVal(); 

   //Set Pressure Value
    Set_Pressure_Val(Main_Alg_Pval); 


}

STATE_define(Main_Alg_High_Pressure_Not_Detect) 
{
   //STATE_name
   Main_Alg_state_id = Main_Alg_High_Pressure_Not_Detect ; 


   //Get pressure value 
    Main_Alg_Pval = getPressureVal(); 

   //Set Pressure Value
    Set_Pressure_Val(Main_Alg_Pval); 


}






