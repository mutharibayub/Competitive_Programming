#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <map>
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
        int n,k;
        cin>>n>>k;
        map<int,set<int>> xm, ym;
        map<array<int,2>,int> mines;
        set<array<int,2>> vis;
        vector<int> minTimes;
        for(int i=0;i<n;i++)
        {
            int x,y,tm;
            cin>>x>>y>>tm;
            xm[x].insert(y);
            ym[y].insert(x);
            mines[{x,y}]=tm;
        }
        for(auto mine:mines)
        {
            int x=mine.first[0];
            int y=mine.first[1];
            if(vis.find({x,y})!=vis.end())continue;
            int tm=mine.second;
            minTimes.push_back(tm);
            vector<array<int,2>> stk;
            stk.push_back({x,y});
            vis.insert({x,y});
            while(!stk.empty())
            {
                int tx = stk.back()[0];
                int ty = stk.back()[1];
                int mny=ty-k, mxy=ty+k, mnx=tx-k, mxx=tx+k;
                minTimes.back()=min(minTimes.back(),mines[{tx,ty}]); 
                stk.pop_back();

                auto &ts1 = xm[tx];
                auto it = ts1.lower_bound(mny);
                while(it!=ts1.end()&&*it<=mxy)
                {
                    if(vis.find({tx,*it})==vis.end())
                    {
                        vis.insert({tx,*it});
                        stk.push_back({tx,*it});
                    }
                    it++;
                }

                auto &ts2 = ym[ty];
                it = ts2.lower_bound(mnx);
                while(it!=ts2.end()&&*it<=mxx)
                {
                    if(vis.find({*it,ty})==vis.end())
                    {
                        vis.insert({*it,ty});
                        stk.push_back({*it,ty});
                    }
                    it++;
                }
            }
        }
        sort(minTimes.begin(),minTimes.end());
        int cnt = 0;
        int l=0;
        int r=minTimes.size()-1;
        int tm=-1;
        while(l<=r)
        {
            tm++;
            while(l<=r&&minTimes[l]<=tm)l++;
            r--;
            cnt++;
        }
        cout << tm << '\n';
    }

    return 0;
}