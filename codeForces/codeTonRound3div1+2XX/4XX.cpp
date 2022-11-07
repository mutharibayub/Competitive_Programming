#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long

const ll MOD = 998244353;

ll eulerTotient(ll num, ll max)
{
    ll ans = max;
    for(ll i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            while(num%i==0)
            {
                num/=i;    
            }
            ans-=ans/i;
        }
    }
    if(num>1)ans-=ans/num;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << eulerTotient(30, 60) << '\n';
    return 0;

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
            // cout << arr[i-1] << ' ' << arr[i] << '\n';
            if(arr[i-1]%arr[i])
            {
                ans = 0;
                break;
            }
            if(arr[i-1]!=arr[i])
            {
                ans = (ans*(eulerTotient(arr[i-1]/arr[i], m/arr[i])))%MOD;
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