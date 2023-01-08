#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <assert.h>
#include <array>
 
using namespace std;
 
typedef long long ll;
 
const int MOD=1e9+7;
 
ll pwr(ll n, ll e, ll mod=MOD)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
        {
            ans=ans*n%mod;
        }
        n=n*n%mod;
        e/=2;
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    const bool MULTI = true;
 
    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            --arr[i];
        }
        array<vector<int>,2> cnts;
        cnts[0].assign(n+1,0);
        cnts[1].assign(n+1,0);
        for(int i=0;i<n;i++)
        {
            cnts[0][arr[i]]++;
            cnts[1][arr[i]]++;
        }
        for(int )
    }
 
    return 0;
}