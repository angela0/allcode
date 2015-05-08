#include "stdio.h"
#include "time.h"
#include "stdlib.h"

void swap(int v[], int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void shiftup(int v[], int i)
{
	int c;
	while(i>=1 && (c=i/2)>=1)
	{
		if(v[i]>v[c])
		{
			swap(v, i, c);
			i = c;
		}
		else
			break;
	}
}

void shiftdown(int v[], int i)
{
	int j = 1, c;

	while(j<=i && (c=2*j)<=i)
	{
		if(c+1<=i && v[c]<v[c+1])
			c++;
		if(v[j]<v[c])
		{
			swap(v, j, c);
			j = c;
		}
		else
			break;
	}
}

int main(int argc, char const *argv[])
{
	int i, j;
	int num;
	int v[100];

	srand(time(NULL));

	v[0] = 9;

	printf("source:\n");
	for(i = 1; i <= v[0]; ++i)
	{
		v[i] = rand()%100;
		printf("%d ", v[i]);
	}
	for(i = 2; i <= v[0]; ++i)
	{
		shiftup(v, i);
	}
	printf("\n");

	for(i = v[0]; i >= 2; --i)
	{
		swap(v, 1, i);
		shiftdown(v, i-1);
	}

	printf("result:\n");
	for(i = 1; i <= v[0]; ++i)
	{
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}