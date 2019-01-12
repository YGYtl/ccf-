#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n, c=0;
	int a[1001];
	memset(a,0,sizeof(a));
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	for(int i=1; i<n-1; i++)
	{
		if((a[i]<a[i-1]&&a[i]<a[i+1])||(a[i]>a[i-1]&&a[i]>a[i+1]))
		{
			c++;
		}
	}
	printf("%d\n", c);
	return 0;
}
