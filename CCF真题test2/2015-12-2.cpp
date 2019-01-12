#include<iostream>
using namespace std;
struct data{
	int d;
	int t;
	data() { t = 1; }
};
int main()
{
	int n, m;
	data a[40][40];
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%d", &a[i][j].d);
		}
	}
	for(int i=0; i<n; i++)//行相同的 
	{
		for(int j=1; j<m-1; j++)
		{
			if(a[i][j].d==a[i][j-1].d&&a[i][j].d==a[i][j+1].d)
			{
				a[i][j].t = 0;
				a[i][j-1].t = 0;
				a[i][j+1].t = 0;
			}
		}
	}
	for(int i=1; i<n-1; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(a[i][j].d==a[i-1][j].d&&a[i][j].d==a[i+1][j].d)
			{
				a[i][j].t = 0;
				a[i-1][j].t = 0;
				a[i+1][j].t = 0;
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(j) printf(" ");
			if(a[i][j].t) printf("%d", a[i][j].d);
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}
