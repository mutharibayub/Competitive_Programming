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

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

const int MAXN = 2e5+1;
vector<int> children[MAXN];
int iColor[MAXN];
int fColor[MAXN];
int colorCost[MAXN];
ll dp[MAXN][3]; // ancestor never set, ancestor set to correct, ancestor set to wrong

void dfs(int u)
{   
    dp[u][0]=dp[u][1]=dp[u][2]=1e16;

    for(auto child: children[u])
        dfs(child);

    ll cc = 0;
    for(auto child: children[u])
        cc += (fColor[child]!=fColor[u]?dp[child][2]:dp[child][1]);
    dp[u][2] = colorCost[u]+cc;
    dp[u][1] = dp[u][2]-colorCost[u];
    dp[u][0] = dp[u][2];
    if(fColor[u]==iColor[u])
    {
        cc = 0;
        for(auto child: children[u])
        {
            cc += dp[child][0];
        }
        dp[u][0]=min(dp[u][0], cc);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // initFact();

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            children[i].clear();

        for(int i=0;i<n-1;i++)
        {
            int u;
            cin>>u;
            u--;
            children[u].push_back(i+1);
        }
        for(int i=0;i<n;i++)cin>>colorCost[i];
        for(int i=0;i<n;i++)cin>>iColor[i];
        for(int i=0;i<n;i++)cin>>fColor[i]; 
        dfs(0);
        cout << dp[0][0] << '\n';
    }
    return 0;
}