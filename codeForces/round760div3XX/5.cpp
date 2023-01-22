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
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        bool ok=true;
        ll sum=0;
        for(int i=0;i<n;i++)sum+=arr[i];
        if(sum%(n*(n+1)/2))ok=false;
        sum/=(n*(n+1)/2);
        vector<ll> ans(n);
        for(int i=0;i<n&&ok;i++)
        {
            ll val = arr[i];
            val -= sum;
            val = arr[(i+n-1)%n]-val;
            if(val<=0||val%n)
            {
                ok=false;
            }
            else
            {
                val/=n;
                ans[i]=val;
            }
        }
        if(!ok)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
            for(int i=0;i<n;i++)
            {
                if(i)cout << ' ';
                cout << ans[i];
            }cout << '\n';
        }
    }

    return 0;
}