#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s, str1;
	cin >> s;
	int f, n;
	scanf("%d %d", &f, &n);
	if(f == 0)
	{
		for(int i=0; i<s.length(); i++)
		{
			if(s[i]>='A'&&s[i]<='Z') s[i] = s[i] + 32;
		}
	}
	for(int i=0; i<n; i++)
	{
		cin >> str1;
		string str2 = "", g;
		for(int j=0; j<str1.length(); j++) str2 += str1[j];
		if(f == 0)
		{
			for(int j=0; j<str2.length(); j++)
			{
				if(str2[j]>='A'&&str2[j]<='Z') str2[j] = str2[j] + 32;
			}
		}
		for(int j=0; j<str2.length(); j++)
		{
			for(int k=j; (k<j+s.length())&&k<str2.length(); k++) g += str2[k];
			if(g==s)
			{
				cout << str1 << endl;
				break;
			}
			g.clear();
		}
	}
	return 0;
}

