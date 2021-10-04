#include <bits/stdc++.h>

using namespace std; 

void powerset(char str[][100], int j, int i=0, string r="") 
{ 
	string a(str[i]);
	
    if (i == j) 
	{ 
    	cout << "\{" << r << "\}"; 
    	return; 
    } 
	
    powerset(str, j, i + 1, r); 
    powerset(str, j, i + 1, r + a);
} 
 
int main() 
{ 
	char str[100][100];
	int j=0;
	char y;

	while(scanf("%s",&str[j])!=EOF)
	{
	    j++;
		
		if(y=getchar()!='\n')
	    {
			continue;	
		}
		
		powerset(str, j);
		cout << endl;
		j=0;
    }

	return 0; 
}

