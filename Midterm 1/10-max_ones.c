#include <stdio.h>

int max_ones(int num);

int main() {

	int x ;

	printf("Please enter number to count the max number of ones between two zeros : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);


	printf("the max number of ones is : %d",max_ones(x));


	return 0;
}

int max_ones(int num)
{
	int i , j ,flag =0 , max=0 ;

	for (i = 0 ; i<=16 ; i++)
	{

		j = num&(1<<i) ;

		if (j > 0)
		{
			flag++;
		}

		else
		{
			if (flag > max )
			{
				max = flag ;
			}
			flag=0;
		}
	}
	return max ;
}
