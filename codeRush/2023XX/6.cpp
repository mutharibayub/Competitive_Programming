#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <limits>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <cassert>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> p(n), q(n);
        for(int i=0;i<n;i++)cin>>p[i], p[i]--;
        for(int i=0;i<n;i++)cin>>q[i], q[i]--;

        vector<vector<int>> loc(n);
        for(int i=0;i<n;i++)
        {
            loc[p[i]].push_back(i);
            if(p[i]!=q[i])loc[q[i]].push_back(i);
        }

        vector<int> nxt;
        ll ans = 1;

        for(int i=0;i<n;i++)
        {
            if(p[i]==q[i])nxt.push_back(i), ans = (ans*n)%MOD;
        }

        bool ok = true;
        for(int ii=0;ii<(int)nxt.size()&&ok;ii++)
        {
            int i = nxt[ii];
            assert(p[i]==q[i]);
            for(auto ele:loc[p[i]])
            {
                if(ele==i)continue;
                if(p[ele]!=p[i]&&q[ele]!=q[i])continue;
                if(p[ele]==q[ele])
                {
                    ok=false;
                    break;
                }
                if(p[ele]==p[i])swap(p[ele], q[ele]);
                q[ele]=p[ele];
                nxt.push_back(ele);
            }
        }

        vector<int> cnt(n, 0);
        for(int i=0;i<n&&ok;i++)
        {
            if(++cnt[p[i]]>2)ok=false;
            if(++cnt[q[i]]>2)ok=false;
            loc[i].clear();
        }

        for(int i=0;i<n&&ok;i++)
        {
            if(p[i]!=q[i])
            {
                loc[p[i]].push_back(i);
                loc[q[i]].push_back(i);
            }
        }

        vector<bool> done(n, false);
        for(int i=0;i<n&&ok;i++)
        {
            if(p[i]!=q[i]&&!done[i])
            {
                int curLoc = i;
                int val = p[i];
                while(!done[curLoc])
                {
                    done[curLoc]=true;
                    if(curLoc==loc[val][0])swap(loc[val][0], loc[val][1]);
                    curLoc=loc[val][0];
                    if(p[curLoc]==val)val=q[curLoc];
                    else val=p[curLoc];
                }
                ans = (ans*2)%MOD;
            }
        }

        cout << (ok?ans:0) << '\n';

    }
    return 0;
}