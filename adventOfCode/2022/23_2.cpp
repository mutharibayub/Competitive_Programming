#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <array>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

#define DEBUG(X) cout << #X": " << X << endl;

void printGrid(set<array<int,2>> &lcs)
{
    int mnr=1e9+7,mnc=1e9+7,mxr=-1*(1e9+7),mxc=-1*(1e9+7);
    for(auto lc:lcs)
    {
        mnr=min(mnr,lc[0]);
        mnc=min(mnc,lc[1]);
        mxr=max(mxr,lc[0]);
        mxc=max(mxc,lc[1]);
    }
    int R=mxr-mnr+1;
    int C=mxc-mnc+1;
    vector<string> grid(R,string(C,'.'));
    for(auto lc:lcs)
    {
        grid[lc[0]-mnr][lc[1]-mnc]='#';
    }
    for(int i=0;i<R;i++)
    cout << grid[i] << '\n';
}

int main()
{
    string filename = "23input.txt";
    ifstream fin(filename);

    set<array<int,2>> lcs;
    int r=0;
    while(!fin.eof())
    {
        string s;
        fin>>s;
        if(s=="")break;
        for(int c=0;s[c];c++)
        {
            if(s[c]=='#')
            {
                lcs.insert({r,c});
            }
        }
        r++;
    }

    array<int,2> pb[4][3] = {{{-1,-1},{-1,0},{-1,1}},{{1,-1},{1,0},{1,1}},{{-1,-1},{0,-1},{1,-1}},{{-1,1},{0,1},{1,1}}};
    int pbc = 0;
    int ans=0;
    map<array<int,2>,int> prop;
    for(int i=0;;i++)
    {
        bool move=false;
        prop.clear();
        for(auto lc:lcs)
        {
            bool skip=true;
            for(int j=0;j<4&&skip;j++)
            {
                for(int k=0;k<3&&skip;k++)
                {
                    array<int,2> tlc = {pb[j][k][0]+lc[0], pb[j][k][1]+lc[1]};
                    if(lcs.find(tlc)!=lcs.end())skip=false;              
                }
            }
            if(skip)continue;
            for(int j=0;j<4;j++)
            {
                bool free=true;
                int tpbc = (pbc+j)%4;
                for(int k=0;k<3;k++)
                {
                    array<int,2> tlc = {pb[tpbc][k][0]+lc[0], pb[tpbc][k][1]+lc[1]};
                    if(lcs.find(tlc)!=lcs.end())
                    {
                        free=false;
                        break;
                    }
                }
                if(free)
                {
                    array<int,2> tlc = {pb[tpbc][1][0]+lc[0], pb[tpbc][1][1]+lc[1]};
                    prop[tlc]++;
                    break;
                }
            }
        }
        set<array<int,2>> tmp = lcs;
        for(auto lc:tmp)
        {
            bool skip=true;
            for(int j=0;j<4&&skip;j++)
            {
                for(int k=0;k<3&&skip;k++)
                {
                    array<int,2> tlc = {pb[j][k][0]+lc[0], pb[j][k][1]+lc[1]};
                    if(tmp.find(tlc)!=tmp.end())skip=false;              
                }
            }
            if(skip)continue;
            for(int j=0;j<4;j++)
            {
                bool free=true;
                int tpbc = (pbc+j)%4;
                for(int k=0;k<3;k++)
                {
                    array<int,2> tlc = {pb[tpbc][k][0]+lc[0], pb[tpbc][k][1]+lc[1]};
                    if(tmp.find(tlc)!=tmp.end())
                    {
                        free=false;
                        break;
                    }
                }
                if(free)
                {
                    array<int,2> tlc = {pb[tpbc][1][0]+lc[0], pb[tpbc][1][1]+lc[1]};
                    if(prop[tlc]==1)
                    {
                        lcs.erase(lc);
                        lcs.insert(tlc);
                        move=true;
                    }
                    break;
                }
            }
        }
        ans=i+1;
        if(!move)break;
        pbc=(pbc+1)%4;
    }

    cout << ans << '\n';

    return 0;
}