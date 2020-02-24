
/*
 * Copyright (C) ZWP
 * Problem: Festival
 */

#include <stdio.h>

int main()
{
	int c,n,l,i,j;
	int price[100][1000] = {0};
	scanf("%d", &c);
	for(i = 0 ; i < c ; i++)
	{
		scanf("%d %d", &n, &l);
		for(j = 0; j < n; j++)
		{
			scanf("%d",&(price[i][j]));
		}
	}

	/*test*/
	for(i = 0 ; i < 100 ; i++)
	{
		for(j = 0; j < 1000; j++)
		{
			printf("%d ",price[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

