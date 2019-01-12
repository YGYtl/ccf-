#include<iostream>
using namespace std;
int main()
{
	string s;
	int sum = 0;
	cin >> s;
	for(int i=0; i<s.length(); i++)
	{
		if(i==0) sum += (s[i]-'0')*1;
		else if(i==2) sum += (s[i]-'0')*2;
		else if(i==3) sum += (s[i]-'0')*3;
		else if(i==4) sum += (s[i]-'0')*4;
		else if(i==6) sum += (s[i]-'0')*5;
		else if(i==7) sum += (s[i]-'0')*6;
		else if(i==8) sum += (s[i]-'0')*7;
		else if(i==9) sum += (s[i]-'0')*8;
		else if(i==10) sum += (s[i]-'0')*9;
	}
	if((sum%11==s[12]-'0')||(sum%11==0&&s[12]=='X')) printf("Right\n");
	else
	{
		for(int i=0; i<12; i++) printf("%c", s[i]);
		if(sum%11!=10) printf("%c\n", sum%11+'0');
		else printf("X\n");
	}
	return 0;
}
