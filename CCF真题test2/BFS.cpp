#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int main()
{
	queue<int> q;
	int n, a, b;
	scanf("%d", &n);
	int m[n][n];
	bool visited[n];
	memset(m,0,sizeof(m)+1);
	memset(visited,false,sizeof(m)+1);
	for(int i=0; i<n; i++)
	{
		scanf("%d %d", &a, &b);
		m[a][b] = m[b][a] = 1;
	}
	q.push(1);
	visited[1] = true;
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		printf("%d\n", k);
		for(int j=1; j<=n; j++)
		{
			if(m[k][j]==1&&visited[j]==false)
			{
				q.push(j);
				visited[j] = true;
			}
		}
	}
	return 0;
}
