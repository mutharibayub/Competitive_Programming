#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

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

class FenwickTree
{
    vector<int> arr;
public:
    FenwickTree(int n)
    {
        arr.resize(n+1, 0);
    }
    int get(int idx)
    {
        idx++;
        int o=0;
        while(idx)
        {
            o+=arr[idx];
            idx-=idx&-idx;
        }return o;
    }
    void update(int idx, int update)
    {
        idx++;
        while(idx<arr.size())
        {
            arr[idx]+=update;
            idx+=idx&-idx;
        }
    }
};

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
        map<int, ll> loc;
        vector<vector<array<int,2>>> al(n);
        for(int i=0;i<m;i++)
        {
            int u, v, dir;
            cin>>u>>v>>dir;
            u--,v--;
            al[v].push_back({u, dir});
            al[u].push_back({v, -dir});
        }
        vector<int> stk;
        bool ok=true;
        for(int i=0;i<n&&ok;i++)
        {
            if(loc.find(i)!=loc.end())continue;
            loc[i]=0;
            stk.push_back(i);
            while(!stk.empty()&&ok)
            {
                int top=stk.back();
                stk.pop_back();
                for(auto ele:al[top])
                {
                    if(loc.find(ele[0])==loc.end())
                    {
                        loc[ele[0]]=loc[top]+ele[1];
                        stk.push_back(ele[0]);
                    }
                    else
                    {
                        if(loc[ele[0]]!=loc[top]+ele[1])
                        {
                            ok=false;
                            break;
                        }
                    }
                }
            }
        }
        cout << (ok?"YES":"NO") << '\n';
    }
    return 0;
}