#include <stdio.h>

int dig_sum(int num);

int main() {

	int x ;

	    printf("Please enter number to get the sum of its digits : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&x);


		printf("\n the sum of digits is = %d",dig_sum(x));


    return 0;
}

int dig_sum(int num)
{
	int sum = 0 ;

	while(num !=0)
	{
	  sum+= (num%10);

		num /= 10 ;
	}
	return sum ;
}
