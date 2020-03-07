
/*
 * Copyright (C) ZWP
 * Problem: MaxConsecutiveArray Chapter 4, page 78
 */

#include <stdio.h>

//baseline
int getMaxConsecutiveArray(int *str, int lenght, int start_pos, int end_pos)
{
	
}

//better
int getMaxConsecutiveArray(int *str, int lenght, int start_pos, int end_pos)
{
	
}


//divide-and-conquer
int getMaxConsecutiveArray(int *str, int lenght, int start_pos, int end_pos)
{
	
}


//dynamic programming
int getMaxConsecutiveArray(int *str, int lenght, int start_pos, int end_pos)
{
	
}

int main()
{
	int c,n,l,i,j;
	int range[100][2] = {0};
	int price[100][1000] = {0};
	float output = 0.0;
	scanf("%d", &c);
	for(i = 0 ; i < c; i++)
	{
		scanf("%d %d", &(range[i][0]), &(range[i][1]));
		for(j = 0; j < range[i][0]; j++)
		{
			scanf("%d",&(price[i][j]));
		}
	}

	for(i = 0 ; i < c; i++)
	{
		output = get_answer(range[i][0], range[i][1], &(price[i][0]));
		printf("%.10f", output);
		if(i != c-1)
		{
			printf("\n");
		}
	}
	
	return 0;
}

