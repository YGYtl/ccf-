#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    string s;
    bool flag = false;
    string text = "";
    while (getline(cin,s))  
    {
        if (s.length() == 0)
        {
            int _sum = 1;
            if (flag)
            {
                if (text[1] == 'p') text.erase(text.length()-1,1),text += "</p>";
                if (text[1] == 'u')  text += "</ul>";
	            for (int i = 0; i < text.length(); i++)
	            {
	                if (text[i] == '_')
	                {
	                    text.erase(i, 1);
	                    if (_sum == 1) text.insert(i, "<em>");
	                    if (_sum == 2) text.insert(i, "</em>");
	                    _sum = (_sum == 1 ? 2 : 1);
	                }
	            }
	            for (int i = 0; i < text.length(); i++)
	            {
	                if (text[i] == '[')
	                {
	                    string link = "", href = "";
	                    text.erase(i, 1);//É¾µô 
	                    while (text[i] != ']') link += text[i], text.erase(i, 1);
	                    text.erase(i, 2);
	                    while (text[i] != ')') href += text[i], text.erase(i, 1);
	                    text.erase(i, 1);
	                    string ans = "";
	                    ans += "<a href=\"", ans += href, ans += "\">", ans += link, ans += "</a>";
	                    text.insert(i, ans);
	                }
	            }
	            cout << text << endl;
	            text = "", flag = false;
            }
        }
        if (s[0] == '#')
        {
            int sum = 0;
            while (s[0] == '#') sum++, s.erase(0, 1);
            while (s[0] == ' ') s.erase(0, 1);
            string ans;
            ans += "<h" , ans += (sum + '0'), ans += ">";
            s.insert(0, ans), ans = "";
            ans += "</h", ans += (sum + '0'), ans += ">";
            s += ans;
            text += s, flag = true;
        }
        else if (s[0] == '*')
        {
            s.erase(0, 1);
            while(s[0] == ' ') s.erase(0,1);
            s.insert(0,"<li>");
            s+="</li>";
            if (!flag)
            {
                string ans = "";
                ans += "<ul>", ans += "\n";
                s.insert(0, ans);
            }
            text += s, text+="\n", flag = true;
        }
        else if(s[0])
        {
            if (!flag)
            {
                s.insert(0, "<p>");
            }
            flag = true, text += s, text += "\n";
        }
    }
    int _sum = 1;
    if (text[1] == 'p') text.erase(text.length() - 1, 1), text += "</p>";
    if (text[1] == 'u') text += "</ul>";
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '_')
        {
            text.erase(i, 1);
            if (_sum == 1) text.insert(i, "<em>");
            if (_sum == 2) text.insert(i, "</em>");
            _sum = (_sum == 1 ? 2 : 1);
        }
    }
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '[')
        {
            string link = "", href = "";
            text.erase(i, 1);
            while (text[i] != ']')link += text[i], text.erase(i, 1);
            text.erase(i, 2);
            while (text[i] != ')') href += text[i], text.erase(i, 1);
            text.erase(i, 1);
            string ans = "";
            ans += "<a href=\"", ans += href, ans += "\">", ans += link, ans += "</a>";
            text.insert(i, ans);
        }
    }
    cout << text << endl;
    text = "", flag = false;
    return 0;
}
