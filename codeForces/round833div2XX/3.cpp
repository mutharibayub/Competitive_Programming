#include <iostream>
#include <vector>
#include <map>

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
        int n;
        cin>>n;
        vector<int> arr(n);
        ll sum = 0;
        bool zeroFound = false;
        int ans=0;
        map<ll, int> counts;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(arr[i]==0)
            {
                zeroFound = true;
                int maxCount = 0;
                do
                {
                    sum += arr[i];
                    maxCount = max(maxCount, ++counts[sum]);
                    i++;
                } while (i<n && arr[i]!=0);
                i--;
                ans += maxCount;
                counts.clear();
            }
            if(!zeroFound && sum==0)
            {
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}