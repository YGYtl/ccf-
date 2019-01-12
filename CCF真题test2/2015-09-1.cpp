#include<iostream>
using namespace std;
int main()
{
	int n, k, c=0, l;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &k);
		if(i==0)
		{
			l = k;
			c = 1;
		}
		else
		{
			if(l!=k)
			{
				l = k;
				c++;
			}
		}
	}
	printf("%d\n", c);
	return 0;
}
