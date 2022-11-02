#include <iostream>
#include <vector>

using namespace std;

#define ll long long

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
        ll maxHeight = 0;
        ll width = 0;
        vector<pair<ll,ll>> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].first>>arr[i].second;
            maxHeight = max(maxHeight, max(arr[i].first,arr[i].second));
            width += min(arr[i].first, arr[i].second);
        }
        // for(int i=0;i<n;i++)
        // {
        //     if()
        // }
        cout << (2ll*maxHeight+2ll*width) << '\n';
    }

    return 0;
}