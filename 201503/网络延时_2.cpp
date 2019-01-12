#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int n, m, k, ans=0, index;
vector<int> a[10001];
queue<int> q;
int vis[10001], d[10001];
void bfs(int o){
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof((d)));
	q.push(o);
	vis[o] = 1;
	while(!q.empty()){
		int g = q.front(); q.pop();
		for(int i=0; i<a[g].size(); i++){ 
			int v = a[g][i];
			if(vis[v]==0){
				vis[v] = 1;
				d[v] = d[g] + 1;
				q.push(v);
				if(ans<d[v]){
					ans = d[v];
					index = v;
				}
			}
		}
	}
}
int main()
{
	int g = 2;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n-1; i++){
		scanf("%d", &k);
		a[k].push_back(g);
		a[g++].push_back(k);
	}
	for(int i=0; i<m; i++){
		scanf("%d", &k);
		a[k].push_back(g);
		a[g++].push_back(k);
	}
	for(int i=0; i<g; i++){
		k = a[i].size();
		printf("%d\n", i);
		for(int j=0; j<k; j++){
			printf(" %d", a[i][j]);
		}
		printf("\n");
	} 
	bfs(1);
	bfs(index);
	printf("%d\n", ans);
	return 0;
}
