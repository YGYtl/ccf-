#include<iostream>
using namespace std;
int main()
{
	int n, c=1;
	int k, max, index1, index2;
	scanf("%d", &n);
	int v[20][5];
	for(int i=0; i<20; i++) for(int j=0; j<5; j++) v[i][j] = c++;
	for(int o=0; o<n; o++)
	{
		scanf("%d", &k);
		index2 = -1;
		for(int i=0; i<20; i++)
		{
			c = 0, max = 0;
			for(int j=0; j<5; j++)
			{
				if(v[i][j]!=0)
				{
					if(c==0) index1 = j;
					c++;
					if(c>=k)
					{
						index2 = index1;
						break;
					}
				}
				else { c = 0; }
			}
			if(index2!=-1)
			{
				for(int j=index2; j<index2+k; j++)
				{
					if(j!=index2) printf(" ");
					printf("%d", v[i][j]);
					v[i][j] = 0;
				}
				printf("\n");
				break;
			}
		}
		if(index2==-1)
		{
			c = k;
			for(int i=0; i<20&&c; i++)
			{
				for(int j=0; j<5&&c; j++)
				{
					if(v[i][j]!=0)
					{
						if(c!=k) printf(" ");
						printf("%d", v[i][j]);
						v[i][j] = 0;
						c--;
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}
