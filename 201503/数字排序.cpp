#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct data
{
	int x;
	int count;
	bool operator < (const data &u) const{
		return count==u.count?x<u.x:count>u.count;
	}
}a[1010];

int main()
{
	int n, index;
	scanf("%d", &n);
	for(int i=0; i<1010; i++)
	{
		a[i].count = 0;
		a[i].x = i;
	}
	for(int i=0; i<n; i++)
	{
		scanf("%d", &index);
		a[index].count++;
	}
	sort(a,a+1010);
	for(int i=0; i<n; i++)
	{
		if(a[i].count==0) break;
		printf("%d %d\n", a[i].x, a[i].count);
	}
	return 0;
}
