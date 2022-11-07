#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int maxGrp(vector<int> &arr, ll groupSum)
{
    int maxGrp=-1;
    int grpSize=0;
    ll grpLeft = groupSum;
    for(int i=0;i<arr.size();i++)
    {
        grpLeft-=arr[i];
        grpSize++;
        if(grpLeft==0)
        {
            grpLeft=groupSum;
            maxGrp=max(maxGrp,grpSize);
            grpSize=0;
        }
        else if(grpLeft<0)
        {
            return (1e9+7);
        }
    }
    if(grpLeft==groupSum)
    {
        return maxGrp;
    }
    return (1e9+7);
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
        ll sum=0;
        int maxNum=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            maxNum = max(maxNum, arr[i]);
        }
        vector<ll> factors;
        factors.reserve(n);
        for(int i=1;1ll*i*i<=sum;i++)
        {
            if(sum%i==0)
            {
                if(i>=maxNum)factors.push_back(i);
                if(sum/i>=maxNum)factors.push_back(sum/i);
            }
        }
        sort(factors.begin(), factors.end());
        int ans = 1e9+7;
        for(auto factor:factors)
        {
            // cout << factor << ' ';
            int tmp=maxGrp(arr, factor);
            ans = min(ans, tmp);
            if(ans==1)break;
        }
        cout << ans << '\n';
    }

    return 0;
}
