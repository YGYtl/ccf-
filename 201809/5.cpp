#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m, r;
long long l;
long long a[100005], k[100005];
int main()
{
	scanf("%d %lld %d", &m, &l, &r);//3 3 6
	a[0] = 1;
	int q = 998244353;
	for(int i=1; i<=m; i++){
		scanf("%d", &k[i]);
	}
	if(m==2&&k[0]==1&&k[1]==1){
		for(int i=1; i<=r; i++){
			if(i==1) a[i] = (k[i]*a[0])%q;
			else a[i] = (a[i-1]+a[i-2])%q;
			if(i>=l&&i<=r) printf("%lld\n", a[i]);
		}
	}
	else{
		for(int i=1; i<=r; i++){
			int m_min = min(i,m);
			int c = i-1;
			long long num = 0;
			for(int j=1; j<=m_min; j++){
				num += (a[c--]*k[j])%q;
			}
			a[i] = num%q;
			if(i>=l&&i<=r) printf("%lld\n", a[i]);
		}
	}
	return 0;
}
