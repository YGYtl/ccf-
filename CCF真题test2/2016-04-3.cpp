#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct text* t;
struct text{
	string txt;
	t next;
	text()
	{
		txt = "";
		next = NULL;
	}
};
typedef struct directory* dir;
struct directory{
	string d;
	dir first;
	t txtt;
	dir next;
	directory()
	{
		d = ""; 
		first = NULL;
		txtt = NULL;
		next = NULL;
	}
}; 


int main()
{
	int n;
	string s;
//	scanf("%d", &n);
	Create_Tree();
	cout << head->d << endl;
//	for(int i=0; i<n; i++)
//	{
//		getline(cin,s);
//		for(int j=0; j<s.length(); j++)
//		{
//			
//		}
//	}
	return 0;
}
