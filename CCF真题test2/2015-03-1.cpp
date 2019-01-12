#include<iostream>
#include<string.h>
using namespace std;
int a[1001][1001];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);//2, 3
	memset(a,0,sizeof(a));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &a[i][j]);
	for(int i=m-1; i>=0; i--)//3
	{
		for(int j=0; j<n; j++)//2
		{
			if(j) printf(" ");
			printf("%d", a[j][i]);
		}
		printf("\n");
	}
	return 0;
}
