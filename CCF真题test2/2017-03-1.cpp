#include<iostream>
using namespace std;
int main()
{
	int n, k, c = 0, sum=0, g;
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &g);
		sum += g;
		if(sum >= k)
		{
			c++;
			sum = 0;
		}
	}
	if(sum!=0) c++;
	printf("%d\n", c);
	return 0;
}
