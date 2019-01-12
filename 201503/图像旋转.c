#include<stdio.h>
int main()
{
	int j, k;
	int n, m;
	int a[1001][1001] = {'\0'};
	scanf("%d %d", &n, &m);
	for(j=0; j<n; j++)
	{
		for(k=0; k<m; k++)
		{
			scanf("%d", &a[j][k]);
		}
	}
	
	for(j=m-1; j>=0; j--)
	{
		for(k=0; k<n-1; k++)
		{
			printf("%d ", a[k][j]);
		}
		printf("%d", a[n-1][j]);
		if(j!=0) printf("\n");
	}
	return 0;
}
