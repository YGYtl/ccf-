#include<iostream>
using namespace std;
int main()
{
	int n, c=0;
	scanf("%d", &n);
	while(n)
	{
		if(n>=50)
		{
			int k = n/50;
			n = n%50;
			c += k*7;
		}
		if(n>=30)
		{
			int k = n/30;
			n = n%30;
			c += k*4;
		}
		if(n>=10)
		{
			int k = n/10;
			n = n%10;
			c += k;
		}
	}
	printf("%d\n", c);
	return 0;
}
