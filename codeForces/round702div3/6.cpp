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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        vector<int> counts;
        for(int i=0;i<n;i++)
        {
            int cnt=1;
            while(i+1<n&&arr[i+1]==arr[i])cnt++, i++;
            counts.push_back(cnt);
        }
        sort(counts.begin(), counts.end());
        vector<int> sm = counts;
        for(int i=1;i<counts.size();i++)sm[i]+=sm[i-1];
        int ans = 1e9+7;
        for(int i=0;i<counts.size();i++)
        {
            int l=i-1;
            while(i+1<counts.size()&&counts[i+1]==counts[i])i++;
            int before = l<0?0:sm[l];
            int after = sm.back()-sm[i]-(counts[i]*(counts.size()-i-1));
            ans = min(ans, before+after);
        }
        cout << ans << '\n';
    }

    return 0;
}