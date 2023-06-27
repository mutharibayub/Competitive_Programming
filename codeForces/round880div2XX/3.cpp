#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool MULTI = true;
    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        long long a, b, c, k;
        cin>>a>>b>>c>>k;
        int aLower=pow(10, a-1), aUpper=pow(10, a)-1;
        int bLower=pow(10, b-1), bUpper=pow(10, b)-1;
        int cLower=pow(10, c-1), cUpper=pow(10, c)-1;
        long long cnt = 0;
        array<int, 3> ans = {-1, -1, -1};
        for(int i=aLower;i<=aUpper;i++)
        {
            int smallest = max(bLower, cLower-i);
            int highest = min(bUpper, cUpper-i);
            if(smallest>highest)continue;
            if(highest-smallest+1+cnt>=k)
            {
                int ahead = k-cnt-1;
                ans = {i, smallest+ahead, i+smallest+ahead};
                break;
            }
            cnt+=highest-smallest+1;
        }
        if(ans[0]==-1)cout << -1 << '\n';
        else cout << ans[0] << " + " << ans[1] << " = " << ans[2] << '\n';
    }
    return 0;
}