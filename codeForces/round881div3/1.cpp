#include <iostream>
#include <vector>
#include <string>
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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        int l=0, r=arr.size()-1;
        int ans = 0;
        while(l<r)
        {
            ans += arr[r]-arr[l];
            l++, r--;
        }
        cout << ans << '\n';
    }
    return 0;
}