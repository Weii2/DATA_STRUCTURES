#include <stdio.h>
#include <string.h>

int collapsingFind(int i, int set[], int *po)
{
	int root, trail, lead, count=0;
	
	for(root=i; set[root]>=0; root=set[root])
		count++;

	for(trail=i; trail!=root; trail=lead)
	{
		lead=set[trail];
		if(lead==root)
			break;
		set[trail]=root;
		count++;
	}
	*po=count;

	return root;
}

void heightUnion(int i, int j, int set[], int num_node)
{
	int temp=set[i]+set[j], n, height[2]={0};
	
	for(int m=0; m<num_node; m++)
	{
		int count=0;
		if(set[m]<0)
			continue;
		for(n=m; set[n]>=0; n=set[n])
			count++;
		if(n==i && count>height[0])
			height[0]=count;
		else if(n==j && count>height[1])
			height[1]=count;
	}
	
	if(height[0]>=height[0]){	
		set[i]=j;	set[j]=temp;
	}
	else{
		set[j]=i;	set[i]=temp;
	}
}

int main()
{
	char operation[5];
	int T;
	scanf("%d",&T);
	
	int set[100*T], num, num_node=0, p, q, outcome[100*T], *po=&outcome[0];
	for(int i=0; i<T; i++)
	{
		scanf("%d",&num);	num_node=num_node+num;
		for(int j=0; j<num; j++)
		{
			
			scanf("%d%d", &p, &q);
			set[p]=q;
		}
	}
	
	while(scanf("%s",&operation))
	{
		if( strcmp(operation,"UNION") == 0 )
		{
			int r1,r2;
			scanf("%d%d",&r1,&r2);
			heightUnion(r1, r2, set, num_node);
		}
		else if( strcmp(operation,"FIND") == 0 )
		{
			int value;
			scanf("%d",&value);
			collapsingFind(value, set, po++);
		}
		else if( strcmp(operation,"STOP") == 0 )
			break;
	}
	
	int i=0;
	while(outcome[i]!=0)
	{
		printf("%d\n",outcome[i]);
		i++;
	}
	return 0;
}

