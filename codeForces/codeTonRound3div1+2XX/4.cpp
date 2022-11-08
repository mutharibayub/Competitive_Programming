#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long

const ll MOD = 998244353;

ll coprimeCount(ll num, ll max)
{
    vector<ll> pf;
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            pf.push_back(i);
            while(num%i==0)num/=i;
        }
    }
    if(num>1)pf.push_back(num);
    int pfc = pf.size();
    ll ans = 0;
    for(int i=0;i<(1<<pfc);i++)
    {
        ll mul = 1;
        for(int j=0;j<pfc;j++)
        {
            if(i&(1<<j))
            {
                mul*=-pf[j];
            }
        }
        ans += max/mul;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        ll ans = 1;
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]%arr[i])
            {
                ans = 0;
                break;
            }
            if(arr[i-1]!=arr[i])
            {
                ans = (ans*(coprimeCount(arr[i-1]/arr[i], m/arr[i])))%MOD;
            }
            else 
            {
                ans = (ans*(m/arr[i]))%MOD;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}