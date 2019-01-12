#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, k1, k2;
	int num = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &k2);
		if(i==0) k1 = k2;
		else
		{
			if(abs(k1-k2)>=num) num = abs(k1-k2);
			k1 = k2;
		}
	}
	printf("%d\n", num);
	return 0;
}
