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
        int n;
        cin>>n;
        vector<ll> pref(n-1);
        for(int i=0;i<n-1;i++)cin>>pref[i];
        vector<ll> eles(n-1);
        vector<int> cnt(n+1, 0);
        ll extra=-1;
        bool ok=true;
        for(int i=0;i<n-1&&ok;i++)
        {
            eles[i]=pref[i]-(i?pref[i-1]:0);
            if(eles[i]>n)
            {
                if(extra!=-1)ok=false;
                else extra=eles[i];
            }
            else if(eles[i]<=0)ok=false;
            else cnt[eles[i]]++;
        }
        if(!ok)
        {
            cout << "NO" << '\n';
            continue;
        }
        vector<int> missing;
        for(int i=1;i<=n;i++)
        {
            if(extra==-1&&cnt[i]==2)extra=i;
            else if(!cnt[i])missing.push_back(i);
        }
        if((missing.size()==2&&extra!=-1&&missing.front()+missing.back()==extra)||(missing.size()==1&&extra==-1))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}