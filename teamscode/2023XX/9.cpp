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

const int N = 1000+1;
const int MOD = 998244353;
ll fact[N];
ll factInv[N];
ll nCr(ll n, ll r)
{
    return fact[n]*factInv[n-r]%MOD*factInv[r]%MOD;
}
ll pwr(ll b, ll e)
{
    ll o=1;
    while(e)
    {
        if(e&1)o=(o*b)%MOD;
        b=(b*b)%MOD;
        e/=2;
    }return o;
}
ll getInv(ll n)
{
    return pwr(n, MOD-2);
}
void initFact()
{
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%MOD;
    factInv[N-1]=getInv(fact[N-1]);
    for(int i=N-2;i>=0;i--)factInv[i]=(factInv[i+1]*(i+1))%MOD;
}

int getParent(vector<int> &parent, int u)
{
    if(parent[parent[u]]!=parent[u])
    {
        parent[u]=getParent(parent, parent[u]);
    }return parent[u];
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
        vector<array<int, 4>> coords(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<4;j++)
                cin>>coords[i][j];
        }
        map<int, array<int, 4>> prev;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            bool removed=true;
            sum += 1ll*(coords[i][2]-coords[i][0])*(coords[i][3]-coords[i][1]);
            while(removed)
            {
                removed=false;
                int toRemove=-1;
                for(auto [idx, box]: prev)
                {
                    if(box[2]<=coords[i][0]||coords[i][2]<=box[0])continue;
                    if(box[1]>=coords[i][3]||box[3]<=coords[i][1])continue;
                    sum -= 1ll*(box[2]-box[0])*(box[3]-box[1]);
                    sum -= 1ll*(coords[i][2]-coords[i][0])*(coords[i][3]-coords[i][1]);
                    coords[i][0]=min(coords[i][0], box[0]);
                    coords[i][1]=min(coords[i][1], box[1]);
                    coords[i][2]=max(coords[i][2], box[2]);
                    coords[i][3]=max(coords[i][3], box[3]);
                    sum += 1ll*(coords[i][2]-coords[i][0])*(coords[i][3]-coords[i][1]);
                    toRemove=idx;
                    removed=true;
                    break;
                }
                if(removed)prev.erase(toRemove);
            }
            prev[i]=coords[i];
            cout << sum << '\n';
        }
    }
    return 0;
}