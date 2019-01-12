#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, k, count=1, num = 0;
	scanf("%d %d", &n, &k);
	vector<int> v;
	v.resize(n);
	for(int i=0; i<n; i++) v[i] = i+1;
	while(true)
	{
		for(int i=0; i<n; i++)
		{
			if(v[i]!=-1)
			{
				if(count%k==0||count%10==k)
				{
					v[i] = -1;
					num++;
					if(num==n-1) break;
				}
				count++;//±¨Êý 
			}
		}
		if(num==n-1) break;
	}
	for(int i=0; i<n; i++)
	{
		if(v[i]!=-1)
		{
			printf("%d\n", v[i]);
			return 0;
		}
	}
	return 0;
}
