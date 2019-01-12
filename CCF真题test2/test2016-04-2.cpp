#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int a[15][10], b[4][4];
	int o = 3, flag = 0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=0; i<15; i++) for(int j=0; j<10; j++) scanf("%d", &a[i][j]);
	for(int i=0; i<4; i++) for(int j=0; j<4; j++) scanf("%d", &b[i][j]);
	for(int i=3; i>=0; i--)
	{
		for(int j=0; j<4; j++)
		{
			if(b[i][j]!=0)
			{
				flag = 1;
				break;
			}
		}
		if(flag==1) break;
		o--;
	}
	
	return 0;
}
