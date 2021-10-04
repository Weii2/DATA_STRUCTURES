#include <stdio.h>
#include <math.h>
#include <limits.h>

int choose(int N, int found[], int distance[])
{
	int min=INT_MAX, position;
	for(int i=0; i<N; i++)
	{
		if(distance[i]<min && found[i]==0)
		{
			min=distance[i];
			position=i;
		}
	}
	return position;
}

void shortPath(int u, int N, int cost[][N], int found[], int distance[], int pre[])
{
	int v;
	
	for(int i=0; i<N; i++)
	{
		found[i]=0;
		distance[i]=cost[u][i];
		pre[i]=-1;
		if(cost[u][i]!=5 && i!=0)
			pre[i]=u;
	}

	found[u]=1;	distance[u]=0;
	
	for(int i=0; i<N-2; i++)
	{
		v=choose(N, found ,distance);
		found[v]=1;
		for(int j=0; j<N; j++)
		{
			if(found[j]==0)
				if(distance[j] > abs(distance[v]+cost[v][j]) && cost[v][j]!=INT_MAX){
					distance[j] = distance[v]+cost[v][j];	pre[j]=v;
				}
		}
	}
}

int main()
{
	int N,M;
	while(scanf("%d%d", &N, &M)!=EOF )
	{
		int cost[N][N], found[N], distance[N], pre[N], path[N-1][N-1], temp, size[N-1];
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				cost[i][j]=INT_MAX;
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
	
		shortPath(0, N, cost, found, distance, pre);
		
		for(int i=0; i<N-1; i++)
		{
			temp=pre[i+1];	size[i]=0;
			path[i][0]=i+1;
			for(int j=1; j<N; j++)
			{
				path[i][j]=temp;
				size[i]++;
				temp=pre[temp];
				if(temp==-1)
					break;
			}
		}
		printf("\n");
		for(int i=0; i<N-1; i++)
		{
			if(distance[i+1]==INT_MAX)
			{
				printf("Impossible\n");
				break;
			}
			for(int j=size[i]; j>=0; j--)
			{
				printf("%d,",path[i][j]);
			}
			printf("\b %d\n",distance[i+1]);
		}
		printf("\n");
	}
	return 0;
}

