#include<stdio.h>
#include<stdlib.h>

typedef struct queue *queuePt;
typedef struct queue{
	char data;
	queuePt link;
};
queuePt f=NULL, r=NULL;

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

int main()
{
	int N, j, x, s=0, check, fi=0;
	char queue[26], group[N][26], operation[7], p, y, final[100];
		
	scanf("%d",&N);
	
	for(int i=0; i<N; i++)
	{
		j=0;
		while(1)
		{
	    	scanf("%s",&group[i][j++]);
			if( (y=getchar()) == '\n')
				break;
		}
	}

	while(scanf("%s",&operation)!=EOF)
	{
		if( strcmp(operation,"DEQUEUE") == 0 )
		{
			final[fi++]=f->data;
			Dequeue();
			s--;
		}
		else if( strcmp(operation,"ENQUEUE") == 0 )
		{
			check=0,x=N;
			y=getchar();
			p=getchar();

			for(int i=0; i<N; i++)
			{
				for(int k=1; k<=(group[i][0]-'0'); k++)
				{
					if(p==group[i][k])
						x=i;
				}
			}

			queuePt temp = malloc(sizeof(*temp)), cur = f, pre = NULL;
			temp->data = p; 
			temp->link = NULL;
			if(f == NULL && r == NULL){
				f = r = temp;
				continue;
			}

			for(int i=0; i<s; i++)
			{
				for(int k=1; k<=(group[x][0]-'0'); k++)
				{
					if(cur->data == group[x][k])
					{
						if(cur==f)
						{
							temp->link = f;
							f = temp;
						}
						else
						{
							pre->link = temp;
							temp->link = cur;
						}
						check=1;
						break;
					}
				}
				pre = cur;
				cur = cur->link;
				if(check==1)
					break;
			}
			if(check==0)
			{	
				r->link = temp;
				r = temp;
			}
			s++;
		}
	}
	
	for(int i=0; i<=fi; i++)
	{
		printf("%c\n",final[i]);
	}
		
	return 0;
} 
