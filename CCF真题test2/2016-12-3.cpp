#include<iostream>
using namespace std;
struct power{
	string s;
	int num;
	power() { num = 0; }
}power1[101];
struct role{
	string s;
	int c;
	power p[101];
	role() { c = 0; }
}role1[101];
struct people{
	string s;
	int c;
	role r[101];
	people() { c = 0; }
}people1[101];


int main()
{
	int p, r, u, q;
	string s;
	scanf("%d", &p);
	for(int i=0; i<p; i++)
	{
		cin >> s;
		int num = 0;
		for(int j=0; j<s.length(); j++)
		{
			if(s[j]==':')
			{
				s.erase(j,1);
				while(s[j]>='0'&&s[j]<='9') num = num*10+s[j]-'0', s.erase(j,1);
				break;
			}
		}
		power1[i].s = s;
		power1[i].num = num;
	}
	scanf("%d", &r);
	string str;
	int k;
	for(int i=0; i<r; i++)
	{
		cin >> str >> k;
		for(int o=0; o<k; o++)
		{
			cin >> s;
			int num = 0;
			for(int j=0; j<s.length(); j++)
			{
				if(s[j]==':')
				{
					s.erase(j,1);
					while(s[j]>='0'&&s[j]<='9') num = num*10+s[j]-'0', s.erase(j,1);
					break;
				}
			}
			role1[i].s = str;
			role1[i].p[role1[i].c].s = s;
			role1[i].p[role1[i].c].num = num;
			role1[i].c++;
		}
	}
	scanf("%d", &u);
	for(int i=0; i<u; i++)
	{
		cin >> str >> k;
		people1[i].s = str;
		people1[i].c = k;
		for(int j=0; j<k; j++)
		{
			cin >> s;
			people1[i].r[j].s = s;
		}
	}
	scanf("%d", &q);
	for(int i=0; i<q; i++)
	{
		cin >> str >> s;
		int num = 0;
		for(int j=0; j<s.length(); j++)
		{
			if(s[j]==':')
			{
				s.erase(j,1);
				while(s[j]>='0'&&s[j]<='9') num = num*10+s[j]-'0', s.erase(j,1);
				break;
			}
		}
		//s 和 num
		bool flag = false, flag2 = false;
		int max = 0;
		for(int i=0; i<p; i++)
		{
			if(power1[i].s==s)
			{
				flag2 = true;
				break;
			}
		}
		if(flag2 == false)
		{
			printf("false\n");
			continue;
		}
		for(int i=0; i<u&&flag==false; i++)
		{
			if(people1[i].s==str)//找到玩家 
			{
				for(int j=0; j<people1[i].c; j++)//角色数量 
				{
					for(int k=0; k<r; k++)
					{
						if(role1[k].s==people1[i].r[j].s)//找到相同角色 
						{
							for(int o=0; o<role1[k].c; o++)
							{
								if(role1[k].p[o].s==s&&role1[k].p[o].num>=num)
								{
									flag = true;
									if(role1[k].p[o].num>num&&role1[k].p[o].num>max)
									{
										max = role1[k].p[o].num;
										
									}
								}
							}
						}
					}
				}
			}
		}
		if(flag == false) printf("false\n");
		else
		{
			if(num==0&&max!=0) printf("%d\n", max);
			else printf("true\n");
		}
	}
	return 0;
}
