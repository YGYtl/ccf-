#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int n, m, t;
int r, c, a, b, ans;
int count = 0;
struct data{
	int a, b;
	int t;
}g;
//bfs
int vis[105][105][305], at[105][105][2], d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int main()
{
	scanf("%d %d %d", &n, &m, &t);
	for(int i=0; i<t; i++){
		scanf("%d %d %d %d", &r, &c, &a, &b);
		at[r][c][0] = a; at[r][c][1] = b;
	}
	g.a = 1; g.b = 1;
	g.t = 0;
	queue<data> q;
	q.push(g);
	memset(vis,0,sizeof(vis));
	vis[1][1][0] = 1;
	while(!q.empty()){
		int x = q.front().a;
		int y = q.front().b;
		int t = q.front().t;
		if(x==n&&y==m){
			printf("%d\n", t);
			return 0;
		}
		q.pop();
		for(int i=0; i<4; i++){
			int xx = d[i][0] + x;
			int yy = d[i][1] + y;
			int tt = t + 1;
			if(vis[xx][yy][tt]||xx<1||xx>n||yy<1||yy>n||(tt>=at[xx][yy][0]&&tt<=at[xx][yy][1])) continue;
			g.a = xx; g.b = yy; g.t = tt;
			vis[xx][yy][tt] = 1;
			q.push(g);
			vis[xx][yy][tt] = 0;
		}
	}
	return 0;
}

