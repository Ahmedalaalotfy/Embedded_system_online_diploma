#include <stdio.h>
#define ARR_SIZE 7

int uni_num(int *ptr);

int main() {

	int x[ARR_SIZE]={4,2,5,2,5,7,4};

	printf("the unique number is : %d",uni_num(x));


	return 0;
}

int uni_num(int *ptr)
{
	int i , j , num ,flag ;

	for ( j = 0 ; j < ARR_SIZE ; j++ )
	{
         num = ptr [j];
         flag = 0 ;

		for (i = 0 ; i < ARR_SIZE ; i++)
		{
			if (num == ptr[i] )
			{
				flag++ ;

				if (flag == 2 )
				{
					break ;
				}
			}
		}
		if (flag == 1)
		{
		     break ;
		}
	}
	return num ;
}
