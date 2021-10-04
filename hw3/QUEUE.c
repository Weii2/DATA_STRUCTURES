#include<stdio.h>
#include<string.h>

int main()
{
	int N, j, r, s=0, check, fi=0;
	char queue[26], group[N][26], operation[7], p, y, final[100];
		
	scanf("%d",&N);	
	
	for(int i=0; i<N; i++)
	{
		j=0;
		while(1)
		{
	    	scanf("%s",&group[i][j++]);
			y=getchar();

			if(y == '\n')
				break;
		}
	}

	while(scanf("%s",&operation)!=EOF)
	{
		if( strcmp(operation,"DEQUEUE") == 0 )
		{
			final[fi++]=queue[0];
			
			for(int i=0; i<=s; i++)
			{
				queue[i]=queue[i+1];
			}

			s--;
		}
		else if( strcmp(operation,"ENQUEUE") == 0 )
		{
			check=0,r=N;
			y=getchar();
			p=getchar();

			for(int i=0; i<N; i++)
			{
				for(int k=1; k<=(group[i][0]-'0'); k++)
				{
					if(p==group[i][k])
						r=i;
				}
			}
				
			for(int i=0; i<s; i++)
			{
				for(int k=1; k<=(group[r][0]-'0'); k++)
				{
					if(queue[i]==group[r][k])
					{
						for(int m=s; m>=i; m--)
						{
							queue[m]=queue[m-1];
						}
						queue[i]=p;
						check=1;
						break;
					}
				}
				if(check==1)
					break;
			}
			if(check==0)
				queue[s]=p;

			s++;
		}
	}
	
	for(int i=0; i<=fi; i++)
	{
		printf("%c\n",final[i]);
	}
	
	return 0;
} 
