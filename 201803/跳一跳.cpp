#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, sum=0, c=0;
	while(scanf("%d", &n))
	{
		if(n==0) break;
		if(n==2)
		{
			c++;
			sum += 2*c;
		}
		else
		{
			c = 0;
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}
