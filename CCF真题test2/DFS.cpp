#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int main()
{
	stack<int> s;
	int n, a, b;
	scanf("%d", &n);//点有1~n 
	int m[n][n];//无向图 
	bool visited[n];
	memset(m,0,sizeof(m)+1);
	memset(visited,false,sizeof(m)+1);
	for(int i=0; i<n; i++)
	{
		scanf("%d %d", &a, &b);
		m[a][b] = m[b][a] = 1;
	}
	s.push(1);
	while(!s.empty())
	{
		int k = s.top();
		s.pop();
		printf("%d\n", k);
		visited[k] = true;
		for(int i=1; i<=n; i++)
		{
			if(m[k][i]==1&&visited[i]==false)
			{
				s.push(i);
				break;
			}
		}
	}
	return 0;
}
