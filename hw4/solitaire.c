#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct queue *queuePt;
typedef struct queue{
	char *data;
	queuePt link;
};
queuePt f=NULL, r=NULL;

void Enqueue(char *c) {
	queuePt temp = malloc(sizeof(*temp));
	temp->data = c; 
	temp->link = NULL;
	if(f == NULL && r == NULL){
		f = r = temp;
		return;
	}
	r->link = temp;
	r = temp;
}

void Dequeue() {
	queuePt temp = f;
	if(f == NULL) {
		return;
	}
	if(f == r) {
		f = r = NULL;
	}
	else {
		f = f->link;
	}
	free(temp);
}

void Print() {
	queuePt temp = f;
	while(temp != NULL) {
		printf("%s ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}
	
int main()
{
	srand((unsigned) time(NULL));	rand();
	
	char *cards[13] = {"K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A"};
	int no=0, num1, p, k=0, s=13, num2[13];

	while(no<13)
	{
		num1 = (int) ((double)(rand()) / (RAND_MAX) * (13.0 - 0.0) );
		p=0;

		for(int i=0; i<no; i++)
		{
			if(num2[i] == num1)
			{
				p=1;
				break;
			} 
		}
		
		if(p==0)
		{
			num2[no]=num1;
			no++;
		}
	}
	
	for(int i=0; i<13; i++)
	{
		Enqueue(cards[num2[i]]);
	}
	Print();	
	while(s!=1)
	{
		if(f->data == cards[k])
		{
			Dequeue();
			s--;
			k++;
		}
		else
		{
			Enqueue(f->data);
			Dequeue();
		}
		
		Print();
	}

	return 0;
}

