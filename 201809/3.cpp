#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct data{
	char s[100];
}a[104], b[20];

struct d{
	vector<string> v;
}A[104], B[20];
int main()
{
	int n, m;
	cin >> n >> m;
	getchar();
	for(int i=0; i<n; i++) gets(a[i].s);
	for(int i=0; i<n; i++){
		string s="";
		bool flag = true;
		for(int j=0; a[i].s[j]!='\0'; j++){
			if(a[i].s[j]=='#') flag = false;
			if(a[i].s[j]>='A'&&a[i].s[j]<='Z'&&flag) a[i].s[j]+=32;
			if(a[i].s[j]=='.') continue;
			if(a[i].s[j]==' '){
				A[i].v.push_back(s);
				s = "";
			}
			else s += a[i].s[j];
		}
		if(s.length()!=0) A[i].v.push_back(s);
	}
	for(int i=0; i<m; i++) gets(b[i].s);
	for(int i=0; i<m; i++){
		string s="";
		bool flag = true;
		for(int j=0; b[i].s[j]!='\0'; j++){
			if(b[i].s[j]=='#') flag = false;
			if(b[i].s[j]>='A'&&b[i].s[j]<='Z'&&flag) b[i].s[j]+=32;
			if(b[i].s[j]==' '){
				B[i].v.push_back(s);
				s = "";
			}
			else s += b[i].s[j];
		}
		if(s.length()!=0) B[i].v.push_back(s);
	}
	for(int i=0; i<m; i++){
		int c = 0, g = 0;
		vector<int> vm;
		for(int j=0; j<n; j++){
			for(int k=0; k<A[j].v.size(); k++){
				if(B[i].v[g]==A[j].v[k]){
					g++;
					if(g==B[i].v.size()){
						c++; g=0;
						vm.push_back(j+1);
					}
				}
			}
		}
		printf("%d", vm.size());
		for(int j=0; j<vm.size(); j++) printf(" %d", vm[j]);
		printf("\n");
	}
	return 0;
}
