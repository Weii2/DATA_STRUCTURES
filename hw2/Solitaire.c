#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned) time(NULL));
	rand();
	
	char *cards[13] = {"K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A"}, *ran_cards[13], *store[1];
	int no=0,num1,f,j,k=0,s=13;
	int num2[13];

	while(no<13)
	{
		num1 = (int) ((double)(rand()) / (RAND_MAX) * (13.0 - 0.0) );
		f=0;

		for(int i=0; i<no; i++)
		{
			if(num2[i] == num1)
			{
				f=1;
				break;
			} 
		}
		
		if(f==0)
		{
			num2[no]=num1;
			no++;
		}
	}
	
	for(int i=0; i<13; i++)
	{
		ran_cards[i]=cards[num2[i]];
		printf("%s ",ran_cards[i]);
	}
	
	while(s!=1)
	{
		printf("\n");
		j=1;
		
		if(ran_cards[0]==cards[k])
		{
			for(int i=0; i<s; i++)
			{
				ran_cards[i]=ran_cards[i+1];
			}
			s--;
			k++;
		}
		else
		{
			store[0]=ran_cards[0];
			for(int i=0; i<s-1; i++)
			{
				ran_cards[i]=ran_cards[i+1];
				j++;
			}
			ran_cards[j-1]=store[0];
		}
		
		for(int i=0; i<s; i++)
		{
			printf("%s ",ran_cards[i]);
		}
	}

	return 0;
}
