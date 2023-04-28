#include <stdio.h>

int count_ones(int num);

int main() {

	int x ;

	printf("Please enter number to count its number of ones : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);


	printf("the number of ones is : %d",count_ones(x));


	return 0;
}

int count_ones(int num)
{
	int i , j , count=0 ;

	for (i = 0 ; i<=16 ; i++)
	{
		j = num&(1<<i) ;

		if (j > 0)
		{
			count++ ;
		}

	}

	return count ;
}
