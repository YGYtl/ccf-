#include<iostream>
using namespace std;
struct data{
	int x1, y1;
	int x2, y2;
};
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	data table[n];
	int f[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d %d %d %d", &table[i].x1, &table[i].y1, &table[i].x2, &table[i].y2);
		f[i] = n - i - 1;
	}
	int x, y;
	for(int i=0; i<m; i++)
	{
		scanf("%d %d", &x, &y);
		bool flag = true;
		for(int j=0; j<n; j++)
		{
			if(x >= table[f[j]].x1 && x <= table[f[j]].x2 && y >= table[f[j]].y1 && y <= table[f[j]].y2)
			{
				int v = f[j];
				printf("%d\n", f[j]+1);
				for(int k=j; k>0; k--) f[k] = f[k-1];
				f[0] = v;
				flag = false;
				break;
			}
		}
		if(flag) printf("IGNORED\n");
	}
	return 0;
}
