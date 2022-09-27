#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(string s, string p)
{
    for(int i=0;i<2;i++)
    {
        while(!p.empty() && !s.empty() && p.back()!='*')
        {
            if(p.back()!=s.back() && p.back()!='?')
            {
                return false;
            }
            p.pop_back();
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        reverse(p.begin(), p.end());
    }
    int asterikCount = 0;
    for(int i=0;i<p[i];i++)
    {
        if(p[i]=='*')asterikCount++;
    }
    if(asterikCount == p.size() && asterikCount!=0)return true;
    if(s == "" || p == "")
    {
        if(s != "" || p != "")
        {
            return false;
        }
        return true;
    }
    vector<string> tokens;
    string tmp="";
    for(int i=0;p[i];i++)
    {
        if(p[i]=='*')
        {
            if(tmp!="")
            {
                tokens.push_back(tmp);
                tmp.clear();
            }
        }
        else
        {
            tmp.push_back(p[i]);
        }
    }
    if(tmp!="")
    {
        tokens.push_back(tmp);
    }
    reverse(tokens.begin(), tokens.end());
    for(int i=0;s[i];i++)
    {
        bool matched = true;
        for(int j=0;tokens.back()[j];j++)
        {
            if((tokens.back()[j]!=s[i+j] && tokens.back()[j]!='?') || (s[i+j]==0 && tokens.back()[j]=='?'))
            {
                matched = false;
                break;
            }
        }
        if(matched)
        {
            i += tokens.back().size()-1;
            tokens.pop_back();
            if(tokens.empty())
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string text = "abc";
    string pattern = "*abc?*";
    cout<<solve(text, pattern)<<'\n';

}