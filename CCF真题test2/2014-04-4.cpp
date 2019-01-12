#include<iostream>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
int n, m, k, r;
struct data{
	int x, y;
}a[201];
int map[201][201];
int d[201][201];
bool visited[201][201];
void bfs()
{
	memset(visited,false,sizeof(visited));
	memset(d,INF,sizeof(d));
	data p, f;
	p.x = p.y = 0;
	queue<data> q;
	d[0][0] = 0;
	visited[0][0] = true;
	q.push(p);
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		visited[p.x][p.y] = false;
		for(int i=0; i<n+m; i++)
		{
			if(map[p.x][i])
			{
				f.x = i;
				f.y = p.y;
				if(f.x>=n) f.y++;
				if(f.y<=k&&d[f.x][f.y]>d[p.x][p.y]+1)
				{
					d[f.x][f.y] = d[p.x][p.y]+1;
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
	printf("%d\n", ans-1);
}
int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &r);
	for(int i=0; i<n+m; i++) scanf("%d %d", &a[i].x, &a[i].y);
	for(int i=0; i<n+m; i++)
	{
		for(int j=i+1; j<n+m; j++)
		{
			if((long long)abs(a[i].x-a[j].x)*(long long)abs(a[i].x-a[j].x)+(long long)abs(a[i].y-a[j].y)*(long long)abs(a[i].y-a[j].y)<=(long long)r*r)
			{
				map[i][j] = map[j][i] = 1;
			}
		}
	}
	bfs();
	return 0;
}
