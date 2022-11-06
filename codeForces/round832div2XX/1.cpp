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
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        ll ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += arr[i];
        }
        cout << abs(ans) << '\n';
    }

    return 0;
}