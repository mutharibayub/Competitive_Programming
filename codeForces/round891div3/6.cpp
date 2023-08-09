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
const int MOD = 1e9+7;
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
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        map<int, int> cnt;
        for(int i=0;i<n;i++)cnt[arr[i]]++;
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            ll a, b;
            cin>>a>>b;
            if(b==0)
            {
                cout << 1ll * cnt[0] * cnt[a];
            }
            else if(b>0)
            {
                if(!a)
                {
                    cout << 0;
                }
                else
                {
                    int mul = (a<0?-1:1);
                    a=abs(a);
                    ll cur=0;
                    for(ll jmp=a/2;jmp;jmp/=2)
                    {
                        while(cur+jmp<=a/2&&(cur+jmp)*(a-cur-jmp)<=b)cur+=jmp;
                    }
                    ll ans=(cur*(a-cur)==b?1ll*cnt[mul*cur]*cnt[mul*(a-cur)]:0);
                    if(cur*(a-cur)==b&&cur*2==a)ans=1ll*cnt[mul*cur]*(cnt[mul*cur]-1)/2;
                    cout << ans;
                }
            }
            else
            {
                int mul = (a<0?-1:1);
                a=abs(a),b=abs(b);
                ll cur=0;
                for(ll jmp=1e9;jmp;jmp/=2)
                {
                    while(cur+jmp<=1e9&&(cur+jmp)*(cur+jmp+a)<=b)cur+=jmp;
                }
                ll ans=(cur*(cur+a)==b?1ll*cnt[-1*mul*cur]*cnt[mul*(cur+a)]:0);
                if(cur*(cur+a)==b&&a==0)
                {
                    ans= 1ll*cnt[cur]*(cnt[cur]-1)/2 + 1ll*cnt[-cur]*(cnt[-cur]-1)/2;
                }
                cout << ans;
            }
            cout << " \n"[i==q-1];
        }
    }
    return 0;
}