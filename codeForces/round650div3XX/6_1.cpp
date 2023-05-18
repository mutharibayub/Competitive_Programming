#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

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
        vector<int> srt=arr;
        sort(srt.begin(), srt.end());
        int ans = 1e9+7;
        for(int i=0;i<=n;i++)
        {
            vector<int> newArr = arr;
            for(int j=n-1, offset=0;j>=0;j--)
            {
                if(i&&newArr[j]<=srt[i-1])
                {
                    offset++;
                }
                else
                {
                    newArr[j+offset]=newArr[j];
                }
            }

            int count=i, sub=0;
            int minMoved = 1e9+7;
            int last = -1;
            for(int j=i;j<n;j++)
            {
                if(srt[j]>minMoved)break;
                while(j+sub<n&&newArr[j+sub]>srt[j])
                {
                    minMoved = min(minMoved, newArr[j+sub]);
                    sub++;
                }
            }
            if(minMoved!=1e9+7)
            {
                count += n-(lower_bound(srt.begin(), srt.end(), minMoved)-srt.begin());   
            }
            ans = min(ans, count);
        }
        cout << ans << '\n';
    }
    return 0;
}