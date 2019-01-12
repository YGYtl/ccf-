#include<stdio.h>
int main()
{
	char a[20]={'\0'};
	char b[20]={'\0'};
	gets(a);
	int count = 0;
	int i, sum=0, k=1;
	for(i=0; count<3; i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			sum = sum + (a[i]-'0')*k;
			k++;
		}
		else{
			count++;
		}
		b[i] = a[i];
	}
	int m=0;
	m = sum%11;
	if(m<10&&a[i]-'0'==m) printf("Right");
	else if(m==10&&a[i]=='X') printf("Right");
	else{
		printf("%s", b);
		if(m<10) printf("%d", m);
		else printf("X");
	}
	return 0;
}
