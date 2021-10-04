#include <stdio.h>
#include <stdlib.h>
#define Max_Elements 200 
#define heap_full(n)  (n==Max_Elements-1)
#define heap_empty(n) (!n)

typedef struct{
	int key;
	}element;
element heap[Max_Elements];
int n=0;

void Insert(element item, int *n)
{
	int i;
	if(heap_full(*n)){
		printf("The Heap is Full!\n");	exit(EXIT_FAILURE);
	}
	i = *n+1;
	while( (i!=1) && (item.key>heap[i/2].key) ){
		heap[i]=heap[i/2];	i=i/2;
	}
	heap[i]=item;	*n=*n+1;
}

void Heapify(int *n)
{
	int parent=1, child=2, max;
	element temp;
	while(child <= *n)
	{
		if(heap[parent].key < heap[child].key)
			max=child;
		else
			max=parent;
		if(heap[max].key < heap[child+1].key)
			max=child+1;

		temp=heap[parent];
		heap[parent]=heap[max];
		heap[max]=temp;
		
		parent++;
		child=parent*2;
	}
}

void zero(int *n)
{
	while( !heap_empty(*n) )
	{
		heap[*n].key=0;
		*n=*n-1;
	}
}

int main()
{
	int T, M, N, check;
	element X[M+1];
	
	scanf("%d",&T);
	int money[T];
	for(int i=0; i<T; i++)
	{
		scanf("%d%d", &M, &N);
		for(int j=1; j<=M; j++)
		{
			scanf("%d",&X[j]);
			Insert(X[j], &n);
			check=check+X[j].key;
		}

		if( (T<1||T>10) || (M<1||M>1000000) || (N<1||N>1000000) || check<N){
			printf("Input is Wrong!\n");	i--;	continue;
		}
		
		money[i]=0;
		for(int j=1; j<=N; j++)
		{
			money[i]=money[i]+heap[1].key;
			heap[1].key--;
			Heapify(&n);
		}
		zero(&n);
	}
	
	for(int i=0; i<T; i++)
		printf("%d\n",money[i]);
		
	return 0;
}

