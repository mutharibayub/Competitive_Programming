#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

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
        vector<ll> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<ll> next;
        next.reserve(n);
        int ans = 0;
        ll diff=1;        
        while(n>1)
        {
            for(int i=0;i<n;i+=2)
            {
                if(abs(arr[i]-arr[i+1])!=diff)
                {
                    ans=-1;
                    break;
                }
                if(arr[i]>arr[i+1])ans++;
                next.push_back(arr[i]+arr[i+1]);
            }
            if(ans==-1)break;
            arr = next;
            next.clear();
            diff *= 4;
            n /= 2;
        }
        cout << ans << '\n';
    }

    return 0;
}
