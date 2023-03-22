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
        vector<int> test(n);
        test[0]=arr[0];
        for(int i=1;i<n;i++)test[i]=test[i-1]+arr[i];
        int ans = 1e9+7;
        for(int i=0;i<n;i++)
        {
            bool ok = true;
            int op = i;
            for(int j=i+1;j<n&&ok;j++)
            {
                int cnt = 0;
                int sum = 0;
                for(;j<n&&sum<test[i];j++)
                {
                    sum+=arr[j];
                    cnt++;
                }
                j--;
                if(sum!=test[i])ok=false;
                op+=cnt-1;
            }
            if(ok)ans=min(ans, op);
        }
        cout << ans << '\n';
    }
    return 0;
}