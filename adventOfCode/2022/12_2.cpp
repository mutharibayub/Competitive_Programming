#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <array>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    string filename = "12input.txt";
    ifstream fin(filename);

    vector<string> mat;
    while(!fin.eof())
    {
        string tmp;
        fin>>tmp;
        if(tmp=="")break;
        mat.push_back(tmp);
    }
    array<int,2> s,e;
    queue<pair<array<int,2>, int>> q; 
    set<array<int,2>> done;
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            if(mat[i][j]=='S')
            {
                s={i,j};
                mat[i][j]='a';
            }
            else if(mat[i][j]=='E')
            {
                e={i,j};
                mat[i][j]='z';
            }
        }
    }
    swap(s,e);
    q.push({s, 0});
    int ans=-1;
    while(!q.empty())
    {
        array<int,2> top = q.front().first;
        int cl = mat[top[0]][top[1]];
        int dist = q.front().second;
        if(cl=='a')
        {
            ans=dist;
            break;
        }
        q.pop();
        if(top[0]>0 && mat[top[0]-1][top[1]]-cl>-2 && done.find({top[0]-1, top[1]})==done.end())
        {
            done.insert({top[0]-1, top[1]});
            q.push({{top[0]-1, top[1]}, dist+1});
        }
        if(top[1]>0 && mat[top[0]][top[1]-1]-cl>-2 && done.find({top[0], top[1]-1})==done.end())
        {
            done.insert({top[0], top[1]-1});
            q.push({{top[0], top[1]-1}, dist+1});
        }
        if(top[0]<mat.size()-1 && mat[top[0]+1][top[1]]-cl>-2 && done.find({top[0]+1, top[1]})==done.end())
        {
            done.insert({top[0]+1, top[1]});
            q.push({{top[0]+1, top[1]}, dist+1});
        }
        if(top[1]<mat[0].size()-1 && mat[top[0]][top[1]+1]-cl>-2 && done.find({top[0], top[1]+1})==done.end())
        {
            done.insert({top[0], top[1]+1});
            q.push({{top[0], top[1]+1}, dist+1});
        }
    }
    cout << ans << '\n';

    return 0;
}