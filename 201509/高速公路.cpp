#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<string.h>
#include<algorithm>
#define N 10001
using namespace std;
int n, m, ans=0;
vector<int> map[N];
int vis[N], l[N], t;
//l[N]数组存储当前第i个节点能够直接或者间接访问到的最早的节点的时序time
int dfn[N];//dfn[i]数组存储第i个节点的访问时间time
stack<int> s;
int instack[N];
void tarjan(int u){
	dfn[u] = l[u] = ++t;//父与原来是一样的 
	s.push(u);
	instack[u] = 1;
	vis[u] = 1;
	for(int i=0; i<map[u].size(); i++){
		int v = map[u][i];
		if(vis[v]==0){
			tarjan(v);//递归进stack 
			l[u] = min(l[u],l[v]);//父与子的比较 
		}
		else if(instack[v]){//在栈中 
			l[u] = min(l[u],dfn[v]);//父与原来的比较 
		}
	}
	int num, c = 0;
	if(dfn[u]==l[u]){//以u为根的搜索子树上所有节点是一个强连通分量
		do{
			num = s.top();//出栈 
			instack[num] = 0;
			s.pop();
			c++;
		}while(num!=u);
		if(c>1){
			ans += c*(c-1)/2;//每个环的连通分量相加 
		}
	}
}
int main()
{
	int a, b;
	memset(vis,0,sizeof(vis));
	memset(dfn,0,sizeof(dfn));
	memset(l,0,sizeof(l));
	memset(instack,0,sizeof(instack));
	cin >> n >> m;
	for (int i = 0; i<m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
	}
	t = 0;
	for (int i = 1; i <= n; i++) {
		if(vis[i]==0){
			vis[i] = 1;
			tarjan(i);
		}
	}
	cout << ans << endl;
	return 0;
}
