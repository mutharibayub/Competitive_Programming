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
#include <limits>

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

// const int N = 2e5+1;
// const int MOD = 998244353;
// ll fact[N];
// ll factInv[N];
// ll nCr(ll n, ll r)
// {
//     return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
// }
// ll pwr(ll b, ll e)
// {
//     ll o=1;
//     while(e)
//     {
//         if(e&1)o=(o*b)%MOD;
//         b=(b*b)%MOD;
//         e/=2;
//     }return o;
// }
// ll getInv(ll n)
// {
//     return pwr(n, MOD-2);
// }
// void initFact()
// {
//     fact[0]=1;
//     for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%MOD;
//     factInv[N-1]=getInv(fact[N-1]);
//     for(int i=N-2;i>=0;i--)factInv[i]=(factInv[i+1]*(i+1))%MOD;
// }

int getParent(vector<int> &parent, int u)
{
    if(parent[parent[u]]!=parent[u])
    {
        parent[u]=getParent(parent, parent[u]);
    }return parent[u];
}

bool dfs(vector<vector<int>> &children, vector<int> &depth, vector<int> &color, vector<int> &done, int &xr, int u)
{
    done.push_back(u);
    if(children[u].size() == 1)
    {
        if(xr==-1)
        {
            xr = (depth[u]%2);
        }
        if(xr!=(depth[u]%2))
            return false;
    }  
    color[u] = depth[u]%2;  
    for(auto child: children[u])
    {
        if(!dfs(children, depth, color, done, xr, child))
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // initFact();

    int tttt=1;
    // cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<int> depth(n);
        vector<vector<int>> children(n);
        vector<int> parent(n);

        depth.front()=0;
        parent.front()=-1;
        int maxDepth = 0;

        for(int v=1;v<n;v++)
        {
            int u;
            cin>>u;
            u--;
            children[u].push_back(v);
            depth[v]=depth[u]+1;
            parent[v]=u;
            maxDepth = max(maxDepth, depth[v]);
        }

        int colorCount;
        vector<int> color(n);
        
        if(maxDepth == 1)
        {
            colorCount = 1;
            for(int i=0;i<n;i++)
            {
                color[i]=depth[i]-1;
            }
        }
        else
        {
            colorCount=2;
            bool ok = true;
            vector<int> done;
            for(int i=0;i<n&&ok;i++)
            {
                if(depth[i]!=1)
                    continue;
                int xr=-1;
                ok &= dfs(children, depth, color, done, xr, i);
                if(xr==1)
                for(auto u: done)
                    color[u]^=xr;
                done.clear();   
            }
            if(!ok)
            {
                colorCount=3;
                for(int i=0;i<n;i++)
                    color[i]=depth[i]%3;
            }
        }

        cout << colorCount << endl;
        for(int i=1;i<n;i++)
            cout << color[i]+1 << ' ';
        cout << endl;

        int last = -1;
        while(true)
        {
            int query;
            cin>>query;
            if(query == 0)
            {
                if(colorCount == 1)
                {
                    int col;
                    cin>>col;
                    cout << 1 << endl;
                }
                else if(colorCount == 2)
                {
                    array<int, 2> cnts;
                    int total = 0;
                    int chosen = -1;
                    for(int i=0;i<2;i++)
                    {
                        cin>>cnts[i];
                        if(last!=-1&&last==i)
                            cnts[i]=0;
                        total+=cnts[i];
                    }
                    if(total == 1)
                    {
                        if(cnts[0])
                            chosen = 0;
                        else
                            chosen = 1;
                    }
                    else if(total == 2)
                    {
                        assert(cnts[0]==1&&cnts[1]==1);
                        chosen = 0;
                    }
                    else
                    {
                        if(cnts[0]==1)
                            chosen = 0;
                        else 
                            chosen = 1;
                    }
                    last = chosen;
                    cout << chosen + 1 << endl;
                }
                else 
                {
                    array<int, 3> cnts;
                    int len=0;
                    int chosen=-1;
                    for(int i=0;i<3;i++)
                        cin>>cnts[i], len+=(cnts[i]!=0);
                    if(len==1)
                        for(int i=0;i<3;i++)
                            if(cnts[i])
                            {
                                cnts[(i+1)%3]=1;
                                break;
                            }
                    if(cnts[0]&&cnts[1])
                        chosen = 0;
                    else if(cnts[1]&&cnts[2])
                        chosen = 1;
                    else 
                        chosen = 2;
                    cout << chosen + 1 << endl;
                }
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}