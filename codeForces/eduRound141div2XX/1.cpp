#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI = true;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.rbegin(),arr.rend());
        if(arr.front()==arr.back())
        {
            cout << "NO" << '\n';
            continue;
        }
        if(arr[0]==arr[1])
        {
            swap(arr.front(),arr.back());
        }
        cout << "YES" << '\n';
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << arr[i];
        }cout << '\n';
    }

    return 0;
}