#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

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
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        map<ll,ll> cnts;
        ll ans = 1;
        cnts[arr[0]]=1;
        ll offset = 0;
        for(int i=1;i<n;i++)
        {
            ll zeroCount=cnts[0+offset];
            ll toAdd = ((ans-zeroCount)%MOD+MOD)%MOD;
            ans=(ans+toAdd)%MOD;
            offset-=arr[i];
            cnts[arr[i]+offset]=(cnts[arr[i]+offset]+toAdd)%MOD;
        }    
        cout << ans << '\n';
    }
    
    return 0;
}