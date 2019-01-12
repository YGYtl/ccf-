#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
using namespace std;
int mp[1001][1001];
map<int,vector<int> > p;
vector<int> v;
int n, m, a, b, c;
void dfs(int k){
	int mi = n+1;
	if(c==m) return;
	for(int i=1; i<=n; i++){//找最小的值 
		if(i!=k&&mp[k][i]&&p[k][i]){
			mi = min(mi,i);
		}
	}
	if(mi==n+1) return;
	c++;
	if(mi!=n+1){
		v.push_back(mi);
		p[k][mi] = p[mi][k] = 0;
		dfs(mi);
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	memset(mp,0,sizeof(mp));
	c = 0;
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		mp[a][b] = mp[b][a] = 1;
		if(p[a].size()==0) p[a].reserve(10001);
		if(p[b].size()==0) p[b].reserve(10001);
		p[a][b] = p[b][a] = 1;
	}
	v.push_back(1);
	dfs(1);
	bool flag = true;
	if(c!=m) flag = false; 
	if(flag){
		for(int i=0; i<v.size(); i++){
			if(i) printf(" ");
			printf("%d", v[i]);
		}
	}
	else printf("-1");
	return 0;
}
