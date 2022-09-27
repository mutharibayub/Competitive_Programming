#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isValid(string code) {
    stack<string> tags;
    bool expectClose, expectOpen, CDATA;
    string content = "";
    expectClose = expectOpen = CDATA = false;
    for (int i = 0; code[i]; i++)
    {
        // cout<<code[i]<<" ";
        if (expectClose)
        {
            if (code[i] == '>')
            {
                if (tags.empty() || tags.top() != content)
                {
                    return false;
                }
                else
                {
                    tags.pop();
                    if (tags.empty() && code[i + 1])return false;
                }
                expectClose = false;
            }
            else if (code[i] < 'A' || code[i]>'Z' || content.length() == 9)
            {
                return false;
            }
            else
            {
                content.push_back(code[i]);
            }
        }
        else if (expectOpen)
        {
            if (code[i] == '>')
            {
                // cout<<"~"<<content<<"~";
                if (content == "")return false;
                tags.push(content);
                expectOpen = false;
            }
            else if (code[i] < 'A' || code[i]>'Z' || content.length() == 9)
            {
                return false;
            }
            else
            {
                content.push_back(code[i]);
            }
        }
        else if (CDATA)
        {
            if (code[i]==']' && i + 3<=code.size() && code[i+1]==']' && code[i+2]=='>')
            {
                CDATA = false;
                i += 2;
            }
            else
            {
                content.push_back(code[i]);
            }
        }
        else
        {
            content = "";
            if (code[i] == '<')
            {
                if (code[i + 1] == '/')
                {
                    expectClose = true;
                    if (tags.empty())return false;
                    i++;
                }
                else if (code[i + 1] == '!')
                {
                    if (i + 9 < code.size() && code.substr(i, 9) == "<![CDATA[")
                    {
                        CDATA = true;
                        if (tags.empty())return false;
                        i += 8;
                    }
                    else
                    {
                        expectOpen = true;
                    }
                }
                else
                {
                    expectOpen = true;
                }
            }
            else
            {
                if (tags.empty())return false;
            }

        }
    }
    if (tags.empty() && !expectOpen && !expectClose && !CDATA)return true;
    return false;
}

int main()
{
    cout<<isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>");   
    return 0;
}