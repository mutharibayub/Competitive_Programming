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

int gcd(int a, int b)
{
    if(a<b)swap(a, b);
    if(!b)return a;
    return gcd(b, a%b);
}

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
        int mx = -1e9, mn=1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            mn=min(mn, arr[i]);
            mx=max(mx, arr[i]);
        }

        bool allSame = true;
        for(int i=0;i+1<n&&allSame;i++)
        {
            if(arr[i]!=arr[i+1])
            {
                allSame=false;
            }
        }

        if(allSame)
        {
            cout << -1 << '\n';
            continue;
        }

        int ans = mx-mn;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==mn)continue;
            ans=gcd(ans, arr[i]-mn);
        }
        cout << ans << '\n';
    }    

    return 0;
}