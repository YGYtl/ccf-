#include<stdio.h>
int two(int n)
{
	if((n%400==0)||(n%4==0&&n%100!=0))
		return 1;
	return 0;
}
int main()
{
	int y, d, i;
	scanf("%d %d", &y, &d);
	int mon[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(two(y)) mon[1]++;
	for(i=0; i<12; i++)
	{
		if(d<=mon[i])
		{
			printf("%d\n%d\n", i+1, d);
			break;
		}
		d -= mon[i];
	}
	return 0;
}
