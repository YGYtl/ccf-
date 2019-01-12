#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;

struct node{
	int i_d;
	int target;
	int time;
	bool operator < (const node &u) const//重载 
	{
		if(time > u.time) return true;
		if(time < u.time) return false;
		if(target > u.target) return true;
		if(target < u.target) return false;
		if(i_d > u.i_d) return true;
		return false;
	}
}; 

int main()
{
	priority_queue<node> q;//优先队列
	int a[1001]={'\0'};
	int n, k;
	int w, s, c;
	scanf("%d %d", &n, &k);
	node o;
	while(k--)
	{
		scanf("%d %d %d", &w, &s, &c);
		o.i_d = w;
		o.target = 1;
		o.time = s;
		q.push(o);
		o.target = 0;
		o.time = s + c ;
		q.push(o);
	}
	
	for(int i=0; i<=n; i++)
	{
		a[i] = i;
	}
	
	while(!q.empty())
	{
		o = q.top();
		cout << o.time << endl;
		q.pop();
		if(o.target == 1)//已近取走了 
		{
			for(int i=0; i<=n; i++)
			{
				if(a[i]==o.i_d)
				{
					a[i] = -1;
					break;
				}
			}
		}
		else{
			for(int i=0; i<=n; i++)
			{
				if(a[i]==-1)//放回来 
				{
					a[i] = o.i_d;
					break;
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		if(i!=1) cout << ' ';
		cout << a[i];
	}
	return 0;
}
