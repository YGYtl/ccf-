#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
bool cmp(int a, int b) {
	return a < b;
}
int main()
{
	int n, i, c=0;
	int a[100000]={'\0'};
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	int j, k, o;
	sort(a,a+n,cmp);
	for(i=n-1; i>0; i--)
	{
		if(a[i]-a[i-1]==1) c++;
	}
	printf("%d", c);
	return 0;
}
