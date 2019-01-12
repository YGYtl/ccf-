#include<iostream>
using namespace std;
int main()
{
	int n, sum = 0, k = 0;
	while(scanf("%d", &n))
	{
		if(n==0) break;
		if(n==2)
		{
			k++;
			sum += 2*k;
		}
		else
		{
			sum += n;
			k = 0;
		}
	}
	printf("%d\n", sum);
	return 0;
}
