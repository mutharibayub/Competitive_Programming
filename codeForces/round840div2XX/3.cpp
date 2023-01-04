#include <iostream>
#include <string>
#include <map> 
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std; 

typedef long long ll;

ll getMax(ll a, ll b)
{
    return max(a+b,abs(a-b)*2ll);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI=true;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        ll ans=0;
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++)ans+=arr[i];
        if(n==2)
        {
            ans=getMax(arr[0],arr[1]);
        }
        else if(n==3)
        {
            ans=getMax(arr[0],arr[1])+arr[2];
            ans=max(ans,arr[0]+getMax(arr[1],arr[2]));
            ans=max(ans,max(arr[0],arr[2])*3);
            ll lf=abs(arr[0]-arr[1]), rf=abs(arr[1]-arr[2]);
            ans=max(ans,lf+getMax(lf,arr[2]));
            ans=max(ans,rf+getMax(rf,arr[0]));
            ans=max(ans,abs(arr[0]-arr[2])*3);
            ans=max(ans,lf*3);
            ans=max(ans,rf*3);
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                ans=max(ans,arr[i]*n);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}