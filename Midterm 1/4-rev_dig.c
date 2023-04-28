#include <stdio.h>

void rev_dig(int num);

int main() {

	int x ;

	printf("Please enter number to get the reverse of its digits : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);


	rev_dig(x);


	return 0;
}

void rev_dig(int num)
{
	int temp[50] , i ,j ;

	for (i = 0 ; num>0 ; i++)
	{
		temp[i] = (num%10);
		num /= 10 ;
	}
	printf("\nthe reversed number is : ");
	for( j=0 ; j<i ; j++)
	{
		printf("%d",temp[j]);
	}
}
