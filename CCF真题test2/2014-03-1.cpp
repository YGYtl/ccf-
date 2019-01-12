#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, c=0;
	scanf("%d", &n);
	vector<int> v;
	v.resize(n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &v[i]);
		for(int j=0; j<i; j++)
		{
			if(abs(v[i])==abs(v[j])&&v[i]!=v[j])
			{
				v[i] = 0;
				v[j] = 0;
				c++;
				break;
			}
		}
	}
	printf("%d\n", c);
	return 0;
}
