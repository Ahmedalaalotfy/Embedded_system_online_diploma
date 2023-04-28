#include <stdio.h>
#define ARR_SIZE 7

int sum_100(int num);

int main() {


	printf("the sum from 1 to 100 is : %d",sum_100(100));


	return 0;
}

int sum_100(int num)
{
	int x ;

	x = num ;

	if (num !=0)
	{
		x+= sum_100(--num) ;
	}

	return x ;
}
