#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <string>
using namespace std;

vector<int> splitStrToInt(const string& s,char delim)
{
    vector<int> out;
    string t="";
    for(int i=0;s[i];i++)
    {
        if(s[i]==delim)
        {
            out.push_back(stoi(t));
            t="";
        }
        else
        {
            t.push_back(s[i]);
        }
    }
    out.push_back(stoi(t));
    return out;
}

vector<vector<int>> getPaths(const vector<int>& inOrd,const vector<int>& postOrd)
{
    //save locations of number of inOrd in a dict
    unordered_map<int,int> locs;
    for(int i=0;i<inOrd.size();i++)
    {
        locs[inOrd[i]]=i;
    }

    //use two stacks one for saving the range of current tree and second for saving its coord
    // in final tree vector
    stack<pair<int,int>> rangeStk;
    rangeStk.push(make_pair(0,inOrd.size()-1));
    vector<int> path;

    vector<vector<int>> paths;
    bool toSave=false;
    pair<int,int> range;
    for(int i=postOrd.size()-1;i>=0;i--)
    {
        range=rangeStk.top();
        rangeStk.pop();
        while(!path.empty() && (locs[path.back()]<range.first-1 || locs[path.back()]>range.second+1))
        {
            if(toSave)
            {
                paths.push_back(path);
                toSave=false;
            }
            path.pop_back();
        }
        path.push_back(postOrd[i]);
        toSave=true;
        if(range.first<=locs[postOrd[i]]-1)
        {
            rangeStk.push(make_pair(range.first,locs[postOrd[i]]-1));
        }
        if(locs[postOrd[i]]+1<=range.second)
        {
            rangeStk.push(make_pair(locs[postOrd[i]]+1,range.second));
        }
    }
    if(toSave)paths.push_back(path);
    return paths;
}

string testCase()
{
    string out="";
    string inn,postt,toCC;
    getline(cin,inn);
    getline(cin,postt);
    getline(cin,toCC);
    vector<int> inOrd=splitStrToInt(inn,' ');
    vector<int> postOrd=splitStrToInt(postt,' ');
    vector<int> toCheck=splitStrToInt(toCC,' ');
    vector<vector<int>> paths = getPaths(inOrd,postOrd);
    unordered_set<int> lens;
    for(int i=0;i<paths.size();i++)
    {
        for(int j=0;j<paths[i].size();j++)
        {
            int len=0;
            for(int k=j;k<paths[i].size();k++)
            {
                len+=paths[i][k];
                lens.insert(len);
            }
        }
    }
    for(int i=0;i<toCheck.size();i++)
    {
        if(lens.find(toCheck[i])==lens.end())
        {
            out+="FALSE\n";
        }
        else
        {
            out+="TRUE\n";
        }
    }
    return out;
}

int main()
{
    int n;
    string out="";
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        out+=testCase();
    }
    cout<<out;
}