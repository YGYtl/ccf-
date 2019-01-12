#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct d{
	int data;
	int c;
	d() { c = 0; }
};
bool cmp(d a, d b)
{
	if(a.c != b.c) return a.c > b.c;
	else return a.data < b.data;
}
int main()
{
	int n, k;
	scanf("%d", &n);
	map<int,int> m;
	for(int i=0; i<n; i++)
	{
		scanf("%d", &k);
		m[k]++;
	}
	map<int,int>::iterator v;
	vector<d> vm;
	for(v=m.begin(); v!=m.end(); v++)
	{
		d a;
		a.data = v->first;
		a.c = v->second;
		vm.push_back(a);
	}
	sort(vm.begin(),vm.end(),cmp);
	for(int i=0; i<vm.size(); i++)
	{
		printf("%d %d\n", vm[i].data, vm[i].c);
	}
	return 0;
}
