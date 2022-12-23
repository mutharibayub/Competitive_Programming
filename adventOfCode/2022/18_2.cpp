#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <array>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

#define DEBUG(X) cout << #X": " << X << endl;

typedef long long ll;

void parseString(const string &s, array<int,3> &out)
{
    int cnt=0;
    for(int i=0;s[i];i++)
    {
        string tmp="";
        if(s[i]>='0'&&s[i]<='9')
        {
            while(s[i]>='0'&&s[i]<='9')
            {
                tmp.push_back(s[i]);
                i++;
            }
            out[cnt++]=stoi(tmp);
            if(cnt==3)return;
            i--;
        }
    }
}

int main()
{
    string filename = "18input.txt";
    ifstream fin(filename);

    set<array<int,3>> pts;
    array<int,3> mn={(int)1e9+7,(int)1e9+7,(int)1e9+7}, mx={-1,-1,-1};

    while(!fin.eof())
    {
        string tmp;
        fin>>tmp;
        if(tmp=="")break;
        array<int,3> pt;
        parseString(tmp, pt);
        for(int i=0;i<3;i++)
        {
            mn[i]=min(mn[i], pt[i]);
            mx[i]=max(mx[i], pt[i]);
        }
        pts.insert(pt);
    }

    for(int i=0;i<3;i++)
    {
        mn[i]--;
        mx[i]++;
    }

    vector<array<int,3>> nbs = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

    set<array<int,3>> water;
    vector<array<int,3>> stk;
    stk.push_back(mn);
    water.insert(mn);
    while(!stk.empty())
    {
        array<int,3> pt=stk.back();
        stk.pop_back();
        for(auto nb:nbs)
        {
            array<int,3> tpt=pt;
            for(int i=0;i<3;i++)tpt[i]+=nb[i];
            bool outOfRange = false;
            for(int i=0;i<3;i++)
            {
                outOfRange|=(tpt[i]<mn[i])||(tpt[i]>mx[i]);
            }
            if(!outOfRange&&pts.find(tpt)==pts.end()&&water.find(tpt)==water.end())
            {
                water.insert(tpt);
                stk.push_back(tpt);
            }
        }
    }

    int ans=0;
    for(auto pt:pts)
    {
        for(auto nb:nbs)
        {
            array<int,3> tpt=pt;            
            for(int i=0;i<3;i++)tpt[i]+=nb[i];
            if(pts.find(tpt)==pts.end() && water.find(tpt)!=water.end())
            {
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}