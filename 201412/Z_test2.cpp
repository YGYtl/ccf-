#include<iostream>
using namespace std;
int a[510][510];
int main()
{
	int n, x=0, y=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=0; i<n; i++)
	{
		if(i&1)//奇数 
		{
			for(int j=0; j<i; j++) printf("%d ", a[x++][y--]);
			printf("%d ", a[x++][y]);
		}
		else//偶数 
		{
			for(int j=0; j<i; j++) printf("%d ", a[x--][y++]);
			printf("%d ", a[x][y++]);
		}
	}
	
	if(n&1) x++, y--;
	else x--, y++;
	
	for(int i=n-2; i>0; i--)
	{
		if(i&1)//奇数 
		{
			for(int j=0; j<i; j++) printf("%d ", a[x++][y--]);
			printf("%d ", a[x][y++]);
		}
		else//偶数 
		{
			for(int j=0; j<i; j++) printf("%d ", a[x--][y++]);
			printf("%d ", a[x++][y]);
		}
	}
	if(n!=1) printf("%d", a[n-1][n-1]);
	return 0;
}
