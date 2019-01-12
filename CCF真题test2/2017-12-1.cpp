#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, num = 32765;
	vector<int> v;
	scanf("%d", &n);
	v.resize(n);
	for(int i=0; i<n; i++) scanf("%d", &v[i]);
	sort(v.begin(),v.end());
	for(int i=1; i<n; i++)
	{
		if(v[i]-v[i-1]<num) num = v[i]-v[i-1];
	}
	printf("%d", num);
	return 0;
}
