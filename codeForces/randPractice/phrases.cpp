#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <string>
using namespace std;

vector<string> splitStr(const string& s,char delim)
{
    vector<string> out;
    string t="";
    for(int i=0;s[i];i++)
    {
        if(s[i]==delim)
        {
            out.push_back(t);
            t="";
        }
        else
        {
            t.push_back(s[i]);
        }
    }
    out.push_back(t);
    return out;
}

string testCase()
{
    string in;
    getline(cin,in);
    vector<string> keywords=splitStr(in,',');
    string phrase;
    getline(cin,phrase);
    unordered_set<string> kws;
    unordered_set<int> lens;
    int maxLen=0;

    for(auto it:keywords)
    {
        kws.insert(it);
        lens.insert(it.size());
        if(it.size()>maxLen)maxLen=it.size();
    }

    vector<int> phraseScore(phrase.size()+1,0);
    phraseScore[0]=1;
    string temp;
    for(int i=0;i<phraseScore.size();i++)
    {
        temp="";
        if(phraseScore[i]==0)continue;
        for(int j=1;j<=maxLen && j+i<phraseScore.size();j++)
        {  
            temp.push_back(phrase[i+j-1]);
            if(lens.find(j)==lens.end())continue;
            if(kws.count(temp)>0)phraseScore[i+j]+=phraseScore[i];
        }
    }
    return to_string(phraseScore.back())+"\n";
}

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    string out="";
    for(int i=0;i<n;i++)
    {
        out+=testCase();
    }
    cout<<out;

    return 0;
}