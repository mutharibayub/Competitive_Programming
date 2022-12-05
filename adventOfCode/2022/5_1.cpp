#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    string filename = "5input.txt";
    ifstream fin(filename);
    
    vector<vector<string>> stks;
    string s;
    int n;
    fin>>n;
    stks.assign(n, vector<string>());
    while(1)
    {
        bool end=false;
        for(int i=0;i<n;i++)
        {
            fin>>s;
            if(s!="!"&&s!="_")
            {
                stks[i].push_back(s);
            }
            else if(s=="_")
            {
                end=true;
                break;
            }
        }
        if(end)break;
    }
    for(int i=0;i<n;i++)reverse(stks[i].begin(), stks[i].end());
    while(!fin.eof())
    {
        int a,b,c;
        fin>>a>>b>>c;
        b--,c--;
        for(int i=0;i<a;i++)
        {
            stks[c].push_back(stks[b].back());
            stks[b].pop_back();
        }
    }
    for(int i=0;i<n;i++)cout << stks[i].back();
    cout << '\n';

    return 0;
}