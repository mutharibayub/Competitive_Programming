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
        n*=2;
        vector<array<int, 3>> arr(n);
        bool ok = false;
        for(int i=0;i<n;i++)
        {
            int a, b;
            char c;
            cin>>a>>b>>c;
            arr[i] = {a, b, (c=='(')*2-1};
        }
        auto &tarr=arr;
        for(int iter=0;iter<2&&!ok;iter++)
        {
            if(iter)arr=tarr;
            function<double(const array<int, 3>&, const array<int, 3>&)> calc = [&](auto obj1, auto obj2)
            {
                if(obj1[0]==obj2[0]&&obj1[1]==obj1[1])return 1.0;
                double val;
                if(iter==0)
                    val = 1.0*(obj2[1]-obj1[1])/(obj1[0]-obj2[0]);
                else
                    val = 1.0*(obj2[0]-obj1[0])/(obj1[1]-obj2[1]); 
                return val;
            };

            set<double> mults = {1};
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    double req = calc(arr[i], arr[j]);
                    if(req >= 1.0 && req!=numeric_limits<float>::infinity())
                    {
                        mults.insert(req);
                    }
                }
            }
            
            for(double mult: mults)
            {
                vector<pair<double, int>> tmp(n);
                for(int i=0;i<n;i++)
                {
                    if(iter==0)
                        tmp[i]={mult*arr[i][0]+arr[i][1], arr[i][2]};
                    else
                        tmp[i]={mult*arr[i][1]+arr[i][0], arr[i][2]};
                }
                for(int i=0;i<n;i++)
                {
                    bool swapped=false;
                    for(int j=0;j<n-1;j++)
                    {
                        if(tmp[j] > tmp[j+1])
                        {
                            swapped=true;
                            swap(tmp[j], tmp[j+1]);
                            swap(arr[j], arr[j+1]);
                        }
                    }
                    if(!swapped)break;
                }
                int sm=0;
                int cur=0;
                ok=true;
                for(int i=0;i<n+1;i++)
                {
                    if(i==n || (i&&tmp[i].first-tmp[i-1].first>0.000000000001))
                    {
                        sm+=cur;
                        if(sm<0)
                        {
                            ok=false;
                            break;
                        }
                        if(i<n)cur=tmp[i].second;
                    }
                    else if(i<n)
                    {
                        cur+=tmp[i].second;
                    }
                }
                if(ok)
                {
                    break;
                }
            }
        }
        cout << (ok?"YES":"NO") << '\n';
    }
    return 0;
}