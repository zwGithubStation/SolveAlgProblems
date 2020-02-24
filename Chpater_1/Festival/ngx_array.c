
/*
 * Copyright (C) ZWP
 * Problem: Festival
 */

#include <stdio.h>

int get_min_total(int cnt, int max, int *prices)
{
	int i,j,cur,answer = 0;
	for (i = 0; i <= max-cnt; i++)
	{
		cur = 0;
		for (j = i; j < i+cnt; j++)
		{
			cur += prices[j];
		}

		if (cur < answer || i == 0) //first record
			answer = cur;
	}

	return answer;
}

float get_answer(int max, int min, int *prices)
{
	int i,total;
	float answer = 0.0;
	float cur = 0.0;
	
	for (i = min; i <= max; i++)
	{
		total = get_min_total(i, max, prices);
		
		cur = (float)total / (float)i;
		if (cur < answer || i == min) //first record
			answer = cur;
	}

	return answer;
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

