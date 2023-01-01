#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll norm(ll num)
{
    return (num%MOD+MOD)%MOD;
}

ll power(ll n, ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
        {
            ans=norm(ans*n);
        }
        n=norm(n*n);
        e/=2;
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
        int n;
        cin>>n;
        int upper = 1;
        while(upper<=n)upper*=2;
        vector<int> psqs;
        for(int i=0;i*i<upper;i++)
        {
            psqs.push_back(i*i);
        }          
        vector<int> arr(n);
        vector<int> count(upper,0);
        for(int i=0;i<n;i++)cin>>arr[i];
        int xr=0;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            count[xr]++;
            xr^=arr[i];
            for(int j=0;j<psqs.size();j++)
            {
                ans+=count[psqs[j]^xr];
            }
        }
        ans = ((1ll*n*(n+1))/2) - ans;
        cout << ans << '\n';
    }

    return 0;
}