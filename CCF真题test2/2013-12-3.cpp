#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//最大矩阵，小型模拟 
int main()
{
	int n, k, o;
	scanf("%d", &n);
	int mx;
	vector<int> v;
	v.resize(n);
	for(int i=0; i<n; i++) scanf("%d", &v[i]);//不可改变
	mx = v[0];
	for(int i=0; i<n; i++)
	{
		int num = v[i];
		for(int j=i+1; j<n; j++)
		{
			num = min(num,v[j]);
			mx = max(mx,num*(j-i+1));//最小的
		}
	}
	printf("%d\n", mx);
	return 0;
}
