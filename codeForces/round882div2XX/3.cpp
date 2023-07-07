#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

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
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<bool> canDo(1<<8, 0);
        canDo[0]=true;
        int ans = 0;
        int xr=0;
        for(int i=0;i<n;i++)
        {
            xr^=arr[i];
            for(int j=0;j<(1<<8);j++)
            {
                if(canDo[j])
                    ans=max(ans, xr^j);
            }
            canDo[xr]=true;
        }
        cout << ans << '\n';
    }    

    return 0;
}