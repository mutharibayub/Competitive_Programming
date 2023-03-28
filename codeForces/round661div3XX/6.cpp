#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
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
        int n;
        cin>>n;
        vector<int> coords;
        vector<array<int,2>> segs(n);
        for(int i=0;i<n;i++)
        {
            int l,r;
            cin>>l>>r;
            segs[i][0]=l;
            segs[i][1]=r;
            coords.push_back(l);
            coords.push_back(r);
        }
        sort(coords.begin(), coords.end());
        for(int i=0;i<n;i++)
        {
            int l = lower_bound(coords.begin(), coords.end(), segs[i][0])-coords.begin();
            int r = lower_bound(coords.begin(), coords.end(), segs[i][1])-coords.begin();
            segs[i][0]=r-l;
            segs[i][1]=l;
        }
        sort(segs.begin(), segs.end());
        vector<int> vals(n,0);
        vector<vector<int>> mp(coords.size());
        vector<vector<pair<int,int>>> prevSegs(coords.size()); 
        int ans = -1;
        for(int i=0;i<=n;i++)
        {
            int curBest = 0;
            for(int j=0;j<coords.size();j++)
            {
                if(j && mp[j-1].size())
                {
                    auto &it = mp[j-1];
                    while(it.size())
                    {
                        curBest = max(curBest, it.back());
                        it.pop_back();
                    }
                }
                if(prevSegs[j].size())
                {
                    for(auto seg:prevSegs[j])
                    {
                        if(i==n || j>=segs[i][1] && j+seg.first<=segs[i][1]+segs[i][0])
                        {
                            mp[j+seg.first].push_back(vals[seg.second]+curBest);
                        }
                    }
                }
            }
            if(mp[coords.size()-1].size())
            {
                auto &it = mp[coords.size()-1];
                while(it.size())
                {
                    curBest = max(curBest, it.back());
                    it.pop_back();
                }
            }
            if(i<n)
            {
                vals[i]=curBest+1;
                prevSegs[segs[i][1]].emplace_back(segs[i][0],i);
            }
            else 
            {
                ans = curBest;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}