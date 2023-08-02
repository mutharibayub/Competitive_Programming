#include <iostream>
#include <vector>
#include <algorithm>

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
        int n, m;
        cin>>n>>m;
        vector<int> arr(n), x(m);
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<m;i++)cin>>x[i];
        vector<ll> sm(n);
        ll peak = sm[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            sm[i]=sm[i-1]+arr[i];
            peak=max(peak, sm[i]);
        }
        vector<ll> srt = sm;
        sort(srt.begin(), srt.end());
        vector<int> inds(n, 1e9+7);
        for(int i=0;i<n;i++)
        {
            int nm = lower_bound(srt.begin(), srt.end(), sm[i])-srt.begin();
            inds[nm]=min(inds[nm], i);
        }
        vector<int> mn(n, 1e9+7);
        mn.back()=inds.back();
        for(int i=n-2;i>=0;i--)
        {
            mn[i]=min(mn[i+1], inds[i]);
        }
        for(int i=0;i<m;i++)
        {
            if(i)cout << ' ';
            ll sum = 0;
            ll count = 0;
            if(sum+peak<x[i])
            {
                if(sm.back()<=0)
                {
                    cout << -1 ;
                    continue;
                }
                else
                {
                    ll rounds = (x[i]-peak+sm.back()-1)/sm.back();
                    sum += rounds*sm.back();
                    count += rounds*n;
                }
            }
            ll needed = x[i]-sum;
            int nm = lower_bound(srt.begin(), srt.end(), needed)-srt.begin();
            count += mn[nm];
            cout << count ;
        }cout << '\n';
    }

    return 0;
}