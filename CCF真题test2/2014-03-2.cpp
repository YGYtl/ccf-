#include<iostream>
using namespace std;
struct data{
	int x1, y1;
	int x2, y2;
};
int main()
{
	int n, m;
	int x, y;
	int num;
	scanf("%d %d", &n, &m);
	data table[n];
	int f[n];//记录层数 
	for(int i=0; i<n; i++)//最下层到最上层 
	{
		scanf("%d %d %d %d", &table[i].x1, &table[i].y1, &table[i].x2, &table[i].y2);
		f[i] = n-i-1;
	}
	for(int i=0; i<m; i++)
	{
		scanf("%d %d", &x, &y);
		num = -1;
		for(int j=0; j<n; j++)//最上面一层开始找 
		{
			if(table[f[j]].x1<=x&&table[f[j]].y1<=y&&table[f[j]].x2>=x&&table[f[j]].y2>=y)
			{
				num = j;
				printf("%d\n", f[j]+1);
				int v = f[j];
				for(int k=j; k>0; k--) f[k] = f[k-1];//改变层数
				f[0] = v;
				break;
			}
		}
		if(num==-1) printf("IGNORED\n");
	}
	return 0;
}
