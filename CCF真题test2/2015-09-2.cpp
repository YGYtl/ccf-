#include<iostream>
using namespace std;
int main()
{
	int y, d;
	int r[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool flag = false;//平年 
	int month = 1;
	scanf("%d %d", &y, &d);
	if((y%4==0&&y%100!=0)||(y%400==0)) flag = true;//是闰年
	if(flag) r[1] = 29;
	for(int i=0; i<12; i++)
	{
		if(d<=r[i]) break;
		month++;
		d -= r[i];
	}
	printf("%d\n%d\n", month, d);
	return 0;
}
