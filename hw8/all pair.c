#include <stdio.h>
#include <math.h>
#include <limits.h>

void allCosts(int N, int cost[][N], int distance[][N], int pre[][N])
{
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			distance[i][j]=cost[i][j];

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(cost[i][j]==0 || cost[i][j]==50000)
				pre[i][j]=-1;
			else
				pre[i][j]=i;
		}
	}
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)	
				if(distance[i][j] > distance[i][k]+distance[k][j] && distance[i][k]!=50000 && distance[k][j]!=50000)
				{
					distance[i][j] = distance[i][k]+distance[k][j];
					pre[i][j] = k;
				}
}

int main()
{
	int N,M;
	while(scanf("%d%d", &N, &M)!=EOF )
	{
		int cost[N][N], distance[N][N], pre[N][N], path[N-1][N-1], temp, size[N-1];
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				cost[i][j]=50000;
				if(i==j)
					cost[i][j]=0;
			}
		} 
		for(int i=0; i<M; i++)
		{
			int u,v,w;
			scanf("%d%d%d", &u, &v, &w);
			cost[u][v]=w;
		}
		allCosts(N, cost, distance, pre);
		printf("\n");
		for(int k=0; k<N; k++)
		{
			for(int i=0; i<N; i++)
			{
				size[i]=0;
				temp=pre[k][i];
				path[i][size[i]++]=i;
				for(int j=0; j<N; j++)
				{
					if(temp == -1)
						break;
					path[i][size[i]++]=temp;
					if(temp == k && size[i]>3)
						break;
					temp=pre[k][temp];
				}
			}
			for(int i=0; i<N; i++)
			{
				if(size[i]-1 == 0)
					continue;
				for(int j=size[i]-1; j>=0; j--)
				{
					printf("%d,",path[i][j]);
				}
				printf("\b %d\n",distance[k][i]);
			}
		}
		printf("\n");
	}
	return 0;
}

