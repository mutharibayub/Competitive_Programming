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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        vector<ll> sm(n);
        sm[0]=arr[0];
        for(int i=1;i<n;i++)sm[i]=sm[i-1]+arr[i];
        int l=0, r=n-1;
        while(l!=r)
        {
            int mid = (l+r+1)/2;
            cout << "? " << mid-l;
            for(int i=l;i<mid;i++)
            {
                cout << ' ' << i+1;
            }cout << endl;
            ll x, cnt=sm[mid-1]-(l?sm[l-1]:0);
            cin>>x;
            if(cnt<x)r=mid-1;
            else l=mid;
        }
        cout << "! " << l+1 << endl;
    }

    return 0;
}