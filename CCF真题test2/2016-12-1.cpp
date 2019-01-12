#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n, c1=0, c2=0;
	vector<int> v;
	scanf("%d", &n);
	v.resize(n);
	for(int i=0; i<n; i++) scanf("%d", &v[i]);
	sort(v.begin(),v.end());
	for(int i=0; i<n; i++)
	{
		if(v[i]<v[n/2]) c1++;
		if(v[i]>v[n/2]) c2++;
	}
	if(c1==c2) printf("%d\n", v[n/2]);
	else printf("-1\n");
	return 0;
}
