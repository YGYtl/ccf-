#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct data{
	int w, s, c;//钥匙编号， 上课时间， 上课时长 
	int last;
}g1[1010], g2[1010];//看开始，看结束 
bool cmp1(data a, data b)
{
	if(a.last!=b.last) return a.last < b.last;
	else return a.s<b.s;
}
bool cmp2(data a, data b)
{
	if(a.last!=b.last) return a.last < b.last;
	else return a.w < b.w;
}
int main()
{
	int n, k, c = 0;
	scanf("%d %d", &n, &k);
	int a[1010];
	memset(a,0,sizeof(a));
	for(int i=1; i<=n; i++) a[i] = i;
	for(int i=0; i<k; i++)
	{
		scanf("%d %d %d", &g1[c].w, &g1[c].s, &g1[c].c);
		g1[c].last = 0;
		g2[c].w = g1[c].w; g2[c].s = g1[c].s; g2[c].c = g1[c].c;
		g2[c].last = g1[c].s + g1[c].c;
		c++;
	}
	sort(g1,g1+c,cmp1);
	sort(g2,g2+c,cmp2);
	int f1 = 0, f2 = 0;
	while(f2<c)
	{
		for( ; f1<c; f1++)
		{
			if(g1[f1].s<g2[f2].last)
			{
				for(int i=1; i<=n; i++)
				{
					if(a[i]==g1[f1].w)
					{
						a[i] = -1;//取出来 
						break;
					}
				}
			}
			else break;
		}
		for(int i=1; i<=n; i++)//放回去 
		{
			if(a[i]==-1)
			{
				a[i] = g2[f2++].w;
				break;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(i!=1) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}
