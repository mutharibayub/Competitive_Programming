#include <iostream>
#include <vector>
#include <utility>
using namespace std;

string stringify(pair<int,int> p)
{
    string out = "";
    out.push_back(p.first/10+'0');
    out.push_back(p.first%10+'0');
    out.push_back(p.second/10+'0');
    out.push_back(p.second%10+'0');
    string outo = "";
    for(int i=0,copy=0;out[i];i++)
    {
        if(copy)
        {
            outo.push_back(out[i]);
        }
        else if(out[i]=='0')
        {
            continue;
        }
        else
        {
            outo.push_back(out[i]);
            copy = 1;
        }
    }
    return outo;
}

vector<pair<int,int>> genPossibs(int ts)
{
    vector<pair<int,int>> out;
    if(ts/60<100)
    {
        out.push_back(make_pair(ts/60,ts%60));
    }
    if(ts%60<40 && ts/60>0)
    {
        out.push_back(make_pair(ts/60-1, ts%60+60));
    }
    return out;
}

int getCost(const string& path, int start, int mc, int pc)
{
    int64_t cost = 0;
    int cPlace = start;
    for(int i=0;path[i];i++)
    {
        if(cPlace!=path[i]-'0')
        {
            cost+=mc;
            cPlace = path[i]-'0';
        }
        cost+=pc;
    }
    return cost;
}

int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
    vector<pair<int,int>> possibs = genPossibs(targetSeconds);
    int minCost = 999999;
    for(int i=0;i<possibs.size();i++)
    {
        int t = getCost(stringify(possibs[i]),startAt, moveCost, pushCost);
        if(t<minCost)
        {
            minCost = t;
        }
    }
    return minCost;
}

int main()
{
    cout<<minCostSetTime(9,1,2,0)<<endl;
    return 0;
}