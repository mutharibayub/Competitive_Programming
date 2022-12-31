#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll n,s,e;
        cin>>n>>s>>e;
        vector<ll> arr(n),rq(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++)
        {
            while(i<n&&i&&arr[i]==arr[i-1])
            {
                rq[i]=rq[i-1];
                i++;
            }
            if(i<n)rq[i]=arr[i]-i;
        }
        int ptr=0;
        while(ptr<n&&s>=rq[ptr])ptr++;
        ll ans=0;
        while(1)
        {
            ll inc = 2*ptr-n;
            ll maxInc = ptr;
            if(s+maxInc>=e)
            {
                ans+=e-s;
                break;
            }
            else if(inc<=0)
            {
                ans=-1;
                break;
            }
            else if(ptr==n||arr[ptr]>=e)
            {
                ll diff = e-s-ptr;
                ll jump = inc;
                ll iterations = (diff+jump-1)/jump;
                ans+=iterations*n;
                s+=iterations*inc;
            }
            else if(s>=rq[ptr])
            {
                while(ptr<n&&s>=rq[ptr])ptr++;
            }
            else
            {
                ll diff = rq[ptr]-s;
                ll jump = inc;
                ll iterations = (diff+jump-1)/jump;
                ans+=iterations*n;
                s+=iterations*inc;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}