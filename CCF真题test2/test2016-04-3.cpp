#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int num,pos,pos1;
	string curPos,line;
	cin >> num >> curPos;
	getchar();
	while (num--)
	{
		getline(cin, line);
		//  1.首位不为'/'的情况
		if (line.empty())line = curPos;
		else if (line[0] != '/')line = curPos + "/" + line;
		//  2.出现/../
		while ((pos = line.find("/../")) != -1)
		{
			if (!pos)line.erase(0, 3);
			else{
				pos1 = line.rfind("/", pos - 1);
				line.erase(pos1, pos - pos1 + 3);
			}
		}
		while ((pos = line.find("/./")) != -1)line.erase(pos, 2);//   3.出现/./
		while ((pos = line.find("//")) != -1) line.erase(pos, 1);//   4.出现///
		if (line.size()>1 && line[line.size() - 1] == '/')line.erase(line.size() - 1, 1);//   5.末尾有/
		cout << line << endl;// 6.最后输出
	}
	return 0;
}
