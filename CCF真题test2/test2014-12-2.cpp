#include<iostream>
#include<string.h>
using namespace std;
int a[501][501];
int main()
{
	int n, c=0;
	int k = 1;
	int l=0, r=0;
	scanf("%d", &n);
	memset(a,0,sizeof(a));
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &a[i][j]);
	printf("%d", a[l][r++]);
	for(int i=1; i<n; i++)
	{
		if(i%2!=0)//ÆæÊý 
		{
			int g = r;
			while(l!=g) printf(" %d", a[l++][r--]);
			printf(" %d", a[l++][r]);
		}
		else
		{
			int g = r;
			while(l!=g) printf(" %d", a[l--][r++]);
			printf(" %d", a[l][r++]);
		}
	}
	if(n%2==0) r++, l--;
	else l++, r--;
	for(int i=n-1; i>1; i--)
	{
		if(i%2==0) 
		{
			int g = r;
			while(l!=g) printf(" %d", a[l++][r--]);
			printf(" %d", a[l][r++]);
		}
		else
		{
			int g = r;
			while(l!=g) printf(" %d", a[l--][r++]);
			printf(" %d", a[l++][r]);
		}
	}
	if(n!=1) printf(" %d", a[n-1][n-1]);
	return 0;
}
