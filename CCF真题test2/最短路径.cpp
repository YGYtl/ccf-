#include<iostream>
#include<string.h>
using namespace std;
struct node{
	int weight;
	int father;
	bool visited;
	node()
	{
		weight = 32767;
		father = -1;
		visited = false;
	}
};
int main()
{
	int n, u;
	int a, b, weight;
	scanf("%d %d", &n, &u);
	node m[n+1][n+1];//图，值不修改 
	for(int i=0; i<u; i++)
	{
		scanf("%d %d", &a, &b);
		scanf("%d", &m[a][b].weight);
		m[b][a].weight = m[a][b].weight;
		if(a==1||b==1)
		{
			m[a][b].father = 1;
			m[b][a].father = 1;
		}
	}
	int g = 2;//g点到各个点的最短路径 
	m[g][g].visited = true;
	for(int i=2; i<=n; i++)
	{
		int min = 32767, index;
		for(int j=1; j<=n; j++)
		{
			if(j==g) continue;
			if(m[g][j].visited==false&&m[g][j].weight<min)//找到未访问中值最小的 
			{
				min = m[g][j].weight;
				index = j;
			}
		}
		for(int j=1; j<=n; j++)
		{
			if(j==g) continue;
			if(min+m[index][j].weight<m[g][j].weight)
			{
				m[g][j].weight = min+m[index][j].weight;
				m[g][j].father = index;
			}
		}
		m[g][index].visited = true;
	}
	for(int i=1; i<=n; i++) printf(" %5d", i);
	printf("\n");
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			printf(" %5d", m[i][j].weight);
		}
		printf("\n");
	}
	return 0;
}
