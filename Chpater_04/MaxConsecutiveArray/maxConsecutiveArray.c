
/*
 * Copyright (C) ZWP
 * Problem: MaxConsecutiveArray Chapter 4, page 78
   Consideration : 1.partial sum may exceed int-range (ignore)
   				   2.multi-answer(ignore)
   Compile: gcc -std=c99 -fsanitize=address -fno-omit-frame-pointer -O1 -g maxConsecutiveArray.c
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

//baseline
int getMaxConsecutiveArrayBase(int *str, int lenght, int *start_pos, int *end_pos)
{
	int i,j;
	int cur_sum,sum = 0;
	for (i = 0; i < lenght; i++)
	{
		cur_sum = 0;
		for (j = i; j < lenght; j++)
		{
			if (cur_sum + str[j] > sum)
			{
				sum = cur_sum + str[j];
				*start_pos = i;
				*end_pos = j;
			}
		}
	}

	return sum;
}

//better
int getMaxConsecutiveArrayBetter(int *str, int lenght, int start_pos, int end_pos)
{
	
}


//divide-and-conquer
int getMaxConsecutiveArrayDAC(int *str, int lenght, int start_pos, int end_pos)
{
	
}


//dynamic programming
int getMaxConsecutiveArrayDP(int *str, int lenght, int start_pos, int end_pos)
{
	
}

int main()
{
	int length,use_cnt,i,j,sum,start_pos,end_pos;
	int str[100][100000] = {0};
	scanf("%d", &use_cnt);
	for(i = 0 ; i < use_cnt; i++)
	{
		scanf("%d", &length);
		for(j = 0; j < length; j++)
		{
			scanf("%d",&(str[i][j]));
		}
	}

	for(i = 0; i < use_cnt; i++)
	{
		sum = getMaxConsecutiveArrayBase(str[i], strlen(str[i]), &start_pos, &end_pos);
		printf("%d %d %d", sum, start_pos, end_pos);
		if(i != use_cnt-1)
		{
			printf("\n");
		}
	}
	
	return 0;
}

