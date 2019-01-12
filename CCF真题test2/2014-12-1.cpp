#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n, k;
	map<int,int> m;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &k);
		m[k]++;
		if(i) printf(" ");
		printf("%d", m[k]);
	}
	return 0;
}
