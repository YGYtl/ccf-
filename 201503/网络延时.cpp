#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string.h>
#define N 10001
using namespace std;
int n, m, k;
vector<int> a[N];
queue<int> q;
int vis[N];
int d[N];
int ans=0, index;
void bfs(int o){
	q.push(o);
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	while(!q.empty()){
		int g = q.front(); q.pop();//¸¸ 
		vis[g] = 1;
		for(int i=0; i<a[g].size(); i++){
			int p = a[g][i];//×Ó 
			if(vis[p]==0){
				vis[p] = 1;
				d[p] = d[g]+1;
				q.push(p);
				if(ans<d[p]){
					ans = d[p];
					index = p;
				}
			}
		}
	}
}


int main()
{
	int f = 1;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n-1; i++){
		scanf("%d", &k);
		a[k].push_back(++f);
		a[f].push_back(k);
	}
	for(int i=0; i<m; i++){
		scanf("%d", &k);
		a[k].push_back(++f);
		a[f].push_back(k);
	}
	bfs(1);
	bfs(index);
	cout << ans << endl;
	return 0;
}
