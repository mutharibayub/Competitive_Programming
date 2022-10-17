#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll maxTime(vector<pair<ll,ll>> &arr, ll val)
{
    ll maxTime = -1;
    for(int i=0;i<arr.size();i++)
    {
        maxTime = max(maxTime, abs(arr[i].first - val)+arr[i].second);
    }
    return maxTime;
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
        vector<pair<ll,ll>> arr(n);
        ll minVal = 1e9+7, maxVal = -1*(1e9+7);
        for(int i=0;i<n;i++)
        {
            cin >> arr[i].first;
            arr[i].first*=2;
            minVal = min(minVal, arr[i].first);
            maxVal = max(maxVal, arr[i].first);
        }

        for(int i=0;i<n;i++)
        {
            cin >> arr[i].second;
            arr[i].second*=2;
        }

        ll jump = maxVal-minVal;
        ll ans = minVal;
        ll curMaxTime = maxTime(arr, ans);
        for(;jump;jump=jump>>1)
        {
            ll nextMaxTime;
            while((nextMaxTime=maxTime(arr, ans+jump)) < curMaxTime)
            {
                ans += jump;
                curMaxTime = nextMaxTime;
            }
            while((nextMaxTime=maxTime(arr, ans-jump)) < curMaxTime)
            {
                ans -= jump;
                curMaxTime = nextMaxTime;
            }
        }
        cout << (ans>>1) << "." << ((ans&1)?'5':'0') << '\n';
    }

    return 0;
}