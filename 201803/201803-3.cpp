#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct data{
	vector<string> v;
	string s;
}a[104], b[104];

bool num(string s){
	for(int i=0; i<s.length(); i++){
		if(s[i]<'0'||s[i]>'9') return false;
	}
	return true;
}
bool strr(string s){
	int flag = true;
	for(int i=0; i<s.length()&&flag; i++){
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')) flag = true;
		else flag = false;
	}
	return flag;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	string s1, s2;
	for(int i=0; i<n; i++){
		cin >> s1 >> s2;
		string s;
		for(int j=0; j<s1.length(); j++){
			if(s1[j]=='/'){
				if(s.length()!=0){
					a[i].v.push_back(s);
				}
				s = "";
				continue;
			}
			s += s1[j];
		}
		if(s.length()!=0){
			a[i].v.push_back(s);
			s = "";
		}
		a[i].s = s2;
	}
	string s;
	for(int i=0; i<m; i++){
		cin >> s;
		string str;
		for(int j=0; j<s.length(); j++){
			if(s[j]=='/'){
				if(str.length()!=0){
					b[i].v.push_back(str);
				}
				str = "";
				continue;
			}
			str+=s[j];
		}
		if(str.length()!=0){
			b[i].v.push_back(str);
			str = "";
		}
	}
	
	for(int i=0; i<m; i++){//b
		bool f = true, g = false;
		int index = -1;
		for(int j=0; j<n; j++){//a
			if(a[j].v[0]==b[i].v[0]){//µÚÒ»¸ö 
				for(int k=1; k<a[j].v.size()&&f; k++){
					if(a[j].v[k]=="<path>"){
						g = true;
						break;
					}
					if(a[j].v[k]=="<int>"){
						
						continue;
					}
					if(a[j].v[k]=="<str>"){
						
						continue;
					}
					
				}
				index = j;
				break;
			}
		}
		if(f){
			cout << a[index].s;
			for(int i=1; i<b[index].v.size(); i++){
				if(i) cout << " ";
				if(i!=1&&g) cout << "/";
				cout << b[index].v[i];
			}
			cout << endl;
		}
		else{
			cout << "404" << endl;
		}
	}
	
	
	return 0;
}
