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
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<bool> done(n,false);
        int ans=1;
        bool foundBest=false;
        for(int i=0;i<n;i++)
        {
            if(!done[i])
            {
                int ln=0;
                int ptr=i;
                bool finder=false;
                set<int> inCycle;
                while(!done[ptr])
                {
                    ln++;
                    done[ptr]=true;
                    inCycle.insert(ptr);
                    if(!foundBest&&(inCycle.find(ptr-1)!=inCycle.end()||
                                                inCycle.find(ptr+1)!=inCycle.end()))
                    {
                        finder=true;
                        foundBest=true;
                    }
                    ptr=arr[ptr]-1;
                }
                ans+=ln-1;
                if(finder)ans-=2;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}