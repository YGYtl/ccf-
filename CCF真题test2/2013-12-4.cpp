#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n;
	long long a[1010][10]={'\0'};
	scanf("%d", &n);
	memset(a,0,sizeof(a));
	for(int i=0; i<=n; i++) a[i][0] = 0;
	for(int k=1; k<=n; k++)
	{
		a[k][0] = 1;
		a[k][1] = (a[k-1][0] + a[k-1][1]*2)%1000000007;
		a[k][2] = (a[k-1][0] + a[k-1][2])%1000000007;
		a[k][3] = (a[k-1][1] + a[k-1][2] + a[k-1][3]*2)%1000000007;
		a[k][4] = (a[k-1][1] + a[k-1][4]*2)%1000000007;
		a[k][5] = (a[k-1][3] + a[k-1][4] + a[k-1][5]*2)%1000000007;
	}
	printf("%I64d\n", a[n][5]);
	return 0;
}
