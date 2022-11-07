#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

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
        string s;
        cin>>n>>s;
        int max1=0, max0=0, _1=0, _0=0, total1=0, total0=0; 
        for(int i=0;s[i];i++)
        {
            if(s[i]=='1')
            {
                total1++;
                _1++;
                _0=0;
                max1 = max(max1, _1);
            }
            else
            {
                total0++;
                _0++;
                _1=0;
                max0 = max(max0, _0);
            }
        }
        ll ans = max({1ll*total0*total1, 1ll*max1*max1, 1ll*max0*max0});
        cout << ans << '\n';
    }

    return 0;
}