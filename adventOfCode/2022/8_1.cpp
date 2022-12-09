#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    string filename = "8input.txt";
    ifstream fin(filename);

    set<pair<int,int>> visible;
    vector<string> mat;
    while(!fin.eof())
    {
        string s;
        fin>>s;
        if(s=="")break;
        mat.push_back(s);
    }
    for(int i=0;i<mat.size();i++)
    {
        int mx=-1;
        for(int j=0;j<mat[0].size();j++)
        {
            if(mx<mat[i][j]-'0')visible.insert({i,j});
            mx = max(mx, mat[i][j]-'0');
        }
        mx=-1;
        for(int j=mat[0].size()-1;j>=0;j--)
        {
            if(mx<mat[i][j]-'0')visible.insert({i,j});
            mx = max(mx, mat[i][j]-'0');
        }    
    }
    for(int i=0;i<mat[0].size();i++)
    {
        int mx=-1;
        for(int j=0;j<mat.size();j++)
        {
            if(mx<mat[j][i]-'0')visible.insert({j,i});
            mx = max(mx, mat[j][i]-'0');
        }
        mx=-1;
        for(int j=mat.size()-1;j>=0;j--)
        {
            if(mx<mat[j][i]-'0')visible.insert({j,i});
            mx = max(mx, mat[j][i]-'0');
        }    
    }
    cout << visible.size() << '\n';
    return 0;
}