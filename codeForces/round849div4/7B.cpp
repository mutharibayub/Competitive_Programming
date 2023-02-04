#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>

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
        ll c;
        cin>>c;
        vector<int> a(n+1);
        vector<ll> sum(n);
        vector<array<int,2>> costs(n);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=0;i<n;i++)
        {
            int leftCost=a[i+1]+i+1;
            int rightCost=a[i+1]+n+1-(i+1);
            costs[i]={min(leftCost, rightCost), i+1};
        }
        sort(costs.begin(), costs.end());
        for(int i=0;i<n;i++)
        {
            sum[i]=i?sum[i-1]:0;
            sum[i]+=costs[i][0];
        }

        if(sum.back()<=c)
        {
            cout << n << '\n';
            continue;
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int idx=costs[i][1];
            int leftCost=a[idx]+idx;
            int rightCost=a[idx]+n+1-idx;
            int ind = lower_bound(sum.begin(), sum.end(), c-leftCost+1)-sum.begin();
            if(ind)
            {
                if(costs[ind][0]<=min(leftCost,rightCost))
                {
                    ans=max(ans, ind+1);
                }
                else
                {
                    ll cLeft=c-(sum[ind]-costs[ind][0])+min(leftCost, rightCost)-leftCost;
                    ind = lower_bound(sum.begin(), sum.end(), (sum[ind]-costs[ind][0])+cLeft+1)-sum.begin();
                    ans=max(ans, ind);
                }   
            }
            if(leftCost<=c)ans=max(ans, 1);
        }
        cout << ans << '\n';
    }

    return 0;

}