#include <stdio.h>
#define ARR_SIZE 50

void rev_name(char *ptr);

int main() {

	char x[ARR_SIZE]= "ahmed alaa eldin lotfy";
	rev_name(x);
	return 0;
}

void rev_name(char *ptr)
{
	int i , j , k , count=0 , flag;

	for (i = 0 ; ptr[i] != '\0' ; i++)
	{
		if (ptr[i] == ' ')
			count++;
	}
	for (j = (i-2) ; j >=0 ; j--)
	{
		if ( ptr[j] == ' ')
			break;
	}
	while (count != 0)
	{
		flag = 0 ;
		for ( k = j ; k <= (i-1) ; k++ )
		{
			printf("%c",ptr[k+1]);
			flag++;
		}

		j-= flag ;
		i-= flag ;
		count -- ;
	}

	for (j = 0 ; ptr[j] != ' ' ; j++)
	{
		printf("%c",ptr[j]);
	}
}
