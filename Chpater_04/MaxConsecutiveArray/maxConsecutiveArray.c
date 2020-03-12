
/*
 * Copyright (C) ZWP
 * Problem: MaxConsecutiveArray Chapter 4, page 78
   Consideration : 
   			 1.partial sum may exceed int-range (ignore)
   			 2.multi-answer(ignore)
   solution:
   			 1.baseline 
   			 2.divide-and-conquer
   			 3.dp/greedy : SumMaxInclude(i) = Max(SumMaxInclude(i-1), 0) + A(i)
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
	int cur_sum,sum = INT_MIN;
	for (i = 0; i < lenght; i++)
	{
		if (sum < str[i])
		{
			sum = str[i];
			*start_pos = i;
			*end_pos = i;
		}
		cur_sum = str[i];
		
		for (j = i+1; j < lenght; j++)
		{
			cur_sum = cur_sum + str[j];
			if (cur_sum > sum)
			{
				sum = cur_sum;
				*start_pos = i;
				*end_pos = j;
			}
		}
	}

	return sum;
}


//divide-and-conquer

int getMaxConsecutiveArrayDACWithPos(int *str, int iter_begin, int iter_end, int *start_pos, int *end_pos)
{
	int mid_pos,i;
	int sum = 0;
	int left_conj_max = INT_MIN;
	int right_conj_max = INT_MIN;

	int left_no_conj_max = INT_MIN;
	int right_no_conj_max = INT_MIN;
	int start_temp1,end_temp1,start_temp2,end_temp2;
	
	if (iter_begin == iter_end)
	{
		*start_pos = iter_begin;
		*end_pos = iter_end;
		return str[iter_begin];
	}
		
	mid_pos = (iter_begin+iter_end) / 2;

	for (i = mid_pos; i >= iter_begin; i--)
	{
		sum += str[i];
		if (sum > left_conj_max)
		{
			start_temp1 = i;
			left_conj_max = sum;
		}
	}

	sum = 0;
	for (i = mid_pos+1; i <= iter_end; i++)
	{
		sum += str[i];
		if (sum > right_conj_max)
		{
			end_temp1 = i;
			right_conj_max = sum;
		}
	}

	left_no_conj_max = getMaxConsecutiveArrayDACWithPos(str, iter_begin, mid_pos, start_pos, end_pos);
	start_temp2 = *start_pos;
	end_temp2 = *end_pos;
	right_no_conj_max = getMaxConsecutiveArrayDACWithPos(str, mid_pos+1, iter_end, start_pos, end_pos);

	if (left_no_conj_max >= right_no_conj_max && left_no_conj_max >= left_conj_max + right_conj_max)
	{
		*start_pos = start_temp2;
		*end_pos = end_temp2;
		return left_no_conj_max;
	}
	else if (right_no_conj_max >= left_no_conj_max && right_no_conj_max >= left_conj_max + right_conj_max)
	{
		return right_no_conj_max;
	}
	else
	{
		*start_pos = start_temp1;
		*end_pos = end_temp1;
		return left_conj_max + right_conj_max;
	}
	
}


int getMaxConsecutiveArrayDAC(int *str, int iter_begin, int iter_end)
{
	int mid_pos,i;
	int sum = 0;
	int left_conj_max = INT_MIN;
	int right_conj_max = INT_MIN;

	int left_no_conj_max = INT_MIN;
	int right_no_conj_max = INT_MIN;
	//int start_temp1,end_temp1,start_temp2,end_temp2,targ;
	
	if (iter_begin == iter_end)
	{
		//*start_pos = iter_begin;
		//*end_pos = iter_end;
		printf("[%d - %d], maxSum:%d\n", iter_begin, iter_end, str[iter_begin]);
		return str[iter_begin];
	}
		
	mid_pos = (iter_begin+iter_end) / 2;

	for (i = mid_pos; i >= iter_begin; i--)
	{
		sum += str[i];
		if (sum > left_conj_max)
		{
			//start_temp1 = i;
			left_conj_max = sum;
		}
	}

	sum = 0;
	for (i = mid_pos+1; i <= iter_end; i++)
	{
		sum += str[i];
		if (sum > right_conj_max)
		{
			//end_temp1 = i;
			right_conj_max = sum;
		}
	}

	left_no_conj_max = getMaxConsecutiveArrayDAC(str, iter_begin, mid_pos);
	//start_temp2 = *start_pos;
	//end_temp2 = *end_pos;
	right_no_conj_max = getMaxConsecutiveArrayDAC(str, mid_pos+1, iter_end);

	if (left_no_conj_max >= right_no_conj_max && left_no_conj_max >= left_conj_max + right_conj_max)
	{
		//*start_pos = start_temp2;
		//*end_pos = end_temp2;
		printf("[%d - %d], maxSum(left no conj):%d\n", iter_begin, iter_end, left_no_conj_max);
		return left_no_conj_max;
	}
	else if (right_no_conj_max >= left_no_conj_max && right_no_conj_max >= left_conj_max + right_conj_max)
	{
		printf("[%d - %d], maxSum(right no conj):%d\n", iter_begin, iter_end, right_no_conj_max);
		return right_no_conj_max;
	}
	else
	{
		//*start_pos = start_temp1;
		//*end_pos = end_temp1;
		printf("[%d - %d], maxSum(conj):left(%d) right(%d)\n", iter_begin, iter_end, left_conj_max, right_conj_max);
		return left_conj_max + right_conj_max;
	}
	
}


//dynamic programming || greedy
#define MAX(x, y) ((x) > (y) ? (x) : (y))
int getMaxConsecutiveArrayDP(int *str, int length)
{
	int sum = INT_MIN;
	int curSumMax = 0;
	int i;
	
	for (i = 0; i < length; i++)
	{
		curSumMax = MAX(curSumMax, 0) + str[i];
		sum = MAX(sum, curSumMax);
	}

	return sum;
}



int main()
{
	int use_cnt,i,j,sum,start_pos,end_pos;
	int str[100][10000] = {0};
	int length[100] = {0};
	scanf("%d", &use_cnt);
	for(i = 0 ; i < use_cnt; i++)
	{
		scanf("%d", &(length[i]));
		for(j = 0; j < length[i]; j++)
		{
			scanf("%d",&(str[i][j]));
		}
	}

	for(i = 0; i < use_cnt; i++)
	{
		//sum = getMaxConsecutiveArrayBase(str[i], length[i], &start_pos, &end_pos);
		//sum = getMaxConsecutiveArrayDAC(str[i], 0, length[i]-1);
		//sum = getMaxConsecutiveArrayDACWithPos(str[i], 0, length[i]-1, &start_pos, &end_pos);
		sum = getMaxConsecutiveArrayDP(str[i], length[i]);
		printf("maxSum=%d", sum);
		//printf("maxSum=%d [%d %d]", sum, start_pos, end_pos);
		if(i != use_cnt-1)
		{
			printf("\n");
		}
	}
	
	return 0;
}

