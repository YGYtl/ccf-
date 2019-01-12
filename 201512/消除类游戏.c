#include<stdio.h>
int main()
{
	int n, m;
	int a[50][50]={'\0'};
	int b[50][50]={'\0'};
	int ca[50][50]={'\0'};
	scanf("%d %d", &n, &m);
	int i, j, k, temp, o;
	for(j=0; j<n; j++)
	{
		for(k=0; k<m; k++)
		{
			scanf("%d", &a[j][k]);
			ca[j][k] = a[j][k];
		}
	}
	int c;
	for(j=0; j<n; j++)//行 
	{
		c = 0;
		for(k=0; k<=m; k++)//列 
		{
			if(k==0)
				temp = a[j][k];
			if(a[j][k]==temp)
				c++;
			else if(k==m||a[j][k]!=temp)
			{
				b[j][k-1] = c;
				temp = a[j][k];
				c = 1;
			}
		}
	}
	for(j=0; j<n; j++)
	{
		for(k=0; k<m; k++)
		{
			if(b[j][k]>=3)
			{
				o = k;
				while(b[j][k]!=0)
				{
					b[j][k]--;
					ca[j][o--] = 0;
				}
			}
			b[j][k] = 0;
		}
	}
	
	for(j=0; j<m; j++)//列 
	{
		c = 0;
		for(k=0; k<=n; k++)//行 
		{
			if(k==0)
				temp = a[k][j];
			if(a[k][j]==temp)
				c++;
			else if(k==m||a[k][j]!=temp)
			{
				b[k-1][j] = c;
				temp = a[k][j];
				c = 1;
			}
		}
	}
	for(j=0; j<m; j++)//列 
	{
		for(k=0; k<n; k++)//行 
		{
			if(b[k][j]>=3)
			{
				o = k;
				while(b[k][j]!=0)
				{
					b[k][j]--;
					ca[o--][j] = 0;
				}
			}
		}
	}
	
	for(j=0; j<n; j++)
	{
		for(k=0; k<m; k++)
		{
			printf("%d ", ca[j][k]);
		}
		printf("\n");
	}
	return 0;
}
