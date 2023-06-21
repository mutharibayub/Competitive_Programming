#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        vector<pair<int, int>> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++)cin>>a[i].first, a[i].second=i;
        for(int i=0;i<n;i++)cin>>b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[a[i].second]=b[i];
        }
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }
    return 0;
}