#include<iostream>
using namespace std;
int main()
{
	int a[15][15];
	int b[4][4];
	for(int i=0; i<15; i++) for(int j=0; j<10; j++) scanf("%d", &a[i][j]);
	for(int i=0; i<4; i++) for(int j=0; j<4; j++) scanf("%d", &b[i][j]);
	int k, flag = 0;
	scanf("%d", &k);
	int x = k-1;
	int y = x+4;
	int u = 3;
	for(int i=3; i>=0; i--)
	{
		for(int j=0; j<4; j++)
		{
			if(b[i][j]==1)
			{
				flag = 1;
				break;
			}
		}
		if(flag==1) break; 
		u--;//2
	}
	int f = 14;//
	for(int i=4; i<15; i++)
	{
		int c = u;
		for(int j=i; j>=i-u; j--)
		{
			if((a[j][x]==b[c][0]&&b[c][0]==1)||(a[j][x+1]==b[c][1]&&b[c][1]==1)||(a[j][x+2]==b[c][2]&&b[c][2]==1)||(a[j][x+3]==b[c][3]&&b[c][3]==1))
			{
				f = i-1;
				break;
			}
			c--;
		}
		if(f!=14) break;
	}
	int g = u;
	for(int i=f; i>=f-u; i--)
	{
		int c = 0;
		for(int j=x; j<y; j++)
		{
			if(b[g][c++]==0) continue;
			a[i][j] = 1;
		}
		g--;
	}
	for(int i=0; i<15; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(f) printf(" ");
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
