#include <stdio.h>
#include <stdlib.h>

typedef struct listnode *listPt;
typedef struct listnode{
	int data;
	listPt link;
};
listPt graph[100]={NULL}, rear[100]={NULL};

void insert(int v1, int v2){
	listPt temp = malloc(sizeof(*temp));
	temp->data = v2; 
	temp->link = NULL;

	if(graph[v1] == NULL && rear[v1] == NULL){
		graph[v1] = rear[v1] = temp;

		return;
	}
	rear[v1]->link = temp;
	rear[v1] = temp;
}

int paint(int num_V, int num_E, int red[], int blue[], int *ri, int *bi){
	int i;
	for(i=0; i<num_V; i++)
	{
		int check=2, big=*bi, fail=0;
		listPt temp = graph[i];
		if(temp==NULL)
			continue;
		if(*ri>*bi)
			big=*ri;

		for(int j=0; j<big; j++)
		{
			if(i==red[j]){
				check=0;	fail++;
			}
			if(i==blue[j]){
				check=1;	fail++;
			}
		}
		if(fail==2)
			return fail;
		if(check==2)
			red[(*ri)++]=i;
			
		while(temp)
		{
			int check2=0;
			if(check==0 || check==2){
				for(int j=0; j<*bi; j++){
					if(temp->data==blue[j]){
						check2=1;	break;
					}
				}
				if(check2==1){
					temp=temp->link;	continue;
				}
				blue[(*bi)++]=temp->data;
			}
			else if(check==1){
				for(int j=0; j<*ri; j++){
					if(temp->data==red[j]){
						check2=1;	break;
					}
				}
				if(check2==1){
					temp=temp->link;	continue;
				}
				red[(*ri)++]=temp->data;
			}
			temp=temp->link;
		}
	}
}

int main()
{
	int num_V, num_E;
	scanf("%d%d", &num_V, &num_E);

	//int red[num_V],blue[num_V];
	int red[100]={0}, blue[100]={1}, ri=1, bi=0, fail;
	
	for(int i=0; i<num_E; i++)
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		insert(v1,v2);	
	}

	fail=paint(num_V, num_E, red, blue, &ri, &bi);
	if(fail==2)
		printf("false\n");
	else
	{
		printf("true\n");
		for(int j=0; j<ri; j++)
			printf("%d ",red[j]);
		printf("\n");
		for(int j=0; j<bi; j++)
			printf("%d ",blue[j]);
		printf("\n");
	}
	
	return 0;
}
