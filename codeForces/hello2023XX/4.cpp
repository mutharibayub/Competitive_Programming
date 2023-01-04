#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <assert.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll norm(ll n, ll mod=MOD)
{
    return (n%mod+mod)%mod;
}

ll pwr(ll n, ll e, ll mod = MOD)
{
    ll a=1;
    while(e)
    {
        if(e&1)
        {
            a = norm(a*n);
        }
        n=norm(n*n);
        e/=2;
    }
    return a;
}

ll gcd(ll a, ll b)
{
    if(b>a)swap(a,b);
    if(!b)return a;
    return gcd(b, a%b);
}

class sqrtDecom
{
private:
    vector<ll> arr;
    vector<ll> box;
    int boxSize=447;
public:
    sqrtDecom(vector<ll> &a)
    {
        arr=a;
        box.assign((a.size()+boxSize-1)/boxSize,0);
        for(int i=0;i<arr.size();i++)
        {
            box[i/boxSize]=max(box[i/boxSize],arr[i]);
        }
    }
    ll getMax(int s, int e)
    {
        ll ans=0;
        for(;s<=e;)
        {
            int boxNum = s/boxSize;
            if(s%boxSize||s+boxSize>e)
            {
                ans=max(ans,arr[s]);
                s++;
            }
            else
            {
                ans=max(ans,box[boxNum]);
                s+=boxSize;
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI = true;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        vector<ll> a(n),b(n);
        map<ll,vector<int>> inds;
        map<ll, int> rzs;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        cin>>m;
        for(int i=0;i<m;i++)
        {
            ll rz;
            cin>>rz;
            rzs[rz]++;
        }
        auto sqrtD = sqrtDecom(b);
        bool no=false;
        for(int i=0;i<n&&!no;i++)
        {
            if(b[i]>a[i])no=true;
            else if(b[i]<a[i])inds[b[i]].push_back(i);
        }
        if(no)
        {
            cout << "NO" << '\n';
            continue;
        }
        for(auto num:inds)
        {
            auto &arr = num.second;
            ll mxr = num.first;
            int cnt=1;
            for(int i=0;i+1<arr.size();i++)
            {
                ll mx = sqrtD.getMax(arr[i],arr[i+1]);
                if(mx>mxr)
                {
                    cnt++;
                }
            }
            rzs[mxr]-=cnt;
            if(rzs[mxr]<0)
            {
                no=true;
                break;
            }
        }
        cout << (no?"NO":"YES") << '\n';
    }

    return 0;
}