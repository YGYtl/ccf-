#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#define N 1005
//并查集 && 最小生成树 
using namespace std;
int n, m;
int a, b, c;
int map[N][N];
int M(int key[], bool vis[]){
	int mi = INT_MAX, min_index = -1;
	for(int i=1; i<=n; i++){
		if(!vis[i]&&key[i]<mi){//找到最小的key[i] 
			mi = key[i];
			min_index = i;
		}
	}
	return min_index;
}


int p(){
	int key[N];
	bool vis[N];
	int count = 0;
	for(int i=1; i<=n; i++){
		key[i] = INT_MAX;
		vis[i] = false;
	}
	key[1] = 0;
	for(int i=1; i<=n; i++){
		int u = M(key,vis);//1 2 4
		vis[u] = true;
		count+=key[u];//0
		for(int j=1; j<=n; j++){
			if(!vis[j]&&map[u][j]<key[j])
				key[j] = map[u][j];
		}
	}
	return count;
}
int main()
{
	int ans;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			map[i][j] = INT_MAX;
		}
	}
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = map[b][a] = min(c,map[a][b]);
	}
	ans = p();
	cout << ans;
	return 0;
}
