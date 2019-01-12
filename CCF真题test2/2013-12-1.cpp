#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n, k, max=-1;
	scanf("%d", &n);
	map<int,int> m;
	for(int i=0; i<n; i++)
	{
		scanf("%d", &k);
		m[k]++;
		if(m[k]>max) max = m[k];
	}
	map<int,int>::iterator v;
	for(v=m.begin(); v!=m.end(); v++)
	{
		if(v->second==max)
		{
			printf("%d\n", v->first);
			break;
		}
	}
	return 0;
}
