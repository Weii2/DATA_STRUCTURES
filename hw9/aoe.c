#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePt;
typedef struct node{
	int vertex;
	int dur;
	nodePt link;
};
typedef struct{
	int count;
	nodePt link;
} hdnodes;
hdnodes graph[100];
nodePt rear[100];

void push(int x, int u, int v){
	graph[v].count++;
	nodePt temp = malloc(sizeof(*temp));
	temp->vertex =v;
	temp->dur = x; 
	temp->link = NULL;
	if(graph[u].link == NULL && rear[u] == NULL){
		graph[u].link = rear[u] = temp;
		return;
	}
	rear[u]->link = temp;
	rear[u] = temp;
}

void topSort(hdnodes graph[], int n, int earliest[], int latest[]){
	int j, k, top=-1, order[n];
	nodePt ptr;
	for(int i=0; i<n; i++)
		if(!graph[i].count){
			graph[i].count=top;	top=i;
		}
	for(int i=0; i<n; i++)
	{
		if(top==-1)
			exit(EXIT_FAILURE);
		else
		{
			j=top;
			top=graph[top].count;
			order[i]=j;
			for(ptr=graph[j].link; ptr; ptr=ptr->link)
			{
				k=ptr->vertex;
				if(earliest[k] < earliest[j] + ptr->dur)
					earliest[k] = earliest[j] + ptr->dur;
				graph[k].count--;
				if(!graph[k].count){
					graph[k].count=top;	top=k;
				}
			}
		}
	}
	for(int i=0; i<n; i++)	
		latest[i]=earliest[n-1];
	for(int i=n-2; i>=0; i--)
		for(ptr=graph[order[i]].link; ptr; ptr=ptr->link)
			if(latest[order[i]] > latest[ptr->vertex] - ptr->dur)
				latest[order[i]] = latest[ptr->vertex] - ptr->dur;
}

int main()
{
	int N;	scanf("%d",&N);
	int n, index[N][4], u, v, duration, earliest[N], latest[N], early[N], late[N], critical_ac[N], critical_num=0;
	
	for(int i=0; i<N; i++)
	{
		graph[i].count=0;	graph[i].link=NULL;	rear[i]=NULL;
		earliest[i]=0;
	};
	
	for(int i=0; i<N; i++)
	{
		scanf("%d%d%d%d",&index[i], &u, &v, &duration);
		push(duration, u, v);
		if(u<v)
			n=v;
		index[i][1]=u;	index[i][2]=v;	index[i][3]=duration;
	}
	n++;

	topSort(graph, n, earliest, latest);
	
	printf("\nevent ee    le\n");
	for(int i=0; i<n; i++)
	{
		printf("%-2d    %-2d    %-2d\n", i, earliest[i], latest[i]);
	}
	
	printf("\nact.  e     l     slack    critical\n");
	for(int i=0; i<N; i++)
	{
		early[i] = earliest[index[i][1]];
		late[i] = latest[index[i][2]]-index[i][3];
		printf("%-2d    %-2d    %-2d    %-2d       ", index[i][0], early[i], late[i], late[i]-early[i]);
		if(late[i]-early[i]==0){
			printf("Yes\n");
			critical_ac[critical_num++]=index[i][0];
		}
		else
			printf("No\n");
	}
	
	printf("\n");
	for(int i=0; i<critical_num; i++)
		printf("%d ",critical_ac[i]);
		
	return 0;
}

