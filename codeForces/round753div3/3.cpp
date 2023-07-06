#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        ll ans = -(1e18+7);
        for(int i=0;i<n;i++)
        {
            ans = max(ans, 1ll*arr[i]-(i?arr[i-1]:0));
        }
        cout << ans << '\n';
    }    

    return 0;
}