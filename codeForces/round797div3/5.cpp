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
        int n,k;
        ll ans=0;
        cin>>n>>k;
        vector<int> arr(n), bins(k,0);
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++)
        {
            ans+=arr[i]/k;
            bins[arr[i]%k]++;
        }
        int l=1,r=k-1;
        while(l<r)
        {
            if(bins[l]&&bins[r]&&l+r>=k)
            {
                int use = min(bins[l],bins[r]);
                ans+=use;
                bins[l]-=use;
                bins[r]-=use;
            }
            else
            {
                if(!bins[l])l++;
                else if(!bins[r])r--;
                else if(l+r<k)l++;
            }
        }
        if(r*2>=k)ans+=bins[r]/2;
        cout << ans << '\n';
    }

    return 0;
}