#include <stdio.h>
#define ARR_SIZE 5

void rev_array(int *ptr);

int main() {

	int x[ARR_SIZE]={1,2,3,4,5} , i;

	rev_array(x);

	printf("the reversed array is : ");

		for ( i = 0 ; i < ARR_SIZE ; i++ )
			{
		         printf("%d",x[i]);
			}

	return 0;
}

void rev_array(int *ptr)
{
	int i  ,temp[ARR_SIZE] ;

	for ( i = 0 ; i < ARR_SIZE ; i++ )
	{
         temp[ARR_SIZE-i-1] = ptr[i];
	}

	for ( i = 0 ; i < ARR_SIZE ; i++ )
		{
	         ptr[i] = temp[i] ;

		}
}
