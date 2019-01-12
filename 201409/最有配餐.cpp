#include<iostream>
#include<cstdio>
#include<queue>
#include<string.h>
#define N 1005
using namespace std;
struct data{
	int x, y, t;
	data(){t = 0;}
};
queue<data> q;
int map[N][N];
int vis[N][N];
int n, m, k, d, ans, c;
int g[2][4]={{0,1,0,-1},{1,0,-1,0}};
int bfs(){
	while(!q.empty()){
		data temp;
		temp = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			data t = temp;
			t.x += g[0][i];
			t.y += g[1][i];
			t.t++;
			if(t.x>0&&t.x<=n&&t.y>0&&t.y<=n&&!vis[t.x][t.y]){
				vis[t.x][t.y] = 1;
				if(map[t.x][t.y]){
					ans+=map[t.x][t.y]*t.t;
					c++;
					if(c==k) return ans;
				}
				q.push(t);
			}
		}
	}
	return -1;
}

int main()
{
	int o1, o2, num;
	ans = 0; c = 0;
	scanf("%d %d %d %d", &n, &m, &k, &d);
	memset(vis,0,sizeof(vis));
	memset(map,0,sizeof(map));
	for(int i=0; i<m; i++){//商店 
		scanf("%d %d", &o1, &o2);
		vis[o1][o2] = 1;
		data temp;
		temp.x=o1; temp.y=o2;
		temp.t=0;
		q.push(temp);
	}
	for(int i=0; i<k; i++){//客户 
		scanf("%d %d %d", &o1, &o2, &num);
		map[o1][o2] = num;
	}
	for(int i=0; i<d; i++){//不可走的点 
		scanf("%d %d", &o1, &o2);
		vis[o1][o2] = 1;
	}
	cout << bfs() << endl;
	return 0;
}
