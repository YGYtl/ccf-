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
//l[N]����洢��ǰ��i���ڵ��ܹ�ֱ�ӻ��߼�ӷ��ʵ�������Ľڵ��ʱ��time
int dfn[N];//dfn[i]����洢��i���ڵ�ķ���ʱ��time
stack<int> s;
int instack[N];
void tarjan(int u){
	dfn[u] = l[u] = ++t;//����ԭ����һ���� 
	s.push(u);
	instack[u] = 1;
	vis[u] = 1;
	for(int i=0; i<map[u].size(); i++){
		int v = map[u][i];
		if(vis[v]==0){
			tarjan(v);//�ݹ��stack 
			l[u] = min(l[u],l[v]);//�����ӵıȽ� 
		}
		else if(instack[v]){//��ջ�� 
			l[u] = min(l[u],dfn[v]);//����ԭ���ıȽ� 
		}
	}
	int num, c = 0;
	if(dfn[u]==l[u]){//��uΪ�����������������нڵ���һ��ǿ��ͨ����
		do{
			num = s.top();//��ջ 
			instack[num] = 0;
			s.pop();
			c++;
		}while(num!=u);
		if(c>1){
			ans += c*(c-1)/2;//ÿ��������ͨ������� 
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
