#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int l,r,x,a,b;
        cin>>l>>r>>x>>a>>b;
        if(a==b)
        {
            cout << 0 << '\n';
            continue;
        }
        int ans = 1e9+7;
        vector<array<int,2>> stk;
        stk.push_back({a,0});
        while(!stk.empty())
        {
            int top = stk.back()[0];
            int dist = stk.back()[1];
            stk.pop_back();
            if(abs(b-top)>=x)
            {
                ans=min(ans, dist+1);
            }
            if(dist<4)
            {
                if(abs(l-top)>=x)
                {
                    stk.push_back({l, dist+1});
                }
                if(abs(r-top)>=x)
                {
                    stk.push_back({r, dist+1});
                }
            }
        }
        if(ans==1e9+7)ans=-1;
        cout << ans << '\n';

    }


    return 0;
}