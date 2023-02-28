#include <iostream>
#include <vector>

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
        int n, c;
        cin>>n>>c;
        vector<int> a(n), b(n-1);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n-1;i++)cin>>b[i];
        int ans = 1e9+7;
        int cur = 0;
        int days = 0;
        for(int i=0;i<n;i++)
        {
            int rqToBuy = max(c-cur, 0);
            int daysToBuy = (rqToBuy+a[i]-1)/a[i];
            ans = min(ans, days+daysToBuy);
            if(i<n-1)
            {
                int rqToNxt = max(b[i]-cur, 0);
                int daysToNxt = (rqToNxt+a[i]-1)/a[i];
                cur=cur+daysToNxt*a[i]-b[i];
                days+=daysToNxt+1;
            }
            if(days >= ans)break;
        }

        cout << ans << '\n';

    }

    return 0;
}