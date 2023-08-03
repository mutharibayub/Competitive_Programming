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
        vector<array<int,3>> arr(n);
        vector<array<int,3>> notInv, inv;
        for(int i=0;i<n;i++)cin>>arr[i][0]>>arr[i][1],arr[i][2]=i;
        notInv=inv=arr;
        for(int i=0;i<n;i++)swap(inv[i][0], inv[i][1]);
        sort(inv.begin(), inv.end());
        sort(notInv.begin(), notInv.end());
        for(int i=1;i<n;i++)
        {
            if(notInv[i][1]>notInv[i-1][1])notInv[i][1]=notInv[i-1][1], notInv[i][2]=notInv[i-1][2];
            if(inv[i][1]>inv[i-1][1])inv[i][1]=inv[i-1][1], inv[i][2]=inv[i-1][2];
        }
        vector<int> ans(n, -2);
        for(int i=0;i<n;i++)
        {
            for(auto ptr:{&notInv, &inv})
            {
                auto &list = *ptr;
                if(ans[i]!=-2)continue;
                if(list.front()[0]>=arr[i][0])continue;
                int cur=0;
                for(int jmp=n-1;jmp;jmp/=2)
                {
                    while(cur+jmp<n&&list[cur+jmp][0]<arr[i][0])cur+=jmp;
                }
                if(list[cur][1]<arr[i][1])
                {
                    ans[i]=list[cur][2];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout << ans[i]+1 << " \n"[i==n-1];
        }
    }
    return 0;
}