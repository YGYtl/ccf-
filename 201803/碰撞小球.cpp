#include<iostream>
#include<cstring>
using namespace std;
struct data{
	int n;
	int k;
}a[101];
int main()
{
	int n, l, t;
	bool visited[101];
	scanf("%d %d %d", &n, &l, &t);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i].n);
		a[i].k = 1;
	}
	for(int i=0; i<t; i++)
	{
		memset(visited,false,n);
		int g = 0;
		for(int j=0; j<n; j++) a[j].n = a[j].n + a[j].k;//全部加一 
		for(int j=0; j<n; j++)//找碰撞的球，让他反向 
		{
			for(int k=j+1; k<n; k++)
			{
				if(visited[k]==false&&a[j].n==a[k].n)
				{
					a[k].k *= -1;
					if(g == 0) a[j].k *= -1;
					visited[k] = true;
				}
			}
			if(a[j].n==l&&a[j].k>0) a[j].k *= -1;
			if(a[j].n==0&&a[j].k<0) a[j].k *= -1;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(i) printf(" ");
		printf("%d", a[i]);
	}
	return 0;
}
