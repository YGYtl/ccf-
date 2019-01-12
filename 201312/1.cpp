#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
	int n, k, j=0, index, max;
	map<int,int> m;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &k);
		m[k]++;
	}
	map<int,int>::iterator v;
	for(v=m.begin(); v!=m.end(); v++)
	{
		if(j==0)
		{
			index = v->second;
			max = v->first;
		}
		j = 1;
		if(v->second>index)
		{
			index = v->second;
			max = v->first;
		}
	}
	printf("%d", max);
	return 0;
}
