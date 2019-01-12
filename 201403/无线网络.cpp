#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 0x3f3f3f3f
#define N 201
using namespace std;
struct data{
	int x;
	int y;
}a[201];
int n, m, k, r;
int map[201][201];
int d[201][201];
bool visited[201][201];
void dfs()
{
	memset(visited,false,sizeof(visited));
	memset(d,INF,sizeof(d));
	queue<data> q;
	data s, f;
	s.x = s.y = 0;
	d[0][0] = 0;
	visited[0][0] = true;
	q.push(s);
	while(!q.empty())
	{
		s = q.front();
		q.pop();
		visited[s.x][s.y] = false;
		for(int i=0; i<n+m; i++)
		{
			if(map[s.x][i])
			{
				f.x = i;
				f.y = s.y;
				if(i>=n) f.y++;
				if(f.y<=k&&d[f.x][f.y]>d[s.x][s.y]+1)//经过对少个转换器 
				{
					d[f.x][f.y] = d[s.x][s.y]+1;
					if(!visited[f.x][f.y])
					{
						visited[f.x][f.y] = true;
						q.push(f);
					}
				}
			}
		}
	}
	int ans = INF;
	for(int i=0; i<=k; i++) ans = min(ans,d[1][i]);
	//没有增加时，增加一个时，增加到k时，最短 
	printf("%d\n", ans-1);
}
int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &r);
	for(int i=0; i<m+n; i++) scanf("%d %d", &a[i].x, &a[i].y);
	for(int i=0; i<m+n; i++)
	{
		for(int j=i+1; j<m+n; j++)
		{
			if((long long)(a[i].x-a[j].x)*(a[i].x-a[j].x)+(long long)(a[i].y-a[j].y)*(a[i].y-a[j].y)<=((long long)r*r))
			{
				map[i][j] = map[j][i] = 1;
			}
		}
	}
	dfs();
	return 0;
}
