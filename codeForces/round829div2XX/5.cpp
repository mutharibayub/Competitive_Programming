#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define ll long long

const ll MOD = 998244353;

ll getInv(ll num, ll mod)
{
    num%=mod;
    if(num<0)num+=mod;
    ll Q,R=1,T1=0,T2=1,T,tmp=mod;
    while(R)
    {
        Q=mod/num;
        R=mod%num;
        T=T1-T2*Q;
        mod=num;
        num=R;
        T1=T2;
        T2=T;
    }
    return T1>=0?T1%tmp:T1%tmp+tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n, zeros=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            zeros+=arr[i]==0;
        }
        
        int j=0;
        for(int i=0;i<zeros;i++)
        {
            j+=arr[i]==1;
        }
        
        ll val = 0;
        for(int i=1;i<=j;i++)
        {
            ll tmp = ((1ll*n*(n-1))%MOD*getInv(2ll*i*i, MOD))%MOD;
            val = (val+tmp)%MOD;
        }
        
        cout << val << '\n';

    }

    return 0;
}