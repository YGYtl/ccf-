#include<iostream>
#include<vector>
using namespace std;
int bs(int *v, int g);
int n, m;
int main()
{
	int a, b;
	scanf("%d %d", &n, &m);
	int v[n];
	for(int i=0; i<n; i++) v[i] = i+1;
	for(int i=0; i<m; i++)
	{
		scanf("%d %d", &a, &b);
		int k1 = bs(v,a);
		int k2 = k1+b;
		printf("%d %d\n", k1, k2);
		if(b<0)
		{
			if(k2<=0) k2 = 0;
			for(int j=k1; j>k2; j--) v[j] = v[j-1]; 
			v[k2] = a;
		}
		else
		{
			if(k2>=n) k2 = n-1;
			for(int j=k1; j<k2; j++) v[j] = v[j+1];
			v[k2] = a;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(i) printf(" ");
		printf("%d", v[i]);
	}
	return 0;
}
int bs(int *v, int g)
{
	for(int i=0; i<n; i++)
	{
		if(v[i]==g) return i;
	}
}
