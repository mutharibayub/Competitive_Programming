#include <iostream>
#include <vector>

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
        int last = -1;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
            {
                if(last!=-1)
                {
                    ans+=i-last-1;
                }
                last = i;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}