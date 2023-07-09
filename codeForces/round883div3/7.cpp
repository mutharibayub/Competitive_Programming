#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
const int MOD = 1e9+7;
 
ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}
 
ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

int toInt(string bin)
{
    int o=0;
    int p=1;
    while(bin.size())
    {
        o+=(bin.back()=='1'?p:0);
        p*=2;
        bin.pop_back();
    }return o;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, m;
        cin>>n>>m;
        string tmp;
        cin>>tmp;
        int start = toInt(tmp);
        vector<pair<int,int>> meds(m);
        vector<int> medCost(m);
        for(int i=0;i<m;i++)
        {
            cin>>medCost[i];
            cin>>tmp;
            meds[i].first=toInt(tmp);
            cin>>tmp;
            meds[i].second=toInt(tmp);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int minCost = -1;
        pq.push({0, 0});
        vector<bool> done(1<<n, false);
        while(!pq.empty())
        {
            int topCost = pq.top().first;
            int topMask = pq.top().second;
            done[topMask]=true;
            if((topMask|start)==topMask)
            {
                minCost=topCost;
                break;
            }
            for(int i=0;i<m;i++)
            {
                if((meds[i].second|topMask)==topMask&&(topMask|meds[i].first)!=topMask)
                {
                    pq.push({medCost[i]+topCost, meds[i].first|topMask});
                }
            }
            while(!pq.empty()&&done[pq.top().second])pq.pop();
        }
        
        cout << minCost << '\n';
    }    
 
    return 0;
}